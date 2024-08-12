/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CSCAPI
#define _INC_CSCAPI
#include <windows.h>
#ifdef __cplusplus
extern "C" {
#endif

DWORD OfflineFilesEnable(
  WINBOOL bEnable,
  WINBOOL *pbRebootRequired
);
DWORD OfflineFilesQueryStatus(
  WINBOOL *pbActive,
  WINBOOL *pbEnabled
);

#ifdef __cplusplus
}
#endif
#endif /*_INC_CSCAPI*/
