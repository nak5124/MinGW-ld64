/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

/* The purpose of this file is to provide support for MSVC's intrinsics (what gcc calls
 * Builtins) in gcc.  In MSVC, there are several features for intrinsics:

 * - Intrinsics can either be implemented inline (via the compiler), or implemented as functions.
 * - You can specify which approach you prefer either globally (via compile switch /Oi) or
 *   on a function by function basis via pragmas.
 * - Before you can use any of the intrinsics, they must be declared via a prototype.  For
 *   whatever reason, MS has decided to put all the intrinsics in one file (intrin.h) AND
 *   to put duplicate copies of some of these prototypes in various platform sdk headers.

 * In gcc, this is implemented as follows:

 * - The inline implementations for the intrinsics are located in intrin-impl.h.  This file
 *   is included by intrin.h, as well as various platform sdk headers.
 * - Including intrin.h will create definitions/implementations for all available MSVC intrinsics.
 * - Including various platforms sdk headers will only include the intrinsics defined in that
 *   header.  As of this writing, only winnt.h and winbase.h use this approach.
 * - If an application defines its own prototypes for intrinsics (ie without including any
 *   platform header or intrin.h), the symbols will be resolved from the library.  Since this
 *   will likely result in the code being invoked via 'call', performance may be degraded.

 * If you wish to implement intrinsic functions that are defined in intrin.h but are not
 * yet implemented in mingw-w64, see the comments at the top of intrin-impl.h.
 */
#ifndef __INTRIN_H_
#define __INTRIN_H_

#include <corecrt.h>
#include <setjmp.h>
#include <stddef.h>
#include <psdk_inc/intrin-impl.h>

/*
 * Intrins shiped with GCC conflict with our versions in C++, because they don't use extern "C"
 * linkage while our variants use them. We try to work around this by including those headers
 * here wrapped in extern "C" block. It's still possible that those intrins will get default
 * C++ linkage (when GCC headers are explicitly included before intrin.h), but at least their
 * guards will prevent duplicated declarations and avoid conflicts.
 *
 * On GCC 4.9 and Clang we may always include those headers. On older GCCs, we may do it only if CPU
 * features used by them are enabled, so we need to check macros like __SSE__ or __MMX__ first.
 */
#if __MINGW_GNUC_PREREQ(4, 9) || defined(__clang__)
# define __MINGW_FORCE_SYS_INTRINS
#endif

#if defined(__x86_64__) && !defined(__arm64ec__)
#include <stdlib.h>
#include <errno.h>

__MINGW_BEGIN_C_DECLS

#include <x86intrin.h>
#include <cpuid.h>

/* Undefine the GCC one taking 5 parameters to prefer the mingw-w64 one. */
#undef __cpuid

/* Before 4.9.2, x86intrin.h had broken versions of these. */
#undef _lrotl
#undef _lrotr

__MINGW_END_C_DECLS

#endif

#ifndef __MINGW_FORCE_SYS_INTRINS
# ifndef __MMX__
    typedef union __m64 { char v[7]; } __m64;
# endif
# ifndef __SSE__
    typedef union __m128 { char v[16]; } __m128;
# endif
# ifndef __SSE2__
    typedef union __m128d { char v[16]; } __m128d;
    typedef union __m128i { char v[16]; } __m128i;
# endif
#endif

#ifndef WINAPI
# define WINAPI __stdcall
#endif

#if defined(__x86_64__) && !defined(__arm64ec__)

#if defined(__MMX__) || defined(__MINGW_FORCE_SYS_INTRINS)
__MINGW_BEGIN_C_DECLS
#include <mmintrin.h>
__MINGW_END_C_DECLS
#endif

/* Note: mm3dnow.h intentionally not included; 3DNow! is deprecated. */

/* NOTE: it's not included by MS version, but we do it to try work around C++/C linkage differences */
#if defined(__SSE__) || defined(__MINGW_FORCE_SYS_INTRINS)
__MINGW_BEGIN_C_DECLS
#include <xmmintrin.h>
__MINGW_END_C_DECLS
#endif

#if defined(__SSE2__) || defined(__MINGW_FORCE_SYS_INTRINS)
__MINGW_BEGIN_C_DECLS
#include <emmintrin.h>
__MINGW_END_C_DECLS
#endif

