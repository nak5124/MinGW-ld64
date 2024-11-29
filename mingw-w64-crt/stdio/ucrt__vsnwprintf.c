/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define __CRT__NO_INLINE
#include <stdio.h>

int __cdecl _vsnwprintf(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, va_list _ArgList)
{
    int _Ret;
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
}

int __cdecl (*__MINGW_IMP_SYMBOL(_vsnwprintf))(wchar_t *__restrict, size_t, const wchar_t *__restrict, va_list) = _vsnwprintf;
