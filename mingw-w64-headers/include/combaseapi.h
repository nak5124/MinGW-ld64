/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#include <apiset.h>
#include <apisetcconv.h>

#include <rpc.h>
#include <rpcndr.h>

#ifndef _WIN32_WINNT
# define _WIN32_WINNT 0x0A00
#endif

#ifndef _COMBASEAPI_H_
#define _COMBASEAPI_H_

#include <pshpack8.h>

#define WINOLEAPI        EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE
#define WINOLEAPI_(type) EXTERN_C DECLSPEC_IMPORT type    STDAPICALLTYPE

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#if defined(__cplusplus) && !defined(CINTERFACE)

#ifdef COM_STDMETHOD_CAN_THROW
# define COM_DECLSPEC_NOTHROW
#else
# define COM_DECLSPEC_NOTHROW DECLSPEC_NOTHROW
#endif

#define __STRUCT__ struct
#undef  interface
#define interface __STRUCT__
#define STDMETHOD(method)                virtual COM_DECLSPEC_NOTHROW                         HRESULT STDMETHODCALLTYPE  method
#define STDMETHOD_CHPE_PATCHABLE(method) virtual COM_DECLSPEC_NOTHROW DECLSPEC_CHPE_PATCHABLE HRESULT STDMETHODCALLTYPE  method
#define STDMETHOD_(type, method)         virtual COM_DECLSPEC_NOTHROW                         type    STDMETHODCALLTYPE  method
#define STDMETHODV(method)               virtual COM_DECLSPEC_NOTHROW                         HRESULT STDMETHODVCALLTYPE method
#define STDMETHODV_(type, method)        virtual COM_DECLSPEC_NOTHROW                         type    STDMETHODVCALLTYPE method
#define PURE = 0
#define THIS_
#define THIS void
#define DECLARE_INTERFACE(iface)                      interface                    DECLSPEC_NOVTABLE iface
#define DECLARE_INTERFACE_(iface, baseiface)          interface                    DECLSPEC_NOVTABLE iface : public baseiface
#define DECLARE_INTERFACE_IID(iface, iid)             interface DECLSPEC_UUID(iid) DECLSPEC_NOVTABLE iface
#define DECLARE_INTERFACE_IID_(iface, baseiface, iid) interface DECLSPEC_UUID(iid) DECLSPEC_NOVTABLE iface : public baseiface

#define IFACEMETHOD(method)         STDMETHOD(method)
#define IFACEMETHOD_(type, method)  STDMETHOD_(type, method)
#define IFACEMETHODV(method)        STDMETHODV(method)
#define IFACEMETHODV_(type, method) STDMETHODV_(type, method)

#ifndef BEGIN_INTERFACE
# define BEGIN_INTERFACE
# define END_INTERFACE
#endif

interface IUnknown;

  extern "C++"
  {
    template<typename T> void **IID_PPV_ARGS_Helper(T **pp)
    {
      (void)static_cast<IUnknown *>(*pp);
      return reinterpret_cast<void **>(pp);
    }
  }

#define IID_PPV_ARGS(ppType) __uuidof(**(ppType)), IID_PPV_ARGS_Helper(ppType)

#else

#undef  interface
#define interface struct

#define STDMETHOD(method)         HRESULT (STDMETHODCALLTYPE  *method)
#define STDMETHOD_(type, method)  type    (STDMETHODCALLTYPE  *method)
#define STDMETHODV(method)        HRESULT (STDMETHODVCALLTYPE *method)
#define STDMETHODV_(type, method) type    (STDMETHODVCALLTYPE *method)

#define IFACEMETHOD(method)         STDMETHOD(method)
#define IFACEMETHOD_(type, method)  STDMETHOD_(type, method)
#define IFACEMETHODV(method)        STDMETHODV(method)
#define IFACEMETHODV_(type, method) STDMETHODV_(type, method)

#ifndef BEGIN_INTERFACE
# define BEGIN_INTERFACE
# define END_INTERFACE
#endif

