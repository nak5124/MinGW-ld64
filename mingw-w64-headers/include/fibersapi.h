/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _FIBERS_H_
#define _FIBERS_H_

#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#ifndef FLS_OUT_OF_INDEXES
# define FLS_OUT_OF_INDEXES ((DWORD)0xFFFFFFFF)
#endif

  WINBASEAPI DWORD   WINAPI FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback);
  WINBASEAPI PVOID   WINAPI FlsGetValue(DWORD dwFlsIndex);
  WINBASEAPI WINBOOL WINAPI FlsSetValue(DWORD dwFlsIndex, PVOID lpFlsData);
  WINBASEAPI WINBOOL WINAPI FlsFree(DWORD dwFlsIndex);
  WINBASEAPI WINBOOL WINAPI IsThreadAFiber(VOID);
  WINBASEAPI PVOID   WINAPI FlsGetValue2(DWORD dwTlsIndex);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#ifdef __cplusplus
}
#endif

#endif  /* _FIBERS_H_ */
