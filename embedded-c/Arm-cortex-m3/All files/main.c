#include "mod_int_standard.h"

#define RCC_BASE    0x40021000
#define PORTA_BASE  0x40010800
//register that enables i/o
#define RCC_APB2ENR *(vunint32 *)(RCC_BASE + 0X18)

#define gpio_ODR  *(vunint32 *)(PORTA_BASE + 0X0c)
#define gpio_CRH  *(vunint32 *)(PORTA_BASE + 0X04)
// choose bit to set or clear from this macro
#define specefic_bit  13
#define pin_specific  pin##specefic_bit

//union approach to reach specific pin
typedef union {
	vunint32 all_feilds ;
	struct {
		vunint32 reserved:specefic_bit ;
		vunint32 pin_specific:1 ;
	}pin;
} porta_t ;


volatile porta_t* ptrporta = (volatile porta_t*)( PORTA_BASE + 0X0c) ;
unint32 var_bss[3] ;

int main(void)
{
	// ENABLES RCC CLOCK
	RCC_APB2ENR |= (1<<2) ;
	//
	gpio_CRH &= 0XFF0FFFFF ;
	gpio_CRH |= 0X00200000 ;



	/* Loop forever */
	while(1){
		vunint32 i ;
		// (*(vunint32*)(PORTA_BASE + 0X13)) |= 1<<specefic_bit ;

		ptrporta->pin.pin_specific=1;
		for (i=0;i <5000;i++);
		ptrporta->pin.pin_specific=0;
	//	(*(vunint32*)(PORTA_BASE + 0X13)) &= ~(1<<specefic_bit) ;

		for (i=0;i <5000;i++);



	}

}
