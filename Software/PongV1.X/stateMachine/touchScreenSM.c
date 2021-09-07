/*
 * File:   touchScreen.c
 * Author: sebastie.metral
 *
 * Created on 30. août 2021, 12:42
 */
#include "touchScreenSM.h"
#include <stdio.h>
#include <string.h>
#include <xc.h>
#include <stdlib.h>

typedef enum state3{WAITING,CALCULATEPOSITION} state3;
extern const FONT_INFO arialNarrow_12ptFontInfo;
state3 touchScreenState;

void touchScreenInit()
{
    touchScreenState=WAITING;
    configTouch();
}
//------------------------------------------------------------------------------
//Method that will change the state of the statemachine depending on an event
//------------------------------------------------------------------------------
void touchScreenSM(Event ev, GameParameters* g)
{
    switch(touchScreenState)
    {
        case WAITING:
            if(ev==evPress)
            {
                touchScreenState=CALCULATEPOSITION;
                touchScreenController(g);
            }
            break;
        case CALCULATEPOSITION:
            if(ev==evRelease)
            {
                touchScreenState=WAITING;
                touchScreenController(g);
            }
            if(ev==evTimerPos)
            {
                touchScreenController(g);
            }
            break;
        default:
            break;
    }
}
//------------------------------------------------------------------------------
//Method that will be call on a state change to do the action on entry
//------------------------------------------------------------------------------
void touchScreenController(GameParameters* g)
{
    char s[20];

    switch(touchScreenState)
    {
        case WAITING:
            //1.Reset TimerPos
            //Pin configuration for press touch
            INTEDG1=0; 
            configTouch();
               
            //3.Create TimerSleep
            break;
        case CALCULATEPOSITION:
            //1.Reset TIMER SLEEP
            //------------------------------------------------------------------
            //--------------xMeasurement 
            INT1IE=0;  
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
            XF_scheduleTimer(9,evTimerPos,false);
            //------------------------------------------------------------------
            //Pin configuration for realease touch
            ADCON0=0b00101000;
            configTouch();
            
            //Save value if screen still press
            if(PORTBbits.RB1 == 0)
            {
                sprintf(s,"X: %d",valueX);
                LCD_DrawText(s,&arialNarrow_12ptFontInfo,A_RIGHT,200,200,BLACK,WHITE);
                GameParameters_setX(g,valueX);
                sprintf(s,"Y: %d",valueY);
                LCD_DrawText(s,&arialNarrow_12ptFontInfo,A_RIGHT,200,250,BLACK,WHITE);  
                GameParameters_setY(g,valueY);
            }
            
            //------------------------------------------------------------------
            //3.Create TimerPos

            break;
        default:
            break;
    }
}
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
    INT1IF = 0;
    INT1IE=1;
}
void configMeasure(bool channel)
{
    if(channel==0)
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
    if(channel==1)
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