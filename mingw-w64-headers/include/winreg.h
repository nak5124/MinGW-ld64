/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _WINREG_
#define _WINREG_

#include <_mingw_unicode.h>
#include <winapifamily.h>

#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>
#include <minwinbase.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

#ifndef WINVER
# define WINVER 0x0A00
#endif

#define RRF_RT_REG_NONE       0x00000001
#define RRF_RT_REG_SZ         0x00000002
#define RRF_RT_REG_EXPAND_SZ  0x00000004
#define RRF_RT_REG_BINARY     0x00000008
#define RRF_RT_REG_DWORD      0x00000010
#define RRF_RT_REG_MULTI_SZ   0x00000020
#define RRF_RT_REG_QWORD      0x00000040
#define RRF_RT_DWORD          (RRF_RT_REG_BINARY | RRF_RT_REG_DWORD)
#define RRF_RT_QWORD          (RRF_RT_REG_BINARY | RRF_RT_REG_QWORD)
#define RRF_RT_ANY            0x0000ffff
#define RRF_SUBKEY_WOW6464KEY 0x00010000
#define RRF_SUBKEY_WOW6432KEY 0x00020000
#define RRF_WOW64_MASK        0x00030000
#define RRF_NOEXPAND          0x10000000
#define RRF_ZEROONFAILURE     0x20000000

#define REG_PROCESS_APPKEY               0x00000001
#define REG_USE_CURRENT_SECURITY_CONTEXT 0x00000002

#ifndef _PROVIDER_STRUCTS_DEFINED
#define _PROVIDER_STRUCTS_DEFINED

#define PROVIDER_KEEPS_VALUE_LENGTH 0x1

  struct val_context
  {
    int    valuelen;
    LPVOID value_context;
    LPVOID val_buff_ptr;
  };

  typedef struct val_context FAR *PVALCONTEXT;

  typedef struct pvalueA
  {
    LPSTR  pv_valuename;
    int    pv_valuelen;
    LPVOID pv_value_context;
    DWORD  pv_type;
  } PVALUEA, FAR *PPVALUEA;

  typedef struct pvalueW
  {
    LPWSTR pv_valuename;
    int    pv_valuelen;
    LPVOID pv_value_context;
    DWORD  pv_type;
  } PVALUEW, FAR *PPVALUEW;

  __MINGW_TYPEDEF_AW(PVALUE)
  __MINGW_TYPEDEF_AW(PPVALUE)

  typedef DWORD __cdecl QUERYHANDLER(LPVOID keycontext, PVALCONTEXT val_list, DWORD num_vals, LPVOID outputbuffer, DWORD FAR *total_outlen, DWORD input_blen);

  typedef QUERYHANDLER FAR *PQUERYHANDLER;

  typedef struct provider_info
  {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    DWORD         pi_flags;
    LPVOID        pi_key_context;
  } REG_PROVIDER;

  typedef struct provider_info FAR *PPROVIDER;

  typedef struct value_entA
  {
    LPSTR     ve_valuename;
    DWORD     ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD     ve_type;
  } VALENTA, FAR *PVALENTA;

  typedef struct value_entW
  {
    LPWSTR    ve_valuename;
    DWORD     ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD     ve_type;
  } VALENTW, FAR *PVALENTW;

  __MINGW_TYPEDEF_AW(VALENT)
  __MINGW_TYPEDEF_AW(PVALENT)

#endif  /* _PROVIDER_STRUCTS_DEFINED */

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  typedef LONG        LSTATUS;
  typedef ACCESS_MASK REGSAM;

#define HKEY_CLASSES_ROOT                ((HKEY)(ULONG_PTR)((LONG)0x80000000))
#define HKEY_CURRENT_USER                ((HKEY)(ULONG_PTR)((LONG)0x80000001))
#define HKEY_LOCAL_MACHINE               ((HKEY)(ULONG_PTR)((LONG)0x80000002))
#define HKEY_USERS                       ((HKEY)(ULONG_PTR)((LONG)0x80000003))
#define HKEY_PERFORMANCE_DATA            ((HKEY)(ULONG_PTR)((LONG)0x80000004))
#define HKEY_PERFORMANCE_TEXT            ((HKEY)(ULONG_PTR)((LONG)0x80000050))
#define HKEY_PERFORMANCE_NLSTEXT         ((HKEY)(ULONG_PTR)((LONG)0x80000060))
#define HKEY_CURRENT_CONFIG              ((HKEY)(ULONG_PTR)((LONG)0x80000005))
#define HKEY_DYN_DATA                    ((HKEY)(ULONG_PTR)((LONG)0x80000006))
#define HKEY_CURRENT_USER_LOCAL_SETTINGS ((HKEY)(ULONG_PTR)((LONG)0x80000007))

