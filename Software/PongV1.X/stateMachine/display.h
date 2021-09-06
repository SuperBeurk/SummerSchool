#ifndef _DISPLAY
#define _DISPLAY
#include "../xf/xf.h"
#include "../libraries/lcd_highlevel.h"
#include "../class/menu.h"
#include "../class/gameParameters.h"
void displayInit(GameParameters* g);
void displaySM(Event ev,GameParameters* g);
void displayController(GameParameters* g,Event ev);
#endif
