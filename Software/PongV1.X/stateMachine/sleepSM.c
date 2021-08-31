/*
 * File:   sleep.c
 * Author: sebastie.metral
 *
 * Created on 30. août 2021, 12:40
 */
#include "sleepSM.h"
typedef enum state{WAKEUP,BACKLIGHTOFF,SLEEP} state;
enum state sleepState;

void sleepInit()
{
    sleepState=WAKEUP;
    sleepController();    
}
void sleepSM(Event ev)
{
   switch(sleepState)
    {
        case WAKEUP: 
            if(ev==evTimer30)
            {
               sleepState=BACKLIGHTOFF;
               sleepController(); 
            }
            break;
        case BACKLIGHTOFF:
            if(ev==evTimer30)
            {
               sleepState=SLEEP;
               sleepController(); 
            }
            if(ev==evPress)
            {
               sleepState=WAKEUP;
               sleepController(); 
            }
            break;
        case SLEEP:
            if(ev==evPress)
            {
               sleepState=WAKEUP;
               sleepController(); 
            }
            break;
        default:
            break;
    } 
}
void sleepController()
{
    switch(sleepState)
    {
        case WAKEUP:
            //1.WAKEUP PIC
            //2.Init all SM
            //3.Init Backlight
            break;
        case BACKLIGHTOFF:
            //1. Backlight OFF
            break;
        case SLEEP:
            //1.Mode Sleep
            //2.Reset X-Y for waiting touch
            break;
        default:
            break;
    }
}
