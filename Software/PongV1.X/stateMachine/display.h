#ifndef _DISPLAY
#define _DISPLAY
#include "../xf/xf.h"
#include "../libraries/lcd_highlevel.h"
void displayInit();
void displaySM(Event ev);
void displayController();
#endif
