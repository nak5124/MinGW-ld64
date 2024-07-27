/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CRTDEFS_MACRO
#define _INC_CRTDEFS_MACRO

#include <_mingw_features.h>

#define __STRINGIFY(x) #x
#define __MINGW64_STRINGIFY(x) __STRINGIFY(x)

#define __MINGW64_VERSION_MAJOR  13
#define __MINGW64_VERSION_MINOR  0
#define __MINGW64_VERSION_BUGFIX 0

/* This macro holds an monotonic increasing value, which indicates
   a specific fix/patch is present on trunk.  This value isn't related to
   minor/major version-macros.  It is increased on demand, if a big
   fix was applied to trunk.  This macro gets just increased on trunk.  For
   other branches its value won't be modified.  */

#define __MINGW64_VERSION_RC 0

#define __MINGW64_VERSION_STR \
  __MINGW64_STRINGIFY(__MINGW64_VERSION_MAJOR) \
  "." \
  __MINGW64_STRINGIFY(__MINGW64_VERSION_MINOR) \
  "." \
  __MINGW64_STRINGIFY(__MINGW64_VERSION_BUGFIX)

#define __MINGW64_VERSION_STATE "alpha"

/* mingw.org's version macros: these make gcc to define
   MINGW32_SUPPORTS_MT_EH and to use the _CRT_MT global
   and the __mingwthr_key_dtor() function from the MinGW
   CRT in its private gthr-win32.h header. */
#define __MINGW32_MAJOR_VERSION 3
#define __MINGW32_MINOR_VERSION 11

/* Set VC specific compiler target macros.  */
#if defined(__x86_64__) && defined(_X86_)
# undef _X86_  /* _X86_ is not for __x86_64__ */
#endif

#ifdef __x86_64__
# define _M_AMD64 100
# define _M_X64   100
# define _AMD64_  1
#endif

#ifdef __aarch64__
# define _M_ARM64 1
# define _ARM64_  1
#endif

#define __MINGW_IMP_SYMBOL(sym)  __imp_##sym
#define __MINGW_IMP_LSYMBOL(sym) __imp_##sym
#define __MINGW_USYMBOL(sym)     sym
#define __MINGW_LSYMBOL(sym)     _##sym

#define __MINGW_ASM_CALL(func)     __asm__(__MINGW64_STRINGIFY(__MINGW_USYMBOL(func)))
#define __MINGW_ASM_CRT_CALL(func) __asm__(__STRINGIFY(func))

#ifndef __PTRDIFF_TYPE__
# define __PTRDIFF_TYPE__ long long int
#endif  /* __PTRDIFF_TYPE__ */

#ifndef __SIZE_TYPE__
# define __SIZE_TYPE__ long long unsigned int
#endif  /* __SIZE_TYPE__ */

#ifndef __WCHAR_TYPE__
# define __WCHAR_TYPE__ unsigned short
#endif

#ifndef __WINT_TYPE__
# define __WINT_TYPE__ unsigned short
#endif

#undef __MINGW_EXTENSION
#ifdef __WIDL__
# define __MINGW_EXTENSION
#else
# define __MINGW_EXTENSION __extension__
#endif  /* __WIDL__ */

/* Special case nameless struct/union.  */
#ifndef __C89_NAMELESS
# define __C89_NAMELESS __MINGW_EXTENSION
# define __C89_NAMELESSSTRUCTNAME
# define __C89_NAMELESSSTRUCTNAME1
# define __C89_NAMELESSSTRUCTNAME2
# define __C89_NAMELESSSTRUCTNAME3
# define __C89_NAMELESSSTRUCTNAME4
# define __C89_NAMELESSSTRUCTNAME5
# define __C89_NAMELESSUNIONNAME
# define __C89_NAMELESSUNIONNAME1
# define __C89_NAMELESSUNIONNAME2
# define __C89_NAMELESSUNIONNAME3
# define __C89_NAMELESSUNIONNAME4
# define __C89_NAMELESSUNIONNAME5
# define __C89_NAMELESSUNIONNAME6
# define __C89_NAMELESSUNIONNAME7
# define __C89_NAMELESSUNIONNAME8
#endif

#ifndef __GNU_EXTENSION
# define __GNU_EXTENSION __MINGW_EXTENSION
#endif

/* MinGW-w64 has some additional C99 printf/scanf feature support.
   So we add some helper macros to ease recognition of them.  */
#define __MINGW_HAVE_ANSI_C99_PRINTF 1
#define __MINGW_HAVE_WIDE_C99_PRINTF 1
#define __MINGW_HAVE_ANSI_C99_SCANF  1
#define __MINGW_HAVE_WIDE_C99_SCANF  1

#ifdef __MINGW_USE_BROKEN_INTERFACE
# define __MINGW_POISON_NAME(__IFACE) __IFACE
#else
# define __MINGW_POISON_NAME(__IFACE) __IFACE##_layout_has_not_been_verified_and_its_declaration_is_most_likely_incorrect
#endif

#ifndef __MSABI_LONG
# define __MSABI_LONG(x) x ## l
#endif  /* __MSABI_LONG */

#define __MINGW_GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

#if __MINGW_GNUC_PREREQ(3, 3)
# define __MINGW_ATTRIB_NONNULL(arg) __attribute__((__nonnull__(arg)))
#else
# define __MINGW_ATTRIB_NONNULL(arg)
#endif

