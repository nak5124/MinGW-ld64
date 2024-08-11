/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _INC_CORECRT
#define _INC_CORECRT

#ifndef _UCRT
# define _UCRT
#endif

#include <vadefs.h>

__MINGW_BEGIN_C_DECLS

#ifndef _HAS_EXCEPTIONS
# define _HAS_EXCEPTIONS 1
#endif

#define _CRT_CONCATENATE_(a, b) a ## b
#define _CRT_CONCATENATE(a, b)  _CRT_CONCATENATE_(a, b)

#define _CRT_UNPARENTHESIZE_(...) __VA_ARGS__
#define _CRT_UNPARENTHESIZE(...)  _CRT_UNPARENTHESIZE_ __VA_ARGS__

#ifndef __CRTDECL
# define __CRTDECL __cdecl
#endif

#ifndef __WIDL__
# ifndef _CONST_RETURN
#   define _CONST_RETURN
# endif
# define _WConst_return _CONST_RETURN
#endif  /* __WIDL__ */

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

#ifndef NULL
# ifdef __cplusplus
#   define NULL 0LL
# else
#   define NULL ((void *)0)
# endif  /* __cplusplus */
#endif  /* NULL */

#ifndef __WIDL__
# ifndef _UNALIGNED
#   define _UNALIGNED __unaligned
#   define  UNALIGNED _UNALIGNED
# endif  /* _UNALIGNED */
#endif  /* __WIDL__ */

#ifndef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
# ifdef WINAPI_FAMILY
#   include <winapifamily.h>
#   if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#     define _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
#   endif
# else
#   define _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
# endif  /* WINAPI_FAMILY */
#endif  /* _CRT_USE_WINAPI_FAMILY_DESKTOP_APP */

#ifndef _CRTIMP_ALTERNATIVE
# define _CRT_ALTERNATIVE_IMPORTED
# define _CRTIMP_ALTERNATIVE _CRTIMP
#endif  /* _CRTIMP_ALTERNATIVE */

#ifndef _CRTRESTRICT
# define _CRTRESTRICT
#endif

#ifndef __WIDL__
# ifndef _CRT_ALIGN
#   define _CRT_ALIGN(x) __attribute__((__aligned__(x)))
# endif
#endif  /* __WIDL__ */

#ifndef __crt_typefix
# define __crt_typefix(ctype)
#endif

#define _ARGMAX 100
#ifndef _TRUNCATE
# define _TRUNCATE ((size_t)-1)
#endif
#define _CRT_INT_MAX  2147483647
#define _CRT_SIZE_MAX ((size_t)-1)

#define __FILEW__     _CRT_WIDE(__FILE__)
#define __FUNCTIONW__ _CRT_WIDE(__FUNCTION__)

#ifdef __cplusplus
# ifndef _STATIC_ASSERT
#   define _STATIC_ASSERT(expr) static_assert((expr), #expr)
# endif
#else
# ifndef _STATIC_ASSERT
#   ifdef __clang__
#     define _STATIC_ASSERT(expr) _Static_assert((expr), #expr)
#   else
#     define _STATIC_ASSERT(expr) extern void __static_assert_t(int [(expr)?1:-1])
#   endif
# endif
#endif

#ifndef _CRT_UNUSED
# define _CRT_UNUSED(x) (void)x
#endif

#ifndef _PGLOBAL
# define _PGLOBAL
#endif

#ifndef _AGLOBAL
# define _AGLOBAL
#endif

#ifdef __cplusplus
# ifndef _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES
#   define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES 1
# endif
# ifndef _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY
#   define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY 0
# endif
# ifndef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES
#   define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 0
# endif
# ifndef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT
#   define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT 0
# endif
# ifndef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY
#   define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY 0
# endif
#else
# undef _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES
# undef _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY
# undef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES
# undef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT
# undef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY
# define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES          0
# define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY   0
# define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES        0
# define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT  0
# define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY 0
#endif  /* __cplusplus */

#ifndef _CRT_SECURE_CPP_NOTHROW
# define _CRT_SECURE_CPP_NOTHROW throw()
#endif

