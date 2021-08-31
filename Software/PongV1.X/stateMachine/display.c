/*
 * File:   display.c
 * Author: sebastie.metral
 *
 * Created on 30. août 2021, 12:40
 */
#include "display.h"
typedef enum state{WELCOME,PARAMETERS,INGAME} state;
enum state displayState;

void displayInit()
{
    displayState=WELCOME;
    displayController();    
}
void displaySM(Event ev)
{
   switch(displayState)
    {
        case WELCOME: 
            break;
        case PARAMETERS:
            break;
        case INGAME:
            break;
        default:
            break;
    } 
}
void displayController()
{
    switch(displayState)
    {
        case WELCOME:
            //Display Welcome Menu
            break;
        case PARAMETERS:
            //Display Parameters menu
            break;
        case INGAME:
            //Display ball
            //Display both paddle
            //Display score
            break;
        default:
            break;
    }
}
