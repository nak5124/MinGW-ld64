/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CORECRT_WSTRING
#define _INC_CORECRT_WSTRING

#include <corecrt.h>

__MINGW_BEGIN_C_DECLS

  _CRTIMP wchar_t *__cdecl wcscat(wchar_t *__restrict _Dest, const wchar_t *__restrict _Source) __NOTHROW __NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t  __cdecl wcscat_s(wchar_t *_Dst, rsize_t _SizeInWords, const wchar_t *_Src);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, wcscat_s, wchar_t, _Dest, const wchar_t *, _Source)
#endif
  _CRTIMP wchar_t *__cdecl wcscpy(wchar_t *__restrict _Dest, const wchar_t *__restrict _Source) __NOTHROW __NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t  __cdecl wcscpy_s(wchar_t *_Dst, rsize_t _SizeInWords, const wchar_t *_Src);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, wcscpy_s, wchar_t, _Dest, const wchar_t *, _Source)
#endif
  _CRTIMP wchar_t *__cdecl wcsncat(wchar_t *__restrict _Dest, const wchar_t *__restrict _Source, size_t _Count) __NOTHROW __NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t  __cdecl wcsncat_s(wchar_t *_Dst, size_t _DstSizeInChars, const wchar_t *_Src, size_t _MaxCount);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(errno_t, wcsncat_s, wchar_t, _Dst, const wchar_t *, _Src, size_t, _MaxCount)
#endif
  _CRTIMP wchar_t *__cdecl wcsncpy(wchar_t *__restrict _Dest, const wchar_t *__restrict _Source, size_t _Count) __NOTHROW __NONNULL((1, 2)) __MINGW_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t  __cdecl wcsncpy_s(wchar_t *_Dst, size_t _DstSizeInChars, const wchar_t *_Src, size_t _MaxCount);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(errno_t, wcsncpy_s, wchar_t, _Dest, const wchar_t *, _Source, size_t, _MaxCount)
#endif
  _CRTIMP wchar_t *__cdecl wcstok(wchar_t *__restrict _Str, const wchar_t *__restrict _Delim, wchar_t **__restrict _Ptr) __NOTHROW __NONNULL((2)) __MINGW_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str, const wchar_t *_Delim, wchar_t **_Context);
#endif

  _CRTIMP wchar_t *__cdecl _wcsdup(const wchar_t *_Str) __NOTHROW __ATTR_MALLOC __ATTR_DEALLOC_FREE __NONNULL((1));
  _CRTIMP int      __cdecl  wcscmp(const wchar_t *_Str1, const wchar_t *_Str2)    __NOTHROW __PURE __NONNULL((1, 2));
  _CRTIMP size_t   __cdecl  wcscspn(const wchar_t *_Str, const wchar_t *_Control) __NOTHROW __PURE __NONNULL((1, 2));
  _CRTIMP size_t   __cdecl  wcslen(const wchar_t *_Str)                           __NOTHROW __PURE __NONNULL((1));
#if defined(__MINGW_USE_XOPEN2K8) || defined(__MINGW_USE_MS)
  _CRTIMP size_t   __cdecl  wcsnlen(const wchar_t *_Src, size_t _MaxCount) __NOTHROW __PURE __NONNULL((1));
#endif

#ifdef __MINGW_USE_SECAPI
  __mingw_ovr
  size_t wcsnlen_s(const wchar_t *_src, size_t _count)
  {
    return _src ? wcsnlen(_src, _count) : 0;
  }
#endif

  _CRTIMP int    __cdecl wcsncmp(const wchar_t *_Str1, const wchar_t *_Str2, size_t _MaxCount) __NOTHROW __PURE __NONNULL((1, 2));
  _CRTIMP size_t __cdecl wcsspn(const wchar_t *_Str, const wchar_t *_Control)                  __NOTHROW __PURE __NONNULL((1, 2));

  extern wchar_t *__cdecl _wcstok(wchar_t *__restrict _Str, const wchar_t *__restrict _Delim) __NOTHROW __NONNULL((2)) __MINGW_DEPRECATED_SEC_WARN;
#ifndef __CRT__NO_INLINE
  __CRT_INLINE __NONNULL((2)) __MINGW_DEPRECATED_SEC_WARN
  __NTH_FNC(wchar_t *__cdecl _wcstok(wchar_t *__restrict _Str, const wchar_t *__restrict _Delim))
  {
    return wcstok(_Str, _Delim, NULL);
  }
#endif

#ifdef _CRT_NON_CONFORMING_WCSTOK
# ifndef __cplusplus
#   define wcstok _wcstok
# elif !defined(_CRT_NO_INLINE_DEPRECATED_WCSTOK)
  extern "C++" inline __NONNULL((2)) __MINGW_DEPRECATED_SEC_WARN
  wchar_t *__CRTDECL wcstok(wchar_t *_Str, const wchar_t *_Delim) __NOTHROW
  {
    return wcstok(_Str, _Delim, NULL);
  }
