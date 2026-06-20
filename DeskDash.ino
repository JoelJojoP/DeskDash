#include "DeskDash.h"

/* Inactivity timeout value */
#define INACTIVITY_TIMEOUT_MS 30000

/* LVGL draw buffers. These are allocated from PSRAM for the full screen */
#define DRAW_BUF_SIZE (TFT_HOR_RES * TFT_VER_RES * (LV_COLOR_DEPTH / 8))
void *drawBuf1 = NULL;
void *drawBuf2 = NULL;

/* Display object and input object */
lv_display_t *glbDisp;
lv_indev_t *glbIndev;

/* Application MVC objects */
DeskDashModel model;
DeskDashView view;

/* Task Handles */
TaskHandle_t xLvglTaskHandle = NULL;
TaskHandle_t xDataInitTaskHandle = NULL;
TaskHandle_t xUpdateViewTask = NULL;
TaskHandle_t xTimeUpdateTaskHandle = NULL;
TaskHandle_t xWeatherUpdateTaskHandle = NULL;

/* Mutex to handle resources for LVGL */
SemaphoreHandle_t xGuiSemaphore;

EventGroupHandle_t xDataEventGroup;
SemaphoreHandle_t xWifiSemaphore;

/* Mutex to handle UART logging */
#if ACTIVE_LOG_LEVEL >= LOG_LEVEL_ERROR
SemaphoreHandle_t xUartSemaphore;
#endif

bool isSleep = false;
bool initDone = false;

/* Function to flush draw buffer to display */
void lv_disp_flush(lv_display_t *disp, const lv_area_t *area,
                   uint8_t *color_p) {
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);
    lv_draw_sw_rgb565_swap((void *)color_p, w * h);
    M5.Display.startWrite();
    M5.Display.pushImageDMA(area->x1, area->y1, w, h, (uint16_t *)color_p);
    M5.Display.waitDMA();
    M5.Display.endWrite();
    lv_disp_flush_ready(disp);
}

