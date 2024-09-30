/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef ___WSA_FD_TYPES_H
#define ___WSA_FD_TYPES_H

#include <psdk_inc/_socket_types.h>

#ifndef FD_SETSIZE
# define FD_SETSIZE 64
#endif

  typedef struct fd_set
  {
    u_int  fd_count;
    SOCKET fd_array[FD_SETSIZE];
  } fd_set;

#ifdef __cplusplus
extern "C" {
#endif

  extern int PASCAL __WSAFDIsSet(SOCKET fd, fd_set *);

#ifdef __cplusplus
}
#endif

#define FD_CLR(fd, set)                                                            \
  do                                                                               \
  {                                                                                \
    u_int __i;                                                                     \
    for(__i = 0; __i < ((fd_set *)(set))->fd_count; __i++)                         \
    {                                                                              \
      if(((fd_set *)(set))->fd_array[__i] == fd)                                   \
      {                                                                            \
        while(__i < ((fd_set *)(set))->fd_count - 1)                               \
        {                                                                          \
          ((fd_set *)(set))->fd_array[__i] = ((fd_set *)(set))->fd_array[__i + 1]; \
          __i++;                                                                   \
        }                                                                          \
        ((fd_set *)(set))->fd_count--;                                             \
        break;                                                                     \
      }                                                                            \
    }                                                                              \
  } while(0)

#ifdef _FD_SET_WINSOCK_DEFINED
# undef _FD_SET_WINSOCK_DEFINED
# undef FD_SET
#endif
#ifndef FD_SET
# ifdef _WINSOCK2API_
#   define FD_SET(fd, set)                                     \
      do                                                       \
      {                                                        \
        u_int __i;                                             \
        for(__i = 0; __i < ((fd_set *)(set))->fd_count; __i++) \
        {                                                      \
          if(((fd_set *)(set))->fd_array[__i] == (fd))         \
          {                                                    \
            break;                                             \
          }                                                    \
        }                                                      \
        if(__i == ((fd_set *)(set))->fd_count)                 \
        {                                                      \
          if(((fd_set *)(set))->fd_count < FD_SETSIZE)         \
          {                                                    \
            ((fd_set *)(set))->fd_array[__i] = (fd);           \
            ((fd_set *)(set))->fd_count++;                     \
          }                                                    \
        }                                                      \
      } while(0)
# else
#   define _FD_SET_WINSOCK_DEFINED
#   define FD_SET(fd, set)                                                   \
      do                                                                     \
      {                                                                      \
        if(((fd_set *)(set))->fd_count < FD_SETSIZE)                         \
          ((fd_set *)(set))->fd_array[((fd_set *)(set))->fd_count++] = (fd); \
      } while(0)
#endif  /* _WINSOCK2API_ */
#endif  /* FD_SET */

#define FD_ZERO(set) (((fd_set *)(set))->fd_count = 0)

#define FD_ISSET(fd, set) __WSAFDIsSet((SOCKET)(fd), (fd_set *)(set))

  typedef struct fd_set  FD_SET;
  typedef struct fd_set *PFD_SET;
  typedef struct fd_set *LPFD_SET;

#endif  /* ___WSA_FD_TYPES_H */
