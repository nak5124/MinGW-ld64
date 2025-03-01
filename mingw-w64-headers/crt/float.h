/*
 * float.h
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within the package.
 *
 * Constants related to floating point arithmetic.
 *
 * Also included here are some non-ANSI bits for accessing the floating
 * point controller.
 *
 */
#include <corecrt.h>

#ifdef __clang__
# ifndef __CLANG_FLOAT_H
#   include_next <float.h>
# endif
#elif !defined(_FLOAT_H___)

  /* Radix of exponent representation, b. */
# undef  FLT_RADIX
# define FLT_RADIX __FLT_RADIX__

  /* Number of base-FLT_RADIX digits in the significand, p. */
# undef  FLT_MANT_DIG
# undef  DBL_MANT_DIG
# undef  LDBL_MANT_DIG
# define FLT_MANT_DIG  __FLT_MANT_DIG__
# define DBL_MANT_DIG  __DBL_MANT_DIG__
# define LDBL_MANT_DIG __LDBL_MANT_DIG__

  /* Number of decimal digits, q, such that any floating-point number with q
   * decimal digits can be rounded into a floating-point number with p radix b
   * digits and back again without change to the q decimal digits,
   * p * log10(b)   if b is a power of 10
   * floor((p - 1) * log10(b)) otherwise */
# undef  FLT_DIG
# undef  DBL_DIG
# undef  LDBL_DIG
# define FLT_DIG  __FLT_DIG__
# define DBL_DIG  __DBL_DIG__
# define LDBL_DIG __LDBL_DIG__

  /* Minimum int x such that FLT_RADIX**(x-1) is a normalized float, emin */
# undef  FLT_MIN_EXP
# undef  DBL_MIN_EXP
# undef  LDBL_MIN_EXP
# define FLT_MIN_EXP  __FLT_MIN_EXP__
# define DBL_MIN_EXP  __DBL_MIN_EXP__
# define LDBL_MIN_EXP __LDBL_MIN_EXP__

  /* Minimum negative integer such that 10 raised to that power is in the
   * range of normalized floating-point numbers,
   * ceil(log10(b) * (emin - 1)) */
# undef  FLT_MIN_10_EXP
# undef  DBL_MIN_10_EXP
# undef  LDBL_MIN_10_EXP
# define FLT_MIN_10_EXP  __FLT_MIN_10_EXP__
# define DBL_MIN_10_EXP  __DBL_MIN_10_EXP__
# define LDBL_MIN_10_EXP __LDBL_MIN_10_EXP__

  /* Maximum int x such that FLT_RADIX**(x-1) is a representable float, emax.  */
# undef  FLT_MAX_EXP
# undef  DBL_MAX_EXP
# undef  LDBL_MAX_EXP
# define FLT_MAX_EXP  __FLT_MAX_EXP__
# define DBL_MAX_EXP  __DBL_MAX_EXP__
# define LDBL_MAX_EXP __LDBL_MAX_EXP__

  /* Maximum integer such that 10 raised to that power is in the range of
   * representable finite floating-point numbers,
   * floor(log10((1 - b**-p) * b**emax)) */
# undef  FLT_MAX_10_EXP
# undef  DBL_MAX_10_EXP
# undef  LDBL_MAX_10_EXP
# define FLT_MAX_10_EXP  __FLT_MAX_10_EXP__
# define DBL_MAX_10_EXP  __DBL_MAX_10_EXP__
# define LDBL_MAX_10_EXP __LDBL_MAX_10_EXP__

  /* Maximum representable finite floating-point number,
    (1 - b**-p) * b**emax */
# undef  FLT_MAX
# undef  DBL_MAX
# undef  LDBL_MAX
# define FLT_MAX  __FLT_MAX__
# define DBL_MAX  __DBL_MAX__
# define LDBL_MAX __LDBL_MAX__

  /* The difference between 1 and the least value greater than 1 that is
   * representable in the given floating point type, b**1-p. */
# undef  FLT_EPSILON
# undef  DBL_EPSILON
# undef  LDBL_EPSILON
# define FLT_EPSILON  __FLT_EPSILON__
# define DBL_EPSILON  __DBL_EPSILON__
# define LDBL_EPSILON __LDBL_EPSILON__

  /* Minimum normalized positive floating-point number, b**(emin - 1). */
# undef  FLT_MIN
# undef  DBL_MIN
# undef  LDBL_MIN
# define FLT_MIN  __FLT_MIN__
# define DBL_MIN  __DBL_MIN__
# define LDBL_MIN __LDBL_MIN__

  /* Addition rounds to 0: zero, 1: nearest, 2: +inf, 3: -inf, -1: unknown.  */
  /* ??? This is supposed to change with calls to fesetround in <fenv.h>.  */
