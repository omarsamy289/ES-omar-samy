

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


