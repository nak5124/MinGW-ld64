#include <winapifamily.h>
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _WINDOWS_
#define _WINDOWS_

#include <_mingw.h>
#include <sdkddkver.h>

#ifndef _INC_WINDOWS
#define _INC_WINDOWS

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#if defined(RC_INVOKED) && !defined(NOWINRES)
#include <winresrc.h>
#else

#ifdef RC_INVOKED
# define NOATOM
# define NOGDI
# define NOGDICAPMASKS
# define NOMETAFILE
# define NOMINMAX
# define NOMSG
# define NOOPENFILE
# define NORASTEROPS
# define NOSCROLL
# define NOSOUND
# define NOSYSMETRICS
# define NOTEXTMETRIC
# define NOWH
# define NOCOMM
# define NOKANJI
# define NOCRYPT
# define NOMCX
#endif

#ifdef __x86_64__
# ifndef _AMD64_
#   define _AMD64_ 1
# endif
#endif

#ifdef __aarch64__
# ifndef _ARM64_
#   define _ARM64_ 1
# endif
#endif

#ifndef RC_INVOKED
# include <excpt.h>
# include <stdarg.h>
#endif

#include <windef.h>
#include <winbase.h>
#include <wingdi.h>
#include <winuser.h>
#include <winnls.h>
#include <wincon.h>
#include <winver.h>
#include <winreg.h>
#include <winnetwk.h>

#ifndef WIN32_LEAN_AND_MEAN
# include <cderr.h>
# include <dde.h>
# include <ddeml.h>
# include <dlgs.h>
# include <lzexpand.h>
# include <mmsystem.h>
# include <nb30.h>
# include <rpc.h>
# include <shellapi.h>
# include <winperf.h>
# include <winsock.h>
# ifndef NOCRYPT
#   include <wincrypt.h>
#   include <winefs.h>
#   include <winscard.h>
# endif
# ifndef NOGDI
#   include <winspool.h>
#   ifdef INC_OLE1
#     include <ole.h>
#   else
#     include <ole2.h>
#   endif
#   include <commdlg.h>
# endif
#endif  /* WIN32_LEAN_AND_MEAN */

#include <stralign.h>

#ifdef INC_OLE2
# include <ole2.h>
#endif

#ifndef NOSERVICE
# include <winsvc.h>
#endif

#ifndef NOMCX
# include <mcx.h>
#endif

#ifndef NOIME
# include <imm.h>
#endif

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#endif  /* defined(RC_INVOKED) && !defined(NOWINRES) */

#endif  /* _INC_WINDOWS */

#endif  /* _WINDOWS_ */
