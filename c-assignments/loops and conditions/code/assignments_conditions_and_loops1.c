#include "stdio.h"
//c program to  find the avarege of maximum of n positive numbers and
//breaks  if the user enters negative number and disply the avarege excluding the negative input
//omar smay

int main () {
	int i,maxnums  ;
	float  n , sum , avarege;
	printf ("enter max numbers :");
	fflush (stdout); fflush (stdin);
	scanf ("%d",&maxnums) ;
	for (i=1 ; i <=maxnums ; i++) {
		printf ( "enter n%d number: \n" , i ) ;
		fflush (stdout); fflush (stdin);
		scanf ("%f",&n) ;
		if (n<0.0) break;
		sum = sum + n ;
	}
	avarege = sum / (i-1) ;
	printf ( "sum is : %.2f\n" , sum ) ;
	fflush (stdout); fflush (stdin);
	printf ( "i-1    : %d\n" , i-1  ) ;
	fflush (stdout); fflush (stdin);
	printf ( "the avarege is %.f/%d : %.2f" ,sum , i-1 , avarege  ) ;
	fflush (stdout); fflush (stdin);
	return 0 ;
}
