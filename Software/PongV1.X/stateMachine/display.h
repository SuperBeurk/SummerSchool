#ifndef _DISPLAY
#define _DISPLAY
#include "../xf/xf.h"
#include "../libraries/lcd_highlevel.h"
#include "../class/menu.h"
#include "../class/gameParameters.h"

//------------------------------------------------------------------------------
//Initialize displaySM
//------------------------------------------------------------------------------
//State:    WELCOME,default state
//------------------------------------------------------------------------------
void displayInit(GameParameters* g);

//------------------------------------------------------------------------------
//Statemachine of displaySM
//------------------------------------------------------------------------------
//State:    WELCOME,
//          PARAMETERS,
//          INGAME,
//          ENDGAME,
//------------------------------------------------------------------------------
void displaySM(Event ev,GameParameters* g);

//------------------------------------------------------------------------------
//Action to do on a state
//------------------------------------------------------------------------------
//State:    WELCOME,    display welcome menu
//          PARAMETERS, display parameters menu
//          INGAME,     redraw ingame element
//          ENDGAME,    display endgame menu
//------------------------------------------------------------------------------
void displayController(GameParameters* g,Event ev);
#endif
