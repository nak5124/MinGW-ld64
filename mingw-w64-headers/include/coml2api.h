/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _COML2API_H_
#define _COML2API_H_

#include <apiset.h>
#include <apisetcconv.h>

#include <combaseapi.h>
#include <objidl.h>
/* #include <propidlbase.h> */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_GAMES)

#define CWCSTORAGENAME 32

#define STGM_DIRECT           0x00000000L
#define STGM_TRANSACTED       0x00010000L
#define STGM_SIMPLE           0x08000000L
#define STGM_READ             0x00000000L
#define STGM_WRITE            0x00000001L
#define STGM_READWRITE        0x00000002L
#define STGM_SHARE_DENY_NONE  0x00000040L
#define STGM_SHARE_DENY_READ  0x00000030L
#define STGM_SHARE_DENY_WRITE 0x00000020L
#define STGM_SHARE_EXCLUSIVE  0x00000010L
#define STGM_PRIORITY         0x00040000L
#define STGM_DELETEONRELEASE  0x04000000L
#define STGM_NOSCRATCH        0x00100000L
#define STGM_CREATE           0x00001000L
#define STGM_CONVERT          0x00020000L
#define STGM_FAILIFTHERE      0x00000000L
#define STGM_NOSNAPSHOT       0x00200000L
#define STGM_DIRECT_SWMR      0x00400000L

  typedef DWORD STGFMT;

#define STGFMT_STORAGE 0
#define STGFMT_NATIVE  1
#define STGFMT_FILE    3
#define STGFMT_ANY     4
#define STGFMT_DOCFILE 5

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_GAMES) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)

#define STGFMT_DOCUMENT 0

  WINOLEAPI StgCreateDocfile(const WCHAR *pwcsName, DWORD grfMode, DWORD reserved, IStorage **ppstgOpen);
  WINOLEAPI StgCreateDocfileOnILockBytes(ILockBytes *plkbyt, DWORD grfMode, DWORD reserved, IStorage **ppstgOpen);
  WINOLEAPI StgOpenStorage(const WCHAR *pwcsName, IStorage *pstgPriority, DWORD grfMode, SNB snbExclude, DWORD reserved, IStorage **ppstgOpen);
  WINOLEAPI StgOpenStorageOnILockBytes(ILockBytes *plkbyt, IStorage *pstgPriority, DWORD grfMode, SNB snbExclude, DWORD reserved, IStorage **ppstgOpen);
  WINOLEAPI StgIsStorageFile(const WCHAR *pwcsName);
  WINOLEAPI StgIsStorageILockBytes(ILockBytes *plkbyt);
  WINOLEAPI StgSetTimes(const WCHAR *lpszName, const FILETIME *pctime, const FILETIME *patime, const FILETIME *pmtime);

#define STGOPTIONS_VERSION 2

  typedef struct tagSTGOPTIONS
  {
    USHORT       usVersion;
    USHORT       reserved;
    ULONG        ulSectorSize;
    const WCHAR *pwcsTemplateFile;
  } STGOPTIONS;

  WINOLEAPI StgCreateStorageEx(const WCHAR *pwcsName, DWORD grfMode, DWORD stgfmt, DWORD grfAttrs, STGOPTIONS *pStgOptions, PSECURITY_DESCRIPTOR pSecurityDescriptor, REFIID riid, void **ppObjectOpen);
  WINOLEAPI StgOpenStorageEx(const WCHAR *pwcsName, DWORD grfMode, DWORD stgfmt, DWORD grfAttrs, STGOPTIONS *pStgOptions, PSECURITY_DESCRIPTOR pSecurityDescriptor, REFIID riid, void **ppObjectOpen);

#ifndef _STGCREATEPROPSTG_DEFINED_

  WINOLEAPI StgCreatePropStg(IUnknown *pUnk, REFFMTID fmtid, const CLSID *pclsid, DWORD grfFlags, DWORD dwReserved, IPropertyStorage **ppPropStg);
  WINOLEAPI StgOpenPropStg(IUnknown *pUnk, REFFMTID fmtid, DWORD grfFlags, DWORD dwReserved, IPropertyStorage **ppPropStg);
  WINOLEAPI StgCreatePropSetStg(IStorage *pStorage, DWORD dwReserved, IPropertySetStorage **ppPropSetStg);

#define CCH_MAX_PROPSTG_NAME 31

  WINOLEAPI FmtIdToPropStgName(const FMTID *pfmtid, LPOLESTR oszName);
  WINOLEAPI PropStgNameToFmtId(const LPOLESTR oszName, FMTID *pfmtid);

#endif  /* _STGCREATEPROPSTG_DEFINED_ */

  WINOLEAPI ReadClassStg(LPSTORAGE pStg, CLSID *pclsid);
  WINOLEAPI WriteClassStg(LPSTORAGE pStg, REFCLSID rclsid);
  WINOLEAPI ReadClassStm(LPSTREAM pStm, CLSID *pclsid);
  WINOLEAPI WriteClassStm(LPSTREAM pStm, REFCLSID rclsid);
  WINOLEAPI GetHGlobalFromILockBytes(LPLOCKBYTES plkbyt, HGLOBAL *phglobal);
  WINOLEAPI CreateILockBytesOnHGlobal(HGLOBAL hGlobal, WINBOOL fDeleteOnRelease, LPLOCKBYTES *pplkbyt);
  WINOLEAPI GetConvertStg(LPSTORAGE pStg);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */

#endif  /* _COML2API_H_ */
