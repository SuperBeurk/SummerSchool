/*
 * File:   gameController.c
 * Author: sebastie.metral
 *
 * Created on 30. août 2021, 12:40
 */
#include "gameController.h"
typedef enum state{NOGAME,PARAMETERS,LOCAL,ONLINE} state;
enum state gameControllerState;

void gameControllerInit(GameParameters* g)
{
    gameControllerState=NOGAME;
    gameControllerController(g);    
}
void gameControllerSM(Event ev,GameParameters* g)
{
   switch(gameControllerState)
    {
        case NOGAME:
            gameControllerController(g);
            if(ev==evParameters)
            {
                gameControllerState=PARAMETERS;
            }
            if(ev==evOnePlayer)
            {
                gameControllerState=LOCAL;
            }
            break;
            if(ev==evTwoPlayer)
            {
                gameControllerState=ONLINE;
            }
        case PARAMETERS:
            gameControllerController(g);
            if(ev==evLeaveParam)
            {
                gameControllerState=NOGAME;
            }
            break;
        case LOCAL:
            if(ev==evTimerPos)
            {
                gameControllerController(g);
            }
            break;
        case ONLINE:

            break;
        default:
            break;
    } 
}
void gameControllerController(GameParameters* g)
{
    switch(gameControllerState)
    {
        case NOGAME:
            if(LCD_InButton(&(g->btnParam),g->x,g->y))
            {
                XF_pushEvent(evParameters,false);
                g->x=0;
                g->y=0;
            }
            if(LCD_InButton(&(g->btnOnePlayer),g->x,g->y))
            {
                XF_pushEvent(evOnePlayer,false);
                g->x=0;
                g->y=0;                
            }
            if(LCD_InButton(&(g->btnTwoPlayer),g->x,g->y))
            {
                XF_pushEvent(evTwoPlayer,false);
                g->x=0;
                g->y=0;
            }
            break;
        case PARAMETERS:
            if(LCD_InSlider(&(g->sldParam),g->x,g->y))
            {
                backlightController(g);
                LCD_SliderUpdate(&(g->sldParam));
                g->x=0;
                g->y=0;
            }
            if(LCD_InButton(&(g->btnLeaveParam),g->x,g->y))
            {
                XF_pushEvent(evLeaveParam,false);
                g->x=0;
                g->y=0;
            }
            break;
        case LOCAL:
            if(LCD_InButton(&(g->btnLeft),g->x,g->y))
            {
                g->x=0;
                g->y=0;
                Paddle_addX(&g->p1,8,0);
            }
            if(LCD_InButton(&(g->btnRight),g->x,g->y))
            {
                g->x=0;
                g->y=0;
                Paddle_addX(&g->p1,8,1);
            }
            Paddle_draw(&g->p1);
            LCD_ButtonUpdate(&(g->btnLeft));
            LCD_ButtonUpdate(&(g->btnRight));
            break;
        case ONLINE:
            break;
        default:
            break;
    }
}
void backlightController(GameParameters* g)
{
    if(((g->x)>=50)&&((g->x)<64))
    {
        GameParameters_setBackLight(g,0);
    }
    else if(((g->x)>=64)&&((g->x)<78))
    {
        GameParameters_setBackLight(g,1);
    }
    else if(((g->x)>=78)&&((g->x)<92))
    {
        GameParameters_setBackLight(g,2);
    }
    else if(((g->x)>=92)&&((g->x)<106))
    {
        GameParameters_setBackLight(g,3);
    }
    else if(((g->x)>=106)&&((g->x)<120))
    {
        GameParameters_setBackLight(g,4);
    }
    else if(((g->x)>=120)&&((g->x)<134))
    {
        GameParameters_setBackLight(g,5);
    }
        else if(((g->x)>=134)&&((g->x)<150))
    {
        GameParameters_setBackLight(g,6);
    }
    else if(((g->x)>=150)&&((g->x)<164))
    {
        GameParameters_setBackLight(g,7);
    }
    else if(((g->x)>=164)&&((g->x)<178))
    {
        GameParameters_setBackLight(g,8);
    }
    else if(((g->x)>=178)&&((g->x)<192))
    {
        GameParameters_setBackLight(g,9);
    }
    else if(((g->x)>=192)&&((g->x)<206))
    {
        GameParameters_setBackLight(g,10);
    }
    else if(((g->x)>=206)&&((g->x)<215))
    {
        GameParameters_setBackLight(g,11);
    }
    g->sldParam.value=g->backlight;
}
