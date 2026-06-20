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
void GUI_initScreen__commonElement();
void GUI_initScreenTexts__commonElement();
void GUI_initScreenStyles__commonElement();

void GUI_initScreen__splashScreen();
void GUI_initScreenTexts__splashScreen();
void GUI_initScreenStyles__splashScreen();

void GUI_initScreen__mainScreen();
void GUI_initScreenTexts__mainScreen();
void GUI_initScreenStyles__mainScreen();

void GUI_initScreen__alarmScreen();
void GUI_initScreenTexts__alarmScreen();
void GUI_initScreenStyles__alarmScreen();

extern lv_style_t GUI_Style__defaultBgStyle;
extern lv_style_t GUI_Style__bgImageStyle;
extern lv_style_t GUI_Style__timeStyle;
extern lv_style_t GUI_Style__dateDispStyle;
extern lv_style_t GUI_Style__defaultPanelStyle;
extern lv_style_t GUI_Style__tempDispStyle;
extern lv_style_t GUI_Style__wthIconStyle;
extern lv_style_t GUI_Style__wthLabelStyle;
extern lv_style_t GUI_Style__lineStyle;
extern lv_style_t GUI_Style__fcWthIconStyle;
extern lv_style_t GUI_Style__class_ag0ku4tzpzkW1P__fcTimeStyle;
extern lv_style_t GUI_Style__fcTempStyle;
extern lv_style_t GUI_Style__sideBarStyle;
extern lv_style_t GUI_Style__sideButStyle;
extern lv_style_t GUI_Style__sideTextStyle;
extern lv_style_t GUI_Style__sideSelIndStyle;

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

void GUI_event__Button__topLayer__homeButton__Clicked(lv_event_t *event);
void GUI_event__Button__topLayer__alarmButton__Clicked(lv_event_t *event);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
