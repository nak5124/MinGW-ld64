/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _SYSTEMTOPOLOGY_H_
#define _SYSTEMTOPOLOGY_H_

#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>
#include <minwinbase.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  WINBASEAPI WINBOOL WINAPI GetNumaHighestNodeNumber(PULONG HighestNodeNumber);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  WINBASEAPI WINBOOL WINAPI GetNumaNodeProcessorMaskEx(USHORT Node, PGROUP_AFFINITY ProcessorMask);
  WINBASEAPI WINBOOL WINAPI GetNumaNodeProcessorMask2(USHORT NodeNumber, PGROUP_AFFINITY ProcessorMasks, USHORT ProcessorMaskCount, PUSHORT RequiredMaskCount);
  WINBASEAPI WINBOOL WINAPI GetNumaProximityNodeEx(ULONG ProximityId, PUSHORT NodeNumber);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#ifdef __cplusplus
}
#endif

#endif  /* _SYSTEMTOPOLOGY_H_ */
