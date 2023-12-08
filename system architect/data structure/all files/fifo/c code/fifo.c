#include "fifo.h"
/*
circular fifo queue declerations .
 omar samy @2023
 */

// the intialyzation of the fifo queue
fifo_status fifo_init (fifo_buffer_t* fifo_buff , item_type* buffer  ,  unsigned int length) {
	// if the the buffer is not inttiialyzed means the fifo can't be intialyzed
	if ( buffer == NULL ) return fifo_null ;
	// set the fifo length to a length entered by the user
	fifo_buff->length = length ;
	// set the count to 0 to further increment or decremt in enqueue or dequeue
	fifo_buff->count =0 ;
	// head and tail and base at first point the very first addres of the buffer
	fifo_buff->head =buffer ;
	fifo_buff->tail =buffer ;
	fifo_buff->base =buffer ;
	// return fifo no error when successded to intialyzed
	return fifo_no_error ;
}


fifo_status fifo_enqueue (fifo_buffer_t* fifo_buff , item_type* item  ) {
	//
	// check if any of those pointers point to null means that the fifo is not intialyzed and not valid
	if (!fifo_buff->head || !fifo_buff->tail || !fifo_buff->base ) return fifo_null ;
	// check if the fifo is full (no empty slots ) means head and tail point to the same address
	// if ( fifo_buff->head == fifo_buff->tail)   return fifo_full ;
	if ((fifo_is_full(fifo_buff))== fifo_full) return fifo_full ;
// assign item to the head last position before increment the head pointer
	*(fifo_buff->head) = *item ;
//
	fifo_buff->count ++ ;
	//implementation of the circular fifo mechanism
	// if fifo head at the same address of the base and there is empty slot at the start of the buffer then
	// make the  head point the very start of the queue to reuse the slot and if there is no empty slots the program
	// will return fifo_full in the last if condition
if ( (fifo_buff->head == (fifo_buff->base + (fifo_buff->length * sizeof(item_type)))))
	{
	fifo_buff->head = fifo_buff->base ;
	}else {
	fifo_buff->head ++ ;
}

	// return fifo no error when successded to enqueue
	return fifo_no_error ;
}




fifo_status fifo_dequeue (fifo_buffer_t* fifo_buff , item_type* item  ) {

	// check if any of those pointers point to null means that the fifo is not intialyzed and not valid
		if (!fifo_buff->head || !fifo_buff->tail || !fifo_buff->base ) return fifo_null ;
	//
	if ( fifo_buff->count == 0 ) return fifo_empty ;
	//
*item = *(fifo_buff->tail) ;
//
fifo_buff->count --;

//implementation of the circular fifo mechanism
	// if fifo tail at the same address of the base and there is empty slot at the start of the buffer then
	// make the  head point the very start of the queue to reuse the slot and if there is no empty slots the program
	// will return fifo_full in the last if condition
if ( fifo_buff->tail == (fifo_buff->base + (fifo_buff->length * sizeof(item_type))))
	{
	fifo_buff->tail = fifo_buff->base ;
	}else {
	fifo_buff->tail ++ ;
}


// return fifo no error when successded to dequeue

	return fifo_no_error ;
}



fifo_status fifo_is_full (fifo_buffer_t* fifo_buff) {
	// check if any of those pointers point to null means that the fifo is not intialyzed and not valid
	if (!fifo_buff->head || !fifo_buff->tail || !fifo_buff->base ) return fifo_null ;
	// check if the fifo count = length means the fifo is full
	if ( fifo_buff->count >= fifo_buff->length ) return fifo_full ;

	return fifo_no_error ;

}

void fifo_print (fifo_buffer_t* fifo_buff) {
	item_type* temp ;
	int i ;
	if(fifo_buff-> count == 0 ) {
	printf ("fifo is empty ") ;
	} else {
		temp = fifo_buff->tail;
		printf ("==========fifo start =========\n") ;

		for (i=0 ; i <fifo_buff->count ; i++) {

			printf("\t fifo (%x) \n" , *temp) ;
					temp++ ;
		}
		printf ("==========fifo end =========\n") ;

	}


}