#define WIN31_CLASS NULL

#define REG_MUI_STRING_TRUNCATE 0x00000001

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

#define REG_SECURE_CONNECTION 1

  WINADVAPI LSTATUS APIENTRY RegConnectRegistryExA(LPCSTR lpMachineName, HKEY hKey, ULONG Flags, PHKEY phkResult);
  WINADVAPI LSTATUS APIENTRY RegConnectRegistryExW(LPCWSTR lpMachineName, HKEY hKey, ULONG Flags, PHKEY phkResult);
#define RegConnectRegistryEx __MINGW_NAME_AW(RegConnectRegistryEx)
  WINADVAPI LONG    APIENTRY RegDisableReflectionKey(HKEY hBase);
  WINADVAPI LONG    APIENTRY RegEnableReflectionKey(HKEY hBase);
  WINADVAPI LONG    APIENTRY RegQueryReflectionKey(HKEY hBase, WINBOOL *bIsReflectionDisabled);
  WINADVAPI LSTATUS APIENTRY RegRenameKey(HKEY hKey, LPCWSTR lpSubKeyName, LPCWSTR lpNewKeyName);
  WINADVAPI WINBOOL APIENTRY InitiateSystemShutdownA(LPSTR lpMachineName, LPSTR lpMessage, DWORD dwTimeout, WINBOOL bForceAppsClosed, WINBOOL bRebootAfterShutdown);
  WINADVAPI WINBOOL APIENTRY InitiateSystemShutdownW(LPWSTR lpMachineName, LPWSTR lpMessage, DWORD dwTimeout, WINBOOL bForceAppsClosed, WINBOOL bRebootAfterShutdown);
#define InitiateSystemShutdown __MINGW_NAME_AW(InitiateSystemShutdown)
  WINADVAPI WINBOOL APIENTRY AbortSystemShutdownA(LPSTR lpMachineName);
  WINADVAPI WINBOOL APIENTRY AbortSystemShutdownW(LPWSTR lpMachineName);
#define AbortSystemShutdown __MINGW_NAME_AW(AbortSystemShutdown)

#include <reason.h>

#define REASON_SWINSTALL    (SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_INSTALLATION)
#define REASON_HWINSTALL    (SHTDN_REASON_MAJOR_HARDWARE|SHTDN_REASON_MINOR_INSTALLATION)
#define REASON_SERVICEHANG  (SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_HUNG)
#define REASON_UNSTABLE     (SHTDN_REASON_MAJOR_SYSTEM|SHTDN_REASON_MINOR_UNSTABLE)
#define REASON_SWHWRECONF   (SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_RECONFIG)
#define REASON_OTHER        (SHTDN_REASON_MAJOR_OTHER|SHTDN_REASON_MINOR_OTHER)
#define REASON_UNKNOWN      SHTDN_REASON_UNKNOWN
#define REASON_LEGACY_API   SHTDN_REASON_LEGACY_API
#define REASON_PLANNED_FLAG SHTDN_REASON_FLAG_PLANNED

#define MAX_SHUTDOWN_TIMEOUT (10 * 365 * 24 * 60 * 60)

  WINADVAPI WINBOOL APIENTRY InitiateSystemShutdownExA(LPSTR lpMachineName, LPSTR lpMessage, DWORD dwTimeout, WINBOOL bForceAppsClosed, WINBOOL bRebootAfterShutdown, DWORD dwReason);
  WINADVAPI WINBOOL APIENTRY InitiateSystemShutdownExW(LPWSTR lpMachineName, LPWSTR lpMessage, DWORD dwTimeout, WINBOOL bForceAppsClosed, WINBOOL bRebootAfterShutdown, DWORD dwReason);
#define InitiateSystemShutdownEx __MINGW_NAME_AW(InitiateSystemShutdownEx)

