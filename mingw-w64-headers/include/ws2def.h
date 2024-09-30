/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WS2DEF_
#define _WS2DEF_

#include <_mingw.h>
#include <winapifamily.h>

#ifndef _WINSOCK_DEPRECATED_BY
# define _WINSOCK_DEPRECATED_BY(replacement)
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(_WINSOCK2API_) && defined(_WINSOCKAPI_)
# error Do not include winsock.h and ws2def.h in the same module. Instead include only winsock2.h.
#endif

#define WS2DEF_INLINE __CRT_INLINE

#include <inaddr.h>

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  typedef USHORT ADDRESS_FAMILY;

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#define AF_UNSPEC     0
#define AF_UNIX       1
#define AF_INET       2
#define AF_IMPLINK    3
#define AF_PUP        4
#define AF_CHAOS      5
#define AF_NS         6
#define AF_IPX        AF_NS
#define AF_ISO        7
#define AF_OSI        AF_ISO
#define AF_ECMA       8
#define AF_DATAKIT    9
#define AF_CCITT      10
#define AF_SNA        11
#define AF_DECnet     12
#define AF_DLI        13
#define AF_LAT        14
#define AF_HYLINK     15
#define AF_APPLETALK  16
#define AF_NETBIOS    17
#define AF_VOICEVIEW  18
#define AF_FIREFOX    19
#define AF_UNKNOWN1   20
#define AF_BAN        21
#define AF_ATM        22
#define AF_INET6      23
#define AF_CLUSTER    24
#define AF_12844      25
#define AF_IRDA       26
#define AF_NETDES     28
#define AF_TCNPROCESS 29
#define AF_TCNMESSAGE 30
#define AF_ICLFXBM    31
#define AF_BTH        32
#define AF_LINK       33
#define AF_HYPERV     34
#define AF_MAX        35

#define SOCK_STREAM    1
#define SOCK_DGRAM     2
#define SOCK_RAW       3
#define SOCK_RDM       4
#define SOCK_SEQPACKET 5

#define SOL_SOCKET 0xffff
#define SOL_IP     (SOL_SOCKET - 4)
#define SOL_IPV6   (SOL_SOCKET - 5)

#define SO_DEBUG               0x0001
#define SO_ACCEPTCONN          0x0002
#define SO_REUSEADDR           0x0004
#define SO_KEEPALIVE           0x0008
#define SO_DONTROUTE           0x0010
#define SO_BROADCAST           0x0020
#define SO_USELOOPBACK         0x0040
#define SO_LINGER              0x0080
#define SO_OOBINLINE           0x0100
#define SO_DONTLINGER          (int)(~SO_LINGER)
#define SO_EXCLUSIVEADDRUSE    ((int)(~SO_REUSEADDR))
#define SO_SNDBUF              0x1001
#define SO_RCVBUF              0x1002
#define SO_SNDLOWAT            0x1003
#define SO_RCVLOWAT            0x1004
#define SO_SNDTIMEO            0x1005
#define SO_RCVTIMEO            0x1006
#define SO_ERROR               0x1007
#define SO_TYPE                0x1008
#define SO_BSP_STATE           0x1009
#define SO_GROUP_ID            0x2001
#define SO_GROUP_PRIORITY      0x2002
#define SO_MAX_MSG_SIZE        0x2003
#define SO_CONDITIONAL_ACCEPT  0x3002
#define SO_PAUSE_ACCEPT        0x3003
#define SO_COMPARTMENT_ID      0x3004
#define SO_RANDOMIZE_PORT      0x3005
#define SO_PORT_SCALABILITY    0x3006
#define SO_REUSE_UNICASTPORT   0x3007
#define SO_REUSE_MULTICASTPORT 0x3008
#define SO_ORIGINAL_DST        0x300F
#define IP6T_SO_ORIGINAL_DST   SO_ORIGINAL_DST

#define WSK_SO_BASE 0x4000

#define TCP_NODELAY 0x0001

#include <psdk_inc/_ip_types.h>

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#ifndef __CSADDR_DEFINED__
#define __CSADDR_DEFINED__

  typedef struct _SOCKET_ADDRESS
  {
    LPSOCKADDR lpSockaddr;
    INT        iSockaddrLength;
  } SOCKET_ADDRESS, *PSOCKET_ADDRESS, *LPSOCKET_ADDRESS;

  typedef struct _SOCKET_ADDRESS_LIST
  {
    INT            iAddressCount;
    SOCKET_ADDRESS Address[1];
  } SOCKET_ADDRESS_LIST, *PSOCKET_ADDRESS_LIST, *LPSOCKET_ADDRESS_LIST;

