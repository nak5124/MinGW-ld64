/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _INC__MINGW_H
#define _INC__MINGW_H

#ifndef __WIDL__
# ifndef __GNUC__
#   error Only GNU compatible compilers are supported!
# endif
# if !defined(__x86_64__) && !defined(__aarch64__)
#   error Only x86_64 and aarch64 are supported!
# endif
#endif

#ifndef _WIN32
# error Only Win32 target is supported!
#endif

#include <_mingw_mac.h>

#define __LONG32 long

/* C/C++ specific language defines.  */
#ifdef __declspec
#  ifndef __MINGW_IMPORT
/* Note the extern. This is needed to work around GCC's
limitations in handling dllimport attribute.  */
#    define __MINGW_IMPORT extern __attribute__((__dllimport__))
#  endif
#  ifndef _CRTIMP
#    undef __USE_CRTIMP
#    if !defined(_CRTBLD) && !defined(_SYSCRT)
#      define __USE_CRTIMP 1
#    endif
#    ifdef __USE_CRTIMP
#      define _CRTIMP __attribute__((__dllimport__))
#    else
#      define _CRTIMP
#    endif
#  endif
#  define __DECLSPEC_SUPPORTED
#else
# undef __DECLSPEC_SUPPORTED
# undef __MINGW_IMPORT
# ifndef _CRTIMP
#   define _CRTIMP
# endif
#endif  /* __declspec */

#ifndef _LDCRTIMP
# if defined(__aarch64__) || defined(_ARM64_)
#   define _LDCRTIMP _CRTIMP
# else
#   define _LDCRTIMP extern
# endif
#endif

#define USE___UUIDOF 0

#ifndef _inline
# define _inline __inline
#endif

#ifdef __cplusplus
# define __CRT_INLINE inline
#else
# if ((__MINGW_GNUC_PREREQ(4, 3) || defined(__clang__)) && __STDC_VERSION__ >= 199901L)
#   define __CRT_INLINE extern inline __attribute__((__gnu_inline__))
# else
#   define __CRT_INLINE extern __inline__
# endif
#endif

#ifndef __MINGW_INTRIN_INLINE
# define __MINGW_INTRIN_INLINE extern __inline__ __attribute__((__always_inline__, __gnu_inline__))
#endif

#ifdef __NO_INLINE__
# undef  __CRT__NO_INLINE
# define __CRT__NO_INLINE 1
#endif

#ifdef __cplusplus
# define __UNUSED_PARAM(x)
#else
# define __UNUSED_PARAM(x) x __MINGW_UNUSED
#endif

#if __MINGW_GNUC_PREREQ(3, 1) && !defined(__cplusplus)
# define __restrict_arr __restrict
#else
# define __restrict_arr
#endif

#ifndef _CRT_STRINGIZE
# define __CRT_STRINGIZE(_Value) #_Value
# define  _CRT_STRINGIZE(_Value) __CRT_STRINGIZE(_Value)
#endif  /* _CRT_STRINGIZE */

#ifndef _CRT_WIDE
# define __CRT_WIDE(_String) L ## _String
# define  _CRT_WIDE(_String) __CRT_WIDE(_String)
#endif  /* _CRT_WIDE */

#define __MINGW_BROKEN_INTERFACE(x) \
  __MINGW_PRAGMA_PARAM(message ("Interface " _CRT_STRINGIZE(x) " has unverified layout."))

#ifndef __MSVCRT_VERSION__
/*  High byte is the major version, low byte is the minor. */
# define __MSVCRT_VERSION__ 0xE00
#endif

#ifndef _WIN32_WINNT
# define _WIN32_WINNT 0x0A00
#endif

#ifndef _INT128_DEFINED
# define _INT128_DEFINED
# define __int8  char
# define __int16 short
# define __int32 int
# define __int64 long long
# if __mingw_clang_prereq(3, 1) && !defined(__SIZEOF_INT128__)
    /* clang >= 3.1 has __int128 but no size macro */
#   define __SIZEOF_INT128__ 16
# endif
# ifndef __SIZEOF_INT128__
    typedef int __int128 __attribute__((__mode__(TI)));
# endif
#endif  /* _INT128_DEFINED */

