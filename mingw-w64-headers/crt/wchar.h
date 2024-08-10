/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_WCHAR
#define _INC_WCHAR

#include <corecrt.h>
#include <memory.h>
#include <corecrt_wconio.h>
#include <corecrt_wctype.h>
#include <corecrt_wdirect.h>
#include <corecrt_wio.h>
#include <corecrt_wprocess.h>
#include <corecrt_wstdio.h>
#include <corecrt_wstdlib.h>
#include <corecrt_wstring.h>
#include <corecrt_wtime.h>
#include <sys/stat.h>
#include <sys/types.h>

__MINGW_BEGIN_C_DECLS

#ifndef WCHAR_MIN  /* Also in stdint.h */
# define WCHAR_MIN 0U
# define WCHAR_MAX 0xffffU
#endif

  typedef wchar_t _Wint_t;

#ifndef _WLOCALE_DEFINED  /* Also in locale.h */
# define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(int _Category, const wchar_t *_Locale);
  _CRTIMP _locale_t __cdecl _wcreate_locale(int _Category, const wchar_t *_Locale);
#endif

  _CRTIMP wint_t __cdecl btowc(int);
  _CRTIMP size_t __cdecl mbrlen(const char * __restrict _Ch, size_t _SizeInBytes, mbstate_t * __restrict _State);
  _CRTIMP size_t __cdecl mbrtowc(wchar_t * __restrict _DstCh, const char * __restrict _SrcCh, size_t _SizeInBytes, mbstate_t * __restrict _State);
  _CRTIMP size_t __cdecl mbsrtowcs(wchar_t * __restrict _Dest, const char ** __restrict _PSrc, size_t _Count, mbstate_t * __restrict _State) __MINGW_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl mbsrtowcs_s(size_t *_Retval, wchar_t *_Dst, size_t _SizeInWords, const char **_PSrc, size_t _N, mbstate_t *_State);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_3(errno_t, mbsrtowcs_s, size_t *, _Retval, wchar_t, _Dst, const char **, _PSrc, size_t, _N, mbstate_t *, _State)
#endif
  _CRTIMP size_t __cdecl wcrtomb(char * __restrict _Dest, wchar_t _Source, mbstate_t * __restrict _State) __MINGW_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl wcrtomb_s(size_t *_Retval, char *_Dst, size_t _SizeInBytes, wchar_t _Ch, mbstate_t *_State);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_2(errno_t, wcrtomb_s, size_t *, _Retval, char, _Dst, wchar_t, _Ch, mbstate_t *, _State)
#endif
  _CRTIMP size_t __cdecl wcsrtombs(char * __restrict _Dest, const wchar_t ** __restrict _PSource, size_t _Count, mbstate_t * __restrict _State) __MINGW_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl wcsrtombs_s(size_t *_Retval, char *_Dst, size_t _SizeInBytes, const wchar_t **_Src, size_t _Size, mbstate_t *_State);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_3(errno_t, wcsrtombs_s, size_t *, _Retval, char, _Dst, const wchar_t **, _Src, size_t, _Size, mbstate_t *, _State)
#endif
  _CRTIMP int __cdecl wctob(wint_t _WCh);
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl wmemcpy_s(wchar_t *_dest, size_t _numberOfElements, const wchar_t *_src, size_t _count);
  _CRTIMP errno_t __cdecl wmemmove_s(wchar_t *_dest, size_t _numberOfElements, const wchar_t *_src, size_t _count);
#endif

#if defined(__MINGW_USE_ISOC95) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)
  extern int __cdecl fwide(FILE *stream, int mode);
#endif

  __mingw_ovr __MINGW_PURE
  int mbsinit(const mbstate_t *_P)
  {
    return (!_P || _P->_Wchar == 0);
  }

  _CONST_RETURN wchar_t *__cdecl wmemchr(const wchar_t *s, wchar_t c, size_t n) __MINGW_NONNULL((1)) __MINGW_PURE;
  extern int __cdecl wmemcmp(const wchar_t *s1, const wchar_t *s2, size_t n) __MINGW_NONNULL((1, 2)) __MINGW_PURE;
  extern wchar_t *__cdecl wmemcpy(wchar_t * __restrict s1, const wchar_t * __restrict s2, size_t n)
    __MINGW_NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN;
  extern wchar_t *__cdecl wmemmove(wchar_t *s1, const wchar_t *s2, size_t n)
    __MINGW_NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN;
  extern wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, size_t n) __MINGW_NONNULL((1));

#ifndef __CRT__NO_INLINE

#if defined(__MINGW_USE_ISOC95) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)
  __CRT_INLINE int __cdecl fwide(FILE *_F,int _M)
  {
    (void)_F;
    return (_M);
  }
#endif

  __CRT_INLINE __MINGW_NONNULL((1)) __MINGW_PURE
  _CONST_RETURN wchar_t *__cdecl wmemchr(const wchar_t *_S, wchar_t _C, size_t _N)
  {
    if(_S)
    {
      for( ; 0 < _N; ++_S, --_N)
        if (*_S == _C)
          return (_CONST_RETURN wchar_t *)(_S);
    }
    return (_CONST_RETURN wchar_t *)NULL;
  }

  __CRT_INLINE __MINGW_NONNULL((1, 2)) __MINGW_PURE
  int __cdecl wmemcmp(const wchar_t *_S1, const wchar_t *_S2, size_t _N)
  {
    if(_N == 0 || _S1 == _S2)
      return 0;  /* even for NULL pointers. */
    if((_S1 && !(_S2)) || (_S2 && !(_S1)))
      return !(_S2) ? 1 : -1;  /* robust. */
    for( ; 0 < _N; ++_S1, ++_S2, --_N)
      if(*_S1 != *_S2)
        return (*_S1 < *_S2 ? -1 : +1);
    return 0;
  }

  __CRT_INLINE __MINGW_NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN
  wchar_t *__cdecl wmemcpy(wchar_t * __restrict _S1, const wchar_t * __restrict _S2, size_t _N)
  {
    return (wchar_t *)memcpy(_S1, _S2, _N * sizeof(wchar_t));
  }

  __CRT_INLINE __MINGW_NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN
  wchar_t *__cdecl wmemmove(wchar_t *_S1, const wchar_t *_S2, size_t _N)
  {
    return (wchar_t *)memmove(_S1, _S2, _N * sizeof(wchar_t));
  }

  __CRT_INLINE __MINGW_NONNULL((1)) wchar_t *__cdecl wmemset(wchar_t *_S, wchar_t _C, size_t _N)
  {
    wchar_t *_Su = _S;
    for( ; 0<_N; ++_Su, --_N)
    {
      *_Su = _C;
    }
    return (_S);
  }

#endif

#ifdef __MINGW_USE_GNU
  extern wchar_t *__cdecl wmempcpy(wchar_t *_Dst, const wchar_t *_Src, size_t _Size) __MINGW_NONNULL((1, 2));
#endif

__MINGW_END_C_DECLS

#endif  /* _INC_WCHAR */
