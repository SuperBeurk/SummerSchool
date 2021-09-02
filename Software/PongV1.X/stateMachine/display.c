/*
 * File:   display.c
 * Author: sebastie.metral
 *
 * Created on 30. août 2021, 12:40
 */
#include "display.h"
extern const FONT_INFO arialNarrow_12ptFontInfo;

typedef enum state{WELCOME,PARAMETERS,INGAME} state;
enum state displayState;

void displayInit(GameParameters* g)
{
    displayState=WELCOME;
    displayController(g);    
}
void displaySM(Event ev, GameParameters* g)
{
   switch(displayState)
    {
        case WELCOME: 
            if((ev==evOnePlayer)||(ev==evTwoPlayer))
            {
                displayState=INGAME;
                displayController(g);
            }
            if(ev==evParameters)
            {
                displayState=PARAMETERS;
                displayController(g);
            }
            break;
        case PARAMETERS:
            if(ev==evLeaveParam)
            {
                displayState=WELCOME;
                displayController(g);
            }
            break;
        case INGAME:
            if(ev==evNewGame)
            {
                displayState=WELCOME;
                displayController(g);
            }
            break;
        default:
            break;
    } 
}
void displayController(GameParameters* g)
{
    switch(displayState)
    {
        case WELCOME:
            //Display Welcome Menu
            Menu_welcomeDraw(g);
            break;
        case PARAMETERS:
            //Display Parameters menu
            Menu_parametersDraw(g);
            break;
        case INGAME:
            //Display ball
            //Display both paddle
            //Display score
            Menu_inGameDraw(g);
            break;
        default:
            break;
    }
}
