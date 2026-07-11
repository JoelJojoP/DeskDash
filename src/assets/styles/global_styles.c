#include "../../../GUI.h"

void GUI_initGlobalStyles() {
    lv_style_init(&GUI_Style__defaultBg);
    lv_style_set_bg_color(&GUI_Style__defaultBg, lv_color_make(0, 0, 0));
    lv_style_set_bg_opa(&GUI_Style__defaultBg, 0);

    lv_style_init(&GUI_Style__blackBg);
    lv_style_set_bg_color(&GUI_Style__blackBg, lv_color_make(0, 0, 0));
    lv_style_set_bg_opa(&GUI_Style__blackBg, 255);

    lv_style_init(&GUI_Style__black60Bg);
    lv_style_set_bg_color(&GUI_Style__black60Bg, lv_color_make(0, 0, 0));
    lv_style_set_bg_opa(&GUI_Style__black60Bg, 153);

    lv_style_init(&GUI_Style__bgImage);
    lv_style_set_transform_pivot_y(&GUI_Style__bgImage, 45);
    lv_style_set_transform_pivot_x(&GUI_Style__bgImage, 80);
    lv_style_set_transform_rotation(&GUI_Style__bgImage, 0);
    lv_style_set_max_height(&GUI_Style__bgImage, 720);
    lv_style_set_min_height(&GUI_Style__bgImage, 0);
    lv_style_set_max_width(&GUI_Style__bgImage, 1280);
    lv_style_set_min_width(&GUI_Style__bgImage, 0);

    lv_style_init(&GUI_Style__interB132C_White);
    lv_style_set_text_font(&GUI_Style__interB132C_White, &interbold132px);
    lv_style_set_text_color(&GUI_Style__interB132C_White,
                            lv_color_make(255, 255, 255));
    lv_style_set_text_opa(&GUI_Style__interB132C_White, 255);
    lv_style_set_text_letter_space(&GUI_Style__interB132C_White, 0);
    lv_style_set_text_line_space(&GUI_Style__interB132C_White, 0);
    lv_style_set_text_align(&GUI_Style__interB132C_White, LV_TEXT_ALIGN_CENTER);

    lv_style_init(&GUI_Style__poppins36C_White);
    lv_style_set_text_font(&GUI_Style__poppins36C_White, &poppins36px);
    lv_style_set_text_color(&GUI_Style__poppins36C_White,
                            lv_color_make(255, 255, 255));
    lv_style_set_text_opa(&GUI_Style__poppins36C_White, 255);
    lv_style_set_text_letter_space(&GUI_Style__poppins36C_White, 0);
    lv_style_set_text_line_space(&GUI_Style__poppins36C_White, 0);
    lv_style_set_text_align(&GUI_Style__poppins36C_White, LV_TEXT_ALIGN_CENTER);

    lv_style_init(&GUI_Style__defaultPanel);
    lv_style_set_bg_color(&GUI_Style__defaultPanel,
                          lv_color_make(255, 255, 255));
    lv_style_set_bg_opa(&GUI_Style__defaultPanel, 31);
    lv_style_set_radius(&GUI_Style__defaultPanel, 30);
    lv_style_set_border_color(&GUI_Style__defaultPanel,
                              lv_color_make(139, 139, 139));
    lv_style_set_border_opa(&GUI_Style__defaultPanel, 255);
    lv_style_set_border_width(&GUI_Style__defaultPanel, 2);
    lv_style_set_border_side(&GUI_Style__defaultPanel,
                             LV_BORDER_SIDE_TOP | LV_BORDER_SIDE_RIGHT |
                                 LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_LEFT);

    lv_style_init(&GUI_Style__inter80L_White);
    lv_style_set_text_font(&GUI_Style__inter80L_White, &inter80px);
    lv_style_set_text_color(&GUI_Style__inter80L_White,
                            lv_color_make(255, 255, 255));
    lv_style_set_text_opa(&GUI_Style__inter80L_White, 255);
    lv_style_set_text_letter_space(&GUI_Style__inter80L_White, 0);
    lv_style_set_text_line_space(&GUI_Style__inter80L_White, 0);
    lv_style_set_text_align(&GUI_Style__inter80L_White, LV_TEXT_ALIGN_LEFT);

    lv_style_init(&GUI_Style__wthIcon);
    lv_style_set_min_width(&GUI_Style__wthIcon, 0);
    lv_style_set_max_width(&GUI_Style__wthIcon, 96);
    lv_style_set_min_height(&GUI_Style__wthIcon, 0);
    lv_style_set_max_height(&GUI_Style__wthIcon, 96);
    lv_style_set_transform_rotation(&GUI_Style__wthIcon, 0);
    lv_style_set_transform_pivot_x(&GUI_Style__wthIcon, 24);
    lv_style_set_transform_pivot_y(&GUI_Style__wthIcon, 24);

    lv_style_init(&GUI_Style__poppins20C_White);
    lv_style_set_text_font(&GUI_Style__poppins20C_White, &poppins20px);
    lv_style_set_text_color(&GUI_Style__poppins20C_White,
                            lv_color_make(255, 255, 255));
    lv_style_set_text_opa(&GUI_Style__poppins20C_White, 255);
    lv_style_set_text_letter_space(&GUI_Style__poppins20C_White, 0);
    lv_style_set_text_line_space(&GUI_Style__poppins20C_White, 0);
    lv_style_set_text_align(&GUI_Style__poppins20C_White, LV_TEXT_ALIGN_CENTER);

    lv_style_init(&GUI_Style__whiteLine);
    lv_style_set_line_color(&GUI_Style__whiteLine,
                            lv_color_make(255, 255, 255));
    lv_style_set_line_opa(&GUI_Style__whiteLine, 255);
    lv_style_set_line_width(&GUI_Style__whiteLine, 2);
    lv_style_set_line_rounded(&GUI_Style__whiteLine, false);

    lv_style_init(&GUI_Style__forecastWthIcon);
    lv_style_set_min_width(&GUI_Style__forecastWthIcon, 0);
    lv_style_set_max_width(&GUI_Style__forecastWthIcon, 8000);
    lv_style_set_min_height(&GUI_Style__forecastWthIcon, 0);
    lv_style_set_max_height(&GUI_Style__forecastWthIcon, 8000);
    lv_style_set_transform_rotation(&GUI_Style__forecastWthIcon, 0);
    lv_style_set_transform_pivot_x(&GUI_Style__forecastWthIcon, 24);
    lv_style_set_transform_pivot_y(&GUI_Style__forecastWthIcon, 24);

    lv_style_init(&GUI_Style__interB22L_White);
    lv_style_set_text_font(&GUI_Style__interB22L_White, &interbold22px);
    lv_style_set_text_color(&GUI_Style__interB22L_White,
                            lv_color_make(255, 255, 255));
    lv_style_set_text_opa(&GUI_Style__interB22L_White, 255);
    lv_style_set_text_letter_space(&GUI_Style__interB22L_White, 0);
    lv_style_set_text_line_space(&GUI_Style__interB22L_White, 0);
    lv_style_set_text_align(&GUI_Style__interB22L_White, LV_TEXT_ALIGN_LEFT);

    lv_style_init(&GUI_Style__montserratL80C_Black);
    lv_style_set_text_font(&GUI_Style__montserratL80C_Black,
                           &montserratlight80px);
    lv_style_set_text_color(&GUI_Style__montserratL80C_Black,
                            lv_color_make(0, 0, 0));
    lv_style_set_text_opa(&GUI_Style__montserratL80C_Black, 255);
    lv_style_set_text_letter_space(&GUI_Style__montserratL80C_Black, 0);
    lv_style_set_text_line_space(&GUI_Style__montserratL80C_Black, 0);
    lv_style_set_text_align(&GUI_Style__montserratL80C_Black,
                            LV_TEXT_ALIGN_CENTER);

    lv_style_init(&GUI_Style__sideBar);
    lv_style_set_bg_color(&GUI_Style__sideBar, lv_color_make(37, 37, 37));
    lv_style_set_bg_opa(&GUI_Style__sideBar, 255);
    lv_style_set_radius(&GUI_Style__sideBar, 0);

    lv_style_init(&GUI_Style__sidebarButton);
    lv_style_set_bg_color(&GUI_Style__sidebarButton, lv_color_make(0, 0, 0));
    lv_style_set_bg_opa(&GUI_Style__sidebarButton, 0);
    lv_style_set_radius(&GUI_Style__sidebarButton, 0);

    lv_style_init(&GUI_Style__sidebarIcon);
    lv_style_set_text_font(&GUI_Style__sidebarIcon, &fonta32px);
    lv_style_set_text_color(&GUI_Style__sidebarIcon,
                            lv_color_make(255, 255, 255));
    lv_style_set_text_opa(&GUI_Style__sidebarIcon, 255);
    lv_style_set_text_letter_space(&GUI_Style__sidebarIcon, 0);
    lv_style_set_text_line_space(&GUI_Style__sidebarIcon, 0);
    lv_style_set_text_align(&GUI_Style__sidebarIcon, LV_TEXT_ALIGN_CENTER);

    lv_style_init(&GUI_Style__sidebarIndicator);
    lv_style_set_bg_color(&GUI_Style__sidebarIndicator,
                          lv_color_make(255, 255, 255));
    lv_style_set_bg_opa(&GUI_Style__sidebarIndicator, 255);
    lv_style_set_radius(&GUI_Style__sidebarIndicator, 0);

    lv_style_init(&GUI_Style__blueButton);
    lv_style_set_bg_color(&GUI_Style__blueButton, lv_color_make(110, 147, 198));
    lv_style_set_bg_opa(&GUI_Style__blueButton, 255);
    lv_style_set_radius(&GUI_Style__blueButton, 50);

    lv_style_init(&GUI_Style__blueActiveSwitch);
    lv_style_set_bg_color(&GUI_Style__blueActiveSwitch,
                          lv_color_make(35, 84, 153));
    lv_style_set_bg_opa(&GUI_Style__blueActiveSwitch, 255);
    lv_style_set_radius(&GUI_Style__blueActiveSwitch, 20);
}
