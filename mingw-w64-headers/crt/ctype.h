/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CTYPE
#define _INC_CTYPE

#include <corecrt.h>
#include <corecrt_wctype.h>

#pragma pack(push, _CRT_PACKING)

__MINGW_BEGIN_C_DECLS

  _CRTIMP int __cdecl _isctype(int _C, int _Type);
  _CRTIMP int __cdecl _isctype_l(int _C, int _Type, _locale_t _Locale);
  _CRTIMP int __cdecl isalpha(int _C);
  _CRTIMP int __cdecl _isalpha_l(int _C, _locale_t _Locale);
  _CRTIMP int __cdecl isupper(int _C);
  _CRTIMP int __cdecl _isupper_l(int _C, _locale_t _Locale);
  _CRTIMP int __cdecl islower(int _C);
  _CRTIMP int __cdecl _islower_l(int _C, _locale_t _Locale);
  _CRTIMP int __cdecl isdigit(int _C);
  _CRTIMP int __cdecl _isdigit_l(int _C, _locale_t _Locale);
  _CRTIMP int __cdecl isxdigit(int _C);
  _CRTIMP int __cdecl _isxdigit_l(int _C, _locale_t _Locale);
  _CRTIMP int __cdecl isspace(int _C);
  _CRTIMP int __cdecl _isspace_l(int _C, _locale_t _Locale);
  _CRTIMP int __cdecl ispunct(int _C);
  _CRTIMP int __cdecl _ispunct_l(int _C, _locale_t _Locale);
#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_MS)
  _CRTIMP int __cdecl isblank(int _C);
#endif
  _CRTIMP int __cdecl _isblank_l(int _C, _locale_t _Locale);
  _CRTIMP int __cdecl isalnum(int _C);
  _CRTIMP int __cdecl _isalnum_l(int _C, _locale_t _Locale);
  _CRTIMP int __cdecl isprint(int _C);
  _CRTIMP int __cdecl _isprint_l(int _C, _locale_t _Locale);
  _CRTIMP int __cdecl isgraph(int _C);
  _CRTIMP int __cdecl _isgraph_l(int _C, _locale_t _Locale);
  _CRTIMP int __cdecl iscntrl(int _C);
  _CRTIMP int __cdecl _iscntrl_l(int _C, _locale_t _Locale);

  _CRTIMP int __cdecl toupper(int _C);
  _CRTIMP int __cdecl tolower(int _C);
  _CRTIMP int __cdecl _tolower(int _C);
  _CRTIMP int __cdecl _tolower_l(int _C, _locale_t _Locale);
  _CRTIMP int __cdecl _toupper(int _C);
  _CRTIMP int __cdecl _toupper_l(int _C, _locale_t _Locale);

  _CRTIMP int __cdecl __isascii(int _C);
  _CRTIMP int __cdecl __toascii(int _C);
  _CRTIMP int __cdecl __iscsymf(int _C);
  _CRTIMP int __cdecl __iscsym(int _C);

#ifndef _CTYPE_DISABLE_MACROS

#ifndef MB_CUR_MAX  /* Also in stdlib.h */
# define MB_CUR_MAX ___mb_cur_max_func()
# ifndef __mb_cur_max
#   define __mb_cur_max (___mb_cur_max_func())
# endif
  _CRTIMP int __cdecl ___mb_cur_max_func(void);
  _CRTIMP int __cdecl ___mb_cur_max_l_func(_locale_t _Locale);
#endif  /* MB_CUR_MAX */

#define __chvalidchk(a, b) (__PCTYPE_FUNC[(unsigned char)(a)] & (b))
#define __ascii_isalpha(c) (__chvalidchk(c, _ALPHA))
#define __ascii_isdigit(c)  __chvalidchk(c, _DIGIT))

#ifdef _CRT_DEFINE_ASCII_CTYPE_MACROS
# define __ascii_tolower(c)  ((((c) >= 'A') && ((c) <= 'Z')) ? ((c) - 'A' + 'a') : (c))
# define __ascii_toupper(c)  ((((c) >= 'a') && ((c) <= 'z')) ? ((c) - 'a' + 'A') : (c))
# define __ascii_iswalpha(c) (('A' <= (c) && (c) <= 'Z') || ( 'a' <= (c) && (c) <= 'z'))
# define __ascii_iswdigit(c) ('0' <= (c) && (c) <= '9')
# define __ascii_towlower(c) ((((c) >= L'A') && ((c) <= L'Z')) ? ((c) - L'A' + L'a') : (c))
# define __ascii_towupper(c) ((((c) >= L'a') && ((c) <= L'z')) ? ((c) - L'a' + L'A') : (c))
#else
  __forceinline int __cdecl __ascii_tolower(int const _C)
  {
    if(_C >= 'A' && _C <= 'Z')
    {
      return _C - ('A' - 'a');
    }
      return _C;
  }

  __forceinline int __cdecl __ascii_toupper(int const _C)
  {
      if (_C >= 'a' && _C <= 'z')
      {
          return _C - ('a' - 'A');
      }
      return _C;
  }

  __forceinline int __cdecl __ascii_iswalpha(int const _C)
  {
    return (_C >= 'A' && _C <= 'Z') || (_C >= 'a' && _C <= 'z');
  }

  __forceinline int __cdecl __ascii_iswdigit(int const _C)
  {
    return _C >= '0' && _C <= '9';
  }

  __forceinline int __cdecl __ascii_towlower(int const _C)
  {
    return __ascii_tolower(_C);
  }

  __forceinline int __cdecl __ascii_towupper(int const _C)
  {
    return __ascii_toupper(_C);
  }
