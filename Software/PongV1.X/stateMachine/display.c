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
            if((ev==evOnePlayer)||(ev==evTwoPlayer))
            {
                displayState=INGAME;
                displayController();
            }
            if(ev==evParameters)
            {
                displayState=PARAMETERS;
                displayController();
            }
            break;
        case PARAMETERS:
            if(ev==evLeaveParameters)
            {
                displayState=WELCOME;
                displayController();
            }
            break;
        case INGAME:
            if(ev==evNewGame)
            {
                displayState=WELCOME;
                displayController();
            }
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
            LCD_Fill(WHITE);
            LCD_DrawText("WELCOME",&arialNarrow_12ptFontInfo,A_CENTER,50,50,BLACK,WHITE);
            break;
        case PARAMETERS:
            //Display Parameters menu
            LCD_Fill(WHITE);
            LCD_DrawText("PARAMETERS",&arialNarrow_12ptFontInfo,A_CENTER,50,50,BLACK,WHITE);
            break;
        case INGAME:
            //Display ball
            //Display both paddle
            //Display score
            LCD_Fill(WHITE);
            LCD_DrawText("INGAME",&arialNarrow_12ptFontInfo,A_CENTER,50,50,BLACK,WHITE);
            break;
        default:
            break;
    }
}
