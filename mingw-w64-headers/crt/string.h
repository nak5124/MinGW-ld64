/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_STRING
#define _INC_STRING

#include <corecrt.h>
#include <memory.h>
#include <corecrt_wstring.h>

__MINGW_BEGIN_C_DECLS

#define _NLSCMPERROR _CRT_INT_MAX

  _CRTIMP char   *__cdecl strcpy(char *__restrict _Dest, const char *__restrict _Source) __MINGW_NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl strcpy_s(char *_Dst, rsize_t _SizeInBytes, const char *_Src);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, strcpy_s, char, _Dest, const char *, _Source)
#endif
  _CRTIMP char   *__cdecl strcat(char *__restrict _Dest, const char *__restrict _Source) __MINGW_NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl strcat_s(char *_Dst, rsize_t _SizeInBytes, const char * _Src);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, strcat_s, char, _Dest, const char *, _Source)
#endif
  _CRTIMP char   *__cdecl strerror(int _ErrMsg) __MINGW_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl strerror_s(char *_Buf, size_t _SizeInBytes, int _ErrNum);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, strerror_s, char, _Buf, int, _ErrNum)
#endif
  _CRTIMP char   *__cdecl strncat(char *__restrict _Dest, const char *__restrict _Source, size_t _Count) __MINGW_NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl strncat_s(char *_Dst, size_t _DstSizeInChars, const char *_Src, size_t _MaxCount);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(errno_t, strncat_s, char, _Dst, const char *, _Src, size_t, _MaxCount)
#endif
  _CRTIMP char   *__cdecl strncpy(char *__restrict _Dest, const char *__restrict _Source, size_t _Count) __MINGW_NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl strncpy_s(char *_Dst, size_t _DstSizeInChars, const char *_Src, size_t _MaxCount);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(errno_t, strncpy_s, char, _Dest, const char *, _Source, size_t, _MaxCount)
#endif
  _CRTIMP char   *__cdecl strtok(char *__restrict _Str, const char *__restrict _Delim) __MINGW_NONNULL((2)) __MINGW_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP char   *__cdecl strtok_s(char *_Str, const char *_Delim, char **_Context);
#endif

  _CRTIMP int     __cdecl   strcmp(const char *_Str1, const char *_Str2) __MINGW_NONNULL((1, 2)) __MINGW_PURE;
  _CRTIMP int     __cdecl  _strcmpi(const char *_Str1, const char *_Str2);
  _CRTIMP int     __cdecl   strcoll(const char *_Str1, const char *_Str2) __MINGW_NONNULL((1, 2)) __MINGW_PURE;
  _CRTIMP int     __cdecl  _strcoll_l(const char *_Str1, const char *_Str2, _locale_t _Locale);
  _CRTIMP size_t  __cdecl   strcspn(const char *_Str, const char *_Control) __MINGW_NONNULL((1, 2)) __MINGW_PURE;
  _CRTIMP char   *__cdecl  _strdup(const char *_Src) __MINGW_NONNULL((1)) __MINGW_MALLOC;
  _CRTIMP char   *__cdecl  _strerror(const char *_ErrMsg) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl  _strerror_s(char *_Buf, size_t _SizeInBytes, const char *_ErrMsg);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _strerror_s, char, _Buf, const char *, _ErrMsg)
  _CRTIMP int     __cdecl  _stricmp(const char *_Str1, const char *_Str2);
  _CRTIMP int     __cdecl  _stricoll(const char *_Str1, const char *_Str2);
  _CRTIMP int     __cdecl  _stricoll_l(const char *_Str1, const char *_Str2, _locale_t _Locale);
  _CRTIMP int     __cdecl  _stricmp_l(const char *_Str1, const char *_Str2, _locale_t _Locale);
  _CRTIMP size_t  __cdecl   strlen(const char *_Str) __MINGW_NONNULL((1)) __MINGW_PURE;
  _CRTIMP char   *__cdecl  _strlwr(char *_String) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl  _strlwr_s(char *_Str, size_t _Size);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, _strlwr_s, char, _Str)
  _CRTIMP char   *__cdecl  _strlwr_l(char *_String, _locale_t _Locale);
  _CRTIMP errno_t __cdecl  _strlwr_s_l(char *_Str, size_t _Size, _locale_t _Locale);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _strlwr_s_l, char, _Str, _locale_t, _Locale)
  _CRTIMP int     __cdecl   strncmp(const char *_Str1, const char *_Str2, size_t _MaxCount) __MINGW_NONNULL((1, 2)) __MINGW_PURE;
  _CRTIMP int     __cdecl  _strnicmp(const char *_Str1, const char *_Str2, size_t _MaxCount);
  _CRTIMP int     __cdecl  _strnicmp_l(const char *_Str1, const char *_Str2, size_t _MaxCount, _locale_t _Locale);
  _CRTIMP int     __cdecl  _strnicoll(const char *_Str1, const char *_Str2, size_t _MaxCount);
  _CRTIMP int     __cdecl  _strnicoll_l(const char *_Str1, const char *_Str2, size_t _MaxCount, _locale_t _Locale);
  _CRTIMP int     __cdecl  _strncoll(const char *_Str1, const char *_Str2, size_t _MaxCount);
  _CRTIMP int     __cdecl  _strncoll_l(const char *_Str1, const char *_Str2, size_t _MaxCount, _locale_t _Locale);
  _CRTIMP size_t  __cdecl __strncnt(const char *_String, size_t _Count);
