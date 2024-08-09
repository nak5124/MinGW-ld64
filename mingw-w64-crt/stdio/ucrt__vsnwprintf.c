/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#undef __MSVCRT_VERSION__
#define _UCRT
#include <stdio.h>

int __cdecl _vsnwprintf(wchar_t * __restrict__ _Dest,size_t _Count,const wchar_t * __restrict__ _Format,va_list _Args) __MINGW_DEPRECATED_SEC_WARN
{
  int ret;
  ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _Dest, _Count, _Format, NULL, _Args);
  return ret < 0 ? -1 : ret;
}
int __cdecl (*__MINGW_IMP_SYMBOL(_vsnwprintf))(wchar_t *__restrict__, size_t, const wchar_t *__restrict__, va_list) = _vsnwprintf;
