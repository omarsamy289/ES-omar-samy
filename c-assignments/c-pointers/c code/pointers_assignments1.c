#include "stdio.h"
//program demonstrate how to handle pointers during the program

int main () {

	int m = 27 ;

	printf("the value of m : %d \n the address of m is %p\n",m ,  &m );
	fflush (stdout) ;fflush (stdin) ;

	int* ptr =&m ;
*ptr = 20 ;

	printf("the value of m : %d \n the address of m is %p\n",*ptr , ptr  );
		fflush (stdout) ;fflush (stdin) ;
int** pptr= &ptr;
**pptr =10 ;

		printf("the value of m : %d \n the address of m is %p",**pptr , *pptr  );
			fflush (stdout) ;fflush (stdin) ;

	return 0 ;
}
