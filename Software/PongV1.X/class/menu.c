#include "menu.h"
extern const FONT_INFO arialNarrow_12ptFontInfo;

//------------------------------------------------------------------------------
//Method that will display the Parameters menu
//------------------------------------------------------------------------------
void Menu_welcomeDraw(GameParameters* g)
{
    LCD_Fill(WHITE);
    LCD_DrawText("WELCOME",&arialNarrow_12ptFontInfo,A_CENTER,50,50,BLACK,WHITE);
    LCD_ButtonDraw(&(g->btnParam));
    LCD_ButtonDraw(&(g->btnOnePlayer));
    LCD_ButtonDraw(&(g->btnTwoPlayer));
}

//------------------------------------------------------------------------------
//Method that will display the Parameters menu
//------------------------------------------------------------------------------
void Menu_parametersDraw(GameParameters* g)
{
    LCD_Fill(WHITE);
    LCD_DrawText("PARAMETERS",&arialNarrow_12ptFontInfo,A_CENTER,50,50,BLACK,WHITE);
    LCD_ButtonDraw(&(g->btnLeaveParam));
    g->sldParam.value=g->backlight;
    LCD_SliderDraw(&(g->sldParam)); 
}

//------------------------------------------------------------------------------
//Method that will display the Parameters menu
//------------------------------------------------------------------------------
void Menu_inGameDraw(GameParameters* g)
{
    LCD_Fill(BLACK);
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
    
    if(g->s1.homeScore==0)
    {
        LCD_DrawText("PLAYER 2 WIN",&arialNarrow_12ptFontInfo,A_CENTER,100,50,WHITE,BLACK);
    }
    else
    {
        LCD_DrawText("PLAYER 1 WIN",&arialNarrow_12ptFontInfo,A_CENTER,100,50,WHITE,BLACK);
    }
    
}
