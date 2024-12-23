/*
* lcd.c
*
* Created: 12/19/2024 4:24:39 PM
*  Author: omar
*/

#include "lcd.h"




void LCD_stat(void) {
	
//DDRA set 0 read
	DataDir_LCD_PORT &= ~(0xFF<< DATA_shift) ;
	
//1
	/*Selects read or write.
	0: Write 
	1: Read    <<<< */
	SET_BIT(LCD_CTRL,RW_SWITCH);
	
//2	
	/* Selects registers.
	0: Instruction register (for write) Busy flag:  <<<<<<<
	address counter (for read)
	1: Data register (for write and read) */
	RESET_BIT(LCD_CTRL,RS_SWITCH);
	
//3
	LCD_kick();
	
//4 
     //DDRA set 0 read
	DataDir_LCD_PORT &= ~(0xFF<<DATA_shift);
	
//5
	/*Selects read or write.
	0: Write  <<<<<<
	1: Read     */
	RESET_BIT(LCD_CTRL,RW_SWITCH);
}


void LCD_kick(void){
	SET_BIT(LCD_CTRL,EN_SWITCH);
	_delay_ms(50);
	//Starts data read/write <<<
	RESET_BIT(LCD_CTRL,EN_SWITCH);
}


void LCD_COMM(unsigned char command ){
	#ifdef EIGHT_BIT_MODE
	LCD_stat();
	LCD_PORT = command ;
	
	/* Selects registers.
	0: Instruction register (for write) Busy flag:  <<<<<<<
	address counter (for read)
	1: Data register (for write and read) */
	RESET_BIT(LCD_CTRL,RS_SWITCH);
	
	/*Selects read or write.
	0: Write <<<<
	1: Read*/
	RESET_BIT(LCD_CTRL,RW_SWITCH);
	
	_delay_ms(5);
	LCD_kick();
	#endif
	
	#ifdef FOUR_BIT_MODE
	// >> least four bit
	LCD_stat();
	LCD_PORT = (LCD_PORT& 0x0F)| (command & 0xF0) ;
	/* Selects registers.
	0: Instruction register (for write) Busy flag:  <<<<<<<
	address counter (for read)
	1: Data register (for write and read) */
	RESET_BIT(LCD_CTRL,RS_SWITCH);
	/*Selects read or write.
	0: Write <<<<
	1: Read*/
	RESET_BIT(LCD_CTRL,RW_SWITCH);
	_delay_ms(1);
	LCD_kick();
	
	// >> most four bit
	LCD_stat();
	LCD_PORT = (LCD_PORT& 0x0F)| (command << 4) ;
	/* Selects registers.
	0: Instruction register (for write) Busy flag:  <<<<<<<
	address counter (for read)
	1: Data register (for write and read) */
	RESET_BIT(LCD_CTRL,RS_SWITCH);
	/*Selects read or write.
	0: Write <<<<
	1: Read*/
	RESET_BIT(LCD_CTRL,RW_SWITCH);
	_delay_ms(1);
	LCD_kick();
	
	
	#endif
	
	
	
	
}


void LCD_clear_screen(){
	_delay_ms(20);
	LCD_COMM(LCD_CLEAR_SCREEN) ;
	
}

void LCD_INIT(void) {
	
	_delay_ms(50);
	//make the direction of the rw / rs / e pin as output
	SET_BIT(DataDir_LCD_CTRL,EN_SWITCH);
	SET_BIT(DataDir_LCD_CTRL,RS_SWITCH);
	SET_BIT(DataDir_LCD_CTRL,RW_SWITCH);
	
	//Starts data read/write <<<
	RESET_BIT(LCD_CTRL,EN_SWITCH);

	/* Selects registers.
	0: Instruction register (for write) Busy flag:  <<<<<<<
	address counter (for read)
	1: Data register (for write and read) */
	RESET_BIT(LCD_CTRL,RS_SWITCH);
	
	/*Selects read or write.
	0: Write <<<<
	1: Read*/
	RESET_BIT(LCD_CTRL,RW_SWITCH);
	
	//set direction of data pins of lcd as output
	DataDir_LCD_PORT = 0xFF ;
	
	_delay_ms(20);

	
	
	#ifdef EIGHT_BIT_MODE
	LCD_COMM(LCD_FUNCTION_8BIT_2LINES);
	
	#endif
	
	#ifdef FOUR_BIT_MODE
	LCD_COMM(0x02);
	LCD_COMM(LCD_FUNCTION_4BIT_2LINES);
	#endif
	
	
	
	// instructions given by manufacture
	LCD_COMM(LCD_ENTRY_MODE);
	LCD_COMM(LCD_BEGIN_AT_FIRST_ROW);
	LCD_COMM(LCD_DISP_ON_CURSOR_BLINK);
}


extern void LCD_WRITE_char(unsigned char character){
	
	#ifdef EIGHT_BIT_MODE
	LCD_stat();
	LCD_PORT = character;
	
	/*Selects read or write.
	0: Write <<<<
	1: Read*/
	RESET_BIT(LCD_CTRL,RW_SWITCH);
	
	/* Selects registers.
	0: Instruction register (for write) Busy flag:  
	address counter (for read)
	1: Data register (for write and read)  <<<<<<< */
	SET_BIT(LCD_CTRL,RS_SWITCH);
	
	_delay_ms(1);
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
	
	_delay_ms(1);
	LCD_kick();
	#endif
	
	
	
}


void LCD_WRITE_string(unsigned char* string ){
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