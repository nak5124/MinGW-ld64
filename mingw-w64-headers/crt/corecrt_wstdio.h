/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CORECRT_WSTDIO
#define _INC_CORECRT_WSTDIO

#include <corecrt.h>
#include <corecrt_stdio_config.h>

#pragma push_macro("snwprintf")
#undef snwprintf
#pragma push_macro("vsnwprintf")
#undef vsnwprintf

__MINGW_BEGIN_C_DECLS

#ifndef _FILE_DEFINED
# define _FILE_DEFINED
  struct _iobuf
  {
    void *_Placeholder;
  };
  typedef struct _iobuf FILE;
#endif

  _CRTIMP FILE *__cdecl __acrt_iob_func(unsigned _Ix);

#define stdin  (__acrt_iob_func(0))
#define stdout (__acrt_iob_func(1))
#define stderr (__acrt_iob_func(2))

#if __MINGW_FORTIFY_LEVEL > 0
# ifndef __MINGW_BOS_DECLARE_DEFINED
#   define __MINGW_BOS_DECLARE_DEFINED
    __mingw_bos_declare;
# endif
#endif

  _CRTIMP int __cdecl __stdio_common_vfwprintf(unsigned __int64 _Options, FILE *_Stream, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vfwprintf_s(unsigned __int64 _Options, FILE *_Stream, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vfwprintf_p(unsigned __int64 _Options, FILE *_Stream, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);

  __mingw_ovr
  int _vfwprintf_l(FILE *__restrict _Stream, const wchar_t *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
  }

  __mingw_ovr
  int _vfwprintf_s_l(FILE *__restrict _Stream, const wchar_t *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int vfwprintf_s(FILE *__restrict _Stream, const wchar_t *__restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, NULL, _ArgList);
  }

#endif

  __mingw_ovr
  int _vfwprintf_p_l(FILE *__restrict _Stream, const wchar_t *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfwprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
  }

  __mingw_ovr
  int _vfwprintf_p(FILE *__restrict _Stream, const wchar_t *__restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfwprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, NULL, _ArgList);
  }

  __mingw_ovr
  int _vwprintf_l(const wchar_t *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, _Locale, _ArgList);
  }

  __mingw_ovr
  int _vwprintf_s_l(const wchar_t *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, _Locale, _ArgList);
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int vwprintf_s(const wchar_t *__restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, NULL, _ArgList);
  }

