#include "DeskDash.h"

const char *ntpServer = "pool.ntp.org";

DeskDashModel::DeskDashModel() {
    data.weather.curTemp = 0.0f;
    data.weather.maxTemp = 0.0f;
    data.weather.minTemp = 0.0f;
    data.weather.wthCode = 0;
    data.weather.isDay = 0;
    data.timeInfo.tm_hour = 0;
    data.timeInfo.tm_min = 0;
    data.timeInfo.tm_wday = 0;
    data.timeInfo.tm_mday = 0;
    data.timeInfo.tm_mon = 0;
    data.timeInfo.tm_year = 0;
    data.isTimeSynced = false;
    data.isWthInitDone = false;
}

int DeskDashModel::setConfig(const char *configFilePath) {
    LOG_INFO("Mounting filesystem");
    if (!LittleFS.begin(false)) {
        LOG_ERROR("LittleFS mount failed!");
        return -1;
    }

    File cfgFile = LittleFS.open(configFilePath, "r");
    if (!cfgFile) {
        LOG_ERROR("Failed to open config file: %s", configFilePath);
        return -1;
    }
    DeserializationError error = deserializeJson(cfg, cfgFile);
    if (error) {
        LOG_ERROR("Failed to parse config file: %s", error.c_str());
        return -1;
    }
    cfgFile.close();
    return 0;
}

int DeskDashModel::initData() {
    int status = 0;

    const long gmtOffset = cfg["gmtOffset"].as<long>();
    const int daylightOffset = cfg["dlOffset"].as<int>();

    status = updateWeather();
    if (status == -1) {
        // Return immediately since device is not connected to WiFi
        return -1;
    }

    configTime(gmtOffset, daylightOffset, ntpServer);
    updateTime();
    while (data.timeInfo.tm_year < (2010 - 1900)) {
        vTaskDelay(pdMS_TO_TICKS(500));
        updateTime();
    }
    data.isTimeSynced = true;
    return status;
}

void DeskDashModel::updateTime() {
    getLocalTime(&data.timeInfo);
}

int DeskDashModel::updateWeather() { 
    const float latitude = cfg["latitude"].as<float>();
    const float longitude = cfg["longitude"].as<float>();

    HTTPClient http;
    JsonDocument weatherDoc;

    char url[200];
    snprintf(url, sizeof(url), "https://api.open-meteo.com/v1/forecast?latitude=%.4f&longitude=%.4f&daily=temperature_2m_max,temperature_2m_min&current=temperature_2m,weather_code,is_day&timezone=auto&forecast_days=1", latitude, longitude);

    http.begin(url);
    int httpResCode = http.GET();
    if (httpResCode == 200) {
        String payload = http.getString();
        DeserializationError error = deserializeJson(weatherDoc, payload);
        if (error) {
            LOG_ERROR("Failed to parse weather data: %s", error.c_str());
            return -1;
        }
        data.weather.curTemp = weatherDoc["current"]["temperature_2m"].as<float>();
        data.weather.maxTemp = weatherDoc["daily"]["temperature_2m_max"][0].as<float>();
        data.weather.minTemp = weatherDoc["daily"]["temperature_2m_min"][0].as<float>();
        data.weather.wthCode = weatherDoc["current"]["weather_code"].as<int>();
        data.weather.isDay = weatherDoc["current"]["is_day"].as<int>();
    } else if (httpResCode < 0) {
        LOG_WARN("Weather update failed, not connected to network");
        return -1;
    } else {
        LOG_ERROR("Failed to fetch weather data. HTTP response code: %d", httpResCode);
        return -2;
    }

    if(!data.isWthInitDone) {
        data.isWthInitDone = true;
    }

    return 0;
}

DeskDashData DeskDashModel::getData() {
    return data;
}

JsonDocument& DeskDashModel::getConfig() {
    return cfg;
}
