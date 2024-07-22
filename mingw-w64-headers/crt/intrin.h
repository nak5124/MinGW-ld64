/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

/* The purpose of this file is to provide support for MSVC's intrinsics (what gcc calls
   Builtins) in gcc.  In MSVC, there are several features for intrinsics:

   - Intrinsics can either be implemented inline (via the compiler), or implemented as functions.
   - You can specify which approach you prefer either globally (via compile switch /Oi) or
     on a function by function basis via pragmas.
   - Before you can use any of the intrinsics, they must be declared via a prototype.  For
     whatever reason, MS has decided to put all the intrinsics in one file (intrin.h) AND
     to put duplicate copies of some of these prototypes in various platform sdk headers.

   In gcc, this is implemented as follows:

   - The inline implementations for the intrinsics are located in intrin-impl.h.  This file
     is included by intrin.h, as well as various platform sdk headers.
   - Including intrin.h will create definitions/implementations for all available MSVC intrinsics.
   - Including various platforms sdk headers will only include the intrinsics defined in that
     header.  As of this writing, only winnt.h and winbase.h use this approach.
   - If an application defines its own prototypes for intrinsics (ie without including any
     platform header or intrin.h), the symbols will be resolved from the library.  Since this
     will likely result in the code being invoked via 'call', performance may be degraded.

   If you wish to implement intrinsic functions that are defined in intrin.h but are not
   yet implemented in mingw-w64, see the comments at the top of intrin-impl.h.
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
#define __MINGW_FORCE_SYS_INTRINS
#endif

#ifdef __x86_64__
#include <stdlib.h>
#include <errno.h>
/* Make sure _mm_malloc and _mm_free are defined.  */
#include <malloc.h>

__MINGW_BEGIN_C_DECLS

#ifndef _mm_malloc
# define _MM_MALLOC_H_INCLUDED
# define _mm_free(a)      _aligned_free(a)
# define _mm_malloc(a, b) _aligned_malloc(a, b)
#endif
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
#ifndef __MMX__
typedef union __m64 { char v[7]; } __m64;
#endif
#ifndef __SSE__
typedef union __m128 { char v[16]; } __m128;
#endif
#ifndef __SSE2__
typedef union __m128d { char v[16]; } __m128d;
typedef union __m128i { char v[16]; } __m128i;
#endif
#endif

#ifndef WINAPI
# define WINAPI __stdcall
#endif

#ifdef __x86_64__

#if defined(__MMX__) || defined(__MINGW_FORCE_SYS_INTRINS)
__MINGW_BEGIN_C_DECLS
#include <mmintrin.h>
__MINGW_END_C_DECLS
#endif

#if defined(__3dNOW__) || defined(__MINGW_FORCE_SYS_INTRINS)
__MINGW_BEGIN_C_DECLS
#include <mm3dnow.h>
__MINGW_END_C_DECLS
#endif

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

#ifndef __x86_64__
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

#ifndef __aarch64__
# undef  __MACHINEARM64
# undef  __MACHINEARM_ARM64
# define __MACHINEARM64     __MACHINEZ
# define __MACHINEARM_ARM64 __MACHINEZ
#endif

__MINGW_BEGIN_C_DECLS

 /* Put all declarations potentially colliding with POSIX headers here.
    So far, Cygwin is the only POSIX system using this header file.
    If that ever changes, make sure to tweak the guarding ifndef. */
    __MACHINE(int __cdecl abs(int))
    __MACHINEX64(double ceil(double))
    __MACHINE(long __cdecl labs(long))
    __MACHINE(int __cdecl memcmp(const void *,const void *,size_t))
    __MACHINE(void *__cdecl memcpy(void * __restrict__ ,const void * __restrict__ ,size_t))
    __MACHINE(void *__cdecl memset(void *,int,size_t))
    __MACHINE(char *__cdecl strcat(char *,const char *))
    __MACHINE(int __cdecl strcmp(const char *,const char *))
    __MACHINE(char *__cdecl strcpy(char * __restrict__ ,const char * __restrict__ ))
    __MACHINE(size_t __cdecl strlen(const char *))
    __MACHINEIW64(wchar_t *__cdecl wcscat(wchar_t * __restrict__ ,const wchar_t * __restrict__ ))
    __MACHINEIW64(int __cdecl wcscmp(const wchar_t *,const wchar_t *))
    __MACHINEIW64(wchar_t *__cdecl wcscpy(wchar_t * __restrict__ ,const wchar_t * __restrict__ ))
    __MACHINEIW64(size_t __cdecl wcslen(const wchar_t *))

