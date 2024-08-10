/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _MATH_H_
#define _MATH_H_

#include <corecrt.h>

__MINGW_BEGIN_C_DECLS

#define _DOMAIN    1  /* domain error in argument */
#define _SING      2  /* singularity */
#define _OVERFLOW  3  /* range overflow */
#define _UNDERFLOW 4  /* range underflow */
#define _TLOSS     5  /* total loss of precision */
#define _PLOSS     6  /* partial loss of precision */

#if defined(__MINGW_USE_XOPEN) || defined(__MINGW_USE_MISC) || defined(__MINGW_USE_MS) || defined(_USE_MATH_DEFINES)
# define M_E        2.71828182845904523536
# define M_LOG2E    1.44269504088896340736
# define M_LOG10E   0.434294481903251827651
# define M_LN2      0.693147180559945309417
# define M_LN10     2.30258509299404568402
# define M_PI       3.14159265358979323846
# define M_PI_2     1.57079632679489661923
# define M_PI_4     0.785398163397448309616
# define M_1_PI     0.318309886183790671538
# define M_2_PI     0.636619772367581343076
# define M_2_SQRTPI 1.12837916709551257390
# define M_SQRT2    1.41421356237309504880
# define M_SQRT1_2  0.707106781186547524401
#endif

/* See also float.h  */
#ifndef __MINGW_FPCLASS_DEFINED
# define __MINGW_FPCLASS_DEFINED 1
# define _FPCLASS_SNAN 0x0001  /* Signaling "Not a Number" */
# define _FPCLASS_QNAN 0x0002  /* Quiet "Not a Number" */
# define _FPCLASS_NINF 0x0004  /* Negative Infinity */
# define _FPCLASS_NN   0x0008  /* Negative Normal */
# define _FPCLASS_ND   0x0010  /* Negative Denormal */
# define _FPCLASS_NZ   0x0020  /* Negative Zero */
# define _FPCLASS_PZ   0x0040  /* Positive Zero */
# define _FPCLASS_PD   0x0080  /* Positive Denormal */
# define _FPCLASS_PN   0x0100  /* Positive Normal */
# define _FPCLASS_PINF 0x0200  /* Positive Infinity */
#endif

#ifndef __mingw_types_compatible_p
# ifdef __cplusplus
    extern "C++"
    {
      template <typename type1, typename type2> struct __mingw_types_compatible_p
      {
        static const bool result = false;
      };

      template <typename type1> struct __mingw_types_compatible_p<type1, type1>
      {
        static const bool result = true;
      };

      template <typename type1> struct __mingw_types_compatible_p<const type1, type1>
      {
        static const bool result = true;
      };

      template <typename type1> struct __mingw_types_compatible_p<type1, const type1>
      {
        static const bool result = true;
      };
    }

#   define __mingw_types_compatible_p(type1, type2) __mingw_types_compatible_p<type1, type2>::result
# else
#   define __mingw_types_compatible_p(type1, type2) __builtin_types_compatible_p(type1, type2)
# endif
#endif

#ifndef __mingw_choose_expr
# ifdef __cplusplus
#   define __mingw_choose_expr(C, E1, E2) ((C) ? E1 : E2)
# else
#   define __mingw_choose_expr __builtin_choose_expr
# endif
#endif

#ifndef __MINGW_SOFTMATH
#define __MINGW_SOFTMATH

/* IEEE float/double type shapes.  */
  typedef union __mingw_dbl_type_t
  {
    double x;
    unsigned long long val;
    __C89_NAMELESS struct
    {
      unsigned int low, high;
    } lh;
  } __mingw_dbl_type_t;

  typedef union __mingw_flt_type_t
  {
    float x;
    unsigned int val;
  } __mingw_flt_type_t;

  typedef union __mingw_ldbl_type_t
  {
    long double x;
    __C89_NAMELESS struct
    {
      unsigned int low, high;
      int sign_exponent : 16;
      int res1 : 16;
      int res0 : 32;
    } lh;
  } __mingw_ldbl_type_t;

#endif

#ifndef _HUGE
  extern double * __MINGW_IMP_SYMBOL(_HUGE);
#define _HUGE (* __MINGW_IMP_SYMBOL(_HUGE))
#endif

#define HUGE_VAL __builtin_huge_val()

#ifndef _EXCEPTION_DEFINED  /* Also in corecrt_startup.h */
# define _EXCEPTION_DEFINED
  struct _exception
  {
    int type;
    const char *name;
    double arg1;
    double arg2;
    double retval;
  };

  void __mingw_raise_matherr(int typ, const char *name, double a1, double a2, double rslt);
  void __mingw_setusermatherr(int (__cdecl *)(struct _exception *));
  _CRTIMP void __setusermatherr(int (__cdecl *)(struct _exception *));
  #define __setusermatherr __mingw_setusermatherr
