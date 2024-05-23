#define KBD_INT 33

#include "isr.h"

extern void kbd_isr();

void
isrman(int ds, int edi, int esi, int ebp, int esp, int ebx, int edx, int ecx,
       int eax, int intno, int errno, int eip, int cs, int attr,int uesp,int ss)
{
	/* Action to take when the interrupt is from the PIC. */
	if (intno == KBD_INT) {
		kbd_isr();
	}
		
	/* Action to take when the interrupt is system reserved. */
	else if (intno >= 0 && intno <= 9)
		printf("intr: %d\n", intno);
	else if (intno >= 10 && intno <= 31)
		printf("intr: %d\n", intno);
}
