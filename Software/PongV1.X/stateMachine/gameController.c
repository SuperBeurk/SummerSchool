#include "gameController.h"
//all state for this stateMachine
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
                XF_scheduleTimer(4-g->level,evGameUpdate,true);//start game timer depending on level
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
            if(ev==evLeave)//if we want to leave parameters
            {
                gameStateMachine=NOGAME;//change state
            }
            break;
//------------------------------------------------------------------------------
        case LOCAL://1 player
            gameControllerController(g,ev);//action to do on this state
            if(ev==evLeave)//if we want to leave parameters
            {
                gameStateMachine=NOGAME;//change state
            }
            else if(ev==evEndGame)//if game is finished
            {
                gameStateMachine=ENDGAME;//change state
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
            if(LCD_InButton(&(g->btnTurnOff),g->x,g->y))//Button turn Off
            {
                XF_pushEvent(evSleep,false);
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
            //check if click is in button leave parameters and return to menu
            if(LCD_InButton(&(g->btnLeave),g->x,g->y))
            {
                XF_pushEvent(evLeave,false);
                GameParameters_resetPos(g);
            }
            break;
//------------------------------------------------------------------------------
        case LOCAL: 
            if(LCD_InButton(&(g->btnLeave),g->x,g->y))//return to menu button
            {
                XF_pushEvent(evLeave,false);
                GameParameters_resetPos(g);
            }
            
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
                XF_scheduleTimer(4-g->level,evGameUpdate,true);//restart game timer depending on level
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
            if(LCD_InButton(&(g->btnTurnOff),g->x,g->y))//Button turn Off
            {
                XF_pushEvent(evSleep,false);
                GameParameters_resetPos(g);
            }
            break;
//------------------------------------------------------------------------------
        default:
            break;
    }
}
