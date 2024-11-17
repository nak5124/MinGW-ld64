/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _DEFAULT_SOURCE
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#define WIN32_LEAN_AND_MEAN
#define NOSERVICE
#define NOMCX
#define NOIME
#include <windows.h>
#include <shlwapi.h>

char *__cdecl realpath(const char *__restrict _Path, char *__restrict _Resolved_path)
{
    if(!_Path)
    {
        errno = EINVAL;
        return NULL;
    }

    if(!PathFileExistsA(_Path))
    {
        errno = ENOENT;
        return NULL;
    }

    char buf[MAX_PATH * 4];
    DWORD retval = GetFullPathNameA(_Path, MAX_PATH * 4, !_Resolved_path ? buf : _Resolved_path, NULL);

    if(retval == 0)
    {
        if(GetLastError() == ERROR_FILENAME_EXCED_RANGE)
        {
            errno = ENAMETOOLONG;
            return NULL;
        }
        else
        {
            errno = EIO;
            return NULL;
        }
    }
    else if(!_Resolved_path)
    {
        _Resolved_path = (char *)malloc(retval + 1);
        if(!_Resolved_path)
        {
            errno = ENOMEM;
            return NULL;
        }
        else
        {
            strcpy(_Resolved_path, buf);
        }
    }

    return _Resolved_path;
}
