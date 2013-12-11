ASM = nasm

all: makefile boot.bin loader.bin

clean: makefile
	-rm *.bin

.PHONY: all clean

boot.bin: makefile boot.asm
	$(ASM) boot.asm -o boot.bin

loader.bin: makefile loader.asm
	$(ASM) loader.asm -o loader.bin


