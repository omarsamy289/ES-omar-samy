#include "stdio.h"
 // reverse elements of the array
void reverse_elements (int*  , int  ) ;
int main () {
	int i ;
	int arr[] = {1,2,3,4,5,6,7} ;
	int size = sizeof (arr) / sizeof (arr[0]);
	printf("the non reverseed array is :  ") ;
	fflush (stdout) ; fflush (stdin) ;
	for ( i =0 ; i < size ; i++ ) {
	printf("%d\t" , arr[i]) ;
	fflush (stdout) ; fflush (stdin) ;

	}
	printf("\n") ;
	fflush (stdout) ; fflush (stdin) ;
	reverse_elements (arr , size  ) ;
	printf("the reverseed array is :      ") ;
	fflush (stdout) ; fflush (stdin) ;
	for ( i =0 ; i < size ; i++ ) {
	printf("%d\t" , arr[i]) ;
	fflush (stdout) ; fflush (stdin) ;

	}

	return 0 ;


}

void reverse_elements (int* arr , int size  ) {




int temp ;
int i  ;

for ( i = 0 ; i < size/2 ;  i++ ){

	temp = arr[i];

	arr[i]=arr[size-i-1] ;

	arr[size-i-1] = temp ;


}


}

