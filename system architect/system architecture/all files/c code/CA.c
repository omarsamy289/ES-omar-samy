/*
 * CA.c
 *
 *  Created on: Dec 12, 2023
 *      Author: omar
 */

#include "CA.h"
int CA_speed =  0 ;
int CA_distance =  0 ;
int CA_threshold =  50 ;

// enum to describe the the state id
enum {
	CA_waiting,
	CA_driving
}CA_state_id;

// pointer to function that takes nothing and return void
void (*CA_state)() ;

// the implementation of the connetion function between US module and the CA module to get distance
// the US module
void US_set_distance (int di) {

	CA_distance = di ;
// check if the distance set by the ultra sonic is less than or bigger than the threshold to further use
// to jump to the correct state
(CA_distance <= CA_threshold ) ? (CA_state = state_name(CA_waiting)) : (CA_state =state_name(CA_driving));



printf("(US ---> CA) US set distance at : %d \n ", CA_distance ) ;
fflush(stdout) ; fflush(stdin) ;

}


// state that sets the speed to 0 when CA_distance <= CA_threshold
state_definition(CA_waiting){
// state id
 CA_state_id = CA_waiting ;
 printf(">>> state CA waiting .....distance :%d....speed:%d \n" , CA_distance , CA_speed) ;
 		fflush(stdout) ; fflush(stdin) ;
// state action
CA_speed =  0;
DC_get_speed (CA_speed) ;

}


// state that sets the speed to 30 when CA_distance > CA_threshold

state_definition(CA_driving){

	// state id
	CA_state_id = CA_driving ;
	printf(">>> state CA driving .....distance :%d....speed:%d \n" , CA_distance , CA_speed) ;
		fflush(stdout) ; fflush(stdin) ;
	// state action
	CA_speed =  30;
	DC_get_speed (CA_speed) ;

}



