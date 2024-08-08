/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CORECRT_WDIRECT
#define _INC_CORECRT_WDIRECT

#include <corecrt.h>

__MINGW_BEGIN_C_DECLS

#pragma push_macro("_wgetcwd")
#pragma push_macro("_wgetdcwd")
#undef _wgetcwd
#undef _wgetdcwd

  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf, int _SizeInWords);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(int _Drive, wchar_t *_DstBuf, int _SizeInWords);

#define _wgetdcwd_nolock  _wgetdcwd

#pragma pop_macro("_wgetcwd")
#pragma pop_macro("_wgetdcwd")

  _CRTIMP int __cdecl _wchdir(const wchar_t *_Path) __MINGW_NONNULL((1));
  _CRTIMP int __cdecl _wmkdir(const wchar_t *_Path) __MINGW_NONNULL((1));
  _CRTIMP int __cdecl _wrmdir(const wchar_t *_Path);

__MINGW_END_C_DECLS

#endif  /* _INC_CORECRT_WDIRECT */
