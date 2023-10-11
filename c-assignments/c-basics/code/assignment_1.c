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
