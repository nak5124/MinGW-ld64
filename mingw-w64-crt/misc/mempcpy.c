#define _GNU_SOURCE
#include <string.h>

void * __cdecl
mempcpy (void *d, const void *s, size_t len)
{
  char *r = ((char *) d) + len;
  if (len != 0)
    memcpy (d, s, len);
  return r;
}

