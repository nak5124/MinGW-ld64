/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _MEMORYAPI_H_
#define _MEMORYAPI_H_

#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>
#include <minwinbase.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#define FILE_MAP_WRITE           SECTION_MAP_WRITE
#define FILE_MAP_READ            SECTION_MAP_READ
#define FILE_MAP_ALL_ACCESS      SECTION_ALL_ACCESS
#define FILE_MAP_EXECUTE         SECTION_MAP_EXECUTE_EXPLICIT
#define FILE_MAP_COPY            0x00000001
#define FILE_MAP_RESERVE         0x80000000
#define FILE_MAP_TARGETS_INVALID 0x40000000
#define FILE_MAP_LARGE_PAGES     0x20000000

  WINBASEAPI WINBOOL WINAPI VirtualFree(LPVOID lpAddress, SIZE_T dwSize, DWORD dwFreeType);
  WINBASEAPI SIZE_T  WINAPI VirtualQuery(LPCVOID lpAddress, PMEMORY_BASIC_INFORMATION lpBuffer, SIZE_T dwLength);
  WINBASEAPI LPVOID  WINAPI VirtualAllocEx(HANDLE hProcess, LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect);
  WINBASEAPI WINBOOL WINAPI VirtualProtectEx(HANDLE hProcess, LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpflOldProtect);
  WINBASEAPI WINBOOL WINAPI VirtualFreeEx(HANDLE hProcess, LPVOID lpAddress, SIZE_T dwSize, DWORD dwFreeType);
  WINBASEAPI WINBOOL WINAPI UnmapViewOfFile(LPCVOID lpBaseAddress);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  WINBASEAPI LPVOID  WINAPI VirtualAlloc(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect);
  WINBASEAPI SIZE_T  WINAPI VirtualQueryEx(HANDLE hProcess, LPCVOID lpAddress, PMEMORY_BASIC_INFORMATION lpBuffer, SIZE_T dwLength);
  WINBASEAPI WINBOOL WINAPI ReadProcessMemory(HANDLE hProcess, LPCVOID lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize, SIZE_T *lpNumberOfBytesRead);
  WINBASEAPI WINBOOL WINAPI WriteProcessMemory(HANDLE hProcess, LPVOID lpBaseAddress, LPCVOID lpBuffer, SIZE_T nSize, SIZE_T *lpNumberOfBytesWritten);
  WINBASEAPI HANDLE  WINAPI CreateFileMappingW(HANDLE hFile, LPSECURITY_ATTRIBUTES lpFileMappingAttributes, DWORD flProtect, DWORD dwMaximumSizeHigh, DWORD dwMaximumSizeLow, LPCWSTR lpName);
#ifdef UNICODE
# define CreateFileMapping CreateFileMappingW
#endif
  WINBASEAPI HANDLE WINAPI OpenFileMappingW(DWORD dwDesiredAccess, WINBOOL bInheritHandle, LPCWSTR lpName);
#ifdef UNICODE
# define OpenFileMapping OpenFileMappingW
#endif
  WINBASEAPI LPVOID WINAPI MapViewOfFile(HANDLE hFileMappingObject, DWORD dwDesiredAccess, DWORD dwFileOffsetHigh, DWORD dwFileOffsetLow, SIZE_T dwNumberOfBytesToMap);
  WINBASEAPI LPVOID WINAPI MapViewOfFileEx(HANDLE hFileMappingObject, DWORD dwDesiredAccess, DWORD dwFileOffsetHigh, DWORD dwFileOffsetLow, SIZE_T dwNumberOfBytesToMap, LPVOID lpBaseAddress);

