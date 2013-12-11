ASM := nasm -f elf32

all: makefile kernel.bin 

clean: makefile
	-rm *.bin
	-rm *.o

.PHONY: all clean

main.o: makefile main.c
	cc -m32 -c main.c -o main.o
kernel.o: makefile kernel.asm	
	$(ASM) kernel.asm -o kernel.o

kernel.bin: makefile main.o kernel.o
	ld -Ttext 0x30400 -m elf_i386 -s -o kernel.bin kernel.o  main.o

