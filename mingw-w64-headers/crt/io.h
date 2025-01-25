/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_IO
#define _INC_IO

#include <corecrt.h>
#include <share.h>
#include <corecrt_wio.h>
#include <direct.h>
#include <sys/types.h>

__MINGW_BEGIN_C_DECLS

#define _finddata_t     _finddata64i32_t
#define _finddatai64_t __finddata64_t

  struct _finddata32_t
  {
    unsigned   attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t   size;
    char       name[260];
  };

  struct _finddata32i64_t
  {
    unsigned                  attrib;
    __time32_t                time_create;
    __time32_t                time_access;
    __time32_t                time_write;
    __MINGW_EXTENSION __int64 size;
    char                      name[260];
  };

  struct _finddata64i32_t
  {
    unsigned   attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t   size;
    char       name[260];
  };

  struct __finddata64_t
  {
    unsigned                  attrib;
    __time64_t                time_create;
    __time64_t                time_access;
    __time64_t                time_write;
    __MINGW_EXTENSION __int64 size;
    char                      name[260];
  };

#ifndef _A_NORMAL
# define _A_NORMAL 0x00
# define _A_RDONLY 0x01
# define _A_HIDDEN 0x02
# define _A_SYSTEM 0x04
# define _A_VOLID  0x08
# define _A_SUBDIR 0x10
# define _A_ARCH   0x20
#endif

#define _findfirst    _findfirst64i32
#define _findnext     _findnext64i32
#define _findfirsti64 _findfirst64
#define _findnexti64  _findnext64

  /* Some defines for _access nAccessMode (MS doesn't define them, but
   * it doesn't seem to hurt to add them). */
#define F_OK 0  /* Check for file existence */
#define X_OK 1  /* Check for execute permission. */
#define W_OK 2  /* Check for write permission */
#define R_OK 4  /* Check for read permission */

#ifndef _CHMOD_UMASK_DEFINED  /* Also in sys/stat.h */
# define _CHMOD_UMASK_DEFINED
  _CRTIMP int __cdecl _chmod(const char *_Filename, int _Mode) __NOTHROW __NONNULL((1));
  _CRTIMP int __cdecl _umask(int _Mode) __NOTHROW __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl  chmod(const char *_Filename, int _AccessMode) __NOTHROW __NONNULL((1)) __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP int __cdecl  umask(int _Mode) __NOTHROW __MINGW_DEPRECATED_MSVC2005 __MINGW_DEPRECATED_SEC_WARN;
