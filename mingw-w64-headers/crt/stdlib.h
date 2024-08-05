/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_STDLIB
#define _INC_STDLIB

#include <corecrt.h>
#include <search.h>
#include <corecrt_wstdlib.h>
#include <limits.h>

__MINGW_BEGIN_C_DECLS

#ifndef _countof
# ifndef __cplusplus
#   define _countof(_Array) (sizeof(_Array) / sizeof(_Array[0]))
# else
    extern "C++"
    {
      template <typename _CountofType, size_t _SizeOfArray>
      char (*__countof_helper(UNALIGNED _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];
      #define _countof(_Array) (sizeof(*__countof_helper(_Array)) + 0)
    }
# endif
#endif

#define __max(a, b) (((a) > (b)) ? (a) : (b))
#define __min(a, b) (((a) < (b)) ? (a) : (b))

  _CRTIMP void __cdecl _swab(char *_Buf1, char *_Buf2, int _SizeInBytes);

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#ifndef _CRT_TERMINATE_DEFINED  /* Also in process.h */
# define _CRT_TERMINATE_DEFINED
  extern void __cdecl __MINGW_NOTHROW exit(int _Code) __MINGW_ATTRIB_NORETURN;
  extern void __cdecl __MINGW_NOTHROW _exit(int _Code) __MINGW_ATTRIB_NORETURN;
# if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)
    extern void __cdecl _Exit(int) __MINGW_ATTRIB_NORETURN;
# endif
# if defined(__MINGW_USE_ISOC11) || defined(__MINGW_USE_ISOCXX11)
    extern void __cdecl __MINGW_NOTHROW quick_exit(int _Code) __MINGW_ATTRIB_NORETURN;
# endif
# pragma push_macro("abort")
# undef abort
  _CRTIMP void __cdecl __MINGW_ATTRIB_NORETURN abort(void);
# pragma pop_macro("abort")
#endif  /* _CRT_TERMINATE_DEFINED */

#define _WRITE_ABORT_MSG  0x1
#define _CALL_REPORTFAULT 0x2

  _CRTIMP unsigned int __cdecl _set_abort_behavior(unsigned int _Flags, unsigned int _Mask);

#ifndef _ONEXIT_T_DEFINED
# define _ONEXIT_T_DEFINED

  typedef int (__cdecl *_onexit_t)(void);

# ifdef __MINGW_USE_MS
#   define onexit_t _onexit_t
# endif
#endif

  extern int __cdecl atexit(void (__cdecl *)(void));
  extern _onexit_t __cdecl _onexit(_onexit_t _Func);
#if defined(__MINGW_USE_ISOC11) || defined(__MINGW_USE_ISOCXX11)
  extern int __cdecl at_quick_exit(void (__cdecl *)(void));
#endif

  typedef void (__cdecl *_purecall_handler)(void);
  typedef void (__cdecl *_invalid_parameter_handler)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, uintptr_t);
  _CRTIMP _purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(void);
  _CRTIMP _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _CRTIMP _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(void);
  _CRTIMP _invalid_parameter_handler __cdecl _set_thread_local_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _CRTIMP _invalid_parameter_handler __cdecl _get_thread_local_invalid_parameter_handler(void);

#define _OUT_TO_DEFAULT 0
#define _OUT_TO_STDERR  1
#define _OUT_TO_MSGBOX  2
#define _REPORT_ERRMODE 3

  _CRTIMP int __cdecl _set_error_mode(int _Mode);

#ifndef _CRT_ERRNO_DEFINED  /* Also in errno.h and stddef.h */
# define _CRT_ERRNO_DEFINED
  _CRTIMP int *__cdecl _errno(void);
# define errno (*_errno())
  _CRTIMP errno_t __cdecl _set_errno(int _Value);
  _CRTIMP errno_t __cdecl _get_errno(int *_Value);
#endif  /* _CRT_ERRNO_DEFINED */
#ifndef _DOSERRNO_DEFINED  /* Also in errno.h */
# define _DOSERRNO_DEFINED
  _CRTIMP unsigned long *__cdecl __doserrno(void);
#define _doserrno (*__doserrno())
  _CRTIMP errno_t __cdecl _set_doserrno(unsigned long _Value);
  _CRTIMP errno_t __cdecl _get_doserrno(unsigned long *_Value);