#if defined(__MINGW_USE_XOPEN) || defined(__MINGW_USE_MS)
  _CRTIMP size_t  __cdecl   strnlen(const char *_Str, size_t _MaxCount) __MINGW_NONNULL((1)) __MINGW_PURE;
#endif

#ifdef __MINGW_USE_SECAPI
  __mingw_ovr
  size_t strnlen_s(const char *__src, size_t __count)
  {
    return __src ? strnlen(__src, __count) : 0;
  }
#endif

  _CRTIMP char               *__cdecl _strnset(char *_Str, int _Val, size_t _MaxCount) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t             __cdecl _strnset_s(char *_Str, size_t _Size, int _Val, size_t _MaxCount);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(errno_t, _strnset_s, char, _Str, int, _Val, size_t, _MaxCount)
  _CRTIMP _CONST_RETURN char *__cdecl  strpbrk(const char *_Str, const char *_Control) __MINGW_NONNULL((1, 2)) __MINGW_PURE;
  _CRTIMP char               *__cdecl _strrev(char *_Str);
  _CRTIMP char               *__cdecl _strset(char *_Str, int _Val) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t             __cdecl _strset_s(char *_Dst, size_t _DstSize, int _Value);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _strset_s, char, _Dst, int, _Value)
  _CRTIMP size_t              __cdecl  strspn(const char *_Str, const char *_Control) __MINGW_NONNULL((1, 2)) __MINGW_PURE;
  _CRTIMP char               *__cdecl _strupr(char *_String) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t             __cdecl _strupr_s(char *_Str, size_t _Size);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, _strupr_s, char, _Str)
  _CRTIMP char               *__cdecl _strupr_l(char *_String, _locale_t _Locale) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t             __cdecl _strupr_s_l(char *_Str, size_t _Size, _locale_t _Locale);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _strupr_s_l, char, _Str, _locale_t, _Locale)
  _CRTIMP size_t              __cdecl  strxfrm(char *__restrict _Dst, const char *__restrict _Src, size_t _MaxCount) __MINGW_NONNULL((2));
  _CRTIMP size_t              __cdecl _strxfrm_l(char *__restrict _Dst, const char *__restrict _Src, size_t _MaxCount, _locale_t _Locale);

  _CRTIMP _CONST_RETURN char *__cdecl strchr(const char *_Str, int _Val)            __MINGW_NONNULL((1))    __MINGW_PURE;
  _CRTIMP _CONST_RETURN char *__cdecl strrchr(const char *_Str, int _Ch)            __MINGW_NONNULL((1))    __MINGW_PURE;
  _CRTIMP _CONST_RETURN char *__cdecl strstr(const char *_Str, const char *_SubStr) __MINGW_NONNULL((1, 2)) __MINGW_PURE;

#if defined(__MINGW_USE_ISOC23) || defined(__MINGW_USE_XOPEN_EXT) || defined(__MINGW_USE_XOPEN2K8) || defined(__MINGW_USE_LIB_EXT2) || defined(__MINGW_USE_MS)
# pragma push_macro("strdup")
# undef strdup
  _CRTIMP char *__cdecl strdup(const char *_Src) __MINGW_NONNULL((1)) __MINGW_MALLOC __MINGW_DEPRECATED_MSVC2005;
# pragma pop_macro("strdup")
#endif
#if defined(__MINGW_USE_ISOC23) || defined(__MINGW_USE_XOPEN2K8) || defined(__MINGW_USE_LIB_EXT2)
  extern char *__cdecl strndup(const char *_Src, size_t _Size) __MINGW_NONNULL((1)) __MINGW_MALLOC;
#endif
#ifdef __MINGW_USE_MS
  _CRTIMP int   __cdecl strcmpi(const char *_Str1, const char *_Str2)                   __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP int   __cdecl stricmp(const char *_Str1,const char *_Str2)                    __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP char *__cdecl strlwr(char *_Str)                                              __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP int   __cdecl strnicmp(const char *_Str1, const char *_Str, size_t _MaxCount) __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP char *__cdecl strnset(char *_Str, int _Val, size_t _MaxCount)                 __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP char *__cdecl strrev(char *_Str)                                              __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP char *__cdecl strset(char *_Str, int _Val)                                    __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP char *__cdecl strupr(char *_Str)                                              __MINGW_DEPRECATED_MSVC2005;
#endif

