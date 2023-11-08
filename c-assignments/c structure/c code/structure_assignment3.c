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





