/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _INC__MINGW_H
#define _INC__MINGW_H

#include <_mingw_features.h>

#if !defined(__x86_64__) && !defined(__aarch64__) && !defined(__WIDL__)
# error Only x86_64 and aarch64 are supported!
#endif

#ifndef _WIN32
# error Only Win32 target is supported!
#endif

#define __STRING(x)       #x
#define __MINGW_STRING(x) __STRING(x)

/* version number of MinGW-w64 */
#define __MINGW64_VERSION_MAJOR  13
#define __MINGW64_VERSION_MINOR  0
#define __MINGW64_VERSION_BUGFIX 0

#define __MINGW64_VERSION_STR                 \
  __MINGW_STRING(__MINGW64_VERSION_MAJOR) "." \
  __MINGW_STRING(__MINGW64_VERSION_MINOR) "." \
  __MINGW_STRING(__MINGW64_VERSION_BUGFIX)

#define __MINGW64_VERSION_STATE "alpha"

/* mingw.org's version macros: these make gcc to define
 * MINGW32_SUPPORTS_MT_EH and to use the _CRT_MT global
 * and the __mingwthr_key_dtor() function from the MinGW
 * CRT in its private gthr-win32.h header. */
#define __MINGW32_MAJOR_VERSION 3
#define __MINGW32_MINOR_VERSION 11

/* Set VC specific compiler target macros. */
#ifdef __x86_64__
# ifdef _X86_
#   undef _X86_
# endif
# define _M_AMD64 100
# define _M_X64   100
# ifndef _AMD64_
#   define _AMD64_ 1
# endif
#endif

#ifdef __aarch64__
# define _M_ARM64 1
# ifndef _ARM64_
#   define _ARM64_  1
# endif
#endif

#ifdef __arm64ec__
# define _M_ARM64EC 1
# ifndef _ARM64EC_
#   define _ARM64EC_ 1
# endif
#endif

#define __IMP_SYMBOL(sym)  __imp_##sym
#define __IMP_LSYMBOL(sym) __imp_##sym
#define __USYMBOL(sym)     sym
#define __LSYMBOL(sym)     _##sym

#define __ASM_CALL(func)     __asm__(__MINGW_STRING(__USYMBOL(func)))
#define __ASM_CRT_CALL(func) __asm__(__STRING(func))

#undef __MINGW_EXTENSION
#ifdef __WIDL__
# define __MINGW_EXTENSION
#else
# define __MINGW_EXTENSION __extension__
#endif  /* __WIDL__ */

#ifndef __GNU_EXTENSION
# define __GNU_EXTENSION __MINGW_EXTENSION
#endif

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

/* ToDo: Remove these macros */
#ifndef __MSABI_LONG
# define __MSABI_LONG(x) x ## l
#endif  /* __MSABI_LONG */
#define __LONG32 long

/* Attributes */
#ifdef __cplusplus
# if __cplusplus >= 201103L
#   define __NOTHROW noexcept(true)
# else
#   define __NOTHROW throw()
# endif
# define __ASM_CALL_NTH(func)     __NOTHROW __asm__(__MINGW_STRING(__USYMBOL(func)))
# define __ASM_CRT_CALL_NTH(func) __NOTHROW __asm__(__STRING(func))
# define __NTH_FNC(func)          func __NOTHROW
#else
# define __NOTHROW                __attribute__((__nothrow__))
# define __ASM_CALL_NTH(func)     __asm__(__MINGW_STRING(__USYMBOL(func))) __NOTHROW
# define __ASM_CRT_CALL_NTH(func) __asm__(__STRING(func)) __NOTHROW
# define __NTH_FNC(func)          __NOTHROW func
#endif

#define __COLD __attribute__((__cold__))

#define __ATTR_MALLOC      __attribute__((__malloc__))
#define __ALLOC_SIZE(args) __attribute__((__alloc_size__ args))

#define __PURE  __attribute__((__pure__))
#define __CONST __attribute__((__const__))

#define __ATTR_UNUSED __attribute__((__unused__))
#ifdef __cplusplus
# define __UNUSED_PARAM(x)
#else
# define __UNUSED_PARAM(x) x __ATTR_UNUSED
#endif
#define __ATTR_USED __attribute__((__used__))
#define __NOINLINE  __attribute__((__noinline__))

