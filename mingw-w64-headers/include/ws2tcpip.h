/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _WS2TCPIP_H_
#define _WS2TCPIP_H_

#include <_mingw_unicode.h>
#include <winapifamily.h>

#ifndef _WINSOCK_DEPRECATED_BY
# define _WINSOCK_DEPRECATED_BY(replacement)
#endif

#include <winsock2.h>
#include <ws2ipdef.h>
#include <limits.h>

#define UDP_NOCHECKSUM        1
#define UDP_CHECKSUM_COVERAGE 20

#define EAI_AGAIN        WSATRY_AGAIN
#define EAI_BADFLAGS     WSAEINVAL
#define EAI_FAIL         WSANO_RECOVERY
#define EAI_FAMILY       WSAEAFNOSUPPORT
#define EAI_MEMORY       WSA_NOT_ENOUGH_MEMORY
#define EAI_NOSECURENAME WSA_SECURE_HOST_NOT_FOUND
#define EAI_NONAME       WSAHOST_NOT_FOUND
#define EAI_SERVICE      WSATYPE_NOT_FOUND
#define EAI_SOCKTYPE     WSAESOCKTNOSUPPORT
#define EAI_IPSECPOLICY  WSA_IPSEC_NAME_POLICY_ERROR
/* #define EAI_NODATA       EAI_NONAME */
#define EAI_NODATA       WSANO_DATA

  typedef __MINGW_NAME_AW(ADDRINFO) ADDRINFOT, *PADDRINFOT;
  typedef ADDRINFOA                 ADDRINFO, *LPADDRINFO;

#ifdef UNICODE
  typedef ADDRINFOEXW ADDRINFOEX, *PADDRINFOEX;
#else
# if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
    typedef ADDRINFOEXA ADDRINFOEX, *PADDRINFOEX;
# endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#endif

