#include "vga.h"

static char* vgacur = (char*) VGA_OFFSET;

void
clear()
{
	/* Fill the frame with white on black white spaces. */
	vgacur = (char*)(VGA_OFFSET);
	for (; vgacur < (char*)(VGA_OFFSET + FRAME_SIZE); vgacur += 2) {
		*(vgacur++) = ' '; /* character */
		*(vgacur--) = 0xf; /* color */
	}
	/* Restore the cursor to its initial position on the clean frame. */
	vgacur = (char*)(VGA_OFFSET);
	updt_cur_pos();
}

void
putchar(const char c)
{
	/* Scroll up when the cursor is at the last free position. */
	if (vgacur == (char*)(VGA_OFFSET + FRAME_SIZE))
		scrollup();
	/* end-of-line */
	if (c == '\n') {
		/* Scroll up when going to the next row in the last row. */
		if ((int)(vgacur) >= VGA_OFFSET + FRAME_SIZE - 2 * NCOL) {
			scrollup();
			return; /* no need for a newline when scroll up */
		}
		/* Go to the start of the next line. */
		int cur = (int)(vgacur);
		cur -= VGA_OFFSET;
		cur /= 2 * NCOL;
		cur *= 2 * NCOL;
		cur += 2 * NCOL;
		cur = cur + VGA_OFFSET;
		vgacur = (char*)(cur);
	/* tab */
	} else if (c == '\t') {
		/* Scroll up when inserting tabs at the end of the last line. */
		if ((int)(vgacur) >= VGA_OFFSET + FRAME_SIZE - 8)
			scrollup();
		/* Draw a tab with n blank spaces. */
		for (int i = 0; i < TAB_SIZE; i++, vgacur += 2)
			*vgacur = ' ';
	/* backspace */
	} else if (c == '`' && (int)(vgacur) >= VGA_OFFSET) {
		vgacur -= 2;
		*vgacur = ' ';
	/* non-control character */
	} else {
		*vgacur = c;
		vgacur += 2;
	}
	updt_cur_pos();
}

void
puts(const char* c)
{
	/* Put all string, except by the last character, into the frame. */
	for (; *c != '\0'; c++ )
		putchar(*c);
}

void
scrollup()
{
	vgacur = (char*)(VGA_OFFSET);

	/* Copy the next line to the current line. */
	for (; vgacur <= (char*)(VGA_OFFSET + FRAME_SIZE - 2*NCOL); vgacur += 2)
		*vgacur = *(vgacur + (NCOL * 2));

	/* Clear the last row, since it was copied to the penultimate row. */
	vgacur = (char*)(VGA_OFFSET + FRAME_SIZE - 2 * NCOL);
	for (; vgacur <= (char*)(VGA_OFFSET + FRAME_SIZE); vgacur += 2)
		*vgacur = ' ';

	/* Put the cursor at the start of the last line. */
	vgacur = (char*)(VGA_OFFSET + FRAME_SIZE - 2 * NCOL);
	updt_cur_pos();
}

void
updt_cur_pos()
{
	outb(CRT_CUR_POS_HI, CRT_CTLR);
	outb((((int)(vgacur) - VGA_OFFSET) / 2) >> 8, CRT_DATA);
	outb(CRT_CUR_POS_LO, CRT_CTLR);
	outb((((int)(vgacur) - VGA_OFFSET) / 2) & 0b11111111, CRT_DATA);
}
