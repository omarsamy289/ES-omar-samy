
## C loops and conditions assignments   


## by : omar samy


## 1- avarege of maximum of n positive numbers

```c code
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



```
## 2- product of 4 integrs

```c code
#include "stdio.h"
//c program to  find the product of 4 integrs entered by the user (if the input is 0 skip it)
//omar smay

int main () {
int i , n , product ;

for ( i = 1 , product =1 ; i <=4 ; i++ ) {

	printf (" enter number(%d):  " , i ) ;
	fflush (stdout) ; fflush ( stdin) ;
	scanf ("%d",&n) ;
	 if ( n == 0) continue ;
	 product *= n ;
}

printf (" the product of the numbers above is %d  " ,  product  ) ;
fflush (stdout) ; fflush ( stdin) ;

return 0 ;

}
```



[![MIT License](https://img.shields.io/badge/go%20to%20screenshots-1A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/c-assignments/c-basics/screen%20shot)


