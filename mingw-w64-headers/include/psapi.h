/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _PSAPI_H_
#define _PSAPI_H_

#include <_mingw.h>
#include <winapifamily.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

#ifndef PSAPI_VERSION
# define PSAPI_VERSION 2
#endif

#if (PSAPI_VERSION > 1)
# define EmptyWorkingSet      K32EmptyWorkingSet
# define EnumPageFilesW       K32EnumPageFilesW
# define EnumPageFilesA       K32EnumPageFilesA
#endif

  WINBOOL WINAPI EmptyWorkingSet(HANDLE hProcess);

  typedef struct _ENUM_PAGE_FILE_INFORMATION
  {
    DWORD  cb;
    DWORD  Reserved;
    SIZE_T TotalSize;
    SIZE_T TotalInUse;
    SIZE_T PeakUsage;
  } ENUM_PAGE_FILE_INFORMATION, *PENUM_PAGE_FILE_INFORMATION;

  typedef WINBOOL (__stdcall *PENUM_PAGE_FILE_CALLBACKA)(LPVOID pContext, PENUM_PAGE_FILE_INFORMATION pPageFileInfo, LPCSTR lpFilename);
  typedef WINBOOL (__stdcall *PENUM_PAGE_FILE_CALLBACKW)(LPVOID pContext, PENUM_PAGE_FILE_INFORMATION pPageFileInfo, LPCWSTR lpFilename);

  WINBOOL WINAPI EnumPageFilesA(PENUM_PAGE_FILE_CALLBACKA pCallBackRoutine, LPVOID pContext);
  WINBOOL WINAPI EnumPageFilesW(PENUM_PAGE_FILE_CALLBACKW pCallBackRoutine, LPVOID pContext);
#define PENUM_PAGE_FILE_CALLBACK __MINGW_NAME_AW(PENUM_PAGE_FILE_CALLBACK)
#define EnumPageFiles            __MINGW_NAME_AW(EnumPageFiles)

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#ifndef PSAPI_VERSION
# define PSAPI_VERSION 2
#endif

#if (PSAPI_VERSION > 1)
# define EnumProcesses        K32EnumProcesses
# define GetProcessMemoryInfo K32GetProcessMemoryInfo
# define GetModuleInformation K32GetModuleInformation
# define GetModuleBaseNameA   K32GetModuleBaseNameA
# define GetModuleBaseNameW   K32GetModuleBaseNameW
# define GetModuleFileNameExA K32GetModuleFileNameExA
# define GetModuleFileNameExW K32GetModuleFileNameExW
# define QueryWorkingSet      K32QueryWorkingSet
# define QueryWorkingSetEx    K32QueryWorkingSetEx
#endif

  WINBOOL WINAPI EnumProcesses(DWORD *lpidProcess, DWORD cb, LPDWORD lpcbNeeded);
  DWORD   WINAPI GetModuleBaseNameA(HANDLE hProcess, HMODULE hModule, LPSTR lpBaseName, DWORD nSize);
  DWORD   WINAPI GetModuleBaseNameW(HANDLE hProcess, HMODULE hModule, LPWSTR lpBaseName, DWORD nSize);
#define GetModuleBaseName __MINGW_NAME_AW(GetModuleBaseName)
  DWORD   WINAPI GetModuleFileNameExA(HANDLE hProcess, HMODULE hModule, LPSTR lpFilename, DWORD nSize);
  DWORD   WINAPI GetModuleFileNameExW(HANDLE hProcess, HMODULE hModule, LPWSTR lpFilename, DWORD nSize);