#define FILE_CACHE_FLAGS_DEFINED
#define FILE_CACHE_MAX_HARD_ENABLE  0x00000001
#define FILE_CACHE_MAX_HARD_DISABLE 0x00000002
#define FILE_CACHE_MIN_HARD_ENABLE  0x00000004
#define FILE_CACHE_MIN_HARD_DISABLE 0x00000008

  WINBASEAPI WINBOOL WINAPI GetSystemFileCacheSize(PSIZE_T lpMinimumFileCacheSize, PSIZE_T lpMaximumFileCacheSize, PDWORD lpFlags);
  WINBASEAPI WINBOOL WINAPI SetSystemFileCacheSize(SIZE_T MinimumFileCacheSize, SIZE_T MaximumFileCacheSize, DWORD Flags);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) || defined(WINSTORECOMPAT)

  WINBASEAPI WINBOOL WINAPI VirtualProtect(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpflOldProtect);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) || defined(WINSTORECOMPAT) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

  WINBASEAPI WINBOOL WINAPI FlushViewOfFile(LPCVOID lpBaseAddress, SIZE_T dwNumberOfBytesToFlush);
  WINBASEAPI SIZE_T  WINAPI GetLargePageMinimum(VOID);
  WINBASEAPI WINBOOL WINAPI GetProcessWorkingSetSize(HANDLE hProcess, PSIZE_T lpMinimumWorkingSetSize, PSIZE_T lpMaximumWorkingSetSize);
  WINBASEAPI WINBOOL WINAPI GetProcessWorkingSetSizeEx(HANDLE hProcess, PSIZE_T lpMinimumWorkingSetSize, PSIZE_T lpMaximumWorkingSetSize, PDWORD Flags);
  WINBASEAPI WINBOOL WINAPI SetProcessWorkingSetSize(HANDLE hProcess, SIZE_T dwMinimumWorkingSetSize, SIZE_T dwMaximumWorkingSetSize);
  WINBASEAPI WINBOOL WINAPI SetProcessWorkingSetSizeEx(HANDLE hProcess, SIZE_T dwMinimumWorkingSetSize, SIZE_T dwMaximumWorkingSetSize, DWORD Flags);
  WINBASEAPI UINT    WINAPI GetWriteWatch(DWORD dwFlags, PVOID lpBaseAddress, SIZE_T dwRegionSize, PVOID *lpAddresses, ULONG_PTR *lpdwCount, LPDWORD lpdwGranularity);
  WINBASEAPI UINT    WINAPI ResetWriteWatch(LPVOID lpBaseAddress, SIZE_T dwRegionSize);
  WINBASEAPI HANDLE  WINAPI CreateFileMappingFromApp(HANDLE hFile, PSECURITY_ATTRIBUTES SecurityAttributes, ULONG PageProtection, ULONG64 MaximumSize, PCWSTR Name);
  WINBASEAPI PVOID   WINAPI MapViewOfFileFromApp(HANDLE hFileMappingObject, ULONG DesiredAccess, ULONG64 FileOffset, SIZE_T NumberOfBytesToMap);
  WINBASEAPI WINBOOL WINAPI UnmapViewOfFileEx(PVOID BaseAddress, ULONG UnmapFlags);

  typedef enum _OFFER_PRIORITY
  {
    VmOfferPriorityVeryLow = 1,
    VmOfferPriorityLow,
    VmOfferPriorityBelowNormal,
    VmOfferPriorityNormal
  } OFFER_PRIORITY;

  WINBASEAPI DWORD   WINAPI OfferVirtualMemory(PVOID VirtualAddress, SIZE_T Size, OFFER_PRIORITY Priority);
  WINBASEAPI DWORD   WINAPI ReclaimVirtualMemory(void const *VirtualAddress, SIZE_T Size);
  WINBASEAPI DWORD   WINAPI DiscardVirtualMemory(PVOID VirtualAddress, SIZE_T Size);
  WINBASEAPI WINBOOL WINAPI SetProcessValidCallTargets(HANDLE hProcess, PVOID VirtualAddress, SIZE_T RegionSize, ULONG NumberOfOffsets, PCFG_CALL_TARGET_INFO OffsetInformation);
  WINBASEAPI WINBOOL WINAPI SetProcessValidCallTargetsForMappedView(HANDLE Process, PVOID VirtualAddress, SIZE_T RegionSize, ULONG NumberOfOffsets, PCFG_CALL_TARGET_INFO OffsetInformation, HANDLE Section, ULONG64 ExpectedFileOffset);
  WINBASEAPI PVOID   WINAPI VirtualAllocFromApp(PVOID BaseAddress, SIZE_T Size, ULONG AllocationType, ULONG  Protection);
  WINBASEAPI WINBOOL WINAPI VirtualProtectFromApp(PVOID lpAddress, SIZE_T dwSize, ULONG flNewProtect, PULONG lpflOldProtect);
  WINBASEAPI HANDLE  WINAPI OpenFileMappingFromApp(ULONG DesiredAccess, WINBOOL InheritHandle, PCWSTR Name);
  WINBASEAPI WINBOOL WINAPI UnmapViewOfFile2(HANDLE Process, PVOID BaseAddress, ULONG UnmapFlags);
  WINBASEAPI WINBOOL WINAPI VirtualUnlockEx(HANDLE Process, LPVOID Address, SIZE_T Size);
  WINBASEAPI PVOID   WINAPI VirtualAlloc2FromApp(HANDLE Process, PVOID BaseAddress, SIZE_T Size, ULONG AllocationType, ULONG PageProtection, MEM_EXTENDED_PARAMETER *ExtendedParameters, ULONG ParameterCount);
  WINBASEAPI PVOID   WINAPI MapViewOfFile3FromApp(HANDLE FileMapping, HANDLE Process, PVOID BaseAddress, ULONG64 Offset, SIZE_T ViewSize, ULONG AllocationType, ULONG PageProtection, MEM_EXTENDED_PARAMETER *ExtendedParameters, ULONG ParameterCount);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  WINBASEAPI WINBOOL WINAPI VirtualLock(LPVOID lpAddress, SIZE_T dwSize);
  WINBASEAPI WINBOOL WINAPI VirtualUnlock(LPVOID lpAddress, SIZE_T dwSize);

  typedef enum _MEMORY_RESOURCE_NOTIFICATION_TYPE
  {
    LowMemoryResourceNotification,
    HighMemoryResourceNotification
  } MEMORY_RESOURCE_NOTIFICATION_TYPE;

  WINBASEAPI HANDLE  WINAPI CreateMemoryResourceNotification(MEMORY_RESOURCE_NOTIFICATION_TYPE NotificationType);
  WINBASEAPI WINBOOL WINAPI QueryMemoryResourceNotification(HANDLE ResourceNotificationHandle, PBOOL ResourceState);
  WINBASEAPI HANDLE  WINAPI CreateFileMappingNumaW(HANDLE hFile, LPSECURITY_ATTRIBUTES lpFileMappingAttributes, DWORD flProtect, DWORD dwMaximumSizeHigh, DWORD dwMaximumSizeLow, LPCWSTR lpName, DWORD nndPreferred);
