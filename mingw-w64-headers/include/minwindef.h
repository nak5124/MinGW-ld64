#ifndef _MINWINDEF_
#define _MINWINDEF_

#include <_mingw.h>
#include <specstrings.h>
#include <winapifamily.h>

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#if !defined(STRICT) && !defined(NO_STRICT)
# define STRICT 1
#endif

#ifndef WIN32
# define WIN32
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef BASETYPES
# define BASETYPES
  typedef unsigned long   ULONG;
  typedef ULONG          *PULONG;
  typedef unsigned short  USHORT;
  typedef USHORT         *PUSHORT;
  typedef unsigned char   UCHAR;
  typedef UCHAR          *PUCHAR;
  typedef char           *PSZ;
#endif

#define MAX_PATH 260

#ifndef NULL
# ifdef __cplusplus
#   define NULL 0LL
# else
#   define NULL ((void *)0)
# endif
#endif

#ifndef FALSE
# define FALSE 0
#endif

#ifndef TRUE
# define TRUE 1
#endif

#ifndef IN
# define IN
#endif

#ifndef OUT
# define OUT
#endif

#ifndef OPTIONAL
# define OPTIONAL
#endif

#undef far
#undef near
#undef pascal

#define far
#define near
#define pascal __stdcall

#define cdecl
#ifndef CDECL
# define CDECL
#endif

#define CALLBACK   __stdcall
#define WINAPI     __stdcall
#define WINAPIV    __cdecl
#define APIENTRY   WINAPI
#define APIPRIVATE __stdcall
#define PASCAL     __stdcall

#ifndef WINAPI_INLINE
# define WINAPI_INLINE WINAPI
#endif

#undef  FAR
#undef  NEAR
#define FAR
#define NEAR
#ifndef CONST
# define CONST const
#endif

#ifndef _DEF_WINBOOL_
# define _DEF_WINBOOL_
  typedef int WINBOOL;
# pragma push_macro("BOOL")
# undef BOOL
  typedef int BOOL;
# define BOOL WINBOOL
  typedef BOOL *PBOOL;
  typedef BOOL *LPBOOL;
# pragma pop_macro("BOOL")
#endif  /* _DEF_WINBOOL_ */

  typedef unsigned long  DWORD;
  typedef unsigned char  BYTE;
  typedef unsigned short WORD;
  typedef float          FLOAT;
  typedef FLOAT         *PFLOAT;
  typedef BYTE          *PBYTE;
  typedef BYTE          *LPBYTE;
  typedef int           *PINT;
  typedef int           *LPINT;
  typedef WORD          *PWORD;
  typedef WORD          *LPWORD;
  typedef long          *LPLONG;
  typedef DWORD         *PDWORD;
  typedef DWORD         *LPDWORD;
  typedef void          *LPVOID;
#ifndef _LPCVOID_DEFINED
# define _LPCVOID_DEFINED
  typedef CONST void *LPCVOID;
#endif

  typedef int           INT;
  typedef unsigned int  UINT;
  typedef unsigned int *PUINT;

#ifndef NT_INCLUDED
# include <winnt.h>
#endif

  typedef UINT_PTR WPARAM;
  typedef LONG_PTR LPARAM;
  typedef LONG_PTR LRESULT;

#ifndef __cplusplus
# ifndef NOMINMAX
#   ifndef max
#     define max(a, b) (((a) > (b)) ? (a) : (b))
#   endif
#   ifndef min
#     define min(a, b) (((a) < (b)) ? (a) : (b))
#   endif
# endif
#endif

#define MAKEWORD(a, b) ((WORD)(((BYTE)(((DWORD_PTR)(a)) & 0xff)) | ((WORD)((BYTE)(((DWORD_PTR)(b)) & 0xff))) << 8))
#define MAKELONG(a, b) ((LONG)(((WORD)(((DWORD_PTR)(a)) & 0xffff)) | ((DWORD)((WORD)(((DWORD_PTR)(b)) & 0xffff))) << 16))
#define LOWORD(l)      ((WORD)(((DWORD_PTR)(l)) & 0xffff))
#define HIWORD(l)      ((WORD)((((DWORD_PTR)(l)) >> 16) & 0xffff))
#define LOBYTE(w)      ((BYTE)(((DWORD_PTR)(w)) & 0xff))
#define HIBYTE(w)      ((BYTE)((((DWORD_PTR)(w)) >> 8) & 0xff))

  typedef HANDLE *SPHANDLE;
  typedef HANDLE *LPHANDLE;
  typedef HANDLE  HGLOBAL;
  typedef HANDLE  HLOCAL;
  typedef HANDLE  GLOBALHANDLE;
  typedef HANDLE  LOCALHANDLE;

  typedef INT_PTR (WINAPI *FARPROC)();
  typedef INT_PTR (WINAPI *NEARPROC)();
  typedef INT_PTR (WINAPI *PROC)();

  typedef WORD ATOM;

  DECLARE_HANDLE(HKEY);
  typedef HKEY *PHKEY;
  DECLARE_HANDLE(HMETAFILE);
  DECLARE_HANDLE(HINSTANCE);
  typedef HINSTANCE HMODULE;
  DECLARE_HANDLE(HRGN);
  DECLARE_HANDLE(HRSRC);
  DECLARE_HANDLE(HSPRITE);
  DECLARE_HANDLE(HLSURF);
  DECLARE_HANDLE(HSTR);
  DECLARE_HANDLE(HTASK);
  DECLARE_HANDLE(HWINSTA);
  DECLARE_HANDLE(HKL);
  typedef int HFILE;

  typedef struct _FILETIME
  {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
  } FILETIME, *PFILETIME, *LPFILETIME;
#define _FILETIME_

#ifdef __cplusplus
}
#endif

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#endif  /* _MINWINDEF_ */
