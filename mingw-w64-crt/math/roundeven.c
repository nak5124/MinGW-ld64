/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _ISOC23_SOURCE
#define __CRT__NO_INLINE
#include <math.h>

double __cdecl roundeven(double _X)
{
  return __builtin_roundeven(_X);
}

long double __cdecl roundevenl(long double _X) __attribute__((alias("roundeven")));
