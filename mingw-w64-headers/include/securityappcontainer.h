/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _APIAPPCONTAINER_
#define _APIAPPCONTAINER_

#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>
#include <minwinbase.h>

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

#ifdef __cplusplus
extern "C" {
#endif

  WINBOOL WINAPI GetAppContainerNamedObjectPath(HANDLE Token, PSID AppContainerSid, ULONG ObjectPathLength, LPWSTR ObjectPath, PULONG ReturnLength);

#ifdef __cplusplus
}
#endif

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#endif  /* _APIAPPCONTAINER_ */
