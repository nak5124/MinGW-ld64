/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _PATHCCH_
#define _PATHCCH_

#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>
#include <minwinbase.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

  typedef enum PATHCCH_OPTIONS
  {
    PATHCCH_NONE                            = 0x0,
    PATHCCH_ALLOW_LONG_PATHS                = 0x01,
    PATHCCH_FORCE_ENABLE_LONG_NAME_PROCESS  = 0x02,
    PATHCCH_FORCE_DISABLE_LONG_NAME_PROCESS = 0x04,
    PATHCCH_DO_NOT_NORMALIZE_SEGMENTS       = 0x08,
    PATHCCH_ENSURE_IS_EXTENDED_LENGTH_PATH  = 0x10,
    PATHCCH_ENSURE_TRAILING_SLASH           = 0x020,
    PATHCCH_CANONICALIZE_SLASHES            = 0x040
  } PATHCCH_OPTIONS;

  DEFINE_ENUM_FLAG_OPERATORS(PATHCCH_OPTIONS)

#define VOLUME_PREFIX     L"\\\\?\\Volume"
#define VOLUME_PREFIX_LEN (ARRAYSIZE (VOLUME_PREFIX) - 1)

#define PATHCCH_MAX_CCH 0x8000

  WINPATHCCHAPI WINBOOL APIENTRY PathIsUNCEx(PCWSTR pszPath, PCWSTR *ppszServer);
  WINPATHCCHAPI WINBOOL APIENTRY PathCchIsRoot(PCWSTR pszPath);
  WINPATHCCHAPI HRESULT APIENTRY PathCchAddBackslashEx(PWSTR pszPath, size_t cchPath, PWSTR *ppszEnd, size_t *pcchRemaining);
  WINPATHCCHAPI HRESULT APIENTRY PathCchAddBackslash(PWSTR pszPath, size_t cchPath);
  WINPATHCCHAPI HRESULT APIENTRY PathCchRemoveBackslashEx(PWSTR pszPath, size_t cchPath, PWSTR *ppszEnd, size_t *pcchRemaining);
  WINPATHCCHAPI HRESULT APIENTRY PathCchRemoveBackslash(PWSTR pszPath, size_t cchPath);
  WINPATHCCHAPI HRESULT APIENTRY PathCchSkipRoot(PCWSTR pszPath, PCWSTR *ppszRootEnd);
  WINPATHCCHAPI HRESULT APIENTRY PathCchStripToRoot(PWSTR pszPath, size_t cchPath);
  WINPATHCCHAPI HRESULT APIENTRY PathCchRemoveFileSpec(PWSTR pszPath, size_t cchPath);
  WINPATHCCHAPI HRESULT APIENTRY PathCchFindExtension(PCWSTR pszPath, size_t cchPath, PCWSTR *ppszExt);
  WINPATHCCHAPI HRESULT APIENTRY PathCchAddExtension(PWSTR pszPath, size_t cchPath, PCWSTR pszExt);
  WINPATHCCHAPI HRESULT APIENTRY PathCchRenameExtension(PWSTR pszPath, size_t cchPath, PCWSTR pszExt);
  WINPATHCCHAPI HRESULT APIENTRY PathCchRemoveExtension(PWSTR pszPath, size_t cchPath);
  WINPATHCCHAPI HRESULT APIENTRY PathCchCanonicalizeEx(PWSTR pszPathOut, size_t cchPathOut, PCWSTR pszPathIn, ULONG dwFlags);
  WINPATHCCHAPI HRESULT APIENTRY PathCchCanonicalize(PWSTR pszPathOut, size_t cchPathOut, PCWSTR pszPathIn);
  WINPATHCCHAPI HRESULT APIENTRY PathCchCombineEx(PWSTR pszPathOut, size_t cchPathOut, PCWSTR pszPathIn, PCWSTR pszMore, ULONG dwFlags);
  WINPATHCCHAPI HRESULT APIENTRY PathCchCombine(PWSTR pszPathOut, size_t cchPathOut, PCWSTR pszPathIn, PCWSTR pszMore);
  WINPATHCCHAPI HRESULT APIENTRY PathCchAppendEx(PWSTR pszPath, size_t cchPath, PCWSTR pszMore, ULONG dwFlags);
  WINPATHCCHAPI HRESULT APIENTRY PathCchAppend(PWSTR pszPath, size_t cchPath, PCWSTR pszMore);
  WINPATHCCHAPI HRESULT APIENTRY PathCchStripPrefix(PWSTR pszPath, size_t cchPath);
  WINPATHCCHAPI HRESULT APIENTRY PathAllocCombine(PCWSTR pszPathIn, PCWSTR pszMore, ULONG dwFlags, PWSTR *ppszPathOut);
  WINPATHCCHAPI HRESULT APIENTRY PathAllocCanonicalize(PCWSTR pszPathIn, ULONG dwFlags, PWSTR *ppszPathOut);

#ifndef PATHCCH_NO_DEPRECATE
# undef PathAddBackslashA
# undef PathAddBackslashW
# undef PathAddExtensionA
# undef PathAddExtensionW
# undef PathAppendA
# undef PathAppendW
# undef PathCanonicalizeA
# undef PathCanonicalizeW
# undef PathCombineA
# undef PathCombineW
# undef PathRenameExtensionA
# undef PathRenameExtensionW
# ifndef DEPRECATE_SUPPORTED
#   define PathAddBackslashA    PathAddBackslashA_instead_use_PathCchAddBackslash;
#   define PathAddBackslashW    PathAddBackslashW_instead_use_PathCchAddBackslash;
#   define PathAddExtensionA    PathAddExtensionA_instead_use_PathCchAddExtension;
#   define PathAddExtensionW    PathAddExtensionW_instead_use_PathCchAddExtension;
#   define PathAppendA          PathAppendA_instead_use_PathCchAppend;
#   define PathAppendW          PathAppendW_instead_use_PathCchAppend;
#   define PathCanonicalizeA    PathCanonicalizeA_instead_use_PathCchCanonicalize;
#   define PathCanonicalizeW    PathCanonicalizeW_instead_use_PathCchCanonicalize;
#   define PathCombineA         PathCombineA_instead_use_PathCchCombine;
#   define PathCombineW         PathCombineW_instead_use_PathCchCombine;
#   define PathRenameExtensionA PathRenameExtensionA_instead_use_PathCchRenameExtension;
#   define PathRenameExtensionW PathRenameExtensionW_instead_use_PathCchRenameExtension;
# endif
#endif

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

  __inline
  WINBOOL PathIsUNCEx(PWSTR pszPath, PWSTR *ppszServer)
  {
    return PathIsUNCEx(const_cast<PCWSTR>(pszPath), const_cast<PCWSTR*>(ppszServer));
  }

  __inline
  HRESULT PathCchSkipRoot(PWSTR pszPath, PWSTR *ppszRootEnd)
  {
    return PathCchSkipRoot(const_cast<PCWSTR>(pszPath), const_cast<PCWSTR*>(ppszRootEnd));
  }

  __inline
  HRESULT PathCchFindExtension(PWSTR pszPath, size_t cchPath, PWSTR *ppszExt)
  {
    return PathCchFindExtension(const_cast<PCWSTR>(pszPath), cchPath, const_cast<PCWSTR*>(ppszExt));
  }

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */

#endif

#endif  /* _PATHCCH_ */
