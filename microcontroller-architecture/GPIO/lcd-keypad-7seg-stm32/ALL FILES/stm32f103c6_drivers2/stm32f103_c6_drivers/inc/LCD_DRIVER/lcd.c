

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
