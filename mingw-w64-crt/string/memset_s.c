/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define __STDC_WANT_SECURE_LIB__ 1
#include <string.h>
#include <errno.h>
#include <limits.h>

errno_t __cdecl memset_s(void *_Dest, rsize_t _Destsz, int _Ch, rsize_t _Count)
{
    errno_t ret = EINVAL;
    if(_Dest == NULL)
    {
        errno = ret;
        return ret;
    }
    else if(_Destsz > RSIZE_MAX)
    {
        errno = ret;
        return ret;
    }
    else if(_Count > RSIZE_MAX)
    {
        errno = ret;
        return ret;
    }
    else
    {
        memset(_Dest, _Ch, _Count < _Destsz ? _Count : _Destsz);
        __asm__ __volatile__("" : : : "memory");
        if(_Count > _Destsz)
        {
            errno = ret;
            return ret;
        }
        else
        {
            ret = 0;
        }
    }
    return ret;
}
