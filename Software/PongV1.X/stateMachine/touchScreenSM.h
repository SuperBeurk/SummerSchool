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

//------------------------------------------------------------------------------
//Initialize touchScreenSM
//------------------------------------------------------------------------------
//State:    WAITING,default state
//------------------------------------------------------------------------------
void touchScreenInit();

//------------------------------------------------------------------------------
//Statemachine of touchScreen
//------------------------------------------------------------------------------
//State:    WAITING
//          CALCULATEPOS,
//------------------------------------------------------------------------------
void touchScreenSM(Event ev,GameParameters* g);

//------------------------------------------------------------------------------
//Action to do on a state
//------------------------------------------------------------------------------
//State:    WAITING, Change LCD pin config for waiting touch interrupt
//          CALCULATEPOS, Change LCD pin onfig for measure  the position then 
//          change the config again to wait a release event, 
//          and recalcule the position if there is no release event every 90 ms(evTimerPos)
//------------------------------------------------------------------------------
void touchScreenController(GameParameters* g);

//------------------------------------------------------------------------------
//Configure the YU,YD,XR,XL pins for waiting interrupt
//------------------------------------------------------------------------------
void configTouch();

//------------------------------------------------------------------------------
//Configure the YU,YD,XR,XL pins for measure the position
//------------------------------------------------------------------------------
void configMeasure(bool channel);
#endif