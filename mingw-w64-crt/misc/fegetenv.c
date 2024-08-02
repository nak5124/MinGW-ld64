/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <fenv.h>

#if defined(__x86_64__) || defined(_AMD64_)
int __mingw_has_sse (void);
#endif  /* defined(__x86_64__) || defined(_AMD64_) */

/* 7.6.4.1
   The fegetenv function stores the current floating-point environment
   in the object pointed to by envp.  */

int __cdecl fegetenv (fenv_t * envp)
{
#if defined(__aarch64__) || defined(_ARM64_)
  unsigned __int64 fpcr;
  __asm__ volatile ("mrs %0, fpcr" : "=r" (fpcr));
  envp->__cw = fpcr;
#else
  __asm__ __volatile__ ("fnstenv %0;": "=m" (*envp));
 /* fnstenv sets control word to non-stop for all exceptions, so we
    need to reload our env to restore the original mask.  */
  __asm__ __volatile__ ("fldenv %0" : : "m" (*envp));
  if (__mingw_has_sse ())
    {
      int _mxcsr;
      __asm__ __volatile__ ("stmxcsr %0" : "=m" (_mxcsr));
      envp->__unused0 = (((unsigned int) _mxcsr) >> 16);
      envp->__unused1 = (((unsigned int) _mxcsr) & 0xffff);
    }
#endif  /* defined(__aarch64__) || defined(_ARM64_) */
  return 0;
}

int __cdecl (*__MINGW_IMP_SYMBOL(fegetenv))(fenv_t *) = fegetenv;
