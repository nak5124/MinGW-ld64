/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CORECRT_WCONIO
#define _INC_CORECRT_WCONIO

#include <corecrt.h>
#include <corecrt_stdio_config.h>

__MINGW_BEGIN_C_DECLS

#ifndef WEOF
# define WEOF ((wint_t)(0xFFFF))
#endif

#ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *_Buffer, size_t _SizeInWords, size_t *_SizeRead);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _cgetws_s, wchar_t, _Buffer, size_t*, _SizeRead)
  _CRTIMP int __cdecl _cputws(const wchar_t *_String);

  _CRTIMP wint_t __cdecl _getwch(void);
  _CRTIMP wint_t __cdecl _getwche(void);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);

  _CRTIMP wint_t __cdecl _getwch_nolock(void);
  _CRTIMP wint_t __cdecl _getwche_nolock(void);
  _CRTIMP wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch_nolock(wint_t _WCh);

  _CRTIMP int __cdecl __conio_common_vcwprintf(unsigned __int64 _Options, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __conio_common_vcwprintf_s(unsigned __int64 _Options, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __conio_common_vcwprintf_p(unsigned __int64 _Options, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);

  __mingw_ovr int _vcwprintf_l(const wchar_t * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __conio_common_vcwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int _vcwprintf(const wchar_t * __restrict _Format, va_list _ArgList)
  {
    return __conio_common_vcwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Format, NULL, _ArgList);
  }

  __mingw_ovr int _vcwprintf_s_l(const wchar_t * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __conio_common_vcwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int _vcwprintf_s(const wchar_t * __restrict _Format, va_list _ArgList)
  {
    return __conio_common_vcwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Format, NULL, _ArgList);
  }

  __mingw_ovr int _vcwprintf_p_l(const wchar_t * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __conio_common_vcwprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int _vcwprintf_p(const wchar_t * __restrict _Format, va_list _ArgList)
  {
    return __conio_common_vcwprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Format, NULL, _ArgList);
  }

  __mingw_ovr int _cwprintf_l(const wchar_t * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __conio_common_vcwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int _cwprintf(const wchar_t * __restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __conio_common_vcwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int _cwprintf_s_l(const wchar_t * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __conio_common_vcwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int _cwprintf_s(const wchar_t * __restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __conio_common_vcwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int _cwprintf_p_l(const wchar_t * __restrict _Format, _locale_t _Locale,...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __conio_common_vcwprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int _cwprintf_p(const wchar_t * __restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __conio_common_vcwprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  _CRTIMP int __cdecl __conio_common_vcwscanf(unsigned __int64 _Options, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _vcwscanf_l(const wchar_t * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __conio_common_vcwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Format, _Locale, _ArgList);
  }

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _vcwscanf(const wchar_t * __restrict _Format, va_list _ArgList)
  {
    return __conio_common_vcwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Format, NULL, _ArgList);
  }

  __mingw_ovr int _vcwscanf_s_l(const wchar_t * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __conio_common_vcwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int _vcwscanf_s(const wchar_t * __restrict _Format, va_list _ArgList)
  {
    return __conio_common_vcwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Format, NULL, _ArgList);
  }

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _cwscanf_l(const wchar_t * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __conio_common_vcwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _cwscanf(const wchar_t * __restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __conio_common_vcwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int _cwscanf_s_l(const wchar_t * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __conio_common_vcwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int _cwscanf_s(const wchar_t * __restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __conio_common_vcwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#endif  /* _CRT_USE_WINAPI_FAMILY_DESKTOP_APP */

__MINGW_END_C_DECLS

#endif  /* _INC_CORECRT_WCONIO */
