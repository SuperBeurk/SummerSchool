# 1 "class/factory.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "class/factory.c" 2
# 1 "class/factory.h" 1
# 1 "class/ball.h" 1
# 1 "class/../libraries/lcd_highlevel.h" 1





# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdint.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\musl_xc8.h" 1 3
# 4 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdint.h" 2 3
# 22 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 127 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long uintptr_t;
# 142 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long intptr_t;
# 158 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef __int24 int24_t;




typedef long int32_t;





typedef long long int64_t;
# 188 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef __uint24 uint24_t;




typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 229 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 22 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdint.h" 2 3


typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;
typedef int24_t int_fast24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;
typedef uint24_t uint_fast24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 144 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 144 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdint.h" 2 3
# 6 "class/../libraries/lcd_highlevel.h" 2





typedef struct
{
    uint8_t width;
    uint16_t offset;
}FONT_CHAR_INFO;

typedef struct
{
    uint8_t height;
    uint8_t start_char;
    uint8_t end_char;
    const FONT_CHAR_INFO * descriptor;
    const uint8_t * bitmap;

}FONT_INFO;
# 50 "class/../libraries/lcd_highlevel.h"
typedef enum
{
    A_LEFT,
    A_RIGHT,
    A_CENTER
}ALIGN;
# 64 "class/../libraries/lcd_highlevel.h"
typedef struct
{
 uint16_t bfType;
 uint32_t bfSize;
 uint16_t bfRvd1;
 uint16_t bfRvd2;
 uint32_t bfOffBits;
 uint32_t biSize;
 uint32_t biWidth;
 uint32_t biHeight;
 uint16_t biPlanes;
 uint16_t biBitCount;
 uint32_t biCompression;
 uint32_t biSizeImage;
 uint32_t biXPelsPerMeter;
 uint32_t biYPelsPerMeter;
 uint32_t biClrUsed;
 uint32_t biClrImportant;
}BMP_STRUCT;




typedef struct
{
  uint16_t posX;
  uint16_t posY;
  uint16_t width;
  uint16_t height;
  uint16_t txtColor;
  uint16_t bgColor;
  const uint8_t *text;
  FONT_INFO * font;
  uint8_t pressed;
  void (*fpPress)(uint8_t);
  void (*fpReleased)(uint8_t);
  void (*fpOut)(uint8_t);
  uint8_t index;
}btn_t;




typedef struct
{
  uint16_t posX;
  uint16_t posY;
  uint16_t width;
  uint16_t height;
  uint16_t sldColor;
  uint16_t bgColor;
  uint16_t borderColor;
  uint16_t cursorWidth;
  uint8_t pressed;
  uint16_t value;
  uint16_t oldValue;
  uint16_t steps;
  void (*fpPress)();
}sld_t;
# 138 "class/../libraries/lcd_highlevel.h"
void LCD_ButtonCreate(uint16_t posX, uint16_t posY,
                      uint16_t width, uint16_t height,
                      uint16_t txtColor, uint16_t bgColor,
                      const uint8_t * textOrBmp, FONT_INFO * font,
                      void (*fpPress)(uint8_t), void (* fpReleased)(uint8_t), void (* fpOut)(uint8_t),
                      btn_t * button,
                      uint8_t index);
# 153 "class/../libraries/lcd_highlevel.h"
void LCD_ButtonDraw(btn_t * button);







void LCD_ButtonUpdate(btn_t * button);
# 175 "class/../libraries/lcd_highlevel.h"
void LCD_SliderCreate(uint16_t posX, uint16_t posY,
                      uint16_t width, uint16_t height,
                      uint16_t sldColor, uint16_t bgColor, uint16_t borderColor,
                      uint16_t cursorWidth,
                      uint16_t steps,
                      void (* fpPress)(),
                      sld_t * slider);







void LCD_SliderUpdate(sld_t * slider);







void LCD_SliderDraw(sld_t * slider);
# 206 "class/../libraries/lcd_highlevel.h"
uint8_t LCD_InSlider(sld_t * slider, uint16_t posX, uint16_t posY);
# 215 "class/../libraries/lcd_highlevel.h"
uint8_t LCD_InButton(btn_t * button, uint16_t posX, uint16_t posY);
# 224 "class/../libraries/lcd_highlevel.h"
void LCD_Init(void);
# 233 "class/../libraries/lcd_highlevel.h"
void LCD_Fill(uint16_t color);







void LCD_SetPixel(uint16_t posX,uint16_t posY, uint16_t color);
# 256 "class/../libraries/lcd_highlevel.h"
void LCD_DrawRect(uint16_t posX1,uint16_t posY1, uint16_t posX2,
  uint16_t posY2,uint8_t fill,uint16_t color);
# 271 "class/../libraries/lcd_highlevel.h"
void LCD_DrawText(const uint8_t * msg,const FONT_INFO * font, ALIGN align,
        uint16_t posX, uint16_t posY, uint16_t color, uint16_t bg_color);
