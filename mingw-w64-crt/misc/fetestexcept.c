/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <fenv.h>

/* 7.6.2.5
 * The fetestexcept function determines which of a specified subset of
 * the exception flags are currently set. The excepts argument
 * specifies the exception flags to be queried.
 * The fetestexcept function returns the value of the bitwise OR of the
 * exception macros corresponding to the currently set exceptions
 * included in excepts. */

int __cdecl fetestexcept(int excepts)
{
#if defined(__aarch64__) || defined(_ARM64_)
  unsigned __int64 fpcr;
  __asm__ __volatile__("mrs %0, fpcr" : "=r" (fpcr));
  return fpcr & excepts & FE_ALL_EXCEPT;
#else
  unsigned short _sw;
  __asm__ __volatile__("fnstsw %%ax" : "=a" (_sw));

  int sse_sw;
  __asm__ __volatile__("stmxcsr %0;" : "=m" (sse_sw));
  _sw |= sse_sw;
  return _sw & excepts & FE_ALL_EXCEPT;
#endif  /* defined(__aarch64__) || defined(_ARM64_) */
}

int __cdecl (*__MINGW_IMP_SYMBOL(fetestexcept))(int) = fetestexcept;
