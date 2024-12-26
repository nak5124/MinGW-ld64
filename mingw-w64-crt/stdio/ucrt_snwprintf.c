/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define __CRT__NO_INLINE
#include <stdio.h>

int __cdecl snwprintf(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, ...)
{
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
}

int __cdecl (*__MINGW_IMP_SYMBOL(snwprintf))(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, ...) = snwprintf;
