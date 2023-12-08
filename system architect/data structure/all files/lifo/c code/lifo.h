#ifndef LIFO_H_
#define LIFO_H_
#include "stdio.h"
#include "mod_int_standard.h"
#define data_type unint32
#define width 5

/* the lifo buffer struct
 * lenght : the lenght of the buffer we further use to set the lengths
 * base poiter : point to the
 *  head pointer : points to
 *  count : increment when  pushing data and decrement when popping data
 *
 */
typedef struct {
	unint32 lenght ;
	data_type* base ;
	data_type* head ;
	unint32 count ;

}lifo_buffer_t;


// user defined  data type to know the statues of every function after it's implementation
typedef enum  {
	lifo_no_error ,
	lifo_full,
	lifo_null,
	lifo_empty
}lifo_statues ;

lifo_statues lifo_push (lifo_buffer_t* lifo_buff  , data_type* value  );
lifo_statues lifo_pop (lifo_buffer_t* lifo_buff , data_type* value  );
lifo_statues lifo_init (lifo_buffer_t* lifo_buff ,data_type* buffer  ,  unint32 lenght);




#endif
