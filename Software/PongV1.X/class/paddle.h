#ifndef _PADDLE
#define _PADDLE
#define _PADDLE_WIDTH 50
#define _PADDLE_HEIGHT 20
#include "../libraries/lcd_highlevel.h"
typedef struct Paddle
{
    uint16_t x;
    uint16_t y;
    uint16_t color;
}Paddle;
void Paddle_init(struct Paddle* p,uint16_t team);
void Paddle_addX(struct Paddle* p,uint16_t value,uint16_t add);
void Paddle_draw(struct Paddle* p);
#endif