#define PURE
#define THIS_ INTERFACE *This,
#define THIS  INTERFACE *This
#ifdef CONST_VTABLE
# undef  CONST_VTBL
# define CONST_VTBL const
# define DECLARE_INTERFACE(iface) typedef interface iface { const struct iface##Vtbl *lpVtbl; } iface; typedef const struct iface##Vtbl iface##Vtbl; const struct iface##Vtbl
#else
# undef  CONST_VTBL
# define CONST_VTBL
# define DECLARE_INTERFACE(iface) typedef interface iface { struct iface##Vtbl *lpVtbl; } iface; typedef struct iface##Vtbl iface##Vtbl; struct iface##Vtbl
#endif
# define DECLARE_INTERFACE_(iface, baseiface)          DECLARE_INTERFACE(iface)
# define DECLARE_INTERFACE_IID(iface, iid)             DECLARE_INTERFACE(iface)
# define DECLARE_INTERFACE_IID_(iface, baseiface, iid) DECLARE_INTERFACE_(iface, baseiface)
#endif

#ifndef FARSTRUCT
# define FARSTRUCT
#endif

#ifndef HUGEP
# define HUGEP
#endif

#include <stdlib.h>

#define LISet32(li, v)  ((li).HighPart = ((LONG)(v)) < 0 ? -1 : 0, (li).LowPart = (v))
#define ULISet32(li, v) ((li).HighPart = 0, (li).LowPart = (v))

#define CLSCTX_INPROC (CLSCTX_INPROC_SERVER | CLSCTX_INPROC_HANDLER                                             )
#define CLSCTX_ALL    (CLSCTX_INPROC_SERVER | CLSCTX_INPROC_HANDLER | CLSCTX_LOCAL_SERVER | CLSCTX_REMOTE_SERVER)
#define CLSCTX_SERVER (CLSCTX_INPROC_SERVER |                         CLSCTX_LOCAL_SERVER | CLSCTX_REMOTE_SERVER)

  typedef enum tagREGCLS
  {
    REGCLS_SINGLEUSE      = 0,
    REGCLS_MULTIPLEUSE    = 1,
    REGCLS_MULTI_SEPARATE = 2,
    REGCLS_SUSPENDED      = 4,
    REGCLS_SURROGATE      = 8,
    REGCLS_AGILE          = 0x10,
  } REGCLS;
  DEFINE_ENUM_FLAG_OPERATORS(REGCLS);

  typedef interface IRpcStubBuffer    IRpcStubBuffer;
  typedef interface IRpcChannelBuffer IRpcChannelBuffer;

  typedef enum tagCOINITBASE
  {
    COINITBASE_MULTITHREADED = 0x0,
  } COINITBASE;

#include <wtypesbase.h>
#include <unknwnbase.h>
#include <objidlbase.h>
#include <guiddef.h>

