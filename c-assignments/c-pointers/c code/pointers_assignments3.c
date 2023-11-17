#include "stdio.h"
//program prints string in reverse using pointers
//omar samy

int main () {
	char string[50]  ;
	char revstring[50] ;
	printf("enter a string: ");
	fflush(stdout); fflush(stdin);
	fgets(string,50,stdin);
	char* ptr ;
	char* rptr ;
	ptr = string ;
	rptr = revstring ;
	int i ;
	int count = 0;

	printf("non reversed string: \n");
	fflush(stdout); fflush(stdin);
	while (*ptr) {
		printf("%c",*ptr);
		fflush(stdout); fflush(stdin);
		ptr++;
		++count;
	}

	printf("reversed string: ");
	fflush(stdout); fflush(stdin);

	for (i = count ; i>=0 ; --i){
		rptr++ ;
		ptr-- ;
		*rptr=*ptr ;
		printf("%c",*rptr);
		fflush(stdout); fflush(stdin);
		rptr--;

	}


	return 0 ;
}