#if defined(__SSE3__) || defined(__MINGW_FORCE_SYS_INTRINS)
__MINGW_BEGIN_C_DECLS
#include <pmmintrin.h>
__MINGW_END_C_DECLS
#endif

#endif

#define __MACHINEX64         __MACHINE
#define __MACHINEI           __MACHINE
#define __MACHINEX86X        __MACHINE
#define __MACHINEX86X_NOIA64 __MACHINE
#define __MACHINEIW64        __MACHINE
#define __MACHINEW64         __MACHINE
#define __MACHINEARM64       __MACHINE
#define __MACHINEARM_ARM64   __MACHINE

#define __MACHINE(X) X;
#define __MACHINEZ(X)

#if !defined(__x86_64__) || defined(__arm64ec__)
# undef  __MACHINEX64
# undef  __MACHINEI
# undef  __MACHINEX86X
# undef  __MACHINEX86X_NOIA64
# undef  __MACHINEIW64
# undef  __MACHINEW64
# define __MACHINEX64         __MACHINEZ
# define __MACHINEI           __MACHINEZ
# define __MACHINEX86X        __MACHINEZ
# define __MACHINEX86X_NOIA64 __MACHINEZ
# define __MACHINEIW64        __MACHINEZ
# define __MACHINEW64         __MACHINEZ
#endif

#if !(defined(__aarch64__) || defined(__arm64ec__))
# undef  __MACHINEARM64
# undef  __MACHINEARM_ARM64
# define __MACHINEARM64     __MACHINEZ
# define __MACHINEARM_ARM64 __MACHINEZ
#endif

__MINGW_BEGIN_C_DECLS

  /* Put all declarations potentially colliding with POSIX headers here.
   * So far, Cygwin is the only POSIX system using this header file.
   * If that ever changes, make sure to tweak the guarding ifndef. */
    __MACHINE(int          __cdecl abs(int))
    __MACHINEX64(double    __cdecl ceil(double))
    __MACHINE(long         __cdecl labs(long))
    __MACHINE(int          __cdecl memcmp(const void *, const void *, size_t))
    __MACHINE(void        *__cdecl memcpy(void *__restrict, const void *__restrict, size_t))
    __MACHINE(void        *__cdecl memset(void *, int, size_t))
    __MACHINE(char        *__cdecl strcat(char *, const char *))
    __MACHINE(int          __cdecl strcmp(const char *, const char *))
    __MACHINE(char        *__cdecl strcpy(char *__restrict, const char *__restrict))
    __MACHINE(size_t       __cdecl strlen(const char *))
    __MACHINEIW64(wchar_t *__cdecl wcscat(wchar_t *__restrict, const wchar_t *__restrict))
    __MACHINEIW64(int      __cdecl wcscmp(const wchar_t *, const wchar_t *))
    __MACHINEIW64(wchar_t *__cdecl wcscpy(wchar_t *__restrict, const wchar_t *__restrict))
    __MACHINEIW64(size_t   __cdecl wcslen(const wchar_t *))

#undef  _alloca
#define _alloca(x) __builtin_alloca((x))
    __MACHINE(unsigned short                     __cdecl  _byteswap_ushort(unsigned short value))
    __MACHINE(unsigned __LONG32                  __cdecl  _byteswap_ulong(unsigned __LONG32 value))
    __MACHINE(__MINGW_EXTENSION unsigned __int64 __cdecl  _byteswap_uint64(unsigned __int64 value))
    __MACHINE(void                               __cdecl __debugbreak(void))
    __MACHINE(void                               __cdecl __fastfail(unsigned int code) __MINGW_NORETURN)
