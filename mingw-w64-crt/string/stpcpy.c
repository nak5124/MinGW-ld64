/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _POSIX_C_SOURCE 200809L
#include <string.h>

char *__cdecl stpcpy(char *_Dest, const char *_Src)
{
    size_t len = strlen(_Src);
    return memcpy(_Dest, _Src, len + 1) + len;
}
