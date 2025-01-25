/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _SSP_INC_WSTRING
#define _SSP_INC_WSTRING

#include <ssp/ssp.h>

__MINGW_BEGIN_C_DECLS

#if __MINGW_FORTIFY_LEVEL > 0

  _CRTIMP wchar_t *__cdecl __mingw_call_wcscpy(wchar_t *__restrict _Dest, const wchar_t *__restrict _Source) __ASM_CRT_CALL_NTH(wcscpy);
  _CRTIMP errno_t  __cdecl __mingw_call_wcscpy_s(wchar_t *_Dst, rsize_t _SizeInWords, const wchar_t *_Src)   __ASM_CRT_CALL(wcscpy_s);
  _CRTIMP wchar_t *__cdecl __mingw_call_wcscat(wchar_t *__restrict _Dest, const wchar_t *__restrict _Source) __ASM_CRT_CALL_NTH(wcscat);
  _CRTIMP errno_t  __cdecl __mingw_call_wcscat_s(wchar_t *_Dst, rsize_t _SizeInWords, const wchar_t *_Src)   __ASM_CRT_CALL(wcscat_s);

  __mingw_bos_extern_ovr __NONNULL((1, 2))
  __NTH_FNC(wchar_t *wcscpy(wchar_t *__restrict _Dest, const wchar_t *__restrict _Source))
  {
    if(__mingw_bos_known(_Dest))
    {
      __mingw_bos_cond_chk(!__mingw_call_wcscpy_s(_Dest, __mingw_bos(_Dest, 1) / sizeof(wchar_t), _Source));
      return _Dest;
    }
    return __mingw_call_wcscpy(_Dest, _Source);
  }

  __mingw_bos_extern_ovr __NONNULL((1, 2))
  __NTH_FNC(wchar_t *wcscat(wchar_t *__restrict _Dest, const wchar_t *__restrict _Source))
  {
    if(__mingw_bos_known(_Dest))
    {
      __mingw_bos_cond_chk(!__mingw_call_wcscat_s(_Dest, __mingw_bos(_Dest, 1) / sizeof(wchar_t), _Source));
      return _Dest;
    }
    return __mingw_call_wcscat(_Dest, _Source);
  }

#endif  /* __MINGW_FORTIFY_LEVEL > 0 */

__MINGW_END_C_DECLS

#endif  /* _SSP_INC_WSTRING */
