/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _DEFAULT_SOURCE
#define __CRT__NO_INLINE
#include <strings.h>

void __cdecl bzero(void *_Ptr, size_t _N)
{
    memset(_Ptr, '\0', _N);
}
