/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define __CRT__NO_INLINE
#include <stdio.h>

int __cdecl vwscanf(const wchar_t *__restrict _Format, va_list _ArgList)
{
    return __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, stdin, _Format, NULL, _ArgList);
}

int __cdecl (*__MINGW_IMP_SYMBOL(vwscanf))(const wchar_t *__restrict _Format, va_list _ArgList) = vwscanf;