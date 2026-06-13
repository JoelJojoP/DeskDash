#include "../../GUI.h"

void GUI_initScreen__mainScreen() {
  GUI_Screen__mainScreen = lv_obj_create(NULL);
  lv_obj_remove_flag(GUI_Screen__mainScreen, LV_OBJ_FLAG_SCROLLABLE);
  GUI_Image__mainScreen__bgImage = lv_image_create(GUI_Screen__mainScreen);
  lv_obj_add_flag(GUI_Image__mainScreen__bgImage, LV_OBJ_FLAG_ADV_HITTEST);
  lv_obj_remove_flag(GUI_Image__mainScreen__bgImage, LV_OBJ_FLAG_SCROLLABLE);
  lv_obj_set_align(GUI_Image__mainScreen__bgImage, LV_ALIGN_CENTER);
  lv_obj_set_size(GUI_Image__mainScreen__bgImage, LV_SIZE_CONTENT,
                  LV_SIZE_CONTENT);

  GUI_Container__mainScreen__timeContainer =
      lv_obj_create(GUI_Screen__mainScreen);
  lv_obj_remove_style_all(GUI_Container__mainScreen__timeContainer);
  lv_obj_remove_flag(GUI_Container__mainScreen__timeContainer,
                     LV_OBJ_FLAG_CLICKABLE);
  lv_obj_remove_flag(GUI_Container__mainScreen__timeContainer,
                     LV_OBJ_FLAG_SCROLLABLE);
  lv_obj_set_pos(GUI_Container__mainScreen__timeContainer, 150, 50);
  lv_obj_set_size(GUI_Container__mainScreen__timeContainer, 500, 350);

  GUI_Label__mainScreen__timeLabel =
      lv_label_create(GUI_Container__mainScreen__timeContainer);
  lv_label_set_long_mode(GUI_Label__mainScreen__timeLabel, LV_LABEL_LONG_WRAP);
  lv_obj_set_align(GUI_Label__mainScreen__timeLabel, LV_ALIGN_TOP_MID);
  lv_obj_set_y(GUI_Label__mainScreen__timeLabel, 10);
  lv_obj_set_size(GUI_Label__mainScreen__timeLabel, LV_SIZE_CONTENT,
                  LV_SIZE_CONTENT);

  GUI_Label__mainScreen__dayLabel =
      lv_label_create(GUI_Container__mainScreen__timeContainer);
  lv_label_set_long_mode(GUI_Label__mainScreen__dayLabel, LV_LABEL_LONG_WRAP);
  lv_obj_set_align(GUI_Label__mainScreen__dayLabel, LV_ALIGN_TOP_MID);
  lv_obj_set_y(GUI_Label__mainScreen__dayLabel, 175);
  lv_obj_set_size(GUI_Label__mainScreen__dayLabel, LV_SIZE_CONTENT,
                  LV_SIZE_CONTENT);

  GUI_Label__mainScreen__dateLabel =
      lv_label_create(GUI_Container__mainScreen__timeContainer);
  lv_label_set_long_mode(GUI_Label__mainScreen__dateLabel, LV_LABEL_LONG_WRAP);
  lv_obj_set_align(GUI_Label__mainScreen__dateLabel, LV_ALIGN_TOP_MID);
  lv_obj_set_y(GUI_Label__mainScreen__dateLabel, 220);
  lv_obj_set_size(GUI_Label__mainScreen__dateLabel, LV_SIZE_CONTENT,
                  LV_SIZE_CONTENT);

  GUI_Panel__mainScreen__weatherPanel = lv_obj_create(GUI_Screen__mainScreen);
  lv_obj_remove_flag(GUI_Panel__mainScreen__weatherPanel,
                     LV_OBJ_FLAG_SCROLLABLE);
  lv_obj_set_align(GUI_Panel__mainScreen__weatherPanel, LV_ALIGN_TOP_RIGHT);
  lv_obj_set_pos(GUI_Panel__mainScreen__weatherPanel, -50, 50);
  lv_obj_set_size(GUI_Panel__mainScreen__weatherPanel, 530, 350);

  GUI_Label__mainScreen__locLabel =
      lv_label_create(GUI_Panel__mainScreen__weatherPanel);
  lv_label_set_long_mode(GUI_Label__mainScreen__locLabel, LV_LABEL_LONG_WRAP);
  lv_obj_set_size(GUI_Label__mainScreen__locLabel, LV_SIZE_CONTENT,
                  LV_SIZE_CONTENT);

  GUI_Label__mainScreen__tempLabel =
      lv_label_create(GUI_Panel__mainScreen__weatherPanel);
  lv_label_set_long_mode(GUI_Label__mainScreen__tempLabel, LV_LABEL_LONG_WRAP);
  lv_obj_set_y(GUI_Label__mainScreen__tempLabel, 40);
  lv_obj_set_size(GUI_Label__mainScreen__tempLabel, LV_SIZE_CONTENT,
                  LV_SIZE_CONTENT);

  GUI_Image__mainScreen__wthIcon =
      lv_image_create(GUI_Panel__mainScreen__weatherPanel);
  lv_obj_add_flag(GUI_Image__mainScreen__wthIcon, LV_OBJ_FLAG_ADV_HITTEST);
  lv_obj_add_flag(GUI_Image__mainScreen__wthIcon, LV_OBJ_FLAG_HIDDEN);
  lv_obj_remove_flag(GUI_Image__mainScreen__wthIcon, LV_OBJ_FLAG_SCROLLABLE);
  lv_obj_set_align(GUI_Image__mainScreen__wthIcon, LV_ALIGN_TOP_RIGHT);
  lv_obj_set_pos(GUI_Image__mainScreen__wthIcon, -20, 20);
  lv_obj_set_size(GUI_Image__mainScreen__wthIcon, LV_SIZE_CONTENT,
                  LV_SIZE_CONTENT);

  GUI_Label__mainScreen__wthLabel =
      lv_label_create(GUI_Panel__mainScreen__weatherPanel);
  lv_label_set_long_mode(GUI_Label__mainScreen__wthLabel, LV_LABEL_LONG_WRAP);
  lv_obj_set_align(GUI_Label__mainScreen__wthLabel, LV_ALIGN_TOP_RIGHT);
  lv_obj_set_y(GUI_Label__mainScreen__wthLabel, 100);
  lv_obj_set_size(GUI_Label__mainScreen__wthLabel, LV_SIZE_CONTENT,
                  LV_SIZE_CONTENT);

  GUI_Label__mainScreen__minMaxLabel =
      lv_label_create(GUI_Panel__mainScreen__weatherPanel);
  lv_label_set_long_mode(GUI_Label__mainScreen__minMaxLabel,
                         LV_LABEL_LONG_WRAP);
  lv_obj_set_y(GUI_Label__mainScreen__minMaxLabel, 135);
  lv_obj_set_size(GUI_Label__mainScreen__minMaxLabel, LV_SIZE_CONTENT,
                  LV_SIZE_CONTENT);

  GUI_Panel__mainScreen__sideBar = lv_obj_create(lv_layer_top());
  lv_obj_remove_flag(GUI_Panel__mainScreen__sideBar, LV_OBJ_FLAG_SCROLLABLE);
  lv_obj_set_size(GUI_Panel__mainScreen__sideBar, 100, 720);
  lv_obj_add_flag(GUI_Panel__mainScreen__sideBar, LV_OBJ_FLAG_HIDDEN);

  GUI_Button__mainScreen__homeButton =
      lv_button_create(GUI_Panel__mainScreen__sideBar);
  lv_obj_set_align(GUI_Button__mainScreen__homeButton, LV_ALIGN_TOP_MID);
  lv_obj_set_size(GUI_Button__mainScreen__homeButton, 100, 100);
  lv_obj_add_event_cb(GUI_Button__mainScreen__homeButton,
                      GUI_event__Button__mainScreen__homeButton__Clicked,
                      LV_EVENT_CLICKED, NULL);

  GUI_Label__mainScreen__homeLabel =
      lv_label_create(GUI_Button__mainScreen__homeButton);
  lv_label_set_long_mode(GUI_Label__mainScreen__homeLabel, LV_LABEL_LONG_WRAP);
  lv_obj_set_align(GUI_Label__mainScreen__homeLabel, LV_ALIGN_CENTER);
  lv_obj_set_size(GUI_Label__mainScreen__homeLabel, LV_SIZE_CONTENT,
                  LV_SIZE_CONTENT);

  GUI_Button__mainScreen__alarmButton =
      lv_button_create(GUI_Panel__mainScreen__sideBar);
  lv_obj_set_align(GUI_Button__mainScreen__alarmButton, LV_ALIGN_TOP_MID);
  lv_obj_set_y(GUI_Button__mainScreen__alarmButton, 100);
  lv_obj_set_size(GUI_Button__mainScreen__alarmButton, 100, 100);
  lv_obj_add_event_cb(GUI_Button__mainScreen__alarmButton,
                      GUI_event__Button__mainScreen__alarmButton__Clicked,
                      LV_EVENT_CLICKED, NULL);

  GUI_Label__mainScreen__alarmLabel =
      lv_label_create(GUI_Button__mainScreen__alarmButton);
  lv_label_set_long_mode(GUI_Label__mainScreen__alarmLabel, LV_LABEL_LONG_WRAP);
  lv_obj_set_align(GUI_Label__mainScreen__alarmLabel, LV_ALIGN_CENTER);
  lv_obj_set_size(GUI_Label__mainScreen__alarmLabel, LV_SIZE_CONTENT,
                  LV_SIZE_CONTENT);

  GUI_Panel__mainScreen__selIndicator =
      lv_obj_create(GUI_Panel__mainScreen__sideBar);
  lv_obj_remove_flag(GUI_Panel__mainScreen__selIndicator,
                     LV_OBJ_FLAG_SCROLLABLE);
  lv_obj_set_align(GUI_Panel__mainScreen__selIndicator, LV_ALIGN_TOP_RIGHT);
  lv_obj_set_x(GUI_Panel__mainScreen__selIndicator, 20);
  lv_obj_set_size(GUI_Panel__mainScreen__selIndicator, 10, 100);

  GUI_initScreenStyles__mainScreen();
  GUI_initScreenTexts__mainScreen();
}

