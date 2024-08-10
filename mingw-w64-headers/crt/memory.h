/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_MEMORY
#define _INC_MEMORY

#include <corecrt.h>

__MINGW_BEGIN_C_DECLS

  _CRTIMP void *__cdecl _memccpy(void *_Dst, const void *_Src, int _Val, size_t _MaxCount) __MINGW_NONNULL((1, 2));
  _CRTIMP int __cdecl _memicmp(const void *_Buf1, const void *_Buf2, size_t _Size);
  _CRTIMP int __cdecl _memicmp_l(const void *_Buf1, const void *_Buf2, size_t _Size, _locale_t _Locale);

#if defined(__MINGW_USE_ISOC23) || defined(__MINGW_USE_XOPEN) || defined(__MINGW_USE_MISC) || defined(__MINGW_USE_MS)
  _CRTIMP void * __cdecl memccpy(void *_Dst, const void *_Src, int _Val, size_t _Size) __MINGW_NONNULL((1, 2)) __MINGW_DEPRECATED_MSVC2005;
#endif
#ifdef __MINGW_USE_MS
  _CRTIMP int __cdecl memicmp(const void *_Buf1, const void *_Buf2, size_t _Size) __MINGW_DEPRECATED_MSVC2005;
#endif

  _CRTIMP void *__cdecl memcpy(void * __restrict _Dst, const void * __restrict _Src, size_t _Size) __MINGW_NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl memcpy_s(void *_dest, size_t _numberOfElements, const void *_src, size_t _count);
#endif
  _CRTIMP void *__cdecl memmove(void *_Dst, const void *_Src, size_t _Size) __MINGW_NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl memmove_s(void *_dest, size_t _numberOfElements, const void *_src, size_t _count);
#endif
  _CRTIMP _CONST_RETURN void *__cdecl memchr(const void *_Buf, int _Val, size_t _MaxCount) __MINGW_NONNULL((1)) __MINGW_PURE;
  _CRTIMP int __cdecl memcmp(const void *_Buf1, const void *_Buf2, size_t _Size) __MINGW_NONNULL((1, 2)) __MINGW_PURE;
  _CRTIMP void *__cdecl memset(void *_Dst, int _Val, size_t _Size) __MINGW_NONNULL((1));

#if __MINGW_FORTIFY_LEVEL > 0

#ifndef __MINGW_BOS_DECLARE_DEFINED
# define __MINGW_BOS_DECLARE_DEFINED
  __mingw_bos_declare;
#endif

  __mingw_bos_extern_ovr __MINGW_NONNULL((1, 2))
  void * memcpy(void * __restrict __dst, const void * __restrict __src, size_t __n)
  {
    return __builtin___memcpy_chk(__dst, __src, __n, __mingw_bos(__dst, 0));
  }

#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl __mingw_call_memcpy_s(void *_dest, size_t _numberOfElements, const void *_src, size_t _count) __MINGW_ASM_CRT_CALL(memcpy_s);

  __mingw_bos_extern_ovr
  errno_t memcpy_s(void * __dst, size_t __os, const void * __src, size_t __n)
  {
    __mingw_bos_ptr_chk_warn(__dst, __os, 0);
    return __mingw_call_memcpy_s(__dst, __os, __src, __n);
  }
#endif

  __mingw_bos_extern_ovr __MINGW_NONNULL((1, 2))
  void * memmove(void * __dst, const void * __src, size_t __n)
  {
    return __builtin___memmove_chk(__dst, __src, __n, __mingw_bos(__dst, 0));
  }

  __mingw_bos_extern_ovr __MINGW_NONNULL((1))
  void * memset(void * __dst, int __val, size_t __n)
  {
    return __builtin___memset_chk(__dst, __val, __n, __mingw_bos(__dst, 0));
  }

#endif  /* __MINGW_FORTIFY_LEVEL > 0 */

__MINGW_END_C_DECLS

#endif  /* _INC_MEMORY */
