#include <stdio.h>
#include <string.h>
// reverse word in a string

void reverseWords(char* ) ;
int main() {
	char str[50] ;
	printf("enter the string : ");
	fflush(stdout) ; fflush(stdin) ;
	gets (str) ;
	printf("Original string: %s\n", str);
	fflush(stdout) ; fflush(stdin) ;
	reverseWords(str);
	printf("Reversed string: %s\n", str);
	fflush(stdout) ; fflush(stdin) ;


	return 0;
}


void reverseWords(char* str) {
	int length = strlen(str);
	int n1, n2;
	int i , j ;
	char temp ;
	// Reverse the entire string
	for (n1 = 0, n2 = length - 1; n1 < n2; n1++, n2--) {
		temp = str[n1];
		str[n1] = str[n2];
		str[n2] = temp;
	}

	n1 = 0;

	// Reverse each word
	for (n2 = 0; n2 < length; n2++) {
		if (str[n2] == ' ') {
			for (int i = n1, j = n2 - 1; i < j; i++, j--) {
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
			n1 = n2 + 1;
		}
	}

	// Reverse the last word
	for ( i = n1, j = length - 1; i < j; i++, j--) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}