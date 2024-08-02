/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <fenv.h>

#if defined(__x86_64__) || defined(_AMD64_)
int __mingw_has_sse (void);

int __mingw_has_sse(void)
{
  int cpuInfo[4],infoType = 1;

  __asm__ __volatile__ (
    "cpuid"
    : "=a" (cpuInfo[0]), "=b" (cpuInfo[1]), "=c" (cpuInfo[2]),
    "=d" (cpuInfo[3])
    : "a" (infoType));
  if (cpuInfo[3] & 0x2000000)
    return 1;
  return 0;
}
#endif  /* defined(__x86_64__) || defined(_AMD64_) */

/* 7.6.2.1
   The feclearexcept function clears the supported exceptions
   represented by its argument.  */

int __cdecl feclearexcept (int excepts)
{
  fenv_t _env;
#if defined(__aarch64__) || defined(_ARM64_)
  unsigned __int64 fpcr;
  (void) _env;
  __asm__ volatile ("mrs %0, fpcr" : "=r" (fpcr));
  fpcr &= ~(excepts & FE_ALL_EXCEPT);
  __asm__ volatile ("msr fpcr, %0" : : "r" (fpcr));
#else
  int _mxcsr;
  if (excepts == FE_ALL_EXCEPT)
    {
      __asm__ volatile ("fnclex");
    }
  else
    {
      __asm__ volatile ("fnstenv %0" : "=m" (_env));
      _env.__status_word &= ~(excepts & FE_ALL_EXCEPT);
      __asm__ volatile ("fldenv %0" : : "m" (_env));
    }
  if (__mingw_has_sse ())
    {
      __asm__ volatile ("stmxcsr %0" : "=m" (_mxcsr));
      _mxcsr &= ~(((excepts & FE_ALL_EXCEPT)));
      __asm__ volatile ("ldmxcsr %0" : : "m" (_mxcsr));
    }
#endif  /* defined(__aarch64__) || defined(_ARM64_) */
  return (0);
}

int __cdecl (*__MINGW_IMP_SYMBOL(feclearexcept))(int) = feclearexcept;
