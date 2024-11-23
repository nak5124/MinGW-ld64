/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _STRINGS_H_
#define _STRINGS_H_

#include <string.h>

#if defined(__MINGW_USE_MISC) || !defined(__MINGW_USE_XOPEN2K8)
  /**/   int  __cdecl bcmp(const void *_Buf1, const void *_Buf2, size_t _Size) __MINGW_NONNULL((1, 2)) __MINGW_PURE;
  extern void __cdecl bcopy(const void *_Src, void *_Dst, size_t _Size) __MINGW_NONNULL((1, 2));
  extern void __cdecl bzero(void *_Ptr, size_t _N) __MINGW_NONNULL((1));
#ifndef __CRT__NO_INLINE
  __CRT_INLINE __MINGW_NONNULL((1, 2))
  void __cdecl bcopy(const void *_Src, void *_Dst, size_t _Size)
  {
    (void)memmove(_Dst, _Src, _Size);
  }
  __CRT_INLINE __MINGW_NONNULL((1))
  void __cdecl bzero(void *_Ptr, size_t _N)
  {
    (void)memset(_Ptr, '\0', _N);
  }
#endif
#endif

#if defined(__MINGW_USE_MISC) || !defined(__MINGW_USE_XOPEN2K8) || defined(__MINGW_USE_XOPEN2K8XSI)
  extern int __cdecl ffs(int _Int) __MINGW_CONST;
#ifndef __CRT__NO_INLINE
  __CRT_INLINE __MINGW_CONST
  int __cdecl ffs(int _Int)
  {
    return __builtin_ffs(_Int);
  }
#endif
#endif

#ifdef __MINGW_USE_MISC
  /**/              extern int __cdecl ffsl(long _Long)        __MINGW_CONST;
  __MINGW_EXTENSION extern int __cdecl ffsll(long long _Llong) __MINGW_CONST;
#ifndef __CRT__NO_INLINE
  __CRT_INLINE __MINGW_CONST
  int __cdecl ffsl(long _Long)
  {
    return __builtin_ffsl(_Long);
  }

  __CRT_INLINE __MINGW_CONST
  int __cdecl ffsll(long long _Llong)
  {
    return __builtin_ffsll(_Llong);
  }
#endif
#endif

#endif  /* _STRINGS_H_ */
