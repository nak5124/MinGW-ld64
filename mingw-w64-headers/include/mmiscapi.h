/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _MMISCAPI_H_
#define _MMISCAPI_H_

#include <_mingw_unicode.h>
#include <apiset.h>
#include <apisetcconv.h>

#include <mmsyscom.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#ifndef MMNODRV

  typedef struct DRVCONFIGINFOEX
  {
    DWORD   dwDCISize;
    LPCWSTR lpszDCISectionName;
    LPCWSTR lpszDCIAliasName;
    DWORD   dnDevNode;
  } DRVCONFIGINFOEX, *PDRVCONFIGINFOEX, *NPDRVCONFIGINFOEX, *LPDRVCONFIGINFOEX;

#ifndef DRV_LOAD

#define DRV_LOAD           0x0001
#define DRV_ENABLE         0x0002
#define DRV_OPEN           0x0003
#define DRV_CLOSE          0x0004
#define DRV_DISABLE        0x0005
#define DRV_FREE           0x0006
#define DRV_CONFIGURE      0x0007
#define DRV_QUERYCONFIGURE 0x0008
#define DRV_INSTALL        0x0009
#define DRV_REMOVE         0x000A
#define DRV_EXITSESSION    0x000B
#define DRV_POWER          0x000F
#define DRV_RESERVED       0x0800
#define DRV_USER           0x4000

  typedef struct tagDRVCONFIGINFO
  {
    DWORD   dwDCISize;
    LPCWSTR lpszDCISectionName;
    LPCWSTR lpszDCIAliasName;
  } DRVCONFIGINFO, *PDRVCONFIGINFO, *NPDRVCONFIGINFO, *LPDRVCONFIGINFO;

#define DRVCNF_CANCEL  0x0000
#define DRVCNF_OK      0x0001
#define DRVCNF_RESTART 0x0002

  typedef LRESULT (CALLBACK *DRIVERPROC)(DWORD_PTR, HDRVR, UINT, LPARAM, LPARAM);

  WINMMAPI LRESULT WINAPI CloseDriver(HDRVR hDriver, LPARAM lParam1, LPARAM lParam2);
  WINMMAPI HDRVR   WINAPI OpenDriver(LPCWSTR szDriverName, LPCWSTR szSectionName, LPARAM lParam2);
  WINMMAPI LRESULT WINAPI SendDriverMessage(HDRVR hDriver, UINT message, LPARAM lParam1, LPARAM lParam2);
  WINMMAPI HMODULE WINAPI DrvGetModuleHandle(HDRVR hDriver);
  WINMMAPI HMODULE WINAPI GetDriverModuleHandle(HDRVR hDriver);
  WINMMAPI LRESULT WINAPI DefDriverProc(DWORD_PTR dwDriverIdentifier, HDRVR hdrvr, UINT uMsg, LPARAM lParam1, LPARAM lParam2);

#endif  /* DRV_LOAD */

#define DRV_CANCEL  DRVCNF_CANCEL
#define DRV_OK      DRVCNF_OK
#define DRV_RESTART DRVCNF_RESTART

#define DRV_MCI_FIRST DRV_RESERVED
#define DRV_MCI_LAST  (DRV_RESERVED + 0xFFF)

  WINBOOL APIENTRY DriverCallback(DWORD_PTR dwCallback, DWORD dwFlags, HDRVR hDevice, DWORD dwMsg, DWORD_PTR dwUser, DWORD_PTR dwParam1, DWORD_PTR dwParam2);
  LONG    WINAPI   sndOpenSound(LPCWSTR EventName, LPCWSTR AppName, INT32 Flags, PHANDLE FileHandle);

  typedef DWORD (APIENTRY *DRIVERMSGPROC)(DWORD, DWORD, DWORD_PTR, DWORD_PTR, DWORD_PTR);

  UINT APIENTRY mmDrvInstall(HDRVR hDriver, LPCWSTR wszDrvEntry, DRIVERMSGPROC drvMessage, UINT wFlags);

#endif  /* MMNODRV */

#ifndef MMNOMMIO

