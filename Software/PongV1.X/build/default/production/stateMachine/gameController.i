# 1 "stateMachine/gameController.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "stateMachine/gameController.c" 2






# 1 "stateMachine/gameController.h" 1
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

enum myEvents{NULLEVENT,evPress,evRelease,evTimer30,evTimerPos,evOnePlayer,evTwoPlayer,evParameters,evLeaveParameters};

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
# 1 "stateMachine/gameController.h" 2

void gameControllerInit();
void gameControllerSM(Event ev);
void gameControllerController();
# 7 "stateMachine/gameController.c" 2

typedef enum state{NOGAME,LOCAL,ONLINE} state;
enum state gameControllerState;

void gameControllerInit()
{
    gameControllerState=NOGAME;
    gameControllerController();
}
void gameControllerSM(Event ev)
{
   switch(gameControllerState)
    {
        case NOGAME:

            break;
        case LOCAL:

            break;
        case ONLINE:

            break;
        default:
            break;
    }
}
void gameControllerController()
{
    switch(gameControllerState)
    {
        case NOGAME:
            break;
        case LOCAL:
            break;
        case ONLINE:
            break;
        default:
            break;
    }
}
