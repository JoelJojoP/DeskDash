#ifndef _GUI_CORE_H
#define _GUI_CORE_H

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

// Screen-specific function declarations
void GUI_initScreen__splashScreen();
void GUI_initScreenTexts__splashScreen();
void GUI_initScreenStyles__splashScreen();

void GUI_initScreen__mainScreen();
void GUI_initScreenTexts__mainScreen();
void GUI_initScreenStyles__mainScreen();

void GUI_initScreen__alarmScreen();
void GUI_initScreenTexts__alarmScreen();
void GUI_initScreenStyles__alarmScreen();

extern lv_style_t GUI_Style__class_ee5haLh6BPfC7X__blackBgStyle;
extern lv_style_t GUI_Style__class_nO9WWVajdwferl__imageBgStyle;
extern lv_style_t GUI_Style__class_z25cHb6hZ3yXcf__timeDispStyle;
extern lv_style_t GUI_Style__class_dQqT0mpaLpxNFX__dateDispStyle;
extern lv_style_t GUI_Style__class_hbZ9trKSkKmFm7__defPanelStyle;
extern lv_style_t GUI_Style__class_MUYJKm3UpbRtLk__tempDispStyle;
extern lv_style_t GUI_Style__class_qhbKUz960C5eEN__icoStyle;
extern lv_style_t GUI_Style__class_dWy3Gyh9l0NT39__wthStyle;
extern lv_style_t GUI_Style__class_ovYKeEQJT7E3hI__;
extern lv_style_t GUI_Style__class_S7dDwgCAuB7Nxa__sideBarStyle;
extern lv_style_t GUI_Style__class_5lXjjcQvO2YFLl__buttonStyle;
extern lv_style_t GUI_Style__class_L11bizL1MaPXIx__sideTextStyle;
extern lv_style_t GUI_Style__class_fAAuYI7RtRWXqZ__;

void GUI_load();

void GUI_init();

void GUI_refresh();

void GUI_initHAL();
void HAL_init();

void GUI_initFramework();

void GUI_loadContent();

void GUI_initContent();

void GUI_initTheme();

void GUI_initScreens();

void GUI_loadFirstScreen();

void GUI_initScreenContents();

void GUI_initScreenTexts();

void GUI_initScreenStyles();

void GUI_initGlobalStyles();

void GUI_initAnimations();

void GUI_event__Button__mainScreen__homeButton__Clicked(lv_event_t *event);
void GUI_event__Button__mainScreen__alarmButton__Clicked(lv_event_t *event);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