#endif  /* _EXCEPTION_DEFINED */

  double __cdecl sin(double _X);
  double __cdecl cos(double _X);
  double __cdecl tan(double _X);
  double __cdecl sinh(double _X);
  double __cdecl cosh(double _X);
  double __cdecl tanh(double _X);
  double __cdecl asin(double _X);
  double __cdecl acos(double _X);
  double __cdecl atan(double _X);
  double __cdecl atan2(double _Y, double _X);
  double __cdecl exp(double _X);
  double __cdecl log(double _X);
  double __cdecl log10(double _X);
  double __cdecl pow(double _X, double _Y);
  double __cdecl sqrt(double _X);
  _CRTIMP double __cdecl ceil(double _X) __MINGW_CONST;
  _CRTIMP double __cdecl floor(double _X) __MINGW_CONST;
  double __cdecl fabs(double _X) __MINGW_CONST;

  double __cdecl ldexp(double _X, int _Y);
  _CRTIMP double __cdecl frexp(double _X, int *_Y);
  _CRTIMP double __cdecl modf(double _X, double *_Y);
  double __cdecl fmod(double _X, double _Y);

#ifdef __MINGW_USE_GNU
  extern void __cdecl sincos(double __x, double *p_sin, double *p_cos);
  extern void __cdecl sincosf(float __x, float *p_sin, float *p_cos);
  extern void __cdecl sincosl(long double __x, long double *p_sin, long double *p_cos);
#endif

#ifndef _CRT_ABS_DEFINED  /* Also in stdlib.h */
# define _CRT_ABS_DEFINED
  int __cdecl abs(int _X) __MINGW_CONST __MINGW_NOTHROW;
  long __cdecl labs(long _X) __MINGW_CONST __MINGW_NOTHROW;
# if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)
    __MINGW_EXTENSION long long __cdecl llabs(long long _X) __MINGW_CONST __MINGW_NOTHROW;
# endif
#endif  /* _CRT_ABS_DEFINED */

#ifndef _CRT_ATOF_DEFINED  /* Also in stdlib.h */
# define _CRT_ATOF_DEFINED
  _CRTIMP double __cdecl atof(const char *_String) __MINGW_NONNULL((1)) __MINGW_PURE __MINGW_NOTHROW;
  _CRTIMP double __cdecl _atof_l(const char *_String, _locale_t _Locale);
#endif  /* _CRT_ATOF_DEFINED */

#include <errno.h>

#ifndef _COMPLEX_DEFINED
# define _COMPLEX_DEFINED
  struct _complex
  {
    double x;
    double y;
  };
# if defined(__MINGW_USE_MS) && !defined(__cplusplus)
#   define complex _complex
# endif
#endif

  _CRTIMP double __cdecl _cabs(struct _complex _ComplexA);
  _CRTIMP double __cdecl _hypot(double _X, double _Y);
  _CRTIMP double __cdecl _j0(double _X);
  _CRTIMP double __cdecl _j1(double _X);
  _CRTIMP double __cdecl _jn(int _X, double _Y);
  _CRTIMP double __cdecl _y0(double _X);
  _CRTIMP double __cdecl _y1(double _X);
  _CRTIMP double __cdecl _yn(int _X, double _Y);
#ifndef _CRT_MATHERR_DEFINED
# define _CRT_MATHERR_DEFINED
  int __cdecl _matherr(struct _exception *pexcept);
#endif

/* These are also declared in Mingw float.h; needed here as well to work
   around GCC build issues.  */
/* BEGIN FLOAT.H COPY */
/*
 * IEEE recommended functions
 */
#ifndef _SIGN_DEFINED  /* Also in float.h */
# define _SIGN_DEFINED
  _CRTIMP double __cdecl _copysign(double _Number, double _Sign) __MINGW_CONST __MINGW_NOTHROW;
  _CRTIMP double __cdecl _chgsign(double _X) __MINGW_NOTHROW;
  _CRTIMP double __cdecl _scalb(double _X, long _Y) __MINGW_NOTHROW;
  _CRTIMP double __cdecl _logb(double _X) __MINGW_NOTHROW;
  _CRTIMP double __cdecl _nextafter(double _X, double _Y) __MINGW_CONST __MINGW_NOTHROW;
  _CRTIMP int __cdecl _finite(double _X) __MINGW_CONST __MINGW_NOTHROW;
  _CRTIMP int __cdecl _isnan(double _X) __MINGW_CONST __MINGW_NOTHROW;
  _CRTIMP int __cdecl _fpclass(double _X) __MINGW_NOTHROW;
#if defined(__x86_64__) || defined(_AMD64_)
  _CRTIMP float __cdecl _scalbf(float _X, long _Y);
#endif

  _LDCRTIMP long double __cdecl _copysignl(long double _Number, long double _Sign) __MINGW_CONST;
  _LDCRTIMP long double __cdecl _chgsignl(long double _X);
#endif  /* _SIGN_DEFINED */

/* END FLOAT.H COPY */

#if defined(__MINGW_USE_XOPEN) || defined(__MINGW_USE_MISC) || defined(__MINGW_USE_MS)

  _CRTIMP double __cdecl j0(double _X) __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP double __cdecl j1(double _X) __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP double __cdecl jn(int _X, double _Y) __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP double __cdecl y0(double _X) __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP double __cdecl y1(double _X) __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP double __cdecl yn(int _X, double _Y) __MINGW_DEPRECATED_MSVC2005;

#endif

#ifdef __MINGW_USE_MS
  _CRTIMP double __cdecl chgsign(double _X);
