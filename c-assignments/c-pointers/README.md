
#  c pointers assignments  


## by : omar samy

[![MIT License](https://img.shields.io/badge/go%20to%20screenshots-1A5BE2)]()

## 1-program demonstrate how to handle pointers during the program

```c code
#include "stdio.h"
//program demonstrate how to handle pointers during the program
//omar samy

int main () {

	int m = 27 ;

	printf("the value of m : %d \n the address of m is %p\n",m ,  &m );
	fflush (stdout) ;fflush (stdin) ;

	int* ptr =&m ;
*ptr = 20 ;

	printf("the value of m : %d \n the address of m is %p\n",*ptr , ptr  );
		fflush (stdout) ;fflush (stdin) ;
int** pptr= &ptr;
**pptr =10 ;

		printf("the value of m : %d \n the address of m is %p",**pptr , *pptr  );
			fflush (stdout) ;fflush (stdin) ;

	return 0 ;
}

```
## 2- program prints all the alphabets using pointers

```c code
#include "stdio.h"
//program prints all the alphabets using pointers
//omar samy

int main () {

	char alpha[26]  ;
	char* ptr ;
	ptr = alpha ;
	int i ;
	for( i = 0  ;i <26  ; i++   )
	{

		*ptr = i + 'A'  ;
		printf("%c\t",*ptr);
		fflush(stdout); fflush(stdin);

		if (*ptr == 'M') {
			printf("\n\n");
			fflush(stdout); fflush(stdin);

		}
		ptr++;
	}


	return 0 ;
}

```

## 3-program prints string in reverse using pointers

```c code
#include "stdio.h"
//program prints string in reverse using pointers
//omar samy

int main () {
	char string[50]  ;
	char revstring[50] ;
	printf("enter a string: ");
	fflush(stdout); fflush(stdin);
	fgets(string,50,stdin);
	char* ptr ;
	char* rptr ;
	ptr = string ;
	rptr = revstring ;
	int i ;
	int count = 0;

	printf("non reversed string: \n");
	fflush(stdout); fflush(stdin);
	while (*ptr) {
		printf("%c",*ptr);
		fflush(stdout); fflush(stdin);
		ptr++;
		++count;
	}

	printf("reversed string: ");
	fflush(stdout); fflush(stdin);

	for (i = count ; i>=0 ; --i){
		rptr++ ;
		ptr-- ;
		*rptr=*ptr ;
		printf("%c",*rptr);
		fflush(stdout); fflush(stdin);
		rptr--;

	}


	return 0 ;
}



```

## 4-program prints array in reverse order using pointers

```c code
#include "stdio.h"
//program prints array in reverse order using pointers
//omar samy

int main () {
	int array[15]  ;
	int size ;
	int i ;
	int* ptr;
	ptr = array ;
	printf("enter the size of the array : ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&size) ;
	for (i = 0 ; i<size ; ++i){
		printf("enter value to array in index %d: ",i+1);
		fflush(stdout); fflush(stdin);
		scanf("%d",ptr) ;
		ptr++;
	}
	printf("the reversed array is\n");
	fflush(stdout); fflush(stdin);
	ptr = &array[size-1] ;
	for (i = size  ; i>0 ; --i){
		printf("the value of the array in index %d is %d \n", i , *ptr);
		fflush(stdout); fflush(stdin);
		ptr--;
	}

	return 0 ;
}


```
## 5- program show a pointer to an array which contents are pointer to an structure

```c code
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



```
[![MIT License](https://img.shields.io/badge/go%20to%20screenshots-1A5BE2)]()



