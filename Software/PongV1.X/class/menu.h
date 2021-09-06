#ifndef _WELCOMEMENU
#define _WELCOMEMENU
#include "../libraries/lcd_highlevel.h"
#include "../class/gameParameters.h"
//------------------------------------------------------------------------------
//Method that will display the welcome menu
//------------------------------------------------------------------------------
void Menu_welcomeDraw(GameParameters* g);

//------------------------------------------------------------------------------
//Method that will display the Parameters menu
//------------------------------------------------------------------------------
void Menu_parametersDraw(GameParameters* g);

//------------------------------------------------------------------------------
//Method that will display the inGame menu
//------------------------------------------------------------------------------
void Menu_inGameDraw(GameParameters* g);

//------------------------------------------------------------------------------
//Method that will display the endGame menu
//------------------------------------------------------------------------------
void Menu_endGame(GameParameters* g);
#endif