#endif  /* _DOSERRNO_DEFINED */
  _CRTIMP char **__cdecl __sys_errlist(void) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#define _sys_errlist (__sys_errlist())
  _CRTIMP int *__cdecl __sys_nerr(void) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#define _sys_nerr (*__sys_nerr())
#ifndef _CRT_PERROR_DEFINED  /* Also in stdio.h */
# define _CRT_PERROR_DEFINED
  _CRTIMP void __cdecl perror(const char *_ErrMsg);
#endif  /* _CRT_PERROR_DEFINED */

  _CRTIMP char **__cdecl __p__pgmptr(void) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(void) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP int *__cdecl __p__fmode(void) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;

#ifndef _pgmptr
# define _pgmptr (* __p__pgmptr())
#endif

#ifndef _wpgmptr
# define _wpgmptr (* __p__wpgmptr())
#endif

#ifndef _fmode
# define _fmode (* __p__fmode())
#endif

  _CRTIMP errno_t __cdecl _get_pgmptr(char **_Value);
  _CRTIMP errno_t __cdecl _get_wpgmptr(wchar_t **_Value);
  _CRTIMP errno_t __cdecl _set_fmode(int _Mode);
  _CRTIMP errno_t __cdecl _get_fmode(int *_PMode);

  typedef struct _div_t
  {
    int quot;
    int rem;
  } div_t;

  typedef struct _ldiv_t
  {
    long quot;
    long rem;
  } ldiv_t;

#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)
  typedef struct _lldiv_t
  {
    __MINGW_EXTENSION long long quot;
    __MINGW_EXTENSION long long rem;
  } lldiv_t;
#endif

#ifndef _CRT_ABS_DEFINED  /* Also in math.h */
# define _CRT_ABS_DEFINED
  int __cdecl abs(int _X);
  long __cdecl labs(long _X);
# if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)
    __MINGW_EXTENSION long long __cdecl llabs(long long _X);
# endif
#endif  /* _CRT_ABS_DEFINED */
  __MINGW_EXTENSION __int64 __cdecl _abs64(__int64 _X);

  unsigned short __cdecl _byteswap_ushort(unsigned short _Short);
  unsigned long __cdecl _byteswap_ulong(unsigned long _Long);
  __MINGW_EXTENSION unsigned __int64 __cdecl _byteswap_uint64(unsigned __int64 _Int64);

  _CRTIMP div_t __cdecl div(int _Numerator, int _Denominator);
  _CRTIMP ldiv_t __cdecl ldiv(long _Numerator, long _Denominator);
#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)
  __MINGW_EXTENSION _CRTIMP lldiv_t __cdecl lldiv(long long _Numerator, long long _Denominator);
#endif

#pragma push_macro("_rotl")
#undef _rotl
  unsigned int __cdecl _rotl(unsigned int _Val, int _Shift);
#pragma pop_macro("_rotl")
#pragma push_macro("_lrotl")
#undef _lrotl
  unsigned long __cdecl _lrotl(unsigned long _Val, int _Shift);
#pragma pop_macro("_lrotl")
#pragma push_macro("_rotl64")
#undef _rotl64
  __MINGW_EXTENSION unsigned __int64 __cdecl _rotl64(unsigned __int64 _Val, int _Shift);
#pragma pop_macro("_rotl64")
#pragma push_macro("_rotr")
#undef _rotr
  unsigned int __cdecl _rotr(unsigned int _Val, int _Shift);
#pragma pop_macro("_rotr")
#pragma push_macro("_lrotr")
#undef _lrotr
  unsigned long __cdecl _lrotr(unsigned long _Val, int _Shift);
#pragma pop_macro("_lrotr")
#pragma push_macro("_rotr64")
#undef _rotr64
  __MINGW_EXTENSION unsigned __int64 __cdecl _rotr64(unsigned __int64 _Val, int _Shift);
#pragma pop_macro("_rotr64")

#define RAND_MAX 0x7fff

  _CRTIMP void __cdecl srand(unsigned int _Seed);
  _CRTIMP int __cdecl rand(void);
#if defined(_CRT_RAND_S) && defined(__MINGW_USE_MS)
  _CRTIMP errno_t __cdecl rand_s(unsigned int *randomValue);
#endif

