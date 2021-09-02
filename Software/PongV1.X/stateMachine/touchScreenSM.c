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

typedef enum state{WAITING,CALCULATEPOSITION} state;
extern const FONT_INFO arialNarrow_12ptFontInfo;
state touchScreenState;

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
            configTouch();
            //3.Create TimerSleep
            break;
        case CALCULATEPOSITION:
            //1.Reset TIMER SLEEP
            //------------------------------------------------------------------
            //--------------xMeasurement 
            configMeasure(false);
            while((ADCON0&0x02)!=0){};
            uint16_t valueX;
            valueX=(ADRESH<<8)+ADRESL;
            valueX=800-valueX;
            if(valueX>=150)
            {
                valueX=(valueX-150)/2;
            }else{valueX=0;} 
            //--------------yMeasurement  
            configMeasure(true);                             
            while((ADCON0&0x02)!=0){};            
            uint16_t valueY;
            valueY=(ADRESH<<8)+ADRESL;
            if(valueY>=125)
            {
                valueY=(valueY-125)/2;
            }else{valueY=0;}
            XF_scheduleTimer(1,evTimerPos,false);
            //------------------------------------------------------------------
            //Pin configuration for realease touch
            ADCON0=0b00101001;
            configTouch();
            INT1IF=0;
            INT1IE=1;
            
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
    TRISB2=0;//Y- GND
    LATB2=0;          
    TRISB1=1;//X+ input/interrupt/pullup
    RBPU=0;
    WPUB=0b00000010;
    INTEDG1=0;           
    TRISB3=1;//X- open           
    TRISB4=1;//Y+ open
    INT1IE=1;
}
void configMeasure(bool channel)
{
    if(channel==0)
    {
        INT1IE=0;           
        ANSB1=0;
        TRISB1=0;//X- GND
        LATB1=0;            
        TRISB3=0;//X+ VCC
        LATB3=1;            
        TRISB4=1;//Y- open              
        TRISB2=1;          
        ANSB2=1;            
        ADCON0=0b00100011;  
    }
    if(channel==1)
    {
        ANSB2=0;
        TRISB2=0;//Y- GND
        LATB2=0;            
        TRISB4=0;//Y+ VCC
        LATB4=1;            
        TRISB3=1;//X- open
        TRISB1=1;
        ANSB1=1;            
        ADCON0=0b00101011;  
    }
}