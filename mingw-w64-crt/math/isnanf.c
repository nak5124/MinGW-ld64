/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <math.h>
int
__isnanf (float _x)
{
    __mingw_flt_type_t hlp;
    int i;
    
    hlp.x = _x;
    i = hlp.val & 0x7fffffff;
    i = 0x7f800000 - i;
    return (int) (((unsigned int) i) >> 31);
}

int __attribute__ ((alias ("__isnanf"))) isnanf (float);
