
## C basics assignments   


## by : omar samy


## 1- simple calulator 

```c code
#include <stdio.h>
//simple calulator
//omar samy

int main(){
float  x ,y ;
char c ;
printf ( "enter the operator: ") ;
fflush (stdin) ; fflush (stdout) ;
scanf ( "%c",&c) ;
printf ( "enter two numbers:") ;
fflush (stdin) ; fflush (stdout) ;
scanf ( "%f%f",&x,&y) ;
//%.1f means displaying only 1 digit after the decimel .
switch (c) {
case '+' :
    printf (" %.1f + %.1f = %.1f" ,x,y,x+y) ;
    fflush (stdin) ; fflush (stdout);
    break;
case '-' :
    printf ("  %.1f - %.1f = %.1f" ,x,y,x-y) ;
    fflush (stdin) ; fflush (stdout) ;
    break;
    case '*' :
    printf ("  %.1f * %.1f = %.1f" ,x,y,x*y) ;
    fflush (stdin) ; fflush (stdout) ;
    break;
    case '/' :
    printf ("  %.1f / %.1f = %.1f" ,x,y,x/y) ;
    fflush (stdin) ; fflush (stdout) ;
    break;
    default :
    printf ("you entered invalid operator") ;
    break ;
}




return 0;
}
```
## 2- vowel or constant

```c code
#include <stdio.h>
//#include <stdlib.h>
// the charcter is vowel or constant
//omar samy

int main (){
	char x ;
	printf ("enter any character : ") ;
	fflush (stdout) ;
	scanf ("%c" , &x) ;
	fflush (stdout) ;
( x == 'a'|| x =='A' ||  x =='i' || x == 'I' ||  x =='o' ||  x =='O' || x == 'e' ||  x =='E' || x == 'u' || x == 'U' ) ?
			printf ("the charcter %c you entered is vowel " , x ) :
			printf ("the charcter %c you entered is constant " , x ) ;

	//fflush (stdin ) ;}

	return 0;

}

```

## 3- odd or even

```c code
#include <stdio.h>
//#include <stdlib.h>
//finding whether the number odd or even
//omar samy

int main (){
	int x ;
	printf ("enter any number : ") ;
	fflush (stdout) ;
	scanf ("%d" , &x) ;
	( x % 2 ==0  ) ? printf ("the number you entered is even " ) :
			printf ("the number you entered is odd " ) ;
	//fflush (stdin ) ;
	return 0;
}

}

```

## 4- check character

```c code
#include <stdio.h>
//finding whether the charcter is alphapet or not
//omar samy
int main () {
	char x = 'a';
	printf ("enter a charcter :") ;
	fflush (stdin) ; fflush(stdout);
	scanf ("%c", &x) ;
	if ( (x <= 'z'&& x >= 'a') || (x <= 'Z' && x >= 'A') )
	{

		printf ( "you entered the alphapet : %c" , x)  ;
		fflush (stdin) ; fflush(stdout);
	}
	else
	{ printf  ( " you didn't enter an alphapet") ;
	  fflush (stdin) ; fflush(stdout);
	}


	return 0 ;
}
```
## 5-finding the largest number

```c code
#include <stdio.h>
//finding the largest number
//omar samy

 int main() {
	int a , b , c ;
	printf(" enter three numbers :") ;
	fflush (stdin) ; fflush (stdout ) ;
	scanf("%d%d%d",&a,&b,&c );
	if ( a>b && a>c) {
		printf(" the largest number is : %d",a) ;
		fflush (stdin) ; fflush (stdout ) ;
	} else if (b>a && b>c ) {
		printf(" the largest number is : %d",b) ;
		fflush (stdin) ; fflush (stdout ) ;

	} else {
		printf(" the largest number is : %d",c) ;
		fflush (stdin) ; fflush (stdout ) ;

	}


	return 0 ;
}

```


[![MIT License](https://img.shields.io/badge/go%20to%20screenshots-1A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/c-assignments/c-basics/screen%20shot)

