
#ifndef _GAMEPARAMETERS
#define _GAMEPARAMETERS
#include "../libraries/lcd_highlevel.h"
#include "ball.h"
#include "paddle.h"
#include "score.h"
#include <xc.h>
typedef struct GameParameters
{
    uint16_t backlight;
    uint16_t x;//save x touchscreen position
    uint16_t y;//save y touchescreen position
    uint16_t level;
    btn_t btnParam;
    btn_t btnOnePlayer;
    btn_t btnTwoPlayer;
    btn_t btnLeave;
    btn_t btnNewGame;
    btn_t btnTurnOff;
    sld_t sldBackLight;
    sld_t sldLevel;
    Ball b;
    Paddle p1;
    Paddle p2;
    Score s1;
}GameParameters;

//------------------------------------------------------------------------------
//Method that will initialize the struct
//------------------------------------------------------------------------------
void GameParameters_init(struct GameParameters* s);

//------------------------------------------------------------------------------
//Method that will set the luminosity from 0 to 100%
//------------------------------------------------------------------------------
void GameParameters_setBackLight(struct GameParameters* s, uint16_t value);

//------------------------------------------------------------------------------
//Method that will set the level
//------------------------------------------------------------------------------
void GameParameters_setLevel(struct GameParameters* s, uint16_t value);

//------------------------------------------------------------------------------
//Method that will set X_tsc position value
//------------------------------------------------------------------------------
void GameParameters_setX(struct GameParameters* s, uint16_t value);

//------------------------------------------------------------------------------
//Method that will set Y_tsc position value
//------------------------------------------------------------------------------
void GameParameters_setY(struct GameParameters* s, uint16_t value);

//------------------------------------------------------------------------------
//Method that will reset tsc position value
//------------------------------------------------------------------------------
void GameParameters_resetPos(struct GameParameters* s);
#endif
