/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define __CRT__NO_INLINE
#include <math.h>

float __cdecl frexpf(float x, int *expn)
{
  return (float)frexp(x, expn);
}

float __cdecl (*__MINGW_IMP_SYMBOL(frexpf))(float x, int *expn) = frexpf;
