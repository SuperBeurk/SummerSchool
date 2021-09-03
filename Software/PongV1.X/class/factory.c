#include <xc.h>
#include "factory.h"

#define _XTAL_FREQ   64000000L
#define _DIR_BACKLIGHT TRISC1
extern const FONT_INFO arialNarrow_12ptFontInfo;

//global variable
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
    TRISC0=0;
    LATC0=1;
    

    T0CON=0b10000110;
    TMR0H=0xFB;
    TMR0L=0x1D;
    TMR0IE=1;
    
    //PWM BACKLIGHT
    _DIR_BACKLIGHT=0;
    PR2=255;
    CCP2CONbits.CCP2M = 0xC;
    CCPR2L = 255;         
    CCP2CONbits.DC2B = 0; 
    TMR2IF=0;
    T2CONbits.T2CKPS0 = 1;  // 4. Set TMR2 prescale and enable Timer2
    T2CONbits.T2CKPS1 = 0;
    T2CONbits.TMR2ON = 1;
    //AD
    ADCON2=0b10100110;
    
    //Init pic and all SM
    XF_init();
    GameParameters_init(&g1);
    sleepInit(&g1);

}
void Factory_exec()
{
    //read the next event
    Event ev;
    ev = XF_popEvent(false);
    if (ev != NULLEVENT)
    {
        sleepSM(ev);
        touchScreenSM(ev,&g1);
        displaySM(ev,&g1);
        gameControllerSM(ev,&g1);
    }
        
}