#ifdef __MINGW_USE_POSIX199506
# ifndef rand_r
#   define rand_r(__seed) (__seed == __seed ? rand () : rand ())
# endif
#endif

#define _CRT_DOUBLE_DEC

#pragma pack(push, 4)
  typedef struct
  {
    unsigned char ld[10];
  } _LDOUBLE;
#pragma pack(pop)

#define _PTR_LD(x) ((unsigned char *)(&(x)->ld))

  typedef struct
  {
    double x;
  } _CRT_DOUBLE;

  typedef struct
  {
    float f;
  } _CRT_FLOAT;

#pragma push_macro("long")
#undef long

  typedef struct
  {
    long double x;
  } _LONGDOUBLE;

#pragma pop_macro("long")

#pragma pack(push, 4)
  typedef struct
  {
    unsigned char ld12[12];
  } _LDBL12;
#pragma pack(pop)

#ifndef _CRT_ATOF_DEFINED  /* Also in math.h */
# define _CRT_ATOF_DEFINED
  _CRTIMP double __cdecl atof(const char *_String);
  _CRTIMP double __cdecl _atof_l(const char *_String, _locale_t _Locale);
#endif  /* _CRT_ATOF_DEFINED */
  _CRTIMP int __cdecl atoi(const char *_Str);
  _CRTIMP long __cdecl atol(const char *_Str);
#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)
  __MINGW_EXTENSION _CRTIMP long long __cdecl atoll(const char *_Str);
#endif
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _atoi64(const char *_String);

  _CRTIMP int __cdecl _atoi_l(const char *_Str, _locale_t _Locale);
  _CRTIMP long __cdecl _atol_l(const char *_Str, _locale_t _Locale);
  __MINGW_EXTENSION _CRTIMP long long __cdecl _atoll_l(char const *_String, _locale_t _Locale);
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _atoi64_l(const char *_String, _locale_t _Locale);

  _CRTIMP int __cdecl _atoflt(_CRT_FLOAT *_Result, char *_Str);
  _CRTIMP int __cdecl _atodbl(_CRT_DOUBLE *_Result, char *_Str);
  _CRTIMP int __cdecl _atoldbl(_LDOUBLE *_Result, char *_Str);

  _CRTIMP int __cdecl _atoflt_l(_CRT_FLOAT *_Result, char *_Str, _locale_t _Locale);
  _CRTIMP int __cdecl _atodbl_l(_CRT_DOUBLE *_Result, char *_Str, _locale_t _Locale);
  _CRTIMP int __cdecl _atoldbl_l(_LDOUBLE *_Result, char *_Str, _locale_t _Locale);

#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)
  _CRTIMP float __cdecl __MINGW_NOTHROW strtof(const char * __restrict__ _Str, char ** __restrict__ _EndPtr);
#endif
  _CRTIMP float __cdecl _strtof_l(const char * __restrict__ _Str, char ** __restrict__ _EndPtr, _locale_t _Locale);
  _CRTIMP double __cdecl __MINGW_NOTHROW strtod(const char * __restrict__ _Str, char ** __restrict__ _EndPtr);
  _CRTIMP double __cdecl _strtod_l(const char * __restrict__ _Str, char ** __restrict__ _EndPtr, _locale_t _Locale);
#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)
  _LDCRTIMP long double __cdecl __MINGW_NOTHROW strtold(const char * __restrict__ _Str, char ** __restrict__ _EndPtr);
#endif
#if defined(__aarch64__) || defined(_ARM64_)
  _LDCRTIMP long double __cdecl _strtold_l(const char * __restrict__ _Str, char ** __restrict__ _EndPtr, _locale_t _Locale);
#endif
  _CRTIMP long __cdecl strtol(const char * __restrict__ _Str, char ** __restrict__ _EndPtr, int _Radix);
  _CRTIMP long __cdecl _strtol_l(const char * __restrict__ _Str, char ** __restrict__ _EndPtr, int _Radix, _locale_t _Locale);
#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)
  __MINGW_EXTENSION _CRTIMP long long __cdecl strtoll(const char * __restrict__ _Str, char ** __restrict__ _EndPtr, int _Radix);
