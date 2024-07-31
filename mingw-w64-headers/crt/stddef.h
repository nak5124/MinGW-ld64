/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <corecrt.h>

#ifndef _INC_STDDEF
#define _INC_STDDEF

__MINGW_BEGIN_C_DECLS

#ifndef _CRT_ERRNO_DEFINED  /* Also in errno.h and stdlib.h */
# define _CRT_ERRNO_DEFINED
  _CRTIMP int *__cdecl _errno(void);
# define errno (*_errno())
  _CRTIMP errno_t __cdecl _set_errno(int _Value);
  _CRTIMP errno_t __cdecl _get_errno(int *_Value);
#endif  /* _CRT_ERRNO_DEFINED */

  _CRTIMP extern unsigned long __cdecl __threadid(void);
#define _threadid (__threadid())
  _CRTIMP extern uintptr_t __cdecl __threadhandle(void);

__MINGW_END_C_DECLS

#endif  /* _INC_STDDEF */

#undef __need_wchar_t
#undef __need_size_t
#undef __need_ptrdiff_t
#undef __need_NULL
#undef __need_wint_t

#ifndef _STDDEF_H
#define _STDDEF_H

  /* Offset of member MEMBER in a struct of type TYPE. */
#undef offsetof  /* in case a system header has defined it. */
#define offsetof(TYPE, MEMBER) __builtin_offsetof(TYPE, MEMBER)

#if defined(__MINGW_USE_ISOC11) || defined(__MINGW_USE_ISOCXX11)
# if !defined(_GCC_MAX_ALIGN_T) && !defined(__CLANG_MAX_ALIGN_T_DEFINED)
#   define _GCC_MAX_ALIGN_T
#   define __CLANG_MAX_ALIGN_T_DEFINED
    /* Type whose alignment is supported in every context and is at least
      as great as that of any standard type not using alignment specifiers. */
    typedef struct
    {
      long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
      long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
    } max_align_t;
# endif
#endif  /* defined(__MINGW_USE_ISOC11) || defined(__MINGW_USE_ISOCXX11) */

#ifdef __MINGW_USE_ISOCXX11
# ifndef _GXX_NULLPTR_T
#   define _GXX_NULLPTR_T
    typedef decltype(nullptr) nullptr_t;
# endif
#endif  /* __MINGW_USE_ISOCXX11 */

#if defined(__STDC_VERSION__) && __STDC_VERSION__ > 201710L
# ifndef _GCC_NULLPTR_T
#   define _GCC_NULLPTR_T
    typedef __typeof__(nullptr) nullptr_t;
# endif

# define unreachable() (__builtin_unreachable())
# define __STDC_VERSION_STDDEF_H__ 202311L
#endif  /* defined(__STDC_VERSION__) && __STDC_VERSION__ > 201710L */

#endif  /* _STDDEF_H */
