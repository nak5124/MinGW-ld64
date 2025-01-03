/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
/*
 * complex.h
 *
 * This file is part of the Mingw32 package.
 *
 * Contributors:
 *  Created by Danny Smith <dannysmith@users.sourceforge.net>
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
 */
#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <corecrt.h>

__MINGW_BEGIN_C_DECLS

/* These macros are specified by C99 standard */
#ifndef __cplusplus
# define complex _Complex
#endif

#define _Complex_I (__extension__  1.0iF)

/* GCC doesn't support _Imaginary type yet, so we don't
   define _Imaginary_I */

#define I _Complex_I

#ifdef __MINGW_USE_ISOC11
# ifdef __clang__
#   define CMPLX(x, y)  ((double complex){ x, y })
#   define CMPLXF(x, y) ((float complex){ x, y })
#   define CMPLXL(x, y) ((long double complex){ x, y })
# elif __MINGW_GNUC_PREREQ(4, 7)
#   define CMPLX(x, y)  __builtin_complex((double)(x), (double)(y))
#   define CMPLXF(x, y) __builtin_complex((float)(x), (float)(y))
#   define CMPLXL(x, y) __builtin_complex((long double)(x), (long double)(y))
# endif
#endif  /* __MINGW_USE_ISOC11 */

  extern double          cabs(double _Complex _Z) __MINGW_CONST;
  extern double _Complex cacos(double _Complex _Z);
  extern double _Complex cacosh(double _Complex _Z);
  extern double          carg(double _Complex _Z) __MINGW_CONST;
  extern double _Complex casin(double _Complex _Z);
  extern double _Complex casinh(double _Complex _Z);
  extern double _Complex catan(double _Complex _Z);
  extern double _Complex catanh(double _Complex _Z);
  extern double _Complex ccos(double _Complex _Z);
  extern double _Complex ccosh(double _Complex _Z);
  extern double _Complex cexp(double _Complex _Z);
  extern double          cimag(double _Complex _Z) __MINGW_CONST;
  extern double _Complex clog(double _Complex _Z);
#if defined(__MINGW_USE_GNU) || defined(__MINGW_USE_MS)
  extern double _Complex clog10(double _Complex _Z);
#endif
  extern double _Complex conj(double _Complex _Z) __MINGW_CONST;
  extern double _Complex cpow(double _Complex _X, double _Complex _Y);
  extern double _Complex cproj(double _Complex _Z) __MINGW_CONST;
  extern double          creal(double _Complex _Z) __MINGW_CONST;
  extern double _Complex csin(double _Complex _Z);
  extern double _Complex csinh(double _Complex _Z);
  extern double _Complex csqrt(double _Complex _Z);
  extern double _Complex ctan(double _Complex _Z);
  extern double _Complex ctanh(double _Complex _Z);
#ifdef __MINGW_USE_MS
  extern double norm(double _Complex _Z);
#endif

  extern float          cabsf(float _Complex _Z) __MINGW_CONST;
  extern float _Complex cacosf(float _Complex _Z);
  extern float _Complex cacoshf(float _Complex _Z);
  extern float          cargf(float _Complex _Z) __MINGW_CONST;
  extern float _Complex casinf(float _Complex _Z);
  extern float _Complex casinhf(float _Complex _Z);
  extern float _Complex catanf(float _Complex _Z);
  extern float _Complex catanhf(float _Complex _Z);
  extern float _Complex ccosf(float _Complex _Z);
  extern float _Complex ccoshf(float _Complex _Z);
  extern float _Complex cexpf(float _Complex _Z);
  extern float          cimagf(float _Complex _Z) __MINGW_CONST;
  extern float _Complex clogf(float _Complex _Z);
#if defined(__MINGW_USE_GNU) || defined(__MINGW_USE_MS)
  extern float _Complex clog10f(float _Complex _Z);
#endif
  extern float _Complex conjf(float _Complex _Z) __MINGW_CONST;
  extern float _Complex cpowf(float _Complex _X, float _Complex _Y);
  extern float _Complex cprojf(float _Complex _Z) __MINGW_CONST;
  extern float          crealf(float _Complex _Z) __MINGW_CONST;
  extern float _Complex csinf(float _Complex _Z);
  extern float _Complex csinhf(float _Complex _Z);
  extern float _Complex csqrtf(float _Complex _Z);
  extern float _Complex ctanf(float _Complex _Z);
  extern float _Complex ctanhf(float _Complex _Z);
#ifdef __MINGW_USE_MS
  extern float normf(float _Complex _Z);
