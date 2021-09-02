#include "menu.h"
extern const FONT_INFO arialNarrow_12ptFontInfo;
void Menu_welcomeDraw(GameParameters* g)
{
    LCD_Fill(WHITE);
    LCD_DrawText("WELCOME",&arialNarrow_12ptFontInfo,A_CENTER,50,50,BLACK,WHITE);
    LCD_ButtonDraw(&(g->btnParam));
    LCD_ButtonDraw(&(g->btnOnePlayer));
    LCD_ButtonDraw(&(g->btnTwoPlayer));
}
void Menu_parametersDraw(GameParameters* g)
{
    LCD_Fill(WHITE);
    LCD_DrawText("PARAMETERS",&arialNarrow_12ptFontInfo,A_CENTER,50,50,BLACK,WHITE);
    LCD_ButtonDraw(&(g->btnLeaveParam));
    g->sldParam.value=g->backlight;
    LCD_SliderDraw(&(g->sldParam)); 
}
void Menu_inGameDraw(GameParameters* g)
{
    LCD_Fill(WHITE);
    LCD_DrawText("INGAME",&arialNarrow_12ptFontInfo,A_CENTER,50,50,BLACK,WHITE);
    LCD_ButtonDraw(&(g->btnRight));
    LCD_ButtonDraw(&(g->btnLeft));
    Paddle_draw(&g->p1);
    Paddle_draw(&g->p2);
    Ball_draw(&g->b);
}
