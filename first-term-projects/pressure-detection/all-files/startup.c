
/* startup code  in c code for cortex m3 stmf103c6 

omar samy 
*/

#include "mod_int_standard.h"


void reset_handler() ;
extern void main() ;
void Default_Handler() 
{ 	
 reset_handler();	
}

/*
--> function that are weak can be replaced or overwritten
--> function that are alias are alias to common funtion ( default_handeler) 
*/

void NHI_handler() __attribute__ ((weak, alias ("Default_Handler"))) ;
void H_Fault_handler() __attribute__ ((weak, alias ("Default_Handler"))) ;
void MM_Fault_handler() __attribute__ ((weak, alias ("Default_Handler"))) ;
void Bus_Fault_handler() __attribute__ ((weak, alias ("Default_Handler"))) ;
void Usage_Fault_handler() __attribute__ ((weak, alias ("Default_Handler"))) ;



/* -->.vector section  is set to be the firt section in .text ( flash memory ) in linker script and the first index
 is (calculated ) is count as stack top and stored at address 0X08000000 (first address in .text )
 accodring to this processor memory layout specification then the function handlers are also spicified to be after 
 the reset handler according to this processor memory layout .
 --> stack top calulated in linker script to be after bss end address by 0x1000
 */ 
 
extern unint32 stack_top ;
 
unint32 vectors[] __attribute__ ((section(".vectors"))) ={
	              

	(unint32) &stack_top,
	(unint32) &reset_handler,
	(unint32) &NHI_handler,
	(unint32) &H_Fault_handler,
	(unint32) &MM_Fault_handler,
	(unint32) &Bus_Fault_handler,
	(unint32) &Usage_Fault_handler
		
};


/*
--> reset function 
*/

extern unint32 _E_text ;
extern unint32 _S_data ;
extern unint32 _E_data ;
extern unint32 _S_bss ;
extern unint32 _E_bss ;


void reset_handler() 
{
//coping data section from flash to ram byte by byte ->unint8

unint32 data_size = (unint8*) &_E_data - (unint8*) &_S_data ;

unint8* p_src = (unint8*)  &_E_text ;

unint8* p_dst = (unint8*)  &_S_data ;

vunint32 i;

for ( i =0 ; i < data_size ; i++ ) {
	
	*((unint8*)p_dst++) = *((unint8*)p_src++ ) ;
                                       }

// bss intialzation and setting it to 0
unint32 bss_size = (unint8*) &_E_bss - (unint8*) &_S_bss ;
 p_dst = (unint8*) &_S_bss ;

for ( i =0 ; i < bss_size ; i++ ) {
	
	*((unint8*) p_dst++ ) = (unint8) 0 ;
                                      }

// jump to main 
	main() ;

}