#if 0  /* moved to psdk_inc/intrin-impl.h */
    __MACHINEI(__LONG32                     _InterlockedDecrement(__LONG32 volatile *))
    __MACHINEX64(__MINGW_EXTENSION __int64  _InterlockedDecrement64(__int64 volatile *))
    __MACHINEI(__LONG32                     _InterlockedExchange(__LONG32 volatile *, __LONG32))
    __MACHINEX64(__MINGW_EXTENSION __int64  _InterlockedExchange64(__int64 volatile *, __int64))
    __MACHINEX64(void                      *_InterlockedExchangePointer(void *volatile *, void *))
    __MACHINEI(__LONG32                     _InterlockedExchangeAdd(__LONG32 volatile *, __LONG32))
    __MACHINEX64(__MINGW_EXTENSION __int64  _InterlockedExchangeAdd64(__int64 volatile *, __int64))
    __MACHINEI(__LONG32                     _InterlockedCompareExchange(__LONG32 volatile *, __LONG32, __LONG32))
    __MACHINEI(__MINGW_EXTENSION __int64    _InterlockedCompareExchange64(__int64 volatile *, __int64, __int64))
    __MACHINEX64(void                      *_InterlockedCompareExchangePointer(void *volatile *, void *, void *))
    __MACHINEI(__LONG32                     _InterlockedIncrement(__LONG32 volatile *))
    __MACHINEX64(__MINGW_EXTENSION __int64  _InterlockedIncrement64(__int64 volatile *))
    __MACHINEIW64(__LONG32                  _InterlockedOr(__LONG32 volatile *, __LONG32))
    __MACHINEW64(__MINGW_EXTENSION __int64  _InterlockedOr64(__int64 volatile *, __int64))
    __MACHINEIW64(__LONG32                  _InterlockedXor(__LONG32 volatile *, __LONG32))
    __MACHINEW64(__MINGW_EXTENSION __int64  _InterlockedXor64(__int64 volatile *, __int64))
    __MACHINEIW64(__LONG32                  _InterlockedAnd(__LONG32 volatile *, __LONG32))
    __MACHINEW64(__MINGW_EXTENSION __int64  _InterlockedAnd64(__int64 volatile *, __int64))
#endif
    __MACHINEZ(void __cdecl longjmp(jmp_buf, int))
#if 0  /* moved to psdk_inc/intrin-impl.h */
    __MACHINE(unsigned long __cdecl _lrotl(unsigned long,int))
    __MACHINE(unsigned long __cdecl _lrotr(unsigned long,int))
#endif
    __MACHINEARM_ARM64(void __cdecl __prefetch(const void *addr))
#pragma push_macro ("_rotl")
#undef _rotl
    __MACHINE(unsigned int __cdecl _rotl(unsigned int, int))
#pragma pop_macro ("_rotl")
#pragma push_macro ("_rotr")
#undef _rotr
    __MACHINE(unsigned int __cdecl _rotr(unsigned int, int))
#pragma pop_macro ("_rotr")
#undef _rotl64
#undef _rotr64
    __MACHINE(__MINGW_EXTENSION unsigned __int64 __cdecl _rotl64(unsigned __int64, int))
    __MACHINE(__MINGW_EXTENSION unsigned __int64 __cdecl _rotr64(unsigned __int64, int))
#define _rotl64 __rolq
#define _rotr64 __rorq
    __MACHINE(int    __cdecl _setjmp(jmp_buf, void *) __MINGW_NOTHROW __MINGW_RETURN_TWICE)
    __MACHINEX64(int __cdecl _setjmpex(jmp_buf, void *) __MINGW_NOTHROW __MINGW_RETURN_TWICE)
    __MACHINE(char  *__cdecl _strset(char *, int))
    __MACHINE(char  *__cdecl  strset(char *, int))
