/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _POSIX_C_SOURCE 202405L
#include <wchar.h>

size_t __cdecl wcslcat(wchar_t *__restrict _Dest, const wchar_t *__restrict _Src, size_t _N)
{
    size_t slen = wcslen(_Src);
    if(_N == 0)
    {
        return slen;
    }

    size_t dlen = wcsnlen(_Dest, _N);
    if(dlen != _N)
    {
        wchar_t *dst  = _Dest + dlen;
        size_t   tlen = _N - dlen - 1;
        if(tlen > slen)
        {
            tlen = slen;
        }
        wmemcpy(dst, _Src, tlen);
        dst[tlen] = '\0';
    }
    return dlen + slen;
}
