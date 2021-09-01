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
    char s[20];

    switch(touchScreenState)
    {
        case WAITING:
            //1.Reset TimerPos
            //2.x-y for waiting touch
            ANSB1=0;
            ANSB2=0;
            TRISB2=0;//Y- GND
            LATB2=0;          
            TRISB1=1;//X+ input/interrupt/pullup
            INT1IE=1;
            RBPU=0;
            WPUB=0b00000010;
            INTEDG1=0;           
            TRISB3=1;//X- open           
            TRISB4=1;//Y+ open
            //3.Create TimerSleep
            break;
        case CALCULATEPOSITION:
            //1.Reset TIMER SLEEP
            //------------------------------------------------------------------
            //2.CalculatePosition
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
            while((ADCON0&0x02)!=0){};
            uint16_t valueX;
            valueX=(ADRESH<<2)+ADRESL;
            
            //--------------yMeasurement  
            ANSB2=0;
            TRISB2=0;//Y- GND
            LATB2=0;            
            TRISB4=0;//Y+ VCC
            LATB4=1;            
            TRISB3=1;//X- open
            TRISB1=1;
            ANSB1=1;            
            ADCON0=0b00101011;                   
            while((ADCON0&0x02)!=0){};            
            uint16_t valueY;
            valueY=(ADRESH<<2)+ADRESL;
            
            
            XF_scheduleTimer(1,evTimerPos,false);
            
            ADCON0=0b00101001;
            //2.x-y for waiting touch
            ANSB1=0;
            ANSB2=0;
            TRISB2=0;//Y- GND
            LATB2=0;          
            TRISB1=1;//X+ input/interrupt/pullup
            INTEDG1=1;
            RBPU=0;
            WPUB=0b00000010;        
            TRISB3=1;//X- open           
            TRISB4=1;//Y+ open
            INT1IF=0;
            INT1IE=1;
            if(PORTBbits.RB1 == 0)
            {
                sprintf(s,"X: %d",valueX);
                LCD_DrawText(s,&arialNarrow_12ptFontInfo,A_CENTER,100,100,BLACK,WHITE);
                sprintf(s,"Y: %d",valueY);
                LCD_DrawText(s,&arialNarrow_12ptFontInfo,A_CENTER,100,200,BLACK,WHITE);               
            }
            //------------------------------------------------------------------
            //3.Create TimerPos

            break;
        default:
            break;
    }
}