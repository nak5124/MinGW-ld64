/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_TYPES
#define _INC_TYPES

#ifndef _WIN32
# error Only Win32 target is supported!
#endif

#include <corecrt.h>

#ifndef _INO_T_DEFINED
# define _INO_T_DEFINED
  typedef unsigned short _ino_t;
  typedef _ino_t          ino_t;
#endif

#ifndef _DEV_T_DEFINED
# define _DEV_T_DEFINED
  typedef unsigned int _dev_t;
  typedef _dev_t        dev_t;
#endif

#ifndef _OFF_T_DEFINED
# define _OFF_T_DEFINED
# ifndef _OFF_T_
#   define _OFF_T_
    typedef long _off_t;
#   ifdef __MINGW_USE_LFS
      typedef _off_t off32_t;
#   endif
# endif
# ifndef _OFF64_T_DEFINED
#   define _OFF64_T_DEFINED
    __MINGW_EXTENSION typedef long long _off64_t;
#   ifdef __MINGW_USE_LFS64
      __MINGW_EXTENSION typedef _off64_t off64_t;
#   endif
# endif
# ifdef __MINGW_USE_FOB64
    typedef _off64_t off_t;
# else
    typedef _off_t   off_t;
# endif
#endif

#ifndef _PID_T_
# define _PID_T_
  __MINGW_EXTENSION typedef __int64 _pid_t;
# undef pid_t
  typedef _pid_t pid_t;
#endif

#ifndef _MODE_T_
# define _MODE_T_
  typedef unsigned short _mode_t;
  typedef _mode_t         mode_t;
#endif

  typedef unsigned int useconds_t;

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

#ifndef _SIGSET_T_
# define _SIGSET_T_
  __MINGW_EXTENSION typedef unsigned long long _sigset_t;
                    typedef _sigset_t           sigset_t;
#endif

#endif  /* _INC_TYPES */
