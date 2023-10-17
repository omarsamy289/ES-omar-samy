/*#include "stdio.h"
//find a transpose of a matrix
//omar samy

int main () {
	int i , n , c , j ;
	int a[10][10] , b[10][10] ;
	printf ("enter rows and colum numbers : ") ;
	fflush(stdout) ; fflush(stdin) ;
	scanf("%d %d" , &c , &j) ;
	for (i=1 ; i<=c ; i++) {
		for (n=1 ; n<=j ; n++) {

			printf ("enter matrix value at matrix[%d][%d] : ",i,n) ;
			fflush(stdout) ; fflush(stdin) ;
			scanf("%d" ,&a[i][n]) ;
		}
	}
		printf ("\n the matrix you entered : \n" ) ;
		fflush(stdout) ; fflush(stdin) ;

		for (i=1 ; i<=c ; i++) {
			for (n=1 ; n<=j ; n++) {

				printf ("%d\t\t",a[i][n]) ;
				fflush(stdout) ; fflush(stdin) ;

			}
			if (n=j-1) {
				printf ("\n\n") ;
				fflush(stdout) ; fflush(stdin) ;

			}
		}

		for (i=1 ; i<=c ; i++) {
			for (n=1 ; n<=j ; n++) {

			b[n][i] = a[i][n] ;

			}
		}





		printf ("\n transposed matrix  : \n" ) ;
		fflush(stdout) ; fflush(stdin) ;
		for (i=1 ; i<=j ; i++) {
			for (n=1 ; n<=c ; n++) {

					 printf ("%d\t\t",b[i][n]) ;
				fflush(stdout) ; fflush(stdin) ;
			}
			if (i==j-1) {
				printf ("\n\n") ;
				fflush(stdout) ; fflush(stdin) ;
			}
		}
		return 0 ;
	}
*/
