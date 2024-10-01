 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <a href=""><img src="https://iili.io/dDCFqk7.md.png" alt="771" border="0"></a><br /><a target='_blank' href=''>
 


[![MIT License](https://img.shields.io/badge/ALL%20FILES%20-7A5BE2)]()

# LAB 1 - MCU Interrupts
* on stm32f103c6 (cortex-m3) :
* open line 0 on the external interupt throught AFIO to NVIC_EXTI0
* trigger PORTA.PIN13 when there is rising edge on line 0 AFIO_EXTICR1 (PORTA.PIN0)
* configure registers 
> * EXTI_IMR
> * EXTI_RTSR
> * EXTI_PR


* System architecture (low-, medium-, XL-density devices)
> [![dDBvckg.md.png](https://iili.io/dDBvckg.md.png)]()
&nbsp;


* EXTI register map
> [![dDBYBtf.md.png](https://iili.io/dDBYBtf.md.png)]()
&nbsp;


## main.c : 

* main.c 

```c code

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "mod_int_standard.h"


//RCC
	#define RCC_BASE    0x40021000
//register that enables CLK ON APB2 BUS
	#define RCC_APB2ENR *(vunint32 *)(RCC_BASE + 0X18)
//register that enables CLK ON GPIOA
	#define RCC_IOPAEN (1<<2)



//GPIO
	#define GPIOA_BASE  0x40010800
	#define gpio_ODR  *(vunint32 *)(GPIOA_BASE + 0X0c)
	#define gpio_CRH  *(vunint32 *)(GPIOA_BASE + 0X04)
	#define gpio_CRL  *(vunint32 *)(GPIOA_BASE + 0X00)


//AFIO alternative function in/out
#define AFIO_BASE 0x40010000
#define AFIO_EXTICR1 *(vunint32 *)(AFIO_BASE + 0x08)

/*
 EXTIx[3:0]: EXTI x configuration (x= 0 to 3)
These bits are written by software to select the source input for EXTIx external interrupt.
0000: PA[x] pin
*/



//NVIC
#define NVIC_EXTI0 *(vunint32 *)(0xE000E100 + 0X00)





//EXTI (external interrupt)
#define EXTI_BASE 0x40010400
// for all REGs |= (1<<1)
#define EXTI_IMR *(vunint32 *)(EXTI_BASE + 0x00)
#define EXTI_RTSR  *(vunint32 *)(EXTI_BASE + 0x08)
#define EXTI_PR *(vunint32 *)(EXTI_BASE + 0x14)


void CLK_INIT(void)
{

// ENABLES RCC CLOCK
	RCC_APB2ENR |= RCC_IOPAEN  ;

//enable AFIO CLK
RCC_APB2ENR |= (1<<0);
}



void GPIO_INIT(void)
{


//
	gpio_CRH &= 0XFF0FFFFF ;
	gpio_CRH |= 0X00200000 ;


	//
	gpio_CRL |= (1<<2);
}






int main(void)
{


CLK_INIT();
GPIO_INIT() ;


// line 1 to EXIP0
AFIO_EXTICR1 =0 ;



// enable line 1
EXTI_IMR |= (1<<0);

//Interrupt when rising edge
EXTI_RTSR |= (1<<0);

//open NVIC
NVIC_EXTI0 |= (1<<6) ;

while(1);

}


void EXTI0_IRQHandler(void)
{


gpio_ODR ^= (1<<13);


EXTI_PR |= (1<<0) ;

}

```



### snap shot from the startup Assembly showing the weak function EXTI0_IRQHandler
&nbsp;

```Assembly
 .word	FLASH_IRQHandler          			/* Flash global interrupt                           */
  .word	RCC_IRQHandler            			/* RCC global interrupt                             */
  .word	EXTI0_IRQHandler          			/* EXTI Line0 interrupt              <<<<<<<<       */
  .word	EXTI1_IRQHandler          			/* EXTI Line1 interrupt                             */
  .word	EXTI2_IRQHandler          			/* EXTI Line2 interrupt                             */
  .word	EXTI3_IRQHandler          			/* EXTI Line3 interrupt                             */
  .word	EXTI4_IRQHandler          			/* EXTI Line4 interrupt                             */
  
  
	.weak	EXTI0_IRQHandler		     	/* <<<<<<<<<<<<<<<<<<<<<<                           */
	.thumb_set EXTI0_IRQHandler,Default_Handler

```





* System architecture (low-, medium-, XL-density devices)
> [![dDBvckg.md.png](https://iili.io/dDBvckg.md.png)]()
&nbsp;


* Rising trigger selection register (EXTI_RTSR)
> [![dDBk80P.md.png](https://iili.io/dDBk80P.md.png)]()
&nbsp;


* Register boundary addresses 
> [![dDBk2l1.md.png](https://iili.io/dDBk2l1.md.png)]()
&nbsp;



* Interrupt mask register (EXTI_IMR) 
> [![dDBhuUJ.md.png](https://iili.io/dDBhuUJ.md.png)]()
&nbsp;

* Pending register (EXTI_PR)
> [![dDBNoVS.md.png](https://iili.io/dDBNoVS.md.png)]()
&nbsp;


* EXTI register map
> [![dDBYBtf.md.png](https://iili.io/dDBYBtf.md.png)]()
&nbsp;


* APBEN2_RCC
> [![dDBRIF1.png](https://iili.io/dDBRIF1.png)]()
&nbsp;


* IMR_EXTI
> [![dDBMC4j.png](https://iili.io/dDBMC4j.png)]()
&nbsp;

* PR_EXIN0
> [![dDBOWE7.png](https://iili.io/dDBOWE7.png)]()
&nbsp;


* full view 
> [![dDB0fg2.md.png](https://iili.io/dDB0fg2.md.png)]()
&nbsp;



[![MIT License](https://img.shields.io/badge/ALL%20FILES%20-7A5BE2)]()


[![MIT License](https://img.shields.io/badge/go%20back%20-7A5BE2)]()

&nbsp;
&nbsp;
&nbsp;

## 🔗 Links

[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/omar-samy-69a7241b0/)
