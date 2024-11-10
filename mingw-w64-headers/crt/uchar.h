/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

/* ISO C1x Unicode utilities
 * Based on ISO/IEC SC22/WG14 9899 TR 19769 (SC22 N1326)
 *
 *  THIS SOFTWARE IS NOT COPYRIGHTED
 *
 *  This source code is offered for use in the public domain. You may
 *  use, modify or distribute it freely.
 *
 *  This code is distributed in the hope that it will be useful but
 *  WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 *  DISCLAIMED. This includes but is not limited to warranties of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *  Date: 2011-09-27
 */
#ifndef __UCHAR_H
#define __UCHAR_H

#include <corecrt.h>
#include <stdint.h>  /* uint_leastXX_t */

__MINGW_BEGIN_C_DECLS

#ifndef __MINGW_USE_ISOCXX11
  typedef uint_least16_t  char16_t;
  typedef uint_least32_t  char32_t;
#endif
  typedef uint_least16_t _Char16_t;
  typedef uint_least32_t _Char32_t;

#ifndef __STDC_UTF_16__
# define __STDC_UTF_16__ 1
#endif

#ifndef __STDC_UTF_32__
# define __STDC_UTF_32__ 1
#endif

  _CRTIMP size_t __cdecl mbrtoc16(char16_t *__restrict _Pc16, const char *__restrict _S, size_t _N, mbstate_t *__restrict _Ps) __MINGW_NOTHROW;
  _CRTIMP size_t __cdecl c16rtomb(char *__restrict _S, char16_t _C16, mbstate_t *__restrict _Ps)                               __MINGW_NOTHROW;

  _CRTIMP size_t __cdecl mbrtoc32(char32_t *__restrict _Pc32, const char *__restrict _S, size_t _N, mbstate_t *__restrict _Ps) __MINGW_NOTHROW;
  _CRTIMP size_t __cdecl c32rtomb(char *__restrict _S, char32_t _C32, mbstate_t *__restrict _Ps)                               __MINGW_NOTHROW;

__MINGW_END_C_DECLS

#endif  /* __UCHAR_H */
