#include "gameParameters.h"
void GameParameters_init(struct GameParameters* s)
{
    s->backlight = 0;
    s->player = 0;
    s->x=0;
    s->y=0;
}
void GameParameters_setBackLight(struct GameParameters* s, uint16_t value)
{
    s->backlight = value;
}
void GameParameters_setPlayer(struct GameParameters* s, uint16_t value)
{
    s->player = value;
}
void GameParameters_draw(struct GameParameters* s)
{
    
}
void GameParameters_setX(struct GameParameters* s, uint16_t value)
{
    s->x=value;
}
void GameParameters_setY(struct GameParameters* s, uint16_t value)
{
    s->y=value;
}