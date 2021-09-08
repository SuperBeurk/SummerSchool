#include "gameParameters.h"
extern FONT_INFO arialNarrow_12ptFontInfo;

//------------------------------------------------------------------------------
//Method that will initialize the struct
//------------------------------------------------------------------------------
void GameParameters_init(struct GameParameters* s)
{
    //Default value
    s->backlight = 11;
    CCPR2L = 255;
    s->x=0;
    s->y=0;
    s->level=1;
    Score_init(&s->s1);
    Ball_init(&(s->b));
    s->b.dy=1;//Default moving vector
    Paddle_init(&(s->p1),0);
    Paddle_init(&(s->p2),1);
    
    //create button and slider    
    LCD_ButtonCreate(10,200,90,30,BLACK,WHITE,"1 Player",&arialNarrow_12ptFontInfo,NULL,NULL,NULL,&(s->btnOnePlayer),1);
    LCD_ButtonCreate(140,200,90,30,BLACK,WHITE,"2 Player",&arialNarrow_12ptFontInfo,NULL,NULL,NULL,&(s->btnTwoPlayer),2);
    LCD_ButtonCreate(10,250,90,30,BLACK,WHITE,"Parametres",&arialNarrow_12ptFontInfo,NULL,NULL,NULL,&(s->btnParam),3);
    LCD_ButtonCreate(140,250,90,30,BLACK,WHITE,"Turn Off",&arialNarrow_12ptFontInfo,NULL,NULL,NULL,&(s->btnTurnOff),4);
    
    LCD_ButtonCreate(220,0,20,20,BLACK,RED,"X",&arialNarrow_12ptFontInfo,NULL,NULL,NULL,&(s->btnLeave),5);
    LCD_ButtonCreate(10,250,90,30,BLACK,WHITE,"New Game",&arialNarrow_12ptFontInfo,NULL,NULL,NULL,&(s->btnNewGame),6);
    
    
    LCD_SliderCreate(50,110,165,20,BLACK,WHITE,RED,0,11,NULL,&(s->sldBackLight));
    LCD_SliderCreate(50,160,165,20,BLACK,WHITE,RED,0,3,NULL,&(s->sldLevel));
}

//------------------------------------------------------------------------------
//Method that will set the luminosity from 0 to 100%
//------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------
//Method that will set the level
//------------------------------------------------------------------------------
void GameParameters_setLevel(struct GameParameters* s, uint16_t value)
{
    s->level = value;
}

//------------------------------------------------------------------------------
//Method that will reset tsc position value
//------------------------------------------------------------------------------
void GameParameters_resetPos(struct GameParameters* s)
{
    s->x=0;
    s->y=0;
}

//------------------------------------------------------------------------------
//Method that will set X_tsc position value
//------------------------------------------------------------------------------
void GameParameters_setX(struct GameParameters* s, uint16_t value)
{
    s->x=value;
}

//------------------------------------------------------------------------------
//Method that will set Y_tsc position value
//------------------------------------------------------------------------------
void GameParameters_setY(struct GameParameters* s, uint16_t value)
{
    s->y=value;
}