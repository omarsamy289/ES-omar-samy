 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <a href=""><img src="https://iili.io/2Aabe9f.md.png" alt="771" border="0"></a><br /><a target='_blank' href=''>



[![MIT License](https://img.shields.io/badge/ALL%20FILES%20-7A5BE2)]()

# LAB 2 - MCU Interrupts
&nbsp;
* on ATMEGA32  :
>* triggering PORTD.PIN5 when there is any logical change on EX INT0
>* triggering PORTD.PIN6 when there is rising edge on EX INT1
>* triggering PORTD.PIN7 when there is falling edge on EX INT2
&nbsp;
* configuring registers 
> * PORTD
> * DDRD
> * MCUCR
> * MCUCSR
> * GICR


* BLOCK DIAGRAM
> [![2Aa19bn.md.png](https://iili.io/2Aa19bn.md.png)]()
&nbsp;


* PROTEUS CAPTURE
> ![Alt Text](https://s11.gifyu.com/images/Syob7.gif)

&nbsp;


&nbsp;


## main.c : 

* main.c 

```c code

/*
 * main.c
 *
 * Author : omar
 */ 



#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define SET_BIT(ADDRESS, BIT) ADDRESS |= (1<<BIT)
#define RESET_BIT(ADDRESS, BIT) ADDRESS &= ~(1<<BIT)
#define TOGGEL_BIT(ADDRESS, BIT) ADDRESS ^= (1<<BIT)
#define READ_BIT(ADDRESS, BIT) ((ADDRESS & (1<<BIT)>>BIT))
/*
#define IO_BASE 0x20
#define PORTD *(volatile unsigned int*)(IO_BASE + 0x12)
#define DDRD *(volatile unsigned int*)(IO_BASE + 0x11)
#define MCUCR *(volatile unsigned int*)(IO_BASE + 0x35)
#define MCUCSR *(volatile unsigned int*)(IO_BASE + 0x34)
#define GICR *(volatile unsigned int*)(IO_BASE + 0x3B)
*/

void SetSenseCntrl(void) {
	
//SET INT0 any logical change
SET_BIT(MCUCR,0);
RESET_BIT(MCUCR,1);

//SET INT1 RISING EDGE
SET_BIT(MCUCR,2);
SET_BIT(MCUCR,3);

// SET INT2 FALLING EDGE
RESET_BIT(MCUCSR,6);

}

void enbextrn(void){

// enabling general extern registers 
SET_BIT(GICR,5);
SET_BIT(GICR,6);
SET_BIT(GICR,7);	
}

int main(void)
{
	SetSenseCntrl();
	enbextrn();
	
	// enable global interrupt
	sei();
	
	
	// set direction of pin(5,6,7) of portD to output
	SET_BIT(DDRD,5);
	SET_BIT(DDRD,6);
	SET_BIT(DDRD,7);
    
    while (1) 
    {
		
		RESET_BIT(PORTD,5);
		RESET_BIT(PORTD,6);
		RESET_BIT(PORTD,7);
    }
}

ISR(INT0_vect){
	SET_BIT(PORTD,5);
	_delay_ms(100);
	
}

ISR(INT1_vect){
	SET_BIT(PORTD,6);
	_delay_ms(100);
	
}

ISR(INT2_vect){
	SET_BIT(PORTD,7);
	_delay_ms(100);
	
}


```



* PORTD
>[![2AaGcog.md.png](https://iili.io/2AaGcog.md.png)]()
&nbsp;


* DDRD
>[![2AaGyOP.md.png](https://iili.io/2AaGyOP.md.png)]()
&nbsp;


* MCUCR
>[![2AaWYD7.md.png](https://iili.io/2AaWYD7.md.png)]()
>[![2AaXK0b.md.png](https://iili.io/2AaXK0b.md.png)]()
&nbsp;


* MCUCSR
>[![2AaXW1s.md.png](https://iili.io/2AaXW1s.md.png)]()
&nbsp;


* GICR
>[![2AaXikQ.md.png](https://iili.io/2AaXikQ.md.png)](https://freeimage.host/i/2AaXikQ)
&nbsp;




* PROTEUS CAPTURE
> ![Alt Text](https://s11.gifyu.com/images/Syob7.gif)

&nbsp;


* PROTEUS view 
> [![2Aahhn1.md.png](https://iili.io/2Aahhn1.md.png)]()
&nbsp;



[![MIT License](https://img.shields.io/badge/ALL%20FILES%20-7A5BE2)]()


[![MIT License](https://img.shields.io/badge/go%20back%20-7A5BE2)]()

&nbsp;
&nbsp;
&nbsp;

## 🔗 Links

[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/omar-samy-69a7241b0/)
