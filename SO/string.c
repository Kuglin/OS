#include "string.h"

int
memcmp(void* src, void* dst, size_t len)
{
	uint8_t* s = (uint8_t*)src;
	uint8_t* d = (uint8_t*)dst;
	for (size_t i = 0; i < len; i++, s++, d++) {
		if (*s != *d)
			return 0;
	}
	return 1;
}

size_t
strlen(char* s)
{
	size_t i = 0;
	for (; *s != '\0'; i++, s++)
		;
	return i;
}

void*
memcpy(void* dst, void* src, size_t len)
{
	uint8_t* d = (uint8_t*)dst;
	uint8_t* s = (uint8_t*)src;
	for (; len-- > 0;)
		*(d++) = *(s++);
	return (void*)d;
}

void*
memset(void* dst, int c, size_t len)
{
	uint8_t* tmp = (uint8_t*)dst;
	for (; len-- > 0;)
		*(tmp++) = (int8_t)c;
	return dst;
}
