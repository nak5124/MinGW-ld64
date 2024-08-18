/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WOW64APISET_H_
#define _WOW64APISET_H_

#include <_mingw_unicode.h>
#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>
#include <minwinbase.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

#ifndef RC_INVOKED
  WINBASEAPI BOOLEAN WINAPI Wow64EnableWow64FsRedirection(BOOLEAN Wow64FsEnableRedirection);
  WINBASEAPI WINBOOL WINAPI Wow64DisableWow64FsRedirection(PVOID *OldValue);
  WINBASEAPI WINBOOL WINAPI Wow64RevertWow64FsRedirection(PVOID OlValue);
#endif  /* RC_INVOKED */

  WINBASEAPI UINT    WINAPI GetSystemWow64DirectoryA(LPSTR lpBuffer, UINT uSize);
  WINBASEAPI UINT    WINAPI GetSystemWow64DirectoryW(LPWSTR lpBuffer, UINT uSize);
#define GetSystemWow64Directory __MINGW_NAME_AW(GetSystemWow64Directory)
  WINBASEAPI USHORT  WINAPI Wow64SetThreadDefaultGuestMachine(USHORT Machine);
  WINBASEAPI UINT    WINAPI GetSystemWow64Directory2A(LPSTR lpBuffer, UINT uSize, WORD ImageFileMachineType);
  WINBASEAPI UINT    WINAPI GetSystemWow64Directory2W(LPWSTR lpBuffer, UINT uSize, WORD ImageFileMachineType);
#define GetSystemWow64Directory2 __MINGW_NAME_AW(GetSystemWow64Directory2)
  WINBASEAPI HRESULT WINAPI IsWow64GuestMachineSupported(USHORT WowGuestMachine, WINBOOL *MachineIsSupported);
  WINBASEAPI WINBOOL WINAPI Wow64GetThreadContext(HANDLE hThread, PWOW64_CONTEXT lpContext);
  WINBASEAPI WINBOOL WINAPI Wow64SetThreadContext(HANDLE hThread, CONST WOW64_CONTEXT *lpContext);
  WINBASEAPI DWORD   WINAPI Wow64SuspendThread(HANDLE hThread);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

  WINBASEAPI WINBOOL WINAPI IsWow64Process(HANDLE hProcess, PBOOL Wow64Process);
  WINBASEAPI WINBOOL WINAPI IsWow64Process2(HANDLE hProcess, USHORT *pProcessMachine, USHORT *pNativeMachine);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */

#ifdef __cplusplus
}
#endif

#endif  /* _WOW64APISET_H_ */
