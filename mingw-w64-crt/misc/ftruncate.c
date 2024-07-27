#include <io.h>

int ftruncate(int __fd, _off_t __length);

int ftruncate(int __fd, _off_t __length)
{
  return _chsize(__fd, __length);
}
