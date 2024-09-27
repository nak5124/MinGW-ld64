/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <stdio.h>

// This is called for wchar cases with __USE_MINGW_ANSI_STDIO enabled (where the
// char case just uses fputc).
int __cdecl __ms_fwprintf(FILE *__restrict file, const wchar_t *__restrict fmt, ...)
{
  __builtin_va_list ap;
  int ret;
  __builtin_va_start(ap, fmt);
  ret = __stdio_common_vfwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_LEGACY_WIDE_SPECIFIERS, file, fmt, NULL, ap);
  __builtin_va_end(ap);
  return ret;
}
int __cdecl (*__MINGW_IMP_SYMBOL(__ms_fwprintf))(FILE *__restrict, const wchar_t *__restrict, ...) = __ms_fwprintf;
