/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _WINSOCK2API_
#define _WINSOCK2API_

#ifndef _WINSOCKAPI_
# define _WINSOCKAPI_
#else
# warning Please include winsock2.h before windows.h
#endif

#include <_mingw_unicode.h>
#include <winapifamily.h>

#ifndef _WINSOCK_DEPRECATED_BY
# define _WINSOCK_DEPRECATED_BY(replacement)
#endif
#ifndef _WINSOCK_DEPRECATED
# define _WINSOCK_DEPRECATED
#endif

#ifndef INCL_WINSOCK_API_PROTOTYPES
# define INCL_WINSOCK_API_PROTOTYPES 1
#endif

#ifndef INCL_WINSOCK_API_TYPEDEFS
# define INCL_WINSOCK_API_TYPEDEFS 0
#endif

#ifndef _INC_WINDOWS
# include <windows.h>
#endif

#ifndef MAKEWORD
# define MAKEWORD(low, high) ((WORD)(((BYTE)(low)) | ((WORD)((BYTE)(high))) << 8))
#endif

#ifndef WINSOCK_VERSION
# define WINSOCK_VERSION MAKEWORD(2, 2)
#endif

#ifndef WINSOCK_API_LINKAGE
# ifdef DECLSPEC_IMPORT
#   define WINSOCK_API_LINKAGE DECLSPEC_IMPORT
# else
#   define WINSOCK_API_LINKAGE
# endif
#endif  /* WINSOCK_API_LINKAGE */

