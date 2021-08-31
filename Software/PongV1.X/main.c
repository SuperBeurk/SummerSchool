/*
 * File:   main.c
 * Author: sebastie.metral
 *
 * Created on 27. août 2021, 10:51
 */


#include <xc.h>
#include "configuration_bits.c"
#include "xf/xf.h"
#include "stateMachine/sleepSM.h"
#include "stateMachine/touchScreenSM.h"
#include "class/factory.h"

void main(void) 
{
    Factory_init();
    while(true)
    {
        Factory_exec();
    }
    return;
}
