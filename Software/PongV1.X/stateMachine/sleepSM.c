#include "sleepSM.h"
//all state for this stateMachine
typedef enum state1{WAKEUP,SLEEP} state1;
state1 sleepState;

//------------------------------------------------------------------------------
//Initialize sleepSM
//------------------------------------------------------------------------------
//State:    WAKEUP,default state
//------------------------------------------------------------------------------
void sleepInit(GameParameters* g)
{
    sleepState=WAKEUP;//default state
    //init all other SM
    displayInit(g);
    gameControllerInit(g);
    touchScreenInit();
    sleepController();    
}

//------------------------------------------------------------------------------
//Statemachine of sleep
//------------------------------------------------------------------------------
//State:    WAKEUP,
//          SLEEP,
//------------------------------------------------------------------------------
void sleepSM(Event ev)
{
    switch(sleepState)
    {
        case WAKEUP: 
            if(ev==evSleep)//No touch for 20s
            {
               sleepState=SLEEP;//change state
               sleepController();//action to do
            }
            break;
//------------------------------------------------------------------------------
        case SLEEP:
            break;
//------------------------------------------------------------------------------
        default:
            break;
    }
}

//------------------------------------------------------------------------------
//Action to do
//------------------------------------------------------------------------------
//State:    WAKEUP, pic awake
//          BACKLIGHTOFF, turn off luminosity after 10s of no touch
//          SLEEP,turn the pic in sleep mode after 20s of no touch
//------------------------------------------------------------------------------
void sleepController()
{
    switch(sleepState)
    {
        case WAKEUP:
            break;
//------------------------------------------------------------------------------
        case SLEEP:
            configPinSleep();
            Sleep();
            Reset();            
            break;
//------------------------------------------------------------------------------
        default:
            break;
    }
}

//------------------------------------------------------------------------------
//Config LCD pin for sleep mode
//------------------------------------------------------------------------------
void configPinSleep()
{
    TRISC=0b10000010;
    TRISA=0;            
    LATA=0xFF;
    LATC0=0;//turn off LCD
    CCPR2L=0;//turn off backlight
    LATC2=1;
    LATC3=1;
    LATC4=1;
    LATC5=1;
    configTouch();//call function that config some pin for touch
}