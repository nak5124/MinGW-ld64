/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_WCHAR
#define _INC_WCHAR

#include <corecrt.h>
#include <corecrt_wconio.h>
#include <corecrt_wstdio.h>
#include <corecrt_wstdlib.h>
#include <corecrt_wstring.h>

#if defined(__LIBMSVCRT__)
/* When building mingw-w64, this should be blank.  */
#define _SECIMP
#else
#ifndef _SECIMP
#define _SECIMP __declspec(dllimport)
#endif /* _SECIMP */
#endif /* defined(__LIBMSVCRT__) */

#pragma pack(push,_CRT_PACKING)

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WCHAR_MIN  /* also in stdint.h */
#define WCHAR_MIN 0U
#define WCHAR_MAX 0xffffU
#endif

#ifndef _FSIZE_T_DEFINED
  typedef unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _WFINDDATA_T_DEFINED
  struct _wfinddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  struct _wfinddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __MINGW_EXTENSION __int64 size;
    wchar_t name[260];
  };

  struct _wfinddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  struct _wfinddata64_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __MINGW_EXTENSION __int64 size;
    wchar_t name[260];
  };
/* #endif */

#ifdef _USE_32BIT_TIME_T
#define _wfinddata_t _wfinddata32_t
#define _wfinddatai64_t _wfinddata32i64_t

#define _wfindfirst _wfindfirst32
#define _wfindnext _wfindnext32
#define _wfindfirst32i64 _wfindfirsti64
#define _wfindnext32i64 _wfindnexti64
#else
#define _wfinddata_t _wfinddata64i32_t
#define _wfinddatai64_t _wfinddata64_t

#define _wfindfirst _wfindfirst64i32
#define _wfindnext _wfindnext64i32
#define _wfindfirsti64 _wfindfirst64
#define _wfindnexti64 _wfindnext64
#endif

#define _WFINDDATA_T_DEFINED
#endif

#ifndef _CONST_RETURN
#define _CONST_RETURN
#endif

#define _WConst_return _CONST_RETURN

#ifndef _CRT_CTYPEDATA_DEFINED
#define _CRT_CTYPEDATA_DEFINED
#ifndef _CTYPE_DISABLE_MACROS

#ifndef __PCTYPE_FUNC
#define __PCTYPE_FUNC __pctype_func()
  _CRTIMP const unsigned short* __pctype_func(void);
#endif

#ifndef _pctype
#define _pctype (__pctype_func())
#endif
#endif
#endif

#ifndef _CRT_WCTYPEDATA_DEFINED
#define _CRT_WCTYPEDATA_DEFINED
#ifndef _CTYPE_DISABLE_MACROS
#if !defined(_wctype) && defined(_CRT_USE_WINAPI_FAMILY_DESKTOP_APP)
  extern const unsigned short ** __MINGW_IMP_SYMBOL(_wctype);
#define _wctype (* __MINGW_IMP_SYMBOL(_wctype))
#endif

  _CRTIMP const wctype_t * __cdecl __pwctype_func(void);
#ifndef _pwctype
#define _pwctype (__pwctype_func())
#endif

#endif
#endif

#define _UPPER 0x1
#define _LOWER 0x2
#define _DIGIT 0x4
#define _SPACE 0x8

#define _PUNCT 0x10
#define _CONTROL 0x20
#define _BLANK 0x40
#define _HEX 0x80

#define _LEADBYTE 0x8000
#define _ALPHA (0x0100|_UPPER|_LOWER)

#ifndef _WCTYPE_DEFINED
#define _WCTYPE_DEFINED

  int __cdecl iswalpha(wint_t _C);
  _CRTIMP int __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  int __cdecl iswupper(wint_t _C);
  _CRTIMP int __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  int __cdecl iswlower(wint_t _C);
  _CRTIMP int __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  int __cdecl iswdigit(wint_t _C);
  _CRTIMP int __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  int __cdecl iswxdigit(wint_t _C);
  _CRTIMP int __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  int __cdecl iswspace(wint_t _C);
  _CRTIMP int __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  int __cdecl iswpunct(wint_t _C);
  _CRTIMP int __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  int __cdecl iswalnum(wint_t _C);
  _CRTIMP int __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  int __cdecl iswprint(wint_t _C);
  _CRTIMP int __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  int __cdecl iswgraph(wint_t _C);
  _CRTIMP int __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  int __cdecl iswcntrl(wint_t _C);
  _CRTIMP int __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  int __cdecl iswascii(wint_t _C);
#ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
  int __cdecl isleadbyte(int _C);
  _CRTIMP int __cdecl _isleadbyte_l(int _C,_locale_t _Locale);
