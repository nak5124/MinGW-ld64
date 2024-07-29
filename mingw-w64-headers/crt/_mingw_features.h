/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_FEATURES_H
#define _INC_FEATURES_H

#undef __MINGW_USE_ISOC95
#undef __MINGW_USE_ISOC99
#undef __MINGW_USE_ISOC11
#undef __MINGW_USE_ISOC23
#undef __MINGW_USE_ISOCXX11
#undef __MINGW_USE_POSIX
#undef __MINGW_USE_POSIX2
#undef __MINGW_USE_POSIX199309
#undef __MINGW_USE_POSIX199506
#undef __MINGW_USE_XOPEN
#undef __MINGW_USE_XOPEN_EXT
#undef __MINGW_USE_UNIX98
#undef __MINGW_USE_XOPEN2K
#undef __MINGW_USE_XOPEN2KXSI
#undef __MINGW_USE_XOPEN2K8
#undef __MINGW_USE_XOPEN2K8XSI
#undef __MINGW_USE_MISC
#undef __MINGW_USE_ATFILE
#undef __MINGW_USE_FOB64
#undef __MINGW_USE_LFS
#undef __MINGW_USE_LFS64
#undef __MINGW_USE_GNU
#undef __MINGW_USE_MS
#undef __MINGW_USE_SECAPI
#undef __MINGW_USE_LIB_EXT2
#undef __MINGW_FORTIFY_LEVEL
#undef __MINGW_FORTIFY_VA_ARG

#define __MINGW_GNUC_PREREQ(major, minor)  (__GNUC__ > (major) || (__GNUC__ == (major) && __GNUC_MINOR__ >= (minor)))
#define __mingw_clang_prereq(major, minor) (__clang_major__ > (major) || (__clang_major__ == (major) && __clang_minor__ >= (minor)))

#ifdef _ISOC2X_SOURCE
# undef  _ISOC2X_SOURCE
# undef  _ISOC23_SOURCE
# define _ISOC23_SOURCE 1
#endif

#ifdef _GNU_SOURCE
# undef  _ISOC95_SOURCE
# undef  _ISOC99_SOURCE
# undef  _ISOC11_SOURCE
# undef  _ISOC23_SOURCE
# undef  _POSIX_C_SOURCE
# undef  _XOPEN_SOURCE
# undef  _XOPEN_SOURCE_EXTENDED
# undef  _DEFAULT_SOURCE
# undef  _ATFILE_SOURCE
# undef  _LARGEFILE_SOURCE
# undef  _LARGEFILE64_SOURCE
# define _ISOC95_SOURCE         1
# define _ISOC99_SOURCE         1
# define _ISOC11_SOURCE         1
# define _ISOC23_SOURCE         1
# define _POSIX_C_SOURCE        200809L
# define _XOPEN_SOURCE          700
# define _XOPEN_SOURCE_EXTENDED 1
# define _DEFAULT_SOURCE        1
# define _ATFILE_SOURCE         1
# define _LARGEFILE_SOURCE      1
# define _LARGEFILE64_SOURCE    1
# define __MINGW_USE_GNU        1
#endif

#if (defined(_POSIX) || defined(_POSIX_SOURCE)) && !defined(_POSIX_C_SOURCE)
# define _POSIX_C_SOURCE 1
#endif

#if defined(_BSD_SOURCE) || defined(_SVID_SOURCE) || \
  (!defined(__STRICT_ANSI__) && \
  !defined(_ISOC99_SOURCE) && !defined(_ISOC11_SOURCE) && !defined(_ISOC23_SOURCE) && \
  !defined(_POSIX_C_SOURCE) && !defined(_XOPEN_SOURCE))
# undef  _DEFAULT_SOURCE
# define _DEFAULT_SOURCE 1
#endif

#if defined(_ISOC23_SOURCE) || (defined(__STDC_VERSION__) && __STDC_VERSION__ > 201710L)
# define __MINGW_USE_ISOC23 1
#endif

#if defined(_ISOC11_SOURCE) || defined(_ISOC23_SOURCE) || (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L) || \
  (defined(__cplusplus) && (__cplusplus - 0) >= 201703L)
# define __MINGW_USE_ISOC11 1
#endif