#define SIZEOF_SOCKET_ADDRESS_LIST(AddressCount) (FIELD_OFFSET(SOCKET_ADDRESS_LIST, Address) + AddressCount * sizeof(SOCKET_ADDRESS))

  typedef struct _CSADDR_INFO
  {
    SOCKET_ADDRESS LocalAddr;
    SOCKET_ADDRESS RemoteAddr;
    INT            iSocketType;
    INT            iProtocol;
  } CSADDR_INFO, *PCSADDR_INFO, *LPCSADDR_INFO;

#endif  /* __CSADDR_DEFINED__ */

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#define _SS_MAXSIZE   128
#define _SS_ALIGNSIZE (sizeof(__int64))
#define _SS_PAD1SIZE  (_SS_ALIGNSIZE - sizeof(USHORT))
#define _SS_PAD2SIZE  (_SS_MAXSIZE - (sizeof(USHORT) + _SS_PAD1SIZE + _SS_ALIGNSIZE))

  typedef struct sockaddr_storage
  {
    ADDRESS_FAMILY              ss_family;
    CHAR                      __ss_pad1[_SS_PAD1SIZE];
    __MINGW_EXTENSION __int64 __ss_align;
    CHAR                      __ss_pad2[_SS_PAD2SIZE];
  } SOCKADDR_STORAGE_LH, *PSOCKADDR_STORAGE_LH, *LPSOCKADDR_STORAGE_LH;

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

  typedef struct sockaddr_storage_xp
  {
    short                       ss_family;
    CHAR                      __ss_pad1[_SS_PAD1SIZE];
    __MINGW_EXTENSION __int64 __ss_align;
    CHAR                      __ss_pad2[_SS_PAD2SIZE];
  } SOCKADDR_STORAGE_XP, *PSOCKADDR_STORAGE_XP, *LPSOCKADDR_STORAGE_XP;

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */

  typedef SOCKADDR_STORAGE_LH SOCKADDR_STORAGE;
  typedef SOCKADDR_STORAGE   *PSOCKADDR_STORAGE, *LPSOCKADDR_STORAGE;

  typedef struct _SOCKET_PROCESSOR_AFFINITY
  {
    PROCESSOR_NUMBER Processor;
    USHORT           NumaNodeId;
    USHORT           Reserved;
  } SOCKET_PROCESSOR_AFFINITY, *PSOCKET_PROCESSOR_AFFINITY;

#define IOC_UNIX     0x00000000
#define IOC_WS2      0x08000000
#define IOC_PROTOCOL 0x10000000
#define IOC_VENDOR   0x18000000
#define IOC_WSK      (IOC_WS2 | 0x07000000)

#define _WSAIO(x, y)   (IOC_VOID | (x) | (y))
#define _WSAIOR(x, y)  (IOC_OUT | (x) | (y))
#define _WSAIOW(x, y)  (IOC_IN | (x) | (y))
#define _WSAIORW(x, y) (IOC_INOUT | (x) | (y))