#endif

/*
 * scalb() is a GCC built-in.
 * Exclude this _scalb() stub; the semantics are incompatible
 * with the built-in implementation.
 *
  _CRTIMP double __cdecl scalb(double _X, long _Y);
 *
 */
#if defined(__MINGW_USE_MISC) || defined(__MINGW_USE_MS)
  _CRTIMP int __cdecl finite(double _X) __MINGW_CONST;
#endif

#ifdef __MINGW_USE_MS

  _CRTIMP int __cdecl fpclass(double _X);

#define FP_SNAN    _FPCLASS_SNAN
#define FP_QNAN    _FPCLASS_QNAN
#define FP_NINF    _FPCLASS_NINF
#define FP_PINF    _FPCLASS_PINF
#define FP_NDENORM _FPCLASS_ND
#define FP_PDENORM _FPCLASS_PD
#define FP_NZERO   _FPCLASS_NZ
#define FP_PZERO   _FPCLASS_PZ
#define FP_NNORM   _FPCLASS_NN
#define FP_PNORM   _FPCLASS_PN

#endif

#if ((defined(__MINGW_USE_XOPEN) && !defined(__MINGW_USE_XOPEN2K)) || defined(__MINGW_USE_MISC)) \
  && (!defined(__cplusplus) || !defined(__MINGW_USE_ISOCXX11))
  extern int __cdecl isnan(double _X) __MINGW_CONST;

# ifndef __CRT__NO_INLINE
  __CRT_INLINE __MINGW_CONST
  int __cdecl isnan(double _X)
  {
    __mingw_dbl_type_t hlp;
    unsigned int l, h;
    hlp.x = _X;
    l = hlp.lh.low;
    h = hlp.lh.high & 0x7fffffff;
    h |= (l | -l) >> 31;
    h = 0x7ff00000 - h;
    return (int)h >> 31;
  }
# endif
#endif

#ifdef __MINGW_USE_MISC
  extern int __cdecl isnanf(float _X) __MINGW_CONST;
  extern int __cdecl isnanl(long double _X) __MINGW_CONST;

# ifndef __CRT__NO_INLINE
  __CRT_INLINE __MINGW_CONST
  int __cdecl isnanf(float _X)
  {
    __mingw_flt_type_t hlp;
    unsigned int i;
    hlp.x = _X;
    i = hlp.val & 0x7fffffff;
    i = 0x7f800000 - i;
    return (int)(i >> 31);
  }

  __CRT_INLINE __MINGW_CONST
  int __cdecl isnanl(long double _X)
  {
#if defined(__x86_64__) || defined(_AMD64_)
    __mingw_ldbl_type_t ld;
    unsigned int xx, signexp;
    ld.x = _X;
    signexp = (ld.lh.sign_exponent & 0x7fff) << 1;
    xx = ld.lh.low | (ld.lh.high & 0x7fffffffu);
    signexp |= (xx | (-xx)) >> 31;
    signexp = 0xfffe - signexp;
    return (int)signexp >> 16;
#elif defined(__aarch64__) || defined(_ARM64_)
    return isnan(_X);
#endif
  }
# endif  /* __CRT__NO_INLINE */
#endif

#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_MS) || defined(__MINGW_USE_C99FORGXX)

#define HUGE_VALF __builtin_huge_valf()
#define HUGE_VALL __builtin_huge_vall()
#define INFINITY  __builtin_inff()
#define NAN       __builtin_nanf("")

/* Use the compiler's builtin define for FLT_EVAL_METHOD to
   set float_t and double_t.  */
#if defined(__x86_64__) || defined(__FLT_EVAL_METHOD__)
# if defined(__x86_64__) || __FLT_EVAL_METHOD__== 0
    typedef float float_t;
    typedef double double_t;
# elif __FLT_EVAL_METHOD__ == 1
    typedef double float_t;
    typedef double double_t;
# else  /* __FLT_EVAL_METHOD__ == 2 default ix87 FPU */
    typedef long double float_t;
    typedef long double double_t;
# endif
#else  /* ix87 FPU default */
  typedef long double float_t;
  typedef long double double_t;
#endif

#define MATH_ERRNO       1
#define MATH_ERREXCEPT   2
#define math_errhandling (MATH_ERRNO | MATH_ERREXCEPT)

/* 7.12.3.1 */
/*
  Return values for fpclassify.
  These are based on Intel x87 fpu condition codes
  in the high byte of status word and differ from
  the return values for MS IEEE 754 extension _fpclass()
*/
#define FP_NAN       0x0100
#define FP_NORMAL    0x0400
#define FP_INFINITE  (FP_NAN | FP_NORMAL)
#define FP_ZERO      0x4000
#define FP_SUBNORMAL (FP_NORMAL | FP_ZERO)
/* 0x0200 is signbit mask */

/*
  We can't inline float or double, because we want to ensure truncation
  to semantic type before classification.
  (A normal long double value might become subnormal when
  converted to double, and zero when converted to float.)
*/
  extern int __cdecl __fpclassify(double _X) __MINGW_CONST;
  extern int __cdecl __fpclassifyf(float _X) __MINGW_CONST;
  extern int __cdecl __fpclassifyl(long double _X) __MINGW_CONST;

