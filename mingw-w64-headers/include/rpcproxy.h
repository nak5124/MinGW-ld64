/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __RPCPROXY_H_VERSION__
# define __RPCPROXY_H_VERSION__ (477)
#endif  /* __RPCPROXY_H_VERSION__ */

#include <winapifamily.h>

#ifndef __RPCPROXY_H__
#define __RPCPROXY_H__

#define __midl_proxy

#ifdef __REQUIRED_RPCPROXY_H_VERSION__
# if __RPCPROXY_H_VERSION__ < __REQUIRED_RPCPROXY_H_VERSION__
#   error incorrect <rpcproxy.h> version. Use the header that matches with the MIDL compiler.
# endif
#endif

#ifdef __x86_64__
# include <pshpack8.h>
#endif

#include <basetsd.h>

#ifndef INC_OLE2
# define INC_OLE2
#endif

#ifndef DECLSPEC_SELECTANY
# define DECLSPEC_SELECTANY __attribute__((__selectany__))
#endif

#ifndef DECLSPEC_NOINLINE
# define DECLSPEC_NOINLINE __attribute__((__noinline__))
#endif

#ifndef GUID_DEFINED
# include <guiddef.h>
#endif  /* GUID_DEFINED */

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#if defined(RPCPROXY_ENABLE_CPP_NO_CINTERFACE) && defined(__cplusplus) && !defined(CINTERFACE)
  typedef struct IRpcStubBufferVtbl         IRpcStubBufferVtbl;
  typedef struct ICallFactoryVtbl           ICallFactoryVtbl;
  typedef struct IReleaseMarshalBuffersVtbl IReleaseMarshalBuffersVtbl;
  typedef struct IPSFactoryBufferVtbl       IPSFactoryBufferVtbl;
#endif

  typedef struct tagCInterfaceStubVtbl   CInterfaceStubVtbl;
  typedef struct tagCInterfaceProxyVtbl  CInterfaceProxyVtbl;
  typedef struct tagCInterfaceStubVtbl  *PCInterfaceStubVtblList;
  typedef struct tagCInterfaceProxyVtbl *PCInterfaceProxyVtblList;
  typedef const char                    *PCInterfaceName;
  typedef int __stdcall IIDLookupRtn(const IID *pIID, int *pIndex);
  typedef IIDLookupRtn *PIIDLookup;

#define NdrDefaultIIDLookup ((PIIDLookup)-1)

  typedef struct tagProxyFileInfo
  {
    const PCInterfaceProxyVtblList  *pProxyVtblList;
    const PCInterfaceStubVtblList   *pStubVtblList;
    const PCInterfaceName           *pNamesArray;
    const IID                      **pDelegatedIIDs;
    const PIIDLookup                 pIIDLookupRtn;
    unsigned short                   TableSize;
    unsigned short                   TableVersion;
    const IID                      **pAsyncIIDLookup;
    LONG_PTR                         Filler2;
    LONG_PTR                         Filler3;
    LONG_PTR                         Filler4;
  } ProxyFileInfo;

  typedef ProxyFileInfo ExtendedProxyFileInfo;

#include <rpc.h>
#include <rpcndr.h>
#include <string.h>
#include <memory.h>
  typedef struct tagCInterfaceProxyHeader
  {
#ifdef USE_STUBLESS_PROXY
    const void *pStublessProxyInfo;
#endif
    const IID  *piid;
  } CInterfaceProxyHeader;

#define CINTERFACE_PROXY_VTABLE(n)  \
  struct                            \
  {                                 \
    CInterfaceProxyHeader  header;  \
    void                  *Vtbl[n]; \
  }