# undef  FLT_ROUNDS
# define FLT_ROUNDS 1

# ifdef __MINGW_USE_ISOC99
    /* The floating-point expression evaluation method.
     *    -1  indeterminate
     *     0  evaluate all operations and constants just to the range and
     * precision of the type
     *     1  evaluate operations and constants of type float and double
     * to the range and precision of the double type, evaluate
     * long double operations and constants to the range and
     * precision of the long double type
     *     2  evaluate all operations and constants to the range and
     * precision of the long double type
     *
     * ??? This ought to change with the setting of the fp control word;
     * the value provided by the compiler assumes the widest setting. */
#   undef  FLT_EVAL_METHOD
#   define FLT_EVAL_METHOD __FLT_EVAL_METHOD__

    /* Number of decimal digits, n, such that any floating-point number in the
     * widest supported floating type with pmax radix b digits can be rounded
     * to a floating-point number with n decimal digits and back again without
     * change to the value,
     *
     * pmax * log10(b)      if b is a power of 10
     * ceil(1 + pmax * log10(b))  otherwise */
#   undef  DECIMAL_DIG
#   define DECIMAL_DIG __DECIMAL_DIG__
# endif  /* __MINGW_USE_ISOC99 */

# ifdef __MINGW_USE_ISOC11
    /* Versions of DECIMAL_DIG for each floating-point type.  */
#   undef  FLT_DECIMAL_DIG
#   undef  DBL_DECIMAL_DIG
#   undef  LDBL_DECIMAL_DIG
#   define FLT_DECIMAL_DIG  __FLT_DECIMAL_DIG__
#   define DBL_DECIMAL_DIG  __DBL_DECIMAL_DIG__
#   define LDBL_DECIMAL_DIG __LDBL_DECIMAL_DIG__

    /* Whether types support subnormal numbers.  */
#   undef  FLT_HAS_SUBNORM
#   undef  DBL_HAS_SUBNORM
#   undef  LDBL_HAS_SUBNORM
#   define FLT_HAS_SUBNORM  __FLT_HAS_DENORM__
#   define DBL_HAS_SUBNORM  __DBL_HAS_DENORM__
#   define LDBL_HAS_SUBNORM __LDBL_HAS_DENORM__

    /* Minimum positive values, including subnormals.  */
#   undef  FLT_TRUE_MIN
#   undef  DBL_TRUE_MIN
#   undef  LDBL_TRUE_MIN
#   define FLT_TRUE_MIN  __FLT_DENORM_MIN__
#   define DBL_TRUE_MIN  __DBL_DENORM_MIN__
#   define LDBL_TRUE_MIN __LDBL_DENORM_MIN__
# endif

# ifdef __MINGW_USE_ISOC23
    /* Maximum finite positive value with MANT_DIG digits in the
     * significand taking their maximum value. */
#   undef  FLT_NORM_MAX
#   undef  DBL_NORM_MAX
#   undef  LDBL_NORM_MAX
#   define FLT_NORM_MAX  __FLT_NORM_MAX__
#   define DBL_NORM_MAX  __DBL_NORM_MAX__
#   define LDBL_NORM_MAX __LDBL_NORM_MAX__

    /* Whether each type matches an IEC 60559 format. */
#   undef  FLT_IS_IEC_60559
#   undef  DBL_IS_IEC_60559
#   undef  LDBL_IS_IEC_60559
#   define FLT_IS_IEC_60559  __FLT_IS_IEC_60559__
#   define DBL_IS_IEC_60559  __DBL_IS_IEC_60559__
#   define LDBL_IS_IEC_60559 __LDBL_IS_IEC_60559__

    /* Signaling NaN, if supported for each type.  All formats supported
     * by GCC support either both quiet and signaling NaNs, or neither
     * kind of NaN. */
#   if __FLT_HAS_QUIET_NAN__
#     undef  FLT_SNAN
#     define FLT_SNAN (__builtin_nansf(""))
#   endif
#   if __DBL_HAS_QUIET_NAN__
#     undef  DBL_SNAN
#     define DBL_SNAN (__builtin_nans(""))
#   endif
#   if __LDBL_HAS_QUIET_NAN__
#     undef  LDBL_SNAN
#     define LDBL_SNAN (__builtin_nansl(""))
#   endif
# endif

# define _FLOAT_H___
#endif

#ifndef _MINGW_FLOAT_H_
#define _MINGW_FLOAT_H_

__MINGW_BEGIN_C_DECLS

#define _DBL_RADIX   2
#define _LDBL_RADIX _DBL_RADIX

#define _SW_INEXACT    0x00000001
#define _SW_UNDERFLOW  0x00000002
#define _SW_OVERFLOW   0x00000004
#define _SW_ZERODIVIDE 0x00000008
#define _SW_INVALID    0x00000010
#define _SW_DENORMAL   0x00080000

