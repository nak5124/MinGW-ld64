/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _APISETFILE_
#define _APISETFILE_

#include <_mingw_unicode.h>
#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>
#include <minwinbase.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#define CREATE_NEW        1
#define CREATE_ALWAYS     2
#define OPEN_EXISTING     3
#define OPEN_ALWAYS       4
#define TRUNCATE_EXISTING 5

#define INVALID_FILE_SIZE        ((DWORD)0xFFFFFFFF)
#define INVALID_SET_FILE_POINTER ((DWORD)-1)
#define INVALID_FILE_ATTRIBUTES  ((DWORD)-1)

  WINBASEAPI LONG    WINAPI CompareFileTime(CONST FILETIME *lpFileTime1, CONST FILETIME *lpFileTime2);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryA(LPCSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryW(LPCWSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
#define CreateDirectory __MINGW_NAME_AW(CreateDirectory)
  WINBASEAPI WINBOOL WINAPI DeleteFileA(LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI DeleteFileW(LPCWSTR lpFileName);
#define DeleteFile __MINGW_NAME_AW(DeleteFile)
  WINBASEAPI WINBOOL WINAPI FileTimeToLocalFileTime(CONST FILETIME *lpFileTime, LPFILETIME lpLocalFileTime);
  WINBASEAPI WINBOOL WINAPI FindClose(HANDLE hFindFile);
  WINBASEAPI HANDLE  WINAPI FindFirstFileA(LPCSTR lpFileName, LPWIN32_FIND_DATAA lpFindFileData);
  WINBASEAPI HANDLE  WINAPI FindFirstFileW(LPCWSTR lpFileName, LPWIN32_FIND_DATAW lpFindFileData);
#define FindFirstFile __MINGW_NAME_AW(FindFirstFile)
  WINBASEAPI HANDLE  WINAPI FindFirstFileExA(LPCSTR lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, LPVOID lpFindFileData, FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter, DWORD dwAdditionalFlags);
  WINBASEAPI HANDLE  WINAPI FindFirstFileExW(LPCWSTR lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, LPVOID lpFindFileData, FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter, DWORD dwAdditionalFlags);
#define FindFirstFileEx __MINGW_NAME_AW(FindFirstFileEx)
  WINBASEAPI WINBOOL WINAPI FindNextFileA(HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData);
  WINBASEAPI WINBOOL WINAPI FindNextFileW(HANDLE hFindFile, LPWIN32_FIND_DATAW lpFindFileData);
#define FindNextFile __MINGW_NAME_AW(FindNextFile)
  WINBASEAPI WINBOOL WINAPI FlushFileBuffers(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceA(LPCSTR lpRootPathName, LPDWORD lpSectorsPerCluster, LPDWORD lpBytesPerSector, LPDWORD lpNumberOfFreeClusters, LPDWORD lpTotalNumberOfClusters);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceW(LPCWSTR lpRootPathName, LPDWORD lpSectorsPerCluster, LPDWORD lpBytesPerSector, LPDWORD lpNumberOfFreeClusters, LPDWORD lpTotalNumberOfClusters);
#define GetDiskFreeSpace __MINGW_NAME_AW(GetDiskFreeSpace)
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExA(LPCSTR lpDirectoryName, PULARGE_INTEGER lpFreeBytesAvailableToCaller, PULARGE_INTEGER lpTotalNumberOfBytes, PULARGE_INTEGER lpTotalNumberOfFreeBytes);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExW(LPCWSTR lpDirectoryName, PULARGE_INTEGER lpFreeBytesAvailableToCaller, PULARGE_INTEGER lpTotalNumberOfBytes, PULARGE_INTEGER lpTotalNumberOfFreeBytes);
#define GetDiskFreeSpaceEx __MINGW_NAME_AW(GetDiskFreeSpaceEx)
  WINBASEAPI UINT    WINAPI GetDriveTypeA(LPCSTR lpRootPathName);
  WINBASEAPI UINT    WINAPI GetDriveTypeW(LPCWSTR lpRootPathName);
#define GetDriveType __MINGW_NAME_AW(GetDriveType)

  typedef struct _WIN32_FILE_ATTRIBUTE_DATA
  {
    DWORD    dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD    nFileSizeHigh;
    DWORD    nFileSizeLow;
  } WIN32_FILE_ATTRIBUTE_DATA, *LPWIN32_FILE_ATTRIBUTE_DATA;

  WINBASEAPI DWORD   WINAPI GetFileAttributesA(LPCSTR lpFileName);
  WINBASEAPI DWORD   WINAPI GetFileAttributesW(LPCWSTR lpFileName);
#define GetFileAttributes __MINGW_NAME_AW(GetFileAttributes)
  WINBASEAPI WINBOOL WINAPI GetFileAttributesExA(LPCSTR lpFileName, GET_FILEEX_INFO_LEVELS fInfoLevelId, LPVOID lpFileInformation);
  WINBASEAPI WINBOOL WINAPI GetFileAttributesExW(LPCWSTR lpFileName, GET_FILEEX_INFO_LEVELS fInfoLevelId, LPVOID lpFileInformation);
#define GetFileAttributesEx __MINGW_NAME_AW(GetFileAttributesEx)

  typedef struct _BY_HANDLE_FILE_INFORMATION
  {
    DWORD    dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD    dwVolumeSerialNumber;
    DWORD    nFileSizeHigh;
    DWORD    nFileSizeLow;
    DWORD    nNumberOfLinks;
    DWORD    nFileIndexHigh;
    DWORD    nFileIndexLow;
  } BY_HANDLE_FILE_INFORMATION, *PBY_HANDLE_FILE_INFORMATION, *LPBY_HANDLE_FILE_INFORMATION;

  WINBASEAPI WINBOOL WINAPI GetFileInformationByHandle(HANDLE hFile, LPBY_HANDLE_FILE_INFORMATION lpFileInformation);
  WINBASEAPI WINBOOL WINAPI GetFileSizeEx(HANDLE hFile, PLARGE_INTEGER lpFileSize);
  WINBASEAPI DWORD   WINAPI GetFileType(HANDLE hFile);
  WINBASEAPI DWORD   WINAPI GetFinalPathNameByHandleA(HANDLE hFile, LPSTR lpszFilePath, DWORD cchFilePath, DWORD dwFlags);
  WINBASEAPI DWORD   WINAPI GetFinalPathNameByHandleW(HANDLE hFile, LPWSTR lpszFilePath, DWORD cchFilePath, DWORD dwFlags);
#define GetFinalPathNameByHandle __MINGW_NAME_AW(GetFinalPathNameByHandle)
  WINBASEAPI WINBOOL WINAPI GetFileTime(HANDLE hFile, LPFILETIME lpCreationTime, LPFILETIME lpLastAccessTime, LPFILETIME lpLastWriteTime);
  WINBASEAPI DWORD   WINAPI GetFullPathNameA(LPCSTR lpFileName, DWORD nBufferLength, LPSTR lpBuffer, LPSTR *lpFilePart);
  WINBASEAPI DWORD   WINAPI GetFullPathNameW(LPCWSTR lpFileName, DWORD nBufferLength, LPWSTR lpBuffer, LPWSTR *lpFilePart);
#define GetFullPathName __MINGW_NAME_AW(GetFullPathName)
  WINBASEAPI DWORD   WINAPI GetLogicalDrives(VOID);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationByHandleW(HANDLE hFile, LPWSTR lpVolumeNameBuffer, DWORD nVolumeNameSize, LPDWORD lpVolumeSerialNumber, LPDWORD lpMaximumComponentLength, LPDWORD lpFileSystemFlags, LPWSTR lpFileSystemNameBuffer, DWORD nFileSystemNameSize);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationA(LPCSTR lpRootPathName, LPSTR lpVolumeNameBuffer, DWORD nVolumeNameSize, LPDWORD lpVolumeSerialNumber, LPDWORD lpMaximumComponentLength, LPDWORD lpFileSystemFlags, LPSTR lpFileSystemNameBuffer, DWORD nFileSystemNameSize);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationW(LPCWSTR lpRootPathName, LPWSTR lpVolumeNameBuffer, DWORD nVolumeNameSize, LPDWORD lpVolumeSerialNumber, LPDWORD lpMaximumComponentLength, LPDWORD lpFileSystemFlags, LPWSTR lpFileSystemNameBuffer, DWORD nFileSystemNameSize);
#define GetVolumeInformation __MINGW_NAME_AW(GetVolumeInformation)
  WINBASEAPI WINBOOL WINAPI GetVolumePathNameW(LPCWSTR lpszFileName, LPWSTR lpszVolumePathName, DWORD cchBufferLength);
#ifdef UNICODE
# define GetVolumePathName GetVolumePathNameW
#endif
  WINBASEAPI WINBOOL WINAPI LocalFileTimeToFileTime(CONST FILETIME *lpLocalFileTime, LPFILETIME lpFileTime);
  WINBASEAPI WINBOOL WINAPI LockFile(HANDLE hFile, DWORD dwFileOffsetLow, DWORD dwFileOffsetHigh, DWORD nNumberOfBytesToLockLow, DWORD nNumberOfBytesToLockHigh);
  WINBASEAPI WINBOOL WINAPI LockFileEx(HANDLE hFile, DWORD dwFlags, DWORD dwReserved, DWORD nNumberOfBytesToLockLow, DWORD nNumberOfBytesToLockHigh, LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI ReadFileEx(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPOVERLAPPED lpOverlapped, LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI ReadFileScatter(HANDLE hFile, FILE_SEGMENT_ELEMENT aSegmentArray[], DWORD nNumberOfBytesToRead, LPDWORD lpReserved, LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryA(LPCSTR lpPathName);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryW(LPCWSTR lpPathName);
#define RemoveDirectory __MINGW_NAME_AW(RemoveDirectory)
  WINBASEAPI WINBOOL WINAPI SetEndOfFile(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI SetFileAttributesA(LPCSTR lpFileName, DWORD dwFileAttributes);
  WINBASEAPI WINBOOL WINAPI SetFileAttributesW(LPCWSTR lpFileName, DWORD dwFileAttributes);
#define SetFileAttributes __MINGW_NAME_AW(SetFileAttributes)
  WINBASEAPI WINBOOL WINAPI SetFileInformationByHandle(HANDLE hFile, FILE_INFO_BY_HANDLE_CLASS FileInformationClass, LPVOID lpFileInformation, DWORD dwBufferSize);
  WINBASEAPI DWORD   WINAPI SetFilePointer(HANDLE hFile, LONG lDistanceToMove, PLONG lpDistanceToMoveHigh, DWORD dwMoveMethod);
  WINBASEAPI WINBOOL WINAPI SetFilePointerEx(HANDLE hFile, LARGE_INTEGER liDistanceToMove, PLARGE_INTEGER lpNewFilePointer, DWORD dwMoveMethod);
  WINBASEAPI WINBOOL WINAPI SetFileTime(HANDLE hFile, CONST FILETIME *lpCreationTime, CONST FILETIME *lpLastAccessTime, CONST FILETIME *lpLastWriteTime);
  WINBASEAPI WINBOOL WINAPI SetFileValidData(HANDLE hFile, LONGLONG ValidDataLength);
  WINBASEAPI WINBOOL WINAPI UnlockFile(HANDLE hFile, DWORD dwFileOffsetLow, DWORD dwFileOffsetHigh, DWORD nNumberOfBytesToUnlockLow, DWORD nNumberOfBytesToUnlockHigh);
  WINBASEAPI WINBOOL WINAPI UnlockFileEx(HANDLE hFile, DWORD dwReserved, DWORD nNumberOfBytesToUnlockLow, DWORD nNumberOfBytesToUnlockHigh, LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI WriteFile(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI WriteFileEx(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPOVERLAPPED lpOverlapped, LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI WriteFileGather(HANDLE hFile, FILE_SEGMENT_ELEMENT aSegmentArray[], DWORD nNumberOfBytesToWrite, LPDWORD lpReserved, LPOVERLAPPED lpOverlapped);
  WINBASEAPI DWORD   WINAPI GetTempPathA(DWORD nBufferLength, LPSTR lpBuffer);
  WINBASEAPI DWORD   WINAPI GetTempPathW(DWORD nBufferLength, LPWSTR lpBuffer);
#define GetTempPath __MINGW_NAME_AW(GetTempPath)

  typedef struct _CREATEFILE2_EXTENDED_PARAMETERS
  {
    DWORD                 dwSize;
    DWORD                 dwFileAttributes;
    DWORD                 dwFileFlags;
    DWORD                 dwSecurityQosFlags;
    LPSECURITY_ATTRIBUTES lpSecurityAttributes;
    HANDLE                hTemplateFile;
  } CREATEFILE2_EXTENDED_PARAMETERS, *PCREATEFILE2_EXTENDED_PARAMETERS, *LPCREATEFILE2_EXTENDED_PARAMETERS;

  WINBASEAPI HANDLE WINAPI CreateFile2(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, DWORD dwCreationDisposition, LPCREATEFILE2_EXTENDED_PARAMETERS pCreateExParams);
  WINBASEAPI DWORD  WINAPI GetTempPath2A(DWORD BufferLength, LPSTR Buffer);
  WINBASEAPI DWORD  WINAPI GetTempPath2W(DWORD BufferLength, LPWSTR Buffer);
#define GetTempPath2 __MINGW_NAME_AW(GetTempPath2)

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  WINBASEAPI HANDLE  WINAPI CreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);
  WINBASEAPI WINBOOL WINAPI AreFileApisANSI(VOID);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) || defined(WINSTORECOMPAT)

  WINBASEAPI HANDLE WINAPI CreateFileW(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);
#define CreateFile __MINGW_NAME_AW(CreateFile)
  WINBASEAPI DWORD  WINAPI GetFileSize(HANDLE hFile, LPDWORD lpFileSizeHigh);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) || defined(WINSTORECOMPAT) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  WINBASEAPI WINBOOL WINAPI DefineDosDeviceW(DWORD dwFlags, LPCWSTR lpDeviceName, LPCWSTR lpTargetPath);
#ifdef UNICODE
# define DefineDosDevice DefineDosDeviceW
#endif
  WINBASEAPI DWORD   WINAPI GetLogicalDriveStringsW(DWORD nBufferLength, LPWSTR lpBuffer);
#ifdef UNICODE
# define GetLogicalDriveStrings GetLogicalDriveStringsW
#endif
  WINBASEAPI WINBOOL WINAPI AreShortNamesEnabled(HANDLE Handle, WINBOOL *Enabled);
  WINBASEAPI DWORD   WINAPI GetShortPathNameW(LPCWSTR lpszLongPath, LPWSTR lpszShortPath, DWORD cchBuffer);
#ifdef UNICODE
# define GetShortPathName GetShortPathNameW
#endif
  WINBASEAPI DWORD   WINAPI QueryDosDeviceW(LPCWSTR lpDeviceName, LPWSTR lpTargetPath, DWORD ucchMax);
#ifdef UNICODE
# define QueryDosDevice QueryDosDeviceW
#endif
  WINBASEAPI WINBOOL WINAPI GetVolumePathNamesForVolumeNameW(LPCWSTR lpszVolumeName, LPWCH lpszVolumePathNames, DWORD cchBufferLength, PDWORD lpcchReturnLength);
#ifdef UNICODE
# define GetVolumePathNamesForVolumeName GetVolumePathNamesForVolumeNameW
#endif
  WINBASEAPI WINBOOL WINAPI SetFileIoOverlappedRange(HANDLE FileHandle, PUCHAR OverlappedRangeStart, ULONG Length);
  WINBASEAPI DWORD   WINAPI GetCompressedFileSizeA(LPCSTR lpFileName, LPDWORD lpFileSizeHigh);
  WINBASEAPI DWORD   WINAPI GetCompressedFileSizeW(LPCWSTR lpFileName, LPDWORD lpFileSizeHigh);
#define GetCompressedFileSize __MINGW_NAME_AW(GetCompressedFileSize)

  typedef enum _STREAM_INFO_LEVELS
  {
    FindStreamInfoStandard,
    FindStreamInfoMaxInfoLevel
  } STREAM_INFO_LEVELS;

  typedef struct _WIN32_FIND_STREAM_DATA
  {
    LARGE_INTEGER StreamSize;
    WCHAR         cStreamName[MAX_PATH + 36];
  } WIN32_FIND_STREAM_DATA, *PWIN32_FIND_STREAM_DATA;

  WINBASEAPI HANDLE  WINAPI   FindFirstStreamW(LPCWSTR lpFileName, STREAM_INFO_LEVELS InfoLevel, LPVOID lpFindStreamData, DWORD dwFlags);
  WINBASEAPI WINBOOL APIENTRY FindNextStreamW(HANDLE hFindStream, LPVOID lpFindStreamData);
  WINBASEAPI HANDLE  WINAPI   FindFirstFileNameW(LPCWSTR lpFileName, DWORD dwFlags, LPDWORD StringLength, PWSTR LinkName);
  WINBASEAPI WINBOOL APIENTRY FindNextFileNameW(HANDLE hFindStream, LPDWORD StringLength, PWSTR LinkName);
  WINBASEAPI VOID    WINAPI   SetFileApisToOEM(VOID);
  WINBASEAPI VOID    WINAPI   SetFileApisToANSI(VOID);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

  WINBASEAPI WINBOOL WINAPI DeleteVolumeMountPointW(LPCWSTR lpszVolumeMountPoint);
#ifdef UNICODE
# define DeleteVolumeMountPoint DeleteVolumeMountPointW
#endif
  WINBASEAPI WINBOOL WINAPI FindCloseChangeNotification(HANDLE hChangeHandle);
  WINBASEAPI HANDLE  WINAPI FindFirstChangeNotificationA(LPCSTR lpPathName, WINBOOL bWatchSubtree, DWORD dwNotifyFilter);
  WINBASEAPI HANDLE  WINAPI FindFirstChangeNotificationW(LPCWSTR lpPathName, WINBOOL bWatchSubtree, DWORD dwNotifyFilter);
#define FindFirstChangeNotification __MINGW_NAME_AW(FindFirstChangeNotification)
  WINBASEAPI HANDLE  WINAPI FindFirstVolumeW(LPWSTR lpszVolumeName, DWORD cchBufferLength);
#ifdef UNICODE
# define FindFirstVolume FindFirstVolumeW
#endif
  WINBASEAPI WINBOOL WINAPI FindNextChangeNotification(HANDLE hChangeHandle);
  WINBASEAPI WINBOOL WINAPI FindNextVolumeW(HANDLE hFindVolume, LPWSTR lpszVolumeName, DWORD cchBufferLength);
#ifdef UNICODE
# define FindNextVolume FindNextVolumeW
#endif
  WINBASEAPI WINBOOL WINAPI FindVolumeClose(HANDLE hFindVolume);

  typedef struct DISK_SPACE_INFORMATION
  {
    ULONGLONG ActualTotalAllocationUnits;
    ULONGLONG ActualAvailableAllocationUnits;
    ULONGLONG ActualPoolUnavailableAllocationUnits;
    ULONGLONG CallerTotalAllocationUnits;
    ULONGLONG CallerAvailableAllocationUnits;
    ULONGLONG CallerPoolUnavailableAllocationUnits;
    ULONGLONG UsedAllocationUnits;
    ULONGLONG TotalReservedAllocationUnits;
    ULONGLONG VolumeStorageReserveAllocationUnits;
    ULONGLONG AvailableCommittedAllocationUnits;
    ULONGLONG PoolAvailableAllocationUnits;
    DWORD     SectorsPerAllocationUnit;
    DWORD     BytesPerSector;
  } DISK_SPACE_INFORMATION;

  WINBASEAPI HRESULT WINAPI GetDiskSpaceInformationA(LPCSTR rootPath, DISK_SPACE_INFORMATION *diskSpaceInfo);
  WINBASEAPI HRESULT WINAPI GetDiskSpaceInformationW(LPCWSTR rootPath, DISK_SPACE_INFORMATION *diskSpaceInfo);
#define GetDiskSpaceInformation __MINGW_NAME_AW(GetDiskSpaceInformation)
  WINBASEAPI DWORD   WINAPI GetLongPathNameA(LPCSTR lpszShortPath, LPSTR lpszLongPath, DWORD cchBuffer);
  WINBASEAPI DWORD   WINAPI GetLongPathNameW(LPCWSTR lpszShortPath, LPWSTR lpszLongPath, DWORD cchBuffer);
#define GetLongPathName __MINGW_NAME_AW(GetLongPathName)
  WINBASEAPI UINT    WINAPI GetTempFileNameA(LPCSTR lpPathName, LPCSTR lpPrefixString, UINT uUnique, LPSTR lpTempFileName);
  WINBASEAPI UINT    WINAPI GetTempFileNameW(LPCWSTR lpPathName, LPCWSTR lpPrefixString, UINT uUnique, LPWSTR lpTempFileName);
#define GetTempFileName __MINGW_NAME_AW(GetTempFileName)
  WINBASEAPI WINBOOL WINAPI GetVolumeNameForVolumeMountPointW(LPCWSTR lpszVolumeMountPoint, LPWSTR lpszVolumeName, DWORD cchBufferLength);
#ifdef UNICODE
# define GetVolumeNameForVolumeMountPoint GetVolumeNameForVolumeMountPointW
#endif

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */

#ifdef __cplusplus
}
#endif

#endif  /* _APISETFILE_ */