#define GetModuleFileNameEx __MINGW_NAME_AW(GetModuleFileNameEx)

  typedef struct _MODULEINFO
  {
    LPVOID lpBaseOfDll;
    DWORD  SizeOfImage;
    LPVOID EntryPoint;
  } MODULEINFO, *LPMODULEINFO;

  WINBOOL WINAPI GetModuleInformation(HANDLE hProcess, HMODULE hModule, LPMODULEINFO lpmodinfo, DWORD cb);

  typedef union _PSAPI_WORKING_SET_BLOCK
  {
    ULONG_PTR Flags;
    __C89_NAMELESS struct
    {
      ULONG_PTR Protection  : 5;
      ULONG_PTR ShareCount  : 3;
      ULONG_PTR Shared      : 1;
      ULONG_PTR Reserved    : 3;
      ULONG_PTR VirtualPage : 52;
    };
  } PSAPI_WORKING_SET_BLOCK, *PPSAPI_WORKING_SET_BLOCK;

  typedef struct _PSAPI_WORKING_SET_INFORMATION
  {
    ULONG_PTR               NumberOfEntries;
    PSAPI_WORKING_SET_BLOCK WorkingSetInfo[1];
  } PSAPI_WORKING_SET_INFORMATION, *PPSAPI_WORKING_SET_INFORMATION;

  typedef union _PSAPI_WORKING_SET_EX_BLOCK
  {
    ULONG_PTR Flags;
    __C89_NAMELESS union
    {
      __C89_NAMELESS struct
      {
        ULONG_PTR Valid           : 1;
        ULONG_PTR ShareCount      : 3;
        ULONG_PTR Win32Protection : 11;
        ULONG_PTR Shared          : 1;
        ULONG_PTR Node            : 6;
        ULONG_PTR Locked          : 1;
        ULONG_PTR LargePage       : 1;
        ULONG_PTR Reserved        : 7;
        ULONG_PTR Bad             : 1;
        ULONG_PTR ReservedUlong   : 32;
      };
      __C89_NAMELESS struct
      {
        ULONG_PTR Valid         : 1;
        ULONG_PTR Reserved0     : 14;
        ULONG_PTR Shared        : 1;
        ULONG_PTR Reserved1     : 15;
        ULONG_PTR Bad           : 1;
        ULONG_PTR ReservedUlong : 32;
      } Invalid;
    };
  } PSAPI_WORKING_SET_EX_BLOCK, *PPSAPI_WORKING_SET_EX_BLOCK;

  typedef struct _PSAPI_WORKING_SET_EX_INFORMATION
  {
    PVOID                      VirtualAddress;
    PSAPI_WORKING_SET_EX_BLOCK VirtualAttributes;
  } PSAPI_WORKING_SET_EX_INFORMATION, *PPSAPI_WORKING_SET_EX_INFORMATION;

  WINBOOL WINAPI QueryWorkingSet(HANDLE hProcess, PVOID pv, DWORD cb);
  WINBOOL WINAPI QueryWorkingSetEx(HANDLE hProcess, PVOID pv, DWORD cb);

  typedef struct _PROCESS_MEMORY_COUNTERS
  {
    DWORD  cb;
    DWORD  PageFaultCount;
    SIZE_T PeakWorkingSetSize;
    SIZE_T WorkingSetSize;
    SIZE_T QuotaPeakPagedPoolUsage;
    SIZE_T QuotaPagedPoolUsage;
    SIZE_T QuotaPeakNonPagedPoolUsage;
    SIZE_T QuotaNonPagedPoolUsage;
    SIZE_T PagefileUsage;
    SIZE_T PeakPagefileUsage;
  } PROCESS_MEMORY_COUNTERS;

  typedef PROCESS_MEMORY_COUNTERS *PPROCESS_MEMORY_COUNTERS;

  typedef struct _PROCESS_MEMORY_COUNTERS_EX
  {
    DWORD  cb;
    DWORD  PageFaultCount;
    SIZE_T PeakWorkingSetSize;
    SIZE_T WorkingSetSize;
    SIZE_T QuotaPeakPagedPoolUsage;
    SIZE_T QuotaPagedPoolUsage;
    SIZE_T QuotaPeakNonPagedPoolUsage;
    SIZE_T QuotaNonPagedPoolUsage;
    SIZE_T PagefileUsage;
    SIZE_T PeakPagefileUsage;
    SIZE_T PrivateUsage;
  } PROCESS_MEMORY_COUNTERS_EX;

  typedef PROCESS_MEMORY_COUNTERS_EX *PPROCESS_MEMORY_COUNTERS_EX;

  typedef struct _PROCESS_MEMORY_COUNTERS_EX2
  {
    DWORD   cb;
    DWORD   PageFaultCount;
    SIZE_T  PeakWorkingSetSize;
    SIZE_T  WorkingSetSize;
    SIZE_T  QuotaPeakPagedPoolUsage;
    SIZE_T  QuotaPagedPoolUsage;
    SIZE_T  QuotaPeakNonPagedPoolUsage;
    SIZE_T  QuotaNonPagedPoolUsage;
    SIZE_T  PagefileUsage;
    SIZE_T  PeakPagefileUsage;
    SIZE_T  PrivateUsage;
    SIZE_T  PrivateWorkingSetSize;
    ULONG64 SharedCommitUsage;
  } PROCESS_MEMORY_COUNTERS_EX2;

  typedef PROCESS_MEMORY_COUNTERS_EX2 *PPROCESS_MEMORY_COUNTERS_EX2;

  WINBOOL WINAPI GetProcessMemoryInfo(HANDLE Process, PPROCESS_MEMORY_COUNTERS ppsmemCounters, DWORD cb);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#define LIST_MODULES_DEFAULT 0x0
#define LIST_MODULES_32BIT   0x01
#define LIST_MODULES_64BIT   0x02
#define LIST_MODULES_ALL     (LIST_MODULES_32BIT | LIST_MODULES_64BIT)

#ifndef PSAPI_VERSION
# define PSAPI_VERSION 2
#endif

