/******************************************************************************/
/* FILENAME	: xf.h                                                            */
/*----------------------------------------------------------------------------*/
/* GOAL		  : Offers the femto XF functions                                   */
/*----------------------------------------------------------------------------*/
/* AUTHOR   : Medard Rieder / Pascal Sartoretti                               */
/*----------------------------------------------------------------------------*/
/* DATE:    : original (Medard Rieder 08.2011)                                */
/*            corrections & simplified (Pascal Sartoretti 06.2016)            */
/******************************************************************************/
#ifndef XF_DEF
#define XF_DEF

#include <stdint.h>         // usage of standard types
#include <stdbool.h>        // usage of boolean types

typedef  uint8_t  Event;    // event type
typedef  uint16_t Time;     // time type
typedef  uint8_t  TimerID;  // identifier of timer (position in buffer)

//------------------------------------------------------------------------------
//All event for this project
//------------------------------------------------------------------------------
//0.NULLEVENT
//1.evPress             Event for detect a press on LCD
//2.evRelease           Event for detect a release on LCD
//3.evTimer30           Timer for no touch and turn pic in sleep mode   (20s)
//4.evTimerpos          Timer for recalcul a position                   (90ms)
//5.evOnePlayer         Event for play in 1 player mode
//6.evTwoPlayer         Event for play in 2 player mode
//7.evParameters        Event for enter in parameters mode
//8.evLeaveParam        Event for leave parameters mode
//9.evEndGame           Event for loosing a game
//10.evGameUpdate       Timer for updating game element                 (50ms)
//11.evRedrawPaddle1    Event for redraw the local paddle
//12.evRedrawPaddle2    Event for redraw the IA/online paddle
//13.evRedrawBall       Event for redraw the ball
//14.evRedrawScore      Event for redraw the score
//15.evNewGame          Event for playing a new game
//------------------------------------------------------------------------------
enum myEvents{NULLEVENT,evPress,evRelease,evTimer30,evTimerPos,evOnePlayer,evTwoPlayer,evParameters,evLeaveParam,evEndGame,evGameUpdate,evRedrawPaddle1,evRedrawPaddle2,evRedrawBall,evRedrawScore,evNewGame};

typedef struct Timer        // timer structure
{
    Time tm;                // time
    Event ev;               // event to post
} Timer;
/*----------------------------------------------------------------------------*/
/* depending on usage, change MAXTIMER and MAXEVENT                           */
/*----------------------------------------------------------------------------*/
#define MAXTIMER 8          // number of timers in our system
#define MAXEVENT 12         // number of events in our system 
#define NULLTIMER 0         // no value for time

/*----------------------------------------------------------------------------*/
typedef struct XF           // the XF structure
{
    Timer timerList[MAXTIMER];    // the timers
    Event eventQueue[MAXEVENT];   // the events
    uint8_t in;                   // the events in pointer
    uint8_t out;                  // the events out pointer
} XF;

/******************************************************************************/
/* FUNCTION     : Init the XF structure                                       */
/* INPUT        : -                                                           */
/* OUTPUT       : -                                                           */
/* COMMENTS     : Have to be called once                                      */
/******************************************************************************/
void XF_init();
/******************************************************************************/
/* FUNCTION     : Push an event on the events queue                           */
/* INPUT        : ev - the event number (not 0)                               */
/*                inISR - (true if called in an ISR, else false)              */
/* OUTPUT       : return false if the queue was full, else true               */
/* COMMENTS     : -                                                           */
/******************************************************************************/
bool XF_pushEvent(Event ev, bool inISR);
/******************************************************************************/
/* FUNCTION     : Pop an event on the events queue                            */
/* INPUT        : inISR - (true if called in an ISR, else false)              */
/* OUTPUT       : return the next waiting event if any, else 0                */
/* COMMENTS     : -                                                           */
/******************************************************************************/
Event XF_popEvent(bool inISR);
/******************************************************************************/
/* FUNCTION     : Post a timer in timers queue                                */
/* INPUT        : tm - time before event arrives                              */
/*                ev - event to post                                          */
/*                inISR - (true if called in an ISR, else false)              */
/* OUTPUT       : return the timer Id used                                    */
/* COMMENTS     : -                                                           */
/******************************************************************************/
TimerID XF_scheduleTimer(Time tm, Event ev, bool inISR);
/******************************************************************************/
/* FUNCTION     : Remove a timer in timers queue                              */
/* INPUT        : id - the timer id to remove                                 */
/*                inISR - (true if called in an ISR, else false)              */
/* OUTPUT       : -                                                           */
/* COMMENTS     : -                                                           */
/******************************************************************************/
void XF_unscheduleTimer(TimerID id, bool inISR);
/******************************************************************************/
/* FUNCTION     : Decrement timers to post events if time elapsed             */
/* INPUT        : -                                                           */
/* OUTPUT       : -                                                           */
/* COMMENTS     : This function has to be called from the timer ISR           */
/******************************************************************************/
void XF_decrementAndQueueTimers();

#endif

