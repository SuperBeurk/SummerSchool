#ifndef _SCORE
#define _SCORE
#include "../libraries/lcd_highlevel.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Score
{
    uint16_t homeScore;
    uint16_t awayScore;
    char str[2];
}Score;
void Score_init(struct Score* s);
void Score_setHomeScore(struct Score* s, uint16_t value);
void Score_setAwayScore(struct Score* s, uint16_t value);
void Score_draw(struct Score* s);
#endif
