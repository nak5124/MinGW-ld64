#include <winapifamily.h>
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __RPCASYNC_H__
#define __RPCASYNC_H__

#include <_mingw_unicode.h>

#ifdef __RPC_WIN64__
# include <pshpack8.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

#ifdef RPC_NO_WINDOWS_H
# include <windef.h>
#endif

#define RPC_ASYNC_VERSION_1_0 sizeof(RPC_ASYNC_STATE)

  typedef enum _RPC_NOTIFICATION_TYPES
  {
    RpcNotificationTypeNone,
    RpcNotificationTypeEvent,
    RpcNotificationTypeApc,
    RpcNotificationTypeIoc,
    RpcNotificationTypeHwnd,
    RpcNotificationTypeCallback
  } RPC_NOTIFICATION_TYPES;

  typedef enum _RPC_ASYNC_EVENT
  {
    RpcCallComplete,
    RpcSendComplete,
    RpcReceiveComplete,
    RpcClientDisconnect,
    RpcClientCancel
  } RPC_ASYNC_EVENT;

  struct _RPC_ASYNC_STATE;

  typedef void RPC_ENTRY RPCNOTIFICATION_ROUTINE(struct _RPC_ASYNC_STATE *pAsync, void *Context, RPC_ASYNC_EVENT Event);
  typedef RPCNOTIFICATION_ROUTINE *PFN_RPCNOTIFICATION_ROUTINE;

  typedef union _RPC_ASYNC_NOTIFICATION_INFO
  {
    struct
    {
      PFN_RPCNOTIFICATION_ROUTINE NotificationRoutine;
      HANDLE                      hThread;
    } APC;
#if !defined(RPC_NO_WINDOWS_H) || defined (_WINBASE_)
    struct
    {
      HANDLE       hIOPort;
      DWORD        dwNumberOfBytesTransferred;
      DWORD_PTR    dwCompletionKey;
      LPOVERLAPPED lpOverlapped;
    } IOC;
#endif
#ifndef RPC_NO_WINDOWS_H
    struct
    {
      HWND hWnd;
      UINT Msg;
    } HWND;
#endif
    HANDLE                      hEvent;
    PFN_RPCNOTIFICATION_ROUTINE NotificationRoutine;
  } RPC_ASYNC_NOTIFICATION_INFO, *PRPC_ASYNC_NOTIFICATION_INFO;

  typedef struct _RPC_ASYNC_STATE
  {
    unsigned int                 Size;
    unsigned long                Signature;
    long                         Lock;
    unsigned long                Flags;
    void                        *StubInfo;
    void                        *UserInfo;
    void                        *RuntimeInfo;
    RPC_ASYNC_EVENT              Event;
    RPC_NOTIFICATION_TYPES       NotificationType;
    RPC_ASYNC_NOTIFICATION_INFO  u;
    LONG_PTR                     Reserved[4];
  } RPC_ASYNC_STATE, *PRPC_ASYNC_STATE;

#define RPC_C_NOTIFY_ON_SEND_COMPLETE 0x1
#define RPC_C_INFINITE_TIMEOUT        INFINITE

#define RpcAsyncGetCallHandle(pAsync) (((PRPC_ASYNC_STATE)pAsync)->RuntimeInfo)

  RPCRTAPI RPC_STATUS RPC_ENTRY RpcAsyncRegisterInfo(PRPC_ASYNC_STATE pAsync);
  RPCRTAPI RPC_STATUS RPC_ENTRY RpcAsyncInitializeHandle(PRPC_ASYNC_STATE pAsync, unsigned int Size);
  RPCRTAPI RPC_STATUS RPC_ENTRY RpcAsyncGetCallStatus(PRPC_ASYNC_STATE pAsync);
  RPCRTAPI RPC_STATUS RPC_ENTRY RpcAsyncCompleteCall(PRPC_ASYNC_STATE pAsync, void *Reply);
  RPCRTAPI RPC_STATUS RPC_ENTRY RpcAsyncAbortCall(PRPC_ASYNC_STATE pAsync, unsigned long ExceptionCode);
  RPCRTAPI RPC_STATUS RPC_ENTRY RpcAsyncCancelCall(PRPC_ASYNC_STATE pAsync, WINBOOL fAbort);

#if !defined(RPC_NO_WINDOWS_H) || defined(_WINBASE_)

  typedef enum tagExtendedErrorParamTypes
  {
    eeptAnsiString = 1,
    eeptUnicodeString,
    eeptLongVal,
    eeptShortVal,
    eeptPointerVal,
    eeptNone,
    eeptBinary
  } ExtendedErrorParamTypes;

