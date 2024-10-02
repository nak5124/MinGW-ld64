/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define __CRT__NO_INLINE
#include <stdio.h>

int __cdecl vsscanf (const char * __restrict __source, const char * __restrict __format, __builtin_va_list __local_argv) {
  return __stdio_common_vsscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, __source, (size_t)-1, __format, NULL, __local_argv);
}
int __cdecl (*__MINGW_IMP_SYMBOL(vsscanf))(const char *__restrict, const char *__restrict, __builtin_va_list) = vsscanf;
