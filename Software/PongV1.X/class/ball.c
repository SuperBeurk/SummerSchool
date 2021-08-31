#include "ball.h"
void Ball_init(struct Ball* b)
{
    b->x = 0;
    b->y = 0;
    b->r = 0;
    b->color = 0;
}
void Ball_setRadius(struct Ball* b, uint16_t value)
{
    b->r = value;
}
void Ball_setPosX(struct Ball* b, uint16_t value)
{
    b->x = value;
}
void Ball_setPosY(struct Ball* b, uint16_t value)
{
    b->y = value;
}
void Ball_setColor(struct Ball* b, uint16_t value)
{
    b->color = value;
}
void Ball_draw(struct Ball* b)
{
    
}
