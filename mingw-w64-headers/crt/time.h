/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _TIME_H_
#define _TIME_H_

#ifndef _WIN32
# error Only Win32 target is supported!
#endif

#include <corecrt.h>
#include <corecrt_wtime.h>

/* Adding timespec definition. */
#include <sys/timeb.h>

__MINGW_BEGIN_C_DECLS

#ifndef _CRT_USE_CONFORMING_ANNEX_K_TIME
# define _CRT_USE_CONFORMING_ANNEX_K_TIME 0
#endif

#ifndef _CLOCK_T_DEFINED
# define _CLOCK_T_DEFINED
  typedef long clock_t;
#endif

#define CLOCKS_PER_SEC ((clock_t)1000)

#ifdef __MINGW_USE_ISOC11
# define TIME_UTC 1
#endif

  _CRTIMP int *__cdecl __daylight(void) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#define _daylight (* __daylight())

  _CRTIMP long *__cdecl __dstbias(void) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#define _dstbias (* __dstbias())

  _CRTIMP long *__cdecl __timezone(void) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#define _timezone (* __timezone())

  _CRTIMP char **__cdecl __tzname(void) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#define _tzname (__tzname())

  _CRTIMP errno_t __cdecl _get_daylight(int *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(long *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(long *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(size_t *_ReturnValue, char *_Buffer, size_t _SizeInBytes, int _Index);

  _CRTIMP char *__cdecl asctime(const struct tm *_Tm) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl asctime_s(char *_Buf, size_t _SizeInWords, const struct tm *_Tm);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, asctime_s, char, _Buffer, const struct tm *, _Time)
#endif
  _CRTIMP clock_t __cdecl clock(void);
  _CRTIMP char *__cdecl _ctime32(const __time32_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _ctime32_s(char *_Buf, size_t _SizeInBytes, const __time32_t *_Time);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _ctime32_s, char, _Buffer, const __time32_t *, _Time)
  _CRTIMP char *__cdecl _ctime64(const __time64_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _ctime64_s(char *_Buf, size_t _SizeInBytes, const __time64_t *_Time);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _ctime64_s, char, _Buffer, const __time64_t *, _Time)
  _CRTIMP double __cdecl _difftime32(__time32_t _Time1, __time32_t _Time2);
  _CRTIMP double __cdecl _difftime64(__time64_t _Time1, __time64_t _Time2);
  _CRTIMP struct tm *__cdecl _gmtime32(const __time32_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _gmtime32_s(struct tm *_Tm, const __time32_t *_Time);
  _CRTIMP struct tm *__cdecl _gmtime64(const __time64_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _gmtime64_s(struct tm *_Tm, const __time64_t *_Time);
  _CRTIMP struct tm *__cdecl _localtime32(const __time32_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _localtime32_s(struct tm *_Tm, const __time32_t *_Time);
  _CRTIMP struct tm *__cdecl _localtime64(const __time64_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _localtime64_s(struct tm *_Tm, const __time64_t *_Time);
  _CRTIMP __time32_t __cdecl _mkgmtime32(struct tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(struct tm *_Tm);
  _CRTIMP __time32_t __cdecl _mktime32(struct tm *_Tm);
  _CRTIMP __time64_t __cdecl _mktime64(struct tm *_Tm);

  _CRTIMP size_t __cdecl strftime(char * __restrict__ _Buf, size_t _SizeInBytes, const char * __restrict__ _Format, const struct tm * __restrict__ _Tm) __MINGW_GNU_STRFTIME(3, 0);
  _CRTIMP size_t __cdecl _strftime_l(char * __restrict__ _Buf, size_t _Max_size, const char * __restrict__ _Format,const struct tm * __restrict__ _Tm, _locale_t _Locale);
  _CRTIMP char *__cdecl _strdate(char *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _strdate_s(char *_Buf, size_t _SizeInBytes);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, _strdate_s, char, _Str)
  _CRTIMP char *__cdecl _strtime(char *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _strtime_s(char *_Buf, size_t _SizeInBytes);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, _strtime_s, char, _Str)
  _CRTIMP __time32_t __cdecl _time32(__time32_t *_Time);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *_Time);
  _CRTIMP int __cdecl _timespec32_get(struct _timespec32 *_Ts, int _Base);
  _CRTIMP int __cdecl _timespec64_get(struct _timespec64 *_Ts, int _Base);

#ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
  extern void __cdecl _tzset(void);
  _CRTIMP unsigned __cdecl _getsystime(struct tm *_Tm) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP unsigned __cdecl _setsystime(struct tm *_Tm,unsigned _MilliSec) __MINGW_ATTRIB_DEPRECATED;
#endif  /* _CRT_USE_WINAPI_FAMILY_DESKTOP_APP */

  char *__cdecl ctime(const time_t *_Time) __MINGW_ASM_CALL(_ctime64) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  double __cdecl difftime(time_t _Time1, time_t _Time2) __MINGW_ASM_CALL(_difftime64);
  struct tm *__cdecl gmtime(const time_t *_Time) __MINGW_ASM_CALL(_gmtime64) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  struct tm *__cdecl localtime(const time_t *_Time) __MINGW_ASM_CALL(_localtime64) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  time_t __cdecl _mkgmtime(struct tm *_Tm) __MINGW_ASM_CALL(_mkgmtime64);
  time_t __cdecl mktime(struct tm *_Tm) __MINGW_ASM_CALL(_mktime64);
  time_t __cdecl time(time_t *_Time) __MINGW_ASM_CALL(_time64);
#ifdef __MINGW_USE_ISOC11
  int __cdecl timespec_get(struct timespec* _Ts, int _Base) __MINGW_ASM_CALL(_timespec64_get);
#endif
#ifdef __MINGW_USE_SECAPI
  errno_t __cdecl ctime_s(char *_Buf, size_t _SizeInBytes, const time_t *_Time) __MINGW_ASM_CALL(_ctime64_s);
# if _CRT_USE_CONFORMING_ANNEX_K_TIME
  __mingw_ovr errno_t __cdecl gmtime_s(const time_t *_Time, struct tm *_Tm)
  {
    if(_gmtime64_s(_Tm, _Time) == 0)
    {
      return _Tm;
    }
    return NULL;
  }

  __mingw_ovr errno_t __cdecl localtime_s(const time_t *_Time, struct tm *_Tm)
  {
    if(_localtime64_s(_Tm, _Time) == 0)
    {
      return _Tm;
    }
    return NULL;
  }
# else
  errno_t __cdecl gmtime_s(struct tm *_Tm, const time_t *_Time) __MINGW_ASM_CALL(_gmtime64_s);
  errno_t __cdecl localtime_s(struct tm *_Tm, const time_t *_Time) __MINGW_ASM_CALL(_localtime64_s);
# endif
#endif

#if (!defined(__STRICT_ANSI__) || defined(__MINGW_USE_POSIX)) && !defined(__MINGW_USE_XOPEN2K) || defined(__MINGW_USE_MS)
# define CLK_TCK CLOCKS_PER_SEC
#endif

#if (defined(__MINGW_USE_POSIX) || defined(__MINGW_USE_MS)) && defined(_CRT_USE_WINAPI_FAMILY_DESKTOP_APP)
  extern void __cdecl tzset(void) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif

#define __MINGW_ATTRIB_DEPRECATED_UCRT \
  __MINGW_ATTRIB_DEPRECATED_MSG( \
    "Only provided for source compatibility; this variable might " \
    "not always be accurate when linking to UCRT.")

#if defined(__MINGW_USE_XOPEN) || defined(__MINGW_USE_MISC) || defined(__MINGW_USE_MS)
  _CRTIMP extern int daylight __MINGW_ATTRIB_DEPRECATED_UCRT;
  _CRTIMP extern long timezone __MINGW_ATTRIB_DEPRECATED_UCRT;
#endif
#if defined(__MINGW_USE_POSIX) || defined(__MINGW_USE_MS)
  _CRTIMP extern char *tzname[2] __MINGW_ATTRIB_DEPRECATED_UCRT;
#endif

#include <_timeval.h>

#ifndef _TIMEZONE_DEFINED  /* Also in sys/time.h */
# define _TIMEZONE_DEFINED
  struct timezone
  {
    int tz_minuteswest;
    int tz_dsttime;
  };

  extern int __cdecl mingw_gettimeofday(struct timeval *p, struct timezone *z);
#endif  /* _TIMEZONE_DEFINED */

#if defined(__MINGW_USE_ISOC23) || defined(__MINGW_USE_POSIX)
  __forceinline struct tm *__cdecl localtime_r(const time_t *_Time, struct tm *_Tm)
  {
    return _localtime64_s(_Tm, _Time) ? NULL : _Tm;
  }

  __forceinline struct tm *__cdecl gmtime_r(const time_t *_Time, struct tm *_Tm)
  {
    return _gmtime64_s(_Tm, _Time) ? NULL : _Tm;
  }

  __forceinline char *__cdecl ctime_r(const time_t *_Time, char *_Str)
  {
    return _ctime64_s(_Str, 0x7fffffff, _Time) ? NULL : _Str;
  }

  _CRTIMP errno_t __cdecl _asctime_s(char *_Buf, size_t _SizeInWords, const struct tm *_Tm) __MINGW_ASM_CALL(asctime_s);
  __forceinline char *__cdecl asctime_r(const struct tm *_Tm, char * _Str)
  {
    return _asctime_s(_Str, 0x7fffffff, _Tm) ? NULL : _Str;
  }
#endif

__MINGW_END_C_DECLS

/* POSIX 2008 says clock_gettime and timespec are defined in time.h header,
   but other systems - like Linux, Solaris, etc - tend to declare such
   recent extensions only if the following guards are met.  */
#if !defined(IN_WINPTHREAD) && defined(__MINGW_USE_POSIX199309)
#include <pthread_time.h>
#endif

#endif  /* _TIME_H_ */
