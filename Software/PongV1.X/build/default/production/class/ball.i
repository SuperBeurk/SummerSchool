# 1 "class/ball.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "class/ball.c" 2
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
# 5 "class/ball.h" 2

typedef struct Ball
{
    uint16_t x;
    uint16_t y;
    uint16_t oldx;
    uint16_t oldy;
    int16_t dx;
    int16_t dy;
}Ball;




void Ball_init(struct Ball* b);




void Ball_Update(struct Ball* b);




void Ball_draw(struct Ball* b);
# 1 "class/ball.c" 2





void Ball_init(struct Ball* b)
{
    b->x = 90;
    b->y = 150;
    b->oldx=20;
    b->oldy=20;
    b->dx = 0;
}




void Ball_Update(struct Ball* b)
{
    b->x=b->x+b->dx;
    b->y=b->y+b->dy;
}




void Ball_draw(struct Ball* b)
{
    LCD_DrawRect(b->oldx-8,b->oldy-8,b->oldx+8,b->oldy+8,1,0b0000000000000000);
    b->oldx=b->x;
    b->oldy=b->y;
    LCD_DrawRect(b->x-8,b->y-8,b->x+8,b->y+8,1,0b1111100000000000);
}
