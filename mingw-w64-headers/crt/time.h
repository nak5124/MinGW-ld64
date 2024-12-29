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

  _CRTIMP int *__cdecl __daylight(void) __MINGW_DEPRECATED_SEC_WARN;
#define _daylight (* __daylight())

  _CRTIMP long *__cdecl __dstbias(void) __MINGW_DEPRECATED_SEC_WARN;
#define _dstbias (* __dstbias())

  _CRTIMP long *__cdecl __timezone(void) __MINGW_DEPRECATED_SEC_WARN;
#define _timezone (* __timezone())

  _CRTIMP char **__cdecl __tzname(void) __MINGW_DEPRECATED_SEC_WARN;
#define _tzname (__tzname())

  _CRTIMP errno_t __cdecl _get_daylight(int *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(long *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(long *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(size_t *_ReturnValue, char *_Buffer, size_t _SizeInBytes, int _Index);

  _CRTIMP char *__cdecl asctime(const struct tm *_Tm) __MINGW_NOTHROW __MINGW_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl asctime_s(char *_Buf, size_t _SizeInWords, const struct tm *_Tm);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, asctime_s, char, _Buffer, const struct tm *, _Time)
#endif
  _CRTIMP clock_t    __cdecl  clock(void) __MINGW_NOTHROW;
  _CRTIMP char      *__cdecl _ctime32(const __time32_t *_Time) __MINGW_NOTHROW __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t    __cdecl _ctime32_s(char *_Buf, size_t _SizeInBytes, const __time32_t *_Time);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _ctime32_s, char, _Buffer, const __time32_t *, _Time)
  _CRTIMP char      *__cdecl _ctime64(const __time64_t *_Time) __MINGW_NOTHROW __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t    __cdecl _ctime64_s(char *_Buf, size_t _SizeInBytes, const __time64_t *_Time);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _ctime64_s, char, _Buffer, const __time64_t *, _Time)
  _CRTIMP double     __cdecl _difftime32(__time32_t _Time1, __time32_t _Time2);
  _CRTIMP double     __cdecl _difftime64(__time64_t _Time1, __time64_t _Time2);
  _CRTIMP struct tm *__cdecl _gmtime32(const __time32_t *_Time) __MINGW_NOTHROW __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t    __cdecl _gmtime32_s(struct tm *_Tm, const __time32_t *_Time);
  _CRTIMP struct tm *__cdecl _gmtime64(const __time64_t *_Time) __MINGW_NOTHROW __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t    __cdecl _gmtime64_s(struct tm *_Tm, const __time64_t *_Time);
  _CRTIMP struct tm *__cdecl _localtime32(const __time32_t *_Time) __MINGW_NOTHROW __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t    __cdecl _localtime32_s(struct tm *_Tm, const __time32_t *_Time);
  _CRTIMP struct tm *__cdecl _localtime64(const __time64_t *_Time) __MINGW_NOTHROW __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t    __cdecl _localtime64_s(struct tm *_Tm, const __time64_t *_Time);
  _CRTIMP __time32_t __cdecl _mkgmtime32(struct tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(struct tm *_Tm);
  _CRTIMP __time32_t __cdecl _mktime32(struct tm *_Tm) __MINGW_NOTHROW;
  _CRTIMP __time64_t __cdecl _mktime64(struct tm *_Tm) __MINGW_NOTHROW;

  _CRTIMP size_t     __cdecl  strftime(char *__restrict _Buf, size_t _SizeInBytes, const char *__restrict _Format, const struct tm *__restrict _Tm)
                                          __MINGW_GNU_STRFTIME(3, 0) __MINGW_NONNULL((1, 3, 4)) __MINGW_NOTHROW;
  _CRTIMP size_t     __cdecl _strftime_l(char *__restrict _Buf, size_t _Max_size, const char *__restrict _Format,const struct tm *__restrict _Tm, _locale_t _Locale);
  _CRTIMP char      *__cdecl _strdate(char *_Buffer) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t    __cdecl _strdate_s(char *_Buf, size_t _SizeInBytes);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, _strdate_s, char, _Str)
  _CRTIMP char      *__cdecl _strtime(char *_Buffer) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t    __cdecl _strtime_s(char *_Buf, size_t _SizeInBytes);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, _strtime_s, char, _Str)
  _CRTIMP __time32_t __cdecl _time32(__time32_t *_Time) __MINGW_NOTHROW;
  _CRTIMP __time64_t __cdecl _time64(__time64_t *_Time) __MINGW_NOTHROW;
  _CRTIMP int        __cdecl _timespec32_get(struct _timespec32 *_Ts, int _Base) __MINGW_NONNULL((1)) __MINGW_NOTHROW;
  _CRTIMP int        __cdecl _timespec64_get(struct _timespec64 *_Ts, int _Base) __MINGW_NONNULL((1)) __MINGW_NOTHROW;

#ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
  extern void      __cdecl _tzset(void)                                   __MINGW_NOTHROW;
  _CRTIMP unsigned __cdecl _getsystime(struct tm *_Tm)                    __MINGW_DEPRECATED;
  _CRTIMP unsigned __cdecl _setsystime(struct tm *_Tm,unsigned _MilliSec) __MINGW_DEPRECATED;
#endif  /* _CRT_USE_WINAPI_FAMILY_DESKTOP_APP */

  char      *__cdecl  ctime(const time_t *_Time)             __MINGW_ASM_CALL(_ctime64)     __MINGW_NOTHROW __MINGW_DEPRECATED_SEC_WARN;
  double     __cdecl  difftime(time_t _Time1, time_t _Time2) __MINGW_ASM_CALL(_difftime64);
  struct tm *__cdecl  gmtime(const time_t *_Time)            __MINGW_ASM_CALL(_gmtime64)    __MINGW_NOTHROW __MINGW_DEPRECATED_SEC_WARN;
  struct tm *__cdecl  localtime(const time_t *_Time)         __MINGW_ASM_CALL(_localtime64) __MINGW_NOTHROW __MINGW_DEPRECATED_SEC_WARN;
  time_t     __cdecl _mkgmtime(struct tm *_Tm)               __MINGW_ASM_CALL(_mkgmtime64);
  time_t     __cdecl  mktime(struct tm *_Tm)                 __MINGW_ASM_CALL(_mktime64)    __MINGW_NOTHROW;
  time_t     __cdecl  time(time_t *_Time)                    __MINGW_ASM_CALL(_time64)      __MINGW_NOTHROW;
#ifdef __MINGW_USE_ISOC11
  int __cdecl timespec_get(struct timespec *_Ts, int _Base) __MINGW_ASM_CALL(_timespec64_get) __MINGW_NONNULL((1)) __MINGW_NOTHROW;
#endif
#ifdef __MINGW_USE_SECAPI
  errno_t __cdecl ctime_s(char *_Buf, size_t _SizeInBytes, const time_t *_Time) __MINGW_ASM_CALL(_ctime64_s);
# if _CRT_USE_CONFORMING_ANNEX_K_TIME
  __mingw_ovr
  errno_t gmtime_s(const time_t *_Time, struct tm *_Tm)
  {
    if(_gmtime64_s(_Tm, _Time) == 0)
    {
      return _Tm;
    }
    return NULL;
  }

  __mingw_ovr
  errno_t localtime_s(const time_t *_Time, struct tm *_Tm)
  {
    if(_localtime64_s(_Tm, _Time) == 0)
    {
      return _Tm;
    }
    return NULL;
  }
# else
  errno_t __cdecl gmtime_s(struct tm *_Tm, const time_t *_Time)    __MINGW_ASM_CALL(_gmtime64_s);
  errno_t __cdecl localtime_s(struct tm *_Tm, const time_t *_Time) __MINGW_ASM_CALL(_localtime64_s);
# endif
#endif

#if (!defined(__STRICT_ANSI__) || defined(__MINGW_USE_POSIX)) && !defined(__MINGW_USE_XOPEN2K) || defined(__MINGW_USE_MS)
# define CLK_TCK CLOCKS_PER_SEC
#endif

#if (defined(__MINGW_USE_POSIX) || defined(__MINGW_USE_MS)) && defined(_CRT_USE_WINAPI_FAMILY_DESKTOP_APP)
  extern void __cdecl tzset(void) __MINGW_NOTHROW __MINGW_DEPRECATED_MSVC2005;
#endif

#define __MINGW_DEPRECATED_UCRT \
  __MINGW_DEPRECATED_MSG( \
    "Only provided for source compatibility; this variable might " \
    "not always be accurate when linking to UCRT.")

#if defined(__MINGW_USE_XOPEN) || defined(__MINGW_USE_MISC) || defined(__MINGW_USE_MS)
  _CRTIMP extern int  daylight __MINGW_DEPRECATED_UCRT;
  _CRTIMP extern long timezone __MINGW_DEPRECATED_UCRT;
#endif
#if defined(__MINGW_USE_POSIX) || defined(__MINGW_USE_MS)
  _CRTIMP extern char *tzname[2] __MINGW_DEPRECATED_UCRT;
#endif

#include <_timeval.h>

#ifndef _TIMEZONE_DEFINED  /* Also in sys/time.h */
# define _TIMEZONE_DEFINED
  struct timezone
  {
    int tz_minuteswest;
    int tz_dsttime;
  };

  extern int __cdecl mingw_gettimeofday(struct timeval *__tv, struct timezone *__tz) __MINGW_NONNULL((1)) __MINGW_NOTHROW;
#endif  /* _TIMEZONE_DEFINED */

#include <errno.h>

#if defined(__MINGW_USE_ISOC23) || defined(__MINGW_USE_POSIX)
  extern struct tm *__cdecl localtime_r(const time_t *__restrict _Time, struct tm *__restrict _Tm) __MINGW_NOTHROW;
  extern struct tm *__cdecl gmtime_r(const time_t *__restrict _Time, struct tm *__restrict _Tm)    __MINGW_NOTHROW;

