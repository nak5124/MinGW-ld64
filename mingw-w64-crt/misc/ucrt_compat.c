/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Winline"

#undef __MSVCRT_VERSION__
#define _UCRT

#define _amsg_exit crtimp__amsg_exit
#define _get_output_format crtimp__get_output_format

#include <internal.h>
#include <sect_attribs.h>
#include <stdio.h>
#include <time.h>
#include <corecrt_startup.h>

#undef _amsg_exit
#undef _get_output_format

// Declarations of non-static functions implemented within this file (that aren't
// declared in any of the included headers, and that isn't mapped away with a define
// to get rid of the _CRTIMP in headers).
void __cdecl _amsg_exit(int ret) __MINGW_NORETURN;
unsigned int __cdecl _get_output_format(void);

int __cdecl __ms_fwprintf(FILE *, const wchar_t *, ...);

extern void (*__MINGW_IMP_SYMBOL(_exit))(int) __MINGW_NORETURN;

__MINGW_NORETURN
void __cdecl _amsg_exit(int ret) {
  fprintf(stderr, "runtime error %d\n", ret);
  (*__MINGW_IMP_SYMBOL(_exit))(255);
}

unsigned int __cdecl _get_output_format(void)
{
  return 0;
}

// These are required to provide the unrepfixed data symbols "timezone"
// and "tzname"; we can't remap "timezone" via a define due to clashes
// with e.g. "struct timezone".
typedef void __cdecl (*_tzset_func)(void);
extern _tzset_func __MINGW_IMP_SYMBOL(_tzset);

// Default initial values until _tzset has been called; these are the same
// as the initial values in msvcrt/ucrtbase.
static char initial_tzname0[] = "PST";
static char initial_tzname1[] = "PDT";
static char *initial_tznames[] = { initial_tzname0, initial_tzname1 };
static long initial_timezone = 28800;
static int initial_daylight = 1;
char** __MINGW_IMP_SYMBOL(tzname) = initial_tznames;
long * __MINGW_IMP_SYMBOL(timezone) = &initial_timezone;
int * __MINGW_IMP_SYMBOL(daylight) = &initial_daylight;

void __cdecl _tzset(void)
{
  __MINGW_IMP_SYMBOL(_tzset)();
  // Redirect the __imp_ pointers to the actual data provided by the UCRT.
  // From this point, the exposed values should stay in sync.
  __MINGW_IMP_SYMBOL(tzname) = _tzname;
  __MINGW_IMP_SYMBOL(timezone) = __timezone();
  __MINGW_IMP_SYMBOL(daylight) = __daylight();
}

void __cdecl tzset(void)
{
  _tzset();
}

// This is called for wchar cases with __USE_MINGW_ANSI_STDIO enabled (where the
// char case just uses fputc).
int __cdecl __ms_fwprintf(FILE *file, const wchar_t *fmt, ...)
{
  va_list ap;
  int ret;
  va_start(ap, fmt);
  ret = __stdio_common_vfwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_LEGACY_WIDE_SPECIFIERS, file, fmt, NULL, ap);
  va_end(ap);
  return ret;
}

// Dummy/unused __imp_ wrappers, to make GNU ld not autoexport these symbols.
void __cdecl (*__MINGW_IMP_SYMBOL(_amsg_exit))(int) = _amsg_exit;
unsigned int __cdecl (*__MINGW_IMP_SYMBOL(_get_output_format))(void) = _get_output_format;
void __cdecl (*__MINGW_IMP_SYMBOL(tzset))(void) = tzset;
int __cdecl (*__MINGW_IMP_SYMBOL(__ms_fwprintf))(FILE *, const wchar_t *, ...) = __ms_fwprintf;
#pragma GCC diagnostic pop
