/*
 * File:   display.c
 * Author: sebastie.metral
 *
 * Created on 30. août 2021, 12:40
 */
#include "display.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern const FONT_INFO arialNarrow_12ptFontInfo;

typedef enum state{WELCOME,PARAMETERS,INGAME,ENDGAME} state;
enum state displayState;

void displayInit(GameParameters* g)
{
    displayState=WELCOME;
    displayController(g,NULLEVENT);    
}
void displaySM(Event ev, GameParameters* g)
{
   switch(displayState)
    {
        case WELCOME: 
            if((ev==evOnePlayer)||(ev==evTwoPlayer))
            {
                displayState=INGAME;
                Menu_inGameDraw(g);
                displayController(g,ev);
            }
            if(ev==evParameters)
            {
                displayState=PARAMETERS;
                displayController(g,ev);
            }
            break;
        case PARAMETERS:
            if(ev==evLeaveParam)
            {
                displayState=WELCOME;
                displayController(g,ev);
            }
            break;
        case INGAME:
            if(ev==evEndGame)
            {
                displayState=ENDGAME;                           
                displayController(g,ev);
            }
            else
            {
                displayController(g,ev);
            }
            break;
       case ENDGAME:
           if(ev==evNewGame)
           {
               displayState=WELCOME;
               displayController(g,ev);
           }
            break;
        default:
            break;
    } 
}
void displayController(GameParameters* g,Event ev)
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
            if(ev==evRedrawPaddle1)
            {
                Paddle_draw(&g->p1);                
            }
            if(ev==evRedrawPaddle2)
            {
                Paddle_draw(&g->p2);
            }
            if(ev==evRedrawBall)
            {
                Ball_draw(&g->b);
            }
            if(ev==evRedrawScore)
            {
                Score_draw(&g->s1);
            }
            break;
        case ENDGAME:
            Menu_endGame(g);
            break;
            
        default:
            break;
    }
}
