/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _ISOC23_SOURCE
#include <math.h>
#include <float.h>

float __cdecl nextupf(float x)
{
  if(__builtin_isinf_sign(x) == 1)
  {
    return __builtin_inff();
  }
  else if(__builtin_isinf_sign(x) == -1)
  {
    return -FLT_MAX;
  }
  else if(__builtin_isnanf(x))
  {
    return __builtin_nanf("");
  }
  else if(iszero(x))
  {
    return FLT_TRUE_MIN;
  }

  int hx;

  __mingw_flt_type_t flt_x;
  flt_x.x = x;
  hx      = flt_x.val;

  if(hx >= 0)
  {
    hx += 1;
  }
  else
  {
    hx -= 1;
  }
  __mingw_flt_type_t flt_nu;
  flt_nu.val = hx;
  x          = flt_nu.x;

  return x;
}
