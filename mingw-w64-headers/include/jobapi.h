/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _JOBAPISET_H_
#define _JOBAPISET_H_

#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>
#include <minwinbase.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  WINBASEAPI WINBOOL WINAPI IsProcessInJob(HANDLE ProcessHandle, HANDLE JobHandle, PBOOL Result);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#ifdef __cplusplus
}
#endif

#endif  /* _JOBAPISET_H_ */
