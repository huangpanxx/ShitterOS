ASM := nasm -f elf32
CC := cc -I ../include/ -L ../lib/

COBJS := kernel.o interrupt.o memory.o print.o global.o
AOBJS := kernela.o porta.o interrupta.o

all: makefile kernel.bin 

clean: makefile
	-rm *.bin
	-rm *.o

.PHONY: all clean

$(COBJS): %.o: %.c makefile
	$(CC) -m32 -c $< -o $@

$(AOBJS): %.o: %.asm makefile
	$(ASM) $< -o $@

kernel.bin: makefile $(COBJS) $(AOBJS)
	ld -Ttext 0x30400 -m elf_i386 -s -o kernel.bin $(AOBJS) $(COBJS)

