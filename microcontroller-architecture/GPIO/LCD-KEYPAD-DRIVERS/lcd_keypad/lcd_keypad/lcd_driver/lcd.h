/*
 * lcd.h
 *
 * Created: 12/19/2024 4:24:26 PM
 *  Author: omar
 */ 


#ifndef LCD_H_
#define LCD_H_
#define F_CPU 1000000UL

#include <util/delay.h>


#define SET_BIT(ADDRESS,BIT) ADDRESS |= (1<<BIT)
#define RESET_BIT(ADDRESS,BIT) ADDRESS &= ~(1<<BIT)
#define TOGGLE_BIT(ADDRESS,BIT) ADDRESS ^= (1<<BIT)
#define READ_BIT(ADDRESS,BIT) (ADDRESS & (1<<BIT) >> BIT)




#define PORTA *(volatile unsigned char *)(0x3B)
#define DDRA  *(volatile unsigned char *)(0x3A)
#define PINA  *(volatile unsigned char *)(0x39)
#define PORTB *(volatile unsigned char *)(0x38)
#define DDRB  *(volatile unsigned char *)(0x37)
#define PINB  *(volatile unsigned char *)(0x36)







#define LCD_PORT PORTA
#define DataDir_LCD_PORT DDRA
#define LCD_CTRL PORTB
#define DataDir_LCD_CTRL DDRB
#define RS_SWITCH 1
#define RW_SWITCH 2
#define EN_SWITCH 3
#define DATA_shift 0 // in 8 bit mode 0 and in 4 bit mode 4

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
void LCD_WRITE_string(unsigned char*);

void LCD_stat(void);
void LCD_kick(void);
void LCD_clear_screen();
void LCD_adjust_XY(unsigned char line, unsigned char position);




#endif /* LCD_H_ */