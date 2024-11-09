/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _WINSVC_
#define _WINSVC_

#include <_mingw.h>
#include <_mingw_unicode.h>
#include <winapifamily.h>
#include <apisetcconv.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

#define SERVICES_ACTIVE_DATABASEW L"ServicesActive"
#define SERVICES_FAILED_DATABASEW L"ServicesFailed"
#define SERVICES_ACTIVE_DATABASEA  "ServicesActive"
#define SERVICES_FAILED_DATABASEA  "ServicesFailed"

#define SC_GROUP_IDENTIFIERW L'+'
#define SC_GROUP_IDENTIFIERA  '+'

#define SERVICES_ACTIVE_DATABASE __MINGW_NAME_AW(SERVICES_ACTIVE_DATABASE)
#define SERVICES_FAILED_DATABASE __MINGW_NAME_AW(SERVICES_FAILED_DATABASE)
#define SC_GROUP_IDENTIFIER      __MINGW_NAME_AW(SC_GROUP_IDENTIFIER)

#define SERVICE_NO_CHANGE 0xffffffff

#define SERVICE_ACTIVE    0x00000001
#define SERVICE_INACTIVE  0x00000002
#define SERVICE_STATE_ALL (SERVICE_ACTIVE | SERVICE_INACTIVE)

#define SERVICE_CONTROL_STOP                  0x00000001
#define SERVICE_CONTROL_PAUSE                 0x00000002
#define SERVICE_CONTROL_CONTINUE              0x00000003
#define SERVICE_CONTROL_INTERROGATE           0x00000004
#define SERVICE_CONTROL_SHUTDOWN              0x00000005
#define SERVICE_CONTROL_PARAMCHANGE           0x00000006
#define SERVICE_CONTROL_NETBINDADD            0x00000007
#define SERVICE_CONTROL_NETBINDREMOVE         0x00000008
#define SERVICE_CONTROL_NETBINDENABLE         0x00000009
#define SERVICE_CONTROL_NETBINDDISABLE        0x0000000A
#define SERVICE_CONTROL_DEVICEEVENT           0x0000000B
#define SERVICE_CONTROL_HARDWAREPROFILECHANGE 0x0000000C
#define SERVICE_CONTROL_POWEREVENT            0x0000000D
#define SERVICE_CONTROL_SESSIONCHANGE         0x0000000E
#define SERVICE_CONTROL_PRESHUTDOWN           0x0000000F
#define SERVICE_CONTROL_TIMECHANGE            0x00000010
#define SERVICE_CONTROL_TRIGGEREVENT          0x00000020
#define SERVICE_CONTROL_LOWRESOURCES          0x00000060
#define SERVICE_CONTROL_SYSTEMLOWRESOURCES    0x00000061
#define SERVICE_STOPPED                       0x00000001
#define SERVICE_START_PENDING                 0x00000002
#define SERVICE_STOP_PENDING                  0x00000003
#define SERVICE_RUNNING                       0x00000004
#define SERVICE_CONTINUE_PENDING              0x00000005
#define SERVICE_PAUSE_PENDING                 0x00000006
#define SERVICE_PAUSED                        0x00000007
#define SERVICE_ACCEPT_STOP                   0x00000001
#define SERVICE_ACCEPT_PAUSE_CONTINUE         0x00000002
#define SERVICE_ACCEPT_SHUTDOWN               0x00000004
#define SERVICE_ACCEPT_PARAMCHANGE            0x00000008
#define SERVICE_ACCEPT_NETBINDCHANGE          0x00000010
#define SERVICE_ACCEPT_HARDWAREPROFILECHANGE  0x00000020
#define SERVICE_ACCEPT_POWEREVENT             0x00000040
#define SERVICE_ACCEPT_SESSIONCHANGE          0x00000080
#define SERVICE_ACCEPT_PRESHUTDOWN            0x00000100
#define SERVICE_ACCEPT_TIMECHANGE             0x00000200
#define SERVICE_ACCEPT_TRIGGEREVENT           0x00000400
#define SERVICE_ACCEPT_USER_LOGOFF            0x00000800
#define SERVICE_ACCEPT_LOWRESOURCES           0x00002000
#define SERVICE_ACCEPT_SYSTEMLOWRESOURCES     0x00004000

#define SC_MANAGER_CONNECT            0x0001
#define SC_MANAGER_CREATE_SERVICE     0x0002
#define SC_MANAGER_ENUMERATE_SERVICE  0x0004
#define SC_MANAGER_LOCK               0x0008
#define SC_MANAGER_QUERY_LOCK_STATUS  0x0010
#define SC_MANAGER_MODIFY_BOOT_CONFIG 0x0020
#define SC_MANAGER_ALL_ACCESS         (STANDARD_RIGHTS_REQUIRED | SC_MANAGER_CONNECT | SC_MANAGER_CREATE_SERVICE | SC_MANAGER_ENUMERATE_SERVICE | SC_MANAGER_LOCK | SC_MANAGER_QUERY_LOCK_STATUS | SC_MANAGER_MODIFY_BOOT_CONFIG)

#define SERVICE_QUERY_CONFIG         0x0001
#define SERVICE_CHANGE_CONFIG        0x0002
#define SERVICE_QUERY_STATUS         0x0004
#define SERVICE_ENUMERATE_DEPENDENTS 0x0008
#define SERVICE_START                0x0010
#define SERVICE_STOP                 0x0020
#define SERVICE_PAUSE_CONTINUE       0x0040
#define SERVICE_INTERROGATE          0x0080
#define SERVICE_USER_DEFINED_CONTROL 0x0100
#define SERVICE_ALL_ACCESS           (STANDARD_RIGHTS_REQUIRED | SERVICE_QUERY_CONFIG | SERVICE_CHANGE_CONFIG | SERVICE_QUERY_STATUS | SERVICE_ENUMERATE_DEPENDENTS | SERVICE_START | SERVICE_STOP | SERVICE_PAUSE_CONTINUE | SERVICE_INTERROGATE | SERVICE_USER_DEFINED_CONTROL)

#define SERVICE_RUNS_IN_SYSTEM_PROCESS 0x00000001

