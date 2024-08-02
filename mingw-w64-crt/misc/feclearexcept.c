/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <fenv.h>

/* 7.6.2.1
 * The feclearexcept function clears the supported exceptions
 * represented by its argument. */

int __cdecl feclearexcept(int excepts)
{
  fenv_t _env;
#if defined(__aarch64__) || defined(_ARM64_)
  unsigned __int64 fpcr;
  (void)_env;
  __asm__ __volatile__("mrs %0, fpcr" : "=r" (fpcr));
  fpcr &= ~(excepts & FE_ALL_EXCEPT);
  __asm__ __volatile__("msr fpcr, %0" : : "r" (fpcr));
#else
  int _mxcsr;
  if(excepts == FE_ALL_EXCEPT)
  {
    __asm__ __volatile__("fnclex");
  }
  else
  {
    __asm__ __volatile__("fnstenv %0" : "=m" (_env));
    _env.__status_word &= ~(excepts & FE_ALL_EXCEPT);
    __asm__ __volatile__("fldenv %0" : : "m" (_env));
  }
  __asm__ __volatile__("stmxcsr %0" : "=m" (_mxcsr));
  _mxcsr &= ~(((excepts & FE_ALL_EXCEPT)));
  __asm__ __volatile__("ldmxcsr %0" : : "m" (_mxcsr));
#endif  /* defined(__aarch64__) || defined(_ARM64_) */
  return (0);
}

int __cdecl (*__MINGW_IMP_SYMBOL(feclearexcept))(int) = feclearexcept;