#define _EM_AMBIGUIOUS 0x80000000
#define _EM_AMBIGUOUS  0x80000000

/* Interrupt Exception Masks */
#define _MCW_EM        0x0008001F
#define _EM_INEXACT    0x00000001
#define _EM_UNDERFLOW  0x00000002
#define _EM_OVERFLOW   0x00000004
#define _EM_ZERODIVIDE 0x00000008
#define _EM_INVALID    0x00000010
#define _EM_DENORMAL   0x00080000

/* Rounding Control */
#define _MCW_RC  0x00000300
#define _RC_NEAR 0x00000000
#define _RC_DOWN 0x00000100
#define _RC_UP   0x00000200
#define _RC_CHOP 0x00000300

/* Precision Control */
#define _MCW_PC 0x00030000
#define _PC_64  0x00000000
#define _PC_53  0x00010000
#define _PC_24  0x00020000

/* Infinity Control */
#define _MCW_IC        0x00040000
#define _IC_AFFINE     0x00040000
#define _IC_PROJECTIVE 0x00000000

/* Denormal Control */
#define _MCW_DN                         0x03000000
#define _DN_SAVE                        0x00000000
#define _DN_FLUSH                       0x01000000
#define _DN_FLUSH_OPERANDS_SAVE_RESULTS 0x02000000
#define _DN_SAVE_OPERANDS_FLUSH_RESULTS 0x03000000

/* invalid subconditions (_SW_INVALID also set) */
#define _SW_UNEMULATED     0x0040  /* Unemulated instruction */
#define _SW_SQRTNEG        0x0080  /* Square root of a negative number */
#define _SW_STACKOVERFLOW  0x0200  /* FP stack overflow */
#define _SW_STACKUNDERFLOW 0x0400  /* FP stack underflow */

/*  Floating point error signals and return codes */
#define _FPE_INVALID         0x81
#define _FPE_DENORMAL        0x82
#define _FPE_ZERODIVIDE      0x83
#define _FPE_OVERFLOW        0x84
#define _FPE_UNDERFLOW       0x85
#define _FPE_INEXACT         0x86
#define _FPE_UNEMULATED      0x87
#define _FPE_SQRTNEG         0x88
#define _FPE_STACKOVERFLOW   0x8a
#define _FPE_STACKUNDERFLOW  0x8b
#define _FPE_EXPLICITGEN     0x8c  /* raise(SIGFPE); */
#define _FPE_MULTIPLE_TRAPS  0x8d
#define _FPE_MULTIPLE_FAULTS 0x8e

/* Return values for fpclass. */
#ifndef __MINGW_FPCLASS_DEFINED
# define __MINGW_FPCLASS_DEFINED 1
# define _FPCLASS_SNAN           0x0001  /* Signaling "Not a Number" */
# define _FPCLASS_QNAN           0x0002  /* Quiet "Not a Number" */
# define _FPCLASS_NINF           0x0004  /* Negative Infinity */
# define _FPCLASS_NN             0x0008  /* Negative Normal */
# define _FPCLASS_ND             0x0010  /* Negative Denormal */
# define _FPCLASS_NZ             0x0020  /* Negative Zero */
# define _FPCLASS_PZ             0x0040  /* Positive Zero */
# define _FPCLASS_PD             0x0080  /* Positive Denormal */
# define _FPCLASS_PN             0x0100  /* Positive Normal */
# define _FPCLASS_PINF           0x0200  /* Positive Infinity */
#endif  /* __MINGW_FPCLASS_DEFINED */

#define _CW_DEFAULT (_RC_NEAR + _EM_INVALID + _EM_ZERODIVIDE + _EM_OVERFLOW + _EM_UNDERFLOW + _EM_INEXACT + _EM_DENORMAL)

  _CRTIMP unsigned int __cdecl _clearfp(void) __NOTHROW;
  _CRTIMP unsigned int __cdecl _controlfp(unsigned int _NewValue, unsigned int _Mask) __NOTHROW __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP void         __cdecl _set_controlfp(unsigned int _NewValue, unsigned int _Mask);
  _CRTIMP errno_t      __cdecl _controlfp_s(unsigned int *_CurrentState, unsigned int _NewValue, unsigned int _Mask);
  _CRTIMP unsigned int __cdecl _statusfp(void) __NOTHROW;
  /**/    void         __cdecl _fpreset(void)  __NOTHROW;

#define _clear87  _clearfp
#define _status87 _statusfp

  _CRTIMP unsigned int __cdecl _control87(unsigned int _NewValue, unsigned int _Mask) __NOTHROW;

  /* Global 'variable' for the current floating point error code. */
  _CRTIMP int *__cdecl __fpecode(void) __NOTHROW;
