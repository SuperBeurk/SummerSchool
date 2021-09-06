# 1 "class/score.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "class/score.c" 2
# 1 "class/score.h" 1


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
# 3 "class/score.h" 2

# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdio.h" 1 3
# 10 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdio.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\features.h" 1 3
# 10 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdio.h" 2 3
# 24 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdio.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 1 3





typedef void * va_list[1];




typedef void * __isoc_va_list[1];
# 122 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned size_t;
# 137 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long ssize_t;
# 246 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long off_t;
# 399 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef struct _IO_FILE FILE;
# 24 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdio.h" 2 3
# 52 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdio.h" 3
typedef union _G_fpos64_t {
 char __opaque[16];
 double __align;
} fpos_t;

extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;





FILE *fopen(const char *restrict, const char *restrict);
FILE *freopen(const char *restrict, const char *restrict, FILE *restrict);
int fclose(FILE *);

int remove(const char *);
int rename(const char *, const char *);

int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
void clearerr(FILE *);

int fseek(FILE *, long, int);
long ftell(FILE *);
void rewind(FILE *);

int fgetpos(FILE *restrict, fpos_t *restrict);
int fsetpos(FILE *, const fpos_t *);

size_t fread(void *restrict, size_t, size_t, FILE *restrict);
size_t fwrite(const void *restrict, size_t, size_t, FILE *restrict);

int fgetc(FILE *);
int getc(FILE *);
int getchar(void);
int ungetc(int, FILE *);

int fputc(int, FILE *);
int putc(int, FILE *);
int putchar(int);

char *fgets(char *restrict, int, FILE *restrict);

char *gets(char *);


int fputs(const char *restrict, FILE *restrict);
int puts(const char *);

#pragma printf_check(printf) const
#pragma printf_check(vprintf) const
#pragma printf_check(sprintf) const
#pragma printf_check(snprintf) const
#pragma printf_check(vsprintf) const
#pragma printf_check(vsnprintf) const

int printf(const char *restrict, ...);
int fprintf(FILE *restrict, const char *restrict, ...);
int sprintf(char *restrict, const char *restrict, ...);
int snprintf(char *restrict, size_t, const char *restrict, ...);

int vprintf(const char *restrict, __isoc_va_list);
int vfprintf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsprintf(char *restrict, const char *restrict, __isoc_va_list);
int vsnprintf(char *restrict, size_t, const char *restrict, __isoc_va_list);

int scanf(const char *restrict, ...);
int fscanf(FILE *restrict, const char *restrict, ...);
int sscanf(const char *restrict, const char *restrict, ...);
int vscanf(const char *restrict, __isoc_va_list);
int vfscanf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsscanf(const char *restrict, const char *restrict, __isoc_va_list);

void perror(const char *);

int setvbuf(FILE *restrict, char *restrict, int, size_t);
void setbuf(FILE *restrict, char *restrict);

char *tmpnam(char *);
FILE *tmpfile(void);




FILE *fmemopen(void *restrict, size_t, const char *restrict);
FILE *open_memstream(char **, size_t *);
FILE *fdopen(int, const char *);
FILE *popen(const char *, const char *);
int pclose(FILE *);
int fileno(FILE *);
int fseeko(FILE *, off_t, int);
off_t ftello(FILE *);
int dprintf(int, const char *restrict, ...);
int vdprintf(int, const char *restrict, __isoc_va_list);
void flockfile(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);
int putc_unlocked(int, FILE *);
int putchar_unlocked(int);
ssize_t getdelim(char **restrict, size_t *restrict, int, FILE *restrict);
ssize_t getline(char **restrict, size_t *restrict, FILE *restrict);
int renameat(int, const char *, int, const char *);
char *ctermid(char *);







char *tempnam(const char *, const char *);
# 4 "class/score.h" 2

# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\string.h" 1 3
# 25 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\string.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 411 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef struct __locale_struct * locale_t;
# 25 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\string.h" 2 3


void *memcpy (void *restrict, const void *restrict, size_t);
void *memmove (void *, const void *, size_t);
void *memset (void *, int, size_t);
int memcmp (const void *, const void *, size_t);
void *memchr (const void *, int, size_t);

char *strcpy (char *restrict, const char *restrict);
char *strncpy (char *restrict, const char *restrict, size_t);

char *strcat (char *restrict, const char *restrict);
char *strncat (char *restrict, const char *restrict, size_t);

int strcmp (const char *, const char *);
int strncmp (const char *, const char *, size_t);

int strcoll (const char *, const char *);
size_t strxfrm (char *restrict, const char *restrict, size_t);

char *strchr (const char *, int);
char *strrchr (const char *, int);

size_t strcspn (const char *, const char *);
size_t strspn (const char *, const char *);
char *strpbrk (const char *, const char *);
char *strstr (const char *, const char *);
char *strtok (char *restrict, const char *restrict);

size_t strlen (const char *);

char *strerror (int);
# 65 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\string.h" 3
char *strtok_r (char *restrict, const char *restrict, char **restrict);
int strerror_r (int, char *, size_t);
char *stpcpy(char *restrict, const char *restrict);
char *stpncpy(char *restrict, const char *restrict, size_t);
size_t strnlen (const char *, size_t);
char *strdup (const char *);
char *strndup (const char *, size_t);
char *strsignal(int);
char *strerror_l (int, locale_t);
int strcoll_l (const char *, const char *, locale_t);
size_t strxfrm_l (char *restrict, const char *restrict, size_t, locale_t);




void *memccpy (void *restrict, const void *restrict, int, size_t);
# 5 "class/score.h" 2

# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdlib.h" 1 3
# 21 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdlib.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 18 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long int wchar_t;
# 21 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c99\\stdlib.h" 2 3


int atoi (const char *);
long atol (const char *);
long long atoll (const char *);
double atof (const char *);

float strtof (const char *restrict, char **restrict);
double strtod (const char *restrict, char **restrict);
long double strtold (const char *restrict, char **restrict);



long strtol (const char *restrict, char **restrict, int);
unsigned long strtoul (const char *restrict, char **restrict, int);
long long strtoll (const char *restrict, char **restrict, int);
unsigned long long strtoull (const char *restrict, char **restrict, int);

int rand (void);
void srand (unsigned);

          void abort (void);
int atexit (void (*) (void));
          void exit (int);
          void _Exit (int);

void *bsearch (const void *, const void *, size_t, size_t, int (*)(const void *, const void *));

__attribute__((nonreentrant)) void qsort (void *, size_t, size_t, int (*)(const void *, const void *));

int abs (int);
long labs (long);
long long llabs (long long);

typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;
typedef struct { long long quot, rem; } lldiv_t;

div_t div (int, int);
ldiv_t ldiv (long, long);
lldiv_t lldiv (long long, long long);

typedef struct { unsigned int quot, rem; } udiv_t;
typedef struct { unsigned long quot, rem; } uldiv_t;
udiv_t udiv (unsigned int, unsigned int);
uldiv_t uldiv (unsigned long, unsigned long);





size_t __ctype_get_mb_cur_max(void);
# 6 "class/score.h" 2

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
# 1 "class/score.c" 2

extern const FONT_INFO arialNarrow_12ptFontInfo;
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
    sprintf(s->str,"%d",s->homeScore);
    LCD_DrawText(s->str,&arialNarrow_12ptFontInfo,A_LEFT,0,0,0b1111111111111111,0b0000000000000000);
    sprintf(s->str,"%d",s->awayScore);
    LCD_DrawText(s->str,&arialNarrow_12ptFontInfo,A_RIGHT,239,0,0b1111111111111111,0b0000000000000000);
}
