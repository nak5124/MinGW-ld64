/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_STRING
#define _INC_STRING

#include <corecrt.h>
#include <corecrt_wstring.h>

#pragma pack(push, _CRT_PACKING)

__MINGW_BEGIN_C_DECLS

#define _NLSCMPERROR _CRT_INT_MAX

#ifndef _CRT_MEMORY_DEFINED  /* Also in memory.h */
# define _CRT_MEMORY_DEFINED

  _CRTIMP void *__cdecl _memccpy(void *_Dst, const void *_Src, int _Val, size_t _MaxCount);
  _CRTIMP int __cdecl _memicmp(const void *_Buf1, const void *_Buf2, size_t _Size);
  _CRTIMP int __cdecl _memicmp_l(const void *_Buf1, const void *_Buf2, size_t _Size, _locale_t _Locale);

#if defined(__MINGW_USE_ISOC23) || defined(__MINGW_USE_XOPEN) || defined(__MINGW_USE_MISC) || defined(__MINGW_USE_MS)
  _CRTIMP void * __cdecl memccpy(void *_Dst, const void *_Src, int _Val, size_t _Size) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif
#ifdef __MINGW_USE_MS
  _CRTIMP int __cdecl memicmp(const void *_Buf1, const void *_Buf2, size_t _Size) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif

  _CRTIMP void *__cdecl memcpy(void * __restrict__ _Dst, const void * __restrict__ _Src, size_t _Size) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl memcpy_s(void *_dest, size_t _numberOfElements, const void *_src, size_t _count);
#endif
  _CRTIMP void *__cdecl memmove(void *_Dst, const void *_Src, size_t _Size) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl memmove_s(void *_dest, size_t _numberOfElements, const void *_src, size_t _count);
#endif
  _CRTIMP _CONST_RETURN void *__cdecl memchr(const void *_Buf, int _Val, size_t _MaxCount);
  _CRTIMP int __cdecl memcmp(const void *_Buf1, const void *_Buf2, size_t _Size);
  _CRTIMP void *__cdecl memset(void *_Dst, int _Val, size_t _Size);

#if __MINGW_FORTIFY_LEVEL > 0

  __mingw_bos_extern_ovr
  void * memcpy(void * __restrict__ __dst, const void * __restrict__ __src, size_t __n)
  {
    return __builtin___memcpy_chk(__dst, __src, __n, __mingw_bos(__dst, 0));
  }

#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl __mingw_call_memcpy_s(void *_dest, size_t _numberOfElements, const void *_src, size_t _count) __MINGW_ASM_CRT_CALL(memcpy_s);

  __mingw_bos_extern_ovr
  errno_t memcpy_s(void * __dst, size_t __os, const void * __src, size_t __n)
  {
    __mingw_bos_ptr_chk_warn(__dst, __os, 0);
    return __mingw_call_memcpy_s(__dst, __os, __src, __n);
  }
#endif

  __mingw_bos_extern_ovr
  void * memmove(void * __dst, const void * __src, size_t __n)
  {
    return __builtin___memmove_chk(__dst, __src, __n, __mingw_bos(__dst, 0));
  }

  __mingw_bos_extern_ovr
  void * memset(void * __dst, int __val, size_t __n)
  {
    return __builtin___memset_chk(__dst, __val, __n, __mingw_bos(__dst, 0));
  }

#endif

#endif  /* _CRT_MEMORY_DEFINED */

  _CRTIMP char *__cdecl strcpy(char * __restrict__ _Dest, const char * __restrict__ _Source) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl strcpy_s(char *_Dst, rsize_t _SizeInBytes, const char *_Src);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, strcpy_s, char, _Dest, const char *, _Source)
#endif
  _CRTIMP char *__cdecl strcat(char * __restrict__ _Dest, const char * __restrict__ _Source) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl strcat_s(char *_Dst, rsize_t _SizeInBytes, const char * _Src);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, strcat_s, char, _Dest, const char *, _Source)
#endif
  _CRTIMP char *__cdecl strerror(int _ErrMsg) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl strerror_s(char *_Buf, size_t _SizeInBytes, int _ErrNum);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, strerror_s, char, _Buf, int, _ErrNum)
#endif
  _CRTIMP char *__cdecl strncat(char * __restrict__ _Dest, const char * __restrict__ _Source, size_t _Count) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl strncat_s(char *_Dst, size_t _DstSizeInChars, const char *_Src, size_t _MaxCount);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(errno_t, strncat_s, char, _Dst, const char *, _Src, size_t, _MaxCount)
