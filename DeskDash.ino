#include <lvgl.h>
#include <M5Unified.h>
#include <M5GFX.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <time.h>
#include "esp_sntp.h"
#include <FreeRTOS.h>
#include "GUI.h"
#include "FS.h"
#include <LittleFS.h>
#include <ArduinoJson.h>

#define LOG_LEVEL_NONE 0
#define LOG_LEVEL_ERROR 1
#define LOG_LEVEL_WARN 2
#define LOG_LEVEL_INFO 3

#define ACTIVE_LOG_LEVEL LOG_LEVEL_ERROR

#if ACTIVE_LOG_LEVEL >= LOG_LEVEL_ERROR
#define LOG_ERROR(fmt, ...) Serial.printf("[ERROR] " fmt "\n", ##__VA_ARGS__)
#else
#define LOG_ERROR(fmt, ...)
#endif

#if ACTIVE_LOG_LEVEL >= LOG_LEVEL_WARN
#define LOG_WARN(fmt, ...) Serial.printf("[WARN] " fmt "\n", ##__VA_ARGS__)
#else
#define LOG_WARN(fmt, ...)
#endif

#if ACTIVE_LOG_LEVEL >= LOG_LEVEL_INFO
#define LOG_INFO(fmt, ...) Serial.printf("[INFO] " fmt "\n", ##__VA_ARGS__)
#else
#define LOG_INFO(fmt, ...)
#endif

/* Screen resolution */
#define TFT_HOR_RES 1280
#define TFT_VER_RES 720

/* LVGL draw buffers. These are allocated from PSRAM for the full screen */
#define DRAW_BUF_SIZE (TFT_HOR_RES * TFT_VER_RES * (LV_COLOR_DEPTH / 8))
void *drawBuf1 = NULL;
void *drawBuf2 = NULL;

/* Display object and input object */
lv_display_t *glbDisp;
lv_indev_t *indev;

/* JSON parser */
JsonDocument cfgDoc;
JsonDocument weatherDoc;
DeserializationError error;
File cfgFile;

/* HTTP Client */
HTTPClient http;

/* Configurations */
const char *ntpServer = "pool.ntp.org";

/* Embedded constants */
const char monthStr[12][10] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
const char dayStr[7][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

/* Task Handles */
TaskHandle_t xLvglTaskHandle = NULL;
TaskHandle_t xInfoSyncTaskHandle = NULL;
TaskHandle_t xDrawScreenTaskHandle = NULL;

/* Mutex to handle resources for LVGL */
SemaphoreHandle_t xGuiSemaphore;

struct tm timeInfo;
uint8_t prevScreen = 0;
uint8_t curScreen = 0;
uint8_t syncState = 0;
bool initDone = false;
bool wthInitDone = false;

/* Function to flush draw buffer to display */
void lv_disp_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *color_p) {
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
  uint8_t touchpad = M5.Display.getTouchRaw(tp, 3);
  if (touchpad > 0) {
    data->state = LV_INDEV_STATE_PR;
    data->point.x = tp[0].x;
    data->point.y = tp[0].y;
    //Serial.printf("X: %d   Y: %d\n", tp[0].x, tp[0].y); //for testing
  } else {
    data->state = LV_INDEV_STATE_REL;
  }
}

/* Custom tick */
static uint32_t my_tick(void) {
  return millis();
}

/* Convert weather code to string */
void wth_code_to_string(int wthCode, char *wthStr, size_t strSize) {
  if (wthCode == 0) {
    snprintf(wthStr, strSize, "Clear");
  } else if (wthCode >= 1 && wthCode <= 2) {
    snprintf(wthStr, strSize, "Partly Cloudy");
  } else if (wthCode == 3) {
    snprintf(wthStr, strSize, "Cloudy");
  } else if (wthCode >= 45 && wthCode <= 48) {
    snprintf(wthStr, strSize, "Fog");
  } else if ((wthCode >= 51 && wthCode <= 57) || (wthCode >= 61 && wthCode <= 67) || (wthCode >= 80 && wthCode <= 82)) {
    snprintf(wthStr, strSize, "Rain");
  } else if ((wthCode >= 71 && wthCode <= 77) || (wthCode >= 85 && wthCode <= 86)) {
    snprintf(wthStr, strSize, "Snow");
  } else if (wthCode >= 95 && wthCode <= 99) {
    snprintf(wthStr, strSize, "Thunderstorm");
  } else {
    snprintf(wthStr, strSize, "Unknown");
  }
}

