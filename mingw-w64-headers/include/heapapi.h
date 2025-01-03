/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _HEAPAPI_H_
#define _HEAPAPI_H_

#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>
#include <minwinbase.h>

#define DECLSPEC_ALLOCATOR

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  typedef struct _HEAP_SUMMARY
  {
    DWORD  cb;
    SIZE_T cbAllocated;
    SIZE_T cbCommitted;
    SIZE_T cbReserved;
    SIZE_T cbMaxReserve;
  } HEAP_SUMMARY, *PHEAP_SUMMARY;
  typedef PHEAP_SUMMARY LPHEAP_SUMMARY;

  WINBASEAPI HANDLE  WINAPI HeapCreate(DWORD flOptions, SIZE_T dwInitialSize, SIZE_T dwMaximumSize);
  WINBASEAPI WINBOOL WINAPI HeapDestroy(HANDLE hHeap);
  WINBASEAPI LPVOID  WINAPI HeapAlloc(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes) DECLSPEC_ALLOCATOR;
  WINBASEAPI LPVOID  WINAPI HeapReAlloc(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem, SIZE_T dwBytes) DECLSPEC_ALLOCATOR;
  WINBASEAPI WINBOOL WINAPI HeapFree(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem);
  WINBASEAPI SIZE_T  WINAPI HeapSize(HANDLE hHeap, DWORD dwFlags, LPCVOID lpMem);
  WINBASEAPI HANDLE  WINAPI GetProcessHeap(VOID);
  WINBASEAPI SIZE_T  WINAPI HeapCompact(HANDLE hHeap, DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI HeapSetInformation(HANDLE HeapHandle, HEAP_INFORMATION_CLASS HeapInformationClass, PVOID HeapInformation, SIZE_T HeapInformationLength);
  WINBASEAPI DWORD   WINAPI GetProcessHeaps(DWORD NumberOfHeaps, PHANDLE ProcessHeaps);
  WINBASEAPI WINBOOL WINAPI HeapLock(HANDLE hHeap);
  WINBASEAPI WINBOOL WINAPI HeapUnlock(HANDLE hHeap);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  WINBASEAPI WINBOOL WINAPI HeapValidate(HANDLE hHeap, DWORD dwFlags, LPCVOID lpMem);
  WINBASEAPI WINBOOL WINAPI HeapWalk(HANDLE hHeap, LPPROCESS_HEAP_ENTRY lpEntry);
  WINBASEAPI WINBOOL WINAPI HeapQueryInformation(HANDLE HeapHandle, HEAP_INFORMATION_CLASS HeapInformationClass, PVOID HeapInformation, SIZE_T HeapInformationLength, PSIZE_T ReturnLength);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)

  WINBOOL WINAPI HeapSummary(HANDLE hHeap, DWORD dwFlags, LPHEAP_SUMMARY lpSummary);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */

#ifdef __cplusplus
}
#endif

#endif  /* _HEAPAPI_H_ */
