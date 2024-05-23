#define BOOT2_BLK 2
#define BOOT2_NBLK 1
#define BOOT2_OFFSET 0x7e00
#define BSP 0x9000
#define SIGN 0xaa55

/* Write the boot signature and load and jump to the second bootloader. */
.globl _start
_start:
	.code16

	/* Zero the segment registers. */
	xorw %ax, %ax
	movw %ax, %ds
	movw %ax, %es
	movw %ax, %fs
	movw %ax, %gs
	movw %ax, %ss

	/* Initialize the base and stack. */
	movw $BSP, %bp
	movw %bp, %sp

	/* Load the second boot. */
	movb $BOOT2_BLK, %cl
	movb $BOOT2_NBLK, %al
	movw $BOOT2_OFFSET, %bx
	call lblk

	jmp BOOT2_OFFSET

#include "lblk.s"

/* Write the boot signature. */
sign:
	.code16
	. = _start + 510
	.2byte SIGN