#ifdef UNICODE
# define CreateFileMappingNuma CreateFileMappingNumaW
#endif

  typedef struct _WIN32_MEMORY_RANGE_ENTRY
  {
    PVOID  VirtualAddress;
    SIZE_T NumberOfBytes;
  } WIN32_MEMORY_RANGE_ENTRY, *PWIN32_MEMORY_RANGE_ENTRY;

  WINBASEAPI WINBOOL WINAPI PrefetchVirtualMemory(HANDLE hProcess, ULONG_PTR NumberOfEntries, PWIN32_MEMORY_RANGE_ENTRY VirtualAddresses, ULONG Flags);
  WINBASEAPI WINBOOL WINAPI AllocateUserPhysicalPages(HANDLE hProcess, PULONG_PTR NumberOfPages, PULONG_PTR PageArray);
  WINBASEAPI WINBOOL WINAPI FreeUserPhysicalPages(HANDLE hProcess, PULONG_PTR NumberOfPages, PULONG_PTR PageArray);
  WINBASEAPI WINBOOL WINAPI MapUserPhysicalPages(PVOID VirtualAddress, ULONG_PTR NumberOfPages, PULONG_PTR PageArray);
  WINBASEAPI WINBOOL WINAPI AllocateUserPhysicalPagesNuma(HANDLE hProcess, PULONG_PTR NumberOfPages, PULONG_PTR PageArray, DWORD nndPreferred);
  WINBASEAPI LPVOID  WINAPI VirtualAllocExNuma(HANDLE hProcess, LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect, DWORD nndPreferred);

