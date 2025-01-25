/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _SSP_INC_STRING
#define _SSP_INC_STRING

#include <ssp/ssp.h>

__MINGW_BEGIN_C_DECLS

#if __MINGW_FORTIFY_LEVEL > 0

  __mingw_bos_extern_ovr __NONNULL((1, 2))
  __NTH_FNC(char *strcpy(char *__restrict _Dest, const char *__restrict _Source))
  {
    return __builtin___strcpy_chk(_Dest, _Source, __mingw_bos(_Dest, 1));
  }

  __mingw_bos_extern_ovr __NONNULL((1, 2))
  __NTH_FNC(char *strcat(char *__restrict _Dest, const char *__restrict _Source))
  {
    return __builtin___strcat_chk(_Dest, _Source, __mingw_bos(_Dest, 1));
  }

  __mingw_bos_extern_ovr __NONNULL((1, 2))
  __NTH_FNC(char *strncat(char *__restrict _Dest, const char *__restrict _Source, size_t _Count))
  {
    return __builtin___strncat_chk(_Dest, _Source, _Count, __mingw_bos(_Dest, 1));
  }

  __mingw_bos_extern_ovr __NONNULL((1, 2))
  __NTH_FNC(char *strncpy(char *__restrict _Dest, const char *__restrict _Source, size_t _Count))
  {
    return __builtin___strncpy_chk(_Dest, _Source, _Count, __mingw_bos(_Dest, 1));
  }

#ifdef __MINGW_USE_MISC
  __mingw_bos_extern_ovr __NONNULL((1, 2))
  __NTH_FNC(void *mempcpy(void *__restrict _Dest, const void *__restrict _Source, size_t _Size))
  {
    return __builtin___mempcpy_chk(_Dest, _Source, _Size, __mingw_bos(_Dest, 0));
  }
#endif

#ifdef __MINGW_USE_XOPEN2K8
  __mingw_bos_extern_ovr __NONNULL((1, 2))
  __NTH_FNC(char *stpcpy(char *__restrict _Dest, const char *__restrict _Source))
  {
    return __builtin___stpcpy_chk(_Dest, _Source, __mingw_bos(_Dest, 1));
  }
#endif

#endif  /* __MINGW_FORTIFY_LEVEL > 0 */

__MINGW_END_C_DECLS

#endif  /* _SSP_INC_STRING */
