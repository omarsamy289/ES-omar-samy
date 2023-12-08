 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <a href=""><img src="https://iili.io/JIkXu7j.md.png" alt="771" border="0"></a><br /><a target='_blank' href='https://iili.io/JIkXu7j.md.png'>



# Data structure ( LIFO - FIFO -LINKED LIST ) 


[![MIT License](https://img.shields.io/badge/LIFO%20FILES%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/system%20architect/data%20structure/all%20files/lifo)
[![MIT License](https://img.shields.io/badge/FIFO%20FILES%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/system%20architect/data%20structure/all%20files/fifo)
[![MIT License](https://img.shields.io/badge/LINKED%20LIST%20FILES%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/system%20architect/data%20structure/all%20files/linked%20list/c%20code)



[![MIT License](https://img.shields.io/badge/go%20back%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main)


# 1- LIFO : STACK data structure 


## lifo.h 

prototype of the lifo functions and the lifo buffer structure and the statues enumuration
> **Note**
 mod int standard library is also included in this project to make use of 
>

```c code

#ifndef LIFO_H_
#define LIFO_H_
#include "stdio.h"
#include "mod_int_standard.h"
// width and data type are defined here for more generalization
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


```


## lifo.c

the implementation of the lifo functions

```c code
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


```



### main.c 

the main program :

```c code

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

```

### output snapshot
[![JIkXwQI.md.png](https://iili.io/JIkXwQI.md.png)](https://freeimage.host/i/JIkXwQI)


## mod_int_standard.h
#### this header files contais the modified int standard library for refrence 

```c code
// header guards
#ifndef MOD_INT_STANDARD_H_
#define MOD_INT_STANDARD_H_

#include "stdint.h"
#include "stdbool.h"

/* universal modified standard integer library
  * Compatible with AUTOSAR Platform Types
  * according to a 32 bit architecture
  * without using standard int library but it's included to use if we need to
 omar samy
*/


#ifndef _Bool
#define _Bool unsigned char
#endif

#ifndef FALSE
#define FLASE  (boolean)false
#endif

#ifndef TRUE
#define TRUE  (boolean)true
#endif

//architecture is 32
#define archtecture_   archtecture_32
//most significant bit first
#define Endianness_bit       Endianness_MSB
//highest byte first
#define Endianness_byte      Endianness_HBF

typedef _Bool    boolean;

typedef char     char_t ;
//unsigned
typedef unsigned  char  unint8;
typedef unsigned  short unint16;
typedef unsigned  int   unint32;
typedef unsigned  long long     unint64;
//signed
typedef  signed char  sint8;
typedef signed  short sint16;
typedef    signed int  sint32;
typedef  signed long long     sint64;
//Volatile unsigned
typedef volatile unsigned  char  vunint8;
typedef volatile unsigned  short vunint16;
typedef  volatile unsigned      vunint32;
typedef volatile unsigned  long long    vunint64;
//Volatile signed
typedef  volatile signed char  vsint8;
typedef  volatile signed short vsint16;
typedef   volatile signed int  vsint32;
typedef  volatile signed long long    vsint64;


#endif

```


# 2- FIFO : QUEUE(circular) data structure 


## fifo.h 

prototype of the lifo functions and the fifo buffer structure and the statues enumuration
> **Note**
 mod int standard library is also included in this project to make use of 
>

```c code

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


```


## fifo.c

the implementation of the lifo functions

```c code
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


```



### main.c 

the main program  

```c code
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

```

### output snapshot

[![JIkX1rg.md.png](https://iili.io/JIkX1rg.md.png)](https://freeimage.host/i/JIkX1rg)

# 3- linked list  : (single linked list) data structure 

## linked_list.h 

prototype of the linked list functions 


```c code
 /*
 * linked_list.h
 *
 *  Created on: Dec 7, 2023
 *      Author: omar samy
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

 struct S_data{
	uint32_t id ;
	char name[40];
	float hight ;
};

 struct S_node {
	 struct S_data student;
	struct S_node* PNextNode ;
};


void add_data () ;
int delete_node () ;
void dumb_Data() ;
void delete_all() ;
int view_node() ;
void find_length() ;
int find_length_recursive(struct S_node*) ;
int find_node_fromEnd() ;
int view_middle() ;
int reverse_list() ;



#endif /* LINKED_LIST_H_ */

```

## linked_list.c 

the implementation of  of the linked list functions 


```c code
 
 /*
 * linked_list.c
 *
 *  Created on: Dec 7, 2023
 *      Author: omar smay
 */
#include "linked_list.h"

#define dprintf(...)  {\
		fflush (stdout) ;\
		fflush (stdin) ;\
		printf(__VA_ARGS__);\
		fflush (stdout) ;\
		fflush (stdin) ; }


struct S_node* g_Phead = NULL ;

// function that adds new node  and fill it with data
void add_data () {
	// create new node and assign it null to further check if malloc scuceded
	struct S_node* Pnew_node = NULL ;
	struct S_node* Plast_node ;

	// if there was no node created before
	if (g_Phead == NULL) {
		// creating new data or new node in the heap memory
		Pnew_node = ( struct S_node*) malloc (sizeof ( struct S_node)) ;
		// check if malloc succeded
		if (Pnew_node) {
			// assign the head pointer to the first node
			g_Phead = Pnew_node ;
			// assign the last node we created to null ( single linked list )
			Pnew_node ->PNextNode = NULL ; }
	}else // if there are nodes already
	{
		// first we assign the plast data poiner to the very first node to navigate until we foun the last node
		Plast_node = g_Phead ;
		while  (Plast_node ->PNextNode){
			Plast_node = Plast_node->PNextNode ;
		}
		// creating new data or new node in the heap memory
		Pnew_node = (struct S_node*) malloc (sizeof (struct S_node)) ;
	}
	// check if malloc succeded
	if (Pnew_node) {
		//assign the last node to the new node we created
		Plast_node->PNextNode = Pnew_node ;


		// assign new data

		char temp[40] ;

		dprintf("\nenter student id : ");
		gets(temp) ;
		Pnew_node->student.id = atoi(temp) ;
		dprintf("enter student name:");
		gets(Pnew_node->student.name) ;
		dprintf("enter student hight : ");
		gets(temp) ;
		Pnew_node->student.hight = atof(temp) ;
		// assign the last node we created to null ( single linked list )
		Pnew_node->PNextNode = NULL ;
	}
}


int delete_node () {
	char temp[40] ;
	uint32_t selected_id ;
	dprintf("\nenter student id  to be deleted : ");
	gets (temp);
	selected_id = atoi(temp) ;


	if (g_Phead) {

		struct S_node* Pselected_node = g_Phead ;
		struct S_node* Pprevious_node = NULL ;

		while(Pselected_node) {

			if (Pselected_node->student.id == selected_id) {

				if (Pprevious_node){

					// assign the previous node of the selected node we want to delete to the next node
					Pprevious_node->PNextNode = Pselected_node->PNextNode;

				}else //Pprevious_node is equal to null means the first node have the selected id
				{
					// discard the first node that we want to delete an and assign the head pointer to the next node or null
					g_Phead = Pselected_node->PNextNode ;

				}
				free(Pselected_node) ;
				dprintf("\ndeleted studnt id number : %d \n",selected_id );
				return 1 ;
				// looping throught the list with two pointers which Pselected_node points to the node after the node which Pprevious_node points to
			}
			Pprevious_node = Pselected_node ;
			Pselected_node = Pselected_node->PNextNode ;
		}

		dprintf("\ncannot find id\n");
		return 0 ;
	}else {
		dprintf("\nthe list is empty\n");
		return 0;
	}
}

void dumb_Data() {
	// make pointer to loop throught the list to view all data
	struct S_node* Pcurrnt_node = g_Phead ;
	uint32_t count = 0 ;
	// check if the list exists
	if(g_Phead == NULL) {
		dprintf("\n the list is empty");
	}else
	{
		// while Pcurrnt_node doesn't equal  null we print all nodes
		while (Pcurrnt_node) {
			dprintf("\n ======================= ") ;
			dprintf("\n record number %d", count+1);
			dprintf("\n \t student id : %d", Pcurrnt_node->student.id);
			dprintf("\n \t student name : %s", Pcurrnt_node->student.name);
			dprintf("\n \t student hight : %f\n", Pcurrnt_node->student.hight);
			dprintf("\n ======================= \n") ;
			count++;
			Pcurrnt_node = Pcurrnt_node->PNextNode ;
		}
	}

}

void delete_all() {

	// make pointer to loop throught the list to delete all nodes
	struct S_node* Pcurrnt_node = g_Phead ;
	// check if the list exists
	if(g_Phead == NULL) {
		dprintf("\n the list is empty \n");
	}else
	{
		// while Pcurrnt_node doesn't equal  null we delete all nodes
		while (Pcurrnt_node) {
			struct S_node* ptemp = Pcurrnt_node ;
			Pcurrnt_node = Pcurrnt_node->PNextNode ;
			free (ptemp) ;
		}
		g_Phead = NULL ;
	}
}

int view_node() {
	// creationg count and index to get from the user
	uint32_t count =0 , index;
	char temp[20] ;
	// assign the Pcurrnt_node to the start of the list
	struct S_node* Pcurrnt_node = g_Phead ;
	// check if the list is empty
	if (g_Phead == NULL) {
		dprintf("\n the list is empty");
	}else // if the list is not empty we loop until we found the node index entered by the user
	{
		dprintf("\n enter index of the node you want to view (starting from 0 ... ): ");
		gets(temp) ;
		index = atoi(temp) ;
		while  (Pcurrnt_node) {
			if (index == count) {
				dprintf("\n ======================= ") ;
				dprintf("\n record number %d", count+1);
				dprintf("\n index number %d", index);
				dprintf("\n \t student id : %d", Pcurrnt_node->student.id);
				dprintf("\n \t student name : %s", Pcurrnt_node->student.name);
				dprintf("\n \t student hight : %f\n", Pcurrnt_node->student.hight);
				dprintf("\n ======================= \n") ;
				return 0 ;
			}
			Pcurrnt_node =Pcurrnt_node->PNextNode ;
			count++ ;
			if (Pcurrnt_node == NULL) {
				// exit if we didn't fine the node spicified by the user
				dprintf("\n index doesn't match\n  ") ;
				return 1;
			}
		}

	}
	return 0 ;

}


void find_length() {

	uint32_t count =0 ;
	struct S_node* Pcurrnt_node = g_Phead ;
	if (g_Phead == NULL) {
		dprintf("\n the list is empty");
	}else {
		while (Pcurrnt_node) {
			++count ;
			Pcurrnt_node = Pcurrnt_node->PNextNode;

		}

		dprintf("\n the length of the list  is %d ",count);
	}

}

int find_length_recursive( struct S_node* g_Phead) {
	if (g_Phead == NULL) {
		return 0;
	}else{
		return 1 + find_length_recursive(g_Phead->PNextNode);
	}

}

int find_node_fromEnd() {
	// create two pointer when the last is point to null and differ from the main pointer by
	// n index entered by the user means that the node main pointer points to is the node we want to view
	struct S_node* Pmain =g_Phead ;
	struct S_node* Plast =g_Phead ;
	uint32_t index ;
	char temp[40] ;

	if (g_Phead == NULL){

		dprintf("\n the list is empty ");

	}else{

		dprintf("\n enter the node number from the end: ");
		gets(temp) ;
		//check if the user entered 0 index
		if (( atoi(temp) )== 0) {
			dprintf("\n you entered 0 try 1,2,3,4.. ");
			return 0;
		}
		index =atoi(temp) ;
		// here we increment the plast pointer unitl it reaches n index entered by the user
		while  (Plast && index ){
			Plast = Plast->PNextNode ;
			--index;
		}
		// if index is not 0 means that Plast reached null before it's set to 0
		// user entered index number bigger than the nodes of the list
		if (index > 0){

			dprintf("\n node doesn't exist within the list ");

			return 0;

		}else{
			// increment pmain pointer until plast is equal to null
			while (Plast) {
				Plast =Plast->PNextNode ;
				Pmain = Pmain->PNextNode ;
			}
			// if plast is  equal to null we print the node that pmain points to
			if (Plast== NULL) {
				dprintf("\n ======================= ") ;
				dprintf("\n \t student id : %d", Pmain->student.id);
				dprintf("\n \t student name : %s", Pmain->student.name);
				dprintf("\n \t student hight : %f\n", Pmain->student.hight);
				dprintf("\n ======================= \n") ;
				return 0;
			}
		}
	}
	return 0;

}


int view_middle() {
	/* creating two pointer one is fast and one is slow
	 * the fast is moving twice the nodes of the slow
	 * when the fast points to null
	 * means that the slow point to the middle ( in case of odd numbers of nodes )
	 *
	 */
	struct S_node* Pfast = g_Phead ;
	struct S_node* Pslow = g_Phead ;
	if (g_Phead == NULL){
		dprintf("\n the list is empty ");
		return 0;
	}
	while (Pslow) {
		if (Pfast->PNextNode == NULL){

			dprintf("\n ======================= ") ;
			dprintf("\n found the middle of the list");
			dprintf("\n \t student id : %d", Pslow->student.id);
			dprintf("\n \t student name : %s", Pslow->student.name);
			dprintf("\n \t student hight : %f\n", Pslow->student.hight);
			dprintf("\n ======================= \n") ;
			return 0;

		}

		Pslow = Pslow->PNextNode;
		Pfast = Pfast->PNextNode->PNextNode ;
	}



	return 0;

}

int reverse_list() {
	if (g_Phead == NULL){
		dprintf("\n the list is empty ");
		return 0;
	}
	struct S_node* Pprev = NULL  ;
	struct S_node* Pcurrent= g_Phead ;
	struct S_node* Pnext = Pcurrent->PNextNode ;


	while(Pcurrent) {
		Pnext =Pcurrent->PNextNode ;
		Pcurrent->PNextNode =Pprev ;
		Pprev =Pcurrent ;
		Pcurrent =Pnext ;
	}

	g_Phead = Pprev;

	return 1;
}



 
```

## main.c 

the main program 


```c code

/*
 * main.c
 *
 *  Created on: Dec 7, 2023
 *      Author: omar samy
 */

#define dprintf(...)  {\
                      fflush (stdout) ;\
	                	fflush (stdin) ;\
                          printf(__VA_ARGS__);\
		                  fflush (stdout) ;\
	                    	fflush (stdin) ; }

#include "linked_list.h"

extern struct S_node* g_Phead ;

void main() {
	int number ;
while (1) {
	dprintf("\n ======================= ") ;
	dprintf("\n choose one of the following options \n") ;
	dprintf(" add student [1] \n") ;
	dprintf(" delete student [2] \n") ;
	dprintf(" view all students [3] \n") ;
	dprintf(" delete all students [4] \n") ;
	dprintf(" view student at specific index [5] \n") ;
	dprintf(" find length of the list [6] \n") ;
	dprintf(" find length of the list via recursive function[7] \n") ;
	dprintf(" view node by it's index number from the end [8]\n") ;
	dprintf(" view node that is in the middle of the list [9]\n") ;
	dprintf(" reverse the list [10]\n") ;
	dprintf(" exit program [11] \n") ;
	dprintf(" ======================= ") ;
	dprintf("\n enter your choice: ") ;
    fflush (stdout) ; fflush (stdin) ;
	scanf ("%d",&number);
    fflush (stdout) ; fflush (stdin) ;
	switch(number)
	{
	case 1:
		add_data () ;
		break ;
	case 2:
		 delete_node () ;
			break ;
	case 3:
		 dumb_Data() ;
			break ;
	case 4:
		 delete_all() ;
				break ;

	case 5:
	      view_node() ;
	            break ;
	case 6:
	     find_length() ;
		         break ;
	case 7:
		dprintf("\n the length of the list is %d \n" , find_length_recursive(g_Phead));
		    break ;
	case 8:
		find_node_fromEnd() ;
		break ;
	case 9:
		dprintf(" in case of odd numbers of nodes in the list this is the middle \n") ;
		dprintf(" in case of even numbers of nodes in the list this is the second middle \n") ;
		 view_middle();
		 break;
	case 10:
		reverse_list();
		break ;
	case 11:
		dprintf(" exit succeded \n") ;
	    exit(0) ;
	    break ;
default :
	dprintf(" wrong choice  \n") ;

    break ;

	}
}

}
 
```

## add_data api

```c code
// function that adds new node  and fill it with data
void add_data () {
	// create new node and assign it null to further check if malloc scuceded
	struct S_node* Pnew_node = NULL ;
	struct S_node* Plast_node ;

	// if there was no node created before
	if (g_Phead == NULL) {
		// creating new data or new node in the heap memory
		Pnew_node = ( struct S_node*) malloc (sizeof ( struct S_node)) ;
		// check if malloc succeded
		if (Pnew_node) {
			// assign the head pointer to the first node
			g_Phead = Pnew_node ;
			// assign the last node we created to null ( single linked list )
			Pnew_node ->PNextNode = NULL ; }
	}else // if there are nodes already
	{
		// first we assign the plast data poiner to the very first node to navigate until we foun the last node
		Plast_node = g_Phead ;
		while  (Plast_node ->PNextNode){
			Plast_node = Plast_node->PNextNode ;
		}
		// creating new data or new node in the heap memory
		Pnew_node = (struct S_node*) malloc (sizeof (struct S_node)) ;
	}
	// check if malloc succeded
	if (Pnew_node) {
		//assign the last node to the new node we created
		Plast_node->PNextNode = Pnew_node ;


		// assign new data

		char temp[40] ;

		dprintf("\nenter student id : ");
		gets(temp) ;
		Pnew_node->student.id = atoi(temp) ;
		dprintf("enter student name:");
		gets(Pnew_node->student.name) ;
		dprintf("enter student hight : ");
		gets(temp) ;
		Pnew_node->student.hight = atof(temp) ;
		// assign the last node we created to null ( single linked list )
		Pnew_node->PNextNode = NULL ;
	}
}

```

### api in action

 ![Alt Text](https://s5.gifyu.com/images/SiEZG.gif)



## delete_node api

```c code


int delete_node () {
	char temp[40] ;
	uint32_t selected_id ;
	dprintf("\nenter student id  to be deleted : ");
	gets (temp);
	selected_id = atoi(temp) ;


	if (g_Phead) {

		struct S_node* Pselected_node = g_Phead ;
		struct S_node* Pprevious_node = NULL ;

		while(Pselected_node) {

			if (Pselected_node->student.id == selected_id) {

				if (Pprevious_node){

					// assign the previous node of the selected node we want to delete to the next node
					Pprevious_node->PNextNode = Pselected_node->PNextNode;

				}else //Pprevious_node is equal to null means the first node have the selected id
				{
					// discard the first node that we want to delete an and assign the head pointer to the next node or null
					g_Phead = Pselected_node->PNextNode ;

				}
				free(Pselected_node) ;
				dprintf("\ndeleted studnt id number : %d \n",selected_id );
				return 1 ;
				// looping throught the list with two pointers which Pselected_node points to the node after the node which Pprevious_node points to
			}
			Pprevious_node = Pselected_node ;
			Pselected_node = Pselected_node->PNextNode ;
		}

		dprintf("\ncannot find id\n");
		return 0 ;
	}else {
		dprintf("\nthe list is empty\n");
		return 0;
	}
}



```

### api in action

 ![Alt Text](https://s5.gifyu.com/images/SiEaz.gif)



## dumb_Data api ( view all nodes )

```c code


void dumb_Data() {
	// make pointer to loop throught the list to view all data
	struct S_node* Pcurrnt_node = g_Phead ;
	uint32_t count = 0 ;
	// check if the list exists
	if(g_Phead == NULL) {
		dprintf("\n the list is empty");
	}else
	{
		// while Pcurrnt_node doesn't equal  null we print all nodes
		while (Pcurrnt_node) {
			dprintf("\n ======================= ") ;
			dprintf("\n record number %d", count+1);
			dprintf("\n \t student id : %d", Pcurrnt_node->student.id);
			dprintf("\n \t student name : %s", Pcurrnt_node->student.name);
			dprintf("\n \t student hight : %f\n", Pcurrnt_node->student.hight);
			dprintf("\n ======================= \n") ;
			count++;
			Pcurrnt_node = Pcurrnt_node->PNextNode ;
		}
	}

}



```

### api in action

 ![Alt Text](https://s5.gifyu.com/images/SiEaM.gif)



## delete_all api

```c code


void delete_all() {

	// make pointer to loop throught the list to delete all nodes
	struct S_node* Pcurrnt_node = g_Phead ;
	// check if the list exists
	if(g_Phead == NULL) {
		dprintf("\n the list is empty \n");
	}else
	{
		// while Pcurrnt_node doesn't equal  null we delete all nodes
		while (Pcurrnt_node) {
			struct S_node* ptemp = Pcurrnt_node ;
			Pcurrnt_node = Pcurrnt_node->PNextNode ;
			free (ptemp) ;
		}
		g_Phead = NULL ;
	}
}


```

### api in action

 ![Alt Text](https://s5.gifyu.com/images/SiEaT.gif)



## view_node at specific index api

```c code


int view_node() {
	// creationg count and index to get from the user
	uint32_t count =0 , index;
	char temp[20] ;
	// assign the Pcurrnt_node to the start of the list
	struct S_node* Pcurrnt_node = g_Phead ;
	// check if the list is empty
	if (g_Phead == NULL) {
		dprintf("\n the list is empty");
	}else // if the list is not empty we loop until we found the node index entered by the user
	{
		dprintf("\n enter index of the node you want to view (starting from 0 ... ): ");
		gets(temp) ;
		index = atoi(temp) ;
		while  (Pcurrnt_node) {
			if (index == count) {
				dprintf("\n ======================= ") ;
				dprintf("\n record number %d", count+1);
				dprintf("\n index number %d", index);
				dprintf("\n \t student id : %d", Pcurrnt_node->student.id);
				dprintf("\n \t student name : %s", Pcurrnt_node->student.name);
				dprintf("\n \t student hight : %f\n", Pcurrnt_node->student.hight);
				dprintf("\n ======================= \n") ;
				return 0 ;
			}
			Pcurrnt_node =Pcurrnt_node->PNextNode ;
			count++ ;
			if (Pcurrnt_node == NULL) {
				// exit if we didn't fine the node spicified by the user
				dprintf("\n index doesn't match\n  ") ;
				return 1;
			}
		}

	}
	return 0 ;

}



```

### api in action
 ![Alt Text](https://s5.gifyu.com/images/SiEYF.gif)




## find_length api

```c code


void find_length() {

	uint32_t count =0 ;
	struct S_node* Pcurrnt_node = g_Phead ;
	if (g_Phead == NULL) {
		dprintf("\n the list is empty");
	}else {
		while (Pcurrnt_node) {
			++count ;
			Pcurrnt_node = Pcurrnt_node->PNextNode;

		}

		dprintf("\n the length of the list  is %d ",count);
	}

}


```

### api in action

 ![Alt Text](https://s5.gifyu.com/images/SiEta.gif)





## find_length_recursive api

```c code


int find_length_recursive( struct S_node* g_Phead) {
	if (g_Phead == NULL) {
		return 0;
	}else{
		return 1 + find_length_recursive(g_Phead->PNextNode);
	}

}


```

### api in action

 ![Alt Text](https://s5.gifyu.com/images/SiEtt.gif)




## find_node_fromEnd api

```c code


int find_node_fromEnd() {
	// create two pointer when the last is point to null and differ from the main pointer by
	// n index entered by the user means that the node main pointer points to is the node we want to view
	struct S_node* Pmain =g_Phead ;
	struct S_node* Plast =g_Phead ;
	uint32_t index ;
	char temp[40] ;

	if (g_Phead == NULL){

		dprintf("\n the list is empty ");

	}else{

		dprintf("\n enter the node number from the end: ");
		gets(temp) ;
		//check if the user entered 0 index
		if (( atoi(temp) )== 0) {
			dprintf("\n you entered 0 try 1,2,3,4.. ");
			return 0;
		}
		index =atoi(temp) ;
		// here we increment the plast pointer unitl it reaches n index entered by the user
		while  (Plast && index ){
			Plast = Plast->PNextNode ;
			--index;
		}
		// if index is not 0 means that Plast reached null before it's set to 0
		// user entered index number bigger than the nodes of the list
		if (index > 0){

			dprintf("\n node doesn't exist within the list ");

			return 0;

		}else{
			// increment pmain pointer until plast is equal to null
			while (Plast) {
				Plast =Plast->PNextNode ;
				Pmain = Pmain->PNextNode ;
			}
			// if plast is  equal to null we print the node that pmain points to
			if (Plast== NULL) {
				dprintf("\n ======================= ") ;
				dprintf("\n \t student id : %d", Pmain->student.id);
				dprintf("\n \t student name : %s", Pmain->student.name);
				dprintf("\n \t student hight : %f\n", Pmain->student.hight);
				dprintf("\n ======================= \n") ;
				return 0;
			}
		}
	}
	return 0;

}


```

### api in action
 ![Alt Text](https://s5.gifyu.com/images/SiEtB.gif)





## view_middle api

```c code


int view_middle() {
	/* creating two pointer one is fast and one is slow
	 * the fast is moving twice the nodes of the slow
	 * when the fast points to null
	 * means that the slow point to the middle ( in case of odd numbers of nodes )
	 *
	 */
	struct S_node* Pfast = g_Phead ;
	struct S_node* Pslow = g_Phead ;
	if (g_Phead == NULL){
		dprintf("\n the list is empty ");
		return 0;
	}
	while (Pslow) {
		if (Pfast->PNextNode == NULL){

			dprintf("\n ======================= ") ;
			dprintf("\n found the middle of the list");
			dprintf("\n \t student id : %d", Pslow->student.id);
			dprintf("\n \t student name : %s", Pslow->student.name);
			dprintf("\n \t student hight : %f\n", Pslow->student.hight);
			dprintf("\n ======================= \n") ;
			return 0;

		}

		Pslow = Pslow->PNextNode;
		Pfast = Pfast->PNextNode->PNextNode ;
	}



	return 0;

}


```

### api in action
 ![Alt Text](https://s5.gifyu.com/images/SiEtP.gif)






## reverse_list api

```c code


int reverse_list() {
	if (g_Phead == NULL){
		dprintf("\n the list is empty ");
		return 0;
	}
	struct S_node* Pprev = NULL  ;
	struct S_node* Pcurrent= g_Phead ;
	struct S_node* Pnext = Pcurrent->PNextNode ;


	while(Pcurrent) {
		Pnext =Pcurrent->PNextNode ;
		Pcurrent->PNextNode =Pprev ;
		Pprev =Pcurrent ;
		Pcurrent =Pnext ;
	}

	g_Phead = Pprev;

	return 1;
}



```

### api in action

 ![Alt Text](https://s5.gifyu.com/images/SiE5s.gif)





[![MIT License](https://img.shields.io/badge/LIFO%20FILES%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/system%20architect/data%20structure/all%20files/lifo)
[![MIT License](https://img.shields.io/badge/FIFO%20FILES%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/system%20architect/data%20structure/all%20files/fifo)
[![MIT License](https://img.shields.io/badge/LINKED%20LIST%20FILES%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/system%20architect/data%20structure/all%20files/linked%20list/c%20code)



[![MIT License](https://img.shields.io/badge/go%20back%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main)

&nbsp;
&nbsp;

&nbsp;

## 🔗 Links

[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/omar-samy-69a7241b0/)
