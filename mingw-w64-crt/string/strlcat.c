/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _DEFAULT_SOURCE
#define _MS_SOURCE
#include <string.h>

size_t __cdecl strlcat(char *__restrict _Dest, const char *__restrict _Src, size_t _N)
{
    size_t slen = strlen(_Src);
    if(_N == 0)
    {
        return slen;
    }

    size_t dlen = strnlen(_Dest, _N);
    if(dlen != _N)
    {
        char  *dst  = _Dest + dlen;
        size_t tlen = _N - dlen - 1;
        if(tlen > slen)
        {
            tlen = slen;
        }
        memcpy(dst, _Src, tlen);
        dst[tlen] = '\0';
    }
    return dlen + slen;
}
