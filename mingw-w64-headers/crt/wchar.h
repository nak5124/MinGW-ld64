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
  _CRTIMP wchar_t  *__cdecl _wsetlocale(int _Category, const wchar_t *_Locale);
  _CRTIMP _locale_t __cdecl _wcreate_locale(int _Category, const wchar_t *_Locale);
#endif

  _CRTIMP wint_t  __cdecl btowc(int) __NOTHROW;
  _CRTIMP size_t  __cdecl mbrlen(const char *__restrict _Ch, size_t _SizeInBytes, mbstate_t *__restrict _State) __NOTHROW;
  _CRTIMP size_t  __cdecl mbrtowc(wchar_t *__restrict _DstCh, const char *__restrict _SrcCh, size_t _SizeInBytes, mbstate_t *__restrict _State) __NOTHROW;
  _CRTIMP size_t  __cdecl mbsrtowcs(wchar_t *__restrict _Dest, const char **__restrict _PSrc, size_t _Count, mbstate_t *__restrict _State) __NOTHROW __MINGW_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl mbsrtowcs_s(size_t *_Retval, wchar_t *_Dst, size_t _SizeInWords, const char **_PSrc, size_t _N, mbstate_t *_State);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_3(errno_t, mbsrtowcs_s, size_t *, _Retval, wchar_t, _Dst, const char **, _PSrc, size_t, _N, mbstate_t *, _State)
#endif
  _CRTIMP size_t  __cdecl wcrtomb(char *__restrict _Dest, wchar_t _Source, mbstate_t *__restrict _State) __NOTHROW __MINGW_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl wcrtomb_s(size_t *_Retval, char *_Dst, size_t _SizeInBytes, wchar_t _Ch, mbstate_t *_State);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_2(errno_t, wcrtomb_s, size_t *, _Retval, char, _Dst, wchar_t, _Ch, mbstate_t *, _State)
#endif
  _CRTIMP size_t  __cdecl wcsrtombs(char *__restrict _Dest, const wchar_t **__restrict _PSource, size_t _Count, mbstate_t *__restrict _State) __NOTHROW __MINGW_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl wcsrtombs_s(size_t *_Retval, char *_Dst, size_t _SizeInBytes, const wchar_t **_Src, size_t _Size, mbstate_t *_State);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_3(errno_t, wcsrtombs_s, size_t *, _Retval, char, _Dst, const wchar_t **, _Src, size_t, _Size, mbstate_t *, _State)
#endif
  _CRTIMP int     __cdecl wctob(wint_t _WCh) __NOTHROW;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl wmemcpy_s(wchar_t *_S1, rsize_t _N1, const wchar_t *_S2, rsize_t _N);
  _CRTIMP errno_t __cdecl wmemmove_s(wchar_t *_S1, rsize_t _N1, const wchar_t *_S2, rsize_t _N);
#endif

#if defined(__MINGW_USE_ISOC95) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)
  extern int __cdecl fwide(FILE *__fp, int __mode) __NOTHROW;
#endif

  __mingw_ovr __PURE
  __NTH_FNC(int mbsinit(const mbstate_t *_P))
  {
    return (!_P || _P->_Wchar == 0);
  }

#ifdef __CORRECT_ISO_CPP_WCHAR_H_PROTO
  extern "C++"
  {
                  wchar_t *__cdecl wmemchr(wchar_t *_S, wchar_t _C, size_t _N)       __ASM_CALL_NTH(wmemchr) __PURE __NONNULL((1));
    _CONST_RETURN wchar_t *__cdecl wmemchr(const wchar_t *_S, wchar_t _C, size_t _N) __ASM_CALL_NTH(wmemchr) __PURE __NONNULL((1));
  }
#else
   extern wchar_t *__cdecl wmemchr(const wchar_t *_S, wchar_t _C, size_t _N) __NOTHROW __PURE __NONNULL((1));
#endif

  extern int      __cdecl wmemcmp(const wchar_t *_S1, const wchar_t *_S2, size_t _N) __NOTHROW __PURE __NONNULL((1, 2));
  extern wchar_t *__cdecl wmemcpy(wchar_t *__restrict _S1, const wchar_t *__restrict _S2, size_t _N) __NOTHROW __NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN;
  extern wchar_t *__cdecl wmemmove(wchar_t *_S1, const wchar_t *_S2, size_t _N)                      __NOTHROW __NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN;
  extern wchar_t *__cdecl wmemset(wchar_t *_S, wchar_t _C, size_t _N)                                __NOTHROW __NONNULL((1));