#ifndef INITGUID
# include <cguid.h>
#endif

  WINOLEAPI        CreateStreamOnHGlobal(HGLOBAL hGlobal, WINBOOL fDeleteOnRelease, LPSTREAM *ppstm);
  WINOLEAPI        GetHGlobalFromStream(LPSTREAM pstm, HGLOBAL *phglobal);
  WINOLEAPI_(void) CoUninitialize(void);
  WINOLEAPI        CoInitializeEx(LPVOID pvReserved, DWORD dwCoInit);
  WINOLEAPI        CoGetContextToken(ULONG_PTR *pToken);
  WINOLEAPI        CoGetApartmentType(APTTYPE *pAptType, APTTYPEQUALIFIER *pAptQualifier);

  DECLARE_HANDLE(CO_MTA_USAGE_COOKIE);

  WINOLEAPI        CoIncrementMTAUsage(CO_MTA_USAGE_COOKIE *pCookie);
  WINOLEAPI        CoDecrementMTAUsage(CO_MTA_USAGE_COOKIE Cookie);
  WINOLEAPI        CoRegisterClassObject(REFCLSID rclsid, LPUNKNOWN pUnk, DWORD dwClsContext, DWORD flags, LPDWORD lpdwRegister);
  WINOLEAPI        CoRevokeClassObject(DWORD dwRegister);
  WINOLEAPI        CoResumeClassObjects(void);
  WINOLEAPI        CoSuspendClassObjects(void);
  WINOLEAPI        CoCreateFreeThreadedMarshaler(LPUNKNOWN punkOuter, LPUNKNOWN *ppunkMarshal);
  WINOLEAPI        CoInitializeSecurity(PSECURITY_DESCRIPTOR pSecDesc, LONG cAuthSvc, SOLE_AUTHENTICATION_SERVICE *asAuthSvc, void *pReserved1, DWORD dwAuthnLevel, DWORD dwImpLevel, void *pAuthList, DWORD dwCapabilities, void *pReserved3);
  WINOLEAPI        CoCreateInstance(REFCLSID rclsid, LPUNKNOWN pUnkOuter, DWORD dwClsContext, REFIID riid, LPVOID *ppv);
  WINOLEAPI        StringFromCLSID(REFCLSID rclsid, LPOLESTR *lplpsz);
  WINOLEAPI        CLSIDFromString(LPCOLESTR lpsz, LPCLSID pclsid);
  WINOLEAPI        StringFromIID(REFIID rclsid, LPOLESTR *lplpsz);
  WINOLEAPI        IIDFromString(LPCOLESTR lpsz, LPIID lpiid);
  WINOLEAPI_(int)  StringFromGUID2(REFGUID rguid, LPOLESTR lpsz, int cchMax);
  WINOLEAPI        CoCreateGuid(GUID *pguid);

  typedef struct tagPROPVARIANT PROPVARIANT;

  WINOLEAPI PropVariantCopy(PROPVARIANT *pvarDest, const PROPVARIANT *pvarSrc);
  WINOLEAPI PropVariantClear(PROPVARIANT *pvar);
  WINOLEAPI FreePropVariantArray(ULONG cVariants, PROPVARIANT *rgvars);

  typedef HRESULT (STDAPICALLTYPE *LPFNGETCLASSOBJECT)(REFCLSID, REFIID, LPVOID *);
  typedef HRESULT (STDAPICALLTYPE *LPFNCANUNLOADNOW)(void);

  STDAPI             DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv);
  STDAPI             DllCanUnloadNow(void);
  WINOLEAPI_(LPVOID) CoTaskMemAlloc(SIZE_T cb);
  WINOLEAPI_(LPVOID) CoTaskMemRealloc(LPVOID pv, SIZE_T cb);
  WINOLEAPI_(void)   CoTaskMemFree(LPVOID pv);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

  WINOLEAPI CoGetCurrentLogicalThreadId(GUID *pguid);

  typedef struct tagServerInformation
  {
    DWORD  dwServerPid;
    DWORD  dwServerTid;
    UINT64 ui64ServerAddress;
  } ServerInformation, *PServerInformation;

  WINOLEAPI CoGetObjectContext(REFIID riid, LPVOID *ppv);
  WINOLEAPI CoGetMarshalSizeMax(ULONG *pulSize, REFIID riid, LPUNKNOWN pUnk, DWORD dwDestContext, LPVOID pvDestContext, DWORD mshlflags);
  WINOLEAPI CoMarshalInterface(LPSTREAM pStm, REFIID riid, LPUNKNOWN pUnk, DWORD dwDestContext, LPVOID pvDestContext, DWORD mshlflags);
  WINOLEAPI CoUnmarshalInterface(LPSTREAM pStm, REFIID riid, LPVOID *ppv);
  WINOLEAPI CoReleaseMarshalData(LPSTREAM pStm);
  WINOLEAPI CoDisconnectObject(LPUNKNOWN pUnk, DWORD dwReserved);
  WINOLEAPI CoGetStandardMarshal(REFIID riid, LPUNKNOWN pUnk, DWORD dwDestContext, LPVOID pvDestContext, DWORD mshlflags, LPMARSHAL *ppMarshal);

  typedef enum tagSTDMSHLFLAGS
  {
    SMEXF_SERVER  = 0x01,
    SMEXF_HANDLER = 0x02
  } STDMSHLFLAGS;

  WINOLEAPI        CoMarshalInterThreadInterfaceInStream(REFIID riid, LPUNKNOWN pUnk, LPSTREAM *ppStm);
  WINOLEAPI        CoGetInterfaceAndReleaseStream(LPSTREAM pStm, REFIID iid, LPVOID *ppv);
  WINOLEAPI_(void) CoFreeUnusedLibraries(void);
  WINOLEAPI_(void) CoFreeUnusedLibrariesEx(DWORD dwUnloadDelay, DWORD dwReserved);
  WINOLEAPI        CoSwitchCallContext(IUnknown *pNewObject, IUnknown **ppOldObject);

