#include "paddle.h"

void Paddle_init(struct Paddle* p,uint16_t team)
{
    p->oldx=0;
    p->oldy=0;
    if(team)
    {
        p->x = 90;
        p->y = 20;
        p->color = WHITE; 
    }
    else
    {
        p->x = 90;
        p->y = 280;
        p->color = WHITE; 
    }
    
}
void Paddle_addX(struct Paddle* p,uint16_t value,uint16_t add)
{
    if(add==1)
    {
        p->x=(p->x)+value;
        if((p->x+_PADDLE_WIDTH)>239)
        {
            p->x=239-(_PADDLE_WIDTH);
        }
    }
    else
    {
        if((p->x)<9)
        {
            p->x=0;
        }
        else
        {
            p->x=(p->x)-value;
        }
        
    }
}
void Paddle_draw(struct Paddle* p)
{
    LCD_DrawRect(p->oldx,p->oldy,p->oldx+_PADDLE_WIDTH,p->oldy+_PADDLE_HEIGHT,1,BLACK);
    p->oldx=p->x;
    p->oldy=p->y;
    //Draw new paddle
    LCD_DrawRect(p->x,p->y,p->x+_PADDLE_WIDTH,p->y+_PADDLE_HEIGHT,1,p->color);
}