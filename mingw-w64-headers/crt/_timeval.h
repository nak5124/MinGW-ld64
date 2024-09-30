/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _TIMEVAL_DEFINED
#define _TIMEVAL_DEFINED

#include <corecrt.h>

  struct timeval
  {
    long tv_sec;
    long tv_usec;
  };

#if defined(__MINGW_USE_MISC) || defined(_WINSOCKAPI_) || defined(_WINSOCK2API_)
# define timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
# define timerclear(tvp) ((tvp)->tv_sec = (tvp)->tv_usec = 0)
# define timercmp(tvp, uvp, cmp)          \
  (((tvp)->tv_sec == (uvp)->tv_sec)       \
    ? ((tvp)->tv_usec cmp (uvp)->tv_usec) \
    : ((tvp)->tv_sec cmp (uvp)->tv_sec))
#endif

#endif  /* _TIMEVAL_DEFINED */
