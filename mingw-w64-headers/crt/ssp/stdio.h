/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _SSP_INC_STDIO
#define _SSP_INC_STDIO

#include <ssp/ssp.h>

__MINGW_BEGIN_C_DECLS

#if __MINGW_FORTIFY_LEVEL > 0

  int __cdecl __mingw_call_vsprintf(char *__restrict _Buffer, const char *__restrict _Format, va_list _ArgList)                       __ASM_CALL(vsprintf);
  int __cdecl __mingw_call_vsnprintf(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, va_list _ArgList) __ASM_CALL(vsnprintf);

  __mingw_bos_extern_ovr
  __MINGW_GNU_PRINTF(2, 0) __NONNULL((3))
  __NTH_FNC(int vsprintf(char *__restrict _Buffer, const char *__restrict _Format, va_list _ArgList))
  {
    if(__mingw_bos_known(_Buffer))
    {
      int _Ret = __mingw_call_vsnprintf(_Buffer, __mingw_bos(_Buffer, 1), _Format, _ArgList);
      if(_Ret >= 0)
      {
        __mingw_bos_ptr_chk(_Buffer, (size_t)_Ret + 1, 1);
      }
      return _Ret;
    }
    return __mingw_call_vsprintf(_Buffer, _Format, _ArgList);
  }

#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)

  __mingw_bos_extern_ovr
  __MINGW_GNU_PRINTF(3, 0) __NONNULL((3))
  __NTH_FNC(int vsnprintf(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, va_list _ArgList))
  {
    __mingw_bos_ptr_chk_warn(_Buffer, _BufferCount, 1);
    return __mingw_call_vsnprintf(_Buffer, _BufferCount, _Format, _ArgList);
  }

#endif  /* defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX) */

#if __MINGW_FORTIFY_VA_ARG

  int __cdecl __mingw_call_sprintf(char *__restrict _Buffer, const char *__restrict __Format, ...)                      __ASM_CALL(sprintf);
  int __cdecl __mingw_call_snprintf(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, ...) __ASM_CALL(snprintf);

  __mingw_bos_extern_ovr
  __MINGW_GNU_PRINTF(2, 3) __NONNULL((2))
  __NTH_FNC(int sprintf(char *__restrict _Buffer, const char *__restrict _Format, ...))
  {
    if(__mingw_bos_known(_Buffer))
    {
      int _Ret = __mingw_call_snprintf(_Buffer, __mingw_bos(_Buffer, 1), _Format, __va_arg_pack());
      if(_Ret >= 0)
      {
        __mingw_bos_ptr_chk(_Buffer, (size_t)_Ret + 1, 1);
      }
      return _Ret;
    }
    return __mingw_call_sprintf(_Buffer, _Format, __va_arg_pack());
  }

#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX)

  __mingw_bos_extern_ovr
  __MINGW_GNU_PRINTF(3, 4) __NONNULL((3))
  __NTH_FNC(int snprintf(char *__restrict _Buffer, size_t _BufferCount, const char *__restrict _Format, ...))
  {
    __mingw_bos_ptr_chk_warn(_Buffer, _BufferCount, 1);
    return __mingw_call_snprintf(_Buffer, _BufferCount, _Format, __va_arg_pack());
  }

#endif  /* defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_UNIX98) || defined(__MINGW_USE_C99FORGXX) */

#endif  /* __MINGW_FORTIFY_VA_ARG */

#ifdef __MINGW_USE_DEPRECATED_GETS
  char *__cdecl __gets_chk(char *_Buffer, size_t _Size) __WUR_FORTIFY;
  char *__cdecl __mingw_call_gets_warn(char *_Buffer) __ASM_CRT_CALL(gets) __WUR_FORTIFY
    __ATTR_WARN("Using gets() is always unsafe - use fgets() instead");

  __mingw_bos_extern_ovr __WUR_FORTIFY
  char * gets(char *_Buffer)
  {
    if(__mingw_bos_known(_Buffer))
    {
      return __gets_chk(_Buffer, __mingw_bos(_Buffer, 1));
    }
    return __mingw_call_gets_warn(_Buffer);
  }
#endif

  _CRTIMP char  *__cdecl __mingw_call_fgets(char *__restrict _Buf, int _MaxCount, FILE *__restrict _File)                         __ASM_CRT_CALL(fgets)      __WUR_FORTIFY;
  _CRTIMP size_t __cdecl __mingw_call_fread(void *__restrict _DstBuf, size_t _ElementSize, size_t _Count, FILE *__restrict _File) __ASM_CRT_CALL(fread)      __WUR_FORTIFY;
  _CRTIMP char  *__cdecl __mingw_call_tmpnam(char *_Buffer)                                                                       __ASM_CRT_CALL_NTH(tmpnam) __WUR_FORTIFY;

  __mingw_bos_extern_ovr __WUR_FORTIFY __NONNULL((3))
  char *fgets(char *__restrict _Buf, int _MaxCount, FILE * __restrict _File)
  {
    __mingw_bos_ptr_chk_warn(_Buf, _MaxCount, 1);
    return __mingw_call_fgets(_Buf, _MaxCount, _File);
  }

  __mingw_bos_extern_ovr __WUR_FORTIFY __NONNULL((4))
  size_t fread(void *__restrict _DstBuf, size_t _ElementSize, size_t _Count, FILE *__restrict _File)
  {
    __mingw_bos_ptr_chk_warn(_DstBuf, _ElementSize * _Count, 0);
    return __mingw_call_fread(_DstBuf, _ElementSize, _Count, _File);
  }

  __mingw_bos_extern_ovr __WUR_FORTIFY
  __NTH_FNC(char *tmpnam(char *_Buffer))
  {
    __mingw_bos_ptr_chk_warn(_Buffer, L_tmpnam, 1);
    return __mingw_call_tmpnam(_Buffer);
  }

#endif  /* __MINGW_FORTIFY_LEVEL > 0 */

__MINGW_END_C_DECLS

#endif  /* _SSP_INC_STDIO */
