/*#include "stdio.h"
//sum of two Matrices
//omar samy

int main () {
	int matrix1[2][2] , matrix2[2][2], matrix3[2][2];
	int i , n ;
	//matrix1 input
	for ( i=0 ; i< 2;i++)
		for ( n=0 ; n< 2;n++){

			printf ( "enter matrix1 value at matrix [%d][%d] : " , i+1 ,n+1 );
			fflush(stdout) ; fflush(stdin) ;
			scanf ("%d",&matrix1[i][n]) ;
			printf ( "\n ");
			fflush(stdout) ; fflush(stdin) ;
		}

	//matrix2 input
	for ( i=0 ; i< 2;i++)
		for ( n=0 ; n< 2;n++){

			printf ( "enter matrix2 value at matrix [%d][%d] : " , i+1 ,n+1 );
			fflush(stdout) ; fflush(stdin) ;
			scanf ("%d",&matrix2[i][n]) ;
			printf ( "\n ");
			fflush(stdout) ; fflush(stdin) ;
		}


	//matrix3
	for ( i=0 ; i< 2;i++)
		for ( n=0 ; n< 2;n++){

			matrix3[i][n] = matrix1[i][n] +matrix2[i][n] ;
		}

	//printing the value of matrix 3
	printf ("\nsum of the two Matrices  :\n\n") ; fflush(stdout) ; fflush(stdin) ;
	for ( i=0 ; i< 2;i++)
		for ( n=0 ; n< 2;n++){
			printf ( "matrix3[%d][%d]: %d\t\t\t" , i+1 ,n+1,matrix3[i][n] );
			fflush(stdout) ; fflush(stdin) ;
			if (n ==1) {
				printf ( "\n" ); fflush(stdout) ; fflush(stdin) ;
		            	}
		}



	return 0 ;
}
*/