#if 0  /* moved to psdk_inc/intrin-impl.h */
    __MACHINEI(void                                  _WriteBarrier(void))
    __MACHINEI(void                                  _ReadWriteBarrier(void))
    __MACHINEX64(void                               __faststorefence(void))
    __MACHINEX64(__MINGW_EXTENSION unsigned __int64 __readcr0(void))
    __MACHINEX64(__MINGW_EXTENSION unsigned __int64 __readcr2(void))
    __MACHINEX64(__MINGW_EXTENSION unsigned __int64 __readcr3(void))
    __MACHINEX64(__MINGW_EXTENSION unsigned __int64 __readcr4(void))
    __MACHINEX64(__MINGW_EXTENSION unsigned __int64 __readcr8(void))
    __MACHINEX64(__MINGW_EXTENSION void             __writecr0(unsigned __int64))
    __MACHINEX64(__MINGW_EXTENSION void             __writecr3(unsigned __int64))
    __MACHINEX64(__MINGW_EXTENSION void             __writecr4(unsigned __int64))
    __MACHINEX64(__MINGW_EXTENSION void             __writecr8(unsigned __int64))
    __MACHINEI(__MINGW_EXTENSION unsigned __int64   __readmsr(unsigned __LONG32))
    __MACHINEI(__MINGW_EXTENSION void               __writemsr(unsigned __LONG32, unsigned __int64))
    __MACHINEI(void                                 __movsb(unsigned char *, unsigned char const *, size_t))
    __MACHINEI(void                                 __movsw(unsigned short *, unsigned short const *, size_t))
    __MACHINEI(void                                 __movsd(unsigned __LONG32 *, unsigned __LONG32 const *, size_t))
    __MACHINEX64(__MINGW_EXTENSION void             __movsq(unsigned long long *, unsigned long long const *, size_t))
    __MACHINEX64(unsigned char                      __readgsbyte(unsigned __LONG32 Offset))
    __MACHINEX64(unsigned short                     __readgsword(unsigned __LONG32 Offset))
    __MACHINEX64(unsigned __LONG32                  __readgsdword(unsigned __LONG32 Offset))
    __MACHINEX64(__MINGW_EXTENSION unsigned __int64 __readgsqword(unsigned __LONG32 Offset))
    __MACHINEX64(void                               __writegsbyte(unsigned __LONG32 Offset, unsigned char Data))
    __MACHINEX64(void                               __writegsword(unsigned __LONG32 Offset, unsigned short Data))
    __MACHINEX64(void                               __writegsdword(unsigned __LONG32 Offset, unsigned __LONG32 Data))
    __MACHINEX64(__MINGW_EXTENSION void             __writegsqword(unsigned __LONG32 Offset, unsigned __int64 Data))
    __MACHINEI(unsigned char                        __inbyte(unsigned short Port))
    __MACHINEI(unsigned short                       __inword(unsigned short Port))
    __MACHINEI(unsigned __LONG32                    __indword(unsigned short Port))
    __MACHINEI(void                                 __outbyte(unsigned short Port, unsigned char Data))
    __MACHINEI(void                                 __outword(unsigned short Port, unsigned short Data))
    __MACHINEI(void                                 __outdword(unsigned short Port, unsigned __LONG32 Data))
    __MACHINEI(void                                 __inbytestring(unsigned short Port, unsigned char *Buffer, unsigned __LONG32 Count))
    __MACHINEI(void                                 __inwordstring(unsigned short Port, unsigned short *Buffer, unsigned __LONG32 Count))
    __MACHINEI(void                                 __indwordstring(unsigned short Port, unsigned __LONG32 *Buffer, unsigned __LONG32 Count))
    __MACHINEI(void                                 __outbytestring(unsigned short Port, unsigned char *Buffer, unsigned __LONG32 Count))
    __MACHINEI(void                                 __outwordstring(unsigned short Port, unsigned short *Buffer, unsigned __LONG32 Count))
    __MACHINEI(void                                 __outdwordstring(unsigned short Port, unsigned __LONG32 *Buffer, unsigned __LONG32 Count))
    __MACHINEI(void                                 __stosb(unsigned char *, unsigned char, size_t))
    __MACHINEI(void                                 __stosw(unsigned short *, unsigned short, size_t))
    __MACHINEI(void                                 __stosd(unsigned __LONG32 *, unsigned __LONG32, size_t))
    __MACHINEX64(__MINGW_EXTENSION void             __stosq(unsigned __int64 *, unsigned __int64, size_t))
    __MACHINEIW64(unsigned char                      _bittest(__LONG32 const *a, __LONG32 b))
    __MACHINEIW64(unsigned char                      _bittestandset(__LONG32 *a, __LONG32 b))
    __MACHINEIW64(unsigned char                      _bittestandreset(__LONG32 *a, __LONG32 b))
    __MACHINEIW64(unsigned char                      _bittestandcomplement(__LONG32 *a,__LONG32 b))
    __MACHINEI(unsigned char                          InterlockedBitTestAndSet(volatile __LONG32 *a, __LONG32 b))
    __MACHINEI(unsigned char                          InterlockedBitTestAndReset(volatile __LONG32 *a, __LONG32 b))
    __MACHINEI(unsigned char                          InterlockedBitTestAndComplement(volatile __LONG32 *a, __LONG32 b))
    __MACHINEI(unsigned char                         _interlockedbittestandset(__LONG32 *a, __LONG32 b))
    __MACHINEI(unsigned char                         _interlockedbittestandreset(__LONG32 *a, __LONG32 b))
    __MACHINEI(unsigned char                         _interlockedbittestandcomplement(__LONG32 *a, __LONG32 b))
    __MACHINEW64(__MINGW_EXTENSION unsigned char     _bittest64(__int64 const *a, __int64 b))
    __MACHINEW64(__MINGW_EXTENSION unsigned char     _bittestandset64(__int64 *a, __int64 b))
    __MACHINEW64(__MINGW_EXTENSION unsigned char     _bittestandreset64(__int64 *a, __int64 b))
    __MACHINEW64(__MINGW_EXTENSION unsigned char     _bittestandcomplement64(__int64 *a,__int64 b))
    __MACHINEX64(__MINGW_EXTENSION unsigned char      InterlockedBitTestAndSet64(volatile __int64 *a, __int64 b))
    __MACHINEX64(__MINGW_EXTENSION unsigned char      InterlockedBitTestAndReset64(volatile __int64 *a, __int64 b))
    __MACHINEX64(__MINGW_EXTENSION unsigned char      InterlockedBitTestAndComplement64(volatile __int64 *a, __int64 b))
    __MACHINEX64(__MINGW_EXTENSION unsigned char     _interlockedbittestandset64(__int64 *a, __int64 b))
    __MACHINEX64(__MINGW_EXTENSION unsigned char     _interlockedbittestandreset64(__int64 *a, __int64 b))
    __MACHINEX64(__MINGW_EXTENSION unsigned char     _interlockedbittestandcomplement64(__int64 *a, __int64 b))
    __MACHINEI(void                                 __cpuid(int a[4], int b))
