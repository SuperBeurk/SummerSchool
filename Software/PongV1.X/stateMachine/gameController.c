/*
 * File:   gameController.c
 * Author: sebastie.metral
 *
 * Created on 30. ao�t 2021, 12:40
 */
#include "gameController.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef enum state{NOGAME,PARAMETERS,LOCAL,ONLINE} state;
extern const FONT_INFO arialNarrow_12ptFontInfo;
enum state gameControllerState;

void gameControllerInit(GameParameters* g)
{
    gameControllerState=NOGAME;
    gameControllerController(g);    
}
void gameControllerSM(Event ev,GameParameters* g)
{
   char s[20];
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
            if (ev==evPress)
            {
                moovePaddle(g);
                
            }
            else if(ev==evGameUpdate)
            {
                mooveBall(g);
                LCD_DrawRect(g->p2.x,g->p2.y,g->p2.x+_PADDLE_WIDTH,g->p2.y+_PADDLE_HEIGHT,1,WHITE);
                g->p2.x=g->b.x;
                Paddle_draw(&g->p2);
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
                GameParameters_resetPos(g);;
            }
            if(LCD_InButton(&(g->btnOnePlayer),g->x,g->y))
            {
                XF_pushEvent(evOnePlayer,false);
                GameParameters_resetPos(g);;               
            }
            if(LCD_InButton(&(g->btnTwoPlayer),g->x,g->y))
            {
                XF_pushEvent(evTwoPlayer,false);
                GameParameters_resetPos(g);
            }
            break;
        case PARAMETERS:
            if(LCD_InSlider(&(g->sldParam),g->x,g->y))
            {
                backlightController(g);
                LCD_SliderUpdate(&(g->sldParam));
                GameParameters_resetPos(g);
            }
            if(LCD_InButton(&(g->btnLeaveParam),g->x,g->y))
            {
                XF_pushEvent(evLeaveParam,false);
                GameParameters_resetPos(g);
            }
            break;
        case LOCAL: 
            break;
        case ONLINE:
            break;
        default:
            break;
    }
}
void moovePaddle(GameParameters* g)
{
    if(LCD_InButton(&(g->btnLeft),g->x,g->y))
    {
        GameParameters_resetPos(g);
        Paddle_addX(&g->p1,8,0);
    }
    if(LCD_InButton(&(g->btnRight),g->x,g->y))
    {
        GameParameters_resetPos(g);
        Paddle_addX(&g->p1,8,1);
    }
    Paddle_draw(&g->p1);
}
void mooveBall(GameParameters* g)
{
    checkCollision(g);
    Ball_Update(&g->b);   
}
void checkCollision(GameParameters* g)
{
    //------------------------collision with paddle 1---------------------------
    if(g->b.y+_BALL_RADIUS>=g->p1.y-1)
    {
        if(g->b.x+_BALL_RADIUS>g->p1.x)
        {
            if(g->b.x-_BALL_RADIUS<g->p1.x+_PADDLE_WIDTH)
            {
                if(g->b.x-g->p1.x<10)
                {
                    //GROS ANGLE GAUCHE
                    g->b.dy=-g->b.dy;
                    g->b.dx=-2;
                }
                else if(g->b.x-g->p1.x<20)
                {
                    //petit ANGLE GAUCHE
                    g->b.dy=-g->b.dy;
                    g->b.dx=-1;
                }
                else if(g->b.x-g->p1.x<30)
                {
                    g->b.dx=g->b.dx;
                    g->b.dy=-g->b.dy;
                }
                else if(g->b.x-g->p1.x<40)
                {
                    //PETIT ANGLE DROIT
                    g->b.dy=-g->b.dy;
                    g->b.dx=1;
                }
                else
                {
                    //GROS ANGLE DROIT
                    g->b.dy=-g->b.dy;
                    g->b.dx=2;
                }
                
                //Home score +1
                g->s1.homeScore++;
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
                    //GROS ANGLE GAUCHE
                    g->b.dy=-g->b.dy;
                    g->b.dx=-2;
                }
                else if(g->b.x-g->p2.x<20)
                {
                    //petit ANGLE GAUCHE
                    g->b.dy=-g->b.dy;
                    g->b.dx=-1;
                }
                else if(g->b.x-g->p2.x<30)
                {
                    g->b.dx=g->b.dx;
                    g->b.dy=-g->b.dy;
                }
                else if(g->b.x-g->p2.x<40)
                {
                    //PETIT ANGLE DROIT
                    g->b.dy=-g->b.dy;
                    g->b.dx=1;
                }
                else
                {
                    //GROS ANGLE DROIT
                    g->b.dy=-g->b.dy;
                    g->b.dx=2;
                }
                //Away score +1
                g->s1.awayScore++;
            }
        }
    }
    //------------------------collision with wall---------------------------
    if(g->b.x+_BALL_RADIUS>=239)
    {
        g->b.dx=-g->b.dx;
    }
    if(g->b.x-_BALL_RADIUS<=0)
    {
        g->b.dx=-g->b.dx;
    }
    //------------------------loose game-----------------------------------
    if(g->b.y-_BALL_RADIUS<=g->p2.y)
    {
        //Paddle 2 loose
    }
    if(g->b.y+_BALL_RADIUS>=g->p1.y)
    {
        //Paddle 1 loose
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
