MinGW-w64 for LD64
==================

What is this ?
--------------
Here is the mingw-w64 source code forked for GCC, where long double equals double for compatibility with MSVC.

Differences from official
-------------------------
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
 - The printf format specifier is ISO-C compatible because _CRT_STDIO_ISO_WIDE_SPECIFIERS is defined by default.
 - Various other cosmetics.

GCC patches
-----------
To use GCC where long double equals double, [GCC patches](https://github.com/nak5124/gcc/tree/ld64) are required.


ToDo
----
 - Update headers
   - shlwapi.h
   - iphlpapi.h