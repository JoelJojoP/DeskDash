#include "../../../GUI.h"

void GUI_initGlobalStyles() {
  lv_style_init(&GUI_Style__class_ee5haLh6BPfC7X__blackBgStyle);
  lv_style_set_bg_color(&GUI_Style__class_ee5haLh6BPfC7X__blackBgStyle,
                        lv_color_make(0, 0, 0));
  lv_style_set_bg_opa(&GUI_Style__class_ee5haLh6BPfC7X__blackBgStyle, 255);
  lv_style_set_radius(&GUI_Style__class_ee5haLh6BPfC7X__blackBgStyle, 0);

  lv_style_init(&GUI_Style__class_nO9WWVajdwferl__imageBgStyle);
  lv_style_set_min_width(&GUI_Style__class_nO9WWVajdwferl__imageBgStyle, 0);
  lv_style_set_max_width(&GUI_Style__class_nO9WWVajdwferl__imageBgStyle, 1280);
  lv_style_set_min_height(&GUI_Style__class_nO9WWVajdwferl__imageBgStyle, 0);
  lv_style_set_max_height(&GUI_Style__class_nO9WWVajdwferl__imageBgStyle, 720);
//   lv_style_set_transform_scale_x(&GUI_Style__class_nO9WWVajdwferl__imageBgStyle,
//                                  2048);
//   lv_style_set_transform_scale_y(&GUI_Style__class_nO9WWVajdwferl__imageBgStyle,
//                                  2048);
  lv_style_set_transform_rotation(
      &GUI_Style__class_nO9WWVajdwferl__imageBgStyle, 0);
  lv_style_set_transform_pivot_x(&GUI_Style__class_nO9WWVajdwferl__imageBgStyle,
                                 80);
  lv_style_set_transform_pivot_y(&GUI_Style__class_nO9WWVajdwferl__imageBgStyle,
                                 45);

  lv_style_init(&GUI_Style__class_z25cHb6hZ3yXcf__timeDispStyle);
  lv_style_set_text_font(&GUI_Style__class_z25cHb6hZ3yXcf__timeDispStyle,
                         &inter);
  lv_style_set_text_color(&GUI_Style__class_z25cHb6hZ3yXcf__timeDispStyle,
                          lv_color_make(255, 255, 255));
  lv_style_set_text_opa(&GUI_Style__class_z25cHb6hZ3yXcf__timeDispStyle, 255);
  lv_style_set_text_letter_space(
      &GUI_Style__class_z25cHb6hZ3yXcf__timeDispStyle, 0);
  lv_style_set_text_line_space(&GUI_Style__class_z25cHb6hZ3yXcf__timeDispStyle,
                               0);
  lv_style_set_text_align(&GUI_Style__class_z25cHb6hZ3yXcf__timeDispStyle,
                          LV_TEXT_ALIGN_LEFT);

  lv_style_init(&GUI_Style__class_dQqT0mpaLpxNFX__dateDispStyle);
  lv_style_set_text_font(&GUI_Style__class_dQqT0mpaLpxNFX__dateDispStyle,
                         &font);
  lv_style_set_text_color(&GUI_Style__class_dQqT0mpaLpxNFX__dateDispStyle,
                          lv_color_make(255, 255, 255));
  lv_style_set_text_opa(&GUI_Style__class_dQqT0mpaLpxNFX__dateDispStyle, 255);
  lv_style_set_text_letter_space(
      &GUI_Style__class_dQqT0mpaLpxNFX__dateDispStyle, 0);
  lv_style_set_text_line_space(&GUI_Style__class_dQqT0mpaLpxNFX__dateDispStyle,
                               0);
  lv_style_set_text_align(&GUI_Style__class_dQqT0mpaLpxNFX__dateDispStyle,
                          LV_TEXT_ALIGN_LEFT);

  lv_style_init(&GUI_Style__class_hbZ9trKSkKmFm7__defPanelStyle);
  lv_style_set_bg_color(&GUI_Style__class_hbZ9trKSkKmFm7__defPanelStyle,
                        lv_color_make(255, 255, 255));
  lv_style_set_bg_opa(&GUI_Style__class_hbZ9trKSkKmFm7__defPanelStyle, 31);
  lv_style_set_radius(&GUI_Style__class_hbZ9trKSkKmFm7__defPanelStyle, 30);
  lv_style_set_border_color(&GUI_Style__class_hbZ9trKSkKmFm7__defPanelStyle,
                            lv_color_make(139, 139, 139));
  lv_style_set_border_opa(&GUI_Style__class_hbZ9trKSkKmFm7__defPanelStyle, 255);
  lv_style_set_border_width(&GUI_Style__class_hbZ9trKSkKmFm7__defPanelStyle, 2);
  lv_style_set_border_side(&GUI_Style__class_hbZ9trKSkKmFm7__defPanelStyle,
                           LV_BORDER_SIDE_TOP | LV_BORDER_SIDE_RIGHT |
                               LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_LEFT);

  lv_style_init(&GUI_Style__class_MUYJKm3UpbRtLk__tempDispStyle);
  lv_style_set_text_font(&GUI_Style__class_MUYJKm3UpbRtLk__tempDispStyle,
                         &inter100px);
  lv_style_set_text_color(&GUI_Style__class_MUYJKm3UpbRtLk__tempDispStyle,
                          lv_color_make(255, 255, 255));
  lv_style_set_text_opa(&GUI_Style__class_MUYJKm3UpbRtLk__tempDispStyle, 255);
  lv_style_set_text_letter_space(
      &GUI_Style__class_MUYJKm3UpbRtLk__tempDispStyle, 0);
  lv_style_set_text_line_space(&GUI_Style__class_MUYJKm3UpbRtLk__tempDispStyle,
                               0);
  lv_style_set_text_align(&GUI_Style__class_MUYJKm3UpbRtLk__tempDispStyle,
                          LV_TEXT_ALIGN_LEFT);

  lv_style_init(&GUI_Style__class_qhbKUz960C5eEN__icoStyle);
  lv_style_set_min_width(&GUI_Style__class_qhbKUz960C5eEN__icoStyle, 0);
  lv_style_set_max_width(&GUI_Style__class_qhbKUz960C5eEN__icoStyle, 96);
  lv_style_set_min_height(&GUI_Style__class_qhbKUz960C5eEN__icoStyle, 0);
  lv_style_set_max_height(&GUI_Style__class_qhbKUz960C5eEN__icoStyle, 96);
//   lv_style_set_transform_scale_x(&GUI_Style__class_qhbKUz960C5eEN__icoStyle,
//                                  512);
//   lv_style_set_transform_scale_y(&GUI_Style__class_qhbKUz960C5eEN__icoStyle,
//                                  512);
  lv_style_set_transform_rotation(&GUI_Style__class_qhbKUz960C5eEN__icoStyle,
                                  0);
  lv_style_set_transform_pivot_x(&GUI_Style__class_qhbKUz960C5eEN__icoStyle,
                                 24);
  lv_style_set_transform_pivot_y(&GUI_Style__class_qhbKUz960C5eEN__icoStyle,
                                 24);

  lv_style_init(&GUI_Style__class_dWy3Gyh9l0NT39__wthStyle);
  lv_style_set_text_font(&GUI_Style__class_dWy3Gyh9l0NT39__wthStyle,
                         &poppins20px);
  lv_style_set_text_color(&GUI_Style__class_dWy3Gyh9l0NT39__wthStyle,
                          lv_color_make(255, 255, 255));
  lv_style_set_text_opa(&GUI_Style__class_dWy3Gyh9l0NT39__wthStyle, 255);
  lv_style_set_text_letter_space(&GUI_Style__class_dWy3Gyh9l0NT39__wthStyle, 0);
  lv_style_set_text_line_space(&GUI_Style__class_dWy3Gyh9l0NT39__wthStyle, 0);
  lv_style_set_text_align(&GUI_Style__class_dWy3Gyh9l0NT39__wthStyle,
                          LV_TEXT_ALIGN_RIGHT);

  lv_style_init(&GUI_Style__class_ovYKeEQJT7E3hI__);
  lv_style_set_flex_flow(&GUI_Style__class_ovYKeEQJT7E3hI__, LV_FLEX_FLOW_ROW);
  lv_style_set_flex_main_place(&GUI_Style__class_ovYKeEQJT7E3hI__,
                               LV_FLEX_ALIGN_START);
  lv_style_set_flex_track_place(&GUI_Style__class_ovYKeEQJT7E3hI__,
                                LV_FLEX_ALIGN_START);
  lv_style_set_flex_cross_place(&GUI_Style__class_ovYKeEQJT7E3hI__,
                                LV_FLEX_ALIGN_START);
  lv_style_set_pad_row(&GUI_Style__class_ovYKeEQJT7E3hI__, 0);
  lv_style_set_pad_column(&GUI_Style__class_ovYKeEQJT7E3hI__, 0);
  lv_style_set_layout(&GUI_Style__class_ovYKeEQJT7E3hI__, LV_LAYOUT_FLEX);

  lv_style_init(&GUI_Style__class_S7dDwgCAuB7Nxa__sideBarStyle);
  lv_style_set_bg_color(&GUI_Style__class_S7dDwgCAuB7Nxa__sideBarStyle,
                        lv_color_make(37, 37, 37));
  lv_style_set_bg_opa(&GUI_Style__class_S7dDwgCAuB7Nxa__sideBarStyle, 255);
  lv_style_set_radius(&GUI_Style__class_S7dDwgCAuB7Nxa__sideBarStyle, 0);

  lv_style_init(&GUI_Style__class_5lXjjcQvO2YFLl__buttonStyle);
  lv_style_set_bg_color(&GUI_Style__class_5lXjjcQvO2YFLl__buttonStyle,
                        lv_color_make(0, 0, 0));
  lv_style_set_bg_opa(&GUI_Style__class_5lXjjcQvO2YFLl__buttonStyle, 0);
  lv_style_set_radius(&GUI_Style__class_5lXjjcQvO2YFLl__buttonStyle, 0);

  lv_style_init(&GUI_Style__class_L11bizL1MaPXIx__sideTextStyle);
  lv_style_set_text_font(&GUI_Style__class_L11bizL1MaPXIx__sideTextStyle,
                         &fonta32px);
  lv_style_set_text_color(&GUI_Style__class_L11bizL1MaPXIx__sideTextStyle,
                          lv_color_make(255, 255, 255));
  lv_style_set_text_opa(&GUI_Style__class_L11bizL1MaPXIx__sideTextStyle, 255);
  lv_style_set_text_letter_space(
      &GUI_Style__class_L11bizL1MaPXIx__sideTextStyle, 0);
  lv_style_set_text_line_space(&GUI_Style__class_L11bizL1MaPXIx__sideTextStyle,
                               0);
  lv_style_set_text_align(&GUI_Style__class_L11bizL1MaPXIx__sideTextStyle,
                          LV_TEXT_ALIGN_CENTER);

  lv_style_init(&GUI_Style__class_fAAuYI7RtRWXqZ__);
  lv_style_set_bg_color(&GUI_Style__class_fAAuYI7RtRWXqZ__,
                        lv_color_make(255, 255, 255));
  lv_style_set_bg_opa(&GUI_Style__class_fAAuYI7RtRWXqZ__, 255);
  lv_style_set_radius(&GUI_Style__class_fAAuYI7RtRWXqZ__, 0);
}
