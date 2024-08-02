/*
 * This Software is provided under the Zope Public License (ZPL) Version 2.1.

 * Copyright (c) 2009, 2010 by the mingw-w64 project

 * See the AUTHORS file for the list of contributors to the mingw-w64 project.

 * This license has been certified as open source. It has also been designated
 * as GPL compatible by the Free Software Foundation (FSF).

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:

 * 1. Redistributions in source code must retain the accompanying copyright
 *    notice, this list of conditions, and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the accompanying
 *    copyright notice, this list of conditions, and the following disclaimer
 *    in the documentation and/or other materials provided with the
 *    distribution.
 * 3. Names of the copyright holders must not be used to endorse or promote
 *    products derived from this software without prior written permission
 *    from the copyright holders.
 * 4. The right to distribute this software or to use it for any purpose does
 *    not give you the right to use Servicemarks (sm) or Trademarks (tm) of
 *    the copyright holders.  Use of them is covered by separate agreement
 *    with the copyright holders.
 * 5. If any files are modified, you must cause the modified files to carry
 *    prominent notices stating that you changed the files and the date of
 *    any change.

 * Disclaimer

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY EXPRESSED
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <errno.h>
#include <limits.h>
#include <fenv.h>
#include <math.h>
#include <errno.h>
#define FE_ROUNDING_MASK (FE_TONEAREST | FE_DOWNWARD | FE_UPWARD | FE_TOWARDZERO)

static long double do_powi_iter(long double d, int y)
{
  unsigned int u = (unsigned int)y;
  long double rslt = ((u & 1) != 0) ? d : 1.0L;
  u >>= 1;
  do
  {
    d *= d;
    if((u & 1) != 0)
      rslt *= d;
    u >>= 1;
  }
  while(u > 0);
  return rslt;
}

static long double __cdecl __powil(long double x, int y);

static long double __cdecl __powil(long double x, int y)
{
  int x_class = fpclassify(x);
  int odd_y = y & 1;
  int recip = 0;
  long double d, rslt;

  if(y == 0 || x == 1.0L)
    return 1.0L;
  else if(x_class == FP_NAN)
  {
    rslt = (signbit(x) ? -__builtin_nanl("") : __builtin_nanl(""));
    (*_errno()) = 33, __mingw_raise_matherr(1, "__powil", (double)(x), (double)((long double)y), (double)(rslt));
    return rslt;
  }
  else if(x_class == FP_ZERO)
  {
    if(y >= 0)
    {
      if(!odd_y || !signbit(x))
        return 0.0L;
      return -0.0L;
    }

    if(!odd_y || !signbit(x))
      return __builtin_huge_vall();
    return (signbit(x) ? -__builtin_huge_vall() : __builtin_huge_vall());
  }
  else if(x_class == FP_INFINITE)
  {
    /* pow( -inf, y) = +0 for y<0 and not an odd integer, */
    if(signbit(x) && y < 0 && !odd_y)
      return 0.0L;
    /* pow( -inf, y) = -inf for y an odd integer > 0. */
    if(signbit(x) && y >= 0 && odd_y)
      return -__builtin_huge_vall();
    /* pow(-inf, y) = +inf for y>0 and not an odd integer. */
    if(signbit(x) && y >= 0 && !odd_y)
      return __builtin_huge_vall();
    /* pow (+/-inf, y) is +/-0 with no exception for y an odd integer < 0. */
    if(y < 0)
    {
      /* pow (+/-inf, y) is +0 with no exception for finite y < 0 and not an odd integer. */
      return (odd_y && signbit(x) ? -0.0L : 0.0L);
    }
    /* pow (+/-inf, y) is +/-inf with no exception for finite y > 0 an odd integer. */
    /* pow (+/-inf, y) is +inf with no exception for finite y > 0 and not an odd integer. */
    return (odd_y && signbit(x) ? -__builtin_huge_vall() : __builtin_huge_vall());
  }

  d = fabsl(x);

  if(y < 0)
  {
    /* By default, do the reciprocal of the result. */
    recip = 1;
    y = -y;
  }

  if(!y)
    rslt = 1.0L;
  else if(y == 1)
    rslt = d;
  else
  {
    rslt = do_powi_iter(d, y);
    if(recip && fpclassify(rslt) == FP_INFINITE && d > 1.0L)
    {
      /* Uncommon case - we had overflow, but we're going to calculate
       * the reciprocal. If this happened, redo the calculation by doing
       * the reciprocal upfront instead. Instead of trying to calculate
       * whether this will happen, we prefer keeping the default case
       * cheap. */
      d = 1.0L / d;
      recip = 0;
      rslt = do_powi_iter(d, y);
    }
  }
  if(recip)
    rslt = 1.0L / rslt;
  if(signbit (x) && odd_y)
    rslt = -rslt;
  return rslt;
}

