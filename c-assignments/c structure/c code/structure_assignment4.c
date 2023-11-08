#include "stdio.h"
//program to add student data using structure array
typedef struct Sstudent {
	int roll ;
	char name [50] ;
	float marks ;
} student ;
int main () {
	student student_array[2] ;
	int i ;
	for (i=0 ; i< sizeof (student_array)/ sizeof (student) ; ++i ) {
		printf ( "\nenter data for student [%d]:\n", i+1) ;
		fflush (stdout) ; fflush (stdin) ;
		student_array[i].roll = i+1 ;
		printf("enter student name : ") ;
		fflush (stdout) ; fflush (stdin) ;
		gets (student_array[i].name) ;
		printf("enter student marks: ") ;
		fflush (stdout) ; fflush (stdin) ;
		scanf ("%f",&student_array[i].marks) ;
	}
	for (i=0 ; i<sizeof (student_array)/ sizeof (student) ; ++i ){
		printf("\nstudent %d data : \n" , i+1) ;
		fflush (stdout) ; fflush (stdin) ;
		printf("student roll:%d \n",student_array[i].roll) ;
		fflush (stdout) ; fflush (stdin) ;
		printf("student name:%s\n",student_array[i].name) ;
		fflush (stdout) ; fflush (stdin) ;
		printf("student marks:%.2f \n",student_array[i].marks) ;
		fflush (stdout) ; fflush (stdin) ;
	}
	return 0 ;
}


