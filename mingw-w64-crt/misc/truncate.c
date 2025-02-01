#include <fcntl.h>
#include <errno.h>

int __cdecl truncate(const char *__file, _off_t __length);
int __cdecl ftruncate(int __fd, _off_t __length);

int __cdecl truncate(const char *__file, _off_t __length)
{
  int ret, fd;
  errno_t err = _sopen_s(&fd, __file, _O_BINARY | _O_RDWR, _SH_DENYNO, 0);
  if(fd == -1)
  {
    /* errno is set by _sopen_s */
    return -1;
  }
  ret = ftruncate(fd, __length);
  err = errno;
  if(_close(fd) == -1)
  {
    /* errno is set by _close: EBADF */
    return -1;
  }
  errno = err;
  return ret;
}
