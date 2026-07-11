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

extern lv_style_t GUI_Style__defaultBg;
extern lv_style_t GUI_Style__blackBg;
extern lv_style_t GUI_Style__black60Bg;
extern lv_style_t GUI_Style__bgImage;
extern lv_style_t GUI_Style__interB132C_White;
extern lv_style_t GUI_Style__poppins36C_White;
extern lv_style_t GUI_Style__defaultPanel;
extern lv_style_t GUI_Style__inter80L_White;
extern lv_style_t GUI_Style__montserratL80C_Black;
extern lv_style_t GUI_Style__wthIcon;
extern lv_style_t GUI_Style__poppins20C_White;
extern lv_style_t GUI_Style__whiteLine;
extern lv_style_t GUI_Style__forecastWthIcon;
extern lv_style_t GUI_Style__interB22L_White;
extern lv_style_t GUI_Style__sideBar;
extern lv_style_t GUI_Style__sidebarButton;
extern lv_style_t GUI_Style__sidebarIcon;
extern lv_style_t GUI_Style__sidebarIndicator;
extern lv_style_t GUI_Style__blueButton;
extern lv_style_t GUI_Style__blueActiveSwitch;

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
