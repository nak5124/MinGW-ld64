/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _TIMEB_H_
#define _TIMEB_H_

#ifndef _WIN32
# error Only Win32 target is supported!
#endif

#include <corecrt.h>

__MINGW_BEGIN_C_DECLS

  struct __timeb32
  {
    __time32_t     time;
    unsigned short millitm;
    short          timezone;
    short          dstflag;
  };

  struct __timeb64
  {
    __time64_t     time;
    unsigned short millitm;
    short          timezone;
    short          dstflag;
  };

#ifndef _TIMEB_DEFINED
# define _TIMEB_DEFINED
  struct timeb
  {
    time_t         time;
    unsigned short millitm;
    short          timezone;
    short          dstflag;
  };
#endif

#define _timeb   __timeb64
#define _ftime   _ftime64
#define _ftime_s _ftime64_s

  _CRTIMP void    __cdecl _ftime32(struct __timeb32 *_Time) __MINGW_NONNULL((1)) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _ftime32_s(struct __timeb32 *_Time);
  _CRTIMP void    __cdecl _ftime64(struct __timeb64 *_Time) __MINGW_NONNULL((1)) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _ftime64_s(struct __timeb64 *_Time);

  void __cdecl ftime(struct timeb *_Time) __MINGW_ASM_CALL(_ftime64) __MINGW_NONNULL((1));

  struct _timespec32
  {
    __time32_t tv_sec;
    long       tv_nsec;
  };

  struct _timespec64
  {
    __time64_t tv_sec;
    long       tv_nsec;
  };

#ifndef _TIMESPEC_DEFINED
# define _TIMESPEC_DEFINED
  struct timespec
  {
    time_t tv_sec;   /* Seconds */
    long   tv_nsec;  /* Nanoseconds */
  };

  struct itimerspec
  {
    struct timespec it_interval;  /* Timer period */
    struct timespec it_value;     /* Timer expiration */
  };
#endif

__MINGW_END_C_DECLS

#endif  /* _TIMEB_H_ */
