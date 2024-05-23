/* TODO: implement a format for unsigned types and check overflows. */

#define MAX_DGT 32

#include "printf.h"

/* Print a character. */
void
printc(char c)
{
	putchar(c);
}

/* Print binary, decimal and hexadecimal signed numbers. */
void
printi(int n, const int b) /* number and base */
{
	/* negative */
	if (n < 0) {
		printf("-");
		n *= -1;
	} /* base prefix */

	int a[MAX_DGT]; /* reversed digits of the number */
	/* Populate the aforementioned array. */
	for (size_t i = 0; i < MAX_DGT; i++) {
		if (n % b + 0x30 <= 0x39)
			a[i] = n % b + 0x30;
		else /* Skip to A-Z on the ascii table when hex. */
			a[i] = n % b + 0x30 + 7;
		n /= b;
	}
	/* Print the aforementioned array in reverse order. */
	for (size_t i = MAX_DGT, z = 0; (i--) > 0;) {
		/* Skip leading zeros. */
		if (a[i] != 0x30)
			z = 1;
		if (z != 0) /* non zero digits */
			printf("%c", (char)a[i]);
		/* the whole number is zero */
		if (z == 0 && i == 0)
			printf("0");
	}
}

/* Print a string. */
void
prints(char* s)
{
	puts(s);
}

/* Print formated text. */
void
printf(char* fmt, ...)
{
	size_t a = 1; /* argument counter */
	for (char* s = fmt; *s != '\0'; s++) {
		if (*s == '%') { /* special character format */
			s++;
			if (*s == 'b')      /* bin */
				printi(*((int32_t*)&fmt + a++), 2);
			else if (*s == 'c') /* char */
				printc(*(int8_t*)((int32_t*)&fmt + a++));
			else if (*s == 'd') /* decimal */
				printi(*((int32_t*)&fmt + a++), 10);
			else if (*s == 's') /* string */
				prints(*(int8_t**)((int32_t*)&fmt + a++));
			else if (*s == 'x') /* hex */
				printi(*((int32_t*)&fmt + a++), 16);
			else
				printf("Undefined format!\n");
		} else /* non special character */
			printf("%c", *s);
	}
}
