/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _APISETDEBUG_
#define _APISETDEBUG_

#include <_mingw_unicode.h>
#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>
#include <minwinbase.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  WINBASEAPI WINBOOL WINAPI IsDebuggerPresent(VOID);
  WINBASEAPI VOID    WINAPI DebugBreak(VOID);
  WINBASEAPI VOID    WINAPI OutputDebugStringA(LPCSTR lpOutputString);
  WINBASEAPI VOID    WINAPI OutputDebugStringW(LPCWSTR lpOutputString);
#define OutputDebugString __MINGW_NAME_AW(OutputDebugString)

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  WINBASEAPI WINBOOL APIENTRY ContinueDebugEvent(DWORD dwProcessId, DWORD dwThreadId, DWORD dwContinueStatus);
  WINBASEAPI WINBOOL APIENTRY WaitForDebugEvent(LPDEBUG_EVENT lpDebugEvent, DWORD dwMilliseconds);
  WINBASEAPI WINBOOL APIENTRY DebugActiveProcess(DWORD dwProcessId);
  WINBASEAPI WINBOOL APIENTRY DebugActiveProcessStop(DWORD dwProcessId);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  WINBASEAPI WINBOOL WINAPI   CheckRemoteDebuggerPresent(HANDLE hProcess, PBOOL pbDebuggerPresent);
  WINBASEAPI WINBOOL APIENTRY WaitForDebugEventEx(LPDEBUG_EVENT lpDebugEvent, DWORD dwMilliseconds);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#ifdef __cplusplus
}
#endif

#endif  /* _APISETDEBUG_ */
