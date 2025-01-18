/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _ISOC23_SOURCE
#include <math.h>
#include <errno.h>
#include <fenv.h>

double __cdecl sinpi(double x)
{
  double abs_x = __builtin_fabs(x);
  if(__builtin_isless(abs_x, 0x1p-29))
  {
    if(x == 0)
    {
      return x;
    }
    return M_PI * x;
  }
  if(__builtin_expect(!!__builtin_isinf_sign(x), 0))
  {
    errno = EDOM;
    feraiseexcept(FE_INVALID);
    return __builtin_nan("inf");
  }

  double iabs_x;
  double fabs_x = __builtin_modf(abs_x, &iabs_x);
  double ret;
  if(fabs_x == 0.0)
  {
    return __builtin_copysign(0.0, x);
  }
  if(__builtin_isless(fabs_x, 0.25))
  {
    ret = __builtin_copysign(sin(M_PI * fabs_x), x);
  }
  else if(__builtin_isless(fabs_x, 0.75))
  {
    ret = __builtin_copysign(cos(M_PI * (0.5 - fabs_x)), x);
  }
  else
  {
    ret = __builtin_copysign(sin(M_PI * (1.0 - fabs_x)), x);
  }
  return ((int)iabs_x % 2 == 0) ? ret : -ret;
}

long double __cdecl sinpil(long double _X) __ALIAS(sinpi);