#endif
  _CRTIMP char *strncpy(char * __restrict__ _Dest, const char * __restrict__ _Source, size_t _Count) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl strncpy_s(char *_Dst, size_t _DstSizeInChars, const char *_Src, size_t _MaxCount);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(errno_t, strncpy_s, char, _Dest, const char *, _Source, size_t, _MaxCount)
#endif
  _CRTIMP char *__cdecl strtok(char * __restrict__ _Str, const char * __restrict__ _Delim) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP char *__cdecl strtok_s(char *_Str, const char *_Delim, char **_Context);
#endif

  _CRTIMP int __cdecl strcmp(const char *_Str1, const char *_Str2);
  _CRTIMP int __cdecl _strcmpi(const char *_Str1, const char *_Str2);
  _CRTIMP int __cdecl strcoll(const char *_Str1, const char *_Str2);
  _CRTIMP int __cdecl _strcoll_l(const char *_Str1, const char *_Str2, _locale_t _Locale);
  _CRTIMP size_t __cdecl strcspn(const char *_Str, const char *_Control);
  _CRTIMP char *__cdecl _strdup(const char *_Src);
  _CRTIMP char *__cdecl _strerror(const char *_ErrMsg) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _strerror_s(char *_Buf, size_t _SizeInBytes, const char *_ErrMsg);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _strerror_s, char, _Buf, const char *, _ErrMsg)
  _CRTIMP int __cdecl _stricmp(const char *_Str1, const char *_Str2);
  _CRTIMP int __cdecl _stricoll(const char *_Str1, const char *_Str2);
  _CRTIMP int __cdecl _stricoll_l(const char *_Str1, const char *_Str2, _locale_t _Locale);
  _CRTIMP int __cdecl _stricmp_l(const char *_Str1, const char *_Str2, _locale_t _Locale);
  _CRTIMP size_t __cdecl strlen(const char *_Str);
  _CRTIMP char *__cdecl _strlwr(char *_String) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _strlwr_s(char *_Str, size_t _Size);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, _strlwr_s, char, _Str)
  _CRTIMP char *__cdecl _strlwr_l(char *_String, _locale_t _Locale);
  _CRTIMP errno_t __cdecl _strlwr_s_l(char *_Str, size_t _Size, _locale_t _Locale);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _strlwr_s_l, char, _Str, _locale_t, _Locale)
  _CRTIMP int __cdecl strncmp(const char *_Str1, const char *_Str2, size_t _MaxCount);
  _CRTIMP int __cdecl _strnicmp(const char *_Str1, const char *_Str2, size_t _MaxCount);
  _CRTIMP int __cdecl _strnicmp_l(const char *_Str1, const char *_Str2, size_t _MaxCount, _locale_t _Locale);
  _CRTIMP int __cdecl _strnicoll(const char *_Str1, const char *_Str2, size_t _MaxCount);
  _CRTIMP int __cdecl _strnicoll_l(const char *_Str1, const char *_Str2, size_t _MaxCount, _locale_t _Locale);
  _CRTIMP int __cdecl _strncoll(const char *_Str1, const char *_Str2, size_t _MaxCount);
  _CRTIMP int __cdecl _strncoll_l(const char *_Str1, const char *_Str2, size_t _MaxCount, _locale_t _Locale);
  _CRTIMP size_t __cdecl __strncnt(const char *_String, size_t _Count);
#if defined(__MINGW_USE_XOPEN) || defined(__MINGW_USE_MS)
  _CRTIMP size_t __cdecl strnlen(const char *_Str, size_t _MaxCount);
#endif

#ifdef __MINGW_USE_SECAPI
  __mingw_ovr size_t __cdecl strnlen_s(const char * _src, size_t _count)
  {
    return _src ? strnlen(_src, _count) : 0;
  }
