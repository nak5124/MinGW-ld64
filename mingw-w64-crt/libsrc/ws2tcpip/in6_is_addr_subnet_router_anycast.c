#ifndef WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <ws2tcpip.h>

BOOLEAN IN6_IS_ADDR_SUBNET_ROUTER_ANYCAST(CONST IN6_ADDR *a)
{
  return (BOOLEAN)(IN6_IS_ADDR_EUI64(a) &&
                  (a->s6_words[4] == 0) &&
                  (a->s6_words[5] == 0) &&
                  (a->s6_words[6] == 0) &&
                  (a->s6_words[7] == 0));
}
