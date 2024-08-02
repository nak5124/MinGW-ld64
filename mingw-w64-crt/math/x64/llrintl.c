/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <math.h>
#include <fenv.h>

long long __cdecl llrintl(long double x)
{
  long long retval = 0ll;
  __asm__ __volatile__("fistpll %0" : "=m" (retval) : "t" (x) : "st");
  return retval;
}

long long __cdecl (*__MINGW_IMP_SYMBOL(llrintl))(long double) = llrintl;
