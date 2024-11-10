/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _XOPEN_SOURCE 700
#include <string.h>
#include <stdlib.h>

char *__cdecl strndup(const char *_Src, size_t _Size)
{
    size_t len = strnlen(_Src, _Size);
    char *dest = (char *)malloc(len + 1);

    if(dest == NULL)
    {
        return NULL;
    }

    memcpy(dest, _Src, len);
    dest[len] = '\0';
    return dest;
}