#define SIO_ASSOCIATE_HANDLE                        _WSAIOW(IOC_WS2, 1)
#define SIO_ENABLE_CIRCULAR_QUEUEING                _WSAIO(IOC_WS2, 2)
#define SIO_FIND_ROUTE                              _WSAIOR(IOC_WS2, 3)
#define SIO_FLUSH                                   _WSAIO(IOC_WS2, 4)
#define SIO_GET_BROADCAST_ADDRESS                   _WSAIOR(IOC_WS2, 5)
#define SIO_GET_EXTENSION_FUNCTION_POINTER          _WSAIORW(IOC_WS2, 6)
#define SIO_GET_QOS                                 _WSAIORW(IOC_WS2, 7)
#define SIO_GET_GROUP_QOS                           _WSAIORW(IOC_WS2, 8)
#define SIO_MULTIPOINT_LOOPBACK                     _WSAIOW(IOC_WS2, 9)
#define SIO_MULTICAST_SCOPE                         _WSAIOW(IOC_WS2, 10)
#define SIO_SET_QOS                                 _WSAIOW(IOC_WS2, 11)
#define SIO_SET_GROUP_QOS                           _WSAIOW(IOC_WS2, 12)
#define SIO_TRANSLATE_HANDLE                        _WSAIORW(IOC_WS2, 13)
#define SIO_ROUTING_INTERFACE_QUERY                 _WSAIORW(IOC_WS2, 20)
#define SIO_ROUTING_INTERFACE_CHANGE                _WSAIOW(IOC_WS2, 21)
#define SIO_ADDRESS_LIST_QUERY                      _WSAIOR(IOC_WS2, 22)
#define SIO_ADDRESS_LIST_CHANGE                     _WSAIO(IOC_WS2, 23)
#define SIO_QUERY_TARGET_PNP_HANDLE                 _WSAIOR(IOC_WS2, 24)
#define SIO_QUERY_RSS_PROCESSOR_INFO                _WSAIOR(IOC_WS2, 37)
#define SIO_ADDRESS_LIST_SORT                       _WSAIORW(IOC_WS2, 25)
#define SIO_RESERVED_1                              _WSAIOW(IOC_WS2, 26)
#define SIO_RESERVED_2                              _WSAIOW(IOC_WS2, 33)
#define SIO_GET_MULTIPLE_EXTENSION_FUNCTION_POINTER _WSAIORW(IOC_WS2, 36)

#define IPPROTO_IP 0

  typedef enum
  {
    IPPROTO_HOPOPTS                = 0,
    IPPROTO_ICMP                   = 1,
    IPPROTO_IGMP                   = 2,
    IPPROTO_GGP                    = 3,
    IPPROTO_IPV4                   = 4,
    IPPROTO_ST                     = 5,
    IPPROTO_TCP                    = 6,
    IPPROTO_CBT                    = 7,
    IPPROTO_EGP                    = 8,
    IPPROTO_IGP                    = 9,
    IPPROTO_PUP                    = 12,
    IPPROTO_UDP                    = 17,
    IPPROTO_IDP                    = 22,
    IPPROTO_RDP                    = 27,
    IPPROTO_IPV6                   = 41,
    IPPROTO_ROUTING                = 43,
    IPPROTO_FRAGMENT               = 44,
    IPPROTO_ESP                    = 50,
    IPPROTO_AH                     = 51,
    IPPROTO_ICMPV6                 = 58,
    IPPROTO_NONE                   = 59,
    IPPROTO_DSTOPTS                = 60,
    IPPROTO_ND                     = 77,
    IPPROTO_ICLFXBM                = 78,
    IPPROTO_PIM                    = 103,
    IPPROTO_PGM                    = 113,
    IPPROTO_L2TP                   = 115,
    IPPROTO_SCTP                   = 132,
    IPPROTO_RAW                    = 255,
    IPPROTO_MAX                    = 256,
    IPPROTO_RESERVED_RAW           = 257,
    IPPROTO_RESERVED_IPSEC         = 258,
    IPPROTO_RESERVED_IPSECOFFLOAD  = 259,
    IPPROTO_RESERVED_WNV           = 260,
    IPPROTO_RESERVED_MAX           = 261
  } IPPROTO, *PIPROTO;

#define IPPORT_TCPMUX         1
#define IPPORT_ECHO           7
#define IPPORT_DISCARD        9
#define IPPORT_SYSTAT         11
#define IPPORT_DAYTIME        13
#define IPPORT_NETSTAT        15
#define IPPORT_QOTD           17
#define IPPORT_MSP            18
#define IPPORT_CHARGEN        19
#define IPPORT_FTP_DATA       20
#define IPPORT_FTP            21
#define IPPORT_TELNET         23
#define IPPORT_SMTP           25
#define IPPORT_TIMESERVER     37
#define IPPORT_NAMESERVER     42
#define IPPORT_WHOIS          43
#define IPPORT_MTP            57
#define IPPORT_TFTP           69
#define IPPORT_RJE            77
#define IPPORT_FINGER         79
#define IPPORT_TTYLINK        87
#define IPPORT_SUPDUP         95
#define IPPORT_POP3           110
#define IPPORT_NTP            123
#define IPPORT_EPMAP          135
#define IPPORT_NETBIOS_NS     137
#define IPPORT_NETBIOS_DGM    138
#define IPPORT_NETBIOS_SSN    139
#define IPPORT_IMAP           143
#define IPPORT_SNMP           161
#define IPPORT_SNMP_TRAP      162
#define IPPORT_IMAP3          220
#define IPPORT_LDAP           389
#define IPPORT_HTTPS          443
#define IPPORT_MICROSOFT_DS   445
#define IPPORT_EXECSERVER     512
#define IPPORT_LOGINSERVER    513
#define IPPORT_CMDSERVER      514
#define IPPORT_EFSSERVER      520
#define IPPORT_BIFFUDP        512
#define IPPORT_WHOSERVER      513
#define IPPORT_ROUTESERVER    520
#define IPPORT_RESERVED       1024
#define IPPORT_REGISTERED_MIN IPPORT_RESERVED
#define IPPORT_REGISTERED_MAX 0xbfff
#define IPPORT_DYNAMIC_MIN    0xc000
#define IPPORT_DYNAMIC_MAX    0xffff

