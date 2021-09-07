#ifndef _GAMECONTROLLER
#define _GAMECONTROLLER
#include "../xf/xf.h"
#include "../class/gameParameters.h"
#include "../gameFunction.h"
#include "sleepSM.h"
//------------------------------------------------------------------------------
//Initialize gameControllerSM
//------------------------------------------------------------------------------
//State:    NOGAME, default state
//------------------------------------------------------------------------------
void gameControllerInit(GameParameters* g);

//------------------------------------------------------------------------------
//Statemachine of gamController
//------------------------------------------------------------------------------
//State:    NOGAME,
//          PARAMETERS,
//          LOCAL,
//          ONLINE,
//          ENDGAME
//------------------------------------------------------------------------------
void gameControllerSM(Event ev,GameParameters* g);

//------------------------------------------------------------------------------
//Action to do on a state
//------------------------------------------------------------------------------
//State:    NOGAME, Check click in button
//          PARAMETERS, SlideBar for backlight
//          LOCAL,  Moove both paddle Moove ball
//          ONLINE,
//          ENDGAME Check click in button new game or sleep
//------------------------------------------------------------------------------
void gameControllerController(GameParameters* g,Event ev);
#endif
