/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _SSP_INC_MEMORY
#define _SSP_INC_MEMORY

#include <ssp/ssp.h>

__MINGW_BEGIN_C_DECLS

#if __MINGW_FORTIFY_LEVEL > 0

  __mingw_bos_extern_ovr __NONNULL((1, 2))
  __NTH_FNC(void *memcpy(void *__restrict _Dst, const void *__restrict _Src, size_t _Size))
  {
    return __builtin___memcpy_chk(_Dst, _Src, _Size, __mingw_bos(_Dst, 0));
  }

#ifdef __MINGW_USE_SECAPI
  _CRTIMP errno_t __cdecl __mingw_call_memcpy_s(void *_Dst, size_t _DstSize, const void *_Src, size_t _SrcSize) __ASM_CRT_CALL(memcpy_s);

  __mingw_bos_extern_ovr
  errno_t memcpy_s(void *_Dst, size_t _DstSize, const void *_Src, size_t _SrcSize)
  {
    __mingw_bos_ptr_chk_warn(_Dst, _DstSize, 0);
    return __mingw_call_memcpy_s(_Dst, _DstSize, _Src, _SrcSize);
  }
#endif

  __mingw_bos_extern_ovr __NONNULL((1, 2))
  __NTH_FNC(void *memmove(void *_Dst, const void *_Src, size_t _Size))
  {
    return __builtin___memmove_chk(_Dst, _Src, _Size, __mingw_bos(_Dst, 0));
  }

  __mingw_bos_extern_ovr __NONNULL((1))
  __NTH_FNC(void *memset(void *_Dst, int _Val, size_t _Size))
  {
    return __builtin___memset_chk(_Dst, _Val, _Size, __mingw_bos(_Dst, 0));
  }

#endif  /* __MINGW_FORTIFY_LEVEL > 0 */

__MINGW_END_C_DECLS

#endif  /* _SSP_INC_MEMORY */