#if defined(__MINGW_USE_MISC) || defined(__MINGW_USE_MS)
  _CRTIMP int __cdecl strcasecmp(const char *_Str1, const char *_Str2)                    __MINGW_NONNULL((1, 2)) __MINGW_PURE;
  _CRTIMP int __cdecl strncasecmp(const char *_Str1, const char *_Str2, size_t _MaxCount) __MINGW_NONNULL((1, 2)) __MINGW_PURE;
#endif

#ifdef __MINGW_USE_MISC
  extern void *__cdecl mempcpy(void *_Dst, const void *_Src, size_t _Size)                                                     __MINGW_NONNULL((1, 2));
  extern void *__cdecl memmem(const void *_Haystack, size_t _Haystacklen, const void *_Needle, size_t _Needlelen) __MINGW_PURE __MINGW_NONNULL((1, 3));
  extern char *__cdecl strchrnul(const char *_S, int _C)                                                          __MINGW_PURE __MINGW_NONNULL((1));
#endif

#ifdef __MINGW_USE_GNU
  extern void *__cdecl memrchr(const void *_S, int _C, size_t _N) __MINGW_PURE __MINGW_NONNULL((1));
#endif

#ifdef __MINGW_USE_POSIX
  /**/   char *__cdecl strtok_r(char *__restrict _Str, const char *__restrict _Delim, char **__restrict _Saveptr) __MINGW_NONNULL((2, 3));
#endif

#ifdef __MINGW_USE_GNU
  extern char *__cdecl strerror_r(int _Errnum, char *_Buf, size_t _Buflen) __MINGW_NONNULL((2));
# ifndef __CRT__NO_INLINE
  __CRT_INLINE __MINGW_NONNULL((2))
  char *__cdecl strerror_r(int _Errnum, char *_Buf, size_t _Buflen)
  {
    errno_t err = strerror_s(_Buf, _Buflen, _Errnum);
    if(err != 0)
    {
      return NULL;
    }
    return _Buf;
  }
# endif
#elif defined(__MINGW_USE_XOPEN2K)
  extern int   __cdecl strerror_r(int _Errnum, char *_Buf, size_t _Buflen) __MINGW_ASM_CALL(__xsi_strerror_r) __MINGW_NONNULL((2));
# ifndef __CRT__NO_INLINE
  __CRT_INLINE __MINGW_NONNULL((2))
  int __cdecl strerror_r(int _Errnum, char *_Buf, size_t _Buflen)
  {
    return strerror_s(_Buf, _Buflen, _Errnum);
  }
# endif
#endif

#ifdef __MINGW_USE_MISC
  extern void __cdecl explicit_bzero(void *_Ptr, size_t _N) __MINGW_NONNULL((1));
#ifndef __CRT__NO_INLINE
  __CRT_INLINE __MINGW_NONNULL((1))
  void __cdecl explicit_bzero(void *_Ptr, size_t _N)
  {
    (void)memset(_Ptr, '\0', _N);
    __asm__ __volatile__("" ::: "memory");
  }
#endif
#endif

#ifdef __MINGW_USE_XOPEN2K8
  extern char *__cdecl stpcpy(char *__restrict _Dest, const char *__restrict _Src)             __MINGW_NONNULL((1, 2));
  extern char *__cdecl stpncpy(char *__restrict _Dest, const char *__restrict _Src, size_t _N) __MINGW_NONNULL((1, 2));
#endif

#if __MINGW_FORTIFY_LEVEL > 0

  __mingw_bos_extern_ovr __MINGW_NONNULL((1, 2))
  char *strcpy(char *__restrict __dst, const char *__restrict __src)
  {
    return __builtin___strcpy_chk(__dst, __src, __mingw_bos(__dst, 1));
  }

  __mingw_bos_extern_ovr __MINGW_NONNULL((1, 2))
  char *strcat(char *__restrict __dst, const char *__restrict __src)
  {
    return __builtin___strcat_chk(__dst, __src, __mingw_bos(__dst, 1));
  }

  __mingw_bos_extern_ovr __MINGW_NONNULL((1, 2))
  char *strncat(char *__restrict __dst, const char *__restrict __src, size_t __n)
  {
    return __builtin___strncat_chk(__dst, __src, __n, __mingw_bos(__dst, 1));
  }

  __mingw_bos_extern_ovr __MINGW_NONNULL((1, 2))
  char *strncpy(char *__restrict __dst, const char *__restrict __src, size_t __n)
  {
    return __builtin___strncpy_chk(__dst, __src, __n, __mingw_bos(__dst, 1));
  }

#ifdef __MINGW_USE_MISC
  __mingw_bos_extern_ovr __MINGW_NONNULL((1, 2))
  void *mempcpy(void *__dst, const void *__src, size_t __n)
  {
    return __builtin___mempcpy_chk(__dst, __src, __n, __mingw_bos(__dst, 0));
  }
#endif

#endif  /* __MINGW_FORTIFY_LEVEL > 0 */

__MINGW_END_C_DECLS

#endif  /* _INC_STRING */
