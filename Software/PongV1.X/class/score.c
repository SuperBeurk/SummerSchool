#include "score.h"
extern const FONT_INFO arialNarrow_12ptFontInfo;
void Score_init(struct Score* s)
{
    s->homeScore = 0;
    s->awayScore = 0;
}
void Score_setHomeScore(struct Score* s, uint16_t value)
{
    s->homeScore = value;
}
void Score_setAwayScore(struct Score* s, uint16_t value)
{
    s->awayScore = value;
}
void Score_draw(struct Score* s)
{
    sprintf(s->str,"%d",s->homeScore);
    LCD_DrawText(s->str,&arialNarrow_12ptFontInfo,A_LEFT,0,0,WHITE,BLACK);
    sprintf(s->str,"%d",s->awayScore);
    LCD_DrawText(s->str,&arialNarrow_12ptFontInfo,A_RIGHT,239,0,WHITE,BLACK);
}