/* Convert weather code to image (use with Mutex lock)*/
void wth_code_to_img(int wthCode, int is_day) {
  bool isValidCode = true;

  if (wthCode != -1) {
    if (wthCode == 0) {
      if(is_day) {
        lv_image_set_src(GUI_Image__mainScreen__wthIcon, &sun);
      } else {
        lv_image_set_src(GUI_Image__mainScreen__wthIcon, &moon);
      }
    } else if (wthCode >= 1 && wthCode <= 2) {
      if(is_day) {
        lv_image_set_src(GUI_Image__mainScreen__wthIcon, &sun_cloud);
      } else {
        lv_image_set_src(GUI_Image__mainScreen__wthIcon, &moon_cloud);
      }
    } else if (wthCode == 3) {
      lv_image_set_src(GUI_Image__mainScreen__wthIcon, &cloud);
    } else if (wthCode >= 45 && wthCode <= 48) {
      lv_image_set_src(GUI_Image__mainScreen__wthIcon, &haze);
    } else if ((wthCode >= 51 && wthCode <= 57) || (wthCode >= 61 && wthCode <= 67) || (wthCode >= 80 && wthCode <= 82)) {
      lv_image_set_src(GUI_Image__mainScreen__wthIcon, &rain);
    } else if ((wthCode >= 71 && wthCode <= 77) || (wthCode >= 85 && wthCode <= 86)) {
      lv_image_set_src(GUI_Image__mainScreen__wthIcon, &snow);
    } else if (wthCode >= 95 && wthCode <= 99) {
      lv_image_set_src(GUI_Image__mainScreen__wthIcon, &thunder);
    } else {
      isValidCode = false;
    }

    if (isValidCode) {
      lv_obj_remove_flag(GUI_Image__mainScreen__wthIcon, LV_OBJ_FLAG_HIDDEN);
    } else {
      lv_obj_add_flag(GUI_Image__mainScreen__wthIcon, LV_OBJ_FLAG_HIDDEN);
    }
  } else {
    lv_obj_add_flag(GUI_Image__mainScreen__wthIcon, LV_OBJ_FLAG_HIDDEN);
  }
}

/* LVGL task to refresh display */
void lvgl_task(void *pvParameters) {
  while (1) {
    if (xSemaphoreTake(xGuiSemaphore, portMAX_DELAY) == pdTRUE) {
      lv_timer_handler();
      xSemaphoreGive(xGuiSemaphore);
    }
    vTaskDelay(pdMS_TO_TICKS(5));
  }
}

/* Information sync task */
void info_sync_task(void *pvParameters) {
  const uint32_t sync_interval = 3 * 60 * 60 * 1000;  // 3 hours in ms

  // Extract data from JSON
  const char *wifiSsid = cfgDoc["wifi"][0]["ssid"];
  const char *wifiPwd = cfgDoc["wifi"][0]["pwd"];
  const long gmtOffset = cfgDoc["gmtOffset"];
  const int daylightOffset = cfgDoc["dlOffset"];
  const float latitude = cfgDoc["latitude"];
  const float longitude = cfgDoc["longitude"];

  char url[200];
  snprintf(url, sizeof(url), "https://api.open-meteo.com/v1/forecast?latitude=%.4f&longitude=%.4f&daily=temperature_2m_max,temperature_2m_min&current=temperature_2m,weather_code,is_day&timezone=auto&forecast_days=1", latitude, longitude);

  while (1) {
    syncState = 1;

    LOG_INFO("Connecting to wifi with SSID: %s. PWD: %s", wifiSsid, wifiPwd);
    WiFi.mode(WIFI_STA);
    WiFi.begin(wifiSsid, wifiPwd);
    while (WiFi.status() != WL_CONNECTED) {
      vTaskDelay(500);
    }
    LOG_INFO("Connected to wifi");
    syncState = 2;

    LOG_INFO("Syncing Time with GMT offset: %llu, daylight offset: %d", gmtOffset, daylightOffset);
    configTime(gmtOffset, daylightOffset, ntpServer);
    while (sntp_get_sync_status() != SNTP_SYNC_STATUS_COMPLETED) {
      vTaskDelay(500);
    }
    LOG_INFO("Time sync completed");
    syncState = 3;

    LOG_INFO("Fetching weather data from URL: %s", url);
    http.begin(url);
    int httpResCode = http.GET();
    LOG_INFO("Server responded with code %d", httpResCode);
    if (httpResCode == 200) {
      String payload = http.getString();
      error = deserializeJson(weatherDoc, payload);
      if (error) {
        LOG_ERROR("Failed to parse weather data");
      } else {
        LOG_INFO("Weather data sync completed");
        LOG_INFO("Current Temperature: %.2f", weatherDoc["current"]["temperature_2m"].as<float>());
        wthInitDone = true;
      }
    }
    syncState = 4;

    LOG_INFO("Disconnecting from wifi");
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
    syncState = 5;

    if (!initDone) {
      initDone = true;
      curScreen = 1;
    }

    vTaskDelay(pdMS_TO_TICKS(sync_interval));
  }
}

