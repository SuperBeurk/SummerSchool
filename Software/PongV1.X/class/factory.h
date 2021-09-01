#include "ball.h"
#include "gameParameters.h"
#include "score.h"
#include "../stateMachine/sleepSM.h"
#include "../stateMachine/touchScreenSM.h"
#include "paddle.h"
#include "../xf/xf.h"
#include "../libraries/lcd_highlevel.h"

void Factory_init();
void Factory_exec();