#define __ATTR_DEPRECATED          __attribute__((__deprecated__))
#define __ATTR_DEPRECATED_MSG(msg) __attribute__((__deprecated__(msg)))

#ifdef __MINGW_MSVC_COMPAT_WARNINGS
# define __MINGW_DEPRECATED_MSG(msg) __ATTR_DEPRECATED_MSG(msg)
#else
# define __MINGW_DEPRECATED_MSG(msg)
#endif  /* __MINGW_MSVC_COMPAT_WARNINGS */

#define __MINGW_MSVC2005_DEPREC_STR \
  "This POSIX function is deprecated beginning in Visual C++ 2005, use _CRT_NONSTDC_NO_DEPRECATE to disable deprecation"

#define __MINGW_SEC_WARN_STR \
  "This function or variable may be unsafe, use _CRT_SECURE_NO_WARNINGS to disable deprecation"

#ifndef _CRT_NONSTDC_NO_DEPRECATE
# define __MINGW_DEPRECATED_MSVC2005 __MINGW_DEPRECATED_MSG(__MINGW_MSVC2005_DEPREC_STR)
#else
# define __MINGW_DEPRECATED_MSVC2005
#endif

#ifndef _CRT_SECURE_NO_WARNINGS
# define __MINGW_DEPRECATED_SEC_WARN __MINGW_DEPRECATED_MSG(__MINGW_SEC_WARN_STR)
#else
# define __MINGW_DEPRECATED_SEC_WARN
#endif

#define __ATTR_WARN(msg) __attribute__((__warning__(msg)))

#define __NONNULL(args) __attribute__((__nonnull__ args))

#define __WUR __attribute__((__warn_unused_result__))
#if defined(__MINGW_FORTIFY_LEVEL) && __MINGW_FORTIFY_LEVEL > 0
# define __WUR_FORTIFY __WUR
#else
# define __WUR_FORTIFY
#endif

#define __ARTIFICIAL __attribute__((__artificial__))

#ifndef __cplusplus
# define __restrict_arr __restrict
#else
# define __restrict_arr
#endif

#define __mingw_unlikely(cond) __builtin_expect((cond), 0)
#define __mingw_likely(cond)   __builtin_expect((cond), 1)

#define __NORETURN __attribute__((__noreturn__))

#define __ATTR_ACCESS(args) __attribute__((__access__ args))
#if defined(__MINGW_FORTIFY_LEVEL) && __MINGW_FORTIFY_LEVEL > 2
# define __ATTR_ACCESS_FORTIFY(amode, refi, sizei)
#else
# define __ATTR_ACCESS_FORTIFY(amode, refi, sizei) __ATTR_ACCESS((amode, refi, sizei))
#endif

#define __ATTR_DEALLOC(dealloc, argno) __attribute__((__malloc__(dealloc, argno)))
#define __ATTR_DEALLOC_FREE            __ATTR_DEALLOC(__builtin_free, 1)

#define __RETURNS_TWICE __attribute__((__returns_twice__))

#define __NO_OPTIMIZE __attribute__((__optimize__("O0")))

#define __SELECTANY __attribute__((__selectany__))

#ifdef __clang__
# define __MINGW_PRINTF_FORMAT   __printf__
# define __MINGW_SCANF_FORMAT    __scanf__
# define __MINGW_STRFTIME_FORMAT __strftime__
#else
# define __MINGW_PRINTF_FORMAT   __gnu_printf__
# define __MINGW_SCANF_FORMAT    __gnu_scanf__
# define __MINGW_STRFTIME_FORMAT __gnu_strftime__
#endif

#define __MINGW_GNU_PRINTF(__format, __args) \
  __attribute__((__format__(__MINGW_PRINTF_FORMAT, __format, __args)))

#define __MINGW_GNU_SCANF(__format, __args) \
  __attribute__((__format__(__MINGW_SCANF_FORMAT, __format, __args)))

#define __MINGW_GNU_STRFTIME(__format, __args) \
  __attribute__((__format__(__MINGW_STRFTIME_FORMAT, __format, __args)))

#define __ALIAS(fnc)         __attribute__((__alias__(__STRING(fnc))))
#define __ALIAS_IMP_SYM(sym) __attribute__((__alias__(__MINGW_STRING(__IMP_SYMBOL(sym)))))

