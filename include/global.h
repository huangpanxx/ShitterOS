#ifndef GLOBAL_H
#define GLOBAL_H

#ifndef __GLOBAL__
#define EXTERN  extern
#else
#define EXTERN
#endif


#include "type.h"
#include "const.h"

typedef struct struct_gate 
{
	u16 offset_low;
	u16 selector;
  	u8	dcount;
	u8  attr;
	u16 offset_high;
} gate;

EXTERN gate g_idt[IDTSIZE];
EXTERN u8   g_idt_ptr[6];

#undef __GLOBAL__
#endif

