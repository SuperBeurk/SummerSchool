#ifndef _TOUCHSCREENSM
#define _TOUCHSCREENSM

#define _DIR_XR TRISB1
#define _DIR_XL TRISB3
#define _DIR_YU TRISB2
#define _DIR_YD TRISB4

#define _TSC_XR LATB1
#define _TSC_XL LATB3
#define _TSC_YU LATB2
#define _TSC_YD LATB4

#define _TSC_OFFSET_X 120
#define _TSC_OFFSET_Y 105
#define _TSC_CONV_X 2.35
#define _TSC_CONV_Y 2
#define _TSC_MAX_X 240

#include "../xf/xf.h"
#include "../libraries/lcd_highlevel.h"
#include "../class/gameParameters.h"
#include <pic18.h>
void touchScreenInit();
void touchScreenSM(Event ev,GameParameters* g);
void touchScreenController(GameParameters* g);
void configTouch();
void configMeasure(bool channel);
#endif