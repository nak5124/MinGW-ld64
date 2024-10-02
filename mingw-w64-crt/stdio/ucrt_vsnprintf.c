/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define __CRT__NO_INLINE
#include <stdio.h>

int __cdecl vsnprintf (char * __restrict __stream, size_t __n, const char * __restrict __format, va_list __local_argv)
{
  int ret;
  ret = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, __stream, __n, __format, NULL, __local_argv);
  return ret < 0 ? -1 : ret;
}
int __cdecl (*__MINGW_IMP_SYMBOL(vsnprintf))(char *__restrict, size_t, const char *__restrict, va_list) = vsnprintf;
