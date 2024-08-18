/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _SYSINFOAPI_H_
#define _SYSINFOAPI_H_

#include <_mingw_unicode.h>
#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>
#include <minwinbase.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  typedef struct _SYSTEM_INFO
  {
    __C89_NAMELESS union
    {
      DWORD dwOemId;
      __C89_NAMELESS struct
      {
        WORD wProcessorArchitecture;
        WORD wReserved;
      } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME;
    DWORD     dwPageSize;
    LPVOID    lpMinimumApplicationAddress;
    LPVOID    lpMaximumApplicationAddress;
    DWORD_PTR dwActiveProcessorMask;
    DWORD     dwNumberOfProcessors;
    DWORD     dwProcessorType;
    DWORD     dwAllocationGranularity;
    WORD      wProcessorLevel;
    WORD      wProcessorRevision;
  } SYSTEM_INFO, *LPSYSTEM_INFO;

  typedef struct _MEMORYSTATUSEX
  {
    DWORD     dwLength;
    DWORD     dwMemoryLoad;
    DWORDLONG ullTotalPhys;
    DWORDLONG ullAvailPhys;
    DWORDLONG ullTotalPageFile;
    DWORDLONG ullAvailPageFile;
    DWORDLONG ullTotalVirtual;
    DWORDLONG ullAvailVirtual;
    DWORDLONG ullAvailExtendedVirtual;
  } MEMORYSTATUSEX, *LPMEMORYSTATUSEX;

#define USER_CET_ENVIRONMENT_WIN32_PROCESS     0x00000000
#define USER_CET_ENVIRONMENT_SGX2_ENCLAVE      0x00000002
#define USER_CET_ENVIRONMENT_VBS_ENCLAVE       0x00000010
#define USER_CET_ENVIRONMENT_VBS_BASIC_ENCLAVE 0x00000011

  WINBASEAPI WINBOOL   WINAPI GlobalMemoryStatusEx(LPMEMORYSTATUSEX lpBuffer);
  WINBASEAPI VOID      WINAPI GetSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI VOID      WINAPI GetSystemTime(LPSYSTEMTIME lpSystemTime);
  WINBASEAPI VOID      WINAPI GetSystemTimeAsFileTime(LPFILETIME lpSystemTimeAsFileTime);
  WINBASEAPI VOID      WINAPI GetLocalTime(LPSYSTEMTIME lpSystemTime);
  WINBASEAPI WINBOOL   WINAPI IsUserCetAvailableInEnvironment(DWORD UserCetEnvironment);
  WINBASEAPI DWORD     WINAPI GetTickCount(VOID);
  WINBASEAPI ULONGLONG WINAPI GetTickCount64(VOID);
  WINBASEAPI UINT      WINAPI GetSystemDirectoryA(LPSTR lpBuffer, UINT uSize);
  WINBASEAPI UINT      WINAPI GetSystemDirectoryW(LPWSTR lpBuffer, UINT uSize);
#define GetSystemDirectory __MINGW_NAME_AW(GetSystemDirectory)
  WINBASEAPI UINT      WINAPI GetSystemWindowsDirectoryA(LPSTR lpBuffer, UINT uSize);
  WINBASEAPI UINT      WINAPI GetSystemWindowsDirectoryW(LPWSTR lpBuffer, UINT uSize);
#define GetSystemWindowsDirectory __MINGW_NAME_AW(GetSystemWindowsDirectory)
  WINBASEAPI WINBOOL   WINAPI GetVersionExA(LPOSVERSIONINFOA lpVersionInformation);
  WINBASEAPI WINBOOL   WINAPI GetVersionExW(LPOSVERSIONINFOW lpVersionInformation);
#define GetVersionEx __MINGW_NAME_AW(GetVersionEx)
  WINBASEAPI WINBOOL   WINAPI GetLogicalProcessorInformation(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION Buffer, PDWORD ReturnedLength);
  WINBASEAPI WINBOOL   WINAPI GetLogicalProcessorInformationEx(LOGICAL_PROCESSOR_RELATIONSHIP RelationshipType, PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX Buffer, PDWORD ReturnedLength);
  WINBASEAPI VOID      WINAPI GetNativeSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI VOID      WINAPI GetSystemTimePreciseAsFileTime(LPFILETIME lpSystemTimeAsFileTime);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

  WINBASEAPI WINBOOL WINAPI GetSystemLeapSecondInformation(PBOOL Enabled, PDWORD Flags);
  WINBASEAPI WINBOOL WINAPI GetProductInfo(DWORD dwOSMajorVersion, DWORD dwOSMinorVersion, DWORD dwSpMajorVersion, DWORD dwSpMinorVersion, PDWORD pdwReturnedProductType);
  WINBASEAPI UINT    WINAPI EnumSystemFirmwareTables(DWORD FirmwareTableProviderSignature, PVOID pFirmwareTableEnumBuffer, DWORD BufferSize);
  WINBASEAPI UINT    WINAPI GetSystemFirmwareTable(DWORD FirmwareTableProviderSignature, DWORD FirmwareTableID, PVOID pFirmwareTableBuffer, DWORD BufferSize);
  WINBASEAPI HRESULT WINAPI GetIntegratedDisplaySize(double *sizeInInches);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  WINBASEAPI DWORD   WINAPI GetVersion(VOID);
  WINBASEAPI WINBOOL WINAPI SetLocalTime(CONST SYSTEMTIME *lpSystemTime);
  WINBASEAPI WINBOOL WINAPI GetSystemTimeAdjustment(PDWORD lpTimeAdjustment, PDWORD lpTimeIncrement, PBOOL lpTimeAdjustmentDisabled);
  WINBASEAPI UINT    WINAPI GetWindowsDirectoryA(LPSTR lpBuffer, UINT uSize);
  WINBASEAPI UINT    WINAPI GetWindowsDirectoryW(LPWSTR lpBuffer, UINT uSize);
#define GetWindowsDirectory __MINGW_NAME_AW(GetWindowsDirectory)

  typedef enum _COMPUTER_NAME_FORMAT
  {
    ComputerNameNetBIOS,
    ComputerNameDnsHostname,
    ComputerNameDnsDomain,
    ComputerNameDnsFullyQualified,
    ComputerNamePhysicalNetBIOS,
    ComputerNamePhysicalDnsHostname,
    ComputerNamePhysicalDnsDomain,
    ComputerNamePhysicalDnsFullyQualified,
    ComputerNameMax
  } COMPUTER_NAME_FORMAT;

  WINBASEAPI WINBOOL WINAPI GetComputerNameExA(COMPUTER_NAME_FORMAT NameType, LPSTR lpBuffer, LPDWORD nSize);
  WINBASEAPI WINBOOL WINAPI GetComputerNameExW(COMPUTER_NAME_FORMAT NameType, LPWSTR lpBuffer, LPDWORD nSize);
#define GetComputerNameEx __MINGW_NAME_AW(GetComputerNameEx)

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  WINBASEAPI WINBOOL WINAPI GetSystemTimeAdjustmentPrecise(PDWORD64 lpTimeAdjustment, PDWORD64 lpTimeIncrement, PBOOL lpTimeAdjustmentDisabled);
  WINBASEAPI WINBOOL WINAPI SetComputerNameExW(COMPUTER_NAME_FORMAT NameType, LPCWSTR lpBuffer);
#ifdef UNICODE
# define SetComputerNameEx SetComputerNameExW
#endif
  WINBASEAPI WINBOOL   WINAPI SetSystemTime(CONST SYSTEMTIME *lpSystemTime);
  NTSYSAPI   ULONGLONG NTAPI  VerSetConditionMask(ULONGLONG ConditionMask, ULONG TypeMask, UCHAR Condition);
  WINBASEAPI WINBOOL   WINAPI GetOsSafeBootMode(PDWORD Flags);
  WINBASEAPI WINBOOL   WINAPI DnsHostnameToComputerNameExW(LPCWSTR Hostname, LPWSTR ComputerName, LPDWORD nSize);
  WINBASEAPI WINBOOL   WINAPI GetPhysicallyInstalledSystemMemory(PULONGLONG TotalMemoryInKilobytes);

#define SCEX2_ALT_NETBIOS_NAME 0x00000001

  WINBASEAPI WINBOOL   WINAPI SetComputerNameEx2W(COMPUTER_NAME_FORMAT NameType, DWORD Flags, LPCWSTR lpBuffer);
#ifdef UNICODE
# define SetComputerNameEx2 SetComputerNameEx2W
#endif
  WINBASEAPI WINBOOL   WINAPI SetSystemTimeAdjustment(DWORD dwTimeAdjustment, WINBOOL bTimeAdjustmentDisabled);
  WINBASEAPI WINBOOL   WINAPI SetSystemTimeAdjustmentPrecise(DWORD64 dwTimeAdjustment, WINBOOL bTimeAdjustmentDisabled);
  WINBASEAPI WINBOOL   WINAPI InstallELAMCertificateInfo(HANDLE ELAMFile);
  WINBASEAPI WINBOOL   WINAPI GetOsManufacturingMode(PBOOL pbEnabled);
  WINBASEAPI WINBOOL   WINAPI SetComputerNameA(LPCSTR lpComputerName);
  WINBASEAPI WINBOOL   WINAPI SetComputerNameW(LPCWSTR lpComputerName);
#define SetComputerName __MINGW_NAME_AW(SetComputerName)
  WINBASEAPI WINBOOL   WINAPI SetComputerNameExA(COMPUTER_NAME_FORMAT NameType, LPCSTR lpBuffer);
#ifndef UNICODE
# define SetComputerNameEx SetComputerNameExA
#endif

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

  WINBASEAPI WINBOOL WINAPI GetProcessorSystemCycleTime(USHORT Group, PSYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION Buffer, PDWORD ReturnedLength);

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

  typedef enum DEVELOPER_DRIVE_ENABLEMENT_STATE
  {
    DeveloperDriveEnablementStateError,
    DeveloperDriveEnabled,
    DeveloperDriveDisabledBySystemPolicy,
    DeveloperDriveDisabledByGroupPolicy
  } DEVELOPER_DRIVE_ENABLEMENT_STATE;

  WINBASEAPI DEVELOPER_DRIVE_ENABLEMENT_STATE WINAPI GetDeveloperDriveEnablementState(VOID);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */

#ifdef __cplusplus
}
#endif

#endif  /* _SYSINFOAPI_H_ */
