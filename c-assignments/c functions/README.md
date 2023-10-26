
## C functions   


## by : omar samy


## 1- finding prime numbers between two numbers 

```c code
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


```
## 2- finding factorial of a number using tail recursion function

```c code
#include "stdio.h"
// finding factorial of a number using tail recursion function
// tail recursion is a recursion function which returns the function itself
//omar samy
int factorial ( int a , int acc ) ;
int main () {
	int x  ;
	printf ( " enter a number: ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf ("%d" ,&x ) ;
	printf ( " the factorial of %d is %d " , x , factorial(x,1) ) ;
	fflush (stdout) ; fflush (stdin) ;
	return 0 ;
}

int factorial (int a , int acc){

	if (a == 0) return acc  ;
	else
		return factorial ( a-1 , a* acc) ;

}

```

## 3-  reverse a statment without using strings

```c code
#include "stdio.h"
// reverse a statment without using strings
//omar samy
void reverse () ;
int main () {
	printf ( " enter a sentence: ") ;
	fflush (stdout) ; fflush (stdin) ;
	reverse () ;
	return 0 ;
}

void reverse () {

	char a ;
	scanf ("%c" , &a ) ;

	if ( a != '\n'){
		reverse () ;
		printf ("%c" , a) ;
		fflush (stdout) ; fflush (stdin) ;

	}

}


```
## 4- find the power of a number using recursive function

```c code
#include "stdio.h"

// find the power of a number using recursive function
//omar samy
int power (int base , int PowerNum ) ;
int main () {
	int x , y ;
	printf ( "enter a base  number : ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf ("%d" , &x ) ;
	printf ( "enter the power degree : ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf ("%d" , &y ) ;
	printf ( "the power(%d) of %d is %d " , y , x , power ( x , y )) ;
	fflush (stdout) ; fflush (stdin) ;
	return 0 ;
}

int power (int base , int PowerNum ) {
	if ( PowerNum != 0)  return base * power ( base , PowerNum -1 ) ;
	else return 1 ;
	}



```
[![MIT License](https://img.shields.io/badge/go%20to%20screenshots-1A5BE2)]()



