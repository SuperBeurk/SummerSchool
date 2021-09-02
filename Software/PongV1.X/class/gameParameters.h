
#ifndef _GAMEPARAMETERS
#define _GAMEPARAMETERS
#include "../libraries/lcd_highlevel.h"
typedef struct GameParameters
{
    uint16_t backlight;
    uint16_t player;
    uint16_t x;
    uint16_t y;
}GameParameters;
void GameParameters_init(struct GameParameters* s);
void GameParameters_setBacklight(struct GameParameters* s, uint16_t value);
void GameParameters_setPlayer(struct GameParameters* s, uint16_t value);
void GameParameters_draw(struct GameParameters* s);
void GameParameters_setX(struct GameParameters* s, uint16_t value);
void GameParameters_setY(struct GameParameters* s, uint16_t value);
#endif