#undef _alloca
#define _alloca(x) __builtin_alloca((x))
    __MACHINE(unsigned short __cdecl _byteswap_ushort(unsigned short value))
    __MACHINE(unsigned __LONG32 __cdecl _byteswap_ulong(unsigned __LONG32 value))
    __MACHINE(__MINGW_EXTENSION unsigned __int64 __cdecl _byteswap_uint64(unsigned __int64 value))
    __MACHINE(void __cdecl __debugbreak(void))
    __MACHINEI(void __cdecl _disable(void))
    __MACHINEI(__MINGW_EXTENSION __int64 __emul(int,int))
    __MACHINEI(__MINGW_EXTENSION unsigned __int64 __emulu(unsigned int,unsigned int))
    __MACHINEI(void __cdecl _enable(void))
    __MACHINE(void __cdecl __MINGW_ATTRIB_NORETURN __fastfail(unsigned int code))
    /* __MACHINEI(__LONG32 __cdecl _InterlockedDecrement(__LONG32 volatile *)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(__MINGW_EXTENSION __int64 _InterlockedDecrement64(__int64 volatile *)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(__LONG32 _InterlockedExchange(__LONG32 volatile *,__LONG32)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(__MINGW_EXTENSION __int64 _InterlockedExchange64(__int64 volatile *,__int64)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(void *_InterlockedExchangePointer(void *volatile *,void *)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(__LONG32 _InterlockedExchangeAdd(__LONG32 volatile *,__LONG32)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(__MINGW_EXTENSION __int64 _InterlockedExchangeAdd64(__int64 volatile *,__int64)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(__LONG32 _InterlockedCompareExchange (__LONG32 volatile *,__LONG32,__LONG32)) moved to psdk_inc/intrin-impl.h */
    __MACHINEX64(__MINGW_EXTENSION __int64 _InterlockedCompare64Exchange128(__int64 volatile *Destination,__int64 ExchangeHigh,__int64 ExchangeLow,__int64 Comparand))
    __MACHINEX64(__MINGW_EXTENSION __int64 _InterlockedCompare64Exchange128_acq(__int64 volatile *Destination,__int64 ExchangeHigh,__int64 ExchangeLow,__int64 Comparand))
    __MACHINEX64(__MINGW_EXTENSION __int64 _InterlockedCompare64Exchange128_rel(__int64 volatile *Destination,__int64 ExchangeHigh,__int64 ExchangeLow,__int64 Comparand))
    /* __MACHINEI(__MINGW_EXTENSION __int64 _InterlockedCompareExchange64(__int64 volatile *,__int64,__int64)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(void *_InterlockedCompareExchangePointer (void *volatile *,void *,void *)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(__LONG32 __cdecl _InterlockedIncrement(__LONG32 volatile *)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(__MINGW_EXTENSION __int64 _InterlockedIncrement64(__int64 volatile *)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEIW64(__LONG32 _InterlockedOr(__LONG32 volatile *,__LONG32)) moved to psdk_inc/intrin-impl.h */
    __MACHINEIW64(char _InterlockedOr8(char volatile *,char))
    __MACHINEIW64(short _InterlockedOr16(short volatile *,short))
    /* __MACHINEW64(__MINGW_EXTENSION __int64 _InterlockedOr64(__int64 volatile *,__int64)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEIW64(__LONG32 _InterlockedXor(__LONG32 volatile *,__LONG32)) moved to psdk_inc/intrin-impl.h */
    __MACHINEIW64(char _InterlockedXor8(char volatile *,char))
    __MACHINEIW64(short _InterlockedXor16(short volatile *,short))
    /* __MACHINEW64(__MINGW_EXTENSION __int64 _InterlockedXor64(__int64 volatile *,__int64)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEIW64(__LONG32 _InterlockedAnd(__LONG32 volatile *,__LONG32)) moved to psdk_inc/intrin-impl.h */
    __MACHINEIW64(char _InterlockedAnd8(char volatile *,char))
    __MACHINEIW64(short _InterlockedAnd16(short volatile *,short))
    /* __MACHINEW64(__MINGW_EXTENSION __int64 _InterlockedAnd64(__int64 volatile *,__int64)) moved to psdk_inc/intrin-impl.h */
    __MACHINEI(int __cdecl _inp(unsigned short))
    __MACHINEI(int __cdecl inp(unsigned short))
    __MACHINEI(unsigned __LONG32 __cdecl _inpd(unsigned short))
    __MACHINEI(unsigned __LONG32 __cdecl inpd(unsigned short))
    __MACHINEI(unsigned short __cdecl _inpw(unsigned short))
    __MACHINEI(unsigned short __cdecl inpw(unsigned short))
    __MACHINEZ(void __cdecl longjmp(jmp_buf,int))

    /* __MACHINE(unsigned long __cdecl _lrotl(unsigned long,int)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINE(unsigned long __cdecl _lrotr(unsigned long,int)) moved to psdk_inc/intrin-impl.h */

    __MACHINEI(__MINGW_EXTENSION unsigned __int64 __ll_lshift(unsigned __int64,int))
    __MACHINEI(__MINGW_EXTENSION __int64 __ll_rshift(__int64,int))
    __MACHINEI(int __cdecl _outp(unsigned short,int))
    __MACHINEI(int __cdecl outp(unsigned short,int))
    __MACHINEI(unsigned __LONG32 __cdecl _outpd(unsigned short,unsigned __LONG32))
    __MACHINEI(unsigned __LONG32 __cdecl outpd(unsigned short,unsigned __LONG32))
    __MACHINEI(unsigned short __cdecl _outpw(unsigned short,unsigned short))
    __MACHINEI(unsigned short __cdecl outpw(unsigned short,unsigned short))
    __MACHINEARM_ARM64(void __cdecl __prefetch(const void *addr))
    __MACHINEI(void *_ReturnAddress(void))
#pragma push_macro ("_rotl")
#undef _rotl
    __MACHINE(unsigned int __cdecl _rotl(unsigned int,int))
#pragma pop_macro ("_rotl")
#pragma push_macro ("_rotr")
#undef _rotr
    __MACHINE(unsigned int __cdecl _rotr(unsigned int,int))
