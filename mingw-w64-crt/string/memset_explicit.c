/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _ISOC23_SOURCE
#define __CRT__NO_INLINE
#include <string.h>

void *__cdecl memset_explicit(void *_Dest, int _Ch, size_t _Count)
{
    memset(_Dest, _Ch, _Count);
    __asm__ __volatile__("" : : "r"(_Dest) : "memory");
}