#ifndef __CRT__NO_INLINE

#if defined(__MINGW_USE_ISOC95) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)
  __CRT_INLINE
  __NTH_FNC(int __cdecl fwide(FILE *_F,int _M))
  {
    (void)_F;
    return (_M);
  }
#endif

#if defined(__x86_64__) && !defined(__arm64ec__)
# include <x86intrin.h>
# define __INTRINSIC_GROUP_WCHAR
# include <psdk_inc/intrin-impl.h>
# ifdef __clang__
#   pragma clang attribute push (__attribute__((target("avx2"))), apply_to=function)
# else
#   pragma GCC push_options
#   pragma GCC target("avx2")
# endif
#endif

#ifndef __cplusplus

  __CRT_INLINE __PURE __NONNULL((1))
  __NTH_FNC(wchar_t *__cdecl wmemchr(const wchar_t *_S, wchar_t _C, size_t _N))
  {
#if defined(__aarch64__) || defined(__arm64ec__)
    if(_S)
    {
      for( ; 0 < _N; ++_S, --_N)
      {
        if (*_S == _C)
        {
          return (wchar_t *)(_S);
        }
      }
    }
    return (wchar_t *)NULL;
#else
    size_t         Count = 0;
    unsigned long  Index = 0;
    const wchar_t *S     = _S;
    if(_N >= 16)
    {
      __m256i V2 = _mm256_broadcastw_epi16(_mm_cvtsi32_si128(_C));
      do
      {
        __m256i V1 = _mm256_loadu_si256((const __m256i *)S);
                V1 = _mm256_cmpeq_epi16(V1, V2);
        unsigned int Mask = (unsigned int)_mm256_movemask_epi8(V1);
        if(Mask != 0)
        {
          _BitScanForward(&Index, Mask);
          Index >>= 1;
          return (wchar_t *)&_S[Count + Index];
        }
        Count += 16;
        S     += 16;
      }
      while(Count + 16 <= _N);
    }
    if(Count + 4 <= _N)
    {
      __m128i V2 = _mm_set1_epi16((short)_C);
      while(Count + 8 <= _N)
      {
        __m128i V1 = _mm_loadu_si128((const __m128i *)S);
                V1 = _mm_cmpeq_epi16(V1, V2);
        unsigned short Mask = (unsigned short)_mm_movemask_epi8(V1);
        if(Mask != 0)
        {
          _BitScanForward(&Index, Mask);
          Index >>= 1;
          return (wchar_t *)&_S[Count + Index];
        }
        Count += 8;
        S     += 8;
      }
      if(Count + 4 <= _N)
      {
        __m128i V1 = _mm_loadu_si64(S);
                V1 = _mm_cmpeq_epi16(V1, V2);
        unsigned char Mask = (unsigned char)_mm_movemask_epi8(V1);
        if(Mask != 0)
        {
          _BitScanForward(&Index, Mask);
          Index >>= 1;
          return (wchar_t *)&_S[Count + Index];
        }
        Count += 4;
      }
    }
    for(; Count < _N; ++Count)
    {
      if(_S[Count] == _C)
      {
        return (wchar_t *)&_S[Count];
      }
    }

    return NULL;
#endif
  }

