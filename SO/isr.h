#ifndef ISR_H
#define ISR_H

#include "printf.h"

/* ISR dispatcher */
void isrman(int ds, int edi, int esi, int ebp, int esp, int ebx, int edx,
            int ecx, int eax, int intno, int errno, int eip, int cs, int attr,
            int uesp, int ss);

#endif
