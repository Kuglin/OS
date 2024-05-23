#ifndef IDT_H
#define IDT_H

#define IDTATTR 0x8e /* ring zero 32-bit interrupt entry */
#define IDTLEN 48    /* system interrupts + hardware IRQs */

#include "gdt.h"
#include "types.h"

struct idt {
	uint16_t isrlo;
	uint16_t cs;
	uint8_t zero;
	uint8_t attr;
	uint16_t isrhi;
} __attribute__((packed));

struct idtr {
	uint16_t ofst;
	uint32_t base;
} __attribute__((packed));

void idt_entry(struct idt*, int, void*); /* Initialize a IDT entry. */
void inidt(struct idt*);                 /* Initialize the IDT entries. */
void inidtr(struct idt*, struct idtr*);  /* Initialize the IDTR entries. */

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();
extern void isr32();
extern void isr33();
extern void isr34();
extern void isr35();
extern void isr36();
extern void isr37();
extern void isr38();
extern void isr39();
extern void isr40();
extern void isr41();
extern void isr42();
extern void isr43();
extern void isr44();
extern void isr45();
extern void isr46();
extern void isr47();

#endif
