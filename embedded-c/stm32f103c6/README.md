
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <a href=""><img src="https://i.ibb.co/QfGTFD3/github-embedded-system-thumbnail-projects.png" alt="771" border="0"></a><br /><a target='_blank' href='https://i.ibb.co/QfGTFD3/github-embedded-system-thumbnail-projects.png'>

[![MIT License](https://img.shields.io/badge/c%20file%20-7A5BE2)]()
[![MIT License](https://img.shields.io/badge/hex%20file%20-7A5BE2)]()
[![MIT License](https://img.shields.io/badge/sim%20file%20-7A5BE2)]()

## modified standard int library

```c code
// header guards
#ifndef MOD_INT_STANDARD_H_
#define MOD_INT_STANDARD_H_

#include "stdint.h"
#include "stdbool.h"

/* universal modified standard integer library
  * Compatible with AUTOSAR Platform Types
  * according to a 32 bit architecture
  * without using standard int library but it's included to use if we need to
 omar samy
*/


#ifndef _Bool
#define _Bool unsigned char
#endif

#ifndef FALSE
#define FLASE  (boolean)false
#endif

#ifndef TRUE
#define TRUE  (boolean)true
#endif

//architecture is 32
#define archtecture_   archtecture_32
//most significant bit first
#define Endianness_bit       Endianness_MSB
//highest byte first
#define Endianness_byte      Endianness_HBF

typedef _Bool    boolean;

typedef char     char_t ;
//unsigned
typedef unsigned  char  unint8;
typedef unsigned  short unint16;
typedef unsigned      unint32;
typedef unsigned  long long     unint64;
//signed
typedef   char  sint8;
typedef   short sint16;
typedef    signed  sint32;
typedef   long long     sint64;
//Volatile unsigned
typedef volatile unsigned  char  vunint8;
typedef volatile unsigned  short vunint16;
typedef  volatile unsigned      vunint32;
typedef volatile unsigned  long long    vunint64;
//Volatile signed
typedef  volatile char  vsint8;
typedef  volatile short vsint16;
typedef   volatile signed  vsint32;
typedef  volatile long long    vsint64;


#endif


```


## program to toggle led on stm32f103c6
### protues capture 
 ![Alt Text](https://s5.gifyu.com/images/SRQem.gif)


```c code

#include "mod_int_standard.h"

#define RCC_BASE    0x40021000
#define PORTA_BASE  0x40010800
//register that enables i/o
#define RCC_APB2ENR *(vunint32 *)(RCC_BASE + 0X18)

#define gpio_ODR  *(vunint32 *)(PORTA_BASE + 0X0c)
#define gpio_CRH  *(vunint32 *)(PORTA_BASE + 0X04)
// choose bit to set or clear from this macro
#define specefic_bit  13
#define pin_specific  pin##specefic_bit

//union approach to reach specific pin
typedef union {
	vunint32 all_feilds ;
	struct {
		vunint32 reserved:specefic_bit ;
		vunint32 pin_specific:1 ;
	}pin;
} porta_t ;


volatile porta_t* ptrporta = (volatile porta_t*)( PORTA_BASE + 0X0c) ;

int main(void)
{
	// ENABLES RCC CLOCK
	RCC_APB2ENR |= (1<<2) ;
	//
	gpio_CRH &= 0XFF0FFFFF ;
	gpio_CRH |= 0X00200000 ;



	/* Loop forever */
	while(1){
		vunint32 i ;
		// (*(vunint32*)(PORTA_BASE + 0X13)) |= 1<<specefic_bit ;

		ptrporta->pin.pin_specific=1;
		for (i=0;i <5000;i++);
	ptrporta->pin.pin_specific=0;
	//	(*(vunint32*)(PORTA_BASE + 0X13)) &= ~(1<<specefic_bit) ;

		for (i=0;i <5000;i++);



	}

}


```

 ![Alt Text](https://s5.gifyu.com/images/SRQeQ.gif)

[![MIT License](https://img.shields.io/badge/c%20file%20-7A5BE2)]()
[![MIT License](https://img.shields.io/badge/hex%20file%20-7A5BE2)]()
[![MIT License](https://img.shields.io/badge/sim%20file%20-7A5BE2)]()

[![MIT License](https://img.shields.io/badge/go%20back%20-7A5BE2)]()

&nbsp;
&nbsp;

&nbsp;

## 🔗 Links

[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/omar-samy-69a7241b0/)