#ifndef _SSIZE_T_DEFINED
# define _SSIZE_T_DEFINED
# undef ssize_t
  __MINGW_EXTENSION typedef __int64 ssize_t;
#endif  /* _SSIZE_T_DEFINED */

#ifndef _UINTPTR_T_DEFINED
# define _UINTPTR_T_DEFINED
# ifndef __uintptr_t_defined
#   define __uintptr_t_defined
#   undef uintptr_t
    __MINGW_EXTENSION typedef unsigned __int64 uintptr_t;
# endif  /* __uintptr_t_defined */
#endif  /* _UINTPTR_T_DEFINED */

#ifndef _RSIZE_T_DEFINED
# define _RSIZE_T_DEFINED
# undef rsize_t
  typedef size_t rsize_t;
#endif

#ifndef _ERRCODE_DEFINED
# define _ERRCODE_DEFINED
  typedef int errno_t;
#endif  /* _ERRCODE_DEFINED */

#ifndef _WCTYPE_T_DEFINED
# define _WCTYPE_T_DEFINED
# ifndef _WINT_T
#   define _WINT_T
    typedef unsigned short wint_t;
    typedef unsigned short wctype_t;
# endif  /* _WINT_T */
#endif  /* _WCTYPE_T_DEFINED */

#ifndef _TIME32_T_DEFINED
# define _TIME32_T_DEFINED
  typedef long __time32_t;
#endif  /* _TIME32_T_DEFINED */

#ifndef _TIME64_T_DEFINED
# define _TIME64_T_DEFINED
  __MINGW_EXTENSION typedef __int64 __time64_t;
#endif  /* _TIME64_T_DEFINED */

#ifdef _USE_32BIT_TIME_T
# error You cannot use 32-bit time_t (_USE_32BIT_TIME_T) with _WIN64
# undef _USE_32BIT_TIME_T
#endif  /* _USE_32BIT_TIME_T */

#ifndef _TIME_T_DEFINED
# define _TIME_T_DEFINED
  typedef __time64_t time_t;
#endif  /* _TIME_T_DEFINED */

  _CRTIMP_ALTERNATIVE void __cdecl _invalid_parameter_noinfo(void);
  _CRTIMP             void __cdecl _invalid_parameter_noinfo_noreturn(void) __MINGW_NORETURN;

  _CRTIMP void __cdecl _invoke_watson
  (
    wchar_t const *_Expression, wchar_t const *_FunctionName, wchar_t const *_FileName, unsigned int _LineNo, uintptr_t _Reserved
  ) __MINGW_NORETURN;

  typedef struct _Mbstatet
  {
    unsigned long  _Wchar;
    unsigned short _Byte, _State;
  } _Mbstatet;

  typedef _Mbstatet mbstate_t;