#define SERVICE_CONFIG_DESCRIPTION              1
#define SERVICE_CONFIG_FAILURE_ACTIONS          2
#define SERVICE_CONFIG_DELAYED_AUTO_START_INFO  3
#define SERVICE_CONFIG_FAILURE_ACTIONS_FLAG     4
#define SERVICE_CONFIG_SERVICE_SID_INFO         5
#define SERVICE_CONFIG_REQUIRED_PRIVILEGES_INFO 6
#define SERVICE_CONFIG_PRESHUTDOWN_INFO         7
#define SERVICE_CONFIG_TRIGGER_INFO             8
#define SERVICE_CONFIG_PREFERRED_NODE           9
#define SERVICE_CONFIG_LAUNCH_PROTECTED         12

#define SERVICE_NOTIFY_STATUS_CHANGE_1 1
#define SERVICE_NOTIFY_STATUS_CHANGE_2 2
#define SERVICE_NOTIFY_STATUS_CHANGE   SERVICE_NOTIFY_STATUS_CHANGE_2

#define SERVICE_NOTIFY_STOPPED          0x00000001
#define SERVICE_NOTIFY_START_PENDING    0x00000002
#define SERVICE_NOTIFY_STOP_PENDING     0x00000004
#define SERVICE_NOTIFY_RUNNING          0x00000008
#define SERVICE_NOTIFY_CONTINUE_PENDING 0x00000010
#define SERVICE_NOTIFY_PAUSE_PENDING    0x00000020
#define SERVICE_NOTIFY_PAUSED           0x00000040
#define SERVICE_NOTIFY_CREATED          0x00000080
#define SERVICE_NOTIFY_DELETED          0x00000100
#define SERVICE_NOTIFY_DELETE_PENDING   0x00000200

#define SERVICE_STOP_REASON_FLAG_MIN       0x00000000
#define SERVICE_STOP_REASON_FLAG_UNPLANNED 0x10000000
#define SERVICE_STOP_REASON_FLAG_CUSTOM    0x20000000
#define SERVICE_STOP_REASON_FLAG_PLANNED   0x40000000
#define SERVICE_STOP_REASON_FLAG_MAX       0x80000000

#define SERVICE_STOP_REASON_MAJOR_MIN             0x00000000
#define SERVICE_STOP_REASON_MAJOR_OTHER           0x00010000
#define SERVICE_STOP_REASON_MAJOR_HARDWARE        0x00020000
#define SERVICE_STOP_REASON_MAJOR_OPERATINGSYSTEM 0x00030000
#define SERVICE_STOP_REASON_MAJOR_SOFTWARE        0x00040000
#define SERVICE_STOP_REASON_MAJOR_APPLICATION     0x00050000
#define SERVICE_STOP_REASON_MAJOR_NONE            0x00060000
#define SERVICE_STOP_REASON_MAJOR_MAX             0x00070000
#define SERVICE_STOP_REASON_MAJOR_MIN_CUSTOM      0x00400000
#define SERVICE_STOP_REASON_MAJOR_MAX_CUSTOM      0x00ff0000

#define SERVICE_STOP_REASON_MINOR_MIN                       0x00000000
#define SERVICE_STOP_REASON_MINOR_OTHER                     0x00000001
#define SERVICE_STOP_REASON_MINOR_MAINTENANCE               0x00000002
#define SERVICE_STOP_REASON_MINOR_INSTALLATION              0x00000003
#define SERVICE_STOP_REASON_MINOR_UPGRADE                   0x00000004
#define SERVICE_STOP_REASON_MINOR_RECONFIG                  0x00000005
#define SERVICE_STOP_REASON_MINOR_HUNG                      0x00000006
#define SERVICE_STOP_REASON_MINOR_UNSTABLE                  0x00000007
#define SERVICE_STOP_REASON_MINOR_DISK                      0x00000008
#define SERVICE_STOP_REASON_MINOR_NETWORKCARD               0x00000009
#define SERVICE_STOP_REASON_MINOR_ENVIRONMENT               0x0000000a
#define SERVICE_STOP_REASON_MINOR_HARDWARE_DRIVER           0x0000000b
#define SERVICE_STOP_REASON_MINOR_OTHERDRIVER               0x0000000c
#define SERVICE_STOP_REASON_MINOR_SERVICEPACK               0x0000000d
#define SERVICE_STOP_REASON_MINOR_SOFTWARE_UPDATE           0x0000000e
#define SERVICE_STOP_REASON_MINOR_SECURITYFIX               0x0000000f
#define SERVICE_STOP_REASON_MINOR_SECURITY                  0x00000010
#define SERVICE_STOP_REASON_MINOR_NETWORK_CONNECTIVITY      0x00000011
#define SERVICE_STOP_REASON_MINOR_WMI                       0x00000012
#define SERVICE_STOP_REASON_MINOR_SERVICEPACK_UNINSTALL     0x00000013
#define SERVICE_STOP_REASON_MINOR_SOFTWARE_UPDATE_UNINSTALL 0x00000014
#define SERVICE_STOP_REASON_MINOR_SECURITYFIX_UNINSTALL     0x00000015
#define SERVICE_STOP_REASON_MINOR_MMC                       0x00000016
#define SERVICE_STOP_REASON_MINOR_NONE                      0x00000017
#define SERVICE_STOP_REASON_MINOR_MEMOTYLIMIT               0x00000018
#define SERVICE_STOP_REASON_MINOR_MAX                       0x00000019
#define SERVICE_STOP_REASON_MINOR_MIN_CUSTOM                0x00000100
#define SERVICE_STOP_REASON_MINOR_MAX_CUSTOM                0x0000FFFF

#define SERVICE_CONTROL_STATUS_REASON_INFO 1

#define SERVICE_SID_TYPE_NONE         0x00000000
#define SERVICE_SID_TYPE_UNRESTRICTED 0x00000001
#define SERVICE_SID_TYPE_RESTRICTED   (0x00000002 | SERVICE_SID_TYPE_UNRESTRICTED)

#define SERVICE_TRIGGER_TYPE_DEVICE_INTERFACE_ARRIVAL   1
#define SERVICE_TRIGGER_TYPE_IP_ADDRESS_AVAILABILITY    2
#define SERVICE_TRIGGER_TYPE_DOMAIN_JOIN                3
#define SERVICE_TRIGGER_TYPE_FIREWALL_PORT_EVENT        4
#define SERVICE_TRIGGER_TYPE_GROUP_POLICY               5
#define SERVICE_TRIGGER_TYPE_NETWORK_ENDPOINT           6
#define SERVICE_TRIGGER_TYPE_CUSTOM_SYSTEM_STATE_CHANGE 7
#define SERVICE_TRIGGER_TYPE_CUSTOM                     20
#define SERVICE_TRIGGER_TYPE_AGGREGATE                  30

