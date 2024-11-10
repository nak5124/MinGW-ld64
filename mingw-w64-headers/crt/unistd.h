/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _UNISTD_H
#define _UNISTD_H
#define __UNISTD_H_SOURCED__ 1

#include <io.h>
#include <process.h>
#include <getopt.h>
#include <sys/types.h>  /* For useconds_t. */

__MINGW_BEGIN_C_DECLS

/* These are also defined in stdio.h. */
#ifndef SEEK_SET
# define SEEK_SET 0
# define SEEK_CUR 1
# define SEEK_END 2
#endif

/* These are also defined in stdio.h. */
#ifndef STDIN_FILENO
# define STDIN_FILENO  0
# define STDOUT_FILENO 1
# define STDERR_FILENO 2
#endif

/* Used by shutdown(2). */
#ifdef __MINGW_USE_POSIX

/* MySql connector already defined SHUT_RDWR. */
#ifndef SHUT_RDWR
# define SHUT_RD   0x00
# define SHUT_WR   0x01
# define SHUT_RDWR 0x02
#endif

#endif

#pragma push_macro("sleep")
#undef sleep
  extern unsigned int __cdecl sleep(unsigned __seconds);
#pragma pop_macro("sleep")

#if (defined(__MINGW_USE_XOPEN_EXT) && !defined(__MINGW_USE_XOPEN2K8)) || defined(__MINGW_USE_MISC)
  extern int __cdecl usleep(useconds_t __useconds) __MINGW_NOTHROW;
#endif

#if defined(__MINGW_USE_XOPEN_EXT) || defined(__MINGW_USE_XOPEN2K)
# ifndef __MINGW_USE_FOB64
    extern int __cdecl truncate(const char *__file, off_t __length) __MINGW_NONNULL((1));
# else
    extern int __cdecl truncate(const char *__file, off_t __length) __MINGW_ASM_CALL(truncate64) __MINGW_NONNULL((1));
# endif
# ifdef __MINGW_USE_LFS64
    extern int __cdecl truncate64(const char *__file, off64_t __length) __MINGW_NONNULL((1));
# endif
#endif

#if defined(__MINGW_USE_POSIX199309) || defined(__MINGW_USE_XOPEN_EXT) || defined(__MINGW_USE_XOPEN2K)
# ifndef __MINGW_USE_FOB64
    extern int __cdecl ftruncate(int __fd, off_t __length);
#   ifndef __CRT__NO_INLINE
      __CRT_INLINE
      int __cdecl ftruncate(int __fd, off_t __length)
      {
        return _chsize(__fd, __length);
      }
#   endif
# else
    extern int __cdecl ftruncate(int __fd, off_t __length) __MINGW_ASM_CALL(ftruncate64);
# endif
# ifdef __MINGW_USE_LFS64
    extern int __cdecl ftruncate64(int __fd, off64_t __length);
# endif
#endif

#ifndef _CRT_SWAB_DEFINED  /* Also in stdlib.h */
# define _CRT_SWAB_DEFINED
# if defined(__MINGW_USE_XOPEN) || defined(__MINGW_USE_MS)
    _CRTIMP void __cdecl swab(char *_Buf1, char *_Buf2, int _SizeInBytes) __MINGW_NONNULL((1, 2)) __MINGW_DEPRECATED_MSVC2005;
# endif
#endif  /* _CRT_SWAB_DEFINED */

#if defined(_CRT_USE_WINAPI_FAMILY_DESKTOP_APP) || defined(WINSTORECOMPAT)
# ifndef _CRT_GETPID_DEFINED  /* Also in process.h */
#   define _CRT_GETPID_DEFINED
    _CRTIMP int __cdecl getpid(void) __MINGW_DEPRECATED_MSVC2005;
# endif
#endif  /* defined(_CRT_USE_WINAPI_FAMILY_DESKTOP_APP) || defined(WINSTORECOMPAT) */

#ifdef __MINGW_USE_MISC
  extern int __cdecl getentropy(void *_Buffer, size_t _Length);
#endif

__MINGW_END_C_DECLS

#include <pthread_unistd.h>

#undef __UNISTD_H_SOURCED__

#endif  /* _UNISTD_H */
