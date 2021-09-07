
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
    uint16_t player;
    uint16_t x;
    uint16_t y;
    uint16_t level;
    btn_t btnParam;
    btn_t btnOnePlayer;
    btn_t btnTwoPlayer;
    btn_t btnLeaveParam;
    btn_t btnNewGame;
    sld_t sldBackLight;
    sld_t sldLevel;
    Ball b;
    Paddle p1;
    Paddle p2;
    Score s1;
}GameParameters;
void GameParameters_init(struct GameParameters* s);
void GameParameters_setBackLight(struct GameParameters* s, uint16_t value);
void GameParameters_setLevel(struct GameParameters* s, uint16_t value);
void GameParameters_setPlayer(struct GameParameters* s, uint16_t value);
void GameParameters_setX(struct GameParameters* s, uint16_t value);
void GameParameters_setY(struct GameParameters* s, uint16_t value);
void GameParameters_resetPos(struct GameParameters* s);
#endif
