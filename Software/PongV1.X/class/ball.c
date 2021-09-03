#include "ball.h"

void Ball_init(struct Ball* b)
{
    b->x = 90;
    b->y = 150;
    b->dx = 0;
    b->dy = 1;
}
void Ball_Update(struct Ball* b)
{
    LCD_DrawRect(b->x-_BALL_RADIUS,b->y-_BALL_RADIUS,b->x+_BALL_RADIUS,b->y+_BALL_RADIUS,1,WHITE);
    b->x=b->x+b->dx;
    b->y=b->y+b->dy;
    Ball_draw(b);
}
void Ball_draw(struct Ball* b)
{                                                                                                                                                                                                
    LCD_DrawRect(b->x-_BALL_RADIUS,b->y-_BALL_RADIUS,b->x+_BALL_RADIUS,b->y+_BALL_RADIUS,1,_BALL_COLOR);
}