#ifdef __cplusplus
extern "C" {
#endif

/* undefine macros from winsock.h */
#include <psdk_inc/_ws1_undef.h>
#include <_bsd_types.h>
#include <ws2def.h>
#include <psdk_inc/_socket_types.h>
#include <psdk_inc/_fd_types.h>
#include <_timeval.h>

#define FIONREAD _IOR('f', 127, u_long)
#define FIONBIO  _IOW('f', 126, u_long)
#define FIOASYNC _IOW('f', 125, u_long)

#define SIOCSHIWAT _IOW('s', 0, u_long)
#define SIOCGHIWAT _IOR('s', 1, u_long)
#define SIOCSLOWAT _IOW('s', 2, u_long)
#define SIOCGLOWAT _IOR('s', 3, u_long)
#define SIOCATMARK _IOR('s', 7, u_long)

#define IMPLINK_IP        155
#define IMPLINK_LOWEXPER  156
#define IMPLINK_HIGHEXPER 158

#include <inaddr.h>

#define ADDR_ANY INADDR_ANY

#include <psdk_inc/_wsadata.h>

#define FROM_PROTOCOL_INFO (-1)

#define SO_PROTOCOL_INFOA 0x2004
#define SO_PROTOCOL_INFOW 0x2005
#define SO_PROTOCOL_INFO  __MINGW_NAME_AW(SO_PROTOCOL_INFO)
#define PVD_CONFIG        0x3001

#define PF_UNSPEC    AF_UNSPEC
#define PF_UNIX      AF_UNIX
#define PF_INET      AF_INET
#define PF_IMPLINK   AF_IMPLINK
#define PF_PUP       AF_PUP
#define PF_CHAOS     AF_CHAOS
#define PF_NS        AF_NS
#define PF_IPX       AF_IPX
#define PF_ISO       AF_ISO
#define PF_OSI       AF_OSI
#define PF_ECMA      AF_ECMA
#define PF_DATAKIT   AF_DATAKIT
#define PF_CCITT     AF_CCITT
#define PF_SNA       AF_SNA
#define PF_DECnet    AF_DECnet
#define PF_DLI       AF_DLI
#define PF_LAT       AF_LAT
#define PF_HYLINK    AF_HYLINK
#define PF_APPLETALK AF_APPLETALK
#define PF_VOICEVIEW AF_VOICEVIEW
#define PF_FIREFOX   AF_FIREFOX
#define PF_UNKNOWN1  AF_UNKNOWN1
#define PF_BAN       AF_BAN
#define PF_ATM       AF_ATM
#define PF_INET6     AF_INET6
#define PF_BTH       AF_BTH
#define PF_MAX       AF_MAX

#define SOMAXCONN         0x7fffffff
#define SOMAXCONN_HINT(b) (-(b))

#define MSG_OOB            0x1
#define MSG_PEEK           0x2
#define MSG_DONTROUTE      0x4
#define MSG_WAITALL        0x8
#define MSG_PUSH_IMMEDIATE 0x20
#define MSG_PARTIAL        0x8000
#define MSG_INTERRUPT      0x10
#define MSG_MAXIOVLEN      16

#define MAXGETHOSTSTRUCT 1024

#define FD_READ_BIT 0
#define FD_READ     (1 << FD_READ_BIT)

#define FD_WRITE_BIT 1
#define FD_WRITE     (1 << FD_WRITE_BIT)

#define FD_OOB_BIT 2
#define FD_OOB     (1 << FD_OOB_BIT)

#define FD_ACCEPT_BIT 3
#define FD_ACCEPT     (1 << FD_ACCEPT_BIT)

#define FD_CONNECT_BIT 4
#define FD_CONNECT     (1 << FD_CONNECT_BIT)

#define FD_CLOSE_BIT 5
#define FD_CLOSE     (1 << FD_CLOSE_BIT)

#define FD_QOS_BIT 6
#define FD_QOS     (1 << FD_QOS_BIT)

#define FD_GROUP_QOS_BIT 7
#define FD_GROUP_QOS     (1 << FD_GROUP_QOS_BIT)

#define FD_ROUTING_INTERFACE_CHANGE_BIT 8
#define FD_ROUTING_INTERFACE_CHANGE     (1 << FD_ROUTING_INTERFACE_CHANGE_BIT)

#define FD_ADDRESS_LIST_CHANGE_BIT 9
#define FD_ADDRESS_LIST_CHANGE     (1 << FD_ADDRESS_LIST_CHANGE_BIT)

#define FD_MAX_EVENTS 10
#define FD_ALL_EVENTS ((1 << FD_MAX_EVENTS) - 1)

#include <psdk_inc/_wsa_errnos.h>

#define WSAAPI        PASCAL
#define WSAEVENT      HANDLE
#define LPWSAEVENT    LPHANDLE
#define WSAOVERLAPPED OVERLAPPED

  typedef struct _OVERLAPPED *LPWSAOVERLAPPED;

#define WSA_IO_PENDING        (ERROR_IO_PENDING)
#define WSA_IO_INCOMPLETE     (ERROR_IO_INCOMPLETE)
#define WSA_INVALID_HANDLE    (ERROR_INVALID_HANDLE)
#define WSA_INVALID_PARAMETER (ERROR_INVALID_PARAMETER)
#define WSA_NOT_ENOUGH_MEMORY (ERROR_NOT_ENOUGH_MEMORY)
#define WSA_OPERATION_ABORTED (ERROR_OPERATION_ABORTED)

#define WSA_INVALID_EVENT       ((WSAEVENT)NULL)
#define WSA_MAXIMUM_WAIT_EVENTS (MAXIMUM_WAIT_OBJECTS)
#define WSA_WAIT_FAILED         (WAIT_FAILED)
#define WSA_WAIT_EVENT_0        (WAIT_OBJECT_0)
#define WSA_WAIT_IO_COMPLETION  (WAIT_IO_COMPLETION)
#define WSA_WAIT_TIMEOUT        (WAIT_TIMEOUT)
#define WSA_INFINITE            (INFINITE)

#define LPQOS LPVOID

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#undef LPQOS

#include <qos.h>

  typedef struct _QualityOfService
  {
    FLOWSPEC SendingFlowspec;
    FLOWSPEC ReceivingFlowspec;
    WSABUF   ProviderSpecific;
  } QOS, *LPQOS;

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */

#define CF_ACCEPT 0x0000
#define CF_REJECT 0x0001
#define CF_DEFER  0x0002

#define SD_RECEIVE 0x00
#define SD_SEND    0x01
#define SD_BOTH    0x02

  typedef unsigned int GROUP;

#define SG_UNCONSTRAINED_GROUP 0x01
#define SG_CONSTRAINED_GROUP   0x02

  typedef struct _WSANETWORKEVENTS
  {
    long lNetworkEvents;
    int  iErrorCode[FD_MAX_EVENTS];
  } WSANETWORKEVENTS, *LPWSANETWORKEVENTS;

#ifndef GUID_DEFINED
# include <guiddef.h>
#endif

#define MAX_PROTOCOL_CHAIN 7

#define BASE_PROTOCOL    1
#define LAYERED_PROTOCOL 0

  typedef struct _WSAPROTOCOLCHAIN
  {
    int   ChainLen;
    DWORD ChainEntries[MAX_PROTOCOL_CHAIN];
  } WSAPROTOCOLCHAIN, *LPWSAPROTOCOLCHAIN;

#define WSAPROTOCOL_LEN 255

  typedef struct _WSAPROTOCOL_INFOA
  {
    DWORD            dwServiceFlags1;
    DWORD            dwServiceFlags2;
    DWORD            dwServiceFlags3;
    DWORD            dwServiceFlags4;
    DWORD            dwProviderFlags;
    GUID             ProviderId;
    DWORD            dwCatalogEntryId;
    WSAPROTOCOLCHAIN ProtocolChain;
    int              iVersion;
    int              iAddressFamily;
    int              iMaxSockAddr;
    int              iMinSockAddr;
    int              iSocketType;
    int              iProtocol;
    int              iProtocolMaxOffset;
    int              iNetworkByteOrder;
    int              iSecurityScheme;
    DWORD            dwMessageSize;
    DWORD            dwProviderReserved;
    CHAR             szProtocol[WSAPROTOCOL_LEN+1];
  } WSAPROTOCOL_INFOA, *LPWSAPROTOCOL_INFOA;

  typedef struct _WSAPROTOCOL_INFOW
  {
    DWORD            dwServiceFlags1;
    DWORD            dwServiceFlags2;
    DWORD            dwServiceFlags3;
    DWORD            dwServiceFlags4;
    DWORD            dwProviderFlags;
    GUID             ProviderId;
    DWORD            dwCatalogEntryId;
    WSAPROTOCOLCHAIN ProtocolChain;
    int              iVersion;
    int              iAddressFamily;
    int              iMaxSockAddr;
    int              iMinSockAddr;
    int              iSocketType;
    int              iProtocol;
    int              iProtocolMaxOffset;
    int              iNetworkByteOrder;
    int              iSecurityScheme;
    DWORD            dwMessageSize;
    DWORD            dwProviderReserved;
    WCHAR            szProtocol[WSAPROTOCOL_LEN+1];
  } WSAPROTOCOL_INFOW, *LPWSAPROTOCOL_INFOW;

  __MINGW_TYPEDEF_AW(WSAPROTOCOL_INFO)
  __MINGW_TYPEDEF_AW(LPWSAPROTOCOL_INFO)

#define PFL_MULTIPLE_PROTO_ENTRIES  0x00000001
#define PFL_RECOMMENDED_PROTO_ENTRY 0x00000002
#define PFL_HIDDEN                  0x00000004
#define PFL_MATCHES_PROTOCOL_ZERO   0x00000008
#define PFL_NETWORKDIRECT_PROVIDER  0x00000010

#define XP1_CONNECTIONLESS           0x00000001
#define XP1_GUARANTEED_DELIVERY      0x00000002
#define XP1_GUARANTEED_ORDER         0x00000004
#define XP1_MESSAGE_ORIENTED         0x00000008
#define XP1_PSEUDO_STREAM            0x00000010
#define XP1_GRACEFUL_CLOSE           0x00000020
#define XP1_EXPEDITED_DATA           0x00000040
#define XP1_CONNECT_DATA             0x00000080
#define XP1_DISCONNECT_DATA          0x00000100
#define XP1_SUPPORT_BROADCAST        0x00000200
#define XP1_SUPPORT_MULTIPOINT       0x00000400
#define XP1_MULTIPOINT_CONTROL_PLANE 0x00000800
#define XP1_MULTIPOINT_DATA_PLANE    0x00001000
#define XP1_QOS_SUPPORTED            0x00002000
#define XP1_INTERRUPT                0x00004000
#define XP1_UNI_SEND                 0x00008000
#define XP1_UNI_RECV                 0x00010000
#define XP1_IFS_HANDLES              0x00020000
#define XP1_PARTIAL_MESSAGE          0x00040000
#define XP1_SAN_SUPPORT_SDP          0x00080000

#define BIGENDIAN    0x0000
#define LITTLEENDIAN 0x0001

#define SECURITY_PROTOCOL_NONE 0x0000

#define JL_SENDER_ONLY   0x01
#define JL_RECEIVER_ONLY 0x02
#define JL_BOTH          0x04

#define WSA_FLAG_OVERLAPPED             0x01
#define WSA_FLAG_MULTIPOINT_C_ROOT      0x02
#define WSA_FLAG_MULTIPOINT_C_LEAF      0x04
#define WSA_FLAG_MULTIPOINT_D_ROOT      0x08
#define WSA_FLAG_MULTIPOINT_D_LEAF      0x10
#define WSA_FLAG_ACCESS_SYSTEM_SECURITY 0x40
#define WSA_FLAG_NO_HANDLE_INHERIT      0x80
#define WSA_FLAG_REGISTERED_IO          0x100

  typedef int  (CALLBACK *LPCONDITIONPROC)(LPWSABUF lpCallerId, LPWSABUF lpCallerData, LPQOS lpSQOS, LPQOS lpGQOS, LPWSABUF lpCalleeId, LPWSABUF lpCalleeData, GROUP *g, DWORD_PTR dwCallbackData);
  typedef void (CALLBACK *LPWSAOVERLAPPED_COMPLETION_ROUTINE)(DWORD dwError, DWORD cbTransferred, LPWSAOVERLAPPED lpOverlapped, DWORD dwFlags);

#define SIO_NSP_NOTIFY_CHANGE _WSAIOW(IOC_WS2, 25)

  typedef enum _WSACOMPLETIONTYPE
  {
    NSP_NOTIFY_IMMEDIATELY = 0,
    NSP_NOTIFY_HWND,
    NSP_NOTIFY_EVENT,
    NSP_NOTIFY_PORT,
    NSP_NOTIFY_APC
  } WSACOMPLETIONTYPE, *PWSACOMPLETIONTYPE, *LPWSACOMPLETIONTYPE;

  typedef struct _WSACOMPLETION
  {
    WSACOMPLETIONTYPE Type;
    union
    {
      struct
      {
        HWND   hWnd;
        UINT   uMsg;
        WPARAM context;
      } WindowMessage;
      struct
      {
        LPWSAOVERLAPPED lpOverlapped;
      } Event;
      struct
      {
        LPWSAOVERLAPPED                    lpOverlapped;
        LPWSAOVERLAPPED_COMPLETION_ROUTINE lpfnCompletionProc;
      } Apc;
      struct
      {
        LPWSAOVERLAPPED lpOverlapped;
        HANDLE          hPort;
        ULONG_PTR       Key;
      } Port;
    } Parameters;
  } WSACOMPLETION, *PWSACOMPLETION, *LPWSACOMPLETION;

#define TH_NETDEV 0x00000001
#define TH_TAPI   0x00000002

#ifndef _tagBLOB_DEFINED
# define _tagBLOB_DEFINED
# define _BLOB_DEFINED
# define _LPBLOB_DEFINED
  typedef struct _BLOB
  {
    ULONG  cbSize;
    BYTE  *pBlobData;
  } BLOB, *LPBLOB;
#endif  /* _tagBLOB_DEFINED */

#define SERVICE_MULTIPLE (0x00000001)

#define RES_UNUSED_1    (0x00000001)
#define RES_FLUSH_CACHE (0x00000002)
#ifndef RES_SERVICE
# define RES_SERVICE    (0x00000004)
#endif

#define SERVICE_TYPE_VALUE_IPXPORTA "IpxSocket"
#define SERVICE_TYPE_VALUE_IPXPORTW L"IpxSocket"
#define SERVICE_TYPE_VALUE_SAPIDA   "SapId"
#define SERVICE_TYPE_VALUE_SAPIDW   L"SapId"

#define SERVICE_TYPE_VALUE_TCPPORTA "TcpPort"
#define SERVICE_TYPE_VALUE_TCPPORTW L"TcpPort"

#define SERVICE_TYPE_VALUE_UDPPORTA "UdpPort"
#define SERVICE_TYPE_VALUE_UDPPORTW L"UdpPort"

#define SERVICE_TYPE_VALUE_OBJECTIDA "ObjectId"
#define SERVICE_TYPE_VALUE_OBJECTIDW L"ObjectId"

#define SERVICE_TYPE_VALUE_SAPID    __MINGW_NAME_AW(SERVICE_TYPE_VALUE_SAPID)
#define SERVICE_TYPE_VALUE_TCPPORT  __MINGW_NAME_AW(SERVICE_TYPE_VALUE_TCPPORT)
#define SERVICE_TYPE_VALUE_UDPPORT  __MINGW_NAME_AW(SERVICE_TYPE_VALUE_UDPPORT)
#define SERVICE_TYPE_VALUE_OBJECTID __MINGW_NAME_AW(SERVICE_TYPE_VALUE_OBJECTID)

  typedef struct _AFPROTOCOLS
  {
    INT iAddressFamily;
    INT iProtocol;
  } AFPROTOCOLS, *PAFPROTOCOLS, *LPAFPROTOCOLS;

  typedef enum _WSAEcomparator
  {
    COMP_EQUAL = 0,
    COMP_NOTLESS
  } WSAECOMPARATOR, *PWSAECOMPARATOR, *LPWSAECOMPARATOR;

  typedef struct _WSAVersion
  {
    DWORD          dwVersion;
    WSAECOMPARATOR ecHow;
  } WSAVERSION, *PWSAVERSION, *LPWSAVERSION;

  typedef struct _WSAQuerySetA
  {
    DWORD         dwSize;
    LPSTR         lpszServiceInstanceName;
    LPGUID        lpServiceClassId;
    LPWSAVERSION  lpVersion;
    LPSTR         lpszComment;
    DWORD         dwNameSpace;
    LPGUID        lpNSProviderId;
    LPSTR         lpszContext;
    DWORD         dwNumberOfProtocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPSTR         lpszQueryString;
    DWORD         dwNumberOfCsAddrs;
    LPCSADDR_INFO lpcsaBuffer;
    DWORD         dwOutputFlags;
    LPBLOB        lpBlob;
  } WSAQUERYSETA, *PWSAQUERYSETA, *LPWSAQUERYSETA;

  typedef struct _WSAQuerySetW
  {
    DWORD         dwSize;
    LPWSTR        lpszServiceInstanceName;
    LPGUID        lpServiceClassId;
    LPWSAVERSION  lpVersion;
    LPWSTR        lpszComment;
    DWORD         dwNameSpace;
    LPGUID        lpNSProviderId;
    LPWSTR        lpszContext;
    DWORD         dwNumberOfProtocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPWSTR        lpszQueryString;
    DWORD         dwNumberOfCsAddrs;
    LPCSADDR_INFO lpcsaBuffer;
    DWORD         dwOutputFlags;
    LPBLOB        lpBlob;
  } WSAQUERYSETW, *PWSAQUERYSETW, *LPWSAQUERYSETW;

  __MINGW_TYPEDEF_AW(WSAQUERYSET)
  __MINGW_TYPEDEF_AW(PWSAQUERYSET)
  __MINGW_TYPEDEF_AW(LPWSAQUERYSET)

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  typedef struct _WSAQuerySet2A
  {
    DWORD         dwSize;
    LPSTR         lpszServiceInstanceName;
    LPWSAVERSION  lpVersion;
    LPSTR         lpszComment;
    DWORD         dwNameSpace;
    LPGUID        lpNSProviderId;
    LPSTR         lpszContext;
    DWORD         dwNumberOfProtocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPSTR         lpszQueryString;
    DWORD         dwNumberOfCsAddrs;
    LPCSADDR_INFO lpcsaBuffer;
    DWORD         dwOutputFlags;
    LPBLOB        lpBlob;
  } WSAQUERYSET2A, *PWSAQUERYSET2A, *LPWSAQUERYSET2A;

  typedef struct _WSAQuerySet2W
  {
    DWORD         dwSize;
    LPWSTR        lpszServiceInstanceName;
    LPWSAVERSION  lpVersion;
    LPWSTR        lpszComment;
    DWORD         dwNameSpace;
    LPGUID        lpNSProviderId;
    LPWSTR        lpszContext;
    DWORD         dwNumberOfProtocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPWSTR        lpszQueryString;
    DWORD         dwNumberOfCsAddrs;
    LPCSADDR_INFO lpcsaBuffer;
    DWORD         dwOutputFlags;
    LPBLOB        lpBlob;
  } WSAQUERYSET2W, *PWSAQUERYSET2W, *LPWSAQUERYSET2W;

  __MINGW_TYPEDEF_AW(WSAQUERYSET2)
  __MINGW_TYPEDEF_AW(PWSAQUERYSET2)
  __MINGW_TYPEDEF_AW(LPWSAQUERYSET2)

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#define LUP_DEEP                     0x00000001
#define LUP_CONTAINERS               0x00000002
#define LUP_NOCONTAINERS             0x00000004
#define LUP_NEAREST                  0x00000008
#define LUP_RETURN_NAME              0x00000010
#define LUP_RETURN_TYPE              0x00000020
#define LUP_RETURN_VERSION           0x00000040
#define LUP_RETURN_COMMENT           0x00000080
#define LUP_RETURN_ADDR              0x00000100
#define LUP_RETURN_BLOB              0x00000200
#define LUP_RETURN_ALIASES           0x00000400
#define LUP_RETURN_QUERY_STRING      0x00000800
#define LUP_RETURN_ALL               0x00000FF0
#define LUP_RES_SERVICE              0x00008000
#define LUP_FLUSHCACHE               0x00001000
#define LUP_FLUSHPREVIOUS            0x00002000
#define LUP_NON_AUTHORITATIVE        0x00004000
#define LUP_SECURE                   0x00008000
#define LUP_RETURN_PREFERRED_NAMES   0x00010000
#define LUP_DNS_ONLY                 0x00020000
#define LUP_RETURN_RESPONSE_FLAGS    0x00040000
#define LUP_RESERVED_UNUSED          0x00080000
#define LUP_ADDRCONFIG               0x00100000
#define LUP_DUAL_ADDR                0x00200000
#define LUP_FILESERVER               0x00400000
#define LUP_DISABLE_IDN_ENCODING     0x00800000
#define LUP_API_ANSI                 0x01000000
#define LUP_EXTENDED_QUERYSET        0x02000000
#define LUP_SECURE_WITH_FALLBACK     0x04000000
#define LUP_EXCLUSIVE_CUSTOM_SERVERS 0x08000000
#define LUP_REQUIRE_SECURE           0x10000000
#define LUP_RETURN_TTL               0x20000000
#define LUP_FORCE_CLEAR_TEXT         0x40000000
#define LUP_RESOLUTION_HANDLE        0x80000000

#define RESULT_IS_ALIAS   0x0001
#define RESULT_IS_ADDED   0x0010
#define RESULT_IS_CHANGED 0x0020
#define RESULT_IS_DELETED 0x0040

  typedef enum _WSAESETSERVICEOP
  {
    RNRSERVICE_REGISTER = 0,
    RNRSERVICE_DEREGISTER,
    RNRSERVICE_DELETE
  } WSAESETSERVICEOP, *PWSAESETSERVICEOP, *LPWSAESETSERVICEOP;

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  typedef struct _WSANSClassInfoA
  {
    LPSTR  lpszName;
    DWORD  dwNameSpace;
    DWORD  dwValueType;
    DWORD  dwValueSize;
    LPVOID lpValue;
  } WSANSCLASSINFOA, *PWSANSCLASSINFOA, *LPWSANSCLASSINFOA;

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

  typedef struct _WSANSClassInfoW
  {
    LPWSTR lpszName;
    DWORD  dwNameSpace;
    DWORD  dwValueType;
    DWORD  dwValueSize;
    LPVOID lpValue;
  } WSANSCLASSINFOW, *PWSANSCLASSINFOW, *LPWSANSCLASSINFOW;

#ifdef UNICODE
  typedef WSANSCLASSINFOW   WSANSCLASSINFO;
  typedef PWSANSCLASSINFOW  PWSANSCLASSINFO;
  typedef LPWSANSCLASSINFOW LPWSANSCLASSINFO;
#else
# if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
    typedef WSANSCLASSINFOA   WSANSCLASSINFO;
    typedef PWSANSCLASSINFOA  PWSANSCLASSINFO;
    typedef LPWSANSCLASSINFOA LPWSANSCLASSINFO;
# endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  typedef struct _WSAServiceClassInfoA
  {
    LPGUID            lpServiceClassId;
    LPSTR             lpszServiceClassName;
    DWORD             dwCount;
    LPWSANSCLASSINFOA lpClassInfos;
  } WSASERVICECLASSINFOA, *PWSASERVICECLASSINFOA, *LPWSASERVICECLASSINFOA;

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

  typedef struct _WSAServiceClassInfoW
  {
    LPGUID            lpServiceClassId;
    LPWSTR            lpszServiceClassName;
    DWORD             dwCount;
    LPWSANSCLASSINFOW lpClassInfos;
  } WSASERVICECLASSINFOW, *PWSASERVICECLASSINFOW, *LPWSASERVICECLASSINFOW;

#ifdef UNICODE
  typedef WSASERVICECLASSINFOW   WSASERVICECLASSINFO;
  typedef PWSASERVICECLASSINFOW  PWSASERVICECLASSINFO;
  typedef LPWSASERVICECLASSINFOW LPWSASERVICECLASSINFO;
#else
# if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
    typedef WSASERVICECLASSINFOA   WSASERVICECLASSINFO;
    typedef PWSASERVICECLASSINFOA  PWSASERVICECLASSINFO;
    typedef LPWSASERVICECLASSINFOA LPWSASERVICECLASSINFO;
# endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */
#endif  /* UNICODE */

  typedef struct _WSANAMESPACE_INFOA
  {
    GUID    NSProviderId;
    DWORD   dwNameSpace;
    WINBOOL fActive;
    DWORD   dwVersion;
    LPSTR   lpszIdentifier;
  } WSANAMESPACE_INFOA, *PWSANAMESPACE_INFOA, *LPWSANAMESPACE_INFOA;

  typedef struct _WSANAMESPACE_INFOW
  {
    GUID    NSProviderId;
    DWORD   dwNameSpace;
    WINBOOL fActive;
    DWORD   dwVersion;
    LPWSTR  lpszIdentifier;
  } WSANAMESPACE_INFOW, *PWSANAMESPACE_INFOW, *LPWSANAMESPACE_INFOW;

  typedef struct _WSANAMESPACE_INFOEXA
  {
    GUID    NSProviderId;
    DWORD   dwNameSpace;
    WINBOOL fActive;
    DWORD   dwVersion;
    LPSTR   lpszIdentifier;
    BLOB    ProviderSpecific;
  } WSANAMESPACE_INFOEXA, *PWSANAMESPACE_INFOEXA, *LPWSANAMESPACE_INFOEXA;

  typedef struct _WSANAMESPACE_INFOEXW
  {
    GUID    NSProviderId;
    DWORD   dwNameSpace;
    WINBOOL fActive;
    DWORD   dwVersion;
    LPWSTR  lpszIdentifier;
    BLOB    ProviderSpecific;
  } WSANAMESPACE_INFOEXW, *PWSANAMESPACE_INFOEXW, *LPWSANAMESPACE_INFOEXW;

  __MINGW_TYPEDEF_AW(WSANAMESPACE_INFO)
  __MINGW_TYPEDEF_AW(PWSANAMESPACE_INFO)
  __MINGW_TYPEDEF_AW(LPWSANAMESPACE_INFO)
  __MINGW_TYPEDEF_AW(WSANAMESPACE_INFOEX)
  __MINGW_TYPEDEF_AW(PWSANAMESPACE_INFOEX)
  __MINGW_TYPEDEF_AW(LPWSANAMESPACE_INFOEX)

#define POLLRDNORM 0x0100
#define POLLRDBAND 0x0200
#define POLLIN     (POLLRDNORM | POLLRDBAND)
#define POLLPRI    0x0400

#define POLLWRNORM 0x0010
#define POLLOUT    (POLLWRNORM)
#define POLLWRBAND 0x0020

#define POLLERR    0x0001
#define POLLHUP    0x0002
#define POLLNVAL   0x0004

  typedef struct pollfd
  {
    SOCKET fd;
    SHORT  events;
    SHORT  revents;
  } WSAPOLLFD, *PWSAPOLLFD, *LPWSAPOLLFD;

  typedef struct SOCK_NOTIFY_REGISTRATION
  {
    SOCKET socket;
    PVOID  completionKey;
    UINT16 eventFilter;
    UINT8  operation;
    UINT8  triggerFlags;
    DWORD  registrationResult;
  } SOCK_NOTIFY_REGISTRATION;

#if INCL_WINSOCK_API_PROTOTYPES

#ifndef __WINSOCK_WS1_SHARED
  WINSOCK_API_LINKAGE SOCKET           WSAAPI accept(SOCKET s, struct sockaddr *addr, int *addrlen);
  WINSOCK_API_LINKAGE int              WSAAPI bind(SOCKET s, const struct sockaddr *name, int namelen);
  WINSOCK_API_LINKAGE int              WSAAPI closesocket(SOCKET s);
  WINSOCK_API_LINKAGE int              WSAAPI connect(SOCKET s, const struct sockaddr *name, int namelen);
  WINSOCK_API_LINKAGE int              WSAAPI ioctlsocket(SOCKET s, long cmd, u_long *argp);
  WINSOCK_API_LINKAGE int              WSAAPI getpeername(SOCKET s, struct sockaddr *name, int *namelen);
  WINSOCK_API_LINKAGE int              WSAAPI getsockname(SOCKET s, struct sockaddr *name, int *namelen);
  WINSOCK_API_LINKAGE int              WSAAPI getsockopt(SOCKET s, int level, int optname, char *optval, int *optlen);
  WINSOCK_API_LINKAGE u_long           WSAAPI htonl(u_long hostlong);
  WINSOCK_API_LINKAGE u_short          WSAAPI htons(u_short hostshort);
  WINSOCK_API_LINKAGE unsigned long    WSAAPI inet_addr(const char *cp);
  WINSOCK_API_LINKAGE char            *WSAAPI inet_ntoa(struct in_addr in);
  WINSOCK_API_LINKAGE int              WSAAPI listen(SOCKET s, int backlog);
  WINSOCK_API_LINKAGE u_long           WSAAPI ntohl(u_long netlong);
  WINSOCK_API_LINKAGE u_short          WSAAPI ntohs(u_short netshort);
  WINSOCK_API_LINKAGE int              WSAAPI recv(SOCKET s, char *buf, int len, int flags);
  WINSOCK_API_LINKAGE int              WSAAPI recvfrom(SOCKET s, char *buf, int len, int flags, struct sockaddr *from, int *fromlen);
  WINSOCK_API_LINKAGE int              WSAAPI select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, const struct timeval *timeout);
  WINSOCK_API_LINKAGE int              WSAAPI send(SOCKET s, const char *buf, int len, int flags);
  WINSOCK_API_LINKAGE int              WSAAPI sendto(SOCKET s, const char *buf, int len, int flags, const struct sockaddr *to, int tolen);
  WINSOCK_API_LINKAGE int              WSAAPI setsockopt(SOCKET s, int level, int optname, const char *optval, int optlen);
  WINSOCK_API_LINKAGE int              WSAAPI shutdown(SOCKET s, int how);
  WINSOCK_API_LINKAGE SOCKET           WSAAPI socket(int af, int type, int protocol);
  WINSOCK_API_LINKAGE struct hostent  *WSAAPI gethostbyaddr(const char *addr, int len, int type);
  WINSOCK_API_LINKAGE struct hostent  *WSAAPI gethostbyname(const char *name);
  WINSOCK_API_LINKAGE int              WSAAPI gethostname(char *name, int namelen);
  WINSOCK_API_LINKAGE struct servent  *WSAAPI getservbyport(int port, const char *proto);
  WINSOCK_API_LINKAGE struct servent  *WSAAPI getservbyname(const char *name, const char *proto);
  WINSOCK_API_LINKAGE struct protoent *WSAAPI getprotobynumber(int number);
  WINSOCK_API_LINKAGE struct protoent *WSAAPI getprotobyname(const char *name);
  WINSOCK_API_LINKAGE int              WSAAPI WSAStartup(WORD wVersionRequested, LPWSADATA lpWSAData);
  WINSOCK_API_LINKAGE int              WSAAPI WSACleanup(void);
  WINSOCK_API_LINKAGE void             WSAAPI WSASetLastError(int iError);
  WINSOCK_API_LINKAGE int              WSAAPI WSAGetLastError(void);

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAIsBlocking(void);
  WINSOCK_API_LINKAGE int     WSAAPI WSAUnhookBlockingHook(void);
  WINSOCK_API_LINKAGE FARPROC WSAAPI WSASetBlockingHook(FARPROC lpBlockFunc);
  WINSOCK_API_LINKAGE int     WSAAPI WSACancelBlockingCall(void);
  WINSOCK_API_LINKAGE HANDLE  WSAAPI WSAAsyncGetServByName(HWND hWnd, u_int wMsg, const char *name, const char *proto, char *buf, int buflen);
  WINSOCK_API_LINKAGE HANDLE  WSAAPI WSAAsyncGetServByPort(HWND hWnd, u_int wMsg, int port, const char *proto, char *buf, int buflen);
  WINSOCK_API_LINKAGE HANDLE  WSAAPI WSAAsyncGetProtoByName(HWND hWnd, u_int wMsg, const char *name, char *buf, int buflen);
  WINSOCK_API_LINKAGE HANDLE  WSAAPI WSAAsyncGetProtoByNumber(HWND hWnd, u_int wMsg, int number, char *buf, int buflen);
  WINSOCK_API_LINKAGE HANDLE  WSAAPI WSAAsyncGetHostByName(HWND hWnd, u_int wMsg, const char *name, char *buf, int buflen);
  WINSOCK_API_LINKAGE HANDLE  WSAAPI WSAAsyncGetHostByAddr(HWND hWnd, u_int wMsg, const char *addr, int len, int type, char *buf, int buflen);
  WINSOCK_API_LINKAGE int     WSAAPI WSACancelAsyncRequest(HANDLE hAsyncTaskHandle);
  WINSOCK_API_LINKAGE int     WSAAPI WSAAsyncSelect(SOCKET s, HWND hWnd, u_int wMsg, long lEvent);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#endif  /* __WINSOCK_WS1_SHARED */

  WINSOCK_API_LINKAGE int      WSAAPI GetHostNameW(PWSTR name, int namelen);
  WINSOCK_API_LINKAGE SOCKET   WSAAPI WSAAccept(SOCKET s, struct sockaddr *addr, LPINT addrlen, LPCONDITIONPROC lpfnCondition, DWORD_PTR dwCallbackData);
  WINSOCK_API_LINKAGE WINBOOL  WSAAPI WSACloseEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE int      WSAAPI WSAConnect(SOCKET s, const struct sockaddr *name, int namelen, LPWSABUF lpCallerData, LPWSABUF lpCalleeData, LPQOS lpSQOS, LPQOS lpGQOS);
  WINSOCK_API_LINKAGE WINBOOL  PASCAL WSAConnectByNameA(SOCKET s, LPCSTR nodename, LPCSTR servicename, LPDWORD LocalAddressLength, LPSOCKADDR LocalAddress, LPDWORD RemoteAddressLength, LPSOCKADDR RemoteAddress, const struct timeval *timeout, LPWSAOVERLAPPED Reserved);
  WINSOCK_API_LINKAGE WINBOOL  PASCAL WSAConnectByNameW(SOCKET s, LPWSTR nodename, LPWSTR servicename, LPDWORD LocalAddressLength, LPSOCKADDR LocalAddress, LPDWORD RemoteAddressLength, LPSOCKADDR RemoteAddress, const struct timeval *timeout, LPWSAOVERLAPPED Reserved);
