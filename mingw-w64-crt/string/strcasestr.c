/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _DEFAULT_SOURCE
#include <string.h>

char *strcasestr(const char *_Haystack, const char *_Needle)
{
    size_t l = strlen(_Needle);
    for(; *_Haystack; _Haystack++)
    {
        if(!_strnicmp(_Haystack, _Needle, l))
        {
            return (char *)_Haystack;
        }
    }
    return NULL;
}
