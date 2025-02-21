/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _ROERROR_H
#define _ROERROR_H

#include <apiset.h>
#include <apisetcconv.h>
#include <hstring.h>
#include <restrictederrorinfo.h>
#include <rpc.h>

#include <sdkddkver.h>

#define WINOLEGLOBAL EXTERN_C DECLSPEC_IMPORT

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

  typedef enum
  {
    RO_ERROR_REPORTING_NONE                 = 0x00000000,
    RO_ERROR_REPORTING_SUPPRESSEXCEPTIONS   = 0x00000001,
    RO_ERROR_REPORTING_FORCEEXCEPTIONS      = 0x00000002,
    RO_ERROR_REPORTING_USESETERRORINFO      = 0x00000004,
    RO_ERROR_REPORTING_SUPPRESSSETERRORINFO = 0x00000008
  } RO_ERROR_REPORTING_FLAGS;

  DEFINE_ENUM_FLAG_OPERATORS(RO_ERROR_REPORTING_FLAGS);

#define MAX_ERROR_MESSAGE_CHARS 512

  STDAPI RoGetErrorReportingFlags(UINT32 *pflags);
  STDAPI RoSetErrorReportingFlags(UINT32 flags);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  STDAPI RoResolveRestrictedErrorInfoReference(PCWSTR reference, IRestrictedErrorInfo **ppRestrictedErrorInfo);

  typedef HRESULT (WINAPI *PINSPECT_MEMORY_CALLBACK)(void *context, UINT_PTR readAddress, UINT32 length, BYTE *buffer);

  STDAPI           RoInspectThreadErrorInfo(UINT_PTR targetTebAddress, USHORT machine, PINSPECT_MEMORY_CALLBACK readMemoryCallback, PVOID context, UINT_PTR *targetErrorInfoAddress);
  STDAPI           RoInspectCapturedStackBackTrace(UINT_PTR targetErrorInfoAddress, USHORT machine, PINSPECT_MEMORY_CALLBACK readMemoryCallback, PVOID context, UINT32 *frameCount, UINT_PTR *targetBackTraceAddress);
  STDAPI           RoGetMatchingRestrictedErrorInfo(HRESULT hrIn, IRestrictedErrorInfo **ppRestrictedErrorInfo);
  STDAPI           RoReportFailedDelegate(IUnknown *punkDelegate, IRestrictedErrorInfo *pRestrictedErrorInfo);
  STDAPI_(WINBOOL) IsErrorPropagationEnabled(void);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

  STDAPI           SetRestrictedErrorInfo(IRestrictedErrorInfo *pRestrictedErrorInfo);
  STDAPI           GetRestrictedErrorInfo(IRestrictedErrorInfo **ppRestrictedErrorInfo);
  STDAPI_(WINBOOL) RoOriginateErrorW(HRESULT error, UINT cchMax, PCWSTR message);
  STDAPI_(WINBOOL) RoOriginateError(HRESULT error, HSTRING message);
  STDAPI_(WINBOOL) RoTransformErrorW(HRESULT oldError, HRESULT newError, UINT cchMax, PCWSTR message);
  STDAPI_(WINBOOL) RoTransformError(HRESULT oldError, HRESULT newError, HSTRING message);
  STDAPI           RoCaptureErrorContext(HRESULT hr);
  STDAPI_(void)    RoFailFastWithErrorContext(HRESULT hrError);

