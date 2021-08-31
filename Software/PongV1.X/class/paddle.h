#include "../libraries/lcd_highlevel.h"
struct Paddle
{
    uint16_t x;
    uint16_t y;
    uint16_t w;
    uint16_t h;
    uint16_t color;
};
void Paddle_init(struct Paddle* p);
void Paddle_setWidth(struct Paddle* p, uint16_t value);
void Paddle_setHeight(struct Paddle* p, uint16_t value);
void Paddle_setPosX(struct Paddle* p, uint16_t value);
void Paddle_setPosY(struct Paddle* p, uint16_t value);
void Paddle_setColor(struct Paddle* p, uint16_t value);
