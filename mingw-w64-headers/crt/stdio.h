/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_STDIO
#define _INC_STDIO

#include <corecrt.h>
#include <corecrt_wstdio.h>
#include <sys/types.h>

#pragma push_macro("snprintf")
#undef snprintf
#pragma push_macro("vsnprintf")
#undef vsnprintf

__MINGW_BEGIN_C_DECLS

#define BUFSIZ       512
#define _NFILE       _NSTREAM_
#define _NSTREAM_    512
#define _IOB_ENTRIES 3
#define EOF          (-1)

#define _IOFBF 0x0000
#define _IOLBF 0x0040
#define _IONBF 0x0004

#define _P_tmpdir   "\\"
#define _wP_tmpdir L"\\"

#define L_tmpnam   260
#ifdef __MINGW_USE_SECAPI
# define L_tmpnam_s L_tmpnam
#endif

#ifdef __MINGW_USE_POSIX
# define L_ctermid 9
#endif
#if !defined(__MINGW_USE_XOPEN2K) || defined(__MINGW_USE_GNU)
# define L_cuserid 32
#endif

#define SEEK_CUR 1
#define SEEK_END 2
#define SEEK_SET 0

#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#define FILENAME_MAX 260
#define FOPEN_MAX    20
#define _SYS_OPEN    20
#define TMP_MAX      2147483647
#ifdef __MINGW_USE_SECAPI
# define  TMP_MAX_S TMP_MAX
# define _TMP_MAX_S TMP_MAX
#endif

#ifndef _FPOS_T_DEFINED
# define _FPOS_T_DEFINED
# undef _FPOSOFF
  __MINGW_EXTENSION typedef __int64 fpos_t;
# define _FPOSOFF(fp) ((long)(fp))
#endif

  _CRTIMP int __cdecl __stdio_common_vfprintf(unsigned __int64 _Options, FILE *_Stream, const char *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vfprintf_s(unsigned __int64 _Options, FILE *_Stream, const char *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vfprintf_p(unsigned __int64 _Options, FILE *_Stream, const char *_Format, _locale_t _Locale, va_list _ArgList);

  __mingw_ovr
  int _vfprintf_l(FILE *__restrict _Stream, const char *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
  }

  __mingw_ovr
  int _vfprintf_s_l(FILE *__restrict _Stream, const char *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int vfprintf_s(FILE *__restrict _Stream, const char *__restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, NULL, _ArgList);
  }

#endif

  __mingw_ovr
  int _vfprintf_p_l(FILE *__restrict _Stream, const char *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
  }

  __mingw_ovr
  int _vfprintf_p(FILE *__restrict _Stream, const char *__restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, NULL, _ArgList);
  }

  __mingw_ovr
  int _vprintf_l(const char *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, _Locale, _ArgList);
  }

  __mingw_ovr
  int _vprintf_s_l(const char *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, _Locale, _ArgList);
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int vprintf_s(const char *__restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, NULL, _ArgList);
  }

