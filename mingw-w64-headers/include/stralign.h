#include <winapifamily.h>
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __STRALIGN_H_
#define __STRALIGN_H_

#ifndef _STRALIGN_USE_SECURE_CRT
# if defined(__GOT_SECURE_LIB__) && __GOT_SECURE_LIB__ >= 200402L && defined(__MINGW_USE_SECAPI)
#   define _STRALIGN_USE_SECURE_CRT 1
# else
#   define _STRALIGN_USE_SECURE_CRT 0
# endif
#endif

#ifndef _WINDOWS_INSECURE_DEPRECATE
# if defined(_WINDOWS_SECURE_NO_DEPRECATE) || !_STRALIGN_USE_SECURE_CRT
#   define _WINDOWS_INSECURE_DEPRECATE
# else
#   define _WINDOWS_INSECURE_DEPRECATE __declspec(deprecated)
# endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#ifndef WSTR_ALIGNED
# define WSTR_ALIGNED(s) TRUE
#endif

  LPUWSTR WINAPI   uaw_CharUpperW(LPUWSTR String);
  int     APIENTRY uaw_lstrcmpW(PCUWSTR String1, PCUWSTR String2);
  int     APIENTRY uaw_lstrcmpiW(PCUWSTR String1, PCUWSTR String2);
  int     WINAPI   uaw_lstrlenW(LPCUWSTR String);
  PUWSTR  __cdecl  uaw_wcschr(PCUWSTR String, WCHAR Character);
  PUWSTR  __cdecl  uaw_wcscpy(PUWSTR Destination, PCUWSTR Source);
  int     __cdecl  uaw_wcsicmp(PCUWSTR String1, PCUWSTR String2);
  size_t  __cdecl  uaw_wcslen(PCUWSTR String);
  PUWSTR  __cdecl  uaw_wcsrchr(PCUWSTR String, WCHAR Character);
#ifdef CharUpper
  static __inline
  LPUWSTR ua_CharUpperW(LPUWSTR String)
  {
    if(WSTR_ALIGNED(String))
    {
      return CharUpperW((PWSTR)String);
    }
    else
    {
      return uaw_CharUpperW(String);
    }
  }
#endif

#ifdef lstrcmp
  static __inline
  int ua_lstrcmpW(LPCUWSTR String1, LPCUWSTR String2)
  {
    if(WSTR_ALIGNED(String1) && WSTR_ALIGNED(String2))
    {
      return lstrcmpW((LPCWSTR)String1, (LPCWSTR)String2);
    }
    else
    {
      return uaw_lstrcmpW(String1, String2);
    }
  }
#endif

#ifdef lstrcmpi
  static __inline
  int ua_lstrcmpiW(LPCUWSTR String1, LPCUWSTR String2)
  {
    if(WSTR_ALIGNED(String1) && WSTR_ALIGNED(String2))
    {
      return lstrcmpiW((LPCWSTR)String1, (LPCWSTR)String2);
    }
    else
    {
      return uaw_lstrcmpiW(String1, String2);
    }
  }
#endif

#ifdef lstrlen
  static __inline
  int ua_lstrlenW(LPCUWSTR String)
  {
    if(WSTR_ALIGNED(String))
    {
      return lstrlenW((PCWSTR)String);
    }
    else
    {
      return uaw_lstrlenW(String);
    }
  }
#endif

#if defined(_INC_STRING) || defined(_INC_WCHAR)

#ifdef _WConst_return
  typedef _WConst_return WCHAR UNALIGNED *PUWSTR_C;
#else
  typedef WCHAR UNALIGNED *PUWSTR_C;
#endif

  static __inline
  PUWSTR_C ua_wcschr(PCUWSTR String, WCHAR Character)
  {
    if(WSTR_ALIGNED(String))
    {
      return (PUWSTR_C)wcschr((PCWSTR)String, Character);
    }
    else
    {
      return (PUWSTR_C)uaw_wcschr(String, Character);
    }
  }

  static __inline
  PUWSTR_C ua_wcsrchr(PCUWSTR String, WCHAR Character)
  {
    if(WSTR_ALIGNED(String))
    {
      return (PUWSTR_C)wcsrchr((PCWSTR)String, Character);
    }
    else
    {
      return (PUWSTR_C)uaw_wcsrchr(String, Character);
    }
  }

