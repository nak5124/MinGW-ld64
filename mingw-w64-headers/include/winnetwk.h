#include <winapifamily.h>
/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WINNETWK_
#define _WINNETWK_

#include <_mingw_unicode.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

#include <wnnc.h>

#define RESOURCE_CONNECTED  0x00000001
#define RESOURCE_GLOBALNET  0x00000002
#define RESOURCE_REMEMBERED 0x00000003
#define RESOURCE_RECENT     0x00000004
#define RESOURCE_CONTEXT    0x00000005

#define RESOURCETYPE_ANY      0x00000000
#define RESOURCETYPE_DISK     0x00000001
#define RESOURCETYPE_PRINT    0x00000002
#define RESOURCETYPE_RESERVED 0x00000008
#define RESOURCETYPE_UNKNOWN  0xFFFFFFFF

#define RESOURCEUSAGE_CONNECTABLE   0x00000001
#define RESOURCEUSAGE_CONTAINER     0x00000002
#define RESOURCEUSAGE_NOLOCALDEVICE 0x00000004
#define RESOURCEUSAGE_SIBLING       0x00000008
#define RESOURCEUSAGE_ATTACHED      0x00000010
#define RESOURCEUSAGE_ALL           (RESOURCEUSAGE_CONNECTABLE | RESOURCEUSAGE_CONTAINER | RESOURCEUSAGE_ATTACHED)
#define RESOURCEUSAGE_RESERVED      0x80000000

#define RESOURCEDISPLAYTYPE_GENERIC      0x00000000
#define RESOURCEDISPLAYTYPE_DOMAIN       0x00000001
#define RESOURCEDISPLAYTYPE_SERVER       0x00000002
#define RESOURCEDISPLAYTYPE_SHARE        0x00000003
#define RESOURCEDISPLAYTYPE_FILE         0x00000004
#define RESOURCEDISPLAYTYPE_GROUP        0x00000005
#define RESOURCEDISPLAYTYPE_NETWORK      0x00000006
#define RESOURCEDISPLAYTYPE_ROOT         0x00000007
#define RESOURCEDISPLAYTYPE_SHAREADMIN   0x00000008
#define RESOURCEDISPLAYTYPE_DIRECTORY    0x00000009
#define RESOURCEDISPLAYTYPE_TREE         0x0000000A
#define RESOURCEDISPLAYTYPE_NDSCONTAINER 0x0000000B

  typedef struct _NETRESOURCEA
  {
    DWORD dwScope;
    DWORD dwType;
    DWORD dwDisplayType;
    DWORD dwUsage;
    LPSTR lpLocalName;
    LPSTR lpRemoteName;
    LPSTR lpComment;
    LPSTR lpProvider;
  } NETRESOURCEA, *LPNETRESOURCEA;

  typedef struct _NETRESOURCEW
  {
    DWORD  dwScope;
    DWORD  dwType;
    DWORD  dwDisplayType;
    DWORD  dwUsage;
    LPWSTR lpLocalName;
    LPWSTR lpRemoteName;
    LPWSTR lpComment;
    LPWSTR lpProvider;
  } NETRESOURCEW, *LPNETRESOURCEW;

  __MINGW_TYPEDEF_AW(NETRESOURCE)
  __MINGW_TYPEDEF_AW(LPNETRESOURCE)

#define NETPROPERTY_PERSISTENT 1