#if defined(_ISOC99_SOURCE) || defined(_ISOC11_SOURCE) || defined(_ISOC23_SOURCE) || (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || \
  (defined(__cplusplus) && ((__cplusplus - 0) >= 201103L || defined(__GXX_EXPERIMENTAL_CXX0X__)))
# define __MINGW_USE_ISOC99 1
#endif

#if defined(_ISOC99_SOURCE) || defined(_ISOC11_SOURCE) || defined(_ISOC23_SOURCE) || (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199409L)
# define __MINGW_USE_ISOC95 1
#endif

#if defined(__cplusplus) && ((__cplusplus - 0) >= 201103L || defined(__GXX_EXPERIMENTAL_CXX0X__))
# undef  __MINGW_USE_ISOCXX11
# define __MINGW_USE_ISOCXX11 1
#endif

#ifdef _DEFAULT_SOURCE
# undef  _POSIX_C_SOURCE
# define _POSIX_C_SOURCE 200809L
#endif

#if (!defined(__STRICT_ANSI__) || (defined(_XOPEN_SOURCE) && (_XOPEN_SOURCE - 0) >= 500)) && !defined(_POSIX_C_SOURCE)
# define _POSIX_C_SOURCE 1
# if defined(_XOPEN_SOURCE) && (_XOPEN_SOURCE - 0) < 500
#   define _POSIX_C_SOURCE 2
# elif defined(_XOPEN_SOURCE) && (_XOPEN_SOURCE - 0) < 600
#   define _POSIX_C_SOURCE 199506L
# elif defined(_XOPEN_SOURCE) && (_XOPEN_SOURCE - 0) < 700
#   define _POSIX_C_SOURCE 200112L
# else
#   define _POSIX_C_SOURCE 200809L
# endif
#endif

#if (defined(_THREAD_SAFE) || defined(_REENTRANT)) && (!defined(_POSIX_C_SOURCE) || (_POSIX_C_SOURCE - 0) < 199506L)
# undef  _POSIX_C_SOURCE
# define _POSIX_C_SOURCE 199506L
#endif

#if (defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE - 0) >= 1)
# define __MINGW_USE_POSIX 1
# if (_POSIX_C_SOURCE - 0) >= 2
#   define __MINGW_USE_POSIX2 1
#   if (_POSIX_C_SOURCE - 0) >= 199309L
#     define __MINGW_USE_POSIX199309 1
#     if (_POSIX_C_SOURCE - 0) >= 199506L
#       define __MINGW_USE_POSIX199506 1
#       if (_POSIX_C_SOURCE - 0) >= 200112L
#         undef  __MINGW_USE_ISOC95
#         undef  __MINGW_USE_ISOC99
#         define __MINGW_USE_ISOC95  1
#         define __MINGW_USE_ISOC99  1
#         define __MINGW_USE_XOPEN2K 1
#         if (_POSIX_C_SOURCE - 0) >= 200809L
#           define __MINGW_USE_XOPEN2K8 1
#           undef  _ATFILE_SOURCE
#           define _ATFILE_SOURCE       1
#         endif
#       endif
#     endif
#   endif
# endif
#endif

#ifdef _XOPEN_SOURCE
# undef  __MINGW_USE_POSIX
# undef  __MINGW_USE_POSIX2
# define __MINGW_USE_POSIX  1
# define __MINGW_USE_POSIX2 1
# define __MINGW_USE_XOPEN  1
# if (_XOPEN_SOURCE - 0) >= 500
#   define __MINGW_USE_XOPEN_EXT 1
#   define __MINGW_USE_UNIX98    1
#   undef _LARGEFILE_SOURCE
#   define _LARGEFILE_SOURCE     1
#   if (_XOPEN_SOURCE - 0) >= 600
#     undef  __MINGW_USE_ISOC95
#     undef  __MINGW_USE_ISOC99
#     define __MINGW_USE_ISOC95     1
#     define __MINGW_USE_ISOC99     1
#     define __MINGW_USE_XOPEN2K    1
#     define __MINGW_USE_XOPEN2KXSI 1
#     if (_XOPEN_SOURCE - 0) >= 700
#       define __MINGW_USE_XOPEN2K8    1
#       define __MINGW_USE_XOPEN2K8XSI 1
#     endif
#   endif
# else
#   ifdef _XOPEN_SOURCE_EXTENDED
#     define __MINGW_USE_XOPEN_EXT 1
#   endif
# endif
#endif

