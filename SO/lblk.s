#define CYLINDER 0
#define DRIVE 0
#define HEAD 0

/*
 * Load blocks from the disk to the buffer ES:BX.
 * Usage:
 *   CL: Starting block.
 *   AL: Number of blocks to read.
 */
lblk:
	.code16
	pusha
	movb $2, %ah /* BIOS call to read blocks from the disk. */
	movb $CYLINDER, %ch
	movb $DRIVE,    %dl
	movb $HEAD,     %dh
	int $0x13
	popa
	ret
