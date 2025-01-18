/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define __CRT__NO_INLINE
#include <math.h>

int __cdecl __signbit(double x)
{
  __mingw_dbl_type_t hlp;

  hlp.x = x;
  return ((hlp.lh.high & 0x80000000) != 0);
}

#undef signbit
int __cdecl signbit(double x) __ALIAS(__signbit);

int __cdecl __signbitl(long double x) __ALIAS(__signbit);
int __cdecl signbitl(long double x) __ALIAS(__signbit);
