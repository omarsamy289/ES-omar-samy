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