#endif
    __MACHINE(__MINGW_EXTENSION __int64 __cdecl _abs64(__int64))
#if 0  /* moved to psdk_inc/intrin-impl.h */
    __MACHINEIW64(unsigned char                  _BitScanForward(unsigned __LONG32 *Index, unsigned __LONG32 Mask))
    __MACHINEIW64(unsigned char                  _BitScanReverse(unsigned __LONG32 *Index, unsigned __LONG32 Mask))
    __MACHINEW64(__MINGW_EXTENSION unsigned char _BitScanForward64(unsigned __LONG32 *Index, unsigned __int64 Mask))
    __MACHINEW64(__MINGW_EXTENSION unsigned char _BitScanReverse64(unsigned __LONG32 *Index, unsigned __int64 Mask))
#endif
    __MACHINEIW64(_CRTIMP wchar_t *__cdecl _wcsset(wchar_t *, wchar_t))
#if 0  /* moved to psdk_inc/intrin-impl.h */
    __MACHINEW64(__MINGW_EXTENSION unsigned __int64 __shiftleft128(unsigned __int64 LowPart, unsigned __int64 HighPart, unsigned char Shift))
    __MACHINEW64(__MINGW_EXTENSION unsigned __int64 __shiftright128(unsigned __int64 LowPart, unsigned __int64 HighPart, unsigned char Shift))
    __MACHINEW64(__MINGW_EXTENSION unsigned __int64  _umul128(unsigned __int64 multiplier, unsigned __int64 multiplicand, unsigned __int64 *highproduct))
    __MACHINEW64(__MINGW_EXTENSION __int64           _mul128(__int64 multiplier, __int64 multiplicand, __int64 *highproduct))
    __MACHINEI(void                                 __int2c(void))
    __MACHINEIW64(void                               _ReadBarrier(void))
    __MACHINEIW64(unsigned char                      _rotr8(unsigned char value, unsigned char shift))
    __MACHINEIW64(unsigned short                     _rotr16(unsigned short value, unsigned char shift))
    __MACHINEIW64(unsigned char                      _rotl8(unsigned char value, unsigned char shift))
    __MACHINEIW64(unsigned short                     _rotl16(unsigned short value, unsigned char shift))
    __MACHINEIW64(short                              _InterlockedIncrement16(short volatile *Addend))
    __MACHINEIW64(short                              _InterlockedDecrement16(short volatile *Addend))
    __MACHINEIW64(short                              _InterlockedCompareExchange16(short volatile *Destination, short Exchange, short Comparand))
#endif

__MINGW_END_C_DECLS

#endif  /* __INTRIN_H_ */
