/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _POSIX_C_SOURCE 200112L
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int __cdecl setenv(const char *_Name, const char *_Value, int _Overwrite)
{
    if(!_Name || *_Name == '\0' || strchr(_Name, '=') != NULL)
    {
        errno = EINVAL;
        return -1;
    }

    if(!_Overwrite && getenv(_Name) != NULL)
    {
        return 0;
    }

    if(_putenv_s(_Name, _Value) != 0)
    {
        errno = EINVAL;
        return -1;
    }

    return 0;
}
