/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _DEFAULT_SOURCE
#include <string.h>

size_t __cdecl strlcpy(char *__restrict _Dest, const char *__restrict _Src, size_t _N)
{
    size_t slen = strlen(_Src);
    if(_N == 0)
    {
        return slen;
    }

    if(_N > slen)
    {
        memcpy(_Dest, _Src, slen + 1);
    }
    else
    {
        memcpy(_Dest, _Src, _N);
        _Dest[_N - 1] = '\0';
    }
    return slen;
}
