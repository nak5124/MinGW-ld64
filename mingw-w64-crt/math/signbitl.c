/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#include <math.h>

#define __FP_SIGNBIT 0x0200

int __signbitl(long double x)
{
#if defined(__x86_64__) || defined(_AMD64_)
  __mingw_ldbl_type_t ld;
  ld.x = x;
  return ((ld.lh.sign_exponent & 0x8000) != 0);
#elif defined(__aarch64__) || defined(_ARM64_)
  return __signbit(x);
#endif
}

int __attribute__((alias("__signbitl"))) signbitl(long double);
