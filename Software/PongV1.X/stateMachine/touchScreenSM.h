#ifndef _TOUCHSCREENSM
#define _TOUCHSCREENSM
#include "../xf/xf.h"
#include "../libraries/lcd_highlevel.h"
#include "../class/gameParameters.h"
#include <pic18.h>
void touchScreenInit();
void touchScreenSM(Event ev,GameParameters* g);
void touchScreenController(GameParameters* g);
void configTouch();
void configMeasure(bool channel);
#endif