#define SERVICE_TRIGGER_DATA_TYPE_BINARY      1
#define SERVICE_TRIGGER_DATA_TYPE_STRING      2
#define SERVICE_TRIGGER_DATA_TYPE_LEVEL       3
#define SERVICE_TRIGGER_DATA_TYPE_KEYWORD_ANY 4
#define SERVICE_TRIGGER_DATA_TYPE_KEYWORD_ALL 5

#define SERVICE_START_REASON_DEMAND             0x00000001
#define SERVICE_START_REASON_AUTO               0x00000002
#define SERVICE_START_REASON_TRIGGER            0x00000004
#define SERVICE_START_REASON_RESTART_ON_FAILURE 0x00000008
#define SERVICE_START_REASON_DELAYEDAUTO        0x00000010

#define SERVICE_DYNAMIC_INFORMATION_LEVEL_START_REASON 1

#define SERVICE_LAUNCH_PROTECTED_NONE              0
#define SERVICE_LAUNCH_PROTECTED_WINDOWS           1
#define SERVICE_LAUNCH_PROTECTED_WINDOWS_LIGHT     2
#define SERVICE_LAUNCH_PROTECTED_ANTIMALWARE_LIGHT 3

  DEFINE_GUID(NETWORK_MANAGER_FIRST_IP_ADDRESS_ARRIVAL_GUID, 0x4f27f2de, 0x14e2, 0x430b, 0xa5, 0x49, 0x7c, 0xd4, 0x8c, 0xbc, 0x82, 0x45);
  DEFINE_GUID(NETWORK_MANAGER_LAST_IP_ADDRESS_REMOVAL_GUID,  0xcc4ba62a, 0x162e, 0x4648, 0x84, 0x7a, 0xb6, 0xbd, 0xf9, 0x93, 0xe3, 0x35);
  DEFINE_GUID(DOMAIN_JOIN_GUID,                              0x1ce20aba, 0x9851, 0x4421, 0x94, 0x30, 0x1d, 0xde, 0xb7, 0x66, 0xe8, 0x09);
  DEFINE_GUID(DOMAIN_LEAVE_GUID,                             0xddaf516e, 0x58c2, 0x4866, 0x95, 0x74, 0xc3, 0xb6, 0x15, 0xd4, 0x2e, 0xa1);
  DEFINE_GUID(FIREWALL_PORT_OPEN_GUID,                       0xb7569e07, 0x8421, 0x4ee0, 0xad, 0x10, 0x86, 0x91, 0x5a, 0xfd, 0xad, 0x09);
  DEFINE_GUID(FIREWALL_PORT_CLOSE_GUID,                      0xa144ed38, 0x8e12, 0x4de4, 0x9d, 0x96, 0xe6, 0x47, 0x40, 0xb1, 0xa5, 0x24);
  DEFINE_GUID(MACHINE_POLICY_PRESENT_GUID,                   0x659FCAE6, 0x5BDB, 0x4DA9, 0xB1, 0xFF, 0xCA, 0x2A, 0x17, 0x8D, 0x46, 0xE0);
  DEFINE_GUID(USER_POLICY_PRESENT_GUID,                      0x54FB46C8, 0xF089, 0x464C, 0xB1, 0xFD, 0x59, 0xD1, 0xB6, 0x2C, 0x3B, 0x50);
  DEFINE_GUID(RPC_INTERFACE_EVENT_GUID,                      0xbc90d167, 0x9470, 0x4139, 0xa9, 0xba, 0xbe, 0x0b, 0xbb, 0xf5, 0xb7, 0x4d);
  DEFINE_GUID(NAMED_PIPE_EVENT_GUID,                         0x1f81d131, 0x3fac, 0x4537, 0x9e, 0x0c, 0x7e, 0x7b, 0x0c, 0x2f, 0x4b, 0x55);
  DEFINE_GUID(CUSTOM_SYSTEM_STATE_CHANGE_EVENT_GUID,         0x2d7a2816, 0x0c5e, 0x45fc, 0x9c, 0xe7, 0x57, 0x0e, 0x5e, 0xcd, 0xe9, 0xc9);

  typedef struct
  {
    DWORD Data[2];
  } SERVICE_TRIGGER_CUSTOM_STATE_ID;

  typedef struct _SERVICE_CUSTOM_SYSTEM_STATE_CHANGE_DATA_ITEM
  {
    union
    {
      SERVICE_TRIGGER_CUSTOM_STATE_ID CustomStateId;
      struct
      {
        DWORD DataOffset;
        BYTE  Data[1];
      } s;
    } u;
  } SERVICE_CUSTOM_SYSTEM_STATE_CHANGE_DATA_ITEM, *LPSERVICE_CUSTOM_SYSTEM_STATE_CHANGE_DATA_ITEM;

