/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _ENCLAVEAPI_H_
#define _ENCLAVEAPI_H_

#include <_mingw_unicode.h>
#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>
#include <minwinbase.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_APP)

  WINBASEAPI WINBOOL WINAPI IsEnclaveTypeSupported(DWORD flEnclaveType);
  WINBASEAPI LPVOID  WINAPI CreateEnclave(HANDLE hProcess, LPVOID lpAddress, SIZE_T dwSize, SIZE_T dwInitialCommitment, DWORD flEnclaveType, LPCVOID lpEnclaveInformation, DWORD dwInfoLength, LPDWORD lpEnclaveError);
  WINBASEAPI WINBOOL WINAPI LoadEnclaveData(HANDLE hProcess, LPVOID lpAddress, LPCVOID lpBuffer, SIZE_T nSize, DWORD flProtect, LPCVOID lpPageInformation, DWORD dwInfoLength, PSIZE_T lpNumberOfBytesWritten, LPDWORD lpEnclaveError);
  WINBASEAPI WINBOOL WINAPI InitializeEnclave(HANDLE hProcess, LPVOID lpAddress, LPCVOID lpEnclaveInformation, DWORD dwInfoLength, LPDWORD lpEnclaveError);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_APP) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  WINBASEAPI WINBOOL WINAPI LoadEnclaveImageA(LPVOID lpEnclaveAddress, LPCSTR lpImageName);
  WINBASEAPI WINBOOL WINAPI LoadEnclaveImageW(LPVOID lpEnclaveAddress, LPCWSTR lpImageName);
#define LoadEnclaveImage __MINGW_NAME_AW(LoadEnclaveImage)
  WINBASEAPI WINBOOL WINAPI CallEnclave(LPENCLAVE_ROUTINE lpRoutine, LPVOID lpParameter, WINBOOL fWaitForThread, LPVOID *lpReturnValue);
  WINBASEAPI WINBOOL WINAPI TerminateEnclave(LPVOID lpAddress, WINBOOL fWait);
  WINBASEAPI WINBOOL WINAPI DeleteEnclave(LPVOID lpAddress);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#ifdef __cplusplus
}
#endif

#endif  /* _ENCLAVEAPI_H_ */
