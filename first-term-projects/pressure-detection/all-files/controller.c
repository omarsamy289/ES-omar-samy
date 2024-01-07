#include "controller.h"

extern void start_alarm() ;
extern void stop_alarm() ;
//extern void store_flash() ;

void GPIO_INITIALIZATION (){
	SET_BIT(APB2ENR, 2);
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;
}


vunint32 pressure_val ;
vunint32 threshold = 20 ;

void Delay(unint32 nCount)
{
	for(; nCount != 0; nCount--);
}

unint32  getPressureVal(){

	return (GPIOA_IDR & 0xFF);
}





state_definition(controller_idle) {

controller_state_id = controller_idle ;
stop_alarm() ;
//state_definition(alarm_stop);
state_definition(pressure_reading) ;
pressure_val =  getPressureVal() ;
//state_definition(flash_busy) ;
//store_flash() ;
(pressure_val > threshold )? (func_pointer_controller = state_name (controller_busy)) : (func_pointer_controller = state_name(controller_idle)) ;

}


state_definition(controller_busy) {
controller_state_id = controller_busy ;
 state_definition(alarm_start) ;
 start_alarm() ;
 state_definition(flash_busy) ;
 Delay(500000);
//state_definition( pressure_reading) ;
state_definition(pressure_reading) ;
pressure_val =  getPressureVal() ;
//state_definition(flash_busy) ;
//store_flash() ;
 (pressure_val > threshold) ? (func_pointer_controller = state_name (controller_busy)) : (func_pointer_controller = state_name(controller_idle)) ;
}