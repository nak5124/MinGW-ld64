/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_STAT
#define _INC_STAT

#ifndef _WIN32
# error Only Win32 target is supported!
#endif

#include <corecrt.h>
#include <sys/types.h>

__MINGW_BEGIN_C_DECLS

  struct _stat32
  {
    _dev_t         st_dev;
    _ino_t         st_ino;
    unsigned short st_mode;
    short          st_nlink;
    short          st_uid;
    short          st_gid;
    _dev_t         st_rdev;
    _off_t         st_size;
    __time32_t     st_atime;
    __time32_t     st_mtime;
    __time32_t     st_ctime;
  };

  struct _stat32i64
  {
    _dev_t                    st_dev;
    _ino_t                    st_ino;
    unsigned short            st_mode;
    short                     st_nlink;
    short                     st_uid;
    short                     st_gid;
    _dev_t                    st_rdev;
    __MINGW_EXTENSION __int64 st_size;
    __time32_t                st_atime;
    __time32_t                st_mtime;
    __time32_t                st_ctime;
  };

  struct _stat64i32
  {
    _dev_t         st_dev;
    _ino_t         st_ino;
    unsigned short st_mode;
    short          st_nlink;
    short          st_uid;
    short          st_gid;
    _dev_t         st_rdev;
    _off_t         st_size;
    __time64_t     st_atime;
    __time64_t     st_mtime;
    __time64_t     st_ctime;
  };

  struct _stat64
  {
    _dev_t                    st_dev;
    _ino_t                    st_ino;
    unsigned short            st_mode;
    short                     st_nlink;
    short                     st_uid;
    short                     st_gid;
    _dev_t                    st_rdev;
    __MINGW_EXTENSION __int64 st_size;
    __time64_t                st_atime;
    __time64_t                st_mtime;
    __time64_t                st_ctime;
  };

#define __stat64 _stat64

  struct stat
  {
    _dev_t         st_dev;
    _ino_t         st_ino;
    unsigned short st_mode;
    short          st_nlink;
    short          st_uid;
    short          st_gid;
    _dev_t         st_rdev;
    off_t          st_size;
    time_t         st_atime;
    time_t         st_mtime;
    time_t         st_ctime;
  };

#ifdef __MINGW_USE_LFS64
  struct stat64
  {
    _dev_t         st_dev;
    _ino_t         st_ino;
    unsigned short st_mode;
    short          st_nlink;
    short          st_uid;
    short          st_gid;
    _dev_t         st_rdev;
    off64_t        st_size;
    __time64_t     st_atime;
    __time64_t     st_mtime;
    __time64_t     st_ctime;
  };
#endif

#define _S_IFMT   0xF000
#define _S_IFDIR  0x4000
#define _S_IFCHR  0x2000
#define _S_IFIFO  0x1000
#define _S_IFREG  0x8000
#define _S_IREAD  0x0100
#define _S_IWRITE 0x0080
#define _S_IEXEC  0x0040

#define S_IFMT   _S_IFMT
#define S_IFDIR  _S_IFDIR
#define S_IFCHR  _S_IFCHR
#define S_IFREG  _S_IFREG
#define S_IREAD  _S_IREAD
#define S_IWRITE _S_IWRITE
#define S_IEXEC  _S_IEXEC

#define _fstat    _fstat64i32
#define _fstati64 _fstat64
#define _stat     _stat64i32
#define _stati64  _stat64
#define _wstat    _wstat64i32
#define _wstati64 _wstat64

  _CRTIMP int __cdecl _fstat32(int _FileDes, struct _stat32 *_Stat)       __MINGW_NONNULL((2));
  _CRTIMP int __cdecl _fstat32i64(int _FileDes, struct _stat32i64 *_Stat) __MINGW_NONNULL((2));
  _CRTIMP int __cdecl _fstat64i32(int _FileDes, struct _stat64i32 *_Stat) __MINGW_NONNULL((2));
  _CRTIMP int __cdecl _fstat64(int _FileDes, struct _stat64 *_Stat)       __MINGW_NONNULL((2));
  _CRTIMP int __cdecl _stat32(const char *_Name, struct _stat32 *_Stat)       __MINGW_NONNULL((1, 2));
  _CRTIMP int __cdecl _stat32i64(const char *_Name, struct _stat32i64 *_Stat) __MINGW_NONNULL((1, 2));
  _CRTIMP int __cdecl _stat64i32(const char *_Name, struct _stat64i32 *_Stat) __MINGW_NONNULL((1, 2));
  _CRTIMP int __cdecl _stat64(const char *_Name, struct _stat64 *_Stat)       __MINGW_NONNULL((1, 2));
  _CRTIMP int __cdecl _wstat32(const wchar_t *_Name, struct _stat32 *_Stat)       __MINGW_NONNULL((1, 2));
  _CRTIMP int __cdecl _wstat32i64(const wchar_t *_Name, struct _stat32i64 *_Stat) __MINGW_NONNULL((1, 2));
  _CRTIMP int __cdecl _wstat64i32(const wchar_t *_Name, struct _stat64i32 *_Stat) __MINGW_NONNULL((1, 2));
  _CRTIMP int __cdecl _wstat64(const wchar_t *_Name, struct _stat64 *_Stat)       __MINGW_NONNULL((1, 2));

