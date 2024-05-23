#include "idt.h"

void
idt_entry(struct idt* idt, int n, void* isr)
{
	idt[n].isrlo = (uint16_t)((uint32_t)(isr) & 0xffff);
	idt[n].cs = KCS;
	idt[n].attr = IDTATTR;
	idt[n].zero = 0;
	idt[n].isrhi = (uint16_t)((uint32_t)(isr) >> 16);
}

void
inidtr(struct idt* idt, struct idtr* idtr)
{
	(*idtr).base = (uint32_t) idt;
	(*idtr).ofst = (uint16_t)(sizeof(*idt) * IDTLEN - 1);
}

void
inidt(struct idt* idt)
{
	idt_entry(idt, 0, isr0);
	idt_entry(idt, 1, isr1);
	idt_entry(idt, 2, isr2);
	idt_entry(idt, 3, isr3);
	idt_entry(idt, 4, isr4);
	idt_entry(idt, 5, isr5);
	idt_entry(idt, 6, isr6);
	idt_entry(idt, 7, isr7);
	idt_entry(idt, 8, isr8);
	idt_entry(idt, 9, isr9);
	idt_entry(idt, 10, isr10);
	idt_entry(idt, 11, isr11);
	idt_entry(idt, 12, isr12);
	idt_entry(idt, 13, isr13);
	idt_entry(idt, 14, isr14);
	idt_entry(idt, 15, isr15);
	idt_entry(idt, 16, isr16);
	idt_entry(idt, 17, isr17);
	idt_entry(idt, 18, isr18);
	idt_entry(idt, 19, isr19);
	idt_entry(idt, 20, isr20);
	idt_entry(idt, 21, isr21);
	idt_entry(idt, 22, isr22);
	idt_entry(idt, 23, isr23);
	idt_entry(idt, 24, isr24);
	idt_entry(idt, 25, isr25);
	idt_entry(idt, 26, isr26);
	idt_entry(idt, 27, isr27);
	idt_entry(idt, 28, isr28);
	idt_entry(idt, 29, isr29);
	idt_entry(idt, 30, isr30);
	idt_entry(idt, 31, isr31);
	idt_entry(idt, 32, isr32);
	idt_entry(idt, 33, isr33);
	idt_entry(idt, 34, isr34);
	idt_entry(idt, 35, isr35);
	idt_entry(idt, 36, isr36);
	idt_entry(idt, 37, isr37);
	idt_entry(idt, 38, isr38);
	idt_entry(idt, 39, isr39);
	idt_entry(idt, 40, isr40);
	idt_entry(idt, 41, isr41);
	idt_entry(idt, 42, isr42);
	idt_entry(idt, 43, isr43);
	idt_entry(idt, 44, isr44);
	idt_entry(idt, 45, isr45);
	idt_entry(idt, 46, isr46);
	idt_entry(idt, 47, isr47);
}
