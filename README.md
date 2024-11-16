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
 - Various header clean-ups, including removal of old functions.
 - Add new functions
   - arc4random, arc4random_buf, arc4random_uniform
   - getentropy
   - mkstemps
   - strerror_r
   - strndup
 - The printf format specifier is ISO-C compatible because _CRT_STDIO_ISO_WIDE_SPECIFIERS is defined by default.
 - Various other cosmetics.

GCC patches
-----------
To use GCC where long double equals double, [GCC patches](https://github.com/nak5124/gcc/tree/ld64) are required.
