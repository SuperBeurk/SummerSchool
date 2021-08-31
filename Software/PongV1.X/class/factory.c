#include <xc.h>
#include "factory.h"

//global variable
Paddle p1;
Paddle p2;
Ball b1;
Score s1;
GameParameters g1;

void Factory_init()
{
    OSCCON = 0b01110010; // for 64MHz cpu clock (default is 8MHz) 
    
    LCD_Init();
    LCD_Fill(BLUE);
    //LCD_DrawRect(10, 10, 230, 310, 0, BLACK);
    //Init pic and all SM
//    XF_init();
//    sleepInit();
//    Ball_init(&b1);
//    Paddle_init(&p1);
//    Paddle_init(&p2);
}
void Factory_exec()
{
    //read the next event
//    Event ev;
//    ev = XF_popEvent(false);
//    if (ev != NULLEVENT)
//    {
//        sleepSM(ev);
//        touchScreenSM(ev);
//    }
        
}