#define IN_CLASSA(i)     (((LONG)(i) & 0x80000000) == 0)
#define IN_CLASSA_NET    0xff000000
#define IN_CLASSA_NSHIFT 24
#define IN_CLASSA_HOST   0x00ffffff
#define IN_CLASSA_MAX    128

#define IN_CLASSB(i)     (((LONG)(i) & 0xc0000000) == 0x80000000)
#define IN_CLASSB_NET    0xffff0000
#define IN_CLASSB_NSHIFT 16
#define IN_CLASSB_HOST   0x0000ffff
#define IN_CLASSB_MAX    65536

#define IN_CLASSC(i)     (((LONG)(i) & 0xe0000000) == 0xc0000000)
#define IN_CLASSC_NET    0xffffff00
#define IN_CLASSC_NSHIFT 8
#define IN_CLASSC_HOST   0x000000ff

#define IN_CLASSD(i)     (((long)(i) & 0xf0000000) == 0xe0000000)
#define IN_CLASSD_NET    0xf0000000
#define IN_CLASSD_NSHIFT 28
#define IN_CLASSD_HOST   0x0fffffff
#define IN_MULTICAST(i)  IN_CLASSD(i)

#define INADDR_ANY       (ULONG)0x00000000
#define INADDR_LOOPBACK  0x7f000001
#define INADDR_BROADCAST (ULONG)0xffffffff
#define INADDR_NONE      0xffffffff

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  typedef enum _SCOPE_LEVEL
  {
    ScopeLevelInterface    = 1,
    ScopeLevelLink         = 2,
    ScopeLevelSubnet       = 3,
    ScopeLevelAdmin        = 4,
    ScopeLevelSite         = 5,
    ScopeLevelOrganization = 8,
    ScopeLevelGlobal       = 14,
    ScopeLevelCount        = 16
  } SCOPE_LEVEL;

  typedef struct _SCOPE_ID
  {
    __C89_NAMELESS union
    {
      __C89_NAMELESS struct
      {
        ULONG Zone  : 28;
        ULONG Level : 4;
      };
      ULONG Value;
    };
  } SCOPE_ID, *PSCOPE_ID;

#define SCOPEID_UNSPECIFIED_INIT { 0 }

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

  typedef struct sockaddr_dl
  {
    ADDRESS_FAMILY sdl_family;
    UCHAR          sdl_data[8];
    UCHAR          sdl_zero[4];
  } SOCKADDR_DL, *PSOCKADDR_DL;

#define IOCPARM_MASK 0x7f
#define IOC_VOID     0x20000000
#define IOC_OUT      0x40000000
#define IOC_IN       0x80000000
#define IOC_INOUT    (IOC_IN | IOC_OUT)

#define _IO(x, y)     (IOC_VOID | ((x) << 8) | (y))
#define _IOR(x, y, t) (IOC_OUT | (((long)sizeof(t) & IOCPARM_MASK) << 16) | ((x) << 8) | (y))
#define _IOW(x, y, t) (IOC_IN | (((long)sizeof(t) & IOCPARM_MASK) << 16) | ((x) << 8) | (y))

  typedef struct _WSABUF
  {
    ULONG  len;
    CHAR  *buf;
  } WSABUF, *LPWSABUF;

  typedef struct _WSAMSG
  {
    LPSOCKADDR name;
    INT        namelen;
    LPWSABUF   lpBuffers;
    ULONG      dwBufferCount;
    WSABUF     Control;
    ULONG      dwFlags;
  } WSAMSG, *PWSAMSG, *LPWSAMSG;

