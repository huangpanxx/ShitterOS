; 编译链接方法
; (ld 的‘-s’选项意为“strip all”)
;
; [root@XXX XXX]# nasm -f elf kernel.asm -o kernel.o
; [root@XXX XXX]# ld -s kernel.o -o kernel.bin
; [root@XXX XXX]# 

[section .data]
GS		dw	0

extern main

[section .text]	; 代码在此

global _start	; 导出 _start
global put_chr;

_start:	; 跳到这里来的时候，我们假设 gs 指向显存
	mov edi,GS
	mov eax,gs
	mov [edi],eax
	call main
	hlt
	jmp $

put_chr:
	push 	ebp
	mov	ebp,esp
	push	eax
	push	edi
	push	ecx
	mov	edi,[ebp+12] ;行
	mov	eax,80
	mul	edi
	mov	edi,eax
	add	edi,[ebp+8] ;列
	mov	eax,2
	mul	edi
	mov	edi,eax

	push	gs
	mov	ecx,GS
	mov 	gs,[ecx]
	mov	eax,[ebp+16] ;值
	and 	eax,0x0000ffff
	mov	[gs:edi],ax
	pop	gs

	pop	ecx
	pop	edi
	pop	eax
	mov	esp,ebp
	pop	ebp
	ret
	
