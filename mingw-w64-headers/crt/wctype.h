/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_WCTYPE
#define _INC_WCTYPE

#ifndef _WIN32
# error Only Win32 target is supported!
#endif

#include <corecrt.h>
#include <corecrt_wctype.h>

__MINGW_BEGIN_C_DECLS

  typedef wchar_t wctrans_t;
  _CRTIMP wint_t    __cdecl towctrans(wint_t _C, wctrans_t _Value) __MINGW_NOTHROW;
  _CRTIMP wctrans_t __cdecl wctrans(const char *_Name)             __MINGW_NOTHROW;
  _CRTIMP wctype_t  __cdecl wctype(const char *_Name);

__MINGW_END_C_DECLS

#endif  /* _INC_WCTYPE */