#ifndef __CRT__NO_INLINE
  __CRT_INLINE __MINGW_CONST
  int __cdecl __fpclassify(double _X)
  {
    __mingw_dbl_type_t hlp;
    unsigned int l, h;
    hlp.x = _X;
    h = hlp.lh.high;
    l = hlp.lh.low | (h & 0xfffff);
    h &= 0x7ff00000;
    if((h | l) == 0)
      return FP_ZERO;
    if(!h)
      return FP_SUBNORMAL;
    if(h == 0x7ff00000)
      return l ? FP_NAN : FP_INFINITE;
    return FP_NORMAL;
  }

  __CRT_INLINE __MINGW_CONST
  int __cdecl __fpclassifyf(float _X)
  {
    __mingw_flt_type_t hlp;
    hlp.x = _X;
    hlp.val &= 0x7fffffff;
    if(hlp.val == 0)
      return FP_ZERO;
    if(hlp.val < 0x800000)
      return FP_SUBNORMAL;
    if(hlp.val >= 0x7f800000)
      return hlp.val > 0x7f800000 ? FP_NAN : FP_INFINITE;
    return FP_NORMAL;
  }

  __CRT_INLINE __MINGW_CONST
  int __cdecl __fpclassifyl(long double _X)
  {
#if defined(__x86_64__) || defined(_AMD64_)
    __mingw_ldbl_type_t hlp;
    unsigned int e;
    hlp.x = _X;
    e = hlp.lh.sign_exponent & 0x7fff;
    if(!e)
    {
      unsigned int h = hlp.lh.high;
      if(!(hlp.lh.low | h))
        return FP_ZERO;
      else if(!(h & 0x80000000))
        return FP_SUBNORMAL;
    }
    else if(e == 0x7fff)
      return (((hlp.lh.high & 0x7fffffff) | hlp.lh.low) == 0 ? FP_INFINITE : FP_NAN);
    return FP_NORMAL;
#elif defined(__aarch64__) || defined(_ARM64_)
    return __fpclassify(_X);
#endif
  }
#endif  /* __CRT__NO_INLINE */

#if ((__MINGW_GNUC_PREREQ(4, 4) && !defined(__SUPPORT_SNAN__)) || __mingw_clang_prereq(2, 8)) \
  && (!defined(__OPTIMIZE_SIZE__) || defined(__cplusplus))
# define fpclassify(_X) (__builtin_fpclassify(FP_NAN, FP_INFINITE, FP_NORMAL, FP_SUBNORMAL, FP_ZERO, _X))
#else
# define fpclassify(_X)                                            \
    __mingw_choose_expr(                                           \
      __mingw_types_compatible_p(__typeof__(_X), double),          \
      __fpclassify(_X),                                            \
      __mingw_choose_expr(                                         \
        __mingw_types_compatible_p(__typeof__(_X), float),         \
        __fpclassifyf(_X),                                         \
        __mingw_choose_expr(                                       \
          __mingw_types_compatible_p(__typeof__(_X), long double), \
          __fpclassifyl(_X),                                       \
          (__builtin_trap(), 0))))
#endif

/* 7.12.3.2 */
#if (__MINGW_GNUC_PREREQ(4, 4) && !defined(__SUPPORT_SNAN__)) || __mingw_clang_prereq(2, 8)
# define isfinite(_X) __builtin_isfinite(_X)
#else
# define isfinite(_X) ((fpclassify(_X) & FP_NAN) == 0)
#endif

/* 7.12.3.3 */
#if (__MINGW_GNUC_PREREQ(4, 4) && !defined(__SUPPORT_SNAN__)) || __mingw_clang_prereq(3, 7)
# define isinf(_X) __builtin_isinf_sign(_X)
#else
# define isinf(_X) (fpclassify(_X) == FP_INFINITE)
#endif

/* 7.12.3.4 */
/* We don't need to worry about truncation here:
   A NaN stays a NaN. */
  extern int __cdecl __isnan(double _X) __MINGW_CONST;
  extern int __cdecl __isnanf(float _X) __MINGW_CONST;
  extern int __cdecl __isnanl(long double _X) __MINGW_CONST;

#ifndef __CRT__NO_INLINE
  __CRT_INLINE __MINGW_CONST
  int __cdecl __isnan(double _X)
  {
    __mingw_dbl_type_t hlp;
    unsigned int l, h;
    hlp.x = _X;
    l = hlp.lh.low;
    h = hlp.lh.high & 0x7fffffff;
    h |= (l | -l) >> 31;
    h = 0x7ff00000 - h;
    return (int)h >> 31;
  }

  __CRT_INLINE __MINGW_CONST
  int __cdecl __isnanf(float _X)
  {
    __mingw_flt_type_t hlp;
    unsigned int i;
    hlp.x = _X;
    i = hlp.val & 0x7fffffff;
    i = 0x7f800000 - i;
    return (int)(i >> 31);
  }

  __CRT_INLINE __MINGW_CONST
  int __cdecl __isnanl(long double _X)
  {
#if defined(__x86_64__) || defined(_AMD64_)
    __mingw_ldbl_type_t ld;
    unsigned int xx, signexp;
    ld.x = _X;
    signexp = (ld.lh.sign_exponent & 0x7fff) << 1;
    xx = ld.lh.low | (ld.lh.high & 0x7fffffffu);
    signexp |= (xx | (-xx)) >> 31;
    signexp = 0xfffe - signexp;
    return (int)signexp >> 16;
#elif defined(__aarch64__) || defined(_ARM64_)
    return __isnan(_X);
#endif
  }
