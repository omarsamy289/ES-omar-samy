#ifndef ALARM_H_
#define ALARM_H_
#include "state.h"

enum {
    alarm_start,
    alarm_stop,
    alarm_idle
}alarm_state_id;

// pointer to unction to move between the states
 void (*func_pointer_alarm)() ;

void start_alarm() ;
void stop_alarm() ;
state_definition(alarm_idle) ;
state_definition(alarm_start) ;
state_definition(alarm_stop) ;

#endif