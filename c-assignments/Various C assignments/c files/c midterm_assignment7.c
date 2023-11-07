#include "stdio.h"
//function to sum  the numbers from 1 to 100 using recusion
int sum_numbers  ( unsigned int );
int main () {
	unsigned int n;
	printf("enter the range of the numbers between 1 and   ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf ("%d",&n) ;
	printf("the sum of the range between 1 and %d is %d  " , n ,   sum_numbers  ( n ) ) ;

	return 0 ;


}

int sum_numbers  ( unsigned int n ) {

static int i = 0 ;

if ( n >0){

	sum_numbers (n-1) ;
	i = i+n ;

}


	return i ;

}


