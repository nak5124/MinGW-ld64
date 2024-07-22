/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_LOCALE
#define _INC_LOCALE

#include <corecrt.h>

#pragma pack(push, _CRT_PACKING)

__MINGW_BEGIN_C_DECLS

#define LC_ALL      0
#define LC_COLLATE  1
#define LC_CTYPE    2
#define LC_MONETARY 3
#define LC_NUMERIC  4
#define LC_TIME     5

#define LC_MIN LC_ALL
#define LC_MAX LC_TIME

  struct lconv
  {
    char *decimal_point;
    char *thousands_sep;
    char *grouping;
    char *int_curr_symbol;
    char *currency_symbol;
    char *mon_decimal_point;
    char *mon_thousands_sep;
    char *mon_grouping;
    char *positive_sign;
    char *negative_sign;
    char int_frac_digits;
    char frac_digits;
    char p_cs_precedes;
    char p_sep_by_space;
    char n_cs_precedes;
    char n_sep_by_space;
    char p_sign_posn;
    char n_sign_posn;
    wchar_t *_W_decimal_point;
    wchar_t *_W_thousands_sep;
    wchar_t *_W_int_curr_symbol;
    wchar_t *_W_currency_symbol;
    wchar_t *_W_mon_decimal_point;
    wchar_t *_W_mon_thousands_sep;
    wchar_t *_W_positive_sign;
    wchar_t *_W_negative_sign;
  };

  struct tm;

#ifdef __CHAR_UNSIGNED__
  /* Pull in the constructor from 'charmax.c'. */
  extern int __mingw_initcharmax;
  __MINGW_SELECTANY int* __mingw_reference_charmax = &__mingw_initcharmax;
#endif

#define _ENABLE_PER_THREAD_LOCALE         0x1
#define _DISABLE_PER_THREAD_LOCALE        0x2
#define _ENABLE_PER_THREAD_LOCALE_GLOBAL  0x10
#define _DISABLE_PER_THREAD_LOCALE_GLOBAL 0x20
#define _ENABLE_PER_THREAD_LOCALE_NEW     0x100
#define _DISABLE_PER_THREAD_LOCALE_NEW    0x200

  _CRTIMP void __cdecl _lock_locales(void);
  _CRTIMP void __cdecl _unlock_locales(void);
  _CRTIMP int __cdecl _configthreadlocale(int _Flag);
  _CRTIMP char *__cdecl setlocale(int _Category, const char *_Locale);
  _CRTIMP struct lconv *__cdecl localeconv(void);
  _CRTIMP _locale_t __cdecl _get_current_locale(void);
  _CRTIMP _locale_t __cdecl _create_locale(int _Category, const char *_Locale);
  _CRTIMP void __cdecl _free_locale(_locale_t _Locale);
#ifndef _WLOCALE_DEFINED  /* Also in wchar.h */
# define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(int _Category, const wchar_t *_Locale);
  _CRTIMP _locale_t __cdecl _wcreate_locale(int _Category, const wchar_t *_Locale);
#endif

  _CRTIMP wchar_t **__cdecl ___lc_locale_name_func(void);
  _CRTIMP unsigned int __cdecl ___lc_codepage_func(void);
  _CRTIMP unsigned int __cdecl ___lc_collate_cp_func(void);

  _CRTIMP char *__cdecl _Getdays(void);
  _CRTIMP char *__cdecl _Getmonths(void);
  _CRTIMP void *__cdecl _Gettnames(void);
  _CRTIMP wchar_t *__cdecl _W_Getdays(void);
  _CRTIMP wchar_t *__cdecl _W_Getmonths(void);
  _CRTIMP void *__cdecl _W_Gettnames(void);
  _CRTIMP size_t __cdecl _Strftime(char *_Buffer, size_t _Max_size, const char * _Format, const struct tm *_Timeptr, void *_Lc_time_arg);
  _CRTIMP size_t __cdecl _Wcsftime(wchar_t *_Buffer, size_t _Max_size, const wchar_t *_Format, const struct tm *_Timeptr, void *_Lc_time_arg);

__MINGW_END_C_DECLS

#pragma pack(pop)

#endif  /* _INC_LOCALE */
