#ifndef WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <ws2tcpip.h>

BOOLEAN IN6_IS_ADDR_SUBNET_RESERVED_ANYCAST(CONST IN6_ADDR *a)
{
  return (BOOLEAN)(IN6_IS_ADDR_EUI64(a) &&
                  (a->s6_words[4] == 0xfffd) &&
                  (a->s6_words[5] == 0xffff) &&
                  (a->s6_words[6] == 0xffff) &&
                  ((a->s6_words[7] & 0x80ff) == 0x80ff));
}
