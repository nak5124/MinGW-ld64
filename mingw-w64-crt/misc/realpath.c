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

static char *__cdecl realpatha(const char *__restrict _Path, char *__restrict _Resolved_path)
{
    HANDLE hFile = CreateFileA(_Path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if(hFile == INVALID_HANDLE_VALUE)
    {
        DWORD err = GetLastError();
        if(err == ERROR_FILE_NOT_FOUND)
        {
            errno = ENOENT;
            return NULL;
        }
        else if(err == ERROR_FILENAME_EXCED_RANGE)
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

    char buf[MAX_PATH * 4];
    DWORD retval = GetFinalPathNameByHandleA(hFile, buf, MAX_PATH * 4, FILE_NAME_NORMALIZED | VOLUME_NAME_DOS);
    CloseHandle(hFile);
    if(retval == 0)
    {
        DWORD err = GetLastError();
        if(err == ERROR_PATH_NOT_FOUND)
        {
            errno = ENOENT;
            return NULL;
        }
        else if(err == ERROR_NOT_ENOUGH_MEMORY)
        {
            errno = ENOMEM;
            return NULL;
        }
        else
        {
            errno = EIO;
            return NULL;
        }
    }

    if(!_Resolved_path)
    {
        _Resolved_path = (char *)malloc(retval - 4);
        if(!_Resolved_path)
        {
            errno = ENOMEM;
            return NULL;
        }
    }
    strcpy(_Resolved_path, buf + 4);

    return _Resolved_path;
}

char *__cdecl realpath(const char *__restrict _Path, char *__restrict _Resolved_path)
{
    if(!_Path)
    {
        errno = EINVAL;
        return NULL;
    }

    int      len0  = MultiByteToWideChar(CP_THREAD_ACP, 0, _Path, -1, NULL, 0);
    wchar_t *wpath = (wchar_t *)malloc(len0 * sizeof(wchar_t));
    int      len1  = MultiByteToWideChar(CP_THREAD_ACP, 0, _Path, -1, wpath, len0);
    if(len0 != len1)
    {
        free(wpath);
        return realpatha(_Path, _Resolved_path);
    }

    CREATEFILE2_EXTENDED_PARAMETERS extendedParams = { 0 };
    extendedParams.dwSize           = sizeof(CREATEFILE2_EXTENDED_PARAMETERS);
    extendedParams.dwFileAttributes = FILE_ATTRIBUTE_NORMAL;
    HANDLE hFile = CreateFile2(wpath, GENERIC_READ, FILE_SHARE_READ, OPEN_EXISTING, &extendedParams);
    free(wpath);
    if(hFile == INVALID_HANDLE_VALUE)
    {
        DWORD err = GetLastError();
        if(err == ERROR_FILE_NOT_FOUND)
        {
            errno = ENOENT;
            return NULL;
        }
        else if(err == ERROR_FILENAME_EXCED_RANGE)
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

    wchar_t wbuf[32767 * 2];
    DWORD retval = GetFinalPathNameByHandleW(hFile, wbuf, 32767 * 2, FILE_NAME_NORMALIZED | VOLUME_NAME_DOS);
    CloseHandle(hFile);
    if(retval == 0)
    {
        DWORD err = GetLastError();
        if(err == ERROR_PATH_NOT_FOUND)
        {
            errno = ENOENT;
            return NULL;
        }
        if(err == ERROR_NOT_ENOUGH_MEMORY)
        {
            errno = ENOMEM;
            return NULL;
        }
        else
        {
            errno = EIO;
            return NULL;
        }
    }

    char abuf[32767 * 4];
    len0 = WideCharToMultiByte(CP_THREAD_ACP, 0, wbuf, -1, NULL, 0, NULL, NULL);
    len1 = WideCharToMultiByte(CP_THREAD_ACP, 0, wbuf, -1, abuf, len0, NULL, NULL);
    if(len0 != len1)
    {
        return realpatha(_Path, _Resolved_path);
    }

    if(!_Resolved_path)
    {
        _Resolved_path = (char *)malloc(len0 - 4);
        if(!_Resolved_path)
        {
            errno = ENOMEM;
            return NULL;
        }
    }
    strcpy(_Resolved_path, abuf + 4);

    return _Resolved_path;
}
