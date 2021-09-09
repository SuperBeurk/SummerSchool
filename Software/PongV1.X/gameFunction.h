#ifndef _GAMEFUNCTION
#define _GAMEFUNCTION
#include "class/gameParameters.h"
#include "xf/xf.h"
//------------------------------------------------------------------------------
//Method that will moove the local paddle on a click on the screen depending where we clicked
//------------------------------------------------------------------------------
void moovePaddle1(GameParameters* g);

//------------------------------------------------------------------------------
//Method that will moove the IA paddle
//------------------------------------------------------------------------------
void moovePaddle2(GameParameters* g);

//------------------------------------------------------------------------------
//Method that will moove the ball
//------------------------------------------------------------------------------
void mooveBall(GameParameters* g);

//------------------------------------------------------------------------------
//Method that will desactivate the sleepEventTimer
//------------------------------------------------------------------------------
void desactivateTimerSleep();

//------------------------------------------------------------------------------
//Method that will update the luminosity
//------------------------------------------------------------------------------
void backlightController(GameParameters* g);

//------------------------------------------------------------------------------
//Method that will update the level
//------------------------------------------------------------------------------
void levelController(GameParameters* g);

//------------------------------------------------------------------------------
//Method that will check the game collision
//------------------------------------------------------------------------------
void checkCollision(GameParameters* g);
#endif