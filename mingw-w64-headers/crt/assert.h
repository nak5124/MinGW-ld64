/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

/* According to C99 standard (section 7.2) the assert
   macro shall be redefined each time assert.h gets
   included depending on the status of NDEBUG macro.  */
#undef assert

#ifndef __ASSERT_H_
#define __ASSERT_H_

#include <corecrt.h>

__MINGW_BEGIN_C_DECLS

#if defined(__MINGW_USE_ISOC11) && !defined(__cplusplus)
/* Static assertion.  Requires support in the compiler. */
# undef static_assert
# define static_assert _Static_assert
#endif

  _CRTIMP void __cdecl _wassert(const wchar_t *_Message, const wchar_t *_File, unsigned _Line) __MINGW_NORETURN;
  _CRTIMP void __cdecl _assert(const char *_Message, const char *_File, unsigned _Line) __MINGW_NORETURN;

__MINGW_END_C_DECLS

#endif  /* __ASSERT_H_ */

#ifdef NDEBUG
# define assert(_Expression) ((void)0)
#elif defined(_UNICODE) || defined(UNICODE)
# define assert(_Expression) \
  (void) \
  ((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression), _CRT_WIDE(__FILE__), __LINE__), 0))
#else
# define assert(_Expression) \
  (void) \
  ((!!(_Expression)) || (_assert(#_Expression, __FILE__, __LINE__), 0))
#endif  /* NDEBUG */