#define SERVICE_TRIGGER_ACTION_SERVICE_START 1
#define SERVICE_TRIGGER_ACTION_SERVICE_STOP  2
#define SERVICE_TRIGGER_STARTED_ARGUMENT     L"TriggerStarted"

  typedef struct _SERVICE_DESCRIPTIONA
  {
    LPSTR lpDescription;
  } SERVICE_DESCRIPTIONA, *LPSERVICE_DESCRIPTIONA;

  typedef struct _SERVICE_DESCRIPTIONW
  {
    LPWSTR lpDescription;
  } SERVICE_DESCRIPTIONW, *LPSERVICE_DESCRIPTIONW;

  __MINGW_TYPEDEF_AW(SERVICE_DESCRIPTION)
  __MINGW_TYPEDEF_AW(LPSERVICE_DESCRIPTION)

  typedef enum _SC_ACTION_TYPE
  {
    SC_ACTION_NONE        = 0,
    SC_ACTION_RESTART     = 1,
    SC_ACTION_REBOOT      = 2,
    SC_ACTION_RUN_COMMAND = 3,
    SC_ACTION_OWN_RESTART = 4
  } SC_ACTION_TYPE;

  typedef struct _SC_ACTION
  {
    SC_ACTION_TYPE Type;
    DWORD          Delay;
  } SC_ACTION, *LPSC_ACTION;

  typedef struct _SERVICE_FAILURE_ACTIONSA
  {
    DWORD      dwResetPeriod;
    LPSTR      lpRebootMsg;
    LPSTR      lpCommand;
    DWORD      cActions;
    SC_ACTION *lpsaActions;
  } SERVICE_FAILURE_ACTIONSA, *LPSERVICE_FAILURE_ACTIONSA;

  typedef struct _SERVICE_FAILURE_ACTIONSW
  {
    DWORD      dwResetPeriod;
    LPWSTR     lpRebootMsg;
    LPWSTR     lpCommand;
    DWORD      cActions;
    SC_ACTION *lpsaActions;
  } SERVICE_FAILURE_ACTIONSW, *LPSERVICE_FAILURE_ACTIONSW;

  __MINGW_TYPEDEF_AW(SERVICE_FAILURE_ACTIONS)
  __MINGW_TYPEDEF_AW(LPSERVICE_FAILURE_ACTIONS)

  typedef struct _SERVICE_DELAYED_AUTO_START_INFO
  {
    WINBOOL fDelayedAutostart;
  } SERVICE_DELAYED_AUTO_START_INFO, *LPSERVICE_DELAYED_AUTO_START_INFO;

  typedef struct _SERVICE_FAILURE_ACTIONS_FLAG
  {
    WINBOOL fFailureActionsOnNonCrashFailures;
  } SERVICE_FAILURE_ACTIONS_FLAG, *LPSERVICE_FAILURE_ACTIONS_FLAG;

  typedef struct _SERVICE_SID_INFO
  {
    DWORD dwServiceSidType;
  } SERVICE_SID_INFO, *LPSERVICE_SID_INFO;

  typedef struct _SERVICE_REQUIRED_PRIVILEGES_INFOA
  {
    LPSTR pmszRequiredPrivileges;
  } SERVICE_REQUIRED_PRIVILEGES_INFOA, *LPSERVICE_REQUIRED_PRIVILEGES_INFOA;

  typedef struct _SERVICE_REQUIRED_PRIVILEGES_INFOW
  {
    LPWSTR pmszRequiredPrivileges;
  } SERVICE_REQUIRED_PRIVILEGES_INFOW, *LPSERVICE_REQUIRED_PRIVILEGES_INFOW;

  __MINGW_TYPEDEF_AW(SERVICE_REQUIRED_PRIVILEGES_INFO)
  __MINGW_TYPEDEF_AW(LPSERVICE_REQUIRED_PRIVILEGES_INFO)

  typedef struct _SERVICE_PRESHUTDOWN_INFO
  {
    DWORD dwPreshutdownTimeout;
  } SERVICE_PRESHUTDOWN_INFO, *LPSERVICE_PRESHUTDOWN_INFO;

  typedef struct _SERVICE_TRIGGER_SPECIFIC_DATA_ITEM
  {
    DWORD dwDataType;
    DWORD cbData;
    PBYTE pData;
  } SERVICE_TRIGGER_SPECIFIC_DATA_ITEM, *PSERVICE_TRIGGER_SPECIFIC_DATA_ITEM;

  typedef struct _SERVICE_TRIGGER
  {
    DWORD                                dwTriggerType;
    DWORD                                dwAction;
    GUID                                *pTriggerSubtype;
    DWORD                                cDataItems;
    PSERVICE_TRIGGER_SPECIFIC_DATA_ITEM  pDataItems;
  } SERVICE_TRIGGER, *PSERVICE_TRIGGER;

  typedef struct _SERVICE_TRIGGER_INFO
  {
    DWORD            cTriggers;
    PSERVICE_TRIGGER pTriggers;
    PBYTE            pReserved;
  } SERVICE_TRIGGER_INFO, *PSERVICE_TRIGGER_INFO;

