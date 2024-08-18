/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _FILEAPIFROMAPP_H_
#define _FILEAPIFROMAPP_H_

#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>
#include <minwinbase.h>
#include <fileapi.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)

#ifndef WIN_NOEXCEPT
# ifdef __cplusplus
#   define WIN_NOEXCEPT noexcept
# else
#   define WIN_NOEXCEPT
# endif
#endif

  WINSTORAGEAPI WINBOOL WINAPI CopyFileFromAppW(LPCWSTR lpExistingFileName, LPCWSTR lpNewFileName, WINBOOL bFailIfExists) WIN_NOEXCEPT;
  WINSTORAGEAPI WINBOOL WINAPI CreateDirectoryFromAppW(LPCWSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes) WIN_NOEXCEPT;
  WINSTORAGEAPI HANDLE  WINAPI CreateFileFromAppW(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile) WIN_NOEXCEPT;
  WINSTORAGEAPI HANDLE  WINAPI CreateFile2FromAppW(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, DWORD dwCreationDisposition, LPCREATEFILE2_EXTENDED_PARAMETERS pCreateExParams) WIN_NOEXCEPT;
  WINSTORAGEAPI WINBOOL WINAPI DeleteFileFromAppW(LPCWSTR lpFileName) WIN_NOEXCEPT;
  WINSTORAGEAPI HANDLE  WINAPI FindFirstFileExFromAppW(LPCWSTR lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, LPVOID lpFindFileData, FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter, DWORD dwAdditionalFlags) WIN_NOEXCEPT;
  WINSTORAGEAPI WINBOOL WINAPI GetFileAttributesExFromAppW(LPCWSTR lpFileName, GET_FILEEX_INFO_LEVELS fInfoLevelId, LPVOID lpFileInformation) WIN_NOEXCEPT;
  WINSTORAGEAPI WINBOOL WINAPI MoveFileFromAppW(LPCWSTR lpExistingFileName, LPCWSTR lpNewFileName) WIN_NOEXCEPT;
  WINSTORAGEAPI WINBOOL WINAPI RemoveDirectoryFromAppW(LPCWSTR lpPathName) WIN_NOEXCEPT;
  WINSTORAGEAPI WINBOOL WINAPI ReplaceFileFromAppW(LPCWSTR lpReplacedFileName, LPCWSTR lpReplacementFileName, LPCWSTR lpBackupFileName, DWORD dwReplaceFlags, LPVOID lpExclude, LPVOID lpReserved) WIN_NOEXCEPT;
  WINSTORAGEAPI WINBOOL WINAPI SetFileAttributesFromAppW(LPCWSTR lpFileName, DWORD dwFileAttributes) WINSTORAGEAPI;

#endif/* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) */

#ifdef __cplusplus
} // extern "C"
#endif

#endif  /* _FILEAPIFROMAPP_H_ */