#define MMIOERR_BASE             256
#define MMIOERR_FILENOTFOUND     (MMIOERR_BASE + 1)
#define MMIOERR_OUTOFMEMORY      (MMIOERR_BASE + 2)
#define MMIOERR_CANNOTOPEN       (MMIOERR_BASE + 3)
#define MMIOERR_CANNOTCLOSE      (MMIOERR_BASE + 4)
#define MMIOERR_CANNOTREAD       (MMIOERR_BASE + 5)
#define MMIOERR_CANNOTWRITE      (MMIOERR_BASE + 6)
#define MMIOERR_CANNOTSEEK       (MMIOERR_BASE + 7)
#define MMIOERR_CANNOTEXPAND     (MMIOERR_BASE + 8)
#define MMIOERR_CHUNKNOTFOUND    (MMIOERR_BASE + 9)
#define MMIOERR_UNBUFFERED       (MMIOERR_BASE + 10)
#define MMIOERR_PATHNOTFOUND     (MMIOERR_BASE + 11)
#define MMIOERR_ACCESSDENIED     (MMIOERR_BASE + 12)
#define MMIOERR_SHARINGVIOLATION (MMIOERR_BASE + 13)
#define MMIOERR_NETWORKERROR     (MMIOERR_BASE + 14)
#define MMIOERR_TOOMANYOPENFILES (MMIOERR_BASE + 15)
#define MMIOERR_INVALIDFILE      (MMIOERR_BASE + 16)

#define CFSEPCHAR '+'

  typedef DWORD FOURCC;
  typedef char  _huge *HPSTR;
  DECLARE_HANDLE(HMMIO);
  typedef LRESULT  (CALLBACK MMIOPROC)(LPSTR lpmmioinfo, UINT uMsg, LPARAM lParam1, LPARAM lParam2);
  typedef MMIOPROC *LPMMIOPROC;

  typedef struct _MMIOINFO
  {
    DWORD      dwFlags;
    FOURCC     fccIOProc;
    LPMMIOPROC pIOProc;
    UINT       wErrorRet;
    HTASK      htask;
    LONG       cchBuffer;
    HPSTR      pchBuffer;
    HPSTR      pchNext;
    HPSTR      pchEndRead;
    HPSTR      pchEndWrite;
    LONG       lBufOffset;
    LONG       lDiskOffset;
    DWORD      adwInfo[3];
    DWORD      dwReserved1;
    DWORD      dwReserved2;
    HMMIO      hmmio;
  } MMIOINFO, *PMMIOINFO, *NPMMIOINFO, *LPMMIOINFO;
  typedef const MMIOINFO *LPCMMIOINFO;

  typedef struct _MMCKINFO
  {
    FOURCC ckid;
    DWORD  cksize;
    FOURCC fccType;
    DWORD  dwDataOffset;
    DWORD  dwFlags;
  } MMCKINFO, *PMMCKINFO, *NPMMCKINFO, *LPMMCKINFO;
  typedef const MMCKINFO *LPCMMCKINFO;

#define MMIO_RWMODE      0x00000003
#define MMIO_SHAREMODE   0x00000070
#define MMIO_CREATE      0x00001000
#define MMIO_PARSE       0x00000100
#define MMIO_DELETE      0x00000200
#define MMIO_EXIST       0x00004000
#define MMIO_ALLOCBUF    0x00010000
#define MMIO_GETTEMP     0x00020000
#define MMIO_DIRTY       0x10000000
#define MMIO_READ        0x00000000
#define MMIO_WRITE       0x00000001
#define MMIO_READWRITE   0x00000002
#define MMIO_COMPAT      0x00000000
#define MMIO_EXCLUSIVE   0x00000010
#define MMIO_DENYWRITE   0x00000020
#define MMIO_DENYREAD    0x00000030
#define MMIO_DENYNONE    0x00000040
#define MMIO_FHOPEN      0x0010
#define MMIO_EMPTYBUF    0x0010
#define MMIO_TOUPPER     0x0010
#define MMIO_INSTALLPROC 0x00010000
#define MMIO_GLOBALPROC  0x10000000
#define MMIO_REMOVEPROC  0x00020000
#define MMIO_UNICODEPROC 0x01000000
#define MMIO_FINDPROC    0x00040000
#define MMIO_FINDCHUNK   0x0010
#define MMIO_FINDRIFF    0x0020
#define MMIO_FINDLIST    0x0040
#define MMIO_CREATERIFF  0x0020
#define MMIO_CREATELIST  0x0040

#define MMIOM_READ       MMIO_READ
#define MMIOM_WRITE      MMIO_WRITE
#define MMIOM_SEEK       2
#define MMIOM_OPEN       3
#define MMIOM_CLOSE      4
#define MMIOM_WRITEFLUSH 5
#define MMIOM_RENAME     6
#define MMIOM_USER       0x8000

