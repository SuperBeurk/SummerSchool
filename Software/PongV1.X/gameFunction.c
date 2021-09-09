#include "gameFunction.h"
extern XF theXF;   
//------------------------------------------------------------------------------
//Method that will moove the local paddle on a click on the screen depending where we clicked
//------------------------------------------------------------------------------
void moovePaddle1(GameParameters* g)
{
    
    if((g->x>0)&&(g->x<110))//check if click is on the left of the screen
    {
        GameParameters_resetPos(g);//reset click
        Paddle_addX(&g->p1,1,0);//Moove left
    }
    
    if(g->x>=130)//check if click is on the right of the screen
    {
        GameParameters_resetPos(g);//reset click
        Paddle_addX(&g->p1,1,1);//Moove right
    }
    XF_pushEvent(evRedrawPaddle1,false);//Create redraw event for display
}

//------------------------------------------------------------------------------
//Method that will moove the IA paddle
//------------------------------------------------------------------------------
void moovePaddle2(GameParameters* g)
{
    //Moove IA Paddle
    if(g->p2.x+(_PADDLE_WIDTH/2)<g->b.x-2)//if the paddle is at left of the ball
    {
        Paddle_addX(&g->p2,2,1);//moove paddle right
        XF_pushEvent(evRedrawPaddle2,false);
    }
    else if(g->p2.x+(_PADDLE_WIDTH/2)>g->b.x+2)//if paddle is at right of the ball
    {
        Paddle_addX(&g->p2,2,0);//moove paddle left
        XF_pushEvent(evRedrawPaddle2,false);
    }
}

//------------------------------------------------------------------------------
//Method that will desactivate the sleepEventTimer
//------------------------------------------------------------------------------
void desactivateTimerSleep()
{
    for (int i=0; i<MAXTIMER; i++)
    {
        if (theXF.timerList[i].ev == evSleep)
        {
            XF_unscheduleTimer(i, false);
        }
    }
}

//------------------------------------------------------------------------------
//Method that will moove the ball
//------------------------------------------------------------------------------
void mooveBall(GameParameters* g)
{
    checkCollision(g);//check collision with wall and both paddle  
    Ball_Update(&g->b); //moove the ball with his vector
    XF_pushEvent(evRedrawBall,false);
    XF_pushEvent(evRedrawScore,false);
}

//------------------------------------------------------------------------------
//Method that will check the game collision
//------------------------------------------------------------------------------
void checkCollision(GameParameters* g)
{
    char s[20];
    //------------------------ball collision with wall--------------------------
    if(g->b.x+g->b.dx+_BALL_RADIUS>=239)//right wall
    {
        g->b.dx=-g->b.dx;
        g->b.x+=g->b.dx;
    }
    if((int)(g->b.x+g->b.dx-_BALL_RADIUS)<=1)//left wall
    {
        g->b.dx=-g->b.dx;
        g->b.x+=g->b.dx;
    }
    //------------------------collision with paddle 1---------------------------
    if(g->b.y+_BALL_RADIUS==g->p1.y-1)//same height as the paddle
    {
        if(g->b.x+_BALL_RADIUS>g->p1.x)
        {
            if(g->b.x-_BALL_RADIUS<g->p1.x+_PADDLE_WIDTH)//ball is in the paddle
            {
                //The paddle is divided in 5 compartment to create different angle for the ball
                if(g->b.x-g->p1.x<10)//in 1/5 of the paddle
                {
                    //big left angle
                    g->b.dy=-g->b.dy;
                    g->b.dx-=2;
                }
                else if(g->b.x-g->p1.x<20)//in 2/5
                {
                    //small left angle
                    g->b.dy=-g->b.dy;
                    g->b.dx-=1;
                }
                else if(g->b.x-g->p1.x<30)//in 3/5
                {
                    //center
                    g->b.dx=-g->b.dx;
                    g->b.dy=-g->b.dy;
                }
                else if(g->b.x-g->p1.x<40)//in 4/5
                {
                    //small right angle
                    g->b.dy=-g->b.dy;
                    g->b.dx+=1;
                }
                else//in 5/5
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
    //same as first paddle
    if(g->b.y-_BALL_RADIUS==g->p2.y+_PADDLE_HEIGHT+1)
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
                    g->b.dx=-g->b.dx;
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
    if(g->b.y-_BALL_RADIUS<g->p2.y-_PADDLE_HEIGHT)
    {
        //Paddle 2 loose
        XF_pushEvent(evEndGame,false);
        g->s1.awayScore=0;
    }
    if(g->b.y+_BALL_RADIUS>g->p1.y+_PADDLE_HEIGHT)
    {
        //Paddle 1 loose
        XF_pushEvent(evEndGame,false);
        g->s1.homeScore=0;
    }
    
}

//------------------------------------------------------------------------------
//Method that will update the luminosity
//------------------------------------------------------------------------------
void backlightController(GameParameters* g)
{
    //check where wi click on the slider
    if(((g->x)>=50)&&((g->x)<64))
    {
        GameParameters_setBackLight(g,0);//0%
    }
    else if(((g->x)>=64)&&((g->x)<78))
    {
        GameParameters_setBackLight(g,1);//9%
    }
    else if(((g->x)>=78)&&((g->x)<92))
    {
        GameParameters_setBackLight(g,2);//18%
    }
    else if(((g->x)>=92)&&((g->x)<106))
    {
        GameParameters_setBackLight(g,3);//27%
    }
    else if(((g->x)>=106)&&((g->x)<120))
    {
        GameParameters_setBackLight(g,4);//36%
    }
    else if(((g->x)>=120)&&((g->x)<134))
    {
        GameParameters_setBackLight(g,5);//45%
    }
        else if(((g->x)>=134)&&((g->x)<150))
    {
        GameParameters_setBackLight(g,6);//54%
    }
    else if(((g->x)>=150)&&((g->x)<164))
    {
        GameParameters_setBackLight(g,7);//63%
    }
    else if(((g->x)>=164)&&((g->x)<178))
    {
        GameParameters_setBackLight(g,8);//72%
    }
    else if(((g->x)>=178)&&((g->x)<192))
    {
        GameParameters_setBackLight(g,9);//81%
    }
    else if(((g->x)>=192)&&((g->x)<206))
    {
        GameParameters_setBackLight(g,10);//90%
    }
    else if(((g->x)>=206)&&((g->x)<215))
    {
        GameParameters_setBackLight(g,11);//100%
    }
    g->sldBackLight.value=g->backlight;//update slidebar value
}

//------------------------------------------------------------------------------
//Method that will update the level
//------------------------------------------------------------------------------
void levelController(GameParameters* g)
{
    //check where we click on the slider
    if(((g->x)>=105)&&((g->x)<160))
    {
        GameParameters_setLevel(g,2);//Level 2
    }
    else if(((g->x)>=160)&&((g->x)<215))
    {
        GameParameters_setLevel(g,3);//Level 3
    }
    else
    {
        GameParameters_setLevel(g,1);//Level 1 default
    }
    g->sldLevel.value=g->level;//update slidebar value
}
