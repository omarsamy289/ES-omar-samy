
#include "lifo.h"


//lifo push function thats pushes new data to the stack

lifo_statues lifo_push (lifo_buffer_t* lifo_buff , data_type* value  ){

// if the base pointer or the head pointer points to null means the lifo not intialyzed
	if(!lifo_buff->base || !lifo_buff->head ) return lifo_null ;
// check if the lifo is full by comparing lifo count to lifo length
	if(lifo_buff->count >= lifo_buff->lenght) return lifo_full ;
//assign the new data where the head points to and then increment the head pointer position
	*(lifo_buff->head) = *value ;
	lifo_buff->head ++ ;
//  increment the stack count when pushes new data
	lifo_buff->count ++ ;
// return lifo_no_error when lifo push succeeded
	return lifo_no_error ;


}


lifo_statues lifo_pop (lifo_buffer_t* lifo_buff , data_type * value ){
	// if the base pointer or the head pointer points to null means the lifo not intialyzed
	if(!lifo_buff->base || !lifo_buff->head ) return lifo_null ;
// check if the lifo stack is empty
	if(lifo_buff->count == 0 ) return lifo_empty ;
	lifo_buff->head -- ;
	*value = *(lifo_buff->head) ;
	lifo_buff->count -- ;
	// return lifo_no_error when lifo pop succeeded
	return lifo_no_error ;

}


lifo_statues lifo_init (lifo_buffer_t* lifo_buff , data_type * buffer  ,  unint32 lenght){
	if(buffer == NULL ) return lifo_null ;
	lifo_buff->base = buffer ;
	lifo_buff->head = buffer ;
	lifo_buff->lenght = lenght ;
	lifo_buff->count =0 ;
	return lifo_no_error ;
}
