#include "lifo.h"



data_type buffer[width];



void main () {

	lifo_buffer_t lifo_1  ;

	lifo_init(&lifo_1 , buffer , width ) ;

	unint32 i ;
	unint32 temp = 0 ;
	for (i = 0 ; i <width ; i++) {

		if ( lifo_push(&lifo_1 ,&i ) == lifo_no_error ) {
		//	 lifo_push(&lifo_1 ,&buffer[i] );
			printf ( "\nlifo push : %d \n" ,i ) ;
			fflush(stdout) ;fflush(stdin) ;
		}


	}

	for (i = 0 ; i <width ; i++) {

		if ( lifo_pop(&lifo_1 ,&temp ) == lifo_no_error ) {
		//	lifo_pop(&lifo_1 ,&buffer[i] ) ;
			printf ( "\nlifo pop : %d\n" , temp) ;
			fflush(stdout) ;fflush(stdin) ;
		}


	}






}
