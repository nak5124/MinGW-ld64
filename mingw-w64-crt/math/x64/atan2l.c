/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <math.h>

long double __cdecl atan2l(long double y, long double x)
{
  long double res = 0.0L;
  __asm__ __volatile__("fpatan" : "=t" (res) : "u" (y), "0" (x) : "st(1)");
  return res;
}

long double __cdecl (*__MINGW_IMP_SYMBOL(atan2l))(long double, long double) = atan2l;