#define SHUTDOWN_FORCE_OTHERS          0x00000001
#define SHUTDOWN_FORCE_SELF            0x00000002
#define SHUTDOWN_RESTART               0x00000004
#define SHUTDOWN_POWEROFF              0x00000008
#define SHUTDOWN_NOREBOOT              0x00000010
#define SHUTDOWN_GRACE_OVERRIDE        0x00000020
#define SHUTDOWN_INSTALL_UPDATES       0x00000040
#define SHUTDOWN_RESTARTAPPS           0x00000080
#define SHUTDOWN_SKIP_SVC_PRESHUTDOWN  0x00000100
#define SHUTDOWN_HYBRID                0x00000200
#define SHUTDOWN_RESTART_BOOTOPTIONS   0x00000400
#define SHUTDOWN_SOFT_REBOOT           0x00000800
#define SHUTDOWN_MOBILE_UI             0x00001000
#define SHUTDOWN_ARSO                  0x00002000
#define SHUTDOWN_CHECK_SAFE_FOR_SERVER 0x00004000
#define SHUTDOWN_VAIL_CONTAINER        0x00008000
#define SHUTDOWN_SYSTEM_INITIATED      0x00010000

  WINADVAPI DWORD APIENTRY InitiateShutdownA(LPSTR lpMachineName, LPSTR lpMessage, DWORD dwGracePeriod, DWORD dwShutdownFlags, DWORD dwReason);
  WINADVAPI DWORD APIENTRY InitiateShutdownW(LPWSTR lpMachineName, LPWSTR lpMessage, DWORD dwGracePeriod, DWORD dwShutdownFlags, DWORD dwReason);
#define InitiateShutdown __MINGW_NAME_AW(InitiateShutdown)
  WINADVAPI DWORD APIENTRY CheckForHiberboot(PBOOLEAN pHiberboot, BOOLEAN bClearFlag);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  WINADVAPI LSTATUS APIENTRY RegCloseKey(HKEY hKey);
  WINADVAPI LSTATUS APIENTRY RegCreateKeyA(HKEY hKey, LPCSTR lpSubKey, PHKEY phkResult);
  WINADVAPI LSTATUS APIENTRY RegCreateKeyW(HKEY hKey, LPCWSTR lpSubKey, PHKEY phkResult);
#define RegCreateKey __MINGW_NAME_AW(RegCreateKey)
  WINADVAPI LSTATUS APIENTRY RegCreateKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass, DWORD dwOptions, REGSAM samDesired, LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition);
  WINADVAPI LSTATUS APIENTRY RegCreateKeyExW(HKEY hKey, LPCWSTR lpSubKey, DWORD Reserved, LPWSTR lpClass, DWORD dwOptions, REGSAM samDesired, LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition);
#define RegCreateKeyEx __MINGW_NAME_AW(RegCreateKeyEx)
  WINADVAPI LSTATUS APIENTRY RegDeleteKeyA(HKEY hKey, LPCSTR lpSubKey);
  WINADVAPI LSTATUS APIENTRY RegDeleteKeyW(HKEY hKey, LPCWSTR lpSubKey);
#define RegDeleteKey __MINGW_NAME_AW(RegDeleteKey)
  WINADVAPI LSTATUS APIENTRY RegDeleteKeyExA(HKEY hKey, LPCSTR lpSubKey, REGSAM samDesired, DWORD Reserved);
  WINADVAPI LSTATUS APIENTRY RegDeleteKeyExW(HKEY hKey, LPCWSTR lpSubKey, REGSAM samDesired, DWORD Reserved);
#define RegDeleteKeyEx __MINGW_NAME_AW(RegDeleteKeyEx)
  WINADVAPI LSTATUS APIENTRY RegDeleteValueA(HKEY hKey, LPCSTR lpValueName);
  WINADVAPI LSTATUS APIENTRY RegDeleteValueW(HKEY hKey, LPCWSTR lpValueName);
#define RegDeleteValue __MINGW_NAME_AW(RegDeleteValue)
  WINADVAPI LSTATUS APIENTRY RegEnumKeyA(HKEY hKey, DWORD dwIndex, LPSTR lpName, DWORD cchName);
  WINADVAPI LSTATUS APIENTRY RegEnumKeyW(HKEY hKey, DWORD dwIndex, LPWSTR lpName, DWORD cchName);
#define RegEnumKey __MINGW_NAME_AW(RegEnumKey)
  WINADVAPI LSTATUS APIENTRY RegEnumKeyExA(HKEY hKey, DWORD dwIndex, LPSTR lpName, LPDWORD lpcchName, LPDWORD lpReserved, LPSTR lpClass, LPDWORD lpcchClass, PFILETIME lpftLastWriteTime);
  WINADVAPI LSTATUS APIENTRY RegEnumKeyExW(HKEY hKey, DWORD dwIndex, LPWSTR lpName, LPDWORD lpcchName, LPDWORD lpReserved, LPWSTR lpClass, LPDWORD lpcchClass, PFILETIME lpftLastWriteTime);
