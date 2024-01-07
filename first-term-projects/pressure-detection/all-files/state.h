/*
 * stat.h
 *
 *  Created on: jan 7, 2024
 *      Author: omar
 */

#ifndef STATE_H_
#define STATE_H_
#include "mod_int_standard.h"

#define SET_BIT(ADDRESS,BIT)   ADDRESS |=  (1<<BIT)
#define RESET_BIT(ADDRESS,BIT) ADDRESS &= ~(1<<BIT)
#define TOGGLE_BIT(ADDRESS,BIT)  ADDRESS ^=  (1<<BIT)
#define READ_BIT(ADDRESS,BIT) ((ADDRESS) &   (1<<(BIT)))

#define GPIOA_CRL *(volatile unint32 *)(GPIO_PORTA + 0x00)
#define GPIOA_CRH *(volatile unint32 *)(GPIO_PORTA + 0X04)
#define GPIOA_IDR *(volatile unint32 *)(GPIO_PORTA + 0x08)
#define GPIOA_ODR *(volatile unint32 *)(GPIO_PORTA + 0x0C)


#define GPIO_PORTA 0x40010800
#define BASE_RCC   0x40021000

#define APB2ENR   *(volatile uint32_t *)(BASE_RCC + 0x18)





// state definitio macros
#define state_definition(state_func) void SD_##state_func()
#define state_name(state_func) SD_##state_func

// connections between the blocks

unint32 getPressureVal();
void Set_Alarm_actuator(int i);
state_definition(alarm_start) ;
state_definition(alarm_stop);



#endif /* STATE_H_ */
