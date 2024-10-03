/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

// For ucrt, this function normally is an inline function in stdio.h.
// libmingwex doesn't use the ucrt version of headers, and wassert.c can
// end up requiring a concrete version of it.

#define __CRT__NO_INLINE
#include <stdio.h>

int __cdecl fwprintf(FILE *__restrict ptr, const wchar_t *__restrict fmt, ...)
{
  __builtin_va_list ap;
  int ret;
  __builtin_va_start(ap, fmt);
  ret = __stdio_common_vfwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, ptr, fmt, NULL, ap);
  __builtin_va_end(ap);
  return ret;
}

int __cdecl (*__MINGW_IMP_SYMBOL(fwprintf))(FILE *__restrict, const wchar_t *__restrict, ...) = fwprintf;
