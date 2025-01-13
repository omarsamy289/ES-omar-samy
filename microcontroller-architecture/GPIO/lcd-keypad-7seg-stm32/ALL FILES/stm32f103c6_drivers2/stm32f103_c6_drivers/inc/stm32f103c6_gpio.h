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
