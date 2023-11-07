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


