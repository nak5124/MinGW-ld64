/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_SETJMP
#define _INC_SETJMP

#include <corecrt.h>

__MINGW_BEGIN_C_DECLS

#ifdef __x86_64__

  typedef _CRT_ALIGN(16) struct _SETJMP_FLOAT128
  {
    __MINGW_EXTENSION unsigned __int64 Part[2];
  } SETJMP_FLOAT128;

#define _JBLEN 16
  typedef SETJMP_FLOAT128 _JBTYPE;

  typedef struct _JUMP_BUFFER
  {
    __MINGW_EXTENSION unsigned __int64 Frame;
    __MINGW_EXTENSION unsigned __int64 Rbx;
    __MINGW_EXTENSION unsigned __int64 Rsp;
    __MINGW_EXTENSION unsigned __int64 Rbp;
    __MINGW_EXTENSION unsigned __int64 Rsi;
    __MINGW_EXTENSION unsigned __int64 Rdi;
    __MINGW_EXTENSION unsigned __int64 R12;
    __MINGW_EXTENSION unsigned __int64 R13;
    __MINGW_EXTENSION unsigned __int64 R14;
    __MINGW_EXTENSION unsigned __int64 R15;
    __MINGW_EXTENSION unsigned __int64 Rip;
    unsigned long                      MxCsr;
    unsigned short                     FpCsr;
    unsigned short                     Spare;
    SETJMP_FLOAT128                    Xmm6;
    SETJMP_FLOAT128                    Xmm7;
    SETJMP_FLOAT128                    Xmm8;
    SETJMP_FLOAT128                    Xmm9;
    SETJMP_FLOAT128                    Xmm10;
    SETJMP_FLOAT128                    Xmm11;
    SETJMP_FLOAT128                    Xmm12;
    SETJMP_FLOAT128                    Xmm13;
    SETJMP_FLOAT128                    Xmm14;
    SETJMP_FLOAT128                    Xmm15;
  } _JUMP_BUFFER;

#elif defined(__aarch64__)

#define _JBLEN  24
#define _JBTYPE unsigned __int64

  typedef struct __JUMP_BUFFER
  {
    unsigned __int64 Frame;
    unsigned __int64 Reserved;
    unsigned __int64 X19;
    unsigned __int64 X20;
    unsigned __int64 X21;
    unsigned __int64 X22;
    unsigned __int64 X23;
    unsigned __int64 X24;
    unsigned __int64 X25;
    unsigned __int64 X26;
    unsigned __int64 X27;
    unsigned __int64 X28;
    unsigned __int64 Fp;
    unsigned __int64 Lr;
    unsigned __int64 Sp;
    unsigned long    Fpcr;
    unsigned long    Fpsr;
    double           D[8];
  } _JUMP_BUFFER;

#else

#define _JBLEN  1
#define _JBTYPE int

#endif

#ifndef _JMP_BUF_DEFINED
# define _JMP_BUF_DEFINED
  typedef _JBTYPE jmp_buf[_JBLEN];
#endif

  _CRTIMP void  __cdecl longjmp(jmp_buf _Buf, int _Value) __NOTHROW __NORETURN;

#define _setjmp   __intrinsic_setjmpex
#define _setjmpex __intrinsic_setjmpex
#ifndef _INC_SETJMPEX
# if defined(__aarch64__) || defined(_ARM64_)
#   define setjmp(BUF) _setjmp((BUF), __builtin_sponentry())
# else
#   define setjmp(BUF) _setjmp((BUF), __builtin_frame_address(0))
# endif
  int __cdecl _setjmp(jmp_buf _Buf, void *_Ctx) __NOTHROW __RETURNS_TWICE;
#else
# undef setjmp
# define setjmp(BUF)   _setjmpex((BUF), __builtin_frame_address(0))
# define setjmpex(BUF) _setjmpex((BUF), __builtin_frame_address(0))
  int __cdecl _setjmpex(jmp_buf _Buf, void *_Ctx) __NOTHROW __RETURNS_TWICE;
#endif

__MINGW_END_C_DECLS

#endif  /* _INC_SETJMP */