#endif  /* __CRT__NO_INLINE */

#if (__MINGW_GNUC_PREREQ(4, 4) && !defined(__SUPPORT_SNAN__)) || __mingw_clang_prereq(2, 8)
# define isnan(_X) __builtin_isnan(_X)
#else
# define isnan(_X)                                                 \
    __mingw_choose_expr(                                           \
      __mingw_types_compatible_p(__typeof__(_X), double),          \
      __isnan(_X),                                                 \
      __mingw_choose_expr(                                         \
        __mingw_types_compatible_p(__typeof__(_X), float),         \
        __isnanf(_X),                                              \
        __mingw_choose_expr(                                       \
          __mingw_types_compatible_p(__typeof__(_X), long double), \
          __isnanl(_X),                                            \
          (__builtin_trap(), _X))))
#endif

/* 7.12.3.5 */
#if (__MINGW_GNUC_PREREQ(4, 4) && !defined(__SUPPORT_SNAN__)) || __mingw_clang_prereq(2, 8)
# define isnormal(_X) __builtin_isnormal(_X)
#else
# define isnormal(_X) (fpclassify(_X) == FP_NORMAL)
#endif

/* 7.12.3.6 The signbit macro */
  extern int __cdecl __signbit(double _X) __MINGW_CONST;
  extern int __cdecl __signbitf(float _X) __MINGW_CONST;
  extern int __cdecl __signbitl(long double _X) __MINGW_CONST;

#ifndef __CRT__NO_INLINE
  __CRT_INLINE __MINGW_CONST
  int __cdecl __signbit(double _X)
  {
    __mingw_dbl_type_t hlp;
    hlp.x = _X;
    return ((hlp.lh.high & 0x80000000) != 0);
  }

  __CRT_INLINE __MINGW_CONST
  int __cdecl __signbitf(float _X)
  {
    __mingw_flt_type_t hlp;
    hlp.x = _X;
    return (hlp.val & 0x80000000) != 0;
  }

  __CRT_INLINE __MINGW_CONST
  int __cdecl __signbitl(long double _X)
  {
#if defined(__x86_64__) || defined(_AMD64_)
    __mingw_ldbl_type_t ld;
    ld.x = _X;
    return (ld.lh.sign_exponent & 0x8000) != 0;
#elif defined(__aarch64__) || defined(_ARM64_)
    return __signbit(_X);
#endif
  }
#endif  /* __CRT__NO_INLINE */

#if __MINGW_GNUC_PREREQ(6, 0) || __mingw_clang_prereq(3, 3)
# define signbit(_X) __builtin_signbit(_X)
#else
# define signbit(_X)                                               \
    __mingw_choose_expr(                                           \
      __mingw_types_compatible_p(__typeof__(_X), double),          \
      __signbit(_X),                                               \
      __mingw_choose_expr(                                         \
        __mingw_types_compatible_p(__typeof__(_X), float),         \
        __signbitf(_X),                                            \
        __mingw_choose_expr(                                       \
          __mingw_types_compatible_p(__typeof__(_X), long double), \
          __signbitl(_X),                                          \
          (__builtin_trap(), _X))))
#endif

/* 7.12.4 Trigonometric functions: Double in C89 */
  _CRTIMP float __cdecl sinf(float _X);
  _LDCRTIMP long double __cdecl sinl(long double _X);

  _CRTIMP float __cdecl cosf(float _X);
  _LDCRTIMP long double __cdecl cosl(long double _X);

  _CRTIMP float __cdecl tanf(float _X);
  _LDCRTIMP long double __cdecl tanl(long double _X);

  _CRTIMP float __cdecl asinf(float _X);
  _LDCRTIMP long double __cdecl asinl(long double _X);

  _CRTIMP float __cdecl acosf(float _X);
  _LDCRTIMP long double __cdecl acosl(long double _X);

  _CRTIMP float __cdecl atanf(float _X);
  _LDCRTIMP long double __cdecl atanl(long double _X);

  _CRTIMP float __cdecl atan2f(float _Y, float _X);
  _LDCRTIMP long double __cdecl atan2l(long double _Y, long double _X);

/* 7.12.5 Hyperbolic functions: Double in C89  */
  _CRTIMP float __cdecl sinhf(float _X);
  _LDCRTIMP long double __cdecl sinhl(long double _X);

  _CRTIMP float __cdecl coshf(float _X);
  _LDCRTIMP long double __cdecl coshl(long double _X);

  _CRTIMP float __cdecl tanhf(float _X);
  _LDCRTIMP long double __cdecl tanhl(long double _X);

/* Inverse hyperbolic trig functions  */
/* 7.12.5.1 */
  _CRTIMP double __cdecl acosh(double _X);
  _CRTIMP float __cdecl acoshf(float _X);
  _LDCRTIMP long double __cdecl acoshl(long double _X);

