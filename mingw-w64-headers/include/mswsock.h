/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <winsock2.h>

#ifndef _MSWSOCK_
#define _MSWSOCK_

#include <_mingw.h>
#include <winapifamily.h>

#ifndef _WINSOCK_DEPRECATED_BY
# define _WINSOCK_DEPRECATED_BY(replacement)
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <mswsockdef.h>

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#define SO_CONNDATA             0x7000
#define SO_CONNOPT              0x7001
#define SO_DISCDATA             0x7002
#define SO_DISCOPT              0x7003
#define SO_CONNDATALEN          0x7004
#define SO_CONNOPTLEN           0x7005
#define SO_DISCDATALEN          0x7006
#define SO_DISCOPTLEN           0x7007
#define SO_OPENTYPE             0x7008
#define SO_SYNCHRONOUS_ALERT    0x10
#define SO_SYNCHRONOUS_NONALERT 0x20

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#define SO_MAXDG                  0x7009
#define SO_MAXPATHDG              0x700A
#define SO_UPDATE_ACCEPT_CONTEXT  0x700B
#define SO_CONNECT_TIME           0x700C
#define SO_UPDATE_CONNECT_CONTEXT 0x7010

#define TCP_BSDURGENT 0x7000

#define SIO_UDP_CONNRESET _WSAIOW(IOC_VENDOR, 12)
#define SIO_UDP_NETRESET  _WSAIOW(IOC_VENDOR, 15)

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#ifndef __MSWSOCK_WS1_SHARED
  INT PASCAL WSARecvEx(SOCKET s, CHAR *buf, INT len, INT *flags);
#endif /* __MSWSOCK_WS1_SHARED */

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#include <psdk_inc/_xmitfile.h>

#define TF_DISCONNECT         0x01
#define TF_REUSE_SOCKET       0x02
#define TF_WRITE_BEHIND       0x04
#define TF_USE_DEFAULT_WORKER 0x00
#define TF_USE_SYSTEM_THREAD  0x10
#define TF_USE_KERNEL_APC     0x20

#ifndef __MSWSOCK_WS1_SHARED
  WINBOOL PASCAL TransmitFile(SOCKET hSocket, HANDLE hFile, DWORD nNumberOfBytesToWrite, DWORD nNumberOfBytesPerSend, LPOVERLAPPED lpOverlapped, LPTRANSMIT_FILE_BUFFERS lpTransmitBuffers, DWORD dwReserved);
  WINBOOL PASCAL AcceptEx(SOCKET sListenSocket, SOCKET sAcceptSocket, PVOID lpOutputBuffer, DWORD dwReceiveDataLength, DWORD dwLocalAddressLength, DWORD dwRemoteAddressLength, LPDWORD lpdwBytesReceived, LPOVERLAPPED lpOverlapped);
  VOID    PASCAL GetAcceptExSockaddrs(PVOID lpOutputBuffer, DWORD dwReceiveDataLength, DWORD dwLocalAddressLength, DWORD dwRemoteAddressLength, struct sockaddr **LocalSockaddr, LPINT LocalSockaddrLength, struct sockaddr **RemoteSockaddr, LPINT RemoteSockaddrLength);
#endif  /* __MSWSOCK_WS1_SHARED */

  typedef WINBOOL (PASCAL *LPFN_TRANSMITFILE)(SOCKET hSocket, HANDLE hFile, DWORD nNumberOfBytesToWrite, DWORD nNumberOfBytesPerSend, LPOVERLAPPED lpOverlapped, LPTRANSMIT_FILE_BUFFERS lpTransmitBuffers, DWORD dwReserved);

#define WSAID_TRANSMITFILE {0xb5367df0, 0xcbac, 0x11cf, {0x95, 0xca, 0x00, 0x80, 0x5f, 0x48, 0xa1, 0x92}}

  typedef WINBOOL (PASCAL *LPFN_ACCEPTEX)(SOCKET sListenSocket, SOCKET sAcceptSocket, PVOID lpOutputBuffer, DWORD dwReceiveDataLength, DWORD dwLocalAddressLength, DWORD dwRemoteAddressLength, LPDWORD lpdwBytesReceived, LPOVERLAPPED lpOverlapped);