/* inline function-related macros */
#ifndef _inline
# define _inline __inline
#endif

#define __always_inline __attribute__((__always_inline__))
#define __gnu_inline    __attribute__((__gnu_inline__))

#undef __mingw_ovr
#ifdef __cplusplus
# define __mingw_ovr inline __cdecl
#else
# define __mingw_ovr static __ATTR_UNUSED __inline __cdecl
#endif

#undef __CRT_INLINE
#ifdef __cplusplus
# define __CRT_INLINE inline
#else
# if defined(__STDC_VERSION__) && (__STDC_VERSION__ - 0) >= 199901L
#   define __CRT_INLINE extern inline __gnu_inline
# else
#   define __CRT_INLINE extern __inline
# endif
#endif

#ifndef __MINGW_INTRIN_INLINE
# define __MINGW_INTRIN_INLINE extern __inline __always_inline __gnu_inline
#endif

#ifdef __NO_INLINE__
# undef  __CRT__NO_INLINE
# define __CRT__NO_INLINE 1
#endif

#ifdef __cplusplus
# define __forceinline inline __always_inline
#else
# define __forceinline extern __inline __always_inline __gnu_inline
#endif

/* Enable workaround for ABI incompatibility on affected platforms */
#ifndef WIDL_EXPLICIT_AGGREGATE_RETURNS
# ifdef __cplusplus
#   define  WIDL_EXPLICIT_AGGREGATE_RETURNS
# endif
#endif

/* Recent MSVC supports C++14 but it doesn't define __cplusplus accordingly.  */
#define __MINGW_CXX11_CONSTEXPR
#define __MINGW_CXX14_CONSTEXPR
#ifdef __cplusplus
# if __cplusplus >= 201103L
#  undef __MINGW_CXX11_CONSTEXPR
#  define __MINGW_CXX11_CONSTEXPR constexpr
# endif
# if __cplusplus >= 201402L
#  undef __MINGW_CXX14_CONSTEXPR
#  define __MINGW_CXX14_CONSTEXPR constexpr
# endif
#endif

/* MSVC defines _NATIVE_NULLPTR_SUPPORTED when nullptr is supported. We emulate it here for GCC. */
#ifdef __MINGW_USE_ISOCXX11
# define _NATIVE_NULLPTR_SUPPORTED
#endif

/* for backward compatibility */
#ifndef MINGW_HAS_SECURE_API
# define MINGW_HAS_SECURE_API 1
#endif

#ifndef __MSVCRT_VERSION__
/*  High byte is the major version, low byte is the minor. */
# define __MSVCRT_VERSION__ 0xE00
#endif

#ifndef _WIN32_WINNT
# define _WIN32_WINNT 0x0A00
#endif

/* We have to define _DLL for gcc based mingw version. This define is set
 * by VC, when DLL-based runtime is used. So, gcc based runtime just have
 * DLL-base runtime, therefore this define has to be set.
 * As our headers are possibly used by windows compiler having a static
 * C-runtime, we make this definition gnu compiler specific here.  */
#ifndef _DLL
# define _DLL
#endif

#ifndef _MT
# define _MT
#endif

/* _dowildcard is an int that controls the globbing of the command line.
 * The MinGW32 (mingw.org) runtime calls it _CRT_glob, so we are adding
 * a compatibility definition here:  you can use either of _CRT_glob or
 * _dowildcard .
 * If _dowildcard is non-zero, the command line will be globbed:  *.*
 * will be expanded to be all files in the startup directory.
 * In the mingw-w64 library a _dowildcard variable is defined as being
 * 0, therefore command line globbing is DISABLED by default. To turn it
 * on and to leave wildcard command line processing MS's globbing code,
 * include a line in one of your source modules defining _dowildcard and
 * setting it to -1, like so:
 * int _dowildcard = -1;
 */
#undef  _CRT_glob
#define _CRT_glob _dowildcard

#ifndef _UCRT
# define _UCRT
#endif