#ifdef __cplusplus
extern "C" {
#endif

  WINSOCK_API_LINKAGE INT WSAAPI getaddrinfo(PCSTR pNodeName, PCSTR pServiceName, const ADDRINFOA *pHints, PADDRINFOA *ppResult);
  WINSOCK_API_LINKAGE INT WSAAPI GetAddrInfoW(PCWSTR pNodeName, PCWSTR pServiceName, const ADDRINFOW *pHints, PADDRINFOW *ppResult);
#define GetAddrInfoA getaddrinfo
#define GetAddrInfo  __MINGW_NAME_AW(GetAddrInfo)

  typedef void (CALLBACK * LPLOOKUPSERVICE_COMPLETION_ROUTINE)(DWORD dwError, DWORD dwBytes, LPWSAOVERLAPPED lpOverlapped);

  WINSOCK_API_LINKAGE INT    WSAAPI GetAddrInfoExW(PCWSTR pName, PCWSTR pServiceName, DWORD dwNameSpace, LPGUID lpNspId, const ADDRINFOEXW *hints, PADDRINFOEXW *ppResult, struct timeval *timeout, LPOVERLAPPED lpOverlapped, LPLOOKUPSERVICE_COMPLETION_ROUTINE lpCompletionRoutine, LPHANDLE lpNameHandle);
  WINSOCK_API_LINKAGE INT    WSAAPI GetAddrInfoExCancel(LPHANDLE lpHandle);
  WINSOCK_API_LINKAGE INT    WSAAPI GetAddrInfoExOverlappedResult(LPOVERLAPPED lpOverlapped);
  WINSOCK_API_LINKAGE INT    WSAAPI SetAddrInfoExW(PCWSTR pName, PCWSTR pServiceName, SOCKET_ADDRESS *pAddresses, DWORD dwAddressCount, LPBLOB lpBlob, DWORD dwFlags, DWORD dwNameSpace, LPGUID lpNspId, struct timeval *timeout, LPOVERLAPPED lpOverlapped, LPLOOKUPSERVICE_COMPLETION_ROUTINE lpCompletionRoutine, LPHANDLE lpNameHandle);
  WINSOCK_API_LINKAGE VOID   WSAAPI freeaddrinfo(PADDRINFOA pAddrInfo);
  WINSOCK_API_LINKAGE VOID   WSAAPI FreeAddrInfoW(PADDRINFOW pAddrInfo);
#define FreeAddrInfoA freeaddrinfo
#define FreeAddrInfo  __MINGW_NAME_AW(FreeAddrInfo)
  WINSOCK_API_LINKAGE void   WSAAPI FreeAddrInfoExW(PADDRINFOEXW pAddrInfo);

  typedef int socklen_t;

  WINSOCK_API_LINKAGE INT    WSAAPI getnameinfo(const SOCKADDR *pSockaddr, socklen_t SockaddrLength, PCHAR pNodeBuffer, DWORD NodeBufferSize, PCHAR pServiceBuffer, DWORD ServiceBufferSize, INT Flags);
  WINSOCK_API_LINKAGE INT    WSAAPI GetNameInfoW(const SOCKADDR *pSockaddr, socklen_t SockaddrLength, PWCHAR pNodeBuffer, DWORD NodeBufferSize, PWCHAR pServiceBuffer, DWORD ServiceBufferSize, INT Flags);
#define GetNameInfoA getnameinfo
#define GetNameInfo  __MINGW_NAME_AW(GetNameInfo)
  WINSOCK_API_LINKAGE INT    WSAAPI inet_pton(INT Family, PCSTR pszAddrString, PVOID pAddrBuf);
  /**/                INT    WSAAPI InetPtonW(INT Family, PCWSTR pszAddrString, PVOID pAddrBuf);
  /**/                PCSTR  WSAAPI inet_ntop(INT Family, const VOID *pAddr, PSTR pStringBuf, size_t StringBufSize);
  /**/                PCWSTR WSAAPI InetNtopW(INT Family, const VOID *pAddr, PWSTR pStringBuf, size_t StringBufSIze);
#define InetPtonA inet_pton
#define InetNtopA inet_ntop
#define InetPton  __MINGW_NAME_AW(InetPton)
#define InetNtop  __MINGW_NAME_AW(InetNtop)

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  WINSOCK_API_LINKAGE INT WSAAPI GetAddrInfoExA(PCSTR pName, PCSTR pServiceName, DWORD dwNameSpace, LPGUID lpNspId, const ADDRINFOEXA *hints, PADDRINFOEXA *ppResult, struct timeval *timeout, LPOVERLAPPED lpOverlapped, LPLOOKUPSERVICE_COMPLETION_ROUTINE lpCompletionRoutine, LPHANDLE lpNameHandle);
  WINSOCK_API_LINKAGE INT WSAAPI SetAddrInfoExA(PCSTR pName, PCSTR pServiceName, SOCKET_ADDRESS *pAddresses, DWORD dwAddressCount, LPBLOB lpBlob, DWORD dwFlags, DWORD dwNameSpace, LPGUID lpNspId, struct timeval *timeout, LPOVERLAPPED lpOverlapped, LPLOOKUPSERVICE_COMPLETION_ROUTINE lpCompletionRoutine, LPHANDLE lpNameHandle);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  WINSOCK_API_LINKAGE void WSAAPI FreeAddrInfoEx(PADDRINFOEXA pAddrInfo);
#define FreeAddrInfoExA FreeAddrInfoEx

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#ifdef UNICODE
# define GetAddrInfoEx  GetAddrInfoExW
# define SetAddrInfoEx  SetAddrInfoExW
# define FreeAddrInfoEx FreeAddrInfoExW
#else
# if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
#   define GetAddrInfoEx GetAddrInfoExA
#   define SetAddrInfoEx SetAddrInfoExA
# endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#endif

#if INCL_WINSOCK_API_TYPEDEFS

  typedef INT    (WSAAPI *LPFN_GETADDRINFO)(PCSTR pNodeName, PCSTR pServiceName, const ADDRINFOA *pHints, PADDRINFOA *ppResult);
  typedef INT    (WSAAPI *LPFN_GETADDRINFOW)(PCWSTR pNodeName, PCWSTR pServiceName, const ADDRINFOW *pHints, PADDRINFOW *ppResult);
#define LPFN_GETADDRINFOA LPFN_GETADDRINFO
#define LPFN_GETADDRINFOT __MINGW_NAME_AW(LPFN_GETADDRINFO)
  typedef INT    (WSAAPI *LPFN_GETADDRINFOEXW)(PCWSTR pName, PCWSTR pServiceName, DWORD dwNameSpace, LPGUID lpNspId, const ADDRINFOEXW *hints, PADDRINFOEXW *ppResult, struct timeval *timeout, LPOVERLAPPED lpOverlapped, LPLOOKUPSERVICE_COMPLETION_ROUTINE lpCompletionRoutine, LPHANDLE lpNameHandle);
  typedef INT    (WSAAPI *LPFN_GETADDRINFOEXCANCEL)(LPHANDLE lpHandle);
  typedef INT    (WSAAPI *LPFN_GETADDRINFOEXOVERLAPPEDRESULT)(LPOVERLAPPED lpOverlapped);
  typedef INT    (WSAAPI *LPFN_SETADDRINFOEXW)(PCWSTR pName, PCWSTR pServiceName, SOCKET_ADDRESS *pAddresses, DWORD dwAddressCount, LPBLOB lpBlob, DWORD dwFlags, DWORD dwNameSpace, LPGUID lpNspId, struct timeval *timeout, LPOVERLAPPED lpOverlapped, LPLOOKUPSERVICE_COMPLETION_ROUTINE lpCompletionRoutine, LPHANDLE lpNameHandle);
  typedef VOID   (WSAAPI *LPFN_FREEADDRINFO)(PADDRINFOA pAddrInfo);
  typedef VOID   (WSAAPI *LPFN_FREEADDRINFOW)(PADDRINFOW pAddrInfo);
#define LPFN_FREEADDRINFOA LPFN_FREEADDRINFO
#define LPFN_FREEADDRINFOT __MINGW_NAME_AW(LPFN_FREEADDRINFO)
  typedef void   (WSAAPI *LPFN_FREEADDRINFOEXW)(PADDRINFOEXW pAddrInfo);
  typedef int    (WSAAPI *LPFN_GETNAMEINFO)(const SOCKADDR *pSockaddr, socklen_t SockaddrLength, PCHAR pNodeBuffer, DWORD NodeBufferSize, PCHAR pServiceBuffer, DWORD ServiceBufferSize, INT Flags);
  typedef INT    (WSAAPI *LPFN_GETNAMEINFOW)(const SOCKADDR *pSockaddr, socklen_t SockaddrLength, PWCHAR pNodeBuffer, DWORD NodeBufferSize, PWCHAR pServiceBuffer, DWORD ServiceBufferSize, INT Flags);
#define LPFN_GETNAMEINFOA LPFN_GETNAMEINFO
#define LPFN_GETNAMEINFOT __MINGW_NAME_AW(LPFN_GETNAMEINFO)
  typedef INT    (WSAAPI *LPFN_INET_PTONA)(INT Family, PCSTR pszAddrString, PVOID pAddrBuf);
  typedef INT    (WSAAPI *LPFN_INET_PTONW)(INT Family, PCWSTR pszAddrString, PVOID pAddrBuf);
  typedef PCSTR  (WSAAPI *LPFN_INET_NTOPA)(INT Family, PVOID pAddr, PSTR pStringBuf, size_t StringBufSize);
  typedef PCWSTR (WSAAPI *LPFN_INET_NTOPW)(INT Family, PVOID pAddr, PWSTR pStringBuf, size_t StringBufSize);
#define LPFN_INET_PTON __MINGW_NAME_AW(LPFN_INET_PTON)
#define LPFN_INET_NTOP __MINGW_NAME_AW(LPFN_INET_NTOP)

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  typedef INT  (WSAAPI *LPFN_GETADDRINFOEXA)(PCSTR pName, PCSTR pServiceName, DWORD dwNameSpace, LPGUID lpNspId, const ADDRINFOEXA *hints, PADDRINFOEXA *ppResult, struct timeval *timeout, LPOVERLAPPED lpOverlapped, LPLOOKUPSERVICE_COMPLETION_ROUTINE lpCompletionRoutine, LPHANDLE lpNameHandle);
  typedef INT  (WSAAPI *LPFN_SETADDRINFOEXA)(PCSTR pName, PCSTR pServiceName, SOCKET_ADDRESS *pAddresses, DWORD dwAddressCount, LPBLOB lpBlob, DWORD dwFlags, DWORD dwNameSpace, LPGUID lpNspId, struct timeval *timeout, LPOVERLAPPED lpOverlapped, LPLOOKUPSERVICE_COMPLETION_ROUTINE lpCompletionRoutine, LPHANDLE lpNameHandle);
  typedef void (WSAAPI *LPFN_FREEADDRINFOEXA)(PADDRINFOEXA pAddrInfo);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#ifdef UNICODE
# define LPFN_GETADDRINFOEX  LPFN_GETADDRINFOEXW
# define LPFN_SETADDRINFOEX  LPFN_SETADDRINFOEXW
# define LPFN_FREEADDRINFOEX LPFN_FREEADDRINFOEXW
#else
# if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
#   define LPFN_GETADDRINFOEX  LPFN_GETADDRINFOEXA
#   define LPFN_SETADDRINFOEX  LPFN_SETADDRINFOEXA
#   define LPFN_FREEADDRINFOEX LPFN_FREEADDRINFOEXA
# endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#endif

#endif  /* INCL_WINSOCK_API_TYPEDEFS */

#if INCL_WINSOCK_API_PROTOTYPES

#define GAI_STRERROR_BUFFER_SIZE 1024

  char  *gai_strerrorA(int);
  WS2TCPIP_INLINE
  char *gai_strerrorA(int ecode)
  {
    static char buff[GAI_STRERROR_BUFFER_SIZE + 1];
    (void)FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_MAX_WIDTH_MASK,
            NULL, ecode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)buff,
            GAI_STRERROR_BUFFER_SIZE, NULL);
    return buff;
  }

  WCHAR *gai_strerrorW(int);
  WS2TCPIP_INLINE
  WCHAR *gai_strerrorW(int ecode)
  {
    static WCHAR buff[GAI_STRERROR_BUFFER_SIZE + 1];
    (void)FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_MAX_WIDTH_MASK,
            NULL, ecode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPWSTR)buff,
            GAI_STRERROR_BUFFER_SIZE, NULL);
    return buff;
  }

