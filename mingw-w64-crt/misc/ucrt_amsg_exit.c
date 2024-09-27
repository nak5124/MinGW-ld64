/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <stdio.h>
#include <stdlib.h>
#include <internal.h>

extern void (*__MINGW_IMP_SYMBOL(_exit))(int) __MINGW_NORETURN;

__MINGW_NORETURN
void __cdecl _amsg_exit(int ret)
{
  fprintf(stderr, "runtime error %d\n", ret);
  (*__MINGW_IMP_SYMBOL(_exit))(255);
}
void __cdecl (*__MINGW_IMP_SYMBOL(_amsg_exit))(int) = _amsg_exit;
