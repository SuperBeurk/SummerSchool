#include "paddle.h"

//------------------------------------------------------------------------------
//Method that will init the paddle struct
//------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------
//Method that will do a step on the paddle
//------------------------------------------------------------------------------
void Paddle_addX(struct Paddle* p,uint16_t value,uint16_t add)
{
    if(add==1)
    {
        p->x=(p->x)+value;
        if((p->x+_PADDLE_WIDTH)>239)//check if step is out of screen border right
        {
            p->x=239-(_PADDLE_WIDTH);
        }
    }
    else
    {
        if((p->x)<value+1)//check if step is out of screen border left
        {
            p->x=0;
        }
        else
        {
            p->x=(p->x)-value;
        }
        
    }
}

//------------------------------------------------------------------------------
//Method that will draw the new paddle
//------------------------------------------------------------------------------
void Paddle_draw(struct Paddle* p)
{
    //Clear old paddle
    LCD_DrawRect(p->oldx,p->oldy,p->oldx+_PADDLE_WIDTH,p->oldy+_PADDLE_HEIGHT,1,BLACK);
    //Save actual value as old ones
    p->oldx=p->x;
    p->oldy=p->y;
    //Draw new paddle
    LCD_DrawRect(p->x,p->y,p->x+_PADDLE_WIDTH,p->y+_PADDLE_HEIGHT,1,p->color);
}