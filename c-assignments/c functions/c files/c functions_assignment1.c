#include "stdio.h"
// finding prime numbers between two numbers
// prime numbers cannot be devided on any number except 1 and itself
//omar samy
int checkprime ( int num ) ;
int main () {
	int x , y , flag ,i;
	printf ( " enter two number( intervals ) :  ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf ("%d %d" ,&x ,&y ) ;
	printf ( " the prime numbers between %d and %d are :   ", x , y ) ;
	fflush (stdout) ; fflush (stdin) ;
	for ( i = x+1 ; i < y ; ++i){

		flag = checkprime (i) ;
		if (flag==0){
			printf ( " %d ", i ) ;
			fflush (stdout) ; fflush (stdin) ;
		}
	}
	return 0 ;
}

int checkprime ( int num ) {
	int j ,flag=0 ;
	for ( j= 2 ; j <= num/2 ; ++j)
	{
		if ( num%j==0) {
			flag = 1 ;
			break ;
		}
	}

return flag ;
}