#define COM_RIGHTS_EXECUTE         1
#define COM_RIGHTS_EXECUTE_LOCAL   2
#define COM_RIGHTS_EXECUTE_REMOTE  4
#define COM_RIGHTS_ACTIVATE_LOCAL  8
#define COM_RIGHTS_ACTIVATE_REMOTE 16
#define COM_RIGHTS_RESERVED1       32
#define COM_RIGHTS_RESERVED2       64

  WINOLEAPI CoCreateInstanceEx(REFCLSID Clsid, IUnknown *punkOuter, DWORD dwClsCtx, COSERVERINFO *pServerInfo, DWORD dwCount, MULTI_QI *pResults);
  WINOLEAPI CoCreateInstanceFromApp(REFCLSID Clsid, IUnknown *punkOuter, DWORD dwClsCtx, PVOID reserved, DWORD dwCount, MULTI_QI *pResults);

  enum AgileReferenceOptions
  {
    AGILEREFERENCE_DEFAULT        = 0,
    AGILEREFERENCE_DELAYEDMARSHAL = 1,
  };

  WINOLEAPI RoGetAgileReference(enum AgileReferenceOptions options, REFIID riid, IUnknown *pUnk, IAgileReference **ppAgileReference);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  WINOLEAPI           CoGetMalloc(DWORD dwMemContext, LPMALLOC *ppMalloc);
  WINOLEAPI_(DWORD)   CoGetCurrentProcess(void);
  WINOLEAPI           CoGetCallerTID(LPDWORD lpdwTID);
  WINOLEAPI           CoGetDefaultContext(APTTYPE aptType, REFIID riid, void **ppv);
  WINOLEAPI           CoDecodeProxy(DWORD dwClientPid, UINT64 ui64ProxyAddress, PServerInformation pServerInformation);
  WINOLEAPI_(ULONG)   CoAddRefServerProcess(void);
  WINOLEAPI_(ULONG)   CoReleaseServerProcess(void);
  WINOLEAPI           CoGetPSClsid(REFIID riid, CLSID *pClsid);
  WINOLEAPI           CoRegisterPSClsid(REFIID riid, REFCLSID rclsid);
  WINOLEAPI           CoRegisterSurrogate(LPSURROGATE pSurrogate);
  WINOLEAPI           CoMarshalHresult(LPSTREAM pstm, HRESULT hresult);
  WINOLEAPI           CoUnmarshalHresult(LPSTREAM pstm, HRESULT *phresult);
  WINOLEAPI           CoLockObjectExternal(LPUNKNOWN pUnk, WINBOOL fLock, WINBOOL fLastUnlockReleases);
  WINOLEAPI           CoGetStdMarshalEx(LPUNKNOWN pUnkOuter, DWORD smexflags, LPUNKNOWN *ppUnkInner);
  WINOLEAPI_(WINBOOL) CoIsHandlerConnected(LPUNKNOWN pUnk);
  WINOLEAPI           CoDisconnectContext(DWORD dwTimeout);
  WINOLEAPI           CoGetCallContext(REFIID riid, void **ppInterface);
  WINOLEAPI           CoQueryProxyBlanket(IUnknown *pProxy, DWORD *pwAuthnSvc, DWORD *pAuthzSvc, LPOLESTR *pServerPrincName, DWORD *pAuthnLevel, DWORD *pImpLevel, RPC_AUTH_IDENTITY_HANDLE *pAuthInfo, DWORD *pCapabilites);
  WINOLEAPI           CoSetProxyBlanket(IUnknown *pProxy, DWORD dwAuthnSvc, DWORD dwAuthzSvc, OLECHAR *pServerPrincName, DWORD dwAuthnLevel, DWORD dwImpLevel, RPC_AUTH_IDENTITY_HANDLE pAuthInfo, DWORD dwCapabilities);
  WINOLEAPI           CoCopyProxy(IUnknown *pProxy, IUnknown **ppCopy);
  WINOLEAPI           CoQueryClientBlanket(DWORD *pAuthnSvc, DWORD *pAuthzSvc, LPOLESTR *pServerPrincName, DWORD *pAuthnLevel, DWORD *pImpLevel, RPC_AUTHZ_HANDLE *pPrivs, DWORD *pCapabilities);
  WINOLEAPI           CoImpersonateClient(void);
  WINOLEAPI           CoRevertToSelf(void);
  WINOLEAPI           CoQueryAuthenticationServices(DWORD *pcAuthSvc, SOLE_AUTHENTICATION_SERVICE **asAuthSvc);
  /* WINOLEAPI           CoRegisterActivationFilter(IActivationFilter *pActivationFilter); */
  WINOLEAPI           CoGetCancelObject(DWORD dwThreadId, REFIID iid, void **ppUnk);
  WINOLEAPI           CoSetCancelObject(IUnknown *pUnk);
  WINOLEAPI           CoCancelCall(DWORD dwThreadId, ULONG ulTimeout);
  WINOLEAPI           CoTestCancel(void);
  WINOLEAPI           CoEnableCallCancellation(LPVOID pReserved);
  WINOLEAPI           CoDisableCallCancellation(LPVOID pReserved);
  WINOLEAPI           CoWaitForMultipleHandles(DWORD dwFlags, DWORD dwTimeout, ULONG cHandles, LPHANDLE pHandles, LPDWORD lpdwindex);

  typedef enum tagCOWAIT_FLAGS
  {
    COWAIT_DEFAULT                  = 0,
    COWAIT_WAITALL                  = 1,
    COWAIT_ALERTABLE                = 2,
    COWAIT_INPUTAVAILABLE           = 4,
    COWAIT_DISPATCH_CALLS           = 8,
    COWAIT_DISPATCH_WINDOW_MESSAGES = 0x10,
  } COWAIT_FLAGS;
  DEFINE_ENUM_FLAG_OPERATORS(COWAIT_FLAGS);

  typedef enum CWMO_FLAGS
  {
    CWMO_DEFAULT                  = 0,
    CWMO_DISPATCH_CALLS           = 1,
    CWMO_DISPATCH_WINDOW_MESSAGES = 2
  } CWMO_FLAGS;
  DEFINE_ENUM_FLAG_OPERATORS(CWMO_FLAGS);

  WINOLEAPI CoWaitForMultipleObjects(DWORD dwFlags, DWORD dwTimeout, ULONG cHandles, const HANDLE *pHandles, LPDWORD lpdwindex);