#ifdef __cplusplus
  namespace Windows
  {
    namespace Foundation
    {
      namespace Diagnostics
      {
        typedef enum
        {
          None                 = RO_ERROR_REPORTING_NONE,
          SuppressExceptions   = RO_ERROR_REPORTING_SUPPRESSEXCEPTIONS,
          ForceExceptions      = RO_ERROR_REPORTING_FORCEEXCEPTIONS,
          UseSetErrorInfo      = RO_ERROR_REPORTING_USESETERRORINFO,
          SuppressSetErrorInfo = RO_ERROR_REPORTING_SUPPRESSSETERRORINFO
        } RoErrorReportingFlags;

        DEFINE_ENUM_FLAG_OPERATORS(RoErrorReportingFlags);

        inline HRESULT GetErrorReportingFlags(UINT32 *pflags)
        {
          return ::RoGetErrorReportingFlags(pflags);
        }

        inline HRESULT SetErrorReportingFlags(UINT32 flags)
        {
          return ::RoSetErrorReportingFlags(flags);
        }

        inline WINBOOL OriginateError(HRESULT error, UINT cchMax, PCWSTR message)
        {
          if(SUCCEEDED(error))
          {
            return FALSE;
          }
          return ::RoOriginateErrorW(error, cchMax, message);
        }

        inline WINBOOL OriginateError(HRESULT error, HSTRING message)
        {
          if(SUCCEEDED(error))
          {
            return FALSE;
          }
          return ::RoOriginateError(error, message);
        }

        inline WINBOOL TransformError(HRESULT oldError, HRESULT newError, UINT cchMax, PCWSTR message)
        {
          if((oldError == newError) || (SUCCEEDED(oldError) && SUCCEEDED(newError)))
          {
            return FALSE;
          }
          return ::RoTransformErrorW(oldError, newError, cchMax, message);
        }

        inline WINBOOL TransformError(HRESULT oldError, HRESULT newError, HSTRING message)
        {
          if((oldError == newError) || (SUCCEEDED(oldError) && SUCCEEDED(newError)))
          {
            return FALSE;
          }
            return ::RoTransformError(oldError, newError, message);
        }
      }
    }
  }

  namespace ABI
  {
    namespace Windows
    {
      namespace Foundation
      {
        namespace Diagnostics
        {
          typedef enum
          {
            None                 = RO_ERROR_REPORTING_NONE,
            SuppressExceptions   = RO_ERROR_REPORTING_SUPPRESSEXCEPTIONS,
            ForceExceptions      = RO_ERROR_REPORTING_FORCEEXCEPTIONS,
            UseSetErrorInfo      = RO_ERROR_REPORTING_USESETERRORINFO,
            SuppressSetErrorInfo = RO_ERROR_REPORTING_SUPPRESSSETERRORINFO
          } RoErrorReportingFlags;

          DEFINE_ENUM_FLAG_OPERATORS(RoErrorReportingFlags);

          inline HRESULT GetErrorReportingFlags(UINT32 *pflags)
          {
            return ::RoGetErrorReportingFlags(pflags);
          }

          inline HRESULT SetErrorReportingFlags(UINT32 flags)
          {
            return ::RoSetErrorReportingFlags(flags);
          }

          inline WINBOOL OriginateError(HRESULT error, UINT cchMax, PCWSTR message)
          {
            return ::RoOriginateErrorW(error, cchMax, message);
          }

          inline WINBOOL OriginateError(HRESULT error, HSTRING message)
          {
            return ::RoOriginateError(error, message);
          }

          inline WINBOOL TransformError(HRESULT oldError, HRESULT newError, UINT cchMax, PCWSTR message)
          {
            return ::RoTransformErrorW(oldError, newError, cchMax, message);
          }

          inline WINBOOL TransformError(HRESULT oldError, HRESULT newError, HSTRING message)
          {
            return ::RoTransformError(oldError, newError, message);
          }
        }
      }
    }
  }

#endif  /* __cplusplus */

#define EXCEPTION_RO_ORIGINATEERROR ((DWORD)((0x1 << 30) | (FACILITY_WINDOWS << 16) | 0x201))
#define EXCEPTION_RO_TRANSFORMERROR ((DWORD)((0x1 << 30) | (FACILITY_WINDOWS << 16) | 0x202))

  STDAPI_(WINBOOL) RoOriginateLanguageException(HRESULT error, HSTRING message, IUnknown *languageException);
  STDAPI_(void)    RoClearError(void);
  STDAPI           RoReportUnhandledError(IRestrictedErrorInfo *pRestrictedErrorInfo);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */

#endif  /* _ROERROR_H */
