#ifndef _GUI_VARIABLES_H
#define _GUI_VARIABLES_H

#include "gui_core.h"

#ifdef __cplusplus
extern "C" {
#endif

extern lv_obj_t *GUI_Screen__splashScreen;
extern lv_obj_t *GUI_Bar__splashScreen__initBar;

extern lv_obj_t *GUI_Screen__mainScreen;
extern lv_obj_t *GUI_Image__mainScreen__bgImage;
extern lv_obj_t *GUI_Container__mainScreen__timeContainer;
extern lv_obj_t *GUI_Label__mainScreen__timeLabel;
extern lv_obj_t *GUI_Label__mainScreen__dayLabel;
extern lv_obj_t *GUI_Label__mainScreen__dateLabel;
extern lv_obj_t *GUI_Panel__mainScreen__weatherPanel;
extern lv_obj_t *GUI_Label__mainScreen__locLabel;
extern lv_obj_t *GUI_Label__mainScreen__tempLabel;
extern lv_obj_t *GUI_Image__mainScreen__wthIcon;
extern lv_obj_t *GUI_Label__mainScreen__wthLabel;
extern lv_obj_t *GUI_Label__mainScreen__minMaxLabel;

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
