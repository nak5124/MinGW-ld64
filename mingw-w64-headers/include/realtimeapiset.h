/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _APISETREALTIME_
#define _APISETREALTIME_

#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  WINBASEAPI WINBOOL WINAPI QueryThreadCycleTime(HANDLE ThreadHandle, PULONG64 CycleTime);
  WINBASEAPI WINBOOL WINAPI QueryProcessCycleTime(HANDLE ProcessHandle, PULONG64 CycleTime);
  WINBASEAPI WINBOOL WINAPI QueryIdleProcessorCycleTime(PULONG BufferLength, PULONG64 ProcessorIdleCycleTime);
  WINBASEAPI WINBOOL WINAPI QueryIdleProcessorCycleTimeEx(USHORT Group, PULONG BufferLength, PULONG64 ProcessorIdleCycleTime);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

  WINBASEAPI VOID    WINAPI QueryInterruptTimePrecise(PULONGLONG lpInterruptTimePrecise);
  WINBASEAPI VOID    WINAPI QueryUnbiasedInterruptTimePrecise(PULONGLONG lpUnbiasedInterruptTimePrecise);
  WINBASEAPI VOID    WINAPI QueryInterruptTime(PULONGLONG lpInterruptTime);
  WINBASEAPI WINBOOL WINAPI QueryUnbiasedInterruptTime(PULONGLONG UnbiasedTime);
  WINBASEAPI HRESULT WINAPI QueryAuxiliaryCounterFrequency(PULONGLONG lpAuxiliaryCounterFrequency);
  WINBASEAPI HRESULT WINAPI ConvertAuxiliaryCounterToPerformanceCounter(ULONGLONG ullAuxiliaryCounterValue, PULONGLONG lpPerformanceCounterValue, PULONGLONG lpConversionError);
  WINBASEAPI HRESULT WINAPI ConvertPerformanceCounterToAuxiliaryCounter(ULONGLONG ullPerformanceCounterValue, PULONGLONG lpAuxiliaryCounterValue, PULONGLONG lpConversionError);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */

#ifdef __cplusplus
}
#endif

#endif  /* _APISETREALTIME_ */