/* C/C++ specific language defines.  */
#ifndef __MINGW_IMPORT
# define __MINGW_IMPORT extern __attribute__((__dllimport__))
#endif
#ifndef _CRTIMP
# undef __USE_CRTIMP
# if !defined(_CRTBLD) && !defined(_SYSCRT)
#   define __USE_CRTIMP 1
# endif
# ifdef __USE_CRTIMP
#   define _CRTIMP __attribute__((__dllimport__))
# else
#   define _CRTIMP
# endif
#endif
#define __DECLSPEC_SUPPORTED

#ifndef __CRTDECL
# ifndef __cplusplus
#   define __CRTDECL __cdecl __ATTR_UNUSED
# else
#   define __CRTDECL __cdecl
# endif
#endif

#undef  _CRT_PACKING
#define _CRT_PACKING 8
#ifdef __cplusplus
# define __MINGW_BEGIN_C_DECLS                        \
    _Pragma(__MINGW_STRING(pack(push, _CRT_PACKING))) \
    extern "C" {
# define __MINGW_END_C_DECLS     \
    }                            \
    _Pragma(__STRING(pack(pop)))
#else
# define __MINGW_BEGIN_C_DECLS _Pragma(__MINGW_STRING(pack(push, _CRT_PACKING)))
# define __MINGW_END_C_DECLS   _Pragma(__STRING(pack(pop)))
#endif

#ifndef _HAS_EXCEPTIONS
# define _HAS_EXCEPTIONS 1
#endif

#define _CRT_STRINGIZE_(_Value) #_Value
#define _CRT_STRINGIZE(_Value)  _CRT_STRINGIZE_(_Value)

#define _CRT_WIDE_(_String) L ## _String
#define _CRT_WIDE(_String)  _CRT_WIDE_(_String)

#define _CRT_CONCATENATE_(a, b) a ## b
#define _CRT_CONCATENATE(a, b)  _CRT_CONCATENATE_(a, b)

#define _CRT_UNPARENTHESIZE_(...) __VA_ARGS__
#define _CRT_UNPARENTHESIZE(...)  _CRT_UNPARENTHESIZE_ __VA_ARGS__

#define __MINGW_BROKEN_INTERFACE(x) __MINGW_PRAGMA_PARAM(message ("Interface " _CRT_STRINGIZE(x) " has unverified layout."))

/* MSVC compability */
#define _VCRTIMP _CRTIMP
#define _MRTIMP

/* Microsoft-specific sized integer types */
#define __int8  char
#define __int16 short
#define __int32 int
#define __int64 long long

#define __ptr32
#define __ptr64
#ifndef __unaligned
# define __unaligned
#endif
#ifndef __w64
# define __w64
#endif

#ifndef __WIDL__
# ifndef _UNALIGNED
#   define _UNALIGNED __unaligned
#   define  UNALIGNED _UNALIGNED
# endif  /* _UNALIGNED */
#endif  /* __WIDL__ */

#define _CRT_DEPRECATE_TEXT(_Text) __ATTR_DEPRECATED_MSG(_Text)

#if defined(_CRT_SECURE_NO_DEPRECATE) && !defined(_CRT_SECURE_NO_WARNINGS)
# define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef _CRT_INSECURE_DEPRECATE
# ifdef _CRT_SECURE_NO_WARNINGS
#   define _CRT_INSECURE_DEPRECATE(_Replacement)
# else
#   define _CRT_INSECURE_DEPRECATE(_Replacement) _CRT_DEPRECATE_TEXT(   \
      "This function or variable may be unsafe. Consider using "        \
      #_Replacement                                                     \
      " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. " \
      "See online help for details.")
# endif
#endif

#if defined(_CRT_SECURE_DEPRECATE_MEMORY) && !defined(_CRT_SECURE_WARNINGS_MEMORY)
# define _CRT_SECURE_WARNINGS_MEMORY
#endif

#ifndef _CRT_INSECURE_DEPRECATE_MEMORY
# ifndef _CRT_SECURE_WARNINGS_MEMORY
#   define _CRT_INSECURE_DEPRECATE_MEMORY(_Replacement)
# else
#   define _CRT_INSECURE_DEPRECATE_MEMORY(_Replacement) _CRT_INSECURE_DEPRECATE(_Replacement)
# endif
#endif

#if defined(NONAMELESSSTRUCT) && !defined(NONAMELESSUNION)
# define NONAMELESSUNION 1
#endif
#if defined(NONAMELESSUNION) && !defined(NONAMELESSSTRUCT)
# define NONAMELESSSTRUCT 1
#endif

