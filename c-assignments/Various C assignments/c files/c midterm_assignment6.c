#include "stdio.h"
//return uniq number in the array

int  return_number (int* , int) ;
int main () {
	int arr [3] = {4,2,4} ;
	int size = sizeof(arr) / sizeof(arr[0]) ;

	printf( "the unique number of the array is:%d ",   return_number (arr ,size) ) ;
		fflush (stdout) ; fflush (stdin) ;


	return 0 ;


}

int  return_number (int* arr , int size) {

int i , number=0;

for (i=0 ; i < size ; i++)  number^= arr[i] ;



return number ;

}

