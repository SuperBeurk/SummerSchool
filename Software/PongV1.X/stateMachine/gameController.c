/*
 * File:   gameController.c
 * Author: sebastie.metral
 *
 * Created on 30. août 2021, 12:40
 */
#include "gameController.h"
typedef enum gameSM{NOGAME,PARAMETERS,LOCAL,ONLINE,ENDGAME} gameSM;
gameSM gameStateMachine;
extern const FONT_INFO arialNarrow_12ptFontInfo;


void gameControllerInit(GameParameters* g)
{
    gameStateMachine=NOGAME;
    gameControllerController(g,NULLEVENT);    
}

//------------------------------------------------------------------------------
//Statemachine of gamcontroller
//------------------------------------------------------------------------------
void gameControllerSM(Event ev,GameParameters* g)
{
   switch(gameStateMachine)
    {
       //condition to change state
        case NOGAME:
            gameControllerController(g,NULLEVENT);//call action to do
            if(ev==evParameters)
            {
                gameStateMachine=PARAMETERS;//change state
            }
            if(ev==evOnePlayer)
            {
                gameStateMachine=LOCAL;
                XF_scheduleTimer(5,evGameUpdate,true);
            }
            break;
            if(ev==evTwoPlayer)
            {
                gameStateMachine=ONLINE;
                XF_scheduleTimer(5,evGameUpdate,false);
            }
        case PARAMETERS:
            gameControllerController(g,NULLEVENT);
            if(ev==evLeaveParam)
            {
                gameStateMachine=NOGAME;
            }
            break;
        case LOCAL://1 player
            gameControllerController(g,ev);
            break;
        case ONLINE://2 player

            break;
       case ENDGAME:
           gameControllerController(g,ev);
           break;
        default:
            break;
    } 
}

