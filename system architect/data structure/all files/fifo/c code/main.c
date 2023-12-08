#include "fifo.h"

fifo_buffer_t fifo_1 ;
#define width 5

item_type buffer_1[width] ;

void main () {
item_type i , temp =0;
	 if ( fifo_init ( &fifo_1 ,  &buffer_1 , 5) == fifo_no_error )
	 {
		 printf("fifo init done \n") ;
		 fflush(stdout) ; fflush(stdin) ;
	 }

	for (i=0 ; i<7 ; i++) {
		printf("fifo enqueue(%x) \n" , i) ;
				 fflush(stdout) ; fflush(stdin) ;
		if ( fifo_enqueue (&fifo_1, &i ) == fifo_no_error ) {

			printf("fifo success\n") ;
							 fflush(stdout) ; fflush(stdin) ;
		} else {

			printf("fifo failed\n") ;
				 fflush(stdout) ; fflush(stdin) ;
		}
	}
	 fifo_print (&fifo_1);


	 if ( fifo_dequeue (&fifo_1  , &temp  )  == fifo_no_error ) {
		 		  printf("fifo dequeue(%x) done  \n" ,  temp) ;
		 		  				 fflush(stdout) ; fflush(stdin) ;
		 	  }

	  if ( fifo_dequeue (&fifo_1  , &temp  )  == fifo_no_error ) {
	 		  printf("fifo dequeue(%x) done  \n" ,  temp) ;
	 		  				 fflush(stdout) ; fflush(stdin) ;
	 	  }

		 fifo_print (&fifo_1);


}