#define CWMO_MAX_HANDLES 56

  WINOLEAPI CoGetTreatAsClass(REFCLSID clsidOld, LPCLSID pClsidNew);
  WINOLEAPI CoInvalidateRemoteMachineBindings(LPOLESTR pszMachineName);
  WINOLEAPI CoFileTimeNow(FILETIME *lpFileTime);
  WINOLEAPI CLSIDFromProgIDEx(LPCOLESTR lpszProgID, LPCLSID lpclsid);

#ifndef _CO_DEVICE_CATALOG_
# define _CO_DEVICE_CATALOG_
#endif

  DECLARE_HANDLE(CO_DEVICE_CATALOG_COOKIE);

  WINOLEAPI CoRegisterDeviceCatalog(PCWSTR deviceInstanceId, CO_DEVICE_CATALOG_COOKIE *cookie);
  WINOLEAPI CoRevokeDeviceCatalog(CO_DEVICE_CATALOG_COOKIE cookie);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  WINOLEAPI CoAllowUnmarshalerCLSID(REFCLSID clsid);

#define _CRT_INTERNAL_COMBASE_SYMBOL_PREFIX ""

  WINOLEAPI CoGetClassObject(REFCLSID rclsid, DWORD dwClsContext, LPVOID pvReserved, REFIID riid, LPVOID *ppv);
  WINOLEAPI ProgIDFromCLSID(REFCLSID clsid, LPOLESTR *lplpszProgID);
  WINOLEAPI CLSIDFromProgID(LPCOLESTR lpszProgID, LPCLSID lpclsid);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#ifndef RC_INVOKED
# include <poppack.h>
#endif

#endif  /* _COMBASEAPI_H_ */