#endif

  __mingw_ovr
  int _vwprintf_p_l(const wchar_t *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfwprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, _Locale, _ArgList);
  }

  __mingw_ovr
  int _vwprintf_p(const wchar_t *__restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfwprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, NULL, _ArgList);
  }

  __mingw_ovr
  int _fwprintf_l(FILE *__restrict _Stream, const wchar_t *__restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr
  int _fwprintf_s_l(FILE *__restrict _Stream, const wchar_t *__restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int fwprintf_s(FILE *__restrict _Stream, const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#endif

  __mingw_ovr
  int _fwprintf_p_l(FILE *__restrict _Stream, const wchar_t *__restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfwprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr
  int _fwprintf_p(FILE *__restrict _Stream, const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfwprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr
  int _wprintf_l(const wchar_t *__restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr
  int _wprintf_s_l(const wchar_t *__restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int wprintf_s(const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#endif

  __mingw_ovr
  int _wprintf_p_l(const wchar_t *__restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfwprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr
  int _wprintf_p(const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfwprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  _CRTIMP int __cdecl __stdio_common_vfwscanf(unsigned __int64 _Options, FILE *_Stream, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);

  __mingw_ovr
  int _vfwscanf_l(FILE *__restrict _Stream, const wchar_t *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
  }

  __mingw_ovr
  int _vfwscanf_s_l(FILE *__restrict _Stream, const wchar_t *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Stream, _Format, _Locale, _ArgList);
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int vfwscanf_s(FILE *__restrict _Stream, const wchar_t *__restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Stream, _Format, NULL, _ArgList);
  }

#endif

  __mingw_ovr
  int _vwscanf_l(const wchar_t *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, stdin, _Format, _Locale, _ArgList);
  }

  __mingw_ovr
  int _vwscanf_s_l(const wchar_t *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, stdin, _Format, _Locale, _ArgList);
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int vwscanf_s(const wchar_t *__restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, stdin, _Format, NULL, _ArgList);
  }

#endif

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _fwscanf_l(FILE *__restrict _Stream, const wchar_t *__restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr
  int _fwscanf_s_l(FILE *__restrict _Stream, const wchar_t *__restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Stream, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int fwscanf_s(FILE *__restrict _Stream, const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Stream, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#endif

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _wscanf_l(const wchar_t *__restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, stdin, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr
  int _wscanf_s_l(const wchar_t *__restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, stdin, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int wscanf_s(const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, stdin, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#endif

  _CRTIMP int __cdecl __stdio_common_vswprintf(unsigned __int64 _Options, wchar_t *_Buffer, size_t _BufferCount, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vswprintf_s(unsigned __int64 _Options, wchar_t *_Buffer, size_t _BufferCount, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vsnwprintf_s(unsigned __int64 _Options, wchar_t *_Buffer, size_t _BufferCount, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vswprintf_p(unsigned __int64 _Options, wchar_t *_Buffer, size_t _BufferCount, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _vsnwprintf_l(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _vsnwprintf_s_l(wchar_t *__restrict _Buffer, size_t _BufferCount, size_t _MaxCount, const wchar_t *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsnwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _vsnwprintf_s(wchar_t *__restrict _Buffer, size_t _BufferCount, size_t _MaxCount, const wchar_t *__restrict _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsnwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _MaxCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(int, _vsnwprintf_s, wchar_t, _Buffer, size_t, _BufferCount, const wchar_t *, _Format, va_list, _ArgList)

  __mingw_ovr /* __attribute__((__format__(gnu_wprintf, 3, 0))) */ __MINGW_NONNULL((3)) __MINGW_DEPRECATED_SEC_WARN
  int _vsnwprintf(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _vswprintf_c_l(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _vswprintf_c(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _vswprintf_l(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int __vswprintf_l(wchar_t *__restrict _Buffer, const wchar_t *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _vswprintf(wchar_t *__restrict _Buffer, const wchar_t *__restrict _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, (size_t)-1, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _vswprintf_s_l(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int vswprintf_s(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(int, vswprintf_s, wchar_t, _Buffer, const wchar_t *, _Format, va_list, _ArgList)

#endif

  __mingw_ovr
  int _vswprintf_p_l(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _vswprintf_p(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _vscwprintf_l(const wchar_t *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _vscwprintf(const wchar_t *__restrict _Format, va_list _ArgList)
  {
      int _Ret;
      _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, NULL, _ArgList);
      return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _vscwprintf_p_l(const wchar_t *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _vscwprintf_p(const wchar_t *__restrict _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int __swprintf_l(wchar_t *__restrict _Buffer, const wchar_t *__restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _swprintf_l(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _swprintf(wchar_t *__restrict _Buffer, const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, (size_t)-1, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _swprintf_s_l(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int swprintf_s(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1_ARGLIST(int, swprintf_s, vswprintf_s, wchar_t, _Buffer, const wchar_t *, _Format)

#endif

  __mingw_ovr
  int _swprintf_p_l(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _swprintf_p(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _swprintf_c_l(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _swprintf_c(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _snwprintf_l(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr /* __attribute__((__format__(gnu_wprintf, 3, 4))) */ __MINGW_NONNULL((3)) __MINGW_DEPRECATED_SEC_WARN
  int _snwprintf(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _snwprintf_s_l(wchar_t *__restrict _Buffer, size_t _BufferCount, size_t _MaxCount, const wchar_t *__restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsnwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _snwprintf_s(wchar_t *__restrict _Buffer, size_t _BufferCount, size_t _MaxCount, const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vsnwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _MaxCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2_ARGLIST(int, _snwprintf_s, _vsnwprintf_s, wchar_t, _Buffer, size_t, _BufferCount, const wchar_t *, _Format)

  __mingw_ovr
  int _scwprintf_l(const wchar_t *__restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _scwprintf(const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _scwprintf_p_l(const wchar_t *__restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _scwprintf_p(const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  _CRTIMP int __cdecl __stdio_common_vswscanf(unsigned __int64 _Options, const wchar_t *_Buffer, size_t _BufferCount, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);

  __mingw_ovr
  int _vswscanf_l(wchar_t *__restrict _Buffer, const wchar_t *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
  }

  __mingw_ovr
  int _vswscanf_s_l(wchar_t *__restrict _Buffer, const wchar_t *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int vswscanf_s(wchar_t *__restrict _Buffer, const wchar_t *__restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Buffer, (size_t)-1, _Format, NULL, _ArgList);
  }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(int, vswscanf_s, wchar_t, _Buffer, const wchar_t *, _Format, va_list, _ArgList)

#endif

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _vsnwscanf_l(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
  }

  __mingw_ovr
  int _vsnwscanf_s_l(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
  }

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _swscanf_l(wchar_t *__restrict _Buffer, const wchar_t *__restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr
  int _swscanf_s_l(wchar_t *__restrict _Buffer, const wchar_t *__restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int swscanf_s(wchar_t *__restrict _Buffer, const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Buffer, (size_t)-1, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#endif

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _snwscanf_l(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _snwscanf(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr
  int _snwscanf_s_l(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr
  int _snwscanf_s(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#if defined(__MINGW_USE_ISOC95) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)

  extern int __cdecl vfwprintf(FILE *__restrict _Stream, const wchar_t *__restrict _Format, va_list _ArgList)
    /* __attribute__((__format__(gnu_wprintf, 2, 0))) */ __MINGW_NONNULL((1, 2));
  extern int __cdecl vwprintf(const wchar_t *__restrict _Format, va_list _ArgList)
    /* __attribute__((__format__(gnu_wprintf, 1, 0))) */ __MINGW_NONNULL((1));
  extern int __cdecl fwprintf(FILE *__restrict _Stream, const wchar_t *__restrict _Format, ...)
    /* __attribute__((__format__(gnu_wprintf, 2, 3))) */ __MINGW_NONNULL((1, 2));
  extern int __cdecl wprintf(const wchar_t *__restrict _Format, ...)
    /* __attribute__((__format__(gnu_wprintf, 1, 2))) */ __MINGW_NONNULL((1));

#ifndef __CRT__NO_INLINE

  __CRT_INLINE /* __attribute__((__format__(gnu_wprintf, 2, 0))) */ __MINGW_NONNULL((1, 2))
  int __cdecl vfwprintf(FILE *__restrict _Stream, const wchar_t *__restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, NULL, _ArgList);
  }

  __CRT_INLINE /* __attribute__((__format__(gnu_wprintf, 1, 0))) */ __MINGW_NONNULL((1))
  int __cdecl vwprintf(const wchar_t *__restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, NULL, _ArgList);
  }

  __CRT_INLINE /* __attribute__((__format__(gnu_wprintf, 2, 3))) */ __MINGW_NONNULL((1, 2))
  int __cdecl fwprintf(FILE *__restrict _Stream, const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __CRT_INLINE /* __attribute__((__format__(gnu_wprintf, 1, 2))) */ __MINGW_NONNULL((1))
  int __cdecl wprintf(const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#endif  /* __CRT__NO_INLINE */

#endif  /* defined(__MINGW_USE_ISOC95) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX) */

#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)

  extern int __cdecl vfwscanf(FILE *__restrict _Stream, const wchar_t *__restrict _Format, va_list _ArgList)
    /* __attribute__((__format__(gnu_wscanf, 2, 0))) */ __MINGW_NONNULL((1, 2));
  extern int __cdecl vwscanf(const wchar_t *__restrict _Format, va_list _ArgList)
    /* __attribute__((__format__(gnu_wscanf, 1, 0))) */ __MINGW_NONNULL((1));

#ifndef __CRT__NO_INLINE

  __CRT_INLINE /* __attribute__((__format__(gnu_wscanf, 2, 0))) */ __MINGW_NONNULL((1, 2))
  int __cdecl vfwscanf(FILE *__restrict _Stream, const wchar_t *__restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Stream, _Format, NULL, _ArgList);
  }

  __CRT_INLINE /* __attribute__((__format__(gnu_wscanf, 1, 0))) */ __MINGW_NONNULL((1))
  int __cdecl vwscanf(const wchar_t *__restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, stdin, _Format, NULL, _ArgList);
  }

#endif

#endif  /* defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX) */

#if defined(__MINGW_USE_ISOC95) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)

  extern int __cdecl fwscanf(FILE *__restrict _Stream, const wchar_t *__restrict _Format, ...)
    /* __attribute__((__format__(gnu_wscanf, 2, 3))) */ __MINGW_NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN;
  extern int __cdecl wscanf(const wchar_t *__restrict _Format, ...)
    /* __attribute__((__format__(gnu_wscanf, 1, 2))) */ __MINGW_NONNULL((1)) __MINGW_DEPRECATED_SEC_WARN;

#ifndef __CRT__NO_INLINE

  __CRT_INLINE /* __attribute__((__format__(gnu_wscanf, 2, 3))) */ __MINGW_NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN
  int __cdecl fwscanf(FILE *__restrict _Stream, const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Stream, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __CRT_INLINE /* __attribute__((__format__(gnu_wscanf, 1, 2))) */ __MINGW_NONNULL((1)) __MINGW_DEPRECATED_SEC_WARN
  int wscanf(const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, stdin, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#endif

#endif  /* defined(__MINGW_USE_ISOC95) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX) */

  extern int __cdecl vsnwprintf(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, va_list _ArgList)
    /* __attribute__((__format__(gnu_wprintf, 3, 0))) */ __MINGW_NONNULL((3));
  extern int __cdecl snwprintf(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, ...)
    /* __attribute__((__format__(gnu_wprintf, 3, 4))) */ __MINGW_NONNULL((3));

#ifndef __CRT__NO_INLINE

  __CRT_INLINE /* __attribute__((__format__(gnu_wprintf, 3, 0))) */ __MINGW_NONNULL((3))
  int __cdecl vsnwprintf(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __CRT_INLINE /* __attribute__((__format__(gnu_wprintf, 3, 4))) */ __MINGW_NONNULL((3))
  int __cdecl snwprintf(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#endif

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  /* __attribute__((__format__(gnu_wprintf, 3, 0))) */ __MINGW_NONNULL((3))
  int vsnwprintf_s(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  /* __attribute__((__format__(gnu_wprintf, 3, 4))) */ __MINGW_NONNULL((3))
  int snwprintf_s(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#endif

#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)

  extern int __cdecl vswscanf(const wchar_t *__restrict _Buffer, const wchar_t *__restrict _Format, va_list _ArgList)
    /* __attribute__((__format__(gnu_wscanf, 2, 0))) */ __MINGW_NONNULL((2));

#ifndef __CRT__NO_INLINE

  __CRT_INLINE /* __attribute__((__format__(gnu_wscanf, 2, 0))) */ __MINGW_NONNULL((2))
  int __cdecl vswscanf(const wchar_t *__restrict _Buffer, const wchar_t *__restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Buffer, (size_t)-1, _Format, NULL, _ArgList);
  }

#endif

#endif  /* defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX) */

#if defined(__MINGW_USE_ISOC95) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)

  extern int __cdecl swscanf(const wchar_t *__restrict _Buffer, const wchar_t *__restrict _Format, ...)
    /* __attribute__((__format__(gnu_wscanf, 2, 3))) */ __MINGW_NONNULL((2)) __MINGW_DEPRECATED_SEC_WARN;

#ifndef __CRT__NO_INLINE

  __CRT_INLINE /* __attribute__((__format__(gnu_wscanf, 2, 3))) */ __MINGW_NONNULL((2)) __MINGW_DEPRECATED_SEC_WARN
  int __cdecl swscanf(const wchar_t *__restrict _Buffer, const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Buffer, (size_t)-1, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#endif

#endif  /* defined(__MINGW_USE_ISOC95) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX) */

#if defined(__MINGW_USE_ISOC95) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)

  extern int __cdecl vswprintf(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, va_list _ArgList)
    /* __attribute__((__format__(gnu_wprintf, 3, 0))) */ __MINGW_NONNULL((3));
  extern int __cdecl swprintf(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, ...)
    /* __attribute__((__format__(gnu_wprintf, 3, 4))) */ __MINGW_NONNULL((3));

#ifndef __CRT__NO_INLINE

  __CRT_INLINE /* __attribute__((__format__(gnu_wprintf, 3, 0))) */ __MINGW_NONNULL((3))
  int __cdecl vswprintf(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, va_list _ArgList)
  {
    int _Ret;
    /*
     * __stdio_common_vswprintf() for case _Buffer == NULL and _BufferCount == 0 and
     * without _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR option, is
     * executed in "standard snprintf behavior" and returns number of (wide)
     * chars required to allocate. For all other cases it is executed in a way
     * that returns negative value on error. But C95+ compliant swprintf() for
     * case _BufferCount == 0 returns negative value, so handle this case specially.
     */
    if(_Buffer == NULL && _BufferCount == 0)
    {
      return -1;
    }
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __CRT_INLINE /* __attribute__((__format__(gnu_wprintf, 3, 4))) */ __MINGW_NONNULL((3))
  int __cdecl swprintf(wchar_t *__restrict _Buffer, size_t _BufferCount, const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    /*
     * __stdio_common_vswprintf() for case _Buffer == NULL and _BufferCount == 0 and
     * without _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR option, is
     * executed in "standard snprintf behavior" and returns number of (wide)
     * chars required to allocate. For all other cases it is executed in a way
     * that returns negative value on error. But C95+ compliant swprintf() for
     * case _BufferCount == 0 returns negative value, so handle this case specially.
     */
    if(_Buffer == NULL && _BufferCount == 0)
    {
      return -1;
    }
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

#endif

#endif  /* defined(__MINGW_USE_ISOC95) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX) */

#ifdef __cplusplus

extern "C++"
{
  __mingw_ovr
  /* __attribute__((__format__(gnu_wprintf, 2, 0))) */ __MINGW_NONNULL((2)) __MINGW_DEPRECATED_SEC_WARN
  int vswprintf(wchar_t *__restrict _Buffer, const wchar_t *__restrict _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, (size_t)-1, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  /* __attribute__((__format__(gnu_wprintf, 2, 3))) */ __MINGW_NONNULL((2)) __MINGW_DEPRECATED_SEC_WARN
  int swprintf(wchar_t *__restrict _Buffer, const wchar_t *__restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, (size_t)-1, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _vswprintf_l(wchar_t *_Buffer, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _swprintf_l(wchar_t *_Buffer, const wchar_t *_Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }
}

#elif defined(_CRT_NON_CONFORMING_SWPRINTFS)

#if defined(__MINGW_USE_ISOC95) || defined(__MINGW_USE_UNIX98)
# define swprintf  _swprintf
# define vswprintf _vswprintf
#endif
#define _swprintf_l  __swprintf_l
#define _vswprintf_l __vswprintf_l

#endif  /* __cplusplus */

#ifndef WEOF
# define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP wint_t   __cdecl  fgetwc(FILE *_File) __MINGW_NONNULL((1));
  _CRTIMP wint_t   __cdecl _fgetwchar(void);
  _CRTIMP wint_t   __cdecl  fputwc(wchar_t _Ch, FILE *_File) __MINGW_NONNULL((2));
  _CRTIMP wint_t   __cdecl _fputwchar(wchar_t _Ch);
  _CRTIMP wint_t   __cdecl  getwc(FILE *_File) __MINGW_NONNULL((1));
  _CRTIMP wint_t   __cdecl  getwchar(void);
  _CRTIMP wchar_t *__cdecl  fgetws(wchar_t *__restrict _Dst, int _SizeInWords, FILE *__restrict _File) __MINGW_NONNULL((3));
  _CRTIMP int      __cdecl  fputws(const wchar_t *__restrict _Str, FILE *__restrict _File) __MINGW_NONNULL((2));
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str, size_t _SizeInWords);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(wchar_t *, _getws_s, wchar_t, _DstBuf)
  _CRTIMP wint_t   __cdecl  putwc(wchar_t _Ch, FILE *_File) __MINGW_NONNULL((2));
  _CRTIMP wint_t   __cdecl  putwchar(wchar_t _Ch);
  _CRTIMP int      __cdecl _putws(const wchar_t *_Str);
  _CRTIMP wint_t   __cdecl  ungetwc(wint_t _Ch, FILE *_File) __MINGW_NONNULL((2));
  _CRTIMP FILE    *__cdecl _wfdopen(int _FileHandle, const wchar_t *_Mode);
  _CRTIMP FILE    *__cdecl _wfopen(const wchar_t * __restrict _Filename, const wchar_t *__restrict  _Mode) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t  __cdecl _wfopen_s(FILE **_File,const wchar_t *_Filename,const wchar_t *_Mode);
  _CRTIMP FILE    *__cdecl _wfreopen(const wchar_t *__restrict _Filename, const wchar_t *__restrict _Mode, FILE *__restrict _OldFile) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t  __cdecl _wfreopen_s(FILE **_File, const wchar_t *_Filename, const wchar_t *_Mode, FILE *_OldFile);
  _CRTIMP FILE    *__cdecl _wfsopen(const wchar_t *_Filename, const wchar_t *_Mode, int _ShFlag);
#ifndef _CRT_WPERROR_DEFINED  /* Also in corecrt_wstdlib.h */
# define _CRT_WPERROR_DEFINED
  _CRTIMP void __cdecl _wperror(const wchar_t *_ErrMsg);
#endif  /* _CRT_WPERROR_DEFINED */
#ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
  _CRTIMP FILE *__cdecl _wpopen(const wchar_t *_Command, const wchar_t *_Mode);
# ifndef wpopen
#   define wpopen _wpopen
# endif
#endif
  _CRTIMP int __cdecl _wremove(const wchar_t *_Filename);
#pragma push_macro("_wtempnam")
#undef _wtempnam
  _CRTIMP wchar_t *__cdecl _wtempnam(const wchar_t *_Directory, const wchar_t *_FilePrefix);
#pragma pop_macro("_wtempnam")
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t  __cdecl _wtmpnam_s(wchar_t *_DstBuf, size_t _SizeInWords);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, _wtmpnam_s, wchar_t, _DstBuf)

  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch, FILE *_File);
  _CRTIMP wint_t __cdecl _getwc_nolock(FILE *_Stream);
  _CRTIMP wint_t __cdecl _putwc_nolock(wchar_t _Character, FILE *_Stream);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch, FILE *_File);

#ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP

#ifndef _WSPAWN_DEFINED  /* Also in corecrt_wprocess.h */
# define _WSPAWN_DEFINED
  _CRTIMP intptr_t __cdecl _wspawnl(int _Mode, const wchar_t *_Filename, const wchar_t *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _wspawnle(int _Mode, const wchar_t *_Filename, const wchar_t *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _wspawnlp(int _Mode, const wchar_t *_Filename, const wchar_t *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(int _Mode, const wchar_t *_Filename, const wchar_t *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _wspawnv(int _Mode, const wchar_t *_Filename, const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(int _Mode, const wchar_t *_Filename, const wchar_t *const *_ArgList, const wchar_t *const *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(int _Mode, const wchar_t *_Filename, const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(int _Mode, const wchar_t *_Filename, const wchar_t *const *_ArgList, const wchar_t *const *_Env);
#endif  /* _WSPAWN_DEFINED */

#endif  /* _CRT_USE_WINAPI_FAMILY_DESKTOP_APP */

__MINGW_END_C_DECLS

#pragma pop_macro("snwprintf")
#pragma pop_macro("vsnwprintf")

#endif  /* _INC_CORECRT_WSTDIO */