#ifndef __MINGW_USE_FOB64
  int __cdecl fstat(int _Desc, struct stat *_Stat)                __MINGW_NONNULL((2));
  int __cdecl stat(const char *_Filename, struct stat *_Stat)     __MINGW_NONNULL((1, 2));
  int __cdecl wstat(const wchar_t *_Filename, struct stat *_Stat) __MINGW_NONNULL((1, 2));
#else
  int __cdecl fstat(int _Desc, struct stat *_Stat)                __MINGW_ASM_CALL(fstat64) __MINGW_NONNULL((2));
  int __cdecl stat(const char *_Filename, struct stat *_Stat)     __MINGW_ASM_CALL(stat64)  __MINGW_NONNULL((1, 2));
  int __cdecl wstat(const wchar_t *_Filename, struct stat *_Stat) __MINGW_ASM_CALL(wstat64) __MINGW_NONNULL((1, 2));
#endif

#ifdef __MINGW_USE_LFS64
  int __cdecl fstat64(int _FileDes, struct stat64 *_Stat)         __MINGW_NONNULL((2));
  int __cdecl stat64(const char *_Name, struct stat64 *_Stat)     __MINGW_NONNULL((1, 2));
  int __cdecl wstat64(const wchar_t *_Name, struct stat64 *_Stat) __MINGW_NONNULL((1, 2));
#endif

#define _S_IFBLK 0x3000

#define S_IFIFO  _S_IFIFO
#define S_IFBLK  _S_IFBLK

#define _S_IRWXU (_S_IREAD | _S_IWRITE | _S_IEXEC)
#define _S_IXUSR _S_IEXEC
#define _S_IWUSR _S_IWRITE
#define _S_IRUSR _S_IREAD

#define S_IRWXU  _S_IRWXU
#define S_IXUSR  _S_IXUSR
#define S_IWUSR  _S_IWUSR
#define S_IRUSR  _S_IRUSR

#define S_IRGRP  (S_IRUSR >> 3)
#define S_IWGRP  (S_IWUSR >> 3)
#define S_IXGRP  (S_IXUSR >> 3)
#define S_IRWXG  (S_IRWXU >> 3)

#define S_IROTH  (S_IRGRP >> 3)
#define S_IWOTH  (S_IWGRP >> 3)
#define S_IXOTH  (S_IXGRP >> 3)
#define S_IRWXO  (S_IRWXG >> 3)

#define S_ISDIR(m)  (((m) & S_IFMT) == S_IFDIR)
#define S_ISFIFO(m) (((m) & S_IFMT) == S_IFIFO)
#define S_ISCHR(m)  (((m) & S_IFMT) == S_IFCHR)
#define S_ISBLK(m)  (((m) & S_IFMT) == S_IFBLK)
#define S_ISREG(m)  (((m) & S_IFMT) == S_IFREG)

#ifndef _CHMOD_UMASK_DEFINED  /* Also in io.h */
# define _CHMOD_UMASK_DEFINED
  _CRTIMP int __cdecl _chmod(const char *_Filename, int _Mode) __MINGW_NONNULL((1));
  _CRTIMP int __cdecl _umask(int _Mode) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP int __cdecl  chmod(const char *_Filename, int _AccessMode) __MINGW_NONNULL((1)) __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP int __cdecl  umask(int _Mode) __MINGW_DEPRECATED_MSVC2005 __MINGW_DEPRECATED_SEC_WARN;
#endif

#ifndef _MKDIR_DEFINED  /* Also in direct.h */
# define _MKDIR_DEFINED
  _CRTIMP int __cdecl _mkdir(const char *_Path) __MINGW_NONNULL((1));
  _CRTIMP int __cdecl  mkdir(const char *_Path) __MINGW_NONNULL((1)) __MINGW_DEPRECATED_MSVC2005;
#endif

__MINGW_END_C_DECLS

#endif  /* _INC_STAT */
