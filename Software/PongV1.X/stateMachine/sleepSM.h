#ifndef _SLEEPSM
#define _SLEEPSM
#include "../xf/xf.h"
#include "display.h"
#include "gameController.h"
#include "touchScreenSM.h"
#include "../class/gameParameters.h"

//------------------------------------------------------------------------------
//Initialize sleepSM
//------------------------------------------------------------------------------
//State:    WAKEUP,default state
//------------------------------------------------------------------------------
void sleepInit(GameParameters* g);

//------------------------------------------------------------------------------
//Statemachine of sleep
//------------------------------------------------------------------------------
//State:    WAKEUP,
//          BACKLIGHTOFF,
//          SLEEP,
//------------------------------------------------------------------------------
void sleepSM(Event ev);

//------------------------------------------------------------------------------
//Action to do
//------------------------------------------------------------------------------
//State:    WAKEUP, pic awake
//          BACKLIGHTOFF, turn off luminosity after 30s of no touch
//          SLEEP,turn the pic in sleep mode after 60s of no touch
//------------------------------------------------------------------------------
void sleepController();

//------------------------------------------------------------------------------
//Config LCD pin for sleep mode
//------------------------------------------------------------------------------
void configPinSleep();
#endif
