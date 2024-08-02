/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <math.h>

long double __cdecl
fminl (long double _x, long double _y)
{
  return ((islessequal(_x, _y) || __isnanl (_y)) ? _x : _y );
}

long double __cdecl (*__MINGW_IMP_SYMBOL(fminl))(long double, long double) = fminl;
