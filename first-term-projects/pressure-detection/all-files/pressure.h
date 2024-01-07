#ifndef PRESSURE_H_
#define PRESSURE_H_
#include "state.h"

//
 void (*func_pointer_pressure)() ;


enum {
    pressure_idle,
    pressure_reading
}pressure_state_id;

       


state_definition(pressure_idle) ;
state_definition( pressure_reading) ;













#endif