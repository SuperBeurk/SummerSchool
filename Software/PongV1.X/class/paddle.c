#include "paddle.h"

void Paddle_init(struct Paddle* p,uint16_t team)
{
    if(team)
    {
        p->x = 90;
        p->y = 20;
        p->w = 50;
        p->h = 20;
        p->color = BLUE; 
    }
    else
    {
        p->x = 90;
        p->y = 280;
        p->w = 50;
        p->h = 20;
        p->color = BLUE; 
    }
    
}
void Paddle_addX(struct Paddle* p,uint16_t value,uint16_t add)
{
    LCD_DrawRect(p->x,p->y,p->x+p->w,p->y+p->h,1,WHITE);
    if(add==1)
    {
        p->x=(p->x)+value;
        if((p->x+p->w)>239)
        {
            p->x=239-(p->w);
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
    //Draw new paddle
    LCD_DrawRect(p->x,p->y,p->x+p->w,p->y+p->h,1,p->color);
}