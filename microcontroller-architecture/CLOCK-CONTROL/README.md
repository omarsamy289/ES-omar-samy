 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <a href=""><img src="https://iili.io/dZxmHDQ.md.png" alt="771" border="0"></a><br /><a target='_blank' href='https://iili.io/dZxmHDQ.md.png'>


[![MIT License](https://img.shields.io/badge/ALL%20FILES%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/microcontroller-architecture/CLOCK-CONTROL/ALLFILES)

# LAB 1 
* enabling GPIOA CLK ON APB2 BUS
* opening IOPAEN BIT on APB2ENR
*  SysClk 8 MHZ
*  only internal HSI_RC

### main.c 

```c code

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
// register address
#define GPIOA_BASE 0x40010800
#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x0C)
//0x4002 1000 - 0x4002 13FF Reset and clock control RCC
#define RCC_BASE 0x40021000
//APB2 peripheral clock enable register (RCC_APB2ENR)
//Address: 0x18
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE + 0x18)

int main(void)
{

//RCC_APB2ENR
//	Bit 2 IOPAEN: IO port A clock enable
//	Set and cleared by software.
//	0: IO port A clock disabled
//	1: IO port A clock enabled <<<<<

	RCC_APB2ENR |= 1<<2 ;



//Init GPIOA
GPIOA_CRH &= 0xFF0FFFFF;
GPIOA_CRH |= 0x00200000;
while(1)
{
GPIOA_ODR |= 1<<13 ;
for (int i = 0; i < 5000; i++); // arbitrary delay
GPIOA_ODR &= ~(1<<13) ;
for (int i = 0; i < 5000; i++); // arbitrary delay
}
}
```


### microVISION simulation

* RCC 
> [![dZx9iSn.png](https://iili.io/dZx9iSn.png)]()
&nbsp;
&nbsp;

* GPIOA I/O
> [![dZxJeQR.png](https://iili.io/dZxJeQR.png)]()
&nbsp;

* GPIOA registers
> [![dZxdpPp.png](https://iili.io/dZxdpPp.png)]()
&nbsp;

* logic analyzer
> [![dZx3HLx.md.png](https://iili.io/dZx3HLx.md.png)]()
&nbsp;

* full view 
> [![dZxFAnj.md.png](https://iili.io/dZxFAnj.md.png)]()
&nbsp;



# LAB 2-1
*  APB1 BUS frequancy 4MHZ
*  APB2 BUS frequancy 2MHZ
*  AHB  Bus freuancy  8MHZ
*  SysClk 8 MHZ
*  only internal HSI_RC


### main.c 

```c code


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
// register address
#define GPIOA_BASE 0x40010800
#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x0C)


//0x4002 1000 - 0x4002 13FF Reset and clock control RCC
#define RCC_BASE 0x40021000

//APB2 peripheral clock enable register (RCC_APB2ENR)
//Address: 0x18
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE + 0x18)

//Clock configuration register (RCC_CFGR)
//Address offset: 0x04
#define RCC_CFGR *(volatile uint32_t *)(RCC_BASE +  0x04)

// HSI is SYSCLK by default


int main(void)
{

	//RCC_APB2ENR
	//	Bit 2 IOPAEN: IO port A clock enable
	//	Set and cleared by software.
	//	0: IO port A clock disabled
	//	1: IO port A clock enabled
RCC_APB2ENR |= 1<<2 ;

//	Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
//	Set and cleared by software to control the division factor of the APB low-speed clock
//	(PCLK1).
//	Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
//	0xx: HCLK not divided
//	100: HCLK divided by 2<<
//	101: HCLK divided by 4
//	110: HCLK divided by 8
//	111: HCLK divided by 16
RCC_CFGR |= (0b100<<8) ;

//Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
//Set and cleared by software to control the division factor of the APB high-speed clock
//(PCLK2).
//0xx: HCLK not divided
//100: HCLK divided by 2
//101: HCLK divided by 4<<
//110: HCLK divided by 8
//111: HCLK divided by 16

RCC_CFGR |= (0b101<<11) ;



//Init GPIOA
GPIOA_CRH &= 0xFF0FFFFF;
GPIOA_CRH |= 0x00200000;
while(1)
{
GPIOA_ODR |= 1<<13 ;
for (int i = 0; i < 5000; i++); // arbitrary delay
GPIOA_ODR &= ~(1<<13) ;
for (int i = 0; i < 5000; i++); // arbitrary delay
}
}
```


### microVISION simulation

* clock tree
> [![dZxIlqX.md.png](https://iili.io/dZxIlqX.md.png)]()
&nbsp;

* RCC registers
> [![dZxTvnI.png](https://iili.io/dZxTvnI.png)]()
&nbsp;

* GPIOA I/O
> [![dZxukRj.md.png](https://iili.io/dZxukRj.md.png)]()
&nbsp;

* GPIOA registers
> [![dZxRK3F.png](https://iili.io/dZxRK3F.png)]()
&nbsp;

* logic analyzer
> [![dZxAhIR.md.png](https://iili.io/dZxAhIR.md.png)]()
&nbsp;

* Power reset and clock control (RCC)
> [![dZx5BK7.md.png](https://iili.io/dZx5BK7.md.png)]()
&nbsp;



# LAB 2-2 
*  APB1 BUS frequancy 16MHZ
*  APB2 BUS frequancy 8MHZ
*  AHB  Bus freuancy  32MHZ
*  SysClk 32 MHZ
*  only internal HSI_RC




### main.c 

```c code


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
// register address
#define GPIOA_BASE 0x40010800
#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x0C)


//0x4002 1000 - 0x4002 13FF Reset and clock control RCC
#define RCC_BASE 0x40021000


//Clock configuration register (RCC_CFGR)
//Address offset: 0x04
#define RCC_CFGR  *(volatile uint32_t *)(RCC_BASE + 0x04)


//APB2 peripheral clock enable register (RCC_APB2ENR)
//Address: 0x18
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE + 0x18)


//Clock control register (RCC_CR)
//Address offset: 0x00
#define RCC_CR *(volatile uint32_t *)(RCC_BASE +  0x00)



// HSI is SYSCLK by default


int main(void)
{

	//RCC_APB2ENR
	//	Bit 2 IOPAEN: IO port A clock enable
	//	Set and cleared by software.
	//	0: IO port A clock disabled
	//	1: IO port A clock enabled <<
RCC_APB2ENR |= 1<<2 ;


//PLLMUL: PLL multiplication factor
//Bits 21:18 PLLMUL: PLL multiplication factor
//These bits are written by software to define the PLL multiplication factor. These bits can be
//written only when PLL is disabled.
//Caution: The PLL output frequency must not exceed 72 MHz.
//0000: PLL input clock x 2
//0001: PLL input clock x 3
//0010: PLL input clock x 4
//0011: PLL input clock x 5
//0100: PLL input clock x 6
//0101: PLL input clock x 7
//0110: PLL input clock x 8 <<
RCC_CFGR |= (0b0110<<18) ;



//Bit 24 PLLON: PLL enable
//Set and cleared by software to enable PLL.
//Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the
//PLL clock is used as system clock or is selected to become the system clock.
//0: PLL OFF
//1: PLL ON <<

RCC_CR |= 1<<24 ;

//SW: System clock switch
//Bits 1:0 SW: System clock switch
//Set and cleared by software to select SYSCLK source.
//Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of
//failure of the HSE oscillator used directly or indirectly as system clock (if the Clock Security
//System is enabled).
//00: HSI selected as system clock
//01: HSE selected as system clock
//10: PLL selected as system clock  <<
//11: not allowed
RCC_CFGR |= (0b10<<0) ;





//	Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
//	Set and cleared by software to control the division factor of the APB low-speed clock
//	(PCLK1).
//	Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
//	0xx: HCLK not divided
//	100: HCLK divided by 2 <<
//	101: HCLK divided by 4
//	110: HCLK divided by 8
//	111: HCLK divided by 16
RCC_CFGR |= (0b100<<8) ;

//Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
//Set and cleared by software to control the division factor of the APB high-speed clock
//(PCLK2).
//0xx: HCLK not divided
//100: HCLK divided by 2
//101: HCLK divided by 4 <<
//110: HCLK divided by 8
//111: HCLK divided by 16

RCC_CFGR |= (0b101<<11) ;



//Init GPIOA
GPIOA_CRH &= 0xFF0FFFFF;
GPIOA_CRH |= 0x00200000;
while(1)
{
GPIOA_ODR |= 1<<13 ;
for (int i = 0; i < 5000; i++); // arbitrary delay
GPIOA_ODR &= ~(1<<13) ;
for (int i = 0; i < 5000; i++); // arbitrary delay
}
}


```


### microVISION simulation

* clock tree
>[![dZx0mXa.md.png](https://iili.io/dZx0mXa.md.png)]()
&nbsp;

* RCC registers
> [![dZx0ve9.png](https://iili.io/dZx0ve9.png)]()
&nbsp;

* GPIOA I/O
> [![dZx0xHP.md.png](https://iili.io/dZx0xHP.md.png)]()
&nbsp;

* GPIOA registers
> [![dZxlByX.png](https://iili.io/dZxlByX.png)]()
&nbsp;

* FULL view
> [![dZxcVkX.md.png](https://iili.io/dZxcVkX.md.png)]()
&nbsp;

* Power reset and clock control (RCC)
> [![dZxaUzJ.md.png](https://iili.io/dZxaUzJ.md.png)]()
&nbsp;





[![MIT License](https://img.shields.io/badge/ALL%20FILES%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/microcontroller-architecture/CLOCK-CONTROL/ALLFILES)


[![MIT License](https://img.shields.io/badge/go%20back%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy)

&nbsp;
&nbsp;
&nbsp;

## 🔗 Links

[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/omar-samy-69a7241b0/)