#pragma pop_macro ("_rotr")
#undef _rotl64
#undef _rotr64
    __MACHINE(__MINGW_EXTENSION unsigned __int64 __cdecl _rotl64(unsigned __int64,int))
    __MACHINE(__MINGW_EXTENSION unsigned __int64 __cdecl _rotr64(unsigned __int64,int))
#define _rotl64 __rolq
#define _rotr64 __rorq
#ifndef USE_NO_MINGW_SETJMP_TWO_ARGS
    __MACHINE(int __cdecl __attribute__ ((__nothrow__,__returns_twice__)) _setjmp(jmp_buf,void *))
    __MACHINEX64(int __cdecl __attribute__ ((__nothrow__,__returns_twice__)) _setjmpex(jmp_buf,void *))
#else
    __MACHINE(int __cdecl __attribute__ ((__nothrow__,__returns_twice__)) _setjmp(jmp_buf))
    __MACHINEX64(int __cdecl __attribute__ ((__nothrow__,__returns_twice__)) _setjmpex(jmp_buf))
#endif
    __MACHINE(char *__cdecl _strset(char *,int))
    __MACHINE(char *__cdecl strset(char *,int))
    __MACHINEI(__MINGW_EXTENSION unsigned __int64 __ull_rshift(unsigned __int64,int))
    __MACHINEI(void *_AddressOfReturnAddress(void))

