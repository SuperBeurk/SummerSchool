#include "gameParameters.h"
extern FONT_INFO arialNarrow_12ptFontInfo;
void GameParameters_init(struct GameParameters* s)
{
    s->backlight = 11;
    CCPR2L = 255;
    s->player = 0;
    s->x=0;
    s->y=0;
    Ball_init(&(s->b));
    Paddle_init(&(s->p1),0);
    Paddle_init(&(s->p2),1);
    LCD_ButtonCreate(130,50,90,20,WHITE,BLACK,"Parametres",&arialNarrow_12ptFontInfo,NULL,NULL,NULL,&(s->btnParam),1);
    LCD_ButtonCreate(10,250,70,20,WHITE,BLACK,"1 Player",&arialNarrow_12ptFontInfo,NULL,NULL,NULL,&(s->btnOnePlayer),2);
    LCD_ButtonCreate(150,250,70,20,WHITE,BLACK,"2 Player",&arialNarrow_12ptFontInfo,NULL,NULL,NULL,&(s->btnTwoPlayer),3);
    LCD_ButtonCreate(130,50,90,20,WHITE,BLACK,"QUITTER",&arialNarrow_12ptFontInfo,NULL,NULL,NULL,&(s->btnLeaveParam),4);
    LCD_ButtonCreate(10,220,70,50,BLACK,WHITE,"<--",&arialNarrow_12ptFontInfo,NULL,NULL,NULL,&(s->btnLeft),5);
    LCD_ButtonCreate(150,220,70,50,BLACK,WHITE,"-->",&arialNarrow_12ptFontInfo,NULL,NULL,NULL,&(s->btnRight),6);
    LCD_SliderCreate(50,100,165,20,BLACK,WHITE,RED,0,11,NULL,&(s->sldParam));
}
void GameParameters_setBackLight(struct GameParameters* s, uint16_t value)
{
    s->backlight = value;
    if(s->backlight==11)
    {
        CCPR2L = 255;
    }
    else
    {
        CCPR2L=(s->backlight)*23;
    }
}
void GameParameters_setPlayer(struct GameParameters* s, uint16_t value)
{
    s->player = value;
}
void GameParameters_draw(struct GameParameters* s)
{
    
}
void GameParameters_resetPos(struct GameParameters* s)
{
    s->x=0;
    s->y=0;
}
void GameParameters_setX(struct GameParameters* s, uint16_t value)
{
    s->x=value;
}
void GameParameters_setY(struct GameParameters* s, uint16_t value)
{
    s->y=value;
}