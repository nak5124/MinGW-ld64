/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CORECRT_WSTDIO
#define _INC_CORECRT_WSTDIO

#include <corecrt.h>
#include <corecrt_stdio_config.h>

#pragma pack(push, _CRT_PACKING)

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

  _CRTIMP FILE *__cdecl __acrt_iob_func(unsigned index);

#define stdin  (__acrt_iob_func(0))
#define stdout (__acrt_iob_func(1))
#define stderr (__acrt_iob_func(2))

#if __MINGW_FORTIFY_LEVEL > 0
#ifndef __MINGW_BOS_DECLARE_DEFINED
# define __MINGW_BOS_DECLARE_DEFINED
  __mingw_bos_declare;
#endif
#endif

  /* __attribute__((__format__(gnu_wprintf, 2, 0))) */ extern __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __mingw_vfwprintf(FILE * __restrict__ _File, const wchar_t * __restrict__ _Format, va_list _ArgList);
  /* __attribute__((__format__(gnu_wprintf, 1, 0))) */ extern __MINGW_ATTRIB_NONNULL(1)
  int __cdecl __mingw_vwprintf(const wchar_t * __restrict__ _Format, va_list _ArgList);
  /* __attribute__((__format__(gnu_wprintf, 2, 3))) */ extern __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __mingw_fwprintf(FILE * __restrict__ _File, const wchar_t * __restrict__ _Format, ...);
  /* __attribute__((__format__(gnu_wprintf, 1, 2))) */ extern __MINGW_ATTRIB_NONNULL(1)
  int __cdecl __mingw_wprintf(const wchar_t * __restrict__ _Format, ...);

  /* __attribute__((__format__(gnu_wscanf, 2, 0))) */ extern __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __mingw_vfwscanf(FILE * __restrict__ fp, const wchar_t * __restrict__ Format, va_list argp);
  /* __attribute__((__format__(gnu_wscanf, 1, 0))) */ extern __MINGW_ATTRIB_NONNULL(1)
  int __cdecl __mingw_vwscanf(const wchar_t * __restrict__ Format, va_list argp);
  /* __attribute__((__format__(gnu_wscanf, 2, 3))) */ extern __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __mingw_fwscanf(FILE * __restrict__ _File, const wchar_t * __restrict__ _Format, ...);
  /* __attribute__((__format__(gnu_wscanf, 1, 2))) */ extern __MINGW_ATTRIB_NONNULL(1)
  int __cdecl __mingw_wscanf(const wchar_t * __restrict__ _Format, ...);

  /* __attribute__((__format__(gnu_wprintf, 3, 0))) */ extern __MINGW_ATTRIB_NONNULL(3)
  int __cdecl __mingw_vsnwprintf(wchar_t * __restrict__ , size_t, const wchar_t * __restrict__ , va_list);
  /* __attribute__((__format__(gnu_wprintf, 2, 0))) */ extern __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __mingw_vswprintf(wchar_t * __restrict__ , const wchar_t * __restrict__ , va_list);
  /* __attribute__((__format__(gnu_wprintf, 2, 3))) */ extern __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __mingw_swprintf(wchar_t * __restrict__ , const wchar_t * __restrict__ , ...);
  /* __attribute__((__format__(gnu_wprintf, 3, 4))) */ extern __MINGW_ATTRIB_NONNULL(3)
  int __cdecl __mingw_snwprintf(wchar_t * __restrict__ s, size_t n, const wchar_t * __restrict__ format, ...);

  /* __attribute__((__format__(gnu_wscanf, 2, 0))) */ extern __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __mingw_vswscanf(const wchar_t * __restrict__ _Str, const wchar_t * __restrict__ Format, va_list argp);
  /* __attribute__((__format__(gnu_wscanf, 2, 3))) */ extern __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __mingw_swscanf(const wchar_t * __restrict__ _Src, const wchar_t * __restrict__ _Format, ...);

  /* __attribute__((__format__(ms_wprintf, 2, 3))) */ extern __MINGW_ATTRIB_NONNULL(2)
  int __cdecl __ms_fwprintf(FILE * __restrict__ _File, const wchar_t * __restrict__ _Format, ...);

  _CRTIMP int __cdecl __stdio_common_vfwprintf(unsigned __int64 options, FILE *file, const wchar_t *format, _locale_t locale, va_list valist);
  _CRTIMP int __cdecl __stdio_common_vfwprintf_s(unsigned __int64 _Options, FILE *_File, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vfwprintf_p(unsigned __int64 _Options, FILE *_Stream, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);

  __mingw_ovr int __cdecl _vfwprintf_l(FILE * __restrict__ _Stream, const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int __cdecl _vfwprintf_s_l(FILE * __restrict__ _Stream, const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
  }

#ifdef __MINGW_USE_SECAPI
  __mingw_ovr int __cdecl vfwprintf_s(FILE * __restrict__ _Stream, const wchar_t * __restrict__ _Format, va_list _ArgList)
  {
    return __stdio_common_vfwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, NULL, _ArgList);
  }
#endif

  __mingw_ovr int __cdecl _vfwprintf_p_l(FILE * __restrict__ _Stream, const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfwprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int __cdecl _vfwprintf_p(FILE * __restrict__ _Stream, const wchar_t * __restrict__ _Format, va_list _ArgList)
  {
    return __stdio_common_vfwprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, NULL, _ArgList);
  }

  __mingw_ovr int __cdecl _vwprintf_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int __cdecl _vwprintf_s_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, _Locale, _ArgList);
  }

