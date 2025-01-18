/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_VADEFS
#define _INC_VADEFS

#include <_mingw.h>

__MINGW_BEGIN_C_DECLS

#ifndef _W64
# define _W64
#endif

#ifndef _UINTPTR_T_DEFINED
# define _UINTPTR_T_DEFINED
# ifndef __uintptr_t_defined
#   define __uintptr_t_defined
#   undef uintptr_t
    __MINGW_EXTENSION typedef unsigned __int64 uintptr_t;
# endif  /* __uintptr_t_defined */
#endif  /* _UINTPTR_T_DEFINED */

#ifndef __GNUC_VA_LIST
# define __GNUC_VA_LIST
  typedef __builtin_va_list __gnuc_va_list;
#endif

#ifndef _VA_LIST_DEFINED  /* Also in stdarg.h */
# define _VA_LIST_DEFINED
  typedef __gnuc_va_list va_list;
#endif  /* _VA_LIST_DEFINED */

#ifdef __cplusplus
# define _ADDRESSOF(v) (&reinterpret_cast<const char &>(v))
#else
# define _ADDRESSOF(v) (&(v))
#endif

#if defined(__aarch64__) || defined(__arm64ec__)
# define _VA_ALIGN       8
# define _SLOTSIZEOF(t)  ((sizeof(t) + _VA_ALIGN - 1) & ~(_VA_ALIGN - 1))
# define _APALIGN(t, ap) (((va_list)0 - (ap)) & (__alignof(t) - 1))
#else
# define _SLOTSIZEOF(t)  (sizeof(t))
# define _APALIGN(t, ap) (__alignof(t))
#endif

/* Use GCC builtins */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ > 201710L
# define __crt_va_start(v, ...) __builtin_va_start(v, 0)
#else
# define __crt_va_start(v, l)   __builtin_va_start(v, l)
#endif
#define __crt_va_arg(v, l)  __builtin_va_arg(v, l)
#define __crt_va_end(v)     __builtin_va_end(v)
#define __crt_va_copy(d, s) __builtin_va_copy(d, s)

__MINGW_END_C_DECLS

#endif  /* _INC_VADEFS */
