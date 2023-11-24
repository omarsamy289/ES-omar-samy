
#include "mod_int_standard.h"
#include "uart.h"
// uart tx register
#define UART0DR  *(vunint32 *)((unint32 *)0x101f1000+ 0x0)

void uart_send_string (unint8* pstring ) {

	while (*pstring != '\0') {


		UART0DR = (unint32) *pstring ;
		pstring ++ ;

	}




}
