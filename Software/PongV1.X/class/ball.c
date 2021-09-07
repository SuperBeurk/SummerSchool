#include "ball.h"

void Ball_init(struct Ball* b)
{
    b->x = 90;
    b->y = 150;
    b->oldx=20;
    b->oldy=20;
    b->dx = 0;
}
void Ball_Update(struct Ball* b)
{
    b->x=b->x+b->dx;
    b->y=b->y+b->dy;
}
void Ball_draw(struct Ball* b)
{       
    LCD_DrawRect(b->oldx-_BALL_RADIUS,b->oldy-_BALL_RADIUS,b->oldx+_BALL_RADIUS,b->oldy+_BALL_RADIUS,1,BLACK);  
    b->oldx=b->x;
    b->oldy=b->y;
    LCD_DrawRect(b->x-_BALL_RADIUS,b->y-_BALL_RADIUS,b->x+_BALL_RADIUS,b->y+_BALL_RADIUS,1,_BALL_COLOR);
}