#define gai_strerror __MINGW_NAME_AW(gai_strerror)

#endif  /* INCL_WINSOCK_API_PROTOTYPES */

  WS2TCPIP_INLINE
  int setipv4sourcefilter(SOCKET Socket, IN_ADDR Interface, IN_ADDR Group, MULTICAST_MODE_TYPE FilterMode, ULONG SourceCount, CONST IN_ADDR *SourceList)
  {
    int Error;
    DWORD Size, Returned;
    PIP_MSFILTER Filter;

    if(SourceCount > (((ULONG)(ULONG_MAX - sizeof(*Filter))) / sizeof(*SourceList)))
    {
      WSASetLastError(WSAENOBUFS);
      return SOCKET_ERROR;
    }

    Size   = IP_MSFILTER_SIZE(SourceCount);
    Filter = (PIP_MSFILTER)HeapAlloc(GetProcessHeap(), 0, Size);
    if(Filter == NULL)
    {
      WSASetLastError(WSAENOBUFS);
      return SOCKET_ERROR;
    }

    Filter->imsf_multiaddr = Group;
    Filter->imsf_interface = Interface;
    Filter->imsf_fmode     = FilterMode;
    Filter->imsf_numsrc    = SourceCount;
    if(SourceCount > 0)
    {
      CopyMemory(Filter->imsf_slist, SourceList, SourceCount * sizeof(*SourceList));
    }

    Error = WSAIoctl(Socket, SIOCSIPMSFILTER, Filter, Size, NULL, 0, &Returned, NULL, NULL);
    HeapFree(GetProcessHeap(), 0, Filter);
    return Error;
  }

  WS2TCPIP_INLINE
  int getipv4sourcefilter(SOCKET Socket, IN_ADDR Interface, IN_ADDR Group, MULTICAST_MODE_TYPE *FilterMode, ULONG *SourceCount, IN_ADDR *SourceList)
  {
    int Error;
    DWORD Size, Returned;
    PIP_MSFILTER Filter;

    if(*SourceCount > (((ULONG)(ULONG_MAX - sizeof(*Filter))) / sizeof(*SourceList)))
    {
      WSASetLastError(WSAENOBUFS);
      return SOCKET_ERROR;
    }

    Size   = IP_MSFILTER_SIZE(*SourceCount);
    Filter = (PIP_MSFILTER)HeapAlloc(GetProcessHeap(), 0, Size);
    if(Filter == NULL)
    {
      WSASetLastError(WSAENOBUFS);
      return SOCKET_ERROR;
    }

    Filter->imsf_multiaddr = Group;
    Filter->imsf_interface = Interface;
    Filter->imsf_numsrc  = *SourceCount;

    Error = WSAIoctl(Socket, SIOCGIPMSFILTER, Filter, Size, Filter, Size, &Returned, NULL, NULL);
    if(Error == 0)
    {
      if(*SourceCount > 0)
      {
        CopyMemory(SourceList, Filter->imsf_slist, *SourceCount * sizeof(*SourceList));
        *SourceCount = Filter->imsf_numsrc;
      }
      *FilterMode = Filter->imsf_fmode;
    }

    HeapFree(GetProcessHeap(), 0, Filter);
    return Error;
  }

  WS2TCPIP_INLINE
  int setsourcefilter(SOCKET Socket, ULONG Interface, CONST SOCKADDR *Group, int GroupLength, MULTICAST_MODE_TYPE FilterMode, ULONG SourceCount, CONST SOCKADDR_STORAGE *SourceList)
  {
    int Error;
    DWORD Size, Returned;
    PGROUP_FILTER Filter;

    if(SourceCount >= (((ULONG)(ULONG_MAX - sizeof(*Filter))) / sizeof(*SourceList)))
    {
      WSASetLastError(WSAENOBUFS);
      return SOCKET_ERROR;
    }

    Size   = GROUP_FILTER_SIZE(SourceCount);
    Filter = (PGROUP_FILTER)HeapAlloc(GetProcessHeap(), 0, Size);
    if(Filter == NULL)
    {
      WSASetLastError(WSAENOBUFS);
      return SOCKET_ERROR;
    }

    Filter->gf_interface = Interface;
    ZeroMemory(&Filter->gf_group, sizeof(Filter->gf_group));
    CopyMemory(&Filter->gf_group, Group, GroupLength);
    Filter->gf_fmode  = FilterMode;
    Filter->gf_numsrc = SourceCount;
    if(SourceCount > 0)
    {
      CopyMemory(Filter->gf_slist, SourceList, SourceCount * sizeof(*SourceList));
    }

    Error = WSAIoctl(Socket, SIOCSMSFILTER, Filter, Size, NULL, 0, &Returned, NULL, NULL);
    HeapFree(GetProcessHeap(), 0, Filter);
    return Error;
  }

  WS2TCPIP_INLINE
  int getsourcefilter(SOCKET Socket, ULONG Interface, CONST SOCKADDR *Group, int GroupLength, MULTICAST_MODE_TYPE *FilterMode, ULONG *SourceCount, SOCKADDR_STORAGE *SourceList)
  {
    int Error;
    DWORD Size, Returned;
    PGROUP_FILTER Filter;

    if(*SourceCount > (((ULONG)(ULONG_MAX - sizeof(*Filter))) / sizeof(*SourceList)))
    {
      WSASetLastError(WSAENOBUFS);
      return SOCKET_ERROR;
    }

    Size   = GROUP_FILTER_SIZE(*SourceCount);
    Filter = (PGROUP_FILTER)HeapAlloc(GetProcessHeap(), 0, Size);
    if(Filter == NULL)
    {
      WSASetLastError(WSAENOBUFS);
      return SOCKET_ERROR;
    }

    Filter->gf_interface = Interface;
    ZeroMemory(&Filter->gf_group, sizeof(Filter->gf_group));
    CopyMemory(&Filter->gf_group, Group, GroupLength);
    Filter->gf_numsrc = *SourceCount;

    Error = WSAIoctl(Socket, SIOCGMSFILTER, Filter, Size, Filter, Size, &Returned, NULL, NULL);
    if(Error == 0)
    {
      if(*SourceCount > 0)
      {
        CopyMemory(SourceList, Filter->gf_slist, *SourceCount * sizeof(*SourceList));
        *SourceCount = Filter->gf_numsrc;
      }
      *FilterMode = Filter->gf_fmode;
    }

    HeapFree(GetProcessHeap(), 0, Filter);
    return Error;
  }

