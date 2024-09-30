#ifndef WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <ws2tcpip.h>

VOID IN6_SET_ADDR_UNSPECIFIED(PIN6_ADDR a)
{
	memset(a->s6_bytes, 0, sizeof(PIN6_ADDR));
}