#define FOURCC_RIFF mmioFOURCC('R', 'I', 'F', 'F')
#define FOURCC_LIST mmioFOURCC('L', 'I', 'S', 'T')

#define FOURCC_DOS mmioFOURCC('D', 'O', 'S', ' ')
#define FOURCC_MEM mmioFOURCC('M', 'E', 'M', ' ')

#ifndef SEEK_SET
# define SEEK_SET 0
# define SEEK_CUR 1
# define SEEK_END 2
#endif

#define MMIO_DEFAULTBUFFER 8192

#define mmioFOURCC(ch0, ch1, ch2, ch3) MAKEFOURCC(ch0, ch1, ch2, ch3)

  WINMMAPI FOURCC     WINAPI mmioStringToFOURCCA(LPCSTR sz, UINT uFlags);
  WINMMAPI FOURCC     WINAPI mmioStringToFOURCCW(LPCWSTR sz, UINT uFlags);
#define mmioStringToFOURCC __MINGW_NAME_AW(mmioStringToFOURCC)
  WINMMAPI LPMMIOPROC WINAPI mmioInstallIOProcA(FOURCC fccIOProc, LPMMIOPROC pIOProc, DWORD dwFlags);
  WINMMAPI LPMMIOPROC WINAPI mmioInstallIOProcW(FOURCC fccIOProc, LPMMIOPROC pIOProc, DWORD dwFlags);
#define mmioInstallIOProc __MINGW_NAME_AW(mmioInstallIOProc)
  WINMMAPI HMMIO      WINAPI mmioOpenA(LPSTR pszFileName, LPMMIOINFO pmmioinfo, DWORD fdwOpen);
  WINMMAPI HMMIO      WINAPI mmioOpenW(LPWSTR pszFileName, LPMMIOINFO pmmioinfo, DWORD fdwOpen);
#define mmioOpen __MINGW_NAME_AW(mmioOpen)
  WINMMAPI MMRESULT   WINAPI mmioRenameA(LPCSTR pszFileName, LPCSTR pszNewFileName, LPCMMIOINFO pmmioinfo, DWORD fdwRename);
  WINMMAPI MMRESULT   WINAPI mmioRenameW(LPCWSTR pszFileName, LPCWSTR pszNewFileName, LPCMMIOINFO pmmioinfo, DWORD fdwRename);
#define mmioRename __MINGW_NAME_AW(mmioRename)
  WINMMAPI MMRESULT   WINAPI mmioClose(HMMIO hmmio, UINT fuClose);
  WINMMAPI LONG       WINAPI mmioRead(HMMIO hmmio, HPSTR pch, LONG cch);
  WINMMAPI LONG       WINAPI mmioWrite(HMMIO hmmio, const char _huge *pch, LONG cch);
  WINMMAPI LONG       WINAPI mmioSeek(HMMIO hmmio, LONG lOffset, int iOrigin);
  WINMMAPI MMRESULT   WINAPI mmioGetInfo(HMMIO hmmio, LPMMIOINFO pmmioinfo, UINT fuInfo);
  WINMMAPI MMRESULT   WINAPI mmioSetInfo(HMMIO hmmio, LPCMMIOINFO pmmioinfo, UINT fuInfo);
  WINMMAPI MMRESULT   WINAPI mmioSetBuffer(HMMIO hmmio, LPSTR pchBuffer, LONG cchBuffer, UINT fuBuffer);
  WINMMAPI MMRESULT   WINAPI mmioFlush(HMMIO hmmio, UINT fuFlush);
  WINMMAPI MMRESULT   WINAPI mmioAdvance(HMMIO hmmio, LPMMIOINFO pmmioinfo, UINT fuAdvance);
  WINMMAPI LRESULT    WINAPI mmioSendMessage(HMMIO hmmio, UINT uMsg, LPARAM lParam1, LPARAM lParam2);
  WINMMAPI MMRESULT   WINAPI mmioDescend(HMMIO hmmio, LPMMCKINFO pmmcki, const MMCKINFO *pmmckiParent, UINT fuDescend);
  WINMMAPI MMRESULT   WINAPI mmioAscend(HMMIO hmmio, LPMMCKINFO pmmcki, UINT fuAscend);
  WINMMAPI MMRESULT   WINAPI mmioCreateChunk(HMMIO hmmio, LPMMCKINFO pmmcki, UINT fuCreate);

#endif  /* MMNOMMIO */

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */

#ifdef __cplusplus
}
#endif

#endif  /* _MMISCAPI_H_ */