#define CONNECT_UPDATE_PROFILE          0x00000001
#define CONNECT_UPDATE_RECENT           0x00000002
#define CONNECT_TEMPORARY               0x00000004
#define CONNECT_INTERACTIVE             0x00000008
#define CONNECT_PROMPT                  0x00000010
#define CONNECT_NEED_DRIVE              0x00000020
#define CONNECT_REFCOUNT                0x00000040
#define CONNECT_REDIRECT                0x00000080
#define CONNECT_LOCALDRIVE              0x00000100
#define CONNECT_CURRENT_MEDIA           0x00000200
#define CONNECT_DEFERRED                0x00000400
#define CONNECT_RESERVED                0xFF000000
#define CONNECT_COMMANDLINE             0x00000800
#define CONNECT_CMD_SAVECRED            0x00001000
#define CONNECT_CRED_RESET              0x00002000
#define CONNECT_REQUIRE_INTEGRITY       0x00004000
#define CONNECT_REQUIRE_PRIVACY         0x00008000
#define CONNECT_WRITE_THROUGH_SEMANTICS 0x00010000
#define CONNECT_GLOBAL_MAPPING          0x00040000

  DWORD APIENTRY WNetAddConnectionA(LPCSTR lpRemoteName, LPCSTR lpPassword, LPCSTR lpLocalName);
  DWORD APIENTRY WNetAddConnectionW(LPCWSTR lpRemoteName, LPCWSTR lpPassword, LPCWSTR lpLocalName);
#define WNetAddConnection __MINGW_NAME_AW(WNetAddConnection)
  DWORD APIENTRY WNetAddConnection2A(LPNETRESOURCEA lpNetResource, LPCSTR lpPassword, LPCSTR lpUserName, DWORD dwFlags);
  DWORD APIENTRY WNetAddConnection2W(LPNETRESOURCEW lpNetResource, LPCWSTR lpPassword, LPCWSTR lpUserName, DWORD dwFlags);
#define WNetAddConnection2 __MINGW_NAME_AW(WNetAddConnection2)
  DWORD APIENTRY WNetAddConnection3A(HWND hwndOwner, LPNETRESOURCEA lpNetResource, LPCSTR lpPassword, LPCSTR lpUserName, DWORD dwFlags);
  DWORD APIENTRY WNetAddConnection3W(HWND hwndOwner, LPNETRESOURCEW lpNetResource, LPCWSTR lpPassword, LPCWSTR lpUserName, DWORD dwFlags);
#define WNetAddConnection3 __MINGW_NAME_AW(WNetAddConnection3)
  DWORD APIENTRY WNetAddConnection4A(HWND hwndOwner, LPNETRESOURCEA lpNetResource, PVOID pAuthBuffer, DWORD cbAuthBuffer, DWORD dwFlags, PBYTE lpUseOptions, DWORD cbUseOptions);
  DWORD APIENTRY WNetAddConnection4W(HWND hwndOwner, LPNETRESOURCEW lpNetResource, PVOID pAuthBuffer, DWORD cbAuthBuffer, DWORD dwFlags, PBYTE lpUseOptions, DWORD cbUseOptions);
#define WNetAddConnection4 __MINGW_NAME_AW(WNetAddConnection4)
  DWORD APIENTRY WNetCancelConnectionA(LPCSTR lpName, WINBOOL fForce);
  DWORD APIENTRY WNetCancelConnectionW(LPCWSTR lpName, WINBOOL fForce);
#define WNetCancelConnection __MINGW_NAME_AW(WNetCancelConnection)
  DWORD APIENTRY WNetCancelConnection2A(LPCSTR lpName, DWORD dwFlags, WINBOOL fForce);
  DWORD APIENTRY WNetCancelConnection2W(LPCWSTR lpName, DWORD dwFlags, WINBOOL fForce);
#define WNetCancelConnection2 __MINGW_NAME_AW(WNetCancelConnection2)
  DWORD APIENTRY WNetGetConnectionA(LPCSTR lpLocalName, LPSTR lpRemoteName, LPDWORD lpnLength);
  DWORD APIENTRY WNetGetConnectionW(LPCWSTR lpLocalName, LPWSTR lpRemoteName, LPDWORD lpnLength);
