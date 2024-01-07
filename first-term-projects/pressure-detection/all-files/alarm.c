#include "alarm.h"

void Set_Alarm_actuator(int i){
	func_pointer_alarm = state_name(alarm_idle) ;
    if (i == 1){
		SET_BIT(GPIOA_ODR,13);
	}
	else if (i == 0){
		RESET_BIT(GPIOA_ODR,13);
	}
}

void start_alarm() {
Set_Alarm_actuator(0) ;

}

void stop_alarm() {

Set_Alarm_actuator(1) ;

}

state_definition(alarm_idle) {
 alarm_state_id = alarm_idle ;
 func_pointer_alarm = state_name(alarm_idle);
}

state_definition(alarm_start) {
    alarm_state_id= alarm_start ;
Set_Alarm_actuator(0) ;
func_pointer_alarm = state_name(alarm_start);
}


state_definition(alarm_stop) {
    alarm_state_id = alarm_stop ;
Set_Alarm_actuator(1) ;
func_pointer_alarm = state_name(alarm_idle);

}
