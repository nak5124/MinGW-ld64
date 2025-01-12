/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _MS_SOURCE
#include <string.h>

int __cdecl __xsi_strerror_r(int _Errnum, char *_Buf, size_t _Buflen);

int __cdecl __xsi_strerror_r(int _Errnum, char *_Buf, size_t _Buflen)
{
    return strerror_s(_Buf, _Buflen, _Errnum);
}