/* 7.12.5.2 */
  _CRTIMP double __cdecl asinh(double _X);
  _CRTIMP float __cdecl asinhf(float _X);
  _LDCRTIMP long double __cdecl asinhl(long double _X);

/* 7.12.5.3 */
  _CRTIMP double __cdecl atanh(double _X);
  _CRTIMP float __cdecl atanhf(float _X);
  _LDCRTIMP long double __cdecl atanhl(long double _X);

/* Exponentials and logarithms  */
/* 7.12.6.1 Double in C89 */
  _CRTIMP float __cdecl expf(float _X);
  _LDCRTIMP long double __cdecl expl(long double _X);

/* 7.12.6.2 */
  _CRTIMP double __cdecl exp2(double _X);
  _CRTIMP float __cdecl exp2f(float _X);
  _LDCRTIMP long double __cdecl exp2l(long double _X);

/* 7.12.6.3 The expm1 functions */
  _CRTIMP double __cdecl expm1(double _X);
  _CRTIMP float __cdecl expm1f(float _X);
  _LDCRTIMP long double __cdecl expm1l(long double _X);

/* 7.12.6.4 Double in C89 */
  extern float __cdecl frexpf(float _X, int *_Y);
  _LDCRTIMP long double __cdecl frexpl(long double _X, int *_Y);

#ifndef __CRT__NO_INLINE
  __CRT_INLINE float __cdecl frexpf(float _X, int *_Y)
  {
    return (float)frexp(_X, _Y);
  }
#endif  /* __CRT__NO_INLINE */

/* 7.12.6.5 */
#define FP_ILOGB0   ((int)0x80000000)
#define FP_ILOGBNAN ((int)0x7fffffff)
  _CRTIMP int __cdecl ilogb(double _X);
  _CRTIMP int __cdecl ilogbf(float _X);
  _LDCRTIMP int __cdecl ilogbl(long double _X);

/* 7.12.6.6  Double in C89 */
  extern float __cdecl ldexpf(float _X, int _Y);
  extern long double __cdecl ldexpl(long double _X, int _Y);

#ifndef __CRT__NO_INLINE
  __CRT_INLINE float __cdecl ldexpf(float _X, int _Y)
  {
    return (float)ldexp(_X, _Y);
  }
#endif  /* __CRT__NO_INLINE */

/* 7.12.6.7 Double in C89 */
  _CRTIMP float __cdecl logf(float _X);
  _LDCRTIMP long double __cdecl logl(long double _X);

/* 7.12.6.8 Double in C89 */
  _CRTIMP float __cdecl log10f(float _X);
  _LDCRTIMP long double __cdecl log10l(long double _X);

/* 7.12.6.9 */
  _CRTIMP double __cdecl log1p(double _X);
  _CRTIMP float __cdecl log1pf(float _X);
  _LDCRTIMP long double __cdecl log1pl(long double _X);

/* 7.12.6.10 */
  _CRTIMP double __cdecl log2(double _X);
  _CRTIMP float __cdecl log2f(float _X);
  _LDCRTIMP long double __cdecl log2l(long double _X);

/* 7.12.6.11 */
  _CRTIMP double __cdecl logb(double _X);
  _CRTIMP float __cdecl logbf(float _X);
  _LDCRTIMP long double __cdecl logbl(long double _X);

/* 7.12.6.12  Double in C89 */
  _CRTIMP float __cdecl modff(float _X, float *_Y);
  extern long double __cdecl modfl(long double _X, long double *_Y);

/* 7.12.6.13 */
  extern double __cdecl scalbn(double _X, int _Y);
  extern float __cdecl scalbnf(float _X, int _Y);
  extern long double __cdecl scalbnl(long double _X, int _Y);

  extern double __cdecl scalbln(double _X, long _Y);
  extern float __cdecl scalblnf(float _X, long _Y);
  extern long double __cdecl scalblnl(long double _X, long _Y);

/* 7.12.7.1 */
/* Implementations adapted from Cephes versions */
  _CRTIMP double __cdecl cbrt(double _X);
  _CRTIMP float __cdecl cbrtf(float _X);
  _LDCRTIMP long double __cdecl cbrtl(long double _X);

/* 7.12.7.2 The fabs functions: Double in C89 */
#if defined(__aarch64__) || defined(_ARM64_)
  _CRTIMP float __cdecl fabsf(float _X) __MINGW_CONST;
#else
  extern float __cdecl fabsf(float _X) __MINGW_CONST;
#endif
  _LDCRTIMP long double __cdecl fabsl(long double _X) __MINGW_CONST;

#ifndef __CRT__NO_INLINE
#if defined(__x86_64__) || defined(_AMD64_)
  __CRT_INLINE __MINGW_CONST
  float __cdecl fabsf(float _X)
  {
    return __builtin_fabsf(_X);
  }

  __CRT_INLINE __MINGW_CONST
  long double __cdecl fabsl(long double _X)
  {
    long double res = 0.0l;
    __asm__ __volatile__("fabs;" : "=t" (res) : "0" (_X));
    return res;
  }
