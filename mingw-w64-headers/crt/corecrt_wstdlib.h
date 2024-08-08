/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CORECRT_WSTDLIB
#define _INC_CORECRT_WSTDLIB

#include <corecrt.h>

__MINGW_BEGIN_C_DECLS

#define _MAX_ITOSTR_BASE16_COUNT   (8  + 1)
#define _MAX_ITOSTR_BASE10_COUNT   (1 + 10 + 1)
#define _MAX_ITOSTR_BASE8_COUNT    (11 + 1)
#define _MAX_ITOSTR_BASE2_COUNT    (32 + 1)

#define _MAX_LTOSTR_BASE16_COUNT   (8  + 1)
#define _MAX_LTOSTR_BASE10_COUNT   (1 + 10 + 1)
#define _MAX_LTOSTR_BASE8_COUNT    (11 + 1)
#define _MAX_LTOSTR_BASE2_COUNT    (32 + 1)

#define _MAX_ULTOSTR_BASE16_COUNT  (8  + 1)
#define _MAX_ULTOSTR_BASE10_COUNT  (10 + 1)
#define _MAX_ULTOSTR_BASE8_COUNT   (11 + 1)
#define _MAX_ULTOSTR_BASE2_COUNT   (32 + 1)

#define _MAX_I64TOSTR_BASE16_COUNT (16 + 1)
#define _MAX_I64TOSTR_BASE10_COUNT (1 + 19 + 1)
#define _MAX_I64TOSTR_BASE8_COUNT  (22 + 1)
#define _MAX_I64TOSTR_BASE2_COUNT  (64 + 1)

