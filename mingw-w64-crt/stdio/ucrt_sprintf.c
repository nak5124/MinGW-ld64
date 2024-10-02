/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define __CRT__NO_INLINE
#include <stdio.h>

int __cdecl sprintf(char * __restrict _Dest,const char * __restrict _Format,...) __MINGW_DEPRECATED_SEC_WARN
{
  __builtin_va_list ap;
  int ret;
  __builtin_va_start(ap, _Format);
  ret = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, _Dest, (size_t)-1, _Format, NULL, ap);
  __builtin_va_end(ap);
  return ret < 0 ? -1 : ret;
}
int __cdecl (*__MINGW_IMP_SYMBOL(sprintf))(char *__restrict, const char *__restrict, ...) = sprintf;
