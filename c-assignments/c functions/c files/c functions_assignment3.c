#include "stdio.h"
// reverse a statment without using strings
//omar samy
void reverse () ;
int main () {
	printf ( " enter a sentence: ") ;
	fflush (stdout) ; fflush (stdin) ;
	reverse () ;
	return 0 ;
}

void reverse () {

	char a ;
	scanf ("%c" , &a ) ;

	if ( a != '\n'){
		reverse () ;
		printf ("%c" , a) ;
		fflush (stdout) ; fflush (stdin) ;

	}

}





