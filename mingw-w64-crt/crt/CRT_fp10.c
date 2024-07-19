/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

void _fpreset (void);

void _fpreset (void)
{
#if defined(__aarch64__) || defined(_ARM64_)
  __asm__ __volatile__ (
    "msr	fpcr, %0\n\t" : : "r"(0LL /* INITIAL_FPSCR */));
#else
  __asm__ ("fninit");
#endif
}

void __attribute__ ((alias ("_fpreset"))) fpreset(void);