#if (PSAPI_VERSION > 1)
# define EnumProcessModules          K32EnumProcessModules
# define EnumProcessModulesEx        K32EnumProcessModulesEx
# define InitializeProcessForWsWatch K32InitializeProcessForWsWatch
# define GetWsChanges                K32GetWsChanges
# define GetWsChangesEx              K32GetWsChangesEx
# define GetMappedFileNameA          K32GetMappedFileNameA
# define GetMappedFileNameW          K32GetMappedFileNameW
# define EnumDeviceDrivers           K32EnumDeviceDrivers
# define GetDeviceDriverBaseNameA    K32GetDeviceDriverBaseNameA
# define GetDeviceDriverBaseNameW    K32GetDeviceDriverBaseNameW
# define GetDeviceDriverFileNameA    K32GetDeviceDriverFileNameA
# define GetDeviceDriverFileNameW    K32GetDeviceDriverFileNameW
# define GetPerformanceInfo          K32GetPerformanceInfo
# define GetProcessImageFileNameA    K32GetProcessImageFileNameA
# define GetProcessImageFileNameW    K32GetProcessImageFileNameW
#endif

  WINBOOL WINAPI EnumProcessModules(HANDLE hProcess, HMODULE *lphModule, DWORD cb, LPDWORD lpcbNeeded);
  WINBOOL WINAPI EnumProcessModulesEx(HANDLE hProcess, HMODULE *lphModule, DWORD cb, LPDWORD lpcbNeeded, DWORD dwFilterFlag);
  WINBOOL WINAPI InitializeProcessForWsWatch(HANDLE hProcess);

  typedef struct _PSAPI_WS_WATCH_INFORMATION
  {
    LPVOID FaultingPc;
    LPVOID FaultingVa;
  } PSAPI_WS_WATCH_INFORMATION, *PPSAPI_WS_WATCH_INFORMATION;

  typedef struct _PSAPI_WS_WATCH_INFORMATION_EX
  {
    PSAPI_WS_WATCH_INFORMATION BasicInfo;
    ULONG_PTR                  FaultingThreadId;
    ULONG_PTR                  Flags;
  } PSAPI_WS_WATCH_INFORMATION_EX, *PPSAPI_WS_WATCH_INFORMATION_EX;

  WINBOOL WINAPI GetWsChanges(HANDLE hProcess, PPSAPI_WS_WATCH_INFORMATION lpWatchInfo, DWORD cb);
  WINBOOL WINAPI GetWsChangesEx(HANDLE hProcess, PPSAPI_WS_WATCH_INFORMATION_EX lpWatchInfoEx, PDWORD cb);
  DWORD   WINAPI GetMappedFileNameA(HANDLE hProcess, LPVOID lpv, LPSTR lpFilename, DWORD nSize);
  DWORD   WINAPI GetMappedFileNameW(HANDLE hProcess, LPVOID lpv, LPWSTR lpFilename, DWORD nSize);
#define GetMappedFileName __MINGW_NAME_AW(GetMappedFileName)
  WINBOOL WINAPI EnumDeviceDrivers(LPVOID *lpImageBase, DWORD cb, LPDWORD lpcbNeeded);
  DWORD   WINAPI GetDeviceDriverBaseNameA(LPVOID ImageBase, LPSTR lpFilename, DWORD nSize);
  DWORD   WINAPI GetDeviceDriverBaseNameW(LPVOID ImageBase, LPWSTR lpBaseName, DWORD nSize);
#define GetDeviceDriverBaseName __MINGW_NAME_AW(GetDeviceDriverBaseName)
  DWORD   WINAPI GetDeviceDriverFileNameA(LPVOID ImageBase, LPSTR lpFilename, DWORD nSize);
  DWORD   WINAPI GetDeviceDriverFileNameW(LPVOID ImageBase, LPWSTR lpFilename, DWORD nSize);
#define GetDeviceDriverFileName __MINGW_NAME_AW(GetDeviceDriverFileName)

  typedef struct _PERFORMANCE_INFORMATION
  {
    DWORD  cb;
    SIZE_T CommitTotal;
    SIZE_T CommitLimit;
    SIZE_T CommitPeak;
    SIZE_T PhysicalTotal;
    SIZE_T PhysicalAvailable;
    SIZE_T SystemCache;
    SIZE_T KernelTotal;
    SIZE_T KernelPaged;
    SIZE_T KernelNonpaged;
    SIZE_T PageSize;
    DWORD  HandleCount;
    DWORD  ProcessCount;
    DWORD  ThreadCount;
  } PERFORMANCE_INFORMATION, *PPERFORMANCE_INFORMATION, PERFORMACE_INFORMATION, *PPERFORMACE_INFORMATION;

  WINBOOL WINAPI GetPerformanceInfo(PPERFORMANCE_INFORMATION pPerformanceInformation, DWORD cb);
  DWORD   WINAPI GetProcessImageFileNameA(HANDLE hProcess, LPSTR lpImageFileName, DWORD nSize);
  DWORD   WINAPI GetProcessImageFileNameW(HANDLE hProcess, LPWSTR lpImageFileName, DWORD nSize);
#define GetProcessImageFileName __MINGW_NAME_AW(GetProcessImageFileName)

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#ifdef __cplusplus
}
#endif

#endif  /* _PSAPI_H_ */
