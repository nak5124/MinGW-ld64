/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define __CRT__NO_INLINE
#include <math.h>

int __fpclassifyf (float _x)
{
    __mingw_flt_type_t hlp;

    hlp.x = _x;
    hlp.val &= 0x7fffffff;
    if (hlp.val == 0)
      return FP_ZERO;
    if (hlp.val < 0x800000)
      return FP_SUBNORMAL;
    if (hlp.val >= 0x7f800000)
      return (hlp.val > 0x7f800000 ? FP_NAN : FP_INFINITE);
    return FP_NORMAL;
}
