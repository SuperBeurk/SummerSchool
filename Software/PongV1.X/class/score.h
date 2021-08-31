#include "../libraries/lcd_highlevel.h"
typedef struct Score
{
    uint16_t homeScore;
    uint16_t awayScore;
}Score;
void Score_init(struct Score* s);
void Score_setHomeScore(struct Score* s, uint16_t value);
void Score_setAwayScore(struct Score* s, uint16_t value);
void Score_draw(struct Score* s);
