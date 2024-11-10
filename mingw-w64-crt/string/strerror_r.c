/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _GNU_SOURCE
#include <string.h>

char *__cdecl strerror_r(int _Errnum, char *_Buf, size_t _Buflen)
{
    errno_t err = strerror_s(_Buf, _Buflen, _Errnum);
    if(err != 0)
    {
        return NULL;
    }
    return _Buf;
}
