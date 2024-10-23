#include <winapifamily.h>
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __WINEFS_H__
#define __WINEFS_H__

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#define WINEFS_SETUSERKEY_SET_CAPABILITIES 0x00000001

#ifndef ALGIDDEF
# define ALGIDDEF
  typedef unsigned int ALG_ID;
#endif

  typedef struct _CERTIFICATE_BLOB
  {
    DWORD dwCertEncodingType;
    DWORD cbData;
    PBYTE pbData;
  } EFS_CERTIFICATE_BLOB, *PEFS_CERTIFICATE_BLOB;

  typedef struct _EFS_HASH_BLOB
  {
    DWORD cbData;
    PBYTE pbData;
  } EFS_HASH_BLOB, *PEFS_HASH_BLOB;

  typedef struct _EFS_RPC_BLOB
  {
    DWORD cbData;
    PBYTE pbData;
  } EFS_RPC_BLOB, *PEFS_RPC_BLOB;

  typedef struct _EFS_PIN_BLOB
  {
    DWORD cbPadding;
    DWORD cbData;
    PBYTE pbData;
  } EFS_PIN_BLOB, *PEFS_PIN_BLOB;

  typedef struct _EFS_KEY_INFO
  {
    DWORD  dwVersion;
    ULONG  Entropy;
    ALG_ID Algorithm;
    ULONG  KeyLength;
  } EFS_KEY_INFO, *PEFS_KEY_INFO;

  typedef struct _EFS_COMPATIBILITY_INFO
  {
    DWORD EfsVersion;
  } EFS_COMPATIBILITY_INFO, *PEFS_COMPATIBILITY_INFO;

#define EFS_COMPATIBILITY_VERSION_NCRYPT_PROTECTOR 5
#define EFS_COMPATIBILITY_VERSION_PFILE_PROTECTOR  6

#define EFS_IS_DESCRIPTOR_VERSION(__v) ((__v == EFS_COMPATIBILITY_VERSION_NCRYPT_PROTECTOR) || (__v == EFS_COMPATIBILITY_VERSION_PFILE_PROTECTOR))

#define EFS_SUBVER_UNKNOWN      0
#define EFS_EFS_SUBVER_EFS_CERT 1
#define EFS_PFILE_SUBVER_RMS    2
#define EFS_PFILE_SUBVER_APPX   3

  typedef struct _EFS_VERSION_INFO
  {
    DWORD EfsVersion;
    DWORD SubVersion;
  } EFS_VERSION_INFO, *PEFS_VERSION_INFO;

#define EFS_IS_APPX_VERSION(__v, __subV) ((__v == EFS_COMPATIBILITY_VERSION_PFILE_PROTECTOR) && (__subV == EFS_PFILE_SUBVER_APPX))

  typedef struct _EFS_DECRYPTION_STATUS_INFO
  {
    DWORD dwDecryptionError;
    DWORD dwHashOffset;
    DWORD cbHash;
  } EFS_DECRYPTION_STATUS_INFO, *PEFS_DECRYPTION_STATUS_INFO;

  typedef struct _EFS_ENCRYPTION_STATUS_INFO
  {
    WINBOOL bHasCurrentKey;
    DWORD   dwEncryptionError;
  } EFS_ENCRYPTION_STATUS_INFO, *PEFS_ENCRYPTION_STATUS_INFO;

  typedef struct _ENCRYPTION_CERTIFICATE
  {
    DWORD                  cbTotalLength;
    SID                   *pUserSid;
    PEFS_CERTIFICATE_BLOB  pCertBlob;
  } ENCRYPTION_CERTIFICATE, *PENCRYPTION_CERTIFICATE;

#define MAX_SID_SIZE 256

  typedef struct _ENCRYPTION_CERTIFICATE_HASH
  {
    DWORD           cbTotalLength;
    SID            *pUserSid;
    PEFS_HASH_BLOB  pHash;
    LPWSTR          lpDisplayInformation;
  } ENCRYPTION_CERTIFICATE_HASH, *PENCRYPTION_CERTIFICATE_HASH;

  typedef struct _ENCRYPTION_CERTIFICATE_HASH_LIST
  {
    DWORD                         nCert_Hash;
    PENCRYPTION_CERTIFICATE_HASH *pUsers;
  } ENCRYPTION_CERTIFICATE_HASH_LIST, *PENCRYPTION_CERTIFICATE_HASH_LIST;

  typedef struct _ENCRYPTION_CERTIFICATE_LIST
  {
    DWORD                    nUsers;
    PENCRYPTION_CERTIFICATE *pUsers;
  } ENCRYPTION_CERTIFICATE_LIST, *PENCRYPTION_CERTIFICATE_LIST;

