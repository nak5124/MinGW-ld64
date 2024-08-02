/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <math.h>

long double __cdecl
atanl (long double x)
{
  long double res = 0.0L;

  asm volatile (
       "fld1\n\t"
       "fpatan"
       : "=t" (res) : "0" (x));
  return res;
}

long double __cdecl (*__MINGW_IMP_SYMBOL(atanl))(long double) = atanl;
