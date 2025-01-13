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
