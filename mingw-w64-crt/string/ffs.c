/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _DEFAULT_SOURCE
#define __CRT__NO_INLINE
#include <strings.h>

int __cdecl ffs(int _Int)
{
    return __builtin_ffs(_Int);
}

#undef ffsl
int __cdecl ffsl(long _Long) __attribute__((alias("ffs")));
