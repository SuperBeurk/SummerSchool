#ifndef _SLEEPSM
#define _SLEEPSM
#include "../xf/xf.h"
#include "display.h"
#include "gameController.h"
#include "touchScreenSM.h"
#include "../class/gameParameters.h"
void sleepInit(GameParameters* g);
void sleepSM(Event ev);
void sleepController();
#endif