#ifndef __CRT__NO_INLINE
  __CRT_INLINE __MINGW_NOTHROW
  struct tm *__cdecl localtime_r(const time_t *__restrict _Time, struct tm *__restrict _Tm)
  {
    errno_t ret = _localtime64_s(_Tm, _Time);
    if(ret == 0)
    {
      return _Tm;
    }
    errno = ret;
    return NULL;
  }

  __CRT_INLINE __MINGW_NOTHROW
  struct tm *__cdecl gmtime_r(const time_t *__restrict _Time, struct tm *__restrict _Tm)
  {
    errno_t ret = _gmtime64_s(_Tm, _Time);
    if(ret == 0)
    {
      return _Tm;
    }
    errno = ret;
    return NULL;
  }
#endif  /* __CRT__NO_INLINE */
#endif

#ifdef __MINGW_USE_POSIX
  extern char *__cdecl ctime_r(const time_t *__restrict _Time, char *__restrict _Buf)    __MINGW_NOTHROW;
  extern char *__cdecl asctime_r(const struct tm *__restrict _Tm, char *__restrict _Buf) __MINGW_NOTHROW;

#ifndef __CRT__NO_INLINE
  __CRT_INLINE __MINGW_NOTHROW
  char *__cdecl ctime_r(const time_t *__restrict _Time, char *__restrict _Buf)
  {
    errno_t ret = _ctime64_s(_Buf, 26, _Time);
    if(ret == 0)
    {
      return _Buf;
    }
    errno = ret;
    return NULL;
  }

  _CRTIMP errno_t __cdecl _asctime_s(char *_Buf, size_t _SizeInWords, const struct tm *_Tm) __MINGW_ASM_CALL(asctime_s);
  __CRT_INLINE __MINGW_NOTHROW
  char *__cdecl asctime_r(const struct tm *__restrict _Tm, char *__restrict _Buf)
  {
    errno_t ret = _asctime_s(_Buf, 26, _Tm);
    if(ret == 0)
    {
      return _Buf;
    }
    errno = ret;
    return NULL;
  }
#endif  /* __CRT__NO_INLINE */
#endif

#ifdef __MINGW_USE_POSIX199309

/* Posix timers are supported */
#ifndef _POSIX_TIMERS
# define _POSIX_TIMERS 200809L
#endif

/* Monotonic clocks are available.  */
#ifndef _POSIX_MONOTONIC_CLOCK
# define _POSIX_MONOTONIC_CLOCK 200809L
#endif

/* CPU-time clocks are available.  */
#ifndef _POSIX_CPUTIME
# define _POSIX_CPUTIME 200809L
#endif

/* Clock support in threads are available.  */
#ifndef _POSIX_THREAD_CPUTIME
# define _POSIX_THREAD_CPUTIME 200809L
#endif

#ifndef __clockid_t_defined
  typedef int clockid_t;
# define __clockid_t_defined 1
#endif  /* __clockid_t_defined */

#ifndef TIMER_ABSTIME
# define TIMER_ABSTIME 1
#endif

#ifndef CLOCK_REALTIME
# define CLOCK_REALTIME 0
#endif

#ifndef CLOCK_MONOTONIC
# define CLOCK_MONOTONIC 1
#endif

#ifndef CLOCK_PROCESS_CPUTIME_ID
# define CLOCK_PROCESS_CPUTIME_ID 2
#endif

#ifndef CLOCK_THREAD_CPUTIME_ID
# define CLOCK_THREAD_CPUTIME_ID 3
#endif

#ifndef CLOCK_REALTIME_COARSE
# define CLOCK_REALTIME_COARSE 4
#endif

#ifndef _POSIX_TIMERS_DEFINED
# define _POSIX_TIMERS_DEFINED
  extern int __cdecl nanosleep(const struct timespec *request, struct timespec *remain);
  extern int __cdecl clock_nanosleep(clockid_t clock_id, int flags, const struct timespec *request, struct timespec *remain);
  extern int __cdecl clock_getres(clockid_t clock_id, struct timespec *res);
  extern int __cdecl clock_gettime(clockid_t clock_id, struct timespec *tp)       __MINGW_NONNULL((2));
  extern int __cdecl clock_settime(clockid_t clock_id, const struct timespec *tp) __MINGW_NONNULL((2));
#endif

#endif  /* __MINGW_USE_POSIX199309 */

#ifdef __MINGW_USE_ISOC23
  extern int __cdecl timespec_getres(struct timespec *_Ts, int _Base);
#endif

#if defined(__MINGW_USE_MISC) || defined(__MINGW_USE_ISOC23)
  /**/ time_t __cdecl timegm(struct tm *_Tm);
#endif

#ifdef __MINGW_USE_MISC
  /**/ time_t __cdecl timelocal(struct tm *_Tm);
#endif

__MINGW_END_C_DECLS

#endif  /* _TIME_H_ */
