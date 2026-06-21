#include "../../GUI.h"

void GUI_initScreen__commonElement() {
    GUI_Image__bottomLayer__bgImage = lv_image_create(lv_layer_bottom());
    lv_obj_add_flag(GUI_Image__bottomLayer__bgImage, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_remove_flag(GUI_Image__bottomLayer__bgImage, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_align(GUI_Image__bottomLayer__bgImage, LV_ALIGN_CENTER);
    lv_obj_set_size(GUI_Image__bottomLayer__bgImage, LV_SIZE_CONTENT,
                    LV_SIZE_CONTENT);

    GUI_Panel__topLayer__sideBar = lv_obj_create(lv_layer_top());
    lv_obj_remove_flag(GUI_Panel__topLayer__sideBar, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(GUI_Panel__topLayer__sideBar, 100, 720);

    GUI_Button__topLayer__homeButton =
        lv_button_create(GUI_Panel__topLayer__sideBar);
    lv_obj_set_align(GUI_Button__topLayer__homeButton, LV_ALIGN_TOP_MID);
    lv_obj_set_size(GUI_Button__topLayer__homeButton, 100, 100);
    lv_obj_add_event_cb(GUI_Button__topLayer__homeButton,
                        GUI_event__Button__topLayer__homeButton__Clicked,
                        LV_EVENT_CLICKED, NULL);

    GUI_Label__topLayer__homeLabel =
        lv_label_create(GUI_Button__topLayer__homeButton);
    lv_label_set_long_mode(GUI_Label__topLayer__homeLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_align(GUI_Label__topLayer__homeLabel, LV_ALIGN_CENTER);
    lv_obj_set_size(GUI_Label__topLayer__homeLabel, LV_SIZE_CONTENT,
                    LV_SIZE_CONTENT);

    GUI_Button__topLayer__alarmButton =
        lv_button_create(GUI_Panel__topLayer__sideBar);
    lv_obj_set_align(GUI_Button__topLayer__alarmButton, LV_ALIGN_TOP_MID);
    lv_obj_set_y(GUI_Button__topLayer__alarmButton, 100);
    lv_obj_set_size(GUI_Button__topLayer__alarmButton, 100, 100);
    lv_obj_add_event_cb(GUI_Button__topLayer__alarmButton,
                        GUI_event__Button__topLayer__alarmButton__Clicked,
                        LV_EVENT_CLICKED, NULL);

    GUI_Label__topLayer__alarmLabel =
        lv_label_create(GUI_Button__topLayer__alarmButton);
    lv_label_set_long_mode(GUI_Label__topLayer__alarmLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_align(GUI_Label__topLayer__alarmLabel, LV_ALIGN_CENTER);
    lv_obj_set_size(GUI_Label__topLayer__alarmLabel, LV_SIZE_CONTENT,
                    LV_SIZE_CONTENT);

    GUI_Button__topLayer__settingButton =
        lv_button_create(GUI_Panel__topLayer__sideBar);
    lv_obj_set_align(GUI_Button__topLayer__settingButton, LV_ALIGN_TOP_MID);
    lv_obj_set_y(GUI_Button__topLayer__settingButton, 200);
    lv_obj_set_size(GUI_Button__topLayer__settingButton, 100, 100);

    GUI_Label__topLayer__settingLabel =
        lv_label_create(GUI_Button__topLayer__settingButton);
    lv_label_set_long_mode(GUI_Label__topLayer__settingLabel,
                           LV_LABEL_LONG_WRAP);
    lv_obj_set_align(GUI_Label__topLayer__settingLabel, LV_ALIGN_CENTER);
    lv_obj_set_size(GUI_Label__topLayer__settingLabel, LV_SIZE_CONTENT,
                    LV_SIZE_CONTENT);

    GUI_Button__topLayer__wifiButton =
        lv_button_create(GUI_Panel__topLayer__sideBar);
    lv_obj_set_align(GUI_Button__topLayer__wifiButton, LV_ALIGN_TOP_MID);
    lv_obj_set_y(GUI_Button__topLayer__wifiButton, 580);
    lv_obj_set_size(GUI_Button__topLayer__wifiButton, 100, 100);

    GUI_Label__topLayer__wifiLabel =
        lv_label_create(GUI_Button__topLayer__wifiButton);
    lv_label_set_long_mode(GUI_Label__topLayer__wifiLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_align(GUI_Label__topLayer__wifiLabel, LV_ALIGN_CENTER);
    lv_obj_set_size(GUI_Label__topLayer__wifiLabel, LV_SIZE_CONTENT,
                    LV_SIZE_CONTENT);

    GUI_Panel__topLayer__selIndicator =
        lv_obj_create(GUI_Panel__topLayer__sideBar);
    lv_obj_remove_flag(GUI_Panel__topLayer__selIndicator,
                       LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(GUI_Panel__topLayer__selIndicator, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_align(GUI_Panel__topLayer__selIndicator, LV_ALIGN_TOP_RIGHT);
    lv_obj_set_x(GUI_Panel__topLayer__selIndicator, 20);
    lv_obj_set_size(GUI_Panel__topLayer__selIndicator, 10, 100);

    GUI_initScreenStyles__commonElement();
    GUI_initScreenTexts__commonElement();
}

void GUI_initScreenTexts__commonElement() {
    lv_label_set_text(GUI_Label__topLayer__homeLabel, HOME_ICON);
    lv_label_set_text(GUI_Label__topLayer__alarmLabel, ALARM_ICON);
    lv_label_set_text(GUI_Label__topLayer__settingLabel, SETTING_ICON);
    lv_label_set_text(GUI_Label__topLayer__wifiLabel, REFRESH_ICON);
}

void GUI_initScreenStyles__commonElement() {
    lv_image_set_src(GUI_Image__bottomLayer__bgImage, &bg);

    lv_image_set_scale_x(GUI_Image__bottomLayer__bgImage, 2048);
    lv_image_set_scale_y(GUI_Image__bottomLayer__bgImage, 2048);

    lv_obj_add_style(GUI_Image__bottomLayer__bgImage, &GUI_Style__bgImageStyle,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_style(GUI_Panel__topLayer__sideBar, &GUI_Style__sideBarStyle,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_style(GUI_Button__topLayer__homeButton, &GUI_Style__sideButStyle,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_style(GUI_Label__topLayer__homeLabel,
                     &GUI_Style__sideTextStyle,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_style(GUI_Button__topLayer__alarmButton,
                     &GUI_Style__sideButStyle, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_style(GUI_Label__topLayer__alarmLabel,
                     &GUI_Style__sideTextStyle,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_style(GUI_Button__topLayer__settingButton,
                     &GUI_Style__sideButStyle, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_style(GUI_Label__topLayer__settingLabel,
                     &GUI_Style__sideTextStyle,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_style(GUI_Button__topLayer__wifiButton, &GUI_Style__sideButStyle,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_style(GUI_Label__topLayer__wifiLabel,
                     &GUI_Style__sideTextStyle,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_style(GUI_Panel__topLayer__selIndicator,
                     &GUI_Style__sideSelIndStyle,
                     LV_PART_MAIN | LV_STATE_DEFAULT);
}