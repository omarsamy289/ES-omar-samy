

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
//	1: IO port A clock enabled

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
