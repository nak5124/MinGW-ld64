#ifndef WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <ws2tcpip.h>

BOOLEAN IN6_IS_ADDR_SITELOCAL(CONST IN6_ADDR *a)
{
  return (BOOLEAN)((a->s6_bytes[0] == 0xfe) && ((a->s6_bytes[1] & 0xc0) == 0xc0));
}