#define __ptr32
#define __ptr64
#ifndef __unaligned
# define __unaligned
#endif
#ifndef __w64
# define __w64
#endif
#ifdef __cplusplus
# define __forceinline inline __attribute__((__always_inline__))
#else
# define __forceinline extern __inline__ __attribute__((__always_inline__, __gnu_inline__))
#endif  /* __cplusplus */

#ifndef __nothrow
# ifdef __cplusplus
#   define __nothrow __MINGW_NOTHROW
# else
#   define __nothrow
# endif
#endif  /* __nothrow */

#ifndef _W64
# define _W64
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

#define _CRT_DEPRECATE_TEXT(_Text) __MINGW_DEPRECATED_MSG(_Text)

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

#ifndef _CRT_INSECURE_DEPRECATE_GLOBALS
# ifdef _CRT_SECURE_NO_WARNINGS_GLOBALS
#   define _CRT_INSECURE_DEPRECATE_GLOBALS(replacement)
# else
#   define _CRT_INSECURE_DEPRECATE_GLOBALS(replacement) _CRT_INSECURE_DEPRECATE(replacement)
# endif
#endif

#if defined(_CRT_MANAGED_HEAP_NO_DEPRECATE) && !defined(_CRT_MANAGED_HEAP_NO_WARNINGS)
# define _CRT_MANAGED_HEAP_NO_WARNINGS
#endif

#define _SECURECRT_FILL_BUFFER_PATTERN 0xFE

#if defined(_CRT_OBSOLETE_NO_DEPRECATE) && !defined(_CRT_OBSOLETE_NO_WARNINGS)
# define _CRT_OBSOLETE_NO_WARNINGS
#endif

#ifndef _CRT_OBSOLETE
# ifdef _CRT_OBSOLETE_NO_WARNINGS
#   define _CRT_OBSOLETE(_NewItem)
# else
#   define _CRT_OBSOLETE(_NewItem) _CRT_DEPRECATE_TEXT(                  \
      "This function or variable has been superceded by newer library "  \
      "or operating system functionality. Consider using " #_NewItem " " \
      "instead. See online help for details.")
# endif
#endif

/* MSVC defines _NATIVE_NULLPTR_SUPPORTED when nullptr is supported. We emulate it here for GCC. */
#if __MINGW_GNUC_PREREQ(4, 6) && defined(__MINGW_USE_ISOCXX11)
# define _NATIVE_NULLPTR_SUPPORTED
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
#  define DUMMYUNIONNAME  u
#  define DUMMYUNIONNAME1 u1  /* Wine uses this variant */
#  define DUMMYUNIONNAME2 u2
#  define DUMMYUNIONNAME3 u3
#  define DUMMYUNIONNAME4 u4
#  define DUMMYUNIONNAME5 u5
#  define DUMMYUNIONNAME6 u6
#  define DUMMYUNIONNAME7 u7
#  define DUMMYUNIONNAME8 u8
#  define DUMMYUNIONNAME9 u9
# else
#  define DUMMYUNIONNAME
#  define DUMMYUNIONNAME1  /* Wine uses this variant */
#  define DUMMYUNIONNAME2
#  define DUMMYUNIONNAME3
#  define DUMMYUNIONNAME4
#  define DUMMYUNIONNAME5
#  define DUMMYUNIONNAME6
#  define DUMMYUNIONNAME7
#  define DUMMYUNIONNAME8
#  define DUMMYUNIONNAME9
# endif
#endif  /* DUMMYUNIONNAME */

#ifndef DUMMYSTRUCTNAME
# ifdef NONAMELESSUNION
#  define DUMMYSTRUCTNAME  s
#  define DUMMYSTRUCTNAME1 s1  /* Wine uses this variant */
#  define DUMMYSTRUCTNAME2 s2
#  define DUMMYSTRUCTNAME3 s3
#  define DUMMYSTRUCTNAME4 s4
#  define DUMMYSTRUCTNAME5 s5
# else
#  define DUMMYSTRUCTNAME
#  define DUMMYSTRUCTNAME1  /* Wine uses this variant */
#  define DUMMYSTRUCTNAME2
#  define DUMMYSTRUCTNAME3
#  define DUMMYSTRUCTNAME4
#  define DUMMYSTRUCTNAME5
# endif
#endif  /* DUMMYSTRUCTNAME */


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

