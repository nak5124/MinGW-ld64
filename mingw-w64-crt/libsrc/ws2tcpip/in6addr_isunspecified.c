#ifndef WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <ws2tcpip.h>

BOOLEAN IN6ADDR_ISUNSPECIFIED(CONST SOCKADDR_IN6 *a)
{
  return (BOOLEAN)(a->sin6_scope_id == 0 && IN6_IS_ADDR_UNSPECIFIED(&a->sin6_addr));
}
