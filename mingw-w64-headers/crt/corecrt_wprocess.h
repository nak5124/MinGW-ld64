/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CORECRT_WPROCESS
#define _INC_CORECRT_WPROCESS

#include <corecrt.h>

#pragma pack(push, _CRT_PACKING)

__MINGW_BEGIN_C_DECLS

#ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP

  _CRTIMP intptr_t __cdecl _wexecl(const wchar_t *_Filename, const wchar_t *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _wexecle(const wchar_t *_Filename, const wchar_t *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _wexeclp(const wchar_t *_Filename, const wchar_t *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _wexeclpe(const wchar_t *_Filename, const wchar_t *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _wexecv(const wchar_t *_Filename, const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(const wchar_t *_Filename, const wchar_t *const *_ArgList, const wchar_t *const *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(const wchar_t *_Filename, const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(const wchar_t *_Filename, const wchar_t *const *_ArgList, const wchar_t *const *_Env);

#ifndef _WSPAWN_DEFINED  /* Also in corecrt_wstdio.h */
# define _WSPAWN_DEFINED
  _CRTIMP intptr_t __cdecl _wspawnl(int _Mode, const wchar_t *_Filename, const wchar_t *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _wspawnle(int _Mode, const wchar_t *_Filename, const wchar_t *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _wspawnlp(int _Mode, const wchar_t *_Filename, const wchar_t *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(int _Mode, const wchar_t *_Filename, const wchar_t *_ArgList, ...);
  _CRTIMP intptr_t __cdecl _wspawnv(int _Mode, const wchar_t *_Filename, const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(int _Mode, const wchar_t *_Filename, const wchar_t *const *_ArgList, const wchar_t *const *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(int _Mode, const wchar_t *_Filename, const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(int _Mode, const wchar_t *_Filename, const wchar_t *const *_ArgList, const wchar_t *const *_Env);
#endif

#ifndef _CRT_WSYSTEM_DEFINED  /* Also in corecrt_wstdlib.h */
# define _CRT_WSYSTEM_DEFINED
  _CRTIMP int __cdecl _wsystem(const wchar_t *_Command);
#endif

#endif  /* _CRT_USE_WINAPI_FAMILY_DESKTOP_APP */

__MINGW_END_C_DECLS

#pragma pack(pop)

#endif  /* _INC_CORECRT_WPROCESS */
