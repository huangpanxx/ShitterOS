size := 1474560 #80*18*512*2 
dirs := boot kernel
qemu := qemu-system-i386
files := ./boot/loader.bin  ./kernel/kernel.bin

all: makefile os.img

clean: makefile
	$(foreach N,$(dirs), make clean -C $(N);)
	-rm -R os
	-rm os.img

run: makefile os.img
	$(qemu) -fda os.img

subs: makefile
	$(foreach N,$(dirs),make -C $(N);)

.PHONY: all clean run subs

os: makefile
	-mkdir os

os.img: makefile os subs
	dd if=/dev/zero of=./os.img  bs=$(size) count=1
	dd if=./boot/boot.bin of=./os.img  conv=notrunc
	sudo mount ./os.img ./os
	sudo cp $(files) ./os
	sudo umount -vl ./os


