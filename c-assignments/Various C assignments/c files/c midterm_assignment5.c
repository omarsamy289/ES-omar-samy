#include "stdio.h"
//c function to count ones in a birary of a decimel input
int count_ones (int ) ;
int main () {
	int num ;
	printf("enter a value :  ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf ("%d",&num) ;
	printf("the number of one's in the bainary of %d is %d " ,num , count_ones (num) ) ;
	fflush (stdout) ; fflush (stdin) ;

	return 0 ;


}

int count_ones (int number ) {
int count = 0 ;
int i ;
for ( i= 0 ; i <32 ; i++ ) {

	if ( number & (1<<i)) count++ ;
}

return count ;





