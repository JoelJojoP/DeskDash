#include "DeskDash.h"

DeskDashView::DeskDashView() {
    // Nothing to initialize in the constructor for now
}

void DeskDashView::toggleWifiIcon(bool isConnected) {
    if (xSemaphoreTake(xGuiSemaphore, portMAX_DELAY) == pdTRUE) {
        if (isConnected) {
            lv_label_set_text(GUI_Label__topLayer__wifiLabel, WIFI_ICON);
            lv_obj_remove_flag(GUI_Button__topLayer__wifiButton, LV_OBJ_FLAG_CLICKABLE);
        } else {
            lv_label_set_text(GUI_Label__topLayer__wifiLabel, REFRESH_ICON);
            lv_obj_add_flag(GUI_Button__topLayer__wifiButton, LV_OBJ_FLAG_CLICKABLE);
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
                                 const lv_image_dsc_t *wthIcon) {
    if (xSemaphoreTake(xGuiSemaphore, portMAX_DELAY) == pdTRUE) {
        lv_label_set_text(GUI_Label__mainScreen__tempLabel, curTempStr);
        lv_label_set_text(GUI_Label__mainScreen__minMaxLabel, minMaxTempStr);
        lv_label_set_text(GUI_Label__mainScreen__wthLabel, wthStr);
        if (wthIcon != NULL) {
            lv_obj_remove_flag(GUI_Image__mainScreen__wthIcon, LV_OBJ_FLAG_HIDDEN);
            lv_img_set_src(GUI_Image__mainScreen__wthIcon, wthIcon);
        } else {
            lv_obj_add_flag(GUI_Image__mainScreen__wthIcon, LV_OBJ_FLAG_HIDDEN);
        }
        xSemaphoreGive(xGuiSemaphore);
    }
}

void DeskDashView::updateForecast(int idx, const char *timeStr, const char *tempStr, const lv_image_dsc_t *wthIcon) {
    if (xSemaphoreTake(xGuiSemaphore, portMAX_DELAY) == pdTRUE) {
        lv_label_set_text(GUI_Label__mainScreen__fcTimeLabel[idx], timeStr);
        lv_label_set_text(GUI_Label__mainScreen__fcTempLabel[idx], tempStr);
        if (wthIcon != NULL) {
            lv_obj_remove_flag(GUI_Image__mainScreen__fcWthIcon[idx], LV_OBJ_FLAG_HIDDEN);
            lv_img_set_src(GUI_Image__mainScreen__fcWthIcon[idx], wthIcon);
        } else {
            lv_obj_add_flag(GUI_Image__mainScreen__fcWthIcon[idx], LV_OBJ_FLAG_HIDDEN);
        }
        xSemaphoreGive(xGuiSemaphore);
    }
}

void DeskDashView::updateLocation(const char *locationStr) {
    if (xSemaphoreTake(xGuiSemaphore, portMAX_DELAY) == pdTRUE) {
        lv_label_set_text(GUI_Label__mainScreen__locationLabel, locationStr);
        xSemaphoreGive(xGuiSemaphore);
    }
}

/* Put the M5Tab5 to sleep */
void DeskDashView::goSleep() {
    LOG_INFO("Entering sleep");
    ledcWrite(DISP_BL_PIN, 0);
    M5.Display.writecommand(0x28); // Display off
    // esp_light_sleep_start();
}

/* Wake up the M5Tab5 from sleep */
void DeskDashView::wakeUp() {
    LOG_INFO("Waking up from sleep");
    M5.Display.writecommand(0x29); // Display on
    ledcWrite(DISP_BL_PIN, 20);
}