#define _WSACMSGHDR cmsghdr

  typedef struct _WSACMSGHDR
  {
    SIZE_T cmsg_len;
    INT    cmsg_level;
    INT    cmsg_type;
  } WSACMSGHDR, *PWSACMSGHDR, *LPWSACMSGHDR;

  typedef WSACMSGHDR CMSGHDR, *PCMSGHDR;

#define WSA_CMSGHDR_ALIGN(length)  (((length) + TYPE_ALIGNMENT(WSACMSGHDR) - 1) & (~(TYPE_ALIGNMENT(WSACMSGHDR) - 1)))
#define WSA_CMSGDATA_ALIGN(length) (((length) + MAX_NATURAL_ALIGNMENT - 1) & (~(MAX_NATURAL_ALIGNMENT - 1)))

#define CMSGHDR_ALIGN  WSA_CMSGHDR_ALIGN
#define CMSGDATA_ALIGN WSA_CMSGDATA_ALIGN

#define WSA_CMSG_FIRSTHDR(msg) \
  (((msg)->Control.len >= sizeof(WSACMSGHDR)) \
    ? (LPWSACMSGHDR)(msg)->Control.buf        \
    : (LPWSACMSGHDR)NULL)

#define CMSG_FIRSTHDR WSA_CMSG_FIRSTHDR

#define WSA_CMSG_NXTHDR(msg, cmsg)                                                  \
  (((cmsg) == NULL)                                                                 \
    ? WSA_CMSG_FIRSTHDR(msg)                                                        \
    : ((((PUCHAR)(cmsg) + WSA_CMSGHDR_ALIGN((cmsg)->cmsg_len) + sizeof(WSACMSGHDR)) \
      > (PUCHAR)((msg)->Control.buf) + (msg)->Control.len)                          \
        ? (LPWSACMSGHDR)NULL                                                        \
        : (LPWSACMSGHDR)((PUCHAR)(cmsg) + WSA_CMSGHDR_ALIGN((cmsg)->cmsg_len))))

#define CMSG_NXTHDR WSA_CMSG_NXTHDR

#define WSA_CMSG_DATA(cmsg)    ((PUCHAR)(cmsg) + WSA_CMSGDATA_ALIGN(sizeof(WSACMSGHDR)))
#define WSA_CMSG_SPACE(length) (WSA_CMSGDATA_ALIGN(sizeof(WSACMSGHDR) + WSA_CMSGHDR_ALIGN(length)))

#define CMSG_SPACE WSA_CMSG_SPACE

#define WSA_CMSG_LEN(length) (WSA_CMSGDATA_ALIGN(sizeof(WSACMSGHDR)) + length)

#define CMSG_LEN WSA_CMSG_LEN

#define MSG_TRUNC    0x0100
#define MSG_CTRUNC   0x0200
#define MSG_BCAST    0x0400
#define MSG_MCAST    0x0800
#define MSG_ERRQUEUE 0x1000

#define AI_PASSIVE                  0x00000001
#define AI_CANONNAME                0x00000002
#define AI_NUMERICHOST              0x00000004
#define AI_NUMERICSERV              0x00000008
#define AI_DNS_ONLY                 0x00000010
#define AI_FORCE_CLEAR_TEXT         0x00000020
#define AI_BYPASS_DNS_CACHE         0x00000040
#define AI_RETURN_TTL               0x00000080
#define AI_ALL                      0x00000100
#define AI_ADDRCONFIG               0x00000400
#define AI_V4MAPPED                 0x00000800
#define AI_NON_AUTHORITATIVE        0x00004000
#define AI_SECURE                   0x00008000
#define AI_RETURN_PREFERRED_NAMES   0x00010000
#define AI_FQDN                     0x00020000
#define AI_FILESERVER               0x00040000
#define AI_DISABLE_IDN_ENCODING     0x00080000
#define AI_SECURE_WITH_FALLBACK     0x00100000
#define AI_EXCLUSIVE_CUSTOM_SERVERS 0x00200000
#define AI_RETURN_RESPONSE_FLAGS    0x10000000
#define AI_REQUIRE_SECURE           0x20000000
#define AI_RESOLUTION_HANDLE        0x40000000
#define AI_EXTENDED                 0x80000000

  typedef struct addrinfo
  {
    int              ai_flags;
    int              ai_family;
    int              ai_socktype;
    int              ai_protocol;
    size_t           ai_addrlen;
    char            *ai_canonname;
    struct sockaddr *ai_addr;
    struct addrinfo *ai_next;
  } ADDRINFOA, *PADDRINFOA;

  typedef struct addrinfoW
  {
    int               ai_flags;
    int               ai_family;
    int               ai_socktype;
    int               ai_protocol;
    size_t            ai_addrlen;
    PWSTR             ai_canonname;
    struct sockaddr  *ai_addr;
    struct addrinfoW *ai_next;
  } ADDRINFOW, *PADDRINFOW;

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  typedef struct addrinfoexA
  {
    int                 ai_flags;
    int                 ai_family;
    int                 ai_socktype;
    int                 ai_protocol;
    size_t              ai_addrlen;
    char               *ai_canonname;
    struct sockaddr    *ai_addr;
    void               *ai_blob;
    size_t              ai_bloblen;
    LPGUID              ai_provider;
    struct addrinfoexA *ai_next;
  } ADDRINFOEXA, *PADDRINFOEXA, *LPADDRINFOEXA;

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

  typedef struct addrinfoexW
  {
    int                 ai_flags;
    int                 ai_family;
    int                 ai_socktype;
    int                 ai_protocol;
    size_t              ai_addrlen;
    PWSTR               ai_canonname;
    struct sockaddr    *ai_addr;
    void               *ai_blob;
    size_t              ai_bloblen;
    LPGUID              ai_provider;
    struct addrinfoexW *ai_next;
  } ADDRINFOEXW, *PADDRINFOEXW, *LPADDRINFOEXW;

