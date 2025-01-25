/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _SSP_INC_WIO
#define _SSP_INC_WIO

#include <ssp/ssp.h>
#include <fcntl.h>

#ifndef __HAS__O_CREAT
# define __HAS__O_CREAT(flag) (__builtin_constant_p(flag & _O_CREAT) && (flag & _O_CREAT))
#endif

__MINGW_BEGIN_C_DECLS

#if __MINGW_FORTIFY_LEVEL > 0

#if __MINGW_FORTIFY_VA_ARG

  _CRTIMP int __cdecl __mingw_call__wopen(const wchar_t *_Filename, int _OpenFlag, ...) __ASM_CRT_CALL(_wopen);
  _CRTIMP int __cdecl __mingw_call__wopen_warn_toomany(const wchar_t *_Filename, int _OpenFlag, ...) __ASM_CRT_CALL(_wopen)
    __ATTR_WARN("_wopen(): too many arguments");
  _CRTIMP int __cdecl __mingw_call__wopen_warn_missing(const wchar_t *_Filename, int _OpenFlag, ...) __ASM_CRT_CALL(_wopen)
    __ATTR_WARN("_wopen(..._O_CREAT...): missing argument");

  __mingw_bos_extern_ovr __NONNULL((1))
  int _wopen(const wchar_t *_Filename, int _OpenFlag, ...)
  {
    if(__va_arg_pack_len() > 1)
    {
      return __mingw_call__wopen_warn_toomany(_Filename, _OpenFlag, __va_arg_pack());
    }
    if(__va_arg_pack_len() < 1 && __HAS__O_CREAT(_OpenFlag))
    {
      return __mingw_call__wopen_warn_missing(_Filename, _OpenFlag, 0);
    }
    if(__va_arg_pack_len() < 1)
    {
      return __mingw_call__wopen(_Filename, _OpenFlag, 0);
    }
    return __mingw_call__wopen(_Filename, _OpenFlag, __va_arg_pack());
  }

  _CRTIMP int __cdecl __mingw_call__wsopen(const wchar_t *_Filename, int _OpenFlag, int _ShareFlag, ...) __ASM_CRT_CALL(_wsopen);
  _CRTIMP int __cdecl __mingw_call__wsopen_warn_toomany(const wchar_t *_Filename, int _OpenFlag, int _ShareFlag, ...) __ASM_CRT_CALL(_wsopen)
    __ATTR_WARN("_wsopen(): too many arguments");
  _CRTIMP int __cdecl __mingw_call__wsopen_warn_missing(const wchar_t *_Filename, int _OpenFlag, int _ShareFlag, ...) __ASM_CRT_CALL(_wsopen)
    __ATTR_WARN("_wsopen(..._O_CREAT...): missing argument");

  __mingw_bos_extern_ovr
  int _wsopen(const wchar_t *_Filename, int _OpenFlag, int _ShareFlag, ...)
  {
    if(__va_arg_pack_len() > 1)
    {
      return __mingw_call__wsopen_warn_toomany(_Filename, _OpenFlag, _ShareFlag, __va_arg_pack());
    }
    if(__va_arg_pack_len() < 1 && __HAS__O_CREAT(_OpenFlag))
    {
      return __mingw_call__wsopen_warn_missing(_Filename, _OpenFlag, _ShareFlag, 0);
    }
    if(__va_arg_pack_len() < 1)
    {
      return __mingw_call__wsopen(_Filename, _OpenFlag, _ShareFlag, 0);
    }
    return __mingw_call__wsopen(_Filename, _OpenFlag, _ShareFlag, __va_arg_pack());
  }

#endif  /* __MINGW_FORTIFY_VA_ARG */

#endif  /* __MINGW_FORTIFY_LEVEL > 0 */

__MINGW_END_C_DECLS

#endif  /* _SSP_INC_WIO */
