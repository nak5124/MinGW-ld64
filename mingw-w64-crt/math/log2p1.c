/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _ISOC23_SOURCE
#include <math.h>

double __cdecl log2p1(double x)
{
  if(__builtin_expect(!!__builtin_islessequal(x, -1.0), 0))
  {
    if(x == -1)
    {
      errno = ERANGE;
      return -HUGE_VAL;
    }
    else
    {
      errno = EDOM;
      return __builtin_nan("<-1");
    }
  }
  if(__builtin_isless(__builtin_fabs(x), 0x1p-54))
  {
    return M_LOG2E * x;
  }
  return M_LOG2E * log1p(x);
}

long double __cdecl log2p1l(long double _X) __attribute__((alias("log2p1")));
