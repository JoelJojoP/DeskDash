#include "../../GUI.h"

#ifdef GUI_EXTERNAL_CUSTOM_CALLBACK_FUNCTION_FILE
#include GUI_EXTERNAL_CUSTOM_CALLBACK_FUNCTION_FILE
#endif

void GUI_event__Button__mainScreen__homeButton__Clicked(lv_event_t *event) {
  if(GUI_Screen__mainScreen == lv_screen_active()) {
    return;
  }
  _ui_screen_change(&GUI_Screen__mainScreen, LV_SCR_LOAD_ANIM_NONE, 500, 0,
                    &GUI_initScreen__mainScreen);       // Change_Screen
  lv_obj_set_y(GUI_Panel__mainScreen__selIndicator, 0); // Basic_Properties
}

void GUI_event__Button__mainScreen__alarmButton__Clicked(lv_event_t *event) {
  if(GUI_Screen__alarmScreen == lv_screen_active()) {
    return;
  }
  _ui_screen_change(&GUI_Screen__alarmScreen, LV_SCR_LOAD_ANIM_NONE, 500, 0,
                    &GUI_initScreen__alarmScreen);        // Change_Screen
  lv_obj_set_y(GUI_Panel__mainScreen__selIndicator, 100); // Basic_Properties
}
