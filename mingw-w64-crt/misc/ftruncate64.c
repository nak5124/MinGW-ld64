#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <errno.h>
#define WIN32_LEAN_AND_MEAN
#define NOSERVICE
#define NOMCX
#define NOIME
#include <windows.h>

static int checkfreespace(const HANDLE f, const ULONGLONG requiredspace)
{
  ULARGE_INTEGER freespace;
  LARGE_INTEGER  currentsize;
  DWORD          check;

  /* Get current size */
  if(!GetFileSizeEx(f, &currentsize))
  {
    /* Error checking file size */
    errno = EBADF;
    return -1;
  }

  /* Short circuit disk space check if shrink operation */
  if((ULONGLONG)currentsize.QuadPart >= requiredspace)
  {
    return 0;
  }

  /* Get path length */
  WCHAR filepath[MAX_PATH];
  check = GetFinalPathNameByHandleW(f, filepath, MAX_PATH, FILE_NAME_NORMALIZED);
  if(!check)
  {
    /* Error resolving filename */
    errno = EBADF;
    return -1;
  }

  WCHAR volpath[check + 1];
  if(!GetVolumePathNameW(filepath, volpath, check + 1))
  {
    errno = EBADF;
    return -1;
  }

  /* Get available free space */
  check = GetDiskFreeSpaceExW(volpath, &freespace, NULL, NULL);
  if(!check)
  {
    /* Error getting free space */
    errno = EFBIG;
    return -1;
  }

  /* Check space requirements */
  if((requiredspace - currentsize.QuadPart) > freespace.QuadPart)
  {
    /* File too big for disk */
    errno = EFBIG;
    return -1;
  }

  /* We have enough space to truncate/expand */
  return 0;
}

int __cdecl ftruncate64(int __fd, _off64_t __length)
{
  HANDLE        f;
  LARGE_INTEGER quad;
  DWORD         check;

  int     ret = 0;
  __int64 pos;

  /* Sanity check */
  if(__length < 0)
  {
    errno = EINVAL;
    return -1;
  }

  f = (HANDLE)_get_osfhandle(__fd);
  if(f == INVALID_HANDLE_VALUE)
  {
    /* errno is set by _get_osfhandle: EBADF */
    return -1;
  }
  if((GetFileType(f) != FILE_TYPE_DISK))
  {
    errno = EINVAL;
    return -1;
  }

  /* Save position */
  if((pos = _telli64(__fd)) == -1LL)
  {
    errno = EINVAL;
    return -1;
  }

  /* Check available space */
  check = checkfreespace(f, __length);
  if(check != 0)
  {
    /* Error, errno already set */
    return -1;
  }

  quad.QuadPart = __length;
  check = SetFilePointerEx(f, quad, NULL, FILE_BEGIN);
  if(!check)
  {
    switch (GetLastError())
    {
      case ERROR_NEGATIVE_SEEK:
        /* file too big? */
        errno = EFBIG;
        return -1;
      case INVALID_SET_FILE_POINTER:
        /* shouldn't happen */
        errno = EINVAL;
        return -1;
      default:
        /* shouldn't happen */
        errno = EINVAL;
        return -1;
    }
  }

  check = SetEndOfFile(f);
  if(!check)
  {
    errno = EINVAL;
    return -1;
  }

  if(_lseeki64(__fd, pos, SEEK_SET) == -1LL)
  {
    errno = EINVAL;
    return -1;
  }

  return ret;
}
