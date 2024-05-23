#ifndef X86_H
#define X86_H

#include "types.h"

/* Disable interrupts. */
#define cli() \
	__asm__ __volatile__("cli")

/* Halt the machine. */
#define hlt() \
	__asm__ __volatile__("hlt")

/* Enable interrupts. */
#define sti() \
	__asm__ __volatile__("sti")

int inb(int);        /* Read data from a port. */
void lidt(void*);    /* Load the IDT descriptor. */
void outb(int, int); /* Send data to a port. */

#endif
