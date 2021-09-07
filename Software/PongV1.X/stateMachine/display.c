#include "display.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern const FONT_INFO arialNarrow_12ptFontInfo;
//all state for this stateMachine
typedef enum state4{WELCOME,PARAMETERS,INGAME,ENDGAME} state4;
state4 displayState;

//------------------------------------------------------------------------------
//Initialize displaySM
//------------------------------------------------------------------------------
//State:    WELCOME,default state
//------------------------------------------------------------------------------
void displayInit(GameParameters* g)
{

    displayState=WELCOME;    //Default state
    displayController(g,NULLEVENT);    //action to do
}

//------------------------------------------------------------------------------
//Statemachine of displaySM
//------------------------------------------------------------------------------
//State:    WELCOME
//          PARAMETERS
//          INGAME
//          ENDGAME
//------------------------------------------------------------------------------
void displaySM(Event ev, GameParameters* g)
{
   switch(displayState)
    {
        case WELCOME: 
            if((ev==evOnePlayer)||(ev==evTwoPlayer))//if we want to play in 1 or 2 player mode
            {
                displayState=INGAME;//change state
                Menu_inGameDraw(g);//display ingame menu
                displayController(g,ev);//action to do
            }
            if(ev==evParameters)//if we want to update parameters
            {
                displayState=PARAMETERS;//change state
                displayController(g,ev);//action to do
            }
            break;
//------------------------------------------------------------------------------
        case PARAMETERS:
            if(ev==evLeaveParam)//if we want to leave parameters
            {
                displayState=WELCOME;//change state
                displayController(g,ev);//action to do
            }
            break;
//------------------------------------------------------------------------------
        case INGAME:
            if(ev==evEndGame)//if we loose our game
            {
                displayState=ENDGAME;//change state                     
                displayController(g,ev);//action to do
            }
            else//if we are still in game
            {
                displayController(g,ev);//redraw elemtn that need to be redraw
            }
            break;
//------------------------------------------------------------------------------
       case ENDGAME:
           if(ev==evNewGame)//if we want to replay a game
           {
               displayState=WELCOME;//change state
               displayController(g,ev);//action to do
           }
            break;
//------------------------------------------------------------------------------
        default:
            break;
    } 
}

//------------------------------------------------------------------------------
//Action to do on a state
//------------------------------------------------------------------------------
//State:    WELCOME,    display welcome menu
//          PARAMETERS, display parameters menu
//          INGAME,     redraw ingame element
//          ENDGAME,    display endgame menu
//------------------------------------------------------------------------------
void displayController(GameParameters* g,Event ev)
{
    switch(displayState)
    {
        case WELCOME:
            //Display Welcome Menu
            Menu_welcomeDraw(g);
            break;
//------------------------------------------------------------------------------
        case PARAMETERS:
            //Display Parameters menu
            Menu_parametersDraw(g);
            break;
//------------------------------------------------------------------------------
        case INGAME:
            //Update draw element depending on event
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
                LCD_DrawRect(0,160,239,160,1,WHITE);//Midlle line
            }
            break;
//------------------------------------------------------------------------------
        case ENDGAME:
            Menu_endGame(g);//Display engame menu
            break;
//------------------------------------------------------------------------------            
        default:
            break;
    }
}