#define WSAID_ACCEPTEX {0xb5367df1, 0xcbac, 0x11cf, {0x95, 0xca, 0x00, 0x80, 0x5f, 0x48, 0xa1, 0x92}}

  typedef VOID (PASCAL *LPFN_GETACCEPTEXSOCKADDRS)(PVOID lpOutputBuffer, DWORD dwReceiveDataLength, DWORD dwLocalAddressLength, DWORD dwRemoteAddressLength, struct sockaddr **LocalSockaddr, LPINT LocalSockaddrLength, struct sockaddr **RemoteSockaddr, LPINT RemoteSockaddrLength);

#define WSAID_GETACCEPTEXSOCKADDRS {0xb5367df2, 0xcbac, 0x11cf, {0x95, 0xca, 0x00, 0x80, 0x5f, 0x48, 0xa1, 0x92}}

  typedef struct _TRANSMIT_PACKETS_ELEMENT
  {
    ULONG dwElFlags;
#define TP_ELEMENT_MEMORY 1
#define TP_ELEMENT_FILE   2
#define TP_ELEMENT_EOP    4
    ULONG cLength;
    __C89_NAMELESS union
    {
      __C89_NAMELESS struct
      {
        LARGE_INTEGER nFileOffset;
        HANDLE        hFile;
      };
      PVOID pBuffer;
    };
  } TRANSMIT_PACKETS_ELEMENT, *PTRANSMIT_PACKETS_ELEMENT, *LPTRANSMIT_PACKETS_ELEMENT;

#define TP_DISCONNECT         TF_DISCONNECT
#define TP_REUSE_SOCKET       TF_REUSE_SOCKET
#define TP_USE_DEFAULT_WORKER TF_USE_DEFAULT_WORKER
#define TP_USE_SYSTEM_THREAD  TF_USE_SYSTEM_THREAD
#define TP_USE_KERNEL_APC     TF_USE_KERNEL_APC

  typedef WINBOOL (PASCAL *LPFN_TRANSMITPACKETS)(SOCKET hSocket, LPTRANSMIT_PACKETS_ELEMENT lpPacketArray, DWORD nElementCount, DWORD nSendSize, LPOVERLAPPED lpOverlapped, DWORD dwFlags);

#define WSAID_TRANSMITPACKETS {0xd9689da0, 0x1f90, 0x11d3, {0x99, 0x71, 0x00, 0xc0, 0x4f, 0x68, 0xc8, 0x76}}

  typedef WINBOOL (PASCAL *LPFN_CONNECTEX)(SOCKET s, const struct sockaddr *name, int namelen, PVOID lpSendBuffer, DWORD dwSendDataLength, LPDWORD lpdwBytesSent, LPOVERLAPPED lpOverlapped);

#define WSAID_CONNECTEX {0x25a207b9, 0xddf3, 0x4660, {0x8e, 0xe9, 0x76, 0xe5, 0x8c, 0x74, 0x06, 0x3e}}

  typedef WINBOOL (PASCAL *LPFN_DISCONNECTEX)(SOCKET s, LPOVERLAPPED lpOverlapped, DWORD dwFlags, DWORD dwReserved);

#define WSAID_DISCONNECTEX {0x7fda2e11, 0x8630, 0x436f, {0xa0, 0x31, 0xf5, 0x36, 0xa6, 0xee, 0xc1, 0x57}}

#define DE_REUSE_SOCKET TF_REUSE_SOCKET

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#define NLA_NAMESPACE_GUID     {0x6642243a, 0x3ba8, 0x4aa6, {0xba, 0xa5, 0x2e, 0xb, 0xd7, 0x1f, 0xdd, 0x83}}
#define NLA_SERVICE_CLASS_GUID {0x37e515, 0xb5c9, 0x4a43, {0xba, 0xda, 0x8b, 0x48, 0xa8, 0x7a, 0xd2, 0x39}}

