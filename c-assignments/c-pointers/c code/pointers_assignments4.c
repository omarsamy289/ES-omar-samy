#include "stdio.h"
//program prints array in reverse order using pointers
//omar samy

int main () {
	int array[15]  ;
	int size ;
	int i ;
	int* ptr;
	ptr = array ;
	printf("enter the size of the array : ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&size) ;
	for (i = 0 ; i<size ; ++i){
		printf("enter value to array in index %d: ",i+1);
		fflush(stdout); fflush(stdin);
		scanf("%d",ptr) ;
		ptr++;
	}
	printf("the reversed array is\n");
	fflush(stdout); fflush(stdin);
	ptr = &array[size-1] ;
	for (i = size  ; i>0 ; --i){
		printf("the value of the array in index %d is %d \n", i , *ptr);
		fflush(stdout); fflush(stdin);
		ptr--;
	}

	return 0 ;
}

