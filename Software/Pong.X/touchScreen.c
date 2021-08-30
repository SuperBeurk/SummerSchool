/*
 * File:   touchScreen.c
 * Author: sebastie.metral
 *
 * Created on 30. août 2021, 12:42
 */
#include "touchScreen.h"
extern enum myEvents{nullEvent,evPress,evRelease,evTimer30,evTimer60};
enum state{WAITING,CALCULATEPOSITION};
enum state touchScreenState;

void touchScreenInit()
{
    touchScreenState=WAITING;
    touchScreenController();
}
void touchScreenSM(Event ev)
{
    
}
void touchScreenController()
{
    switch(touchScreenState)
    {
        case WAITING:
            break;
        case CALCULATEPOSITION:
            break;
        default:
            break;
    }
}