#define __MINGW_ATTRIB_UNUSED __attribute__((__unused__))

#if __MINGW_GNUC_PREREQ(3, 1)
# define __MINGW_ATTRIB_USED       __attribute__((__used__))
# define __MINGW_ATTRIB_DEPRECATED __attribute__((__deprecated__))
# if __MINGW_GNUC_PREREQ(4, 5) || defined(__clang__)
#   define __MINGW_ATTRIB_DEPRECATED_MSG(x) __attribute__((__deprecated__(x)))
# endif
#else
# define __MINGW_ATTRIB_USED
# define __MINGW_ATTRIB_DEPRECATED
#endif

#ifndef __MINGW_ATTRIB_DEPRECATED_MSG
#define __MINGW_ATTRIB_DEPRECATED_MSG(x) __MINGW_ATTRIB_DEPRECATED
#endif

#ifdef __MINGW_MSVC_COMPAT_WARNINGS
# if __MINGW_GNUC_PREREQ(4, 5)
#   define __MINGW_ATTRIB_DEPRECATED_STR(X) __attribute__((__deprecated__(X)))
# else
#   define __MINGW_ATTRIB_DEPRECATED_STR(X) __MINGW_ATTRIB_DEPRECATED
# endif
#else
# define __MINGW_ATTRIB_DEPRECATED_STR(X)
#endif  /* __MINGW_MSVC_COMPAT_WARNINGS */

#define __MINGW_SEC_WARN_STR \
  "This function or variable may be unsafe, use _CRT_SECURE_NO_WARNINGS to disable deprecation"

#define __MINGW_MSVC2005_DEPREC_STR \
  "This POSIX function is deprecated beginning in Visual C++ 2005, use _CRT_NONSTDC_NO_DEPRECATE to disable deprecation"

#ifndef _CRT_NONSTDC_NO_DEPRECATE
# define __MINGW_ATTRIB_DEPRECATED_MSVC2005 __MINGW_ATTRIB_DEPRECATED_STR(__MINGW_MSVC2005_DEPREC_STR)
#else
# define __MINGW_ATTRIB_DEPRECATED_MSVC2005
#endif

#ifndef _CRT_SECURE_NO_WARNINGS
# define __MINGW_ATTRIB_DEPRECATED_SEC_WARN __MINGW_ATTRIB_DEPRECATED_STR(__MINGW_SEC_WARN_STR)
#else
# define __MINGW_ATTRIB_DEPRECATED_SEC_WARN
#endif

#define __MINGW_ATTRIB_NORETURN __attribute__((__noreturn__))
#define __MINGW_ATTRIB_CONST    __attribute__((__const__))

#if __MINGW_GNUC_PREREQ(3, 0)
# define __MINGW_ATTRIB_MALLOC __attribute__((__malloc__))
# define __MINGW_ATTRIB_PURE   __attribute__((__pure__))
#else
# define __MINGW_ATTRIB_MALLOC
# define __MINGW_ATTRIB_PURE
#endif

#if __MINGW_GNUC_PREREQ(3, 3)
# define __MINGW_NOTHROW __attribute__((__nothrow__))
#else
# define __MINGW_NOTHROW
#endif

#if __MINGW_GNUC_PREREQ(4, 4)
# define __MINGW_ATTRIB_NO_OPTIMIZE __attribute__((__optimize__("0")))
#else
# define __MINGW_ATTRIB_NO_OPTIMIZE
#endif

#if __MINGW_GNUC_PREREQ(4, 4)
# define __MINGW_PRAGMA_PARAM(x) _Pragma (#x)
#else
# define __MINGW_PRAGMA_PARAM(x)
#endif

#ifdef __cplusplus
# define __MINGW_BEGIN_C_DECLS extern "C" {
# define __MINGW_END_C_DECLS   }
#else
# define __MINGW_BEGIN_C_DECLS
# define __MINGW_END_C_DECLS
#endif

#ifdef __clang__
# define __MINGW_PRINTF_FORMAT __printf__
# define __MINGW_SCANF_FORMAT  __scanf__
#else
# define __MINGW_PRINTF_FORMAT __gnu_printf__
# define __MINGW_SCANF_FORMAT  __gnu_scanf__
#endif

#define __MINGW_GNU_PRINTF(__format, __args) \
  __attribute__((__format__(__MINGW_PRINTF_FORMAT, __format, __args)))

#define __MINGW_GNU_SCANF(__format, __args) \
  __attribute__((__format__(__MINGW_SCANF_FORMAT, __format, __args)))

#undef __mingw_ovr
#ifdef __cplusplus
# define __mingw_ovr inline __cdecl
#else
# define __mingw_ovr static __attribute__((__unused__)) __inline__ __cdecl
#endif  /* __cplusplus */

#if __MINGW_GNUC_PREREQ(4, 3) || defined(__clang__)
# define __mingw_attribute_artificial __attribute__((__artificial__))
#else
# define __mingw_attribute_artificial
#endif

#define __MINGW_SELECTANY __attribute__((__selectany__))

/* Enable workaround for ABI incompatibility on affected platforms */
#ifndef WIDL_EXPLICIT_AGGREGATE_RETURNS
# ifdef __cplusplus
#   define  WIDL_EXPLICIT_AGGREGATE_RETURNS
# endif
#endif

#endif  /* _INC_CRTDEFS_MACRO */
