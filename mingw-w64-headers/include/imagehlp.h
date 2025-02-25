/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _IMAGEHLP_
#define _IMAGEHLP_

#include <_mingw.h>
#include <dbghelp.h>

#ifndef WINTRUST_H
# include <wintrust.h>
#endif

#if WINAPI_FAMILY_PARTITION(NONGAMESPARTITIONS)

#ifdef __cplusplus
extern "C" {
#endif

  WINBOOL IMAGEAPI BindImage(PCSTR ImageName, PCSTR DllPath, PCSTR SymbolPath);

  typedef enum _IMAGEHLP_STATUS_REASON
  {
    BindOutOfMemory,
    BindRvaToVaFailed,
    BindNoRoomInImage,
    BindImportModuleFailed,
    BindImportProcedureFailed,
    BindImportModule,
    BindImportProcedure,
    BindForwarder,
    BindForwarderNOT,
    BindImageModified,
    BindExpandFileHeaders,
    BindImageComplete,
    BindMismatchedSymbols,
    BindSymbolsNotUpdated,
    BindImportProcedure32,
    BindImportProcedure64,
    BindForwarder32,
    BindForwarder64,
    BindForwarderNOT32,
    BindForwarderNOT64
  } IMAGEHLP_STATUS_REASON;

  typedef WINBOOL (__stdcall *PIMAGEHLP_STATUS_ROUTINE)  (IMAGEHLP_STATUS_REASON Reason, PCSTR ImageName, PCSTR DllName, ULONG_PTR Va, ULONG_PTR Parameter);
  typedef WINBOOL (__stdcall *PIMAGEHLP_STATUS_ROUTINE32)(IMAGEHLP_STATUS_REASON Reason, PCSTR ImageName, PCSTR DllName, ULONG Va, ULONG_PTR Parameter);
  typedef WINBOOL (__stdcall *PIMAGEHLP_STATUS_ROUTINE64)(IMAGEHLP_STATUS_REASON Reason, PCSTR ImageName, PCSTR DllName, ULONG64 Va, ULONG_PTR Parameter);

  WINBOOL IMAGEAPI BindImageEx(DWORD Flags, PCSTR ImageName, PCSTR DllPath, PCSTR SymbolPath, PIMAGEHLP_STATUS_ROUTINE StatusRoutine);

#define BIND_NO_BOUND_IMPORTS  0x00000001
#define BIND_NO_UPDATE         0x00000002
#define BIND_ALL_IMAGES        0x00000004
#define BIND_CACHE_IMPORT_DLLS 0x00000008
#define BIND_REPORT_64BIT_VA   0x00000010

  WINBOOL IMAGEAPI ReBaseImage(PCSTR CurrentImageName,PCSTR SymbolPath,WINBOOL fReBase,WINBOOL fRebaseSysfileOk, WINBOOL fGoingDown, ULONG CheckImageSize, ULONG *OldImageSize, ULONG_PTR *OldImageBase, ULONG *NewImageSize, ULONG_PTR *NewImageBase, ULONG TimeStamp);
  WINBOOL IMAGEAPI ReBaseImage64(PCSTR CurrentImageName, PCSTR SymbolPath, WINBOOL fReBase, WINBOOL fRebaseSysfileOk, WINBOOL  fGoingDown, ULONG CheckImageSize, ULONG *OldImageSize, ULONG64 *OldImageBase, ULONG *NewImageSize, ULONG64 *NewImageBase, ULONG TimeStamp);

#define CHECKSUM_SUCCESS         0
#define CHECKSUM_OPEN_FAILURE    1
#define CHECKSUM_MAP_FAILURE     2
#define CHECKSUM_MAPVIEW_FAILURE 3
#define CHECKSUM_UNICODE_FAILURE 4

#define SPLITSYM_REMOVE_PRIVATE    0x00000001
#define SPLITSYM_EXTRACT_ALL       0x00000002
#define SPLITSYM_SYMBOLPATH_IS_SRC 0x00000004

  PIMAGE_NT_HEADERS IMAGEAPI CheckSumMappedFile(PVOID BaseAddress, DWORD FileLength, PDWORD HeaderSum, PDWORD CheckSum);
  DWORD             IMAGEAPI MapFileAndCheckSumA(PCSTR Filename, PDWORD HeaderSum, PDWORD CheckSum);
  DWORD             IMAGEAPI MapFileAndCheckSumW(PCWSTR Filename, PDWORD HeaderSum, PDWORD CheckSum);
#define MapFileAndCheckSum __MINGW_NAME_AW(MapFileAndCheckSum)
  WINBOOL           IMAGEAPI GetImageConfigInformation(PLOADED_IMAGE LoadedImage, PIMAGE_LOAD_CONFIG_DIRECTORY ImageConfigInformation);
  DWORD             IMAGEAPI GetImageUnusedHeaderBytes(PLOADED_IMAGE LoadedImage, PDWORD SizeUnusedHeaderBytes);
  WINBOOL           IMAGEAPI SetImageConfigInformation(PLOADED_IMAGE LoadedImage, PIMAGE_LOAD_CONFIG_DIRECTORY ImageConfigInformation);

#define CERT_PE_IMAGE_DIGEST_DEBUG_INFO      0x01
#define CERT_PE_IMAGE_DIGEST_RESOURCES       0x02
#define CERT_PE_IMAGE_DIGEST_ALL_IMPORT_INFO 0x04
#define CERT_PE_IMAGE_DIGEST_NON_PE_INFO     0x08
#define CERT_SECTION_TYPE_ANY                0xFF

  typedef PVOID DIGEST_HANDLE;
  typedef WINBOOL (WINAPI *DIGEST_FUNCTION)(DIGEST_HANDLE refdata, PBYTE pData, DWORD dwLength);

  WINBOOL       IMAGEAPI ImageGetDigestStream(HANDLE FileHandle, DWORD DigestLevel, DIGEST_FUNCTION DigestFunction, DIGEST_HANDLE DigestHandle);
  WINBOOL       IMAGEAPI ImageAddCertificate(HANDLE FileHandle, LPWIN_CERTIFICATE Certificate, PDWORD Index);
  WINBOOL       IMAGEAPI ImageRemoveCertificate(HANDLE FileHandle, DWORD Index);
  WINBOOL       IMAGEAPI ImageEnumerateCertificates(HANDLE FileHandle, WORD TypeFilter, PDWORD CertificateCount, PDWORD Indices, DWORD IndexCount);
  WINBOOL       IMAGEAPI ImageGetCertificateData(HANDLE FileHandle, DWORD CertificateIndex, LPWIN_CERTIFICATE Certificate, PDWORD RequiredLength);
  WINBOOL       IMAGEAPI ImageGetCertificateHeader(HANDLE FileHandle, DWORD CertificateIndex, LPWIN_CERTIFICATE Certificateheader);
  PLOADED_IMAGE IMAGEAPI ImageLoad(PCSTR DllName, PCSTR DllPath);
  WINBOOL       IMAGEAPI ImageUnload(PLOADED_IMAGE LoadedImage);
  WINBOOL       IMAGEAPI MapAndLoad(PCSTR ImageName, PCSTR DllPath, PLOADED_IMAGE LoadedImage, WINBOOL DotDll, WINBOOL ReadOnly);
  WINBOOL       IMAGEAPI UnMapAndLoad(PLOADED_IMAGE LoadedImage);
  WINBOOL       IMAGEAPI TouchFileTimes(HANDLE FileHandle, PSYSTEMTIME pSystemTime);
  WINBOOL       IMAGEAPI SplitSymbols(PSTR ImageName, PCSTR SymbolsPath, PSTR SymbolFilePath, ULONG Flags);
  WINBOOL       IMAGEAPI UpdateDebugInfoFile(PCSTR ImageFileName, PCSTR SymbolPath, PSTR DebugFilePath, PIMAGE_NT_HEADERS32 NtHeaders);
  WINBOOL       IMAGEAPI UpdateDebugInfoFileEx(PCSTR ImageFileName, PCSTR SymbolPath, PSTR DebugFilePath, PIMAGE_NT_HEADERS32 NtHeaders, DWORD OldCheckSum);

#ifdef __cplusplus
}
#endif

#endif  /* WINAPI_FAMILY_PARTITION(NONGAMESPARTITIONS) */

#endif  /* _IMAGEHLP_ */
