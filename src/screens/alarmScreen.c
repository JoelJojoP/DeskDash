#include "../../GUI.h"

void GUI_initScreen__alarmScreen() {
    GUI_Screen__alarmScreen = lv_obj_create(NULL);
    lv_obj_remove_flag(GUI_Screen__alarmScreen, LV_OBJ_FLAG_SCROLLABLE);

    GUI_initScreenStyles__alarmScreen();
    GUI_initScreenTexts__alarmScreen();
}

void GUI_initScreenTexts__alarmScreen() {}

void GUI_initScreenStyles__alarmScreen() {
    lv_obj_add_style(GUI_Screen__alarmScreen, &GUI_Style__defaultBgStyle,
                     LV_PART_MAIN | LV_STATE_DEFAULT);
}
