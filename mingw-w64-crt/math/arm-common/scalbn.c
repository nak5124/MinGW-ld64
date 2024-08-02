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

float __cdecl scalbnf(float x, int exp)
{
    return x * exp2f(exp);
}

long double __cdecl scalbnl(long double x, int exp)
{
#if defined(__aarch64__) || defined(_ARM64_)
    return scalbn(x, exp);
#else
# error Not supported on your platform yet
#endif
}

double __cdecl scalbln(double x, long exp)
{
    return x * exp2(exp);
}

float __cdecl scalblnf(float x, long exp)
{
    return x * exp2f(exp);
}

long double __cdecl scalblnl(long double x, long exp)
{
#if defined(__aarch64__) || defined(_ARM64_)
    return scalbln(x, exp);
#else
# error Not supported on your platform yet
#endif
}

double __cdecl (*__MINGW_IMP_SYMBOL(scalbn))(double, int) = scalbn;
float __cdecl (*__MINGW_IMP_SYMBOL(scalbnf))(float, int) = scalbnf;
long double __cdecl (*__MINGW_IMP_SYMBOL(scalbnl))(long double, int) = scalbnl;
double __cdecl (*__MINGW_IMP_SYMBOL(scalbln))(double, int) = scalbln;
float __cdecl (*__MINGW_IMP_SYMBOL(scalblnf))(float, int) = scalblnf;
long double __cdecl (*__MINGW_IMP_SYMBOL(scalblnl))(long double, int) = scalblnl;
double __cdecl ldexp(double x, int exp) __attribute__((alias("scalbn")));
extern double __attribute__ ((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(scalbn)))))
(__cdecl *__MINGW_IMP_SYMBOL(ldexp))(double x, int exp);
