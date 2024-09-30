#ifndef WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <ws2tcpip.h>

BOOLEAN IN6ADDR_ISEQUAL(CONST SOCKADDR_IN6 *a, CONST SOCKADDR_IN6 *b)
{
  return (BOOLEAN)(a->sin6_scope_id == b->sin6_scope_id && IN6_ADDR_EQUAL(&a->sin6_addr, &b->sin6_addr));
}