void GUI_initScreenTexts__mainScreen() {
  lv_label_set_text(GUI_Label__mainScreen__timeLabel, "10:10");
  lv_label_set_text(GUI_Label__mainScreen__dayLabel, "Sunday");
  lv_label_set_text(GUI_Label__mainScreen__dateLabel, "January 01, 1970");
  lv_label_set_text(GUI_Label__mainScreen__locLabel, "--");
  lv_label_set_text(GUI_Label__mainScreen__tempLabel, "--°C");
  lv_label_set_text(GUI_Label__mainScreen__wthLabel, "--");
  lv_label_set_text(GUI_Label__mainScreen__minMaxLabel, "H: --° | L: --°");
  lv_label_set_text(GUI_Label__mainScreen__homeLabel, HOME_ICON);
  lv_label_set_text(GUI_Label__mainScreen__alarmLabel, ALARM_ICON);
}

void GUI_initScreenStyles__mainScreen() {
  lv_image_set_src(GUI_Image__mainScreen__bgImage,
                   &upload_bg1_ec5fd9fb2bb84319a9d53603745df739_png);
  
  lv_image_set_scale_x(GUI_Image__mainScreen__bgImage, 2048);
  lv_image_set_scale_y(GUI_Image__mainScreen__bgImage, 2048);

  lv_obj_add_style(GUI_Image__mainScreen__bgImage,
                   &GUI_Style__class_nO9WWVajdwferl__imageBgStyle,
                   LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_add_style(GUI_Label__mainScreen__timeLabel,
                   &GUI_Style__class_z25cHb6hZ3yXcf__timeDispStyle,
                   LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_add_style(GUI_Label__mainScreen__dayLabel,
                   &GUI_Style__class_dQqT0mpaLpxNFX__dateDispStyle,
                   LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_add_style(GUI_Label__mainScreen__dateLabel,
                   &GUI_Style__class_dQqT0mpaLpxNFX__dateDispStyle,
                   LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_add_style(GUI_Panel__mainScreen__weatherPanel,
                   &GUI_Style__class_hbZ9trKSkKmFm7__defPanelStyle,
                   LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_add_style(GUI_Label__mainScreen__locLabel,
                   &GUI_Style__class_dQqT0mpaLpxNFX__dateDispStyle,
                   LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_add_style(GUI_Label__mainScreen__tempLabel,
                   &GUI_Style__class_MUYJKm3UpbRtLk__tempDispStyle,
                   LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_image_set_src(GUI_Image__mainScreen__wthIcon,
                   &sun);

  lv_image_set_scale_x(GUI_Image__mainScreen__wthIcon, 512);
  lv_image_set_scale_y(GUI_Image__mainScreen__wthIcon, 512);

  lv_obj_add_style(GUI_Image__mainScreen__wthIcon,
                   &GUI_Style__class_qhbKUz960C5eEN__icoStyle,
                   LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_add_style(GUI_Label__mainScreen__wthLabel,
                   &GUI_Style__class_dWy3Gyh9l0NT39__wthStyle,
                   LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_add_style(GUI_Label__mainScreen__wthLabel,
                   &GUI_Style__class_ovYKeEQJT7E3hI__,
                   LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_add_style(GUI_Label__mainScreen__minMaxLabel,
                   &GUI_Style__class_dWy3Gyh9l0NT39__wthStyle,
                   LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_add_style(GUI_Panel__mainScreen__sideBar,
                   &GUI_Style__class_S7dDwgCAuB7Nxa__sideBarStyle,
                   LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_add_style(GUI_Button__mainScreen__homeButton,
                   &GUI_Style__class_5lXjjcQvO2YFLl__buttonStyle,
                   LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_add_style(GUI_Label__mainScreen__homeLabel,
                   &GUI_Style__class_L11bizL1MaPXIx__sideTextStyle,
                   LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_add_style(GUI_Button__mainScreen__alarmButton,
                   &GUI_Style__class_5lXjjcQvO2YFLl__buttonStyle,
                   LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_add_style(GUI_Label__mainScreen__alarmLabel,
                   &GUI_Style__class_L11bizL1MaPXIx__sideTextStyle,
                   LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_add_style(GUI_Panel__mainScreen__selIndicator,
                   &GUI_Style__class_fAAuYI7RtRWXqZ__,
                   LV_PART_MAIN | LV_STATE_DEFAULT);
}
