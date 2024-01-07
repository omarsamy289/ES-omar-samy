 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <a href=""><img src="https://s13.gifyu.com/images/S021k.png" alt="771" border="0"></a><br /><a target='_blank' href='https://s13.gifyu.com/images/S021k.png'>


> click the button to view the pdf report ( system architecture of the project in only included in the pdf report )

[![MIT License](https://img.shields.io/badge/project%20pdf%20report%20-7A5BE2)]()

&nbsp;
&nbsp;

[![MIT License](https://img.shields.io/badge/all%20files%20-7A5BE2)]()

[![MIT License](https://img.shields.io/badge/protues%20snap%20shot%20-7A5BE2)]()
[![MIT License](https://img.shields.io/badge/TTOOL%20snap%20shot%20-7A5BE2)]()


&nbsp;
&nbsp;
[![MIT License](https://img.shields.io/badge/go%20back%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main)


# First term project 1 : pressure detection system 


# Embedded-c implementation 


## protues snap shot
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ![Alt Text](https://s13.gifyu.com/images/S021Q.gif)
 
 
 
## makefile

> the make file for target soc : cortex-m3

```makefile
#makefile for CORTEX M3


#this line is for the error that doesn't recognize make 
SHELL=C:/Windows/System32/cmd.exe


CC=arm-none-eabi-
#added -mthumb to CFLAGS for error: target CPU does not support ARM mode -mthumb or include PATH of stm32 ide ( which has  arm-none-eabi- included )
CFLAGS= -gdwarf-2 -g -mcpu=cortex-m3 
INCS= -I .
LIBS=
SRC= $(wildcard *.c)
OPJ= $(SRC:.c=.o)
#As= $(wildcard *.s)
#AsOPJ= $(As:.s=.o)

projectname=pressure_detect


all: $(projectname).bin
	@echo "build is done"
	ls
	
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

	
$(projectname).elf: $(OPJ) 
	$(CC)ld.exe -T linker_script.ld  $(LIBS)  $(OPJ)  -o $@ -Map=output.map
	cp $(projectname).elf $(projectname).axf

$(projectname).bin: $(projectname).elf 
	$(CC)objcopy.exe -O binary $<  $@
	
clean:
	rm *.elf *.bin

clean_all: 
	rm *.elf *.bin *.o 
	ls
	
dumpelf:
	arm-none-eabi-objdump.exe: -h  $(projectname).elf 


	

	
```
 
 
## startup code 

> the startup in c code for cortex-m3 stm32c6f103

```c code

/* startup code  in c code for cortex m3 stmf103c6 

omar samy 
*/

#include "mod_int_standard.h"


void reset_handler() ;
extern void main() ;
void Default_Handler() 
{ 	
 reset_handler();	
}

/*
--> function that are weak can be replaced or overwritten
--> function that are alias are alias to common funtion ( default_handeler) 
*/

void NHI_handler() __attribute__ ((weak, alias ("Default_Handler"))) ;
void H_Fault_handler() __attribute__ ((weak, alias ("Default_Handler"))) ;
void MM_Fault_handler() __attribute__ ((weak, alias ("Default_Handler"))) ;
void Bus_Fault_handler() __attribute__ ((weak, alias ("Default_Handler"))) ;
void Usage_Fault_handler() __attribute__ ((weak, alias ("Default_Handler"))) ;



/* -->.vector section  is set to be the firt section in .text ( flash memory ) in linker script and the first index
 is (calculated ) is count as stack top and stored at address 0X08000000 (first address in .text )
 accodring to this processor memory layout specification then the function handlers are also spicified to be after 
 the reset handler according to this processor memory layout .
 --> stack top calulated in linker script to be after bss end address by 0x1000
 */ 
 
extern unint32 stack_top ;
 
unint32 vectors[] __attribute__ ((section(".vectors"))) ={
	              

	(unint32) &stack_top,
	(unint32) &reset_handler,
	(unint32) &NHI_handler,
	(unint32) &H_Fault_handler,
	(unint32) &MM_Fault_handler,
	(unint32) &Bus_Fault_handler,
	(unint32) &Usage_Fault_handler
		
};


/*
--> reset function 
*/

extern unint32 _E_text ;
extern unint32 _S_data ;
extern unint32 _E_data ;
extern unint32 _S_bss ;
extern unint32 _E_bss ;


void reset_handler() 
{
//coping data section from flash to ram byte by byte ->unint8

unint32 data_size = (unint8*) &_E_data - (unint8*) &_S_data ;

unint8* p_src = (unint8*)  &_E_text ;

unint8* p_dst = (unint8*)  &_S_data ;

vunint32 i;

for ( i =0 ; i < data_size ; i++ ) {
	
	*((unint8*)p_dst++) = *((unint8*)p_src++ ) ;
                                       }

// bss intialzation and setting it to 0
unint32 bss_size = (unint8*) &_E_bss - (unint8*) &_S_bss ;
 p_dst = (unint8*) &_S_bss ;

for ( i =0 ; i < bss_size ; i++ ) {
	
	*((unint8*) p_dst++ ) = (unint8) 0 ;
                                      }

// jump to main 
	main() ;

}



```

 
 
## linker script

> the linker script fortarget soc : cortex m-3 stm32c6f103

```script

/* linker script for cortex-m3

eng. omar samy 

*/

ENTRY(reset_handler) 

MEMORY 
{
flash(RX) : ORIGIN = 0X08000000, LENGTH = 128K
sram(RWX) : ORIGIN = 0X20000000, LENGTH = 20K 	 

}

SECTIONS 
{
	.text :{
		
      * (.vectors*)
	  * (.text*)
	  * (.rodata)
	  * (.pressure_vals)
	  _E_text = . ;
      }> flash
	  
	.data :{
		_S_data = . ;
		* (.data)
	. = ALIGN(4) ;	
		_E_data = . ;	
      }> sram AT> flash
	  
	.bss :{
		_S_bss = . ;
		* (.bss*)
		_E_bss = . ;
		. = ALIGN(4) ;
	}> sram
	. = . + 0x1000 ;
	stack_top = . ;



}

```

 

## state.h
> in this file we created state difintions to further use and implement in files 
> also added the prototype of signals function that connencts between the blocks 

```c code
/*
 * stat.h
 *
 *  Created on: jan 7, 2024
 *      Author: omar
 */

#ifndef STATE_H_
#define STATE_H_
#include "mod_int_standard.h"

#define SET_BIT(ADDRESS,BIT)   ADDRESS |=  (1<<BIT)
#define RESET_BIT(ADDRESS,BIT) ADDRESS &= ~(1<<BIT)
#define TOGGLE_BIT(ADDRESS,BIT)  ADDRESS ^=  (1<<BIT)
#define READ_BIT(ADDRESS,BIT) ((ADDRESS) &   (1<<(BIT)))

#define GPIOA_CRL *(volatile unint32 *)(GPIO_PORTA + 0x00)
#define GPIOA_CRH *(volatile unint32 *)(GPIO_PORTA + 0X04)
#define GPIOA_IDR *(volatile unint32 *)(GPIO_PORTA + 0x08)
#define GPIOA_ODR *(volatile unint32 *)(GPIO_PORTA + 0x0C)


#define GPIO_PORTA 0x40010800
#define BASE_RCC   0x40021000

#define APB2ENR   *(volatile uint32_t *)(BASE_RCC + 0x18)





// state definitio macros
#define state_definition(state_func) void SD_##state_func()
#define state_name(state_func) SD_##state_func

// connections between the blocks

unint32 getPressureVal();
void Set_Alarm_actuator(int i);
state_definition(alarm_start) ;
state_definition(alarm_stop);



#endif /* STATE_H_ */

```



## contrller.h 

> the prototype of the main controller module

```c code
#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "state.h"


void Delay(unint32 nCount);


void GPIO_INITIALIZATION ();


// pointer to unction to move between the states
 void (*func_pointer_controller)() ;


enum {
    controller_idle,
    controller_busy
}controller_state_id;

       


state_definition(controller_idle) ;
state_definition(controller_busy) ;









#endif

```


## contrller.c 

> the implementation of the main controller module 

```c code

#include "controller.h"

extern void start_alarm() ;
extern void stop_alarm() ;
//extern void store_flash() ;

void GPIO_INITIALIZATION (){
	SET_BIT(APB2ENR, 2);
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;
}


vunint32 pressure_val ;
vunint32 threshold = 20 ;

void Delay(unint32 nCount)
{
	for(; nCount != 0; nCount--);
}

unint32  getPressureVal(){

	return (GPIOA_IDR & 0xFF);
}





state_definition(controller_idle) {

controller_state_id = controller_idle ;
stop_alarm() ;
//state_definition(alarm_stop);
state_definition(pressure_reading) ;
pressure_val =  getPressureVal() ;
//state_definition(flash_busy) ;
//store_flash() ;
(pressure_val > threshold )? (func_pointer_controller = state_name (controller_busy)) : (func_pointer_controller = state_name(controller_idle)) ;

}


state_definition(controller_busy) {
controller_state_id = controller_busy ;
 state_definition(alarm_start) ;
 start_alarm() ;
 state_definition(flash_busy) ;
 Delay(500000);
//state_definition( pressure_reading) ;
state_definition(pressure_reading) ;
pressure_val =  getPressureVal() ;
//state_definition(flash_busy) ;
//store_flash() ;
 (pressure_val > threshold) ? (func_pointer_controller = state_name (controller_busy)) : (func_pointer_controller = state_name(controller_idle)) ;
}



```


## alarm.h 

> the prototype of the alarm module

```c code
#ifndef ALARM_H_
#define ALARM_H_
#include "state.h"

enum {
    alarm_start,
    alarm_stop,
    alarm_idle
}alarm_state_id;

// pointer to unction to move between the states
 void (*func_pointer_alarm)() ;

void start_alarm() ;
void stop_alarm() ;
state_definition(alarm_idle) ;
state_definition(alarm_start) ;
state_definition(alarm_stop) ;

#endif

```


## alarm.c 

> the implementation of the alarm module

```c code
#include "alarm.h"

void Set_Alarm_actuator(int i){
	func_pointer_alarm = state_name(alarm_idle) ;
    if (i == 1){
		SET_BIT(GPIOA_ODR,13);
	}
	else if (i == 0){
		RESET_BIT(GPIOA_ODR,13);
	}
}

void start_alarm() {
Set_Alarm_actuator(0) ;

}

void stop_alarm() {

Set_Alarm_actuator(1) ;

}

state_definition(alarm_idle) {
 alarm_state_id = alarm_idle ;
 func_pointer_alarm = state_name(alarm_idle);
}

state_definition(alarm_start) {
    alarm_state_id= alarm_start ;
Set_Alarm_actuator(0) ;
func_pointer_alarm = state_name(alarm_start);
}


state_definition(alarm_stop) {
    alarm_state_id = alarm_stop ;
Set_Alarm_actuator(1) ;
func_pointer_alarm = state_name(alarm_idle);

}


```


## pressure.h 

> the prototype of the pressure seneor module

```c code
#ifndef PRESSURE_H_
#define PRESSURE_H_
#include "state.h"

//
 void (*func_pointer_pressure)() ;


enum {
    pressure_idle,
    pressure_reading
}pressure_state_id;

       


state_definition(pressure_idle) ;
state_definition( pressure_reading) ;



#endif

```


## pressure.c

> the implementation of  the pressure seneor module

```c code
#include "pressure.h"

extern unint32 getPressureVal();
extern void Delay(unint32 nCount);


state_definition(pressure_idle) {

pressure_state_id = pressure_idle ;


}

state_definition( pressure_reading) {
pressure_state_id =pressure_reading ;
//getPressureVal() ;
Delay(500000); 
func_pointer_pressure = state_name(pressure_idle) ;
 

}

```


## main.c 

> the main program

```c code
#include "state.h"
#include "pressure.h"
#include "alarm.h"
#include "controller.h"




void setup() {
// init all the drivers
// init all the stat pointers 
GPIO_INITIALIZATION();
func_pointer_controller = state_name (controller_idle) ;
//func_pointer_flash = state_name(flash_idle) ;
func_pointer_alarm = state_name(alarm_idle) ; 
func_pointer_pressure = state_name(pressure_idle) ;
// init all the modules
Set_Alarm_actuator(1) ;
// 



}
/*
the method to store values of pressure when changes in real time and storing it the .pressure_vals section 
in the soc flash ( and only when it dectecs changes in the values)
>>>>
if (current_value != past_value ) { 
       
 value_storage [count] =current_value  ;

past_value = current_value ;
    }
 ++count ;

*/
unint32 value_storage [100] __attribute__ ((section(".pressure_vals"))) ;
vunint32* flash_ptr ;
vunint32 current_value ;
vunint32 past_value ;
vunint32 count =0 ;
void main (){
	
	setup() ;
	while (1)
	{
	func_pointer_controller() ;
	*flash_ptr  = getPressureVal() ;
 current_value = *flash_ptr ;
if (count == 100 ) count = 0 ;
if (current_value != past_value ) { 
       
 value_storage [count] =current_value  ;

past_value = current_value ;
++count ;
    }
 

	}

}


```





## protues snapshot
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ![Alt Text](https://s13.gifyu.com/images/S021Q.gif)





&nbsp;
&nbsp;


> click the button to view the pdf report ( system architecture of the project in only included in the pdf report )

[![MIT License](https://img.shields.io/badge/project%20pdf%20report%20-7A5BE2)]()

&nbsp;
&nbsp;

[![MIT License](https://img.shields.io/badge/all%20files%20-7A5BE2)]()

[![MIT License](https://img.shields.io/badge/protues%20snap%20shot%20-7A5BE2)]()
[![MIT License](https://img.shields.io/badge/TTOOL%20snap%20shot%20-7A5BE2)]()


&nbsp;
&nbsp;
[![MIT License](https://img.shields.io/badge/go%20back%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main)



&nbsp;

## 🔗 Links

[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/omar-samy-69a7241b0/)
