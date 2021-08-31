/*
 * File:   touchScreen.c
 * Author: sebastie.metral
 *
 * Created on 30. août 2021, 12:42
 */
#include "touchScreenSM.h"
typedef enum state{WAITING,CALCULATEPOSITION} state;
state touchScreenState;

void touchScreenInit()
{
    touchScreenState=WAITING;
    touchScreenController();
}
//------------------------------------------------------------------------------
//Method that will change the state of the statemachine depending on an event
//------------------------------------------------------------------------------
void touchScreenSM(Event ev)
{
    switch(touchScreenState)
    {
        case WAITING:
            if(ev==evPress)
            {
                touchScreenState=CALCULATEPOSITION;
                touchScreenController();
            }
            break;
        case CALCULATEPOSITION:
            if(ev==evRelease)
            {
                touchScreenState=WAITING;
                touchScreenController();
            }
            if(ev==evTimerPos)
            {
                touchScreenController();
            }
            break;
        default:
            break;
    }
}
//------------------------------------------------------------------------------
//Method that will be call on a state change to do the action on entry
//------------------------------------------------------------------------------
void touchScreenController()
{
    switch(touchScreenState)
    {
        case WAITING:
            //1.Reset TimerPos
            //2.x-y for touch screen
            //3.Create TimerSleep
            break;
        case CALCULATEPOSITION:
            //1.Reset TIMER SLEEP
            //2.CalculatePosition
            //3.Create TimerPos
            break;
        default:
            break;
    }
}