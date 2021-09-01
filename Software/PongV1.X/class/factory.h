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

void Factory_init();
void Factory_exec();