#define WSAConnectByName __MINGW_NAME_AW(WSAConnectByName)
  WINSOCK_API_LINKAGE WINBOOL  PASCAL WSAConnectByList(SOCKET s, PSOCKET_ADDRESS_LIST SocketAddressList, LPDWORD LocalAddressLength, LPSOCKADDR LocalAddress, LPDWORD RemoteAddressLength, LPSOCKADDR RemoteAddress, const struct timeval *timeout, LPWSAOVERLAPPED Reserved);
  WINSOCK_API_LINKAGE WSAEVENT WSAAPI WSACreateEvent(void);
  WINSOCK_API_LINKAGE int      WSAAPI WSADuplicateSocketA(SOCKET s, DWORD dwProcessId, LPWSAPROTOCOL_INFOA lpProtocolInfo);
  WINSOCK_API_LINKAGE int      WSAAPI WSADuplicateSocketW(SOCKET s, DWORD dwProcessId, LPWSAPROTOCOL_INFOW lpProtocolInfo);
#define WSADuplicateSocket __MINGW_NAME_AW(WSADuplicateSocket)
  WINSOCK_API_LINKAGE int      WSAAPI WSAEnumNetworkEvents(SOCKET s, WSAEVENT hEventObject, LPWSANETWORKEVENTS lpNetworkEvents);
  WINSOCK_API_LINKAGE int      WSAAPI WSAEnumProtocolsA(LPINT lpiProtocols, LPWSAPROTOCOL_INFOA lpProtocolBuffer, LPDWORD lpdwBufferLength);
  WINSOCK_API_LINKAGE int      WSAAPI WSAEnumProtocolsW(LPINT lpiProtocols, LPWSAPROTOCOL_INFOW lpProtocolBuffer, LPDWORD lpdwBufferLength);
