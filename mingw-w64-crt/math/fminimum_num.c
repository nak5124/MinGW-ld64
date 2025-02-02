/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _ISOC23_SOURCE
#include <math.h>

double __cdecl fminimum_num(double _X, double _Y)
{
  if(isless(_X, _Y))
  {
    return _X;
  }
  else if(isgreater(_X, _Y))
  {
    return _Y;
  }
  else if(isunordered(_X, _Y))
  {
    return __builtin_isnan(_X) ? (__builtin_isnan(_Y) ? _X + _Y : _Y) : _X;
  }
  else
  {
    return __builtin_signbit(_X) ? _X : _Y;
  }
}

long double __cdecl fminimum_numl(long double _X, long double _Y) __ALIAS(fminimum_num);
