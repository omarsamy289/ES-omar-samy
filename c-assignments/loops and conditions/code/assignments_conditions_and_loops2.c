#include "stdio.h"
//c program to  find the product of 4 integrs entered by the user if the input is 0 skip it
//omar smay

int main () {
int i , n , product ;

for ( i = 1 , product =1 ; i <=4 ; i++ ) {

	printf (" enter number(%d):  " , i ) ;
	fflush (stdout) ; fflush ( stdin) ;
	scanf ("%d",&n) ;
	 if ( n == 0) continue ;
	 product *= n ;
}

printf (" the product of the numbers above is %d  " ,  product  ) ;
fflush (stdout) ; fflush ( stdin) ;

return 0 ;

}