#define SC_AGGREGATE_STORAGE_KEY L"System\\CurrentControlSet\\Control\\ServiceAggregatedEvents"

  typedef struct _SERVICE_PREFERRED_NODE_INFO
  {
    USHORT  usPreferredNode;
    BOOLEAN fDelete;
  } SERVICE_PREFERRED_NODE_INFO, *LPSERVICE_PREFERRED_NODE_INFO;

  typedef struct _SERVICE_TIMECHANGE_INFO
  {
    LARGE_INTEGER liNewTime;
    LARGE_INTEGER liOldTime;
  } SERVICE_TIMECHANGE_INFO, *PSERVICE_TIMECHANGE_INFO;

  typedef struct _SERVICE_LAUNCH_PROTECTED_INFO
  {
    DWORD dwLaunchProtected;
  } SERVICE_LAUNCH_PROTECTED_INFO, *PSERVICE_LAUNCH_PROTECTED_INFO;

  DECLARE_HANDLE(SC_HANDLE);
  typedef SC_HANDLE *LPSC_HANDLE;
  DECLARE_HANDLE(SERVICE_STATUS_HANDLE);

  typedef enum _SC_STATUS_TYPE
  {
    SC_STATUS_PROCESS_INFO = 0
  } SC_STATUS_TYPE;

  typedef enum _SC_ENUM_TYPE
  {
    SC_ENUM_PROCESS_INFO = 0
  } SC_ENUM_TYPE;

  typedef struct _SERVICE_STATUS
  {
    DWORD dwServiceType;
    DWORD dwCurrentState;
    DWORD dwControlsAccepted;
    DWORD dwWin32ExitCode;
    DWORD dwServiceSpecificExitCode;
    DWORD dwCheckPoint;
    DWORD dwWaitHint;
  } SERVICE_STATUS, *LPSERVICE_STATUS;

  typedef struct _SERVICE_STATUS_PROCESS
  {
    DWORD dwServiceType;
    DWORD dwCurrentState;
    DWORD dwControlsAccepted;
    DWORD dwWin32ExitCode;
    DWORD dwServiceSpecificExitCode;
    DWORD dwCheckPoint;
    DWORD dwWaitHint;
    DWORD dwProcessId;
    DWORD dwServiceFlags;
  } SERVICE_STATUS_PROCESS, *LPSERVICE_STATUS_PROCESS;

  typedef struct _ENUM_SERVICE_STATUSA
  {
    LPSTR          lpServiceName;
    LPSTR          lpDisplayName;
    SERVICE_STATUS ServiceStatus;
  } ENUM_SERVICE_STATUSA, *LPENUM_SERVICE_STATUSA;

  typedef struct _ENUM_SERVICE_STATUSW
  {
    LPWSTR         lpServiceName;
    LPWSTR         lpDisplayName;
    SERVICE_STATUS ServiceStatus;
  } ENUM_SERVICE_STATUSW, *LPENUM_SERVICE_STATUSW;

  __MINGW_TYPEDEF_AW(ENUM_SERVICE_STATUS)
  __MINGW_TYPEDEF_AW(LPENUM_SERVICE_STATUS)

  typedef struct _ENUM_SERVICE_STATUS_PROCESSA
  {
    LPSTR                  lpServiceName;
    LPSTR                  lpDisplayName;
    SERVICE_STATUS_PROCESS ServiceStatusProcess;
  } ENUM_SERVICE_STATUS_PROCESSA, *LPENUM_SERVICE_STATUS_PROCESSA;

  typedef struct _ENUM_SERVICE_STATUS_PROCESSW
  {
    LPWSTR                 lpServiceName;
    LPWSTR                 lpDisplayName;
    SERVICE_STATUS_PROCESS ServiceStatusProcess;
  } ENUM_SERVICE_STATUS_PROCESSW, *LPENUM_SERVICE_STATUS_PROCESSW;

  __MINGW_TYPEDEF_AW(ENUM_SERVICE_STATUS_PROCESS)
  __MINGW_TYPEDEF_AW(LPENUM_SERVICE_STATUS_PROCESS)

  typedef LPVOID SC_LOCK;

  typedef struct _QUERY_SERVICE_LOCK_STATUSA
  {
    DWORD fIsLocked;
    LPSTR lpLockOwner;
    DWORD dwLockDuration;
  } QUERY_SERVICE_LOCK_STATUSA, *LPQUERY_SERVICE_LOCK_STATUSA;

  typedef struct _QUERY_SERVICE_LOCK_STATUSW
  {
    DWORD  fIsLocked;
    LPWSTR lpLockOwner;
    DWORD  dwLockDuration;
  } QUERY_SERVICE_LOCK_STATUSW, *LPQUERY_SERVICE_LOCK_STATUSW;

  __MINGW_TYPEDEF_AW(QUERY_SERVICE_LOCK_STATUS)
  __MINGW_TYPEDEF_AW(LPQUERY_SERVICE_LOCK_STATUS)

  typedef struct _QUERY_SERVICE_CONFIGA
  {
    DWORD dwServiceType;
    DWORD dwStartType;
    DWORD dwErrorControl;
    LPSTR lpBinaryPathName;
    LPSTR lpLoadOrderGroup;
    DWORD dwTagId;
    LPSTR lpDependencies;
    LPSTR lpServiceStartName;
    LPSTR lpDisplayName;
  } QUERY_SERVICE_CONFIGA, *LPQUERY_SERVICE_CONFIGA;

  typedef struct _QUERY_SERVICE_CONFIGW
  {
    DWORD  dwServiceType;
    DWORD  dwStartType;
    DWORD  dwErrorControl;
    LPWSTR lpBinaryPathName;
    LPWSTR lpLoadOrderGroup;
    DWORD  dwTagId;
    LPWSTR lpDependencies;
    LPWSTR lpServiceStartName;
    LPWSTR lpDisplayName;
  } QUERY_SERVICE_CONFIGW, *LPQUERY_SERVICE_CONFIGW;

  __MINGW_TYPEDEF_AW(QUERY_SERVICE_CONFIG)
  __MINGW_TYPEDEF_AW(LPQUERY_SERVICE_CONFIG)

  typedef VOID WINAPI SERVICE_MAIN_FUNCTIONA(DWORD dwNumServicesArgs, LPSTR *lpServiceArgVectors);
  typedef VOID WINAPI SERVICE_MAIN_FUNCTIONW(DWORD dwNumServicesArgs, LPWSTR *lpServiceArgVectors);

#define SERVICE_MAIN_FUNCTION __MINGW_NAME_AW(SERVICE_MAIN_FUNCTION)

  typedef VOID (WINAPI *LPSERVICE_MAIN_FUNCTIONA)(DWORD dwNumServicesArgs, LPSTR *lpServiceArgVectors);
  typedef VOID (WINAPI *LPSERVICE_MAIN_FUNCTIONW)(DWORD dwNumServicesArgs, LPWSTR *lpServiceArgVectors);