# endif
#endif  /* _CRT_NON_CONFORMING_WCSTOK */

  _CRTIMP wchar_t *__cdecl  _wcserror(int _ErrNum) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t  __cdecl  _wcserror_s(wchar_t *_Buf, size_t _SizeInWords, int _ErrNum);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _wcserror_s, wchar_t, buffer, int, error)
  _CRTIMP wchar_t *__cdecl __wcserror(const wchar_t *_Str) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t  __cdecl __wcserror_s(wchar_t *_Buffer, size_t _SizeInWords, const wchar_t *_ErrMsg);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, __wcserror_s, wchar_t, _Buffer, const wchar_t *, _ErrorMessage)
  _CRTIMP int      __cdecl  _wcsicmp(const wchar_t *_Str1, const wchar_t *_Str2);
  _CRTIMP int      __cdecl  _wcsicmp_l(const wchar_t *_Str1, const wchar_t *_Str2, _locale_t _Locale);
  _CRTIMP int      __cdecl  _wcsnicmp(const wchar_t *_Str1, const wchar_t *_Str2, size_t _MaxCount);
  _CRTIMP int      __cdecl  _wcsnicmp_l(const wchar_t *_Str1, const wchar_t *_Str2, size_t _MaxCount, _locale_t _Locale);
  _CRTIMP wchar_t *__cdecl  _wcsnset(wchar_t *_Str, wchar_t _Val, size_t _MaxCount) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t  __cdecl  _wcsnset_s(wchar_t *_Dst, size_t _DstSizeInWords, wchar_t _Val, size_t _MaxCount);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(errno_t, _wcsnset_s, wchar_t, _Destination, wchar_t, _Value, size_t, _MaxCount)
  _CRTIMP wchar_t *__cdecl  _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl  _wcsset(wchar_t *_Str, wchar_t _Val) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t  __cdecl  _wcsset_s(wchar_t *_Str, size_t _SizeInWords, wchar_t _Val);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _wcsset_s, wchar_t, _String, wchar_t, _Value)
  _CRTIMP wchar_t *__cdecl  _wcslwr(wchar_t *_String) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t  __cdecl  _wcslwr_s(wchar_t *_Str, size_t _SizeInWords);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, _wcslwr_s, wchar_t, _Str)
  _CRTIMP wchar_t *__cdecl  _wcslwr_l(wchar_t *_String, _locale_t _Locale) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t  __cdecl  _wcslwr_s_l(wchar_t *_Str, size_t _SizeInWords, _locale_t _Locale);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _wcslwr_s_l, wchar_t, _Str, _locale_t, _Locale)
  _CRTIMP wchar_t *__cdecl  _wcsupr(wchar_t *_String) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t  __cdecl  _wcsupr_s(wchar_t *_Str, size_t _Size);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, _wcsupr_s, wchar_t, _Str)
  _CRTIMP wchar_t *__cdecl  _wcsupr_l(wchar_t *_String, _locale_t _Locale) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t  __cdecl  _wcsupr_s_l(wchar_t *_Str, size_t _Size, _locale_t _Locale);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(errno_t, _wcsupr_s_l, wchar_t, _Str, _locale_t, _Locale)
  _CRTIMP size_t   __cdecl   wcsxfrm(wchar_t *__restrict _Dst, const wchar_t *__restrict _Src, size_t _MaxCount)                      __NOTHROW __NONNULL((2));
  _CRTIMP size_t   __cdecl  _wcsxfrm_l(wchar_t *__restrict _Dst, const wchar_t *__restrict _Src, size_t _MaxCount, _locale_t _Locale) __NOTHROW __NONNULL((2));
  _CRTIMP int      __cdecl   wcscoll(const wchar_t *_Str1, const wchar_t *_Str2)                       __NOTHROW __NONNULL((1, 2));
  _CRTIMP int      __cdecl  _wcscoll_l(const wchar_t *_Str1, const wchar_t *_Str2, _locale_t _Locale)  __NOTHROW __NONNULL((1, 2));
  _CRTIMP int      __cdecl  _wcsicoll(const wchar_t *_Str1, const wchar_t *_Str2)                      __NOTHROW __NONNULL((1, 2));
  _CRTIMP int      __cdecl  _wcsicoll_l(const wchar_t *_Str1, const wchar_t *_Str2, _locale_t _Locale) __NOTHROW __NONNULL((1, 2));
  _CRTIMP int      __cdecl  _wcsncoll(const wchar_t *_Str1, const wchar_t *_Str2, size_t _MaxCount);
  _CRTIMP int      __cdecl  _wcsncoll_l(const wchar_t *_Str1, const wchar_t *_Str2, size_t _MaxCount, _locale_t _Locale);
  _CRTIMP int      __cdecl  _wcsnicoll(const wchar_t *_Str1, const wchar_t *_Str2, size_t _MaxCount);
  _CRTIMP int      __cdecl  _wcsnicoll_l(const wchar_t *_Str1, const wchar_t *_Str2, size_t _MaxCount, _locale_t _Locale);