#if !defined(__SSE__) && !defined(__MINGW_FORCE_SYS_INTRINS)
    __MACHINEX86X_NOIA64(__m128 _mm_add_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_add_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_sub_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_sub_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_mul_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_mul_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_div_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_div_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_sqrt_ss(__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_sqrt_ps(__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_rcp_ss(__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_rcp_ps(__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_rsqrt_ss(__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_rsqrt_ps(__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_min_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_min_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_max_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_max_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_and_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_andnot_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_or_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_xor_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmpeq_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmpeq_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmplt_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmplt_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmple_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmple_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmpgt_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmpgt_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmpge_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmpge_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmpneq_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmpneq_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmpnlt_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmpnlt_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmpnle_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmpnle_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmpngt_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmpngt_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmpnge_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmpnge_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmpord_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmpord_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmpunord_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cmpunord_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(int _mm_comieq_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(int _mm_comilt_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(int _mm_comile_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(int _mm_comigt_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(int _mm_comige_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(int _mm_comineq_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(int _mm_ucomieq_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(int _mm_ucomilt_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(int _mm_ucomile_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(int _mm_ucomigt_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(int _mm_ucomige_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(int _mm_ucomineq_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(int _mm_cvt_ss2si(__m128))
    __MACHINEX86X_NOIA64(int _mm_cvtt_ss2si(__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_cvt_si2ss(__m128,int))
#pragma push_macro ("_mm_shuffle_ps")
#undef _mm_shuffle_ps
    __MACHINEX86X_NOIA64(__m128 _mm_shuffle_ps(__m128,__m128,int const))
#pragma pop_macro ("_mm_shuffle_ps")
    __MACHINEX86X_NOIA64(__m128 _mm_unpackhi_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_unpacklo_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_loadh_pi(__m128,__m64 const*))
    __MACHINEX86X_NOIA64(void _mm_storeh_pi(__m64*,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_loadl_pi(__m128,__m64 const*))
    __MACHINEX86X_NOIA64(void _mm_storel_pi(__m64*,__m128))
    __MACHINEX86X_NOIA64(int _mm_movemask_ps(__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_set_ss(float))
    __MACHINEX86X_NOIA64(__m128 _mm_set_ps1(float))
    __MACHINEX86X_NOIA64(__m128 _mm_set_ps(float,float,float,float))
    __MACHINEX86X_NOIA64(__m128 _mm_setr_ps(float,float,float,float))
    __MACHINEX86X_NOIA64(__m128 _mm_setzero_ps(void))
    __MACHINEX86X_NOIA64(__m128 _mm_load_ss(float const*))
    __MACHINEX86X_NOIA64(__m128 _mm_load_ps1(float const*))
    __MACHINEX86X_NOIA64(__m128 _mm_load_ps(float const*))
    __MACHINEX86X_NOIA64(__m128 _mm_loadr_ps(float const*))
    __MACHINEX86X_NOIA64(__m128 _mm_loadu_ps(float const*))
    __MACHINEX86X_NOIA64(__m128 _mm_move_ss(__m128,__m128))
    __MACHINEX86X_NOIA64(void _mm_store_ss(float*,__m128))
    __MACHINEX86X_NOIA64(void _mm_store_ps1(float*,__m128))
    __MACHINEX86X_NOIA64(void _mm_store_ps(float*,__m128))
    __MACHINEX86X_NOIA64(void _mm_storer_ps(float*,__m128))
    __MACHINEX86X_NOIA64(void _mm_storeu_ps(float*,__m128))
/*    __MACHINEX86X_NOIA64(void _mm_prefetch(char const*,int)) */
    __MACHINEX86X_NOIA64(void _mm_stream_ps(float*,__m128))
    __MACHINEX86X_NOIA64(void _mm_sfence(void))
    __MACHINEX86X_NOIA64(unsigned int _mm_getcsr(void))
    __MACHINEX86X_NOIA64(void _mm_setcsr(unsigned int))
    __MACHINEX86X_NOIA64(__m128 _mm_movelh_ps(__m128,__m128))
    __MACHINEX86X_NOIA64(__m128 _mm_movehl_ps(__m128,__m128))
#endif
#if !defined(__3dNOW__) && !defined(__MINGW_FORCE_SYS_INTRINS)
    __MACHINEX86X_NOIA64(void _m_prefetch(void*))
    __MACHINEX86X_NOIA64(void _m_prefetchw(void*_Source))
#endif
#if !defined(__SSE2__) && !defined(__MINGW_FORCE_SYS_INTRINS)
    __MACHINEX86X(__m128d _mm_add_sd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_add_pd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_div_sd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_div_pd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_max_sd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_max_pd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_min_sd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_min_pd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_mul_sd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_mul_pd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_sqrt_sd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_sqrt_pd(__m128d))
    __MACHINEX86X(__m128d _mm_sub_sd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_sub_pd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_and_pd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_andnot_pd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_or_pd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_xor_pd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmpeq_sd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmpeq_pd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmplt_sd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmplt_pd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmple_sd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmple_pd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmpgt_sd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmpgt_pd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmpge_sd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmpge_pd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmpneq_sd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmpneq_pd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmpnlt_sd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmpnlt_pd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmpnle_sd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmpnle_pd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmpngt_sd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmpngt_pd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmpnge_sd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmpnge_pd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmpord_sd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmpord_pd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmpunord_sd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_cmpunord_pd(__m128d,__m128d))
    __MACHINEX86X(int _mm_comieq_sd(__m128d,__m128d))
    __MACHINEX86X(int _mm_comilt_sd(__m128d,__m128d))
    __MACHINEX86X(int _mm_comile_sd(__m128d,__m128d))
    __MACHINEX86X(int _mm_comigt_sd(__m128d,__m128d))
    __MACHINEX86X(int _mm_comige_sd(__m128d,__m128d))
    __MACHINEX86X(int _mm_comineq_sd(__m128d,__m128d))
    __MACHINEX86X(int _mm_ucomieq_sd(__m128d,__m128d))
    __MACHINEX86X(int _mm_ucomilt_sd(__m128d,__m128d))
    __MACHINEX86X(int _mm_ucomile_sd(__m128d,__m128d))
    __MACHINEX86X(int _mm_ucomigt_sd(__m128d,__m128d))
    __MACHINEX86X(int _mm_ucomige_sd(__m128d,__m128d))
    __MACHINEX86X(int _mm_ucomineq_sd(__m128d,__m128d))
    __MACHINEX86X(__m128 _mm_cvtpd_ps(__m128d))
    __MACHINEX86X(__m128d _mm_cvtps_pd(__m128))
    __MACHINEX86X(__m128d _mm_cvtepi32_pd(__m128i))
    __MACHINEX86X(__m128i _mm_cvtpd_epi32(__m128d))
    __MACHINEX86X(int _mm_cvtsd_si32(__m128d))
    __MACHINEX86X(__m128 _mm_cvtsd_ss(__m128,__m128d))
    __MACHINEX86X(__m128d _mm_cvtsi32_sd(__m128d,int))
    __MACHINEX86X(__m128d _mm_cvtss_sd(__m128d,__m128))
    __MACHINEX86X(__m128i _mm_cvttpd_epi32(__m128d))
    __MACHINEX86X(int _mm_cvttsd_si32(__m128d))
    __MACHINEX86X(__m128 _mm_cvtepi32_ps(__m128i))
    __MACHINEX86X(__m128i _mm_cvtps_epi32(__m128))
    __MACHINEX86X(__m128i _mm_cvttps_epi32(__m128))
    __MACHINEX86X(__m128d _mm_unpackhi_pd(__m128d,__m128d))
    __MACHINEX86X(__m128d _mm_unpacklo_pd(__m128d,__m128d))
    __MACHINEX86X(int _mm_movemask_pd(__m128d))
    /*  __MACHINEX86X(__m128d _mm_shuffle_pd(__m128d,__m128d,int)) */
    __MACHINEX86X(__m128d _mm_load_pd(double const*))
    __MACHINEX86X(__m128d _mm_load1_pd(double const*))
    __MACHINEX86X(__m128d _mm_loadr_pd(double const*))
    __MACHINEX86X(__m128d _mm_loadu_pd(double const*))
    __MACHINEX86X(__m128d _mm_load_sd(double const*))
    __MACHINEX86X(__m128d _mm_loadh_pd(__m128d,double const*))
    __MACHINEX86X(__m128d _mm_loadl_pd(__m128d,double const*))
    __MACHINEX86X(__m128d _mm_set_sd(double))
    __MACHINEX86X(__m128d _mm_set1_pd(double))
    __MACHINEX86X(__m128d _mm_set_pd(double,double))
    __MACHINEX86X(__m128d _mm_setr_pd(double,double))
    __MACHINEX86X(__m128d _mm_setzero_pd(void))
    __MACHINEX86X(__m128d _mm_move_sd(__m128d,__m128d))
    __MACHINEX86X(void _mm_store_sd(double*,__m128d))
    __MACHINEX86X(void _mm_store1_pd(double*,__m128d))
    __MACHINEX86X(void _mm_store_pd(double*,__m128d))
    __MACHINEX86X(void _mm_storeu_pd(double*,__m128d))
    __MACHINEX86X(void _mm_storer_pd(double*,__m128d))
    __MACHINEX86X(void _mm_storeh_pd(double*,__m128d))
    __MACHINEX86X(void _mm_storel_pd(double*,__m128d))
    __MACHINEX86X(__m128i _mm_add_epi8(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_add_epi16(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_add_epi32(__m128i,__m128i))
#endif

#if !defined(__SSE2__) && !defined(__MINGW_FORCE_SYS_INTRINS)
    __MACHINEX86X(__m128i _mm_add_epi64(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_adds_epi8(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_adds_epi16(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_adds_epu8(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_adds_epu16(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_avg_epu8(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_avg_epu16(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_madd_epi16(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_max_epi16(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_max_epu8(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_min_epi16(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_min_epu8(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_mulhi_epi16(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_mulhi_epu16(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_mullo_epi16(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_mul_epu32(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_sad_epu8(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_sub_epi8(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_sub_epi16(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_sub_epi32(__m128i,__m128i))
#endif
#if !defined(__SSE2__) && !defined(__MINGW_FORCE_SYS_INTRINS)
    __MACHINEX86X(__m128i _mm_sub_epi64(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_subs_epi8(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_subs_epi16(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_subs_epu8(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_subs_epu16(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_andnot_si128(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_and_si128(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_or_si128(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_xor_si128(__m128i,__m128i))
    /*  __MACHINEX86X(__m128i _mm_slli_si128(__m128i,int)) */
/*    __MACHINEX86X(__m128i _mm_slli_epi16(__m128i,int)) */
    __MACHINEX86X(__m128i _mm_sll_epi16(__m128i,__m128i))
/*    __MACHINEX86X(__m128i _mm_slli_epi32(__m128i,int)) */
    __MACHINEX86X(__m128i _mm_sll_epi32(__m128i,__m128i))
/*    __MACHINEX86X(__m128i _mm_slli_epi64(__m128i,int)) */
    __MACHINEX86X(__m128i _mm_sll_epi64(__m128i,__m128i))
/*    __MACHINEX86X(__m128i _mm_srai_epi16(__m128i,int)) */
    __MACHINEX86X(__m128i _mm_sra_epi16(__m128i,__m128i))
/*    __MACHINEX86X(__m128i _mm_srai_epi32(__m128i,int)) */
    __MACHINEX86X(__m128i _mm_sra_epi32(__m128i,__m128i))
    /*  __MACHINEX86X(__m128i _mm_srli_si128(__m128i,int)) */
/*    __MACHINEX86X(__m128i _mm_srli_epi16(__m128i,int)) */
    __MACHINEX86X(__m128i _mm_srl_epi16(__m128i,__m128i))
/*    __MACHINEX86X(__m128i _mm_srli_epi32(__m128i,int)) */
    __MACHINEX86X(__m128i _mm_srl_epi32(__m128i,__m128i))
/*    __MACHINEX86X(__m128i _mm_srli_epi64(__m128i,int)) */
    __MACHINEX86X(__m128i _mm_srl_epi64(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_cmpeq_epi8(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_cmpeq_epi16(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_cmpeq_epi32(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_cmpgt_epi8(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_cmpgt_epi16(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_cmpgt_epi32(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_cmplt_epi8(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_cmplt_epi16(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_cmplt_epi32(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_cvtsi32_si128(int))
    __MACHINEX86X(int _mm_cvtsi128_si32(__m128i))
    __MACHINEX86X(__m128i _mm_packs_epi16(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_packs_epi32(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_packus_epi16(__m128i,__m128i))
    /*  __MACHINEX86X(int _mm_extract_epi16(__m128i,int)) */
    /*  __MACHINEX86X(__m128i _mm_insert_epi16(__m128i,int,int)) */
    __MACHINEX86X(int _mm_movemask_epi8(__m128i))
    /*  __MACHINEX86X(__m128i _mm_shuffle_epi32(__m128i,int)) */
    /*  __MACHINEX86X(__m128i _mm_shufflehi_epi16(__m128i,int)) */
    /*  __MACHINEX86X(__m128i _mm_shufflelo_epi16(__m128i,int)) */
    __MACHINEX86X(__m128i _mm_unpackhi_epi8(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_unpackhi_epi16(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_unpackhi_epi32(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_unpackhi_epi64(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_unpacklo_epi8(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_unpacklo_epi16(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_unpacklo_epi32(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_unpacklo_epi64(__m128i,__m128i))
    __MACHINEX86X(__m128i _mm_load_si128(__m128i const*))
    __MACHINEX86X(__m128i _mm_loadu_si128(__m128i const*))
    __MACHINEX86X(__m128i _mm_loadl_epi64(__m128i const*))
    __MACHINEX86X(__m128i _mm_set_epi32(int,int,int,int))
    __MACHINEX86X(__m128i _mm_set_epi16(short,short,short,short,short,short,short,short))
    __MACHINEX86X(__m128i _mm_set_epi8(char,char,char,char,char,char,char,char,char,char,char,char,char,char,char,char))
    __MACHINEX86X(__m128i _mm_set1_epi32(int))
    __MACHINEX86X(__m128i _mm_set1_epi16(short))
    __MACHINEX86X(__m128i _mm_set1_epi8(char))
    __MACHINEX86X(__m128i _mm_setl_epi64(__m128i))
    __MACHINEX86X(__m128i _mm_setr_epi32(int,int,int,int))
    __MACHINEX86X(__m128i _mm_setr_epi16(short,short,short,short,short,short,short,short))
    __MACHINEX86X(__m128i _mm_setr_epi8(char,char,char,char,char,char,char,char,char,char,char,char,char,char,char,char))
    __MACHINEX86X(__m128i _mm_setzero_si128(void))
    __MACHINEX86X(void _mm_store_si128(__m128i*,__m128i))
    __MACHINEX86X(void _mm_storeu_si128(__m128i*,__m128i))
    __MACHINEX86X(void _mm_storel_epi64(__m128i*,__m128i))
    __MACHINEX86X(void _mm_maskmoveu_si128(__m128i,__m128i,char*))
    __MACHINEX86X(__m128i _mm_move_epi64(__m128i))
    __MACHINEX86X(void _mm_stream_pd(double*,__m128d))
    __MACHINEX86X(void _mm_stream_si128(__m128i*,__m128i))
    __MACHINEX86X(void _mm_clflush(void const *))
    __MACHINEX86X(void _mm_lfence(void))
    __MACHINEX86X(void _mm_mfence(void))
    __MACHINEX86X(void _mm_stream_si32(int*,int))
#endif
#if !defined(__SSE__) && !defined(__MINGW_FORCE_SYS_INTRINS)
    __MACHINEX86X(void _mm_pause(void))
#endif
#if !defined(__SSE3__) && !defined(__MINGW_FORCE_SYS_INTRINS)
    __MACHINEX86X(__m128 _mm_addsub_ps(__m128,__m128))
    __MACHINEX86X(__m128d _mm_addsub_pd(__m128d,__m128d))
    __MACHINEX86X(__m128 _mm_hadd_ps(__m128,__m128))
    __MACHINEX86X(__m128d _mm_hadd_pd(__m128d,__m128d))
    __MACHINEX86X(__m128 _mm_hsub_ps(__m128,__m128))
    __MACHINEX86X(__m128d _mm_hsub_pd(__m128d,__m128d))
    __MACHINEX86X(__m128i _mm_lddqu_si128(__m128i const*))
    __MACHINEX86X(void _mm_monitor(void const*,unsigned int,unsigned int))
    __MACHINEX86X(__m128d _mm_movedup_pd(__m128d))
    __MACHINEX86X(__m128d _mm_loaddup_pd(double const*))
    __MACHINEX86X(__m128 _mm_movehdup_ps(__m128))
    __MACHINEX86X(__m128 _mm_moveldup_ps(__m128))
    __MACHINEX86X(void _mm_mwait(unsigned int,unsigned int))
#endif
    /* __MACHINEI(void _WriteBarrier(void)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(void _ReadWriteBarrier(void)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(void __faststorefence(void)) moved to psdk_inc/intrin-impl.h */
    __MACHINEX64(__MINGW_EXTENSION __int64 __mulh(__int64,__int64))
    __MACHINEX64(__MINGW_EXTENSION unsigned __int64 __umulh(unsigned __int64,unsigned __int64))
    /* __MACHINEX64(__MINGW_EXTENSION unsigned __int64 __readcr0(void)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(__MINGW_EXTENSION unsigned __int64 __readcr2(void)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(__MINGW_EXTENSION unsigned __int64 __readcr3(void)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(__MINGW_EXTENSION unsigned __int64 __readcr4(void)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(__MINGW_EXTENSION unsigned __int64 __readcr8(void)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(__MINGW_EXTENSION void __writecr0(unsigned __int64)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(__MINGW_EXTENSION void __writecr3(unsigned __int64)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(__MINGW_EXTENSION void __writecr4(unsigned __int64)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(__MINGW_EXTENSION void __writecr8(unsigned __int64)) moved to psdk_inc/intrin-impl.h */
    __MACHINEI(void __wbinvd(void))
    __MACHINEI(void __invlpg(void*))
    /* __MACHINEI(__MINGW_EXTENSION unsigned __int64 __readmsr(unsigned __LONG32)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(__MINGW_EXTENSION void __writemsr(unsigned __LONG32,unsigned __int64)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(void __movsb(unsigned char *,unsigned char const *,size_t)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(void __movsw(unsigned short *,unsigned short const *,size_t)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(void __movsd(unsigned __LONG32 *,unsigned __LONG32 const *,size_t)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(__MINGW_EXTENSION void __movsq(unsigned long long *,unsigned long long const *,size_t)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(unsigned char __readgsbyte(unsigned __LONG32 Offset)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(unsigned short __readgsword(unsigned __LONG32 Offset)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(unsigned __LONG32 __readgsdword(unsigned __LONG32 Offset)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(__MINGW_EXTENSION unsigned __int64 __readgsqword(unsigned __LONG32 Offset)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(void __writegsbyte(unsigned __LONG32 Offset,unsigned char Data)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(void __writegsword(unsigned __LONG32 Offset,unsigned short Data)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(void __writegsdword(unsigned __LONG32 Offset,unsigned __LONG32 Data)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(__MINGW_EXTENSION void __writegsqword(unsigned __LONG32 Offset,unsigned __int64 Data)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(unsigned char __inbyte(unsigned short Port)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(unsigned short __inword(unsigned short Port)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(unsigned __LONG32 __indword(unsigned short Port)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(void __outbyte(unsigned short Port,unsigned char Data)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(void __outword(unsigned short Port,unsigned short Data)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(void __outdword(unsigned short Port,unsigned __LONG32 Data)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(void __inbytestring(unsigned short Port,unsigned char *Buffer,unsigned __LONG32 Count)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(void __inwordstring(unsigned short Port,unsigned short *Buffer,unsigned __LONG32 Count)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(void __indwordstring(unsigned short Port,unsigned __LONG32 *Buffer,unsigned __LONG32 Count)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(void __outbytestring(unsigned short Port,unsigned char *Buffer,unsigned __LONG32 Count)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(void __outwordstring(unsigned short Port,unsigned short *Buffer,unsigned __LONG32 Count)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(void __outdwordstring(unsigned short Port,unsigned __LONG32 *Buffer,unsigned __LONG32 Count)) moved to psdk_inc/intrin-impl.h */
    __MACHINEI(unsigned int __getcallerseflags())
#if !defined(__SSE2__) && !defined(__MINGW_FORCE_SYS_INTRINS)
    __MACHINEX64(__MINGW_EXTENSION __m128i _mm_set_epi64x(__int64 i1,__int64 i0))
    __MACHINEX64(__MINGW_EXTENSION __m128i _mm_set1_epi64x(__int64 i))
    __MACHINEX64(__MINGW_EXTENSION __int64 _mm_cvtsd_si64x(__m128d a))
    __MACHINEX64(__MINGW_EXTENSION __m128d _mm_cvtsi64x_sd(__m128d a,__int64 b))
    __MACHINEX64(__MINGW_EXTENSION __m128 _mm_cvtsi64x_ss(__m128 a,__int64 b))
    __MACHINEX64(__MINGW_EXTENSION __int64 _mm_cvtss_si64x(__m128 a))
    __MACHINEX64(__MINGW_EXTENSION __int64 _mm_cvttsd_si64x(__m128d a))
    __MACHINEX64(__MINGW_EXTENSION __int64 _mm_cvttss_si64x(__m128 a))
    __MACHINEX64(__MINGW_EXTENSION __m128i _mm_cvtsi64x_si128(__int64 a))
    __MACHINEX64(__MINGW_EXTENSION __int64 _mm_cvtsi128_si64x(__m128i a))
#endif
    __MACHINEX64(__MINGW_EXTENSION void _mm_stream_si64x(__int64 *,__int64))
    /* __MACHINEI(void __stosb(unsigned char *,unsigned char,size_t)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(void __stosw(unsigned short *,unsigned short,size_t)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(void __stosd(unsigned __LONG32 *,unsigned __LONG32,size_t)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(__MINGW_EXTENSION void __stosq(unsigned __int64 *,unsigned __int64,size_t)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEIW64(unsigned char _bittest(__LONG32 const *a,__LONG32 b)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEIW64(unsigned char _bittestandset(__LONG32 *a,__LONG32 b)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEIW64(unsigned char _bittestandreset(__LONG32 *a,__LONG32 b)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEIW64(unsigned char _bittestandcomplement(__LONG32 *a,__LONG32 b)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(unsigned char InterlockedBitTestAndSet(volatile __LONG32 *a,__LONG32 b)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(unsigned char InterlockedBitTestAndReset(volatile __LONG32 *a,__LONG32 b)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(unsigned char InterlockedBitTestAndComplement(volatile __LONG32 *a,__LONG32 b)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(unsigned char _interlockedbittestandset(__LONG32 *a,__LONG32 b)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(unsigned char _interlockedbittestandreset(__LONG32 *a,__LONG32 b)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(unsigned char _interlockedbittestandcomplement(__LONG32 *a,__LONG32 b)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEW64(__MINGW_EXTENSION unsigned char _bittest64(__int64 const *a,__int64 b)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEW64(__MINGW_EXTENSION unsigned char _bittestandset64(__int64 *a,__int64 b)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEW64(__MINGW_EXTENSION unsigned char _bittestandreset64(__int64 *a,__int64 b)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEW64(__MINGW_EXTENSION unsigned char _bittestandcomplement64(__int64 *a,__int64 b)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(__MINGW_EXTENSION unsigned char InterlockedBitTestAndSet64(volatile __int64 *a,__int64 b)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(__MINGW_EXTENSION unsigned char InterlockedBitTestAndReset64(volatile __int64 *a,__int64 b)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(__MINGW_EXTENSION unsigned char InterlockedBitTestAndComplement64(volatile __int64 *a,__int64 b)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(__MINGW_EXTENSION unsigned char _interlockedbittestandset64(__int64 *a,__int64 b)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(__MINGW_EXTENSION unsigned char _interlockedbittestandreset64(__int64 *a,__int64 b)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEX64(__MINGW_EXTENSION unsigned char _interlockedbittestandcomplement64(__int64 *a,__int64 b)) moved to psdk_inc/intrin-impl.h */
    __MACHINEI(void __cpuid(int a[4],int b))
    __MACHINEI(__MINGW_EXTENSION unsigned __int64 __readpmc(unsigned __LONG32 a))
    __MACHINEI(unsigned __LONG32 __segmentlimit(unsigned __LONG32 a))

    __MACHINE(__MINGW_EXTENSION __int64 __cdecl _abs64(__int64))

    /* __MACHINEIW64(unsigned char _BitScanForward(unsigned __LONG32 *Index,unsigned __LONG32 Mask)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEIW64(unsigned char _BitScanReverse(unsigned __LONG32 *Index,unsigned __LONG32 Mask)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEW64(__MINGW_EXTENSION unsigned char _BitScanForward64(unsigned __LONG32 *Index,unsigned __int64 Mask)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEW64(__MINGW_EXTENSION unsigned char _BitScanReverse64(unsigned __LONG32 *Index,unsigned __int64 Mask)) moved to psdk_inc/intrin-impl.h */
    __MACHINEIW64(_CRTIMP wchar_t *__cdecl _wcsset(wchar_t *,wchar_t))
    /* __MACHINEW64(__MINGW_EXTENSION unsigned __int64 __shiftleft128(unsigned __int64 LowPart,unsigned __int64 HighPart,unsigned char Shift)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEW64(__MINGW_EXTENSION unsigned __int64 __shiftright128(unsigned __int64 LowPart,unsigned __int64 HighPart,unsigned char Shift)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEW64(__MINGW_EXTENSION unsigned __int64 _umul128(unsigned __int64 multiplier,unsigned __int64 multiplicand,unsigned __int64 *highproduct)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEW64(__MINGW_EXTENSION __int64 _mul128(__int64 multiplier,__int64 multiplicand,__int64 *highproduct)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEI(void __int2c(void)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEIW64(void _ReadBarrier(void)) moved to psdk_inc/intrin-impl.h */
    __MACHINEIW64(unsigned char _rotr8(unsigned char value,unsigned char shift))
    __MACHINEIW64(unsigned short _rotr16(unsigned short value,unsigned char shift))
    __MACHINEIW64(unsigned char _rotl8(unsigned char value,unsigned char shift))
    __MACHINEIW64(unsigned short _rotl16(unsigned short value,unsigned char shift))
    /* __MACHINEIW64(short _InterlockedIncrement16(short volatile *Addend)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEIW64(short _InterlockedDecrement16(short volatile *Addend)) moved to psdk_inc/intrin-impl.h */
    /* __MACHINEIW64(short _InterlockedCompareExchange16(short volatile *Destination,short Exchange,short Comparand)) moved to psdk_inc/intrin-impl.h */
    __MACHINEIW64(void __nvreg_save_fence(void))
    __MACHINEIW64(void __nvreg_restore_fence(void))

    __MACHINEX64(short _InterlockedCompareExchange16_np(short volatile *Destination,short Exchange,short Comparand))
    __MACHINEX64(__LONG32 _InterlockedCompareExchange_np (__LONG32 *,__LONG32,__LONG32))
    __MACHINEX64(__MINGW_EXTENSION __int64 _InterlockedCompareExchange64_np(__int64 *,__int64,__int64))
    __MACHINEX64(void *_InterlockedCompareExchangePointer_np (void **,void *,void *))
    __MACHINEX64(__MINGW_EXTENSION __int64 _InterlockedCompare64Exchange128_np(__int64 *Destination,__int64 ExchangeHigh,__int64 ExchangeLow,__int64 Comparand))
    __MACHINEX64(__MINGW_EXTENSION __int64 _InterlockedCompare64Exchange128_acq_np(__int64 *Destination,__int64 ExchangeHigh,__int64 ExchangeLow,__int64 Comparand))
    __MACHINEX64(__MINGW_EXTENSION __int64 _InterlockedCompare64Exchange128_rel_np(__int64 *Destination,__int64 ExchangeHigh,__int64 ExchangeLow,__int64 Comparand))
    __MACHINEX64(__LONG32 _InterlockedAnd_np(__LONG32 *,__LONG32))
    __MACHINEX64(char _InterlockedAnd8_np(char *,char))
    __MACHINEX64(short _InterlockedAnd16_np(short *,short))
    __MACHINEX64(__MINGW_EXTENSION __int64 _InterlockedAnd64_np(__int64 *,__int64))
    __MACHINEX64(__LONG32 _InterlockedOr_np(__LONG32 *,__LONG32))
    __MACHINEX64(char _InterlockedOr8_np(char *,char))
    __MACHINEX64(short _InterlockedOr16_np(short *,short))
    __MACHINEX64(__MINGW_EXTENSION __int64 _InterlockedOr64_np(__int64 *,__int64))
    __MACHINEX64(__LONG32 _InterlockedXor_np(__LONG32 *,__LONG32))
    __MACHINEX64(char _InterlockedXor8_np(char *,char))
    __MACHINEX64(short _InterlockedXor16_np(short *,short))
    __MACHINEX64(__MINGW_EXTENSION __int64 _InterlockedXor64_np(__int64 *,__int64))

#if defined(_NO_PREFETCHW)
#ifdef __x86_64__

#define _InterlockedCompareExchange16 _InterlockedCompareExchange16_np
#define _InterlockedCompareExchange _InterlockedCompareExchange_np
#define _InterlockedCompareExchange64 _InterlockedCompareExchange64_np
#define _InterlockedCompareExchangePointer _InterlockedCompareExchangePointer_np
#define _InterlockedCompare64Exchange128 _InterlockedCompare64Exchange128_np
#define _InterlockedCompare64Exchange128_acq _InterlockedCompare64Exchange128_acq_np
#define _InterlockedCompare64Exchange128_rel _InterlockedCompare64Exchange128_rel_np
#define _InterlockedAnd _InterlockedAnd_np
#define _InterlockedAnd8 _InterlockedAnd8_np
#define _InterlockedAnd16 _InterlockedAnd16_np
#define _InterlockedAnd64 _InterlockedAnd64_np
#define _InterlockedOr _InterlockedOr_np
#define _InterlockedOr8 _InterlockedOr8_np
#define _InterlockedOr16 _InterlockedOr16_np
#define _InterlockedOr64 _InterlockedOr64_np
#define _InterlockedXor _InterlockedXor_np
#define _InterlockedXor8 _InterlockedXor8_np
#define _InterlockedXor16 _InterlockedXor16_np
#define _InterlockedXor64 _InterlockedXor64_np
#endif
#endif

__MINGW_END_C_DECLS

#endif  /* __INTRIN_H_ */
