#include "../../GUI.h"

void GUI_initScreen__splashScreen() {
  GUI_Screen__splashScreen = lv_obj_create(NULL);
  lv_obj_remove_flag(GUI_Screen__splashScreen, LV_OBJ_FLAG_SCROLLABLE);
  GUI_Bar__splashScreen__initBar = lv_bar_create(GUI_Screen__splashScreen);
  lv_bar_set_value(GUI_Bar__splashScreen__initBar, 0, LV_ANIM_OFF);
  lv_bar_set_mode(GUI_Bar__splashScreen__initBar, LV_BAR_MODE_NORMAL);
  lv_obj_set_align(GUI_Bar__splashScreen__initBar, LV_ALIGN_CENTER);
  lv_obj_set_size(GUI_Bar__splashScreen__initBar, 500, 10);

  GUI_initScreenStyles__splashScreen();
  GUI_initScreenTexts__splashScreen();
}

void GUI_initScreenTexts__splashScreen() {
}

void GUI_initScreenStyles__splashScreen() {
  lv_obj_add_style(GUI_Screen__splashScreen,
                   &GUI_Style__class_ee5haLh6BPfC7X__blackBgStyle,
                   LV_PART_MAIN | LV_STATE_DEFAULT);
}