#define MEHC_PATROL_SCRUBBER_PRESENT 0x1

  WINBASEAPI WINBOOL WINAPI GetMemoryErrorHandlingCapabilities(PULONG Capabilities);

  typedef VOID (WINAPI BAD_MEMORY_CALLBACK_ROUTINE)(VOID);
  typedef BAD_MEMORY_CALLBACK_ROUTINE *PBAD_MEMORY_CALLBACK_ROUTINE;

  WINBASEAPI PVOID   WINAPI RegisterBadMemoryNotification(PBAD_MEMORY_CALLBACK_ROUTINE Callback);
  WINBASEAPI WINBOOL WINAPI UnregisterBadMemoryNotification(PVOID RegistrationHandle);

  typedef enum WIN32_MEMORY_INFORMATION_CLASS
  {
    MemoryRegionInfo
  } WIN32_MEMORY_INFORMATION_CLASS;

  typedef struct WIN32_MEMORY_REGION_INFORMATION
  {
    PVOID AllocationBase;
    ULONG AllocationProtect;
    __C89_NAMELESS union
    {
      ULONG Flags;
      __C89_NAMELESS struct
      {
        ULONG Private        : 1;
        ULONG MappedDataFile : 1;
        ULONG MappedImage    : 1;
        ULONG MappedPageFile : 1;
        ULONG MappedPhysical : 1;
        ULONG DirectMapped   : 1;
        ULONG Reserved       : 26;
      };
    };
    SIZE_T RegionSize;
    SIZE_T CommitSize;
  } WIN32_MEMORY_REGION_INFORMATION;

  WINBASEAPI WINBOOL WINAPI QueryVirtualMemoryInformation(HANDLE Process, const VOID *VirtualAddress, WIN32_MEMORY_INFORMATION_CLASS MemoryInformationClass, PVOID MemoryInformation, SIZE_T MemoryInformationSize, PSIZE_T ReturnSize);
  WINBASEAPI PVOID   WINAPI MapViewOfFileNuma2(HANDLE FileMappingHandle, HANDLE ProcessHandle, ULONG64 Offset, PVOID BaseAddress, SIZE_T ViewSize, ULONG AllocationType, ULONG PageProtection, ULONG PreferredNode);

#ifndef __WIDL__
  FORCEINLINE
  PVOID MapViewOfFile2(HANDLE FileMappingHandle, HANDLE ProcessHandle, ULONG64 Offset, PVOID BaseAddress, SIZE_T ViewSize, ULONG AllocationType, ULONG PageProtection)
  {
    return MapViewOfFileNuma2(FileMappingHandle, ProcessHandle, Offset, BaseAddress, ViewSize, AllocationType, PageProtection, NUMA_NO_PREFERRED_NODE);
  }
#endif  /* __WIDL__ */

  WINBASEAPI PVOID   WINAPI VirtualAlloc2(HANDLE Process, PVOID BaseAddress, SIZE_T Size, ULONG AllocationType, ULONG PageProtection, MEM_EXTENDED_PARAMETER *ExtendedParameters, ULONG ParameterCount);
  WINBASEAPI PVOID   WINAPI MapViewOfFile3(HANDLE FileMapping, HANDLE Process, PVOID BaseAddress, ULONG64 Offset, SIZE_T ViewSize, ULONG AllocationType, ULONG PageProtection, MEM_EXTENDED_PARAMETER *ExtendedParameters, ULONG ParameterCount);
  WINBASEAPI HANDLE  WINAPI CreateFileMapping2(HANDLE File, SECURITY_ATTRIBUTES *SecurityAttributes, ULONG DesiredAccess, ULONG PageProtection, ULONG AllocationAttributes, ULONG64 MaximumSize, PCWSTR Name, MEM_EXTENDED_PARAMETER *ExtendedParameters, ULONG ParameterCount);
  WINBASEAPI WINBOOL WINAPI AllocateUserPhysicalPages2(HANDLE ObjectHandle, PULONG_PTR NumberOfPages, PULONG_PTR PageArray, PMEM_EXTENDED_PARAMETER ExtendedParameters, ULONG ExtendedParameterCount);

  typedef enum WIN32_MEMORY_PARTITION_INFORMATION_CLASS
  {
    MemoryPartitionInfo,
    MemoryPartitionDedicatedMemoryInfo
  } WIN32_MEMORY_PARTITION_INFORMATION_CLASS;

  typedef struct DECLSPEC_ALIGN(8) WIN32_MEMORY_PARTITION_INFORMATION
  {
    ULONG   Flags;
    ULONG   NumaNode;
    ULONG   Channel;
    ULONG   NumberOfNumaNodes;
    ULONG64 ResidentAvailablePages;
    ULONG64 CommittedPages;
    ULONG64 CommitLimit;
    ULONG64 PeakCommitment;
    ULONG64 TotalNumberOfPages;
    ULONG64 AvailablePages;
    ULONG64 ZeroPages;
    ULONG64 FreePages;
    ULONG64 StandbyPages;
    ULONG64 Reserved[16];
    ULONG64 MaximumCommitLimit;
    ULONG64 Reserved2;
    ULONG   PartitionId;
  } WIN32_MEMORY_PARTITION_INFORMATION;

  WINBASEAPI HANDLE  WINAPI OpenDedicatedMemoryPartition(HANDLE Partition, ULONG64 DedicatedMemoryTypeId, ACCESS_MASK DesiredAccess, WINBOOL InheritHandle);
  WINBASEAPI WINBOOL WINAPI QueryPartitionInformation(HANDLE Partition, WIN32_MEMORY_PARTITION_INFORMATION_CLASS PartitionInformationClass, PVOID PartitionInformation, ULONG PartitionInformationLength);
  WINBASEAPI WINBOOL WINAPI GetMemoryNumaClosestInitiatorNode(ULONG TargetNodeNumber, ULONG *InitiatorNodeNumber);

