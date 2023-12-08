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


