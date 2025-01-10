/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _ISOC23_SOURCE
#include <math.h>

double __cdecl atan2pi(double y, double x)
{
  double ret = atan2(y, x) / M_PI;
  return __builtin_isgreater(__builtin_fabs(ret), 1.0) ? __builtin_copysign(1.0, ret) : ret;
}

long double __cdecl atan2pil(long double _Y, long double _X) __attribute__((alias("atan2pi")));
