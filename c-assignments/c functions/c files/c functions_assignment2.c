#include "stdio.h"
// finding factorial of a number using tail recursion function
// tail recursion is a recursion function which returns the function itself
//omar samy
int factorial ( int a , int acc ) ;
int main () {
	int x  ;
	printf ( " enter a number: ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf ("%d" ,&x ) ;
	printf ( " the factorial of %d is %d " , x , factorial(x,1) ) ;
	fflush (stdout) ; fflush (stdin) ;
	return 0 ;
}

int factorial (int a , int acc){

	if (a == 0) return acc  ;
	else
		return factorial ( a-1 , a* acc) ;

}


