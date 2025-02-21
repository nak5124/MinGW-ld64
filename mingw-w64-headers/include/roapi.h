/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __ROAPI_H__
#define __ROAPI_H__

#include <_mingw.h>

#include <apiset.h>
#include <apisetcconv.h>
#include <wtypesbase.h>
#include <inspectable.h>
#include <combaseapi.h>
#include <activation.h>
#include <hstring.h>

#define ROAPI DECLSPEC_IMPORT

#ifdef __cplusplus
extern "C" {
#endif

  typedef enum RO_INIT_TYPE
  {
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    RO_INIT_SINGLETHREADED = 0,
#endif
    RO_INIT_MULTITHREADED  = 1
  } RO_INIT_TYPE;

#ifdef __cplusplus
  typedef struct _RO_REGISTRATION_COOKIE {} *RO_REGISTRATION_COOKIE;
#else
  typedef struct _RO_REGISTRATION_COOKIE *RO_REGISTRATION_COOKIE;
#endif

  typedef HRESULT (STDAPICALLTYPE *PFNGETACTIVATIONFACTORY)(HSTRING, IActivationFactory **);

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

  ROAPI HRESULT WINAPI RoInitialize(RO_INIT_TYPE initType);
  ROAPI void    WINAPI RoUninitialize(void);
  ROAPI HRESULT WINAPI RoActivateInstance(HSTRING activatableClassId, IInspectable **instance);
  ROAPI HRESULT WINAPI RoRegisterActivationFactories(HSTRING *activatableClassIds, PFNGETACTIVATIONFACTORY *activationFactoryCallbacks, UINT32 count, RO_REGISTRATION_COOKIE *cookie);
  ROAPI void    WINAPI RoRevokeActivationFactories(RO_REGISTRATION_COOKIE cookie);
  ROAPI HRESULT WINAPI RoGetActivationFactory(HSTRING activatableClassId, REFIID iid, void **factory);

  typedef interface IApartmentShutdown IApartmentShutdown;
  DECLARE_HANDLE(APARTMENT_SHUTDOWN_REGISTRATION_COOKIE);

  ROAPI HRESULT WINAPI RoRegisterForApartmentShutdown(IApartmentShutdown *callbackObj, UINT64 *apartmentId, APARTMENT_SHUTDOWN_REGISTRATION_COOKIE *regCookie);
  ROAPI HRESULT WINAPI RoUnregisterForApartmentShutdown(APARTMENT_SHUTDOWN_REGISTRATION_COOKIE regCookie);
  ROAPI HRESULT WINAPI RoGetApartmentIdentifier(UINT64 *apartmentIdentifier);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */

#ifdef __cplusplus
}
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

#ifdef __cplusplus

  namespace Windows
  {
    namespace Foundation
    {
      __inline HRESULT Initialize(RO_INIT_TYPE initType
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        = RO_INIT_SINGLETHREADED
#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
      )
      {
        return RoInitialize(initType);
      }

      __inline void Uninitialize()
      {
        RoUninitialize();
      }

      template<class T>
      __inline HRESULT ActivateInstance(HSTRING activatableClassId, T **instance)
      {
        *instance = nullptr;
        IInspectable *pInspectable;
        HRESULT hr = RoActivateInstance(activatableClassId, &pInspectable);
        if(SUCCEEDED(hr))
        {
          if(__uuidof(T) == __uuidof(IInspectable))
          {
            *instance = static_cast<T*>(pInspectable);
          }
          else
          {
            hr = pInspectable->QueryInterface(IID_PPV_ARGS(instance));
            pInspectable->Release();
          }
        }
        return hr;
      }

      __inline HRESULT RegisterActivationFactories(HSTRING *activatableClassIds, PFNGETACTIVATIONFACTORY *activationFactoryCallbacks, UINT32 count, RO_REGISTRATION_COOKIE *cookie)
      {
        return RoRegisterActivationFactories(activatableClassIds, activationFactoryCallbacks, count, cookie);
      }

      __inline void RevokeActivationFactories(RO_REGISTRATION_COOKIE cookie)
      {
        RoRevokeActivationFactories(cookie);
      }

      template<class T>
      __inline HRESULT GetActivationFactory(HSTRING activatableClassId, T **factory)
      {
        return RoGetActivationFactory(activatableClassId, IID_PPV_ARGS(factory));
      }
    }
  }

  namespace ABI
  {
    namespace Windows
    {
      namespace Foundation
      {
        __inline HRESULT Initialize(RO_INIT_TYPE initType
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
          = RO_INIT_SINGLETHREADED
#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
        )
        {
          return RoInitialize(initType);
        }

        __inline void Uninitialize()
        {
          RoUninitialize();
        }

        template<class T>
        __inline HRESULT ActivateInstance(HSTRING activatableClassId, T **instance)
        {
          return ::Windows::Foundation::ActivateInstance(activatableClassId, instance);
        }

        __inline HRESULT RegisterActivationFactories(HSTRING *activatableClassIds, PFNGETACTIVATIONFACTORY *activationFactoryCallbacks, UINT32 count, RO_REGISTRATION_COOKIE *cookie)
        {
          return RoRegisterActivationFactories(activatableClassIds, activationFactoryCallbacks, count, cookie);
        }

        __inline void RevokeActivationFactories(RO_REGISTRATION_COOKIE cookie)
        {
          RoRevokeActivationFactories(cookie);
        }

        template<class T>
        __inline HRESULT GetActivationFactory(HSTRING activatableClassId, T **factory)
        {
          return RoGetActivationFactory(activatableClassId, IID_PPV_ARGS(factory));
        }
      }
    }
  }

#endif  /* __cplusplus */

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */

#endif  /* __ROAPI_H__ */
