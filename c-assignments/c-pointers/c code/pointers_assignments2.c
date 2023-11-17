#include "stdio.h"
//program prints all the alphabets using pointers
//omar samy

int main () {

	char alpha[26]  ;
	char* ptr ;
	ptr = alpha ;
	int i ;
	for( i = 0  ;i <26  ; i++   )
	{

		*ptr = i + 'A'  ;
		printf("%c\t",*ptr);
		fflush(stdout); fflush(stdin);

		if (*ptr == 'M') {
			printf("\n\n");
			fflush(stdout); fflush(stdin);

		}
		ptr++;
	}


	return 0 ;
}
