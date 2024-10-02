/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define __CRT__NO_INLINE
#include <stdio.h>

int __cdecl printf(const char * __restrict _Format,...)
{
  __builtin_va_list ap;
  int ret;
  __builtin_va_start(ap, _Format);
  ret = __stdio_common_vfprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, NULL, ap);
  __builtin_va_end(ap);
  return ret;
}
int __cdecl (*__MINGW_IMP_SYMBOL(printf))(const char *__restrict, ...) = printf;
