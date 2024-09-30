/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef s6_addr

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  typedef struct in6_addr
  {
    union
    {
      UCHAR  Byte[16];
      USHORT Word[8];
    } u;
  } IN6_ADDR, *PIN6_ADDR, *LPIN6_ADDR;

#define in_addr6 in6_addr

#define _S6_un  u
#define _S6_u8  Byte
#define s6_addr _S6_un._S6_u8

#define s6_bytes u.Byte
#define s6_words u.Word

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#endif  /* s6_addr */
