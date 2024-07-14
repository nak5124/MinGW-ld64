/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_DIRECT
#define _INC_DIRECT

#include <corecrt.h>
#include <corecrt_wdirect.h>

#pragma pack(push, _CRT_PACKING)

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP

#ifndef _DISKFREE_T_DEFINED
# define _DISKFREE_T_DEFINED
  struct _diskfree_t
  {
    unsigned total_clusters;
    unsigned avail_clusters;
    unsigned sectors_per_cluster;
    unsigned bytes_per_sector;
  };
#endif

#ifndef _GETDISKFREE_DEFINED  /* Also in dos.h */
# define _GETDISKFREE_DEFINED
  _CRTIMP unsigned __cdecl _getdiskfree(unsigned _Drive, struct _diskfree_t *_DiskFree);
#endif  /* _GETDISKFREE_DEFINED */

  _CRTIMP int __cdecl _chdrive(int _Drive);
  _CRTIMP int __cdecl _getdrive(void);
  _CRTIMP unsigned long __cdecl _getdrives(void);

#endif  /* _CRT_USE_WINAPI_FAMILY_DESKTOP_APP */

#pragma push_macro("_getcwd")
#pragma push_macro("_getdcwd")
#undef _getcwd
#undef _getdcwd

  _CRTIMP char *__cdecl _getcwd(char *_DstBuf, int _SizeInBytes);
  _CRTIMP char *__cdecl _getdcwd(int _Drive, char *_DstBuf, int _SizeInBytes);

#define _getdcwd_nolock _getdcwd

#pragma pop_macro("_getcwd")
#pragma pop_macro("_getdcwd")

  _CRTIMP int __cdecl _chdir(const char *_Path);
  _CRTIMP int __cdecl _mkdir(const char *_Path);
  _CRTIMP int __cdecl _rmdir(const char *_Path);

#ifdef _CRT_USE_WINAPI_FAMILY_DESKTOP_APP

#pragma push_macro("getcwd")
#undef getcwd
  _CRTIMP char *__cdecl getcwd(char *_DstBuf, int _SizeInBytes) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
#pragma pop_macro("getcwd")
  _CRTIMP int __cdecl chdir(const char *_Path) __MINGW_ATTRIB_DEPRECATED_MSVC2005;

#ifndef diskfree_t
# define diskfree_t _diskfree_t
#endif

#endif  /* _CRT_USE_WINAPI_FAMILY_DESKTOP_APP */

  _CRTIMP int __cdecl mkdir(const char *_Path) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
  _CRTIMP int __cdecl rmdir(const char *_Path) __MINGW_ATTRIB_DEPRECATED_MSVC2005;

#ifdef __cplusplus
}
#endif

#pragma pack(pop)

#endif  /* _INC_DIRECT */
