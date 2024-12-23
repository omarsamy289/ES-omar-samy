 

<div align="center">
  
[![2O1i7fI.md.png](https://iili.io/2O1i7fI.md.png)]() 


</div>



<div align="center">
  
---------

</div>




[![MIT License](https://img.shields.io/badge/ALL%20FILES%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/microcontroller-architecture/GPIO/LCD-KEYPAD-DRIVERS/lcd_keypad)

# LAB  - LCD / KEYPAD drivers
 
&nbsp;
* on ATMEGA32  :
>* configuring  lcd  to portA portB
>* configuring keypad to portD
&nbsp;


* PIN CONFIGRATION 
> [![2YZmdu4.md.png](https://iili.io/2YZmdu4.md.png)]()
&nbsp;

* configuring registers (x = A,B..) 
> * PORTx
> * DDRx
> * PINx



* PROTEUS CAPTURE 
> ![Alt Text](https://s13.gifyu.com/images/SP8EL.gif)
&nbsp;


&nbsp;


## LCD DRIVER : 

* LCD.h

```c code
 
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
 
```

* LCD.c

```c code
 
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
 
```


## KEYPAD DRIVER : 

* KEYPAD.h

```c code
 
 
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
 
 
 
```

* KEYPAD.c

```c code
 
 
/*
 * keypad.c
 *
 * Created: 12/19/2024 4:25:38 PM
 *  Author: omar
 */ 

#include "keypad.h"
int Keypad_Row [] = {ROW1,ROW2, ROW3, ROW4}; //rows of the keypad
int Keypad_Col[] = {COL1, COL2, COL3, COL4};//columns



void KEYPAD_INIT() {
	
	RESET_BIT(DataDir_KEYPAD_PORT,ROW1) ;
	RESET_BIT(DataDir_KEYPAD_PORT,ROW2) ;
	RESET_BIT(DataDir_KEYPAD_PORT,ROW3) ;
	RESET_BIT(DataDir_KEYPAD_PORT,ROW4) ;
		
	SET_BIT (DataDir_KEYPAD_PORT,COL1) ;
	SET_BIT (DataDir_KEYPAD_PORT,COL2) ;
	SET_BIT (DataDir_KEYPAD_PORT,COL3) ;
	SET_BIT (DataDir_KEYPAD_PORT,COL4) ;
	
	KEYPAD_PORT = 0xFF;	
}

char KEYPAD_GETKEY(){
	
		volatile unsigned int i , j ;	
	
	for (i = 0; i < 4; i++){
		
		SET_BIT(KEYPAD_PORT,Keypad_Col[0]) ;
		SET_BIT(KEYPAD_PORT,Keypad_Col[1]) ;
		SET_BIT(KEYPAD_PORT,Keypad_Col[2]) ;
		SET_BIT(KEYPAD_PORT,Keypad_Col[3]) ;
		RESET_BIT(KEYPAD_PORT,Keypad_Col[i]) ;
		for(j = 0; j < 4; j++){
			if (!(keypadPIN & (1 << Keypad_Row[j])))
			{
				while(!(keypadPIN & (1 << Keypad_Row[j])));
				switch(i){
					case (0):
					if (j == 0) return '7';
					else if (j == 1) return '4';
					else if (j == 2) return '1';
					else if (j == 3) return '?';
					break;
					case (1):
					if (j == 0) return '8';
					else if (j == 1) return '5';
					else if (j == 2) return '2';
					else if (j == 3) return '0';
					break;
					case (2):
					if (j == 0) return '9';
					else if (j == 1) return '6';
					else if (j == 2) return '3';
					else if (j == 3) return '=';
					break;
					case (3):
					if (j == 0) return '/';
					else if (j == 1) return '*';
					else if (j == 2) return '-';
					else if (j == 3) return '+';
					break;
				}
			}
		}
	}
	return 'A'; 
	
	
		
} 
 
 
```



## MAIN PROGRAM : 

* MAIN.c

```c code
 
 
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


 
 
```


* BLOCK DIAGRAM 
> [![2YZbOTQ.md.png](https://iili.io/2YZbOTQ.md.png)]()
&nbsp;


* PIN CONFIGRATION 
> [![2YZmdu4.md.png](https://iili.io/2YZmdu4.md.png)]()
&nbsp;


* Pin Equivalent Schematic
> [![2YZm7P1.md.png](https://iili.io/2YZm7P1.md.png)]()
&nbsp;

* RIGESTERS SUMMARY 
> [![2YZmNln.md.png](https://iili.io/2YZmNln.md.png)]()
> [![2YZmtOx.md.png](https://iili.io/2YZmtOx.md.png)]()
&nbsp;


[![MIT License](https://img.shields.io/badge/ALL%20FILES%20-7A5BE2)]()


[![MIT License](https://img.shields.io/badge/go%20back%20-7A5BE2)]()

&nbsp;
&nbsp;
&nbsp;

## 🔗 Links

[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/omar-samy-69a7241b0/)
