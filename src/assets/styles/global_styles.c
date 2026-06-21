#include "../../../GUI.h"

void GUI_initGlobalStyles() {
    lv_style_init(&GUI_Style__defaultBgStyle);
    lv_style_set_bg_color(&GUI_Style__defaultBgStyle, lv_color_make(0, 0, 0));
    lv_style_set_bg_opa(&GUI_Style__defaultBgStyle, 0);

    lv_style_init(&GUI_Style__bgImageStyle);
    lv_style_set_transform_pivot_y(&GUI_Style__bgImageStyle, 45);
    lv_style_set_transform_pivot_x(&GUI_Style__bgImageStyle, 80);
    lv_style_set_transform_rotation(&GUI_Style__bgImageStyle, 0);
    // lv_style_set_transform_scale_y(&GUI_Style__bgImageStyle, 2048);
    // lv_style_set_transform_scale_x(&GUI_Style__bgImageStyle, 2048);
    lv_style_set_max_height(&GUI_Style__bgImageStyle, 720);
    lv_style_set_min_height(&GUI_Style__bgImageStyle, 0);
    lv_style_set_max_width(&GUI_Style__bgImageStyle, 1280);
    lv_style_set_min_width(&GUI_Style__bgImageStyle, 0);

    lv_style_init(&GUI_Style__timeStyle);
    lv_style_set_text_font(&GUI_Style__timeStyle, &interbold132px);
    lv_style_set_text_color(&GUI_Style__timeStyle,
                            lv_color_make(255, 255, 255));
    lv_style_set_text_opa(&GUI_Style__timeStyle, 255);
    lv_style_set_text_letter_space(&GUI_Style__timeStyle, 0);
    lv_style_set_text_line_space(&GUI_Style__timeStyle, 0);
    lv_style_set_text_align(&GUI_Style__timeStyle, LV_TEXT_ALIGN_CENTER);

    lv_style_init(&GUI_Style__dateDispStyle);
    lv_style_set_text_font(&GUI_Style__dateDispStyle, &poppins36px);
    lv_style_set_text_color(&GUI_Style__dateDispStyle,
                            lv_color_make(255, 255, 255));
    lv_style_set_text_opa(&GUI_Style__dateDispStyle, 255);
    lv_style_set_text_letter_space(&GUI_Style__dateDispStyle, 0);
    lv_style_set_text_line_space(&GUI_Style__dateDispStyle, 0);
    lv_style_set_text_align(&GUI_Style__dateDispStyle, LV_TEXT_ALIGN_CENTER);

    lv_style_init(&GUI_Style__defaultPanelStyle);
    lv_style_set_bg_color(&GUI_Style__defaultPanelStyle,
                          lv_color_make(255, 255, 255));
    lv_style_set_bg_opa(&GUI_Style__defaultPanelStyle, 31);
    lv_style_set_radius(&GUI_Style__defaultPanelStyle, 30);
    lv_style_set_border_color(&GUI_Style__defaultPanelStyle,
                              lv_color_make(139, 139, 139));
    lv_style_set_border_opa(&GUI_Style__defaultPanelStyle, 255);
    lv_style_set_border_width(&GUI_Style__defaultPanelStyle, 2);
    lv_style_set_border_side(&GUI_Style__defaultPanelStyle,
                             LV_BORDER_SIDE_TOP | LV_BORDER_SIDE_RIGHT |
                                 LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_LEFT);

    lv_style_init(&GUI_Style__tempDispStyle);
    lv_style_set_text_font(&GUI_Style__tempDispStyle, &inter80px);
    lv_style_set_text_color(&GUI_Style__tempDispStyle,
                            lv_color_make(255, 255, 255));
    lv_style_set_text_opa(&GUI_Style__tempDispStyle, 255);
    lv_style_set_text_letter_space(&GUI_Style__tempDispStyle, 0);
    lv_style_set_text_line_space(&GUI_Style__tempDispStyle, 0);
    lv_style_set_text_align(&GUI_Style__tempDispStyle, LV_TEXT_ALIGN_LEFT);

    lv_style_init(&GUI_Style__wthIconStyle);
    lv_style_set_min_width(&GUI_Style__wthIconStyle, 0);
    lv_style_set_max_width(&GUI_Style__wthIconStyle, 96);
    lv_style_set_min_height(&GUI_Style__wthIconStyle, 0);
    lv_style_set_max_height(&GUI_Style__wthIconStyle, 96);
    // lv_style_set_transform_scale_x(&GUI_Style__wthIconStyle, 512);
    // lv_style_set_transform_scale_y(&GUI_Style__wthIconStyle, 512);
    lv_style_set_transform_rotation(&GUI_Style__wthIconStyle, 0);
    lv_style_set_transform_pivot_x(&GUI_Style__wthIconStyle, 24);
    lv_style_set_transform_pivot_y(&GUI_Style__wthIconStyle, 24);

    lv_style_init(&GUI_Style__wthLabelStyle);
    lv_style_set_text_font(&GUI_Style__wthLabelStyle, &poppins20px);
    lv_style_set_text_color(&GUI_Style__wthLabelStyle,
                            lv_color_make(255, 255, 255));
    lv_style_set_text_opa(&GUI_Style__wthLabelStyle, 255);
    lv_style_set_text_letter_space(&GUI_Style__wthLabelStyle, 0);
    lv_style_set_text_line_space(&GUI_Style__wthLabelStyle, 0);
    lv_style_set_text_align(&GUI_Style__wthLabelStyle, LV_TEXT_ALIGN_CENTER);

    lv_style_init(&GUI_Style__lineStyle);
    lv_style_set_line_color(&GUI_Style__lineStyle, lv_color_make(255, 255, 255));
    lv_style_set_line_opa(&GUI_Style__lineStyle, 255);
    lv_style_set_line_width(&GUI_Style__lineStyle, 2);
    lv_style_set_line_rounded(&GUI_Style__lineStyle, false);

    lv_style_init(&GUI_Style__fcWthIconStyle);
    lv_style_set_min_width(&GUI_Style__fcWthIconStyle, 0);
    lv_style_set_max_width(&GUI_Style__fcWthIconStyle, 8000);
    lv_style_set_min_height(&GUI_Style__fcWthIconStyle, 0);
    lv_style_set_max_height(&GUI_Style__fcWthIconStyle, 8000);
    // lv_style_set_transform_scale_x(&GUI_Style__fcWthIconStyle, 370);
    // lv_style_set_transform_scale_y(&GUI_Style__fcWthIconStyle, 370);
    lv_style_set_transform_rotation(&GUI_Style__fcWthIconStyle, 0);
    lv_style_set_transform_pivot_x(&GUI_Style__fcWthIconStyle, 24);
    lv_style_set_transform_pivot_y(&GUI_Style__fcWthIconStyle, 24);

    lv_style_init(&GUI_Style__fcTempStyle);
    lv_style_set_text_font(&GUI_Style__fcTempStyle, &interbold22px);
    lv_style_set_text_color(&GUI_Style__fcTempStyle,
                            lv_color_make(255, 255, 255));
    lv_style_set_text_opa(&GUI_Style__fcTempStyle, 255);
    lv_style_set_text_letter_space(&GUI_Style__fcTempStyle, 0);
    lv_style_set_text_line_space(&GUI_Style__fcTempStyle, 0);
    lv_style_set_text_align(&GUI_Style__fcTempStyle, LV_TEXT_ALIGN_LEFT);

    lv_style_init(&GUI_Style__sideBarStyle);
    lv_style_set_bg_color(&GUI_Style__sideBarStyle, lv_color_make(37, 37, 37));
    lv_style_set_bg_opa(&GUI_Style__sideBarStyle, 255);
    lv_style_set_radius(&GUI_Style__sideBarStyle, 0);

    lv_style_init(&GUI_Style__sideButStyle);
    lv_style_set_bg_color(&GUI_Style__sideButStyle, lv_color_make(0, 0, 0));
    lv_style_set_bg_opa(&GUI_Style__sideButStyle, 0);
    lv_style_set_radius(&GUI_Style__sideButStyle, 0);

    lv_style_init(&GUI_Style__sideTextStyle);
    lv_style_set_text_font(&GUI_Style__sideTextStyle, &fonta32px);
    lv_style_set_text_color(&GUI_Style__sideTextStyle,
                            lv_color_make(255, 255, 255));
    lv_style_set_text_opa(&GUI_Style__sideTextStyle, 255);
    lv_style_set_text_letter_space(&GUI_Style__sideTextStyle, 0);
    lv_style_set_text_line_space(&GUI_Style__sideTextStyle, 0);
    lv_style_set_text_align(&GUI_Style__sideTextStyle, LV_TEXT_ALIGN_CENTER);

    lv_style_init(&GUI_Style__sideSelIndStyle);
    lv_style_set_bg_color(&GUI_Style__sideSelIndStyle,
                          lv_color_make(255, 255, 255));
    lv_style_set_bg_opa(&GUI_Style__sideSelIndStyle, 255);
    lv_style_set_radius(&GUI_Style__sideSelIndStyle, 0);
}
