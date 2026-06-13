#include "DeskDash.h"

DeskDashView::DeskDashView() {
    // Nothing to initialize in the constructor for now
}

void DeskDashView::changeScreen() {
    if (xSemaphoreTake(xGuiSemaphore, portMAX_DELAY) == pdTRUE) {
        lv_screen_load(GUI_Screen__mainScreen);
        lv_obj_remove_flag(GUI_Panel__mainScreen__sideBar, LV_OBJ_FLAG_HIDDEN);
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

void DeskDashView::updateWeather(const char *curTempStr, const char *minMaxTempStr, const char *wthStr) {
    if (xSemaphoreTake(xGuiSemaphore, portMAX_DELAY) == pdTRUE) {
        lv_label_set_text(GUI_Label__mainScreen__tempLabel, curTempStr);
        lv_label_set_text(GUI_Label__mainScreen__minMaxLabel, minMaxTempStr);
        lv_label_set_text(GUI_Label__mainScreen__wthLabel, wthStr);
        xSemaphoreGive(xGuiSemaphore);
    }
}

void DeskDashView::updateWeatherIcon(int wthCode, int isDay) {
    bool isValidCode = true;
    if (xSemaphoreTake(xGuiSemaphore, portMAX_DELAY) == pdTRUE) {
        if (wthCode != -1) {
            if (wthCode == 0) {
                if(isDay) {
                    lv_image_set_src(GUI_Image__mainScreen__wthIcon, &sun);
                } else {
                    lv_image_set_src(GUI_Image__mainScreen__wthIcon, &moon);
                }
            } else if (wthCode >= 1 && wthCode <= 2) {
                if(isDay) {
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
        xSemaphoreGive(xGuiSemaphore);
    }
}

void DeskDashView::updateLocation(const char *locationStr) {
    if (xSemaphoreTake(xGuiSemaphore, portMAX_DELAY) == pdTRUE) {
        lv_label_set_text(GUI_Label__mainScreen__locLabel, locationStr);
        xSemaphoreGive(xGuiSemaphore);
    }
}