#ifndef __ANONYMOUS_DEFINED
# define __ANONYMOUS_DEFINED
# define _ANONYMOUS_UNION  __MINGW_EXTENSION
# define _ANONYMOUS_STRUCT __MINGW_EXTENSION
# ifndef NONAMELESSUNION
#   define _UNION_NAME(x)
#   define _STRUCT_NAME(x)
# else
#   define _UNION_NAME(x)  x
#   define _STRUCT_NAME(x) x
# endif
#endif  /* __ANONYMOUS_DEFINED */

#ifndef DUMMYUNIONNAME
# ifdef NONAMELESSUNION
#   define DUMMYUNIONNAME  u
#   define DUMMYUNIONNAME1 u1  /* Wine uses this variant */
#   define DUMMYUNIONNAME2 u2
#   define DUMMYUNIONNAME3 u3
#   define DUMMYUNIONNAME4 u4
#   define DUMMYUNIONNAME5 u5
#   define DUMMYUNIONNAME6 u6
#   define DUMMYUNIONNAME7 u7
#   define DUMMYUNIONNAME8 u8
#   define DUMMYUNIONNAME9 u9
# else
#   define DUMMYUNIONNAME
#   define DUMMYUNIONNAME1  /* Wine uses this variant */
#   define DUMMYUNIONNAME2
#   define DUMMYUNIONNAME3
#   define DUMMYUNIONNAME4
#   define DUMMYUNIONNAME5
#   define DUMMYUNIONNAME6
#   define DUMMYUNIONNAME7
#   define DUMMYUNIONNAME8
#   define DUMMYUNIONNAME9
# endif
#endif  /* DUMMYUNIONNAME */

#ifndef DUMMYSTRUCTNAME
# ifdef NONAMELESSUNION
#   define DUMMYSTRUCTNAME  s
#   define DUMMYSTRUCTNAME1 s1  /* Wine uses this variant */
#   define DUMMYSTRUCTNAME2 s2
#   define DUMMYSTRUCTNAME3 s3
#   define DUMMYSTRUCTNAME4 s4
#   define DUMMYSTRUCTNAME5 s5
#   define DUMMYSTRUCTNAME6 s6
# else
#   define DUMMYSTRUCTNAME
#   define DUMMYSTRUCTNAME1  /* Wine uses this variant */
#   define DUMMYSTRUCTNAME2
#   define DUMMYSTRUCTNAME3
#   define DUMMYSTRUCTNAME4
#   define DUMMYSTRUCTNAME5
#   define DUMMYSTRUCTNAME6
# endif
#endif  /* DUMMYSTRUCTNAME */

#define USE___UUIDOF 0

/* Macros for __uuidof template-based emulation */
#if defined(__cplusplus) && (USE___UUIDOF == 0)

#if __cpp_constexpr >= 200704l && __cpp_inline_variables >= 201606L
# define __CRT_UUID_DECL(type, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
    extern "C++"                                                          \
    {                                                                     \
      template<> struct __mingw_uuidof_s<type>                            \
      {                                                                   \
        static constexpr IID __uuid_inst = {                              \
          l, w1, w2, {b1, b2, b3, b4, b5, b6, b7, b8}                     \
        };                                                                \
      };                                                                  \
      template<> constexpr const GUID &__mingw_uuidof<type>()             \
      {                                                                   \
        return __mingw_uuidof_s<type>::__uuid_inst;                       \
      }                                                                   \
      template<> constexpr const GUID &__mingw_uuidof<type*>()            \
      {                                                                   \
        return  __mingw_uuidof_s<type>::__uuid_inst;                      \
      }                                                                   \
    }
#else
# define __CRT_UUID_DECL(type, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
    extern "C++"                                                          \
    {                                                                     \
      template<> inline const GUID &__mingw_uuidof<type>()                \
      {                                                                   \
        static const IID __uuid_inst = {                                  \
          l, w1, w2, {b1, b2, b3, b4, b5, b6, b7, b8}                     \
        };                                                                \
        return __uuid_inst;                                               \
      }                                                                   \
      template<> inline const GUID &__mingw_uuidof<type*>()               \
      {                                                                   \
        return __mingw_uuidof<type>();                                    \
      }                                                                   \
    }
