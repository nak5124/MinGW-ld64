/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_MEMORY
#define _INC_MEMORY

#include <corecrt.h>

__MINGW_BEGIN_C_DECLS

  _CRTIMP void *__cdecl _memccpy(void *__restrict _Dst, const void *__restrict _Src, int _Val, size_t _MaxCount) __NOTHROW __NONNULL((1, 2));
  _CRTIMP int   __cdecl _memicmp(const void *_Buf1, const void *_Buf2, size_t _Size);
  _CRTIMP int   __cdecl _memicmp_l(const void *_Buf1, const void *_Buf2, size_t _Size, _locale_t _Locale);

#if defined(__MINGW_USE_ISOC23) || defined(__MINGW_USE_XOPEN) || defined(__MINGW_USE_MISC) || defined(__MINGW_USE_MS)
  _CRTIMP void *__cdecl  memccpy(void *__restrict _Dst, const void *__restrict _Src, int _Val, size_t _Size) __NOTHROW __NONNULL((1, 2)) __MINGW_DEPRECATED_MSVC2005;
#endif
#ifdef __MINGW_USE_MS
  _CRTIMP int   __cdecl  memicmp(const void *_Buf1, const void *_Buf2, size_t _Size) __MINGW_DEPRECATED_MSVC2005;
#endif

  _CRTIMP void   *__cdecl memcpy(void *__restrict _Dst, const void *__restrict _Src, size_t _Size) __NOTHROW __NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl memcpy_s(void *_Dst, rsize_t _DstSize, const void *_Src, rsize_t _SrcSize);
#endif
  _CRTIMP void   *__cdecl memmove(void *_Dst, const void *_Src, size_t _Size) __NOTHROW __NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl memmove_s(void *_Dst, rsize_t _DstSize, const void *_Src, rsize_t _SrcSize);
#endif
  _CRTIMP _CONST_RETURN void *__cdecl memchr(const void *_Buf, int _Val, size_t _MaxCount) __NOTHROW __PURE __NONNULL((1));
  _CRTIMP int   __cdecl memcmp(const void *_Buf1, const void *_Buf2, size_t _Size)         __NOTHROW __PURE __NONNULL((1, 2));
  _CRTIMP void *__cdecl memset(void *_Dst, int _Val, size_t _Size)                         __NOTHROW __NONNULL((1));

__MINGW_END_C_DECLS

#include <ssp/memory.h>

#endif  /* _INC_MEMORY */
