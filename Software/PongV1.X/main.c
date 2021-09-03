/*
 * File:   main.c
 * Author: sebastie.metral
 *
 * Created on 27. août 2021, 10:51
 */
#include <xc.h>
#include "configuration_bits.c"
#include "xf/xf.h"
#include "stateMachine/sleepSM.h"
#include "stateMachine/touchScreenSM.h"
#include "class/factory.h"
#include <pic18.h>
#include <stdio.h>
#include <string.h>

extern const FONT_INFO arialNarrow_12ptFontInfo;

void __interrupt() isr(void)
{
    if((INT1IF==1)&&(INT1IE==1))
    {
        if(INTEDG1==0)
        {
            INTEDG1=1;
            INT1IF=0;
            XF_pushEvent(evPress,true);

        }
        else if(INTEDG1==1)
        {
            INTEDG1=0;
            INT1IF=0;
            XF_pushEvent(evRelease,true);

        }
        
        
    }
    if((TMR0IF==1)&&(TMR0IE==1))
    {
        XF_decrementAndQueueTimers(); 
        XF_scheduleTimer(5,evGameUpdate,true);
        TMR0H=0xFB;
        TMR0L=0x1D;
        TMR0IF=0;              
    }
}
void main(void) 
{
    Factory_init();
    while(true)
    {
        Factory_exec();
          
    }
    return;
}