#define MaxNumberOfEEInfoParams 4
#define RPC_EEINFO_VERSION      1

  typedef struct tagBinaryParam
  {
    void  *Buffer;
    short  Size;
  } BinaryParam;

  typedef struct tagRPC_EE_INFO_PARAM
  {
    ExtendedErrorParamTypes ParameterType;
    union
    {
      LPSTR       AnsiString;
      LPWSTR      UnicodeString;
      long        LVal;
      short       SVal;
      ULONGLONG   PVal;
      BinaryParam BVal;
    } u;
  } RPC_EE_INFO_PARAM;

#define EEInfoPreviousRecordsMissing 1
#define EEInfoNextRecordsMissing     2
#define EEInfoUseFileTime            4
#define EEInfoGCCOM                  11
#define EEInfoGCFRS                  12

  typedef struct tagRPC_EXTENDED_ERROR_INFO
  {
    ULONG  Version;
    LPWSTR ComputerName;
    ULONG  ProcessID;
    union
    {
      SYSTEMTIME SystemTime;
      FILETIME   FileTime;
    } u;
    ULONG             GeneratingComponent;
    ULONG             Status;
    USHORT            DetectionLocation;
    USHORT            Flags;
    int               NumberOfParameters;
    RPC_EE_INFO_PARAM Parameters[MaxNumberOfEEInfoParams];
  } RPC_EXTENDED_ERROR_INFO;

  typedef struct tagRPC_ERROR_ENUM_HANDLE
  {
    ULONG  Signature;
    void  *CurrentPos;
    void  *Head;
  } RPC_ERROR_ENUM_HANDLE;

  RPCRTAPI RPC_STATUS RPC_ENTRY RpcErrorStartEnumeration(RPC_ERROR_ENUM_HANDLE *EnumHandle);
  RPCRTAPI RPC_STATUS RPC_ENTRY RpcErrorGetNextRecord(RPC_ERROR_ENUM_HANDLE *EnumHandle, WINBOOL CopyStrings, RPC_EXTENDED_ERROR_INFO *ErrorInfo);
  RPCRTAPI RPC_STATUS RPC_ENTRY RpcErrorEndEnumeration(RPC_ERROR_ENUM_HANDLE *EnumHandle);
  RPCRTAPI RPC_STATUS RPC_ENTRY RpcErrorResetEnumeration(RPC_ERROR_ENUM_HANDLE *EnumHandle);
  RPCRTAPI RPC_STATUS RPC_ENTRY RpcErrorGetNumberOfRecords(RPC_ERROR_ENUM_HANDLE *EnumHandle, int *Records);
  RPCRTAPI RPC_STATUS RPC_ENTRY RpcErrorSaveErrorInfo(RPC_ERROR_ENUM_HANDLE *EnumHandle, PVOID *ErrorBlob, size_t *BlobSize);
  RPCRTAPI RPC_STATUS RPC_ENTRY RpcErrorLoadErrorInfo(PVOID ErrorBlob, size_t BlobSize, RPC_ERROR_ENUM_HANDLE *EnumHandle);
  RPCRTAPI RPC_STATUS RPC_ENTRY RpcErrorAddRecord(RPC_EXTENDED_ERROR_INFO *ErrorInfo);
  RPCRTAPI void       RPC_ENTRY RpcErrorClearInformation(void);

#endif

  RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingBind(PRPC_ASYNC_STATE pAsync, RPC_BINDING_HANDLE Binding, RPC_IF_HANDLE IfSpec);
  RPCRTAPI RPC_STATUS RPC_ENTRY RpcBindingUnbind(RPC_BINDING_HANDLE Binding);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  RPCRTAPI RPC_STATUS RPC_ENTRY RpcGetAuthorizationContextForClient(RPC_BINDING_HANDLE ClientBinding, WINBOOL ImpersonateOnReturn, PVOID Reserved1, PLARGE_INTEGER pExpirationTime, LUID Reserved2, DWORD Reserved3, PVOID Reserved4, PVOID *pAuthzClientContext);
  RPCRTAPI RPC_STATUS RPC_ENTRY RpcFreeAuthorizationContext(PVOID *pAuthzClientContext);
  RPCRTAPI RPC_STATUS RPC_ENTRY RpcSsContextLockExclusive(RPC_BINDING_HANDLE ServerBindingHandle, PVOID UserContext);
  RPCRTAPI RPC_STATUS RPC_ENTRY RpcSsContextLockShared(RPC_BINDING_HANDLE ServerBindingHandle, PVOID UserContext);

  typedef enum tagRpcLocalAddressFormat
  {
    rlafInvalid = 0,
    rlafIPv4,
    rlafIPv6
  } RpcLocalAddressFormat;

  typedef struct _RPC_CALL_LOCAL_ADDRESS_V1
  {
    unsigned int           Version;
    void                  *Buffer;
    unsigned long          BufferSize;
    RpcLocalAddressFormat  AddressFormat;
  } RPC_CALL_LOCAL_ADDRESS_V1, *PRPC_CALL_LOCAL_ADDRESS_V1;

