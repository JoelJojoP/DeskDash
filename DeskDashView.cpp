#include "DeskDash.h"

DeskDashView::DeskDashView() {
    // Nothing to initialize in the constructor for now
}

void DeskDashView::toggleWifiIcon(bool isConnected) {
    if (xSemaphoreTake(xGuiSemaphore, portMAX_DELAY) == pdTRUE) {
        if (isConnected) {
            lv_label_set_text(GUI_Label__topLayer__wifiLabel, WIFI_ICON);
        } else {
            lv_label_set_text(GUI_Label__topLayer__wifiLabel, REFRESH_ICON);
        }
        xSemaphoreGive(xGuiSemaphore);
    }
}

void DeskDashView::changeScreen() {
    if (xSemaphoreTake(xGuiSemaphore, portMAX_DELAY) == pdTRUE) {
        lv_display_trigger_activity(NULL);
        lv_screen_load(GUI_Screen__mainScreen);
        lv_obj_remove_flag(GUI_Panel__topLayer__selIndicator, LV_OBJ_FLAG_HIDDEN);
        initDone = true;
        xSemaphoreGive(xGuiSemaphore);
    }
}

void DeskDashView::toggleForecastPanel(bool show) {
    if (xSemaphoreTake(xGuiSemaphore, portMAX_DELAY) == pdTRUE) {
        if (show) {
            lv_obj_remove_flag(GUI_Container__mainScreen__fcContainer, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(GUI_Label__mainScreen__fcLabel, LV_OBJ_FLAG_HIDDEN);
        } else {
            lv_obj_add_flag(GUI_Container__mainScreen__fcContainer, LV_OBJ_FLAG_HIDDEN);
            lv_obj_remove_flag(GUI_Label__mainScreen__fcLabel, LV_OBJ_FLAG_HIDDEN);
        }
        xSemaphoreGive(xGuiSemaphore);
    }
}

void DeskDashView::updateTime(const char *timeStr) {
    if (xSemaphoreTake(xGuiSemaphore, portMAX_DELAY) == pdTRUE) {
        lv_label_set_text(GUI_Label__mainScreen__timeLabel, timeStr);
        xSemaphoreGive(xGuiSemaphore);
    }
}

void DeskDashView::updateDate(const char *dateStr, const char *dayStr) {
    if (xSemaphoreTake(xGuiSemaphore, portMAX_DELAY) == pdTRUE) {
        lv_label_set_text(GUI_Label__mainScreen__dayLabel, dayStr);
        lv_label_set_text(GUI_Label__mainScreen__dateLabel, dateStr);
        xSemaphoreGive(xGuiSemaphore);
    }
}

void DeskDashView::updateWeather(const char *curTempStr,
                                 const char *minMaxTempStr, const char *wthStr,
                                 int wthCode, int isDay) {
    if (xSemaphoreTake(xGuiSemaphore, portMAX_DELAY) == pdTRUE) {
        lv_label_set_text(GUI_Label__mainScreen__tempLabel, curTempStr);
        lv_label_set_text(GUI_Label__mainScreen__minMaxLabel, minMaxTempStr);
        lv_label_set_text(GUI_Label__mainScreen__wthLabel, wthStr);
        updateWeatherIcon(GUI_Image__mainScreen__wthIcon, wthCode, isDay);
        xSemaphoreGive(xGuiSemaphore);
    }
}

void DeskDashView::updateForecast(const char *timeStr, const char *tempStr, int wthCode, int isDay, int idx) {
    if (xSemaphoreTake(xGuiSemaphore, portMAX_DELAY) == pdTRUE) {
        lv_label_set_text(GUI_Label__mainScreen__fcTimeLabel[idx], timeStr);
        lv_label_set_text(GUI_Label__mainScreen__fcTempLabel[idx], tempStr);
        updateWeatherIcon(GUI_Image__mainScreen__fcWthIcon[idx], wthCode, isDay);
        xSemaphoreGive(xGuiSemaphore);
    }
}

void DeskDashView::updateLocation(const char *locationStr) {
    if (xSemaphoreTake(xGuiSemaphore, portMAX_DELAY) == pdTRUE) {
        lv_label_set_text(GUI_Label__mainScreen__locationLabel, locationStr);
        xSemaphoreGive(xGuiSemaphore);
    }
}

void DeskDashView::updateWeatherIcon(lv_obj_t *wthIcon, int wthCode,
                                     int isDay) {
    bool isValidCode = true;
    if (wthCode != -1) {
        if (wthCode == 0) {
            if (isDay) {
                lv_image_set_src(wthIcon, &sun);
            } else {
                lv_image_set_src(wthIcon, &moon);
            }
        } else if (wthCode >= 1 && wthCode <= 2) {
            if (isDay) {
                lv_image_set_src(wthIcon, &sun_cloud);
            } else {
                lv_image_set_src(wthIcon, &moon_cloud);
            }
        } else if (wthCode == 3) {
            lv_image_set_src(wthIcon, &cloud);
        } else if (wthCode >= 45 && wthCode <= 48) {
            lv_image_set_src(wthIcon, &haze);
        } else if ((wthCode >= 51 && wthCode <= 57) ||
                   (wthCode >= 61 && wthCode <= 67) ||
                   (wthCode >= 80 && wthCode <= 82)) {
            lv_image_set_src(wthIcon, &rain);
        } else if ((wthCode >= 71 && wthCode <= 77) ||
                   (wthCode >= 85 && wthCode <= 86)) {
            lv_image_set_src(wthIcon, &snow);
        } else if (wthCode >= 95 && wthCode <= 99) {
            lv_image_set_src(wthIcon, &thunder);
        } else {
            isValidCode = false;
        }

        if (isValidCode) {
            lv_obj_remove_flag(wthIcon, LV_OBJ_FLAG_HIDDEN);
        } else {
            lv_obj_add_flag(wthIcon, LV_OBJ_FLAG_HIDDEN);
        }
    } else {
        lv_obj_add_flag(wthIcon, LV_OBJ_FLAG_HIDDEN);
    }
}