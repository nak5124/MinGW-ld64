/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _ISOC23_SOURCE
#include <math.h>
#include <errno.h>
#include <fenv.h>

double __cdecl cospi(double x)
{
  x = __builtin_fabs(x);
  if(__builtin_isless(x, 0x1p-29))
  {
    return 1.0;
  }
  if(__builtin_expect(!!__builtin_isinf_sign(x), 0))
  {
    errno = EDOM;
    feraiseexcept(FE_INVALID);
    return __builtin_nan("inf");
  }

  double i_x;
  double f_x = __builtin_modf(x, &i_x);
  double ret;
  if(__builtin_isless(f_x, 0.25))
  {
    ret = cos(M_PI * f_x);
  }
  else if(__builtin_isless(f_x, 0.75))
  {
    if(f_x == 0.5)
    {
      return 0.0;
    }
    ret = sin(M_PI * (0.5 - f_x));
  }
  else
  {
    ret = -cos(M_PI * (1.0 - f_x));
  }
  return ((int)i_x % 2 == 0) ? ret : -ret;
}

long double __cdecl cospil(long double _X) __ALIAS(cospi);
