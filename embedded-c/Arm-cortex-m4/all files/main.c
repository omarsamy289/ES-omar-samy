/*
ARM cortex m4 
TIVA C 
TM4c123GXL
omar samy
*/
#include "mod_int_standard.h"

//SYSTEM CLOCK REGISTER
#define SYSCTL_RCGC2_R   *((vunint32*)(0x400FE000 + 0x108))
// PORT DIRECTION REGISTER
#define GPIO_PORTF_DIR_R   *((vunint32*)(0x40025000 + 0x400))
// PORT  DATA REGISTER 
#define GPIO_PORTF_DATA_R   *((vunint32*)(0x40025000 + 0x3FC))
//PORT ENABLE REGISTER
#define GPIO_PORTF_DEN_R   *((vunint32*)(0x40025000 + 0x51C))



int main()
{
	
	vunint32 count ;
	// ENABLES RCC CLOCK
SYSCTL_RCGC2_R  = 0x20 ;
// dalay 
for ( count =0 ; count < 300 ; count ++) ; 

//direction is out for pin3 portf 
GPIO_PORTF_DIR_R |= 1<<3 ; 

// data enabling register 
GPIO_PORTF_DEN_R |= 1<<3 ; 

while (1)
{
GPIO_PORTF_DATA_R |= 1<<3 ;	
	for ( count =0 ; count < 200000 ; count ++) ; 
GPIO_PORTF_DATA_R &= ~(1<<3) ;		
	for ( count =0 ; count < 200000 ; count ++) ; 	
}


return 0 ;	
}