#if defined(__cplusplus) && defined(_WConst_Return)
  static __inline
  PUWSTR ua_wcschr(PUWSTR String, WCHAR Character)
  {
    if(WSTR_ALIGNED(String))
    {
      return wcscpy((PWSTR)Destination, (PCWSTR)Source);
    }
    else
    {
      return uaw_wcscpy(Destination, Source);
    }
  }

  static __inline
  PUWSTR ua_wcscpy_s(PUWSTR Destination, size_t DestinationSize, PCUWSTR Source)
  {
    if(WSTR_ALIGNED(Source) && WSTR_ALIGNED(Destination))
    {
      return (wcscpy_s((PWSTR)Destination, DestinationSize, (PCWSTR)Source) == 0 ? Destination : NULL);
    }
    else
    {
      return uaw_wcscpy((PCUWSTR)String, Character);
    }
  }

  static __inline
  PUWSTR ua_wcsrchr(PUWSTR String, WCHAR Character)
  {
    if(WSTR_ALIGNED(String))
    {
      return wcsrchr(String, Character);
    }
    else
    {
      return uaw_wcsrchr((PCUWSTR)String, Character);
    }
  }
#endif

  static __inline
  PUWSTR ua_wcscpy(PUWSTR Destination, PCUWSTR Source)
  {
    if(WSTR_ALIGNED(Source) && WSTR_ALIGNED(Destination))
    {
      return wcscpy((PWSTR)Destination, (PCWSTR)Source);
    }
    else
    {
      return uaw_wcscpy(Destination, Source);
    }
  }

#if _STRALIGN_USE_SECURE_CRT
  static __inline
  PUWSTR ua_wcscpy_s(PUWSTR Destination, size_t DestinationSize, PCUWSTR Source)
  {
    if(WSTR_ALIGNED(Source) && WSTR_ALIGNED(Destination))
    {
      return (wcscpy_s((PWSTR)Destination, DestinationSize, (PCWSTR)Source) == 0 ? Destination : NULL);
    }
    else
    {
      return uaw_wcscpy(Destination, Source);
    }
  }
#endif

  static __inline
  size_t ua_wcslen(PCUWSTR String)
  {
    if(WSTR_ALIGNED(String))
    {
      return wcslen((PCWSTR)String);
    }
    else
    {
      return uaw_wcslen(String);
    }
  }

#endif  /* defined(_INC_STRING) || defined(_INC_WCHAR) */

  static __inline
  int ua_wcsicmp(LPCUWSTR String1, LPCUWSTR String2)
  {
    if(WSTR_ALIGNED(String1) && WSTR_ALIGNED(String2))
    {
      return _wcsicmp((LPCWSTR)String1, (LPCWSTR)String2);
    }
    else
    {
      return uaw_wcsicmp(String1, String2);
    }
  }

#ifndef __UA_WCSLEN
# define __UA_WCSLEN ua_wcslen
#endif

#define __UA_WSTRSIZE(s)     ((__UA_WCSLEN(s) + 1) * sizeof(WCHAR))
#define __UA_STACKCOPY(p, s) memcpy_s(_alloca(s),s,p,s)

#define WSTR_ALIGNED_STACK_COPY(d, s) (*(d) = (PCWSTR)(s))
#define ASTR_ALIGNED_STACK_COPY(d, s) (*(d) = (PCSTR)(s))

#define STRUC_ALIGNED_STACK_COPY(t, s) ((CONST t *)(s))

#ifdef UNICODE
# define TSTR_ALIGNED_STACK_COPY(d, s) WSTR_ALIGNED_STACK_COPY(d, s)
# define TSTR_ALIGNED(x)               WSTR_ALIGNED(x)
# define ua_CharUpper                  ua_CharUpperW
# define ua_lstrcmp                    ua_lstrcmpW
# define ua_lstrcmpi                   ua_lstrcmpiW
# define ua_lstrlen                    ua_lstrlenW
# define ua_tcscpy                     ua_wcscpy
# if _STRALIGN_USE_SECURE_CRT
#   define ua_tcscpy_s ua_wcscpy_s
# endif
#else
# define TSTR_ALIGNED_STACK_COPY(d, s) ASTR_ALIGNED_STACK_COPY(d, s)
# define TSTR_ALIGNED(x)               TRUE
# define ua_CharUpper                  CharUpperA
# define ua_lstrcmp                    lstrcmpA
# define ua_lstrcmpi                   lstrcmpiA
# define ua_lstrlen                    lstrlenA
# define ua_tcscpy                     strcpy
# if _STRALIGN_USE_SECURE_CRT
#   define ua_tcscpy_s strcpy_s
# endif
#endif

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */

#ifdef __cplusplus
}
#endif

#endif  /* __STRALIGN_H_ */
