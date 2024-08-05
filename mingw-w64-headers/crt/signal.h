/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_SIGNAL
#define _INC_SIGNAL

#include <corecrt.h>
#include <pthread_signal.h>

__MINGW_BEGIN_C_DECLS

#ifndef _SIG_ATOMIC_T_DEFINED
# define _SIG_ATOMIC_T_DEFINED
  typedef int sig_atomic_t;
#endif

#define NSIG 23

#define SIGINT         2
#define SIGILL         4
#define SIGABRT_COMPAT 6
#define SIGFPE         8
#define SIGSEGV        11
#define SIGTERM        15
#define SIGBREAK       21
#define SIGABRT        22  /* used by abort, replace SIGIOT in the future */
#define SIGABRT2       22

#ifdef __MINGW_USE_POSIX
# define SIGHUP  1   /* hangup */
# define SIGQUIT 3   /* quit */
# define SIGTRAP 5   /* trace trap (not reset when caught) */
# define SIGIOT  6   /* IOT instruction */
# define SIGEMT  7   /* EMT instruction */
# define SIGKILL 9   /* kill (cannot be caught or ignored) */
# define SIGBUS  10  /* bus error */
# define SIGSYS  12  /* bad argument to system call */
# define SIGPIPE 13  /* write on a pipe with no one to read it */
# ifdef __USE_MINGW_ALARM
#   define SIGALRM 14  /* alarm clock */
# endif
#endif

  typedef void (__cdecl *__p_sig_fn_t)(int);

#define SIG_DFL (__p_sig_fn_t)0
#define SIG_IGN (__p_sig_fn_t)1
#define SIG_GET (__p_sig_fn_t)2
#define SIG_SGE (__p_sig_fn_t)3
#define SIG_ACK (__p_sig_fn_t)4
#define SIG_ERR (__p_sig_fn_t)-1

  _CRTIMP void **__cdecl __pxcptinfoptrs(void);
#define _pxcptinfoptrs (*__pxcptinfoptrs())

  _CRTIMP __p_sig_fn_t __cdecl signal(int _SigNum, __p_sig_fn_t _Func);
  _CRTIMP int __cdecl raise(int _SigNum);

__MINGW_END_C_DECLS

#endif  /* _INC_SIGNAL */