static long double internal_modf(long double value, long double *iptr)
{
  long double int_part = (long double)0.0;
  /* truncate */
  /* truncate */
  __asm__ __volatile__(
    "pushq  %%rax\n\t"
    "subq   $8,       %%rsp\n"
    "fnstcw 4(%%rsp)\n"
    "movzwl 4(%%rsp), %%eax\n"
    "orb    $12,      %%ah\n"
    "movw   %%ax,     (%%rsp)\n"
    "fldcw  (%%rsp)\n"
    "frndint\n"
    "fldcw  4(%%rsp)\n"
    "addq   $8, %%rsp\n"
    "popq %%rax"
    : "=t" (int_part) : "0" (value));  /* round */
  if(iptr)
    *iptr = int_part;
  return (isinf(value) ?  (long double)0.0 : value - int_part);
}

long double __cdecl powl(long double x, long double y)
{
  int x_class = fpclassify(x);
  int y_class = fpclassify(y);
  long odd_y = 0;
  long double d, rslt;

  if(y_class == FP_ZERO || x == 1.0L)
    return 1.0L;
  else if(x_class == FP_NAN || y_class == FP_NAN)
  {
    if(x_class == FP_NAN)
    {
      (*_errno()) = 33, __mingw_raise_matherr(1, "powl", (double)(x), (double)(y), (double)(x));
      return x;
    }
    else
    {
      (*_errno()) = 33, __mingw_raise_matherr(1, "powl", (double)(x), (double)(y), (double)(y));
      return y;
    }
  }
  else if(x_class == FP_ZERO)
  {
    if(y_class == FP_INFINITE)
      return (signbit(y) ? __builtin_huge_vall() : 0.0L);

    if(signbit(x) && internal_modf(y, &d) != 0.0)
    {
      return signbit(y) ? (1.0 / -x) : 0.0L;
      /*__FLT_RPT_DOMAIN ("pow", x, y, -__builtin_nanl(""));
      return -__builtin_nanl(""); */
    }
    odd_y = (internal_modf(ldexpl(y, -1), &d) != 0.0) ? 1 : 0;
    if(!signbit(y))
    {
      if(!odd_y || !signbit(x))
        return 0.0L;
      return -0.0L;
    }

    if(!odd_y || !signbit(x))
      return __builtin_huge_vall();
    return (signbit(x) ? -__builtin_huge_vall() : __builtin_huge_vall());
  }
  else if(y_class == FP_INFINITE)
  {
    long double a_x;

    if(x_class == FP_INFINITE)
      return (signbit(y) ? 0.0L : __builtin_huge_vall());
    a_x = (signbit(x) ? -x : x);
    if(a_x == 1.0)
      return 1.0L;
    if(a_x > 1.0)
      return (signbit(y) == 0 ? __builtin_huge_vall() : 0.0L);
    return (!signbit(y) ? 0.0L : __builtin_huge_vall());
  }
  else if(x_class == FP_INFINITE)
  {
    /* pow (x, y) signals the invalid operation exception for finite x < 0 and finite non-integer y. */
    if(signbit(x) && internal_modf(y, &d) != 0.0)
    {
      return signbit(y) ? 1.0 / -x : -x;
      /*__FLT_RPT_DOMAIN ("pow", x, y, -__builtin_nanl(""));
      return -__builtin_nanl("");*/
    }
    odd_y = (internal_modf(ldexpl(y, -1), &d) != 0.0) ? 1 : 0;
    /* pow( -inf, y) = +0 for y<0 and not an odd integer, */
    if(signbit(x) && signbit(y) && !odd_y)
      return 0.0L;
    /* pow( -inf, y) = -inf for y an odd integer > 0. */
    if(signbit(x) && !signbit(y) && odd_y)
      return -__builtin_huge_vall();
    /* pow( -inf, y) = +inf for y>0 and not an odd integer. */
    if (signbit(x) && !signbit(y) && !odd_y)
      return __builtin_huge_vall();
    /* pow (+/-inf, y) is +/-0 with no exception for y an odd integer < 0. */
    if(signbit(y))
    {
      /* pow (+/-inf, y) is +0 with no exception for finite y < 0 and not an odd integer. */
      return (odd_y && signbit(x) ? -0.0L : 0.0L);
    }
    /* pow (+/-inf, y) is +/-inf with no exception for finite y > 0 an odd integer. */
    /* pow (+/-inf, y) is +inf with no exception for finite y > 0 and not an odd integer. */
    return (odd_y && signbit(x) ? -__builtin_huge_vall() : __builtin_huge_vall());
  }

  if(internal_modf(y, &d) != 0.0)
  {
    if(signbit(x))
    {
      (*_errno()) = 33, __mingw_raise_matherr(1, "powl", (double)(x), (double)(y), (double)(-__builtin_nanl("")));
      return -__builtin_nanl("");
    }
    if(y == 0.5L)
    {
      __asm__ __volatile__("fsqrt" : "=t" (rslt) : "0" (x));
      return rslt;
    }
  }
  else if((d <= (long double)INT_MAX && d >= (long double)INT_MIN))
    return __powil(x, (int)y);
  /* As exp already checks for minlog and maxlog no further checks are necessary. */
  rslt = (long double)exp2l((long double)y * log2l((long double)fabsl(x)));

  if(signbit(x) && internal_modf(ldexpl(y, -1), &d) != 0.0)
    rslt = -rslt;
  return rslt;
}

long double __cdecl (*__MINGW_IMP_SYMBOL(powl))(long double, long double) = powl;
