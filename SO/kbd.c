#include "i8259.h"
#include "printf.h"
#include "x86.h"

static int shift = 0;
static int caps = 0;

static char sc[] = {
    ' ', ' ', '1', '2', '3', '4', '5', '6', '7', '8', 
    '9', '0', '-', '=', '`', ' ', 'q', 'w', 'e', 'r', 
    't', 'y', 'u', 'i', 'o', 'p', '[', ']', ' ', ' ',
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', 
    '"', ' ', ' ', ' ', 'z', 'x', 'c', 'v', 'b', 'n', 
    'm', ',', '.', '/', ' ', ' ', ' ', ' '};

static unsigned char scShift[] = {
    ' ', ' ', '!', '@', '#', '$', '%', '¨', '&', '*', 
    '(', ')', '-', '=', '`', ' ', 'Q', 'W', 'E', 'R', 
    'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', ' ', ' ',
    'A', 'S', 'D', 'F', 'G', 'H', 'I', 'J', 'L', ':', 
    '"', ' ', ' ', ' ', 'Z', 'X', 'C', 'V', 'B', 'N', 
    'M', '<', '>', '?', ' ', ' ', ' ', ' '};

/* scancode to ascii */
void
sctoa(unsigned char scod)
{


    //Verificar caps
    if (scod == 0x3A)
    {
        if (caps)
        {
            caps = 0;
            return;
        }
        caps = 1;
        return;
    }

    //Verificar shift
    if (scod == 0x2A || scod == 0x36) {
        shift = 1;
        return;
    }

    if (scod == 0xAA || scod == 0xB6) {
        shift = 0;
        return;
    }
    
    
    //Printar de acordo
    if (scod >= 0 && scod <= 0x39) {
        if (shift) {
            if (caps) {
                if (sc[scod] >= 97 && sc[scod] <= 122) {
                    printc(toLowerCase(scShift[scod]));
                    return;
                }
            }
            printc(scShift[scod]);
            return;
        }
        if (caps)
        {
            if (sc[scod] >= 97 && sc[scod] <= 122)
            {
                printc(toUpperCase(sc[scod]));
                return;
            }

        }
        
        printc(sc[scod]);
    }
}

/* keyboard interrupt service handler */
void
kbd_isr()
{
	eoi(PIC1_CTLR);
	sctoa(inb(0x60));
}

int toUpperCase(int c) {
    return c-32;
}

int toLowerCase(int c) {
    return c+32;
}