/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _SSP_H_
#define _SSP_H_

#include <corecrt.h>

#undef __MINGW_FORTIFY_VA_ARG
/* If _FORTIFY_SOURCE is enabled, some inline functions may use
 * __builtin_va_arg_pack().  GCC may report an error if the address
 * of such a function is used.  Set _FORTIFY_VA_ARG=0 in this case.
 * Clang doesn't, as of version 19, yet implement __builtin_va_arg_pack().  */
#if __MINGW_FORTIFY_LEVEL > 0 && __has_builtin(__builtin_va_arg_pack) && __has_builtin(__builtin_va_arg_pack_len) \
  && (!defined(_FORTIFY_VA_ARG) || _FORTIFY_VA_ARG > 0)
# define __MINGW_FORTIFY_VA_ARG 1
#else
# define __MINGW_FORTIFY_VA_ARG 0
#endif

#if __MINGW_FORTIFY_LEVEL > 0
# if __MINGW_FORTIFY_LEVEL > 2
#   define __mingw_bos(p, maxtype) __builtin_dynamic_object_size((p), (maxtype) > 0)
#   define __mingw_bos_known(p)    (__builtin_object_size(p, 0) != (size_t)-1 || !__builtin_constant_p(__mingw_bos(p, 0)))
# else
#   define __mingw_bos(p, maxtype) __builtin_object_size((p), ((maxtype) > 0) && (__MINGW_FORTIFY_LEVEL > 1))
#   define __mingw_bos_known(p)    (__mingw_bos(p, 0) != (size_t)-1)
# endif
# define __mingw_bos_cond_chk(c)            (__builtin_expect((c), 1) ? (void)0 : __chk_fail())
# define __mingw_bos_ptr_chk(p, n, maxtype) __mingw_bos_cond_chk(!__mingw_bos_known(p) || __mingw_bos(p, maxtype) >= (size_t)(n))
# define __mingw_bos_ptr_chk_warn(p, n, maxtype)                   \
    ((__mingw_bos_known(p)                                         \
    && __builtin_constant_p(__mingw_bos(p, maxtype) < (size_t)(n)) \
    && __mingw_bos(p, maxtype) < (size_t)(n))                      \
    ? __mingw_chk_fail_warn() : __mingw_bos_ptr_chk(p, n, maxtype))
  /* Calling an function with __attribute__((__warning__("...")))
   * from a system include __inline__ function does not print
   * a warning unless caller has __attribute__((__artificial__)). */
# define __mingw_bos_extern_ovr extern __inline __cdecl __always_inline __gnu_inline __ARTIFICIAL
#endif  /* __MINGW_FORTIFY_LEVEL > 0 */

#ifdef __MINGW_FORTIFY_VA_ARG
# define __va_arg_pack()     __builtin_va_arg_pack()
# define __va_arg_pack_len() __builtin_va_arg_pack_len()
#endif

__MINGW_BEGIN_C_DECLS

#if __MINGW_FORTIFY_LEVEL > 0
  void __cdecl __chk_fail(void) __NORETURN;
  void __cdecl __mingw_chk_fail_warn(void) __ASM_CALL(__chk_fail) __NORETURN __ATTR_WARN("Buffer overflow detected");
#endif

__MINGW_END_C_DECLS

#endif  /* _SSP_H_ */