# 281 "class/../libraries/lcd_highlevel.h"
uint16_t RGB2LCD(uint8_t * colorTableEntry);
# 295 "class/../libraries/lcd_highlevel.h"
uint8_t LCD_Bitmap(const uint8_t * bmpPtr, uint16_t posX, uint16_t posY);
# 1 "class/ball.h" 2

typedef struct Ball
{
    uint16_t x;
    uint16_t y;
    uint16_t r;
    uint16_t color;
}Ball;
void Ball_init(struct Ball* b);
void Ball_setRadius(struct Ball* b, uint16_t value);
void Ball_setPosX(struct Ball* b, uint16_t value);
void Ball_setPosY(struct Ball* b, uint16_t value);
void Ball_setColor(struct Ball* b, uint16_t value);
void Ball_draw(struct Ball* b);
# 1 "class/factory.h" 2

# 1 "class/gameParameters.h" 1
# 1 "class/../libraries/lcd_highlevel.h" 1
# 1 "class/gameParameters.h" 2

typedef struct GameParameters
{
    uint16_t backlight;
    uint16_t player;
}GameParameters;
void GameParameters_init(struct GameParameters* s);
void GameParameters_setBacklight(struct GameParameters* s, uint16_t value);
void GameParameters_setPlayer(struct GameParameters* s, uint16_t value);
void GameParameters_draw(struct GameParameters* s);
# 2 "class/factory.h" 2

# 1 "class/score.h" 1
# 1 "class/../libraries/lcd_highlevel.h" 1
# 1 "class/score.h" 2

typedef struct Score
{
    uint16_t homeScore;
    uint16_t awayScore;
}Score;
void Score_init(struct Score* s);
void Score_setHomeScore(struct Score* s, uint16_t value);
void Score_setAwayScore(struct Score* s, uint16_t value);
void Score_draw(struct Score* s);
# 3 "class/factory.h" 2

# 1 "class/../stateMachine/sleepSM.h" 1
# 1 "class/../stateMachine/../xf/xf.h" 1
# 15 "class/../stateMachine/../xf/xf.h"
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdbool.h" 1 3
# 16 "class/../stateMachine/../xf/xf.h" 2

typedef uint8_t Event;
typedef uint16_t Time;
typedef uint8_t TimerID;

enum myEvents{NULLEVENT,evPress,evRelease,evTimer30,evTimerPos,evOnePlayer,evTwoPlayer,evParameters,evLeaveParameters};

typedef struct Timer
{
    Time tm;
    Event ev;
} Timer;
# 36 "class/../stateMachine/../xf/xf.h"
typedef struct XF
{
    Timer timerList[8];
    Event eventQueue[12];
    uint8_t in;
    uint8_t out;
} XF;







void XF_init();







_Bool XF_pushEvent(Event ev, _Bool inISR);






Event XF_popEvent(_Bool inISR);
# 74 "class/../stateMachine/../xf/xf.h"
TimerID XF_scheduleTimer(Time tm, Event ev, _Bool inISR);







void XF_unscheduleTimer(TimerID id, _Bool inISR);






void XF_decrementAndQueueTimers();
# 1 "class/../stateMachine/sleepSM.h" 2

void sleepInit();
void sleepSM(Event ev);
void sleepController();
# 4 "class/factory.h" 2

# 1 "class/../stateMachine/touchScreenSM.h" 1

void touchScreenInit();
void touchScreenSM(Event ev);
void touchScreenController();
# 5 "class/factory.h" 2

# 1 "class/paddle.h" 1
# 1 "class/../libraries/lcd_highlevel.h" 1
# 1 "class/paddle.h" 2

typedef struct Paddle
{
    uint16_t x;
    uint16_t y;
    uint16_t w;
    uint16_t h;
    uint16_t color;
}Paddle;
void Paddle_init(struct Paddle* p);
void Paddle_setWidth(struct Paddle* p, uint16_t value);
void Paddle_setHeight(struct Paddle* p, uint16_t value);
void Paddle_setPosX(struct Paddle* p, uint16_t value);
void Paddle_setPosY(struct Paddle* p, uint16_t value);
void Paddle_setColor(struct Paddle* p, uint16_t value);
void Paddle_draw(struct Paddle* p);
# 6 "class/factory.h" 2



void Factory_init();
void Factory_exec();
# 1 "class/factory.c" 2



Paddle p1;
Paddle p2;
Ball b1;
Score s1;
GameParameters g1;

void Factory_init()
{

    XF_init();
    sleepInit();
    Ball_init(&b1);
    Paddle_init(&p1);
    Paddle_init(&p2);
}
void Factory_exec()
{

    Event ev;
    ev = XF_popEvent(0);
    if (ev != NULLEVENT)
    {
        sleepSM(ev);
        touchScreenSM(ev);
    }
}
