#define BSP 0x90000
#define KERN_BLK 3
#define KERN_NBLK 40
#define KERN_OFFSET 0x10000
#define SCP 0x92

#include "gdt.h"

/* Load the kernel, enable protected mode, then jump to the kernel. */
.globl _start
_start:
	.code16

	/* Enable bit 20 for high memory addressing. */
	cli
	inb $SCP, %al
	orb $2, %al
	outb %al, $SCP

	/* Load the kernel. */
	movb $KERN_BLK, %cl
	movb $KERN_NBLK, %al
	movw $(KERN_OFFSET / 0x10), %bx
	movw %bx, %es
	xorw %bx, %bx
	sti
	call lblk

	/* Load the GDT. */
	cli
	lgdt gdtr

	/* Set the Protection-enable flag. */
	movl %cr0, %eax
	orl $1, %eax
	movl %eax, %cr0

	/* Load the segment registers with the GDT data segment selector. */
	movw $KDS, %ax
	movw %ax, %ds
	movw %ax, %es
	movw %ax, %fs
	movw %ax, %gs
	movw %ax, %ss

	/* Setup the stack. */
	movl $BSP, %ebp
	movl %ebp, %esp

	ljmpl $KCS, $KERN_OFFSET

#include "gdt.s"
#include "lblk.s"
