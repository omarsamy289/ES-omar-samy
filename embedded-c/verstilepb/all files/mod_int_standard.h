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
