#include "i8259.h"
#include "idt.h"
#include "isr.h"
#include "vga.h"

#include "printf.h"

#include "lerHd.h"

/* Initialize video and interrupts, then halt the machine. */
void
main()
{
	clear();

	/* Initialize the IDT and the IDT descriptor. */
	struct idt idt[IDTLEN];
	struct idtr idtr;
	inidt(idt);
	inidtr(idt, &idtr);

	init_i8259();
	outb(0b11111101, PIC1_DATA); /* Unmask the keyboard IRQ. */
	lidt(&idtr);
	sti();

	verificar_hd();

	/* Wait for interrupts. */
	while (1)

		hlt();
}