#define EFS_METADATA_ADD_USER     0x00000001
#define EFS_METADATA_REMOVE_USER  0x00000002
#define EFS_METADATA_REPLACE_USER 0x00000004
#define EFS_METADATA_GENERAL_OP   0x00000008

  typedef struct _ENCRYPTED_FILE_METADATA_SIGNATURE
  {
    DWORD                             dwEfsAccessType;
    PENCRYPTION_CERTIFICATE_HASH_LIST pCertificatesAdded;
    PENCRYPTION_CERTIFICATE           pEncryptionCertificate;
    PEFS_RPC_BLOB                     pEfsStreamSignature;
  } ENCRYPTED_FILE_METADATA_SIGNATURE, *PENCRYPTED_FILE_METADATA_SIGNATURE;

  typedef struct _ENCRYPTION_PROTECTOR
  {
    DWORD   cbTotalLength;
    SID    *pUserSid;
    LPWSTR  lpProtectorDescriptor;
  } ENCRYPTION_PROTECTOR, *PENCRYPTION_PROTECTOR;

  typedef struct _ENCRYPTION_PROTECTOR_LIST
  {
    DWORD                  nProtectors;
    PENCRYPTION_PROTECTOR *pProtectors;
  } ENCRYPTION_PROTECTOR_LIST, *PENCRYPTION_PROTECTOR_LIST;

  WINADVAPI DWORD   WINAPI QueryUsersOnEncryptedFile(LPCWSTR lpFileName, PENCRYPTION_CERTIFICATE_HASH_LIST *pUsers);
  WINADVAPI DWORD   WINAPI QueryRecoveryAgentsOnEncryptedFile(LPCWSTR lpFileName, PENCRYPTION_CERTIFICATE_HASH_LIST *pRecoveryAgents);
  WINADVAPI DWORD   WINAPI RemoveUsersFromEncryptedFile(LPCWSTR lpFileName, PENCRYPTION_CERTIFICATE_HASH_LIST pHashes);
  WINADVAPI DWORD   WINAPI AddUsersToEncryptedFile(LPCWSTR lpFileName, PENCRYPTION_CERTIFICATE_LIST pEncryptionCertificates);
  WINADVAPI DWORD   WINAPI SetUserFileEncryptionKey(PENCRYPTION_CERTIFICATE pEncryptionCertificate);
  WINADVAPI DWORD   WINAPI SetUserFileEncryptionKeyEx(PENCRYPTION_CERTIFICATE pEncryptionCertificate, DWORD dwCapabilities, DWORD dwFlags, LPVOID pvReserved);
  WINADVAPI VOID    WINAPI FreeEncryptionCertificateHashList(PENCRYPTION_CERTIFICATE_HASH_LIST pUsers);
  WINADVAPI WINBOOL WINAPI EncryptionDisable(LPCWSTR DirPath, WINBOOL Disable);
  WINADVAPI DWORD   WINAPI DuplicateEncryptionInfoFile(LPCWSTR SrcFileName, LPCWSTR DstFileName, DWORD dwCreationDistribution, DWORD dwAttributes, CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI DWORD   WINAPI GetEncryptedFileMetadata(LPCWSTR lpFileName, PDWORD pcbMetadata, PBYTE *ppbMetadata);
  WINADVAPI DWORD   WINAPI SetEncryptedFileMetadata(LPCWSTR lpFileName, PBYTE pbOldMetadata, PBYTE pbNewMetadata, PENCRYPTION_CERTIFICATE_HASH pOwnerHash, DWORD dwOperation, PENCRYPTION_CERTIFICATE_HASH_LIST pCertificatesAdded);
  WINADVAPI VOID    WINAPI FreeEncryptedFileMetadata(PBYTE pbMetadata);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */

#ifdef __cplusplus
}
#endif

#endif  /* __WINEFS_H__ */