#define LPSERVICE_MAIN_FUNCTION __MINGW_NAME_AW(LPSERVICE_MAIN_FUNCTION)

  typedef struct _SERVICE_TABLE_ENTRYA
  {
    LPSTR                    lpServiceName;
    LPSERVICE_MAIN_FUNCTIONA lpServiceProc;
  } SERVICE_TABLE_ENTRYA, *LPSERVICE_TABLE_ENTRYA;

  typedef struct _SERVICE_TABLE_ENTRYW
  {
    LPWSTR                   lpServiceName;
    LPSERVICE_MAIN_FUNCTIONW lpServiceProc;
  } SERVICE_TABLE_ENTRYW, *LPSERVICE_TABLE_ENTRYW;

  __MINGW_TYPEDEF_AW(SERVICE_TABLE_ENTRY)
  __MINGW_TYPEDEF_AW(LPSERVICE_TABLE_ENTRY)

  typedef VOID  WINAPI HANDLER_FUNCTION(DWORD dwControl);
  typedef DWORD WINAPI HANDLER_FUNCTION_EX(DWORD dwControl, DWORD dwEventType, LPVOID lpEventData, LPVOID lpContext);
  typedef VOID  (WINAPI *LPHANDLER_FUNCTION)(DWORD dwControl);
  typedef DWORD (WINAPI *LPHANDLER_FUNCTION_EX)(DWORD dwControl, DWORD dwEventType, LPVOID lpEventData, LPVOID lpContext);

  typedef VOID (CALLBACK *PFN_SC_NOTIFY_CALLBACK)(PVOID pParameter);

  typedef struct _SERVICE_NOTIFY_1
  {
    DWORD                  dwVersion;
    PFN_SC_NOTIFY_CALLBACK pfnNotifyCallback;
    PVOID                  pContext;
    DWORD                  dwNotificationStatus;
    SERVICE_STATUS_PROCESS ServiceStatus;
  } SERVICE_NOTIFY_1, *PSERVICE_NOTIFY_1;

  typedef struct _SERVICE_NOTIFY_2A
  {
    DWORD                  dwVersion;
    PFN_SC_NOTIFY_CALLBACK pfnNotifyCallback;
    PVOID                  pContext;
    DWORD                  dwNotificationStatus;
    SERVICE_STATUS_PROCESS ServiceStatus;
    DWORD                  dwNotificationTriggered;
    LPSTR                  pszServiceNames;
  } SERVICE_NOTIFY_2A, *PSERVICE_NOTIFY_2A;

  typedef struct _SERVICE_NOTIFY_2W
  {
    DWORD                  dwVersion;
    PFN_SC_NOTIFY_CALLBACK pfnNotifyCallback;
    PVOID                  pContext;
    DWORD                  dwNotificationStatus;
    SERVICE_STATUS_PROCESS ServiceStatus;
    DWORD                  dwNotificationTriggered;
    LPWSTR                 pszServiceNames;
  } SERVICE_NOTIFY_2W, *PSERVICE_NOTIFY_2W;

  __MINGW_TYPEDEF_AW(SERVICE_NOTIFY_2)
  __MINGW_TYPEDEF_AW(PSERVICE_NOTIFY_2)

  typedef SERVICE_NOTIFY_2A SERVICE_NOTIFYA, *PSERVICE_NOTIFYA;
  typedef SERVICE_NOTIFY_2W SERVICE_NOTIFYW, *PSERVICE_NOTIFYW;

  __MINGW_TYPEDEF_AW(SERVICE_NOTIFY)
  __MINGW_TYPEDEF_AW(PSERVICE_NOTIFY)

  typedef struct _SERVICE_CONTROL_STATUS_REASON_PARAMSA
  {
    DWORD                  dwReason;
    LPSTR                  pszComment;
    SERVICE_STATUS_PROCESS ServiceStatus;
  } SERVICE_CONTROL_STATUS_REASON_PARAMSA, *PSERVICE_CONTROL_STATUS_REASON_PARAMSA;

  typedef struct _SERVICE_CONTROL_STATUS_REASON_PARAMSW
  {
    DWORD                  dwReason;
    LPWSTR                 pszComment;
    SERVICE_STATUS_PROCESS ServiceStatus;
  } SERVICE_CONTROL_STATUS_REASON_PARAMSW, *PSERVICE_CONTROL_STATUS_REASON_PARAMSW;

  __MINGW_TYPEDEF_AW(SERVICE_CONTROL_STATUS_REASON_PARAMS)
  __MINGW_TYPEDEF_AW(PSERVICE_CONTROL_STATUS_REASON_PARAMS)

  typedef struct _SERVICE_START_REASON
  {
    DWORD dwReason;
  } SERVICE_START_REASON, *PSERVICE_START_REASON;

  WINADVAPI WINBOOL               WINAPI ChangeServiceConfigA(SC_HANDLE hService, DWORD dwServiceType, DWORD dwStartType, DWORD dwErrorControl, LPCSTR lpBinaryPathName, LPCSTR lpLoadOrderGroup, LPDWORD lpdwTagId, LPCSTR lpDependencies, LPCSTR lpServiceStartName, LPCSTR lpPassword, LPCSTR lpDisplayName);
  WINADVAPI WINBOOL               WINAPI ChangeServiceConfigW(SC_HANDLE hService, DWORD dwServiceType, DWORD dwStartType, DWORD dwErrorControl, LPCWSTR lpBinaryPathName, LPCWSTR lpLoadOrderGroup, LPDWORD lpdwTagId, LPCWSTR lpDependencies, LPCWSTR lpServiceStartName, LPCWSTR lpPassword, LPCWSTR lpDisplayName);
#define ChangeServiceConfig __MINGW_NAME_AW(ChangeServiceConfig)
  WINADVAPI WINBOOL               WINAPI ChangeServiceConfig2A(SC_HANDLE hService, DWORD dwInfoLevel, LPVOID lpInfo);
  WINADVAPI WINBOOL               WINAPI ChangeServiceConfig2W(SC_HANDLE hService, DWORD dwInfoLevel, LPVOID lpInfo);
#define ChangeServiceConfig2 __MINGW_NAME_AW(ChangeServiceConfig2)
  WINADVAPI WINBOOL               WINAPI CloseServiceHandle(SC_HANDLE hSCObject);
  WINADVAPI WINBOOL               WINAPI ControlService(SC_HANDLE hService, DWORD dwControl, LPSERVICE_STATUS lpServiceStatus);
  WINADVAPI SC_HANDLE             WINAPI CreateServiceA(SC_HANDLE hSCManager, LPCSTR lpServiceName, LPCSTR lpDisplayName, DWORD dwDesiredAccess, DWORD dwServiceType, DWORD dwStartType, DWORD dwErrorControl, LPCSTR lpBinaryPathName, LPCSTR lpLoadOrderGroup, LPDWORD lpdwTagId, LPCSTR lpDependencies, LPCSTR lpServiceStartName, LPCSTR lpPassword);
  WINADVAPI SC_HANDLE             WINAPI CreateServiceW(SC_HANDLE hSCManager, LPCWSTR lpServiceName, LPCWSTR lpDisplayName, DWORD dwDesiredAccess, DWORD dwServiceType, DWORD dwStartType, DWORD dwErrorControl, LPCWSTR lpBinaryPathName, LPCWSTR lpLoadOrderGroup, LPDWORD lpdwTagId, LPCWSTR lpDependencies, LPCWSTR lpServiceStartName, LPCWSTR lpPassword);
#define CreateService __MINGW_NAME_AW(CreateService)
  WINADVAPI WINBOOL               WINAPI DeleteService(SC_HANDLE hService);
  WINADVAPI WINBOOL               WINAPI EnumDependentServicesA(SC_HANDLE hService, DWORD dwServiceState, LPENUM_SERVICE_STATUSA lpServices, DWORD cbBufSize, LPDWORD pcbBytesNeeded, LPDWORD lpServicesReturned);
  WINADVAPI WINBOOL               WINAPI EnumDependentServicesW(SC_HANDLE hService, DWORD dwServiceState, LPENUM_SERVICE_STATUSW lpServices, DWORD cbBufSize, LPDWORD pcbBytesNeeded, LPDWORD lpServicesReturned);
#define EnumDependentServices __MINGW_NAME_AW(EnumDependentServices)
  WINADVAPI WINBOOL               WINAPI EnumServicesStatusExA(SC_HANDLE hSCManager, SC_ENUM_TYPE InfoLevel, DWORD dwServiceType, DWORD dwServiceState, LPBYTE lpServices, DWORD cbBufSize, LPDWORD pcbBytesNeeded, LPDWORD lpServicesReturned, LPDWORD lpResumeHandle, LPCSTR pszGroupName);
  WINADVAPI WINBOOL               WINAPI EnumServicesStatusExW(SC_HANDLE hSCManager, SC_ENUM_TYPE InfoLevel, DWORD dwServiceType, DWORD dwServiceState, LPBYTE lpServices, DWORD cbBufSize, LPDWORD pcbBytesNeeded, LPDWORD lpServicesReturned, LPDWORD lpResumeHandle, LPCWSTR pszGroupName);
