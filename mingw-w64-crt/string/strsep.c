/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <string.h>

char *__cdecl strsep(char **__restrict _Stringp, const char *__restrict _Delim)
{
    char *str = *_Stringp;
    char *p;

    if(!str)
    {
        return NULL;
    }

    p = strpbrk(str, _Delim);
    if(p)
    {
        *p        = '\0';
        *_Stringp = p + 1;
    }
    else
    {
        *_Stringp = NULL;
    }

    return str;
}
