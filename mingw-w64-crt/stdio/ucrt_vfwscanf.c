/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define __CRT__NO_INLINE
#include <stdio.h>

int __cdecl vfwscanf(FILE *__restrict _Stream, const wchar_t *__restrict _Format, va_list _ArgList)
{
    return __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Stream, _Format, NULL, _ArgList);
}

int __cdecl (*__MINGW_IMP_SYMBOL(vfwscanf))(FILE *__restrict _Stream, const wchar_t *__restrict _Format, va_list _ArgList) = vfwscanf;