#endif  /* __cpp_constexpr >= 200704l && __cpp_inline_variables >= 201606L */

#define __uuidof(type) __mingw_uuidof<__typeof(type)>()

#else

#define __CRT_UUID_DECL(type, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8)

#endif  /* defined(__cplusplus) && (USE___UUIDOF == 0) */

__MINGW_BEGIN_C_DECLS

#ifndef _SIZE_T_DEFINED
# define _SIZE_T_DEFINED
# undef size_t
  __MINGW_EXTENSION typedef unsigned __int64 size_t;
#endif  /* _SIZE_T_DEFINED */

#ifndef _PTRDIFF_T_DEFINED
# define _PTRDIFF_T_DEFINED
# ifndef _PTRDIFF_T_
#   define _PTRDIFF_T_
#   undef ptrdiff_t
    __MINGW_EXTENSION typedef __int64 ptrdiff_t;
# endif  /* _PTRDIFF_T_ */
#endif  /* _PTRDIFF_T_DEFINED */

#ifndef _INTPTR_T_DEFINED
# define _INTPTR_T_DEFINED
# ifndef __intptr_t_defined
#   define __intptr_t_defined
#   undef intptr_t
    __MINGW_EXTENSION typedef __int64 intptr_t;
# endif  /* __intptr_t_defined */
#endif  /* _INTPTR_T_DEFINED */

#ifndef _WCHAR_T_DEFINED
# define _WCHAR_T_DEFINED
# if !defined(__cplusplus) && !defined(__WIDL__)
    typedef unsigned short wchar_t;
# endif  /* !defined(__cplusplus) && !defined(__WIDL__) */
#endif  /* _WCHAR_T_DEFINED */

#ifndef __ASSEMBLER__

#ifdef __MINGW_INTRIN_INLINE

#define __MINGW_DEBUGBREAK_IMPL !__has_builtin(__debugbreak)
#if __MINGW_DEBUGBREAK_IMPL
  void __cdecl __debugbreak(void);
  __MINGW_INTRIN_INLINE
  void __cdecl __debugbreak(void)
  {
#if defined(__aarch64__) || defined(__arm64ec__)
    __asm__ __volatile__("brk #0xf000");
#elif defined(__x86_64__)
    __asm__ __volatile__("int {$}3":);
#else
    __asm__ __volatile__("unimplemented");
#endif
}
#endif  /* __MINGW_DEBUGBREAK_IMPL */

#define __MINGW_FASTFAIL_IMPL !__has_builtin(__fastfail)
#if __MINGW_FASTFAIL_IMPL
  void __cdecl __fastfail(unsigned int __code) __NORETURN;
  __MINGW_INTRIN_INLINE __NORETURN
  void __cdecl __fastfail(unsigned int __code)
  {
#if defined(__aarch64__) || defined(__arm64ec__)
    register unsigned int w0 __asm__("w0") = __code;
    __asm__ __volatile__("brk #0xf003" : : "r"(w0));
#elif defined(__x86_64__)
    __asm__ __volatile__("int {$}0x29" : : "c"(__code));
#else
    __asm__ __volatile__("unimplemented");
#endif
    __builtin_unreachable();
  }
#endif  /* __MINGW_FASTFAIL_IMPL */

#define __MINGW_PREFETCH_IMPL !__has_builtin(__prefetch)
#if __MINGW_PREFETCH_IMPL && (defined(__aarch64__) || defined(__arm64ec__))
  void __cdecl __prefetch(const void *__addr);
  __MINGW_INTRIN_INLINE void __cdecl __prefetch(const void *__addr)
  {
    __asm__ __volatile__("prfm pldl1keep, [%0]"::"r"(__addr));
  }
#endif  /* __MINGW_PREFETCH_IMPL && defined(__aarch64__) */

#endif  /* __MINGW_INTRIN_INLINE */

/* mingw-w64 specific functions: */
  const char *__mingw_get_crt_info(void);

#endif  /* __ASSEMBLER__ */

__MINGW_END_C_DECLS

#endif  /* _INC__MINGW_H */

#ifndef MINGW_SDK_INIT
#define MINGW_SDK_INIT

#ifndef __WIDL__
# include <sdks/_mingw_ddk.h>
#endif

#endif  /* MINGW_SDK_INIT */
