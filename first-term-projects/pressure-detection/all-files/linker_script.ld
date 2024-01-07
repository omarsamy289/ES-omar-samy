/* linker script for cortex-m3

eng. omar samy 

*/

ENTRY(reset_handler) 

MEMORY 
{
flash(RX) : ORIGIN = 0X08000000, LENGTH = 128K
sram(RWX) : ORIGIN = 0X20000000, LENGTH = 20K 	 

}

SECTIONS 
{
	.text :{
		
      * (.vectors*)
	  * (.text*)
	  * (.rodata)
	  * (.pressure_vals)
	  _E_text = . ;
      }> flash
	  
	.data :{
		_S_data = . ;
		* (.data)
	. = ALIGN(4) ;	
		_E_data = . ;	
      }> sram AT> flash
	  
	.bss :{
		_S_bss = . ;
		* (.bss*)
		_E_bss = . ;
		. = ALIGN(4) ;
	}> sram
	. = . + 0x1000 ;
	stack_top = . ;



}