#define NLA_ALLUSERS_NETWORK 0x00000001
#define NLA_FRIENDLY_NAME    0x00000002

  typedef enum _NLA_BLOB_DATA_TYPE
  {
    NLA_RAW_DATA        = 0,
    NLA_INTERFACE       = 1,
    NLA_802_1X_LOCATION = 2,
    NLA_CONNECTIVITY    = 3,
    NLA_ICS             = 4,
  } NLA_BLOB_DATA_TYPE, *PNLA_BLOB_DATA_TYPE;

  typedef enum _NLA_CONNECTIVITY_TYPE
  {
    NLA_NETWORK_AD_HOC    = 0,
    NLA_NETWORK_MANAGED   = 1,
    NLA_NETWORK_UNMANAGED = 2,
    NLA_NETWORK_UNKNOWN   = 3,
  } NLA_CONNECTIVITY_TYPE, *PNLA_CONNECTIVITY_TYPE;

  typedef enum _NLA_INTERNET
  {
    NLA_INTERNET_UNKNOWN = 0,
    NLA_INTERNET_NO      = 1,
    NLA_INTERNET_YES     = 2,
  } NLA_INTERNET, *PNLA_INTERNET;

  typedef struct _NLA_BLOB
  {
    struct
    {
      NLA_BLOB_DATA_TYPE type;
      DWORD              dwSize;
      DWORD              nextOffset;
    } header;
    union
    {
      CHAR rawData[1];
      struct
      {
        DWORD dwType;
        DWORD dwSpeed;
        CHAR  adapterName[1];
      } interfaceData;
      struct
      {
        CHAR information[1];
      } locationData;
      struct
      {
        NLA_CONNECTIVITY_TYPE type;
        NLA_INTERNET          internet;
      } connectivity;
      struct
      {
        struct
        {
          DWORD speed;
          DWORD type;
          DWORD state;
          WCHAR machineName[256];
          WCHAR sharedAdapterName[256];
        } remote;
      } ICS;
    } data;
  } NLA_BLOB, *PNLA_BLOB, *LPNLA_BLOB;

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

  typedef INT (PASCAL *LPFN_WSARECVMSG)(SOCKET s, LPWSAMSG lpMsg, LPDWORD lpdwNumberOfBytesRecvd, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);

#define WSAID_WSARECVMSG {0xf689d7c8, 0x6f1f, 0x436b, {0x8a, 0x53, 0xe5, 0x4f, 0xe3, 0x51, 0xc3, 0x22}}

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#define SIO_BSP_HANDLE        _WSAIOR(IOC_WS2, 27)
#define SIO_BSP_HANDLE_SELECT _WSAIOR(IOC_WS2, 28)
#define SIO_BSP_HANDLE_POLL   _WSAIOR(IOC_WS2, 29)
#define SIO_BASE_HANDLE       _WSAIOR(IOC_WS2, 34)

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#define SIO_EXT_SELECT  _WSAIORW(IOC_WS2, 30)
#define SIO_EXT_POLL    _WSAIORW(IOC_WS2, 31)
#define SIO_EXT_SENDMSG _WSAIORW(IOC_WS2, 32)

  typedef struct
  {
    int       result;
    ULONG     fds;
    INT       timeout;
    WSAPOLLFD fdArray[0];
  } WSAPOLLDATA, *LPWSAPOLLDATA;

  typedef struct
  {
    LPWSAMSG                           lpMsg;
    DWORD                              dwFlags;
    LPDWORD                            lpNumberOfBytesSent;
    LPWSAOVERLAPPED                    lpOverlapped;
    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine;
  } WSASENDMSG, *LPWSASENDMSG;

  typedef INT (PASCAL *LPFN_WSASENDMSG)(SOCKET s, LPWSAMSG lpMsg, DWORD dwFlags, LPDWORD lpNumberOfBytesSent, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);

#define WSAID_WSASENDMSG {0xa441e712, 0x754f, 0x43ca, {0x84, 0xa7, 0x0d, 0xee, 0x44, 0xcf, 0x60, 0x6d}}

  typedef INT (WSAAPI *LPFN_WSAPOLL)(LPWSAPOLLFD fdarray, ULONG nfds, INT timeout);