#define RegEnumKeyEx __MINGW_NAME_AW(RegEnumKeyEx)
  WINADVAPI LSTATUS APIENTRY RegEnumValueA(HKEY hKey, DWORD dwIndex, LPSTR lpValueName, LPDWORD lpcchValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
  WINADVAPI LSTATUS APIENTRY RegEnumValueW(HKEY hKey, DWORD dwIndex, LPWSTR lpValueName, LPDWORD lpcchValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
#define RegEnumValue __MINGW_NAME_AW(RegEnumValue)
  WINADVAPI LSTATUS APIENTRY RegOpenKeyA(HKEY hKey, LPCSTR lpSubKey, PHKEY phkResult);
  WINADVAPI LSTATUS APIENTRY RegOpenKeyW(HKEY hKey, LPCWSTR lpSubKey, PHKEY phkResult);
#define RegOpenKey __MINGW_NAME_AW(RegOpenKey)
  WINADVAPI LSTATUS APIENTRY RegOpenKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult);
  WINADVAPI LSTATUS APIENTRY RegOpenKeyExW(HKEY hKey, LPCWSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult);
#define RegOpenKeyEx __MINGW_NAME_AW(RegOpenKeyEx)
  WINADVAPI LSTATUS APIENTRY RegQueryInfoKeyA(HKEY hKey, LPSTR lpClass, LPDWORD lpcchClass, LPDWORD lpReserved, LPDWORD lpcSubKeys, LPDWORD lpcbMaxSubKeyLen, LPDWORD lpcbMaxClassLen, LPDWORD lpcValues, LPDWORD lpcbMaxValueNameLen, LPDWORD lpcbMaxValueLen, LPDWORD lpcbSecurityDescriptor, PFILETIME lpftLastWriteTime);
  WINADVAPI LSTATUS APIENTRY RegQueryInfoKeyW(HKEY hKey, LPWSTR lpClass, LPDWORD lpcchClass, LPDWORD lpReserved, LPDWORD lpcSubKeys, LPDWORD lpcbMaxSubKeyLen, LPDWORD lpcbMaxClassLen, LPDWORD lpcValues, LPDWORD lpcbMaxValueNameLen, LPDWORD lpcbMaxValueLen, LPDWORD lpcbSecurityDescriptor, PFILETIME lpftLastWriteTime);
#define RegQueryInfoKey __MINGW_NAME_AW(RegQueryInfoKey)
  WINADVAPI LSTATUS APIENTRY RegQueryValueExA(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
  WINADVAPI LSTATUS APIENTRY RegQueryValueExW(HKEY hKey, LPCWSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
#define RegQueryValueEx __MINGW_NAME_AW(RegQueryValueEx)
  WINADVAPI LSTATUS APIENTRY RegSetValueExA(HKEY hKey, LPCSTR lpValueName, DWORD Reserved, DWORD dwType, CONST BYTE *lpData, DWORD cbData);
  WINADVAPI LSTATUS APIENTRY RegSetValueExW(HKEY hKey, LPCWSTR lpValueName, DWORD Reserved, DWORD dwType, CONST BYTE *lpData, DWORD cbData);
#define RegSetValueEx __MINGW_NAME_AW(RegSetValueEx)

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

  WINADVAPI LSTATUS APIENTRY RegOverridePredefKey(HKEY hKey, HKEY hNewHKey);
  WINADVAPI LSTATUS APIENTRY RegOpenUserClassesRoot(HANDLE hToken, DWORD dwOptions, REGSAM samDesired, PHKEY phkResult);
  WINADVAPI LSTATUS APIENTRY RegOpenCurrentUser(REGSAM samDesired, PHKEY phkResult);
  WINADVAPI LSTATUS APIENTRY RegDisablePredefinedCache(VOID);
  WINADVAPI LSTATUS APIENTRY RegDisablePredefinedCacheEx(VOID);
  WINADVAPI LSTATUS APIENTRY RegConnectRegistryA(LPCSTR lpMachineName, HKEY hKey, PHKEY phkResult);
  WINADVAPI LSTATUS APIENTRY RegConnectRegistryW(LPCWSTR lpMachineName, HKEY hKey, PHKEY phkResult);
#define RegConnectRegistry __MINGW_NAME_AW(RegConnectRegistry)
  WINADVAPI LSTATUS APIENTRY RegCreateKeyTransactedA(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass, DWORD dwOptions, REGSAM samDesired, CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition, HANDLE hTransaction, PVOID pExtendedParemeter);
  WINADVAPI LSTATUS APIENTRY RegCreateKeyTransactedW(HKEY hKey, LPCWSTR lpSubKey, DWORD Reserved, LPWSTR lpClass, DWORD dwOptions, REGSAM samDesired, CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition, HANDLE hTransaction, PVOID pExtendedParemeter);
#define RegCreateKeyTransacted __MINGW_NAME_AW(RegCreateKeyTransacted)
  WINADVAPI LSTATUS APIENTRY RegDeleteKeyTransactedA(HKEY hKey, LPCSTR lpSubKey, REGSAM samDesired, DWORD Reserved, HANDLE hTransaction, PVOID pExtendedParameter);
  WINADVAPI LSTATUS APIENTRY RegDeleteKeyTransactedW(HKEY hKey, LPCWSTR lpSubKey, REGSAM samDesired, DWORD Reserved, HANDLE hTransaction, PVOID pExtendedParameter);
#define RegDeleteKeyTransacted __MINGW_NAME_AW(RegDeleteKeyTransacted)
  WINADVAPI LSTATUS APIENTRY RegFlushKey(HKEY hKey);
  WINADVAPI LSTATUS APIENTRY RegGetKeySecurity(HKEY hKey, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor, LPDWORD lpcbSecurityDescriptor);
  WINADVAPI LSTATUS APIENTRY RegLoadKeyA(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpFile);
  WINADVAPI LSTATUS APIENTRY RegLoadKeyW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpFile);
#define RegLoadKey __MINGW_NAME_AW(RegLoadKey)
  WINADVAPI LSTATUS APIENTRY RegNotifyChangeKeyValue(HKEY hKey, WINBOOL bWatchSubtree, DWORD dwNotifyFilter, HANDLE hEvent, WINBOOL fAsynchronous);
  WINADVAPI LSTATUS APIENTRY RegOpenKeyTransactedA(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult, HANDLE hTransaction, PVOID pExtendedParameter);
  WINADVAPI LSTATUS APIENTRY RegOpenKeyTransactedW(HKEY hKey, LPCWSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult, HANDLE hTransaction, PVOID pExtendedParameter);
#define RegOpenKeyTransacted __MINGW_NAME_AW(RegOpenKeyTransacted)
  WINADVAPI LSTATUS APIENTRY RegQueryValueA(HKEY hKey, LPCSTR lpSubKey, LPSTR lpData, PLONG lpcbData);
  WINADVAPI LSTATUS APIENTRY RegQueryValueW(HKEY hKey, LPCWSTR lpSubKey, LPWSTR lpData, PLONG lpcbData);
#define RegQueryValue __MINGW_NAME_AW(RegQueryValue)
  WINADVAPI LSTATUS APIENTRY RegQueryMultipleValuesA(HKEY hKey, PVALENTA val_list, DWORD num_vals, LPSTR lpValueBuf, LPDWORD ldwTotsize);
  WINADVAPI LSTATUS APIENTRY RegQueryMultipleValuesW(HKEY hKey, PVALENTW val_list, DWORD num_vals, LPWSTR lpValueBuf, LPDWORD ldwTotsize);
#define RegQueryMultipleValues __MINGW_NAME_AW(RegQueryMultipleValues)
  WINADVAPI LSTATUS APIENTRY RegReplaceKeyA(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpNewFile, LPCSTR lpOldFile);
  WINADVAPI LSTATUS APIENTRY RegReplaceKeyW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpNewFile, LPCWSTR lpOldFile);
#define RegReplaceKey __MINGW_NAME_AW(RegReplaceKey)
  WINADVAPI LSTATUS APIENTRY RegRestoreKeyA(HKEY hKey, LPCSTR lpFile, DWORD dwFlags);
  WINADVAPI LSTATUS APIENTRY RegRestoreKeyW(HKEY hKey, LPCWSTR lpFile, DWORD dwFlags);
#define RegRestoreKey __MINGW_NAME_AW(RegRestoreKey)
  WINADVAPI LSTATUS APIENTRY RegSaveKeyA(HKEY hKey, LPCSTR lpFile, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LSTATUS APIENTRY RegSaveKeyW(HKEY hKey, LPCWSTR lpFile, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
#define RegSaveKey __MINGW_NAME_AW(RegSaveKey)
  WINADVAPI LSTATUS APIENTRY RegSetKeySecurity(HKEY hKey, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI LSTATUS APIENTRY RegSetValueA(HKEY hKey, LPCSTR lpSubKey, DWORD dwType, LPCSTR lpData, DWORD cbData);
  WINADVAPI LSTATUS APIENTRY RegSetValueW(HKEY hKey, LPCWSTR lpSubKey, DWORD dwType, LPCWSTR lpData, DWORD cbData);
#define RegSetValue __MINGW_NAME_AW(RegSetValue)
  WINADVAPI LSTATUS APIENTRY RegUnLoadKeyA(HKEY hKey, LPCSTR lpSubKey);
  WINADVAPI LSTATUS APIENTRY RegUnLoadKeyW(HKEY hKey, LPCWSTR lpSubKey);
#define RegUnLoadKey __MINGW_NAME_AW(RegUnLoadKey)
  WINADVAPI LSTATUS APIENTRY RegDeleteKeyValueA(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpValueName);
  WINADVAPI LSTATUS APIENTRY RegDeleteKeyValueW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpValueName);
#define RegDeleteKeyValue __MINGW_NAME_AW(RegDeleteKeyValue)
  WINADVAPI LSTATUS APIENTRY RegSetKeyValueA(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpValueName, DWORD dwType, LPCVOID lpData, DWORD cbData);
  WINADVAPI LSTATUS APIENTRY RegSetKeyValueW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpValueName, DWORD dwType, LPCVOID lpData, DWORD cbData);
#define RegSetKeyValue __MINGW_NAME_AW(RegSetKeyValue)
  WINADVAPI LSTATUS APIENTRY RegDeleteTreeA(HKEY hKey, LPCSTR lpSubKey);
  WINADVAPI LSTATUS APIENTRY RegDeleteTreeW(HKEY hKey, LPCWSTR lpSubKey);
#define RegDeleteTree __MINGW_NAME_AW(RegDeleteTree)
  WINADVAPI LSTATUS APIENTRY RegCopyTreeA(HKEY hKeySrc, LPCSTR lpSubKey, HKEY hKeyDest);
  WINADVAPI LSTATUS APIENTRY RegCopyTreeW(HKEY hKeySrc, LPCWSTR lpSubKey, HKEY hKeyDest);
#define RegCopyTree __MINGW_NAME_AW(RegCopyTree)
  WINADVAPI LSTATUS APIENTRY RegGetValueA(HKEY hkey, LPCSTR lpSubKey, LPCSTR lpValue, DWORD dwFlags, LPDWORD pdwType, PVOID pvData, LPDWORD pcbData);
  WINADVAPI LSTATUS APIENTRY RegGetValueW(HKEY hkey, LPCWSTR lpSubKey, LPCWSTR lpValue, DWORD dwFlags, LPDWORD pdwType, PVOID pvData, LPDWORD pcbData);
#define RegGetValue __MINGW_NAME_AW(RegGetValue)
  WINADVAPI LSTATUS APIENTRY RegLoadMUIStringA(HKEY hKey, LPCSTR pszValue, LPSTR pszOutBuf, DWORD cbOutBuf, LPDWORD pcbData, DWORD Flags, LPCSTR pszDirectory);
  WINADVAPI LSTATUS APIENTRY RegLoadMUIStringW(HKEY hKey, LPCWSTR pszValue, LPWSTR pszOutBuf, DWORD cbOutBuf, LPDWORD pcbData, DWORD Flags, LPCWSTR pszDirectory);
#define RegLoadMUIString __MINGW_NAME_AW(RegLoadMUIString)
  WINADVAPI LSTATUS APIENTRY RegLoadAppKeyA(LPCSTR lpFile, PHKEY phkResult, REGSAM samDesired, DWORD dwOptions, DWORD Reserved);
  WINADVAPI LSTATUS APIENTRY RegLoadAppKeyW(LPCWSTR lpFile, PHKEY phkResult, REGSAM samDesired, DWORD dwOptions, DWORD Reserved);
#define RegLoadAppKey __MINGW_NAME_AW(RegLoadAppKey)
  WINADVAPI LSTATUS APIENTRY RegSaveKeyExA(HKEY hKey, LPCSTR lpFile, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD Flags);
  WINADVAPI LSTATUS APIENTRY RegSaveKeyExW(HKEY hKey, LPCWSTR lpFile, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD Flags);
#define RegSaveKeyEx __MINGW_NAME_AW(RegSaveKeyEx)

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */

#ifdef __cplusplus
}
#endif

#endif  /* _WINREG_ */