#define WNetGetConnection __MINGW_NAME_AW(WNetGetConnection)
  DWORD APIENTRY WNetUseConnectionA(HWND hwndOwner, LPNETRESOURCEA lpNetResource, LPCSTR lpPassword, LPCSTR lpUserID, DWORD dwFlags, LPSTR lpAccessName, LPDWORD lpBufferSize, LPDWORD lpResult);
  DWORD APIENTRY WNetUseConnectionW(HWND hwndOwner, LPNETRESOURCEW lpNetResource, LPCWSTR lpPassword, LPCWSTR lpUserID, DWORD dwFlags, LPWSTR lpAccessName, LPDWORD lpBufferSize, LPDWORD lpResult);
#define WNetUseConnection __MINGW_NAME_AW(WNetUseConnection)
  DWORD APIENTRY WNetUseConnection4A(HWND hwndOwner, LPNETRESOURCEA lpNetResource, PVOID pAuthBuffer, DWORD cbAuthBuffer, DWORD dwFlags, PBYTE lpUseOptions, DWORD cbUseOptions, LPSTR lpAccessName, LPDWORD lpBufferSize, LPDWORD lpResult);
  DWORD APIENTRY WNetUseConnection4W(HWND hwndOwner, LPNETRESOURCEW lpNetResource, PVOID pAuthBuffer, DWORD cbAuthBuffer, DWORD dwFlags, PBYTE lpUseOptions, DWORD cbUseOptions, LPWSTR lpAccessName, LPDWORD lpBufferSize, LPDWORD lpResult);
#define WNetUseConnection4 __MINGW_NAME_AW(WNetUseConnection4)
  DWORD APIENTRY WNetConnectionDialog(HWND hwnd, DWORD dwType);
  DWORD APIENTRY WNetDisconnectDialog(HWND hwnd, DWORD dwType);

  typedef struct _CONNECTDLGSTRUCTA
  {
    DWORD          cbStructure;
    HWND           hwndOwner;
    LPNETRESOURCEA lpConnRes;
    DWORD          dwFlags;
    DWORD          dwDevNum;
  } CONNECTDLGSTRUCTA, *LPCONNECTDLGSTRUCTA;

  typedef struct _CONNECTDLGSTRUCTW
  {
    DWORD          cbStructure;
    HWND           hwndOwner;
    LPNETRESOURCEW lpConnRes;
    DWORD          dwFlags;
    DWORD          dwDevNum;
  } CONNECTDLGSTRUCTW, *LPCONNECTDLGSTRUCTW;

  __MINGW_TYPEDEF_AW(CONNECTDLGSTRUCT)
  __MINGW_TYPEDEF_AW(LPCONNECTDLGSTRUCT)

#define CONNDLG_RO_PATH    0x00000001
#define CONNDLG_CONN_POINT 0x00000002
#define CONNDLG_USE_MRU    0x00000004
#define CONNDLG_HIDE_BOX   0x00000008

#define CONNDLG_PERSIST     0x00000010
#define CONNDLG_NOT_PERSIST 0x00000020

  DWORD APIENTRY WNetConnectionDialog1A(LPCONNECTDLGSTRUCTA lpConnDlgStruct);
  DWORD APIENTRY WNetConnectionDialog1W(LPCONNECTDLGSTRUCTW lpConnDlgStruct);
#define WNetConnectionDialog1 __MINGW_NAME_AW(WNetConnectionDialog1)

  typedef struct _DISCDLGSTRUCTA
  {
    DWORD cbStructure;
    HWND  hwndOwner;
    LPSTR lpLocalName;
    LPSTR lpRemoteName;
    DWORD dwFlags;
  } DISCDLGSTRUCTA, *LPDISCDLGSTRUCTA;

  typedef struct _DISCDLGSTRUCTW
  {
    DWORD  cbStructure;
    HWND   hwndOwner;
    LPWSTR lpLocalName;
    LPWSTR lpRemoteName;
    DWORD  dwFlags;
  } DISCDLGSTRUCTW, *LPDISCDLGSTRUCTW;

  __MINGW_TYPEDEF_AW(DISCDLGSTRUCT)
  __MINGW_TYPEDEF_AW(LPDISCDLGSTRUCT)

