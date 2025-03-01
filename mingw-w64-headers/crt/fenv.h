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

/* FPU control word rounding flags */
#define FE_TONEAREST  _RC_NEAR
#define FE_UPWARD     _RC_UP
#define FE_DOWNWARD   _RC_DOWN
#define FE_TOWARDZERO _RC_CHOP
#define FE_ROUND_MASK _MCW_RC

  /* Type representing exception flags. */
  typedef unsigned long fexcept_t;

  /* Type representing floating-point environment. */
  typedef struct fenv_t
  {
    unsigned long _Fe_ctl;
    unsigned long _Fe_stat;
  } fenv_t;

#define FE_INEXACT   _SW_INEXACT
#define FE_UNDERFLOW _SW_UNDERFLOW
#define FE_OVERFLOW  _SW_OVERFLOW
#define FE_DIVBYZERO _SW_ZERODIVIDE
#define FE_INVALID   _SW_INVALID
#define FE_DENORMAL  _SW_DENORMAL

#define FE_ALL_EXCEPT (FE_DIVBYZERO | FE_INEXACT | FE_INVALID | FE_OVERFLOW | FE_UNDERFLOW)

#ifndef __WIDL__
# ifdef __x86_64__
  __SELECTANY extern const fenv_t _Fenv1 = {0x3f00003f, 0};
# else
  __SELECTANY extern const fenv_t _Fenv1 = {0x0000003f, 0};
# endif
# define FE_DFL_ENV (&_Fenv1)
#endif

  /* 7.6.2 Exception */
  _CRTIMP int __cdecl feclearexcept(int _Flags)                           __NOTHROW;
  _CRTIMP int __cdecl fegetexceptflag(fexcept_t *_Except, int _TestFlags) __NOTHROW;
  __forceinline __NO_OPTIMIZE
  __NTH_FNC(int __cdecl feraiseexcept(int _Except))
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
  _CRTIMP int __cdecl fesetexceptflag(const fexcept_t *_Except, int _SetFlags) __NOTHROW;
  _CRTIMP int __cdecl fetestexcept(int _Flags)                                 __NOTHROW;

  /* 7.6.3 Rounding */
  _CRTIMP int __cdecl fegetround(void)       __NOTHROW __PURE;
  _CRTIMP int __cdecl fesetround(int _Round) __NOTHROW;

  /* 7.6.4 Environment */
  _CRTIMP int __cdecl fegetenv(fenv_t *_Env)       __NOTHROW;
  _CRTIMP int __cdecl fesetenv(const fenv_t *_Env) __NOTHROW;
  __forceinline
  __NTH_FNC(int __cdecl feupdateenv(const fenv_t *_Penv))
  {
    int _Except = fetestexcept(FE_ALL_EXCEPT);
    if(fesetenv(_Penv) != 0 || feraiseexcept(_Except) != 0)
    {
      return 1;
    }
    return 0;
  }
  _CRTIMP int __cdecl feholdexcept(fenv_t *_Env) __NOTHROW;

__MINGW_END_C_DECLS

#endif  /* _FENV_H_ */
