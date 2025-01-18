/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _ISOC23_SOURCE
#include <math.h>
#include <errno.h>

double __cdecl asinpi(double x)
{
  if(__builtin_expect(!!(__builtin_isgreater(__builtin_fabs(x), 1.0)), 0))
  {
    errno = EDOM;
    return __builtin_nan("1");
  }
  double ret = asin(x) / M_PI;
  return __builtin_isgreater(__builtin_fabs(ret), 0.5) ? __builtin_copysign(0.5, ret) : ret;
}

long double __cdecl asinpil(long double _X) __ALIAS(asinpi);
