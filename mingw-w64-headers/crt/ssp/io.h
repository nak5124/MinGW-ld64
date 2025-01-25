/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _SSP_INC_IO
#define _SSP_INC_IO

#include <ssp/ssp.h>
#include <fcntl.h>

#ifndef __HAS__O_CREAT
# define __HAS__O_CREAT(flag) (__builtin_constant_p(flag & _O_CREAT) && (flag & _O_CREAT))
#endif

__MINGW_BEGIN_C_DECLS

#if __MINGW_FORTIFY_LEVEL > 0

  _CRTIMP int __cdecl __mingw_call__read(int _FileHandle, void *_DstBuf, unsigned int _MaxCharCount) __ASM_CRT_CALL(_read) __WUR_FORTIFY;

  __mingw_bos_extern_ovr __WUR_FORTIFY
  int _read(int _FileHandle, void *_DstBuf, unsigned int _MaxCharCount)
  {
    __mingw_bos_ptr_chk_warn(_DstBuf, _MaxCharCount, 0);
    return __mingw_call__read(_FileHandle, _DstBuf, _MaxCharCount);
  }

  __mingw_bos_extern_ovr __WUR_FORTIFY
  int read(int _FileHandle, void *_DstBuf, unsigned int _MaxCharCount)
  {
    return _read(_FileHandle, _DstBuf, _MaxCharCount);
  }

#if __MINGW_FORTIFY_VA_ARG

  _CRTIMP int __cdecl __mingw_call__open(const char *_Filename, int _OpenFlag, ...) __ASM_CRT_CALL(_open);
  _CRTIMP int __cdecl __mingw_call__open_warn_toomany(const char *_Filename, int _OpenFlag, ...) __ASM_CRT_CALL(_open)
    __ATTR_WARN("_open(): too many arguments");
  _CRTIMP int __cdecl __mingw_call__open_warn_missing(const char *_Filename, int _OpenFlag, ...) __ASM_CRT_CALL(_open)
    __ATTR_WARN("_open(..._O_CREAT...): missing argument");

  __mingw_bos_extern_ovr __NONNULL((1))
  int _open(const char *_Filename, int _OpenFlag, ...)
  {
    if(__va_arg_pack_len() > 1)
    {
      return __mingw_call__open_warn_toomany(_Filename, _OpenFlag, __va_arg_pack());
    }
    if(__va_arg_pack_len() < 1 && __HAS__O_CREAT(_OpenFlag))
    {
      return __mingw_call__open_warn_missing(_Filename, _OpenFlag, 0);
    }
    if(__va_arg_pack_len() < 1)
    {
      return __mingw_call__open(_Filename, _OpenFlag, 0);
    }
    return __mingw_call__open(_Filename, _OpenFlag, __va_arg_pack());
  }

  __mingw_bos_extern_ovr __NONNULL((1))
  int open(const char *_Filename, int _OpenFlag, ...)
  {
    return _open(_Filename, _OpenFlag, __va_arg_pack());
  }

#ifdef __MINGW_USE_LFS64
  __mingw_bos_extern_ovr __NONNULL((1))
  int open64(const char *_Filename, int _OpenFlag, ...)
  {
    return _open(_Filename, _OpenFlag, __va_arg_pack());
  }
#endif

  _CRTIMP int __cdecl __mingw_call__sopen(const char *_Filename, int _OpenFlag, int _ShareFlag, ...) __ASM_CRT_CALL(_sopen);
  _CRTIMP int __cdecl __mingw_call__sopen_warn_toomany(const char *_Filename, int _OpenFlag, int _ShareFlag, ...) __ASM_CRT_CALL(_sopen)
    __ATTR_WARN("_sopen(): too many arguments");
  _CRTIMP int __cdecl __mingw_call__sopen_warn_missing(const char *_Filename, int _OpenFlag, int _ShareFlag, ...) __ASM_CRT_CALL(_sopen)
    __ATTR_WARN("_sopen(..._O_CREAT...): missing argument");

  __mingw_bos_extern_ovr
  int _sopen(const char *_Filename, int _OpenFlag, int _ShareFlag, ...)
  {
    if(__va_arg_pack_len() > 1)
    {
      return __mingw_call__sopen_warn_toomany(_Filename, _OpenFlag, _ShareFlag, __va_arg_pack());
    }
    if(__va_arg_pack_len() < 1 && __HAS__O_CREAT(_OpenFlag))
    {
      return __mingw_call__sopen_warn_missing(_Filename, _OpenFlag, _ShareFlag, 0);
    }
    if(__va_arg_pack_len() < 1)
    {
      return __mingw_call__sopen(_Filename, _OpenFlag, _ShareFlag, 0);
    }
    return __mingw_call__sopen(_Filename, _OpenFlag, _ShareFlag, __va_arg_pack());
  }

  __mingw_bos_extern_ovr
  int sopen(const char *_Filename, int _OpenFlag, int _ShareFlag, ...)
  {
    return _sopen(_Filename, _OpenFlag, _ShareFlag, __va_arg_pack());
  }

#endif  /* __MINGW_FORTIFY_VA_ARG */

#endif  /* __MINGW_FORTIFY_LEVEL > 0 */

__MINGW_END_C_DECLS

#endif  /* _SSP_INC_IO */