#endif

  _CRTIMP char *__cdecl _strnset(char *_Str, int _Val, size_t _MaxCount) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _strnset_s(char *_Str, size_t _Size, int _Val, size_t _MaxCount);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(errno_t, _strnset_s, char, _Str, int, _Val, size_t, _MaxCount)
  _CRTIMP _CONST_RETURN char *__cdecl strpbrk(const char *_Str, const char *_Control);
  _CRTIMP char *__cdecl _strrev(char *_Str);
  _CRTIMP char * __cdecl _strset(char *_Str, int _Val) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _strset_s(char *_Dst, size_t _DstSize, int _Value);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _strset_s, char, _Dst, int, _Value)
  _CRTIMP size_t __cdecl strspn(const char *_Str, const char *_Control);
  _CRTIMP char *__cdecl _strupr(char *_String) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _strupr_s(char *_Str, size_t _Size);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, _strupr_s, char, _Str)
  _CRTIMP char *_strupr_l(char *_String, _locale_t _Locale) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _strupr_s_l(char *_Str, size_t _Size, _locale_t _Locale);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _strupr_s_l, char, _Str, _locale_t, _Locale)
  _CRTIMP size_t __cdecl strxfrm(char * __restrict__ _Dst, const char * __restrict__ _Src, size_t _MaxCount);
  _CRTIMP size_t __cdecl _strxfrm_l(char * __restrict__ _Dst, const char * __restrict__ _Src, size_t _MaxCount, _locale_t _Locale);

  _CRTIMP _CONST_RETURN char *__cdecl strchr(const char *_Str, int _Val);
  _CRTIMP _CONST_RETURN char *__cdecl strrchr(const char *_Str, int _Ch);
  _CRTIMP _CONST_RETURN char *__cdecl strstr(const char *_Str, const char *_SubStr);

#if defined(__MINGW_USE_ISOC23) || defined(__MINGW_USE_XOPEN_EXT) || defined(__MINGW_USE_XOPEN2K8) || defined(__MINGW_USE_LIB_EXT2) || defined(__MINGW_USE_MS)
# pragma push_macro("strdup")
# undef strdup
  _CRTIMP char *__cdecl strdup(const char *_Src) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
# pragma pop_macro("strdup")
#endif
#ifdef __MINGW_USE_MS
  _CRTIMP int __cdecl strcmpi(const char *_Str1, const char *_Str2) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  _CRTIMP int __cdecl stricmp(const char *_Str1,const char *_Str2) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  _CRTIMP char *__cdecl strlwr(char *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  _CRTIMP int __cdecl strnicmp(const char *_Str1, const char *_Str, size_t _MaxCount) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  _CRTIMP char *__cdecl strnset(char *_Str, int _Val, size_t _MaxCount) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  _CRTIMP char *__cdecl strrev(char *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  _CRTIMP char *__cdecl strset(char *_Str, int _Val) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  _CRTIMP char *__cdecl strupr(char *_Str) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif

#if defined(__MINGW_USE_MISC) || defined(__MINGW_USE_MS)
  _CRTIMP int __cdecl strcasecmp(const char *_Str1, const char *_Str2);
  _CRTIMP int __cdecl strncasecmp(const char *_Str1, const char *_Str2, size_t _MaxCount);
#endif

#ifdef __MINGW_USE_MISC
  extern void *__cdecl mempcpy(void *_Dst, const void *_Src, size_t _Size);
#endif

#if defined(__MINGW_USE_POSIX) || defined(__MINGW_USE_MISC)
# pragma push_macro("strtok_r")
# undef strtok_r
  extern char *strtok_r(char * __restrict__ _Str, const char * __restrict__ _Delim, char ** __restrict__ __last);
# pragma pop_macro("strtok_r")
#endif

#if __MINGW_FORTIFY_LEVEL > 0

  __mingw_bos_extern_ovr
  char * strcpy(char * __restrict__ __dst, const char * __restrict__ __src)
  {
    return __builtin___strcpy_chk(__dst, __src, __mingw_bos(__dst, 1));
  }

  __mingw_bos_extern_ovr
  char * strcat(char * __restrict__ __dst, const char * __restrict__ __src)
  {
    return __builtin___strcat_chk(__dst, __src, __mingw_bos(__dst, 1));
  }

  __mingw_bos_extern_ovr
  char * strncat(char * __restrict__ __dst, const char * __restrict__ __src, size_t __n)
  {
    return __builtin___strncat_chk(__dst, __src, __n, __mingw_bos(__dst, 1));
  }

  __mingw_bos_extern_ovr
  char * strncpy(char * __restrict__ __dst, const char * __restrict__ __src, size_t __n)
  {
    return __builtin___strncpy_chk(__dst, __src, __n, __mingw_bos(__dst, 1));
  }

#ifdef __MINGW_USE_MISC
  __mingw_bos_extern_ovr
  void * mempcpy(void * __dst, const void * __src, size_t __n)
  {
    return __builtin___mempcpy_chk(__dst, __src, __n, __mingw_bos(__dst, 0));
  }
#endif

#endif  /* __MINGW_FORTIFY_LEVEL > 0 */

__MINGW_END_C_DECLS

#pragma pack(pop)

#endif  /* _INC_STRING */
