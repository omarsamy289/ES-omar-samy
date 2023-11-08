#include "stdio.h"
//program to add two distances (feet-inch input)
typedef struct Sdistance {
	int feet ;
	float inch ;
} distance ;
int main () {
	distance distance_1 ;
	distance distance_2 ;
	int feet_sum ;
	float inch_sum ;
	printf("enter the measures of the first distance:\n") ;
	fflush (stdout) ; fflush (stdin) ;
	printf("enter feet measure : ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf("%d",&distance_1.feet) ;
	printf("enter inches measure : ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf("%f",&distance_1.inch) ;
	printf("enter the measures of the second distance:\n") ;
	fflush (stdout) ; fflush (stdin) ;
	printf("enter feet measure : ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf("%d",&distance_2.feet) ;
	printf("enter inches measure : ") ;
	fflush (stdout) ; fflush (stdin) ;
	scanf("%f",&distance_2.inch) ;
	feet_sum = distance_1.feet + distance_2.feet ;
	inch_sum = distance_1.inch + distance_2.inch ;
	check_again :
	if ( inch_sum >= 12.0   ) {
		inch_sum= inch_sum - 12.0 ;
		++feet_sum;
		if (inch_sum >= 12.0 ) goto check_again ;
	}
	printf("\nsum of the two distances: %d\' %.2f\"" , feet_sum , inch_sum) ;
	fflush (stdout) ; fflush (stdin) ;
	return 0 ;
}


