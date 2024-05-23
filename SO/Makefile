.PHONY: all clean

CC= cc
CFLAGS= -O0 -Wall -Wextra -fno-builtin -fno-pic -fno-pie -fno-stack-check \
-fno-stack-protector -g -m32 -nostdlib -std=c99
LD= ld
LDFLAGS= -m elf_i386 --oformat=binary
RM= rm -f

all: floppy.img

boot0.o: boot0.S
	${CC} ${CFLAGS} -c $? -o $@

boot1.o: boot1.S
	${CC} ${CFLAGS} -c $? -o $@

idt.o: idt.c
	${CC} ${CFLAGS} -c $? -o $@

isr.c.o: isr.c
	${CC} ${CFLAGS} -Wno-unused-parameter -c $? -o $@

isr.s.o: isr.S
	${CC} ${CFLAGS} -c $? -o $@

kbd.o: kbd.c
	${CC} ${CFLAGS} -c $? -o $@

lerHd.o: lerHd.c
	${CC} ${CFLAGS} -c $? -o $@

kernel.o: kernel.c
	${CC} ${CFLAGS} -ffreestanding -c $? -o $@

printf.o: printf.c
	${CC} ${CFLAGS} -c $? -o $@

vga.o: vga.c
	${CC} ${CFLAGS} -c $? -o $@

x86.o: x86.c
	${CC} ${CFLAGS} -c $? -o $@

boot0: boot0.o
	${LD} ${LDFLAGS} --Ttext 0x7c00 -e _start $? -o $@

boot1: boot1.o
	${LD} ${LDFLAGS} --Ttext 0x7e00 -e _start $? -o $@

kernel: kernel.o vga.o x86.o idt.o isr.c.o isr.s.o kbd.o printf.o lerHd.o
	${LD} ${LDFLAGS} --Ttext 0x10000 -e main $? -o $@

floppy.img: boot0 boot1 kernel
	dd if=/dev/zero of=$@ bs=512 count=2880
	dd if=boot0 of=$@ bs=512 count=1 conv=notrunc seek=0
	dd if=boot1 of=$@ bs=512 count=1 conv=notrunc seek=1
	dd if=kernel of=$@ bs=512 count=40 conv=notrunc seek=2

clean:
	${RM} *.o bochsout.txt boot[01] floppy.img kernel

criar_hd:
	bximage -func=create -hd=20M -imgmode=flat -sectsize=512 -q hd.img
	dd if=teste.txt of=hd.img bs=512 count=1 conv=notrunc