/*#include "stdio.h"
//calculate average using arrays
//omar samy

int main () {
	int i , nums , average , sum=0;
	int matrix [100] ;
 printf ("enter number count : ") ;
fflush (stdout) ; fflush (stdin) ;
scanf ( "%d",&nums) ;
if (nums < 0 || nums >= 100){
	 printf ("you didn't enter a number between 0 and 100\n") ;
	fflush (stdout) ; fflush (stdin) ;
	 printf (" enter a number between 0 and 100 :") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf ( "%d",&nums) ;
}
for (i=0 ; i < nums ; ++i ) {
	 printf ("enter number at matrix[%d] : ", i+1) ;
	fflush (stdout) ; fflush (stdin) ;
	scanf ( "%d",&matrix[i]) ;
	sum += matrix[i] ;
}
average = sum / nums;
printf ("the average is %d/%d  = %d", sum, nums ,average ) ;
fflush (stdout) ; fflush (stdin) ;


	return 0 ;
}
*/
