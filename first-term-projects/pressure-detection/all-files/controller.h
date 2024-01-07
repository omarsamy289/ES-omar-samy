#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "state.h"


void Delay(unint32 nCount);


void GPIO_INITIALIZATION ();


// pointer to unction to move between the states
 void (*func_pointer_controller)() ;


enum {
    controller_idle,
    controller_busy
}controller_state_id;

       


state_definition(controller_idle) ;
state_definition(controller_busy) ;









#endif