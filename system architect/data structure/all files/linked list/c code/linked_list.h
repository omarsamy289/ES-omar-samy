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
