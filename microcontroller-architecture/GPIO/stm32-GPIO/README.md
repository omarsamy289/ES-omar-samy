 

<div align="center">
  
[![20YLRhN.md.png](https://iili.io/20YLRhN.md.png)]()

  </div>

  
[![MIT License](https://img.shields.io/badge/ALL%20FILES%20-7A5BE2)]()

# LAB 1 - MCU GPIO 
&nbsp;

* on STM32F106c6  :
> * configuring pA.1 and pA.13 as input floating (high z) .
> * configuring pB.1 and pB.13 as output push-pull .
&nbsp;

* configuring registers 
> * APB2ENR
> * GPIO_ODR
> * GPIO_IDR
> * GPIO_CRH
> * GPIO_CRL
> * GPIO_LOCK



* IO STRUCTURE
> [![2YtGqss.md.png](https://iili.io/2YtGqss.md.png)]()
&nbsp;



&nbsp;


## main.c : 

* main.c 

```c code




typedef volatile unsigned int vuint32_t ;
#define SET_BIT(ADDRESS, BIT) ADDRESS |= (1<<BIT)
#define RESET_BIT(ADDRESS, BIT) ADDRESS &= ~(1<<BIT)
#define TOGGEL_BIT(ADDRESS, BIT) ADDRESS ^= (1<<BIT)
#define READ_BIT(ADDRESS, BIT) ((ADDRESS & (1<<BIT)>>BIT))

//GPIOA
#define GPIOA_BASE  0x40010800
#define gpioA_ODR  *(vuint32_t *)(GPIOA_BASE + 0X0c)
#define gpioA_CRH  *(vuint32_t *)(GPIOA_BASE + 0X04)
#define gpioA_CRL  *(vuint32_t *)(GPIOA_BASE + 0X00)
#define	GPIOA_IDR *(vuint32_t *)(GPIOA_BASE + 0x08 )
#define	GPIOA_LCKR *(vuint32_t *)(GPIOA_BASE + 0x18)

//GPIOB
#define GPIOB_BASE  0x40010C00
#define gpioB_ODR  *(vuint32_t *)(GPIOB_BASE + 0X0c)
#define gpioB_CRH  *(vuint32_t *)(GPIOB_BASE + 0X04)
#define gpioB_CRL  *(vuint32_t *)(GPIOB_BASE + 0X00)
#define	GPIOB_IDR *(vuint32_t *)(GPIOB_BASE + 0x08)
#define	GPIOB_LCKR *(vuint32_t *)(GPIOB_BASE + 0x18)

//RCC
#define RCC_BASE 0x40021000
//register that enables CLK ON APB2 BUS
#define RCC_APB2ENR *(vuint32_t *)(RCC_BASE + 0X18)


vuint32_t i ;



void RCC_CONFIGURE() {

//ENABLE PORTA CLK
SET_BIT(RCC_APB2ENR ,2) ;

//ENABLE PORTB CLK
SET_BIT(RCC_APB2ENR ,3) ;

}

/*
CNFy[1:0]: Port x configuration bits (y= 0 .. 15)
These bits are written by software to configure the corresponding I/O port.
Refer to Table 20: Port bit configuration table.
In input mode (in case of (MODE[1:0]=00)):
00: Analog mode
>>> 01: Floating input (reset state)
10: Input with pull-up / pull-down
11: Reserved
In output mode (in case of (MODE[1:0] > 00)) :
>>> 00: General purpose output push-pull
01: General purpose output Open-drain
10: Alternate function output Push-pull
11: Alternate function output Open-drain
*/

/*
MODEy[1:0]: Port x mode bits (y= 0 .. 15)
These bits are written by software to configure the corresponding I/O port.
Refer to Table 20: Port bit configuration table.
>>> 00: Input mode (reset state)
01: Output mode, max speed 10 MHz.
>>> 10: Output mode, max speed 2 MHz.
11: Output mode, max speed 50 MHz.
*/

void GPIO_CONFIGURE() {

//PORTA.PIN1 INPUT FLOATING MODE PULLUP resistor (SINGLE PRESS)
//CNF1 01
// maro method
SET_BIT(gpioA_CRL, 6) ;
RESET_BIT(gpioA_CRL , 7) ;

// bianary method
//gpioA_CRL |= (0b01<<6)


//MODE1 00
// maro method
RESET_BIT(gpioA_CRL, 4) ;
RESET_BIT(gpioA_CRL ,5) ;



// bianary method
//gpioA_CRL &= ~(0b11 << 4) ;



////////////////

//PORTA.PIN13 INPUT FLOATING MODE PULLDOWN resistor (MULTI PRESS)

//CNF13 01
// maro method
SET_BIT(gpioA_CRH , 22) ;
RESET_BIT(gpioA_CRH , 23) ;

// bianary method
//gpioA_CRH |= (0b01<<6) ș


//MODE13 00
// maro method
RESET_BIT(gpioA_CRH, 20) ;
RESET_BIT(gpioA_CRH ,21) ;

// bianary method
//gpioA_CRH |= (0b00<<20)

/////////////////

//PORTB.PIN1 OUTPUT PUSH-PULL

//CNF1 00
// maro method
RESET_BIT(gpioB_CRL, 6) ;
RESET_BIT(gpioB_CRL , 7) ;

// bianary method
// gpioB_CRL &= ~(0b11<<6) ;


//MODE1 10
// macro method
RESET_BIT(gpioB_CRL, 4) ;
SET_BIT(gpioB_CRL ,5) ;

// bianary method
//gpioB_CRL |= (0b10 << 4) ;



/////////////

//PORTB.PIN13 OUTPUT PUSH-PULL
//PORTB.PIN13 OUTPUT PUSH-PULL

//CNF13 00
// maro method
RESET_BIT(gpioB_CRH, 22) ;
RESET_BIT(gpioB_CRH , 23) ;

// bianary method
//gpioB_CRH &= ~(0b11 <<22) ;


//MODE13 10
// maro method
RESET_BIT(gpioB_CRH, 20) ;
SET_BIT(gpioB_CRH ,21) ;

// bianary method
//gpioB_CRH |= (0b10 <<20) ;
//gpioB_ODR &= ~(1<<13) ;

/*
//PA1 input high z
gpioA_CRL |= 1 << 6 ;

//PB1 output push pull
//CFN:00 MODE:01
gpioB_CRL &= ~(0b11 << 6);
gpioB_CRL |= 0b01 << 4 ;

//PA13 input high z
gpioA_CRH &= 	~(0b11 << 20 ) ;
gpioA_CRH |= 	(0b01 << 22 ) ;

//PB13 output push pull

gpioB_CRH |= (0b01 << 20 ) ;
gpioB_CRH &= ~(0b11 << 22 ) ;

*/

gpioB_ODR  = 0xFFFFFFFF ;

}


/*
LOCK key writing sequence:
Write 1
Write 0
Write 1
Read 0
Read 1 (this read is optional but confirms that the lock is active)
*/


void GPIO_LOCK(){

//PORTA.PIN1
SET_BIT(GPIOA_LCKR,1);

//PORTA.PIN13
SET_BIT(GPIOA_LCKR,13);

//PORTB.PIN1
SET_BIT(GPIOB_LCKR,1);

//PORTB.PIN13
SET_BIT(GPIOB_LCKR,13);

//PORTA LOCK SEQUANCE

SET_BIT (GPIOA_LCKR,16);
RESET_BIT(GPIOA_LCKR,16);
SET_BIT(GPIOA_LCKR,16);
//READ_BIT(GPIOA_LCKR,16);
//READ_BIT(GPIOA_LCKR,16);
//checks if the lock has been done
if (~(READ_BIT(GPIOA_LCKR,16))) TOGGEL_BIT(gpioB_ODR, 1); ;
SET_BIT(gpioB_ODR, 1);
if ((READ_BIT(GPIOA_LCKR,16))) TOGGEL_BIT(gpioB_ODR, 1); ;
SET_BIT(gpioB_ODR, 1);
//PORTB LOCK SEQUANCE

SET_BIT (GPIOB_LCKR,16);
RESET_BIT(GPIOB_LCKR,16);
SET_BIT (GPIOB_LCKR,16);
//checks if the lock has been done
if ((READ_BIT(GPIOB_LCKR,16)) == 0 ){

	TOGGEL_BIT(gpioB_ODR ,13) ;
	for (int i = 0; i < 5000; i++);

}
if ((READ_BIT(GPIOB_LCKR,16)) == 1) TOGGEL_BIT(gpioB_ODR,13) ;


}


int main(void) {

RCC_CONFIGURE() ;
GPIO_CONFIGURE() ;
GPIO_LOCK() ;
gpioB_ODR = 0x11111111 ;

while(1){
//	gpioB_ODR |= (1<<1) ;
//	gpioB_ODR |= (1<<13) ;
/*
if(((READ_BIT(GPIOA_IDR,1)))==1) {
RESET_BIT(gpioB_ODR,1);
for (int i = 0; i < 5000; i++);
// arbitrary delay

}

if((READ_BIT(GPIOA_IDR,13))==1) {
RESET_BIT(gpioB_ODR,13) ;


}

*/

//PA1 >> external PUR
if  (( ( GPIOA_IDR & 1<<1) >>1 ) == 0 ){
	//single press
	//TOGGEL_BIT(gpioB_ODR, 1);
	gpioB_ODR ^= 1<<1 ;
	while(( ( GPIOA_IDR & 1<<1) >>1) == 0 );

	for (int i = 0; i < 5000; i++);
										}


if  (( ( GPIOA_IDR & 1<<13) >>13 ) == 1 ){

	//TOGGEL_BIT(gpioB_ODR, 13);
	gpioB_ODR ^= 1<<13 ;
	for (int i = 0; i < 5000; i++);
										}


}

}








```

* SYSTEM ARCHITECTURE
> [![2Yt1Uap.md.png](https://iili.io/2Yt1Uap.md.png)]()
&nbsp;


* IO STRUCTURE
> [![2YtGqss.md.png](https://iili.io/2YtGqss.md.png)]()
&nbsp;

* MEMORY OF RCC
> [![2YtMCj1.md.png](https://iili.io/2YtMCj1.md.png)]()

&nbsp;

* MEMORY OF PORTA - PORTB
> [![2YtMSFj.md.png](https://iili.io/2YtMSFj.md.png)]()
&nbsp;


* PORT BIT CONFIGURATION TABLE
> [![2YtVnHl.md.png](https://iili.io/2YtVnHl.md.png)]()

&nbsp;

* APB2ENR
> [![2YtVVig.md.png](https://iili.io/2YtVVig.md.png)]()
&nbsp;


* GPIO_ODR
> [![2YtWJdx.md.png](https://iili.io/2YtWJdx.md.png)]()
&nbsp;


* GPIO_IDR
> [![2YtWc1s.md.png](https://iili.io/2YtWc1s.md.png)]()
&nbsp;

* GPIO_LOCK
> [![2YtXR8x.md.png](https://iili.io/2YtXR8x.md.png)]()
> [![2YtXW8v.md.png](https://iili.io/2YtXW8v.md.png)]()
&nbsp;

* GPIO_CRH
> [![2Yth2oP.md.png](https://iili.io/2Yth2oP.md.png)]()
&nbsp;

* GPIO_CRL
> [![2YthVs9.md.png](https://iili.io/2YthVs9.md.png)]()
&nbsp;

* MODE BIT
> [![2YthtzN.md.png](https://iili.io/2YthtzN.md.png)]()
&nbsp;

* CNF BIT
> [![2YtjhQI.md.png](https://iili.io/2YtjhQI.md.png)]()
&nbsp;


* microVISION portB
> [![20YDwDx.md.png](https://iili.io/20YDwDx.md.png)]()

&nbsp;


* microVISION portA
> [![20YmGyu.md.png](https://iili.io/20YmGyu.md.png)]()
&nbsp;



[![MIT License](https://img.shields.io/badge/ALL%20FILES%20-7A5BE2)]()


[![MIT License](https://img.shields.io/badge/go%20back%20-7A5BE2)]()

&nbsp;
&nbsp;
&nbsp;

## 🔗 Links

[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/omar-samy-69a7241b0/)