/* Draw screen task */
void draw_screen_task(void *pvParameters) {
  char timeStr[6] = "10:10";
  char dStr[10] = "Sunday";
  char dateStr[20] = "January 01, 1970";
  char tempStr[10] = "--°C";
  char tempMinMaxStr[25] = "H: --° | L: --°";
  char wthStr[20] = "--";
  const char *city = cfgDoc["city"];
  int wthCode = -1;
  int isDay = -1;
  bool newDay = false;
  bool isNewDay = false;

  while (1) {
    if ((curScreen == 1) && (prevScreen != 1)) {
      LOG_INFO("Changing screen: %d -> %d", prevScreen, curScreen);
      prevScreen = curScreen;
      getLocalTime(&timeInfo);
      snprintf(timeStr, sizeof(timeStr), "%02d:%02d", timeInfo.tm_hour, timeInfo.tm_min);
      snprintf(dStr, sizeof(dStr), "%s", dayStr[timeInfo.tm_wday]);
      snprintf(dateStr, sizeof(dateStr), "%s %02d, %04d", monthStr[timeInfo.tm_mon], timeInfo.tm_mday, (1900 + timeInfo.tm_year));
      if(wthInitDone) {
        wthInitDone = false;
        snprintf(tempStr, sizeof(tempStr), "%.1f°C", weatherDoc["current"]["temperature_2m"].as<float>());
        snprintf(tempMinMaxStr, sizeof(tempMinMaxStr), "H: %.0f° | L: %.0f°", weatherDoc["daily"]["temperature_2m_max"][0].as<float>(), weatherDoc["daily"]["temperature_2m_min"][0].as<float>());
        wthCode = weatherDoc["current"]["weather_code"].as<int>();
        isDay = weatherDoc["current"]["is_day"].as<int>();
        wth_code_to_string(wthCode, wthStr, sizeof(wthStr));
      }

      if (xSemaphoreTake(xGuiSemaphore, portMAX_DELAY) == pdTRUE) {
        lv_label_set_text(GUI_Label__mainScreen__timeLabel, timeStr);
        lv_label_set_text(GUI_Label__mainScreen__dayLabel, dStr);
        lv_label_set_text(GUI_Label__mainScreen__dateLabel, dateStr);
        lv_label_set_text(GUI_Label__mainScreen__locLabel, city);
        lv_label_set_text(GUI_Label__mainScreen__tempLabel, tempStr);
        lv_label_set_text(GUI_Label__mainScreen__minMaxLabel, tempMinMaxStr);
        lv_label_set_text(GUI_Label__mainScreen__wthLabel, wthStr);
        wth_code_to_img(wthCode, isDay);
        lv_screen_load(GUI_Screen__mainScreen);
        xSemaphoreGive(xGuiSemaphore);
      }

      LOG_INFO("Screen change complete");
    }

    if (curScreen == 0) {
      if (xSemaphoreTake(xGuiSemaphore, portMAX_DELAY) == pdTRUE) {
        lv_bar_set_value(GUI_Bar__splashScreen__initBar, (20 * syncState), LV_ANIM_OFF);
        xSemaphoreGive(xGuiSemaphore);
      }
    } else if (curScreen == 1) {
      getLocalTime(&timeInfo);
      snprintf(timeStr, sizeof(timeStr), "%02d:%02d", timeInfo.tm_hour, timeInfo.tm_min);
      if (timeInfo.tm_hour == 0 && !newDay) {
        snprintf(dStr, sizeof(dStr), "%s", dayStr[timeInfo.tm_wday]);
        snprintf(dateStr, sizeof(dateStr), "%s %02d, %04d", monthStr[timeInfo.tm_mon], timeInfo.tm_mday, (1900 + timeInfo.tm_year));
        newDay = true;
        isNewDay = true;
      } else if (timeInfo.tm_hour != 0) {
        newDay = false;
      }
      if (wthInitDone) {
        snprintf(tempStr, sizeof(tempStr), "%.1f°C", weatherDoc["current"]["temperature_2m"].as<float>());
        snprintf(tempMinMaxStr, sizeof(tempMinMaxStr), "H: %.0f° | L: %.0f°", weatherDoc["daily"]["temperature_2m_max"][0].as<float>(), weatherDoc["daily"]["temperature_2m_min"][0].as<float>());
        wthCode = weatherDoc["current"]["weather_code"].as<int>();
        isDay = weatherDoc["current"]["is_day"].as<int>();
        wth_code_to_string(wthCode, wthStr, sizeof(wthStr));
      }

      if (xSemaphoreTake(xGuiSemaphore, portMAX_DELAY) == pdTRUE) {
        lv_label_set_text(GUI_Label__mainScreen__timeLabel, timeStr);
        if (isNewDay) {
          lv_label_set_text(GUI_Label__mainScreen__dayLabel, dStr);
          lv_label_set_text(GUI_Label__mainScreen__dateLabel, dateStr);
          isNewDay = false;
        }
        if (wthInitDone) {
          wthInitDone = false;
          lv_label_set_text(GUI_Label__mainScreen__tempLabel, tempStr);
          lv_label_set_text(GUI_Label__mainScreen__minMaxLabel, tempMinMaxStr);
          lv_label_set_text(GUI_Label__mainScreen__wthLabel, wthStr);
          wth_code_to_img(wthCode, isDay);
        }
        xSemaphoreGive(xGuiSemaphore);
      }
    }

    vTaskDelay(pdMS_TO_TICKS(5000));
  }
}

