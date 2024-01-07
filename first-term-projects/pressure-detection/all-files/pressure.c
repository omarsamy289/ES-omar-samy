#include "pressure.h"

extern unint32 getPressureVal();
extern void Delay(unint32 nCount);


state_definition(pressure_idle) {

pressure_state_id = pressure_idle ;


}

state_definition( pressure_reading) {
pressure_state_id =pressure_reading ;
//getPressureVal() ;
Delay(500000); 
func_pointer_pressure = state_name(pressure_idle) ;
 

}