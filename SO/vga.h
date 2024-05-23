#ifndef VGA_H
#define VGA_H

#define CRT_CTLR 0x3d4
#define CRT_DATA 0x3d5
#define CRT_CUR_POS_HI 0xe
#define CRT_CUR_POS_LO 0xf
#define FRAME_SIZE 2 * NCOL * NROW
#define NCOL 80
#define NROW 25
#define TAB_SIZE 8
#define VGA_OFFSET 0xb8000

#include "x86.h"

void clear();             /* Clear the frame black. */
void putchar(const char); /* Put a character on the screen. */
void puts(const char*);   /* Put a string on the screen. */
void scrollup();          /* Scroll one line up. */
void updt_cur_pos();      /* Put the cursor at the last character. */

#endif
