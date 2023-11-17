#include "stdio.h"
// program show a pointer to an array which contents are pointer to an structure
//omar samy

typedef struct Sstudent{
	char name[50] ;
	int id ;
} student ;
int main () {
	int i ;
	student  student_one= {"omar samy" , 1997} , student_two={"samy omar" , 17785}  ;
	student (*ptr[]) = { &student_one , &student_two } ;
	// (student (*((*aptr)[2])) =&ptr ) this is a pointer to an array of two pointers
	//to a student struct datatype pointer  to an array of two pointer to student struct
	student (*((*aptr)[2])) =&ptr ;
	for ( i = 0 ; i < 2 ; ++i ){
		printf("the student number[%d] name is %s\n" ,i+1,(*(*aptr+i))->name );
		fflush(stdout); fflush(stdin);
		printf("the student number[%d] id is %d\n" ,i+1,(*(*aptr+i))->id );
		fflush(stdout); fflush(stdin);
		printf( "          *****************\n" );
		fflush(stdout); fflush(stdin);
	}
	return 0 ;
}

