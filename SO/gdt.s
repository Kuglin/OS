/* 32-bit flat mode */

gdt:
	.code16
	.8byte 0

gdtc:
	.code16
	.2byte 0xffff
	.2byte 0
	.byte 0
	.byte 0b10011010
	.byte 0b11001111
	.byte 0

gdtd:
	.code16
	.2byte 0xffff
	.2byte 0
	.byte 0
	.byte 0b10010010
	.byte 0b11001111
	.byte 0

gdtr:
	.code16
	.2byte . - gdt - 1
	.4byte gdt
