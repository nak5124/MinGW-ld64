#ifndef WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <ws2tcpip.h>

BOOLEAN IN6_IS_ADDR_V4COMPAT(CONST IN6_ADDR *a)
{
  return (BOOLEAN)((a->s6_words[0] == 0) &&
                  (a->s6_words[1] == 0) &&
                  (a->s6_words[2] == 0) &&
                  (a->s6_words[3] == 0) &&
                  (a->s6_words[4] == 0) &&
                  (a->s6_words[5] == 0) &&
                  !((a->s6_words[6] == 0) &&
                  (a->s6_addr[14] == 0) &&
                  ((a->s6_addr[15] == 0) ||
                  (a->s6_addr[15] == 1))));
}
