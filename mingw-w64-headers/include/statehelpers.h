/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _CORESTATEHELPERSAPIS_H_
#define _CORESTATEHELPERSAPIS_H_

#include <apiset.h>
#include <apisetcconv.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  WINBASEAPI LSTATUS WINAPI GetRegistryValueWithFallbackW(HKEY hkeyPrimary, LPCWSTR pwszPrimarySubKey, HKEY hkeyFallback, LPCWSTR pwszFallbackSubKey, PCWSTR pwszValue, DWORD dwFlags,
    LPDWORD pdwType, PVOID pvData, DWORD cbDataIn, LPDWORD pcbDataOut);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#ifdef __cplusplus
}
#endif

#endif  /* _CORESTATEHELPERSAPIS_H_ */
