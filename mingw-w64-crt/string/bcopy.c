/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _DEFAULT_SOURCE
#include <strings.h>

void __cdecl bcopy(const void *_Src, void *_Dst, size_t _Size)
{
    (void)memmove(_Dst, _Src, _Size);
}
