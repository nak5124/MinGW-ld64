/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define __FP_SIGNBIT 0x0200
int __signbit(double x);

typedef union __mingw_dbl_type_t
{
  double x;
  unsigned long long val;
  __extension__ struct
  {
    unsigned int low, high;
  } lh;
} __mingw_dbl_type_t;

int __signbit(double x)
{
  __mingw_dbl_type_t hlp;

  hlp.x = x;
  return ((hlp.lh.high & 0x80000000) != 0);
}

#undef signbit
int __attribute__((alias("__signbit"))) signbit(double);
