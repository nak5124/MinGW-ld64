/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <math.h>

long double __cdecl ldexpl(long double x, int n)
{
#if defined(__aarch64__) || defined(_ARM64_)
    return ldexp(x, n);
#else
# error Not supported on your platform yet
#endif
}

long double __cdecl (*__MINGW_IMP_SYMBOL(ldexpl))(long double, int) = ldexpl;
