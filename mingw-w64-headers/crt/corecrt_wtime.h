/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CORECRT_WTIME
#define _INC_CORECRT_WTIME

#include <corecrt.h>

__MINGW_BEGIN_C_DECLS

#ifndef _TM_DEFINED
# define _TM_DEFINED
  struct tm
  {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
  };
#endif

  _CRTIMP wchar_t *__cdecl _wasctime(const struct tm *_Tm) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t  __cdecl _wasctime_s(wchar_t *_Buf, size_t _SizeInWords, const struct tm *_Tm);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _wasctime_s, wchar_t, _Buffer, const struct tm *, _Time)
  _CRTIMP size_t   __cdecl  wcsftime(wchar_t *__restrict _Buf, size_t _SizeInWords, const wchar_t *__restrict _Format, const struct tm *__restrict _Tm) __MINGW_NONNULL((1, 3, 4));
  _CRTIMP size_t   __cdecl _wcsftime_l(wchar_t *__restrict _Buf, size_t _SizeInWords, const wchar_t *__restrict _Format, const struct tm *__restrict _Tm, _locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wctime32(const __time32_t *_Time) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t  __cdecl _wctime32_s(wchar_t *_Buf, size_t _SizeInWords, const __time32_t *_Time);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _wctime32_s, wchar_t, _Buffer, const __time32_t *, _Time)
  _CRTIMP wchar_t *__cdecl _wctime64(const __time64_t *_Time) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t  __cdecl _wctime64_s(wchar_t *_Buf, size_t _SizeInWords, const __time64_t *_Time);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _wctime64_s, wchar_t, _Buffer, const __time64_t *, _Time)
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t  __cdecl _wstrdate_s(wchar_t *_Buf, size_t _SizeInWords);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, _wstrdate_s, wchar_t, _Buffer)
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t  __cdecl _wstrtime_s(wchar_t *_Buf, size_t _SizeInWords);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, _wstrtime_s, wchar_t, _Buffer)

  wchar_t *__cdecl _wctime(const time_t *_Time) __MINGW_ASM_CALL(_wctime64) __MINGW_DEPRECATED_SEC_WARN;
  errno_t  __cdecl _wctime_s(wchar_t *_Buffer, size_t _SizeInWords, const time_t *_Time) __MINGW_ASM_CALL(_wctime64_s);

__MINGW_END_C_DECLS

#endif  /* _INC_CORECRT_WTIME */