#ifdef __CORRECT_ISO_CPP_WCHAR_H_PROTO
  extern "C++"
  {
                  wchar_t *__cdecl wcschr(wchar_t *_Str, wchar_t _Ch)                    __ASM_CALL_NTH(wcschr)  __PURE __NONNULL((1));
    _CONST_RETURN wchar_t *__cdecl wcschr(const wchar_t *_Str, wchar_t _Ch)              __ASM_CALL_NTH(wcschr)  __PURE __NONNULL((1));
                  wchar_t *__cdecl wcsrchr(wchar_t *_Str, wchar_t _Ch)                   __ASM_CALL_NTH(wcsrchr) __PURE __NONNULL((1));
    _CONST_RETURN wchar_t *__cdecl wcsrchr(const wchar_t *_Str, wchar_t _Ch)             __ASM_CALL_NTH(wcsrchr) __PURE __NONNULL((1));
                  wchar_t *__cdecl wcspbrk(wchar_t *_Str, const wchar_t *_Control)       __ASM_CALL_NTH(wcspbrk) __PURE __NONNULL((1, 2));
    _CONST_RETURN wchar_t *__cdecl wcspbrk(const wchar_t *_Str, const wchar_t *_Control) __ASM_CALL_NTH(wcspbrk) __PURE __NONNULL((1, 2));
                  wchar_t *__cdecl wcsstr(wchar_t *_Str, const wchar_t *_SubStr)         __ASM_CALL_NTH(wcsstr)  __PURE __NONNULL((1, 2));
    _CONST_RETURN wchar_t *__cdecl wcsstr(const wchar_t *_Str, const wchar_t *_SubStr)   __ASM_CALL_NTH(wcsstr)  __PURE __NONNULL((1, 2));
                  wchar_t *__cdecl wcswcs(wchar_t *_Str, const wchar_t *_SubStr)         __ASM_CALL_NTH(wcswcs)  __PURE __NONNULL((1, 2));
    _CONST_RETURN wchar_t *__cdecl wcswcs(const wchar_t *_Str, const wchar_t *_SubStr)   __ASM_CALL_NTH(wcswcs)  __PURE __NONNULL((1, 2));
  }
#else
  _CRTIMP wchar_t *__cdecl wcschr(const wchar_t *_Str, wchar_t _Ch)              __NOTHROW __PURE __NONNULL((1));
  _CRTIMP wchar_t *__cdecl wcsrchr(const wchar_t *_Str, wchar_t _Ch)             __NOTHROW __PURE __NONNULL((1));
  _CRTIMP wchar_t *__cdecl wcspbrk(const wchar_t *_Str, const wchar_t *_Control) __NOTHROW __PURE __NONNULL((1, 2));
  _CRTIMP wchar_t *__cdecl wcsstr(const wchar_t *_Str, const wchar_t *_SubStr)   __NOTHROW __PURE __NONNULL((1, 2));
# if defined(__MINGW_USE_XOPEN) || defined(__MINGW_USE_MS)
  _CRTIMP wchar_t *__cdecl wcswcs(const wchar_t *_Str, const wchar_t *_SubStr)   __NOTHROW __PURE __NONNULL((1, 2));
# endif
#endif


#if defined(__MINGW_USE_XOPEN2K8) || defined(__MINGW_USE_MS)
  _CRTIMP wchar_t *__cdecl wcsdup(const wchar_t *_Str) __NOTHROW __ATTR_MALLOC __ATTR_DEALLOC_FREE __NONNULL((1)) __MINGW_DEPRECATED_MSVC2005;
#endif
#ifdef __MINGW_USE_MS
  _CRTIMP int      __cdecl wcsicmp(const wchar_t *_Str1, const wchar_t *_Str2)                    __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP int      __cdecl wcsnicmp(const wchar_t *_Str1, const wchar_t *_Str2, size_t _MaxCount) __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP wchar_t *__cdecl wcsnset(wchar_t *_Str, wchar_t _Val, size_t _MaxCount)                 __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP wchar_t *__cdecl wcsrev(wchar_t *_Str)                                                  __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP wchar_t *__cdecl wcsset(wchar_t *_Str, wchar_t _Val)                                    __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP wchar_t *__cdecl wcslwr(wchar_t *_Str)                                                  __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP wchar_t *__cdecl wcsupr(wchar_t *_Str)                                                  __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP int      __cdecl wcsicoll(const wchar_t *_Str1, const wchar_t *_Str2)                   __MINGW_DEPRECATED_MSVC2005;
#endif

__MINGW_END_C_DECLS

#include <ssp/wstring.h>

#endif  /* _INC_CORECRT_WSTRING */
