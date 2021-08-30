/*
 * File:   main.c
 * Author: sebastie.metral
 *
 * Created on 27. août 2021, 10:51
 */


#include <xc.h>
#include "xf.h"
#include "sleep.h"
#include "touchScreen.h"
enum myEvents{nullEvent,evPress,evRelease,evTimer30,evTimer60};

void init()
{
    XF_init();
    sleepInit();
    touchScreenInit();
}
void main(void) {
    init();
    Event ev=NULLEVENT;
    while(true)
    {
        ev=XF_popEvent(false);
        if(ev!=NULLEVENT)
        {
            sleepSM(ev);
            touchScreenSM(ev);
        }
    }
    return;
}
