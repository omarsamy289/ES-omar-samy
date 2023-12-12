/*
 * main.c
 *
 *  Created on: Dec 12, 2023
 *      Author: omar
 */
#include "CA.h"
#include "DC.h"
#include "US.h"

void setup() {
// init all drivers
// init ISR
// init HAL (US, DC...)
// init block
	 US_init () ;
  	DC_init () ;
//init all of the state pointers
	CA_state = state_name(CA_waiting) ;
	US_state = state_name(US_busy) ;
	DC_state = state_name(DC_idle) ;

}

void main() {

	setup();
volatile int i ;
	while(1){
		US_state();
		CA_state();
		DC_state();
		for(i=0 ; i<1000 ; i++) ;
	}
}
