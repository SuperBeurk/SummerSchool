#include "../libraries/lcd_highlevel.h"
typedef struct GameParameters
{
    uint16_t backlight;
    uint16_t player;
}GameParameters;
void GameParameters_init(struct GameParameters* s);
void GameParameters_setBacklight(struct GameParameters* s, uint16_t value);
void GameParameters_setPlayer(struct GameParameters* s, uint16_t value);
void GameParameters_draw(struct GameParameters* s);
