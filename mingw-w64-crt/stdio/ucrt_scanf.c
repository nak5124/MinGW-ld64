/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define __CRT__NO_INLINE
#include <stdio.h>

int __cdecl scanf(const char * __restrict _Format,...) {
  __builtin_va_list __ap;
  int __ret;
  __builtin_va_start(__ap, _Format);
  __ret = __stdio_common_vfscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, stdin, _Format, NULL, __ap);
  __builtin_va_end(__ap);
  return __ret;
}
int __cdecl (*__MINGW_IMP_SYMBOL(scanf))(const char *__restrict, ...) = scanf;
