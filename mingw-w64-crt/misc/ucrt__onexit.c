/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#undef __MSVCRT_VERSION__
#define _UCRT

#include <stdlib.h>
#include <corecrt_startup.h>

_onexit_t __cdecl _onexit(_onexit_t func)
{
  return _crt_atexit((_PVFV)func) == 0 ? func : NULL;
}
_onexit_t __cdecl (*__MINGW_IMP_SYMBOL(_onexit))(_onexit_t func) = _onexit;

onexit_t __attribute__ ((alias ("_onexit"))) __cdecl onexit(onexit_t func);
extern onexit_t __attribute__ ((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(_onexit)))))
(__cdecl *__MINGW_IMP_SYMBOL(onexit))(onexit_t func);
