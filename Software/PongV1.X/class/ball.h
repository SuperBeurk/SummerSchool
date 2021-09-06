#ifndef _BALL
#define _BALL
#define _BALL_RADIUS 4
#define _BALL_COLOR RED
#include "../libraries/lcd_highlevel.h"
typedef struct Ball
{
    uint16_t x;
    uint16_t y;
    uint16_t oldx;
    uint16_t oldy;
    int16_t dx;
    int16_t dy;
}Ball;
void Ball_init(struct Ball* b);
void Ball_Update(struct Ball* b);
void Ball_draw(struct Ball* b);
#endif