#ifdef IDEAL_SEND_BACKLOG_IOCTLS

  WS2TCPIP_INLINE
  int idealsendbacklogquery(SOCKET s, ULONG *pISB)
  {
    DWORD bytes;
    return WSAIoctl(s, SIO_IDEAL_SEND_BACKLOG_QUERY, NULL, 0, pISB, sizeof(*pISB), &bytes, NULL, NULL);
  }

  WS2TCPIP_INLINE
  int idealsendbacklognotify(SOCKET s, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine)
  {
    DWORD bytes;
    return WSAIoctl(s, SIO_IDEAL_SEND_BACKLOG_CHANGE, NULL, 0, NULL, 0, &bytes, lpOverlapped, lpCompletionRoutine);
  }

#endif  /* IDEAL_SEND_BACKLOG_IOCTLS */

  WS2TCPIP_INLINE
  INT WSAGetIPUserMtu(SOCKET Socket, DWORD *Mtu)
  {
    WSAPROTOCOL_INFOW Info;
    INT InfoSize = sizeof(Info);
    INT OptSize  = sizeof(*Mtu);
    INT Error;

    Error = getsockopt(Socket, SOL_SOCKET, SO_PROTOCOL_INFO, (PCHAR)&Info, &InfoSize);
    if(Error != SOCKET_ERROR)
    {
      if(Info.iAddressFamily == AF_INET)
      {
        Error = getsockopt(Socket, IPPROTO_IP, IP_USER_MTU, (PCHAR)Mtu, &OptSize);
      }
      else if(Info.iAddressFamily == AF_INET6)
      {
        Error = getsockopt(Socket, IPPROTO_IPV6, IPV6_USER_MTU, (PCHAR)Mtu, &OptSize);
      }
      else
      {
        Error = SOCKET_ERROR;
        WSASetLastError(WSAEAFNOSUPPORT);
      }
    }

    return Error;
  }

  WS2TCPIP_INLINE
  INT WSASetIPUserMtu(SOCKET Socket, DWORD Mtu)
  {
    WSAPROTOCOL_INFOW Info;
    INT InfoSize = sizeof(Info);
    INT Error;

    Error = getsockopt(Socket, SOL_SOCKET, SO_PROTOCOL_INFO, (PCHAR)&Info, &InfoSize);
    if(Error != SOCKET_ERROR)
    {
      if(Info.iAddressFamily == AF_INET)
      {
        Error = setsockopt(Socket, IPPROTO_IP, IP_USER_MTU, (PCHAR)&Mtu, sizeof(Mtu));
      }
      else if(Info.iAddressFamily == AF_INET6)
      {
        Error = setsockopt(Socket, IPPROTO_IPV6, IPV6_USER_MTU, (PCHAR)&Mtu, sizeof(Mtu));
      }
      else
      {
        Error = SOCKET_ERROR;
        WSASetLastError(WSAEAFNOSUPPORT);
      }
    }

    return Error;
  }

  WS2TCPIP_INLINE
  INT WSAGetFailConnectOnIcmpError(SOCKET Socket, DWORD *Enabled)
  {
    INT OptSize = sizeof(*Enabled);
    return getsockopt(Socket, IPPROTO_TCP, TCP_FAIL_CONNECT_ON_ICMP_ERROR, (CHAR*)Enabled, &OptSize);
  }

  WS2TCPIP_INLINE
  INT WSASetFailConnectOnIcmpError(SOCKET Socket, DWORD Enabled)
  {
    return setsockopt(Socket, IPPROTO_TCP, TCP_FAIL_CONNECT_ON_ICMP_ERROR, (CHAR*)&Enabled, sizeof(Enabled));
  }

  WS2TCPIP_INLINE
  INT WSAGetIcmpErrorInfo(SOCKET Socket, ICMP_ERROR_INFO *Info)
  {
    INT Error;
    INT OptSize = sizeof(*Info);

    Error = getsockopt(Socket, IPPROTO_TCP, TCP_ICMP_ERROR_INFO, (CHAR*)Info, &OptSize);
    if(Error != SOCKET_ERROR && OptSize == 0)
    {
      Error = SOCKET_ERROR;
      WSASetLastError(WSANO_DATA);
    }

    return Error;
  }

  WS2TCPIP_INLINE
  INT WSAGetUdpSendMessageSize(SOCKET Socket, DWORD *MsgSize)
  {
    INT OptSize = sizeof(*MsgSize);
    return getsockopt(Socket, IPPROTO_UDP, UDP_SEND_MSG_SIZE, (PCHAR)MsgSize, &OptSize);
  }

  WS2TCPIP_INLINE
  INT WSASetUdpSendMessageSize(SOCKET Socket, DWORD MsgSize)
  {
    return setsockopt(Socket, IPPROTO_UDP, UDP_SEND_MSG_SIZE, (PCHAR)&MsgSize, sizeof(MsgSize));
  }

  WS2TCPIP_INLINE
  INT WSAGetUdpRecvMaxCoalescedSize(SOCKET Socket, DWORD *MaxCoalescedMsgSize)
  {
    INT OptSize = sizeof(*MaxCoalescedMsgSize);
    return getsockopt(Socket, IPPROTO_UDP, UDP_RECV_MAX_COALESCED_SIZE, (PCHAR)MaxCoalescedMsgSize, &OptSize);
  }

  WS2TCPIP_INLINE
  INT WSASetUdpRecvMaxCoalescedSize(SOCKET Socket, DWORD MaxCoalescedMsgSize)
  {
    return setsockopt(Socket, IPPROTO_UDP, UDP_RECV_MAX_COALESCED_SIZE, (PCHAR)&MaxCoalescedMsgSize, sizeof(MaxCoalescedMsgSize));
  }

  WS2TCPIP_INLINE
  INT WSAGetRecvIPEcn(SOCKET Socket, DWORD *Enabled)
  {
    WSAPROTOCOL_INFOW Info;
    INT InfoSize = sizeof(Info);
    INT OptSize  = sizeof(*Enabled);
    INT Error;

    Error = getsockopt(Socket, SOL_SOCKET, SO_PROTOCOL_INFO, (PCHAR)&Info, &InfoSize);
    if(Error != SOCKET_ERROR)
    {
      if(Info.iAddressFamily == AF_INET)
      {
        Error = getsockopt(Socket, IPPROTO_IP, IP_RECVECN, (PCHAR)Enabled, &OptSize);
      }
      else if(Info.iAddressFamily == AF_INET6)
      {
        Error = getsockopt(Socket, IPPROTO_IPV6, IPV6_RECVECN, (PCHAR)Enabled, &OptSize);
      }
      else
      {
        Error = SOCKET_ERROR;
        WSASetLastError(WSAEAFNOSUPPORT);
      }
    }

    return Error;
}

  WS2TCPIP_INLINE
  INT WSASetRecvIPEcn(SOCKET Socket, DWORD Enabled)
  {
    WSAPROTOCOL_INFOW Info;
    INT InfoSize = sizeof(Info);
    INT Error;

    Error = getsockopt(Socket, SOL_SOCKET, SO_PROTOCOL_INFO, (PCHAR)&Info, &InfoSize);
    if(Error != SOCKET_ERROR)
    {
      if(Info.iAddressFamily == AF_INET)
      {
        Error = setsockopt(Socket, IPPROTO_IP, IP_RECVECN, (PCHAR)&Enabled, sizeof(Enabled));
      }
      else if(Info.iAddressFamily == AF_INET6)
      {
        Error = setsockopt(Socket, IPPROTO_IPV6, IPV6_RECVECN, (PCHAR)&Enabled, sizeof(Enabled));
      }
      else
      {
        Error = SOCKET_ERROR;
        WSASetLastError(WSAEAFNOSUPPORT);
      }
    }

    return Error;
  }

