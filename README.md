MinGW-ld64
==========

Fork of mingw-w64 configured to treat long double as equivalent to double for MSVC compatibility.

Differences from official MinGW-w64
-----------------------------------
 - Removed mingw implementations for long double, such as math functions, as long double is equal to double as in MSVC.
 - Support UCRT only.
 - Only GCC and CLANG are assumed.
 - Only x86_64 and ARM64 are supported.
 - _WIN32_WINNT and NTDDI_VERSION are always defined with the latest version.
 - Added _mingw_features.h, a new header for feature test macros.
 - Removed mingw stdio implementation.
 - Removed mingw mbwc convert functions.
 - Various header clean-ups, including removal of old functions.
 - Update OneCore_apiset to 10.0.26100.
 - Added new functions
   - arc4random, arc4random_buf, arc4random_uniform
   - getentropy
   - mkstemps/mkdtemp
   - strerror_r
   - strndup
   - realpath
   - old BSD strings functions
   - ffs functions
   - strverscmp
   - insque/remque
   - memmem
   - (un)setenv
   - strchrnul/memrchr
   - stp(n)cpy
   - qsort_r
   - clearenv
   - strcasestr
   - memset_s
   - memset_explicit
   - strlcat/strlcpy
   - strsep
   - a64l/l64a
   - reallocarray
   - timespec_getres
   - timegm/timelocal
   - malloc_usable_size
   - exp10/exp10f/exp10l/pow10/pow10f/pow10l(all:CORE-MATH)
   - exp10m1/exp10m1f/exp10m1l(all:CORE-MATH)
   - acospi/acospif/acospil(f:CORE-MATH)
   - roundeven/roundevenf/roundevenl
   - asinpi/asinpif/asinpil(f:CORE-MATH)
   - atanpi/atanpif/atanpil(all:CORE-MATH)
   - atan2pi/atan2pif/atan2pil(f:CORE-MATH)
   - cospi/cospif/cospil(f:CORE-MATH)
 - The printf format specifier is ISO-C compatible because _CRT_STDIO_ISO_WIDE_SPECIFIERS is defined by default.
 - Replace sincosf/sincos by CORE-MATH implementation
 - Replace lgammaf by CORE-MATH implementation
 - Various other cosmetics.

GCC patches
-----------
To use GCC where long double equals double, [GCC patches](https://github.com/nak5124/gcc/tree/ld64) are required.


ToDo
----
Add missing math functions
  - sinpi/tanpi
  - exp2m1
  - log10p1/log2p1
  - rsqrt

Update libonecore/libonecoreuap_apiset
