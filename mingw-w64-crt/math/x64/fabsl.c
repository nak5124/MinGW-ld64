/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define __CRT__NO_INLINE
#include <math.h>

long double __cdecl fabsl(long double x)
{
  long double res = 0.0L;
  __asm__ __volatile__("fabs;" : "=t" (res) : "0" (x));
  return res;
}

long double __cdecl (*__MINGW_IMP_SYMBOL(fabsl))(long double) = fabsl;
