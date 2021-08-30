/*
 * File:   sleep.c
 * Author: sebastie.metral
 *
 * Created on 30. août 2021, 12:40
 */
#include "sleep.h"
extern enum myEvents{nullEvent,evPress,evRelease,evTimer30,evTimer60};
enum state{WAKEUP,BACKLIGHTOFF,SLEEP};
enum state sleepState;

void sleepInit()
{
    sleepState=WAKEUP;
    sleepController();    
}
void sleepSM(Event ev)
{
    
}
void sleepController()
{
    switch(sleepState)
    {
        case WAKEUP:
            break;
        case BACKLIGHTOFF:
            break;
        case SLEEP:
            break;
        default:
            break;
    }
}
