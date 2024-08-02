/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <math.h>

long double __cdecl fmodl(long double x, long double y)
{
  long double res = 0.0L;

  __asm__ __volatile__(
    "1:\tfprem\n\t"
    "fstsw %%ax\n\t"
    "sahf\n\t"
    "jp    1b\n\t"
    "fstp  %%st(1)"
    : "=t" (res) : "0" (x), "u" (y) : "ax", "st(1)");
  return res;
}

long double __cdecl (*__MINGW_IMP_SYMBOL(fmodl))(long double, long double) = fmodl;
