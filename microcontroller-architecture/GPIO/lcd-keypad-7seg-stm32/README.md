 
 

<div align="center">
  
[![20YLRhN.md.png](https://iili.io/20YLRhN.md.png)]()

  </div>



<div align="center">
  
---------

</div>




[![MIT License](https://img.shields.io/badge/ALL%20FILES%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/microcontroller-architecture/GPIO/lcd-keypad-7seg-stm32/ALL%20FILES)

# LAB  - GPIO DRIVERS GONFIGURATION ON STM32F103C6
 
&nbsp;
* on stm32f103c6 :
>* creating hash file for all the mcu features and priphrals
>* creating gpio driver featuring gpio modes and some API's
>* creating lcd and keypad drivers for stm32
>* adding 7segment single digit disply
&nbsp;





## PROTEUS CAPTURE

> ![Alt Text](https://s7.gifyu.com/images/SXJI3.gif) 
&nbsp;


&nbsp;



## MCU MAIN HASH FILE  : 

* stm32f103c6.h

```c code
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

```

## GPIO DRIVER HASH FILE  : 

* stm32f103c6_gpio.h

```c code
/*
 * stm32f103c6_gpio.h
 *
 *  Created on: Dec 24, 2024
 *      Author: OMAR SAMY
 */

#ifndef INC_STM32F103C6_GPIO_H_
#define INC_STM32F103C6_GPIO_H_




//-----------------------------
//Includes
//-----------------------------

#include "STM32F103Cx.h"


//-----------------------------
//User type definitions (structures)
//-----------------------------
//-----------------------------

typedef struct {


uint16_t PinNumber ; /* specifies the pin number to be configured
						options can be found @ref_gpio_pin_number*/
uint8_t GpioMode ;/* specifies the pin mode to be configured
						options can be found @ref_gpio_mode*/
uint8_t GpioSpeed ; /* specifies the output speed to be configured
						options cen be found @ref_gpio_speed*/

}GPIO_config_t;




//Macros Configuration References


//-----------------------------
/*@ref_gpio_pin_number
*/
#define GPIO_PIN0 				((uint16_t)0x0001) /* pin 0 selected 0001 */
#define GPIO_PIN1 				((uint16_t)0x0002) /* pin 1 selected 0010*/
#define GPIO_PIN2 				((uint16_t)0x0004) /* pin 2 selected 0100*/
#define GPIO_PIN3 				((uint16_t)0x0008) /* pin 3 selected 1000*/
#define GPIO_PIN4 				((uint16_t)0x0010) /* pin 4 selected */
#define GPIO_PIN5 				((uint16_t)0x0020) /* pin 5 selected */
#define GPIO_PIN6 				((uint16_t)0x0040) /* pin 6 selected */
#define GPIO_PIN7				((uint16_t)0x0080) /* pin 7 selected */
#define GPIO_PIN8 				((uint16_t)0x0100) /* pin 8 selected */
#define GPIO_PIN9				((uint16_t)0x0200) /* pin 9 selected */
#define GPIO_PIN10				((uint16_t)0x0400) /* pin 10 selected */
#define GPIO_PIN11				((uint16_t)0x0800) /* pin 11 selected */
#define GPIO_PIN12				((uint16_t)0x1000) /* pin 12 selected */
#define GPIO_PIN13 				((uint16_t)0x2000) /* pin 13 selected */
#define GPIO_PIN14				((uint16_t)0x4000) /* pin 14 selected */
#define GPIO_PIN15				((uint16_t)0x8000) /* pin 15 selected */
#define GPIO_PIN_ALL			((uint16_t)0xFFFF) /* all pins selected */

#define GPIO_PIN_MASK			(0x0000FFFFu)	   /* pin mask */


//-----------------------------
/*@ref_gpio_GpioMode
*/

/*
In input mode (MODE[1:0]=00):
1: Analog mode
2: Floating input (reset state)
3: Input with pull-up / pull-down
In output mode (MODE[1:0] > 00):
4: General purpose output push-pull
5: General purpose output Open-drain
6: Alternate function output Push-pull
7: Alternate function output Open-drain
8: Alternate function input
*/
#define GPIO_MODE_Analog 					0x00000000u // Analog mode
#define GPIO_MODE_Floating_input 			0x00000001u // Floating input (high z)
#define GPIO_MODE_Input_pull_up				0x00000002u // Input with pull-up
#define GPIO_MODE_Input_pull_down 			0x00000003u // Input with pull-down
#define GPIO_MODE_output_push_pull			0x00000004u // General purpose output push-pull
#define GPIO_MODE_output_open_drain 		0x00000005u // General purpose output Open-drain
#define GPIO_MODE_Afio_PP					0x00000006u // Alternate function output Push-pull
#define GPIO_MODE_Afio_OD 					0x00000007u // Alternate function output Open-drain
#define GPIO_MODE_Afio_Input 				0x00000008u // Alternate function input



//-----------------------------
/*@ref_gpio_Gpiospeed
*/

/*
1: Output mode, max speed 10 MHz.
2: Output mode, max speed 2 MHz.
3: Output mode, max speed 50 MHz
*/

#define GPIO_speed10MHz 	0x00000001u//Output mode, max speed 10 MHz.
#define GPIO_speed2MHz   	0x00000002u//Output mode, max speed 2 MHz.
#define GPIO_speed50MHz 	0x00000003u//Output mode, max speed 50 MHz.






//@ref GPIO_PIN_VALUE

#define PIN_SET 	1//1
#define PIN_RESET 	0//0


//@ref GPIO_LOCK_state

#define LOCK_ENABLED	1//1
#define LOCK_FAILED 	0//0

/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

void        MCAL_GPIO_INIT(GPIO_typedef* GPIOx,GPIO_config_t* configx ) ;
void        MCAL_GPIO_DEINIT(GPIO_typedef* GPIOx ) ;
uint8_t     MCAL_GPIO_READPIN(GPIO_typedef* GPIOx, uint16_t PinNumber ) ;
uint16_t    MCAL_GPIO_READPORT(GPIO_typedef* GPIOx ) ;
void  	    MCAL_GPIO_WRITEPIN(GPIO_typedef* GPIOx , uint16_t PinNumber , uint8_t value) ;
void  	    MCAL_GPIO_WRITEPORT(GPIO_typedef* GPIOx , uint16_t value) ;
void  	 	MCAL_GPIO_togglePIN(GPIO_typedef* GPIOx , uint16_t PinNumber) ;
void  	 	MCAL_GPIO_togglePort(GPIO_typedef* GPIOx ) ;
uint8_t     MCAL_GPIO_LCKPIN(GPIO_typedef* GPIOx , uint16_t PinNumber) ;


#endif /* INC_STM32F103C6_GPIO_H_ */

```

## GPIO DRIVER SOURCE FILE  : 

* * stm32f103c6_gpio.c

```c code


/**
 * @brief this file is the source code file for the gpio driver 
 * 
 * 
 * 
 */




/** 
 * stm32f103c6_gpio.c
 *
 *  Created on: Dec 24, 2024
 *      Author: OMAR SAMY
 */
#include "STM32F103Cx.h"
#include "stm32f103c6_gpio.h"




/// @brief this function gets the pin location on registers CRL and CRH
/// @param PinNumber 
/// @return 0
uint16_t MCAL_GPIO_CRLH (uint16_t PinNumber ) {

	switch(PinNumber)
	{

	case GPIO_PIN0 :
		return 0 ;
		break;
	case GPIO_PIN1 :
		return 4 ;
		break;
	case GPIO_PIN2 :
		return 8 ;
		break;
	case GPIO_PIN3 :
		return 12 ;
		break;

	case GPIO_PIN4 :
		return 16 ;
		break;

	case GPIO_PIN5 :
		return 20 ;
		break;

	case GPIO_PIN6 :
		return 24 ;
		break;

	case GPIO_PIN7 :
		return 28 ;
		break;



	case GPIO_PIN8 :
		return 0 ;
		break;
	case GPIO_PIN9 :
		return 4 ;
		break;
	case GPIO_PIN10 :
		return 8 ;
		break;
	case GPIO_PIN11 :
		return 12 ;
		break;

	case GPIO_PIN12 :
		return 16 ;
		break;

	case GPIO_PIN13 :
		return 20 ;
		break;

	case GPIO_PIN14:
		return 24 ;
		break;

	case GPIO_PIN15 :
		return 28 ;
		break;




	}
	return 0 ;
}
/**
 * @Fn-MCAL_GPIO_INIT
 * @brief - initialize the specific gpio port or pin
 * @param [in] -GPIOx specifies the gpio instant and register to be configured
 * @param [in] -configx specifies the type of the configuration to be done
 * @retval - none
 * Note- the package LQF48 has only instant of gpio A,B and  part of C,D
 */
void MCAL_GPIO_INIT(GPIO_typedef* GPIOx,GPIO_config_t* configx ) {



	//	Port configuration register low (GPIOx_CRL) (x=0..7)
	//	Port configuration register high (GPIOx_CRH) (x=8..15)


	volatile uint32_t* configRegister = NULL  ;
	uint8_t PINType =0 ;
	configRegister = (configx->PinNumber < GPIO_PIN8)?  &GPIOx->CRL : &GPIOx->CRH ;

	// clear  CNFx[1:0] MODEx[1:0]

	(*configRegister) &= ~(0xF << MCAL_GPIO_CRLH(configx->PinNumber) ) ;

	// if pin to be configured as output
	if ((configx->GpioMode == GPIO_MODE_output_push_pull)||(configx->GpioMode == GPIO_MODE_output_open_drain) ||
			(configx->GpioMode == GPIO_MODE_Afio_PP) || (configx->GpioMode == GPIO_MODE_Afio_OD)){
		// set  CNFx[1:0] MODEx[1:0]
		PINType = (((((configx->GpioMode) - 4) <<2 ) |   (configx->GpioSpeed)) & 0x0f ) ;
	}
	// if pin to be configured as input ->	MODEx[00]
	else
	{

		if ((configx->GpioMode == GPIO_MODE_Floating_input)||(configx->GpioMode == GPIO_MODE_Analog))
		{
			// set  CNFx[1:0] MODEx[00]
			PINType = (((((configx->GpioMode) ) << 2 ) |   (0x0)) & 0x0f ) ;
		}else if((configx->GpioMode == GPIO_MODE_Afio_Input))
		{

			// set  CNFx[1:0] MODEx[00]
			PINType = (((((GPIO_MODE_Floating_input) ) << 2 ) |   (0x0)) & 0x0f ) ;

		}else // input PU PD
		{

			PINType = (((((GPIO_MODE_Input_pull_up) ) << 2 ) |   (0x0)) & 0x0f ) ;

			if ((configx->GpioMode == GPIO_MODE_Input_pull_up)) {
				// input PU set ODRx to 1
				GPIOx->ODR |= (configx->PinNumber) ;

			}else
			{
				// input PD reset ODRx to 0

				GPIOx->ODR &= ~(configx->PinNumber) ;


			}


		}




	}


	// write on  CRL or CRH
	(*configRegister)  |= ((PINType) << (MCAL_GPIO_CRLH(configx->PinNumber)) );

}



/**
 * @Fn-MCAL_GPIO_INIT
 * @brief - deinitialize or restet the specific gpio port or registers
 * @param [in] -GPIOx specifies the gpio instant and register to be configured
 * @retval - none
 * Note- the package LQF48 has only instant of gpio A,B and  part of C,D
 */
void MCAL_GPIO_DEINIT(GPIO_typedef* GPIOx ) {

	if (GPIOx == GPIOA)
	{
		RCC->APB2RSTR |= (1<<2); // BIT2 RESET GPIOA
		RCC->APB2RSTR &= ~(1<<2) ;

	}else if (GPIOx == GPIOB)
	{
		RCC->APB2RSTR |= (1<<3); // BIT3 RESET GPIOB
		RCC->APB2RSTR &= ~(1<<3) ;

	}else if (GPIOx == GPIOC)
	{
		RCC->APB2RSTR |= (1<<4); // BIT4 RESET GPIOC
		RCC->APB2RSTR &= ~(1<<4) ;

	}else if (GPIOx == GPIOD)
	{
		RCC->APB2RSTR |= (1<<5); // BIT5 RESET GPIOD
		RCC->APB2RSTR &= ~(1<<5) ;

	}else if (GPIOx == GPIOE)
	{
		RCC->APB2RSTR |= (1<<6); // BIT6 RESET GPIOE
		RCC->APB2RSTR &= ~(1<<6) ;

	}


}

/**
 * @Fn MCAL_GPIO_READPIN
 * @brief -read specificPIN
 * @param [in] -GPIOx specifies the gpio instant and register to be configured
 * @param [in] -PinNumber specifies pin to be read the data from
 * @retval - uint8_t @ref GPIO_PIN_VALUE
 * Note- the package LQF48 has only instant of gpio A,B and  part of C,D
 */
uint8_t  MCAL_GPIO_READPIN(GPIO_typedef* GPIOx, uint16_t PinNumber )
{
	uint8_t pin_value ;

	if ( ((GPIOx->IDR) & PinNumber)!= (uint32_t)PIN_RESET )
	{
		pin_value = PIN_SET ;



	}else
	{

		pin_value = PIN_RESET ;

	}

	return pin_value ;
}




/**
 * @Fn-MCAL_GPIO_READPORT
 * @brief -read specific port
 * @param [in] -GPIOx specifies the gpio instant and register to be configured
 * @retval - uint16_t
 * Note-none
 */
uint16_t   MCAL_GPIO_READPORT(GPIO_typedef* GPIOx )  {

	uint16_t port_value ;

	port_value = (uint16_t)GPIOx->IDR ;
	return port_value ;



}







/**
 * @Fn-MCAL_GPIO_WRITEPIN
 * @brief -write on  specific pin
 * @param [in] -GPIOx specifies the gpio instant and register to be configured
 * @param [in] -PinNumber specifies pin to be write the data on
 * @param [in] -value specifies the value to be written
 * @retval - none
 * Note-none
 */
void   MCAL_GPIO_WRITEPIN(GPIO_typedef* GPIOx , uint16_t PinNumber , uint8_t value) {
	if ( value != (uint8_t)PIN_RESET )
	{
		//	GPIOx->ODR |= PinNumber  ;
		GPIOx->BSRR = (uint32_t)PinNumber  ;
	}else
	{
		//	GPIOx->ODR &= ~(PinNumber)  ;
		GPIOx->BRR = (uint32_t)PinNumber  ;
	}

}


/**
 * @Fn-MCAL_GPIO_WRITEPOR
 * @brief -write on  specific port
 * @param [in] -GPIOx specifies the gpio instant and register to be configured
 * @param [in] -value specifies the value to be written
 * @retval - none
 * Note-none
 */
void   MCAL_GPIO_WRITEPORT(GPIO_typedef* GPIOx , uint16_t value) {


	GPIOx->ODR = (uint32_t)value ;
}



/**
 * 
 * @Fn-MCAL_GPIO_togglePIN
 * @brief -toggle  specific pin
 * @param [in] -GPIOx specifies the gpio instant and register to be configured
 * @param [in] -PinNumber specifies the pin to be toggled
 * @retval - none
 * Note-none
 */
void   MCAL_GPIO_togglePIN(GPIO_typedef* GPIOx , uint16_t PinNumber) {

	GPIOx ->ODR ^= PinNumber ;

}

/**
 * @Fn-MCAL_GPIO_togglePort
 * @brief -toggle  specific port
 * @param [in] -GPIOx specifies the gpio instant and register to be configured
 * @retval - none
 * Note-none
 */
void   MCAL_GPIO_togglePort(GPIO_typedef* GPIOx ) {

	GPIOx ->ODR ^=  GPIOx ->ODR ;


}
/**
 * @Fn-MCAL_GPIO_LCKPIN
 * @brief -write on  specific port
 * @param [in] -GPIOx specifies the gpio instant and register to be configured
 * @param [in] -PinNumber specifies the pin to be LOCKED
 * @retval - none
 * Note-none
 */
uint8_t   MCAL_GPIO_LCKPIN(GPIO_typedef* GPIOx , uint16_t PinNumber) {
/*
	Bit 16 LCKK[16]: Lock key
	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	0: Port configuration lock key not active
	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	LOCK key writing sequence:
	Write 1
	Write 0
	Write 1
	Read 0
	Read 1 (this read is optional but confirms that the lock is active)
	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	Any error in the lock sequence will abort the lock.
	Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	These bits are read write but can only be written when the LCKK bit is 0.
	0: Port configuration not locked
	1: Port configuration locked
*/


volatile uint32_t LCKpin = 1<<16 ;

LCKpin |= PinNumber ;


//Write 1
GPIOx->LCKR = LCKpin ;
//Write 0
GPIOx->LCKR = PinNumber ;
//	Write 1
GPIOx->LCKR = LCKpin ;
//	Read 0
LCKpin = GPIOx->LCKR  ;
//	Read 1
if ( (uint32_t)(GPIOx->LCKR & 1<<16) )
{

	return LOCK_ENABLED ;

}else

{

	return LOCK_FAILED ;

}






}



```



## keypad driver hash file : 

* keypad.h

```c code


/*
 * keypad.h
 *
 * Created: 12/19/2024 4:25:25 PM
 *  Author: omar
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_


#include "STM32F103Cx.h"
#include "stm32f103c6_gpio.h"
	GPIO_config_t pinconfig ;



#define SET_BIT(ADDRESS,BIT) ADDRESS |= (1<<BIT)
#define RESET_BIT(ADDRESS,BIT) ADDRESS &= ~(1<<BIT)
#define TOGGLE_BIT(ADDRESS,BIT) ADDRESS ^= (1<<BIT)
#define READ_BIT(ADDRESS,BIT) (ADDRESS & (1<<BIT) >> BIT)



#define ROW1 GPIO_PIN0
#define ROW2 GPIO_PIN1
#define ROW3 GPIO_PIN3
#define ROW4 GPIO_PIN4
#define COL1 GPIO_PIN5
#define COL2 GPIO_PIN6
#define COL3 GPIO_PIN7
#define COL4 GPIO_PIN8

#define KEYPAD_PORT GPIOB

void KEYPAD_INIT();
char KEYPAD_GETKEY();










#endif /* KEYPAD_H_ */


```


## keypad source file : 

* keypad.c

```c code

/*
 * keypad.c
 *
 * Created: 12/19/2024 4:25:38 PM
 *  Author: omar
 */

#include <KEYPAD_DRIVER/keypad.h>
int Keypad_Row[] = { ROW1, ROW2, ROW3, ROW4 }; //rows of the keypad
int Keypad_Col[] = { COL1, COL2, COL3, COL4 }; //columns

void KEYPAD_INIT() {
//
//	RESET_BIT(DataDir_KEYPAD_PORT,ROW1) ;
//	RESET_BIT(DataDir_KEYPAD_PORT,ROW2) ;
//	RESET_BIT(DataDir_KEYPAD_PORT,ROW3) ;
//	RESET_BIT(DataDir_KEYPAD_PORT,ROW4) ;
	pinconfig.PinNumber = ROW1;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(KEYPAD_PORT, &pinconfig);

	pinconfig.PinNumber = ROW2;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(KEYPAD_PORT, &pinconfig);

	pinconfig.PinNumber = ROW3;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(KEYPAD_PORT, &pinconfig);

	pinconfig.PinNumber = ROW4;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(KEYPAD_PORT, &pinconfig);

	pinconfig.PinNumber = COL1;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(KEYPAD_PORT, &pinconfig);
	pinconfig.PinNumber = COL2;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(KEYPAD_PORT, &pinconfig);

	pinconfig.PinNumber = COL3;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(KEYPAD_PORT, &pinconfig);

	pinconfig.PinNumber = COL4;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(KEYPAD_PORT, &pinconfig);

//	SET_BIT (DataDir_KEYPAD_PORT,COL1) ;
//	SET_BIT (DataDir_KEYPAD_PORT,COL2) ;
//	SET_BIT (DataDir_KEYPAD_PORT,COL3) ;
//	SET_BIT (DataDir_KEYPAD_PORT,COL4) ;
//	KEYPAD_PORT = 0xFF;
	MCAL_GPIO_WRITEPORT(KEYPAD_PORT, 0xFF);
}


char KEYPAD_GETKEY() {

	volatile unsigned int i, j;

	for (i = 0; i < 4; i++) {

//		SET_BIT(KEYPAD_PORT,Keypad_Col[0]) ;
//		SET_BIT(KEYPAD_PORT,Keypad_Col[1]) ;
//		SET_BIT(KEYPAD_PORT,Keypad_Col[2]) ;
//		SET_BIT(KEYPAD_PORT,Keypad_Col[3]) ;
//		RESET_BIT(KEYPAD_PORT,Keypad_Col[i]) ;

		MCAL_GPIO_WRITEPIN(KEYPAD_PORT, Keypad_Col[0], PIN_SET);
		MCAL_GPIO_WRITEPIN(KEYPAD_PORT, Keypad_Col[1], PIN_SET);
		MCAL_GPIO_WRITEPIN(KEYPAD_PORT, Keypad_Col[2], PIN_SET);
		MCAL_GPIO_WRITEPIN(KEYPAD_PORT, Keypad_Col[3], PIN_SET);
		MCAL_GPIO_WRITEPIN(KEYPAD_PORT, Keypad_Col[i], PIN_RESET);

		for (j = 0; j < 4; j++) {

			if ((MCAL_GPIO_READPIN(KEYPAD_PORT,Keypad_Row[j])) == 0) {
				while (!(MCAL_GPIO_READPIN(KEYPAD_PORT,Keypad_Row[j])));
				switch (i) {
				case (0):
					if (j == 0)
						return '7';
					else if (j == 1)
						return '4';
					else if (j == 2)
						return '1';
					else if (j == 3)
						return '?';
					break;
				case (1):
					if (j == 0)
						return '8';
					else if (j == 1)
						return '5';
					else if (j == 2)
						return '2';
					else if (j == 3)
						return '0';
					break;
				case (2):
					if (j == 0)
						return '9';
					else if (j == 1)
						return '6';
					else if (j == 2)
						return '3';
					else if (j == 3)
						return '=';
					break;
				case (3):
					if (j == 0)
						return '/';
					else if (j == 1)
						return '*';
					else if (j == 2)
						return '-';
					else if (j == 3)
						return '+';
					break;
				}
			}
		}
	}
	return 'A';

}


```


## LCD driver hash file : 

* lcd.h

```c code

/*
 * lcd.h
 *
 * Created: 12/19/2024 4:24:26 PM
 *  Author: omar
 */ 


#ifndef LCD_H_
#define LCD_H_
//#define F_CPU 1000000UL


#include "STM32F103Cx.h"
#include "stm32f103c6_gpio.h"

	GPIO_config_t pinconfig ;


#define SET_BIT(ADDRESS,BIT) ADDRESS |= (1<<BIT)
#define RESET_BIT(ADDRESS,BIT) ADDRESS &= ~(1<<BIT)
#define TOGGLE_BIT(ADDRESS,BIT) ADDRESS ^= (1<<BIT)
#define READ_BIT(ADDRESS,BIT) (ADDRESS & (1<<BIT) >> BIT)









#define LCD_PORT GPIOA
#define LCD_CTRL GPIOA
#define RS_SWITCH GPIO_PIN8
#define RW_SWITCH GPIO_PIN9
#define EN_SWITCH GPIO_PIN10
// #define DATA_shift 0 // in 8 bit mode 0 and in 4 bit mode 4

#define EIGHT_BIT_MODE
//#define FOUR_BIT_MODE

#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)




void LCD_INIT(void);
void LCD_COMM(unsigned char);
void LCD_WRITE_char(unsigned char);
void LCD_WRITE_string( char*);

void LCD_stat(void);
void LCD_kick(void);
void LCD_clear_screen();
void LCD_adjust_XY(unsigned char line, unsigned char position);
void wait(int ) ;
void LCD_INIT_ALL() ;


#endif /* LCD_H_ */



```


## LCD driver source file : 

* lcd.c

```c code



/*
* lcd.c
*
* Created: 12/19/2024 4:24:39 PM
*  Author: omar
*/

#include <LCD_DRIVER/lcd.h>
//#include "STM32F103Cx.h"
//#include "stm32f103c6_gpio.h"
//

	void wait(int time) {
	int j, i ;
	for (i=0 ; i< time ; i ++)
		for (j=0 ; j< 255 ; j ++) ;

	}


void LCD_stat(void) {
	
//DDRA set 0 read
//DataDir_LCD_PORT &= ~(0xFF<< DATA_shift) ;
	// data pins
		///PORTA.PIN0 GPIO_MODE_Floating_input
		pinconfig.PinNumber = GPIO_PIN0;
		pinconfig.GpioMode = GPIO_MODE_output_push_pull;
		pinconfig.GpioSpeed = GPIO_speed10MHz;
		MCAL_GPIO_INIT(LCD_PORT, &pinconfig);
		///PORTA.PIN1 output_push_pull
		pinconfig.PinNumber = GPIO_PIN1;
		pinconfig.GpioMode = GPIO_MODE_output_push_pull;
		pinconfig.GpioSpeed = GPIO_speed10MHz;
		MCAL_GPIO_INIT(LCD_PORT, &pinconfig);
		///PORTA.PIN2 output_push_pull
		pinconfig.PinNumber = GPIO_PIN2;
		pinconfig.GpioMode = GPIO_MODE_output_push_pull;
		pinconfig.GpioSpeed = GPIO_speed10MHz;
		MCAL_GPIO_INIT(LCD_PORT, &pinconfig);
		///PORTA.PIN3 output_push_pull
		pinconfig.PinNumber = GPIO_PIN3;
		pinconfig.GpioMode = GPIO_MODE_output_push_pull;
		pinconfig.GpioSpeed = GPIO_speed10MHz;
		MCAL_GPIO_INIT(LCD_PORT, &pinconfig);
		///PORTA.PIN4 output_push_pull
		pinconfig.PinNumber = GPIO_PIN4;
		pinconfig.GpioMode = GPIO_MODE_output_push_pull;
		pinconfig.GpioSpeed = GPIO_speed10MHz;
		MCAL_GPIO_INIT(LCD_PORT, &pinconfig);
		///PORTA.PIN5 output_push_pull
		pinconfig.PinNumber = GPIO_PIN5;
		pinconfig.GpioMode = GPIO_MODE_output_push_pull;
		pinconfig.GpioSpeed = GPIO_speed10MHz;
		MCAL_GPIO_INIT(LCD_PORT, &pinconfig);
		///PORTA.PIN6 output_push_pull
		pinconfig.PinNumber = GPIO_PIN6;
		pinconfig.GpioMode = GPIO_MODE_output_push_pull;
		pinconfig.GpioSpeed = GPIO_speed10MHz;
		MCAL_GPIO_INIT(LCD_PORT, &pinconfig);
		///PORTA.PIN7 output_push_pull
		pinconfig.PinNumber = GPIO_PIN7;
		pinconfig.GpioMode = GPIO_MODE_output_push_pull;
		pinconfig.GpioSpeed = GPIO_speed10MHz;
		MCAL_GPIO_INIT(LCD_PORT, &pinconfig);

//1
	/*Selects read or write.
	0: Write 
	1: Read    <<<< */
		MCAL_GPIO_WRITEPIN(LCD_CTRL, RW_SWITCH, PIN_SET) ;
//	SET_BIT(LCD_CTRL,RW_SWITCH);
	
//2	
	/* Selects registers.
	0: Instruction register (for write) Busy flag:  <<<<<<<
	address counter (for read)
	1: Data register (for write and read) */
//	RESET_BIT(LCD_CTRL,RS_SWITCH);
	MCAL_GPIO_WRITEPIN(LCD_CTRL, RS_SWITCH, PIN_RESET) ;

	
//3
	LCD_kick();
	
//4 
     //DDRA set 0 read
	//DataDir_LCD_PORT &= ~(0xFF<<DATA_shift);
	
//5
	/*Selects read or write.
	0: Write  <<<<<<
	1: Read     */
//	RESET_BIT(LCD_CTRL,RW_SWITCH);
	MCAL_GPIO_WRITEPIN(GPIOA, RW_SWITCH, PIN_RESET) ;
}


void LCD_INIT_ALL() {
	wait(20) ;
	LCD_INIT() ;
	LCD_clear_screen() ;
	wait(15) ;
	LCD_COMM(LCD_FUNCTION_8BIT_2LINES);
	LCD_COMM(LCD_ENTRY_MODE);
	LCD_COMM(LCD_BEGIN_AT_FIRST_ROW);
	LCD_COMM(LCD_DISP_ON_CURSOR_BLINK);

}

void LCD_kick(void){
//	SET_BIT(LCD_CTRL,EN_SWITCH);
	MCAL_GPIO_WRITEPIN(LCD_CTRL, EN_SWITCH, PIN_SET) ;

	wait(5);
	//Starts data read/write <<<
//	RESET_BIT(LCD_CTRL,EN_SWITCH);
	MCAL_GPIO_WRITEPIN(LCD_CTRL, EN_SWITCH, PIN_RESET) ;

}


void LCD_COMM(unsigned char command ){
	LCD_stat();
	//#ifdef EIGHT_BIT_MODE

//	LCD_PORT = command ;
MCAL_GPIO_WRITEPORT(LCD_PORT, command) ;
	/* Selects registers.
	0: Instruction register (for write) Busy flag:  <<<<<<<
	address counter (for read)
	1: Data register (for write and read) */
//	RESET_BIT(LCD_CTRL,RS_SWITCH);
	MCAL_GPIO_WRITEPIN(LCD_CTRL, RW_SWITCH, PIN_RESET) ;
	/*Selects read or write.
	0: Write <<<<
	1: Read*/
//	RESET_BIT(LCD_CTRL,RW_SWITCH);
MCAL_GPIO_WRITEPIN(LCD_CTRL, RS_SWITCH, PIN_RESET) ;
	
	wait(5);
	LCD_kick();
//	#endif
//
//	#ifdef FOUR_BIT_MODE
//	// >> least four bit
//	LCD_PORT = (LCD_PORT& 0x0F)| (command & 0xF0) ;
//	/* Selects registers.
//	0: Instruction register (for write) Busy flag:  <<<<<<<
//	address counter (for read)
//	1: Data register (for write and read) */
//	RESET_BIT(LCD_CTRL,RS_SWITCH);
//	/*Selects read or write.
//	0: Write <<<<
//	1: Read*/
//	RESET_BIT(LCD_CTRL,RW_SWITCH);
//	wait(1);
//	LCD_kick();
//
//	// >> most four bit
//	LCD_stat();
//	LCD_PORT = (LCD_PORT& 0x0F)| (command << 4) ;
//	/* Selects registers.
//	0: Instruction register (for write) Busy flag:  <<<<<<<
//	address counter (for read)
//	1: Data register (for write and read) */
//	RESET_BIT(LCD_CTRL,RS_SWITCH);
//	/*Selects read or write.
//	0: Write <<<<
//	1: Read*/
//	RESET_BIT(LCD_CTRL,RW_SWITCH);
//	wait(1);
//	LCD_kick();
//
//
//	#endif
//
	
	
	
}


void LCD_clear_screen(){
	wait(5);
	LCD_COMM(LCD_CLEAR_SCREEN) ;
	
}

void LCD_INIT(void) {
	wait(1);
	//make the direction of the rw / rs / e pin as output
//	SET_BIT(DataDir_LCD_CTRL,EN_SWITCH);
//	SET_BIT(DataDir_LCD_CTRL,RS_SWITCH);
//	SET_BIT(DataDir_LCD_CTRL,RW_SWITCH);
//MCAL_GPIO_WRITEPIN(LCD_CTRL, EN_SWITCH, PIN_SET) ;
//MCAL_GPIO_WRITEPIN(LCD_CTRL, EN_SWITCH, PIN_SET) ;
//MCAL_GPIO_WRITEPIN(LCD_CTRL, EN_SWITCH, PIN_SET) ;
	///PORTA.PIN8 INPUT FLOATING MODE
	pinconfig.PinNumber = EN_SWITCH;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(LCD_CTRL, &pinconfig);


	///PORTA.PIN9 INPUT FLOATING MODE
	pinconfig.PinNumber = RW_SWITCH;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(LCD_CTRL, &pinconfig);


	///PORTA.PIN10 INPUT FLOATING MODE
	pinconfig.PinNumber = RS_SWITCH;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(LCD_CTRL, &pinconfig);
	wait(5);
	// data pins
	///PORTA.PIN0 output_push_pull
	pinconfig.PinNumber = GPIO_PIN0;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(LCD_CTRL, &pinconfig);
	///PORTA.PIN1 output_push_pull
	pinconfig.PinNumber = GPIO_PIN1;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(LCD_CTRL, &pinconfig);
	///PORTA.PIN2 output_push_pull
	pinconfig.PinNumber = GPIO_PIN2;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(LCD_CTRL, &pinconfig);
	///PORTA.PIN3 output_push_pull
	pinconfig.PinNumber = GPIO_PIN3;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(LCD_CTRL, &pinconfig);
	///PORTA.PIN4 output_push_pull
	pinconfig.PinNumber = GPIO_PIN4;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(LCD_CTRL, &pinconfig);
	///PORTA.PIN5 output_push_pull
	pinconfig.PinNumber = GPIO_PIN5;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(LCD_CTRL, &pinconfig);
	///PORTA.PIN6 output_push_pull
	pinconfig.PinNumber = GPIO_PIN6;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(LCD_CTRL, &pinconfig);
	///PORTA.PIN7 output_push_pull
	pinconfig.PinNumber = GPIO_PIN7;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(LCD_CTRL, &pinconfig);


	MCAL_GPIO_WRITEPIN(LCD_CTRL, EN_SWITCH, PIN_RESET);
	MCAL_GPIO_WRITEPIN(LCD_CTRL, RS_SWITCH, PIN_RESET);
	MCAL_GPIO_WRITEPIN(LCD_CTRL, RW_SWITCH, PIN_RESET);

	
	//set direction of data pins of lcd as output
	//	DataDir_LCD_PORT = 0xFF ;
	
	wait(5);

	
	
//	#ifdef EIGHT_BIT_MODE
//	LCD_COMM(LCD_FUNCTION_8BIT_2LINES);
//
//	#endif
//
//	#ifdef FOUR_BIT_MODE
//	LCD_COMM(0x02);
//	LCD_COMM(LCD_FUNCTION_4BIT_2LINES);
//	#endif
//
//
//
//	// instructions given by manufacture
//	LCD_COMM(LCD_ENTRY_MODE);
//	LCD_COMM(LCD_BEGIN_AT_FIRST_ROW);
//	LCD_COMM(LCD_DISP_ON_CURSOR_BLINK);
}


extern void LCD_WRITE_char(unsigned char character){
	
	#ifdef EIGHT_BIT_MODE
	LCD_stat();
//	LCD_PORT = character;
	MCAL_GPIO_WRITEPORT(LCD_PORT, character) ;
	/*Selects read or write.
	0: Write <<<<
	1: Read*/
//	RESET_BIT(LCD_CTRL,RW_SWITCH);
	MCAL_GPIO_WRITEPIN(LCD_CTRL, RW_SWITCH, PIN_RESET) ;
	/* Selects registers.
	0: Instruction register (for write) Busy flag:  
	address counter (for read)
	1: Data register (for write and read)  <<<<<<< */
//	SET_BIT(LCD_CTRL,RS_SWITCH);
	MCAL_GPIO_WRITEPIN(LCD_CTRL, RS_SWITCH, PIN_SET) ;
	wait(500);
	LCD_kick();
	#endif
	
	#ifdef FOUR_BIT_MODE
	LCD_stat();
	LCD_PORT = character;
	
	/*Selects read or write.
	0: Write <<<<
	1: Read*/
	RESET_BIT(LCD_CTRL,RW_SWITCH);
	
	SET_BIT(LCD_CTRL,RS_SWITCH);
	
	wait(1);
	LCD_kick();
	#endif
	
	
	
}


void LCD_WRITE_string( char* string ){
volatile unsigned int count = 0 ;
while(*string > 0) {
	 LCD_WRITE_char(*string++);
	count ++ ;
	if (count == 16 ){
		
	LCD_adjust_XY(2,0) ;
		
		} else if(count  == 32) {
		LCD_clear_screen() ;
		LCD_adjust_XY(1,0) ;
		count  = 0 ;
			}
	}
}






void LCD_adjust_XY(unsigned char line, unsigned char position){

if (line == 1)
{
	if (position < 16 && position >= 0)
	{
		LCD_COMM(LCD_BEGIN_AT_FIRST_ROW+position);
	}
}
if (line == 2)
{
	if (position < 16 && position >= 0)
	{
		LCD_COMM(LCD_BEGIN_AT_SECOND_ROW+position);
	}
}

}


```

## MAIN PROGRAM : 

* MAIN.c

```c code

/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "STM32F103Cx.h"
#include "stm32f103c6_gpio.h"
#include <LCD_DRIVER/lcd.h>
#include <KEYPAD_DRIVER/keypad.h>

/**
 * @brief 
 * 
 */

#define ZERO 0x01
#define ONE 0x79
#define TWO 0x24
#define THREE 0x30
#define FOUR 0x19
#define FIVE 0x12
#define SIX 0x02
#define SEVEN 0x4C
#define EIGHT 0x00
#define NINE 0x10

void RCC_CONFIGURE() {

	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
}

/**
 * @brief 
 * 
 */
void GPIO_CONFIGURE() {

	GPIO_config_t pinconfig;

	//PA1 input HighZ Floating input (reset state)
	//	pinconfig.PinNumber = GPIO_PIN_1;
	//	pinconfig.GpioMode = GpioMode_INPUT_FLO;
	//	MCAL_GPIO_INIT(GPIOA, &pinconfig);

	//PB1 (output PUSH pull Mode)
	//01: Output mode, max speed 10 MHz.
	//CNF 00: General purpose output push-pull
	pinconfig.PinNumber = GPIO_PIN9;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(GPIOB, &pinconfig);

	pinconfig.PinNumber = GPIO_PIN10;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(GPIOB, &pinconfig);

	pinconfig.PinNumber = GPIO_PIN11;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(GPIOB, &pinconfig);

	pinconfig.PinNumber = GPIO_PIN12;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(GPIOB, &pinconfig);

	pinconfig.PinNumber = GPIO_PIN13;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(GPIOB, &pinconfig);

	//============================

	//PA13 input HighZ Floating input (reset state)
	pinconfig.PinNumber = GPIO_PIN14;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(GPIOB, &pinconfig);
	//PB13 (output PUSH pull Mode)
	pinconfig.PinNumber = GPIO_PIN15;
	pinconfig.GpioMode = GPIO_MODE_output_push_pull;
	pinconfig.GpioSpeed = GPIO_speed10MHz;
	MCAL_GPIO_INIT(GPIOB, &pinconfig);

}

int main(void) {

	RCC_CONFIGURE();
	GPIO_CONFIGURE();
	LCD_INIT_ALL();
	KEYPAD_INIT();
	//LCD_WRITE_string("hey omar");
//	wait(500);
//	LCD_clear_screen();
	LCD_WRITE_string("7SEG mode");
	wait(500);
	LCD_clear_screen();
	unsigned char temp;
	unsigned char seg[] = { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
			EIGHT, NINE, ZERO };
	unsigned char lcd[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
			'0' };
	for (int i = 0; i < 11; i++) {
		MCAL_GPIO_WRITEPORT(GPIOB, seg[i] << 9);
		LCD_WRITE_char(lcd[i]);
		wait(1000);
	}
	KEYPAD_INIT();
	LCD_clear_screen();
	LCD_WRITE_string("keypad mode");
	wait(500);
	LCD_clear_screen();
	while (1) {
		temp = KEYPAD_GETKEY();

		switch (temp) {
		case 'A':
			break;
		case '?':
			LCD_clear_screen();
			break;
		default:
			LCD_WRITE_char(temp);
			break;
		}
	}
	return 0;
}



```

## TRM SHOTS 

## PROTEUS CAPTURE

> ![Alt Text](https://s7.gifyu.com/images/SXJI3.gif) 
&nbsp;


* SYSTEM ARCHITECTURE
> [![2Yt1Uap.md.png](https://iili.io/2Yt1Uap.md.png)]()
&nbsp;


* IO STRUCTURE
> [![2YtGqss.md.png](https://iili.io/2YtGqss.md.png)]()
&nbsp;

* MEMORY OF RCC
> [![2YtMCj1.md.png](https://iili.io/2YtMCj1.md.png)]()

&nbsp;

* MEMORY OF PORTA - PORTB
> [![2YtMSFj.md.png](https://iili.io/2YtMSFj.md.png)]()
&nbsp;


* PORT BIT CONFIGURATION TABLE
> [![2YtVnHl.md.png](https://iili.io/2YtVnHl.md.png)]()

&nbsp;

* APB2ENR
> [![2YtVVig.md.png](https://iili.io/2YtVVig.md.png)]()
&nbsp;


* GPIO_ODR
> [![2YtWJdx.md.png](https://iili.io/2YtWJdx.md.png)]()
&nbsp;


* GPIO_IDR
> [![2YtWc1s.md.png](https://iili.io/2YtWc1s.md.png)]()
&nbsp;

* GPIO_LOCK
> [![2YtXR8x.md.png](https://iili.io/2YtXR8x.md.png)]()
> [![2YtXW8v.md.png](https://iili.io/2YtXW8v.md.png)]()
&nbsp;

* GPIO_CRH
> [![2Yth2oP.md.png](https://iili.io/2Yth2oP.md.png)]()
&nbsp;

* GPIO_CRL
> [![2YthVs9.md.png](https://iili.io/2YthVs9.md.png)]()
&nbsp;

* MODE BIT
> [![2YthtzN.md.png](https://iili.io/2YthtzN.md.png)]()
&nbsp;

* CNF BIT
> [![2YtjhQI.md.png](https://iili.io/2YtjhQI.md.png)]()
&nbsp;


* microVISION portB
> [![20YDwDx.md.png](https://iili.io/20YDwDx.md.png)]()

&nbsp;


* microVISION portA
> [![20YmGyu.md.png](https://iili.io/20YmGyu.md.png)]()
&nbsp;



[![MIT License](https://img.shields.io/badge/ALL%20FILES%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/microcontroller-architecture/GPIO/lcd-keypad-7seg-stm32/ALL%20FILES)



&nbsp;
&nbsp;
&nbsp;

## 🔗 Links

[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/omar-samy-69a7241b0/)