#endif
  __MINGW_EXTENSION _CRTIMP long long __cdecl _strtoll_l(const char * __restrict__ _Str, char ** __restrict__ _EndPtr, int _Radix, _locale_t _Locale);
  _CRTIMP unsigned long __cdecl strtoul(const char * __restrict__ _Str, char ** __restrict__ _EndPtr, int _Radix);
  _CRTIMP unsigned long __cdecl _strtoul_l(const char * __restrict__ _Str, char ** __restrict__ _EndPtr, int _Radix, _locale_t _Locale);
#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_C99FORGXX)
  __MINGW_EXTENSION _CRTIMP unsigned long long __cdecl strtoull(const char * __restrict__ _Str, char ** __restrict__ _EndPtr, int _Radix);
#endif
  __MINGW_EXTENSION _CRTIMP unsigned long long __cdecl _strtoull_l(const char * __restrict__ _Str, char ** __restrict__ _EndPtr, int _Radix, _locale_t _Locale);
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _strtoi64(const char *_String, char **_EndPtr, int _Radix);
  __MINGW_EXTENSION _CRTIMP __int64 __cdecl _strtoi64_l(const char *_String, char **_EndPtr, int _Radix, _locale_t _Locale);
  __MINGW_EXTENSION _CRTIMP unsigned __int64 __cdecl _strtoui64(const char *_String, char **_EndPtr, int _Radix);
  __MINGW_EXTENSION _CRTIMP unsigned __int64 __cdecl _strtoui64_l(const char *_String, char **_EndPtr, int _Radix, _locale_t _Locale);

  _CRTIMP char *__cdecl _itoa(int _Value, char *_Dest, int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _itoa_s(int _Value, char *_DstBuf, size_t _Size, int _Radix);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_1(errno_t, _itoa_s, int, _Value, char, _Dest, int, _Radix)
  _CRTIMP char *__cdecl _ltoa(long _Value, char *_Dest, int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _ltoa_s(long _Val, char *_DstBuf, size_t _Size, int _Radix);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_1(errno_t, _ltoa_s, long, _Value, char, _Dest, int, _Radix)
  _CRTIMP char *__cdecl _ultoa(unsigned long _Value, char *_Dest, int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _ultoa_s(unsigned long _Val, char *_DstBuf, size_t _Size, int _Radix);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_1(errno_t, _ultoa_s, unsigned long, _Value, char, _Dest, int, _Radix)
  __MINGW_EXTENSION _CRTIMP char *__cdecl _i64toa(__int64 _Val, char *_DstBuf, int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  __MINGW_EXTENSION _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val, char *_DstBuf, size_t _Size, int _Radix);
  __MINGW_EXTENSION _CRTIMP char *__cdecl _ui64toa(unsigned __int64 _Val, char *_DstBuf, int _Radix) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  __MINGW_EXTENSION _CRTIMP errno_t __cdecl _ui64toa_s(unsigned __int64 _Val, char *_DstBuf, size_t _Size, int _Radix);

#define _CVTBUFSIZE (309 + 40)

  _CRTIMP char *__cdecl _ecvt(double _Val, int _NumOfDigits, int *_PtDec, int *_PtSign) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _ecvt_s(char *_DstBuf, size_t _Size, double _Val, int _NumOfDights, int *_PtDec, int *_PtSign);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_4(errno_t, _ecvt_s, char, _Buffer, double, _Value, int, _DigitCount, int *, _PtDec, int *, _PtSign)
  _CRTIMP char *__cdecl _fcvt(double _Val, int _NumOfDec, int *_PtDec, int *_PtSign) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _fcvt_s(char *_DstBuf, size_t _Size, double _Val, int _NumOfDec, int *_PtDec, int *_PtSign);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_4(errno_t, _fcvt_s, char, _Buffer, double, _Value, int, _FractionalDigitCount, int *, _PtDec, int *, _PtSign)
  _CRTIMP char *__cdecl _gcvt(double _Val, int _NumOfDigits, char *_DstBuf) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _gcvt_s(char *_DstBuf, size_t _Size, double _Val, int _NumOfDigits);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(errno_t, _gcvt_s, char, _Buffer, double, _Value, int, _DigitCount)

#ifndef MB_CUR_MAX  /* Also in ctype.h */
# define MB_CUR_MAX ___mb_cur_max_func()
# ifndef __mb_cur_max
#   define __mb_cur_max (___mb_cur_max_func())
# endif
  _CRTIMP int __cdecl ___mb_cur_max_func(void);
  _CRTIMP int __cdecl ___mb_cur_max_l_func(_locale_t _Locale);
#endif  /* MB_CUR_MAX */

  _CRTIMP int __cdecl mblen(const char *_Ch, size_t _MaxCount);
  _CRTIMP int __cdecl _mblen_l(const char *_Ch, size_t _MaxCount, _locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrlen(const char *_Str);
  _CRTIMP size_t __cdecl _mbstrlen_l(const char *_Str, _locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrnlen(const char *_Str, size_t _MaxCount);
  _CRTIMP size_t __cdecl _mbstrnlen_l(const char *_Str, size_t _MaxCount, _locale_t _Locale);
  _CRTIMP int __cdecl mbtowc(wchar_t * __restrict__ _DstCh, const char * __restrict__ _SrcCh, size_t _SrcSizeInBytes);
  _CRTIMP int __cdecl _mbtowc_l(wchar_t * __restrict__ _DstCh, const char * __restrict__ _SrcCh, size_t _SrcSizeInBytes, _locale_t _Locale);
  _CRTIMP size_t __cdecl mbstowcs(wchar_t * __restrict__ _Dest, const char * __restrict__ _Source, size_t _MaxCount);
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl mbstowcs_s(size_t *_PtNumOfCharConverted, wchar_t *_DstBuf, size_t _SizeInWords, const char *_SrcBuf, size_t _MaxCount);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_2(errno_t, mbstowcs_s, size_t *, _PtNumOfCharConverted, wchar_t, _Dest, const char *, _Source, size_t, _MaxCount)
#endif
  _CRTIMP size_t __cdecl _mbstowcs_l(wchar_t * __restrict__ _Dest, const char * __restrict__ _Source, size_t _MaxCount, _locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(size_t *_PtNumOfCharConverted, wchar_t *_DstBuf, size_t _SizeInWords, const char *_SrcBuf, size_t _MaxCount, _locale_t _Locale);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_3(errno_t, _mbstowcs_s_l, size_t *, _PtNumOfCharConverted, wchar_t, _Dest, const char *, _Source, size_t, _MaxCount, _locale_t, _Locale)

  _CRTIMP int __cdecl wctomb(char *_MbCh, wchar_t _WCh) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl wctomb_s(int *_SizeConverted, char *_MbCh, rsize_t _SizeInBytes, wchar_t _WCh);
#endif
  _CRTIMP int __cdecl _wctomb_l(char *_MbCh, wchar_t _WCh, _locale_t _Locale) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _wctomb_s_l(int *_SizeConverted, char *_MbCh, size_t _SizeInBytes, wchar_t _WCh, _locale_t _Locale);
  _CRTIMP size_t __cdecl wcstombs(char * __restrict__ _Dest, const wchar_t * __restrict__ _Source, size_t _MaxCount) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl wcstombs_s(size_t *_PtNumOfCharConverted, char *_Dst, size_t _DstSizeInBytes, const wchar_t *_Src, size_t _MaxCountInBytes);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_2(errno_t, wcstombs_s, size_t *, _PtNumOfCharConverted, char, _Dst, const wchar_t *, _Src, size_t, _MaxCountInBytes)
#endif
  _CRTIMP size_t __cdecl _wcstombs_l(char * __restrict__ _Dest,const wchar_t * __restrict__ _Source,size_t _MaxCount,_locale_t _Locale) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _wcstombs_s_l(size_t *_PtNumOfCharConverted, char *_Dst, size_t _DstSizeInBytes, const wchar_t *_Src, size_t _MaxCountInBytes, _locale_t _Locale);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_3(errno_t, _wcstombs_s_l, size_t *, _PtNumOfCharConverted, char, _Dst, const wchar_t *, _Src, size_t, _MaxCountInBytes, _locale_t, _Locale)

#define _MAX_PATH  260
#define _MAX_DRIVE 3
#define _MAX_DIR   256
#define _MAX_FNAME 256
#define _MAX_EXT   256

#pragma push_macro("_fullpath")
#undef _fullpath
  _CRTIMP char *__cdecl _fullpath(char *_FullPath, const char *_Path, size_t _SizeInBytes);
#pragma pop_macro("_fullpath")
  _CRTIMP void __cdecl _makepath(char *_Path,const char *_Drive,const char *_Dir,const char *_Filename,const char *_Ext) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _makepath_s(char *_PathResult, size_t _Size, const char *_Drive, const char *_Dir, const char *_Filename, const char *_Ext);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_4(errno_t, _makepath_s, char, _PathResult, const char *, _Drive, const char *, _Dir, const char *, _Filename, const char *, _Ext)
  _CRTIMP void __cdecl _splitpath(const char *_FullPath, char *_Drive, char *_Dir, char *_Filename, char *_Ext) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _splitpath_s(const char *_FullPath, char *_Drive, size_t _DriveSize, char *_Dir, size_t _DirSize, char *_Filename, size_t _FilenameSize, char *_Ext, size_t _ExtSize);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_SPLITPATH(errno_t, _splitpath_s, char, _Dest)

  _CRTIMP int *__cdecl __p___argc(void);
  _CRTIMP char ***__cdecl __p___argv(void);
  _CRTIMP wchar_t ***__cdecl __p___wargv(void);

#ifndef __argc
# define __argc (* __p___argc())
#endif
#ifndef __argv
# define __argv (* __p___argv())
#endif
#ifndef __wargv
# define __wargv (* __p___wargv())
#endif

  _CRTIMP char ***__cdecl __p__environ(void);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(void);

#ifndef _environ
# define _environ (* __p__environ())
#endif

#ifndef _wenviron
# define _wenviron (* __p__wenviron())
#endif

#define _MAX_ENV 32767

  _CRTIMP char *__cdecl getenv(const char *_VarName) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl getenv_s(size_t *_ReturnSize, char *_DstBuf, rsize_t _DstSize, const char *_VarName);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_1_1(errno_t, getenv_s, size_t *, _ReturnSize, char, _Dest, const char *, _VarName)
#endif
  _CRTIMP errno_t __cdecl _dupenv_s(char **_PBuffer, size_t *_PBufferSizeInBytes, const char *_VarName);

#ifndef _CRT_SYSTEM_DEFINED  /* Also in process.h */
# define _CRT_SYSTEM_DEFINED
  _CRTIMP int __cdecl system(const char *_Command);
#endif  /* _CRT_SYSTEM_DEFINED */

  _CRTIMP int __cdecl _putenv(const char *_EnvString);
  _CRTIMP errno_t __cdecl _putenv_s(const char *_Name, const char *_Value);
  _CRTIMP void __cdecl _searchenv(const char *_Filename, const char *_EnvVar, char *_ResultPath) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t __cdecl _searchenv_s(const char *_Filename, const char *_EnvVar, char *_ResultPath, size_t _SizeInBytes);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_2_0(errno_t, _searchenv_s, const char *, _Filename, const char *, _VarName, char, _Buffer)

  _CRTIMP void __cdecl _seterrormode(int _Mode) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP void __cdecl _beep(unsigned _Frequency, unsigned _Duration) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP void __cdecl _sleep(unsigned long _Duration) __MINGW_ATTRIB_DEPRECATED;

#ifdef __MINGW_USE_MS
# define sys_errlist _sys_errlist
# define sys_nerr    _sys_nerr
#endif

#if (defined(__MINGW_USE_XOPEN_EXT) && !defined(__MINGW_USE_XOPEN2K8)) || defined(__MINGW_USE_MISC) || defined(__MINGW_USE_MS)
  _CRTIMP char *__cdecl ecvt(double _Val, int _NumOfDigits, int *_PtDec, int *_PtSign) __MINGW_ATTRIB_DEPRECATED_MSVC2005 __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP char *__cdecl fcvt(double _Val, int _NumOfDec, int *_PtDec, int *_PtSign) __MINGW_ATTRIB_DEPRECATED_MSVC2005 __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP char *__cdecl gcvt(double _Val, int _NumOfDigits, char *_DstBuf) __MINGW_ATTRIB_DEPRECATED_MSVC2005 __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#endif
#ifdef __MINGW_USE_MS
  _CRTIMP char *__cdecl itoa(int _Val, char *_DstBuf, int _Radix) __MINGW_ATTRIB_DEPRECATED_MSVC2005 __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP char *__cdecl ltoa(long _Val, char *_DstBuf, int _Radix) __MINGW_ATTRIB_DEPRECATED_MSVC2005 __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
  _CRTIMP char *__cdecl ultoa(unsigned long _Val, char *_Dstbuf, int _Radix) __MINGW_ATTRIB_DEPRECATED_MSVC2005 __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#endif

#ifndef _CRT_SWAB_DEFINED  /* Also in unistd.h */
# define _CRT_SWAB_DEFINED
# if defined(__MINGW_USE_XOPEN) || defined(__MINGW_USE_MS)
    _CRTIMP void __cdecl swab(char *_Buf1, char *_Buf2, int _SizeInBytes) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
# endif
#endif  /* _CRT_SWAB_DEFINED */

#if defined(__MINGW_USE_GNU) || defined(__MINGW_USE_MS)
# define environ _environ
#endif

#if defined(__MINGW_USE_XOPEN) || defined(__MINGW_USE_MISC) || defined(__MINGW_USE_MS)
  _CRTIMP int __cdecl putenv(const char *_EnvString) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#endif
#ifdef __MINGW_USE_MS
  extern onexit_t __cdecl onexit(onexit_t _Func);
#endif

#ifndef _CRT_ALLOCATION_DEFINED  /* Also in malloc.h */
# define _CRT_ALLOCATION_DEFINED

#define _MM_MALLOC_H_INCLUDED
#define _mm_free(a)      _aligned_free(a)
#define _mm_malloc(a, b) _aligned_malloc(a, b)

# undef  _alloca
# define _alloca(x) __builtin_alloca((x))
# undef   alloca
# define  alloca _alloca

  _CRTIMP void *__cdecl _calloc_base(size_t _Count, size_t _Size);
  _CRTIMP void *__cdecl calloc(size_t _NumOfElements, size_t _SizeOfElements);
  _CRTIMP int __cdecl _callnewh(size_t _Size);
  _CRTIMP void *__cdecl _expand(void *_Memory, size_t _NewSize);
  _CRTIMP void __cdecl _free_base(void *_Block);
  _CRTIMP void __cdecl free(void *_Memory);
  _CRTIMP void *__cdecl _malloc_base(size_t _Size);
  _CRTIMP void *__cdecl malloc(size_t _Size);
  _CRTIMP size_t __cdecl _msize_base(void *_Block);
  _CRTIMP size_t __cdecl _msize(void *_Memory);
  _CRTIMP void *__cdecl _realloc_base(void *_Block, size_t _Size);
  _CRTIMP void *__cdecl realloc(void *_Memory, size_t _NewSize);
  _CRTIMP void *__cdecl _recalloc_base(void *_Block, size_t _Count, size_t _Size);
  _CRTIMP void *__cdecl _recalloc(void *_Memory, size_t _Count, size_t _Size);
  _CRTIMP void __cdecl _aligned_free(void *_Memory);
  _CRTIMP void *__cdecl _aligned_malloc(size_t _Size, size_t _Alignment);
  _CRTIMP void *__cdecl _aligned_offset_malloc(size_t _Size, size_t _Alignment, size_t _Offset);
  _CRTIMP size_t __cdecl _aligned_msize(void *_Block, size_t _Alignment, size_t _Offset);
  _CRTIMP void *__cdecl _aligned_offset_realloc(void *_Memory, size_t _Size, size_t _Alignment, size_t _Offset);
  _CRTIMP void *__cdecl _aligned_offset_recalloc(void *_Memory, size_t _Count, size_t _Size, size_t _Alignment, size_t _Offset);
  _CRTIMP void *__cdecl _aligned_realloc(void *_Memory, size_t _Size, size_t _Alignment);
  _CRTIMP void *__cdecl _aligned_recalloc(void *_Memory, size_t _Count, size_t _Size, size_t _Alignment);
#endif  /* _CRT_ALLOCATION_DEFINED */

#if defined(__MINGW_USE_XOPEN_EXT) || defined(__MINGW_USE_XOPEN2K8) || defined(__MINGW_USE_MISC)
  extern int __cdecl mkstemp(char *template_name);
#endif

#ifndef __STRICT_ANSI__
  __MINGW_EXTENSION char *__cdecl lltoa(long long _Val, char *_DstBuf, int _Radix);
  __MINGW_EXTENSION char *__cdecl ulltoa(unsigned long long _Val, char *_DstBuf, int _Radix);
#endif  /* __STRICT_ANSI__ */

__MINGW_END_C_DECLS

#endif  /* _INC_STDLIB */
