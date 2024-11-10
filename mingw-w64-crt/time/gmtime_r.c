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

struct tm *__cdecl gmtime_r(const time_t *__restrict _Time, struct tm *__restrict _Tm)
{
    errno_t ret = _gmtime64_s(_Tm, _Time);
    if(ret == 0)
    {
        return _Tm;
    }
    errno = ret;
    return NULL;
}