#define _MAX_U64TOSTR_BASE16_COUNT (16 + 1)
#define _MAX_U64TOSTR_BASE10_COUNT (20 + 1)
#define _MAX_U64TOSTR_BASE8_COUNT  (22 + 1)
#define _MAX_U64TOSTR_BASE2_COUNT  (64 + 1)

  _CRTIMP wchar_t *__cdecl _itow(int _Value, wchar_t *_Dest, int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _itow_s(int _Value, wchar_t *_Buffer, size_t _BufferCount, int _Radix);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_1(errno_t, _itow_s, int, _Value, wchar_t, _Buffer, int, _Radix)
  _CRTIMP wchar_t *__cdecl _ltow(long _Value, wchar_t *_Dest, int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _ltow_s(long _Value, wchar_t *_Buffer, size_t _BufferCount, int _Radix);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_1(errno_t, _ltow_s, long, _Value, wchar_t, _Buffer, int, _Radix)
  _CRTIMP wchar_t *__cdecl _ultow(unsigned long _Value, wchar_t *_Dest, int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _ultow_s(unsigned long _Value, wchar_t *_Buffer, size_t _BufferCount, int _Radix);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_1(errno_t, _ultow_s, unsigned long, _Value, wchar_t, _Buffer, int, _Radix)
  _CRTIMP double __cdecl wcstod(const wchar_t * __restrict__ _Str, wchar_t ** __restrict__ _EndPtr) __MINGW_NONNULL((1));
  _CRTIMP double __cdecl _wcstod_l(const wchar_t * __restrict__ _Str, wchar_t ** __restrict__ _EndPtr, _locale_t _Locale);
  _CRTIMP long __cdecl wcstol(const wchar_t * __restrict__ _Str, wchar_t ** __restrict__ _EndPtr, int _Radix) __MINGW_NONNULL((1));
  _CRTIMP long __cdecl _wcstol_l(const wchar_t * __restrict__ _Str, wchar_t ** __restrict__ _EndPtr, int _Radix, _locale_t _Locale);
#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)
  __MINGW_EXTENSION _CRTIMP long long __cdecl wcstoll(const wchar_t * __restrict__ _Str, wchar_t ** __restrict__ _EndPtr, int _Radix) __MINGW_NONNULL((1));
#endif
  __MINGW_EXTENSION _CRTIMP long long __cdecl _wcstoll_l(const wchar_t * __restrict__ _String, wchar_t ** __restrict__ _EndPtr, int _Radix, _locale_t _Locale);
  _CRTIMP unsigned long __cdecl wcstoul(const wchar_t * __restrict__ _Str, wchar_t ** __restrict__ _EndPtr, int _Radix) __MINGW_NONNULL((1));
  _CRTIMP unsigned long __cdecl _wcstoul_l(const wchar_t * __restrict__ _Str, wchar_t ** __restrict__ _EndPtr, int _Radix, _locale_t _Locale);
#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)
  __MINGW_EXTENSION _CRTIMP unsigned long long __cdecl wcstoull(const wchar_t * __restrict__ _String, wchar_t ** __restrict__ _EndPtr, int _Radix) __MINGW_NONNULL((1));
#endif
  __MINGW_EXTENSION _CRTIMP unsigned long long __cdecl _wcstoull_l(const wchar_t * __restrict__ _String, wchar_t ** __restrict__ _EndPtr, int _Radix, _locale_t _Locale);
#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)
  _LDCRTIMP long double __cdecl wcstold(const wchar_t * __restrict__ _String, wchar_t ** __restrict__ _EndPtr) __MINGW_NONNULL((1));
#endif
#if defined(__aarch64__) || defined(_ARM64_)
  _LDCRTIMP long double __cdecl _wcstold_l(const wchar_t * __restrict__ _String, wchar_t ** __restrict__ _EndPtr, _locale_t _Locale);
#endif
#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)
  _CRTIMP float __cdecl wcstof(const wchar_t * __restrict__ _Str, wchar_t ** __restrict__ _EndPtr) __MINGW_NONNULL((1));
#endif
  _CRTIMP float __cdecl _wcstof_l(const wchar_t * __restrict__ _Str, wchar_t ** __restrict__ _EndPtr, _locale_t _Locale);
  _CRTIMP double __cdecl _wtof(const wchar_t *_Str);
  _CRTIMP double __cdecl _wtof_l(const wchar_t *_Str, _locale_t _Locale);
  _CRTIMP int __cdecl _wtoi(const wchar_t *_Str);
  _CRTIMP int __cdecl _wtoi_l(const wchar_t *_Str, _locale_t _Locale);
  _CRTIMP long __cdecl _wtol(const wchar_t *_Str);
  _CRTIMP long __cdecl _wtol_l(const wchar_t *_Str, _locale_t _Locale);
  __MINGW_EXTENSION _CRTIMP long long __cdecl _wtoll(const wchar_t *_String);
  __MINGW_EXTENSION _CRTIMP long long __cdecl _wtoll_l(const wchar_t *_String, _locale_t _Locale);
  __MINGW_EXTENSION _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val, wchar_t *_DstBuf, int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  __MINGW_EXTENSION _CRTIMP errno_t __cdecl _i64tow_s(__int64  _Value, wchar_t *_Buffer, size_t _BufferCount, int _Radix);
  __MINGW_EXTENSION _CRTIMP wchar_t *__cdecl _ui64tow(unsigned __int64 _Val, wchar_t *_DstBuf, int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  __MINGW_EXTENSION _CRTIMP errno_t __cdecl _ui64tow_s(unsigned __int64  _Value, wchar_t *_Buffer, size_t _BufferCount, int _Radix);
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _wtoi64(const wchar_t *_Str);
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _wtoi64_l(const wchar_t *_Str, _locale_t _Locale);
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _wcstoi64(const wchar_t *_Str, wchar_t **_EndPtr, int _Radix);
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _wcstoi64_l(const wchar_t *_Str, wchar_t **_EndPtr, int _Radix, _locale_t _Locale);
  __MINGW_EXTENSION _CRTIMP unsigned __int64 __cdecl _wcstoui64(const wchar_t *_Str, wchar_t **_EndPtr, int _Radix);
  __MINGW_EXTENSION _CRTIMP unsigned __int64 __cdecl _wcstoui64_l(const wchar_t *_Str, wchar_t **_EndPtr, int _Radix, _locale_t _Locale);

#pragma push_macro("_wfullpath")
#undef _wfullpath
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath, const wchar_t *_Path, size_t _SizeInWords);
#pragma pop_macro("_wfullpath")
  _CRTIMP void __cdecl _wmakepath(wchar_t *_ResultPath, const wchar_t *_Drive, const wchar_t *_Dir, const wchar_t *_Filename, const wchar_t *_Ext) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *_Buffer, size_t _BufferCount, const wchar_t *_Drive, const wchar_t *_Dir, const wchar_t *_Filename, const wchar_t *_Ext);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_4(errno_t, _wmakepath_s, wchar_t, _Buffer, const wchar_t *, _Drive, const wchar_t *, _Dir, const wchar_t *, _Filename, const wchar_t *, _Ext)
#ifndef _CRT_WPERROR_DEFINED  /* Also in corecrt_wstdio.h */
# define _CRT_WPERROR_DEFINED
  _CRTIMP void __cdecl _wperror(const wchar_t *_ErrMsg);
#endif  /* _CRT_WPERROR_DEFINED */
  _CRTIMP void __cdecl _wsplitpath(const wchar_t *_FullPath, wchar_t *_Drive, wchar_t *_Dir, wchar_t *_Filename, wchar_t *_Ext) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _wsplitpath_s(const wchar_t *_FullPath, wchar_t *_Drive, size_t _DriveCount, wchar_t *_Dir, size_t _DirCount, wchar_t *_Filename, size_t _FilenameCount, wchar_t *_Ext, size_t _ExtCount);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_SPLITPATH(errno_t, _wsplitpath_s, wchar_t, _Path)

  _CRTIMP wchar_t *__cdecl _wgetenv(const wchar_t *_VarName) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _wgetenv_s(size_t *_RequiredCount, wchar_t *_Buffer, size_t _BufferCount, const wchar_t *_VarName);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_1(errno_t, _wgetenv_s, size_t *, _RequiredCount, wchar_t, _Buffer, const wchar_t *, _VarName)
#pragma push_macro("_wdupenv_s")
#undef _wdupenv_s
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **_Buffer, size_t *_BufferCount, const wchar_t *_VarName);
#pragma pop_macro("_wdupenv_s")

#ifndef _CRT_WSYSTEM_DEFINED  /* Also in corecrt_wprocess.h */
# define _CRT_WSYSTEM_DEFINED
  _CRTIMP int __cdecl _wsystem(const wchar_t *_Command);
#endif  /* _CRT_WSYSTEM_DEFINED */

  _CRTIMP int __cdecl _wputenv(const wchar_t *_EnvString);
  _CRTIMP errno_t __cdecl _wputenv_s(const wchar_t *_Name, const wchar_t *_Value);
  _CRTIMP void __cdecl _wsearchenv(const wchar_t *_Filename, const wchar_t *_EnvVar, wchar_t *_ResultPath) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _wsearchenv_s(const wchar_t *_Filename, const wchar_t *_VarName, wchar_t *_Buffer, size_t _BufferCount);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_2_0(errno_t, _wsearchenv_s, const wchar_t *, _Filename, const wchar_t *, _VarName, wchar_t, _ResultPath)

#ifndef __STRICT_ANSI__
  __MINGW_EXTENSION long long __cdecl wtoll(const wchar_t *_String);
  __MINGW_EXTENSION wchar_t *__cdecl lltow(long long _Val, wchar_t *_DstBuf, int _Radix);
  __MINGW_EXTENSION wchar_t *__cdecl ulltow(unsigned long long _Val, wchar_t *_DstBuf, int _Radix);
#endif  /* __STRICT_ANSI__ */

__MINGW_END_C_DECLS

#endif  /* _INC_CORECRT_WSTDLIB */