/* Initial setup */
void setup() {
#if ACTIVE_LOG_LEVEL >= LOG_LEVEL_ERROR
  Serial.begin(115200);
#endif
  LOG_INFO("Initializing M5Tab5");
  auto cfg = M5.config();
  M5.begin(cfg);
  sntp_set_sync_mode(SNTP_SYNC_MODE_IMMED);
  M5.Display.setRotation(1);

  // Allocate draw buffers from PSRAM
  LOG_INFO("Allocating memory for draw buffer");
  drawBuf1 = (uint8_t *)heap_caps_aligned_alloc(64, DRAW_BUF_SIZE, MALLOC_CAP_SPIRAM);
  drawBuf2 = (uint8_t *)heap_caps_aligned_alloc(64, DRAW_BUF_SIZE, MALLOC_CAP_SPIRAM);

  if (drawBuf1 == NULL || drawBuf2 == NULL) {
    LOG_ERROR("Failed to allocate memory for draw buffer!");
    return;
  }

  LOG_INFO("Mounting filesystem");
  if (!LittleFS.begin(false)) {
    LOG_ERROR("LittleFS mount failed!");
    return;
  }

  LOG_INFO("Opening config file");
  cfgFile = LittleFS.open("/config.json");
  if (!cfgFile) {
    LOG_ERROR("Failed to open file!");
    return;
  }

  LOG_INFO("Parsing config file");
  error = deserializeJson(cfgDoc, cfgFile);
  cfgFile.close();
  if (error) {
    LOG_ERROR("Failed to parse config file");
    return;
  }

  LOG_INFO("Initializing LVGL");
  lv_init();
  lv_tick_set_cb(my_tick);

  glbDisp = lv_display_create(TFT_HOR_RES, TFT_VER_RES);
  lv_display_set_flush_cb(glbDisp, lv_disp_flush);
  lv_display_set_buffers(glbDisp, drawBuf1, drawBuf2, DRAW_BUF_SIZE, LV_DISPLAY_RENDER_MODE_FULL);

  indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, lv_indev_read);

  xGuiSemaphore = xSemaphoreCreateMutex();

  if (xSemaphoreTake(xGuiSemaphore, portMAX_DELAY) == pdTRUE) {
    GUI_init();
    xSemaphoreGive(xGuiSemaphore);
  }

  // Create Tasks
  LOG_INFO("Creating LVGL task");
  xTaskCreatePinnedToCore(lvgl_task, "Lvgl", 8192, NULL, 5, &xLvglTaskHandle, 1);
  LOG_INFO("Creating info sync task");
  xTaskCreatePinnedToCore(info_sync_task, "InfoSync", 4096, NULL, 1, &xInfoSyncTaskHandle, 0);
  LOG_INFO("Creating screen drawer task");
  xTaskCreatePinnedToCore(draw_screen_task, "DrawScreen", 16384, NULL, 1, &xDrawScreenTaskHandle, 0);

  LOG_INFO("Completed Initialization");
}

void loop() {
  vTaskDelay(10000);
}
