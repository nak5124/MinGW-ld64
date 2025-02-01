/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define __CRT__NO_INLINE
#include <wchar.h>
#include <intrin.h>

wchar_t *__cdecl wmemchr(const wchar_t *_S, wchar_t _C, size_t _N)
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
