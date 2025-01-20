/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _POSIX_C_SOURCE 202405L
#include <wchar.h>

size_t __cdecl wcslcpy(wchar_t *__restrict _Dest, const wchar_t *__restrict _Src, size_t _N)
{
    size_t slen = wcslen(_Src);
    if(_N == 0)
    {
        return slen;
    }

    if(_N > slen)
    {
        wmemcpy(_Dest, _Src, slen + 1);
    }
    else
    {
        wmemcpy(_Dest, _Src, _N);
        _Dest[_N - 1] = '\0';
    }
    return slen;
}