/* Function to read touchscreen inputs */
static void lv_indev_read(lv_indev_t *indev_driver, lv_indev_data_t *data) {
    lgfx::touch_point_t tp[3];
    uint8_t touchpad = M5.Display.getTouchRaw(tp, 1);
    if (touchpad > 0) {
        data->point.x = tp[0].y;
        data->point.y = (720 - tp[0].x);
        data->state = LV_INDEV_STATE_PRESSED;
        if (isSleep) {
            wake_up();
            isSleep = false;
        }
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

/* Custom tick */
static uint32_t my_tick(void) { return millis(); }

/* LVGL task to refresh display */
void lvgl_task(void *pvParameters) {
    while (1) {
        if (xSemaphoreTake(xGuiSemaphore, portMAX_DELAY) == pdTRUE) {
            lv_timer_handler();
            if ((lv_disp_get_inactive_time(NULL) > INACTIVITY_TIMEOUT_MS) &&
                initDone && !isSleep) {
                go_sleep();
                isSleep = true;
            }
            xSemaphoreGive(xGuiSemaphore);
        }
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}

int connectToWiFi() {
    JsonDocument &cfg = model.getConfig();
    int wifiCnt = cfg["wifiCnt"].as<int>() | 0;
    const char *ssid;
    const char *password;
    int attempts;

    if (xSemaphoreTake(xWifiSemaphore, portMAX_DELAY) == pdTRUE) {
        WiFi.mode(WIFI_STA);
        for (int i = 0; i < wifiCnt; i++) {
            ssid = cfg["wifi"][i]["ssid"];
            password = cfg["wifi"][i]["pwd"];
            WiFi.begin(ssid, password);
            attempts = 0;
            while (WiFi.status() != WL_CONNECTED && attempts < 60) {
                vTaskDelay(pdMS_TO_TICKS(500));
                attempts++;
            }
            if (WiFi.status() == WL_CONNECTED) {
                LOG_INFO("Connected to WiFi: %s", ssid);
                return 0;
            } else {
                LOG_WARN("Failed to connect to WiFi: %s", ssid);
            }
        }
        LOG_ERROR("Failed to connect to any WiFi network");
        return -1;
    }
}

void disconnectWiFi() {
    if (WiFi.status() == WL_CONNECTED) {
        WiFi.disconnect(true);
    }
    WiFi.mode(WIFI_OFF);
    xSemaphoreGive(xWifiSemaphore);
    LOG_INFO("Disconnected from WiFi");
}

void wthCodeToString(int wthCode, char *wthStr, size_t strSize) {
    if (wthCode == 0) {
        snprintf(wthStr, strSize, "Clear");
    } else if (wthCode >= 1 && wthCode <= 2) {
        snprintf(wthStr, strSize, "Partly Cloudy");
    } else if (wthCode == 3) {
        snprintf(wthStr, strSize, "Cloudy");
    } else if (wthCode >= 45 && wthCode <= 48) {
        snprintf(wthStr, strSize, "Fog");
    } else if ((wthCode >= 51 && wthCode <= 57) ||
               (wthCode >= 61 && wthCode <= 67) ||
               (wthCode >= 80 && wthCode <= 82)) {
        snprintf(wthStr, strSize, "Rain");
    } else if ((wthCode >= 71 && wthCode <= 77) ||
               (wthCode >= 85 && wthCode <= 86)) {
        snprintf(wthStr, strSize, "Snow");
    } else if (wthCode >= 95 && wthCode <= 99) {
        snprintf(wthStr, strSize, "Thunderstorm");
    } else {
        snprintf(wthStr, strSize, "Unknown");
    }
}

void initializeTask(void *pvParameters) {
    int status = 0;

    status = connectToWiFi();
    if (status != 0) {
        LOG_ERROR("Failed to connect to WiFi during initialization");
    } else {
        status = model.initData();
        if (status != 0) {
            LOG_ERROR("Failed to initialize data");
        } else {
            LOG_INFO("Data initialization completed");
            initDone = true;
            lv_display_trigger_activity(NULL);
            xEventGroupSetBits(xDataEventGroup,
                               TIME_UPDATE_EVENT | DAY_UPDATE_EVENT |
                                   WEATHER_UPDATE_EVENT | SCREEN_CHANGE_EVENT);
            xTaskCreatePinnedToCore(updateTimeTask, "UpdateTime", 4096, NULL, 1,
                                    &xTimeUpdateTaskHandle, 0);
            xTaskCreatePinnedToCore(updateWeatherTask, "UpdateWeather", 4096,
                                    NULL, 1, &xWeatherUpdateTaskHandle, 0);
        }
    }
    disconnectWiFi();
    vTaskDelete(NULL);
}

void updateViewTask(void *pvParameters) {
    EventBits_t uxBits;
    DeskDashData data;

    while (1) {
        uxBits =
            xEventGroupWaitBits(xDataEventGroup,
                                TIME_UPDATE_EVENT | DAY_UPDATE_EVENT |
                                    WEATHER_UPDATE_EVENT | SCREEN_CHANGE_EVENT,
                                pdTRUE, pdFALSE, portMAX_DELAY);
        data = model.getData();

        if (uxBits & TIME_UPDATE_EVENT && data.isTimeSynced) {
            char timeStr[6];
            strftime(timeStr, sizeof(timeStr), "%H:%M", &data.timeInfo);
            view.updateTime(timeStr);
        }

        if (uxBits & DAY_UPDATE_EVENT && data.isTimeSynced) {
            char dayStr[10];
            char dateStr[20];
            strftime(dayStr, sizeof(dayStr), "%A", &data.timeInfo);
            strftime(dateStr, sizeof(dateStr), "%B %d, %Y", &data.timeInfo);
            view.updateDate(dateStr, dayStr);
        }

        if (uxBits & WEATHER_UPDATE_EVENT && data.isWthInitDone) {
            char curTempStr[10];
            char minMaxTempStr[25];
            char wthStr[20];
            wthCodeToString(data.weather.wthCode, wthStr, sizeof(wthStr));
            snprintf(curTempStr, sizeof(curTempStr), "%.1f°C",
                     data.weather.curTemp);
            snprintf(minMaxTempStr, sizeof(minMaxTempStr),
                     "H: %.1f° | L: %.1f°", data.weather.maxTemp,
                     data.weather.minTemp);
            view.updateWeather(curTempStr, minMaxTempStr, wthStr);
            view.updateWeatherIcon(data.weather.wthCode, data.weather.isDay);
        }

        if (uxBits & SCREEN_CHANGE_EVENT) {
            view.changeScreen();
            view.updateLocation(model.getConfig()["city"]);
        }
    }
}

void updateTimeTask(void *pvParameters) {
    DeskDashData data;
    int prevDay = -1;

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(20000)); // Update time every minute
        model.updateTime();
        xEventGroupSetBits(xDataEventGroup, TIME_UPDATE_EVENT);
        data = model.getData();
        if (data.timeInfo.tm_mday != prevDay) {
            xEventGroupSetBits(xDataEventGroup, DAY_UPDATE_EVENT);
            prevDay = data.timeInfo.tm_mday;
        }
    }
}

void updateWeatherTask(void *pvParameters) {
    int status = 0;
    uint32_t waitDelay = 3600000; // Update weather every 1 hour

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(waitDelay)); // Retry every 10 minutes
        status = connectToWiFi();
        if (status != 0) {
            // Retry every 10 minutes if WiFi connection fails
            waitDelay = 600000;
            LOG_WARN("Skipping weather update due to WiFi connection failure");
        } else {
            if (model.updateWeather() == 0) {
                xEventGroupSetBits(xDataEventGroup, WEATHER_UPDATE_EVENT);
                // Reset to 1 hour on successful update
                waitDelay = 3600000;
                LOG_INFO("Weather update successful");
            } else {
                // Retry every 10 minutes if weather update fails
                waitDelay = 600000;
                LOG_WARN("Weather update failed");
            }
        }
        disconnectWiFi();
    }
}

