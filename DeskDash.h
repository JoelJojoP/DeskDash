#include "FS.h"
#include "GUI.h"
#include <ArduinoJson.h>
#include <FreeRTOS.h>
#include <HTTPClient.h>
#include <LittleFS.h>
#include <M5GFX.h>
#include <M5Unified.h>
#include <WiFi.h>
#include <lvgl.h>
#include <time.h>

/* Logging */
#define LOG_LEVEL_NONE 0
#define LOG_LEVEL_ERROR 1
#define LOG_LEVEL_WARN 2
#define LOG_LEVEL_INFO 3

/* Active log level settings */
#define ACTIVE_LOG_LEVEL LOG_LEVEL_ERROR

#if ACTIVE_LOG_LEVEL >= LOG_LEVEL_ERROR
#define LOG_ERROR(fmt, ...)                                                    \
    xSemaphoreTake(xUartSemaphore, portMAX_DELAY);                             \
    Serial.printf("[ERROR] " fmt "\n", ##__VA_ARGS__);                         \
    xSemaphoreGive(xUartSemaphore)
#else
#define LOG_ERROR(fmt, ...)
#endif

#if ACTIVE_LOG_LEVEL >= LOG_LEVEL_WARN
#define LOG_WARN(fmt, ...)                                                     \
    xSemaphoreTake(xUartSemaphore, portMAX_DELAY);                             \
    Serial.printf("[WARN] " fmt "\n", ##__VA_ARGS__);                          \
    xSemaphoreGive(xUartSemaphore)
#else
#define LOG_WARN(fmt, ...)
#endif

#if ACTIVE_LOG_LEVEL >= LOG_LEVEL_INFO
#define LOG_INFO(fmt, ...)                                                     \
    xSemaphoreTake(xUartSemaphore, portMAX_DELAY);                             \
    Serial.printf("[INFO] " fmt "\n", ##__VA_ARGS__);                          \
    xSemaphoreGive(xUartSemaphore)
#else
#define LOG_INFO(fmt, ...)
#endif

/* Screen resolution */
#define TFT_HOR_RES 1280
#define TFT_VER_RES 720

/* Touchscreen interrupt pin */
#define TOUCH_INT_PIN 23

/* Disaply backlight pin */
#define DISP_BL_PIN 22

#define TIME_UPDATE_EVENT (1 << 0)
#define DAY_UPDATE_EVENT (1 << 1)
#define WEATHER_UPDATE_EVENT (1 << 2)
#define SCREEN_CHANGE_EVENT (1 << 3)

extern SemaphoreHandle_t xGuiSemaphore;

#if ACTIVE_LOG_LEVEL >= LOG_LEVEL_ERROR
extern SemaphoreHandle_t xUartSemaphore;
#endif

typedef struct {
    float curTemp;
    float maxTemp;
    float minTemp;
    int wthCode;
    int isDay;
} WeatherInfo;

typedef struct {
    struct tm timeInfo;
    WeatherInfo weather;
    bool isTimeSynced;
    bool isWthInitDone;
} DeskDashData;

class DeskDashModel {
  private:
    DeskDashData data;
    JsonDocument cfg;

  public:
    DeskDashModel();
    int setConfig(const char *configFilePath);
    int updateWeather();
    void updateTime();
    int initData();
    DeskDashData getData();
    JsonDocument &getConfig();
};

class DeskDashView {
  private:
  public:
    DeskDashView();
    void changeScreen();
    void updateTime(const char *timeStr);
    void updateDate(const char *dateStr, const char *dayStr);
    void updateWeather(const char *curTempStr, const char *minMaxTempStr,
                       const char *wthStr);
    void updateWeatherIcon(int wthCode, int isDay = 1);
    void updateLocation(const char *locationStr);
};

/* Function declarations */
void go_sleep();
void wake_up();