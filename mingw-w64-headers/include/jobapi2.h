/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _JOBAPISET2_H_
#define _JOBAPISET2_H_

#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>
#include <minwinbase.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  typedef struct JOBOBJECT_IO_RATE_CONTROL_INFORMATION
  {
    LONG64 MaxIops;
    LONG64 MaxBandwidth;
    LONG64 ReservationIops;
    PCWSTR VolumeName;
    ULONG  BaseIoSize;
    ULONG  ControlFlags;
  } JOBOBJECT_IO_RATE_CONTROL_INFORMATION;

  WINBASEAPI HANDLE  WINAPI CreateJobObjectW(LPSECURITY_ATTRIBUTES lpJobAttributes, LPCWSTR lpName);
  WINBASEAPI VOID    WINAPI FreeMemoryJobObject(VOID *Buffer);
  WINBASEAPI HANDLE  WINAPI OpenJobObjectW(DWORD dwDesiredAccess, WINBOOL bInheritHandle, LPCWSTR lpName);
  WINBASEAPI WINBOOL WINAPI AssignProcessToJobObject(HANDLE hJob, HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI TerminateJobObject(HANDLE hJob, UINT uExitCode);
  WINBASEAPI WINBOOL WINAPI SetInformationJobObject(HANDLE hJob, JOBOBJECTINFOCLASS JobObjectInformationClass, LPVOID lpJobObjectInformation, DWORD cbJobObjectInformationLength);
  WINBASEAPI DWORD   WINAPI SetIoRateControlInformationJobObject(HANDLE hJob, JOBOBJECT_IO_RATE_CONTROL_INFORMATION *IoRateControlInfo);
  WINBASEAPI WINBOOL WINAPI QueryInformationJobObject(HANDLE hJob, JOBOBJECTINFOCLASS JobObjectInformationClass, LPVOID lpJobObjectInformation, DWORD cbJobObjectInformationLength, LPDWORD lpReturnLength);
  WINBASEAPI DWORD   WINAPI QueryIoRateControlInformationJobObject(HANDLE hJob, PCWSTR VolumeName, JOBOBJECT_IO_RATE_CONTROL_INFORMATION **InfoBlocks, ULONG *InfoBlockCount);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#ifdef __cplusplus
}
#endif

#endif  /* _JOBAPISET2_H_ */