//------------------------------------------------------------------------------
//Action to do on a state
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
        case PARAMETERS:
            //check if click is in slider
            if(LCD_InSlider(&(g->sldParam),g->x,g->y))
            {
                backlightController(g);//Call method to update luminosity
                LCD_SliderUpdate(&(g->sldParam));
                GameParameters_resetPos(g);
            }
            //check if click is in button leave parameters
            if(LCD_InButton(&(g->btnLeaveParam),g->x,g->y))
            {
                XF_pushEvent(evLeaveParam,false);
                GameParameters_resetPos(g);
            }
            break;
        case LOCAL: 
            if (ev==evTimerPos)
            {
                //Moove player 1 paddle on tsc
                moovePaddle(g);
                
            }
            else if(ev==evGameUpdate)//Every 50 ms
            {
                //Moove ball
                mooveBall(g);
                
                //Moove IA Paddle
                if(g->b.x+_PADDLE_WIDTH>=239)
                {
                    g->p2.x=239-_PADDLE_WIDTH;
                }
                else
                {
                    g->p2.x=g->b.x;
                }
                XF_pushEvent(evRedrawPaddle2,false);  
                XF_scheduleTimer(5,evGameUpdate,true);
            }
            break;
        case ONLINE:
            break;
        case ENDGAME:
            if(LCD_InButton(&(g->btnNewGame),g->x,g->y))
            {
                //reset game parameters for new game
                GameParameters_init(g);
                XF_pushEvent(evNewGame,false);
                gameStateMachine=NOGAME;                       
            }
            break;
        default:
            break;
    }
}
void moovePaddle(GameParameters* g)
{
    //Moove left
    if(LCD_InButton(&(g->btnLeft),g->x,g->y))
    {
        GameParameters_resetPos(g);
        Paddle_addX(&g->p1,20,0);
    }
    //Moove right
    if(LCD_InButton(&(g->btnRight),g->x,g->y))
    {
        GameParameters_resetPos(g);
        Paddle_addX(&g->p1,20,1);
    }
    XF_pushEvent(evRedrawPaddle1,false);
}
void mooveBall(GameParameters* g)
{
    checkCollision(g);    
    Ball_Update(&g->b); 
    XF_pushEvent(evRedrawBall,false);
}
void checkCollision(GameParameters* g)
{
    char s[20];
    //------------------------collision with wall---------------------------
    if(g->b.x+g->b.dx+_BALL_RADIUS>=239)
    {
        g->b.dx=-g->b.dx;
    }
    if(g->b.x+g->b.dx-_BALL_RADIUS<=3)
    {
        g->b.dx=-g->b.dx;
    }
    //------------------------collision with paddle 1---------------------------
    if(g->b.y+_BALL_RADIUS>=g->p1.y-1)
    {
        if(g->b.x+_BALL_RADIUS>g->p1.x)
        {
            if(g->b.x-_BALL_RADIUS<g->p1.x+_PADDLE_WIDTH)
            {
                if(g->b.x-g->p1.x<10)
                {
                    //big left angle
                    g->b.dy=-g->b.dy;
                    g->b.dx-=2;
                }
                else if(g->b.x-g->p1.x<20)
                {
                    //small left angle
                    g->b.dy=-g->b.dy;
                    g->b.dx-=1;
                }
                else if(g->b.x-g->p1.x<30)
                {
                    //center
                    g->b.dx=g->b.dx;
                    g->b.dy=-g->b.dy;
                }
                else if(g->b.x-g->p1.x<40)
                {
                    //small right angle
                    g->b.dy=-g->b.dy;
                    g->b.dx+=1;
                }
                else
                {
                    //big right angle
                    g->b.dy=-g->b.dy;
                    g->b.dx+=2;
                }
                
                //Home score +1
                g->s1.homeScore++;
                XF_pushEvent(evRedrawScore,false);
                
            }
        }
    }
    //------------------------collision with paddle 2---------------------------
    if(g->b.y-_BALL_RADIUS<=g->p2.y+_PADDLE_HEIGHT+1)
    {
        if(g->b.x+_BALL_RADIUS>g->p2.x)
        {
            if(g->b.x-_BALL_RADIUS<g->p2.x+_PADDLE_WIDTH)
            {
                if(g->b.x-g->p2.x<10)
                {
                    //Big left angle
                    g->b.dy=-g->b.dy;
                    g->b.dx-=2;
                }
                else if(g->b.x-g->p2.x<20)
                {
                    //Small left angle
                    g->b.dy=-g->b.dy;
                    g->b.dx-=1;
                }
                else if(g->b.x-g->p2.x<30)
                {
                    //center
                    g->b.dx=g->b.dx;
                    g->b.dy=-g->b.dy;
                }
                else if(g->b.x-g->p2.x<40)
                {
                    //small right angle
                    g->b.dy=-g->b.dy;
                    g->b.dx+=1;
                }
                else
                {
                    //big right angle
                    g->b.dy=-g->b.dy;
                    g->b.dx+=2;
                }
                //Away score +1
                g->s1.awayScore++;
                XF_pushEvent(evRedrawScore,false);
            }
        }
    }
    
    //------------------------loose game-----------------------------------
    if(g->b.y-_BALL_RADIUS<=g->p2.y-5)
    {
        //Paddle 2 loose
        XF_pushEvent(evEndGame,false);
        g->s1.awayScore=0;
        gameStateMachine=ENDGAME;
    }
    if(g->b.y+_BALL_RADIUS>=g->p1.y+5)
    {
        //Paddle 1 loose
        XF_pushEvent(evEndGame,false);
        g->s1.homeScore=0;
        gameStateMachine=ENDGAME;
    }
    
}
//Update backlight power
void backlightController(GameParameters* g)
{
    if(((g->x)>=50)&&((g->x)<64))
    {
        GameParameters_setBackLight(g,0);//0%
    }
    else if(((g->x)>=64)&&((g->x)<78))
    {
        GameParameters_setBackLight(g,1);//0%
    }
    else if(((g->x)>=78)&&((g->x)<92))
    {
        GameParameters_setBackLight(g,2);//10%
    }
    else if(((g->x)>=92)&&((g->x)<106))
    {
        GameParameters_setBackLight(g,3);//20%
    }
    else if(((g->x)>=106)&&((g->x)<120))
    {
        GameParameters_setBackLight(g,4);//30%
    }
    else if(((g->x)>=120)&&((g->x)<134))
    {
        GameParameters_setBackLight(g,5);//40%
    }
        else if(((g->x)>=134)&&((g->x)<150))
    {
        GameParameters_setBackLight(g,6);//50%
    }
    else if(((g->x)>=150)&&((g->x)<164))
    {
        GameParameters_setBackLight(g,7);//60%
    }
    else if(((g->x)>=164)&&((g->x)<178))
    {
        GameParameters_setBackLight(g,8);//70%
    }
    else if(((g->x)>=178)&&((g->x)<192))
    {
        GameParameters_setBackLight(g,9);//80%
    }
    else if(((g->x)>=192)&&((g->x)<206))
    {
        GameParameters_setBackLight(g,10);//90%
    }
    else if(((g->x)>=206)&&((g->x)<215))
    {
        GameParameters_setBackLight(g,11);//100%
    }
    g->sldParam.value=g->backlight;
}