#define WSAID_WSAPOLL {0x18C76F85, 0xDC66, 0x4964, {0x97, 0x2E, 0x23, 0xC2, 0x72, 0x38, 0x31, 0x2B}}

  typedef WINBOOL (PASCAL *LPFN_RIORECEIVE)(RIO_RQ SocketQueue, PRIO_BUF pData, ULONG DataBufferCount, DWORD Flags, PVOID RequestContext);
  typedef int     (PASCAL *LPFN_RIORECEIVEEX)(RIO_RQ SocketQueue, PRIO_BUF pData, ULONG DataBufferCount, PRIO_BUF pLocalAddress, PRIO_BUF pRemoteAddress, PRIO_BUF pControlContext, PRIO_BUF pFlags, DWORD Flags, PVOID RequestContext);
  typedef WINBOOL (PASCAL *LPFN_RIOSEND)(RIO_RQ SocketQueue, PRIO_BUF pData, ULONG DataBufferCount, DWORD Flags, PVOID RequestContext);
  typedef WINBOOL (PASCAL *LPFN_RIOSENDEX)(RIO_RQ SocketQueue, PRIO_BUF pData, ULONG DataBufferCount, PRIO_BUF pLocalAddress, PRIO_BUF pRemoteAddress, PRIO_BUF pControlContext, PRIO_BUF pFlags, DWORD Flags, PVOID RequestContext);
  typedef VOID    (PASCAL *LPFN_RIOCLOSECOMPLETIONQUEUE)(RIO_CQ CQ);

  typedef enum _RIO_NOTIFICATION_COMPLETION_TYPE
  {
    RIO_EVENT_COMPLETION = 1,
    RIO_IOCP_COMPLETION  = 2,
  } RIO_NOTIFICATION_COMPLETION_TYPE, *PRIO_NOTIFICATION_COMPLETION_TYPE;

  typedef struct _RIO_NOTIFICATION_COMPLETION
  {
    RIO_NOTIFICATION_COMPLETION_TYPE Type;
    __C89_NAMELESS union
    {
      struct
      {
        HANDLE  EventHandle;
        WINBOOL NotifyReset;
      } Event;
      struct
      {
        HANDLE IocpHandle;
        PVOID  CompletionKey;
        PVOID  Overlapped;
      } Iocp;
    };
  } RIO_NOTIFICATION_COMPLETION, *PRIO_NOTIFICATION_COMPLETION;

  typedef RIO_CQ       (PASCAL *LPFN_RIOCREATECOMPLETIONQUEUE)(DWORD QueueSize, PRIO_NOTIFICATION_COMPLETION NotificationCompletion);
  typedef RIO_RQ       (PASCAL *LPFN_RIOCREATEREQUESTQUEUE)(SOCKET Socket, ULONG MaxOutstandingReceive, ULONG MaxReceiveDataBuffers, ULONG MaxOutstandingSend, ULONG MaxSendDataBuffers, RIO_CQ ReceiveCQ, RIO_CQ SendCQ, PVOID SocketContext);
  typedef ULONG        (PASCAL *LPFN_RIODEQUEUECOMPLETION)(RIO_CQ CQ, PRIORESULT Array, ULONG ArraySize);
  typedef VOID         (PASCAL *LPFN_RIODEREGISTERBUFFER)(RIO_BUFFERID BufferId);
  typedef INT          (PASCAL *LPFN_RIONOTIFY)(RIO_CQ CQ);
  typedef RIO_BUFFERID (PASCAL *LPFN_RIOREGISTERBUFFER)(PCHAR DataBuffer, DWORD DataLength);
  typedef WINBOOL      (PASCAL *LPFN_RIORESIZECOMPLETIONQUEUE)(RIO_CQ CQ, DWORD QueueSize);
  typedef WINBOOL      (PASCAL *LPFN_RIORESIZEREQUESTQUEUE)(RIO_RQ RQ, DWORD MaxOutstandingReceive, DWORD MaxOutstandingSend);

  typedef struct _RIO_EXTENSION_FUNCTION_TABLE
  {
    DWORD                         cbSize;
    LPFN_RIORECEIVE               RIOReceive;
    LPFN_RIORECEIVEEX             RIOReceiveEx;
    LPFN_RIOSEND                  RIOSend;
    LPFN_RIOSENDEX                RIOSendEx;
    LPFN_RIOCLOSECOMPLETIONQUEUE  RIOCloseCompletionQueue;
    LPFN_RIOCREATECOMPLETIONQUEUE RIOCreateCompletionQueue;
    LPFN_RIOCREATEREQUESTQUEUE    RIOCreateRequestQueue;
    LPFN_RIODEQUEUECOMPLETION     RIODequeueCompletion;
    LPFN_RIODEREGISTERBUFFER      RIODeregisterBuffer;
    LPFN_RIONOTIFY                RIONotify;
    LPFN_RIOREGISTERBUFFER        RIORegisterBuffer;
    LPFN_RIORESIZECOMPLETIONQUEUE RIOResizeCompletionQueue;
    LPFN_RIORESIZEREQUESTQUEUE    RIOResizeRequestQueue;
  } RIO_EXTENSION_FUNCTION_TABLE, *PRIO_EXTENSION_FUNCTION_TABLE;

#define WSAID_MULTIPLE_RIO {0x8509e081, 0x96dd, 0x4005, {0xb1, 0x65, 0x9e, 0x2e, 0xe8, 0xc7, 0x9e, 0x3f}}

#ifdef __cplusplus
}
#endif

#endif  /* _MSWSOCK_ */
