#ifndef FIFO_H_
#define FIFO_H_
#include "stdio.h"
#include "mod_int_standard.h"
#define item_type unint8




typedef struct {
	unsigned int length ;
	unsigned int count ;
	item_type* base ;
	item_type* head ;
	item_type* tail ;
}fifo_buffer_t;


// user-defined data type for diffrent fifo status
typedef enum  {
	fifo_no_error ,
	fifo_full,
	fifo_null,
	fifo_empty
}fifo_status;

// protypes of the functions declared in fifo.c
fifo_status fifo_enqueue (fifo_buffer_t* fifo_buff , item_type* item  );
fifo_status fifo_dequeue (fifo_buffer_t* fifo_buff , item_type* item  );
fifo_status fifo_init (fifo_buffer_t* fifo_buff , item_type* buffer  ,  unsigned int lenght);
fifo_status fifo_is_full (fifo_buffer_t* fifo_buff) ;
void fifo_print (fifo_buffer_t* fifo_buff) ;



#endif
