#include "stdio.h"
//function to take a number and sum all the digits
int sum_digits  (int) ;
int main () {
	int i ;
	printf("enter a value :  ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf ("%d",&i) ;
	printf("the sum of digits of %d is %d" , i , sum_digits  (i)) ;
		fflush (stdout) ; fflush (stdin) ;



	return 0 ;


}

int sum_digits  (int number ) {

int rem , sum =0;
	while (number !=0 ){
		rem = number % 10 ;
		sum = sum + rem ;
		number = number / 10 ;



	}

	return sum ;


}