#define RPC_QUERY_SERVER_PRINCIPAL_NAME (0x02)
#define RPC_QUERY_CLIENT_PRINCIPAL_NAME (0x04)
#define RPC_QUERY_CALL_LOCAL_ADDRESS    (0x08)
#define RPC_QUERY_CLIENT_PID            (0x10)
#define RPC_QUERY_IS_CLIENT_LOCAL       (0x20)
#define RPC_QUERY_NO_AUTH_REQUIRED      (0x40)
#define RPC_CALL_ATTRIBUTES_VERSION     (3)
#define RPC_QUERY_CLIENT_ID             (0x80)

  typedef struct tagRPC_CALL_ATTRIBUTES_V1_A
  {
    unsigned int   Version;
    unsigned long  Flags;
    unsigned long  ServerPrincipalNameBufferLength;
    unsigned char *ServerPrincipalName;
    unsigned long  ClientPrincipalNameBufferLength;
    unsigned char *ClientPrincipalName;
    unsigned long  AuthenticationLevel;
    unsigned long  AuthenticationService;
    WINBOOL        NullSession;
  } RPC_CALL_ATTRIBUTES_V1_A;

  typedef struct tagRPC_CALL_ATTRIBUTES_V1_W
  {
    unsigned int    Version;
    unsigned long   Flags;
    unsigned long   ServerPrincipalNameBufferLength;
    unsigned short *ServerPrincipalName;
    unsigned long   ClientPrincipalNameBufferLength;
    unsigned short *ClientPrincipalName;
    unsigned long   AuthenticationLevel;
    unsigned long   AuthenticationService;
    WINBOOL         NullSession;
  } RPC_CALL_ATTRIBUTES_V1_W;

#define RPC_CALL_ATTRIBUTES_V1 __MINGW_NAME_UAW(RPC_CALL_ATTRIBUTES_V1)

#define RPC_CALL_STATUS_CANCELLED    0x01
#define RPC_CALL_STATUS_DISCONNECTED 0x02

  typedef enum tagRpcCallType
  {
    rctInvalid = 0,
    rctNormal,
    rctTraining,
    rctGuaranteed
  } RpcCallType;

  typedef enum tagRpcCallClientLocality
  {
    rcclInvalid = 0,
    rcclLocal,
    rcclRemote,
    rcclClientUnknownLocality
  } RpcCallClientLocality;

  typedef struct tagRPC_CALL_ATTRIBUTES_V2_A
  {
    unsigned int               Version;
    unsigned long              Flags;
    unsigned long              ServerPrincipalNameBufferLength;
    unsigned char             *ServerPrincipalName;
    unsigned long              ClientPrincipalNameBufferLength;
    unsigned char             *ClientPrincipalName;
    unsigned long              AuthenticationLevel;
    unsigned long              AuthenticationService;
    WINBOOL                    NullSession;
    WINBOOL                    KernelModeCaller;
    unsigned long              ProtocolSequence;
    unsigned long              IsClientLocal;
    HANDLE                     ClientPID;
    unsigned long              CallStatus;
    RpcCallType                CallType;
    RPC_CALL_LOCAL_ADDRESS_V1 *CallLocalAddress;
    unsigned short             OpNum;
    UUID                       InterfaceUuid;
  } RPC_CALL_ATTRIBUTES_V2_A;

  typedef struct tagRPC_CALL_ATTRIBUTES_V2_W
  {
    unsigned int               Version;
    unsigned long              Flags;
    unsigned long              ServerPrincipalNameBufferLength;
    unsigned short            *ServerPrincipalName;
    unsigned long              ClientPrincipalNameBufferLength;
    unsigned short            *ClientPrincipalName;
    unsigned long              AuthenticationLevel;
    unsigned long              AuthenticationService;
    WINBOOL                    NullSession;
    WINBOOL                    KernelModeCaller;
    unsigned long              ProtocolSequence;
    RpcCallClientLocality      IsClientLocal;
    HANDLE                     ClientPID;
    unsigned long              CallStatus;
    RpcCallType                CallType;
    RPC_CALL_LOCAL_ADDRESS_V1 *CallLocalAddress;
    unsigned short             OpNum;
    UUID                       InterfaceUuid;
  } RPC_CALL_ATTRIBUTES_V2_W;