#endif

  _CRTIMP int      __cdecl _access(const char *_Filename, int _AccessMode) __NOTHROW __NONNULL((1));
  _CRTIMP errno_t  __cdecl _access_s(const char *_Filename, int _AccessMode);
  _CRTIMP int      __cdecl _chsize(int _FileHandle, long _Size) __MINGW_DEPRECATED_SEC_WARN;
  __MINGW_EXTENSION
  _CRTIMP errno_t  __cdecl _chsize_s (int _FileHandle, __int64 _Size);
  _CRTIMP int      __cdecl _close(int _FileHandle);
  _CRTIMP int      __cdecl _commit(int _FileHandle);
  _CRTIMP int      __cdecl _creat(const char *_Filename, int _PermissionMode) __NONNULL((1)) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP int      __cdecl _dup(int _FileHandle) __NOTHROW __WUR_FORTIFY;
  _CRTIMP int      __cdecl _dup2(int _FileHandleSrc, int _FileHandleDst) __NOTHROW;
  _CRTIMP int      __cdecl _eof(int _FileHandle);
  _CRTIMP long     __cdecl _filelength(int _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(const char *_Filename, struct _finddata32_t *_FindData);
  _CRTIMP int      __cdecl _findnext32(intptr_t _FindHandle, struct _finddata32_t *_FindData);
  _CRTIMP int      __cdecl _findclose(intptr_t _FindHandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(int _FileHandle);
  _CRTIMP int      __cdecl _isatty(int _FileHandle) __NOTHROW;
  _CRTIMP int      __cdecl _locking(int _FileHandle, int _LockMode, long _NumOfBytes);
  _CRTIMP long     __cdecl _lseek(int _FileHandle, long _Offset, int _Origin) __NOTHROW;
  _CRTIMP char    *__cdecl _mktemp(char *_TemplateName) __NOTHROW __NONNULL((1)) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t  __cdecl _mktemp_s (char *_TemplateName, size_t _Size);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, _mktemp_s, char, _TemplateName)
  _CRTIMP int      __cdecl _open_osfhandle(intptr_t _OSFileHandle, int _Flags);
#ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP
  _CRTIMP int      __cdecl _pipe(int *_PtHandles, unsigned int _PipeSize, int _TextMode);
#endif  /* _CRT_USE_WINAPI_FAMILY_DESKTOP_APP */
  _CRTIMP int      __cdecl _read(int _FileHandle, void *_DstBuf, unsigned int _MaxCharCount) __WUR_FORTIFY __ATTR_ACCESS_FORTIFY(__write_only__, 2, 3);
#ifndef _CRT_DIRECTORY_DEFINED  /* Also in stdio.h */
# define _CRT_DIRECTORY_DEFINED
  _CRTIMP int __cdecl  remove(const char *_Filename) __NOTHROW;
  _CRTIMP int __cdecl  rename(const char *_OldFilename, const char *_NewFilename) __NOTHROW;
  _CRTIMP int __cdecl _unlink(const char *_Filename) __NOTHROW __NONNULL((1));
# ifdef __MINGW_USE_MS
  _CRTIMP int __cdecl  unlink(const char *_Filename) __NOTHROW __NONNULL((1)) __MINGW_DEPRECATED_MSVC2005;
# endif
#endif  /* _CRT_DIRECTORY_DEFINED */
  _CRTIMP int      __cdecl _setmode(int _FileHandle, int _Mode);
  _CRTIMP long     __cdecl _tell(int _FileHandle);
  _CRTIMP errno_t  __cdecl _umask_s(int _NewMode, int *_OldMode);
  _CRTIMP int      __cdecl _write(int _FileHandle, const void *_Buf, unsigned int _MaxCharCount) __WUR_FORTIFY __ATTR_ACCESS((__read_only__, 2, 3));
  __MINGW_EXTENSION
  _CRTIMP __int64  __cdecl _filelengthi64(int _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(const char *_Filename, struct _finddata32i64_t *_FindData);
  _CRTIMP intptr_t __cdecl _findfirst64i32(const char *_Filename, struct _finddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _findfirst64(const char *_Filename, struct __finddata64_t *_FindData);
  _CRTIMP int      __cdecl _findnext32i64(intptr_t _FindHandle, struct _finddata32i64_t *_FindData);
  _CRTIMP int      __cdecl _findnext64i32(intptr_t _FindHandle, struct _finddata64i32_t *_FindData);
  _CRTIMP int      __cdecl _findnext64(intptr_t _FindHandle, struct __finddata64_t *_FindData);
  __MINGW_EXTENSION
  _CRTIMP __int64  __cdecl _lseeki64(int _FileHandle, __int64 _Offset,int _Origin) __NOTHROW;
  __MINGW_EXTENSION
  _CRTIMP __int64  __cdecl _telli64(int _FileHandle);
  _CRTIMP int      __cdecl _open(const char *_Filename, int _OpenFlag, ...) __NONNULL((1)) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP int      __cdecl _sopen(const char *_Filename, int _OpenFlag, int _ShareFlag, ...) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t  __cdecl _sopen_s(int *_FileHandle, const char *_Filename, int _OpenFlag, int _ShareFlag, int _PermissionMode);
  _CRTIMP errno_t  __cdecl _sopen_s_nolock(int *_FileHandle, const char *_Filename, int _OpenFlag, int _ShareFlag, int _PermissionMode);
  _CRTIMP errno_t  __cdecl _sopen_dispatch(const char *_Filename, int _OpenFlag, int _ShareFlag, int _PMode, int *_PFileHandle, int _BSecure);

  extern  int   __cdecl access(const char *_Filename, int _AccessMode) __NOTHROW __NONNULL((1)) __MINGW_DEPRECATED_MSVC2005;
#ifdef __MINGW_USE_MS
  _CRTIMP int   __cdecl chsize(int _FileHandle, long _Size) __MINGW_DEPRECATED_MSVC2005;
#endif
  _CRTIMP int   __cdecl close(int _FileHandle) __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP int   __cdecl creat(const char *_Filename, int _PermissionMode) __NONNULL((1)) __MINGW_DEPRECATED_MSVC2005 __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP int   __cdecl dup(int _FileHandle)               __NOTHROW __WUR_FORTIFY __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP int   __cdecl dup2(int _FileHandleSrc, int _FileHandleDst) __WUR_FORTIFY __MINGW_DEPRECATED_MSVC2005;
#ifdef __MINGW_USE_MS
  _CRTIMP int   __cdecl eof(int _FileHandle) __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP long  __cdecl filelength(int _FileHandle) __MINGW_DEPRECATED_MSVC2005;
#endif
  _CRTIMP int   __cdecl isatty(int _FileHandle) __NOTHROW __MINGW_DEPRECATED_MSVC2005;
#ifdef __MINGW_USE_MS
  _CRTIMP int   __cdecl locking(int _FileHandle, int _LockMode, long _NumOfBytes) __MINGW_DEPRECATED_MSVC2005;
#endif
#ifndef __MINGW_USE_FOB64
  _CRTIMP long  __cdecl lseek(int _FileHandle, long _Offset, int _Origin) __NOTHROW __MINGW_DEPRECATED_MSVC2005;
#else
  _CRTIMP off_t __cdecl lseek(int _FileHandle, off_t _Offset, int _Origin) __ASM_CALL_NTH(lseek64) __MINGW_DEPRECATED_MSVC2005;
#endif
#if (defined(__MINGW_USE_XOPEN_EXT) && !defined(__MINGW_USE_XOPEN2K8)) || defined(__MINGW_USE_MISC) || defined(__MINGW_USE_MS)
  _CRTIMP char *__cdecl mktemp(char *_TemplateName) __NOTHROW __NONNULL((1)) __MINGW_DEPRECATED_MSVC2005 __MINGW_DEPRECATED_SEC_WARN;
#endif
#ifndef __MINGW_USE_FOB64
  _CRTIMP int   __cdecl open(const char *_Filename, int _OpenFlag, ...) __NONNULL((1)) __MINGW_DEPRECATED_MSVC2005 __MINGW_DEPRECATED_SEC_WARN;
#else
  _CRTIMP int   __cdecl open(const char *_Filename, int _OpenFlag, ...) __ASM_CALL(open64) __NONNULL((1)) __MINGW_DEPRECATED_MSVC2005 __MINGW_DEPRECATED_SEC_WARN;
#endif
  _CRTIMP int   __cdecl read(int _FileHandle, void *_DstBuf, unsigned int _MaxCharCount) __WUR_FORTIFY __ATTR_ACCESS_FORTIFY(__write_only__, 2, 3) __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP int   __cdecl setmode(int _FileHandle, int _Mode) __MINGW_DEPRECATED_MSVC2005;
#ifdef __MINGW_USE_MS
  _CRTIMP int   __cdecl sopen(const char *_Filename, int _OpenFlag, int _ShareFlag, ...) __MINGW_DEPRECATED_MSVC2005 __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP long  __cdecl tell(int _FileHandle) __MINGW_DEPRECATED_MSVC2005;
#endif
  _CRTIMP int   __cdecl write(int _Filehandle, const void *_Buf, unsigned int _MaxCharCount) __WUR_FORTIFY __ATTR_ACCESS((__read_only__, 2, 3)) __MINGW_DEPRECATED_MSVC2005;

#ifdef __MINGW_USE_LFS64
  int     __cdecl open64(const char *_Filename, int _OpenFlag, ...) __NONNULL((1));
  off64_t __cdecl lseek64(int __fd, off64_t __offset, int __whence) __NOTHROW;
#endif

#if defined(__MINGW_USE_POSIX) || defined(__MINGW_USE_XOPEN)
  extern char *__cdecl getlogin(void);
# ifdef __USE_MINGW_ALARM
    extern unsigned int __cdecl alarm(unsigned int __seconds) __NOTHROW;
# endif
#endif

__MINGW_END_C_DECLS

#include <ssp/io.h>

#endif  /* _INC_IO */