#define EnumServicesStatusEx __MINGW_NAME_AW(EnumServicesStatusEx)
  WINADVAPI WINBOOL               WINAPI GetServiceKeyNameA(SC_HANDLE hSCManager, LPCSTR lpDisplayName, LPSTR lpServiceName, LPDWORD lpcchBuffer);
  WINADVAPI WINBOOL               WINAPI GetServiceKeyNameW(SC_HANDLE hSCManager, LPCWSTR lpDisplayName, LPWSTR lpServiceName, LPDWORD lpcchBuffer);
#define GetServiceKeyName __MINGW_NAME_AW(GetServiceKeyName)
  WINADVAPI WINBOOL               WINAPI GetServiceDisplayNameA(SC_HANDLE hSCManager, LPCSTR lpServiceName, LPSTR lpDisplayName, LPDWORD lpcchBuffer);
  WINADVAPI WINBOOL               WINAPI GetServiceDisplayNameW(SC_HANDLE hSCManager, LPCWSTR lpServiceName, LPWSTR lpDisplayName, LPDWORD lpcchBuffer);
#define GetServiceDisplayName __MINGW_NAME_AW(GetServiceDisplayName)
  WINADVAPI SC_HANDLE             WINAPI OpenSCManagerA(LPCSTR lpMachineName, LPCSTR lpDatabaseName, DWORD dwDesiredAccess);
  WINADVAPI SC_HANDLE             WINAPI OpenSCManagerW(LPCWSTR lpMachineName, LPCWSTR lpDatabaseName, DWORD dwDesiredAccess);
#define OpenSCManager __MINGW_NAME_AW(OpenSCManager)
  WINADVAPI SC_HANDLE             WINAPI OpenServiceA(SC_HANDLE hSCManager, LPCSTR lpServiceName, DWORD dwDesiredAccess);
  WINADVAPI SC_HANDLE             WINAPI OpenServiceW(SC_HANDLE hSCManager, LPCWSTR lpServiceName, DWORD dwDesiredAccess);
#define OpenService __MINGW_NAME_AW(OpenService)
  WINADVAPI WINBOOL               WINAPI QueryServiceConfigA(SC_HANDLE hService, LPQUERY_SERVICE_CONFIGA lpServiceConfig, DWORD cbBufSize, LPDWORD pcbBytesNeeded);
  WINADVAPI WINBOOL               WINAPI QueryServiceConfigW(SC_HANDLE hService, LPQUERY_SERVICE_CONFIGW lpServiceConfig, DWORD cbBufSize, LPDWORD pcbBytesNeeded);
#define QueryServiceConfig __MINGW_NAME_AW(QueryServiceConfig)
  WINADVAPI WINBOOL               WINAPI QueryServiceConfig2A(SC_HANDLE hService, DWORD dwInfoLevel, LPBYTE lpBuffer, DWORD cbBufSize, LPDWORD pcbBytesNeeded);
  WINADVAPI WINBOOL               WINAPI QueryServiceConfig2W(SC_HANDLE hService, DWORD dwInfoLevel, LPBYTE lpBuffer, DWORD cbBufSize, LPDWORD pcbBytesNeeded);
#define QueryServiceConfig2 __MINGW_NAME_AW(QueryServiceConfig2)
  WINADVAPI WINBOOL               WINAPI QueryServiceObjectSecurity(SC_HANDLE hService, SECURITY_INFORMATION dwSecurityInformation, PSECURITY_DESCRIPTOR lpSecurityDescriptor, DWORD cbBufSize, LPDWORD pcbBytesNeeded);
  WINADVAPI WINBOOL               WINAPI QueryServiceStatus(SC_HANDLE hService, LPSERVICE_STATUS lpServiceStatus);
  WINADVAPI WINBOOL               WINAPI QueryServiceStatusEx(SC_HANDLE hService, SC_STATUS_TYPE InfoLevel, LPBYTE lpBuffer, DWORD cbBufSize, LPDWORD pcbBytesNeeded);
  WINADVAPI SERVICE_STATUS_HANDLE WINAPI RegisterServiceCtrlHandlerA(LPCSTR lpServiceName, LPHANDLER_FUNCTION lpHandlerProc);
  WINADVAPI SERVICE_STATUS_HANDLE WINAPI RegisterServiceCtrlHandlerW(LPCWSTR lpServiceName, LPHANDLER_FUNCTION lpHandlerProc);
#define RegisterServiceCtrlHandler __MINGW_NAME_AW(RegisterServiceCtrlHandler)
  WINADVAPI SERVICE_STATUS_HANDLE WINAPI RegisterServiceCtrlHandlerExA(LPCSTR lpServiceName, LPHANDLER_FUNCTION_EX lpHandlerProc, LPVOID lpContext);
  WINADVAPI SERVICE_STATUS_HANDLE WINAPI RegisterServiceCtrlHandlerExW(LPCWSTR lpServiceName, LPHANDLER_FUNCTION_EX lpHandlerProc, LPVOID lpContext);
#define RegisterServiceCtrlHandlerEx __MINGW_NAME_AW(RegisterServiceCtrlHandlerEx)
  WINADVAPI WINBOOL               WINAPI SetServiceObjectSecurity(SC_HANDLE hService, SECURITY_INFORMATION dwSecurityInformation, PSECURITY_DESCRIPTOR lpSecurityDescriptor);
  WINADVAPI WINBOOL               WINAPI SetServiceStatus(SERVICE_STATUS_HANDLE hServiceStatus, LPSERVICE_STATUS lpServiceStatus);
  WINADVAPI WINBOOL               WINAPI StartServiceCtrlDispatcherA(CONST SERVICE_TABLE_ENTRYA *lpServiceStartTable);
  WINADVAPI WINBOOL               WINAPI StartServiceCtrlDispatcherW(CONST SERVICE_TABLE_ENTRYW *lpServiceStartTable);
#define StartServiceCtrlDispatcher __MINGW_NAME_AW(StartServiceCtrlDispatcher)
  WINADVAPI WINBOOL               WINAPI StartServiceA(SC_HANDLE hService, DWORD dwNumServiceArgs, LPCSTR *lpServiceArgVectors);
  WINADVAPI WINBOOL               WINAPI StartServiceW(SC_HANDLE hService, DWORD dwNumServiceArgs, LPCWSTR *lpServiceArgVectors);
