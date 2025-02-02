/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __TOKENBINDING_H__
#define __TOKENBINDING_H__

#include <winapifamily.h>

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  typedef enum TOKENBINDING_TYPE
  {
    TOKENBINDING_TYPE_PROVIDED = 0,
    TOKENBINDING_TYPE_REFERRED = 1,
  } TOKENBINDING_TYPE;

  typedef enum TOKENBINDING_EXTENSION_FORMAT
  {
    TOKENBINDING_EXTENSION_FORMAT_UNDEFINED = 0,
  } TOKENBINDING_EXTENSION_FORMAT;

  typedef enum TOKENBINDING_KEY_PARAMETERS_TYPE
  {
    TOKENBINDING_KEY_PARAMETERS_TYPE_RSA2048_PKCS = 0,
    TOKENBINDING_KEY_PARAMETERS_TYPE_RSA2048_PSS  = 1,
    TOKENBINDING_KEY_PARAMETERS_TYPE_ECDSAP256    = 2,
    TOKENBINDING_KEY_PARAMETERS_TYPE_ANYEXISTING  = 255,
  } TOKENBINDING_KEY_PARAMETERS_TYPE;

#pragma pack(push, 1)
  typedef struct TOKENBINDING_IDENTIFIER
  {
    BYTE keyType;
  } TOKENBINDING_IDENTIFIER;
#pragma pack(pop)

  typedef struct TOKENBINDING_RESULT_DATA
  {
    TOKENBINDING_TYPE              bindingType;
    DWORD                          identifierSize;
    TOKENBINDING_IDENTIFIER       *identifierData;
    TOKENBINDING_EXTENSION_FORMAT  extensionFormat;
    DWORD                          extensionSize;
    PVOID                          extensionData;
  } TOKENBINDING_RESULT_DATA;

  typedef struct TOKENBINDING_RESULT_LIST
  {
    DWORD                     resultCount;
    TOKENBINDING_RESULT_DATA *resultData;
  } TOKENBINDING_RESULT_LIST;

  typedef struct TOKENBINDING_KEY_TYPES
  {
    DWORD                             keyCount;
    TOKENBINDING_KEY_PARAMETERS_TYPE *keyType;
  } TOKENBINDING_KEY_TYPES;

  STDAPI_(SECURITY_STATUS) TokenBindingGenerateBinding(TOKENBINDING_KEY_PARAMETERS_TYPE keyType, PCWSTR targetURL, TOKENBINDING_TYPE bindingType, const void *tlsEKM,
    DWORD tlsEKMSize, TOKENBINDING_EXTENSION_FORMAT extensionFormat, const void *extensionData, void **tokenBinding, DWORD *tokenBindingSize, TOKENBINDING_RESULT_DATA **resultData);
  STDAPI_(SECURITY_STATUS) TokenBindingGenerateMessage(const void *tokenBindings[], const DWORD tokenBindingsSize[], DWORD tokenBindingsCount, void **tokenBindingMessage, DWORD *tokenBindingMessageSize);
  STDAPI_(SECURITY_STATUS) TokenBindingVerifyMessage(const void *tokenBindingMessage, DWORD tokenBindingMessageSize, TOKENBINDING_KEY_PARAMETERS_TYPE keyType,
    const void *tlsEKM, DWORD tlsEKMSize, TOKENBINDING_RESULT_LIST **resultList);
  STDAPI_(SECURITY_STATUS) TokenBindingGetKeyTypesClient(TOKENBINDING_KEY_TYPES **keyTypes);
  STDAPI_(SECURITY_STATUS) TokenBindingGetKeyTypesServer(TOKENBINDING_KEY_TYPES **keyTypes);
  STDAPI_(SECURITY_STATUS) TokenBindingDeleteBinding(PCWSTR targetURL);
  STDAPI_(SECURITY_STATUS) TokenBindingDeleteAllBindings(void);
  STDAPI_(SECURITY_STATUS) TokenBindingGenerateID(TOKENBINDING_KEY_PARAMETERS_TYPE keyType, const void *publicKey, DWORD publicKeySize, TOKENBINDING_RESULT_DATA **resultData);
  STDAPI_(SECURITY_STATUS) TokenBindingGenerateIDForUri(TOKENBINDING_KEY_PARAMETERS_TYPE keyType, PCWSTR targetUri, TOKENBINDING_RESULT_DATA **resultData);
  STDAPI_(SECURITY_STATUS) TokenBindingGetHighestSupportedVersion(BYTE *majorVersion, BYTE *minorVersion);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#endif  /* __TOKENBINDING_H__ */
