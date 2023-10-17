
## C arrays and strings  


## by : omar samy


## 1- sum of two Matrices

```c code
#include "stdio.h"
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


```
## 2-calculate average using arrays 

```c code
#include "stdio.h"
//calculate average using arrays
//omar samy

int main () {
	int i , nums , average , sum=0;
	int matrix [100] ;
 printf ("enter number count : ") ;
fflush (stdout) ; fflush (stdin) ;
scanf ( "%d",&nums) ;
if (nums < 0 || nums >= 100){
	 printf ("you didn't enter a number between 0 and 100\n") ;
	fflush (stdout) ; fflush (stdin) ;
	 printf (" enter a number between 0 and 100 :") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf ( "%d",&nums) ;
}
for (i=0 ; i < nums ; ++i ) {
	 printf ("enter number at matrix[%d] : ", i+1) ;
	fflush (stdout) ; fflush (stdin) ;
	scanf ( "%d",&matrix[i]) ;
	sum += matrix[i] ;
}
average = sum / nums;
printf ("the average is %d/%d  = %d", sum, nums ,average ) ;
fflush (stdout) ; fflush (stdin) ;


	return 0 ;
}

```

## 3- find a transpose of a matrix

```c code
#include "stdio.h"
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

```

## 4- insert an element in  an array

```c code
#include "stdio.h"
//insert an element in  an array
//omar samy

int main () {
	int elements ,n ,location , i ;
	int a[10] ;
	printf ("enter numbers of elements : ") ;
	fflush(stdout) ; fflush(stdin) ;
	scanf("%d" , &elements) ;
	for ( i=1 ; i<= elements ; i++) {
		printf ("insert the elements at location %d : " , i) ;
		fflush(stdout) ; fflush(stdin) ;
		scanf("%d" , &a[i]) ;

	}
	printf ("\n you entered : \n") ;
	fflush(stdout) ; fflush(stdin) ;
	for ( i=1 ; i<= elements ; i++) {
		printf ("%d\t" , a[i]) ;
		fflush(stdout) ; fflush(stdin) ;
	}
	printf ("\n") ;
		fflush(stdout) ; fflush(stdin) ;

	printf ("enter the location of element you want to insert from 1 to %d: ", elements) ;
	fflush(stdout) ; fflush(stdin) ;
	scanf("%d" , &location) ;

	printf ("enter the value  of the element you want to insert at location %d: ", location ) ;
	fflush(stdout) ; fflush(stdin) ;
	scanf("%d" , &n) ;

	for ( i=elements+1 ; i>= location ; i--) {
		a[i] = a[i-1] ;
		}
elements++ ;
a[location] = n ;

for ( i=1 ; i<= elements ; i++) {
		printf ("%d\t " , a[i]) ;
		fflush(stdout) ; fflush(stdin) ;

	}


	return 0 ;
}

```
## 5-search an element in an array 

```c code
#include "stdio.h"
//search an element in an array
//omar samy

int main () {
int a[50], element , i ,nums ;
printf ("enter numbers of elements in the array: ") ;
fflush(stdout) ; fflush(stdin) ;
scanf("%d" , &nums) ;
for ( i=1 ; i <= nums ; i++) {

	printf ("enter element of the array at location %d: " , i) ;
	fflush(stdout) ; fflush(stdin) ;
	scanf("%d" , &a[i]) ;
}
printf ("enter the element to be searched: " ) ;
	fflush(stdout) ; fflush(stdin) ;
    scanf("%d" , &element) ;
    i = 0 ;
    while (  i < nums && element != a[i]) {

    	i++ ;
    }
    	if ( i <= nums  ) {

    		printf ("element found at location %d ", i ) ;
    		fflush(stdout) ; fflush(stdin) ;


    	}else {

    		printf ("element not found at any location " ) ;
    		    		fflush(stdout) ; fflush(stdin) ;

    	}


	return 0 ;
}

```

## 6- find the frequancy of character in  a string

```c code
#include "stdio.h"
//find the frequancy of character in a string
//omar samy

int main () {
char c[50], ch  ;
int i , count ;
printf ("enter a string : ") ;
fflush(stdout) ; fflush(stdin) ;
gets(c) ;

printf ("enter a character you want to know the frequancy of :  ") ;
fflush(stdout) ; fflush(stdin) ;
scanf ( "%c" , &ch) ;

i=0 ;
count = 0 ;
while ( c[i] != '\0'){
i++;
if (ch == c[i]) {
	++count ;
}
/*else {
	printf ("character not found") ;
	fflush(stdout) ; fflush(stdin) ;
break ;
}*/
}

printf ("\nthe frequancy  of %c is %d  " , ch , count) ;
fflush(stdout) ; fflush(stdin) ;

	return 0 ;
}

```

## 7- find the length of a string

```c code
#include "stdio.h"
#include "string.h"
//find the length of a string
//omar samy

int main () {
char s[50] ;
printf ("enter a string : ") ;
fflush(stdout) ; fflush(stdin) ;
gets(s) ;
printf ("the length of the string is %lld " , strlen(s)) ;
fflush(stdout) ; fflush(stdin) ;

	return 0 ;
}


```

## 8- reverse a string

```c code
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

```

[![MIT License](https://img.shields.io/badge/go%20to%20screenshots-1A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/c-assignments/arrays%20and%20strings/screenshots)



