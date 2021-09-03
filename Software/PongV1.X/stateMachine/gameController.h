#ifndef _GAMECONTROLLER
#define _GAMECONTROLLER
#include "../xf/xf.h"
#include "../class/gameParameters.h"
void gameControllerInit(GameParameters* g);
void gameControllerSM(Event ev,GameParameters* g);
void gameControllerController(GameParameters* g);
void moovePaddle(GameParameters* g);
void mooveBall(GameParameters* g);
void backlightController(GameParameters* g);
void checkCollision(GameParameters* g);
#endif
