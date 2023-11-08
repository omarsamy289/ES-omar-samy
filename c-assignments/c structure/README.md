
# structure , enum , union assignments


## by : omar samy

[![MIT License](https://img.shields.io/badge/go%20to%20screenshots-1A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/c-assignments/c%20structure/screenshots)

## 1- program to store information of a student using structure

```c code

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

```
## 2- program to add two distances (feet-inch input)

```c code

#include "stdio.h"
//program to add two distances (feet-inch input)
typedef struct Sdistance {
	int feet ;
	float inch ;
} distance ;
int main () {
	distance distance_1 ;
	distance distance_2 ;
	int feet_sum ;
	float inch_sum ;
	printf("enter the measures of the first distance:\n") ;
	fflush (stdout) ; fflush (stdin) ;
	printf("enter feet measure : ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf("%d",&distance_1.feet) ;
	printf("enter inches measure : ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf("%f",&distance_1.inch) ;
	printf("enter the measures of the second distance:\n") ;
	fflush (stdout) ; fflush (stdin) ;
	printf("enter feet measure : ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf("%d",&distance_2.feet) ;
	printf("enter inches measure : ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf("%f",&distance_2.inch) ;
	feet_sum = distance_1.feet + distance_2.feet ;
	inch_sum = distance_1.inch + distance_2.inch ;
	check_again :
	if ( inch_sum >= 12.0   ) {
		inch_sum= inch_sum - 12.0 ;
		++feet_sum;
		if (inch_sum >= 12.0 ) goto check_again ;
	}
	printf("\nsum of the two distances: %d\' %.2f\"" , feet_sum , inch_sum) ;
	fflush (stdout) ; fflush (stdin) ;
	return 0 ;
}

```

## 3-program to add two complex numbers (real-imaginary input)

```c code
#include "stdio.h"
//program to add two complex numbers (real-imaginary input)
typedef struct Scomplex {
	float real ;
	float imaginary ;
} complex ;
complex  add_complex ( complex , complex  ) ;
int main () {
	complex number1 ;
	complex number2 ;
	printf("enter the the fisrt complex number:\n") ;
	fflush (stdout) ; fflush (stdin) ;
	printf("enter real number : ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf("%f",&number1.real) ;
	printf("enter imaginary number : ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf("%f",&number1.imaginary) ;
	printf("enter the the second complex number:\n") ;
	fflush (stdout) ; fflush (stdin) ;
	printf("enter real number : ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf("%f",&number2.real) ;
	printf("enter imaginary number : ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf("%f",&number2.imaginary) ;
	add_complex (number1 , number2 ) ;
	printf("the result of adding the two complex number is %.2f+%.2fi ",
		add_complex (number1 , number2 ).real, add_complex (number1 , number2 ).imaginary) ;
	fflush (stdout) ; fflush (stdin) ;

	return 0 ;
}

complex  add_complex ( complex number1 , complex number2 ) {
	complex temp ;
	temp.real =   number1.real + number2.real ;
	temp.imaginary = number1.imaginary + number2.imaginary ;

	return temp ;

}

```

## 4- program to add student data using structure array

```c code
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

```
## 5- calculating area of circle using #define

```c code
#include "stdio.h"
//calculating area of circle using #define
#define area(r)  (3.1415 *(r*r))
int main () {
	int radious ;
	float area ;
	printf ( "enter radious of the circle: ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf("%d",&radious) ;
	area = area(radious) ;
	printf ( "the area is %.2f",area) ;
	fflush (stdout) ; fflush (stdin) ;

	return 0 ;
}

```



[![MIT License](https://img.shields.io/badge/go%20to%20screenshots-1A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/c-assignments/c%20structure/screenshots)

