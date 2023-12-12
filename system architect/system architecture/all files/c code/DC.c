/*
 * DC.c
 *
 *  Created on: Dec 12, 2023
 *      Author: omar
 */

#include "DC.h"

int DC_speed =  0 ;


// enum to describe the the state id

enum {
	DC_idle,
	DC_busy
}DC_state_id;

// pointer to function that takes nothing and return void
void (*DC_state)() ;


// function to get the speed from CA module to be sent to the DC motor module
void DC_get_speed (int sp ) {

	DC_speed = sp ;

	DC_state = state_name(DC_busy) ;

	printf("(CA ---> DC) DC get speed at : %d \n ", DC_speed ) ;
	fflush(stdout) ; fflush(stdin) ;

}


//the implementation of the  initialization function of DC motor

void DC_init () {

	printf(" DC init ...... \n" ) ;
	fflush(stdout) ; fflush(stdin) ;


}

// state DC idle : in this state speed should be idle

state_definition(DC_idle){

	// state id
	DC_state_id = DC_idle ;
	// state action
	// call PWM module to make speed = DC_speed
	printf(">>> stat DC idle .........speed:%d \n" , DC_speed) ;
	fflush(stdout) ; fflush(stdin) ;
}




// state DC busy means that the dc motor is in the driving mode and the speed should be at some value
state_definition(DC_busy){
// state id
 DC_state_id = DC_busy ;
 printf(">>> state DC busy .........speed:%d \n" , DC_speed) ;
 fflush(stdout) ; fflush(stdin) ;
// state action
 DC_state = state_name(DC_idle) ;

}