#ifdef _DEFAULT_SOURCE
# define __MINGW_USE_MISC 1
#endif

#ifdef _ATFILE_SOURCE
# define __MINGW_USE_ATFILE 1
#endif

#ifndef _FILE_OFFSET_BITS
# define _FILE_OFFSET_BITS 64
#endif

#if defined(_FILE_OFFSET_BITS) && _FILE_OFFSET_BITS == 64
# define __MINGW_USE_FOB64   1
# undef  _LARGEFILE_SOURCE
# undef  _LARGEFILE64_SOURCE
# define _LARGEFILE_SOURCE   1
# define _LARGEFILE64_SOURCE 1
#endif

#ifdef _LARGEFILE_SOURCE
# define __MINGW_USE_LFS 1
#endif

#ifdef _LARGEFILE64_SOURCE
# define __MINGW_USE_LFS64 1
#endif

#if (defined(__MINGW_USE_POSIX) || defined(__MINGW_USE_XOPEN) || defined(__MINGW_USE_MISC)) && !defined(__USE_MINGW_ANSI_STDIO)
# define __USE_MINGW_ANSI_STDIO 1
#endif

#if !defined(__USE_MINGW_ANSI_STDIO) || (defined(__USE_MINGW_ANSI_STDIO) && __USE_MINGW_ANSI_STDIO == 0)
# undef  __USE_MINGW_ANSI_STDIO
# define __USE_MINGW_ANSI_STDIO 0
#else
# undef  __USE_MINGW_ANSI_STDIO
# define __USE_MINGW_ANSI_STDIO 1
#endif

#if defined(_MS_SOURCE) || !defined(__STRICT_ANSI__) || defined(_CRT_DECLARE_NONSTDC_NAMES)
# undef  _MS_SOURCE
# define _MS_SOURCE     1
# define __MINGW_USE_MS 1
#endif

#if defined(_MS_SOURCE) || defined(__STDC_WANT_LIB_EXT1__) || defined(__STDC_WANT_SECURE_LIB__)
# define __MINGW_USE_SECAPI 1
#endif

#if defined(__MINGW_USE_GNU) || (defined(__STDC_WANT_LIB_EXT2__) && __STDC_WANT_LIB_EXT2__ > 0)
# define __MINGW_USE_LIB_EXT2 1
#endif

#pragma push_macro("__has_builtin")
#ifndef __has_builtin
# define __has_builtin(x) 0
#endif

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0
# if !defined(__OPTIMIZE__) || __OPTIMIZE__ <= 0
#   warning _FORTIFY_SOURCE requires compiling with optimization (-O)
# elif !__MINGW_GNUC_PREREQ(4, 1)
#   warning _FORTIFY_SOURCE requires GCC 4.1 or later
# elif _FORTIFY_SOURCE > 3
#   warning Using _FORTIFY_SOURCE=3 (levels > 3 are not supported)
# endif
# if _FORTIFY_SOURCE > 2
#   if __has_builtin(__builtin_dynamic_object_size)
#     define __MINGW_FORTIFY_LEVEL 3
#   else
#     warning Using _FORTIFY_SOURCE=2 (level 3 requires __builtin_dynamic_object_size support)
#     define __MINGW_FORTIFY_LEVEL 2
#   endif
# elif _FORTIFY_SOURCE > 1
#   define __MINGW_FORTIFY_LEVEL 2
# else
#   define __MINGW_FORTIFY_LEVEL 1
# endif
#else
# define __MINGW_FORTIFY_LEVEL 0
#endif

/* If _FORTIFY_SOURCE is enabled, some inline functions may use
   __builtin_va_arg_pack().  GCC may report an error if the address
   of such a function is used.  Set _FORTIFY_VA_ARG=0 in this case.
   Clang doesn't, as of version 15, yet implement __builtin_va_arg_pack().  */
#if __MINGW_FORTIFY_LEVEL > 0 \
  && ((__MINGW_GNUC_PREREQ(4, 3) && !defined(__clang__)) || __has_builtin(__builtin_va_arg_pack)) \
  && (!defined(_FORTIFY_VA_ARG) || _FORTIFY_VA_ARG > 0)
# define __MINGW_FORTIFY_VA_ARG 1
#else
# define __MINGW_FORTIFY_VA_ARG 0
#endif

#pragma pop_macro("__has_builtin")

#endif  /* _INC_FEATURES_H */
