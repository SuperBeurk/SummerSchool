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

//------------------------------------------------------------------------------
//Interruption function
//------------------------------------------------------------------------------
//INT1 interrupt on RB1
//TMR0 interrupt timer0
//------------------------------------------------------------------------------
void __interrupt() isr(void)
{
    if((INT1IF==1)&&(INT1IE==1))//Interrupt on RB1
    {
        if(INTEDG1==0)//Falling edge (detect press on LCD)
        {
            INTEDG1=1;//Change edge for waiting a raising edge
            INT1IF=0;//clear flag
            XF_pushEvent(evPress,true);

        }
        else if(INTEDG1==1)//raising edge (detect release on LCD)
        {
            INTEDG1=0;//change edge for falling edge
            INT1IF=0;//clear edge
            XF_pushEvent(evRelease,true);
        }        
    }
    if((TMR0IF==1)&&(TMR0IE==1))//Interrupt on timer 0
    {
        XF_decrementAndQueueTimers(); //Decrement XF timerlist queue
        TMR0H=0xFB;//reset timer for 10 ms
        TMR0L=0x1D;
        TMR0IF=0;//clear flag
    }
}

//------------------------------------------------------------------------------
//main function
//------------------------------------------------------------------------------
void main(void) 
{
    Factory_init();//Init all our stateMachine
    while(true)
    {
        Factory_exec();//Execute our programm         
    }
    return;
}
