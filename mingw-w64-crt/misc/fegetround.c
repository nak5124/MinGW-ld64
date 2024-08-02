/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <fenv.h>

/* 7.6.3.1
 * The fegetround function returns the value of the rounding direction
 * macro representing the current rounding direction. */

int __cdecl fegetround(void)
{
#if defined(__aarch64__) || defined(_ARM64_)
  unsigned __int64 fpcr;
  __asm__ __volatile__("mrs %0, fpcr" : "=r" (fpcr));
  return (fpcr & (FE_TONEAREST | FE_DOWNWARD |  FE_UPWARD | FE_TOWARDZERO));
#else
  int _control;
  __asm__ __volatile__("fnstcw %0" : "=m" (*&_control));
  return (_control & (FE_TONEAREST | FE_DOWNWARD |  FE_UPWARD | FE_TOWARDZERO));
#endif  /* defined(__aarch64__) || defined(_ARM64_) */
}

int __cdecl (*__MINGW_IMP_SYMBOL(fegetround))(void) = fegetround;
