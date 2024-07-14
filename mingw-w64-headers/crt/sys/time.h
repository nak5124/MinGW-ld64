/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _SYS_TIME_H_
#define _SYS_TIME_H_

#include <time.h>

#ifdef __cplusplus
extern "C" {
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

  /* Implementation as per:
     The Open Group Base Specifications, Issue 6
     IEEE Std 1003.1, 2004 Edition
     The timezone pointer arg is ignored.  Errors are ignored. */
#ifndef _GETTIMEOFDAY_DEFINED
# define _GETTIMEOFDAY_DEFINED
  int __cdecl gettimeofday(struct timeval *__restrict__ p, void *__restrict__  z);
#endif

#ifdef __cplusplus
}
#endif

/* Adding timespec definition.  */
#include <sys/timeb.h>

#endif  /* _SYS_TIME_H_ */
