/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_UTIME
#define _INC_UTIME

#ifndef _WIN32
# error Only Win32 target is supported!
#endif

#include <corecrt.h>

__MINGW_BEGIN_C_DECLS

#ifndef _UTIMBUF_DEFINED
# define _UTIMBUF_DEFINED
  struct _utimbuf
  {
    time_t actime;
    time_t modtime;
  };

  struct __utimbuf32
  {
    __time32_t actime;
    __time32_t modtime;
  };

  struct __utimbuf64
  {
    __time64_t actime;
    __time64_t modtime;
  };

  struct utimbuf
  {
    time_t actime;
    time_t modtime;
  };

  struct utimbuf32
  {
    __time32_t actime;
    __time32_t modtime;
  };
#endif

  _CRTIMP int __cdecl _utime32(const char *_Filename, struct __utimbuf32 *_Time)     __MINGW_NONNULL((1));
  _CRTIMP int __cdecl _futime32(int _FileDes, struct __utimbuf32 *_Time);
  _CRTIMP int __cdecl _wutime32(const wchar_t *_Filename, struct __utimbuf32 *_Time) __MINGW_NONNULL((1));
  _CRTIMP int __cdecl _utime64(const char *_Filename, struct __utimbuf64 *_Time)     __MINGW_NONNULL((1));
  _CRTIMP int __cdecl _futime64(int _FileDes, struct __utimbuf64 *_Time);
  _CRTIMP int __cdecl _wutime64(const wchar_t *_Filename, struct __utimbuf64 *_Time) __MINGW_NONNULL((1));

  int __cdecl _utime(const char *_Filename, struct _utimbuf *_Time)     __MINGW_ASM_CALL(_utime64)  __MINGW_NONNULL((1));
  int __cdecl _futime(int _FileDes, struct _utimbuf *_Time)             __MINGW_ASM_CALL(_futime64);
  int __cdecl _wutime(const wchar_t *_Filename, struct _utimbuf *_Time) __MINGW_ASM_CALL(_wutime64) __MINGW_NONNULL((1));
  int __cdecl  utime(const char *_Filename, struct utimbuf *_Time)      __MINGW_ASM_CALL(_utime64)  __MINGW_NONNULL((1));

__MINGW_END_C_DECLS

#endif  /* _INC_UTIME */