#endif

  __mingw_ovr
  int _vprintf_p_l(const char *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, _Locale, _ArgList);
  }

  __mingw_ovr
  int _vprintf_p(const char *__restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, NULL, _ArgList);
  }

  __mingw_ovr
  int _fprintf_l(FILE *__restrict _Stream, const char *__restrict _Format, _locale_t _Locale, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

  _CRTIMP int __cdecl _set_printf_count_output(int _Value);
  _CRTIMP int __cdecl _get_printf_count_output(void);

  __mingw_ovr
  int _fprintf_s_l(FILE *__restrict _Stream, const char *__restrict _Format, _locale_t _Locale, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int fprintf_s(FILE *__restrict _Stream, const char *__restrict _Format, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

#endif

  __mingw_ovr
  int _fprintf_p_l(FILE *__restrict _Stream, const char *__restrict _Format, _locale_t _Locale, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr
  int _fprintf_p(FILE *__restrict _Stream, const char *__restrict _Format, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr
  int _printf_l(const char *__restrict _Format, _locale_t _Locale, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, _Locale, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr
  int _printf_s_l(const char *__restrict _Format, _locale_t _Locale, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, _Locale, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int printf_s(const char *__restrict _Format, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

#endif

  __mingw_ovr
  int _printf_p_l(const char *__restrict _Format, _locale_t _Locale, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, _Locale, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr
  int _printf_p(const char *__restrict _Format, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

  _CRTIMP int __cdecl __stdio_common_vfscanf(unsigned __int64 _Options, FILE *_Stream, const char *_Format, _locale_t _Locale, va_list _Arglist);

  __mingw_ovr
  int _vfscanf_l(FILE *__restrict _Stream, const char *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
  }

  __mingw_ovr
  int _vfscanf_s_l(FILE *__restrict _Stream, const char *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Stream, _Format, _Locale, _ArgList);
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int vfscanf_s(FILE *__restrict _Stream, const char *__restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Stream, _Format, NULL, _ArgList);
  }

#endif

  __mingw_ovr
  int _vscanf_l(const char *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, stdin, _Format, _Locale, _ArgList);
  }

  __mingw_ovr
  int _vscanf_s_l(const char *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, stdin, _Format, _Locale, _ArgList);
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int vscanf_s(const char *__restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, stdin, _Format, NULL, _ArgList);
  }

#endif

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _fscanf_l(FILE *__restrict _Stream, const char *__restrict _Format, _locale_t _Locale, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr
  int _fscanf_s_l(FILE *__restrict _Stream, const char *__restrict _Format, _locale_t _Locale, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Stream, _Format, _Locale, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int fscanf_s(FILE *__restrict _Stream, const char *__restrict _Format, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Stream, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

#endif

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _scanf_l(const char *__restrict _Format, _locale_t _Locale, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, stdin, _Format, _Locale, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr
  int _scanf_s_l(const char *__restrict _Format, _locale_t _Locale, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, stdin, _Format, _Locale, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int scanf_s(const char *__restrict _Format, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, stdin, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

#endif

  _CRTIMP int __cdecl __stdio_common_vsprintf(unsigned __int64 _Options, char *_Buffer, size_t _BufferCount, const char *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vsprintf_s(unsigned __int64 _Options, char *_Buffer, size_t _BufferCount, const char *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vsnprintf_s(unsigned __int64 _Options, char *_Buffer, size_t _BufferCount, size_t _MaxCount, const char *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vsprintf_p(unsigned __int64 _Options, char *_Buffer, size_t _BufferCount, const char *_Format, _locale_t _Locale, va_list _ArgList);

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _vsnprintf_l(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr __MINGW_GNU_PRINTF(3, 0) __NONNULL((3))
  __NTH_FNC(int _vsnprintf(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, va_list _ArgList))
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _vsprintf_l(char *__restrict _Buffer, const char *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _vsprintf_s_l(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int vsprintf_s(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(int, vsprintf_s, char, _Buffer, const char *, _Format, va_list, _ArgList)

#endif

  __mingw_ovr
  int _vsprintf_p_l(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _vsprintf_p(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _vsnprintf_s_l(char *__restrict _Buffer, size_t _BufferCount, size_t _MaxCount, const char *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsnprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _vsnprintf_s(char *__restrict _Buffer, size_t _BufferCount, size_t _MaxCount, const char *__restrict _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsnprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _MaxCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(int, _vsnprintf_s, char, _Buffer, size_t, _BufferCount, const char *, _Format, va_list, _ArgList)

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int vsnprintf_s(char *__restrict _Buffer, size_t _BufferCount, size_t _MaxCount, const char *__restrict _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsnprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _MaxCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(int, vsnprintf_s, char, _Buffer, size_t, _BufferCount, const char *, _Format, va_list, _ArgList)

#endif

  __mingw_ovr
  int _vscprintf_l(const char *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr __PURE __MINGW_GNU_PRINTF(1, 0) __NONNULL((1))
  int _vscprintf(const char *__restrict _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _vscprintf_p_l(const char *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _vscprintf_p(const char *__restrict _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _vsnprintf_c_l(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _vsnprintf_c(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _sprintf_l(char *__restrict _Buffer, const char *__restrict _Format, _locale_t _Locale, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _sprintf_s_l(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, _locale_t _Locale, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int sprintf_s(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vsprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1_ARGLIST(int, sprintf_s, vsprintf_s, char, _Buffer, const char *, _Format)

#endif

  __mingw_ovr
  int _sprintf_p_l(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, _locale_t _Locale, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _sprintf_p(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vsprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _snprintf_l(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, _locale_t _Locale, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr __MINGW_GNU_PRINTF(3, 4) __NONNULL((3)) __MINGW_DEPRECATED_SEC_WARN
  __NTH_FNC(int _snprintf(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, ...))
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _snprintf_c_l(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, _locale_t _Locale, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _snprintf_c(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _snprintf_s_l(char *__restrict _Buffer, size_t _BufferCount, size_t _MaxCount, const char *__restrict _Format, _locale_t _Locale, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsnprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _snprintf_s(char *__restrict _Buffer, size_t _BufferCount, size_t _MaxCount, const char *__restrict _Format, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vsnprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Buffer, _BufferCount, _MaxCount, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2_ARGLIST(int, _snprintf_s, _vsnprintf_s, char, _Buffer, size_t, _BufferCount, const char *, _Format)

  __mingw_ovr
  int _scprintf_l(const char *__restrict _Format, _locale_t _Locale, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, _Locale, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr __PURE __MINGW_GNU_PRINTF(1, 2) __NONNULL((1))
  int _scprintf(const char *__restrict _Format, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _scprintf_p_l(const char *__restrict _Format, _locale_t _Locale, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, _Locale, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr
  int _scprintf_p(const char *__restrict _Format, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vsprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  _CRTIMP int __cdecl __stdio_common_vsscanf(unsigned __int64 _Options, const char *_Buffer, size_t _BufferCount, const char *_Format, _locale_t _Locale, va_list _ArgList);

  __mingw_ovr
  int _vsscanf_l(const char *__restrict _Buffer, const char *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vsscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
  }

  __mingw_ovr
  int _vsscanf_s_l(const char *__restrict _Buffer, const char *__restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vsscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int vsscanf_s(const char *__restrict _Buffer, const char *__restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vsscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Buffer, (size_t)-1, _Format, NULL, _ArgList);
  }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(int, vsscanf_s, const char, _Buffer, const char *, _Format, va_list, _ArgList)

#endif

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _sscanf_l(const char *__restrict _Buffer, const char *__restrict _Format, _locale_t _Locale, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr
  int _sscanf_s_l(const char *__restrict _Buffer, const char *__restrict _Format, _locale_t _Locale, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr
  int sscanf_s(const char *__restrict _Buffer, const char *__restrict _Format, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vsscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Buffer, (size_t)-1, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

#endif

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _snscanf_l(const char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, _locale_t _Locale, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr __MINGW_GNU_SCANF(3, 4) __NONNULL((3)) __MINGW_DEPRECATED_SEC_WARN
  int _snscanf(const char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vsscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr
  int _snscanf_s_l(const char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, _locale_t _Locale, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr
  int _snscanf_s(const char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vsscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"

#undef __builtin_vsnprintf
#undef __builtin_vsprintf

  extern int __cdecl vfprintf(FILE *__restrict _Stream, const char *__restrict _Format, va_list _ArgList)
    __MINGW_GNU_PRINTF(2, 0) __NONNULL((1, 2));
  extern int __cdecl vprintf(const char *__restrict _Format, va_list _ArgList)
    __MINGW_GNU_PRINTF(1, 0) __NONNULL((1));
  extern int __cdecl fprintf(FILE *__restrict _Stream, const char *__restrict _Format, ...)
    __MINGW_GNU_PRINTF(2, 3) __NONNULL((1, 2));
  extern int __cdecl printf(const char *__restrict _Format, ...)
    __MINGW_GNU_PRINTF(1, 2) __NONNULL((1));

#ifndef __CRT__NO_INLINE

  __CRT_INLINE __MINGW_GNU_PRINTF(2, 0) __NONNULL((1, 2))
  int __cdecl vfprintf(FILE *__restrict _Stream, const char *__restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, NULL, _ArgList);
  }

  __CRT_INLINE __MINGW_GNU_PRINTF(1, 0) __NONNULL((1))
  int __cdecl vprintf(const char *__restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, NULL, _ArgList);
  }

  __CRT_INLINE __MINGW_GNU_PRINTF(2, 3) __NONNULL((1, 2))
  int __cdecl fprintf(FILE *__restrict _Stream, const char *__restrict _Format, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

  __CRT_INLINE __MINGW_GNU_PRINTF(1, 2) __NONNULL((1))
  int __cdecl printf(const char *__restrict _Format, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, stdout, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

#endif  /* __CRT__NO_INLINE */

#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)

  extern int __cdecl vfscanf(FILE *__restrict _Stream,  const char *__restrict _Format, va_list _ArgList)
    __MINGW_GNU_SCANF(2, 0) __WUR_FORTIFY __NONNULL((1, 2));
  extern int __cdecl vscanf(const char *__restrict _Format, va_list _ArgList)
    __MINGW_GNU_SCANF(1, 0) __WUR_FORTIFY __NONNULL((1));

#ifndef __CRT__NO_INLINE

  __CRT_INLINE __MINGW_GNU_SCANF(2, 0) __WUR_FORTIFY __NONNULL((1, 2))
  int __cdecl vfscanf(FILE *__restrict _Stream,  const char *__restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Stream, _Format, NULL, _ArgList);
  }

  __CRT_INLINE __MINGW_GNU_SCANF(1, 0) __WUR_FORTIFY __NONNULL((1))
  int __cdecl vscanf(const char *__restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, stdin, _Format, NULL, _ArgList);
  }

#endif  /* __CRT__NO_INLINE */

#endif  /* defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX) */

  extern int __cdecl fscanf(FILE *__restrict _Stream, const char *__restrict _Format, ...)
    __MINGW_GNU_SCANF(2, 3) __WUR_FORTIFY __NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN;
  extern int __cdecl scanf(const char *__restrict _Format, ...)
    __MINGW_GNU_SCANF(1, 2) __WUR_FORTIFY __NONNULL((1)) __MINGW_DEPRECATED_SEC_WARN;

#ifndef __CRT__NO_INLINE

  __CRT_INLINE __MINGW_GNU_SCANF(2, 3) __NONNULL((1, 2)) __WUR_FORTIFY __MINGW_DEPRECATED_SEC_WARN
  int __cdecl fscanf(FILE *__restrict _Stream, const char *__restrict _Format, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Stream, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

  __CRT_INLINE __MINGW_GNU_SCANF(1, 2) __NONNULL((1)) __WUR_FORTIFY __MINGW_DEPRECATED_SEC_WARN
  int __cdecl scanf(const char *__restrict _Format, ...)
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, stdin, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

#endif  /* __CRT__NO_INLINE */

#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)

  extern int __cdecl vsnprintf(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, va_list _ArgList)
    __NOTHROW __MINGW_GNU_PRINTF(3, 0) __NONNULL((3));
  extern int __cdecl snprintf(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, ...)
    __NOTHROW __MINGW_GNU_PRINTF(3, 4) __NONNULL((3));

#ifndef __CRT__NO_INLINE

#if __MINGW_FORTIFY_LEVEL == 0

  __CRT_INLINE __MINGW_GNU_PRINTF(3, 0) __NONNULL((3))
  __NTH_FNC(int __cdecl vsnprintf(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, va_list _ArgList))
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __CRT_INLINE __MINGW_GNU_PRINTF(3, 4) __NONNULL((3))
  __NTH_FNC(int __cdecl snprintf(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, ...))
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

#endif  /* __MINGW_FORTIFY_LEVEL == 0 */

#endif  /* __CRT__NO_INLINE */

#endif  /* defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX) */

  extern int __cdecl vsprintf(char *__restrict _Buffer, const char *__restrict _Format, va_list _ArgList)
    __NOTHROW __MINGW_GNU_PRINTF(2, 0) __NONNULL((2)) __MINGW_DEPRECATED_SEC_WARN;
  extern int __cdecl sprintf(char *__restrict _Buffer, const char *__restrict _Format, ...)
    __NOTHROW __MINGW_GNU_PRINTF(2, 3) __NONNULL((2)) __MINGW_DEPRECATED_SEC_WARN;

#ifndef __CRT__NO_INLINE

#if __MINGW_FORTIFY_LEVEL == 0

  __CRT_INLINE __MINGW_GNU_PRINTF(2, 0) __NONNULL((2)) __MINGW_DEPRECATED_SEC_WARN
  __NTH_FNC(int __cdecl vsprintf(char *__restrict _Buffer, const char *__restrict _Format, va_list _ArgList))
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, _Buffer, (size_t)-1, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __CRT_INLINE __MINGW_GNU_PRINTF(2, 3) __NONNULL((2)) __MINGW_DEPRECATED_SEC_WARN
  __NTH_FNC(int __cdecl sprintf(char *__restrict _Buffer, const char *__restrict _Format, ...))
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, _Buffer, (size_t)-1, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

#endif  /* __MINGW_FORTIFY_LEVEL == 0 */

#endif  /* __CRT__NO_INLINE */

#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)

  extern int __cdecl vsscanf(const char *__restrict _Buffer, const char *__restrict _Format, va_list _ArgList)
    __NOTHROW __MINGW_GNU_SCANF(2, 0) __NONNULL((2));

#ifndef __CRT__NO_INLINE

  __CRT_INLINE __MINGW_GNU_SCANF(2, 0) __NONNULL((2))
  __NTH_FNC(int __cdecl vsscanf(const char *__restrict _Buffer, const char *__restrict _Format, va_list _ArgList))
  {
    return __stdio_common_vsscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Buffer, (size_t)-1, _Format, NULL, _ArgList);
  }

#endif  /* __CRT__NO_INLINE */

#endif  /* defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX) */

  extern int __cdecl sscanf(const char *__restrict _Buffer, const char *__restrict _Format, ...)
    __NOTHROW __MINGW_GNU_SCANF(2, 3) __NONNULL((2)) __MINGW_DEPRECATED_SEC_WARN;

#ifndef __CRT__NO_INLINE

  __CRT_INLINE __MINGW_GNU_SCANF(2, 3) __NONNULL((2)) __MINGW_DEPRECATED_SEC_WARN
  __NTH_FNC(int __cdecl sscanf(const char *__restrict _Buffer, const char *__restrict _Format, ...))
  {
    va_list _ArgList;
    int _Ret;
    __crt_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vsscanf(_CRT_INTERNAL_LOCAL_SCANF_OPTIONS, _Buffer, (size_t)-1, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Ret;
  }

#endif  /* __CRT__NO_INLINE */

#if defined(__MINGW_USE_MISC) || defined(__MINGW_USE_LIB_EXT2) || defined(__MINGW_USE_XOPEN2K24)

  extern int __cdecl vasprintf(char **__restrict _Strp, const char *__restrict _Format, va_list _ArgList)
    __NOTHROW __MINGW_GNU_PRINTF(2, 0) __NONNULL((1, 2)) __WUR_FORTIFY;
  extern int __cdecl asprintf(char **__restrict _Strp, const char *__restrict _Format, ...)
    __NOTHROW __MINGW_GNU_PRINTF(2, 3) __NONNULL((1, 2)) __WUR_FORTIFY;

#endif  /* defined(__MINGW_USE_MISC) || defined(__MINGW_USE_LIB_EXT2) || defined(__MINGW_USE_XOPEN2K24) */

#pragma GCC diagnostic pop

  _CRTIMP errno_t __cdecl _get_stream_buffer_pointers(FILE *_Stream, char ***_Base, char ***_Pointer, int **_Count);

  _CRTIMP void    __cdecl  clearerr(FILE *_File) __NOTHROW __NONNULL((1));
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl  clearerr_s(FILE *_File);
#endif
  _CRTIMP int     __cdecl  fclose(FILE *_File) __NONNULL((1));
#ifndef __MINGW_USE_FOB64
  _CRTIMP FILE   *__cdecl  fopen(const char *__restrict _Filename, const char *__restrict _Mode) __ATTR_MALLOC __ATTR_DEALLOC(fclose, 1) __WUR_FORTIFY __MINGW_DEPRECATED_SEC_WARN;
#else
  _CRTIMP FILE   *__cdecl  fopen(const char *__restrict _Filename, const char *__restrict _Mode) __ASM_CALL(fopen64) __ATTR_MALLOC __WUR_FORTIFY __ATTR_DEALLOC(fclose, 1) __MINGW_DEPRECATED_SEC_WARN;
#endif
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl  fopen_s(FILE **_File, const char *_Filename, const char *_Mode);
  _CRTIMP size_t  __cdecl  fread_s(void *_DstBuf, size_t _DstSize, size_t _ElementSize, size_t _Count, FILE *_File);
#endif
#ifndef __MINGW_USE_FOB64
  _CRTIMP FILE   *__cdecl  freopen(const char *__restrict _Filename, const char *__restrict _Mode, FILE *__restrict _File) __WUR_FORTIFY __NONNULL((3)) __MINGW_DEPRECATED_SEC_WARN;
#else
  _CRTIMP FILE   *__cdecl  freopen(const char *__restrict _Filename, const char *__restrict _Mode, FILE *__restrict _File) __ASM_CALL(freopen64) __WUR_FORTIFY __NONNULL((3)) __MINGW_DEPRECATED_SEC_WARN;
#endif
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl  freopen_s(FILE **_File, const char *_Filename, const char *_Mode, FILE *_Stream);
#endif
#ifdef __MINGW_USE_DEPRECATED_GETS
  _CRTIMP char   *__cdecl  gets(char *_Buffer) __WUR_FORTIFY __ATTR_WARN("Using gets() is always unsafe - use fgets() instead");
#endif
#ifdef __MINGW_USE_SECAPI
  _CRTIMP char   *__cdecl  gets_s(char *_Buffer, rsize_t _Size);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(char *, gets_s, char, _Buffer)
#endif
#ifndef __MINGW_USE_FOB64
  _CRTIMP FILE   *__cdecl  tmpfile(void) __ATTR_MALLOC __ATTR_DEALLOC(fclose, 1) __WUR_FORTIFY __MINGW_DEPRECATED_SEC_WARN;
#else
  _CRTIMP FILE   *__cdecl  tmpfile(void) __ASM_CALL(tmpfile64) __ATTR_MALLOC __ATTR_DEALLOC(fclose, 1) __WUR_FORTIFY __MINGW_DEPRECATED_SEC_WARN;
#endif
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl  tmpfile_s(FILE **_File);
#endif
  _CRTIMP char   *__cdecl  tmpnam(char *_Buffer) __NOTHROW __WUR_FORTIFY;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl  tmpnam_s(char *_Buffer, rsize_t _Size);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, tmpnam_s, char, _Buffer)
#endif
  _CRTIMP int     __cdecl _fcloseall(void);
#if defined(__MINGW_USE_POSIX) || defined(__MINGW_USE_MS)
# ifndef __MINGW_USE_FOB64
  _CRTIMP FILE   *__cdecl  fdopen(int _FileHandle, const char *_Mode) __NOTHROW __ATTR_MALLOC __ATTR_DEALLOC(fclose, 1) __WUR_FORTIFY __MINGW_DEPRECATED_MSVC2005;
# else
  _CRTIMP FILE   *__cdecl  fdopen(int _FileHandle, const char *_Mode) __ASM_CALL_NTH(fdopen64) __ATTR_MALLOC __ATTR_DEALLOC(fclose, 1) __WUR_FORTIFY __MINGW_DEPRECATED_MSVC2005;
# endif
#endif
  _CRTIMP FILE   *__cdecl _fdopen(int _FileHandle, const char *_Mode) __NOTHROW __ATTR_MALLOC __ATTR_DEALLOC(fclose, 1) __WUR_FORTIFY;
  _CRTIMP int     __cdecl  feof(FILE *_File)   __NOTHROW __WUR_FORTIFY __NONNULL((1));
  _CRTIMP int     __cdecl  ferror(FILE *_File) __NOTHROW __WUR_FORTIFY __NONNULL((1));
  _CRTIMP int     __cdecl  fflush(FILE *_File);
  _CRTIMP int     __cdecl  fgetc(FILE *_File) __NONNULL((1));
  _CRTIMP int     __cdecl _fgetchar(void);
#ifndef __MINGW_USE_FOB64
  _CRTIMP int     __cdecl  fgetpos(FILE *__restrict _File , fpos_t *__restrict _Pos) __NONNULL((1));
#else
  _CRTIMP int     __cdecl  fgetpos(FILE *__restrict _File , fpos_t *__restrict _Pos) __ASM_CALL(fgetpos64) __NONNULL((1));
#endif
  _CRTIMP char   *__cdecl  fgets(char *__restrict _Buf, int _MaxCount, FILE *__restrict _File) __WUR_FORTIFY __NONNULL((3));
#if defined(__MINGW_USE_POSIX) || defined(__MINGW_USE_MS)
  _CRTIMP int     __cdecl  fileno(FILE *_File) __NOTHROW __WUR_FORTIFY __NONNULL((1)) __MINGW_DEPRECATED_MSVC2005;
#endif
  _CRTIMP int     __cdecl _fileno(FILE *_File) __NOTHROW __WUR_FORTIFY __NONNULL((1));
  _CRTIMP int     __cdecl _flushall(void);
  _CRTIMP int     __cdecl  fputc(int _Ch, FILE *_File) __NONNULL((2));
  _CRTIMP int     __cdecl _fputchar(int _Ch);
  _CRTIMP int     __cdecl  fputs(const char *__restrict _Str, FILE *__restrict _File) __NONNULL((2));
  _CRTIMP size_t  __cdecl  fread(void *__restrict _DstBuf, size_t _ElementSize, size_t _Count, FILE *__restrict _File) __WUR_FORTIFY __NONNULL((4));
  _CRTIMP FILE   *__cdecl _fsopen(const char *_Filename, const char *_Mode, int _ShFlag);
#ifndef __MINGW_USE_FOB64
  _CRTIMP int     __cdecl  fsetpos(FILE *_File, const fpos_t *_Pos) __NONNULL((1));
#else
  _CRTIMP int     __cdecl  fsetpos(FILE *_File, const fpos_t *_Pos) __ASM_CALL(fsetpos64) __NONNULL((1));
#endif
  _CRTIMP int     __cdecl  fseek(FILE *_File, long _Offset, int _Origin)       __NONNULL((1));
  _CRTIMP int     __cdecl _fseeki64(FILE *_File, __int64 _Offset, int _Origin) __NONNULL((1));
  _CRTIMP long    __cdecl  ftell(FILE *_File)                      __WUR_FORTIFY __NONNULL((1));
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _ftelli64(FILE *_File) __WUR_FORTIFY __NONNULL((1));
  _CRTIMP size_t  __cdecl  fwrite(const void *__restrict _Str, size_t _Size, size_t _Count, FILE *__restrict _File) __NONNULL((4));
  _CRTIMP int     __cdecl  getc(FILE *_File) __NONNULL((1));
  _CRTIMP int     __cdecl  getchar(void);
  _CRTIMP int     __cdecl _getmaxstdio(void);
  _CRTIMP int     __cdecl _getw(FILE *_File) __NONNULL((1));
#ifndef _CRT_PERROR_DEFINED  /* Also in stdlib.h */
# define _CRT_PERROR_DEFINED
  _CRTIMP void __cdecl perror(const char *_ErrMsg) __COLD;
#endif  /* _CRT_PERROR_DEFINED */
#ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
  _CRTIMP int   __cdecl _pclose(FILE *_File) __NONNULL((1));
  _CRTIMP FILE *__cdecl _popen(const char *_Command, const char *_Mode) __ATTR_MALLOC __ATTR_DEALLOC(_pclose, 1) __WUR_FORTIFY;
# ifdef __MINGW_USE_POSIX2
#   ifndef popen
#     define popen  _popen
#     define pclose _pclose
#   endif
# endif
#endif  /* _CRT_USE_WINAPI_FAMILY_DESKTOP_APP */
  _CRTIMP int __cdecl  putc(int _Ch, FILE *_File) __NONNULL((2));
  _CRTIMP int __cdecl  putchar(int _Ch);
  _CRTIMP int __cdecl  puts(const char *_Str);
  _CRTIMP int __cdecl _putw(int _Word, FILE *_File) __NONNULL((2));
#ifndef _CRT_DIRECTORY_DEFINED  /* Also in io.h */
# define _CRT_DIRECTORY_DEFINED
  _CRTIMP int __cdecl  remove(const char *_Filename) __NOTHROW;
  _CRTIMP int __cdecl  rename(const char *_OldFilename, const char *_NewFilename) __NOTHROW;
  _CRTIMP int __cdecl _unlink(const char *_Filename) __NOTHROW __NONNULL((1));
#ifdef __MINGW_USE_MS
  _CRTIMP int __cdecl  unlink(const char *_Filename) __NOTHROW __NONNULL((1)) __MINGW_DEPRECATED_MSVC2005;
#endif
#endif  /* _CRT_DIRECTORY_DEFINED */
  _CRTIMP void  __cdecl  rewind(FILE *_File) __NONNULL((1));
  _CRTIMP int   __cdecl _rmtmp(void);
  _CRTIMP void  __cdecl  setbuf(FILE *__restrict _File, char *__restrict _Buffer) __NONNULL((1)) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP int   __cdecl _setmaxstdio(int _Max);
  _CRTIMP int   __cdecl  setvbuf(FILE *__restrict _File, char *__restrict _Buf, int _Mode, size_t _Size) __NOTHROW __NONNULL((1));
  _CRTIMP char *__cdecl _tempnam(const char *_DirName, const char *_FilePrefix) __NOTHROW __ATTR_MALLOC __WUR_FORTIFY __ATTR_DEALLOC_FREE;
  _CRTIMP int   __cdecl  ungetc(int _Ch, FILE *_File) __NONNULL((2));

  _CRTIMP void   __cdecl _lock_file(FILE *_File);
  _CRTIMP void   __cdecl _unlock_file(FILE *_File);
  _CRTIMP int    __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP int    __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP int    __cdecl _fgetc_nolock(FILE *_File) __NONNULL((1));
  _CRTIMP int    __cdecl _fputc_nolock(int _Char, FILE *_File) __NONNULL((2));
  _CRTIMP size_t __cdecl _fread_nolock(void *__restrict _DstBuf, size_t _ElementSize, size_t _Count, FILE *__restrict _File) __WUR_FORTIFY __NONNULL((4));
  _CRTIMP size_t __cdecl _fread_nolock_s(void *_DstBuf, size_t _DstSize, size_t _ElementSize, size_t _Count, FILE *_File);
  _CRTIMP int    __cdecl _fseek_nolock(FILE *_File, long _Offset, int _Origin) __NONNULL((1));
  __MINGW_EXTENSION _CRTIMP int     __cdecl _fseeki64_nolock(FILE *_File, __int64 _Offset,int _Origin) __NONNULL((1));
  _CRTIMP long   __cdecl _ftell_nolock(FILE *_File)                       __WUR_FORTIFY __NONNULL((1));
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File) __WUR_FORTIFY __NONNULL((1));
  _CRTIMP size_t __cdecl _fwrite_nolock(const void *__restrict _DstBuf, size_t _Size, size_t _Count, FILE *__restrict _File) __NONNULL((4));
  _CRTIMP int    __cdecl _getc_nolock(FILE *_File)            __NONNULL((1));
  _CRTIMP int    __cdecl _putc_nolock(int _Char, FILE *_File) __NONNULL((2));
  _CRTIMP int    __cdecl _ungetc_nolock(int _Ch, FILE *_File) __NONNULL((2));

#define _getchar_nolock()    _getc_nolock(stdin)
#define _putchar_nolock(_c)  _putc_nolock((_c), stdout)
#define _getwchar_nolock()   _getwc_nolock(stdin)
#define _putwchar_nolock(_c) _putwc_nolock((_c), stdout)

  _CRTIMP int *__cdecl __p__commode(void);
#define _commode (*__p__commode())

#if defined(__MINGW_USE_XOPEN) || defined(__MINGW_USE_MISC)
# define P_tmpdir _P_tmpdir
#endif
#ifdef __MINGW_USE_MS
# define SYS_OPEN _SYS_OPEN
#endif

#if defined(__MINGW_USE_XOPEN) || defined(__MINGW_USE_XOPEN2K) || defined(__MINGW_USE_MISC) || defined(__MINGW_USE_MS)
  _CRTIMP char *__cdecl tempnam(const char *_Directory, const char *_FilePrefix) __NOTHROW __ATTR_MALLOC __WUR_FORTIFY __ATTR_DEALLOC_FREE __MINGW_DEPRECATED_MSVC2005;
#endif

#if defined(__MINGW_USE_MS) || defined(__MINGW_USE_GNU)
  _CRTIMP int __cdecl fcloseall(void) __MINGW_DEPRECATED_MSVC2005;
#endif
#ifdef __MINGW_USE_MS
  _CRTIMP int __cdecl fgetchar(void)    __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP int __cdecl flushall(void)    __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP int __cdecl fputchar(int _Ch) __MINGW_DEPRECATED_MSVC2005;
#endif
#if (defined(__MINGW_USE_XOPEN) && !defined(__MINGW_USE_XOPEN2K)) || defined(__MINGW_USE_MISC) || defined(__MINGW_USE_MS)
  _CRTIMP int __cdecl getw(FILE *_File)          __NONNULL((1)) __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP int __cdecl putw(int _Ch, FILE *_File) __NONNULL((2)) __MINGW_DEPRECATED_MSVC2005;
#endif
#ifdef __MINGW_USE_MS
  _CRTIMP int __cdecl rmtmp(void) __MINGW_DEPRECATED_MSVC2005;
#endif

#if defined(__MINGW_USE_LFS) || defined(__MINGW_USE_XOPEN2K)
# ifndef __MINGW_USE_FOB64
    int   __cdecl fseeko(FILE *_File, off_t _Offset, int _Origin) __NONNULL((1));
    off_t __cdecl ftello(FILE *_File)               __WUR_FORTIFY __NONNULL((1));
# else
    int   __cdecl fseeko(FILE *_File, off_t _Offset, int _Origin) __ASM_CALL(fseeko64) __NONNULL((1));
    off_t __cdecl ftello(FILE *_File)               __ASM_CALL(ftello64) __WUR_FORTIFY __NONNULL((1));
# endif
#endif

#ifdef __MINGW_USE_LFS64
  FILE    *__cdecl fdopen64(int _FileHandle, const char *_Mode)                   __NOTHROW __ATTR_MALLOC __ATTR_DEALLOC(fclose, 1) __WUR_FORTIFY;
  FILE    *__cdecl fopen64(const char *__restrict _Filename, const char *__restrict _Mode)  __ATTR_MALLOC __ATTR_DEALLOC(fclose, 1) __WUR_FORTIFY;
  FILE    *__cdecl freopen64(const char *__restrict _Filename, const char *__restrict _Mode, FILE *__restrict _File) __WUR_FORTIFY __NONNULL((3));
  int      __cdecl fgetpos64(FILE *__restrict _File, fpos_t *__restrict _Pos) __NONNULL((1));
  int      __cdecl fsetpos64(FILE *_File, const fpos_t *_Pos)                 __NONNULL((1));
  int      __cdecl fseeko64(FILE *_File, off64_t _Offset, int _Origin)        __NONNULL((1));
  off64_t  __cdecl ftello64(FILE *_File)                        __WUR_FORTIFY __NONNULL((1));
  FILE    *__cdecl tmpfile64(void) __ATTR_MALLOC __ATTR_DEALLOC(fclose, 1) __WUR_FORTIFY;
#endif

  extern unsigned int __cdecl _get_output_format(void);

#ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP

#ifndef _P_WAIT
# define _P_WAIT        0
# define _P_NOWAIT      1
# define _OLD_P_OVERLAY 2
# define _P_NOWAITO     3
# define _P_DETACH      4
# define _P_OVERLAY     2

# define _WAIT_CHILD      0
# define _WAIT_GRANDCHILD 1
#endif

#ifndef _SPAWNV_DEFINED  /* Also in process.h */
# define _SPAWNV_DEFINED
  _CRTIMP intptr_t __cdecl _spawnv(int _Mode, const char *_Filename, const char *const *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(int _Mode, const char *_Filename, const char *const *_ArgList, const char *const *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(int _Mode, const char *_Filename, const char *const *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(int _Mode, const char *_Filename, const char *const *_ArgList, const char *const *_Env);
#endif  /* _SPAWNV_DEFINED */

#endif  /* _CRT_USE_WINAPI_FAMILY_DESKTOP_APP */

__MINGW_END_C_DECLS

#include <ssp/stdio.h>

#pragma pop_macro("snprintf")
#pragma pop_macro("vsnprintf")

#endif  /* _INC_STDIO */
