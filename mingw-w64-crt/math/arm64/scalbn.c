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
double __cdecl (*__MINGW_IMP_SYMBOL(scalbn))(double x, int exp) = scalbn;

float __cdecl scalbnf(float x, int exp)
{
  return x * exp2f(exp);
}
float __cdecl (*__MINGW_IMP_SYMBOL(scalbnf))(float x, int exp) = scalbnf;

long double __cdecl scalbnl(long double x, int exp) __attribute__((alias("scalbn")));
extern long double (__cdecl *__MINGW_IMP_SYMBOL(scalbnl))(long double x, int exp)
  __attribute__((alias(__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(scalbn)))));

double __cdecl scalbln(double x, long exp) __attribute__((alias("scalbn")));
extern double (__cdecl *__MINGW_IMP_SYMBOL(scalbln))(double x, long exp)
  __attribute__((alias(__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(scalbn)))));

float __cdecl scalblnf(float x, long exp) __attribute__((alias("scalbnf")));
extern float (__cdecl *__MINGW_IMP_SYMBOL(scalblnf))(float x, long exp)
  __attribute__((alias(__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(scalbnf)))));

long double __cdecl scalblnl(long double x, long exp) __attribute__((alias("scalbn")));
extern long double (__cdecl *__MINGW_IMP_SYMBOL(scalblnl))(long double, long)
  __attribute__((alias(__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(scalbn)))));

double __cdecl ldexp(double x, int exp) __attribute__((alias("scalbn")));
extern double (__cdecl *__MINGW_IMP_SYMBOL(ldexp))(double x, int exp)
  __attribute__((alias(__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(scalbn)))));

long double __cdecl ldexpl(long double x, int exp) __attribute__((alias("scalbn")));
extern double (__cdecl *__MINGW_IMP_SYMBOL(ldexpl))(long double x, int exp)
  __attribute__((alias(__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(scalbn)))));