#include <mstcpip.h>

#ifdef _SECURE_SOCKET_TYPES_DEFINED_

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_PKG_APPRUNTIME)

  WINSOCK_API_LINKAGE INT WSAAPI WSASetSocketSecurity(SOCKET Socket, const SOCKET_SECURITY_SETTINGS *SecuritySettings, ULONG SecuritySettingsLen, LPWSAOVERLAPPED Overlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE CompletionRoutine);
  WINSOCK_API_LINKAGE INT WSAAPI WSAQuerySocketSecurity(SOCKET Socket, const SOCKET_SECURITY_QUERY_TEMPLATE *SecurityQueryTemplate, ULONG SecurityQueryTemplateLen, SOCKET_SECURITY_QUERY_INFO *SecurityQueryInfo, ULONG *SecurityQueryInfoLen, LPWSAOVERLAPPED Overlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE CompletionRoutine);
  WINSOCK_API_LINKAGE INT WSAAPI WSASetSocketPeerTargetName(SOCKET Socket, const SOCKET_PEER_TARGET_NAME *PeerTargetName, ULONG PeerTargetNameLen, LPWSAOVERLAPPED Overlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE CompletionRoutine);
  WINSOCK_API_LINKAGE INT WSAAPI WSADeleteSocketPeerTargetName(SOCKET Socket, const struct sockaddr *PeerAddr, ULONG PeerAddrLen, LPWSAOVERLAPPED Overlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE CompletionRoutine);
  WINSOCK_API_LINKAGE INT WSAAPI WSAImpersonateSocketPeer(SOCKET Socket, const struct sockaddr *PeerAddr, ULONG PeerAddrLen);
  WINSOCK_API_LINKAGE INT WSAAPI WSARevertImpersonation(void);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_PKG_APPRUNTIME) */

