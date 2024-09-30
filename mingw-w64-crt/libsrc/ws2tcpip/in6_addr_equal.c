#ifndef WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <ws2tcpip.h>

BOOLEAN IN6_ADDR_EQUAL(CONST IN6_ADDR *x, CONST IN6_ADDR *y)
{
  __int64 *a;
  __int64 *b;

  a = (__int64 *)x;
  b = (__int64 *)y;

  return (BOOLEAN)((a[1] == b[1]) && (a[0] == b[0]));
}
