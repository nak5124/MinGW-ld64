/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <fenv.h>
#include <math.h>
#include <errno.h>

long double __cdecl modfl(long double value, long double* iptr)
{
  double _fraction, _integer;
  _fraction = modf((double)value, &_integer);
  *iptr = _integer;
  return _fraction;
}

long double __cdecl (*__MINGW_IMP_SYMBOL(modfl))(long double value, long double *iptr) = modfl;