#endif  /* _SECURE_SOCKET_TYPES_DEFINED_ */

/* Those declarations are mandatory for Open Group Base spec */
#define IN6_IS_ADDR_UNSPECIFIED  IN6_IS_ADDR_UNSPECIFIED
#define IN6_IS_ADDR_LOOPBACK     IN6_IS_ADDR_LOOPBACK
#define IN6_IS_ADDR_MULTICAST    IN6_IS_ADDR_MULTICAST
#define IN6_IS_ADDR_LINKLOCAL    IN6_IS_ADDR_LINKLOCAL
#define IN6_IS_ADDR_SITELOCAL    IN6_IS_ADDR_SITELOCAL
#define IN6_IS_ADDR_V4MAPPED     IN6_IS_ADDR_V4MAPPED
#define IN6_IS_ADDR_V4COMPAT     IN6_IS_ADDR_V4COMPAT
#define IN6_IS_ADDR_MC_NODELOCAL IN6_IS_ADDR_MC_NODELOCAL
#define IN6_IS_ADDR_MC_LINKLOCAL IN6_IS_ADDR_MC_LINKLOCAL
#define IN6_IS_ADDR_MC_SITELOCAL IN6_IS_ADDR_MC_SITELOCAL
#define IN6_IS_ADDR_MC_ORGLOCAL  IN6_IS_ADDR_MC_ORGLOCAL
#define IN6_IS_ADDR_MC_GLOBAL    IN6_IS_ADDR_MC_GLOBAL

#ifdef __cplusplus
}
#endif

#endif  /* _WS2TCPIP_H_ */
