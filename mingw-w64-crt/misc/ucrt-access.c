/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <windows.h>
#include <errno.h>
#include <io.h>

/* On UCRT, unconditionally forward access to __mingw_access. UCRT's
 * access() function return an error if passed the X_OK constant,
 * while msvcrt.dll's access() doesn't. (It's reported that msvcrt.dll's
 * access() also returned errors on X_OK in the version shipped in Vista,
 * but in recent tests it's no longer the case.) */

int __cdecl access(const char *fname, int mode)
{
  DWORD attr;

  if (fname == NULL || (mode & ~(F_OK | X_OK | W_OK | R_OK)))
  {
    errno = EINVAL;
    return -1;
  }

  attr = GetFileAttributesA(fname);
  if (attr == INVALID_FILE_ATTRIBUTES)
  {
    switch (GetLastError())
    {
      case ERROR_FILE_NOT_FOUND:
      case ERROR_PATH_NOT_FOUND:
        errno = ENOENT;
        break;
      case ERROR_ACCESS_DENIED:
        errno = EACCES;
        break;
      default:
        errno = EINVAL;
    }
    return -1;
  }

  if (attr & FILE_ATTRIBUTE_DIRECTORY)
  {
    /* All directories have read & write access */
    return 0;
  }

  if ((attr & FILE_ATTRIBUTE_READONLY) && (mode & W_OK))
  {
    /* no write permission on file */
    errno = EACCES;
    return -1;
  }
  else
    return 0;
}

int __cdecl (*__MINGW_IMP_SYMBOL(access))(const char *fname, int mode) = access;