#ifdef __MINGW_INTRIN_INLINE

#ifdef __has_builtin
# define __MINGW_DEBUGBREAK_IMPL !__has_builtin(__debugbreak)
#else
# define __MINGW_DEBUGBREAK_IMPL 1
#endif  /* __has_builtin */
#if __MINGW_DEBUGBREAK_IMPL == 1
  void __cdecl __debugbreak(void);
  __MINGW_INTRIN_INLINE void __cdecl __debugbreak(void)
  {
#ifdef __x86_64__
    __asm__ __volatile__("int {$}3":);
#elif defined(__aarch64__)
    __asm__ __volatile__("brk #0xf000");
#else
    __asm__ __volatile__("unimplemented");
#endif  /* __x86_64__ */
}
#endif  /* __MINGW_DEBUGBREAK_IMPL == 1 */

#ifdef __has_builtin
# define __MINGW_FASTFAIL_IMPL !__has_builtin(__fastfail)
#else
# define __MINGW_FASTFAIL_IMPL 1
#endif  /* __has_builtin */
#if __MINGW_FASTFAIL_IMPL == 1
  void __cdecl __fastfail(unsigned int __code) __MINGW_NORETURN;
  __MINGW_INTRIN_INLINE __MINGW_NORETURN
  void __cdecl __fastfail(unsigned int __code)
  {
#ifdef __x86_64__
    __asm__ __volatile__("int {$}0x29"::"c"(__code));
#elif defined(__aarch64__)
    register unsigned int __w0 __asm__("__w0") = __code;
    __asm__ __volatile__("brk #0xf003"::"r"(__w0));
#else
    __asm__ __volatile__("unimplemented");
#endif  /* __x86_64__ */
    __builtin_unreachable();
  }
#endif  /* __MINGW_FASTFAIL_IMPL == 1 */

#ifdef __has_builtin
# define __MINGW_PREFETCH_IMPL !__has_builtin(__prefetch)
#else
# define __MINGW_PREFETCH_IMPL 1
#endif  /* __has_builtin */
#if __MINGW_PREFETCH_IMPL == 1 && defined(__aarch64__)
  void __cdecl __prefetch(const void *__addr);
  __MINGW_INTRIN_INLINE void __cdecl __prefetch(const void *__addr)
  {
    __asm__ __volatile__("prfm pldl1keep, [%0]"::"r"(__addr));
  }
#endif  /* __MINGW_PREFETCH_IMPL == 1 && defined(__aarch64__) */

#endif  /* __MINGW_INTRIN_INLINE */

/* mingw-w64 specific functions: */
  const char *__mingw_get_crt_info(void);

#if __MINGW_FORTIFY_LEVEL > 0
  /* Calling an function with __attribute__((__warning__("...")))
   * from a system include __inline__ function does not print
   * a warning unless caller has __attribute__((__artificial__)). */
# define __mingw_bos_declare                                                  \
    void __cdecl __chk_fail(void) __MINGW_NORETURN;                           \
    void __cdecl __mingw_chk_fail_warn(void) __MINGW_ASM_CALL(__chk_fail)     \
    __MINGW_NORETURN __attribute__((__warning__("Buffer overflow detected")))
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
# define __mingw_bos_ovr __mingw_ovr __attribute__((__always_inline__)) __MINGW_ARTIFICIAL
# define __mingw_bos_extern_ovr \
    extern __inline__ __cdecl __attribute__((__always_inline__, __gnu_inline__)) __MINGW_ARTIFICIAL
#else
# define __mingw_bos_ovr __mingw_ovr
#endif  /* __MINGW_FORTIFY_LEVEL > 0 */

/* for backward compatibility */
#ifndef MINGW_HAS_SECURE_API
# define MINGW_HAS_SECURE_API 1
#endif

#define __STDC_SECURE_LIB__ 200411L
#define __GOT_SECURE_LIB__  __STDC_SECURE_LIB__

__MINGW_END_C_DECLS

#endif  /* _INC__MINGW_H */

#ifndef MINGW_SDK_INIT
#define MINGW_SDK_INIT

#ifndef __WIDL__
#include <sdks/_mingw_ddk.h>
#endif

#endif  /* MINGW_SDK_INIT */
