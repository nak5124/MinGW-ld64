/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_VADEFS
#define _INC_VADEFS

#include <_mingw.h>

#ifndef __WIDL__
# undef _CRT_PACKING
# define _CRT_PACKING 8
# pragma pack(push, _CRT_PACKING)
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __GNUC__
# ifndef __GNUC_VA_LIST
#   define __GNUC_VA_LIST
    typedef __builtin_va_list __gnuc_va_list;
# endif
#endif  /* __GNUC__ */

#ifndef _VA_LIST_DEFINED  /* if stdargs.h didn't define it */
# define _VA_LIST_DEFINED
# if defined(__GNUC__)
    typedef __gnuc_va_list va_list;
# elif !defined(__WIDL__)
#   error VARARGS not implemented for this compiler
# endif
#endif  /* _VA_LIST_DEFINED */

#ifdef __cplusplus
# define _ADDRESSOF(v) (&reinterpret_cast<const char &>(v))
#else
# define _ADDRESSOF(v) (&(v))
#endif

#ifdef __GNUC__
/* Use GCC builtins */
# define _crt_va_start(v, l) __builtin_va_start(v, l)
# define _crt_va_arg(v, l)   __builtin_va_arg(v, l)
# define _crt_va_end(v)      __builtin_va_end(v)
# define _crt_va_copy(d, s)  __builtin_va_copy(d, s)
#endif  /* __GNUC__ */

#ifdef __cplusplus
}
#endif

#ifndef __WIDL__
#pragma pack(pop)
#endif

#endif  /* _INC_VADEFS */
