/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <fenv.h>

/* 7.6.2.4
 * The fesetexceptflag function sets the complete status for those
 * exception flags indicated by the argument excepts, according to the
 * representation in the object pointed to by flagp. The value of
 * *flagp shall have been set by a previous call to fegetexceptflag
 * whose second argument represented at least those exceptions
 * represented by the argument excepts. This function does not raise
 * exceptions, but only sets the state of the flags. */

int __cdecl fesetexceptflag(const fexcept_t * flagp, int excepts)
{
  fenv_t _env;

  excepts &= FE_ALL_EXCEPT;

#if defined(__aarch64__) || defined(_ARM64_)
  unsigned __int64 fpcr;
  (void)_env;
  __asm__ __volatile__("mrs %0, fpcr" : "=r" (fpcr));
  fpcr &= ~excepts;
  fpcr |= (*flagp & excepts);
  __asm__ __volatile__("msr fpcr, %0" : : "r" (fpcr));
#else
  __asm__ __volatile__("fnstenv %0;" : "=m" (_env));
  _env.__status_word &= ~excepts;
  _env.__status_word |= (*flagp & excepts);
  __asm__ __volatile__("fldenv %0;" : : "m" (_env));

  int sse_cw;
  __asm__ __volatile__("stmxcsr %0;" : "=m" (sse_cw));
  sse_cw &= ~(excepts << 7);
  sse_cw |= ((*flagp & excepts) << 7);
  __asm__ __volatile__("ldmxcsr %0" : : "m" (sse_cw));

#endif  /* defined(__aarch64__) || defined(_ARM64_) */
  return 0;
}

int __cdecl (*__MINGW_IMP_SYMBOL(fesetexceptflag))(const fexcept_t *, int) = fesetexceptflag;
