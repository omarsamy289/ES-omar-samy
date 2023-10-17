/*#include "stdio.h"
//insert an element in  an array
//omar samy

int main () {
	int elements ,n ,location , i ;
	int a[10] ;
	printf ("enter numbers of elements : ") ;
	fflush(stdout) ; fflush(stdin) ;
	scanf("%d" , &elements) ;
	for ( i=1 ; i<= elements ; i++) {
		printf ("insert the elements at location %d : " , i) ;
		fflush(stdout) ; fflush(stdin) ;
		scanf("%d" , &a[i]) ;

	}
	printf ("\n you entered : \n") ;
	fflush(stdout) ; fflush(stdin) ;
	for ( i=1 ; i<= elements ; i++) {
		printf ("%d\t" , a[i]) ;
		fflush(stdout) ; fflush(stdin) ;
	}
	printf ("\n") ;
		fflush(stdout) ; fflush(stdin) ;

	printf ("enter the location of element you want to insert from 1 to %d: ", elements) ;
	fflush(stdout) ; fflush(stdin) ;
	scanf("%d" , &location) ;

	printf ("enter the value  of the element you want to insert at location %d: ", location ) ;
	fflush(stdout) ; fflush(stdin) ;
	scanf("%d" , &n) ;

	for ( i=elements+1 ; i>= location ; i--) {
		a[i] = a[i-1] ;
		}
elements++ ;
a[location] = n ;

for ( i=1 ; i<= elements ; i++) {
		printf ("%d\t " , a[i]) ;
		fflush(stdout) ; fflush(stdin) ;

	}


	return 0 ;
}
*/
