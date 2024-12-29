/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _ISOC23_SOURCE
#include <time.h>
#define WIN32_LEAN_AND_MEAN
#define NOSERVICE
#define NOMCX
#define NOIME
#include <windows.h>

int __cdecl timespec_getres(struct timespec *_Ts, int _Base)
{
    if(_Base == TIME_UTC)
    {
        LARGE_INTEGER pf;
        QueryPerformanceFrequency(&pf);
        _Ts->tv_sec = 0;
        _Ts->tv_nsec = (int)((1000000000 + (pf.QuadPart >> 1)) / pf.QuadPart);
        if(_Ts->tv_nsec < 1)
        {
            _Ts->tv_nsec = 1;
        }
        return _Base;
    }
    return 0;
}
