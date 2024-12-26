/**
 * @brief this is the header file of the MCU STM32F103C6
 * 
 * 
 */


/** 
 * STM32F103Cx.h
 *
 *  Created on: Dec 24, 2024
 *      Author: OMAR SAMY
 */

#ifndef INC_STM32F103CX_H_
#define INC_STM32F103CX_H_


//-----------------------------
//Includes
//-----------------------------


#include <stdlib.h>
#include <stdint.h>

//=-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

//-----------------------------
//Base addresses for Memories
//-----------------------------

#define flash_memory_base 								0x08000000UL
#define System_memory_base 								0x1FFFF000UL
#define Peripherals_memory_base				 			0x40000000UL
#define SRAM_memory_base 								0x20000000UL
#define Cortex_M3_internal_peripherals_base			 	0xE0000000UL

//=-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-



//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------

#define RCC_base										0x40021000UL
#define Flash_memory_interface_base						0x40022000UL


//-----------------------------
//Base addresses for APB1 Peripherals
//-----------------------------

//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------



#define AFIO_base						0x40010000UL
#define EXTI_base						0x40010400UL
#define PortA_base						0x40010800UL
#define PortB_base						0x40010C00UL
#define PortC_base						0x40011000UL
#define PortD_base						0x40011400UL
#define PortE_base						0x40011800UL



//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t CR ;
	volatile uint32_t CFGR ;
	volatile uint32_t CIR ;
	volatile uint32_t APB2RSTR ;
	volatile uint32_t APB1RSTR ;
	volatile uint32_t AHBENR ;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR ;
	volatile uint32_t BDCR ;
	volatile uint32_t CSR ;
}RCC_typedef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t IMR ;
	volatile uint32_t EMR ;
	volatile uint32_t RTSR ;
	volatile uint32_t FTSR ;
	volatile uint32_t SWIER ;
	volatile uint32_t PR ;

}EXTI_typedef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t EVCR ;
	volatile uint32_t MAPR ;
	volatile uint32_t EXTICR1 ;
	volatile uint32_t EXTICR2 ;
	volatile uint32_t EXTICR3 ;
	volatile uint32_t EXTICR4 ;
	volatile uint32_t RESERVED0;
	volatile uint32_t MAPR2;

}AFIO_typedef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t CRL ;
	volatile uint32_t CRH ;
	volatile uint32_t IDR ;
	volatile uint32_t ODR ;
	volatile uint32_t BSRR ;
	volatile uint32_t BRR ;
	volatile uint32_t LCKR;


}GPIO_typedef;





//=-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA 		((GPIO_typedef *)(PortA_base))
#define GPIOB 		((GPIO_typedef *)(PortB_base))
#define GPIOC 		((GPIO_typedef *)(PortC_base))
#define GPIOD 		((GPIO_typedef *)(PortD_base))
#define GPIOE 		((GPIO_typedef *)(PortE_base))

#define RCC 		((RCC_typedef *)(RCC_base))

#define EXTI 		((EXTI_typedef *)(EXTI_base))

#define AFIO		((AFIO_typedef *)(AFIO_base))
//=-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define RCC_GPIOA_CLK_EN() 		(RCC->APB2ENR |= 1<<2 )
#define RCC_GPIOB_CLK_EN() 		(RCC->APB2ENR |= 1<<3 )
#define RCC_GPIOC_CLK_EN() 		(RCC->APB2ENR |= 1<<4 )
#define RCC_GPIOD_CLK_EN() 		(RCC->APB2ENR |= 1<<5 )
#define RCC_GPIOE_CLK_EN() 		(RCC->APB2ENR |= 1<<6 )


#define RCC_AFIO_CLK_EN() 		(RCC->APB2ENR |= 1<<0 )



//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*



#endif /* INC_STM32F103CX_H_ */
