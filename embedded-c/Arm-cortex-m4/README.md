 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <a href=""><img src="https://iili.io/Jx6k5ap.md.png" alt="771" border="0"></a><br /><a target='_blank' href='https://iili.io/Jx6k5ap.md.png'>


[![MIT License](https://img.shields.io/badge/ALL%20FILES%20-7A5BE2)]()

# LAB 3
#  report on ARM CORTEX-M4 ( TIVAC TM4C123GXL )
## with linkerscript and startup in c code and dubugging in keil uvision
## toggel led in pin13 - PORTAF pin3


 ![Alt Text](https://s5.gifyu.com/images/SRoTp.gif)
[![MIT License](https://img.shields.io/badge/view%20simulation%20in%20full%20screen%20-7A5BE2)](https://s5.gifyu.com/images/SRoTp.gif)




 




## main.c : 
here we set the registers : SYSCTL_RCGC2_R , GPIO_PORTF_DIR_R , GPIO_PORTF_DEN_R and GPIO_PORTF_DATA_R  
and creat a function to toggel a specific pin in PORTF  
- SYSCTL_RCGC2_R : SYSTEM CLOCK REGISTER
- GPIO_PORTF_DIR_R : PORT DIRECTION REGISTER 
- GPIO_PORTF_DEN_R : PORT ENABLING REGISTER
- GPIO_PORTF_DATA_R : PORT DATA REGISTER 


> **Note**
 mod int standard library is also included in this project to make use of 
>

### main.c 

```c code
/*
ARM cortex m4 
TIVA C 
TM4c123GXL
omar samy
*/
#include "mod_int_standard.h"

//SYSTEM CLOCK REGISTER
#define SYSCTL_RCGC2_R   *((vunint32*)(0x400FE000 + 0x108))
// PORT DIRECTION REGISTER
#define GPIO_PORTF_DIR_R   *((vunint32*)(0x40025000 + 0x400))
// PORT  DATA REGISTER 
#define GPIO_PORTF_DATA_R   *((vunint32*)(0x40025000 + 0x3FC))
//PORT ENABLE REGISTER
#define GPIO_PORTF_DEN_R   *((vunint32*)(0x40025000 + 0x51C))



int main()
{
	
	vunint32 count ;
	// ENABLES RCC CLOCK
SYSCTL_RCGC2_R  = 0x20 ;
// dalay 
for ( count =0 ; count < 300 ; count ++) ; 

//direction is out for pin3 portf 
GPIO_PORTF_DIR_R |= 1<<3 ; 

// data enabling register 
GPIO_PORTF_DEN_R |= 1<<3 ; 

while (1)
{
GPIO_PORTF_DATA_R |= 1<<3 ;	
	for ( count =0 ; count < 200000 ; count ++) ; 
GPIO_PORTF_DATA_R &= ~(1<<3) ;		
	for ( count =0 ; count < 200000 ; count ++) ; 	
}


return 0 ;	
}

```

 ![Alt Text](https://s5.gifyu.com/images/SRoTW.gif)





## startup.c
in this startup file we set .vector sctioon which will be the first section in the flash memory (.text) it will have stac_top information stored 
at the first address the the reset handler then threre is other handlers which will be weak and alias to commen function (default handler ) then in the
reset handler we inialize the .data section in flash and coping it to the sram then inlaizing .bss section and set it to 0 
then jumps to main function

.vector section  is set to be the firt section in .text ( flash memory ) in linker script and the first index is (calculated ) is count as stack top and
stored at address 0X00000000 (first address in .text -> (scetion .vectors -> ( stack_top info ) ) accodring to this processor memory layout specification
then the function handlers are also spicified to be after the reset handler according to this processor memory layout .
 --> stack top is calculated to be a static array of 256 elements which indicates 1024 byte ( size of the stack memory  in  .bss means that stack 
 top points to the the address of  stack_top[0] + 256 elements results in the end of this array as the stack top points to the top of the stack .

```c code

/* startup code  in c code for cortex m4 
TIVA C 
TM4C123GXL

@ omar samy  2023
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
 is (calculated ) is count as stack top and stored at address 0X00000000 (first address in .text -> (scetion .vectors -> ( stack_top info ) )
 accodring to this processor memory layout specification then the function handlers are also spicified to be after 
 the reset handler according to this processor memory layout .
 --> stack top is calculated to be astatic array of 256 elements which indicates 1024 byte ( size of the stack memory  in  .bss means that stack 
 top points to the the address of  stack_top[0] + 256 elements results in the end of this array as the stack top points to the top of the stack .
 @ omar samy 2023
 */ 
 
 static unint32 stack_top[256] ;
 
// array of pointers that point to function that takes no arguments and return void --> the pointrt itself is constent
//the pointer is 4 byte which indicate each handler itsels is 4 byte 
void (* const g_p_fn_vectors[])() __attribute__ ((section(".vectors"))) ={
	
	(void (*)()) ( (unint32)stack_top +sizeof(stack_top)),
	 &reset_handler,
	 &NHI_handler,
	 &H_Fault_handler,
	 &MM_Fault_handler,
	 &Bus_Fault_handler,
	 &Usage_Fault_handler
	
	
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
 in linker script we set flash and sram adresses and sizes and set the start and the end of every section to furthur use for inilaization of .data
 section and .bss 


``` python
/* linker script for cortex-M4
TIVA C 
TM4C123GXL
@eng. omar samy  2023


*/

ENTRY(reset_handler) 

MEMORY 
{
flash(RX) : ORIGIN = 0X00000000, LENGTH = 512M
sram(RWX) : ORIGIN = 0X20000000, LENGTH = 512M 	 

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
	}> sram
	


}

```

## makefile 
> **Note**
the arm processor mcpu command is : cortex-m4
>

```Makefile
#makefile for cortex_m4 lab3


#this line is for the error : doesn't see make 
SHELL=C:/Windows/System32/cmd.exe


CC=arm-none-eabi-
#added -mthumb to CFLAGS for error: target CPU does not support ARM mode -mthumb or include PATH of stm32 ide ( which has  arm-none-eabi- included )
CFLAGS= -gdwarf-2 -g -mcpu=cortex-m4
INCS= -I .
LIBS=
SRC= $(wildcard *.c)
OPJ= $(SRC:.c=.o)
#As= $(wildcard *.s)
#AsOPJ= $(As:.s=.o)

projectname=cortex_m4

#AsOPJ gives error when replaced with startup.o in L:27
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


### cortex-m3.elf sections
[![Jx6WeJn.md.png](https://iili.io/Jx6WeJn.md.png)](https://freeimage.host/i/Jx6WeJn)


[![Jx6X9qB.md.png](https://iili.io/Jx6X9qB.md.png)](https://freeimage.host/i/Jx6X9qB)


[![Jx6XKmJ.md.png](https://iili.io/Jx6XKmJ.md.png)](https://freeimage.host/i/Jx6XKmJ)


## mapfile 

```Assembly

Memory Configuration

Name             Origin             Length             Attributes
flash            0x0000000000000000 0x0000000020000000 xr
sram             0x0000000020000000 0x0000000020000000 xrw
*default*        0x0000000000000000 0xffffffffffffffff

Linker script and memory map


.text           0x0000000000000000      0x13c
 *(.vectors*)
 .vectors       0x0000000000000000       0x1c startup.o
                0x0000000000000000                g_p_fn_vectors
 *(.text*)
 .text          0x000000000000001c       0x90 main.o
                0x000000000000001c                main
 .text          0x00000000000000ac       0x90 startup.o
                0x00000000000000ac                Usage_Fault_handler
                0x00000000000000ac                H_Fault_handler
                0x00000000000000ac                Default_Handler
                0x00000000000000ac                MM_Fault_handler
                0x00000000000000ac                NHI_handler
                0x00000000000000ac                Bus_Fault_handler
                0x00000000000000b8                reset_handler
 *(.rodata)
                0x000000000000013c                _E_text = .

.glue_7         0x000000000000013c        0x0
 .glue_7        0x000000000000013c        0x0 linker stubs

.glue_7t        0x000000000000013c        0x0
 .glue_7t       0x000000000000013c        0x0 linker stubs

.vfp11_veneer   0x000000000000013c        0x0
 .vfp11_veneer  0x000000000000013c        0x0 linker stubs

.v4_bx          0x000000000000013c        0x0
 .v4_bx         0x000000000000013c        0x0 linker stubs

.iplt           0x000000000000013c        0x0
 .iplt          0x000000000000013c        0x0 main.o

.rel.dyn        0x000000000000013c        0x0
 .rel.iplt      0x000000000000013c        0x0 main.o

.data           0x0000000020000000        0x0 load address 0x000000000000013c
                0x0000000020000000                _S_data = .
 *(.data)
 .data          0x0000000020000000        0x0 main.o
 .data          0x0000000020000000        0x0 startup.o
                0x0000000020000000                . = ALIGN (0x4)
                0x0000000020000000                _E_data = .

.igot.plt       0x0000000020000000        0x0 load address 0x000000000000013c
 .igot.plt      0x0000000020000000        0x0 main.o

.bss            0x0000000020000000      0x400 load address 0x000000000000013c
                0x0000000020000000                _S_bss = .
 *(.bss*)
 .bss           0x0000000020000000        0x0 main.o
 .bss           0x0000000020000000      0x400 startup.o
                0x0000000020000400                _E_bss = .
LOAD main.o
LOAD startup.o
OUTPUT(cortex_m4.elf elf32-littlearm)

.debug_info     0x0000000000000000      0x258
 .debug_info    0x0000000000000000       0xab main.o
 .debug_info    0x00000000000000ab      0x1ad startup.o

.debug_abbrev   0x0000000000000000      0x13f
 .debug_abbrev  0x0000000000000000       0x65 main.o
 .debug_abbrev  0x0000000000000065       0xda startup.o

.debug_loc      0x0000000000000000       0xb4
 .debug_loc     0x0000000000000000       0x38 main.o
 .debug_loc     0x0000000000000038       0x7c startup.o

.debug_aranges  0x0000000000000000       0x40
 .debug_aranges
                0x0000000000000000       0x20 main.o
 .debug_aranges
                0x0000000000000020       0x20 startup.o

.debug_line     0x0000000000000000       0xf8
 .debug_line    0x0000000000000000       0x79 main.o
 .debug_line    0x0000000000000079       0x7f startup.o

.debug_str      0x0000000000000000      0x19e
 .debug_str     0x0000000000000000      0x111 main.o
                                        0x14a (size before relaxing)
 .debug_str     0x0000000000000111       0x8d startup.o
                                        0x1cd (size before relaxing)

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



[![Jx6XoqN.md.png](https://iili.io/Jx6XoqN.md.png)](https://freeimage.host/i/Jx6XoqN)

[![Jx6Xzgt.md.png](https://iili.io/Jx6Xzgt.md.png)](https://freeimage.host/i/Jx6Xzgt)


## Read-elf file 

```Assembly
Attribute Section: aeabi
File Attributes
  Tag_CPU_name: "Cortex-M4"
  Tag_CPU_arch: v7E-M
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
  Entry point address:               0xb9
  Start of program headers:          52 (bytes into file)
  Start of section headers:          134136 (bytes into file)
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
  [ 1] .text             PROGBITS        00000000 010000 00013c 00  AX  0   0  4
  [ 2] .data             PROGBITS        20000000 020000 000000 00  WA  0   0  1
  [ 3] .bss              NOBITS          20000000 020000 000400 00  WA  0   0  4
  [ 4] .debug_info       PROGBITS        00000000 020000 000258 00      0   0  1
  [ 5] .debug_abbrev     PROGBITS        00000000 020258 00013f 00      0   0  1
  [ 6] .debug_loc        PROGBITS        00000000 020397 0000b4 00      0   0  1
  [ 7] .debug_aranges    PROGBITS        00000000 02044b 000040 00      0   0  1
  [ 8] .debug_line       PROGBITS        00000000 02048b 0000f8 00      0   0  1
  [ 9] .debug_str        PROGBITS        00000000 020583 00019e 01  MS  0   0  1
  [10] .comment          PROGBITS        00000000 020721 00007b 01  MS  0   0  1
  [11] .ARM.attributes   ARM_ATTRIBUTES  00000000 02079c 000033 00      0   0  1
  [12] .debug_frame      PROGBITS        00000000 0207d0 00007c 00      0   0  4
  [13] .symtab           SYMTAB          00000000 02084c 000240 10     14  22  4
  [14] .strtab           STRTAB          00000000 020a8c 0000cd 00      0   0  1
  [15] .shstrtab         STRTAB          00000000 020b59 00009d 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings), I (info),
  L (link order), O (extra OS processing required), G (group), T (TLS),
  C (compressed), x (unknown), o (OS specific), E (exclude),
  y (purecode), p (processor specific)

There are no section groups in this file.

Program Headers:
  Type           Offset   VirtAddr   PhysAddr   FileSiz MemSiz  Flg Align
  LOAD           0x010000 0x00000000 0x00000000 0x0013c 0x0013c R E 0x10000
  LOAD           0x020000 0x20000000 0x0000013c 0x00000 0x00400 RW  0x10000

 Section to Segment mapping:
  Segment Sections...
   00     .text 
   01     .data .bss 

There is no dynamic section in this file.

There are no relocations in this file.

There are no unwind sections in this file.

Symbol table '.symtab' contains 36 entries:
   Num:    Value  Size Type    Bind   Vis      Ndx Name
     0: 00000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 00000000     0 SECTION LOCAL  DEFAULT    1 
     2: 20000000     0 SECTION LOCAL  DEFAULT    2 
     3: 20000000     0 SECTION LOCAL  DEFAULT    3 
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
    14: 000000ac     0 NOTYPE  LOCAL  DEFAULT    1 $t
    15: 20000000     0 NOTYPE  LOCAL  DEFAULT    3 $d
    16: 20000000  1024 NOTYPE  LOCAL  DEFAULT    3 stack_top
    17: 00000000     0 NOTYPE  LOCAL  DEFAULT    1 $d
    18: 00000128     0 NOTYPE  LOCAL  DEFAULT    1 $d
    19: 00000000     0 FILE    LOCAL  DEFAULT  ABS main.c
    20: 0000001c     0 NOTYPE  LOCAL  DEFAULT    1 $t
    21: 00000098     0 NOTYPE  LOCAL  DEFAULT    1 $d
    22: 000000ad    12 FUNC    WEAK   DEFAULT    1 Bus_Fault_handler
    23: 000000b9   132 FUNC    GLOBAL DEFAULT    1 reset_handler
    24: 000000ad    12 FUNC    WEAK   DEFAULT    1 H_Fault_handler
    25: 20000000     0 NOTYPE  GLOBAL DEFAULT    2 _E_data
    26: 20000000     0 NOTYPE  GLOBAL DEFAULT    2 _S_data
    27: 20000400     0 NOTYPE  GLOBAL DEFAULT    3 _E_bss
    28: 000000ad    12 FUNC    GLOBAL DEFAULT    1 Default_Handler
    29: 20000000     0 NOTYPE  GLOBAL DEFAULT    3 _S_bss
    30: 0000001d   144 FUNC    GLOBAL DEFAULT    1 main
    31: 000000ad    12 FUNC    WEAK   DEFAULT    1 MM_Fault_handler
    32: 000000ad    12 FUNC    WEAK   DEFAULT    1 NHI_handler
    33: 00000000    28 OBJECT  GLOBAL DEFAULT    1 g_p_fn_vectors
    34: 0000013c     0 NOTYPE  GLOBAL DEFAULT    1 _E_text
    35: 000000ad    12 FUNC    WEAK   DEFAULT    1 Usage_Fault_handler

No version information found in this file.
Attribute Section: aeabi
File Attributes
  Tag_CPU_name: "Cortex-M4"
  Tag_CPU_arch: v7E-M
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
[![MIT License](https://img.shields.io/badge/dis%20assembly%20-7A5BE2)]()





## debugging in kiel uvision : we compiled with debugging option -gdwarf-2 to get debug information and also created .axf file to run on kiel uvision  
at first .data intialized and copied from flash to sram then the initialization of .bss section and setting it to 0 then the program jumps to main function
setting the registers and then going to while to start yoggling the led throught "GPIO_PORTF_DATA_R" by toggle pin3 between 1 and 0 as we see in the logic analyzer

 ![Alt Text](https://s5.gifyu.com/images/SRoTp.gif)
[![MIT License](https://img.shields.io/badge/view%20simulation%20in%20full%20screen%20-7A5BE2)](https://s5.gifyu.com/images/SRoTp.gif)

 
 ![Alt Text](https://s5.gifyu.com/images/SRoTW.gif)



 


[![MIT License](https://img.shields.io/badge/ALL%20FILES%20-7A5BE2)]()

[![MIT License](https://img.shields.io/badge/go%20to%20top%20-7A5BE2)]()

[![MIT License](https://img.shields.io/badge/go%20back%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main)

&nbsp;
&nbsp;

&nbsp;

## 🔗 Links

[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/omar-samy-69a7241b0/)
