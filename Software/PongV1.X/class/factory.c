#include <xc.h>
#include "factory.h"

#define _XTAL_FREQ   64000000L
extern const FONT_INFO arialNarrow_12ptFontInfo;

//global variable
Paddle p1;
Paddle p2;
Ball b1;
Score s1;
GameParameters g1;

void Factory_init()
{
    
    PLLEN = 1;           // activate PLL x4
    OSCCON = 0b01110000; // for 64MHz cpu clock (default is 8MHz)
    __delay_ms(100);     // Caution -> the PLL needs up to 2 [ms] to start !  
    //LCD
    LCD_Init();
    LCD_Fill(BLUE);
    LCD_DrawText("MenuStart",&arialNarrow_12ptFontInfo,A_CENTER,50,50,BLACK,WHITE);
    

    
    //Interrupt
    GIE=1;
    INT1IE=0;
    
    TRISC1=0;
    T0CON=0b10000110;
    TMR0H=0xE7;
    TMR0L=0x95;
    TMR0IE=1;
    //AD
    ADCON2=0b00100110;
    
    //Init pic and all SM
    XF_init();
    sleepInit();
    Ball_init(&b1);
    Paddle_init(&p1);
    Paddle_init(&p2);
}
void Factory_exec()
{
    //read the next event
    Event ev;
    ev = XF_popEvent(false);
    if (ev != NULLEVENT)
    {
        sleepSM(ev);
        touchScreenSM(ev);
        displaySM(ev);
        gameControllerSM(ev);
    }
        
}