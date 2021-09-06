#ifndef _PADDLE
#define _PADDLE
#define _PADDLE_WIDTH 50
#define _PADDLE_HEIGHT 10
#include "../libraries/lcd_highlevel.h"
typedef struct Paddle
{
    uint16_t x;
    uint16_t y;
    uint16_t oldx;
    uint16_t oldy;
    uint16_t color;
}Paddle;

//------------------------------------------------------------------------------
//Method that will init the paddle struct
//------------------------------------------------------------------------------
void Paddle_init(struct Paddle* p,uint16_t team);

//------------------------------------------------------------------------------
//Method that will do a step of a value of the paddle
//------------------------------------------------------------------------------
void Paddle_addX(struct Paddle* p,uint16_t value,uint16_t add);

//------------------------------------------------------------------------------
//Method that will draw the new paddle
//------------------------------------------------------------------------------
void Paddle_draw(struct Paddle* p);
#endif
