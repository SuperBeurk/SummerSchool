#ifndef _FACTORY
#define _FACTORY
#include "ball.h"
#include "gameParameters.h"
#include "score.h"
#include "../stateMachine/sleepSM.h"
#include "../stateMachine/touchScreenSM.h"
#include "../stateMachine/display.h"
#include "../stateMachine/gameController.h"
#include "paddle.h"
#include "../xf/xf.h"
#include "../libraries/lcd_highlevel.h"
#include "../libraries/arialNarrow_12ptBitmaps.c"
#include <pic18.h>

//------------------------------------------------------------------------------
//Method that will initialize our program
//------------------------------------------------------------------------------
void Factory_init();

//------------------------------------------------------------------------------
//Method that will execute our program
//------------------------------------------------------------------------------
void Factory_exec();
#endif