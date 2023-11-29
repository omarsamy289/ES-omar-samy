
/* startup code  in c code for cortex m4 
TIVA C 
TM4C123GXL

@ omar samy  2023
*/

#include "mod_int_standard.h"


void reset_handler() ;
extern int main(void) ;
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
 is (calculated ) is count as stack top and stored at address 0X00000000 (first address in .text -> (scetion .vectors -> ( stack_top info ) )
 accodring to this processor memory layout specification then the function handlers are also spicified to be after 
 the reset handler according to this processor memory layout .
 --> stack top is calculated to be astatic array of 256 elements which indicates 1024 byte ( size of the stack memory  in  .bss means that stack 
 top points to the the address of  stack_top[0] + 256 elements results in the end of this array as the stack top points to the top of the stack .
 @ omar samy 2023
 */ 
 
 static unint32 stack_top[256] ;
 
// array of pointers that point to function that takes no arguments and return void --> the pointrt itself is constent
//the pointer is 4 byte which indicate each handler itsels is 4 byte 
void (* const g_p_fn_vectors[])() __attribute__ ((section(".vectors"))) ={
	
	(void (*)()) ( (unint32)stack_top +sizeof(stack_top)),
	 &reset_handler,
	 &NHI_handler,
	 &H_Fault_handler,
	 &MM_Fault_handler,
	 &Bus_Fault_handler,
	 &Usage_Fault_handler
	
	
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

