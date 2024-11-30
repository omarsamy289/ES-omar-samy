 

<div align="center"> 
  
[![2004Lle.md.png](https://iili.io/2004Lle.md.png)]()

  </div>




[![MIT License](https://img.shields.io/badge/ALL%20FILES%20-7A5BE2)]()

# LAB 2-1 - MCU GPIO
 
&nbsp;
* on ATMEGA32  :
>* configuring  pA.(1..7) as output

&nbsp;


* PIN CONFIGRATION 
> [![2YZmdu4.md.png](https://iili.io/2YZmdu4.md.png)]()
&nbsp;

* configuring registers (x = A,B..) 
> * PORTx
> * DDRx
> * PINx



* PROTEUS CAPTURE 
> ![Alt Text](https://s7.gifyu.com/images/SGmt5.gif)
&nbsp;


&nbsp;


## main.c : 

* main.c 

```c code
 
#define F_CPU 8000000UL
#include "memorymap.h"
#include <util/delay.h>


int main(void)
{
	DDRA = 0xff ;
    while (1) 
    {
		SET_BIT(PORTA,0) ;
		_delay_ms(200);
		SET_BIT(PORTA,1) ;
		_delay_ms(200);
		SET_BIT(PORTA,2) ;
		_delay_ms(200);
		SET_BIT(PORTA,3) ;
		_delay_ms(200);
		SET_BIT(PORTA,4) ;
		_delay_ms(200);
		SET_BIT(PORTA,5) ;
		_delay_ms(200);
		SET_BIT(PORTA,6) ;
		_delay_ms(200);
		SET_BIT(PORTA,7) ;
		_delay_ms(200);
		/////
			RESET_BIT(PORTA,7) ;
			_delay_ms(200);
			RESET_BIT(PORTA,6) ;
			_delay_ms(200);
			RESET_BIT(PORTA,5) ;
			_delay_ms(200);
			RESET_BIT(PORTA,4) ;
			_delay_ms(200);
			RESET_BIT(PORTA,3) ;
			_delay_ms(200);
			RESET_BIT(PORTA,2) ;
			_delay_ms(200);
			RESET_BIT(PORTA,1) ;
			_delay_ms(200);
			RESET_BIT(PORTA,0) ;
			_delay_ms(200);
		
    }
}


```


<div align="center">
  
----

  </div>




# LAB 2-2 - MCU GPIO 

&nbsp;
* on ATMEGA32  :
> * configuring  D.(5,6,7) as output to anod
> * configuring  D.4 as output to relay
> * configuring  D.0 as input external pull down 

&nbsp;

* configuring registers (x = A,B..) 
> * PORTx
> * DDRx
> * PINx



* PROTEUS CAPTURE 
> ![Alt Text](https://s7.gifyu.com/images/SGm5z.gif)
&nbsp;


&nbsp;


## main.c : 

* main.c 

```c code
 
#define F_CPU 8000000UL
#include "memorymap.h"
#include <util/delay.h>


// d0 button make it input pull down
// when pushed out d4 for 1 second
// and with push lights d5 , d6 ,d7 inclemently
// D0 input  external PUll DOWN
// D4 output to relay
// D5 , D6 ,D7 output to LED ANOD

int main(void)
{
	//D4 OUTPUT
	SET_BIT(DDRD,4);
// D5 , D6 ,D7 output to LED ANOD	
	SET_BIT(DDRD,5);
	SET_BIT(DDRD,6);
	SET_BIT(DDRD,7);
	  // D0 input  external PUll DOWN
	RESET_BIT(DDRD,0);
	SET_BIT(DDRD,0);
	   unsigned int  buttonState = 0;  // To track the number of button presses
	   unsigned int prevButton = 0;   // To detect rising edge of the button press


while (1) {
	uint8_t currentButton = READ_BIT(PIND, 0);  // Read button state

	// Detect button press (rising edge)
	if (currentButton && !prevButton) {
		buttonState++;
		if (buttonState > 4) {
			buttonState = 1;  // Reset the program after the fourth button  press
		}

		switch (buttonState) {
			case 1:
			//RESET_BIT(PORTD, 6);    // Turn off LED on PD6
			//RESET_BIT(PORTD, 7);    // Turn off LED on PD7
			SET_BIT(PORTD, 5);      // Turn on LED on PD5
			SET_BIT(PORTD, 4);      // Turn on buzzer
			_delay_ms(500);         // Wait for 0.5 second
			RESET_BIT(PORTD, 4);    // Turn off buzzer
			break;

			case 2:
			//RESET_BIT(PORTD, 7);    // Turn off LED on PD7
			SET_BIT(PORTD, 5);      // Turn on LED on PD5
			SET_BIT(PORTD, 6);      // Turn on LED on PD6
			SET_BIT(PORTD, 4);      // Turn on buzzer
			_delay_ms(500);         // Wait for 0.5 second
			RESET_BIT(PORTD, 4);    // Turn off buzzer
			break;

			case 3:
			SET_BIT(PORTD, 5);      // Turn on LED on PD5
			SET_BIT(PORTD, 6);      // Turn on LED on PD6
			SET_BIT(PORTD, 7);      // Turn on LED on PD7
			SET_BIT(PORTD, 4);      // Turn on buzzer
			_delay_ms(500);         // Wait for 0.5 second
			RESET_BIT(PORTD, 4);    // Turn off buzzer
			break;

			case 4:
			SET_BIT(PORTD, 4);      // Turn on buzzer
			_delay_ms(500);
			RESET_BIT(PORTD, 7);    // Turn off LED on PD7
			_delay_ms(250);
			RESET_BIT(PORTD, 6);    // Turn off LED on PD6
			_delay_ms(250);
			RESET_BIT(PORTD, 5);    // Turn off LED on PD5
			_delay_ms(500);
			RESET_BIT(PORTD, 4);    // Turn off buzzer
			break;
		}
	}

	prevButton = currentButton;  // Update previous button state
	_delay_ms(50);               // Debounce delay
}
	   

	   return 0;
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
