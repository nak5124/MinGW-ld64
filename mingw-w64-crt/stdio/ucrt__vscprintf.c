/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdio.h>

int __cdecl _vscprintf(const char * __restrict _Format, va_list _ArgList)
{
  int ret;
  ret = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, NULL, _ArgList);
  return ret < 0 ? -1 : ret;
}
int __cdecl (*__MINGW_IMP_SYMBOL(_vscprintf))(const char *__restrict, va_list) = _vscprintf;
