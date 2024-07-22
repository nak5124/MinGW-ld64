/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_SETJMP
#define _INC_SETJMP

#include <corecrt.h>

#pragma pack(push, _CRT_PACKING)

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
    unsigned long MxCsr;
    unsigned short FpCsr;
    unsigned short Spare;
    SETJMP_FLOAT128 Xmm6;
    SETJMP_FLOAT128 Xmm7;
    SETJMP_FLOAT128 Xmm8;
    SETJMP_FLOAT128 Xmm9;
    SETJMP_FLOAT128 Xmm10;
    SETJMP_FLOAT128 Xmm11;
    SETJMP_FLOAT128 Xmm12;
    SETJMP_FLOAT128 Xmm13;
    SETJMP_FLOAT128 Xmm14;
    SETJMP_FLOAT128 Xmm15;
  } _JUMP_BUFFER;

#elif defined(__aarch64__)

#define _JBLEN 24
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
    unsigned long Fpcr;
    unsigned long Fpsr;
    double D[8];
  } _JUMP_BUFFER;

#else

#define _JBLEN 1
#define _JBTYPE int

#endif

#ifndef _JMP_BUF_DEFINED
# define _JMP_BUF_DEFINED
  typedef _JBTYPE jmp_buf[_JBLEN];
#endif

  _CRTIMP __MINGW_ATTRIB_NORETURN __attribute__((__nothrow__)) void __cdecl longjmp(jmp_buf _Buf, int _Value);

  void *__cdecl __attribute__((__nothrow__)) mingw_getsp(void);

#pragma push_macro("__has_builtin")
#ifndef __has_builtin
# define __has_builtin(x) 0
#endif

#define _setjmp __intrinsic_setjmpex
#ifndef _INC_SETJMPEX
# if (defined(__aarch64__) || defined(_ARM64_)) && (!defined(__SEH__) || !__has_builtin(__builtin_sponentry) || defined(__USE_MINGW_SETJMP_NON_SEH))
#   define setjmp(BUF) __mingw_setjmp((BUF))
#   define longjmp     __mingw_longjmp
    int __cdecl __attribute__((__nothrow__, __returns_twice__)) __mingw_setjmp(jmp_buf _Buf);
    __MINGW_ATTRIB_NORETURN __attribute__((__nothrow__)) void __mingw_longjmp(jmp_buf _Buf, int _Value);
# elif defined(__SEH__) && !defined(__USE_MINGW_SETJMP_NON_SEH)
#   if defined(__aarch64__) || defined(_ARM64_)
#     define setjmp(BUF) _setjmp((BUF), __builtin_sponentry())
#   elif (__MINGW_GCC_VERSION < 40702) && !defined(__clang__)
#     define setjmp(BUF) _setjmp((BUF), mingw_getsp())
#   else
#     define setjmp(BUF) _setjmp((BUF), __builtin_frame_address (0))
#   endif
# else
#   define setjmp(BUF) _setjmp((BUF), NULL)
# endif
  int __cdecl __attribute__((__nothrow__, __returns_twice__)) _setjmp(jmp_buf _Buf, void *_Ctx);
  int __cdecl __attribute__((__nothrow__, __returns_twice__)) _setjmp3(jmp_buf _Buf, void *_Ctx);
#else
# undef setjmp
# ifdef __SEH__
#   if (__MINGW_GCC_VERSION < 40702) && !defined(__clang__)
#     define setjmp(BUF)   _setjmpex((BUF), mingw_getsp())
#     define setjmpex(BUF) _setjmpex((BUF), mingw_getsp())
#   else
#     define setjmp(BUF)   _setjmpex((BUF), __builtin_frame_address(0))
#     define setjmpex(BUF) _setjmpex((BUF), __builtin_frame_address(0))
#   endif
# else
#   define setjmp(BUF)   _setjmpex((BUF), NULL)
#   define setjmpex(BUF) _setjmpex((BUF), NULL)
# endif
  int __cdecl __attribute__((__nothrow__, __returns_twice__)) _setjmpex(jmp_buf _Buf, void *_Ctx);
#endif

#pragma pop_macro("__has_builtin")

__MINGW_END_C_DECLS

#pragma pack(pop)

#endif  /* _INC_SETJMP */