#endif

  extern long double          cabsl(long double _Complex _Z) __MINGW_CONST;
  extern long double _Complex cacosl(long double _Complex _Z);
  extern long double _Complex cacoshl(long double _Complex _Z);
  extern long double          cargl(long double _Complex _Z) __MINGW_CONST;
  extern long double _Complex casinl(long double _Complex _Z);
  extern long double _Complex casinhl(long double _Complex _Z);
  extern long double _Complex catanl(long double _Complex _Z);
  extern long double _Complex catanhl(long double _Complex _Z);
  extern long double _Complex ccosl(long double _Complex _Z);
  extern long double _Complex ccoshl(long double _Complex _Z);
  extern long double _Complex cexpl(long double _Complex _Z);
  extern long double          cimagl(long double _Complex _Z) __MINGW_CONST;
  extern long double _Complex clogl(long double _Complex _Z);
#if defined(__MINGW_USE_GNU) || defined(__MINGW_USE_MS)
  extern long double _Complex clog10l(long double _Complex _Z);
#endif
  extern long double _Complex conjl(long double _Complex _Z) __MINGW_CONST;
  extern long double _Complex cpowl(long double _Complex _X, long double _Complex _Y);
  extern long double _Complex cprojl(long double _Complex _Z) __MINGW_CONST;
  extern long double          creall(long double _Complex _Z) __MINGW_CONST;
  extern long double _Complex csinl(long double _Complex _Z);
  extern long double _Complex csinhl(long double _Complex _Z);
  extern long double _Complex csqrtl(long double _Complex _Z);
  extern long double _Complex ctanl(long double _Complex _Z);
  extern long double _Complex ctanhl(long double _Complex _Z);
#ifdef __MINGW_USE_MS
  extern long double norml(long double _Complex _Z);
#endif

#ifndef __CRT__NO_INLINE
#include <math.h>
/* double */
  __CRT_INLINE __MINGW_CONST
  double __cdecl cabs(double _Complex _Z)
  {
    return hypot(__real__ _Z, __imag__ _Z);
  }

  __CRT_INLINE __MINGW_CONST
  double __cdecl carg(double _Complex _Z)
  {
    return atan2(__imag__ _Z, __real__ _Z);
  }

  __CRT_INLINE __MINGW_CONST
  double __cdecl cimag(double _Complex _Z)
  {
    return __imag__ _Z;
  }

  __CRT_INLINE __MINGW_CONST
  double _Complex __cdecl conj(double _Complex _Z)
  {
    return __MINGW_EXTENSION ~_Z;
  }

  __CRT_INLINE __MINGW_CONST
  double __cdecl creal(double _Complex _Z)
  {
    return __real__ _Z;
  }

/* float */
  __CRT_INLINE __MINGW_CONST
  float __cdecl cabsf(float _Complex _Z)
  {
    return hypotf(__real__ _Z, __imag__ _Z);
  }

  __CRT_INLINE __MINGW_CONST
  float __cdecl cargf(float _Complex _Z)
  {
    return atan2f(__imag__ _Z, __real__ _Z);
  }

  __CRT_INLINE __MINGW_CONST
  float __cdecl cimagf(float _Complex _Z)
  {
    return __imag__ _Z;
  }

  __CRT_INLINE __MINGW_CONST
  float _Complex __cdecl conjf(float _Complex _Z)
  {
    return __MINGW_EXTENSION ~_Z;
  }

  __CRT_INLINE __MINGW_CONST
  float __cdecl crealf(float _Complex _Z)
  {
    return __real__ _Z;
  }

/* long double */
  __CRT_INLINE __MINGW_CONST
  long double __cdecl cabsl(long double _Complex _Z)
  {
    return hypotl(__real__ _Z, __imag__ _Z);
  }

  __CRT_INLINE __MINGW_CONST
  long double __cdecl cargl(long double _Complex _Z)
  {
    return atan2l(__imag__ _Z, __real__ _Z);
  }

  __CRT_INLINE __MINGW_CONST
  long double __cdecl cimagl(long double _Complex _Z)
  {
    return __imag__ _Z;
  }

  __CRT_INLINE __MINGW_CONST
  long double _Complex __cdecl conjl(long double _Complex _Z)
  {
    return __MINGW_EXTENSION ~_Z;
  }

  __CRT_INLINE __MINGW_CONST
  long double __cdecl creall(long double _Complex _Z)
  {
    return __real__ _Z;
  }

#endif  /* __CRT__NO_INLINE */

__MINGW_END_C_DECLS

#endif  /* _COMPLEX_H_ */