#define WSAEnumProtocols __MINGW_NAME_AW(WSAEnumProtocols)
  WINSOCK_API_LINKAGE int      WSAAPI WSAEventSelect(SOCKET s, WSAEVENT hEventObject, long lNetworkEvents);
  WINSOCK_API_LINKAGE WINBOOL  WSAAPI WSAGetOverlappedResult(SOCKET s, LPWSAOVERLAPPED lpOverlapped, LPDWORD lpcbTransfer, WINBOOL fWait, LPDWORD lpdwFlags);
  WINSOCK_API_LINKAGE int      WSAAPI WSAHtonl(SOCKET s, u_long hostlong, u_long *lpnetlong);
  WINSOCK_API_LINKAGE int      WSAAPI WSAHtons(SOCKET s, u_short hostshort, u_short *lpnetshort);
  WINSOCK_API_LINKAGE int      WSAAPI WSAIoctl(SOCKET s, DWORD dwIoControlCode, LPVOID lpvInBuffer, DWORD cbInBuffer, LPVOID lpvOutBuffer, DWORD cbOutBuffer, LPDWORD lpcbBytesReturned, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE SOCKET   WSAAPI WSAJoinLeaf(SOCKET s, const struct sockaddr *name, int namelen, LPWSABUF lpCallerData, LPWSABUF lpCalleeData, LPQOS lpSQOS, LPQOS lpGQOS, DWORD dwFlags);
  WINSOCK_API_LINKAGE int      WSAAPI WSANtohl(SOCKET s, u_long netlong, u_long *lphostlong);
  WINSOCK_API_LINKAGE int      WSAAPI WSANtohs(SOCKET s, u_short netshort, u_short *lphostshort);
  WINSOCK_API_LINKAGE int      WSAAPI WSARecv(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesRecvd, LPDWORD lpFlags, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE int      WSAAPI WSARecvFrom(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesRecvd, LPDWORD lpFlags, struct sockaddr *lpFrom, LPINT lpFromlen, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL  WSAAPI WSAResetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE int      WSAAPI WSASend(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesSent, DWORD dwFlags, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE int      WSAAPI WSASendMsg(SOCKET s, LPWSAMSG lpMsg, DWORD dwFlags, LPDWORD lpNumberOfBytesSent, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE int      WSAAPI WSASendTo(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesSent, DWORD dwFlags, const struct sockaddr *lpTo, int iTolen, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL  WSAAPI WSASetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE SOCKET   WSAAPI WSASocketA(int af, int type, int protocol, LPWSAPROTOCOL_INFOA lpProtocolInfo, GROUP g, DWORD dwFlags);
  WINSOCK_API_LINKAGE SOCKET   WSAAPI WSASocketW(int af, int type, int protocol, LPWSAPROTOCOL_INFOW lpProtocolInfo, GROUP g, DWORD dwFlags);
#define WSASocket __MINGW_NAME_AW(WSASocket)
  WINSOCK_API_LINKAGE DWORD    WSAAPI WSAWaitForMultipleEvents(DWORD cEvents, const WSAEVENT *lphEvents, WINBOOL fWaitAll, DWORD dwTimeout, WINBOOL fAlertable);
  WINSOCK_API_LINKAGE INT      WSAAPI WSAAddressToStringA(LPSOCKADDR lpsaAddress, DWORD dwAddressLength, LPWSAPROTOCOL_INFOA lpProtocolInfo, LPSTR lpszAddressString, LPDWORD lpdwAddressStringLength);
  WINSOCK_API_LINKAGE INT      WSAAPI WSAAddressToStringW(LPSOCKADDR lpsaAddress, DWORD dwAddressLength, LPWSAPROTOCOL_INFOW lpProtocolInfo, LPWSTR lpszAddressString, LPDWORD lpdwAddressStringLength);
#define WSAAddressToString __MINGW_NAME_AW(WSAAddressToString)
  WINSOCK_API_LINKAGE INT      WSAAPI WSAStringToAddressA(LPSTR AddressString, INT AddressFamily, LPWSAPROTOCOL_INFOA lpProtocolInfo, LPSOCKADDR lpAddress, LPINT lpAddressLength);
  WINSOCK_API_LINKAGE INT      WSAAPI WSAStringToAddressW(LPWSTR AddressString, INT AddressFamily, LPWSAPROTOCOL_INFOW lpProtocolInfo, LPSOCKADDR lpAddress, LPINT lpAddressLength);
#define WSAStringToAddress __MINGW_NAME_AW(WSAStringToAddress)
  WINSOCK_API_LINKAGE INT      WSAAPI WSALookupServiceBeginA(LPWSAQUERYSETA lpqsRestrictions, DWORD dwControlFlags, LPHANDLE lphLookup);
  WINSOCK_API_LINKAGE INT      WSAAPI WSALookupServiceBeginW(LPWSAQUERYSETW lpqsRestrictions, DWORD dwControlFlags, LPHANDLE lphLookup);
#define WSALookupServiceBegin __MINGW_NAME_AW(WSALookupServiceBegin)
  WINSOCK_API_LINKAGE INT      WSAAPI WSALookupServiceNextA(HANDLE hLookup, DWORD dwControlFlags, LPDWORD lpdwBufferLength, LPWSAQUERYSETA lpqsResults);
  WINSOCK_API_LINKAGE INT      WSAAPI WSALookupServiceNextW(HANDLE hLookup, DWORD dwControlFlags, LPDWORD lpdwBufferLength, LPWSAQUERYSETW lpqsResults);
#define WSALookupServiceNext __MINGW_NAME_AW(WSALookupServiceNext)
  WINSOCK_API_LINKAGE INT      WSAAPI WSANSPIoctl(HANDLE hLookup, DWORD dwControlCode, LPVOID lpvInBuffer, DWORD cbInBuffer, LPVOID lpvOutBuffer, DWORD cbOutBuffer, LPDWORD lpcbBytesReturned, LPWSACOMPLETION lpCompletion);
  WINSOCK_API_LINKAGE INT      WSAAPI WSALookupServiceEnd(HANDLE hLookup);
  WINSOCK_API_LINKAGE INT      WSAAPI WSAGetServiceClassInfoW(LPGUID lpProviderId, LPGUID lpServiceClassId, LPDWORD lpdwBufSize, LPWSASERVICECLASSINFOW lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT      WSAAPI WSAEnumNameSpaceProvidersA(LPDWORD lpdwBufferLength, LPWSANAMESPACE_INFOA lpnspBuffer);
  WINSOCK_API_LINKAGE INT      WSAAPI WSAEnumNameSpaceProvidersW(LPDWORD lpdwBufferLength, LPWSANAMESPACE_INFOW lpnspBuffer);
#define WSAEnumNameSpaceProviders __MINGW_NAME_AW(WSAEnumNameSpaceProviders)
  WINSOCK_API_LINKAGE INT      WSAAPI WSAEnumNameSpaceProvidersExA(LPDWORD lpdwBufferLength, LPWSANAMESPACE_INFOEXA lpnspBuffer);
  WINSOCK_API_LINKAGE INT      WSAAPI WSAEnumNameSpaceProvidersExW(LPDWORD lpdwBufferLength, LPWSANAMESPACE_INFOEXW lpnspBuffer);
#define WSAEnumNameSpaceProvidersEx __MINGW_NAME_AW(WSAEnumNameSpaceProvidersEx)
  WINSOCK_API_LINKAGE INT      WSAAPI WSAGetServiceClassNameByClassIdW(LPGUID lpServiceClassId, LPWSTR lpszServiceClassName, LPDWORD lpdwBufferLength);
  WINSOCK_API_LINKAGE INT      WSAAPI WSASetServiceA(LPWSAQUERYSETA lpqsRegInfo, WSAESETSERVICEOP essoperation, DWORD dwControlFlags);
  WINSOCK_API_LINKAGE INT      WSAAPI WSASetServiceW(LPWSAQUERYSETW lpqsRegInfo, WSAESETSERVICEOP essoperation, DWORD dwControlFlags);
#define WSASetService __MINGW_NAME_AW(WSASetService)
  WINSOCK_API_LINKAGE INT      WSAAPI WSAProviderConfigChange(LPHANDLE lpNotificationHandle, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE int      WSAAPI WSAPoll(LPWSAPOLLFD fdarray, ULONG nfds, INT timeout);
  WINSOCK_API_LINKAGE DWORD    WSAAPI ProcessSocketNotifications(HANDLE completionPort, UINT32 registrationCount, SOCK_NOTIFY_REGISTRATION *registrationInfos, UINT32 timeoutMs, ULONG completionCount, OVERLAPPED_ENTRY *completionPortEntries, UINT32 *receivedEntryCount);
#ifndef __WIDL__
  FORCEINLINE
  UINT32 SocketNotificationRetrieveEvents(OVERLAPPED_ENTRY *notification)
  {
    return (UINT32)notification->dwNumberOfBytesTransferred;
  }
#endif  /* __WIDL__ */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAGetQOSByName(SOCKET s, LPWSABUF lpQOSName, LPQOS lpQOS);
  WINSOCK_API_LINKAGE int     WSAAPI WSARecvDisconnect(SOCKET s, LPWSABUF lpInboundDisconnectData);
  WINSOCK_API_LINKAGE int     WSAAPI WSASendDisconnect(SOCKET s, LPWSABUF lpOutboundDisconnectData);
  WINSOCK_API_LINKAGE INT     WSAAPI WSAInstallServiceClassA(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT     WSAAPI WSAInstallServiceClassW(LPWSASERVICECLASSINFOW lpServiceClassInfo);
#define WSAInstallServiceClass __MINGW_NAME_AW(WSAInstallServiceClass)
  WINSOCK_API_LINKAGE INT     WSAAPI WSARemoveServiceClass(LPGUID lpServiceClassId);
  WINSOCK_API_LINKAGE INT     WSAAPI WSAGetServiceClassInfoA(LPGUID lpProviderId, LPGUID lpServiceClassId, LPDWORD lpdwBufSize, LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT     WSAAPI WSAGetServiceClassNameByClassIdA(LPGUID lpServiceClassId, LPSTR lpszServiceClassName, LPDWORD lpdwBufferLength);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#ifdef UNICODE
# define WSAGetServiceClassInfo          WSAGetServiceClassInfoW
# define WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdW
#else
# if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
#   define WSAGetServiceClassInfo          WSAGetServiceClassInfoA
#   define WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdA
# endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */
#endif

#endif  /* INCL_WINSOCK_API_PROTOTYPES */

#if INCL_WINSOCK_API_TYPEDEFS

  typedef SOCKET           (WSAAPI *LPFN_ACCEPT)(SOCKET s, struct sockaddr *addr, int *addrlen);
  typedef int              (WSAAPI *LPFN_BIND)(SOCKET s, const struct sockaddr *name, int namelen);
  typedef int              (WSAAPI *LPFN_CLOSESOCKET)(SOCKET s);
  typedef int              (WSAAPI *LPFN_CONNECT)(SOCKET s, const struct sockaddr *name, int namelen);
  typedef int              (WSAAPI *LPFN_IOCTLSOCKET)(SOCKET s, long cmd, u_long *argp);
  typedef int              (WSAAPI *LPFN_GETPEERNAME)(SOCKET s, struct sockaddr *name, int *namelen);
  typedef int              (WSAAPI *LPFN_GETSOCKNAME)(SOCKET s, struct sockaddr *name, int *namelen);
  typedef int              (WSAAPI *LPFN_GETSOCKOPT)(SOCKET s, int level, int optname, char *optval, int *optlen);
  typedef u_long           (WSAAPI *LPFN_HTONL)(u_long hostlong);
  typedef u_short          (WSAAPI *LPFN_HTONS)(u_short hostshort);
  typedef unsigned long    (WSAAPI *LPFN_INET_ADDR)(const char *cp);
  typedef char            *(WSAAPI *LPFN_INET_NTOA)(struct in_addr in);
  typedef int              (WSAAPI *LPFN_LISTEN)(SOCKET s, int backlog);
  typedef u_long           (WSAAPI *LPFN_NTOHL)(u_long netlong);
  typedef u_short          (WSAAPI *LPFN_NTOHS)(u_short netshort);
  typedef int              (WSAAPI *LPFN_RECV)(SOCKET s, char *buf, int len, int flags);
  typedef int              (WSAAPI *LPFN_RECVFROM)(SOCKET s, char *buf, int len, int flags, struct sockaddr *from, int *fromlen);
  typedef int              (WSAAPI *LPFN_SELECT)(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, const struct timeval *timeout);
  typedef int              (WSAAPI *LPFN_SEND)(SOCKET s, const char *buf, int len, int flags);
  typedef int              (WSAAPI *LPFN_SENDTO)(SOCKET s, const char *buf, int len, int flags, const struct sockaddr *to, int tolen);
  typedef int              (WSAAPI *LPFN_SETSOCKOPT)(SOCKET s, int level, int optname, const char *optval, int optlen);
  typedef int              (WSAAPI *LPFN_SHUTDOWN)(SOCKET s, int how);
  typedef SOCKET           (WSAAPI *LPFN_SOCKET)(int af, int type, int protocol);
  typedef struct hostent  *(WSAAPI *LPFN_GETHOSTBYADDR)(const char *addr, int len, int type);
  typedef struct hostent  *(WSAAPI *LPFN_GETHOSTBYNAME)(const char *name);
  typedef int              (WSAAPI *LPFN_GETHOSTNAME)(char *name, int namelen);
  typedef struct servent  *(WSAAPI *LPFN_GETSERVBYPORT)(int port, const char *proto);
  typedef struct servent  *(WSAAPI *LPFN_GETSERVBYNAME)(const char *name, const char *proto);
  typedef struct protoent *(WSAAPI *LPFN_GETPROTOBYNUMBER)(int number);
  typedef struct protoent *(WSAAPI *LPFN_GETPROTOBYNAME)(const char *name);
  typedef int              (WSAAPI *LPFN_WSASTARTUP)(WORD wVersionRequested, LPWSADATA lpWSAData);
  typedef int              (WSAAPI *LPFN_WSACLEANUP)(void);
  typedef void             (WSAAPI *LPFN_WSASETLASTERROR)(int iError);
  typedef int              (WSAAPI *LPFN_WSAGETLASTERROR)(void);

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  typedef WINBOOL (WSAAPI *LPFN_WSAISBLOCKING)(void);
  typedef int     (WSAAPI *LPFN_WSAUNHOOKBLOCKINGHOOK)(void);
  typedef FARPROC (WSAAPI *LPFN_WSASETBLOCKINGHOOK)(FARPROC lpBlockFunc);
  typedef int     (WSAAPI *LPFN_WSACANCELBLOCKINGCALL)(void);
  typedef HANDLE  (WSAAPI *LPFN_WSAASYNCGETSERVBYNAME)(HWND hWnd, u_int wMsg, const char *name, const char *proto, char *buf, int buflen);
  typedef HANDLE  (WSAAPI *LPFN_WSAASYNCGETSERVBYPORT)(HWND hWnd, u_int wMsg, int port, const char *proto, char *buf, int buflen);
  typedef HANDLE  (WSAAPI *LPFN_WSAASYNCGETPROTOBYNAME)(HWND hWnd, u_int wMsg, const char *name, char *buf, int buflen);
  typedef HANDLE  (WSAAPI *LPFN_WSAASYNCGETPROTOBYNUMBER)(HWND hWnd, u_int wMsg, int number, char *buf, int buflen);
  typedef HANDLE  (WSAAPI *LPFN_WSAASYNCGETHOSTBYNAME)(HWND hWnd, u_int wMsg, const char *name, char *buf, int buflen);
  typedef HANDLE  (WSAAPI *LPFN_WSAASYNCGETHOSTBYADDR)(HWND hWnd, u_int wMsg, const char *addr, int len, int type, char *buf, int buflen);
  typedef int     (WSAAPI *LPFN_WSACANCELASYNCREQUEST)(HANDLE hAsyncTaskHandle);
  typedef int     (WSAAPI *LPFN_WSAASYNCSELECT)(SOCKET s, HWND hWnd, u_int wMsg, long lEvent);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

  typedef int      (WSAAPI * LPFN_GETHOSTNAMEW)(PWSTR name, int namelen);
  typedef SOCKET   (WSAAPI *LPFN_WSAACCEPT)(SOCKET s, struct sockaddr *addr, LPINT addrlen, LPCONDITIONPROC lpfnCondition, DWORD_PTR dwCallbackData);
  typedef WINBOOL  (WSAAPI *LPFN_WSACLOSEEVENT)(WSAEVENT hEvent);
  typedef int      (WSAAPI *LPFN_WSACONNECT)(SOCKET s, const struct sockaddr *name, int namelen, LPWSABUF lpCallerData, LPWSABUF lpCalleeData, LPQOS lpSQOS, LPQOS lpGQOS);
  typedef WSAEVENT (WSAAPI *LPFN_WSACREATEEVENT)(void);
  typedef int      (WSAAPI *LPFN_WSADUPLICATESOCKETA)(SOCKET s, DWORD dwProcessId, LPWSAPROTOCOL_INFOA lpProtocolInfo);
  typedef int      (WSAAPI *LPFN_WSADUPLICATESOCKETW)(SOCKET s, DWORD dwProcessId, LPWSAPROTOCOL_INFOW lpProtocolInfo);
#define LPFN_WSADUPLICATESOCKET __MINGW_NAME_AW(LPFN_WSADUPLICATESOCKET)
  typedef int      (WSAAPI *LPFN_WSAENUMNETWORKEVENTS)(SOCKET s, WSAEVENT hEventObject, LPWSANETWORKEVENTS lpNetworkEvents);
  typedef int      (WSAAPI *LPFN_WSAENUMPROTOCOLSA)(LPINT lpiProtocols, LPWSAPROTOCOL_INFOA lpProtocolBuffer, LPDWORD lpdwBufferLength);
  typedef int      (WSAAPI *LPFN_WSAENUMPROTOCOLSW)(LPINT lpiProtocols, LPWSAPROTOCOL_INFOW lpProtocolBuffer, LPDWORD lpdwBufferLength);
#define LPFN_WSAENUMPROTOCOLS __MINGW_NAME_AW(LPFN_WSAENUMPROTOCOLS)
  typedef int      (WSAAPI *LPFN_WSAEVENTSELECT)(SOCKET s, WSAEVENT hEventObject, long lNetworkEvents);
  typedef WINBOOL  (WSAAPI *LPFN_WSAGETOVERLAPPEDRESULT)(SOCKET s, LPWSAOVERLAPPED lpOverlapped, LPDWORD lpcbTransfer, WINBOOL fWait, LPDWORD lpdwFlags);
  typedef int      (WSAAPI *LPFN_WSAHTONL)(SOCKET s, u_long hostlong, u_long *lpnetlong);
  typedef int      (WSAAPI *LPFN_WSAHTONS)(SOCKET s, u_short hostshort, u_short *lpnetshort);
  typedef int      (WSAAPI *LPFN_WSAIOCTL)(SOCKET s, DWORD dwIoControlCode, LPVOID lpvInBuffer, DWORD cbInBuffer, LPVOID lpvOutBuffer, DWORD cbOutBuffer, LPDWORD lpcbBytesReturned, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  typedef SOCKET   (WSAAPI *LPFN_WSAJOINLEAF)(SOCKET s, const struct sockaddr *name, int namelen, LPWSABUF lpCallerData, LPWSABUF lpCalleeData, LPQOS lpSQOS, LPQOS lpGQOS, DWORD dwFlags);
  typedef int      (WSAAPI *LPFN_WSANTOHL)(SOCKET s, u_long netlong, u_long *lphostlong);
  typedef int      (WSAAPI *LPFN_WSANTOHS)(SOCKET s, u_short netshort, u_short *lphostshort);
  typedef int      (WSAAPI *LPFN_WSARECV)(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesRecvd, LPDWORD lpFlags, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  typedef int      (WSAAPI *LPFN_WSARECVFROM)(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesRecvd, LPDWORD lpFlags, struct sockaddr *lpFrom, LPINT lpFromlen, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  typedef WINBOOL  (WSAAPI *LPFN_WSARESETEVENT)(WSAEVENT hEvent);
  typedef int      (WSAAPI *LPFN_WSASEND)(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesSent, DWORD dwFlags, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  typedef int      (WSAAPI *LPFN_WSASENDTO)(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesSent, DWORD dwFlags, const struct sockaddr *lpTo, int iTolen, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  typedef WINBOOL  (WSAAPI *LPFN_WSASETEVENT)(WSAEVENT hEvent);
  typedef SOCKET   (WSAAPI *LPFN_WSASOCKETA)(int af, int type, int protocol, LPWSAPROTOCOL_INFOA lpProtocolInfo, GROUP g, DWORD dwFlags);
  typedef SOCKET   (WSAAPI *LPFN_WSASOCKETW)(int af, int type, int protocol, LPWSAPROTOCOL_INFOW lpProtocolInfo, GROUP g, DWORD dwFlags);
#define LPFN_WSASOCKET __MINGW_NAME_AW(LPFN_WSASOCKET)
  typedef DWORD    (WSAAPI *LPFN_WSAWAITFORMULTIPLEEVENTS)(DWORD cEvents, const WSAEVENT *lphEvents, WINBOOL fWaitAll, DWORD dwTimeout, WINBOOL fAlertable);
  typedef INT      (WSAAPI *LPFN_WSAADDRESSTOSTRINGA)(LPSOCKADDR lpsaAddress, DWORD dwAddressLength, LPWSAPROTOCOL_INFOA lpProtocolInfo, LPSTR lpszAddressString, LPDWORD lpdwAddressStringLength);
  typedef INT      (WSAAPI *LPFN_WSAADDRESSTOSTRINGW)(LPSOCKADDR lpsaAddress, DWORD dwAddressLength, LPWSAPROTOCOL_INFOW lpProtocolInfo, LPWSTR lpszAddressString, LPDWORD lpdwAddressStringLength);
#define LPFN_WSAADDRESSTOSTRING __MINGW_NAME_AW(LPFN_WSAADDRESSTOSTRING)
  typedef INT      (WSAAPI *LPFN_WSASTRINGTOADDRESSA)(LPSTR AddressString, INT AddressFamily, LPWSAPROTOCOL_INFOA lpProtocolInfo, LPSOCKADDR lpAddress, LPINT lpAddressLength);
  typedef INT      (WSAAPI *LPFN_WSASTRINGTOADDRESSW)(LPWSTR AddressString, INT AddressFamily, LPWSAPROTOCOL_INFOW lpProtocolInfo, LPSOCKADDR lpAddress, LPINT lpAddressLength);
#define LPFN_WSASTRINGTOADDRESS __MINGW_NAME_AW(LPFN_WSASTRINGTOADDRESS)
  typedef INT      (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINA)(LPWSAQUERYSETA lpqsRestrictions, DWORD dwControlFlags, LPHANDLE lphLookup);
  typedef INT      (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINW)(LPWSAQUERYSETW lpqsRestrictions, DWORD dwControlFlags, LPHANDLE lphLookup);
#define LPFN_WSALOOKUPSERVICEBEGIN __MINGW_NAME_AW(LPFN_WSALOOKUPSERVICEBEGIN)
  typedef INT      (WSAAPI *LPFN_WSALOOKUPSERVICENEXTA)(HANDLE hLookup, DWORD dwControlFlags, LPDWORD lpdwBufferLength, LPWSAQUERYSETA lpqsResults);
  typedef INT      (WSAAPI *LPFN_WSALOOKUPSERVICENEXTW)(HANDLE hLookup, DWORD dwControlFlags, LPDWORD lpdwBufferLength, LPWSAQUERYSETW lpqsResults);
#define LPFN_WSALOOKUPSERVICENEXT __MINGW_NAME_AW(LPFN_WSALOOKUPSERVICENEXT)
  typedef INT      (WSAAPI *LPFN_WSANSPIOCTL)(HANDLE hLookup, DWORD dwControlCode, LPVOID lpvInBuffer, DWORD cbInBuffer, LPVOID lpvOutBuffer, DWORD cbOutBuffer, LPDWORD lpcbBytesReturned, LPWSACOMPLETION lpCompletion);
  typedef INT      (WSAAPI *LPFN_WSALOOKUPSERVICEEND)(HANDLE hLookup);
  typedef INT      (WSAAPI *LPFN_WSAGETSERVICECLASSINFOW)(LPGUID lpProviderId, LPGUID lpServiceClassId, LPDWORD lpdwBufSize, LPWSASERVICECLASSINFOW lpServiceClassInfo);
  typedef INT      (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSA)(LPDWORD lpdwBufferLength, LPWSANAMESPACE_INFOA lpnspBuffer);
  typedef INT      (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSW)(LPDWORD lpdwBufferLength, LPWSANAMESPACE_INFOW lpnspBuffer);
#define LPFN_WSAENUMNAMESPACEPROVIDERS __MINGW_NAME_AW(LPFN_WSAENUMNAMESPACEPROVIDERS)
  typedef INT      (WSAAPI * LPFN_WSAENUMNAMESPACEPROVIDERSEXA)(LPDWORD lpdwBufferLength, LPWSANAMESPACE_INFOEXA lpnspBuffer);
  typedef INT      (WSAAPI * LPFN_WSAENUMNAMESPACEPROVIDERSEXW)(LPDWORD lpdwBufferLength, LPWSANAMESPACE_INFOEXW lpnspBuffer);
#define LPFN_WSAENUMNAMESPACEPROVIDERSEX __MINGW_NAME_AW(LPFN_WSAENUMNAMESPACEPROVIDERSEX)
  typedef INT      (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW)(LPGUID lpServiceClassId, LPWSTR lpszServiceClassName, LPDWORD lpdwBufferLength);
  typedef INT      (WSAAPI *LPFN_WSAPROVIDERCONFIGCHANGE)(LPHANDLE lpNotificationHandle, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  typedef WINBOOL (WSAAPI *LPFN_WSAGETQOSBYNAME)(SOCKET s, LPWSABUF lpQOSName, LPQOS lpQOS);
  typedef int     (WSAAPI *LPFN_WSARECVDISCONNECT)(SOCKET s, LPWSABUF lpInboundDisconnectData);
  typedef int     (WSAAPI *LPFN_WSASENDDISCONNECT)(SOCKET s, LPWSABUF lpOutboundDisconnectData);
  typedef INT     (WSAAPI *LPFN_WSAINSTALLSERVICECLASSA)(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  typedef INT     (WSAAPI *LPFN_WSAINSTALLSERVICECLASSW)(LPWSASERVICECLASSINFOW lpServiceClassInfo);
#define LPFN_WSAINSTALLSERVICECLASS __MINGW_NAME_AW(LPFN_WSAINSTALLSERVICECLASS)
  typedef INT     (WSAAPI *LPFN_WSAREMOVESERVICECLASS)(LPGUID lpServiceClassId);
  typedef INT     (WSAAPI *LPFN_WSAGETSERVICECLASSINFOA)(LPGUID lpProviderId, LPGUID lpServiceClassId, LPDWORD lpdwBufSize, LPWSASERVICECLASSINFOA lpServiceClassInfo);
  typedef INT     (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA)(LPGUID lpServiceClassId, LPSTR lpszServiceClassName, LPDWORD lpdwBufferLength);
  typedef INT     (WSAAPI *LPFN_WSASETSERVICEA)(LPWSAQUERYSETA lpqsRegInfo, WSAESETSERVICEOP essoperation, DWORD dwControlFlags);
  typedef INT     (WSAAPI *LPFN_WSASETSERVICEW)(LPWSAQUERYSETW lpqsRegInfo, WSAESETSERVICEOP essoperation, DWORD dwControlFlags);
#define LPFN_WSASETSERVICE __MINGW_NAME_AW(LPFN_WSASETSERVICE)

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#ifdef UNICODE
# define LPFN_WSAGETSERVICECLASSINFO          LPFN_WSAGETSERVICECLASSINFOW
# define LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW
#else
# if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
#   define LPFN_WSAGETSERVICECLASSINFO          LPFN_WSAGETSERVICECLASSINFOA
#   define LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA
# endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */
#endif

#endif  /* INCL_WINSOCK_API_TYPEDEFS */

#if !defined(NO_EXTRA_HTON_FUNCTIONS) && !defined(__WIDL__)

#define _WS2_32_WINSOCK_SWAP_LONG(l) ((((l) >> 24) & 0x000000FFL) | (((l) >>  8) & 0x0000FF00L) | (((l) <<  8) & 0x00FF0000L) | (((l) << 24) & 0xFF000000L))

#define _WS2_32_WINSOCK_SWAP_LONGLONG(l) \
  ((((l) >> 56) & 0x00000000000000FFLL) | (((l) >> 40) & 0x000000000000FF00LL) | (((l) >> 24) & 0x0000000000FF0000LL) | (((l) >>  8) & 0x00000000FF000000LL) | \
  (((l) <<  8) & 0x000000FF00000000LL) | (((l) << 24) & 0x0000FF0000000000LL) | (((l) << 40) & 0x00FF000000000000LL) | (((l) << 56) & 0xFF00000000000000LL))

#ifndef htonll
  __forceinline
  unsigned __int64 htonll(unsigned __int64 Value)
  {
    const unsigned __int64 Retval = _WS2_32_WINSOCK_SWAP_LONGLONG(Value);
    return Retval;
  }
#endif

#ifndef ntohll
  __forceinline
  unsigned __int64 ntohll(unsigned __int64 Value)
  {
    const unsigned __int64 Retval = _WS2_32_WINSOCK_SWAP_LONGLONG(Value);
    return Retval;
  }
#endif

#ifndef htonf
  __forceinline
  unsigned __int32 htonf(float Value)
  {
    unsigned __int32 Tempval;
    unsigned __int32 Retval;
  	Tempval = *(unsigned __int32 *)(&Value);
    Retval = _WS2_32_WINSOCK_SWAP_LONG(Tempval);
    return Retval;
  }
#endif

#ifndef ntohf
  __forceinline
  float ntohf(unsigned __int32 Value)
  {
    const unsigned __int32 Tempval = _WS2_32_WINSOCK_SWAP_LONG(Value);
    float Retval;
    *((unsigned __int32 *)&Retval) = Tempval;
    return Retval;
  }
#endif

#ifndef htond
  __forceinline
  unsigned __int64 htond(double Value)
  {
    unsigned __int64 Tempval;
    unsigned __int64 Retval;
  	Tempval = *(unsigned __int64 *)(&Value);
    Retval = _WS2_32_WINSOCK_SWAP_LONGLONG(Tempval);
    return Retval;
  }
#endif

#ifndef ntohd
  __forceinline
  double ntohd(unsigned __int64 Value)
  {
    const unsigned __int64 Tempval = _WS2_32_WINSOCK_SWAP_LONGLONG(Value);
    double Retval;
    *((unsigned __int64 *)&Retval) = Tempval;
    return Retval;
  }
#endif

#endif  /* !defined(NO_EXTRA_HTON_FUNCTIONS) && !defined(__WIDL__) */

#define SOCK_NOTIFY_REGISTER_EVENT_NONE   0x00
#define SOCK_NOTIFY_REGISTER_EVENT_IN     0x01
#define SOCK_NOTIFY_REGISTER_EVENT_OUT    0x02
#define SOCK_NOTIFY_REGISTER_EVENT_HANGUP 0x04
#define SOCK_NOTIFY_REGISTER_EVENTS_ALL   (SOCK_NOTIFY_REGISTER_EVENT_IN | SOCK_NOTIFY_REGISTER_EVENT_OUT | SOCK_NOTIFY_REGISTER_EVENT_HANGUP)
#define SOCK_NOTIFY_EVENT_IN              SOCK_NOTIFY_REGISTER_EVENT_IN
#define SOCK_NOTIFY_EVENT_OUT             SOCK_NOTIFY_REGISTER_EVENT_OUT
#define SOCK_NOTIFY_EVENT_HANGUP          SOCK_NOTIFY_REGISTER_EVENT_HANGUP
#define SOCK_NOTIFY_EVENT_ERR             0x40
#define SOCK_NOTIFY_EVENT_REMOVE          0x80
#define SOCK_NOTIFY_EVENTS_ALL            (SOCK_NOTIFY_REGISTER_EVENTS_ALL | SOCK_NOTIFY_EVENT_ERR | SOCK_NOTIFY_EVENT_REMOVE)
#define SOCK_NOTIFY_OP_NONE               0x00
#define SOCK_NOTIFY_OP_ENABLE             0x01
#define SOCK_NOTIFY_OP_DISABLE            0x02
#define SOCK_NOTIFY_OP_REMOVE             0x04
#define SOCK_NOTIFY_TRIGGER_ONESHOT       0x01
#define SOCK_NOTIFY_TRIGGER_PERSISTENT    0x02
#define SOCK_NOTIFY_TRIGGER_LEVEL         0x04
#define SOCK_NOTIFY_TRIGGER_EDGE          0x08
#define SOCK_NOTIFY_TRIGGER_ALL           (SOCK_NOTIFY_TRIGGER_ONESHOT | SOCK_NOTIFY_TRIGGER_PERSISTENT | SOCK_NOTIFY_TRIGGER_LEVEL | SOCK_NOTIFY_TRIGGER_EDGE)

#define WSAMAKEASYNCREPLY(buflen, error) MAKELONG(buflen, error)
#define WSAMAKESELECTREPLY(event, error) MAKELONG(event, error)
#define WSAGETASYNCBUFLEN(lParam)        LOWORD(lParam)
#define WSAGETASYNCERROR(lParam)         HIWORD(lParam)
#define WSAGETSELECTEVENT(lParam)        LOWORD(lParam)
#define WSAGETSELECTERROR(lParam)        HIWORD(lParam)

#ifdef __cplusplus
}
#endif

#ifdef IPV6STRICT
# include <wsipv6ok.h>
#endif

#endif  /* _WINSOCK2API_ */
