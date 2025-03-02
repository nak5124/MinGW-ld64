/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define __CRT__NO_INLINE
#include <wchar.h>
#if defined(__x86_64__) && !defined(__arm64ec__)
# include <x86intrin.h>
# define __INTRINSIC_GROUP_WCHAR
# include <psdk_inc/intrin-impl.h>
#endif

int __cdecl wmemcmp(const wchar_t *_S1,const wchar_t *_S2,size_t _N)
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