#endif  /* _CRT_DEFINE_ASCII_CTYPE_MACROS */

#define _chvalidchk_l(_Char, _Flag, _Locale) (!_Locale ? __chvalidchk(_Char, _Flag) : ((_locale_t)_Locale)->locinfo->_locale_pctype[(unsigned char)(_Char)] & (_Flag))
#define __ascii_isalpha_l(c, locale) (_chvalidchk_l(c, _ALPHA, locale))
#define __ascii_isdigit_l(c, locale) (_chvalidchk_l(c, _DIGIT, locale))
#define _ischartype_l(_Char, _Flag, _Locale) (((_Locale)!=NULL && (((_locale_t)(_Locale))->locinfo->_locale_mb_cur_max) > 1) ? _isctype_l(_Char, (_Flag), _Locale) : _chvalidchk_l(_Char, _Flag, _Locale))
#define _isalpha_l(_Char, _Locale) _ischartype_l(_Char, _ALPHA, _Locale)
#define _isupper_l(_Char, _Locale) _ischartype_l(_Char, _UPPER, _Locale)
#define _islower_l(_Char, _Locale) _ischartype_l(_Char, _LOWER, _Locale)
#define _isdigit_l(_Char, _Locale) _ischartype_l(_Char, _DIGIT, _Locale)
#define _isxdigit_l(_Char, _Locale) _ischartype_l(_Char, _HEX, _Locale)
#define _isspace_l(_Char, _Locale) _ischartype_l(_Char, _SPACE, _Locale)
#define _ispunct_l(_Char, _Locale) _ischartype_l(_Char, _PUNCT _Locale)
#define _isalnum_l(_Char, _Locale) _ischartype_l(_Char, _ALPHA | _DIGIT, _Locale)
#define _isprint_l(_Char, _Locale) _ischartype_l(_Char, _BLANK| _PUNCT | _ALPHA | _DIGIT, _Locale)
#define _isgraph_l(_Char, _Locale) _ischartype_l(_Char, _PUNCT| _ALPHA | _DIGIT, _Locale)
#define _iscntrl_l(_Char, _Locale) _ischartype_l(_Char, _CONTROL, _Locale)

#define _tolower(_Char) ((_Char)-'A'+'a')
#define _toupper(_Char) ((_Char)-'a'+'A')

#define __isascii(_Char) ((unsigned)(_Char) < 0x80)
#define __toascii(_Char) ((_Char) & 0x7f)

#define __iscsymf(_c)  (isalpha(_c) || ((_c)=='_'))
#define __iscsym(_c)   (isalnum(_c) || ((_c)=='_'))
#define __iswcsymf(_c) (iswalpha(_c) || ((_c)=='_'))
#define __iswcsym(_c)  (iswalnum(_c) || ((_c)=='_'))

#define _iscsymf_l(_c, _p)  (_isalpha_l(_c, _p) || ((_c)=='_'))
#define _iscsym_l(_c, _p)   (_isalnum_l(_c, _p) || ((_c)=='_'))
#define _iswcsymf_l(_c, _p) (_iswalpha_l(_c, _p) || ((_c)=='_'))
#define _iswcsym_l(_c, _p)  (_iswalnum_l(_c, _p) || ((_c)=='_'))

#endif  /* _CTYPE_DISABLE_MACROS */

#if defined(__MINGW_USE_MISC) || defined(__MINGW_USE_XOPEN) || defined(__MINGW_USE_MS)
  _CRTIMP int __cdecl isascii(int _C) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  _CRTIMP int __cdecl toascii(int _C) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
# define isascii __isascii
# define toascii __toascii
#endif

#ifdef __MINGW_USE_MS
  _CRTIMP int __cdecl iscsymf(int _C) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  _CRTIMP int __cdecl iscsym(int _C) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
# define iscsymf __iscsymf
# define iscsym  __iscsym
#endif

  /* CRT stuff */
#if 1
  extern const unsigned char __newclmap[];
  extern const unsigned char __newcumap[];
  extern pthreadlocinfo __ptlocinfo;
  extern pthreadmbcinfo __ptmbcinfo;
  extern int __globallocalestatus;
  extern int __locale_changed;
  extern struct threadlocaleinfostruct __initiallocinfo;
  extern _locale_tstruct __initiallocalestructinfo;
  pthreadlocinfo __cdecl __updatetlocinfo(void);
  pthreadmbcinfo __cdecl __updatetmbcinfo(void);
#endif

__MINGW_END_C_DECLS

#pragma pack(pop)

#endif  /* _INC_CTYPE */
