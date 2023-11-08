#include "stdio.h"
//calculating area of circle using #define
#define area(r)  (3.1415 *(r*r))
int main () {
	int radious ;
	float area ;
	printf ( "enter radious of the circle: ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf("%d",&radious) ;
	area = area(radious) ;
	printf ( "the area is %.2f",area) ;
	fflush (stdout) ; fflush (stdin) ;

	return 0 ;
}


