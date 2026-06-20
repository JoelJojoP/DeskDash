#ifndef _GUI_VARIABLES_H
#define _GUI_VARIABLES_H

#include "gui_core.h"

#ifdef __cplusplus
extern "C" {
#endif

extern lv_obj_t *GUI_Image__bottomLayer__bgImage;
extern lv_obj_t *GUI_Panel__topLayer__sideBar;
extern lv_obj_t *GUI_Button__topLayer__homeButton;
extern lv_obj_t *GUI_Label__topLayer__homeLabel;
extern lv_obj_t *GUI_Button__topLayer__alarmButton;
extern lv_obj_t *GUI_Label__topLayer__alarmLabel;
extern lv_obj_t *GUI_Panel__topLayer__selIndicator;
extern lv_obj_t *GUI_Button__topLayer__wifiButton;
extern lv_obj_t *GUI_Label__topLayer__wifiLabel;
extern lv_obj_t *GUI_Button__topLayer__settingButton;
extern lv_obj_t *GUI_Label__topLayer__settingLabel;

extern lv_obj_t *GUI_Screen__splashScreen;

extern lv_obj_t *GUI_Screen__mainScreen;
extern lv_obj_t *GUI_Container__mainScreen__timeContainer;
extern lv_obj_t *GUI_Label__mainScreen__timeLabel;
extern lv_obj_t *GUI_Label__mainScreen__dayLabel;
extern lv_obj_t *GUI_Label__mainScreen__dateLabel;
extern lv_obj_t *GUI_Panel__mainScreen__weatherPanel;
extern lv_obj_t *GUI_Label__mainScreen__locationLabel;
extern lv_obj_t *GUI_Label__mainScreen__tempLabel;
extern lv_obj_t *GUI_Image__mainScreen__wthIcon;
extern lv_obj_t *GUI_Label__mainScreen__wthLabel;
extern lv_obj_t *GUI_Label__mainScreen__minMaxLabel;
extern lv_obj_t *GUI_Line__mainScreen__dividerLine;
extern lv_obj_t *GUI_Label__mainScreen__fcLabel;
extern lv_obj_t *GUI_Container__mainScreen__fcContainer;
extern lv_obj_t *GUI_Container__mainScreen__fcPanel[10];
extern lv_obj_t *GUI_Image__mainScreen__fcWthIcon[10];
extern lv_obj_t *GUI_Label__mainScreen__fcTimeLabel[10];
extern lv_obj_t *GUI_Label__mainScreen__fcTempLabel[10];

extern lv_obj_t *GUI_Screen__alarmScreen;

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