#endif
#endif  /* __CRT__NO_INLINE */

/* 7.12.7.3  */
  _CRTIMP double __cdecl hypot(double _X, double _Y);
  _CRTIMP float __cdecl hypotf(float _X, float _Y);
  _LDCRTIMP long double __cdecl hypotl(long double _X, long double _Y);

/* 7.12.7.4 The pow functions. Double in C89 */
  _CRTIMP float __cdecl powf(float _X, float _Y);
  _LDCRTIMP long double __cdecl powl(long double _X, long double _Y);

/* 7.12.7.5 The sqrt functions. Double in C89. */
  _CRTIMP float __cdecl sqrtf(float _X);
  _LDCRTIMP long double __cdecl sqrtl(long double _X);

/* 7.12.8.1 The erf functions  */
  _CRTIMP double __cdecl erf(double _X);
  _CRTIMP float __cdecl erff(float _X);
  _LDCRTIMP long double __cdecl erfl(long double _X);

/* 7.12.8.2 The erfc functions  */
  _CRTIMP double __cdecl erfc(double _X);
  _CRTIMP float __cdecl erfcf(float _X);
  _LDCRTIMP long double __cdecl erfcl(long double _X);

/* 7.12.8.3 The lgamma functions */
  extern double __cdecl lgamma(double _X);
  extern float __cdecl lgammaf(float _X);
  extern long double __cdecl lgammal(long double _X);

  extern int signgam;

/* 7.12.8.4 The tgamma functions */
  _CRTIMP double __cdecl tgamma(double _X);
  _CRTIMP float __cdecl tgammaf(float _X);
  _LDCRTIMP long double __cdecl tgammal(long double _X);

/* 7.12.9.1 Double in C89 */
  _CRTIMP float __cdecl ceilf(float _X) __MINGW_CONST;
  _LDCRTIMP long double __cdecl ceill(long double _X) __MINGW_CONST;

/* 7.12.9.2 Double in C89 */
  _CRTIMP float __cdecl floorf(float _X) __MINGW_CONST;
  _LDCRTIMP long double __cdecl floorl(long double _X) __MINGW_CONST;

/* 7.12.9.3 */
  _CRTIMP double __cdecl nearbyint(double _X);
  _CRTIMP float __cdecl nearbyintf(float _X);
  _LDCRTIMP long double __cdecl nearbyintl(long double _X);

/* 7.12.9.4 */
/* round, using fpu control word settings */
  _CRTIMP double __cdecl rint(double _X);
  _CRTIMP float __cdecl rintf(float _X);
  _LDCRTIMP long double __cdecl rintl(long double _X);

/* 7.12.9.5 */
  _CRTIMP long __cdecl lrint(double _X);
  _CRTIMP long __cdecl lrintf(float _X);
  _LDCRTIMP long __cdecl lrintl(long double _X);

  __MINGW_EXTENSION _CRTIMP long long __cdecl llrint(double _X);
  __MINGW_EXTENSION _CRTIMP long long __cdecl llrintf(float _X);
  __MINGW_EXTENSION _LDCRTIMP long long __cdecl llrintl(long double _X);

/* 7.12.9.6 */
/* round away from zero, regardless of fpu control word settings */
  _CRTIMP double __cdecl round(double _X) __MINGW_CONST;
  _CRTIMP float __cdecl roundf(float _X) __MINGW_CONST;
  _LDCRTIMP long double __cdecl roundl(long double _X) __MINGW_CONST;

/* 7.12.9.7  */
  _CRTIMP long __cdecl lround(double _X);
  _CRTIMP long __cdecl lroundf(float _X);
  _LDCRTIMP long __cdecl lroundl(long double _X);
  __MINGW_EXTENSION _CRTIMP long long __cdecl llround(double _X);
  __MINGW_EXTENSION _CRTIMP long long __cdecl llroundf(float _X);
  __MINGW_EXTENSION _LDCRTIMP long long __cdecl llroundl(long double _X);

/* 7.12.9.8 */
/* round towards zero, regardless of fpu control word settings */
  _CRTIMP double __cdecl trunc(double _X) __MINGW_CONST;
  _CRTIMP float __cdecl truncf(float _X) __MINGW_CONST;
  _LDCRTIMP long double __cdecl truncl(long double _X) __MINGW_CONST;

/* 7.12.10.1 Double in C89 */
  _CRTIMP float __cdecl fmodf(float _X, float _Y);
  _LDCRTIMP long double __cdecl fmodl(long double _X, long double _Y);

/* 7.12.10.2 */
  _CRTIMP double __cdecl remainder(double _X, double _Y);
  _CRTIMP float __cdecl remainderf(float _X, float _Y);
  _LDCRTIMP long double __cdecl remainderl(long double _X, long double _Y);

/* 7.12.10.3 */
  _CRTIMP double __cdecl remquo(double _X, double _Y, int *_Z);
  _CRTIMP float __cdecl remquof(float _X, float _Y, int *_Z);
  _LDCRTIMP long double __cdecl remquol(long double _X, long double _Y, int *_Z);