#define _fpecode (*(__fpecode()))

  _CRTIMP int __cdecl __fpe_flt_rounds(void);

#define _DBL_ROUNDS   FLT_ROUNDS
#define _LDBL_ROUNDS _DBL_ROUNDS

#ifndef _SIGN_DEFINED  /* Also in math.h */
# define _SIGN_DEFINED
  _CRTIMP double __cdecl _copysign(double _Number, double _Sign) __NOTHROW __CONST;
  _CRTIMP double __cdecl _chgsign(double _X)                     __NOTHROW;
  _CRTIMP double __cdecl _scalb(double _X, long _Y)              __NOTHROW;
  _CRTIMP double __cdecl _logb(double _X)                        __NOTHROW;
  _CRTIMP double __cdecl _nextafter(double _X, double _Y)        __NOTHROW __CONST;
  _CRTIMP int    __cdecl _finite(double _X)                      __NOTHROW __CONST;
  _CRTIMP int    __cdecl _isnan(double _X)                       __NOTHROW __CONST;
  _CRTIMP int    __cdecl _fpclass(double _X)                     __NOTHROW;
#ifdef __x86_64__
  _CRTIMP float  __cdecl _scalbf(float _X, long _Y) __NOTHROW;
#endif

  _CRTIMP long double __cdecl _copysignl(long double _Number, long double _Sign) __NOTHROW __CONST;
  _CRTIMP long double __cdecl _chgsignl(long double _X) __NOTHROW;
#endif  /* _SIGN_DEFINED */

#ifdef __MINGW_USE_MS

#define clear87   _clear87
#define status87  _status87
#define control87 _control87

  void __cdecl fpreset(void) __NOTHROW;

#define DBL_RADIX   _DBL_RADIX
#define DBL_ROUNDS  _DBL_ROUNDS
#define LDBL_RADIX  _LDBL_RADIX
#define LDBL_ROUNDS _LDBL_ROUNDS

#define SW_INEXACT    _SW_INEXACT
#define SW_UNDERFLOW  _SW_UNDERFLOW
#define SW_OVERFLOW   _SW_OVERFLOW
#define SW_INVALID    _SW_INVALID
#define SW_ZERODIVIDE _SW_ZERODIVIDE
#define SW_DENORMAL   _SW_DENORMAL

#define EM_AMBIGUIOUS _EM_AMBIGUIOUS
#define EM_AMBIGUOUS  _EM_AMBIGUOUS

#define MCW_EM        _MCW_EM
#define EM_INEXACT    _EM_INEXACT
#define EM_UNDERFLOW  _EM_UNDERFLOW
#define EM_OVERFLOW   _EM_OVERFLOW
#define EM_ZERODIVIDE _EM_ZERODIVIDE
#define EM_INVALID    _EM_INVALID
#define EM_DENORMAL   _EM_DENORMAL

#define MCW_RC  _MCW_RC
#define RC_NEAR _RC_NEAR
#define RC_DOWN _RC_DOWN
#define RC_UP   _RC_UP
#define RC_CHOP _RC_CHOP

#define MCW_PC _MCW_PC
#define PC_64  _PC_64
#define PC_53  _PC_53
#define PC_24  _PC_24

#define MCW_IC        _MCW_IC
#define IC_AFFINE     _IC_AFFINE
#define IC_PROJECTIVE _IC_PROJECTIVE

#define CW_DEFAULT _CW_DEFAULT

#define SW_UNEMULATED     _SW_UNEMULATED
#define SW_SQRTNEG        _SW_SQRTNEG
#define SW_STACKOVERFLOW  _SW_STACKOVERFLOW
#define SW_STACKUNDERFLOW _SW_STACKUNDERFLOW

#define FPE_INVALID        _FPE_INVALID
#define FPE_DENORMAL       _FPE_DENORMAL
#define FPE_ZERODIVIDE     _FPE_ZERODIVIDE
#define FPE_OVERFLOW       _FPE_OVERFLOW
#define FPE_UNDERFLOW      _FPE_UNDERFLOW
#define FPE_INEXACT        _FPE_INEXACT
#define FPE_UNEMULATED     _FPE_UNEMULATED
#define FPE_SQRTNEG        _FPE_SQRTNEG
#define FPE_STACKOVERFLOW  _FPE_STACKOVERFLOW
#define FPE_STACKUNDERFLOW _FPE_STACKUNDERFLOW
#define FPE_EXPLICITGEN    _FPE_EXPLICITGEN

#endif  /* __MINGW_USE_MS */

#ifdef __MINGW_USE_ISOC23
# ifndef INFINITY
#   define INFINITY  __builtin_inff()
# endif
# ifndef NAN
#   define NAN       __builtin_nanf("")
# endif
#endif

__MINGW_END_C_DECLS

#endif  /* _MINGW_FLOAT_H_ */
