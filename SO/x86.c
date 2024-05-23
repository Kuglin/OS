#include "x86.h"

int
inb(int port)
{
	int data;
	__asm__ __volatile__("inb %%dx, %%al" : "=r" (data) : "Nd" (port));
	return data;
}

void
lidt(void* idtr)
{
	uint16_t a[3];
	a[0] = *(uint16_t*)idtr;
	idtr = (uint16_t*)idtr + 1;
	a[1] = *(uint16_t*)idtr;
	idtr = (uint16_t*)idtr + 1;
	a[2] = *(uint16_t*)idtr;
	__asm__ __volatile__("lidt %0" : : "m"(a));
}

void
outb(int data, int port)
{
	__asm__ __volatile__("outb %%al, %%dx" : : "a" (data), "Nd" (port));
}
