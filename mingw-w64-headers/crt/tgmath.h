/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _TGMATH_H
#define _TGMATH_H

#include <corecrt.h>
#include <math.h>
#include <complex.h>

__MINGW_BEGIN_C_DECLS

#define __TGMATH_FNCS(fnc)          fnc ## f, fnc, fnc ## l

#define __TGMATH_RC(z, rfnc, cfnc)       __builtin_tgmath(__TGMATH_FNCS(rfnc), __TGMATH_FNCS(cfnc), (z))
#define __TGMATH_RC2(z1, z2, rfnc, cfnc) __builtin_tgmath(__TGMATH_FNCS(rfnc), __TGMATH_FNCS(cfnc), (z1), (z2))
#define __TGMATH_R1(x, rfnc)             __builtin_tgmath(__TGMATH_FNCS(rfnc), (x))
#define __TGMATH_R2(x, y, rfnc)          __builtin_tgmath(__TGMATH_FNCS(rfnc), (x), (y))
#define __TGMATH_R3(x, y, z, rfnc)       __builtin_tgmath(__TGMATH_FNCS(rfnc), (x), (y), (z))
#define __TGMATH_C1(z, cfnc)             __builtin_tgmath(__TGMATH_FNCS(cfnc), (z))

#define acos(z)     __TGMATH_RC(z, acos, cacos)
#define asin(z)     __TGMATH_RC(z, asin, casin)
#define atan(z)     __TGMATH_RC(z, atan, catan)
#define atan2(x, y) __TGMATH_R2(x, y, atan2)
#define cos(z)      __TGMATH_RC(z, cos,   ccos)
#define sin(z)      __TGMATH_RC(z, sin,   csin)
#define tan(z)      __TGMATH_RC(z, tan,   ctan)
#define acosh(z)    __TGMATH_RC(z, acosh, cacosh)
#define asinh(z)    __TGMATH_RC(z, asinh, casinh)
#define atanh(z)    __TGMATH_RC(z, atanh, catanh)
#define cosh(z)     __TGMATH_RC(z, cosh,  ccosh)
#define sinh(z)     __TGMATH_RC(z, sinh,  csinh)
#define tanh(z)     __TGMATH_RC(z, tanh,  ctanh)
#define exp(z)      __TGMATH_RC(z, exp,   cexp)
#define exp2(x)     __TGMATH_R1(x, exp2)
#define expm1(x)    __TGMATH_R1(x, expm1)
#define frexp(x, y) __TGMATH_R2(x, y, frexp)
#define ilogb(x)    __TGMATH_R1(x, ilogb)
#define ldexp(x, y) __TGMATH_R2(x, y, ldexp)
#define log(z)      __TGMATH_RC(z, log, clog)
#if defined(__MINGW_USE_GNU) || defined(__MINGW_USE_MS)
# define log10(z) __TGMATH_RC(z, log10, clog10)
#else
# define log10(x) __TGMATH_R1(x, log10)
#endif
#define log1p(x)         __TGMATH_R1(x, log1p)
#define log2(x)          __TGMATH_R1(x, log2)
#define logb(x)          __TGMATH_R1(x, logb)
#define scalbn(x, y)     __TGMATH_R2(x, y, scalbn)
#define scalbln(x, y)    __TGMATH_R2(x, y, scalbln)
#define cbrt(x)          __TGMATH_R1(x, cbrt)
#define fabs(x)          __TGMATH_RC(x, fabs, cabs)
#define hypot(x, y)      __TGMATH_R2(x, y, hypot)
#define pow(z1, z2)      __TGMATH_RC2(z1, z2, pow, cpow)
#define sqrt(z)          __TGMATH_RC(z, sqrt, csqrt)
#define erf(x)           __TGMATH_R1(x, erf)
#define erfc(x)          __TGMATH_R1(x, erfc)
#define lgamma(x)        __TGMATH_R1(x, lgamma)
#define tgamma(x)        __TGMATH_R1(x, tgamma)
#define ceil(x)          __TGMATH_R1(x, ceil)
#define floor(x)         __TGMATH_R1(x, floor)
#define nearbyint(x)     __TGMATH_R1(x, nearbyint)
#define rint(x)          __TGMATH_R1(x, rint)
#define lrint(x)         __TGMATH_R1(x, lrint)
#define llrint(x)        __TGMATH_R1(x, llrint)
#define round(x)         __TGMATH_R1(x, round)
#define lround(x)        __TGMATH_R1(x, lround)
#define llround(x)       __TGMATH_R1(x, llround)
#define trunc(x)         __TGMATH_R1(x, trunc)
#define fmod(x, y)       __TGMATH_R2(x, y, fmod)
#define remainder(x, y)  __TGMATH_R2(x, y, remainder)
#define remquo(x, y, z)  __TGMATH_R3(x, y, z, remquo)
#define copysign(x, y)   __TGMATH_R2(x, y, copysign)
#define nextafter(x, y)  __TGMATH_R2(x, y, nextafter)
#define nexttoward(x, y) __TGMATH_R2(x, y, nexttoward)
#define fdim(x, y)       __TGMATH_R2(x, y, fdim)
#define fmax(x, y)       __TGMATH_R2(x, y, fmax)
#define fmin(x, y)       __TGMATH_R2(x, y, fmin)
#define fma(x, y, z)     __TGMATH_R3(x, y, z, fma)
#define carg(z)          __TGMATH_C1(z, carg)
#define cimag(z)         __TGMATH_C1(z, cimag)
#define conj(z)          __TGMATH_C1(z, conj)
#define cproj(z)         __TGMATH_C1(z, cproj)
#define creal(z)         __TGMATH_C1(z, creal)

