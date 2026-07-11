#include "../../GUI.h"

void GUI_initScreen__alarmScreen() {
    GUI_Screen__alarmScreen = lv_obj_create(NULL);
    lv_obj_remove_flag(GUI_Screen__alarmScreen, LV_OBJ_FLAG_SCROLLABLE);

    for (int i = 0; i < 4; i++) {
        GUI_Panel__alarmScreen__alarmPanel[i] =
            lv_obj_create(GUI_Screen__alarmScreen);
        lv_obj_remove_flag(GUI_Panel__alarmScreen__alarmPanel[i],
                           LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_add_flag(GUI_Panel__alarmScreen__alarmPanel[i], LV_OBJ_FLAG_CLICKABLE);
        lv_obj_add_flag(GUI_Panel__alarmScreen__alarmPanel[i], LV_OBJ_FLAG_HIDDEN);
        lv_obj_set_size(GUI_Panel__alarmScreen__alarmPanel[i], 520, 200);
        lv_obj_set_pos(GUI_Panel__alarmScreen__alarmPanel[i],
                       150 + ((i / 2) * 560), 50 + ((i % 2) * 225));

        GUI_Label__alarmScreen__alarmTimeLabel[i] =
            lv_label_create(GUI_Panel__alarmScreen__alarmPanel[i]);
        lv_label_set_long_mode(GUI_Label__alarmScreen__alarmTimeLabel[i],
                               LV_LABEL_LONG_WRAP);
        lv_obj_set_y(GUI_Label__alarmScreen__alarmTimeLabel[i], 10);
        lv_obj_set_size(GUI_Label__alarmScreen__alarmTimeLabel[i],
                        LV_SIZE_CONTENT, LV_SIZE_CONTENT);

        GUI_Label__alarmScreen__alarmRepeatLabel[i] =
            lv_label_create(GUI_Panel__alarmScreen__alarmPanel[i]);
        lv_label_set_long_mode(GUI_Label__alarmScreen__alarmRepeatLabel[i],
                               LV_LABEL_LONG_WRAP);
        lv_obj_set_y(GUI_Label__alarmScreen__alarmRepeatLabel[i], 120);
        lv_obj_set_size(GUI_Label__alarmScreen__alarmRepeatLabel[i],
                        LV_SIZE_CONTENT, LV_SIZE_CONTENT);

        GUI_Switch__alarmScreen__alarmEnableSwitch[i] =
            lv_switch_create(GUI_Panel__alarmScreen__alarmPanel[i]);
        lv_obj_set_align(GUI_Switch__alarmScreen__alarmEnableSwitch[i],
                         LV_ALIGN_RIGHT_MID);
        lv_obj_set_size(GUI_Switch__alarmScreen__alarmEnableSwitch[i], 70, 40);
    }

    GUI_Button__alarmScreen__alarmAddButton =
        lv_button_create(GUI_Screen__alarmScreen);
    lv_obj_set_align(GUI_Button__alarmScreen__alarmAddButton,
                     LV_ALIGN_BOTTOM_MID);
    lv_obj_set_pos(GUI_Button__alarmScreen__alarmAddButton, 50, -30);
    lv_obj_set_size(GUI_Button__alarmScreen__alarmAddButton, 100, 100);

    GUI_Label__alarmScreen__alarmAddLabel =
        lv_label_create(GUI_Button__alarmScreen__alarmAddButton);
    lv_label_set_long_mode(GUI_Label__alarmScreen__alarmAddLabel,
                           LV_LABEL_LONG_WRAP);
    lv_obj_set_align(GUI_Label__alarmScreen__alarmAddLabel, LV_ALIGN_CENTER);
    lv_obj_set_size(GUI_Label__alarmScreen__alarmAddLabel, LV_SIZE_CONTENT,
                    LV_SIZE_CONTENT);

    GUI_initScreenStyles__alarmScreen();
    GUI_initScreenTexts__alarmScreen();
}

void GUI_initScreenTexts__alarmScreen() {
    for (int i = 0; i < 4; i++) {
        lv_label_set_text(GUI_Label__alarmScreen__alarmTimeLabel[i], "--:--");
        lv_label_set_text(GUI_Label__alarmScreen__alarmRepeatLabel[i], "--");
    }
    lv_label_set_text(GUI_Label__alarmScreen__alarmAddLabel, "+");
}

void GUI_initScreenStyles__alarmScreen() {
    lv_obj_add_style(GUI_Screen__alarmScreen, &GUI_Style__blackBg,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    for (int i = 0; i < 4; i++) {
        lv_obj_add_style(GUI_Panel__alarmScreen__alarmPanel[i],
                         &GUI_Style__defaultPanel,
                         LV_PART_MAIN | LV_STATE_DEFAULT);

        lv_obj_add_style(GUI_Label__alarmScreen__alarmTimeLabel[i],
                         &GUI_Style__inter80L_White,
                         LV_PART_MAIN | LV_STATE_DEFAULT);

        lv_obj_add_style(GUI_Label__alarmScreen__alarmRepeatLabel[i],
                         &GUI_Style__poppins20C_White,
                         LV_PART_MAIN | LV_STATE_DEFAULT);

        lv_obj_add_style(GUI_Switch__alarmScreen__alarmEnableSwitch[i],
                         &GUI_Style__blueActiveSwitch,
                         LV_PART_INDICATOR | LV_STATE_CHECKED);
    }

    lv_obj_add_style(GUI_Button__alarmScreen__alarmAddButton,
                     &GUI_Style__blueButton, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_style(GUI_Label__alarmScreen__alarmAddLabel,
                     &GUI_Style__montserratL80C_Black,
                     LV_PART_MAIN | LV_STATE_DEFAULT);
}