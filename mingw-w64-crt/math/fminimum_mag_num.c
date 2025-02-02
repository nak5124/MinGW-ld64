/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _ISOC23_SOURCE
#include <math.h>

double __cdecl fminimum_mag_num(double _X, double _Y)
{
  double xa = __builtin_fabs(_X);
  double ya = __builtin_fabs(_Y);

  if(isless(xa, ya))
  {
    return _X;
  }
  else if(isgreater(xa, ya))
  {
    return _Y;
  }
  else if(isunordered(xa, ya))
  {
    return __builtin_isnan(_X) ? (__builtin_isnan(_Y) ? _X + _Y : _Y) : _X;
  }
  else
  {
    return __builtin_signbit(_X) ? _X : _Y;
  }
}

long double __cdecl fminimum_mag_numl(long double _X, long double _Y) __ALIAS(fminimum_mag_num);
