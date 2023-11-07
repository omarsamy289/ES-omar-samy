#include "stdio.h"
// maximum numbers of ones between two zeros in a bianary of a decimil input
int find_ones (int  ) ;
int main () {
	int i ;
	printf("enter a number :  ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf ("%d",&i) ;
	printf("maximum numbers of ones in %d is %d" , i ,find_ones (i) ) ;
	fflush (stdout) ; fflush (stdin) ;

	return 0 ;


}

int find_ones (int number ) {

	char count ;

	while ( number!=0) {

		number = (number &(number <<1) ) ;
		count ++ ;
	}
return count ;

}


