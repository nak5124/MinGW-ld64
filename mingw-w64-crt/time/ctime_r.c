/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _XOPEN_SOURCE
#define __STDC_WANT_LIB_EXT1__ 1
#define __CRT__NO_INLINE
#include <time.h>
#include <errno.h>

char *__cdecl ctime_r(const time_t *__restrict _Time, char *__restrict _Buf)
{
    errno_t ret = _ctime64_s(_Buf, 26, _Time);
    if(ret == 0)
    {
        return _Buf;
    }
    errno = ret;
    return NULL;
}
