/*
 * File:   gameController.c
 * Author: sebastie.metral
 *
 * Created on 30. août 2021, 12:40
 */
#include "gameController.h"
typedef enum gameSM{NOGAME,PARAMETERS,LOCAL,ONLINE,ENDGAME} gameSM;
gameSM gameStateMachine;

//------------------------------------------------------------------------------
//Initialize gameControllerSM
//------------------------------------------------------------------------------
//State:    NOGAME, default state
//------------------------------------------------------------------------------
void gameControllerInit(GameParameters* g)
{
    gameStateMachine=NOGAME;
    gameControllerController(g,NULLEVENT);    //action to do
}

//------------------------------------------------------------------------------
//Statemachine of gamController
//------------------------------------------------------------------------------
//State:    NOGAME,
//          PARAMETERS,
//          LOCAL,
//          ONLINE,
//          ENDGAME
//------------------------------------------------------------------------------
void gameControllerSM(Event ev,GameParameters* g)
{
   switch(gameStateMachine)
    {
        case NOGAME:
            gameControllerController(g,NULLEVENT);//call action to do on this state
            if(ev==evParameters)//if we want to update parameters
            {
                gameStateMachine=PARAMETERS;//change state
            }
            if(ev==evOnePlayer)//if we want to play in local
            {
                gameStateMachine=LOCAL;//change state
                if(g->level==3)
                {
                    XF_scheduleTimer(1,evGameUpdate,true);//start game timer
                }
                else if(g->level==2)
                {
                    XF_scheduleTimer(2,evGameUpdate,true);//start game timer
                }
                else if(g->level==1)
                {
                    XF_scheduleTimer(3,evGameUpdate,true);//start game timer
                }
            }
            break;
            if(ev==evTwoPlayer)//if we want to play in online
            {
                gameStateMachine=ONLINE;//change state
                XF_scheduleTimer(5,evGameUpdate,false);//start game timer
            }
//------------------------------------------------------------------------------
        case PARAMETERS:
            gameControllerController(g,NULLEVENT);//action to do on this state
            if(ev==evLeaveParam)//if we want to leave parameters
            {
                gameStateMachine=NOGAME;//change state
            }
            break;
//------------------------------------------------------------------------------
        case LOCAL://1 player
            if(ev==evEndGame)//if game is finished
            {
                gameStateMachine=ENDGAME;//change state
            }
            else
            {
                gameControllerController(g,ev);//action to do on this state
            }
            break;
//------------------------------------------------------------------------------
        case ONLINE://2 player

            break;
//------------------------------------------------------------------------------
       case ENDGAME:
           gameControllerController(g,ev);//action to do on this state
           break;
        default:
            break;
    } 
}

//------------------------------------------------------------------------------
//Action to do on a state
//------------------------------------------------------------------------------
//State:    NOGAME, Check click in button
//          PARAMETERS, SlideBar for backlight, button for level
//          LOCAL,  Moove both paddle Moove ball
//          ONLINE,
//          ENDGAME Check click in button new game or sleep
//------------------------------------------------------------------------------
void gameControllerController(GameParameters* g,Event ev)
{            
    switch(gameStateMachine)
    {
        case NOGAME:
            //check if click is in a button
            if(LCD_InButton(&(g->btnParam),g->x,g->y))//Button param
            {
                XF_pushEvent(evParameters,false);
                GameParameters_resetPos(g);
            }
            if(LCD_InButton(&(g->btnOnePlayer),g->x,g->y))//Button 1 player
            {
                XF_pushEvent(evOnePlayer,false);
                GameParameters_resetPos(g);              
            }
            if(LCD_InButton(&(g->btnTwoPlayer),g->x,g->y))//Button 2 player
            {
                XF_pushEvent(evTwoPlayer,false);
                GameParameters_resetPos(g);
            }
            break;
//------------------------------------------------------------------------------
        case PARAMETERS:
            //check if click is in slider
            if(LCD_InSlider(&(g->sldBackLight),g->x,g->y))
            {
                backlightController(g);//Call method to update luminosity
                LCD_SliderUpdate(&(g->sldBackLight));
                GameParameters_resetPos(g);
            }
            if(LCD_InSlider(&(g->sldLevel),g->x,g->y))
            {
                levelController(g);//Call method to update level
                LCD_SliderUpdate(&(g->sldLevel));
                GameParameters_resetPos(g);
            }
            //check if click is in button leave parameters
            if(LCD_InButton(&(g->btnLeaveParam),g->x,g->y))
            {
                XF_pushEvent(evLeaveParam,false);
                GameParameters_resetPos(g);
            }
            break;
//------------------------------------------------------------------------------
        case LOCAL: 
            if (ev==evTimerPos)//if we got a click on the screen
            {
                //Moove player 1 paddle on tsc
                moovePaddle1(g);//Local paddle
                
            }
            else if(ev==evGameUpdate)//if game timer is done(50ms)
            {
                //Moove ball
                mooveBall(g);
                moovePaddle2(g);//IA Paddle  
                if(g->level==3)
                {
                    XF_scheduleTimer(1,evGameUpdate,true);//start game timer
                }
                else if(g->level==2)
                {
                    XF_scheduleTimer(2,evGameUpdate,true);//start game timer
                }
                else if(g->level==1)
                {
                    XF_scheduleTimer(3,evGameUpdate,true);//start game timer
                }
            }
//------------------------------------------------------------------------------
            break;
        case ONLINE:
            break;
//------------------------------------------------------------------------------
        case ENDGAME:
            //Check if click in button
            if(LCD_InButton(&(g->btnNewGame),g->x,g->y))//button leave game
            {
                //reset game parameters for new game
                GameParameters_init(g);
                XF_pushEvent(evNewGame,false);
                gameStateMachine=NOGAME;//change state for new game                      
            }
            break;
//------------------------------------------------------------------------------
        default:
            break;
    }
}
