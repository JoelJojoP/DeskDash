#include "../../GUI.h"

void GUI_initScreen__splashScreen() {
    GUI_Screen__splashScreen = lv_obj_create(NULL);
    lv_obj_remove_flag(GUI_Screen__splashScreen, LV_OBJ_FLAG_SCROLLABLE);

    GUI_initScreenStyles__splashScreen();
    GUI_initScreenTexts__splashScreen();
}

void GUI_initScreenTexts__splashScreen() {}

void GUI_initScreenStyles__splashScreen() {
    lv_obj_add_style(GUI_Screen__splashScreen, &GUI_Style__defaultBgStyle,
                     LV_PART_MAIN | LV_STATE_DEFAULT);
}