#define DISC_UPDATE_PROFILE 0x00000001
#define DISC_NO_FORCE       0x00000040

  DWORD APIENTRY WNetDisconnectDialog1A(LPDISCDLGSTRUCTA lpConnDlgStruct);
  DWORD APIENTRY WNetDisconnectDialog1W(LPDISCDLGSTRUCTW lpConnDlgStruct);
#define WNetDisconnectDialog1 __MINGW_NAME_AW(WNetDisconnectDialog1)
  DWORD APIENTRY WNetOpenEnumA(DWORD dwScope, DWORD dwType, DWORD dwUsage, LPNETRESOURCEA lpNetResource, LPHANDLE lphEnum);
  DWORD APIENTRY WNetOpenEnumW(DWORD dwScope, DWORD dwType, DWORD dwUsage, LPNETRESOURCEW lpNetResource, LPHANDLE lphEnum);
#define WNetOpenEnum __MINGW_NAME_AW(WNetOpenEnum)
  DWORD APIENTRY WNetEnumResourceA(HANDLE hEnum, LPDWORD lpcCount, LPVOID lpBuffer, LPDWORD lpBufferSize);
  DWORD APIENTRY WNetEnumResourceW(HANDLE hEnum, LPDWORD lpcCount, LPVOID lpBuffer, LPDWORD lpBufferSize);
#define WNetEnumResource __MINGW_NAME_AW(WNetEnumResource)
  DWORD APIENTRY WNetCloseEnum(HANDLE hEnum);
  DWORD APIENTRY WNetGetResourceParentA(LPNETRESOURCEA lpNetResource, LPVOID lpBuffer, LPDWORD lpcbBuffer);
  DWORD APIENTRY WNetGetResourceParentW(LPNETRESOURCEW lpNetResource, LPVOID lpBuffer, LPDWORD lpcbBuffer);
#define WNetGetResourceParent __MINGW_NAME_AW(WNetGetResourceParent)
  DWORD APIENTRY WNetGetResourceInformationA(LPNETRESOURCEA lpNetResource, LPVOID lpBuffer, LPDWORD lpcbBuffer, LPSTR *lplpSystem);
  DWORD APIENTRY WNetGetResourceInformationW(LPNETRESOURCEW lpNetResource, LPVOID lpBuffer, LPDWORD lpcbBuffer, LPWSTR *lplpSystem);
#define WNetGetResourceInformation __MINGW_NAME_AW(WNetGetResourceInformation)

#define UNIVERSAL_NAME_INFO_LEVEL 0x00000001
#define REMOTE_NAME_INFO_LEVEL    0x00000002

  typedef struct _UNIVERSAL_NAME_INFOA
  {
    LPSTR lpUniversalName;
  } UNIVERSAL_NAME_INFOA, *LPUNIVERSAL_NAME_INFOA;

  typedef struct _UNIVERSAL_NAME_INFOW
  {
    LPWSTR lpUniversalName;
  } UNIVERSAL_NAME_INFOW, *LPUNIVERSAL_NAME_INFOW;

  __MINGW_TYPEDEF_AW(UNIVERSAL_NAME_INFO)
  __MINGW_TYPEDEF_AW(LPUNIVERSAL_NAME_INFO)

  typedef struct _REMOTE_NAME_INFOA
  {
    LPSTR lpUniversalName;
    LPSTR lpConnectionName;
    LPSTR lpRemainingPath;
  } REMOTE_NAME_INFOA, *LPREMOTE_NAME_INFOA;

  typedef struct _REMOTE_NAME_INFOW
  {
    LPWSTR lpUniversalName;
    LPWSTR lpConnectionName;
    LPWSTR lpRemainingPath;
  } REMOTE_NAME_INFOW, *LPREMOTE_NAME_INFOW;

  __MINGW_TYPEDEF_AW(REMOTE_NAME_INFO)
  __MINGW_TYPEDEF_AW(LPREMOTE_NAME_INFO)

  DWORD APIENTRY WNetGetUniversalNameA(LPCSTR lpLocalPath, DWORD dwInfoLevel, LPVOID lpBuffer, LPDWORD lpBufferSize);
  DWORD APIENTRY WNetGetUniversalNameW(LPCWSTR lpLocalPath, DWORD dwInfoLevel, LPVOID lpBuffer, LPDWORD lpBufferSize);
