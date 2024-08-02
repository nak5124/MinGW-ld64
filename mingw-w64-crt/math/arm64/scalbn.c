/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <math.h>

double __cdecl scalbn(double x, int exp)
{
  return x * exp2(exp);
}
double __cdecl (*__MINGW_IMP_SYMBOL(scalbn))(double, int) = scalbn;

float __cdecl scalbnf(float x, int exp)
{
  return x * exp2f(exp);
}
float __cdecl (*__MINGW_IMP_SYMBOL(scalbnf))(float, int) = scalbnf;

long double __cdecl scalbnl(long double x, int exp) __attribute__((alias("scalbn")));
extern long double __attribute__((alias(__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(scalbn)))))
  (__cdecl *__MINGW_IMP_SYMBOL(scalbnl))(long double, int);

double __cdecl scalbln(double x, long exp) __attribute__((alias("scalbn")));
extern double __attribute__((alias(__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(scalbn)))))
  (__cdecl *__MINGW_IMP_SYMBOL(scalbln))(double, long);

float __cdecl scalblnf(float x, long exp) __attribute__((alias("scalbnf")));
extern float __attribute__((alias(__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(scalbnf)))))
  (__cdecl *__MINGW_IMP_SYMBOL(scalblnf))(float, long);

long double __cdecl scalblnl(long double x, long exp) __attribute__((alias("scalbnl")));
extern long double __attribute__((alias(__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(scalbnl)))))
  (__cdecl *__MINGW_IMP_SYMBOL(scalblnl))(long double, long);

double __cdecl ldexp(double x, int exp) __attribute__((alias("scalbn")));
extern double __attribute__ ((alias(__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(scalbn)))))
  (__cdecl *__MINGW_IMP_SYMBOL(ldexp))(double, int);

long double __cdecl ldexpl(long double x, int exp) __attribute__((alias("ldexp")));
extern double __attribute__ ((alias(__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(ldexp)))))
  (__cdecl *__MINGW_IMP_SYMBOL(ldexpl))(long double, int);