/* Put the M5Tab5 to sleep */
void go_sleep() {
    LOG_INFO("Entering sleep");
    digitalWrite(DISP_BL_PIN, LOW);
    M5.Display.writecommand(0x28); // Display off
    // esp_light_sleep_start();
}

/* Wake up the M5Tab5 from sleep */
void wake_up() {
    LOG_INFO("Waking up from sleep");
    M5.Display.writecommand(0x29); // Display on
    digitalWrite(DISP_BL_PIN, HIGH);
}

/* Initial setup */
void setup() {
#if ACTIVE_LOG_LEVEL >= LOG_LEVEL_ERROR
    Serial.begin(115200);
    xUartSemaphore = xSemaphoreCreateMutex();
#endif
    LOG_INFO("Initializing M5Tab5");
    auto cfg = M5.config();
    M5.begin(cfg);
    pinMode(DISP_BL_PIN, OUTPUT);
    digitalWrite(DISP_BL_PIN, HIGH);
    // pinMode(TOUCH_INT_PIN, INPUT);
    // gpio_wakeup_enable((gpio_num_t)TOUCH_INT_PIN, GPIO_INTR_LOW_LEVEL);
    // esp_sleep_enable_gpio_wakeup();
    M5.Display.setRotation(1);

    // Allocate draw buffers from PSRAM
    LOG_INFO("Allocating memory for draw buffer");
    drawBuf1 = (uint8_t *)heap_caps_aligned_alloc(64, DRAW_BUF_SIZE,
                                                  MALLOC_CAP_SPIRAM);
    drawBuf2 = (uint8_t *)heap_caps_aligned_alloc(64, DRAW_BUF_SIZE,
                                                  MALLOC_CAP_SPIRAM);

    if (drawBuf1 == NULL || drawBuf2 == NULL) {
        LOG_ERROR("Failed to allocate memory for draw buffer!");
        return;
    }

    if (model.setConfig("/config.json") != 0) {
        LOG_ERROR("Failed to set config!");
        return;
    }

    LOG_INFO("Initializing LVGL");
    lv_init();
    lv_tick_set_cb(my_tick);

    glbDisp = lv_display_create(TFT_HOR_RES, TFT_VER_RES);
    lv_display_set_flush_cb(glbDisp, lv_disp_flush);
    lv_display_set_buffers(glbDisp, drawBuf1, drawBuf2, DRAW_BUF_SIZE,
                           LV_DISPLAY_RENDER_MODE_FULL);

    glbIndev = lv_indev_create();
    lv_indev_set_type(glbIndev, LV_INDEV_TYPE_POINTER);
    lv_indev_set_display(glbIndev, glbDisp);
    lv_indev_set_read_cb(glbIndev, lv_indev_read);

    xGuiSemaphore = xSemaphoreCreateMutex();
    xDataEventGroup = xEventGroupCreate();
    xWifiSemaphore = xSemaphoreCreateBinary();
    xSemaphoreGive(xWifiSemaphore);

    if (xSemaphoreTake(xGuiSemaphore, portMAX_DELAY) == pdTRUE) {
        GUI_init();
        xSemaphoreGive(xGuiSemaphore);
    }

    // Create Tasks
    LOG_INFO("Creating LVGL task");
    xTaskCreatePinnedToCore(lvgl_task, "Lvgl", 8192, NULL, 5, &xLvglTaskHandle,
                            1);
    LOG_INFO("Creating update view task");
    xTaskCreatePinnedToCore(updateViewTask, "UpdateView", 16384, NULL, 1,
                            &xUpdateViewTask, 0);
    LOG_INFO("Creating data initialization task");
    xTaskCreatePinnedToCore(initializeTask, "DataInit", 4096, NULL, 1,
                            &xDataInitTaskHandle, 0);

    LOG_INFO("Completed setup");
}

void loop() { vTaskDelay(10000); }