#endif /* _CRT_USE_WINAPI_FAMILY_DESKTOP_APP */
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  int __cdecl iswctype(wint_t _C,wctype_t _Type);
#if __MSVCRT_VERSION__ >= 0x800
  _CRTIMP int __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP int __cdecl __iswcsymf(wint_t _C);
  _CRTIMP int __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP int __cdecl __iswcsym(wint_t _C);
  _CRTIMP int __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
#endif
#ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
  int __cdecl is_wctype(wint_t _C,wctype_t _Type);
#endif /* _CRT_USE_WINAPI_FAMILY_DESKTOP_APP */

#if (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES) || defined (__cplusplus)
  int __cdecl iswblank(wint_t _C);
#endif

#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED

  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,int _SizeInWords);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(int _Drive,wchar_t *_DstBuf,int _SizeInWords);
#if __MSVCRT_VERSION__ >= 0x800
  wchar_t *__cdecl _wgetdcwd_nolock(int _Drive,wchar_t *_DstBuf,int _SizeInWords);
#endif
  _CRTIMP int __cdecl _wchdir(const wchar_t *_Path);
  _CRTIMP int __cdecl _wmkdir(const wchar_t *_Path);
  _CRTIMP int __cdecl _wrmdir(const wchar_t *_Path);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED

  _CRTIMP int __cdecl _waccess(const wchar_t *_Filename,int _AccessMode);
  _CRTIMP int __cdecl _wchmod(const wchar_t *_Filename,int _Mode);
  _CRTIMP int __cdecl _wcreat(const wchar_t *_Filename,int _PermissionMode) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP intptr_t __cdecl _wfindfirst32(const wchar_t *_Filename,struct _wfinddata32_t *_FindData);
  _CRTIMP int __cdecl _wfindnext32(intptr_t _FindHandle,struct _wfinddata32_t *_FindData);
  _CRTIMP int __cdecl _wunlink(const wchar_t *_Filename);
  _CRTIMP int __cdecl _wrename(const wchar_t *_OldFilename,const wchar_t *_NewFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(const wchar_t *_Filename,struct _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(const wchar_t *_Filename,struct _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(const wchar_t *_Filename,struct _wfinddata64_t *_FindData);
  _CRTIMP int __cdecl _wfindnext32i64(intptr_t _FindHandle,struct _wfinddata32i64_t *_FindData);
  int __cdecl _wfindnext64i32(intptr_t _FindHandle,struct _wfinddata64i32_t *_FindData);
  _CRTIMP int __cdecl _wfindnext64(intptr_t _FindHandle,struct _wfinddata64_t *_FindData);
  _CRTIMP errno_t __cdecl _wsopen_s(int *_FileHandle,const wchar_t *_Filename,int _OpenFlag,int _ShareFlag,int _PermissionFlag);
  _CRTIMP int __cdecl _wopen(const wchar_t *_Filename,int _OpenFlag,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl _wsopen(const wchar_t *_Filename,int _OpenFlag,int _ShareFlag,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#endif

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(int _Category,const wchar_t *_Locale);
#endif

#ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
#ifndef _WEXEC_DEFINED
#define _WEXEC_DEFINED
  _CRTIMP intptr_t __cdecl _wexecl(const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(const wchar_t *_Filename,const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(const wchar_t *_Filename,const wchar_t *const *_ArgList,const wchar_t *const *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(const wchar_t *_Filename,const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(const wchar_t *_Filename,const wchar_t *const *_ArgList,const wchar_t *const *_Env);
#endif

#ifndef _WSPAWN_DEFINED
#define _WSPAWN_DEFINED
  _CRTIMP intptr_t __cdecl _wspawnl(int _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(int _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(int _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(int _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(int _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(int _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList,const wchar_t *const *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(int _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(int _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList,const wchar_t *const *_Env);
#endif

#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP int __cdecl _wsystem(const wchar_t *_Command);
#endif
#endif /* _CRT_USE_WINAPI_FAMILY_DESKTOP_APP */

#ifndef _WCTYPE_INLINE_DEFINED
#undef _CRT_WCTYPE_NOINLINE
#if !defined(__cplusplus) || defined(_CRT_WCTYPE_NOINLINE)
#define iswalpha(_c) (iswctype(_c,_ALPHA))
#define iswupper(_c) (iswctype(_c,_UPPER))
#define iswlower(_c) (iswctype(_c,_LOWER))
#define iswdigit(_c) (iswctype(_c,_DIGIT))
#define iswxdigit(_c) (iswctype(_c,_HEX))
#define iswspace(_c) (iswctype(_c,_SPACE))
#define iswpunct(_c) (iswctype(_c,_PUNCT))
#define iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#define iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#define iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#define iswcntrl(_c) (iswctype(_c,_CONTROL))
#define iswascii(_c) ((unsigned)(_c) < 0x80)

#define _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#define _iswupper_l(_c,_p) (_iswctype_l(_c,_UPPER,_p))
#define _iswlower_l(_c,_p) (_iswctype_l(_c,_LOWER,_p))
#define _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#define _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#define _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#define _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#define _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#define _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#define _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#define _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#if !defined(_CTYPE_DISABLE_MACROS) && defined(_CRT_USE_WINAPI_FAMILY_DESKTOP_APP)
#define isleadbyte(_c) (__PCTYPE_FUNC[(unsigned char)(_c)] & _LEADBYTE)
#endif
#endif
#define _WCTYPE_INLINE_DEFINED
#endif

#if !defined(_POSIX_) || defined(__GNUC__)
#ifndef _INO_T_DEFINED
#define _INO_T_DEFINED
  typedef unsigned short _ino_t;
#ifndef	NO_OLDNAMES
  typedef unsigned short ino_t;
#endif
#endif

#ifndef _DEV_T_DEFINED
#define _DEV_T_DEFINED
  typedef unsigned int _dev_t;
#ifndef	NO_OLDNAMES
  typedef unsigned int dev_t;
#endif
#endif

#include <_mingw_off_t.h>
#include <_mingw_stat64.h>

#ifndef _WSTAT_DEFINED
#define _WSTAT_DEFINED

  _CRTIMP int __cdecl _wstat32(const wchar_t *_Name,struct _stat32 *_Stat);
  _CRTIMP int __cdecl _wstat32i64(const wchar_t *_Name,struct _stat32i64 *_Stat);
  int __cdecl _wstat64i32(const wchar_t *_Name,struct _stat64i32 *_Stat);
  _CRTIMP int __cdecl _wstat64(const wchar_t *_Name,struct _stat64 *_Stat);
#endif
#endif

#ifndef _TM_DEFINED
#define _TM_DEFINED
  struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
  };
#endif

#ifndef _WTIME_DEFINED
#define _WTIME_DEFINED

  _CRTIMP wchar_t *__cdecl _wasctime(const struct tm *_Tm);
  _SECIMP errno_t __cdecl _wasctime_s (wchar_t *_Buf,size_t _SizeInWords,const struct tm *_Tm);
  wchar_t *__cdecl _wctime32(const __time32_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _SECIMP errno_t __cdecl _wctime32_s (wchar_t *_Buf,size_t _SizeInWords,const __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t * __restrict__ _Buf,size_t _SizeInWords,const wchar_t * __restrict__ _Format,const struct tm * __restrict__ _Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t * __restrict__ _Buf,size_t _SizeInWords,const wchar_t * __restrict__ _Format,const struct tm * __restrict__ _Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _SECIMP errno_t __cdecl _wstrdate_s (wchar_t *_Buf,size_t _SizeInWords);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _SECIMP errno_t __cdecl _wstrtime_s (wchar_t *_Buf,size_t _SizeInWords);
  _CRTIMP wchar_t *__cdecl _wctime64(const __time64_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _SECIMP errno_t __cdecl _wctime64_s (wchar_t *_Buf,size_t _SizeInWords,const __time64_t *_Time);

#if !defined (RC_INVOKED) && !defined (_INC_WTIME_INL)
#define _INC_WTIME_INL
  wchar_t *__cdecl _wctime(const time_t *_Time) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifndef __CRT__NO_INLINE
#ifndef _USE_32BIT_TIME_T
  __CRT_INLINE wchar_t *__cdecl _wctime(const time_t *_Time) { return _wctime64(_Time); }
#else
  __CRT_INLINE wchar_t *__cdecl _wctime(const time_t *_Time) { return _wctime32(_Time); }
#endif
#endif /* __CRT__NO_INLINE */
#endif

#if !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#define _INC_WTIME_S_INL
  errno_t __cdecl _wctime_s(wchar_t *, size_t, const time_t *);
#ifndef __CRT__NO_INLINE
#ifndef _USE_32BIT_TIME_T
  __CRT_INLINE errno_t __cdecl _wctime_s (wchar_t *_Buffer,size_t _SizeInWords,const time_t *_Time) { return _wctime64_s (_Buffer,_SizeInWords,_Time); }
#else
  __CRT_INLINE errno_t __cdecl _wctime_s (wchar_t *_Buffer,size_t _SizeInWords,const time_t *_Time) { return _wctime32_s (_Buffer,_SizeInWords,_Time); }
#endif /* _USE_32BIT_TIME_T */
#endif  /* __CRT__NO_INLINE */
#endif /* !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL) */

#endif

#if defined(_UCRT) || defined(__LARGE_MBSTATE_T)
  typedef struct _Mbstatet {
    unsigned long _Wchar;
    unsigned short _Byte, _State;
  } _Mbstatet;
  typedef _Mbstatet mbstate_t;
#else
  typedef int mbstate_t;
#endif
  typedef wchar_t _Wint_t;

  wint_t __cdecl btowc(int);
  size_t __cdecl mbrlen(const char * __restrict__ _Ch,size_t _SizeInBytes,mbstate_t * __restrict__ _State);
  size_t __cdecl mbrtowc(wchar_t * __restrict__ _DstCh,const char * __restrict__ _SrcCh,size_t _SizeInBytes,mbstate_t * __restrict__ _State);
  size_t __cdecl mbsrtowcs(wchar_t * __restrict__ _Dest,const char ** __restrict__ _PSrc,size_t _Count,mbstate_t * __restrict__ _State) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  size_t __cdecl wcrtomb(char * __restrict__ _Dest,wchar_t _Source,mbstate_t * __restrict__ _State) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  size_t __cdecl wcsrtombs(char * __restrict__ _Dest,const wchar_t ** __restrict__ _PSource,size_t _Count,mbstate_t * __restrict__ _State) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  int __cdecl wctob(wint_t _WCh);

#ifndef __NO_ISOCEXT /* these need static lib libmingwex.a */
  wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, size_t n);
  _CONST_RETURN wchar_t *__cdecl wmemchr(const wchar_t *s, wchar_t c, size_t n);
  int __cdecl wmemcmp(const wchar_t *s1, const wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemcpy(wchar_t * __restrict__ s1,const wchar_t * __restrict__ s2,size_t n) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifdef _GNU_SOURCE
  wchar_t * __cdecl wmempcpy (wchar_t *_Dst, const wchar_t *_Src, size_t _Size);
#endif
  wchar_t *__cdecl wmemmove(wchar_t *s1, const wchar_t *s2, size_t n) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  int __cdecl fwide(FILE *stream,int mode);
#if defined(_UCRT) || defined(__LARGE_MBSTATE_T)
  /* With UCRT, mbsinit is only available as inline. */
  __mingw_ovr int __cdecl mbsinit(const mbstate_t *_P) { return (!_P || _P->_Wchar == 0); }
#else
  int __cdecl mbsinit(const mbstate_t *ps);
#endif
  __MINGW_EXTENSION long long __cdecl wcstoll(const wchar_t * __restrict__ nptr,wchar_t ** __restrict__ endptr, int base);
  __MINGW_EXTENSION unsigned long long __cdecl wcstoull(const wchar_t * __restrict__ nptr,wchar_t ** __restrict__ endptr, int base);
#endif /* __NO_ISOCEXT */

  void *__cdecl memmove(void *_Dst,const void *_Src,size_t _MaxCount);
  void *__cdecl memcpy(void * __restrict__ _Dst,const void * __restrict__ _Src,size_t _MaxCount) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifndef __CRT__NO_INLINE
  __CRT_INLINE int __cdecl fwide(FILE *_F,int _M) { (void)_F; return (_M); }
#if !defined(_UCRT) && !defined(__LARGE_MBSTATE_T)
  __CRT_INLINE int __cdecl mbsinit(const mbstate_t *_P) { return (!_P || *_P==0); }
#endif
  __CRT_INLINE _CONST_RETURN wchar_t *__cdecl wmemchr(const wchar_t *_S,wchar_t _C,size_t _N) {
    if (_S) {
      for ( ; 0 < _N; ++_S, --_N)
	if (*_S == _C)
	  return (_CONST_RETURN wchar_t *)(_S);
    }
    return (_CONST_RETURN wchar_t *) NULL;
  }
  __CRT_INLINE int __cdecl wmemcmp(const wchar_t *_S1,const wchar_t *_S2,size_t _N) {
    if (_N == 0 || _S1 == _S2)
      return 0;	/* even for NULL pointers.  */
    if ((_S1 && !(_S2)) || (_S2 && !(_S1)))
      return !(_S2) ? 1 : -1; /* robust.  */
    for ( ; 0 < _N; ++_S1, ++_S2, --_N)
      if (*_S1 != *_S2)
	return (*_S1 < *_S2 ? -1 : +1);
    return 0;
  }
  __CRT_INLINE wchar_t *__cdecl wmemcpy(wchar_t * __restrict__ _S1,const wchar_t * __restrict__ _S2,size_t _N)
  {
    return (wchar_t *) memcpy (_S1,_S2,_N*sizeof(wchar_t));
  }
  __CRT_INLINE wchar_t *__cdecl wmemmove(wchar_t *_S1,const wchar_t *_S2,size_t _N) { return (wchar_t *)memmove(_S1,_S2,_N*sizeof(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemset(wchar_t *_S,wchar_t _C,size_t _N) {
    wchar_t *_Su = _S;
    for (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    return (_S);
  }
#endif /* !__CRT__NO_INLINE */

#ifdef __cplusplus
}
#endif

#pragma pack(pop)

#include <sec_api/wchar_s.h>

#endif /* _INC_WCHAR */

