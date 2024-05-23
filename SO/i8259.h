#ifndef I8259_H
#define I8259_H

/* ports */
#define PIC1_CTLR 0x20
#define PIC1_DATA 0x21
#define PIC2_CTLR 0xa0
#define PIC2_DATA 0xa1

/* initialization commands */
#define ICW1 0b10101     /* edge trigger + interval 4 + cascade + with icw4 */
#define ICW2_PIC1 0x20   /* mapping ISRs 32-39 to the master IRQs */
#define ICW2_PIC2 0x28   /* mapping ISRs 40-47 to the slave IRQs */
#define ICW3_PIC1 0b100  /* master IRQ used for cascading */
#define ICW3_PIC2 0b10   /* slave IRQ used for cascading */
#define ICW4_PIC1 0b1101 /* buffered mode + master + normal eoi + 86 mode */
#define ICW4_PIC2 0b1001 /* buffered mode + slave + normal eoi + 86 mode */

#include "x86.h"

/* operation commands */
#define EOI 0x20

/* Send EOI to a PIC. */
#define eoi(port) \
	outb(EOI, (port));

/* Initialize the PICs. */
#define init_i8259() \
	/* ICW1 */ \
	outb(ICW1, PIC1_CTLR); \
	outb(ICW1, PIC2_CTLR); \
	/* ICW2 */ \
	outb(ICW2_PIC1, PIC1_DATA); \
	outb(ICW2_PIC2, PIC2_DATA); \
	/* ICW3 */ \
	outb(ICW3_PIC1, PIC1_DATA); \
	outb(ICW3_PIC2, PIC2_DATA); \
	/* ICW4 */ \
	outb(ICW4_PIC1, PIC1_DATA); \
	outb(ICW4_PIC2, PIC2_DATA); \
	/* OCW1, the default is all IRQs disabled. */ \
	outb(0b11111111, PIC1_DATA); \
	outb(0b11111111, PIC2_DATA);

#endif
