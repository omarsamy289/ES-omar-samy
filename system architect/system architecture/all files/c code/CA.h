/*
 * CA.h
 *
 *  Created on: Dec 12, 2023
 *      Author: omar
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"


//prototype of the CA_waiting and CA_waiting states

state_definition(CA_waiting);
state_definition(CA_waiting);

//this pointer to function that takes nothing and rerurn void and it's extern to be seen in main.c

extern void (*CA_state)() ;

#endif /* CA_H_ */
