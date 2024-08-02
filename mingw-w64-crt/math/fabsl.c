/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <math.h>

long double __cdecl
fabsl (long double x)
{
#if defined(__x86_64__) || defined(_AMD64_)
  long double res = 0.0L;
  asm volatile ("fabs;" : "=t" (res) : "0" (x));
  return res;
#elif defined(__aarch64__) || defined(_ARM64_)
  return __builtin_fabsl (x);
#endif /* defined(__x86_64__) || defined(_AMD64_) */
}

long double __cdecl (*__MINGW_IMP_SYMBOL(fabsl))(long double) = fabsl;
