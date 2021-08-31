#include "paddle.h"
void Paddle_init(struct Paddle* p)
{
    p->x = 0;
    p->y = 0;
    p->w = 0;
    p->h = 0;
    p->color = 0;
}
void Paddle_setWidth(struct Paddle* p, uint16_t value)
{
    p->w = value;
}
void Paddle_setHeight(struct Paddle* p, uint16_t value)
{
    p->h = value;
}
void Paddle_setPosX(struct Paddle* p, uint16_t value)
{
    p->x = value;
}
void Paddle_setPosY(struct Paddle* p, uint16_t value)
{
    p->y = value;
}
void Paddle_setColor(struct Paddle* p, uint16_t value)
{
    p->color = value;
}
void Paddle_draw(struct Paddle* p)
{
    
}