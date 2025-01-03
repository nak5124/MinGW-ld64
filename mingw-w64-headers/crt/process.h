/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_PROCESS
#define _INC_PROCESS

#include <corecrt.h>
#include <corecrt_startup.h>
#include <corecrt_wprocess.h>

/* Includes a definition of _pid_t and pid_t */
#include <sys/types.h>

__MINGW_BEGIN_C_DECLS

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

#ifndef _CRT_TERMINATE_DEFINED  /* Also in stdlib.h */
# define _CRT_TERMINATE_DEFINED
  extern void __cdecl  exit(int _Code) __MINGW_NORETURN __MINGW_NOTHROW;
  extern void __cdecl _exit(int _Code) __MINGW_NORETURN __MINGW_NOTHROW;
# if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)
    extern void __cdecl _Exit(int _Code) __MINGW_NORETURN __MINGW_NOTHROW;
# endif
# if defined(__MINGW_USE_ISOC11) || defined(__MINGW_USE_ISOCXX11)
    extern void __cdecl quick_exit(int _Code) __MINGW_NORETURN __MINGW_NOTHROW;
# endif
# pragma push_macro("abort")
# undef abort
  _CRTIMP void __cdecl abort(void) __MINGW_NORETURN __MINGW_NOTHROW;
# pragma pop_macro("abort")
#endif  /* _CRT_TERMINATE_DEFINED */

#ifndef _CRT_SYSTEM_DEFINED  /* Also in stdlib.h */
# define _CRT_SYSTEM_DEFINED
  _CRTIMP int __cdecl system(const char *_Command);
#endif  /* _CRT_SYSTEM_DEFINED */

  _CRTIMP void __cdecl _cexit(void) __MINGW_NOTHROW;
  _CRTIMP void __cdecl _c_exit(void) __MINGW_NOTHROW;

  typedef void (__stdcall *_tls_callback_type)(void *, unsigned long, void *);
  _CRTIMP void __cdecl _register_thread_local_exe_atexit_callback(_tls_callback_type _Callback);

#ifdef _DECL_DLLMAIN
# ifdef _WINDOWS_
    WINBOOL WINAPI  DllMain(HANDLE _HDllHandle, DWORD _Reason, LPVOID _Reserved);
    WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle, DWORD _Reason, LPVOID _Reserved);
    WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle, DWORD _Reason, LPVOID _Reserved);
    extern WINBOOL (WINAPI *const _pRawDllMain)(HANDLE, DWORD, LPVOID);
# else
    int __stdcall  DllMain(void *_HDllHandle, unsigned long _Reason, void *_Reserved);
    int __stdcall _CRT_INIT(void *_HDllHandle, unsigned long _Reason, void *_Reserved);
    int __stdcall _wCRT_INIT(void *_HDllHandle, unsigned long _Reason, void *_Reserved);
    extern int (__stdcall *const _pRawDllMain)(void *, unsigned long, void *);
# endif
#endif

  typedef void     (__cdecl   *_beginthread_proc_type  )(void *);
  typedef unsigned (__stdcall *_beginthreadex_proc_type)(void *);

  _CRTIMP uintptr_t __cdecl _beginthread(_beginthread_proc_type _StartAddress, unsigned _StackSize, void *_ArgList);
  _CRTIMP void      __cdecl _endthread(void) __MINGW_NORETURN;
  _CRTIMP uintptr_t __cdecl _beginthreadex(void *_Security, unsigned _StackSize, _beginthreadex_proc_type _StartAddress, void *_ArgList, unsigned _InitFlag, unsigned *_ThrdAddr);
  _CRTIMP void      __cdecl _endthreadex(unsigned _Retval) __MINGW_NORETURN;

#ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
  _CRTIMP int      __cdecl _getpid(void);
  _CRTIMP intptr_t __cdecl _cwait(int *_TermStat, intptr_t _ProcHandle, int _Action);
  _CRTIMP intptr_t __cdecl _execl(const char *_Filename, const char *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _execle(const char *_Filename, const char *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _execlp(const char *_Filename, const char *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _execlpe(const char *_Filename, const char *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _execv(const char *_Filename, const char *const *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(const char *_Filename, const char *const *_ArgList, const char *const *_Env);
  _CRTIMP intptr_t __cdecl _execvp(const char *_Filename, const char *const *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(const char *_Filename, const char *const *_ArgList, const char *const *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(int _Mode, const char *_Filename, const char *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _spawnle(int _Mode, const char *_Filename, const char *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _spawnlp(int _Mode, const char *_Filename, const char *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _spawnlpe(int _Mode, const char *_Filename, const char *_ArgList, ...);

#ifndef _SPAWNV_DEFINED  /* Also in stdio.h */
# define _SPAWNV_DEFINED
  _CRTIMP intptr_t __cdecl _spawnv(int _Mode, const char *_Filename, const char *const *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(int _Mode, const char *_Filename, const char *const *_ArgList, const char *const *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(int _Mode, const char *_Filename, const char *const *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(int _Mode, const char *_Filename, const char *const *_ArgList, const char *const *_Env);
#endif  /* _SPAWNV_DEFINED */

  _CRTIMP intptr_t __cdecl _loaddll(char *_Filename)    __MINGW_DEPRECATED;
  _CRTIMP int      __cdecl _unloaddll(intptr_t _Handle) __MINGW_DEPRECATED;

  typedef int (__cdecl* _GetDllProcAddrProcType)(void);
  _CRTIMP _GetDllProcAddrProcType __cdecl _getdllprocaddr(intptr_t _Handle, char *_ProcedureName, intptr_t _Ordinal) __MINGW_DEPRECATED;

#endif  /* _CRT_USE_WINAPI_FAMILY_DESKTOP_APP */

#ifdef __MINGW_USE_MS
# define P_WAIT          _P_WAIT
# define P_NOWAIT        _P_NOWAIT
# define P_OVERLAY       _P_OVERLAY
# define OLD_P_OVERLAY   _OLD_P_OVERLAY
# define P_NOWAITO       _P_NOWAITO
# define P_DETACH        _P_DETACH
# define WAIT_CHILD      _WAIT_CHILD
# define WAIT_GRANDCHILD _WAIT_GRANDCHILD
#endif

#ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP

#ifdef __MINGW_USE_MS
  _CRTIMP intptr_t __cdecl cwait(int *_TermStat, intptr_t _ProcHandle, int _Action) __MINGW_DEPRECATED_MSVC2005;
#endif
  _CRTIMP int      __cdecl execl(const char *_Filename, const char *_ArgList, ...)  __MINGW_NONNULL((1, 2)) __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP int      __cdecl execle(const char *_Filename, const char *_ArgList, ...) __MINGW_NONNULL((1, 2)) __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP int      __cdecl execlp(const char *_Filename, const char *_ArgList, ...) __MINGW_NONNULL((1, 2)) __MINGW_DEPRECATED_MSVC2005;
#if defined(__MINGW_USE_MISC) || defined(__MINGW_USE_MS)
  _CRTIMP int      __cdecl execlpe(const char *_Filename, const char *_ArgList, ...) __MINGW_NONNULL((1, 2)) __MINGW_DEPRECATED_MSVC2005;
#endif
#ifdef __MINGW_USE_MS
  _CRTIMP intptr_t __cdecl spawnl(int _Mode, const char *_Filename, const char *_ArgList, ...)   __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP intptr_t __cdecl spawnle(int _Mode, const char *_Filename, const char *_ArgList, ...)  __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP intptr_t __cdecl spawnlp(int _Mode, const char *_Filename, const char *_ArgList, ...)  __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP intptr_t __cdecl spawnlpe(int _Mode, const char *_Filename, const char *_ArgList, ...) __MINGW_DEPRECATED_MSVC2005;
#endif
  /* Those methods are predefined by gcc builtins to return int. So to prevent
   * stupid warnings, define them in POSIX way.  This is save, because those
   * methods do not return in success case, so that the return value is not
   * really dependent to its scalar width. */
  _CRTIMP int __cdecl execv(const char *_Filename, char *const _ArgList[])                       __MINGW_NONNULL((1, 2)) __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP int __cdecl execve(const char *_Filename, char *const _ArgList[], char *const _Env[])  __MINGW_NONNULL((1, 2)) __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP int __cdecl execvp(const char *_Filename, char *const _ArgList[])                      __MINGW_NONNULL((1, 2)) __MINGW_DEPRECATED_MSVC2005;
#if defined(__MINGW_USE_GNU) || defined(__MINGW_USE_MS)
  _CRTIMP int __cdecl execvpe(const char *_Filename, char *const _ArgList[], char *const _Env[]) __MINGW_NONNULL((1, 2)) __MINGW_DEPRECATED_MSVC2005;
#endif
#ifdef __MINGW_USE_MS
  _CRTIMP intptr_t __cdecl spawnv(int _Mode,const char *_Filename, char *const _ArgList[])                       __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP intptr_t __cdecl spawnve(int _Mode,const char *_Filename, char *const _ArgList[], char *const _Env[])  __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP intptr_t __cdecl spawnvp(int _Mode,const char *_Filename, char *const _ArgList[])                      __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP intptr_t __cdecl spawnvpe(int _Mode,const char *_Filename, char *const _ArgList[], char *const _Env[]) __MINGW_DEPRECATED_MSVC2005;
#endif

#endif  /* _CRT_USE_WINAPI_FAMILY_DESKTOP_APP */

#if defined(_CRT_USE_WINAPI_FAMILY_DESKTOP_APP) || defined(WINSTORECOMPAT)
# ifndef _CRT_GETPID_DEFINED  /* Also in unistd.h */
#   define _CRT_GETPID_DEFINED
    _CRTIMP int __cdecl getpid(void) __MINGW_DEPRECATED_MSVC2005;
# endif
#endif  /* defined(_CRT_USE_WINAPI_FAMILY_DESKTOP_APP) || defined(WINSTORECOMPAT) */

__MINGW_END_C_DECLS

#endif  /* _INC_PROCESS */