#define RPC_CALL_ATTRIBUTES_V2 __MINGW_NAME_UAW(RPC_CALL_ATTRIBUTES_V2)

  typedef struct tagRPC_CALL_ATTRIBUTES_V3_A
  {
    unsigned int               Version;
    unsigned long              Flags;
    unsigned long              ServerPrincipalNameBufferLength;
    unsigned char             *ServerPrincipalName;
    unsigned long              ClientPrincipalNameBufferLength;
    unsigned char             *ClientPrincipalName;
    unsigned long              AuthenticationLevel;
    unsigned long              AuthenticationService;
    WINBOOL                    NullSession;
    WINBOOL                    KernelModeCaller;
    unsigned long              ProtocolSequence;
    unsigned long              IsClientLocal;
    HANDLE                     ClientPID;
    unsigned long              CallStatus;
    RpcCallType                CallType;
    RPC_CALL_LOCAL_ADDRESS_V1 *CallLocalAddress;
    unsigned short             OpNum;
    UUID                       InterfaceUuid;
    unsigned long              ClientIdentifierBufferLength;
    unsigned char             *ClientIdentifier;
  } RPC_CALL_ATTRIBUTES_V3_A;

  typedef struct tagRPC_CALL_ATTRIBUTES_V3_W
  {
    unsigned int               Version;
    unsigned long              Flags;
    unsigned long              ServerPrincipalNameBufferLength;
    unsigned short            *ServerPrincipalName;
    unsigned long              ClientPrincipalNameBufferLength;
    unsigned short            *ClientPrincipalName;
    unsigned long              AuthenticationLevel;
    unsigned long              AuthenticationService;
    WINBOOL                    NullSession;
    WINBOOL                    KernelModeCaller;
    unsigned long              ProtocolSequence;
    RpcCallClientLocality      IsClientLocal;
    HANDLE                     ClientPID;
    unsigned long              CallStatus;
    RpcCallType                CallType;
    RPC_CALL_LOCAL_ADDRESS_V1 *CallLocalAddress;
    unsigned short             OpNum;
    UUID                       InterfaceUuid;
    unsigned long              ClientIdentifierBufferLength;
    unsigned char             *ClientIdentifier;
  } RPC_CALL_ATTRIBUTES_V3_W;

#define RPC_CALL_ATTRIBUTES_V3 __MINGW_NAME_UAW(RPC_CALL_ATTRIBUTES_V3)

  RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerInqCallAttributesA(RPC_BINDING_HANDLE ClientBinding, void *RpcCallAttributes);
  RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerInqCallAttributesW(RPC_BINDING_HANDLE ClientBinding, void *RpcCallAttributes);
#define RpcServerInqCallAttributes __MINGW_NAME_AW(RpcServerInqCallAttributes)

  typedef RPC_CALL_ATTRIBUTES_V3 RPC_CALL_ATTRIBUTES;

  typedef enum _RPC_NOTIFICATIONS
  {
    RpcNotificationCallNone         = 0,
    RpcNotificationClientDisconnect = 1,
    RpcNotificationCallCancel       = 2
  } RPC_NOTIFICATIONS;

#define RpcNotificationCallStatusChange RpcNotificationClientDisconnect

  RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerSubscribeForNotification(RPC_BINDING_HANDLE Binding, RPC_NOTIFICATIONS Notification, RPC_NOTIFICATION_TYPES NotificationType, RPC_ASYNC_NOTIFICATION_INFO *NotificationInfo);
  RPCRTAPI RPC_STATUS RPC_ENTRY RpcServerUnsubscribeForNotification(RPC_BINDING_HANDLE Binding, RPC_NOTIFICATIONS Notification, unsigned long *NotificationsQueued);
  /**/     RPC_STATUS RPC_ENTRY I_RpcAsyncSetHandle(PRPC_MESSAGE Message, PRPC_ASYNC_STATE pAsync);
  /**/     RPC_STATUS RPC_ENTRY I_RpcAsyncAbortCall(PRPC_ASYNC_STATE pAsync, unsigned long ExceptionCode);
  /**/     int        RPC_ENTRY I_RpcExceptionFilter(unsigned long ExceptionCode);
  RPCRTAPI RPC_STATUS RPC_ENTRY I_RpcBindingInqClientTokenAttributes(RPC_BINDING_HANDLE Binding, LUID *TokenId, LUID *AuthenticationId, LUID *ModifiedId);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#ifdef __cplusplus
}
#endif

#ifdef __RPC_WIN64__
# include <poppack.h>
#endif

#endif  /* __RPCASYNC_H__ */
