#ifndef WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <ws2tcpip.h>

BOOLEAN IN6_IS_ADDR_EUI64(CONST IN6_ADDR *a)
{
  return (BOOLEAN)(((a->s6_bytes[0] & 0xe0) != 0) && !IN6_IS_ADDR_MULTICAST(a));
}