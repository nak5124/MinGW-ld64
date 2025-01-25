/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CORECRT_WIO
#define _INC_CORECRT_WIO

#include <corecrt.h>
#include <share.h>

__MINGW_BEGIN_C_DECLS

#define _wfinddata_t    _wfinddata64i32_t
#define _wfinddatai64_t _wfinddata64_t

#ifndef _FSIZE_T_DEFINED
# define _FSIZE_T_DEFINED
  typedef unsigned long _fsize_t;
#endif

  struct _wfinddata32_t
  {
    unsigned   attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t   size;
    wchar_t    name[260];
  };

  struct _wfinddata32i64_t
  {
    unsigned                  attrib;
    __time32_t                time_create;
    __time32_t                time_access;
    __time32_t                time_write;
    __MINGW_EXTENSION __int64 size;
    wchar_t                   name[260];
  };

  struct _wfinddata64i32_t
  {
    unsigned   attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t   size;
    wchar_t    name[260];
  };

  struct _wfinddata64_t
  {
    unsigned                  attrib;
    __time64_t                time_create;
    __time64_t                time_access;
    __time64_t                time_write;
    __MINGW_EXTENSION __int64 size;
    wchar_t                   name[260];
  };

#define _wfindfirst    _wfindfirst64i32
#define _wfindnext     _wfindnext64i32
#define _wfindfirsti64 _wfindfirst64
#define _wfindnexti64  _wfindnext64

  _CRTIMP int      __cdecl _waccess(const wchar_t *_Filename, int _AccessMode) __NOTHROW __NONNULL((1));
  _CRTIMP errno_t  __cdecl _waccess_s(const wchar_t *_Filename, int _AccessMode);
  _CRTIMP int      __cdecl _wchmod(const wchar_t *_Filename, int _Mode) __NOTHROW __NONNULL((1));
  _CRTIMP int      __cdecl _wcreat(const wchar_t *_Filename, int _PermissionMode) __NONNULL((1)) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP intptr_t __cdecl _wfindfirst32(const wchar_t *_Filename, struct _wfinddata32_t *_FindData);
  _CRTIMP int      __cdecl _wfindnext32(intptr_t _FindHandle, struct _wfinddata32_t *_FindData);
  _CRTIMP int      __cdecl _wunlink(const wchar_t *_Filename) __NOTHROW __NONNULL((1));
  _CRTIMP int      __cdecl _wrename(const wchar_t *_OldFilename, const wchar_t *_NewFilename) __NOTHROW;
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName) __NOTHROW __NONNULL((1)) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t  __cdecl _wmktemp_s(wchar_t *_TemplateName, size_t _SizeInWords);
  __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(errno_t, _wmktemp_s, wchar_t, _TemplateName)
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(const wchar_t *_Filename, struct _wfinddata32i64_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64i32(const wchar_t *_Filename, struct _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(const wchar_t *_Filename, struct _wfinddata64_t *_FindData);
  _CRTIMP int      __cdecl _wfindnext32i64(intptr_t _FindHandle, struct _wfinddata32i64_t *_FindData);
  _CRTIMP int      __cdecl _wfindnext64i32(intptr_t _FindHandle, struct _wfinddata64i32_t *_FindData);
  _CRTIMP int      __cdecl _wfindnext64(intptr_t _FindHandle, struct _wfinddata64_t *_FindData);
  _CRTIMP int      __cdecl _wopen(const wchar_t *_Filename, int _OpenFlag, ...) __NONNULL((1)) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP int      __cdecl _wsopen(const wchar_t *_Filename, int _OpenFlag, int _ShareFlag, ...) __MINGW_DEPRECATED_SEC_WARN;
  _CRTIMP errno_t  __cdecl _wsopen_s(int *_FileHandle, const wchar_t *_Filename, int _OpenFlag, int _ShareFlag, int _PermissionFlag);
  _CRTIMP errno_t  __cdecl _wsopen_dispatch(const wchar_t *_FileName, int _OFlag, int _ShFlag, int _PMode, int *_PFileHandle, int _BSecure);

__MINGW_END_C_DECLS

#include <ssp/wio.h>

#endif  /* _INC_CORECRT_WIO */