#define StartService __MINGW_NAME_AW(StartService)
  WINADVAPI DWORD                 WINAPI NotifyServiceStatusChangeA(SC_HANDLE hService, DWORD dwNotifyMask, PSERVICE_NOTIFYA pNotifyBuffer);
  WINADVAPI DWORD                 WINAPI NotifyServiceStatusChangeW(SC_HANDLE hService, DWORD dwNotifyMask, PSERVICE_NOTIFYW pNotifyBuffer);
#define NotifyServiceStatusChange __MINGW_NAME_AW(NotifyServiceStatusChange)
  WINADVAPI WINBOOL               WINAPI ControlServiceExA(SC_HANDLE hService, DWORD dwControl, DWORD dwInfoLevel, PVOID pControlParams);
  WINADVAPI WINBOOL               WINAPI ControlServiceExW(SC_HANDLE hService, DWORD dwControl, DWORD dwInfoLevel, PVOID pControlParams);
#define ControlServiceEx __MINGW_NAME_AW(ControlServiceEx)
  WINADVAPI WINBOOL               WINAPI QueryServiceDynamicInformation(SERVICE_STATUS_HANDLE hServiceStatus, DWORD dwInfoLevel, PVOID *ppDynamicInfo);

  typedef enum _SC_EVENT_TYPE
  {
    SC_EVENT_DATABASE_CHANGE,
    SC_EVENT_PROPERTY_CHANGE,
    SC_EVENT_STATUS_CHANGE
  } SC_EVENT_TYPE, *PSC_EVENT_TYPE;

  typedef VOID CALLBACK                         SC_NOTIFICATION_CALLBACK(DWORD dwNotify, PVOID pCallbackContext);
  typedef SC_NOTIFICATION_CALLBACK*             PSC_NOTIFICATION_CALLBACK;
  typedef struct _SC_NOTIFICATION_REGISTRATION* PSC_NOTIFICATION_REGISTRATION;

  WINADVAPI DWORD WINAPI SubscribeServiceChangeNotifications(SC_HANDLE hService, SC_EVENT_TYPE eEventType, PSC_NOTIFICATION_CALLBACK pCallback, PVOID pCallbackContext, PSC_NOTIFICATION_REGISTRATION *pSubscription);
  WINADVAPI VOID  WINAPI UnsubscribeServiceChangeNotifications(PSC_NOTIFICATION_REGISTRATION pSubscription);
  WINADVAPI DWORD WINAPI WaitServiceState(SC_HANDLE hService, DWORD dwNotify, DWORD dwTimeout, HANDLE hCancelEvent);

  typedef enum SERVICE_REGISTRY_STATE_TYPE
  {
    ServiceRegistryStateParameters = 0,
    ServiceRegistryStatePersistent = 1,
    MaxServiceRegistryStateType    = 2,
  } SERVICE_REGISTRY_STATE_TYPE;

  DWORD WINAPI GetServiceRegistryStateKey(SERVICE_STATUS_HANDLE ServiceStatusHandle, SERVICE_REGISTRY_STATE_TYPE StateType, DWORD AccessMask, HKEY *ServiceStateKey);

  typedef enum SERVICE_DIRECTORY_TYPE
  {
    ServiceDirectoryPersistentState = 0,
    ServiceDirectoryTypeMax         = 1,
  } SERVICE_DIRECTORY_TYPE;

  DWORD WINAPI GetServiceDirectory(SERVICE_STATUS_HANDLE hServiceStatus, SERVICE_DIRECTORY_TYPE eDirectoryType, PWCHAR lpPathBuffer, DWORD cchPathBufferLength, DWORD *lpcchRequiredBufferLength);

  typedef enum SERVICE_SHARED_REGISTRY_STATE_TYPE
  {
    ServiceSharedRegistryPersistentState = 0
  } SERVICE_SHARED_REGISTRY_STATE_TYPE;

  DWORD WINAPI GetSharedServiceRegistryStateKey(SC_HANDLE ServiceHandle, SERVICE_SHARED_REGISTRY_STATE_TYPE StateType, DWORD AccessMask, HKEY *ServiceStateKey);

  typedef enum SERVICE_SHARED_DIRECTORY_TYPE
  {
    ServiceSharedDirectoryPersistentState = 0
  } SERVICE_SHARED_DIRECTORY_TYPE;

  DWORD WINAPI GetSharedServiceDirectory(SC_HANDLE ServiceHandle, SERVICE_SHARED_DIRECTORY_TYPE DirectoryType, PWCHAR PathBuffer, DWORD PathBufferLength, DWORD *RequiredBufferLength);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

  WINADVAPI WINBOOL WINAPI EnumServicesStatusA(SC_HANDLE hSCManager, DWORD dwServiceType, DWORD dwServiceState, LPENUM_SERVICE_STATUSA lpServices, DWORD cbBufSize, LPDWORD pcbBytesNeeded, LPDWORD lpServicesReturned, LPDWORD lpResumeHandle);
  WINADVAPI WINBOOL WINAPI EnumServicesStatusW(SC_HANDLE hSCManager, DWORD dwServiceType, DWORD dwServiceState, LPENUM_SERVICE_STATUSW lpServices, DWORD cbBufSize, LPDWORD pcbBytesNeeded, LPDWORD lpServicesReturned, LPDWORD lpResumeHandle);
#define EnumServicesStatus __MINGW_NAME_AW(EnumServicesStatus)
  WINADVAPI SC_LOCK WINAPI LockServiceDatabase(SC_HANDLE hSCManager);
  WINADVAPI WINBOOL WINAPI NotifyBootConfigStatus(WINBOOL BootAcceptable);
  WINADVAPI WINBOOL WINAPI QueryServiceLockStatusA(SC_HANDLE hSCManager, LPQUERY_SERVICE_LOCK_STATUSA lpLockStatus, DWORD cbBufSize, LPDWORD pcbBytesNeeded);
  WINADVAPI WINBOOL WINAPI QueryServiceLockStatusW(SC_HANDLE hSCManager, LPQUERY_SERVICE_LOCK_STATUSW lpLockStatus, DWORD cbBufSize, LPDWORD pcbBytesNeeded);
#define QueryServiceLockStatus __MINGW_NAME_AW(QueryServiceLockStatus)
  WINADVAPI WINBOOL WINAPI UnlockServiceDatabase(SC_LOCK ScLock);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */

#ifdef __cplusplus
}
#endif

#endif  /* _WINSVC_ */
