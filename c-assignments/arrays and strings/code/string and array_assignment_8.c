#include "stdio.h"
#include "string.h"
//reverse a string
// omar samy


int main () {
	char a[100] , temp ;
	int i= 0 , j = 0 ;
	printf (" enter the string : ") ;
	fflush (stdout) ; fflush (stdin) ;
    gets(a);
   j = strlen(a)-1 ;
while ( i< j) {
	temp = a[i] ;
	a[i]=a[j] ;
    a[j] = temp ;
	i++ ; j-- ;

}
printf (" the reversed string is : %s " , a) ;
fflush (stdout) ; fflush (stdin) ;




	return 0 ;
}