#endif  /* __cplusplus */

  __CRT_INLINE __PURE __NONNULL((1, 2))
  __NTH_FNC(int __cdecl wmemcmp(const wchar_t *_S1, const wchar_t *_S2, size_t _N))
  {
#if defined(__aarch64__) || defined(__arm64ec__)
    if(_N == 0 || _S1 == _S2)
    {
      /* even for NULL pointers. */
      return 0;
    }
    if((_S1 && !(_S2)) || (_S2 && !(_S1)))
    {
      /* robust. */
      return !(_S2) ? 1 : -1;
    }
    for( ; 0 < _N; ++_S1, ++_S2, --_N)
    {
      if(*_S1 != *_S2)
      {
        return (*_S1 < *_S2 ? -1 : +1);
      }
    }
    return 0;
#else
    size_t         Count = 0;
    unsigned long  Index = 0;
    const wchar_t *S1    = _S1;
    const wchar_t *S2    = _S2;
    while(Count + 16 <= _N)
    {
      __m256i V1 = _mm256_loadu_si256((const __m256i *)S1);
      __m256i V2 = _mm256_loadu_si256((const __m256i *)S2);
              V1 = _mm256_cmpeq_epi16(V1, V2);
      unsigned int Mask = (unsigned int)_mm256_movemask_epi8(V1);
      if(Mask != 0xffffffff)
      {
        _BitScanForward(&Index, ~Mask);
        Index >>= 1;
        return _S1[Count + Index] < _S2[Count + Index] ? -1 : 1;
      }
      Count += 16;
      S1    += 16;
      S2    += 16;
    }
    while(Count + 8 <= _N)
    {
      __m128i V1 = _mm_loadu_si128((const __m128i *)S1);
      __m128i V2 = _mm_loadu_si128((const __m128i *)S2);
              V1 = _mm_cmpeq_epi16(V1, V2);
      unsigned short Mask = (unsigned short)_mm_movemask_epi8(V1);
      if(Mask != 0xffff)
      {
        _BitScanForward(&Index, (unsigned long)~Mask);
        Index >>= 1;
        return _S1[Count + Index] < _S2[Count + Index] ? -1 : 1;
      }
      Count += 8;
      S1    += 8;
      S2    += 8;
    }
    if(Count + 4 <= _N)
    {
      unsigned __int64 V1 = *(unsigned __int64*)S1;
      unsigned __int64 V2 = *(unsigned __int64*)S2;
      if(V1 != V2)
      {
        _BitScanForward64(&Index, (V1 ^ V2));
        Index >>= 4;
        return _S1[Count + Index] < _S2[Count + Index] ? -1 : 1;
      }
      Count += 4;
    }
    for(; Count < _N; ++Count)
    {
      if (_S1[Count] != _S2[Count])
      {
        return _S1[Count] < _S2[Count] ? -1 : 1;
      }
    }
    return 0;
#endif
  }

#if defined(__x86_64__) && !defined(__arm64ec__)
# ifdef __clang__
#   pragma clang attribute pop
# else
#   pragma GCC pop_options
# endif
#endif

  __CRT_INLINE __NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN
  __NTH_FNC(wchar_t *__cdecl wmemcpy(wchar_t *__restrict _S1, const wchar_t *__restrict _S2, size_t _N))
  {
    return (wchar_t *)memcpy(_S1, _S2, _N * sizeof(wchar_t));
  }

  __CRT_INLINE __NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN
  __NTH_FNC(wchar_t *__cdecl wmemmove(wchar_t *_S1, const wchar_t *_S2, size_t _N))
  {
    return (wchar_t *)memmove(_S1, _S2, _N * sizeof(wchar_t));
  }

  __CRT_INLINE __NONNULL((1))
  __NTH_FNC(wchar_t *__cdecl wmemset(wchar_t *_S, wchar_t _C, size_t _N))
  {
    wchar_t *_Su = _S;
    for( ; 0<_N; ++_Su, --_N)
    {
      *_Su = _C;
    }
    return (_S);
  }

#endif  /* __CRT__NO_INLINE */

#ifdef __MINGW_USE_GNU
  extern wchar_t *__cdecl wmempcpy(wchar_t *_Dst, const wchar_t *_Src, size_t _Size) __NOTHROW __NONNULL((1, 2));
#endif

#if defined(__MINGW_USE_MISC) || defined(__MINGW_USE_XOPEN2K24)
  extern size_t  __cdecl wcslcat(wchar_t *__restrict _Dest, const wchar_t *__restrict _Src, size_t _N)
    __NOTHROW __NONNULL((1, 2)) __ATTR_ACCESS((__read_write__, 1, 3));
  extern size_t  __cdecl wcslcpy(wchar_t *__restrict _Dest, const wchar_t *__restrict _Src, size_t _N)
    __NOTHROW __NONNULL((1, 2)) __ATTR_ACCESS((__write_only__, 1, 3));
#endif

__MINGW_END_C_DECLS

#endif  /* _INC_WCHAR */
