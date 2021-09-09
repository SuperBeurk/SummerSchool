#include "touchScreenSM.h"
#include <stdio.h>
#include <string.h>
#include <xc.h>
#include <stdlib.h>
//all state for this stateMachine
typedef enum state3{WAITING,CALCULATEPOSITION} state3;
extern const FONT_INFO arialNarrow_12ptFontInfo;
state3 touchScreenState;

extern XF theXF;   

//------------------------------------------------------------------------------
//Initialize touchScreenSM
//------------------------------------------------------------------------------
//State:    WAITING,default state
//------------------------------------------------------------------------------
void touchScreenInit()
{
    touchScreenState=WAITING;//default state
    configTouch();//config pin for touch
    XF_scheduleTimer(30000,evSleep,false);
}

//------------------------------------------------------------------------------
//Statemachine of touchScreen
//------------------------------------------------------------------------------
//State:    WAITING
//          CALCULATEPOS,
//------------------------------------------------------------------------------
void touchScreenSM(Event ev, GameParameters* g)
{
    switch(touchScreenState)
    {
        case WAITING:
            if(ev==evPress)//If we pressed the LCD screen
            {
                touchScreenState=CALCULATEPOSITION;//change state
                touchScreenController(g);//action to do
            }
            break;
//------------------------------------------------------------------------------
        case CALCULATEPOSITION:
            if(ev==evRelease)//If we release our pressing
            {
                touchScreenState=WAITING;//change state
                touchScreenController(g);//action to do
            }
            if(ev==evTimerPos)//We are still press so recalculate the position depending on this timer
            {
                touchScreenController(g);//action to do
            }
            break;
        default:
            break;
    }
}

//------------------------------------------------------------------------------
//Action to do on a state
//------------------------------------------------------------------------------
//State:    WAITING, Change LCD pin config for waiting touch interrupt
//          CALCULATEPOS, Change LCD pin onfig for measure  the position then 
//          change the config again to wait a release event, 
//          and recalcule the position if there is no release event every 90 ms(evTimerPos)
//------------------------------------------------------------------------------
void touchScreenController(GameParameters* g)
{
    switch(touchScreenState)
    {
        case WAITING:
            //1.Reset TimerPos
            INTEDG1=0;//Interrupt on falling edge
            XF_scheduleTimer(30000,evSleep,false);
            configTouch();//Pin configuration for press touch               
            //3.Create TimerSleep
            break;
//------------------------------------------------------------------
        case CALCULATEPOSITION:
            for (int i=0; i<MAXTIMER; i++)
            {
                if (theXF.timerList[i].ev == evSleep)
                {
                    XF_unscheduleTimer(i, false);
                }
            }
            //1.Reset TIMER SLEEP
            //------------------------------------------------------------------
            //--------------xMeasurement 
            INT1IE=0;//disable interrupt RB1  
            configMeasure(false);
            while((ADCON0&0x02)!=0){};
            uint16_t valueX;
            valueX=(ADRESH<<8)+ADRESL;
            if(valueX<=_TSC_OFFSET_X)
            {
                valueX=_TSC_OFFSET_X;
            }
            valueX=(valueX-_TSC_OFFSET_X)/_TSC_CONV_X;
            valueX=_TSC_MAX_X-valueX;
            //--------------yMeasurement  
            configMeasure(true);                             
            while((ADCON0&0x02)!=0){};            
            uint16_t valueY;
            valueY=(ADRESH<<8)+ADRESL;
            if(valueY<=_TSC_OFFSET_Y)
            {
                valueY=_TSC_OFFSET_Y;
            }
            valueY=(valueY-_TSC_OFFSET_Y)/_TSC_CONV_Y;
            XF_scheduleTimer(4,evTimerPos,false);//Create event for recalculate the pos
            //------------------------------------------------------------------
            ADCON0=0b00101000;//turn off AD
            configTouch();//Pin configuration for realease touch
                       
            if(PORTBbits.RB1 == 0)//Save value if screen still press
            {
                GameParameters_setX(g,valueX); 
                GameParameters_setY(g,valueY);
            }            
            //------------------------------------------------------------------
//------------------------------------------------------------------------------
            break;
        default:
            break;
    }
}

//------------------------------------------------------------------------------
//Configure the YU,YD,XR,XL pins for waiting interrupt
//------------------------------------------------------------------------------
void configTouch()
{
    ANSB1=0;
    ANSB2=0;
    _DIR_YU=0;//Y- GND
    _TSC_YU=0;          
    _DIR_XR=1;//X+ input/interrupt/pullup
    RBPU=0;
    WPUB=0b00000010;    
    _DIR_XL=0;
    _TSC_XL=1;//charger le condo
    NOP();
    _DIR_XL=1;//X- open           
    _DIR_YD=1;//Y+ open
    INT1IF=0;//clear int flag
    INT1IE=1;//enable interrupt RB1
}

//------------------------------------------------------------------------------
//Configure the YU,YD,XR,XL pins for measure the position
//------------------------------------------------------------------------------
void configMeasure(bool channel)
{
    if(channel==0)//y measure
    {         
        ANSB1=0;
        _DIR_XR=0;//X- GND
        _TSC_XR=0;            
        _DIR_XL=0;//X+ VCC
        _TSC_XL=1;            
        _DIR_YD=1;//Y- open              
        _DIR_YU=1;//y+ analog          
        ANSB2=1;            
        ADCON0=0b00100011;  
    }
    if(channel==1)//x measure
    {
        ANSB2=0;
        _DIR_YU=0;//Y- GND
        _TSC_YU=0;            
        _DIR_YD=0;//Y+ VCC
        _TSC_YD=1;            
        _DIR_XL=1;//X- open
        _DIR_XR=1;//x+ analog
        ANSB1=1;            
        ADCON0=0b00101011;  
    }
}