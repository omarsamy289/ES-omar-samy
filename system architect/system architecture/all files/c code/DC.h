/*
 * CA.h
 *
 *  Created on: Dec 12, 2023
 *      Author: omar
 */

#ifndef DC_H_
#define DC_H_
#include "state.h"


//prototype of the DC_busy and dc_idle states

state_definition(DC_idle);
state_definition(DC_busy);

// prototype of the initialization function of the DC motor

void DC_init () ;

//this pointer to function that takes nothing and rerurn void and it's extern to be seen in main.c
extern void (*DC_state)() ;




#endif /* CA_H_ */
