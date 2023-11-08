#include "stdio.h"
//program to store information of a student using structure
typedef struct Sstudent {
	char name[50] ;
	int roll ;
	float marks ;
} student ;

int main () {
	student student_1 ;
	printf("enter the information of the student:\n") ;
	fflush (stdout) ; fflush (stdin) ;
	printf("enter the name of the student: ") ;
	fflush (stdout) ; fflush (stdin) ;
	fgets (student_1.name , 50 ,stdin) ;
	printf("enter roll of the student: " ) ;
	fflush (stdout) ; fflush (stdin) ;
	scanf("%d",&student_1.roll) ;
	printf("enter marks of the student: " ) ;
	fflush (stdout) ; fflush (stdin) ;
	scanf("%f",&student_1.marks) ;
	printf("displying the information of the student:\n") ;
	fflush (stdout) ; fflush (stdin) ;
	printf("name:%sroll:%d\nmarks:%.3f",student_1.name,student_1.roll,student_1.marks) ;
	fflush (stdout) ; fflush (stdin) ;
	return 0 ;
}
