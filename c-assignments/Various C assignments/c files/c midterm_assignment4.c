#include "stdio.h"
//reverse digits in a number
void xreverse (int number ) ;
int main () {
	int i ;
	printf("enter a number :  ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf ("%d",&i) ;
	printf("reversed number:  ") ;
	fflush (stdout) ; fflush (stdin) ;
	 xreverse (i);

	return 0 ;


}

void xreverse (int number ) {
	int last ;
	int reversed ;


	while (number !=0) {
		last = number % 10 ;
		reversed = reversed * 10 + last ;
		number = number / 10;
				if (number ==0) {

					printf ("%d",reversed);

				}else {
					continue ;
				}




	}




}


