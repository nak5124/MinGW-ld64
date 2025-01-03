/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <string.h>

void __cdecl __chk_fail(void) __MINGW_NORETURN;

void *__cdecl __memmove_chk(void *dst, const void *src, size_t n, size_t bufsize);

void *__cdecl __memmove_chk(void *dst, const void *src, size_t n, size_t bufsize)
{
  if (n > bufsize)
    __chk_fail();
  return memmove(dst, src, n);
}
