/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <fenv.h>

  /* 7.6.3.2
   * The fesetround function establishes the rounding direction
   * represented by its argument round. If the argument is not equal
   * to the value of a rounding direction macro, the rounding direction
   * is not changed. */

int __cdecl fesetround(int mode)
{
#if defined(__aarch64__) || defined(_ARM64_)
  unsigned __int64 fpcr;
  if((mode & ~(FE_TONEAREST | FE_DOWNWARD | FE_UPWARD | FE_TOWARDZERO)) != 0)
    return -1;
  __asm__ __volatile__("mrs %0, fpcr" : "=r" (fpcr));
  fpcr &= ~(FE_TONEAREST | FE_DOWNWARD |  FE_UPWARD | FE_TOWARDZERO);
  fpcr |= mode;
  __asm__ __volatile__("msr fpcr, %0" : : "r" (fpcr));
#else
  unsigned short _cw;
  if((mode & ~(FE_TONEAREST | FE_DOWNWARD | FE_UPWARD | FE_TOWARDZERO)) != 0)
    return -1;
  __asm__ __volatile__("fnstcw %0;": "=m" (*&_cw));
  _cw &= ~0xc00;
  _cw |= mode;
  __asm__ __volatile__("fldcw %0;" : : "m" (*&_cw));

  int mxcsr;

  __asm__ __volatile__("stmxcsr %0" : "=m" (*&mxcsr));
  mxcsr &= ~0x6000;
  mxcsr |= mode << 3;
  __asm__ __volatile__("ldmxcsr %0" : : "m" (*&mxcsr));
#endif  /* defined(__aarch64__) || defined(_ARM64_) */
  return 0;
}

int __cdecl (*__MINGW_IMP_SYMBOL(fesetround))(int) = fesetround;
