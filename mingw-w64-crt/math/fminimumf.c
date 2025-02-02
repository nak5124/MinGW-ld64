/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _ISOC23_SOURCE
#include <math.h>

float __cdecl fminimumf(float _X, float _Y)
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
    return _X + _Y;
  }
  else
  {
    return __builtin_signbitf(_X) ? _X : _Y;
  }
}
