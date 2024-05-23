#ifndef STRING_H
#define STRING_H

#include "types.h"

int memcmp(void* src, void* dst, size_t len);
size_t strlen(char* s);
void* memcpy(void* dst, void* src, size_t len);
void* memset(void* dst, int c, size_t len);

#endif
