/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INTERLOCKAPI_H_
#define _INTERLOCKAPI_H_

#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#ifndef NOWINBASEINTERLOCK
#ifdef _SLIST_HEADER_
  WINBASEAPI VOID         WINAPI InitializeSListHead(PSLIST_HEADER ListHead);
  WINBASEAPI PSLIST_ENTRY WINAPI InterlockedPopEntrySList(PSLIST_HEADER ListHead);
  WINBASEAPI PSLIST_ENTRY WINAPI InterlockedPushEntrySList(PSLIST_HEADER ListHead, PSLIST_ENTRY ListEntry);
  WINBASEAPI PSLIST_ENTRY WINAPI InterlockedPushListSListEx(PSLIST_HEADER ListHead, PSLIST_ENTRY List, PSLIST_ENTRY ListEnd, ULONG Count);
#define InterlockedPushListSList InterlockedPushListSListEx
  WINBASEAPI PSLIST_ENTRY WINAPI InterlockedFlushSList(PSLIST_HEADER ListHead);
  WINBASEAPI USHORT       WINAPI QueryDepthSList(PSLIST_HEADER ListHead);
#endif  /* _SLIST_HEADER_ */
#endif  /* NOWINBASEINTERLOCK */

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#ifdef __cplusplus
}
#endif

#endif  /* _INTERLOCKAPI_H_ */
