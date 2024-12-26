/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define __CRT__NO_INLINE
#include <stdio.h>

int __cdecl swscanf(const wchar_t *__restrict _Buffer, const wchar_t *__restrict _Format, ...)
{
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Buffer, (size_t)-1, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
}

int __cdecl (*__MINGW_IMP_SYMBOL(swscanf))(const wchar_t *__restrict _Buffer, const wchar_t *__restrict _Format, ...) = swscanf;
