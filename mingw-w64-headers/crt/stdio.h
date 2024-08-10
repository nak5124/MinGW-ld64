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

#define _P_tmpdir "\\"
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
# define TMP_MAX_S  TMP_MAX
# define _TMP_MAX_S TMP_MAX
#endif

#ifndef _FPOS_T_DEFINED
# define _FPOS_T_DEFINED
# undef _FPOSOFF
  __MINGW_EXTENSION typedef __int64 fpos_t;
# define _FPOSOFF(fp) ((long)(fp))
#endif

  extern int __cdecl __mingw_vfprintf(FILE * __restrict _Stream, const char * __restrict _Format, va_list _ArgList)
    __MINGW_GNU_PRINTF(2, 0) __MINGW_NONNULL((1, 2)) __MINGW_NOTHROW;
  extern int __cdecl __mingw_vprintf(const char * __restrict _Format, va_list _ArgList)
    __MINGW_GNU_PRINTF(1, 0) __MINGW_NONNULL((1)) __MINGW_NOTHROW;
  extern int __cdecl __mingw_fprintf(FILE * __restrict _Stream, const char * __restrict _Format, ...)
    __MINGW_GNU_PRINTF(2, 3) __MINGW_NONNULL((1, 2)) __MINGW_NOTHROW;
  extern int __cdecl __mingw_printf(const char * __restrict _Format, ... )
    __MINGW_GNU_PRINTF(1, 2) __MINGW_NONNULL((1)) __MINGW_NOTHROW;

  extern int __cdecl __mingw_vfscanf(FILE * __restrict _Stream, const char * __restrict _Format, va_list _ArgList)
    __MINGW_GNU_SCANF(2, 0) __MINGW_NONNULL((1, 2));
  extern int __cdecl __mingw_vscanf(const char * __restrict _Format, va_list _ArgList)
    __MINGW_GNU_SCANF(1, 0) __MINGW_NONNULL((1));
  extern int __cdecl __mingw_fscanf(FILE * __restrict _Stream, const char * __restrict _Format, ...)
    __MINGW_GNU_SCANF(2, 3) __MINGW_NONNULL((1, 2));
  extern int __cdecl __mingw_scanf(const char * __restrict _Format, ...)
    __MINGW_GNU_SCANF(1, 2) __MINGW_NONNULL((1));

  extern int __cdecl __mingw_vsnprintf(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, va_list _ArgList)
    __MINGW_GNU_PRINTF(3, 0) __MINGW_NONNULL((3)) __MINGW_NOTHROW;
  extern int __cdecl __mingw_vsprintf(char * __restrict _Buffer, const char * __restrict _Format, va_list _ArgList)
    __MINGW_GNU_PRINTF(2, 0) __MINGW_NONNULL((2)) __MINGW_NOTHROW;
  extern int __cdecl __mingw_sprintf(char * __restrict _Buffer, const char * __restrict _Format, ...)
    __MINGW_GNU_PRINTF(2, 3) __MINGW_NONNULL((2)) __MINGW_NOTHROW;
  extern int __cdecl __mingw_snprintf(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, ...)
    __MINGW_GNU_PRINTF(3, 4) __MINGW_NONNULL((3)) __MINGW_NOTHROW;

  extern int __cdecl __mingw_vsscanf(const char * __restrict _Buffer, const char * __restrict _Format, va_list _ArgList)
    __MINGW_GNU_SCANF(2, 0) __MINGW_NONNULL((2));
  extern int __cdecl __mingw_sscanf(const char * __restrict _Buffer, const char * __restrict _Format, ...)
    __MINGW_GNU_SCANF(2, 3) __MINGW_NONNULL((2));

  extern int __cdecl __mingw_vasprintf(char ** __restrict _Strp, const char * __restrict _Format, va_list _ArgList)
    __MINGW_GNU_PRINTF(2, 0) __MINGW_NONNULL((1, 2)) __MINGW_NOTHROW;
  extern int __cdecl __mingw_asprintf(char ** __restrict _Strp, const char * __restrict _Format, ...)
    __MINGW_GNU_PRINTF(2, 3) __MINGW_NONNULL((1, 2)) __MINGW_NOTHROW;

  _CRTIMP int __cdecl __stdio_common_vfprintf(unsigned __int64 _Options, FILE *_Stream, const char *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vfprintf_s(unsigned __int64 _Options, FILE *_Stream, const char *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vfprintf_p(unsigned __int64 _Options, FILE *_Stream, const char *_Format, _locale_t _Locale, va_list _ArgList);

  __mingw_ovr int _vfprintf_l(FILE * __restrict _Stream, const char * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfprintf(0, _Stream, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int _vfprintf_s_l(FILE * __restrict _Stream, const char * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfprintf_s(0, _Stream, _Format, _Locale, _ArgList);
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr int vfprintf_s(FILE * __restrict _Stream, const char * __restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfprintf_s(0, _Stream, _Format, NULL, _ArgList);
  }

#endif

  __mingw_ovr int _vfprintf_p_l(FILE * __restrict _Stream, const char * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfprintf_p(0, _Stream, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int _vfprintf_p(FILE * __restrict _Stream, const char * __restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfprintf_p(0, _Stream, _Format, NULL, _ArgList);
  }

  __mingw_ovr int _vprintf_l(const char * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfprintf(0, stdout, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int _vprintf_s_l(const char * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfprintf_s(0, stdout, _Format, _Locale, _ArgList);
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr int vprintf_s(const char * __restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfprintf_s(0, stdout, _Format, NULL, _ArgList);
  }

#endif

  __mingw_ovr int _vprintf_p_l(const char * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfprintf_p(0, stdout, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int _vprintf_p(const char * __restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfprintf_p(0, stdout, _Format, NULL, _ArgList);
  }

  __mingw_ovr int _fprintf_l(FILE * __restrict _Stream, const char * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfprintf(0, _Stream, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  _CRTIMP int __cdecl _set_printf_count_output(int _Value);
  _CRTIMP int __cdecl _get_printf_count_output(void);

  __mingw_ovr int _fprintf_s_l(FILE * __restrict _Stream, const char * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfprintf_s(0, _Stream, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr int fprintf_s(FILE * __restrict _Stream, const char * __restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfprintf_s(0, _Stream, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#endif

  __mingw_ovr int _fprintf_p_l(FILE * __restrict _Stream, const char * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfprintf_p(0, _Stream, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int _fprintf_p(FILE * __restrict _Stream, const char * __restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfprintf_p(0, _Stream, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int _printf_l(const char * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfprintf(0, stdout, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int _printf_s_l(const char * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfprintf_s(0, stdout, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr int printf_s(const char * __restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfprintf_s(0, stdout, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#endif

  __mingw_ovr int _printf_p_l(const char * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfprintf_p(0, stdout, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int _printf_p(const char * __restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfprintf_p(0, stdout, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  _CRTIMP int __cdecl __stdio_common_vfscanf(unsigned __int64 options, FILE *file, const char *format, _locale_t locale, va_list valist);

  __mingw_ovr int _vfscanf_l(FILE * __restrict _Stream, const char * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfscanf(0, _Stream, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int _vfscanf_s_l(FILE * __restrict _Stream, const char * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfscanf(_CRT_INTERNAL_SCANF_SECURECRT, _Stream, _Format, _Locale, _ArgList);
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr int vfscanf_s(FILE * __restrict _Stream, const char * __restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfscanf(_CRT_INTERNAL_SCANF_SECURECRT, _Stream, _Format, NULL, _ArgList);
  }

#endif

  __mingw_ovr int _vscanf_l(const char * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfscanf(0, stdin, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int _vscanf_s_l(const char * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vfscanf(_CRT_INTERNAL_SCANF_SECURECRT, stdin, _Format, _Locale, _ArgList);
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr int vscanf_s(const char * __restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vfscanf(_CRT_INTERNAL_SCANF_SECURECRT, stdin, _Format, NULL, _ArgList);
  }

#endif

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _fscanf_l(FILE * __restrict _Stream, const char * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfscanf(0, _Stream, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int _fscanf_s_l(FILE * __restrict _Stream, const char * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfscanf(_CRT_INTERNAL_SCANF_SECURECRT, _Stream, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr int fscanf_s(FILE * __restrict _Stream, const char * __restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfscanf(_CRT_INTERNAL_SCANF_SECURECRT, _Stream, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#endif

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _scanf_l(const char * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfscanf(0, stdin, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int _scanf_s_l(const char * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vfscanf(_CRT_INTERNAL_SCANF_SECURECRT, stdin, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr int scanf_s(const char * __restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vfscanf(_CRT_INTERNAL_SCANF_SECURECRT, stdin, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#endif

  _CRTIMP int __cdecl __stdio_common_vsprintf(unsigned __int64 _Options, char *_Buffer, size_t _BufferCount, const char *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vsprintf_s(unsigned __int64 _Options, char *_Buffer, size_t _BufferCount, const char *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vsnprintf_s(unsigned __int64 _Options, char *_Buffer, size_t _BufferCount, size_t _MaxCount, const char *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __stdio_common_vsprintf_p(unsigned __int64 _Options, char *_Buffer, size_t _BufferCount, const char *_Format, _locale_t _Locale, va_list _ArgList);

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _vsnprintf_l(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  extern int __cdecl _vsnprintf(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, va_list _ArgList)
    __MINGW_GNU_PRINTF(3, 0) __MINGW_NONNULL((3)) __MINGW_NOTHROW;

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _vsprintf_l(char * __restrict _Buffer, const char * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int _vsprintf_s_l(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf_s(0, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr int vsprintf_s(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf_s(0, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(int, vsprintf_s, char, _Buffer, const char *, _Format, va_list, _ArgList)

#endif

  __mingw_ovr int _vsprintf_p_l(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf_p(0, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int _vsprintf_p(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf_p(0, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int _vsnprintf_s_l(char * __restrict _Buffer, size_t _BufferCount, size_t _MaxCount, const char * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsnprintf_s(0, _Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int _vsnprintf_s(char * __restrict _Buffer, size_t _BufferCount, size_t _MaxCount, const char * __restrict _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsnprintf_s(0, _Buffer, _BufferCount, _MaxCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(int, _vsnprintf_s, char, _Buffer, size_t, _BufferCount, const char *, _Format, va_list, _ArgList)

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr int vsnprintf_s(char * __restrict _Buffer, size_t _BufferCount, size_t _MaxCount, const char * __restrict _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsnprintf_s(0, _Buffer, _BufferCount, _MaxCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(int, vsnprintf_s, char, _Buffer, size_t, _BufferCount, const char *, _Format, va_list, _ArgList)

#endif

  __mingw_ovr int _vscprintf_l(const char * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  extern int __cdecl _vscprintf(const char * __restrict _Format, va_list _ArgList)
    __MINGW_PURE __MINGW_GNU_PRINTF(1, 0) __MINGW_NONNULL((1));

  __mingw_ovr int _vscprintf_p_l(const char * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf_p(_CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int _vscprintf_p(const char * __restrict _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf_p(_CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int _vsnprintf_c_l(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf(0, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int _vsnprintf_c(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, va_list _ArgList)
  {
    int _Ret;
    _Ret = __stdio_common_vsprintf(0, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _sprintf_l(char * __restrict _Buffer, const char * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int _sprintf_s_l(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsprintf_s(0, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr int sprintf_s(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vsprintf_s(0, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1_ARGLIST(int, sprintf_s, vsprintf_s, char, _Buffer, const char *, _Format)

#endif

  __mingw_ovr int _sprintf_p_l(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsprintf_p(0, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int _sprintf_p(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vsprintf_p(0, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _snprintf_l(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  extern int __cdecl _snprintf(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, ...)
    __MINGW_GNU_PRINTF(3, 4) __MINGW_NONNULL((3)) __MINGW_NOTHROW __MINGW_DEPRECATED_SEC_WARN;

  __mingw_ovr int _snprintf_c_l(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsprintf(0, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int _snprintf_c(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vsprintf(0, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int _snprintf_s_l(char * __restrict _Buffer, size_t _BufferCount, size_t _MaxCount, const char * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsnprintf_s(0, _Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int _snprintf_s(char * __restrict _Buffer, size_t _BufferCount, size_t _MaxCount, const char * __restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vsnprintf_s(0, _Buffer, _BufferCount, _MaxCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2_ARGLIST(int, _snprintf_s, _vsnprintf_s, char, _Buffer, size_t, _BufferCount, const char *, _Format)

  __mingw_ovr int _scprintf_l(const char * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsprintf(_CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  extern int __cdecl _scprintf(const char * __restrict _Format, ...)
    __MINGW_PURE __MINGW_GNU_PRINTF(1, 2) __MINGW_NONNULL((1));

  __mingw_ovr int _scprintf_p_l(const char * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsprintf_p(_CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  __mingw_ovr int _scprintf_p(const char * __restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vsprintf_p(_CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret < 0 ? -1 : _Ret;
  }

  _CRTIMP int __cdecl __stdio_common_vsscanf(unsigned __int64 _Options, const char *_Buffer, size_t _BufferCount, const char *_Format, _locale_t _Locale, va_list _ArgList);

  __mingw_ovr int _vsscanf_l(const char * __restrict _Buffer, const char * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vsscanf(0, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int _vsscanf_s_l(const char * __restrict _Buffer, const char * __restrict _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __stdio_common_vsscanf(_CRT_INTERNAL_SCANF_SECURECRT, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr int vsscanf_s(const char * __restrict _Buffer, const char * __restrict _Format, va_list _ArgList)
  {
    return __stdio_common_vsscanf(_CRT_INTERNAL_SCANF_SECURECRT, _Buffer, (size_t)-1, _Format, NULL, _ArgList);
  }
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(int, vsscanf_s, const char, _Buffer, const char *, _Format, va_list, _ArgList)

#endif

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _sscanf_l(const char * __restrict _Buffer, const char * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsscanf(0, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int _sscanf_s_l(const char * __restrict _Buffer, const char * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsscanf(_CRT_INTERNAL_SCANF_SECURECRT, _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#ifdef __MINGW_USE_SECAPI

  __mingw_ovr int sscanf_s(const char * __restrict _Buffer, const char * __restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vsscanf(_CRT_INTERNAL_SCANF_SECURECRT, _Buffer, (size_t)-1, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#endif

  __mingw_ovr __MINGW_DEPRECATED_SEC_WARN
  int _snscanf_l(const char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsscanf(0, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  extern int __cdecl _snscanf(const char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, ...)
    __MINGW_GNU_SCANF(3, 4) __MINGW_NONNULL((3)) __MINGW_DEPRECATED_SEC_WARN;

  __mingw_ovr int _snscanf_s_l(const char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __stdio_common_vsscanf(_CRT_INTERNAL_SCANF_SECURECRT, _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int _snscanf_s(const char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __stdio_common_vsscanf(_CRT_INTERNAL_SCANF_SECURECRT, _Buffer, _BufferCount, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"

#if __USE_MINGW_ANSI_STDIO && !defined(_CRTBLD)

  __mingw_ovr
  __MINGW_GNU_PRINTF(2, 0) __MINGW_NONNULL((1, 2))
  int vfprintf(FILE * __restrict _Stream, const char * __restrict _Format, va_list _ArgList)
  {
    return __mingw_vfprintf(_Stream, _Format, _ArgList);
  }

  __mingw_ovr
  __MINGW_GNU_PRINTF(1, 0) __MINGW_NONNULL((1))
  int vprintf(const char * __restrict _Format, va_list _ArgList)
  {
    return __mingw_vfprintf(stdout, _Format, _ArgList);
  }

  __mingw_ovr
  __MINGW_GNU_PRINTF(2, 3) __MINGW_NONNULL((1, 2))
  int fprintf(FILE * __restrict _Stream, const char * __restrict _Format, ...)
  {
    int _Ret;
    __builtin_va_list _ArgList;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __mingw_vfprintf(_Stream, _Format, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr
  __MINGW_GNU_PRINTF(1, 2) __MINGW_NONNULL((1))
  int printf(const char * __restrict _Format, ...)
  {
    int _Ret;
    __builtin_va_list _ArgList;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __mingw_vfprintf(stdout, _Format, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)

  __mingw_ovr
  __MINGW_GNU_SCANF(2, 0) __MINGW_NONNULL((1, 2))
  int vfscanf(FILE * __restrict _Stream, const char * __restrict _Format, va_list _ArgList)
  {
    return __mingw_vfscanf(_Stream, _Format, _ArgList);
  }

  __mingw_ovr
  __MINGW_GNU_SCANF(1, 0) __MINGW_NONNULL((1))
  int vscanf(const char * __restrict _Format, va_list _ArgList)
  {
    return __mingw_vfscanf(stdin, _Format, _ArgList);
  }

#endif

  __mingw_ovr
  __MINGW_GNU_SCANF(2, 3) __MINGW_NONNULL((1, 2))
  int fscanf(FILE * __restrict _Stream, const char * __restrict _Format, ...)
  {
    int _Ret;
    __builtin_va_list _ArgList;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __mingw_vfscanf(_Stream, _Format, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr
  __MINGW_GNU_SCANF(1, 2) __MINGW_NONNULL((1))
  int scanf(const char * __restrict _Format, ...)
  {
    int _Ret;
    __builtin_va_list _ArgList;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __mingw_vfscanf(stdin, _Format, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)

  __mingw_bos_ovr
  __MINGW_GNU_PRINTF(3, 0) __MINGW_NONNULL((3)) __MINGW_NOTHROW
  int vsnprintf(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, va_list _ArgList)
  {
#if __MINGW_FORTIFY_LEVEL > 0
    __mingw_bos_ptr_chk_warn(_Buffer, _BufferCount, 1);
#endif
    return __mingw_vsnprintf(_Buffer, _BufferCount, _Format, _ArgList);
  }

#endif

  __mingw_bos_ovr
  __MINGW_GNU_PRINTF(2, 0) __MINGW_NONNULL((2)) __MINGW_NOTHROW
  int vsprintf(char * __restrict _Buffer, const char * __restrict _Format, va_list _ArgList)
  {
#if __MINGW_FORTIFY_LEVEL > 0
    if(__mingw_bos_known(_Buffer))
    {
      int _Ret = __mingw_vsnprintf(_Buffer, __mingw_bos(_Buffer, 1), _Format, _ArgList);
      if(_Ret >= 0)
        __mingw_bos_ptr_chk(_Buffer, (size_t)_Ret + 1, 1);
      return _Ret;
    }
#endif
    return __mingw_vsprintf(_Buffer, _Format, _ArgList);
  }

#if __MINGW_FORTIFY_VA_ARG

  int sprintf(char * __restrict _Buffer, const char * __restrict _Format, ...) __MINGW_ASM_CALL(__mingw_sprintf);

  __mingw_bos_extern_ovr
  __MINGW_GNU_PRINTF(2, 3) __MINGW_NONNULL((2)) __MINGW_NOTHROW
  int sprintf(char * __restrict _Buffer, const char * __restrict _Format, ...)
  {
    if(__mingw_bos_known(_Buffer))
    {
      int _Ret = __mingw_snprintf(_Buffer, __mingw_bos(_Buffer, 1), _Format, __builtin_va_arg_pack());
      if(_Ret >= 0)
        __mingw_bos_ptr_chk(_Buffer, (size_t)_Ret + 1, 1);
      return _Ret;
    }
    return __mingw_sprintf(_Buffer, _Format, __builtin_va_arg_pack());
  }

#else

  __mingw_ovr
  __MINGW_GNU_PRINTF(2, 3) __MINGW_NONNULL((2)) __MINGW_NOTHROW
  int sprintf(char * __restrict _Buffer, const char * __restrict _Format, ...)
  {
    int _Ret;
    __builtin_va_list _ArgList;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __mingw_vsprintf(_Buffer, _Format, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#endif  /* __MINGW_FORTIFY_VA_ARG */

#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)

#if __MINGW_FORTIFY_VA_ARG

  int snprintf(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, ...) __MINGW_ASM_CALL(__mingw_snprintf);

  __mingw_bos_extern_ovr
  __MINGW_GNU_PRINTF(3, 4) __MINGW_NONNULL((3)) __MINGW_NOTHROW
  int snprintf(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, ...)
  {
    __mingw_bos_ptr_chk_warn(_Buffer, _BufferCount, 1);
    return __mingw_snprintf(_Buffer, _BufferCount, _Format, __builtin_va_arg_pack());
  }

#else

  __mingw_ovr
  __MINGW_GNU_PRINTF(3, 4) __MINGW_NONNULL((3)) __MINGW_NOTHROW
  int snprintf(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, ...)
  {
    int _Ret;
    __builtin_va_list _ArgList;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __mingw_vsnprintf(_Buffer, _BufferCount, _Format, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#endif  /* __MINGW_FORTIFY_VA_ARG */

#endif

#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)

  __mingw_ovr
  __MINGW_GNU_SCANF(2, 0) __MINGW_NONNULL((2))
  int vsscanf(const char * __restrict _Buffer, const char * __restrict _Format, va_list _ArgList)
  {
    return __mingw_vsscanf(_Buffer, _Format, _ArgList);
  }

#endif

  __mingw_ovr
  __MINGW_GNU_SCANF(2, 3) __MINGW_NONNULL((2))
  int sscanf(const char * __restrict _Buffer, const char * __restrict _Format, ...)
  {
    int _Ret;
    __builtin_va_list _ArgList;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __mingw_vsscanf(_Buffer, _Format, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

#if defined(__MINGW_USE_MISC) || defined(__MINGW_USE_LIB_EXT2)
  __mingw_ovr
  __MINGW_GNU_PRINTF(2, 0) __MINGW_NONNULL((1, 2)) __MINGW_NOTHROW
  int vasprintf(char ** __restrict _Strp, const char * __restrict _Format, va_list _ArgList)
  {
    return __mingw_vasprintf(_Strp, _Format, _ArgList);
  }

  __mingw_ovr
  __MINGW_GNU_PRINTF(2, 3) __MINGW_NONNULL((1, 2)) __MINGW_NOTHROW
  int asprintf(char ** __restrict _Strp, const char * __restrict _Format, ...)
  {
    int _Ret;
    __builtin_va_list _ArgList;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __mingw_vasprintf(_Strp, _Format, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }
#endif

/* Override __builtin_printf-routines ... Kludge for libstdc++ ...*/
#define __builtin_vsnprintf __mingw_vsnprintf
#define __builtin_vsprintf  __mingw_vsprintf

#else

#undef __builtin_vsnprintf
#undef __builtin_vsprintf

/*
 * Default configuration: simply direct all calls to UCRT...
 */

  extern int __cdecl vfprintf(FILE * __restrict _Stream, const char * __restrict _Format, va_list _ArgList)
    __MINGW_GNU_PRINTF(2, 0) __MINGW_NONNULL((1, 2));
  extern int __cdecl vprintf(const char * __restrict _Format, va_list _ArgList)
    __MINGW_GNU_PRINTF(1, 0) __MINGW_NONNULL((1));
  extern int __cdecl fprintf(FILE * __restrict _Stream, const char * __restrict _Format, ...)
    __MINGW_GNU_PRINTF(2, 3) __MINGW_NONNULL((1, 2));
  extern int __cdecl printf(const char * __restrict _Format, ...)
    __MINGW_GNU_PRINTF(1, 2) __MINGW_NONNULL((1));

#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)
  extern int __cdecl vfscanf(FILE * __restrict _Stream,  const char * __restrict _Format, va_list _ArgList)
    __MINGW_GNU_SCANF(2, 0) __MINGW_NONNULL((1, 2));
  extern int __cdecl vscanf(const char * __restrict _Format, va_list _ArgList)
    __MINGW_GNU_SCANF(1, 0) __MINGW_NONNULL((1));
#endif
  extern int __cdecl fscanf(FILE * __restrict _Stream, const char * __restrict _Format, ...)
    __MINGW_GNU_SCANF(2, 3) __MINGW_NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN;
  extern int __cdecl scanf(const char * __restrict _Format, ...)
    __MINGW_GNU_SCANF(1, 2) __MINGW_NONNULL((1)) __MINGW_DEPRECATED_SEC_WARN;

#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)
  extern int __cdecl vsnprintf(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, va_list _ArgList)
    __MINGW_GNU_PRINTF(3, 0) __MINGW_NONNULL((3)) __MINGW_NOTHROW;
#endif
  extern int __cdecl vsprintf(char * __restrict _Buffer, const char * __restrict _Format, va_list _ArgList)
    __MINGW_GNU_PRINTF(2, 0) __MINGW_NONNULL((2)) __MINGW_NOTHROW __MINGW_DEPRECATED_SEC_WARN;
  extern int __cdecl sprintf(char * __restrict _Buffer, const char * __restrict _Format, ...)
    __MINGW_GNU_PRINTF(2, 3) __MINGW_NONNULL((2)) __MINGW_NOTHROW __MINGW_DEPRECATED_SEC_WARN;
#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)
  extern int __cdecl snprintf(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, ...)
    __MINGW_GNU_PRINTF(3, 4) __MINGW_NONNULL((3)) __MINGW_NOTHROW;
#endif

#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)
  extern int __cdecl vsscanf(const char * __restrict _Buffer, const char * __restrict _Format, __builtin_va_list _ArgList)
    __MINGW_GNU_SCANF(2, 0) __MINGW_NONNULL((2));
#endif
  extern int __cdecl sscanf(const char * __restrict _Buffer, const char * __restrict _Format, ...)
    __MINGW_GNU_SCANF(2, 3) __MINGW_NONNULL((2)) __MINGW_DEPRECATED_SEC_WARN;

#if __MINGW_FORTIFY_LEVEL > 0

  int __cdecl __mingw_call_vsprintf(char * __restrict _Buffer, const char * __restrict _Format, va_list _ArgList) __MINGW_ASM_CALL(vsprintf);
  int __cdecl __mingw_call_vsnprintf(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, va_list _ArgList) __MINGW_ASM_CALL(vsnprintf);

  __mingw_bos_extern_ovr
  __MINGW_GNU_PRINTF(2, 0) __MINGW_NONNULL((3)) __MINGW_NOTHROW
  int vsprintf(char * __restrict _Buffer, const char * __restrict _Format, va_list _ArgList)
  {
    if(__mingw_bos_known(_Buffer))
    {
      int _Ret = __mingw_call_vsnprintf(_Buffer, __mingw_bos(_Buffer, 1), _Format, _ArgList);
      if(_Ret >= 0)
        __mingw_bos_ptr_chk(_Buffer, (size_t)_Ret + 1, 1);
      return _Ret;
    }
    return __mingw_call_vsprintf(_Buffer, _Format, _ArgList);
  }

#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)

  __mingw_bos_extern_ovr
  __MINGW_GNU_PRINTF(3, 0) __MINGW_NONNULL((3)) __MINGW_NOTHROW
  int vsnprintf(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, va_list _ArgList)
  {
    __mingw_bos_ptr_chk_warn(_Buffer, _BufferCount, 1);
    return __mingw_call_vsnprintf(_Buffer, _BufferCount, _Format, _ArgList);
  }

#endif

#endif  /* __MINGW_FORTIFY_LEVEL > 0 */

#if __MINGW_FORTIFY_VA_ARG

  int __cdecl __mingw_call_sprintf(char * __restrict _Buffer, const char * __restrict __Format, ...) __MINGW_ASM_CALL(sprintf);
  int __cdecl __mingw_call_snprintf(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, ...) __MINGW_ASM_CALL(snprintf);

  __mingw_bos_extern_ovr
  __MINGW_GNU_PRINTF(2, 3) __MINGW_NONNULL((2)) __MINGW_NOTHROW
  int sprintf(char * __restrict _Buffer, const char * __restrict _Format, ...)
  {
    if(__mingw_bos_known(_Buffer))
    {
      int _Ret = __mingw_call_snprintf(_Buffer, __mingw_bos(_Buffer, 1), _Format, __builtin_va_arg_pack());
      if(_Ret >= 0)
        __mingw_bos_ptr_chk(_Buffer, (size_t)_Ret + 1, 1);
      return _Ret;
    }
    return __mingw_call_sprintf(_Buffer, _Format, __builtin_va_arg_pack());
  }

#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)

  __mingw_bos_extern_ovr
  __MINGW_GNU_PRINTF(3, 4) __MINGW_NONNULL((3)) __MINGW_NOTHROW
  int snprintf(char * __restrict _Buffer, size_t _BufferCount, const char * __restrict _Format, ...)
  {
    __mingw_bos_ptr_chk_warn(_Buffer, _BufferCount, 1);
    return __mingw_call_snprintf(_Buffer, _BufferCount, _Format, __builtin_va_arg_pack());
  }

#endif

#endif  /* __MINGW_FORTIFY_VA_ARG */

#if defined(__MINGW_USE_MISC) || defined(__MINGW_USE_LIB_EXT2)
  extern int __cdecl vasprintf(char ** __restrict _Strp, const char * __restrict _Format, va_list _ArgList)
    __MINGW_GNU_PRINTF(2, 0) __MINGW_NONNULL((1, 2)) __MINGW_NOTHROW;
  extern int __cdecl asprintf(char ** __restrict _Strp, const char * __restrict _Format, ...)
    __MINGW_GNU_PRINTF(2, 3) __MINGW_NONNULL((1, 2)) __MINGW_NOTHROW;
#endif

#endif  /* __USE_MINGW_ANSI_STDIO */

#pragma GCC diagnostic pop

  _CRTIMP errno_t __cdecl _get_stream_buffer_pointers(FILE *_Stream, char ** *_Base, char ** *_Pointer, int ** _Count);

  _CRTIMP void __cdecl clearerr(FILE *_File) __MINGW_NONNULL((1));
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl clearerr_s(FILE *_File);
#endif
#ifndef __MINGW_USE_FOB64
  _CRTIMP FILE *__cdecl fopen(const char * __restrict _Filename, const char * __restrict _Mode)
    __MINGW_MALLOC __MINGW_DEALLOC(fclose, 1) __MINGW_DEPRECATED_SEC_WARN;
#else
  _CRTIMP FILE *__cdecl fopen(const char * __restrict _Filename, const char * __restrict _Mode)
    __MINGW_ASM_CALL(fopen64) __MINGW_MALLOC __MINGW_DEALLOC(fclose, 1) __MINGW_DEPRECATED_SEC_WARN;
#endif
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl fopen_s(FILE **_File, const char *_Filename, const char *_Mode);
  _CRTIMP size_t __cdecl fread_s(void *_DstBuf, size_t _DstSize, size_t _ElementSize, size_t _Count, FILE *_File);
#endif
#ifndef __MINGW_USE_FOB64
  _CRTIMP FILE *__cdecl freopen(const char * __restrict _Filename, const char * __restrict _Mode, FILE * __restrict _File)
    __MINGW_NONNULL((3)) __MINGW_DEPRECATED_SEC_WARN;
#else
  _CRTIMP FILE *__cdecl freopen(const char * __restrict _Filename, const char * __restrict _Mode, FILE * __restrict _File)
    __MINGW_ASM_CALL(freopen64) __MINGW_NONNULL((3)) __MINGW_DEPRECATED_SEC_WARN;
#endif
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl freopen_s(FILE** _File, const char *_Filename, const char *_Mode, FILE *_Stream);
#endif
#ifdef __MINGW_USE_DEPRECATED_GETS
  _CRTIMP char *__cdecl gets(char *_Buffer) __attribute__((__warning__("Using gets() is always unsafe - use fgets() instead")));
#endif
#ifdef __MINGW_USE_SECAPI
  _CRTIMP char *__cdecl gets_s(char *_Buffer, rsize_t _Size);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(char *, gets_s, char, _Buffer)
#endif
#ifndef __MINGW_USE_FOB64
  _CRTIMP FILE *__cdecl tmpfile(void)
    __MINGW_MALLOC __MINGW_DEALLOC(fclose, 1) __MINGW_DEPRECATED_SEC_WARN;
#else
  _CRTIMP FILE *__cdecl tmpfile(void)
    __MINGW_ASM_CALL(tmpfile64) __MINGW_MALLOC __MINGW_DEALLOC(fclose, 1) __MINGW_DEPRECATED_SEC_WARN;
#endif
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl tmpfile_s(FILE **_File);
#endif
  _CRTIMP char *__cdecl tmpnam(char *_Buffer);
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl tmpnam_s(char *_Buffer, rsize_t _Size);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, tmpnam_s, char, _Buffer)
#endif
  _CRTIMP int __cdecl fclose(FILE *_File) __MINGW_NONNULL((1));
  _CRTIMP int __cdecl _fcloseall(void);
#if defined(__MINGW_USE_POSIX) || defined(__MINGW_USE_MS)
# ifndef __MINGW_USE_FOB64
  _CRTIMP FILE *__cdecl fdopen(int _FileHandle, const char *_Mode)
    __MINGW_MALLOC __MINGW_DEALLOC(fclose, 1) __MINGW_DEPRECATED_MSVC2005;
# else
  _CRTIMP FILE *__cdecl fdopen(int _FileHandle, const char *_Mode)
    __MINGW_ASM_CALL(fdopen64) __MINGW_MALLOC __MINGW_DEALLOC(fclose, 1) __MINGW_DEPRECATED_MSVC2005;
# endif
#endif
  _CRTIMP FILE *__cdecl _fdopen(int _FileHandle, const char *_Mode) __MINGW_MALLOC __MINGW_DEALLOC(fclose, 1);
  _CRTIMP int __cdecl feof(FILE *_File) __MINGW_NONNULL((1));
  _CRTIMP int __cdecl ferror(FILE *_File) __MINGW_NONNULL((1));
  _CRTIMP int __cdecl fflush(FILE *_File);
  _CRTIMP int __cdecl fgetc(FILE *_File) __MINGW_NONNULL((1));
  _CRTIMP int __cdecl _fgetchar(void);
#ifndef __MINGW_USE_FOB64
  _CRTIMP int __cdecl fgetpos(FILE * __restrict _File , fpos_t * __restrict _Pos) __MINGW_NONNULL((1));
#else
  _CRTIMP int __cdecl fgetpos(FILE * __restrict _File , fpos_t * __restrict _Pos)
    __MINGW_ASM_CALL(fgetpos64) __MINGW_NONNULL((1));
#endif
  _CRTIMP char *__cdecl fgets(char * __restrict _Buf, int _MaxCount, FILE * __restrict _File) __MINGW_NONNULL((3));
#if defined(__MINGW_USE_POSIX) || defined(__MINGW_USE_MS)
  _CRTIMP int __cdecl fileno(FILE *_File) __MINGW_NONNULL((1)) __MINGW_DEPRECATED_MSVC2005;
#endif
  _CRTIMP int __cdecl _fileno(FILE *_File) __MINGW_NONNULL((1));
  _CRTIMP int __cdecl _flushall(void);
  _CRTIMP int __cdecl fputc(int _Ch, FILE *_File) __MINGW_NONNULL((2));
  _CRTIMP int __cdecl _fputchar(int _Ch);
  _CRTIMP int __cdecl fputs(const char * __restrict _Str, FILE * __restrict _File) __MINGW_NONNULL((2));
  _CRTIMP size_t __cdecl fread(void * __restrict _DstBuf, size_t _ElementSize, size_t _Count, FILE * __restrict _File) __MINGW_NONNULL((4));
  _CRTIMP FILE *__cdecl _fsopen(const char *_Filename, const char *_Mode, int _ShFlag);
#ifndef __MINGW_USE_FOB64
  _CRTIMP int __cdecl fsetpos(FILE *_File, const fpos_t *_Pos) __MINGW_NONNULL((1));
#else
  _CRTIMP int __cdecl fsetpos(FILE *_File, const fpos_t *_Pos) __MINGW_ASM_CALL(fsetpos64) __MINGW_NONNULL((1));
#endif
  _CRTIMP int __cdecl fseek(FILE *_File, long _Offset, int _Origin) __MINGW_NONNULL((1));
  _CRTIMP int __cdecl _fseeki64(FILE *_File, __int64 _Offset, int _Origin);
  _CRTIMP long __cdecl ftell(FILE *_File) __MINGW_NONNULL((1));
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _ftelli64(FILE *_File);
  _CRTIMP size_t __cdecl fwrite(const void * __restrict _Str, size_t _Size, size_t _Count, FILE * __restrict _File) __MINGW_NONNULL((4));
  _CRTIMP int __cdecl getc(FILE *_File) __MINGW_NONNULL((1));
  _CRTIMP int __cdecl getchar(void);
  _CRTIMP int __cdecl _getmaxstdio(void);
  _CRTIMP int __cdecl _getw(FILE *_File) __MINGW_NONNULL((1));
#ifndef _CRT_PERROR_DEFINED  /* Also in stdlib.h */
# define _CRT_PERROR_DEFINED
  _CRTIMP void __cdecl perror(const char *_ErrMsg);
#endif  /* _CRT_PERROR_DEFINED */
#ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
  _CRTIMP int __cdecl _pclose(FILE *_File) __MINGW_NONNULL((1));
  _CRTIMP FILE *__cdecl _popen(const char *_Command, const char *_Mode) __MINGW_MALLOC __MINGW_DEALLOC(_pclose, 1);
# ifdef __MINGW_USE_POSIX2
#   ifndef popen
#     define popen  _popen
#     define pclose _pclose
#   endif
# endif
#endif  /* _CRT_USE_WINAPI_FAMILY_DESKTOP_APP */
  _CRTIMP int __cdecl putc(int _Ch, FILE *_File) __MINGW_NONNULL((2));
  _CRTIMP int __cdecl putchar(int _Ch);
  _CRTIMP int __cdecl puts(const char *_Str);
  _CRTIMP int __cdecl _putw(int _Word, FILE *_File) __MINGW_NONNULL((2));
#ifndef _CRT_DIRECTORY_DEFINED  /* Also in io.h */
# define _CRT_DIRECTORY_DEFINED
  _CRTIMP int __cdecl remove(const char *_Filename);
  _CRTIMP int __cdecl rename(const char *_OldFilename, const char *_NewFilename);
  _CRTIMP int __cdecl _unlink(const char *_Filename);
#ifdef __MINGW_USE_MS
  _CRTIMP int __cdecl unlink(const char *_Filename) __MINGW_DEPRECATED_MSVC2005;
#endif
#endif  /* _CRT_DIRECTORY_DEFINED */
  _CRTIMP void __cdecl rewind(FILE *_File) __MINGW_NONNULL((1));
  _CRTIMP int __cdecl _rmtmp(void);
  _CRTIMP void __cdecl setbuf(FILE * __restrict _File, char * __restrict _Buffer) __MINGW_NONNULL((1)) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl _setmaxstdio(int _Max);
  _CRTIMP int __cdecl setvbuf(FILE * __restrict _File, char * __restrict _Buf, int _Mode, size_t _Size) __MINGW_NONNULL((1));
  _CRTIMP char *__cdecl _tempnam(const char *_DirName, const char *_FilePrefix) __MINGW_MALLOC __MINGW_DEALLOC_FREE;
  _CRTIMP int __cdecl ungetc(int _Ch, FILE *_File) __MINGW_NONNULL((2));

  _CRTIMP void __cdecl _lock_file(FILE *_File);
  _CRTIMP void __cdecl _unlock_file(FILE *_File);
  _CRTIMP int __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP int __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP int __cdecl _fgetc_nolock(FILE *_File);
  _CRTIMP int __cdecl _fputc_nolock(int _Char, FILE *_File);
  _CRTIMP size_t __cdecl _fread_nolock(void * __restrict _DstBuf, size_t _ElementSize, size_t _Count, FILE * __restrict _File);
  _CRTIMP size_t __cdecl _fread_nolock_s(void *_DstBuf, size_t _DstSize, size_t _ElementSize, size_t _Count, FILE *_File);
  _CRTIMP int __cdecl _fseek_nolock(FILE *_File, long _Offset, int _Origin);
  __MINGW_EXTENSION _CRTIMP int __cdecl _fseeki64_nolock(FILE *_File, __int64 _Offset,int _Origin);
  _CRTIMP long __cdecl _ftell_nolock(FILE *_File);
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fwrite_nolock(const void * __restrict _DstBuf, size_t _Size, size_t _Count, FILE * __restrict _File);
  _CRTIMP int __cdecl _getc_nolock(FILE *_File);
  _CRTIMP int __cdecl _putc_nolock(int _Char, FILE *_File);
  _CRTIMP int __cdecl _ungetc_nolock(int _Ch, FILE *_File);

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
  _CRTIMP char *__cdecl tempnam(const char *_Directory, const char *_FilePrefix)
    __MINGW_MALLOC __MINGW_DEALLOC_FREE __MINGW_DEPRECATED_MSVC2005;
#endif

#if defined(__MINGW_USE_MS) || defined(__MINGW_USE_GNU)
  _CRTIMP int __cdecl fcloseall(void) __MINGW_DEPRECATED_MSVC2005;
#endif
#ifdef __MINGW_USE_MS
  _CRTIMP int __cdecl fgetchar(void) __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP int __cdecl flushall(void) __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP int __cdecl fputchar(int _Ch) __MINGW_DEPRECATED_MSVC2005;
#endif
#if (defined(__MINGW_USE_XOPEN) && !defined(__MINGW_USE_XOPEN2K)) || defined(__MINGW_USE_MISC) || defined(__MINGW_USE_MS)
  _CRTIMP int __cdecl getw(FILE *_File) __MINGW_NONNULL((1)) __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP int __cdecl putw(int _Ch, FILE *_File) __MINGW_NONNULL((2)) __MINGW_DEPRECATED_MSVC2005;
#endif
#ifdef __MINGW_USE_MS
  _CRTIMP int __cdecl rmtmp(void) __MINGW_DEPRECATED_MSVC2005;
#endif

#if defined(__MINGW_USE_LFS) || defined(__MINGW_USE_XOPEN2K)
# ifndef __MINGW_USE_FOB64
    int __cdecl fseeko(FILE *_File, off_t _Offset, int _Origin) __MINGW_NONNULL((1));
    off_t __cdecl ftello(FILE *_File) __MINGW_NONNULL((1));
# else
    int __cdecl fseeko(FILE *_File, off_t _Offset, int _Origin) __MINGW_ASM_CALL(fseeko64) __MINGW_NONNULL((1));
    off_t __cdecl ftello(FILE *_File) __MINGW_ASM_CALL(ftello64) __MINGW_NONNULL((1));
# endif
#endif

#ifdef __MINGW_USE_LFS64
  FILE *__cdecl fdopen64(int _FileHandle, const char *_Mode) __MINGW_MALLOC __MINGW_DEALLOC(fclose, 1);
  FILE *__cdecl fopen64(const char * __restrict filename, const char * __restrict mode)
    __MINGW_MALLOC __MINGW_DEALLOC(fclose, 1);
  FILE *__cdecl freopen64(const char * __restrict _Filename, const char * __restrict _Mode, FILE * __restrict _File)
    __MINGW_NONNULL((3));
  int __cdecl fgetpos64(FILE * __restrict _File, fpos_t * __restrict _Pos) __MINGW_NONNULL((1));
  int __cdecl fsetpos64(FILE *_File, const fpos_t *_Pos) __MINGW_NONNULL((1));
  int __cdecl fseeko64(FILE *_File, off64_t _Offset, int _Origin) __MINGW_NONNULL((1));
  off64_t __cdecl ftello64(FILE *_File) __MINGW_NONNULL((1));
  FILE *__cdecl tmpfile64(void) __MINGW_MALLOC __MINGW_DEALLOC(fclose, 1);
#endif

  extern unsigned int __cdecl _get_output_format(void);

#if __MINGW_FORTIFY_LEVEL > 0

#ifdef __MINGW_USE_DEPRECATED_GETS
  char * __cdecl __gets_chk(char *, size_t);
  char * __cdecl __mingw_call_gets_warn(char *) __MINGW_ASM_CALL(gets)
    __attribute__((__warning__("Using gets() is always unsafe - use fgets() instead")));

  __mingw_bos_extern_ovr
  char * gets(char * __dst)
  {
    if(__mingw_bos_known(__dst))
      return __gets_chk(__dst, __mingw_bos(__dst, 1));
    return __mingw_call_gets_warn(__dst);
  }
#endif

  char * __cdecl __mingw_call_fgets(char * __restrict, int, FILE * __restrict) __MINGW_ASM_CALL(fgets);
  size_t __cdecl __mingw_call_fread(void * __restrict, size_t, size_t, FILE * __restrict) __MINGW_ASM_CALL(fread);
  char * __cdecl __mingw_call_tmpnam(char *) __MINGW_ASM_CALL(tmpnam);

  __mingw_bos_extern_ovr __MINGW_NONNULL((3))
  char * fgets(char * __restrict __dst, int __n, FILE * __restrict __f)
  {
    __mingw_bos_ptr_chk_warn(__dst, __n, 1);
    return __mingw_call_fgets(__dst, __n, __f);
  }

  __mingw_bos_extern_ovr __MINGW_NONNULL((4))
  size_t fread(void * __restrict __dst, size_t __sz, size_t __n, FILE * __restrict __f)
  {
    __mingw_bos_ptr_chk_warn(__dst, __sz * __n, 0);
    return __mingw_call_fread(__dst, __sz, __n, __f);
  }

  __mingw_bos_extern_ovr
  char * tmpnam(char * __dst)
  {
    __mingw_bos_ptr_chk_warn(__dst, L_tmpnam, 1);
    return __mingw_call_tmpnam(__dst);
  }

#endif  /* __MINGW_FORTIFY_LEVEL > 0 */

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

#pragma pop_macro("snprintf")
#pragma pop_macro("vsnprintf")

#endif  /* _INC_STDIO */
