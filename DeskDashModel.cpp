#include "DeskDash.h"

#define INVALID_WTH_CODE 100

const char *ntpServer = "pool.ntp.org";

DeskDashModel::DeskDashModel() {
    data.weather.curTemp = 0.0f;
    data.weather.maxTemp = 0.0f;
    data.weather.minTemp = 0.0f;
    data.weather.wthCode = INVALID_WTH_CODE;
    data.weather.isDay = 0;
    data.timeInfo.tm_hour = 0;
    data.timeInfo.tm_min = 0;
    data.timeInfo.tm_wday = 0;
    data.timeInfo.tm_mday = 0;
    data.timeInfo.tm_mon = 0;
    data.timeInfo.tm_year = 0;
    for (int i = 0; i < 10; i++) {
        data.forecast[i].hour = 0;
        data.forecast[i].temperature = 0.0f;
        data.forecast[i].wthCode = INVALID_WTH_CODE;
        data.forecast[i].isDay = 0;
    }
    data.isTimeSynced = false;
    data.isWthInitDone = false;
    data.isForecastInitDone = false;
}

int DeskDashModel::setConfig(const char *configFilePath) {
    int status = 0;
    File cfgFile;

    LOG_INFO("Mounting filesystem");
    if (!LittleFS.begin(false)) {
        LOG_ERROR("LittleFS mount failed!");
        status = -1;
    }

    if (status == 0) {
        cfgFile = LittleFS.open(configFilePath, "r");
        if (!cfgFile) {
            LOG_ERROR("Failed to open config file: %s", configFilePath);
            status = -1;
        }
    }

    if (status == 0) {
        DeserializationError error = deserializeJson(cfg, cfgFile);
        if (error) {
            LOG_ERROR("Failed to parse config file: %s", error.c_str());
            status = -1;
        }
    }

    if (cfgFile) {
        cfgFile.close();
    }

    return status;
}

int DeskDashModel::initData() {
    int status = 0;

    const long gmtOffset = cfg["gmtOffset"].as<long>();
    const int daylightOffset = cfg["dlOffset"].as<int>();

    configTime(gmtOffset, daylightOffset, ntpServer);
    updateTime();
    while (data.timeInfo.tm_year < (2010 - 1900)) {
        vTaskDelay(pdMS_TO_TICKS(500));
        updateTime();
    }
    data.isTimeSynced = true;

    status = updateWeather();
    if (status == 0) {
        status = updateForecast();
    }

    return status;
}

void DeskDashModel::updateTime() { getLocalTime(&data.timeInfo); }

int DeskDashModel::updateWeather() {
    const float latitude = cfg["latitude"].as<float>();
    const float longitude = cfg["longitude"].as<float>();

    int status = 0;
    HTTPClient http;
    JsonDocument weatherDoc;
    DeserializationError error;

    char url[200];
    snprintf(url, sizeof(url),
             "https://api.open-meteo.com/v1/"
             "forecast?latitude=%.2f&longitude=%.2f&daily=temperature_2m_max,"
             "temperature_2m_min&current=temperature_2m,weather_code,is_day&"
             "timezone=auto&forecast_days=1",
             latitude, longitude);

    LOG_INFO("Fetching weather data");
    http.begin(url);
    int httpResCode = http.GET();
    if (httpResCode == 200) {
        String payload = http.getString();
        error = deserializeJson(weatherDoc, payload);
        if (error) {
            LOG_ERROR("Failed to parse weather data: %s", error.c_str());
            status = -1;
        }

        if (status == 0) {
            data.weather.curTemp =
                weatherDoc["current"]["temperature_2m"].as<float>();
            data.weather.maxTemp =
                weatherDoc["daily"]["temperature_2m_max"][0].as<float>();
            data.weather.minTemp =
                weatherDoc["daily"]["temperature_2m_min"][0].as<float>();
            data.weather.wthCode =
                weatherDoc["current"]["weather_code"].as<int>();
            data.weather.isDay = weatherDoc["current"]["is_day"].as<int>();
        }
    } else {
        LOG_ERROR("Failed to fetch weather data. HTTP response code: %d",
                  httpResCode);
        status = -1;
    }
    http.end();

    if (!data.isWthInitDone && status == 0) {
        data.isWthInitDone = true;
    }

    return status;
}

int DeskDashModel::updateForecast() {
    const float latitude = cfg["latitude"].as<float>();
    const float longitude = cfg["longitude"].as<float>();
    tm startTime, endTime;
    int status = 0;

    HTTPClient http;
    JsonDocument forecastDoc;
    DeserializationError error;

    // Start forecast from the next hour (included)
    startTime = data.timeInfo;
    startTime.tm_hour += 1;
    mktime(&startTime);

    // End forecast 10 hours later
    endTime = startTime;
    endTime.tm_hour += 9;
    mktime(&endTime);

    char url[200];
    snprintf(
        url, sizeof(url),
        "https://api.open-meteo.com/v1/"
        "forecast?latitude=%.2f&longitude=%.2f&hourly=temperature_2m,"
        "weather_code,is_day&timezone=auto&start_hour=%04d-%02d-%02dT%02d:00&"
        "end_hour=%04d-%02d-%02dT%02d:00",
        latitude, longitude, startTime.tm_year + 1900, startTime.tm_mon + 1,
        startTime.tm_mday, startTime.tm_hour, endTime.tm_year + 1900,
        endTime.tm_mon + 1, endTime.tm_mday, endTime.tm_hour);

    LOG_INFO("Fetching forecast data");
    http.begin(url);
    int httpResCode = http.GET();
    if (httpResCode == 200) {
        String payload = http.getString();
        error = deserializeJson(forecastDoc, payload);
        if (error) {
            LOG_ERROR("Failed to parse forecast data: %s", error.c_str());
            status = -1;
        }

        if (status == 0) {
            for (int i = 0; i < 10; i++) {
                data.forecast[i].hour = (startTime.tm_hour + i) % 24;
                data.forecast[i].temperature =
                    forecastDoc["hourly"]["temperature_2m"][i].as<float>();
                data.forecast[i].wthCode =
                    forecastDoc["hourly"]["weather_code"][i].as<int>();
                data.forecast[i].isDay =
                    forecastDoc["hourly"]["is_day"][i].as<int>();
            }
        }
    } else {
        LOG_ERROR("Failed to fetch forecast data. HTTP response code: %d",
                  httpResCode);
        status = -1;
    }
    http.end();

    if (!data.isForecastInitDone && status == 0) {
        data.isForecastInitDone = true;
    }

    return status;
}

DeskDashData DeskDashModel::getData() { return data; }

JsonDocument &DeskDashModel::getConfig() { return cfg; }
