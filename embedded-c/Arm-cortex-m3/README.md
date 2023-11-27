 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <a href=""><img src="https://iili.io/JoLMZlf.md.png" alt="771" border="0"></a><br /><a target='_blank' href='https://iili.io/JoLMZlf.md.png'>


[![MIT License](https://img.shields.io/badge/ALL%20FILES%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/embedded-c/Arm-cortex-m3/All%20files)

# LAB 2
# this is a full detailed report on ARM cortex-m3 stm32f103c8t6 with linkerscript and startup in c code and dubugging in protues
## toggel led in pin13 - PORTA0


## main.c : here we set the registers : RCC_APB2ENR , gpio_ODR and gpio_CRH and creat a function to toggel a specific pin in portA  

> **Note**
 mod int standard library is also included in this project to make use of 
>

### main.c 

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
unint32 var_bss[3] ;

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


## startup.c
#### in this startup file we set .vector sctioon which will be the first section in the flash memory it will have stac_top information stored at the first address the the reset handler then the vector handlers 
###  which will be weak and alias to commen function (default handler ) then in the reser handler we inialize the .data section in flash and coping it to the sram then inlaizing .bss section and set it to 0 
### then jumps to main function

```c code

/* startup code  in c code for cortex m3 

omar samy 
*/

#include "mod_int_standard.h"


void reset_handler() ;
extern int main(void) ;
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


## mod_int_standard.h
#### this header files contais the modified int standard library for refrence 

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
typedef unsigned  int   unint32;
typedef unsigned  long long     unint64;
//signed
typedef  signed char  sint8;
typedef signed  short sint16;
typedef    signed int  sint32;
typedef  signed long long     sint64;
//Volatile unsigned
typedef volatile unsigned  char  vunint8;
typedef volatile unsigned  short vunint16;
typedef  volatile unsigned      vunint32;
typedef volatile unsigned  long long    vunint64;
//Volatile signed
typedef  volatile signed char  vsint8;
typedef  volatile signed short vsint16;
typedef   volatile signed int  vsint32;
typedef  volatile signed long long    vsint64;


#endif

```
## linker script 
### in linker script we set flash and sram adresses and sizes and set the start and the end of every section to furthur use for inilaization of .data section and .bss and also to set the stack_top at address after 
### .bss section by 0x1000 and pases this information to the very begainging of flash memory


```python
/* linker script for cortex-m3

eng. omar samy 

*/

ENTRY(reset_handler) 

MEMORY 
{
flash(RX) : ORIGIN = 0X08000000, LENGTH = 128K
sram(RWX) : ORIGIN = 0X20000000, LENGTH =  20K 	 

}

SECTIONS 
{
	.text :{
		
      * (.vectors*)
	  * (.text*)
	  * (.rodata)
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

## makefile 
> **Note**
the arm processor mcpu command is : cortex-m3
>

```Makefile
#makefile for cortex_m3 lab2 


#this line is for the error : doesn't see make 
SHELL=C:/Windows/System32/cmd.exe


CC=arm-none-eabi-
#added -mthumb to CFLAGS for error: target CPU does not support ARM mode -mthumb or include PATH of stm32 ide ( which has  arm-none-eabi- included )
CFLAGS= -gdwarf-2 -mcpu=cortex-m3 
INCS= -I .
LIBS=
SRC= $(wildcard *.c)
OPJ= $(SRC:.c=.o)
#As= $(wildcard *.s)
#AsOPJ= $(As:.s=.o)

projectname=cortex_m3

#AsOPJ gives error when replaced with startup.o in L:27
all: $(projectname).bin
	@echo "build is done"
	ls
	
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

	
$(projectname).elf: $(OPJ) 
	$(CC)ld.exe -T linker_script.ld  $(LIBS)  $(OPJ)  -o $@ -Map=output.map

$(projectname).bin: $(projectname).elf 
	$(CC)objcopy.exe -O binary $<  $@
	
clean:
	rm *.elf *.bin

clean_all: 
	rm *.elf *.bin *.o 
	ls
	
dumpelf:
	arm-none-eabi-objdump.exe: -h  $(projectname).elf

dumpobj:
	arm-none-eabi-objdump.exe: -h  main.o
	
```

### main.o sections

[![JoLB7Qn.md.png](https://iili.io/JoLB7Qn.md.png)](https://freeimage.host/i/JoLB7Qn)

### startup.o sections
[![JoLCxne.md.png](https://iili.io/JoLCxne.md.png)](https://freeimage.host/i/JoLCxne)

### cortex-m3.elf sections

[![JoLCkVn.md.png](https://iili.io/JoLCkVn.md.png)](https://freeimage.host/i/JoLCkVn)





## mapfile 

```Assembly

Allocating common symbols
Common symbol       size              file

var_bss             0xc               main.o

Memory Configuration

Name             Origin             Length             Attributes
flash            0x0000000008000000 0x0000000000020000 xr
sram             0x0000000020000000 0x0000000000005000 xrw
*default*        0x0000000000000000 0xffffffffffffffff

Linker script and memory map


.text           0x0000000008000000      0x128
 *(.vectors*)
 .vectors       0x0000000008000000       0x1c startup.o
                0x0000000008000000                vectors
 *(.text*)
 .text          0x000000000800001c       0x7c main.o
                0x000000000800001c                main
 .text          0x0000000008000098       0x90 startup.o
                0x0000000008000098                Usage_Fault_handler
                0x0000000008000098                H_Fault_handler
                0x0000000008000098                Default_Handler
                0x0000000008000098                MM_Fault_handler
                0x0000000008000098                NHI_handler
                0x0000000008000098                Bus_Fault_handler
                0x00000000080000a4                reset_handler
 *(.rodata)
                0x0000000008000128                _E_text = .

.glue_7         0x0000000008000128        0x0
 .glue_7        0x0000000008000128        0x0 linker stubs

.glue_7t        0x0000000008000128        0x0
 .glue_7t       0x0000000008000128        0x0 linker stubs

.vfp11_veneer   0x0000000008000128        0x0
 .vfp11_veneer  0x0000000008000128        0x0 linker stubs

.v4_bx          0x0000000008000128        0x0
 .v4_bx         0x0000000008000128        0x0 linker stubs

.iplt           0x0000000008000128        0x0
 .iplt          0x0000000008000128        0x0 main.o

.rel.dyn        0x0000000008000128        0x0
 .rel.iplt      0x0000000008000128        0x0 main.o

.data           0x0000000020000000        0x4 load address 0x0000000008000128
                0x0000000020000000                _S_data = .
 *(.data)
 .data          0x0000000020000000        0x4 main.o
                0x0000000020000000                ptrporta
 .data          0x0000000020000004        0x0 startup.o
                0x0000000020000004                . = ALIGN (0x4)
                0x0000000020000004                _E_data = .

.igot.plt       0x0000000020000004        0x0 load address 0x000000000800012c
 .igot.plt      0x0000000020000004        0x0 main.o

.bss            0x0000000020000004        0xc load address 0x000000000800012c
                0x0000000020000004                _S_bss = .
 *(.bss*)
 .bss           0x0000000020000004        0x0 main.o
 .bss           0x0000000020000004        0x0 startup.o
                0x0000000020000004                _E_bss = .
                0x0000000020000004                . = ALIGN (0x4)
 COMMON         0x0000000020000004        0xc main.o
                0x0000000020000004                var_bss
                0x0000000020001010                . = (. + 0x1000)
                0x0000000020001010                stack_top = .
LOAD main.o
LOAD startup.o
OUTPUT(cortex_m3.elf elf32-littlearm)

.debug_info     0x0000000000000000      0x2d5
 .debug_info    0x0000000000000000      0x153 main.o
 .debug_info    0x0000000000000153      0x182 startup.o

.debug_abbrev   0x0000000000000000      0x1ac
 .debug_abbrev  0x0000000000000000       0xe5 main.o
 .debug_abbrev  0x00000000000000e5       0xc7 startup.o

.debug_loc      0x0000000000000000       0xb4
 .debug_loc     0x0000000000000000       0x38 main.o
 .debug_loc     0x0000000000000038       0x7c startup.o

.debug_aranges  0x0000000000000000       0x40
 .debug_aranges
                0x0000000000000000       0x20 main.o
 .debug_aranges
                0x0000000000000020       0x20 startup.o

.debug_line     0x0000000000000000       0xef
 .debug_line    0x0000000000000000       0x70 main.o
 .debug_line    0x0000000000000070       0x7f startup.o

.debug_str      0x0000000000000000      0x1db
 .debug_str     0x0000000000000000      0x155 main.o
                                        0x196 (size before relaxing)
 .debug_str     0x0000000000000155       0x86 startup.o
                                        0x1d3 (size before relaxing)

.comment        0x0000000000000000       0x7b
 .comment       0x0000000000000000       0x7b main.o
                                         0x7c (size before relaxing)
 .comment       0x000000000000007b       0x7c startup.o

.ARM.attributes
                0x0000000000000000       0x33
 .ARM.attributes
                0x0000000000000000       0x33 main.o
 .ARM.attributes
                0x0000000000000033       0x33 startup.o

.debug_frame    0x0000000000000000       0x7c
 .debug_frame   0x0000000000000000       0x2c main.o
 .debug_frame   0x000000000000002c       0x50 startup.o

```

[![JoLneeV.md.png](https://iili.io/JoLneeV.md.png)](https://freeimage.host/i/JoLneeV)


[![JoLnSX1.md.png](https://iili.io/JoLnSX1.md.png)](https://freeimage.host/i/JoLnSX1)



## Read-elf file 

```Assembly
ELF Header:
  Magic:   7f 45 4c 46 01 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF32
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              EXEC (Executable file)
  Machine:                           ARM
  Version:                           0x1
  Entry point address:               0x80000a5
  Start of program headers:          52 (bytes into file)
  Start of section headers:          134468 (bytes into file)
  Flags:                             0x5000200, Version5 EABI, soft-float ABI
  Size of this header:               52 (bytes)
  Size of program headers:           32 (bytes)
  Number of program headers:         2
  Size of section headers:           40 (bytes)
  Number of section headers:         16
  Section header string table index: 15
ELF Header:
  Magic:   7f 45 4c 46 01 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF32
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              EXEC (Executable file)
  Machine:                           ARM
  Version:                           0x1
  Entry point address:               0x80000a5
  Start of program headers:          52 (bytes into file)
  Start of section headers:          134468 (bytes into file)
  Flags:                             0x5000200, Version5 EABI, soft-float ABI
  Size of this header:               52 (bytes)
  Size of program headers:           32 (bytes)
  Number of program headers:         2
  Size of section headers:           40 (bytes)
  Number of section headers:         16
  Section header string table index: 15

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .text             PROGBITS        08000000 010000 000128 00  AX  0   0  4
  [ 2] .data             PROGBITS        20000000 020000 000004 00  WA  0   0  4
  [ 3] .bss              NOBITS          20000004 020004 00000c 00  WA  0   0  4
  [ 4] .debug_info       PROGBITS        00000000 020004 0002d5 00      0   0  1
  [ 5] .debug_abbrev     PROGBITS        00000000 0202d9 0001ac 00      0   0  1
  [ 6] .debug_loc        PROGBITS        00000000 020485 0000b4 00      0   0  1
  [ 7] .debug_aranges    PROGBITS        00000000 020539 000040 00      0   0  1
  [ 8] .debug_line       PROGBITS        00000000 020579 0000ef 00      0   0  1
  [ 9] .debug_str        PROGBITS        00000000 020668 0001db 01  MS  0   0  1
  [10] .comment          PROGBITS        00000000 020843 00007b 01  MS  0   0  1
  [11] .ARM.attributes   ARM_ATTRIBUTES  00000000 0208be 000033 00      0   0  1
  [12] .debug_frame      PROGBITS        00000000 0208f4 00007c 00      0   0  4
  [13] .symtab           SYMTAB          00000000 020970 000260 10     14  21  4
  [14] .strtab           STRTAB          00000000 020bd0 0000d7 00      0   0  1
  [15] .shstrtab         STRTAB          00000000 020ca7 00009d 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings), I (info),
  L (link order), O (extra OS processing required), G (group), T (TLS),
  C (compressed), x (unknown), o (OS specific), E (exclude),
  y (purecode), p (processor specific)

There are no section groups in this file.

Program Headers:
  Type           Offset   VirtAddr   PhysAddr   FileSiz MemSiz  Flg Align
  LOAD           0x010000 0x08000000 0x08000000 0x00128 0x00128 R E 0x10000
  LOAD           0x020000 0x20000000 0x08000128 0x00004 0x00010 RW  0x10000

 Section to Segment mapping:
  Segment Sections...
   00     .text 
   01     .data .bss 

There is no dynamic section in this file.

There are no relocations in this file.

There are no unwind sections in this file.

Symbol table '.symtab' contains 38 entries:
   Num:    Value  Size Type    Bind   Vis      Ndx Name
     0: 00000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 08000000     0 SECTION LOCAL  DEFAULT    1 
     2: 20000000     0 SECTION LOCAL  DEFAULT    2 
     3: 20000004     0 SECTION LOCAL  DEFAULT    3 
     4: 00000000     0 SECTION LOCAL  DEFAULT    4 
     5: 00000000     0 SECTION LOCAL  DEFAULT    5 
     6: 00000000     0 SECTION LOCAL  DEFAULT    6 
     7: 00000000     0 SECTION LOCAL  DEFAULT    7 
     8: 00000000     0 SECTION LOCAL  DEFAULT    8 
     9: 00000000     0 SECTION LOCAL  DEFAULT    9 
    10: 00000000     0 SECTION LOCAL  DEFAULT   10 
    11: 00000000     0 SECTION LOCAL  DEFAULT   11 
    12: 00000000     0 SECTION LOCAL  DEFAULT   12 
    13: 00000000     0 FILE    LOCAL  DEFAULT  ABS startup.c
    14: 08000098     0 NOTYPE  LOCAL  DEFAULT    1 $t
    15: 08000000     0 NOTYPE  LOCAL  DEFAULT    1 $d
    16: 08000114     0 NOTYPE  LOCAL  DEFAULT    1 $d
    17: 00000000     0 FILE    LOCAL  DEFAULT  ABS main.c
    18: 20000000     0 NOTYPE  LOCAL  DEFAULT    2 $d
    19: 0800001c     0 NOTYPE  LOCAL  DEFAULT    1 $t
    20: 0800008c     0 NOTYPE  LOCAL  DEFAULT    1 $d
    21: 08000099    12 FUNC    WEAK   DEFAULT    1 Bus_Fault_handler
    22: 080000a5   132 FUNC    GLOBAL DEFAULT    1 reset_handler
    23: 08000099    12 FUNC    WEAK   DEFAULT    1 H_Fault_handler
    24: 20000004     0 NOTYPE  GLOBAL DEFAULT    2 _E_data
    25: 20000000     0 NOTYPE  GLOBAL DEFAULT    2 _S_data
    26: 20000004     0 NOTYPE  GLOBAL DEFAULT    3 _E_bss
    27: 08000099    12 FUNC    GLOBAL DEFAULT    1 Default_Handler
    28: 20000004     0 NOTYPE  GLOBAL DEFAULT    3 _S_bss
    29: 20001010     0 NOTYPE  GLOBAL DEFAULT    3 stack_top
    30: 0800001d   124 FUNC    GLOBAL DEFAULT    1 main
    31: 20000000     4 OBJECT  GLOBAL DEFAULT    2 ptrporta
    32: 20000004    12 OBJECT  GLOBAL DEFAULT    3 var_bss
    33: 08000099    12 FUNC    WEAK   DEFAULT    1 MM_Fault_handler
    34: 08000099    12 FUNC    WEAK   DEFAULT    1 NHI_handler
    35: 08000128     0 NOTYPE  GLOBAL DEFAULT    1 _E_text
    36: 08000000    28 OBJECT  GLOBAL DEFAULT    1 vectors
    37: 08000099    12 FUNC    WEAK   DEFAULT    1 Usage_Fault_handler

No version information found in this file.
Attribute Section: aeabi
File Attributes
  Tag_CPU_name: "Cortex-M3"
  Tag_CPU_arch: v7
  Tag_CPU_arch_profile: Microcontroller
  Tag_THUMB_ISA_use: Thumb-2
  Tag_ABI_PCS_wchar_t: 4
  Tag_ABI_FP_denormal: Needed
  Tag_ABI_FP_exceptions: Needed
  Tag_ABI_FP_number_model: IEEE 754
  Tag_ABI_align_needed: 8-byte
  Tag_ABI_align_preserved: 8-byte, except leaf SP
  Tag_ABI_enum_size: small
  Tag_ABI_optimization_goals: Aggressive Debug
  Tag_CPU_unaligned_access: v6

```






### Disassemply of the elf image for refrance 
[![MIT License](https://img.shields.io/badge/dis%20assembly%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/blob/main/embedded-c/Arm-cortex-m3/All%20files/disas.txt)





## debugging in protues : we compiled with debugging option -gdwarf-2 to run debug on protues
### at first .data intialized and copied from flash to sram then the initialization of .bss section and setting it to 0 then the program jumpsto main function

 ![Alt Text](https://s5.gifyu.com/images/SRF9z.gif)








[![MIT License](https://img.shields.io/badge/ALL%20FILES%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/embedded-c/Arm-cortex-m3/All%20files)

[![MIT License](https://img.shields.io/badge/go%20to%20top%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/embedded-c/Arm-cortex-m3)

[![MIT License](https://img.shields.io/badge/go%20back%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main)

&nbsp;
&nbsp;

&nbsp;

## 🔗 Links

[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/omar-samy-69a7241b0/)
