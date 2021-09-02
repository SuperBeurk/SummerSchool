#include "ball.h"
extern const FONT_INFO arialNarrow_12ptFontInfo;
void Ball_init(struct Ball* b)
{
    b->x = 90;
    b->y = 150;
    b->r = 10;
    b->color = RED;
}
void Ball_setPosX(struct Ball* b, uint16_t value)
{
    b->x = value;
}
void Ball_setPosY(struct Ball* b, uint16_t value)
{
    b->y = value;
}
void Ball_draw(struct Ball* b)
{
    LCD_DrawText("O",&arialNarrow_12ptFontInfo, A_LEFT, b->x, b->y,b->color, WHITE);
}