#define ADDRINFOEX_VERSION_2 2
#define ADDRINFOEX_VERSION_3 3
#define ADDRINFOEX_VERSION_4 4
#define ADDRINFOEX_VERSION_5 5
#define ADDRINFOEX_VERSION_6 6
#define ADDRINFOEX_VERSION_7 7

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

  typedef struct addrinfoex2A
  {
    int                  ai_flags;
    int                  ai_family;
    int                  ai_socktype;
    int                  ai_protocol;
    size_t               ai_addrlen;
    char                *ai_canonname;
    struct sockaddr     *ai_addr;
    void                *ai_blob;
    size_t               ai_bloblen;
    LPGUID               ai_provider;
    struct addrinfoex2A *ai_next;
    int                  ai_version;
    char                *ai_fqdn;
  } ADDRINFOEX2A, *PADDRINFOEX2A, *LPADDRINFOEX2A;

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */

  typedef struct addrinfoex2W
  {
    int                  ai_flags;
    int                  ai_family;
    int                  ai_socktype;
    int                  ai_protocol;
    size_t               ai_addrlen;
    PWSTR                ai_canonname;
    struct sockaddr     *ai_addr;
    void                *ai_blob;
    size_t               ai_bloblen;
    LPGUID               ai_provider;
    struct addrinfoex2W *ai_next;
    int                  ai_version;
    PWSTR                ai_fqdn;
  } ADDRINFOEX2W, *PADDRINFOEX2W, *LPADDRINFOEX2W;

  typedef struct addrinfoex3
  {
    int                 ai_flags;
    int                 ai_family;
    int                 ai_socktype;
    int                 ai_protocol;
    size_t              ai_addrlen;
    PWSTR               ai_canonname;
    struct sockaddr    *ai_addr;
    void               *ai_blob;
    size_t              ai_bloblen;
    LPGUID              ai_provider;
    struct addrinfoex3 *ai_next;
    int                 ai_version;
    PWSTR               ai_fqdn;
    int                 ai_interfaceindex;
  } ADDRINFOEX3, *PADDRINFOEX3, *LPADDRINFOEX3;

  typedef struct addrinfoex4
  {
    int                 ai_flags;
    int                 ai_family;
    int                 ai_socktype;
    int                 ai_protocol;
    size_t              ai_addrlen;
    PWSTR               ai_canonname;
    struct sockaddr    *ai_addr;
    void               *ai_blob;
    size_t              ai_bloblen;
    GUID               *ai_provider;
    struct addrinfoex4 *ai_next;
    int                 ai_version;
    PWSTR               ai_fqdn;
    int                 ai_interfaceindex;
    HANDLE              ai_resolutionhandle;
  } ADDRINFOEX4, *PADDRINFOEX4, *LPADDRINFOEX4;

  typedef struct addrinfoex5
  {
    int                 ai_flags;
    int                 ai_family;
    int                 ai_socktype;
    int                 ai_protocol;
    size_t              ai_addrlen;
    PWSTR               ai_canonname;
    struct sockaddr    *ai_addr;
    void               *ai_blob;
    size_t              ai_bloblen;
    GUID               *ai_provider;
    struct addrinfoex5 *ai_next;
    int                 ai_version;
    PWSTR               ai_fqdn;
    int                 ai_interfaceindex;
    HANDLE              ai_resolutionhandle;
    unsigned int        ai_ttl;
  } ADDRINFOEX5, *PADDRINFOEX5, *LPADDRINFOEX5;

