#include "menu.h"
extern const FONT_INFO arialNarrow_12ptFontInfo;

//------------------------------------------------------------------------------
//Method that will display the Parameters menu
//------------------------------------------------------------------------------
void Menu_welcomeDraw(GameParameters* g)
{
    LCD_Fill(BLACK);
    LCD_DrawText("WELCOME",&arialNarrow_12ptFontInfo,A_CENTER,120,50,WHITE,BLACK);
    
    LCD_ButtonDraw(&(g->btnOnePlayer));
    LCD_ButtonDraw(&(g->btnTwoPlayer));
    LCD_ButtonDraw(&(g->btnParam));
    LCD_ButtonDraw(&(g->btnTurnOff));
}

//------------------------------------------------------------------------------
//Method that will display the Parameters menu
//------------------------------------------------------------------------------
void Menu_parametersDraw(GameParameters* g)
{
    LCD_Fill(BLACK);
    LCD_DrawText("PARAMETERS",&arialNarrow_12ptFontInfo,A_CENTER,120,50,WHITE,BLACK);
    LCD_ButtonDraw(&(g->btnLeave));
    g->sldBackLight.value=g->backlight;
    LCD_SliderDraw(&(g->sldBackLight)); 
    LCD_DrawText("LUMINOSITY",&arialNarrow_12ptFontInfo,A_LEFT,50,95,WHITE,BLACK);
    g->sldLevel.value=g->level;
    LCD_SliderDraw(&(g->sldLevel)); 
    LCD_DrawText("LEVEL",&arialNarrow_12ptFontInfo,A_LEFT,50,145,WHITE,BLACK);
}

//------------------------------------------------------------------------------
//Method that will display the Parameters menu
//------------------------------------------------------------------------------
void Menu_inGameDraw(GameParameters* g)
{
    LCD_Fill(BLACK);
    LCD_ButtonDraw(&(g->btnLeave));
    LCD_DrawRect(0,160,239,160,1,WHITE);//Draw middle score line
    Score_draw(&g->s1);
    Paddle_draw(&g->p1);
    Paddle_draw(&g->p2);
    Ball_draw(&g->b);
}

//------------------------------------------------------------------------------
//Method that will display the Parameters menu
//------------------------------------------------------------------------------
void Menu_endGame(GameParameters* g)
{
    LCD_Fill(BLACK);
    LCD_ButtonDraw(&(g->btnNewGame));
    LCD_ButtonDraw(&(g->btnTurnOff));
    
    if(g->s1.homeScore==0)
    {
        LCD_DrawText("PLAYER 2 WIN",&arialNarrow_12ptFontInfo,A_CENTER,100,50,WHITE,BLACK);
    }
    else
    {
        LCD_DrawText("PLAYER 1 WIN",&arialNarrow_12ptFontInfo,A_CENTER,100,50,WHITE,BLACK);
    }
    
}
