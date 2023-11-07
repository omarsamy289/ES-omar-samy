
# various c assignments  


## by : omar samy

[![MIT License](https://img.shields.io/badge/go%20to%20screenshots-1A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/c-assignments/Various%20C%20assignments/screenshots/collected%20test%20cases)

## 1- function to take a number and sum all the digits

```c code
#include "stdio.h"
//function to take a number and sum all the digits
int sum_digits  (int) ;
int main () {
	int i ;
	printf("enter a value :  ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf ("%d",&i) ;
	printf("the sum of digits of %d is %d" , i , sum_digits  (i)) ;
		fflush (stdout) ; fflush (stdin) ;



	return 0 ;


}

int sum_digits  (int number ) {

int rem , sum =0;
	while (number !=0 ){
		rem = number % 10 ;
		sum = sum + rem ;
		number = number / 10 ;



	}

	return sum ;


}

```
## 2- find square root of a number

```c code
#include "stdio.h"
//find square root of a number
float squareRoot(float ) ;
int main () {
	float i ;
	printf("enter a number :  ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf ("%f",&i) ;
	printf("the square root of %.35f is %.3f ", i , squareRoot(i) ) ;
	fflush (stdout) ; fflush (stdin) ;

	return 0 ;


}



float squareRoot (float number) {

  float i = 0;
  float j = number / 2;

  while (j != i) {
    i = j;
    j = (number / i + i) / 2;
  }

  return j;

}



```

## 3-find prime numbers

```c code
#include "stdio.h"
//find prime numbers
void print_prime (int n1 , int n2 ) ;
int main () {
	int n1 ,n2 ;
	printf("enter  the values of the interval:  ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf ("%d %d",&n1, &n2) ;
	printf("the prime numbers between %d and %d are :  ", n1 , n2) ;
	fflush (stdout) ; fflush (stdin) ;
	 print_prime ( n1 , n2 ) ;

	return 0 ;


}

void print_prime (int n1 , int n2 ) {

int i , j , flag ;

for (i = n1; i <= n2; i++)
    {

        if (i == 1 || i == 0)
            continue;

        flag = 1;

        for (j = 2; j <= i / 2; ++j)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }


        if (flag == 1)
            printf("%d ", i);
    }






}

```

## 4- reverse digits in a number

```c code
#include "stdio.h"
//reverse digits in a number
void xreverse (int number ) ;
int main () {
	int i ;
	printf("enter a number :  ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf ("%d",&i) ;
	printf("reversed number:  ") ;
	fflush (stdout) ; fflush (stdin) ;
	 xreverse (i);

	return 0 ;


}

void xreverse (int number ) {
	int last ;
	int reversed ;


	while (number !=0) {
		last = number % 10 ;
		reversed = reversed * 10 + last ;
		number = number / 10;
				if (number ==0) {

					printf ("%d",reversed);

				}else {
					continue ;
				}




	}




}



```
## 5- c function to count ones in a birary of a decimel input

```c code
#include "stdio.h"
//c function to count ones in a birary of a decimel input
int count_ones (int ) ;
int main () {
	int num ;
	printf("enter a value :  ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf ("%d",&num) ;
	printf("the number of one's in the bainary of %d is %d " ,num , count_ones (num) ) ;
	fflush (stdout) ; fflush (stdin) ;

	return 0 ;


}

int count_ones (int number ) {
int count = 0 ;
int i ;
for ( i= 0 ; i <32 ; i++ ) {

	if ( number & (1<<i)) count++ ;
}

return count ;


```
## 6- return uniq number in the array

```c code
#include "stdio.h"
//return uniq number in the array

int  return_number (int* , int) ;
int main () {
	int arr [3] = {4,2,4} ;
	int size = sizeof(arr) / sizeof(arr[0]) ;

	printf( "the unique number of the array is:%d ",   return_number (arr ,size) ) ;
		fflush (stdout) ; fflush (stdin) ;


	return 0 ;


}

int  return_number (int* arr , int size) {

int i , number=0;

for (i=0 ; i < size ; i++)  number^= arr[i] ;



return number ;

}
```
## 7- function to sum  the numbers from 1 to 100 using recusion

```c code
#include "stdio.h"
//function to sum  the numbers from 1 to 100 using recusion
int sum_numbers  ( unsigned int );
int main () {
	unsigned int n;
	printf("enter the range of the numbers between 1 and   ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf ("%d",&n) ;
	printf("the sum of the range between 1 and %d is %d  " , n ,   sum_numbers  ( n ) ) ;

	return 0 ;


}

int sum_numbers  ( unsigned int n ) {

static int i = 0 ;

if ( n >0){

	sum_numbers (n-1) ;
	i = i+n ;

}


	return i ;

}




```
## 8- reverse elements of the array

```c code
#include "stdio.h"
 // reverse elements of the array
void reverse_elements (int*  , int  ) ;
int main () {
	int i ;
	int arr[] = {1,2,3,4,5,6,7} ;
	int size = sizeof (arr) / sizeof (arr[0]);
	printf("the non reverseed array is :  ") ;
	fflush (stdout) ; fflush (stdin) ;
	for ( i =0 ; i < size ; i++ ) {
	printf("%d\t" , arr[i]) ;
	fflush (stdout) ; fflush (stdin) ;

	}
	printf("\n") ;
	fflush (stdout) ; fflush (stdin) ;
	reverse_elements (arr , size  ) ;
	printf("the reverseed array is :      ") ;
	fflush (stdout) ; fflush (stdin) ;
	for ( i =0 ; i < size ; i++ ) {
	printf("%d\t" , arr[i]) ;
	fflush (stdout) ; fflush (stdin) ;

	}

	return 0 ;


}

void reverse_elements (int* arr , int size  ) {




int temp ;
int i  ;

for ( i = 0 ; i < size/2 ;  i++ ){

	temp = arr[i];

	arr[i]=arr[size-i-1] ;

	arr[size-i-1] = temp ;


}


}


```
## 9- reverse word in a string

```c code
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

```
## 10- maximum numbers of ones between two zeros in a bianary of a decimil input

```c code
#include "stdio.h"
// maximum numbers of ones between two zeros in a bianary of a decimil input
int find_ones (int  ) ;
int main () {
	int i ;
	printf("enter a number :  ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf ("%d",&i) ;
	printf("maximum numbers of ones in %d is %d" , i ,find_ones (i) ) ;
	fflush (stdout) ; fflush (stdin) ;

	return 0 ;


}

int find_ones (int number ) {

	char count ;

	while ( number!=0) {

		number = (number &(number <<1) ) ;
		count ++ ;
	}
return count ;

}



```


[![MIT License](https://img.shields.io/badge/go%20to%20screenshots-1A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/c-assignments/Various%20C%20assignments/screenshots/collected%20test%20cases)