#define WNetGetUniversalName __MINGW_NAME_AW(WNetGetUniversalName)
  DWORD APIENTRY WNetGetUserA(LPCSTR lpName, LPSTR lpUserName, LPDWORD lpnLength);
  DWORD APIENTRY WNetGetUserW(LPCWSTR lpName, LPWSTR lpUserName, LPDWORD lpnLength);
#define WNetGetUser __MINGW_NAME_AW(WNetGetUser)

#define WNFMT_MULTILINE   0x01
#define WNFMT_ABBREVIATED 0x02
#define WNFMT_INENUM      0x10
#define WNFMT_CONNECTION  0x20

  DWORD APIENTRY WNetGetProviderNameA(DWORD dwNetType, LPSTR lpProviderName, LPDWORD lpBufferSize);
  DWORD APIENTRY WNetGetProviderNameW(DWORD dwNetType, LPWSTR lpProviderName, LPDWORD lpBufferSize);
#define WNetGetProviderName __MINGW_NAME_AW(WNetGetProviderName)

  typedef struct _NETINFOSTRUCT
  {
    DWORD     cbStructure;
    DWORD     dwProviderVersion;
    DWORD     dwStatus;
    DWORD     dwCharacteristics;
    ULONG_PTR dwHandle;
    WORD      wNetType;
    DWORD     dwPrinters;
    DWORD     dwDrives;
  } NETINFOSTRUCT, *LPNETINFOSTRUCT;

#define NETINFO_DLL16      0x00000001
#define NETINFO_DISKRED    0x00000004
#define NETINFO_PRINTERRED 0x00000008

  DWORD APIENTRY WNetGetNetworkInformationA(LPCSTR lpProvider, LPNETINFOSTRUCT lpNetInfoStruct);
  DWORD APIENTRY WNetGetNetworkInformationW(LPCWSTR lpProvider, LPNETINFOSTRUCT lpNetInfoStruct);
#define WNetGetNetworkInformation __MINGW_NAME_AW(WNetGetNetworkInformation)
  DWORD APIENTRY WNetGetLastErrorA(LPDWORD lpError, LPSTR lpErrorBuf, DWORD nErrorBufSize, LPSTR lpNameBuf, DWORD nNameBufSize);
  DWORD APIENTRY WNetGetLastErrorW(LPDWORD lpError, LPWSTR lpErrorBuf, DWORD nErrorBufSize, LPWSTR lpNameBuf, DWORD nNameBufSize);
#define WNetGetLastError __MINGW_NAME_AW(WNetGetLastError)

