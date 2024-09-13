/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _LZEXPAND_
#define _LZEXPAND_

#include <_mingw_unicode.h>
#include <winapifamily.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#define LZERROR_BADINHANDLE  (-1)
#define LZERROR_BADOUTHANDLE (-2)
#define LZERROR_READ         (-3)
#define LZERROR_WRITE        (-4)
#define LZERROR_GLOBALLOC    (-5)
#define LZERROR_GLOBLOCK     (-6)
#define LZERROR_BADVALUE     (-7)
#define LZERROR_UNKNOWNALG   (-8)

  INT  APIENTRY LZStart(VOID);
  VOID APIENTRY LZDone(VOID);
  LONG APIENTRY CopyLZFile(INT hfSource, INT hfDest);
  LONG APIENTRY LZCopy(INT hfSource, INT hfDest);
  INT  APIENTRY LZInit(INT hfSource);
  INT  APIENTRY GetExpandedNameA(LPSTR lpszSource, LPSTR lpszBuffer);
  INT  APIENTRY GetExpandedNameW(LPWSTR lpszSource, LPWSTR lpszBuffer);
#define GetExpandedName __MINGW_NAME_AW(GetExpandedName)
  INT  APIENTRY LZOpenFileA(LPSTR lpFileName, LPOFSTRUCT lpReOpenBuf, WORD wStyle);
  INT  APIENTRY LZOpenFileW(LPWSTR lpFileName, LPOFSTRUCT lpReOpenBuf, WORD wStyle);
#define LZOpenFile __MINGW_NAME_AW(LZOpenFile)
  LONG APIENTRY LZSeek(INT hFile, LONG lOffset, INT iOrigin);
  INT  APIENTRY LZRead(INT hFile, CHAR *lpBufferTR, INT cbRead);
  VOID APIENTRY LZClose(INT hFile);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */

#ifdef __cplusplus
}
#endif

#endif  /* _LZEXPAND_ */
