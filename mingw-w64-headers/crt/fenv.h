/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _FENV_H_
#define _FENV_H_

#include <corecrt.h>
#include <float.h>

__MINGW_BEGIN_C_DECLS

#if defined(__aarch64__) || defined(_ARM64_)

/* FPU status word exception flags */
#define FE_INVALID    0x01
#define FE_DIVBYZERO  0x02
#define FE_OVERFLOW   0x04
#define FE_UNDERFLOW  0x08
#define FE_INEXACT    0x10
#define FE_ALL_EXCEPT (FE_INVALID | FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW | FE_INEXACT)

/* FPU control word rounding flags */
#define FE_TONEAREST  0x00000000
#define FE_UPWARD     0x00400000
#define FE_DOWNWARD   0x00800000
#define FE_TOWARDZERO 0x00c00000

/* Amount to shift by to convert an exception to a mask bit.  */
#define FE_EXCEPT_SHIFT 0x08

#else

#define FE_INVALID    0x01
#define FE_DENORMAL   0x02
#define FE_DIVBYZERO  0x04
#define FE_OVERFLOW   0x08
#define FE_UNDERFLOW  0x10
#define FE_INEXACT    0x20
#define FE_ALL_EXCEPT (FE_INVALID | FE_DENORMAL | FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW | FE_INEXACT)

/* FPU control word rounding flags */
#define FE_TONEAREST  0x0000
#define FE_DOWNWARD   0x0400
#define FE_UPWARD     0x0800
#define FE_TOWARDZERO 0x0c00

/* The MXCSR exception flags are the same as the
   FE flags. */
#define __MXCSR_EXCEPT_FLAG_SHIFT 0

/* How much to shift FE status word exception flags
   to get the MXCSR exeptions masks,  */
#define __MXCSR_EXCEPT_MASK_SHIFT 7

/* How much to shift FE status word exception flags
   to get MXCSR rounding flags,  */
#define __MXCSR_ROUND_FLAG_SHIFT 3

#endif  /* defined(__aarch64__) || defined(_ARM64_) */

#if defined(__aarch64__) || defined(_ARM64_)

  /* Type representing exception flags. */
  typedef unsigned int fexcept_t;

  /* Type representing floating-point environment.  */
  typedef struct
  {
    unsigned int __cw;
  } fenv_t;

/* If the default argument is used we use this value.  */
#define FE_DFL_ENV ((const fenv_t *) -1l)

#else

  /*
    For now, support only for the basic abstraction of flags that are
    either set or clear. fexcept_t could be  structure that holds more
    info about the fp environment.
  */
  typedef unsigned short fexcept_t;

  /* This 32-byte struct represents the entire floating point
    environment as stored by fnstenv or fstenv, augmented by
    the  contents of the MXCSR register, as stored by stmxcsr
    (if CPU supports it). */
  typedef struct
  {
    unsigned short __control_word;
    unsigned short __unused0;
    unsigned short __status_word;
    unsigned short __unused1;
    unsigned short __tag_word;
    unsigned short __unused2;
    unsigned int   __ip_offset;  /* instruction pointer offset */
    unsigned short __ip_selector;
    unsigned short __opcode;
    unsigned int   __data_offset;
    unsigned short __data_selector;
    unsigned short __unused3;
    unsigned int   __mxcsr;  /* contents of the MXCSR register  */
  } fenv_t;


/*The C99 standard (7.6.9) allows us to define implementation-specific macros for
  different fp environments */

/* The default Intel x87 floating point environment (64-bit mantissa) */
#define FE_PC64_ENV ((const fenv_t *)-1)

/* The floating point environment set by MSVCRT _fpreset (53-bit mantissa) */
#define FE_PC53_ENV ((const fenv_t *)-2)

/* The FE_DFL_ENV macro is required by standard.
  fesetenv will use the environment set at app startup.*/
#define FE_DFL_ENV ((const fenv_t *)0)

#endif  /* defined(__aarch64__) || defined(_ARM64_) */

  /* 7.6.2 Exception */
  _CRTIMP int __cdecl feclearexcept(int _Flags)                           __MINGW_NOTHROW;
  _CRTIMP int __cdecl fegetexceptflag(fexcept_t *_Except, int _TestFlags) __MINGW_NOTHROW;
  __forceinline __MINGW_NOTHROW __attribute__((optimize("O0")))
  int __cdecl feraiseexcept(int _Except)
  {
    static struct
    {
      int    _Except_Val;
      double _Num;
      double _Denom;
    } const _Table[] =
      {
        {FE_INVALID,   0.0,    0.0   },
        {FE_DIVBYZERO, 1.0,    0.0   },
        {FE_OVERFLOW,  1e+300, 1e-300},
        {FE_UNDERFLOW, 1e-300, 1e+300},
        {FE_INEXACT,   2.0,    3.0   }
      };

    double _Ans = 0.0;
    (void) _Ans;
    size_t _Index;

    if((_Except &= FE_ALL_EXCEPT) == 0)
    {
      return 0;
    }

    for(_Index = 0; _Index < sizeof(_Table) / sizeof(_Table[0]); ++_Index)
    {
      if((_Except & _Table[_Index]._Except_Val) != 0)
      {
        _Ans = _Table[_Index]._Num / _Table[_Index]._Denom;
      }
    }
    return 0;
  }
  _CRTIMP int __cdecl fesetexceptflag(const fexcept_t *_Except, int _SetFlags) __MINGW_NOTHROW;
  _CRTIMP int __cdecl fetestexcept(int _Flags)                                 __MINGW_NOTHROW;

  /* 7.6.3 Rounding */
  _CRTIMP int __cdecl fegetround(void)       __MINGW_PURE __MINGW_NOTHROW;
  _CRTIMP int __cdecl fesetround(int _Round) __MINGW_NOTHROW;

  /* 7.6.4 Environment */
  _CRTIMP int __cdecl fegetenv(fenv_t *_Env)           __MINGW_NOTHROW;
  _CRTIMP int __cdecl fesetenv(const fenv_t *_Env)     __MINGW_NOTHROW;
  __forceinline __MINGW_NOTHROW
  int __cdecl feupdateenv(const fenv_t *_Penv)
  {
    int _Except = fetestexcept(FE_ALL_EXCEPT);
    if(fesetenv(_Penv) != 0 || feraiseexcept(_Except) != 0)
    {
      return 1;
    }
    return 0;
  }
  _CRTIMP int __cdecl feholdexcept(fenv_t *_Env)       __MINGW_NOTHROW;

__MINGW_END_C_DECLS

#endif  /* _FENV_H_ */
