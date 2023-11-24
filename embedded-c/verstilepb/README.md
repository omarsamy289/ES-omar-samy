 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <a href=""><img src="https://iili.io/JocOc8b.md.png" alt="771" border="0"></a><br /><a target='_blank' href='https://iili.io/JocOc8b.md.png'>


[![MIT License](https://img.shields.io/badge/ALL%20FILES%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/embedded-c/verstilepb/all%20files)


# this is a full detailed report on ARM versatilePB LAB 1
## create baremetal SW to send a string using UART0


## 1- first step : creating app.c and uart.c and uart.h 

> **Note**
 mod int standard library is also included in this project to make use of 
>

### uart.c 
#### this c file contais the uart send function and the initialization of uart0 data register which we will send the string into

```c code

//omar samy
#include "mod_int_standard.h"
#include "uart.h"
// uart tx register                    base address offset
#define UART0DR  *(vunint32 *)((unint32 *)0x101f1000+ 0x0)

void uart_send_string (unint8* pstring ) {

	while (*pstring != '\0') {


		UART0DR = (unint32) *pstring ;
		pstring ++ ;

	}

}

```


### uart.h 
#### this header file contais the prototype of uart send function 

```c code
#ifndef _UART_H_
#define _UART_H_

void uart_send_string (unint8*) ;


#endif

```

### app.c
#### this c file contais the main function and the string we will send

```c code
#include "mod_int_standard.h"
#include "uart.h"


unint8 string[100] = " learn-in-depth : omar samy" ;

void main (void) {


	uart_send_string (string);


}

```

### mod_int-standard.h
#### this header files contais the modified int standard library for refrence 

```c code
// header guards
#ifndef _MOD_INT_STANDARD_H_
#define _MOD_INT_STANDARD_H_

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

## 2- second step : compiling app.c and uart.c into app.o and uart.o resectively  without linking 

<a href="https://freeimage.host/i/JocY6mb"><img src="https://iili.io/JocY6mb.md.png" alt="JocY6mb.md.png" border="0"></a>

> **Note**
the arm processor mcpu command is : arm926ej-s
>
<a href="https://freeimage.host/i/JocaN8F"><img src="https://iili.io/JocaN8F.md.png" alt="JocaN8F.md.png" border="0"></a>

## 3- third step : creating startup code to make the stack pointer point to specific address and also branch to main function afterward 

``` assembly 
#assmply based on arm archticture

.global reset
reset :
    ldr sp, = stack_top	
	bl main
	
stop: b stop

```
### creating opj file from startup assembly 

<a href="https://freeimage.host/i/Jocl4kX"><img src="https://iili.io/Jocl4kX.md.png" alt="Jocl4kX.md.png" border="0"></a>

### if we objdumb startup.o we will found that both vma and lma are both set to address 0x00000000

<a href="https://freeimage.host/i/Joc0Y3N"><img src="https://iili.io/Joc0Y3N.md.png" alt="Joc0Y3N.md.png" border="0"></a>

### same if we objdumb app.o we will found that both vma and lma are both set to address 0x00000000 also and with debugging inforamtion is disabled
<a href="https://freeimage.host/i/Joc0QAF"><img src="https://iili.io/Joc0QAF.md.png" alt="Joc0QAF.md.png" border="0"></a>




## 4- forth step : creating linker script to link app.o , uart.o and startup.o into learn-in-depth.elf

``` assembly
ENTRY(reset)

MEMORY 
{

    mem (rwx) : ORIGIN = 0x00000000 , LENGTH = 65M



}


SECTIONS
{
         . = 0x10000;
       .startup . :
       {
          startup.o(.text)

       }> mem
      .text :
       {
          *(.text)
       }> mem
      .data :
       {
          *(.data) 
       }> mem
      .bss :
       {
          *(.bss) *(COMMON)

       }> mem
       . = . + 0x1000;
       stack_top = . ;



}
```

### memory is set address 0x00000000 with size 65 megabyte to further use for VMA and LMA information 

### creating learn-in-depth.elf from app.o , uart.o and startup.o
<a href="https://freeimage.host/i/JocG8tn"><img src="https://iili.io/JocG8tn.md.png" alt="JocG8tn.md.png" border="0"></a>


### opjdump  assmbly from learn-in-depth.elf  
### we will found that reset starts at address 0x10000 as we spcified in the linker script then branch to main function



``` assembly 

learn-in-depth.elf:     file format elf32-littlearm


Disassembly of section .startup:

00010000 <reset>:
   10000:	e3a0da11 	mov	sp, #69632	; 0x11000
   10004:	eb000000 	bl	1000c <main>

00010008 <stop>:
   10008:	eafffffe 	b	10008 <stop>

Disassembly of section .text:

0001000c <main>:
   1000c:	e92d4800 	push	{fp, lr}
   10010:	e28db004 	add	fp, sp, #4
   10014:	e59f0004 	ldr	r0, [pc, #4]	; 10020 <main+0x14>
   10018:	eb000001 	bl	10024 <uart_send_string>
   1001c:	e8bd8800 	pop	{fp, pc}
   10020:	00010074 	andeq	r0, r1, r4, ror r0

00010024 <uart_send_string>:
   10024:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
   10028:	e28db000 	add	fp, sp, #0
   1002c:	e24dd00c 	sub	sp, sp, #12
   10030:	e50b0008 	str	r0, [fp, #-8]
   10034:	ea000006 	b	10054 <uart_send_string+0x30>
   10038:	e59f3030 	ldr	r3, [pc, #48]	; 10070 <uart_send_string+0x4c>
   1003c:	e51b2008 	ldr	r2, [fp, #-8]
   10040:	e5d22000 	ldrb	r2, [r2]
   10044:	e5832000 	str	r2, [r3]
   10048:	e51b3008 	ldr	r3, [fp, #-8]
   1004c:	e2833001 	add	r3, r3, #1
   10050:	e50b3008 	str	r3, [fp, #-8]
   10054:	e51b3008 	ldr	r3, [fp, #-8]
   10058:	e5d33000 	ldrb	r3, [r3]
   1005c:	e3530000 	cmp	r3, #0
   10060:	1afffff4 	bne	10038 <uart_send_string+0x14>
   10064:	e28bd000 	add	sp, fp, #0
   10068:	e8bd0800 	ldmfd	sp!, {fp}
   1006c:	e12fff1e 	bx	lr
   10070:	101f1000 	andsne	r1, pc, r0

Disassembly of section .data:

00010074 <string>:
   10074:	61656c20 	cmnvs	r5, r0, lsr #24
   10078:	692d6e72 	pushvs	{r1, r4, r5, r6, r9, sl, fp, sp, lr}
   1007c:	65642d6e 	strbvs	r2, [r4, #-3438]!	; 0xd6e
   10080:	20687470 	rsbcs	r7, r8, r0, ror r4
   10084:	6d6f203a 	stclvs	0, cr2, [pc, #-232]!	; ffa4 <reset-0x5c>
   10088:	73207261 	teqvc	r0, #268435462	; 0x10000006
   1008c:	00796d61 	rsbseq	r6, r9, r1, ror #26
	...

Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00002d41 	andeq	r2, r0, r1, asr #26
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000023 	andeq	r0, r0, r3, lsr #32
  10:	4d524105 	ldfmie	f4, [r2, #-20]	; 0xffffffec
  14:	45363239 	ldrmi	r3, [r6, #-569]!	; 0x239
  18:	00532d4a 	subseq	r2, r3, sl, asr #26
  1c:	01080506 	tsteq	r8, r6, lsl #10
  20:	04120109 	ldreq	r0, [r2], #-265	; 0x109
  24:	01150114 	tsteq	r5, r4, lsl r1
  28:	01180317 	tsteq	r8, r7, lsl r3
  2c:	Address 0x0000002c is out of bounds.


Disassembly of section .comment:

00000000 <.comment>:
   0:	3a434347 	bcc	10d0d24 <stack_top+0x10bfc4c>
   4:	4e472820 	cdpmi	8, 4, cr2, cr7, cr0, {1}
   8:	34202955 	strtcc	r2, [r0], #-2389	; 0x955
   c:	322e372e 	eorcc	r3, lr, #12058624	; 0xb80000
	...


```





### also in this read elf output file from  learn-in-depth.elf file for futher investigation

<a href="https://freeimage.host/i/JocW2ZF"><img src="https://iili.io/JocW2ZF.md.png" alt="JocW2ZF.md.png" border="0"></a>

``` assembly 
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
  Entry point address:               0x10000
  Start of program headers:          52 (bytes into file)
  Start of section headers:          33120 (bytes into file)
  Flags:                             0x5000002, has entry point, Version5 EABI
  Size of this header:               52 (bytes)
  Size of program headers:           32 (bytes)
  Number of program headers:         1
  Size of section headers:           40 (bytes)
  Number of section headers:         9
  Section header string table index: 6

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .startup          PROGBITS        00010000 008000 00000c 00  AX  0   0  4
  [ 2] .text             PROGBITS        0001000c 00800c 000068 00  AX  0   0  4
  [ 3] .data             PROGBITS        00010074 008074 000064 00  WA  0   0  4
  [ 4] .ARM.attributes   ARM_ATTRIBUTES  00000000 0080d8 00002e 00      0   0  1
  [ 5] .comment          PROGBITS        00000000 008106 000011 01  MS  0   0  1
  [ 6] .shstrtab         STRTAB          00000000 008117 000049 00      0   0  1
  [ 7] .symtab           SYMTAB          00000000 0082c8 000160 10      8  17  4
  [ 8] .strtab           STRTAB          00000000 008428 000050 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings)
  I (info), L (link order), G (group), T (TLS), E (exclude), x (unknown)
  O (extra OS processing required) o (OS specific), p (processor specific)

There are no section groups in this file.

Program Headers:
  Type           Offset   VirtAddr   PhysAddr   FileSiz MemSiz  Flg Align
  LOAD           0x008000 0x00010000 0x00010000 0x000d8 0x000d8 RWE 0x8000

 Section to Segment mapping:
  Segment Sections...
   00     .startup .text .data 

There is no dynamic section in this file.

There are no relocations in this file.

There are no unwind sections in this file.

Symbol table '.symtab' contains 22 entries:
   Num:    Value  Size Type    Bind   Vis      Ndx Name
     0: 00000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 00010000     0 SECTION LOCAL  DEFAULT    1 
     2: 0001000c     0 SECTION LOCAL  DEFAULT    2 
     3: 00010074     0 SECTION LOCAL  DEFAULT    3 
     4: 00000000     0 SECTION LOCAL  DEFAULT    4 
     5: 00000000     0 SECTION LOCAL  DEFAULT    5 
     6: 00000000     0 FILE    LOCAL  DEFAULT  ABS startup.o
     7: 00010000     0 NOTYPE  LOCAL  DEFAULT    1 $a
     8: 00010008     0 NOTYPE  LOCAL  DEFAULT    1 stop
     9: 00000000     0 FILE    LOCAL  DEFAULT  ABS app.c
    10: 00010074     0 NOTYPE  LOCAL  DEFAULT    3 $d
    11: 0001000c     0 NOTYPE  LOCAL  DEFAULT    2 $a
    12: 00010020     0 NOTYPE  LOCAL  DEFAULT    2 $d
    13: 00000000     0 FILE    LOCAL  DEFAULT  ABS uart.c
    14: 00010024     0 NOTYPE  LOCAL  DEFAULT    2 $a
    15: 00010070     0 NOTYPE  LOCAL  DEFAULT    2 $d
    16: 00000000     0 FILE    LOCAL  DEFAULT  ABS 
    17: 00010000     0 NOTYPE  GLOBAL DEFAULT    1 reset
    18: 00010074   100 OBJECT  GLOBAL DEFAULT    3 string
    19: 00010024    80 FUNC    GLOBAL DEFAULT    2 uart_send_string
    20: 000110d8     0 NOTYPE  GLOBAL DEFAULT    3 stack_top
    21: 0001000c    24 FUNC    GLOBAL DEFAULT    2 main

No version information found in this file.
Attribute Section: aeabi
File Attributes
  Tag_CPU_name: "ARM926EJ-S"
  Tag_CPU_arch: v5TEJ
  Tag_ARM_ISA_use: Yes
  Tag_THUMB_ISA_use: Thumb-1
  Tag_ABI_PCS_wchar_t: 4
  Tag_ABI_FP_denormal: Needed
  Tag_ABI_FP_exceptions: Needed
  Tag_ABI_FP_number_model: IEEE 754
  Tag_ABI_align_needed: 8-byte
  Tag_ABI_enum_size: small


```

### symbols of learn-in-depth.elf

<a href="https://freeimage.host/i/JocXe0G"><img src="https://iili.io/JocXe0G.md.png" alt="JocXe0G.md.png" border="0"></a>

### section of learn in depth .elf  shows startup vma and lma starts at address 0x00010000  

<a href="https://freeimage.host/i/JocXsqu"><img src="https://iili.io/JocXsqu.md.png" alt="JocXsqu.md.png" border="0"></a>

### map file from learn-in-depth.elf
<a href="https://freeimage.host/i/JocjacJ"><img src="https://iili.io/JocjacJ.md.png" alt="JocjacJ.md.png" border="0"></a>

``` assembly 

Memory Configuration

Name             Origin             Length             Attributes
mem              0x00000000         0x04100000         xrw
*default*        0x00000000         0xffffffff

Linker script and memory map

                0x00010000                . = 0x10000

.startup        0x00010000        0xc
 startup.o(.text)
 .text          0x00010000        0xc startup.o
                0x00010000                reset

.text           0x0001000c       0x68
 *(.text)
 .text          0x0001000c       0x18 app.o
                0x0001000c                main
 .text          0x00010024       0x50 uart.o
                0x00010024                uart_send_string

.glue_7         0x00010074        0x0
 .glue_7        0x00000000        0x0 linker stubs

.glue_7t        0x00010074        0x0
 .glue_7t       0x00000000        0x0 linker stubs

.vfp11_veneer   0x00010074        0x0
 .vfp11_veneer  0x00000000        0x0 linker stubs

.v4_bx          0x00010074        0x0
 .v4_bx         0x00000000        0x0 linker stubs

.iplt           0x00010074        0x0
 .iplt          0x00000000        0x0 startup.o

.rel.dyn        0x00010074        0x0
 .rel.iplt      0x00000000        0x0 startup.o

.data           0x00010074       0x64
 *(.data)
 .data          0x00010074        0x0 startup.o
 .data          0x00010074       0x64 app.o
                0x00010074                string
 .data          0x000100d8        0x0 uart.o

.igot.plt       0x000100d8        0x0
 .igot.plt      0x00000000        0x0 startup.o

.bss            0x000100d8        0x0
 *(.bss)
 .bss           0x000100d8        0x0 startup.o
 .bss           0x000100d8        0x0 app.o
 .bss           0x000100d8        0x0 uart.o
 *(COMMON)
                0x000110d8                . = (. + 0x1000)
                0x000110d8                stack_top = .
LOAD app.o
LOAD uart.o
LOAD startup.o
OUTPUT(learn-in-depth.elf elf32-littlearm)

.ARM.attributes
                0x00000000       0x2e
 .ARM.attributes
                0x00000000       0x22 startup.o
 .ARM.attributes
                0x00000022       0x32 app.o
 .ARM.attributes
                0x00000054       0x32 uart.o

.comment        0x00000000       0x11
 .comment       0x00000000       0x11 app.o
                                 0x12 (size before relaxing)
 .comment       0x00000000       0x12 uart.o


```


## 5- fivth step (final) : creating bin file   "learn-in-depth.bin" from learn-in-depth.elf to run on QEMU simulator
<a href="https://freeimage.host/i/JochYp2"><img src="https://iili.io/JochYp2.md.png" alt="JochYp2.md.png" border="0"></a>

## run learn-in-depth.bin on QEMU simulator 

<a href="https://freeimage.host/i/JochhkQ"><img src="https://iili.io/JochhkQ.md.png" alt="JochhkQ.md.png" border="0"></a>


[![MIT License](https://img.shields.io/badge/ALL%20FILES%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/embedded-c/verstilepb/all%20files)

[![MIT License](https://img.shields.io/badge/go%20to%20top%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main/embedded-c/verstilepb)

[![MIT License](https://img.shields.io/badge/go%20back%20-7A5BE2)](https://github.com/omarsamy289/ES-omar-samy/tree/main)

&nbsp;
&nbsp;

&nbsp;

## 🔗 Links

[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/omar-samy-69a7241b0/)
