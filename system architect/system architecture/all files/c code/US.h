/*
 * US.h
 *
 *  Created on: Dec 12, 2023
 *      Author: omar
 */

#ifndef US_H_
#define US_H_
#include "state.h"



// prototype of the initialization function of the ultra-sonic
void US_init () ;

//prototype of the us_busy state
state_definition(US_busy);


//this pointer to function that takes nothing and rerurn void and it's extern to be seen in main.c
extern void (*US_state)() ;




#endif /* US_H_ */