#if defined(__cplusplus) && _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(__ret, __func, __dsttype, __dst)      \
  extern "C++"                                                                      \
  {                                                                                 \
    template <size_t __size>                                                        \
    inline __ret __cdecl __func(__dsttype (&__dst)[__size]) _CRT_SECURE_CPP_NOTHROW \
    {                                                                               \
      return __func(__dst, __size);                                                 \
    }                                                                               \
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(__ret, __func, __dsttype, __dst, __type1, __arg1)     \
  extern "C++"                                                                                      \
  {                                                                                                 \
    template <size_t __size>                                                                        \
    inline __ret __cdecl __func(__dsttype (&__dst)[__size], __type1 __arg1) _CRT_SECURE_CPP_NOTHROW \
    {                                                                                               \
        return __func(__dst, __size, __arg1);                                                       \
    }                                                                                               \
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(__ret, __func, __dsttype, __dst, __type1, __arg1, __type2, __arg2)    \
  extern "C++"                                                                                                      \
  {                                                                                                                 \
    template <size_t __size>                                                                                        \
    inline __ret __cdecl __func(__dsttype (&__dst)[__size], __type1 __arg1, __type2 __arg2) _CRT_SECURE_CPP_NOTHROW \
    {                                                                                                               \
      return __func(__dst, __size, __arg1, __arg2);                                                                 \
    }                                                                                                               \
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(__ret, __func, __dsttype, __dst, __type1, __arg1, __type2, __arg2, __type3, __arg3)   \
  extern "C++"                                                                                                                      \
  {                                                                                                                                 \
    template <size_t __size>                                                                                                        \
    inline __ret __cdecl __func(__dsttype (&__dst)[__size], __type1 __arg1, __type2 __arg2, __type3 __arg3) _CRT_SECURE_CPP_NOTHROW \
    {                                                                                                                               \
        return __func(__dst, __size, __arg1, __arg2, __arg3);                                                                       \
    }                                                                                                                               \
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_4(__ret, __func, __dsttype, __dst, __type1, __arg1, __type2, __arg2, __type3, __arg3, __type4, __arg4)  \
  extern "C++"                                                                                                                                      \
  {                                                                                                                                                 \
    template <size_t __size>                                                                                                                        \
    inline __ret __cdecl __func(__dsttype (&__dst)[__size], __type1 __arg1, __type2 __arg2, __type3 __arg3, __type4 __arg4) _CRT_SECURE_CPP_NOTHROW \
    {                                                                                                                                               \
        return __func(__dst, __size, __arg1, __arg2, __arg3, __arg4);                                                                               \
    }                                                                                                                                               \
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_1(__ret, __func, __type0, __arg0, __dsttype, __dst, __type1, __arg1)    \
  extern "C++"                                                                                                      \
  {                                                                                                                 \
    template <size_t __size>                                                                                        \
    inline __ret __cdecl __func(__type0 __arg0, __dsttype (&__dst)[__size], __type1 __arg1) _CRT_SECURE_CPP_NOTHROW \
    {                                                                                                               \
        return __func(__arg0, __dst, __size, __arg1);                                                               \
    }                                                                                                               \
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_2(__ret, __func, __type0, __arg0, __dsttype, __dst, __type1, __arg1, __type2, __arg2)   \
  extern "C++"                                                                                                                      \
  {                                                                                                                                 \
    template <size_t __size>                                                                                                        \
    inline __ret __cdecl __func(__type0 __arg0, __dsttype (&__dst)[__size], __type1 __arg1, __type2 __arg2) _CRT_SECURE_CPP_NOTHROW \
    {                                                                                                                               \
        return __func(__arg0, __dst, __size, __arg1, __arg2);                                                                       \
    }                                                                                                                               \
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_3(__ret, __func, __type0, __arg0, __dsttype, __dst, __type1, __arg1, __type2, __arg2, __type3, __arg3)  \
  extern "C++"                                                                                                                                      \
  {                                                                                                                                                 \
    template <size_t __size>                                                                                                                        \
    inline __ret __cdecl __func(__type0 __arg0, __dsttype (&__dst)[__size], __type1 __arg1, __type2 __arg2, __type3 __arg3) _CRT_SECURE_CPP_NOTHROW \
    {                                                                                                                                               \
        return __func(__arg0, __dst, __size, __arg1, __arg2, __arg3);                                                                               \
    }                                                                                                                                               \
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_2_0(__ret, __func, __type1, __arg1, __type2, __arg2, __dsttype, __dst)    \
  extern "C++"                                                                                                      \
  {                                                                                                                 \
    template <size_t __size>                                                                                        \
    inline __ret __cdecl __func(__type1 __arg1, __type2 __arg2, __dsttype (&__dst)[__size]) _CRT_SECURE_CPP_NOTHROW \
    {                                                                                                               \
        return __func(__arg1, __arg2, __dst, __size);                                                               \
    }                                                                                                               \
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1_ARGLIST(__ret, __func, __vfunc, __dsttype, __dst, __type1, __arg1) \
  extern "C++"                                                                                                   \
  {                                                                                                              \
    template <size_t __size>                                                                                     \
    inline __ret __cdecl __func(__dsttype (&__dst)[__size], __type1 __arg1, ...) _CRT_SECURE_CPP_NOTHROW         \
    {                                                                                                            \
      va_list __vaargs;                                                                                          \
      __crt_va_start(__vaargs, __arg1);                                                                           \
      __ret __retval = __vfunc(__dst, __size, __arg1, __vaargs);                                                 \
      __crt_va_end(__vaargs);                                                                                     \
      return __retval;                                                                                           \
    }                                                                                                            \
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2_ARGLIST(__ret, __func, __vfunc, __dsttype, __dst, __type1, __arg1, __type2, __arg2) \
  extern "C++"                                                                                                                    \
  {                                                                                                                               \
    template <size_t __size>                                                                                                      \
    inline __ret __cdecl __func(__dsttype (&__dst)[__size], __type1 __arg1, __type2 __arg2, ...) _CRT_SECURE_CPP_NOTHROW          \
    {                                                                                                                             \
      va_list __vaargs;                                                                                                           \
      __crt_va_start(__vaargs, __arg2);                                                                                            \
      __ret __retval = __vfunc(__dst, __size, __arg1, __arg2, __vaargs);                                                          \
      __crt_va_end(__vaargs);                                                                                                      \
      return __retval;                                                                                                            \
    }                                                                                                                             \
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_SPLITPATH(__ret, __func, __dsttype, __src)                          \
  extern "C++"                                                                                                \
  {                                                                                                           \
    template <size_t __drive_size, size_t __dir_size, size_t __name_size, size_t __ext_size>                  \
    inline __ret __cdecl __func                                                                               \
    (                                                                                                         \
      const __dsttype *__src,                                                                                 \
      __dsttype (&__drive)[__drive_size],                                                                     \
      __dsttype (&__dir)[__dir_size],                                                                         \
      __dsttype (&__name)[__name_size],                                                                       \
      __dsttype (&__ext)[__ext_size]                                                                          \
    ) _CRT_SECURE_CPP_NOTHROW                                                                                 \
    {                                                                                                         \
      return __func(__src, __drive, __drive_size, __dir, __dir_size, __name, __name_size, __ext, __ext_size); \
    }                                                                                                         \
  }

#else

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(__ret, __func, __dsttype, __dst)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(__ret, __func, __dsttype, __dst, __type1, __arg1)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(__ret, __func, __dsttype, __dst, __type1, __arg1, __type2, __arg2)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_3(__ret, __func, __dsttype, __dst, __type1, __arg1, __type2, __arg2, __type3, __arg3)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_4(__ret, __func, __dsttype, __dst, __type1, __arg1, __type2, __arg2, __type3, __arg3, __type4, __arg4)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_1(__ret, __func, __type0, __arg0, __dsttype, __dst, __type1, __arg1)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_2(__ret, __func, __type0, __arg0, __dsttype, __dst, __type1, __arg1, __type2, __arg2)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_3(__ret, __func, __type0, __arg0, __dsttype, __dst, __type1, __arg1, __type2, __arg2, __type3, __arg3)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_2_0(__ret, __func, __type1, __arg1, __type2, __arg2, __dsttype, __dst)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1_ARGLIST(__ret, __func, __vfunc, __dsttype, __dst, __type1, __arg1)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2_ARGLIST(__ret, __func, __vfunc, __dsttype, __dst, __type1, __arg1, __type2, __arg2)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_SPLITPATH(__ret, __func, __dsttype, __src)

#endif  /* defined(__cplusplus) && _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES */

  struct threadlocaleinfostruct;
  struct threadmbcinfostruct;
  typedef struct threadlocaleinfostruct *pthreadlocinfo;
  typedef struct threadmbcinfostruct    *pthreadmbcinfo;
  struct __lc_time_data;

  typedef struct localeinfo_struct
  {
    pthreadlocinfo locinfo;
    pthreadmbcinfo mbcinfo;
  } _locale_tstruct, *_locale_t;

#ifndef _TAGLC_ID_DEFINED
# define _TAGLC_ID_DEFINED
  typedef struct tagLC_ID
  {
    unsigned short wLanguage;
    unsigned short wCountry;
    unsigned short wCodePage;
  } LC_ID, *LPLC_ID;
#endif  /* _TAGLC_ID_DEFINED */

#ifndef _THREADLOCALEINFO
# define _THREADLOCALEINFO
  typedef struct threadlocaleinfostruct
  {
    const unsigned short *_locale_pctype;
    int                   _locale_mb_cur_max;
    unsigned int          _locale_lc_codepage;
  } threadlocinfo;
#endif  /* _THREADLOCALEINFO */

__MINGW_END_C_DECLS

#endif  /* _INC_CORECRT */
