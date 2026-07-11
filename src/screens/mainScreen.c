#include "../../GUI.h"

void GUI_initScreen__mainScreen() {
    GUI_Screen__mainScreen = lv_obj_create(NULL);
    lv_obj_remove_flag(GUI_Screen__mainScreen, LV_OBJ_FLAG_SCROLLABLE);

    GUI_Container__mainScreen__timeContainer =
        lv_obj_create(GUI_Screen__mainScreen);
    lv_obj_remove_style_all(GUI_Container__mainScreen__timeContainer);
    lv_obj_remove_flag(GUI_Container__mainScreen__timeContainer,
                       LV_OBJ_FLAG_CLICKABLE);
    lv_obj_remove_flag(GUI_Container__mainScreen__timeContainer,
                       LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_pos(GUI_Container__mainScreen__timeContainer, 150, 50);
    lv_obj_set_size(GUI_Container__mainScreen__timeContainer, 480, 350);

    GUI_Label__mainScreen__timeLabel =
        lv_label_create(GUI_Container__mainScreen__timeContainer);
    lv_label_set_long_mode(GUI_Label__mainScreen__timeLabel,
                           LV_LABEL_LONG_WRAP);
    lv_obj_set_align(GUI_Label__mainScreen__timeLabel, LV_ALIGN_TOP_MID);
    lv_obj_set_y(GUI_Label__mainScreen__timeLabel, 50);
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
    lv_label_set_long_mode(GUI_Label__mainScreen__dateLabel,
                           LV_LABEL_LONG_WRAP);
    lv_obj_set_align(GUI_Label__mainScreen__dateLabel, LV_ALIGN_TOP_MID);
    lv_obj_set_y(GUI_Label__mainScreen__dateLabel, 220);
    lv_obj_set_size(GUI_Label__mainScreen__dateLabel, LV_SIZE_CONTENT,
                    LV_SIZE_CONTENT);

    GUI_Panel__mainScreen__weatherPanel = lv_obj_create(GUI_Screen__mainScreen);
    lv_obj_remove_flag(GUI_Panel__mainScreen__weatherPanel,
                       LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_align(GUI_Panel__mainScreen__weatherPanel, LV_ALIGN_TOP_RIGHT);
    lv_obj_set_pos(GUI_Panel__mainScreen__weatherPanel, -50, 50);
    lv_obj_set_size(GUI_Panel__mainScreen__weatherPanel, 550, 390);

    GUI_Label__mainScreen__locationLabel =
        lv_label_create(GUI_Panel__mainScreen__weatherPanel);
    lv_label_set_long_mode(GUI_Label__mainScreen__locationLabel,
                           LV_LABEL_LONG_WRAP);
    lv_obj_set_size(GUI_Label__mainScreen__locationLabel, LV_SIZE_CONTENT,
                    LV_SIZE_CONTENT);

    GUI_Label__mainScreen__tempLabel =
        lv_label_create(GUI_Panel__mainScreen__weatherPanel);
    lv_label_set_long_mode(GUI_Label__mainScreen__tempLabel,
                           LV_LABEL_LONG_WRAP);
    lv_obj_set_y(GUI_Label__mainScreen__tempLabel, 55);
    lv_obj_set_size(GUI_Label__mainScreen__tempLabel, LV_SIZE_CONTENT,
                    LV_SIZE_CONTENT);

    GUI_Image__mainScreen__wthIcon =
        lv_image_create(GUI_Panel__mainScreen__weatherPanel);
    lv_obj_add_flag(GUI_Image__mainScreen__wthIcon, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_add_flag(GUI_Image__mainScreen__wthIcon, LV_OBJ_FLAG_HIDDEN);
    lv_obj_remove_flag(GUI_Image__mainScreen__wthIcon, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_align(GUI_Image__mainScreen__wthIcon, LV_ALIGN_TOP_RIGHT);
    lv_obj_set_pos(GUI_Image__mainScreen__wthIcon, -20, 25);
    lv_obj_set_size(GUI_Image__mainScreen__wthIcon, LV_SIZE_CONTENT,
                    LV_SIZE_CONTENT);

    GUI_Label__mainScreen__wthLabel =
        lv_label_create(GUI_Panel__mainScreen__weatherPanel);
    lv_label_set_long_mode(GUI_Label__mainScreen__wthLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_align(GUI_Label__mainScreen__wthLabel, LV_ALIGN_TOP_RIGHT);
    lv_obj_set_pos(GUI_Label__mainScreen__wthLabel, -5, 100);
    lv_obj_set_size(GUI_Label__mainScreen__wthLabel, LV_SIZE_CONTENT,
                    LV_SIZE_CONTENT);

    GUI_Label__mainScreen__minMaxLabel =
        lv_label_create(GUI_Panel__mainScreen__weatherPanel);
    lv_label_set_long_mode(GUI_Label__mainScreen__minMaxLabel,
                           LV_LABEL_LONG_WRAP);
    lv_obj_set_y(GUI_Label__mainScreen__minMaxLabel, 135);
    lv_obj_set_size(GUI_Label__mainScreen__minMaxLabel, LV_SIZE_CONTENT,
                    LV_SIZE_CONTENT);

    static lv_point_precise_t dividerLinePoints[] = {{0, 180}, {505, 180}};
    GUI_Line__mainScreen__dividerLine =
        lv_line_create(GUI_Panel__mainScreen__weatherPanel);
    lv_line_set_points(GUI_Line__mainScreen__dividerLine, dividerLinePoints, 2);
    lv_obj_set_align(GUI_Line__mainScreen__dividerLine, LV_ALIGN_TOP_LEFT);

    GUI_Label__mainScreen__fcLabel =
        lv_label_create(GUI_Panel__mainScreen__weatherPanel);
    lv_label_set_long_mode(GUI_Label__mainScreen__fcLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_align(GUI_Label__mainScreen__fcLabel, LV_ALIGN_TOP_MID);
    lv_obj_set_y(GUI_Label__mainScreen__fcLabel, 250);
    lv_obj_set_size(GUI_Label__mainScreen__fcLabel, LV_SIZE_CONTENT,
                    LV_SIZE_CONTENT);

    GUI_Container__mainScreen__fcContainer =
        lv_obj_create(GUI_Panel__mainScreen__weatherPanel);
    lv_obj_remove_style_all(GUI_Container__mainScreen__fcContainer);
    lv_obj_add_flag(GUI_Container__mainScreen__fcContainer, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(GUI_Container__mainScreen__fcContainer,
                    LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_scrollbar_mode(GUI_Container__mainScreen__fcContainer,
                              LV_SCROLLBAR_MODE_ACTIVE);
    lv_obj_set_scroll_dir(GUI_Container__mainScreen__fcContainer, LV_DIR_HOR);
    lv_obj_set_align(GUI_Container__mainScreen__fcContainer,
                     LV_ALIGN_BOTTOM_LEFT);
    lv_obj_set_size(GUI_Container__mainScreen__fcContainer, 500, 160);

    for (int i = 0; i < 10; i++) {
        GUI_Container__mainScreen__fcPanel[i] =
            lv_obj_create(GUI_Container__mainScreen__fcContainer);
        lv_obj_remove_style_all(GUI_Container__mainScreen__fcPanel[i]);
        lv_obj_remove_flag(GUI_Container__mainScreen__fcPanel[i],
                           LV_OBJ_FLAG_CLICKABLE);
        lv_obj_remove_flag(GUI_Container__mainScreen__fcPanel[i],
                           LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_set_align(GUI_Container__mainScreen__fcPanel[i],
                         LV_ALIGN_LEFT_MID);
        lv_obj_set_x(GUI_Container__mainScreen__fcPanel[i], i * 100);
        lv_obj_set_size(GUI_Container__mainScreen__fcPanel[i], 100, 160);

        GUI_Image__mainScreen__fcWthIcon[i] =
            lv_image_create(GUI_Container__mainScreen__fcPanel[i]);
        lv_obj_remove_flag(GUI_Image__mainScreen__fcWthIcon[i],
                        LV_OBJ_FLAG_CLICKABLE);
        lv_obj_remove_flag(GUI_Image__mainScreen__fcWthIcon[i],
                           LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_set_align(GUI_Image__mainScreen__fcWthIcon[i], LV_ALIGN_TOP_MID);
        lv_obj_set_y(GUI_Image__mainScreen__fcWthIcon[i], 60);
        lv_obj_set_size(GUI_Image__mainScreen__fcWthIcon[i], LV_SIZE_CONTENT,
                        LV_SIZE_CONTENT);

        GUI_Label__mainScreen__fcTimeLabel[i] =
            lv_label_create(GUI_Container__mainScreen__fcPanel[i]);
        lv_label_set_long_mode(GUI_Label__mainScreen__fcTimeLabel[i],
                               LV_LABEL_LONG_CLIP);
        lv_obj_set_align(GUI_Label__mainScreen__fcTimeLabel[i],
                         LV_ALIGN_TOP_MID);
        lv_obj_set_y(GUI_Label__mainScreen__fcTimeLabel[i], 10);
        lv_obj_set_size(GUI_Label__mainScreen__fcTimeLabel[i], LV_SIZE_CONTENT,
                        LV_SIZE_CONTENT);

        GUI_Label__mainScreen__fcTempLabel[i] =
            lv_label_create(GUI_Container__mainScreen__fcPanel[i]);
        lv_label_set_long_mode(GUI_Label__mainScreen__fcTempLabel[i],
                               LV_LABEL_LONG_CLIP);
        lv_obj_set_align(GUI_Label__mainScreen__fcTempLabel[i],
                         LV_ALIGN_TOP_MID);
        lv_obj_set_y(GUI_Label__mainScreen__fcTempLabel[i], 130);
        lv_obj_set_size(GUI_Label__mainScreen__fcTempLabel[i], LV_SIZE_CONTENT,
                        LV_SIZE_CONTENT);
    }

    lv_obj_refr_size(GUI_Container__mainScreen__fcContainer);

    GUI_initScreenStyles__mainScreen();
    GUI_initScreenTexts__mainScreen();
}

void GUI_initScreenTexts__mainScreen() {
    lv_label_set_text(GUI_Label__mainScreen__timeLabel, "--:--");
    lv_label_set_text(GUI_Label__mainScreen__dayLabel, "--");
    lv_label_set_text(GUI_Label__mainScreen__dateLabel, "--");
    lv_label_set_text(GUI_Label__mainScreen__locationLabel, "--");
    lv_label_set_text(GUI_Label__mainScreen__tempLabel, "--°C");
    lv_label_set_text(GUI_Label__mainScreen__wthLabel, "--");
    lv_label_set_text(GUI_Label__mainScreen__minMaxLabel, "H: --°C | L: --°C");
    lv_label_set_text(GUI_Label__mainScreen__fcLabel, "No Forecast Available");
    for (int i = 0; i < 10; i++) {
        lv_label_set_text(GUI_Label__mainScreen__fcTimeLabel[i], "--:--");
        lv_label_set_text(GUI_Label__mainScreen__fcTempLabel[i], "--°C");
    }
}

void GUI_initScreenStyles__mainScreen() {
    lv_obj_add_style(GUI_Screen__mainScreen, &GUI_Style__defaultBg,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_style(GUI_Label__mainScreen__timeLabel, &GUI_Style__interB132C_White,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_style(GUI_Label__mainScreen__dayLabel, &GUI_Style__poppins36C_White,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_style(GUI_Label__mainScreen__dateLabel,
                     &GUI_Style__poppins36C_White,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_style(GUI_Panel__mainScreen__weatherPanel,
                     &GUI_Style__defaultPanel,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_style(GUI_Label__mainScreen__locationLabel,
                     &GUI_Style__poppins36C_White,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_style(GUI_Label__mainScreen__tempLabel,
                     &GUI_Style__inter80L_White,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_image_set_src(GUI_Image__mainScreen__wthIcon, &sun);

    lv_image_set_scale_x(GUI_Image__mainScreen__wthIcon, 512);
    lv_image_set_scale_y(GUI_Image__mainScreen__wthIcon, 512);

    lv_obj_add_style(GUI_Image__mainScreen__wthIcon, &GUI_Style__wthIcon,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_style(GUI_Label__mainScreen__wthLabel, &GUI_Style__poppins20C_White,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_style(GUI_Label__mainScreen__minMaxLabel,
                     &GUI_Style__poppins20C_White,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_style(GUI_Line__mainScreen__dividerLine, &GUI_Style__whiteLine,
                     0);

    lv_obj_add_style(GUI_Label__mainScreen__fcLabel, &GUI_Style__poppins20C_White,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_style(GUI_Container__mainScreen__fcContainer,
                     &GUI_Style__defaultBg, LV_PART_MAIN | LV_STATE_DEFAULT);

    for (int i = 0; i < 10; i++) {
        lv_image_set_src(GUI_Image__mainScreen__fcWthIcon[i], &sun);

        lv_image_set_scale_x(GUI_Image__mainScreen__fcWthIcon[i], 370);
        lv_image_set_scale_y(GUI_Image__mainScreen__fcWthIcon[i], 370);

        lv_obj_add_style(GUI_Image__mainScreen__fcWthIcon[i],
                         &GUI_Style__forecastWthIcon,
                         LV_PART_MAIN | LV_STATE_DEFAULT);

        lv_obj_add_style(GUI_Label__mainScreen__fcTimeLabel[i],
                         &GUI_Style__poppins20C_White,
                         LV_PART_MAIN | LV_STATE_DEFAULT);

        lv_obj_add_style(GUI_Label__mainScreen__fcTempLabel[i],
                         &GUI_Style__interB22L_White,
                         LV_PART_MAIN | LV_STATE_DEFAULT);
    }
}
