/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _ISOC23_SOURCE
#include <math.h>

float __cdecl fmaximum_magf(float _X, float _Y)
{
  float xa = __builtin_fabsf(_X);
  float ya = __builtin_fabsf(_Y);

  if(isgreater(xa, ya))
  {
    return _X;
  }
  else if(isless(xa, ya))
  {
    return _Y;
  }
  else if(isunordered(xa, ya))
  {
    return _X + _Y;
  }
  else
  {
    return __builtin_signbitf(_X) ? _Y : _X;
  }
}
