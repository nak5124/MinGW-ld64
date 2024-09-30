#ifndef WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <ws2tcpip.h>

BOOLEAN IN6_IS_ADDR_GLOBAL(CONST IN6_ADDR *a)
{
  ULONG High = (a->s6_bytes[0] & 0xf0u);
  return (BOOLEAN)((High != 0) && (High != 0xf0));
}
