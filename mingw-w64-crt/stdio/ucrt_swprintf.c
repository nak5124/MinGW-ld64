/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define __CRT__NO_INLINE
#include <stdio.h>

int __cdecl swprintf(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, ...)
{
    __builtin_va_list _ArgList;
    int _Ret;
    /*
     * __stdio_common_vswprintf() for case _Buffer == NULL and _BufferCount == 0 and
     * without _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR option, is
     * executed in "standard snprintf behavior" and returns number of (wide)
     * chars required to allocate. For all other cases it is executed in a way
     * that returns negative value on error. But C95+ compliant swprintf() for
     * case _BufferCount == 0 returns negative value, so handle this case specially.
     */
    if(_Buffer == NULL && _BufferCount == 0)
    {
      return -1;
    }
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
}

int __cdecl (*__MINGW_IMP_SYMBOL(swprintf))(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, ...) = swprintf;
