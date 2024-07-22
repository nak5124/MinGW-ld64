/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CONIO
#define _INC_CONIO

#include <corecrt.h>
#include <corecrt_wconio.h>

#pragma pack(push, _CRT_PACKING)

__MINGW_BEGIN_C_DECLS

  _CRTIMP char *_cgets(char *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _cgets_s(char *_Buffer, size_t _Size, size_t *_SizeRead);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _cgets_s, char, _Buffer, size_t*, _SizeRead)
  _CRTIMP int __cdecl _cputs(const char *_Str);

  _CRTIMP int __cdecl __conio_common_vcprintf(unsigned __int64 _Options, const char *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __conio_common_vcprintf_s(unsigned __int64 _Options, const char *_Format, _locale_t _Locale, va_list _ArgList);
  _CRTIMP int __cdecl __conio_common_vcprintf_p(unsigned __int64 _Options, const char *_Format, _locale_t _Locale, va_list _ArgList);

  __mingw_ovr int __cdecl _vcprintf_l(const char * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __conio_common_vcprintf(0, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int __cdecl _vcprintf(const char * __restrict__ _Format, va_list _ArgList)
  {
    return __conio_common_vcprintf(0, _Format, NULL, _ArgList);
  }

  __mingw_ovr int __cdecl _vcprintf_s_l(const char * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __conio_common_vcprintf_s(0, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int __cdecl _vcprintf_s(const char * __restrict__ _Format, va_list _ArgList)
  {
    return __conio_common_vcprintf_s(0, _Format, NULL, _ArgList);
  }

  __mingw_ovr int __cdecl _vcprintf_p_l(const char * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __conio_common_vcprintf_p(0, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int __cdecl _vcprintf_p(const char * __restrict__ _Format, va_list _ArgList)
  {
    return __conio_common_vcprintf_p(0, _Format, NULL, _ArgList);
  }

  __mingw_ovr int __cdecl _cprintf_l(const char * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __conio_common_vcprintf(0, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _cprintf(const char * __restrict__ _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __conio_common_vcprintf(0,_Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _cprintf_s_l(const char * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __conio_common_vcprintf_s(0, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _cprintf_s(const char * __restrict__ _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __conio_common_vcprintf_s(0, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _cprintf_p_l(const char * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __conio_common_vcprintf_p(0, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _cprintf_p(const char * __restrict__ _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __conio_common_vcprintf_p(0, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  _CRTIMP int __cdecl __conio_common_vcscanf(unsigned __int64 _Options, const char *_Format, _locale_t _Locale, va_list _ArgList);

  __mingw_ovr __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int __cdecl _vcscanf_l(const char * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __conio_common_vcscanf(0, _Format, _Locale, _ArgList);
  }

  __mingw_ovr __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int __cdecl _vcscanf(const char * __restrict__ _Format, va_list _ArgList)
  {
    return __conio_common_vcscanf(0, _Format, NULL, _ArgList);
  }

  __mingw_ovr int __cdecl _vcscanf_s_l(const char * __restrict__ _Format, _locale_t _Locale, va_list _ArgList)
  {
    return __conio_common_vcscanf(_CRT_INTERNAL_SCANF_SECURECRT, _Format, _Locale, _ArgList);
  }

  __mingw_ovr int __cdecl _vcscanf_s(const char * __restrict__ _Format, va_list _ArgList)
  {
    return __conio_common_vcscanf(_CRT_INTERNAL_SCANF_SECURECRT, _Format, NULL, _ArgList);
  }

  __mingw_ovr __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int __cdecl _cscanf_l(const char * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Locale);
    _Ret = __conio_common_vcscanf(0, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr __MINGW_ATTRIB_DEPRECATED_SEC_WARN
  int __cdecl _cscanf(const char * __restrict__ _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __conio_common_vcscanf(0, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _cscanf_s_l(const char * __restrict__ _Format, _locale_t _Locale, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __conio_common_vcscanf(_CRT_INTERNAL_SCANF_SECURECRT, _Format, _Locale, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr int __cdecl _cscanf_s(const char * __restrict__ _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __conio_common_vcscanf(_CRT_INTERNAL_SCANF_SECURECRT, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  _CRTIMP int __cdecl _kbhit(void);

  _CRTIMP int __cdecl _getch(void);
  _CRTIMP int __cdecl _getche(void);
  _CRTIMP int __cdecl _putch(int _Ch);
  _CRTIMP int __cdecl _ungetch(int _Ch);

  _CRTIMP int __cdecl _getch_nolock(void);
  _CRTIMP int __cdecl _getche_nolock(void);
  _CRTIMP int __cdecl _putch_nolock(int _Ch);
  _CRTIMP int __cdecl _ungetch_nolock(int _Ch);

  _CRTIMP char* __cdecl cgets(char *_Buffer) __MINGW_ATTRIB_DEPRECATED_MSVC2005 __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl cputs(const char *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  _CRTIMP int __cdecl getch(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  _CRTIMP int __cdecl getche(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  _CRTIMP int __cdecl kbhit(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  _CRTIMP int __cdecl putch(int _Ch) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  _CRTIMP int __cdecl ungetch(int _Ch) __MINGW_ATTRIB_DEPRECATED_MSVC2005;

  __mingw_ovr __MINGW_ATTRIB_DEPRECATED_MSVC2005
  int __cdecl cprintf(const char * __restrict__ _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __conio_common_vcprintf(0, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

  __mingw_ovr __MINGW_ATTRIB_DEPRECATED_MSVC2005
  int __cdecl cscanf(const char * __restrict__ _Format, ...)
  {
    __builtin_va_list _ArgList;
    int _Ret;
    __builtin_va_start(_ArgList, _Format);
    _Ret = __conio_common_vcscanf(0, _Format, NULL, _ArgList);
    __builtin_va_end(_ArgList);
    return _Ret;
  }

__MINGW_END_C_DECLS

#pragma pack(pop)

#endif  /* _INC_CONIO */
