#include "stdio.h"

// find the power of a number using recursive function
//omar samy
int power (int base , int PowerNum ) ;
int main () {
	int x , y ;
	printf ( "enter a base  number : ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf ("%d" , &x ) ;
	printf ( "enter the power degree : ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf ("%d" , &y ) ;
	printf ( "the power(%d) of %d is %d " , y , x , power ( x , y )) ;
	fflush (stdout) ; fflush (stdin) ;
	return 0 ;
}

int power (int base , int PowerNum ) {
	if ( PowerNum != 0)  return base * power ( base , PowerNum -1 ) ;
	else return 1 ;
	}





