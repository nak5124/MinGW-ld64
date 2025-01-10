/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _ISOC23_SOURCE
#include <math.h>
#include <errno.h>

double __cdecl acospi(double x)
{
  if(__builtin_expect(!!(__builtin_isgreater(__builtin_fabs(x), 1.0)), 0))
  {
    errno = EDOM;
    return __builtin_nan("1");
  }
  double ret = acos(x) / M_PI;
  return __builtin_isgreater(ret, 1.0) ? 1.0 : ret;
}

long double __cdecl acospil(long double _X) __attribute__((alias("acospi")));