#define IInspectableInterfaceProxyTag ((void *)-1)
#define IUnknownInterfaceProxyTag     ((void *)-2)

  typedef struct tagCInterfaceProxyVtbl
  {
    CInterfaceProxyHeader header;
    void *Vtbl[1];
  } CInterfaceProxyVtbl;

  typedef void (__RPC_STUB *PRPC_STUB_FUNCTION)(IRpcStubBuffer *This, IRpcChannelBuffer *_pRpcChannelBuffer, PRPC_MESSAGE _pRpcMessage, DWORD *pdwStubPhase);

  typedef struct tagCInterfaceStubHeader
  {
    const IID                *piid;
    const MIDL_SERVER_INFO   *pServerInfo;
    ULONG                     DispatchTableCount;
    const PRPC_STUB_FUNCTION *pDispatchTable;
  } CInterfaceStubHeader;

#define IInspectableNdrStubCall2CommonStubListTag ((const PRPC_STUB_FUNCTION*)-1)
#define IInspectableNdrStubCall3CommonStubListTag ((const PRPC_STUB_FUNCTION*)-2)

#if !defined(RPCPROXY_ENABLE_CPP_NO_CINTERFACE) || !defined(__cplusplus) || defined(CINTERFACE)
  typedef struct tagCInterfaceStubVtbl
  {
    CInterfaceStubHeader header;
    IRpcStubBufferVtbl   Vtbl;
  } CInterfaceStubVtbl;

#define RPCPROXY_GET_STUB_HEADER(StubVtblListEntry) (&(StubVtblListEntry)->header)

#else

#define RPCPROXY_GET_STUB_HEADER(StubVtblListEntry) (reinterpret_cast<const CInterfaceStubHeader*>(StubVtblListEntry))

