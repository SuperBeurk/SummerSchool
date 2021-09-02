# 1 "stateMachine/display.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "stateMachine/display.c" 2






# 1 "stateMachine/display.h" 1


# 1 "stateMachine/../xf/xf.h" 1
# 14 "stateMachine/../xf/xf.h"
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
# 15 "stateMachine/../xf/xf.h" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdbool.h" 1 3
# 16 "stateMachine/../xf/xf.h" 2

typedef uint8_t Event;
typedef uint16_t Time;
typedef uint8_t TimerID;

enum myEvents{NULLEVENT,evPress,evRelease,evTimer30,evTimerPos,evOnePlayer,evTwoPlayer,evParameters,evLeaveParameters,evGameUpdate,evNewGame};

typedef struct Timer
{
    Time tm;
    Event ev;
} Timer;
# 36 "stateMachine/../xf/xf.h"
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
# 74 "stateMachine/../xf/xf.h"
TimerID XF_scheduleTimer(Time tm, Event ev, _Bool inISR);







void XF_unscheduleTimer(TimerID id, _Bool inISR);






void XF_decrementAndQueueTimers();
# 3 "stateMachine/display.h" 2

# 1 "stateMachine/../libraries/lcd_highlevel.h" 1
# 11 "stateMachine/../libraries/lcd_highlevel.h"
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
# 50 "stateMachine/../libraries/lcd_highlevel.h"
typedef enum
{
    A_LEFT,
    A_RIGHT,
    A_CENTER
}ALIGN;
# 64 "stateMachine/../libraries/lcd_highlevel.h"
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
# 138 "stateMachine/../libraries/lcd_highlevel.h"
void LCD_ButtonCreate(uint16_t posX, uint16_t posY,
                      uint16_t width, uint16_t height,
                      uint16_t txtColor, uint16_t bgColor,
                      const uint8_t * textOrBmp, FONT_INFO * font,
                      void (*fpPress)(uint8_t), void (* fpReleased)(uint8_t), void (* fpOut)(uint8_t),
                      btn_t * button,
                      uint8_t index);
# 153 "stateMachine/../libraries/lcd_highlevel.h"
void LCD_ButtonDraw(btn_t * button);







void LCD_ButtonUpdate(btn_t * button);
# 175 "stateMachine/../libraries/lcd_highlevel.h"
void LCD_SliderCreate(uint16_t posX, uint16_t posY,
                      uint16_t width, uint16_t height,
                      uint16_t sldColor, uint16_t bgColor, uint16_t borderColor,
                      uint16_t cursorWidth,
                      uint16_t steps,
                      void (* fpPress)(),
                      sld_t * slider);







void LCD_SliderUpdate(sld_t * slider);







void LCD_SliderDraw(sld_t * slider);
# 206 "stateMachine/../libraries/lcd_highlevel.h"
uint8_t LCD_InSlider(sld_t * slider, uint16_t posX, uint16_t posY);
# 215 "stateMachine/../libraries/lcd_highlevel.h"
uint8_t LCD_InButton(btn_t * button, uint16_t posX, uint16_t posY);
# 224 "stateMachine/../libraries/lcd_highlevel.h"
void LCD_Init(void);
# 233 "stateMachine/../libraries/lcd_highlevel.h"
void LCD_Fill(uint16_t color);







void LCD_SetPixel(uint16_t posX,uint16_t posY, uint16_t color);
# 256 "stateMachine/../libraries/lcd_highlevel.h"
void LCD_DrawRect(uint16_t posX1,uint16_t posY1, uint16_t posX2,
  uint16_t posY2,uint8_t fill,uint16_t color);
# 271 "stateMachine/../libraries/lcd_highlevel.h"
void LCD_DrawText(const uint8_t * msg,const FONT_INFO * font, ALIGN align,
        uint16_t posX, uint16_t posY, uint16_t color, uint16_t bg_color);
# 281 "stateMachine/../libraries/lcd_highlevel.h"
uint16_t RGB2LCD(uint8_t * colorTableEntry);
# 295 "stateMachine/../libraries/lcd_highlevel.h"
uint8_t LCD_Bitmap(const uint8_t * bmpPtr, uint16_t posX, uint16_t posY);
# 4 "stateMachine/display.h" 2

void displayInit();
void displaySM(Event ev);
void displayController();
# 7 "stateMachine/display.c" 2

extern const FONT_INFO arialNarrow_12ptFontInfo;

typedef enum state{WELCOME,PARAMETERS,INGAME} state;
enum state displayState;

void displayInit()
{
    displayState=WELCOME;
    displayController();
}
void displaySM(Event ev)
{
   switch(displayState)
    {
        case WELCOME:
            if((ev==evOnePlayer)||(ev==evTwoPlayer))
            {
                displayState=INGAME;
                displayController();
            }
            if(ev==evParameters)
            {
                displayState=PARAMETERS;
                displayController();
            }
            break;
        case PARAMETERS:
            if(ev==evLeaveParameters)
            {
                displayState=WELCOME;
                displayController();
            }
            break;
        case INGAME:
            if(ev==evNewGame)
            {
                displayState=WELCOME;
                displayController();
            }
            break;
        default:
            break;
    }
}
void displayController()
{
    switch(displayState)
    {
        case WELCOME:

            LCD_Fill(0b1111111111111111);
            LCD_DrawText("WELCOME",&arialNarrow_12ptFontInfo,A_CENTER,50,50,0b0000000000000000,0b1111111111111111);
            break;
        case PARAMETERS:

            LCD_Fill(0b1111111111111111);
            LCD_DrawText("PARAMETERS",&arialNarrow_12ptFontInfo,A_CENTER,50,50,0b0000000000000000,0b1111111111111111);
            break;
        case INGAME:



            LCD_Fill(0b1111111111111111);
            LCD_DrawText("INGAME",&arialNarrow_12ptFontInfo,A_CENTER,50,50,0b0000000000000000,0b1111111111111111);
            break;
        default:
            break;
    }
}
