/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#if !defined(RPC_NO_WINDOWS_H) && !defined(_INC_WINDOWS)
# include <windows.h>
#endif

#ifndef __RPC_H__
#define __RPC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <basetsd.h>

#ifdef __aarch64__
# define __RPC_ARM64__
#else
# define __RPC_WIN64__
#endif

#include <pshpack8.h>

#ifndef __MIDL_USER_DEFINED
# define __MIDL_USER_DEFINED
# define midl_user_allocate MIDL_user_allocate
# define midl_user_free     MIDL_user_free
#endif

  typedef void *I_RPC_HANDLE;
  typedef long  RPC_STATUS;

#define RPC_UNICODE_SUPPORTED
#define __RPC_API  __stdcall
#define __RPC_USER __stdcall
#define __RPC_STUB __stdcall
#define RPC_ENTRY  __stdcall

#define __RPC_FAR

#ifndef DECLSPEC_IMPORT
# ifndef __WIDL__
#   define DECLSPEC_IMPORT __declspec(dllimport)
# else
#   define DECLSPEC_IMPORT
# endif
#endif

#define RPCRTAPI DECLSPEC_IMPORT

#define RPCNSAPI DECLSPEC_IMPORT

#include <rpcdce.h>
#include <rpcnsi.h>
#include <rpcnterr.h>
#include <excpt.h>
#include <winerror.h>

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)
/* TODO:  This isn't actual working on gcc.  Either we need to implement
 * their __try/__except/__finally feature, or we need to do at least for x64
 * emulation-code via inline-assembler ... */
#define RpcTryExcept    __try {
#define RpcExcept(expr) } __except(expr) {
#define RpcEndExcept    }
#define RpcTryFinally   __try {
#define RpcFinally      } __finally {
#define RpcEndFinally   }

#define RpcExceptionCode()       GetExceptionCode()
#define RpcAbnormalTermination() AbnormalTermination()

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#if !defined(RPC_NO_WINDOWS_H) || defined(RPC_NEED_RPCASYNC_H)
# include <rpcasync.h>
#endif

#include <poppack.h>

#ifdef __cplusplus
}
#endif

#endif  /* __RPC_H__ */
