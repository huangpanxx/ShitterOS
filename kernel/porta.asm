[SECTION .text]

global out_byte
global in_byte

out_byte:
	push	edx
	mov	edx, [esp + 8]		
	mov	al, [esp + 12]	
	out	dx, al
	nop	
	nop
	pop	edx
	ret

in_byte:
	push	edx
	mov	edx, [esp + 8]		
	xor	eax, eax
	in	al, dx
	nop	
	nop
	pop	edx
	ret

