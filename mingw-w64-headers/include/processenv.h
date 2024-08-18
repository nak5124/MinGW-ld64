/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ifndef _PROCESSENV_
#define _PROCESSENV_

#include <_mingw_unicode.h>
#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  WINBASEAPI WINBOOL WINAPI SetEnvironmentStringsW(LPWCH NewEnvironment);
#ifdef UNICODE
# define SetEnvironmentStrings SetEnvironmentStringsW
#endif
  WINBASEAPI LPSTR  WINAPI GetCommandLineA(VOID);
  WINBASEAPI LPWSTR WINAPI GetCommandLineW(VOID);
#define GetCommandLine __MINGW_NAME_AW(GetCommandLine)
  WINBASEAPI LPCH   WINAPI GetEnvironmentStrings(VOID);
  WINBASEAPI LPWCH  WINAPI GetEnvironmentStringsW(VOID);
#ifdef UNICODE
# define GetEnvironmentStrings  GetEnvironmentStringsW
#else
# define GetEnvironmentStringsA GetEnvironmentStrings
#endif
  WINBASEAPI WINBOOL WINAPI FreeEnvironmentStringsA(LPCH penv);
  WINBASEAPI WINBOOL WINAPI FreeEnvironmentStringsW(LPWCH penv);
#define FreeEnvironmentStrings __MINGW_NAME_AW(FreeEnvironmentStrings)
  WINBASEAPI DWORD   WINAPI GetEnvironmentVariableA(LPCSTR lpName, LPSTR lpBuffer, DWORD nSize);
  WINBASEAPI DWORD   WINAPI GetEnvironmentVariableW(LPCWSTR lpName, LPWSTR lpBuffer, DWORD nSize);
#define GetEnvironmentVariable __MINGW_NAME_AW(GetEnvironmentVariable)
  WINBASEAPI WINBOOL WINAPI SetEnvironmentVariableA(LPCSTR lpName, LPCSTR lpValue);
  WINBASEAPI WINBOOL WINAPI SetEnvironmentVariableW(LPCWSTR lpName, LPCWSTR lpValue);
#define SetEnvironmentVariable __MINGW_NAME_AW(SetEnvironmentVariable)
  WINBASEAPI DWORD   WINAPI ExpandEnvironmentStringsA(LPCSTR lpSrc, LPSTR lpDst, DWORD nSize);
  WINBASEAPI DWORD   WINAPI ExpandEnvironmentStringsW(LPCWSTR lpSrc, LPWSTR lpDst, DWORD nSize);
#define ExpandEnvironmentStrings __MINGW_NAME_AW(ExpandEnvironmentStrings)
  WINBASEAPI WINBOOL WINAPI SetCurrentDirectoryA(LPCSTR lpPathName);
  WINBASEAPI WINBOOL WINAPI SetCurrentDirectoryW(LPCWSTR lpPathName);
#define SetCurrentDirectory __MINGW_NAME_AW(SetCurrentDirectory)
  WINBASEAPI DWORD   WINAPI GetCurrentDirectoryA(DWORD nBufferLength, LPSTR lpBuffer);
  WINBASEAPI DWORD   WINAPI GetCurrentDirectoryW(DWORD nBufferLength, LPWSTR lpBuffer);
#define GetCurrentDirectory __MINGW_NAME_AW(GetCurrentDirectory)

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PC_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  WINBASEAPI HANDLE  WINAPI GetStdHandle(DWORD nStdHandle);
  WINBASEAPI WINBOOL WINAPI SetStdHandle(DWORD nStdHandle, HANDLE hHandle);
  WINBASEAPI WINBOOL WINAPI SetStdHandleEx(DWORD nStdHandle, HANDLE hHandle, PHANDLE phPrevValue);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PC_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  WINBASEAPI DWORD APIENTRY SearchPathA(LPCSTR lpPath, LPCSTR lpFileName, LPCSTR lpExtension, DWORD nBufferLength, LPSTR lpBuffer, LPSTR *lpFilePart);
  WINBASEAPI DWORD WINAPI   SearchPathW(LPCWSTR lpPath, LPCWSTR lpFileName, LPCWSTR lpExtension, DWORD nBufferLength, LPWSTR lpBuffer, LPWSTR *lpFilePart);
#define SearchPath __MINGW_NAME_AW(SearchPath)

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  WINBASEAPI WINBOOL WINAPI NeedCurrentDirectoryForExePathA(LPCSTR ExeName);
  WINBASEAPI WINBOOL WINAPI NeedCurrentDirectoryForExePathW(LPCWSTR ExeName);
#define NeedCurrentDirectoryForExePath __MINGW_NAME_AW(NeedCurrentDirectoryForExePath)

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#ifdef __cplusplus
}
#endif

#endif  /* _PROCESSENV_ */