#endif

  typedef struct tagCInterfaceStubVtblTag
  {
    CInterfaceStubHeader  header;
    void                 *tag;
  } CInterfaceStubVtblTag;

  typedef struct tagCStdStubBuffer
  {
    const struct IRpcStubBufferVtbl         *lpVtbl;
    LONG                                     RefCount;
    struct IUnknown                         *pvServerObject;
    const struct ICallFactoryVtbl           *pCallFactoryVtbl;
    const IID                               *pAsyncIID;
    struct IPSFactoryBuffer                 *pPSFactory;
    const struct IReleaseMarshalBuffersVtbl *pRMBVtbl;
  } CStdStubBuffer;

  typedef struct tagCStdPSFactoryBuffer
  {
    const IPSFactoryBufferVtbl  *lpVtbl;
    LONG                         RefCount;
    const ProxyFileInfo        **pProxyFileList;
    LONG                         Filler1;
  } CStdPSFactoryBuffer;

  RPCRTAPI HRESULT         RPC_ENTRY         NdrProxyErrorHandler(DWORD dwExceptionCode);
  RPCRTAPI void            RPC_ENTRY         NdrStubInitializePartial(PRPC_MESSAGE pRpcMsg, PMIDL_STUB_MESSAGE pStubMsg, PMIDL_STUB_DESC pStubDescriptor, IRpcChannelBuffer *pRpcChannelBuffer, ULONG RequestedBufferSize);
  /**/     void          __RPC_STUB          NdrStubForwardingFunction(IRpcStubBuffer *This, IRpcChannelBuffer *pChannel, PRPC_MESSAGE pmsg, DWORD *pdwStubPhase);
  RPCRTAPI HRESULT         RPC_ENTRY         NdrStubErrorHandler(DWORD dwExceptionCode);
  /**/     HRESULT         STDMETHODCALLTYPE CStdStubBuffer_QueryInterface(IRpcStubBuffer *This, REFIID riid, void **ppvObject);
  /**/     ULONG           STDMETHODCALLTYPE CStdStubBuffer_AddRef(IRpcStubBuffer *This);
  /**/     ULONG           STDMETHODCALLTYPE CStdStubBuffer_Release(IRpcStubBuffer *This);
  /**/     ULONG           STDMETHODCALLTYPE NdrCStdStubBuffer_Release(IRpcStubBuffer *This, IPSFactoryBuffer *pPSF);
  /**/     HRESULT         STDMETHODCALLTYPE CStdStubBuffer_Connect(IRpcStubBuffer *This, IUnknown *pUnkServer);
  /**/     void            STDMETHODCALLTYPE CStdStubBuffer_Disconnect(IRpcStubBuffer *This);
  /**/     HRESULT         STDMETHODCALLTYPE CStdStubBuffer_Invoke(IRpcStubBuffer *This, RPCOLEMESSAGE *pRpcMsg, IRpcChannelBuffer *pRpcChannelBuffer);
  /**/     IRpcStubBuffer *STDMETHODCALLTYPE CStdStubBuffer_IsIIDSupported(IRpcStubBuffer *This, REFIID riid);
  /**/     ULONG           STDMETHODCALLTYPE CStdStubBuffer_CountRefs(IRpcStubBuffer *This);
  /**/     HRESULT         STDMETHODCALLTYPE CStdStubBuffer_DebugServerQueryInterface(IRpcStubBuffer *This, void **ppv);
  /**/     void            STDMETHODCALLTYPE CStdStubBuffer_DebugServerRelease(IRpcStubBuffer *This, void *pv);
  /**/     HRESULT         STDMETHODCALLTYPE CStdStubBuffer2_QueryInterface(IRpcStubBuffer *This, REFIID riid, void **ppvObject);
  /**/     ULONG           STDMETHODCALLTYPE CStdStubBuffer2_Release(IRpcStubBuffer *This);
  /**/     HRESULT         STDMETHODCALLTYPE CStdStubBuffer2_Connect(IRpcStubBuffer *pthis, IUnknown *pUnkServer);
  /**/     void            STDMETHODCALLTYPE CStdStubBuffer2_Disconnect(IRpcStubBuffer *pthis);
  /**/     ULONG           STDMETHODCALLTYPE CStdStubBuffer2_CountRefs(IRpcStubBuffer *pthis);
  /**/     ULONG           STDMETHODCALLTYPE NdrCStdStubBuffer2_Release(IRpcStubBuffer *This, IPSFactoryBuffer *pPSF);
  /**/     HRESULT         STDMETHODCALLTYPE CStdAsyncStubBuffer_QueryInterface(IRpcStubBuffer *pthis, REFIID riid, void **ppvObject);
  /**/     ULONG           STDMETHODCALLTYPE CStdAsyncStubBuffer_AddRef(IRpcStubBuffer *pthis);
  /**/     ULONG           STDMETHODCALLTYPE CStdAsyncStubBuffer_Release(IRpcStubBuffer *pthis);
  /**/     HRESULT         STDMETHODCALLTYPE CStdAsyncStubBuffer_Connect(IRpcStubBuffer *pthis, IUnknown *pUnkServer);
  /**/     void            STDMETHODCALLTYPE CStdAsyncStubBuffer_Disconnect(IRpcStubBuffer *pthis);
  /**/     HRESULT         STDMETHODCALLTYPE CStdAsyncStubBuffer_Invoke(IRpcStubBuffer *pthis, RPCOLEMESSAGE *_prpcmsg, IRpcChannelBuffer *_pRpcChannelBuffer);
  /**/     ULONG           STDMETHODCALLTYPE CStdAsyncStubBuffer2_Release(IRpcStubBuffer *pthis);
  /**/     HRESULT         STDMETHODCALLTYPE CStdAsyncStubBuffer2_Connect(IRpcStubBuffer *pthis, IUnknown *pUnkServer);
  /**/     void            STDMETHODCALLTYPE CStdAsyncStubBuffer2_Disconnect(IRpcStubBuffer *pthis);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient3(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient4(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient5(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient6(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient7(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient8(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient9(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient10(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient11(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient12(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient13(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient14(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient15(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient16(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient17(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient18(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient19(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient20(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient21(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient22(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient23(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient24(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient25(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient26(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient27(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient28(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient29(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient30(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient31(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE ObjectStublessClient32(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction3(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction4(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction5(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction6(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction7(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction8(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction9(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction10(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction11(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction12(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction13(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction14(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction15(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction16(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction17(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction18(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction19(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction20(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction21(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction22(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction23(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction24(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction25(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction26(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction27(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction28(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction29(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction30(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction31(void);
  DECLSPEC_CHPE_GUEST void STDMETHODCALLTYPE NdrProxyForwardingFunction32(void);

#define CStdStubBuffer_METHODS              \
  CStdStubBuffer_QueryInterface,            \
  CStdStubBuffer_AddRef,                    \
  CStdStubBuffer_Release,                   \
  CStdStubBuffer_Connect,                   \
  CStdStubBuffer_Disconnect,                \
  CStdStubBuffer_Invoke,                    \
  CStdStubBuffer_IsIIDSupported,            \
  CStdStubBuffer_CountRefs,                 \
  CStdStubBuffer_DebugServerQueryInterface, \
  CStdStubBuffer_DebugServerRelease

#define CStdStubBuffer_DELEGATING_METHODS      0, 0, CStdStubBuffer2_Release, 0, 0, 0, 0, 0, 0, 0
#define CStdAsyncStubBuffer_METHODS            0, 0, 0,                       0, 0, 0, 0, 0, 0, 0
#define CStdAsyncStubBuffer_DELEGATING_METHODS 0, 0, 0,                       0, 0, 0, 0, 0, 0, 0

#define CStdStubBuffer_METHODS_OPT          \
  CStdStubBuffer_QueryInterface,            \
  CStdStubBuffer_AddRef,                    \
  CStdStubBuffer_Release,                   \
  CStdStubBuffer_Connect,                   \
  CStdStubBuffer_Disconnect,                \
  CStdStubBuffer_Invoke,                    \
  CStdStubBuffer_IsIIDSupported,            \
  CStdStubBuffer_CountRefs,                 \
  CStdStubBuffer_DebugServerQueryInterface, \
  CStdStubBuffer_DebugServerRelease

#define CStdStubBuffer_DELEGATING_METHODS_OPT \
  CStdStubBuffer2_QueryInterface,             \
  CStdStubBuffer_AddRef,                      \
  CStdStubBuffer2_Release,                    \
  CStdStubBuffer2_Connect,                    \
  CStdStubBuffer2_Disconnect,                 \
  CStdStubBuffer_Invoke,                      \
  CStdStubBuffer_IsIIDSupported,              \
  CStdStubBuffer2_CountRefs,                  \
  CStdStubBuffer_DebugServerQueryInterface,   \
  CStdStubBuffer_DebugServerRelease

#define CStdAsyncStubBuffer_METHODS_OPT     \
  CStdAsyncStubBuffer_QueryInterface,       \
  CStdAsyncStubBuffer_AddRef,               \
  CStdAsyncStubBuffer_Release,              \
  CStdAsyncStubBuffer_Connect,              \
  CStdAsyncStubBuffer_Disconnect,           \
  CStdAsyncStubBuffer_Invoke,               \
  CStdStubBuffer_IsIIDSupported,            \
  CStdStubBuffer_CountRefs,                 \
  CStdStubBuffer_DebugServerQueryInterface, \
  CStdStubBuffer_DebugServerRelease

#define CStdAsyncStubBuffer_DELEGATING_METHODS_OPT \
  CStdAsyncStubBuffer_QueryInterface,              \
  CStdAsyncStubBuffer_AddRef,                      \
  CStdAsyncStubBuffer2_Release,                    \
  CStdAsyncStubBuffer2_Connect,                    \
  CStdAsyncStubBuffer2_Disconnect,                 \
  CStdAsyncStubBuffer_Invoke,                      \
  CStdStubBuffer_IsIIDSupported,                   \
  CStdStubBuffer2_CountRefs,                       \
  CStdStubBuffer_DebugServerQueryInterface,        \
  CStdStubBuffer_DebugServerRelease

#define CStdStubBuffer_METHODS_TAG                 ((void *)-1)
#define CStdStubBuffer_DELEGATING_METHODS_TAG      ((void *)-2)
#define CStdAsyncStubBuffer_METHODS_TAG            ((void *)-3)
#define CStdAsyncStubBuffer_DELEGATING_METHODS_TAG ((void *)-4)

#define IID_GENERIC_CHECK_IID(name, pIID, index) memcmp(pIID, name##_ProxyVtblList[index]->header.piid, 16)

#define IID_BS_LOOKUP_SETUP int result, low = -1;

#define IID_BS_LOOKUP_INITIAL_TEST(name, sz, split) \
  result = name##_CHECK_IID(split);                 \
  if(result > 0)                                    \
  {                                                 \
    low = sz - split;                               \
  }                                                 \
  else if(!result)                                  \
  {                                                 \
    low = split;                                    \
    goto found_label;                               \
  }

#define IID_BS_LOOKUP_NEXT_TEST(name, split) \
  result = name##_CHECK_IID(low + split);    \
  if(result >= 0)                            \
  {                                          \
    low = low + split;                       \
    if(!result)                              \
    {                                        \
      goto found_label;                      \
    }                                        \
  }

#define IID_BS_LOOKUP_RETURN_RESULT(name, sz, index) \
  low = low + 1;                                     \
  if(low >= sz)                                      \
  {                                                  \
    goto not_found_label;                            \
  }                                                  \
  result = name##_CHECK_IID(low);                    \
  if(result)                                         \
  {                                                  \
    goto not_found_label;                            \
  }                                                  \
  found_label:                                       \
    (index) = low;                                   \
    return 1;                                        \
  not_found_label:                                   \
    return 0;

  RPCRTAPI HRESULT RPC_ENTRY NdrDllGetClassObject(REFCLSID rclsid, REFIID riid, void **ppv, const ProxyFileInfo **pProxyFileList, const CLSID *pclsid, CStdPSFactoryBuffer *pPSFactoryBuffer);
  RPCRTAPI HRESULT RPC_ENTRY NdrDllCanUnloadNow(CStdPSFactoryBuffer *pPSFactoryBuffer);

#ifndef ENTRY_PREFIX
# ifndef DllMain
#   define DISABLE_THREAD_LIBRARY_CALLS(x) DisableThreadLibraryCalls(x)
# endif
# define ENTRY_PREFIX
# define DLLREGISTERSERVER_ENTRY   DllRegisterServer
# define DLLUNREGISTERSERVER_ENTRY DllUnregisterServer
# define DLLMAIN_ENTRY             DllMain
# define DLLGETCLASSOBJECT_ENTRY   DllGetClassObject
# define DLLCANUNLOADNOW_ENTRY     DllCanUnloadNow
# define DLLRPCDUMMYCALL_ENTRY     DllRpcDummyCall
#else
# define __rpc_macro_expand2(a, b) a##b
# define __rpc_macro_expand(a, b)  __rpc_macro_expand2(a, b)
# define DLLREGISTERSERVER_ENTRY   __rpc_macro_expand(ENTRY_PREFIX, DllRegisterServer)
# define DLLUNREGISTERSERVER_ENTRY __rpc_macro_expand(ENTRY_PREFIX, DllUnregisterServer)
# define DLLMAIN_ENTRY             __rpc_macro_expand(ENTRY_PREFIX, DllMain)
# define DLLGETCLASSOBJECT_ENTRY   __rpc_macro_expand(ENTRY_PREFIX, DllGetClassObject)
# define DLLCANUNLOADNOW_ENTRY     __rpc_macro_expand(ENTRY_PREFIX, DllCanUnloadNow)
# define DLLRPCDUMMYCALL_ENTRY     __rpc_macro_expand(ENTRY_PREFIX, DllRpcDummyCall)
#endif

#ifndef DISABLE_THREAD_LIBRARY_CALLS
# define DISABLE_THREAD_LIBRARY_CALLS(x)
#endif

  RPCRTAPI HRESULT RPC_ENTRY NdrDllRegisterProxy(HMODULE hDll, const ProxyFileInfo **pProxyFileList, const CLSID *pclsid);
  RPCRTAPI HRESULT RPC_ENTRY NdrDllUnregisterProxy(HMODULE hDll, const ProxyFileInfo **pProxyFileList, const CLSID *pclsid);

#define REGISTER_PROXY_DLL_ROUTINES(pProxyFileList, pClsID)                                  \
  HINSTANCE hProxyDll = 0;                                                                   \
  WINBOOL WINAPI DLLMAIN_ENTRY(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)      \
  {                                                                                          \
    UNREFERENCED_PARAMETER(lpvReserved);                                                     \
    if(fdwReason == DLL_PROCESS_ATTACH)                                                      \
    {                                                                                        \
      hProxyDll = hinstDLL;                                                                  \
      DISABLE_THREAD_LIBRARY_CALLS(hinstDLL);                                                \
    }                                                                                        \
    return TRUE;                                                                             \
  }                                                                                          \
  HRESULT STDAPICALLTYPE DLLREGISTERSERVER_ENTRY(void)                                       \
  {                                                                                          \
    return NdrDllRegisterProxy(hProxyDll, (const ProxyFileInfo **)pProxyFileList, pClsID);   \
  }                                                                                          \
  HRESULT STDAPICALLTYPE DLLUNREGISTERSERVER_ENTRY(void)                                     \
  {                                                                                          \
    return NdrDllUnregisterProxy(hProxyDll, (const ProxyFileInfo **)pProxyFileList, pClsID); \
  }

#define STUB_FORWARDING_FUNCTION NdrStubForwardingFunction

#ifdef PROXY_CLSID
# define CLSID_PSFACTORYBUFFER extern CLSID PROXY_CLSID;
#else
# ifdef PROXY_CLSID_IS
#   define CLSID_PSFACTORYBUFFER const CLSID CLSID_PSFactoryBuffer = PROXY_CLSID_IS;
#   define PROXY_CLSID           CLSID_PSFactoryBuffer
# else
#   define CLSID_PSFACTORYBUFFER
# endif
#endif

#ifndef PROXY_CLSID
# define GET_DLL_CLSID (aProxyFileList[0]->pStubVtblList[0] != 0 ? aProxyFileList[0]->pStubVtblList[0]->header.piid : 0)
#else
# define GET_DLL_CLSID &PROXY_CLSID
#endif

#define EXTERN_PROXY_FILE(name) EXTERN_C const ProxyFileInfo name##_ProxyFileInfo;

#define PROXYFILE_LIST_START extern const ProxyFileInfo* const aProxyFileList[] = {

#define REFERENCE_PROXY_FILE(name) &name##_ProxyFileInfo

#define PROXYFILE_LIST_END 0 };

#define DLLDATA_GETPROXYDLLINFO(pPFList, pClsid)                                   \
  void RPC_ENTRY GetProxyDllInfo(const ProxyFileInfo ***pInfo, const CLSID **pId)  \
  {                                                                                \
    *pInfo = (const ProxyFileInfo**)pPFList;                                       \
    *pId   = pClsid;                                                               \
  };

#define DLLGETCLASSOBJECTROUTINE(pPFlist, pClsid, pFactory)                                           \
  HRESULT STDAPICALLTYPE DLLGETCLASSOBJECT_ENTRY(REFCLSID rclsid, REFIID riid, void **ppv)            \
  {                                                                                                   \
    return NdrDllGetClassObject(rclsid, riid, ppv, (const ProxyFileInfo**)pPFlist, pClsid, pFactory); \
  }

#define DLLCANUNLOADNOW(pFactory)                    \
  HRESULT STDAPICALLTYPE DLLCANUNLOADNOW_ENTRY(void) \
  {                                                  \
    return NdrDllCanUnloadNow(pFactory);             \
  }

#define DLLRPCDUMMYCALL void __cdecl DLLRPCDUMMYCALL_ENTRY(void){}

#define CSTDSTUBBUFFERRELEASE(pFactory)                                   \
  DECLSPEC_XFGVIRT(IUnknown, Release)                                     \
  ULONG STDMETHODCALLTYPE CStdStubBuffer_Release(IRpcStubBuffer *This)    \
  {                                                                       \
    return NdrCStdStubBuffer_Release(This, (IPSFactoryBuffer *)pFactory); \
  }

#ifdef PROXY_DELEGATION
# define CSTDSTUBBUFFER2RELEASE(pFactory)                                    \
    DECLSPEC_XFGVIRT(IUnknown, Release)                                      \
    ULONG STDMETHODCALLTYPE CStdStubBuffer2_Release(IRpcStubBuffer *This)    \
    {                                                                        \
      return NdrCStdStubBuffer2_Release(This, (IPSFactoryBuffer *)pFactory); \
    }
#else
# define CSTDSTUBBUFFER2RELEASE(pFactory)
#endif

#ifdef REGISTER_PROXY_DLL
# define DLLREGISTRY_ROUTINES(pProxyFileList, pClsID ) REGISTER_PROXY_DLL_ROUTINES(pProxyFileList, pClsID )
#else
# define DLLREGISTRY_ROUTINES(pProxyFileList, pClsID )
#endif

#define DLLDATA_ROUTINES(pProxyFileList, pClsID)               \
  CLSID_PSFACTORYBUFFER                                        \
  CStdPSFactoryBuffer gPFactory = {0, 0, 0, 0};                \
  DLLDATA_GETPROXYDLLINFO(pProxyFileList, pClsID)              \
  DLLGETCLASSOBJECTROUTINE(pProxyFileList, pClsID, &gPFactory) \
  DLLCANUNLOADNOW(&gPFactory)                                  \
  CSTDSTUBBUFFERRELEASE(&gPFactory)                            \
  CSTDSTUBBUFFER2RELEASE(&gPFactory)                           \
  DLLRPCDUMMYCALL                                              \
  DLLREGISTRY_ROUTINES(pProxyFileList, pClsID)

#define DLLDATA_STANDARD_ROUTINES DLLDATA_ROUTINES((const ProxyFileInfo**)pProxyFileList, &CLSID_PSFactoryBuffer)

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

  RPCRTAPI void RPC_ENTRY NdrProxyInitialize(void *This, PRPC_MESSAGE pRpcMsg, PMIDL_STUB_MESSAGE pStubMsg, PMIDL_STUB_DESC pStubDescriptor, unsigned int ProcNum );
  RPCRTAPI void RPC_ENTRY NdrProxyGetBuffer(void *This, PMIDL_STUB_MESSAGE pStubMsg);
  RPCRTAPI void RPC_ENTRY NdrProxySendReceive(void *This, MIDL_STUB_MESSAGE *pStubMsg);
  RPCRTAPI void RPC_ENTRY NdrProxyFreeBuffer(void *This, MIDL_STUB_MESSAGE *pStubMsg);
  RPCRTAPI void RPC_ENTRY NdrStubInitialize(PRPC_MESSAGE pRpcMsg, PMIDL_STUB_MESSAGE pStubMsg, PMIDL_STUB_DESC pStubDescriptor, IRpcChannelBuffer *pRpcChannelBuffer);
  RPCRTAPI void RPC_ENTRY NdrStubGetBuffer(IRpcStubBuffer *This, IRpcChannelBuffer *pRpcChannelBuffer, PMIDL_STUB_MESSAGE pStubMsg);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */

#ifdef __cplusplus
}
#endif

#ifdef __x86_64__
# include <poppack.h>
#endif

#endif  /* __RPCPROXY_H__ */
