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













