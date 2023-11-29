/* linker script for cortex-M4
TIVA C 
TM4C123GXL
@eng. omar samy  2023


*/

ENTRY(reset_handler) 

MEMORY 
{
flash(RX) : ORIGIN = 0X00000000, LENGTH = 512M
sram(RWX) : ORIGIN = 0X20000000, LENGTH = 512M 	 

}

SECTIONS 
{
	.text :{
		
      * (.vectors*)
	  * (.text*)
	  * (.rodata)
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
	}> sram
	


}