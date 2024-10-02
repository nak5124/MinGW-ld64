/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>
#ifdef __USING_MCFGTHREAD__
#include <mcfgthread/exit.h>
#endif

/* `quick_exit()`, C99  */
void quick_exit(int status) __MINGW_NORETURN;
extern void (*__MINGW_IMP_SYMBOL(quick_exit))(int) __MINGW_NORETURN;

void quick_exit(int status)
{
#ifdef __USING_MCFGTHREAD__
  __MCF_quick_exit(status);
#else
  (*__MINGW_IMP_SYMBOL(quick_exit))(status);
#endif
}

/* `_Exit()`, C99  */
void _Exit(int status) __MINGW_NORETURN;
extern void (*__MINGW_IMP_SYMBOL(_Exit))(int) __MINGW_NORETURN;

void _Exit(int status)
{
#ifdef __USING_MCFGTHREAD__
  __MCF__Exit(status);
#else
  (*__MINGW_IMP_SYMBOL(_Exit))(status);
#endif
}
