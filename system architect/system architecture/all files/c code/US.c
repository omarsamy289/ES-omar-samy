/*
 * US.c
 *
 *  Created on: Dec 12, 2023
 *      Author: omar
 */

#include "US.h"

int US_distance =  0 ;
// enum to describe the the state id
enum {
	US_busy,
}US_state_id;

// pointer to function that takes nothing and return void used to set the us state
void (*US_state)() ;
int US_get_rondom(int l , int r , int count ) ;


//the implementation of the  initialization function of the ultra-sonic
void US_init ()
{

printf(" US init ...... \n" ) ;
fflush(stdout) ; fflush(stdin) ;
}


// state us busy is the only state in us block used to set the distance and send it to CA block via
//US_set_distance function
state_definition(US_busy){

	// state id
	US_state_id =  US_busy;
	// state action

	US_distance =  US_get_rondom(45 , 55 ,  1 ) ;
	US_set_distance(US_distance) ;
//
	printf(">>> state US busy .........distance:%d \n" , US_distance) ;
	fflush(stdout) ; fflush(stdin) ;
	US_state = state_name(US_busy) ;
}


// function to generate rondom numbers within range
int US_get_rondom(int l , int r , int count ){

int i ;
for ( i = 0 ; i < count ; i++) {
	int rand_num  = ( rand() % (r - l + 1) ) + l;
	return rand_num ;

}


}


