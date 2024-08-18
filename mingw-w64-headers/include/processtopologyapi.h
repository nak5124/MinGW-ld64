 /**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _PROCESSTOPOLOGYAPI_H_
#define _PROCESSTOPOLOGYAPI_H_

#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>
#include <minwinbase.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  WINBASEAPI WINBOOL WINAPI GetProcessGroupAffinity(HANDLE hProcess, PUSHORT GroupCount, PUSHORT GroupArray);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  WINBASEAPI WINBOOL WINAPI GetThreadGroupAffinity(HANDLE hThread, PGROUP_AFFINITY GroupAffinity);
  WINBASEAPI WINBOOL WINAPI SetThreadGroupAffinity(HANDLE hThread, CONST GROUP_AFFINITY *GroupAffinity, PGROUP_AFFINITY PreviousGroupAffinity);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#ifdef __cplusplus
}
#endif

#endif  /* _PROCESSTOPOLOGYAPI_H_ */
