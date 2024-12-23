/*
 * keypad.h
 *
 * Created: 12/19/2024 4:25:25 PM
 *  Author: omar
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU 1000000UL

#include <util/delay.h>


#define SET_BIT(ADDRESS,BIT) ADDRESS |= (1<<BIT)
#define RESET_BIT(ADDRESS,BIT) ADDRESS &= ~(1<<BIT)
#define TOGGLE_BIT(ADDRESS,BIT) ADDRESS ^= (1<<BIT)
#define READ_BIT(ADDRESS,BIT) (ADDRESS & (1<<BIT) >> BIT)




#define PORTD *(volatile unsigned char *)(0x32)
#define DDRD  *(volatile unsigned char *)(0x31)
#define PIND  *(volatile unsigned char *)(0x30)


#define ROW1 0
#define ROW2 1
#define ROW3 2
#define ROW4 3
#define COL1 4
#define COL2 5
#define COL3 6
#define COL4 7

#define KEYPAD_PORT PORTD
#define DataDir_KEYPAD_PORT DDRD
#define keypadPIN PIND

void KEYPAD_INIT();
char KEYPAD_GETKEY();










#endif /* KEYPAD_H_ */