#ifdef __MINGW_USE_SECAPI
  __mingw_ovr int __cdecl vwprintf_s(const wchar_t * __restrict__ _Format, va_list _ArgList)
  {
    return __stdio_common_vfwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, NULL, _ArgList);
  }
#endif

  __mingw_ovr int __cdecl _vwprintf_p_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfwprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int __cdecl _vwprintf_p(const wchar_t * __restrict__ _Format, va_list _ArgList)
  {
    return __stdio_common_vfwprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, NULL, _ArgList);
  }

  __mingw_ovr int __cdecl _fwprintf_l(FILE * __restrict__ _Stream, const wchar_t * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _fwprintf_s_l(FILE * __restrict__ _Stream, const wchar_t * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#ifdef __MINGW_USE_SECAPI
  __mingw_ovr int __cdecl fwprintf_s(FILE * __restrict__ _Stream, const wchar_t * __restrict__ _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
#endif

  __mingw_ovr int __cdecl _fwprintf_p_l(FILE * __restrict__ _Stream, const wchar_t * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfwprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _fwprintf_p(FILE * __restrict__ _Stream, const wchar_t * __restrict__ _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfwprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _wprintf_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _wprintf_s_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#ifdef __MINGW_USE_SECAPI
  __mingw_ovr int __cdecl wprintf_s(const wchar_t * __restrict__ _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
#endif

  __mingw_ovr int __cdecl _wprintf_p_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfwprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _wprintf_p(const wchar_t * __restrict__ _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfwprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  _CRTIMP int __cdecl __stdio_common_vfwscanf(unsigned __int64 options, FILE *file, const wchar_t *format, _locale_t locale, va_list valist);

  __mingw_ovr int __cdecl _vfwscanf_l(FILE * __restrict__ _Stream, const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int __cdecl _vfwscanf_s_l(FILE * __restrict__ _Stream, const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Stream, _Format, _Locale, _ArgList);
  }

#ifdef __MINGW_USE_SECAPI
  __mingw_ovr int __cdecl vfwscanf_s(FILE * __restrict__ _Stream, const wchar_t * __restrict__ _Format, va_list _ArgList)
  {
    return __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Stream, _Format, NULL, _ArgList);
  }
#endif

  __mingw_ovr int __cdecl _vwscanf_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, stdin, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int __cdecl _vwscanf_s_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, stdin, _Format, _Locale, _ArgList);
  }

#ifdef __MINGW_USE_SECAPI
  __mingw_ovr int __cdecl vwscanf_s(const wchar_t * __restrict__ _Format, va_list _ArgList)
  {
    return __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, stdin, _Format, NULL, _ArgList);
  }
#endif

  __mingw_ovr __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int __cdecl _fwscanf_l(FILE * __restrict__ _Stream, const wchar_t * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _fwscanf_s_l(FILE * __restrict__ _Stream, const wchar_t * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Stream, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#ifdef __MINGW_USE_SECAPI
  __mingw_ovr int __cdecl fwscanf_s(FILE * __restrict__ _Stream, const wchar_t * __restrict__ _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Stream, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
#endif

  __mingw_ovr __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int __cdecl _wscanf_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, stdin, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _wscanf_s_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, stdin, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#ifdef __MINGW_USE_SECAPI
  __mingw_ovr int __cdecl wscanf_s(const wchar_t * __restrict__ _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, stdin, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
#endif

  _CRTIMP int __cdecl __stdio_common_vswprintf(unsigned __int64 options, wchar_t *str, size_t len, const wchar_t *format, _locale_t locale, va_list valist);
  _CRTIMP int __cdecl __stdio_common_vswprintf_s(unsigned __int64 _Options, wchar_t *_Str, size_t _Len, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vsnwprintf_s(unsigned __int64 _Options, wchar_t *_Str, size_t _Len, size_t _MaxCount, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vswprintf_p(unsigned __int64 _Options, wchar_t *_Buffer, size_t _BufferCount, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList);

  __mingw_ovr __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int __cdecl _vsnwprintf_l(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int __cdecl _vsnwprintf_s_l(wchar_t * __restrict__ _Buffer, size_t _BufferCount, size_t _MaxCount, const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsnwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int __cdecl _vsnwprintf_s(wchar_t * __restrict__ _Buffer, size_t _BufferCount, size_t _MaxCount, const wchar_t * __restrict__ _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsnwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _MaxCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(int, _vsnwprintf_s, wchar_t, _Buffer, size_t, _BufferCount, const wchar_t *, _Format, va_list, _ArgList)

  extern int __cdecl _vsnwprintf(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, va_list _ArgList) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

  __mingw_ovr int __cdecl _vswprintf_c_l(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int __cdecl _vswprintf_c(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int __cdecl _vswprintf_l(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int __cdecl __vswprintf_l(wchar_t * __restrict__ _Buffer, const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int __cdecl _vswprintf(wchar_t * __restrict__ _Buffer, const wchar_t * __restrict__ _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, (size_t)-1, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int __cdecl _vswprintf_s_l(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

#ifdef __MINGW_USE_SECAPI
  __mingw_ovr int __cdecl vswprintf_s(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(int, vswprintf_s, wchar_t, _Buffer, const wchar_t *, _Format, va_list, _ArgList)
#endif

  __mingw_ovr int __cdecl _vswprintf_p_l(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int __cdecl _vswprintf_p(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int __cdecl _vscwprintf_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int __cdecl _vscwprintf(const wchar_t * __restrict__ _Format, va_list _ArgList)
  {
      int _Ret;
      _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, NULL, _ArgList);
      return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int __cdecl _vscwprintf_p_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int __cdecl _vscwprintf_p(const wchar_t * __restrict__ _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vswprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int __cdecl __swprintf_l(wchar_t * __restrict__ _Buffer, const wchar_t * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int __cdecl _swprintf_l(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int __cdecl _swprintf(wchar_t * __restrict__ _Buffer, const wchar_t * __restrict__ _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, (size_t)-1, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int __cdecl _swprintf_s_l(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

#ifdef __MINGW_USE_SECAPI
  __mingw_ovr int __cdecl swprintf_s(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, ...)
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

  __mingw_ovr int __cdecl _swprintf_p_l(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int __cdecl _swprintf_p(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int __cdecl _swprintf_c_l(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int __cdecl _swprintf_c(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int __cdecl _snwprintf_l(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  extern int __cdecl _snwprintf(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, ...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

  __mingw_ovr int __cdecl _snwprintf_s_l(wchar_t * __restrict__ _Buffer, size_t _BufferCount, size_t _MaxCount, const wchar_t * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsnwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int __cdecl _snwprintf_s(wchar_t * __restrict__ _Buffer, size_t _BufferCount, size_t _MaxCount, const wchar_t * __restrict__ _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vsnwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _MaxCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2_ARGLIST(int, _snwprintf_s, _vsnwprintf_s, wchar_t, _Buffer, size_t, _BufferCount, const wchar_t *, _Format)

  __mingw_ovr int __cdecl _scwprintf_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int __cdecl _scwprintf(const wchar_t * __restrict__ _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int __cdecl _scwprintf_p_l(const wchar_t * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int __cdecl _scwprintf_p(const wchar_t * __restrict__ _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  _CRTIMP int __cdecl __stdio_common_vswscanf(unsigned __int64 options, const wchar_t *input, size_t length, const wchar_t *format, _locale_t locale, va_list valist);

  __mingw_ovr int __cdecl _vswscanf_l(wchar_t * __restrict__ _Buffer, const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int __cdecl _vswscanf_s_l(wchar_t * __restrict__ _Buffer, const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
  }

#ifdef __MINGW_USE_SECAPI
  __mingw_ovr int __cdecl vswscanf_s(wchar_t * __restrict__ _Buffer, const wchar_t * __restrict__ _Format, va_list _ArgList)
  {
    return __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Buffer, (size_t)-1, _Format, NULL, _ArgList);
  }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(int, vswscanf_s, wchar_t, _Buffer, const wchar_t *, _Format, va_list, _ArgList)
#endif

  __mingw_ovr __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int __cdecl _vsnwscanf_l(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int __cdecl _vsnwscanf_s_l(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
  }

  __mingw_ovr __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int __cdecl _swscanf_l(wchar_t * __restrict__ _Buffer, const wchar_t * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _swscanf_s_l(wchar_t * __restrict__ _Buffer, const wchar_t * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#ifdef __MINGW_USE_SECAPI
  __mingw_ovr int __cdecl swscanf_s(wchar_t * __restrict__ _Buffer, const wchar_t * __restrict__ _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Buffer, (size_t)-1, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
#endif

  __mingw_ovr __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int __cdecl _snwscanf_l(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int __cdecl _snwscanf(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _snwscanf_s_l(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _snwscanf_s(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#if __USE_MINGW_ANSI_STDIO && !defined(_CRTBLD)

#if defined(__MINGW_USE_ISOC95) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)
  __mingw_ovr
  /* __attribute__((__format__(gnu_wprintf, 2, 0))) */ __MINGW_ATTRIB_NONNULL(2)
  int vfwprintf(FILE *__stream, const wchar_t *__format, __builtin_va_list __local_argv)
  {
    return __mingw_vfwprintf(__stream, __format, __local_argv);
  }

  __mingw_ovr
  /* __attribute__((__format__(gnu_wprintf, 1, 0))) */ __MINGW_ATTRIB_NONNULL(1)
  int vwprintf(const wchar_t *__format, __builtin_va_list __local_argv)
  {
    return __mingw_vfwprintf(stdout, __format, __local_argv);
  }

  __mingw_ovr
  /* __attribute__((__format__(gnu_wprintf, 2, 3))) */ __MINGW_ATTRIB_NONNULL(2)
  int fwprintf(FILE *__stream, const wchar_t *__format, ...)
  {
    int __retval;
    __builtin_va_list __local_argv;
    __builtin_va_start(__local_argv, __format);
    __retval = __mingw_vfwprintf(__stream, __format, __local_argv);
    __builtin_va_end(__local_argv);
    return __retval;
  }

  __mingw_ovr
  /* __attribute__((__format__(gnu_wprintf, 1, 2))) */ __MINGW_ATTRIB_NONNULL(1)
  int wprintf(const wchar_t *__format, ...)
  {
    int __retval;
    __builtin_va_list __local_argv;
    __builtin_va_start(__local_argv, __format);
    __retval = __mingw_vfwprintf(stdout, __format, __local_argv);
    __builtin_va_end(__local_argv);
    return __retval;
  }
#endif

#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)
  __mingw_ovr
  /* __attribute__((__format__(gnu_wscanf, 2, 0))) */ __MINGW_ATTRIB_NONNULL(2)
  int vfwscanf(FILE *__stream, const wchar_t *__format, __builtin_va_list __local_argv)
  {
    return __mingw_vfwscanf(__stream, __format, __local_argv);
  }

  __mingw_ovr
  /* __attribute__((__format__(gnu_wscanf, 1, 0))) */ __MINGW_ATTRIB_NONNULL(1)
  int vwscanf(const wchar_t *__format, __builtin_va_list __local_argv)
  {
    return __mingw_vfwscanf(stdin, __format, __local_argv);
  }
#endif

#if defined(__MINGW_USE_ISOC95) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)
  __mingw_ovr
  /* __attribute__((__format__(gnu_wscanf, 2, 3))) */ __MINGW_ATTRIB_NONNULL(2)
  int fwscanf(FILE *__stream, const wchar_t *__format, ...)
  {
    int __retval;
    __builtin_va_list __local_argv;
    __builtin_va_start(__local_argv, __format);
    __retval = __mingw_vfwscanf(__stream, __format, __local_argv);
    __builtin_va_end(__local_argv);
    return __retval;
  }

  __mingw_ovr
  /* __attribute__((__format__(gnu_wscanf, 1, 2))) */ __MINGW_ATTRIB_NONNULL(1)
  int wscanf(const wchar_t *__format, ...)
  {
    int __retval;
    __builtin_va_list __local_argv;
    __builtin_va_start(__local_argv, __format);
    __retval = __mingw_vfwscanf(stdin, __format, __local_argv);
    __builtin_va_end(__local_argv);
    return __retval;
  }
#endif

  __mingw_bos_ovr
  /* __attribute__((__format__(gnu_wprintf, 3, 0))) */ __MINGW_ATTRIB_NONNULL(3)
  int vsnwprintf(wchar_t *__stream, size_t __n, const wchar_t *__format, __builtin_va_list __local_argv)
  {
#if __MINGW_FORTIFY_LEVEL > 0
    __mingw_bos_ptr_chk_warn(__stream, __n * sizeof(wchar_t), 1);
#endif
    return __mingw_vsnwprintf(__stream, __n, __format, __local_argv);
  }

#if __MINGW_FORTIFY_VA_ARG

  int snwprintf(wchar_t *__stream, size_t __n, const wchar_t *__format, ...) __MINGW_ASM_CALL(__mingw_snwprintf);

  __mingw_bos_extern_ovr
  /* __attribute__((__format__(gnu_wprintf, 3, 4))) */ __MINGW_ATTRIB_NONNULL(3)
  int snwprintf(wchar_t *__stream, size_t __n, const wchar_t *__format, ...)
  {
    __mingw_bos_ptr_chk_warn(__stream, __n * sizeof(wchar_t), 1);
    return __mingw_snwprintf(__stream, __n, __format, __builtin_va_arg_pack());
  }

#else

  __mingw_ovr
  /* __attribute__((__format__(gnu_wprintf, 3, 4))) */ __MINGW_ATTRIB_NONNULL(3)
  int snwprintf(wchar_t *__stream, size_t __n, const wchar_t *__format, ...)
  {
    int __retval;
    __builtin_va_list __local_argv;
    __builtin_va_start(__local_argv, __format);
    __retval = __mingw_vsnwprintf(__stream, __n, __format, __local_argv);
    __builtin_va_end(__local_argv);
    return __retval;
  }

#endif  /* __MINGW_FORTIFY_VA_ARG */

#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)
  __mingw_ovr
  /* __attribute__((__format__(gnu_wscanf, 2, 0))) */ __MINGW_ATTRIB_NONNULL(2)
  int vswscanf(const wchar_t * __restrict__ __source, const wchar_t * __restrict__ __format, __builtin_va_list __local_argv)
  {
    return __mingw_vswscanf(__source, __format, __local_argv);
  }
#endif

#if defined(__MINGW_USE_ISOC95) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)
  __mingw_ovr
  /* __attribute__((__format__(gnu_wscanf, 2, 3))) */ __MINGW_ATTRIB_NONNULL(2)
  int swscanf(const wchar_t *__source, const wchar_t *__format, ...)
  {
    int __retval;
    __builtin_va_list __local_argv;
    __builtin_va_start(__local_argv, __format);
    __retval = __mingw_vswscanf(__source, __format, __local_argv);
    __builtin_va_end(__local_argv);
    return __retval;
  }
#endif

#else

#if defined(__MINGW_USE_ISOC95) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)
  __mingw_ovr
  __MINGW_ATTRIB_NONNULL(2)
  int __cdecl vfwprintf(FILE * __restrict__ _Stream, const wchar_t * __restrict__ _Format, va_list _ArgList)
  {
    return __stdio_common_vfwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, NULL, _ArgList);
  }

  __mingw_ovr
  __MINGW_ATTRIB_NONNULL(1)
  int __cdecl vwprintf(const wchar_t * __restrict__ _Format, va_list _ArgList)
  {
    return __stdio_common_vfwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, NULL, _ArgList);
  }

  extern __MINGW_ATTRIB_NONNULL(2)
  int __cdecl fwprintf(FILE * __restrict__ _Stream, const wchar_t * __restrict__ _Format, ...);

  __mingw_ovr
  __MINGW_ATTRIB_NONNULL(1)
  int __cdecl wprintf(const wchar_t * __restrict__ _Format, ...)
  {
    __builtin_va_list __ap;
    int __ret;
    __builtin_va_start(__ap, _Format);
    __ret = __stdio_common_vfwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, NULL, __ap);
    __builtin_va_end(__ap);
    return __ret;
  }
#endif

#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)
  __mingw_ovr
  __MINGW_ATTRIB_NONNULL(2)
  int vfwscanf(FILE *_Stream,  const wchar_t *_Format, va_list _ArgList)
  {
    return __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Stream, _Format, NULL, _ArgList);
  }

  __mingw_ovr
  __MINGW_ATTRIB_NONNULL(1)
  int vwscanf(const wchar_t *_Format, va_list _ArgList)
  {
    return __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, stdin, _Format, NULL, _ArgList);
  }
#endif

#if defined(__MINGW_USE_ISOC95) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)
  __mingw_ovr
  __MINGW_ATTRIB_NONNULL(2) __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int __cdecl fwscanf(FILE * __restrict__ _Stream, const wchar_t * __restrict__ _Format, ...)
  {
    __builtin_va_list __ap;
    int __ret;
    __builtin_va_start(__ap, _Format);
    __ret = __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Stream, _Format, NULL, __ap);
    __builtin_va_end(__ap);
    return __ret;
  }

  __mingw_ovr
  __MINGW_ATTRIB_NONNULL(1) __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int __cdecl wscanf(const wchar_t * __restrict__ _Format, ...)
  {
    __builtin_va_list __ap;
    int __ret;
    __builtin_va_start(__ap, _Format);
    __ret = __stdio_common_vfwscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, stdin, _Format, NULL, __ap);
    __builtin_va_end(__ap);
    return __ret;
  }
#endif

  __mingw_ovr
  __MINGW_ATTRIB_NONNULL(3)
  int __cdecl vsnwprintf(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, va_list _ArgList)
  {
    int __ret;
    __ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    return __ret < 0 ? -1 : __ret;
  }

  __mingw_ovr
  __MINGW_ATTRIB_NONNULL(3)
  int snwprintf(wchar_t * __restrict__ _Buffer, size_t _BufferCount, const wchar_t * __restrict__ _Format, ...)
  {
    __builtin_va_list __ap;
    int __ret;
    __builtin_va_start(__ap, _Format);
    __ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, _Buffer, _BufferCount, _Format, NULL, __ap);
    __builtin_va_end(__ap);
    return __ret;
  }

#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)
  __mingw_ovr
  __MINGW_ATTRIB_NONNULL(2)
  int vswscanf(const wchar_t * __restrict__ __source, const wchar_t * __restrict__ __format, va_list __local_argv)
  {
    return __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, __source, (size_t)-1, __format, NULL, __local_argv);
  }
#endif

#if defined(__MINGW_USE_ISOC95) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)
  __mingw_ovr
  __MINGW_ATTRIB_NONNULL(2) __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int __cdecl swscanf(const wchar_t * __restrict__ _Src, const wchar_t * __restrict__ _Format, ...)
  {
    __builtin_va_list __ap;
    int __ret;
    __builtin_va_start(__ap, _Format);
    __ret = __stdio_common_vswscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Src, (size_t)-1, _Format, NULL, __ap);
    __builtin_va_end(__ap);
    return __ret;
  }
#endif

#endif  /* __USE_MINGW_ANSI_STDIO */

#if defined(__MINGW_USE_ISOC95) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)
  __mingw_ovr
  /* __attribute__((__format__ (gnu_wprintf, 3, 0))) */ __MINGW_ATTRIB_NONNULL(3)
  int vswprintf(wchar_t *__stream, size_t __count, const wchar_t *__format, __builtin_va_list __local_argv)
  {
    return vsnwprintf(__stream, __count, __format, __local_argv);
  }

  __mingw_ovr
  /* __attribute__((__format__ (gnu_wprintf, 3, 4))) */ __MINGW_ATTRIB_NONNULL(3)
  int swprintf(wchar_t *__stream, size_t __count, const wchar_t *__format, ...)
  {
    int __retval;
    __builtin_va_list __local_argv;
    __builtin_va_start(__local_argv, __format);
    __retval = vsnwprintf(__stream, __count, __format, __local_argv);
    __builtin_va_end(__local_argv);
    return __retval;
  }
#endif

#ifdef __cplusplus

extern "C++"
{
  __mingw_ovr
  /* __attribute__((__format__(gnu_wprintf, 2, 0))) */ __MINGW_ATTRIB_NONNULL(2) __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int vswprintf(wchar_t *__stream, const wchar_t *__format, __builtin_va_list __local_argv)
  {
#if __USE_MINGW_ANSI_STDIO
  return __mingw_vswprintf(__stream, __format, __local_argv);
#else
  return _vswprintf(__stream, __format, __local_argv);
#endif
  }

  __mingw_ovr
  /* __attribute__((__format__(gnu_wprintf, 2, 3))) */ __MINGW_ATTRIB_NONNULL(2) __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int swprintf(wchar_t *__stream, const wchar_t *__format, ...)
  {
    int __retval;
    __builtin_va_list __local_argv;
    __builtin_va_start(__local_argv, __format);
    __retval = vswprintf(__stream, __format, __local_argv);
    __builtin_va_end(__local_argv);
    return __retval;
  }

  __mingw_ovr __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int _vswprintf_l(wchar_t *_Buffer, const wchar_t *_Format, _locale_t _Locale, va_list _ArgList)
  {
    return _vswprintf_l(_Buffer, (size_t)-1, _Format, _Locale, _ArgList);
  }

  __mingw_ovr __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int _swprintf_l(wchar_t *_Buffer, const wchar_t *_Format, _locale_t _Locale, ...)
  {
    int _Ret;
    __builtin_va_list _ArgList;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }
}

#elif defined(_CRT_NON_CONFORMING_SWPRINTFS)

#if defined(__MINGW_USE_ISOC95) || defined(__MINGW_USE_UNIX98)
# if __USE_MINGW_ANSI_STDIO
#   define swprintf  __mingw_swprintf
#   define vswprintf __mingw_vswprintf
# else
#   define swprintf  _swprintf
#   define vswprintf _vswprintf
# endif
#endif
#define _swprintf_l  __swprintf_l
#define _vswprintf_l __vswprintf_l

#endif  /* __cplusplus */

#ifndef WEOF
# define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(void);
  _CRTIMP wint_t __cdecl fputwc(wchar_t _Ch, FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  _CRTIMP wint_t __cdecl getwc(FILE *_File);
  _CRTIMP wint_t __cdecl getwchar(void);
  _CRTIMP wchar_t *__cdecl fgetws(wchar_t * __restrict__ _Dst, int _SizeInWords, FILE * __restrict__ _File);
  _CRTIMP int __cdecl fputws(const wchar_t * __restrict__ _Str, FILE * __restrict__ _File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str, size_t _SizeInWords);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(wchar_t *, _getws_s, wchar_t, _DstBuf)
  _CRTIMP wint_t __cdecl putwc(wchar_t _Ch, FILE *_File);
  _CRTIMP wint_t __cdecl putwchar(wchar_t _Ch);
  _CRTIMP int __cdecl _putws(const wchar_t *_Str);
  _CRTIMP wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  _CRTIMP FILE *__cdecl _wfdopen(int _FileHandle, const wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(const wchar_t * __restrict__ _Filename, const wchar_t *__restrict__  _Mode) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _wfopen_s(FILE **_File,const wchar_t *_Filename,const wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(const wchar_t * __restrict__ _Filename, const wchar_t * __restrict__ _Mode, FILE * __restrict__ _OldFile) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _wfreopen_s(FILE **_File, const wchar_t *_Filename, const wchar_t *_Mode, FILE *_OldFile);
  _CRTIMP FILE *__cdecl _wfsopen(const wchar_t *_Filename, const wchar_t *_Mode, int _ShFlag);
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
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _wtmpnam_s(wchar_t *_DstBuf, size_t _SizeInWords);
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

  /**
   * __mingw_str_wide_utf8
   * Converts a null terminated UCS-2 string to a multibyte (UTF-8) equivalent.
   * Caller is supposed to free allocated buffer with __mingw_str_free().
   * @param[in] wptr Pointer to wide string.
   * @param[out] mbptr Pointer to multibyte string.
   * @param[out] buflen Optional parameter for length of allocated buffer.
   * @return Number of characters converted, 0 for failure.
   *
   * WideCharToMultiByte - http://msdn.microsoft.com/en-us/library/dd374130(VS.85).aspx
   */
  extern int __cdecl __mingw_str_wide_utf8(const wchar_t * const wptr, char **mbptr, size_t * buflen);

  /**
   * __mingw_str_utf8_wide
   * Converts a null terminated UTF-8 string to a UCS-2 equivalent.
   * Caller is supposed to free allocated buffer with __mingw_str_free().
   * @param[out] mbptr Pointer to multibyte string.
   * @param[in] wptr Pointer to wide string.
   * @param[out] buflen Optional parameter for length of allocated buffer.
   * @return Number of characters converted, 0 for failure.
   *
   * MultiByteToWideChar - http://msdn.microsoft.com/en-us/library/dd319072(VS.85).aspx
   */

  extern int __cdecl __mingw_str_utf8_wide(const char *const mbptr, wchar_t ** wptr, size_t * buflen);

  /**
   * __mingw_str_free
   * Frees buffer create by __mingw_str_wide_utf8 and __mingw_str_utf8_wide.
   * @param[in] ptr memory block to free.
   *
   */
  extern void __cdecl __mingw_str_free(void *ptr);

__MINGW_END_C_DECLS

#pragma pop_macro("snwprintf")
#pragma pop_macro("vsnwprintf")

#pragma pack(pop)

#endif  /* _INC_CORECRT_WSTDIO */
