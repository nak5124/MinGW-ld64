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

static char *__cdecl realpatha(const char *__restrict _Path, char *__restrict _Resolved_path)
{
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

char *__cdecl wrealpath(const char *__restrict _Path, char *__restrict _Resolved_path)
{
    if(!_Path)
    {
        errno = EINVAL;
        return NULL;
    }

    int len0 = MultiByteToWideChar(CP_THREAD_ACP, 0, _Path, -1, NULL, 0);
    wchar_t *wpath = (wchar_t *)malloc(len0 * sizeof(wchar_t));
    int len1 = MultiByteToWideChar(CP_THREAD_ACP, 0, _Path, -1, wpath, len0);
    if(len0 != len1)
    {
        free(wpath);
        return realpatha(_Path, _Resolved_path);
    }
    else
    {
        if(!PathFileExistsW(wpath))
        {
            errno = ENOENT;
            return NULL;
        }
        wchar_t wbuf[32767 * 2];
        DWORD retval = GetFullPathNameW(wpath, 32767 * 2, wbuf, NULL);
        free(wpath);

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
        else
        {
            char abuf[32767 * 4];
            len0 = WideCharToMultiByte(CP_THREAD_ACP, 0, wbuf, -1, NULL, 0, NULL, NULL);
            len1 = WideCharToMultiByte(CP_THREAD_ACP, 0, wbuf, -1, abuf, len0, NULL, NULL);
            if(len0 != len1)
            {
                return realpatha(_Path, _Resolved_path);
            }
            else if(!_Resolved_path)
            {
                _Resolved_path = (char *)malloc(len0);
                if(!_Resolved_path)
                {
                    errno = ENOMEM;
                    return NULL;
                }
            }
            strcpy(_Resolved_path, abuf);
        }
    }

    return _Resolved_path;
}
