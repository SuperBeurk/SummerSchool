#ifndef _BALL
#define _BALL
#include "../libraries/lcd_highlevel.h"
typedef struct Ball
{
    uint16_t x;
    uint16_t y;
    uint16_t r;
    uint16_t color;
}Ball;
void Ball_init(struct Ball* b);
void Ball_setPosX(struct Ball* b, uint16_t value);
void Ball_setPosY(struct Ball* b, uint16_t value);
void Ball_draw(struct Ball* b);
#endif
