#ifndef CONST_H
#define CONST_H


/*  8259A interrupt controller ports. */
#define INT_M_CTL     0x20 // I/O port for interrupt controller<Master> 
#define INT_M_CTLMASK 0x21 //  setting bits in this port disables ints <Master> 
#define INT_S_CTL     0xA0 //  I/O port for second interrupt controller<Slave>
#define INT_S_CTLMASK 0xA1 //  setting bits in this port disables ints <Slave>


/*  中断向量 */
#define	INT_VECTOR_IRQ0			0x20
#define	INT_VECTOR_IRQ8			0x28

/* GDT选择子 */
#define SELECTOR_KERNEL_R  	0
#define SELECTOR_KERNEL_RW 	4
#define SELECTOR_VIDEO 		8

/*  权限 */
#define	PRIVILEGE_KRNL	0
#define	PRIVILEGE_TASK	1
#define	PRIVILEGE_USER	3


#define DA_386CGate     0x8C    /* 调用门*/
#define DA_386IGate     0x8E    /* 中断门*/
#define DA_386TGate     0x8F    /* 陷阱门*/


#define IDTSIZE 255

#endif
