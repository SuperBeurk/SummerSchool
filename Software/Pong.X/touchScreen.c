/*
 * File:   touchScreen.c
 * Author: sebastie.metral
 *
 * Created on 30. août 2021, 12:42
 */
#include "xf.h"
#include "touchScreen.h"
enum state{WAITING,CALCULATEPOSITION};
enum state touchScreenState;

void touchScreenInit()
{
    touchScreenState=WAITING;
    touchScreenController();
}
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