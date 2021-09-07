#include "score.h"
extern const FONT_INFO arialNarrow_12ptFontInfo;

//------------------------------------------------------------------------------
//Method that will initialize the struct
//------------------------------------------------------------------------------
void Score_init(struct Score* s)
{
    s->homeScore = 0;
    s->awayScore = 0;
}

//------------------------------------------------------------------------------
//Method that will set homeScore
//------------------------------------------------------------------------------
void Score_setHomeScore(struct Score* s, uint16_t value)
{
    s->homeScore = value;
}

//------------------------------------------------------------------------------
//Method that will set awayScore
//------------------------------------------------------------------------------
void Score_setAwayScore(struct Score* s, uint16_t value)
{
    s->awayScore = value;
}

//------------------------------------------------------------------------------
//Method that will draw score
//------------------------------------------------------------------------------
void Score_draw(struct Score* s)
{
    sprintf(s->str,"%d",s->homeScore);
    LCD_DrawText(s->str,&arialNarrow_12ptFontInfo,A_LEFT,20,170,WHITE,BLACK);
    sprintf(s->str,"%d",s->awayScore);
    LCD_DrawText(s->str,&arialNarrow_12ptFontInfo,A_LEFT,20,138,WHITE,BLACK);
}