#define AI_DNS_SERVER_TYPE_UDP     0x1
#define AI_DNS_SERVER_TYPE_DOH     0x2
#define AI_DNS_SERVER_TYPE_DOT     0x3
#define AI_DNS_SERVER_UDP_FALLBACK 0x1

  typedef struct addrinfo_dns_server
  {
    unsigned int                       ai_servertype;
    __MINGW_EXTENSION unsigned __int64 ai_flags;
    unsigned int                       ai_addrlen;
    struct sockaddr                   *ai_addr;
    __C89_NAMELESS union
    {
      PWSTR ai_template;
      PWSTR ai_hostname;
    };
  } ADDRINFO_DNS_SERVER;

#define AI_DNS_RESPONSE_SECURE   0x1
#define AI_DNS_RESPONSE_HOSTFILE 0x2

  typedef struct addrinfoex6
  {
    int                  ai_flags;
    int                  ai_family;
    int                  ai_socktype;
    int                  ai_protocol;
    size_t               ai_addrlen;
    PWSTR                ai_canonname;
    struct sockaddr     *ai_addr;
    void                *ai_blob;
    size_t               ai_bloblen;
    GUID                *ai_provider;
    struct addrinfoex5  *ai_next;
    int                  ai_version;
    PWSTR                ai_fqdn;
    int                  ai_interfaceindex;
    HANDLE               ai_resolutionhandle;
    unsigned int         ai_ttl;
    unsigned int         ai_numservers;
    ADDRINFO_DNS_SERVER *ai_servers;
    ULONG64              ai_responseflags;
  } ADDRINFOEX6, *PADDRINFOEX6;

#define AI_EXTRA_DNSSEC_REQUIRED 0x0000000000000001

  typedef struct addrinfoex7
  {
    int                  ai_flags;
    int                  ai_family;
    int                  ai_socktype;
    int                  ai_protocol;
    size_t               ai_addrlen;
    PWSTR                ai_canonname;
    struct sockaddr     *ai_addr;
    void                *ai_blob;
    size_t               ai_bloblen;
    GUID                *ai_provider;
    struct addrinfoex7  *ai_next;
    int                  ai_version;
    PWSTR                ai_fqdn;
    int                  ai_interfaceindex;
    HANDLE               ai_resolutionhandle;
    unsigned int         ai_ttl;
    unsigned int         ai_numservers;
    ADDRINFO_DNS_SERVER *ai_servers;
    ULONG64              ai_responseflags;
    ULONG64              ai_extraflags;
  } ADDRINFOEX7, *PADDRINFOEX7;

#define NS_ALL         (0)
#define NS_SAP         (1)
#define NS_NDS         (2)
#define NS_PEER_BROWSE (3)
#define NS_SLP         (5)
#define NS_DHCP        (6)
#define NS_TCPIP_LOCAL (10)
#define NS_TCPIP_HOSTS (11)
#define NS_DNS         (12)
#define NS_NETBT       (13)
#define NS_WINS        (14)
#define NS_NLA         (15)
#define NS_BTH         (16)
#define NS_NBP         (20)
#define NS_MS          (30)
#define NS_STDA        (31)
#define NS_NTDS        (32)
#define NS_EMAIL       (37)
#define NS_PNRPNAME    (38)
#define NS_PNRPCLOUD   (39)
#define NS_X500        (40)
#define NS_NIS         (41)
#define NS_NISPLUS     (42)
#define NS_WRQ         (50)
#define NS_NETDES      (60)

#define NI_NOFQDN      0x01
#define NI_NUMERICHOST 0x02
#define NI_NAMEREQD    0x04
#define NI_NUMERICSERV 0x08
#define NI_DGRAM       0x10
#define NI_MAXHOST     1025
#define NI_MAXSERV     32

#ifdef __cplusplus
}
#endif

#endif  /* _WS2DEF_ */
