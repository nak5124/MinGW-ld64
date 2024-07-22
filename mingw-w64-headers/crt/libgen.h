/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _LIBGEN_H_
#define _LIBGEN_H_

#include <corecrt.h>

__MINGW_BEGIN_C_DECLS

  char *__cdecl __MINGW_NOTHROW basename(char *);
  char *__cdecl __MINGW_NOTHROW dirname(char *);

__MINGW_END_C_DECLS

#endif  /* _LIBGEN_H_ */
