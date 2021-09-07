#ifndef _BALL
#define _BALL
#define _BALL_RADIUS 8
#define _BALL_COLOR RED
#include "../libraries/lcd_highlevel.h"
typedef struct Ball
{
    uint16_t x;
    uint16_t y;
    uint16_t oldx;
    uint16_t oldy;
    int16_t dx;//mooving Y vector
    int16_t dy;//mooving X vector
}Ball;

//------------------------------------------------------------------------------
//Method that will initialize the Ball struct
//------------------------------------------------------------------------------
void Ball_init(struct Ball* b);

//------------------------------------------------------------------------------
//Method that will moove our ball (uppdate) with the mooving vector
//------------------------------------------------------------------------------
void Ball_Update(struct Ball* b);

//------------------------------------------------------------------------------
//Method that will draw our ball
//------------------------------------------------------------------------------
void Ball_draw(struct Ball* b);
#endif
