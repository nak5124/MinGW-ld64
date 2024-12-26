/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _IFMIB_
#define _IFMIB_

#include <winapifamily.h>

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#include <ifdef.h>

#ifndef ANY_SIZE
# define ANY_SIZE 1
#endif

  typedef struct _MIB_IFNUMBER
  {
    DWORD dwValue;
  } MIB_IFNUMBER, *PMIB_IFNUMBER;

#define MAXLEN_PHYSADDR        8
#define MAXLEN_IFDESCR         256
#define MAX_INTERFACE_NAME_LEN 256

  typedef struct _MIB_IFROW
  {
    WCHAR                   wszName[MAX_INTERFACE_NAME_LEN];
    IF_INDEX                dwIndex;
    IFTYPE                  dwType;
    DWORD                   dwMtu;
    DWORD                   dwSpeed;
    DWORD                   dwPhysAddrLen;
    UCHAR                   bPhysAddr[MAXLEN_PHYSADDR];
    DWORD                   dwAdminStatus;
    INTERNAL_IF_OPER_STATUS dwOperStatus;
    DWORD                   dwLastChange;
    DWORD                   dwInOctets;
    DWORD                   dwInUcastPkts;
    DWORD                   dwInNUcastPkts;
    DWORD                   dwInDiscards;
    DWORD                   dwInErrors;
    DWORD                   dwInUnknownProtos;
    DWORD                   dwOutOctets;
    DWORD                   dwOutUcastPkts;
    DWORD                   dwOutNUcastPkts;
    DWORD                   dwOutDiscards;
    DWORD                   dwOutErrors;
    DWORD                   dwOutQLen;
    DWORD                   dwDescrLen;
    UCHAR                   bDescr[MAXLEN_IFDESCR];
  } MIB_IFROW, *PMIB_IFROW;

  typedef struct _MIB_IFTABLE
  {
    DWORD     dwNumEntries;
    MIB_IFROW table[ANY_SIZE];
  } MIB_IFTABLE, *PMIB_IFTABLE;

#define SIZEOF_IFTABLE(X) (FIELD_OFFSET(MIB_IFTABLE, table[0]) + ((X) * sizeof(MIB_IFROW)) + ALIGN_SIZE)

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#endif  /* _IFMIB_ */
