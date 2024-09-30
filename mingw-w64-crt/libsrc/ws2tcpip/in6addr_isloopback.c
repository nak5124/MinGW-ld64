#ifndef WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <ws2tcpip.h>

BOOLEAN IN6ADDR_ISLOOPBACK(CONST SOCKADDR_IN6 *a)
{
  return IN6_IS_ADDR_LOOPBACK(&a->sin6_addr);
}
