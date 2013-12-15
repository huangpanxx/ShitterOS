/*
 * =====================================================================================
 *
 *       Filename:  const.h
 *
 *    Description:  some const value
 *
 *        Version:  1.0
 *        Created:  2013年12月11日 21时10分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  snail
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef CONST_H
#define CONST_H



/*  8259A interrupt controller ports. */
#define INT_M_CTL     0x20 /*  I/O port for interrupt controller       <Master> */
#define INT_M_CTLMASK 0x21 /*  setting bits in this port disables ints <Master> */
#define INT_S_CTL     0xA0 /*  I/O port for second interrupt controller<Slave>  */
#define INT_S_CTLMASK 0xA1 /*  setting bits in this port disables ints <Slave>  */


/*  中断向量 */
#define	INT_VECTOR_IRQ0			0x20
#define	INT_VECTOR_IRQ8			0x28


#endif