#ifdef __MINGW_USE_ISOC23
# define acospi(x)           __TGMATH_R1(x, acospi)
# define asinpi(x)           __TGMATH_R1(x, asinpi)
# define atanpi(x)           __TGMATH_R1(x, atanpi)
# define atan2pi(x, y)       __TGMATH_R2(x, y, atan2)
# define cospi(x)            __TGMATH_R1(x, cospi)
# define sinpi(x)            __TGMATH_R1(x, sinpi)
# define tanpi(x)            __TGMATH_R1(x, tanpi)
# define exp10(x)            __TGMATH_R1(x, exp10)
# define exp10m1(x)          __TGMATH_R1(x, exp10m1)
# define exp2m1(x)           __TGMATH_R1(x, exp2m1)
# define llogb(x)            __TGMATH_R1(x, llogb)
# define log10p1(x)          __TGMATH_R1(x, log10p1)
# define logp1(x)            __TGMATH_R1(x, logp1)
# define log2p1(x)           __TGMATH_R1(x, log2p1)
# define rsqrt(x)            __TGMATH_R1(x, rsqrt)
# define roundeven(x)        __TGMATH_R1(x, roundeven)
# define nextup(x)           __TGMATH_R1(x, nextup)
# define nextdown(x)         __TGMATH_R1(x, nextdown)
# define fmaximum(x)         __TGMATH_R1(x, fmaximum)
# define fminimum(x)         __TGMATH_R1(x, fminimum)
# define fmaximum_mag(x)     __TGMATH_R1(x, fmaximum_mag)
# define fminimum_mag(x)     __TGMATH_R1(x, fminimum_mag)
# define fmaximum_num(x)     __TGMATH_R1(x, fmaximum_num)
# define fminimum_num(x)     __TGMATH_R1(x, fminimum_num)
# define fmaximum_mag_num(x) __TGMATH_R1(x, fmaximum_mag_num)
# define fminimum_mag_num(x) __TGMATH_R1(x, fminimum_mag_num)
#endif

#ifdef __MINGW_USE_MS
# define norm(z) __TGMATH_C1(z, norm)
#endif

#ifdef __MINGW_USE_GNU
# define pow10(x) __TGMATH_R1(x, pow10)
#endif

__MINGW_END_C_DECLS

#endif  /* _TGMATH_H */


