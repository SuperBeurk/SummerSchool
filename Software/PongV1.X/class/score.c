#include "score.h"
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
    
}
