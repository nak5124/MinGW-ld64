/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _ISOC23_SOURCE
#include <math.h>
#include <float.h>
#include <limits.h>

double __cdecl nextdown(double x)
{
  if(__builtin_isinf_sign(x) == 1)
  {
    return DBL_MAX;
  }
  else if(__builtin_isinf_sign(x) == -1)
  {
    return -__builtin_inf();
  }
  else if(__builtin_isnan(x))
  {
    return __builtin_nan("");
  }
  else if(iszero(x))
  {
    return -DBL_TRUE_MIN;
  }

  int          hx;
  unsigned int lx;

  __mingw_dbl_type_t dbl_x;
  dbl_x.x = x;
  hx      = dbl_x.lh.high;
  lx      = dbl_x.lh.low;

  if(hx >= 0)
  {
    lx -= 1;
    if(lx == UINT_MAX)
    {
      hx -= 1;
    }
  }
  else
  {
    if(lx == UINT_MAX)
    {
      hx += 1;
    }
    lx += 1;
  }
  __mingw_dbl_type_t dbl_nu;
  dbl_nu.lh.high = hx;
  dbl_nu.lh.low  = lx;
  x              = dbl_nu.x;

  return x;
}

long double __cdecl nextdownl(long double x) __ALIAS(nextdown);
