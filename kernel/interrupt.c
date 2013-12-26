#include "port.h"
#include "const.h"
#include "global.h"
#include "print.h"


typedef void (*int_handler) ();

void divide_error();
void single_step_exception();
void nmi();
void breakpoint_exception();
void overflow();
void bounds_check();
void inval_opcode();
void copr_not_available();
void double_fault();
void copr_seg_overrun();
void inval_tss();
void segment_not_present();
void stack_exception();
void general_protection();
void page_fault();
void copr_error();

void hwint00();

void set_sti();
void load_idt(void* idt_ptr);

/*
 *以下代码初始化8259A中断控制器
 *流程为：
 *1.向端口20h(主片)或A0h(从片)写入ICW1
 *2.向端口21h(主片)或A1h(从片)写入ICW2
 *3.向端口21h(主片)或A1h(从片)写入ICW3
 *4.向端口21h(主片)或A1h(从片)写入ICW4
 */
void init_8259A()
{
	//1.向端口20h(主片)或A0h(从片)写入ICW1
	out_byte(INT_M_CTL,	0x11);
	out_byte(INT_S_CTL,	0x11);

	//2.向端口21h(主片)或A1h(从片)写入ICW2
	//设置 '主8259' 的中断入口地址为 0x20
	out_byte(INT_M_CTLMASK,	INT_VECTOR_IRQ0);
	//设置 '从8259' 的中断入口地址为 0x28 
	out_byte(INT_S_CTLMASK,	INT_VECTOR_IRQ8);

	//3.向端口21h(主片)或A1h(从片)写入ICW3
	out_byte(INT_M_CTLMASK,	0x4);
	out_byte(INT_S_CTLMASK,	0x2);

	//4.向端口21h(主片)或A1h(从片)写入ICW4
	out_byte(INT_M_CTLMASK,	0x1);
	out_byte(INT_S_CTLMASK,	0x1);

}

void enable_interrupt() 
{
	//开键盘终端
	out_byte(INT_M_CTLMASK,	0xFD);
	out_byte(INT_S_CTLMASK,	0xFF);

	//设置flag位
	set_sti();
}



/*
 *初始化IDT 
 */
void init_idt_desc(u8 vector,u8 desc_type,
		int_handler handler, u8 priviledge)
{
	gate *p_gate = &(g_idt[vector]);
	u32 base 	 = (u32)handler;
	p_gate->offset_low 	= base & 0xFFFF;
	put_int(33,3,4,SELECTOR_KERNEL_R);
	p_gate->selector	= SELECTOR_KERNEL_R;
	p_gate->dcount		= 0;
	p_gate->attr		= desc_type | (priviledge << 5);
	p_gate->offset_high	= (base >> 16) & 0xFFFF;
}


/* 
 * 中断处理函数 (call from interrupta.asm)
 */
void exception_handler(int vec_no,int err_code,int eip,int cs,int eflags)
{
	put_str(0,0,12,"exception_handler called");
}

void spurious_irq(int code)
{
	put_str(0,0,12,"spurious_irq called");
}

void init_idt() 
{
	int i;
	const static int_handler handlers[16] = {
		divide_error,
		single_step_exception,
		nmi,
		breakpoint_exception,
		overflow,
		bounds_check,
		inval_opcode,
		copr_not_available,
		double_fault,
		copr_seg_overrun,
		inval_tss,
		segment_not_present,
		stack_exception,
		general_protection,
		page_fault,
		copr_error
	};

	for(i = 0; i <= 14; ++i) {
		init_idt_desc(i, DA_386IGate,
			handlers[i], PRIVILEGE_KRNL);
	}

	init_idt_desc(16, DA_386IGate,
		handlers[15], PRIVILEGE_KRNL);

	for(i = 0x20; i < IDTSIZE; ++i) {
		init_idt_desc(i, DA_386IGate,
		hwint00, PRIVILEGE_KRNL);
	}

	u16* p_idt_limit = (u16*)(&g_idt_ptr[0]);
	u32* p_idt_base  = (u32*)(&g_idt_ptr[2]);
	
	*p_idt_limit = IDTSIZE * sizeof(gate) - 1;
	*p_idt_base  = (u32)&g_idt;

	load_idt(g_idt_ptr);
}


/* 构建idt */
void setup_idt()
{
	init_8259A();
	init_idt();
	enable_interrupt();
}

