#include "mod_int_standard.h"
#include "uart.h"


unint8 string[100] = " learn-in-depth : omar samy" ;

void main (void) {


	uart_send_string (string);


}
