/*
 * lcd_keypad.c
 *
 * Created: 12/19/2024 4:23:06 PM
 * Author : omar
 */ 


#include "lcd_driver/lcd.h"
#include "keypad_driver/keypad.h"

int main(void)
{
	KEYPAD_INIT() ;
	LCD_INIT();
	_delay_ms(50);
	unsigned char temp ;
    while (1) 
    {
		temp = KEYPAD_GETKEY() ;
		
		switch(temp){
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
}

