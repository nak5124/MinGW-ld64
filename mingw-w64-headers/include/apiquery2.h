/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _APIQUERY2_H_
#define _APIQUERY2_H_

#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>

#undef APICONTRACT
#ifdef API_QUERY_IMPORT
# define APICONTRACT DECLSPEC_IMPORT
#else
# define APICONTRACT
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  APICONTRACT WINBOOL APIENTRY IsApiSetImplemented(PCSTR Contract);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#ifdef __cplusplus
}
#endif

#endif  /* _APIQUERY2_H_ */