/* 7.12.11.1 */
  _CRTIMP double __cdecl copysign(double _Number, double _Sign) __MINGW_CONST;
  _CRTIMP float __cdecl copysignf(float _Number, float _Sign) __MINGW_CONST;
  _LDCRTIMP long double __cdecl copysignl(long double _Number, long double _Sign) __MINGW_CONST;

/* 7.12.11.2 Return a NaN */
  _CRTIMP double __cdecl nan(const char *_X);
  _CRTIMP float __cdecl nanf(const char *_X);
  _LDCRTIMP long double __cdecl nanl(const char *_X);

#define _nan()  nan("")
#define _nanf() nanf("")
#define _nanl() nanl("")

/* 7.12.11.3 */
  _CRTIMP double __cdecl nextafter(double _X, double _Y) __MINGW_CONST __MINGW_NOTHROW;
  _CRTIMP float __cdecl nextafterf(float _X, float _Y) __MINGW_CONST __MINGW_NOTHROW;
  _LDCRTIMP long double __cdecl nextafterl(long double _X, long double _Y) __MINGW_CONST __MINGW_NOTHROW;

/* 7.12.11.4 The nexttoward functions */
  _LDCRTIMP double __cdecl nexttoward(double _X, long double _Y) __MINGW_CONST __MINGW_NOTHROW;
  _LDCRTIMP float __cdecl nexttowardf(float _X,  long double _Y) __MINGW_CONST __MINGW_NOTHROW;
  _LDCRTIMP long double __cdecl nexttowardl(long double _X, long double _Y) __MINGW_CONST __MINGW_NOTHROW;

/* 7.12.12.1 */
/*  x > y ? (x - y) : 0.0  */
  _CRTIMP double __cdecl fdim(double _X, double _Y);
  _CRTIMP float __cdecl fdimf(float _X, float _Y);
  _LDCRTIMP long double __cdecl fdiml(long double _X, long double _Y);

/* fmax and fmin.
  NaN arguments are treated as missing data: if one argument is a NaN
  and the other numeric, then these functions choose the numeric
  value. */

/* 7.12.12.2 */
  _CRTIMP double __cdecl fmax(double _X, double _Y) __MINGW_CONST;
  _CRTIMP float __cdecl fmaxf(float _X, float _Y) __MINGW_CONST;
  _LDCRTIMP long double __cdecl fmaxl(long double _X, long double _Y) __MINGW_CONST;

/* 7.12.12.3 */
  _CRTIMP double __cdecl fmin(double _X, double _Y) __MINGW_CONST;
  _CRTIMP float __cdecl fminf(float _X, float _Y) __MINGW_CONST;
  _LDCRTIMP long double __cdecl fminl(long double _X, long double _Y) __MINGW_CONST;

/* 7.12.13.1 */
/* return x * y + z as a ternary op */
  _CRTIMP double __cdecl fma(double _X, double _Y, double _Z);
  _CRTIMP float __cdecl fmaf(float _X, float _Y, float _Z);
  _LDCRTIMP long double __cdecl fmal(long double _X, long double _Y, long double _Z);

/* 7.12.14 */
/*
 *  With these functions, comparisons involving quiet NaNs set the FP
 *  condition code to "unordered".  The IEEE floating-point spec
 *  dictates that the result of floating-point comparisons should be
 *  false whenever a NaN is involved, with the exception of the != op,
 *  which always returns true: yes, (NaN != NaN) is true).
 */
#define isgreater(x, y)      __builtin_isgreater(x, y)
#define isgreaterequal(x, y) __builtin_isgreaterequal(x, y)
#define isless(x, y)         __builtin_isless(x, y)
#define islessequal(x, y)    __builtin_islessequal(x, y)
#define islessgreater(x, y)  __builtin_islessgreater(x, y)
#define isunordered(x, y)    __builtin_isunordered(x, y)

#endif

  _CRTIMP float __cdecl _hypotf(float _X, float _Y);
  _LDCRTIMP long double __cdecl _hypotl(long double _X, long double _Y);

  _CRTIMP float __cdecl _copysignf(float _Number, float _Sign) __MINGW_CONST;
  _CRTIMP float __cdecl _chgsignf(float _X);
  _CRTIMP float __cdecl _logbf(float _X);
  _CRTIMP int __cdecl _finitef(float _X) __MINGW_CONST;

#if defined(__x86_64__) || defined(_AMD64_)
  _CRTIMP float __cdecl _nextafterf(float _X, float _Y) __MINGW_CONST __MINGW_NOTHROW;
  _CRTIMP int __cdecl _isnanf(float _X) __MINGW_CONST;
  _CRTIMP int __cdecl _fpclassf(float _X);
  _CRTIMP int __cdecl _set_FMA3_enable(int _Flag);
  _CRTIMP int __cdecl _get_FMA3_enable(void);
#endif

#ifndef __cplusplus
# define _matherrl _matherr
#endif

#ifdef __MINGW_USE_MS
# define DOMAIN    _DOMAIN
# define SING      _SING
# define OVERFLOW  _OVERFLOW
# define UNDERFLOW _UNDERFLOW
# define TLOSS     _TLOSS
# define PLOSS     _PLOSS

# define matherr _matherr
# define HUGE    _HUGE
#endif

__MINGW_END_C_DECLS

#endif  /* _MATH_H_ */
