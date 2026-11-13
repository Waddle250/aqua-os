all: aquaiso.bin

boot.bin: boot.asm
	nasm -f bin boot.asm -o boot.bin

kernel.bin: kernel.c kernel_entry.asm
	nasm -f elf32 kernel_entry.asm -o kernel_entry.o
	gcc -ffreestanding -m32 -fno-pic -c kernel.c -o kernel.o
	ld -m elf_i386 -T linker.ld --oformat binary -o kernel.bin kernel_entry.o kernel.o



aquaiso.bin: boot.bin kernel.bin
	cat boot.bin kernel.bin > aquaiso.bin

run:
	qemu-system-x86_64 -drive format=raw,file=aquaiso.bin -d cpu_reset,int -no-reboot
