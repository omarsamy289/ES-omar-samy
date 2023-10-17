/*#include "stdio.h"
//search an element in an array
//omar samy

int main () {
int a[50], element , i ,nums ;
printf ("enter numbers of elements in the array: ") ;
fflush(stdout) ; fflush(stdin) ;
scanf("%d" , &nums) ;
for ( i=1 ; i <= nums ; i++) {

	printf ("enter element of the array at location %d: " , i) ;
	fflush(stdout) ; fflush(stdin) ;
	scanf("%d" , &a[i]) ;
}
printf ("enter the element to be searched: " ) ;
	fflush(stdout) ; fflush(stdin) ;
    scanf("%d" , &element) ;
    i = 0 ;
    while (  i < nums && element != a[i]) {

    	i++ ;
    }
    	if ( i <= nums  ) {

    		printf ("element found at location %d ", i ) ;
    		fflush(stdout) ; fflush(stdin) ;


    	}else {

    		printf ("element not found at any location " ) ;
    		    		fflush(stdout) ; fflush(stdin) ;

    	}


	return 0 ;
}
*/