#define WN_SUCCESS                          NO_ERROR
#define WN_NO_ERROR                         NO_ERROR
#define WN_NOT_SUPPORTED                    ERROR_NOT_SUPPORTED
#define WN_CANCEL                           ERROR_CANCELLED
#define WN_RETRY                            ERROR_RETRY
#define WN_NET_ERROR                        ERROR_UNEXP_NET_ERR
#define WN_MORE_DATA                        ERROR_MORE_DATA
#define WN_BAD_POINTER                      ERROR_INVALID_ADDRESS
#define WN_BAD_VALUE                        ERROR_INVALID_PARAMETER
#define WN_BAD_USER                         ERROR_BAD_USERNAME
#define WN_BAD_PASSWORD                     ERROR_INVALID_PASSWORD
#define WN_ACCESS_DENIED                    ERROR_ACCESS_DENIED
#define WN_FUNCTION_BUSY                    ERROR_BUSY
#define WN_WINDOWS_ERROR                    ERROR_UNEXP_NET_ERR
#define WN_OUT_OF_MEMORY                    ERROR_NOT_ENOUGH_MEMORY
#define WN_NO_NETWORK                       ERROR_NO_NETWORK
#define WN_EXTENDED_ERROR                   ERROR_EXTENDED_ERROR
#define WN_BAD_LEVEL                        ERROR_INVALID_LEVEL
#define WN_BAD_HANDLE                       ERROR_INVALID_HANDLE
#define WN_NOT_INITIALIZING                 ERROR_ALREADY_INITIALIZED
#define WN_NO_MORE_DEVICES                  ERROR_NO_MORE_DEVICES
#define WN_NOT_CONNECTED                    ERROR_NOT_CONNECTED
#define WN_OPEN_FILES                       ERROR_OPEN_FILES
#define WN_DEVICE_IN_USE                    ERROR_DEVICE_IN_USE
#define WN_BAD_NETNAME                      ERROR_BAD_NET_NAME
#define WN_BAD_LOCALNAME                    ERROR_BAD_DEVICE
#define WN_ALREADY_CONNECTED                ERROR_ALREADY_ASSIGNED
#define WN_DEVICE_ERROR                     ERROR_GEN_FAILURE
#define WN_CONNECTION_CLOSED                ERROR_CONNECTION_UNAVAIL
#define WN_NO_NET_OR_BAD_PATH               ERROR_NO_NET_OR_BAD_PATH
#define WN_BAD_PROVIDER                     ERROR_BAD_PROVIDER
#define WN_CANNOT_OPEN_PROFILE              ERROR_CANNOT_OPEN_PROFILE
#define WN_BAD_PROFILE                      ERROR_BAD_PROFILE
#define WN_BAD_DEV_TYPE                     ERROR_BAD_DEV_TYPE
#define WN_DEVICE_ALREADY_REMEMBERED        ERROR_DEVICE_ALREADY_REMEMBERED
#define WN_CONNECTED_OTHER_PASSWORD         ERROR_CONNECTED_OTHER_PASSWORD
#define WN_CONNECTED_OTHER_PASSWORD_DEFAULT ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT
#define WN_NO_MORE_ENTRIES                  ERROR_NO_MORE_ITEMS
#define WN_NOT_CONTAINER                    ERROR_NOT_CONTAINER
#define WN_NOT_AUTHENTICATED                ERROR_NOT_AUTHENTICATED
#define WN_NOT_LOGGED_ON                    ERROR_NOT_LOGGED_ON
#define WN_NOT_VALIDATED                    ERROR_NO_LOGON_SERVERS

  typedef struct _NETCONNECTINFOSTRUCT
  {
    DWORD cbStructure;
    DWORD dwFlags;
    DWORD dwSpeed;
    DWORD dwDelay;
    DWORD dwOptDataSize;
  } NETCONNECTINFOSTRUCT, *LPNETCONNECTINFOSTRUCT;

#define WNCON_FORNETCARD 0x00000001
#define WNCON_NOTROUTED  0x00000002
#define WNCON_SLOWLINK   0x00000004
#define WNCON_DYNAMIC    0x00000008

  DWORD APIENTRY MultinetGetConnectionPerformanceA(LPNETRESOURCEA lpNetResource, LPNETCONNECTINFOSTRUCT lpNetConnectInfoStruct);
  DWORD APIENTRY MultinetGetConnectionPerformanceW(LPNETRESOURCEW lpNetResource, LPNETCONNECTINFOSTRUCT lpNetConnectInfoStruct);
#define MultinetGetConnectionPerformance __MINGW_NAME_AW(MultinetGetConnectionPerformance)

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

  DWORD APIENTRY WNetRestoreSingleConnectionW(HWND hwndParent, LPCWSTR lpDevice, WINBOOL fUseUI);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */

#ifdef __cplusplus
}
#endif

#endif  /* _WINNETWK_ */
