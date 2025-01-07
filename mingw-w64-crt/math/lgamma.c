/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _USE_MATH_DEFINES
#include <math.h>
#include <errno.h>

typedef union uD
{
  unsigned short sh[4];
  double         d;
} uD;

/*
Cephes Math Library Release 2.2:  July, 1992
Copyright 1984, 1987, 1988, 1992 by Stephen L. Moshier
Direct inquiries to 30 Frost Street, Cambridge, MA 02140
*/
/*              polevl.c
 *              p1evl.c
 *
 *  Evaluate polynomial
 *
 *
 *
 * SYNOPSIS:
 *
 * int N;
 * double x, y, coef[N+1], polevl[];
 *
 * y = polevl( x, coef, N );
 *
 *
 *
 * DESCRIPTION:
 *
 * Evaluates polynomial of degree N:
 *
 *                     2          N
 * y  =  C  + C x + C x  +...+ C x
 *        0    1     2          N
 *
 * Coefficients are stored in reverse order:
 *
 * coef[0] = C  , ..., coef[N] = C  .
 *            N                   0
 *
 *  The function p1evl() assumes that coef[N] = 1.0 and is
 * omitted from the array.  Its calling arguments are
 * otherwise the same as polevl().
 *
 *
 * SPEED:
 *
 * In the interest of speed, there are no checks for out
 * of bounds arithmetic.  This routine is used by most of
 * the functions in the library.  Depending on available
 * equipment features, the user may wish to rewrite the
 * program in microcode or assembly language.
 *
 */

/* Polynomial evaluator:
 *  P[0] x^n  +  P[1] x^(n-1)  +  ...  +  P[n]
 */
static __inline__ double polevl(double x, const uD *p, int n)
{
  register double y;

  y = p->d;
  p++;
  do
  {
    y = y * x + p->d;
    p++;
  }
  while (--n);
  return (y);
}

/* Polynomial evaluator:
 *  x^n  +  P[0] x^(n-1)  +  P[1] x^(n-2)  +  ...  +  P[n]
 */
static __inline__  double p1evl(double x, const uD *p, int n)
{
  register double y;

  n -= 1;
  y = x + p->d; p++;
  do
  {
    y = y * x + p->d; p++;
  }
  while (--n);
  return (y);
}

/* A[]: Stirling's formula expansion of log gamma
 * B[], C[]: log gamma function between 2 and 3
 */
static const uD A[] =
{
  { { 0x6661, 0x2733, 0x9850, 0x3f4a } },
  { { 0xe943, 0xb580, 0x7fbd, 0xbf43 } },
  { { 0x5ebb, 0x20dc, 0x019f, 0x3f4a } },
  { { 0xa5a1, 0x16b0, 0xc16c, 0xbf66 } },
  { { 0x554b, 0x5555, 0x5555, 0x3fb5 } }
};

static const uD B[] =
{
  { { 0x6761, 0x8ff3, 0x8901, 0xc095 } },
  { { 0xb93e, 0x355b, 0xf234, 0xc0e2 } },
  { { 0x89e5, 0xf890, 0x3d73, 0xc114 } },
  { { 0xdb51, 0xf994, 0xbc82, 0xc131 } },
  { { 0xf20b, 0x0219, 0x4589, 0xc13a } },
  { { 0x055e, 0x5418, 0x0c67, 0xc12a } }
};

static const uD C[] =
{
  { { 0x12b2, 0x1cf3, 0xfd0d, 0xc075 } },
  { { 0xd757, 0x7b89, 0xaa0d, 0xc0d0 } },
  { { 0x4c9b, 0xb974, 0xeb84, 0xc10a } },
  { { 0x0043, 0x7195, 0x6286, 0xc131 } },
  { { 0xf34c, 0x892f, 0x5255, 0xc143 } },
  { { 0xe14a, 0x6a11, 0xce4b, 0xc13e } }
};

/* log( sqrt( 2*pi ) ) */
static const union
{
  unsigned short s[4];
  double         d;
} ls2p = { { 0xbeb5, 0xc864, 0x67f1, 0x3fed } };
#define LS2PI  (ls2p.d)
#define MAXLGM 2.556348e305

/* log(pi) */
static const union
{
  unsigned short s[4];
  double         d;
} lpi = { { 0xa1bd, 0x48e7, 0x50d0, 0x3ff2 } };
#define LOGPI (lpi.d)

/* Logarithm of gamma function */
/* Reentrant version */
static double __lgamma_r(double x, int *sgngam);

static double __lgamma_r(double x, int *sgngam)
{
  double p, q, u, w, z;
  int i;

  *sgngam = 1;
  if(isnan(x))
  {
    return x;
  }

  if(!isfinite(x))
  {
    return HUGE_VAL;
  }

  if(x < -34.0)
  {
    q = -x;
    w = __lgamma_r(q, sgngam);  /* note this modifies sgngam! */
    p = floor(q);
    if(p == q)
    {
lgsing:
      errno = EDOM;
      return HUGE_VAL;
    }
    i = p;
    if((i & 1) == 0)
    {
      *sgngam = -1;
    }
    else
    {
      *sgngam = 1;
    }
    z = q - p;
    if(z > 0.5)
    {
      p += 1.0;
      z = p - q;
    }
    z = q * sin(M_PI * z);
    if(z == 0.0)
    {
      goto lgsing;
    }
    z = LOGPI - log(z) - w;
    return z;
  }

  if(x < 13.0)
  {
    z = 1.0;
    p = 0.0;
    u = x;
    while(u >= 3.0)
    {
      p -= 1.0;
      u = x + p;
      z *= u;
    }
    while(u < 2.0)
    {
      if(u == 0.0)
      {
        goto lgsing;
      }
      z /= u;
      p += 1.0;
      u = x + p;
    }
    if(z < 0.0)
    {
      *sgngam = -1;
      z = -z;
    }
    else
    {
      *sgngam = 1;
    }
    if(u == 2.0)
    {
      return log(z);
    }
    p -= 2.0;
    x = x + p;
    p = x * polevl(x, B, 5) / p1evl(x, C, 6);
    return log(z) + p;
  }

  if(x > MAXLGM)
  {
    errno = ERANGE;
    return *sgngam * HUGE_VAL;
  }

  q = (x - 0.5) * log(x) - x + LS2PI;
  if(x > 1.0e8)
  {
    return q;
  }

  p = 1.0 / (x * x);
  if(x >= 1000.0)
  {
    q += ((7.9365079365079365079365e-4 * p - 2.7777777777777777777778e-3) * p + 0.0833333333333333333333) / x;
  }
  else
  {
    q += polevl(p, A, 4) / x;
  }
  return q;
}

/* This is the C99 version */
double __cdecl lgamma(double x)
{
  return __lgamma_r(x, &signgam);
}

double __cdecl (*__MINGW_IMP_SYMBOL(lgamma))(double x) = lgamma;

long double __cdecl lgammal(long double x) __attribute__((alias("lgamma")));
extern long double (__cdecl *__MINGW_IMP_SYMBOL(lgammal))(long double x)
  __attribute__((alias(__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(lgamma)))));
