/*
 * ISRs that don't need to push an error code (0) onto the stack do it anyways
 * so a single procedure can handle the context switching, since the stack
 * frame will be equal for all ISRs.
 */

#define ERRNO 0

#include "gdt.h"

/* division by zero */
.globl isr0
isr0:
	cli
	pushl $ERRNO
	pushl $0
	jmp switch_to

/* debug */
.globl isr1
isr1:
	cli
	pushl $ERRNO
	pushl $1
	jmp switch_to

/* non maskable interrupt */
.globl isr2
isr2:
	cli
	pushl $ERRNO
	pushl $2
	jmp switch_to

/* int 3 */
.globl isr3
isr3:
	cli
	pushl $ERRNO
	pushl $3
	jmp switch_to

/* overflow */
.globl isr4
isr4:
	cli
	pushl $ERRNO
	pushl $4
	jmp switch_to

/* out of bounds */
.globl isr5
isr5:
	cli
	pushl $ERRNO
	pushl $5
	jmp switch_to

/* invalid opcode */
.globl isr6
isr6:
	cli
	pushl $ERRNO
	pushl $6
	jmp switch_to

/* coprocessor unavailable */
.globl isr7
isr7:
	cli
	pushl $ERRNO
	pushl $7
	jmp switch_to

/* double fault */
.globl isr8
isr8:
	cli
	pushl $8
	jmp switch_to

/* coprocessor segment overrun */
.globl isr9
isr9:
	cli
	pushl $ERRNO
	pushl $9
	jmp switch_to

/* tss */
.globl isr10
isr10:
	cli
	pushl $10
	jmp switch_to

/* segment not present */
.globl isr11
isr11:
	cli
	pushl $11
	jmp switch_to

/* stack fault */
.globl isr12
isr12:
	cli
	pushl $12
	jmp switch_to

/* general protection fault */
.globl isr13
isr13:
	cli
	pushl $13
	jmp switch_to

/* page fault */
.globl isr14
isr14:
	cli
	pushl $14
	jmp switch_to

/* unknown interrupt */
.globl isr15
isr15:
	cli
	pushl $ERRNO
	pushl $15
	jmp switch_to

/* coprocessor fault */
.globl isr16
isr16:
	cli
	pushl $ERRNO
	pushl $16
	jmp switch_to

/* alignment */
.globl isr17
isr17:
	cli
	pushl $17
	jmp switch_to

/* machine */
.globl isr18
isr18:
	cli
	pushl $ERRNO
	pushl $18
	jmp switch_to

/* reserved */
.globl isr19
isr19:
	cli
	pushl $ERRNO
	pushl $19
	jmp switch_to

/* reserved */
.globl isr20
isr20:
	cli
	pushl $ERRNO
	pushl $20
	jmp switch_to

/* reserved */
.globl isr21
isr21:
	cli
	pushl $ERRNO
	pushl $21
	jmp switch_to

/* reserved */
.globl isr22
isr22:
	cli
	pushl $ERRNO
	pushl $22
	jmp switch_to

/* reserved */
.globl isr23
isr23:
	cli
	pushl $ERRNO
	pushl $23
	jmp switch_to

/* reserved */
.globl isr24
isr24:
	cli
	pushl $ERRNO
	pushl $24
	jmp switch_to

/* reserved */
.globl isr25
isr25:
	cli
	pushl $ERRNO
	pushl $25
	jmp switch_to

/* reserved */
.globl isr26
isr26:
	cli
	pushl $ERRNO
	pushl $26
	jmp switch_to

/* reserved */
.globl isr27
isr27:
	cli
	pushl $ERRNO
	pushl $27
	jmp switch_to

/* reserved */
.globl isr28
isr28:
	cli
	pushl $ERRNO
	pushl $28
	jmp switch_to

/* reserved */
.globl isr29
isr29:
	cli
	pushl $ERRNO
	pushl $29
	jmp switch_to

/* reserved */
.globl isr30
isr30:
	cli
	pushl $30
	jmp switch_to

/* reserved */
.globl isr31
isr31:
	cli
	pushl $ERRNO
	pushl $31
	jmp switch_to

/* PIC1 IRQ 0 */
.globl isr32
isr32:
	cli
	pushl $ERRNO
	pushl $32
	jmp switch_to

/* PIC1 IRQ 1 */
.globl isr33
isr33:
	cli
	pushl $ERRNO
	pushl $33
	jmp switch_to

/* PIC1 IRQ 2 */
.globl isr34
isr34:
	cli
	pushl $ERRNO
	pushl $34
	jmp switch_to

/* PIC1 IRQ 3 */
.globl isr35
isr35:
	cli
	pushl $ERRNO
	pushl $35
	jmp switch_to

/* PIC1 IRQ 4 */
.globl isr36
isr36:
	cli
	pushl $ERRNO
	pushl $36
	jmp switch_to

/* PIC1 IRQ 5 */
.globl isr37
isr37:
	cli
	pushl $ERRNO
	pushl $37
	jmp switch_to

/* PIC1 IRQ 6 */
.globl isr38
isr38:
	cli
	pushl $ERRNO
	pushl $38
	jmp switch_to

/* PIC1 IRQ 7 */
.globl isr39
isr39:
	cli
	pushl $ERRNO
	pushl $39
	jmp switch_to

/* PIC2 IRQ 0 */
.globl isr40
isr40:
	cli
	pushl $ERRNO
	pushl $40
	jmp switch_to

/* PIC2 IRQ 1 */
.globl isr41
isr41:
	cli
	pushl $ERRNO
	pushl $41
	jmp switch_to

/* PIC2 IRQ 2 */
.globl isr42
isr42:
	cli
	pushl $ERRNO
	pushl $42
	jmp switch_to

/* PIC2 IRQ 3 */
.globl isr43
isr43:
	cli
	pushl $ERRNO
	pushl $43
	jmp switch_to

/* PIC2 IRQ 4 */
.globl isr44
isr44:
	cli
	pushl $ERRNO
	pushl $44
	jmp switch_to

/* PIC2 IRQ 5 */
.globl isr45
isr45:
	cli
	pushl $ERRNO
	pushl $45
	jmp switch_to

/* PIC2 IRQ 6 */
.globl isr46
isr46:
	cli
	pushl $ERRNO
	pushl $46
	jmp switch_to

/* PIC2 IRQ 7 */
.globl isr47
isr47:
	cli
	pushl $ERRNO
	pushl $47
	jmp switch_to

/* context saver and ISR handler caller */
switch_to:
	/* Save the current context. */
	pusha
	movw %ds, %ax
	pushl %eax
	movw $KDS, %ax
	movw %ax, %ds
	movw %ax, %es
	movw %ax, %fs
	movw %ax, %gs

	call isrman /* ISR handler */

	/* Restore the previous context. */
	popl %eax
	movw %ax, %ds
	movw %ax, %es
	movw %ax, %fs
	movw %ax, %gs
	popa
	addl $8, %esp /* Pop error and isr code from the stack. */

	sti
	iret
