/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _ISOC23_SOURCE
#include <math.h>
#include <errno.h>
#include <fenv.h>

double __cdecl tanpi(double x)
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
    ret = ((int)iabs_x % 2 == 0) ? __builtin_copysign(0.0, x) : __builtin_copysign(0.0, -x);
  }
  else if(__builtin_isless(fabs_x, 0.25))
  {
    ret = __builtin_copysign(tan(M_PI * fabs_x), x);
  }
  else if(fabs_x == 0.25)
  {
    ret = __builtin_copysign(1.0, x);
  }
  else if(__builtin_isless(fabs_x, 0.5))
  {
    ret = __builtin_copysign(1.0 / tan(M_PI * (0.5 - fabs_x)), x);
  }
  else if(fabs_x == 0.5)
  {
    errno = ERANGE;
    feraiseexcept(FE_DIVBYZERO);
    ret = ((int)iabs_x % 2 == 0) ? __builtin_inf() : -__builtin_inf();
  }
  else if(__builtin_isless(fabs_x, 0.75))
  {
    ret = __builtin_copysign(1.0 / tan(M_PI * (fabs_x - 0.5)), -x);
  }
  else if(fabs_x == 0.75)
  {
    ret = __builtin_copysign(1.0, -x);
  }
  else
  {
    ret = __builtin_copysign(tan(M_PI * (1.0 - fabs_x)), -x);
  }
  return ret;
}

long double __cdecl tanpil(long double _X) __ALIAS(tanpi);
