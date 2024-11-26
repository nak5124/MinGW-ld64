/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _DEFAULT_SOURCE
#include <string.h>

void __cdecl explicit_bzero(void *_Ptr, size_t _N)
{
    (void)memset(_Ptr, '\0', _N);
    __asm__ __volatile__("" : : : "memory");
}