#define WIN32_MEMORY_NUMA_PERFORMANCE_ALL_TARGET_NODE 0xffffffff
#define WIN32_MEMORY_NUMA_PERFORMANCE_READ_LATENCY    0x1
#define WIN32_MEMORY_NUMA_PERFORMANCE_READ_BANDWIDTH  0x2
#define WIN32_MEMORY_NUMA_PERFORMANCE_WRITE_LATENCY   0x4
#define WIN32_MEMORY_NUMA_PERFORMANCE_WRITE_BANDWIDTH 0x8

  typedef struct _WIN32_MEMORY_NUMA_PERFORMANCE_ENTRY
  {
    ULONG InitiatorNodeNumber;
    ULONG TargetNodeNumber;
    UCHAR DataType;
    struct
    {
      UCHAR MinTransferSizeToAchieveValues : 1;
      UCHAR NonSequentialTransfers         : 1;
      UCHAR Reserved                       : 6;
    } Flags;
    ULONGLONG MinTransferSizeInBytes;
    ULONGLONG EntryValue;
  } WIN32_MEMORY_NUMA_PERFORMANCE_ENTRY;

  typedef struct _WIN32_MEMORY_NUMA_PERFORMANCE_INFORMATION_OUTPUT
  {
    ULONG                               EntryCount;
    WIN32_MEMORY_NUMA_PERFORMANCE_ENTRY PerformanceEntries[ANYSIZE_ARRAY];
  } WIN32_MEMORY_NUMA_PERFORMANCE_INFORMATION_OUTPUT;

  WINBOOL WINAPI GetMemoryNumaPerformanceInformation(ULONG NodeNumber, UCHAR DataType, WIN32_MEMORY_NUMA_PERFORMANCE_INFORMATION_OUTPUT **PerfInfo);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#if WINAPI_PARTITION_APP && !(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  FORCEINLINE
  HANDLE WINAPI CreateFileMappingW(HANDLE hFile, LPSECURITY_ATTRIBUTES lpFileMappingAttributes, DWORD flProtect, DWORD dwMaximumSizeHigh, DWORD dwMaximumSizeLow, LPCWSTR lpName)
  {
    return CreateFileMappingFromApp(hFile, lpFileMappingAttributes, flProtect, (((ULONG64)dwMaximumSizeHigh) << 32) | dwMaximumSizeLow, lpName);
  }
#define CreateFileMapping CreateFileMappingW

  FORCEINLINE
  LPVOID WINAPI MapViewOfFile(HANDLE hFileMappingObject, DWORD dwDesiredAccess, DWORD dwFileOffsetHigh, DWORD dwFileOffsetLow, SIZE_T dwNumberOfBytesToMap)
  {
    return MapViewOfFileFromApp(hFileMappingObject, dwDesiredAccess, (((ULONG64)dwFileOffsetHigh) << 32) | dwFileOffsetLow, dwNumberOfBytesToMap);
  }

  FORCEINLINE
  LPVOID WINAPI VirtualAlloc(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect)
  {
    return VirtualAllocFromApp(lpAddress, dwSize, flAllocationType, flProtect);
  }

  FORCEINLINE
  WINBOOL WINAPI VirtualProtect(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpflOldProtect)
  {
    return VirtualProtectFromApp(lpAddress, dwSize, flNewProtect, lpflOldProtect);
  }

  FORCEINLINE
  HANDLE WINAPI OpenFileMappingW(DWORD dwDesiredAccess, WINBOOL bInheritHandle, LPCWSTR lpName)
  {
    return OpenFileMappingFromApp(dwDesiredAccess, bInheritHandle, lpName);
  }
#define OpenFileMapping OpenFileMappingW

#endif  /* WINAPI_PARTITION_APP && !(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#ifdef __cplusplus
}
#endif

#endif  /* _MEMORYAPI_H_ */
