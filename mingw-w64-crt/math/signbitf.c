/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define __FP_SIGNBIT 0x0200
int __cdecl __signbitf(float x);

typedef union __mingw_flt_type_t
{
  float x;
  unsigned int val;
} __mingw_flt_type_t;

int __cdecl __signbitf(float x)
{
  __mingw_flt_type_t hlp;
  hlp.x = x;
  return ((hlp.val & 0x80000000) != 0);
}
int __cdecl signbitf(float x) __attribute__((alias("__signbitf")));
