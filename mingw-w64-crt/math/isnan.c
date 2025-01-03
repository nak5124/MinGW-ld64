/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <math.h>

int __cdecl __isnan(double _x)
{
  __mingw_dbl_type_t hlp;
  int l, h;

  hlp.x = _x;
  l = hlp.lh.low;
  h = hlp.lh.high & 0x7fffffff;
  h |= (unsigned int)(l | -l) >> 31;
  h = 0x7ff00000 - h;
  return (int)((unsigned int)h) >> 31;
}

#undef isnan
int __cdecl isnan(double _x) __attribute__((alias("__isnan")));

int __cdecl __isnanl(long double _x) __attribute__((alias("__isnan")));
int __cdecl isnanl(long double _x) __attribute__((alias("__isnan")));
