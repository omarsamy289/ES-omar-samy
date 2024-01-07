#include "state.h"
#include "pressure.h"
#include "alarm.h"
#include "controller.h"




void setup() {
// init all the drivers
// init all the stat pointers 
GPIO_INITIALIZATION();
func_pointer_controller = state_name (controller_idle) ;
//func_pointer_flash = state_name(flash_idle) ;
func_pointer_alarm = state_name(alarm_idle) ; 
func_pointer_pressure = state_name(pressure_idle) ;
// init all the modules
Set_Alarm_actuator(1) ;
// 



}
/*
the method to store values of pressure when changes in real time and storing it the .pressure_vals section 
in the soc flash ( and only when it dectecs changes in the values)
>>>>
if (current_value != past_value ) { 
       
 value_storage [count] =current_value  ;

past_value = current_value ;
    }
 ++count ;

*/
unint32 value_storage [100] __attribute__ ((section(".pressure_vals"))) ;
vunint32* flash_ptr ;
vunint32 current_value ;
vunint32 past_value ;
vunint32 count =0 ;
void main (){
	
	setup() ;
	while (1)
	{
	func_pointer_controller() ;
	*flash_ptr  = getPressureVal() ;
 current_value = *flash_ptr ;
if (count == 100 ) count = 0 ;
if (current_value != past_value ) { 
       
 value_storage [count] =current_value  ;

past_value = current_value ;
++count ;
    }
 

	}

}
