/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_SHLWAPI
#define _INC_SHLWAPI

#include <_mingw_unicode.h>
#include <winapifamily.h>

#ifndef NOSHLWAPI

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

#include <specstrings.h>
#include <objbase.h>
#include <shtypes.h>

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

#ifndef WINSHLWAPI
# define LWSTDAPI         EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE
# define LWSTDAPI_(type)  EXTERN_C DECLSPEC_IMPORT type    STDAPICALLTYPE
# define LWSTDAPIV        EXTERN_C DECLSPEC_IMPORT HRESULT STDAPIVCALLTYPE
# define LWSTDAPIV_(type) EXTERN_C DECLSPEC_IMPORT type    STDAPIVCALLTYPE
#endif

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

#include <pshpack8.h>

#ifndef __IBindCtx_FWD_DEFINED__
# define __IBindCtx_FWD_DEFINED__
  typedef interface IBindCtx IBindCtx;
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__cplusplus) && defined(STRICT_CONST)
# define USE_STRICT_CONST
#endif

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#ifndef NO_SHLWAPI_STRFCNS

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#ifdef USE_STRICT_CONST
  LWSTDAPI_(PCSTR)  StrChrA(PCSTR pszStart, WORD wMatch);
  LWSTDAPI_(PCWSTR) StrChrW(PCWSTR pszStart, WCHAR wMatch);
  LWSTDAPI_(PCSTR)  StrChrIA(PCSTR pszStart, WORD wMatch);
  LWSTDAPI_(PCWSTR) StrChrIW(PCWSTR pszStart, WCHAR wMatch);
  LWSTDAPI_(PCWSTR) StrChrNW(PCWSTR pszStart, WCHAR wMatch, UINT cchMax);
  LWSTDAPI_(PCWSTR) StrChrNIW(PCWSTR pszStart, WCHAR wMatch, UINT cchMax);
#else
  LWSTDAPI_(PSTR)   StrChrA(PCSTR pszStart, WORD wMatch);
  LWSTDAPI_(PWSTR)  StrChrW(PCWSTR pszStart, WCHAR wMatch);
  LWSTDAPI_(PSTR)   StrChrIA(PCSTR pszStart, WORD wMatch);
  LWSTDAPI_(PWSTR)  StrChrIW(PCWSTR pszStart, WCHAR wMatch);
  LWSTDAPI_(PWSTR)  StrChrNW(PCWSTR pszStart, WCHAR wMatch, UINT cchMax);
  LWSTDAPI_(PWSTR)  StrChrNIW(PCWSTR pszStart, WCHAR wMatch, UINT cchMax);
#endif
#define StrChr  __MINGW_NAME_AW(StrChr)
#define StrChrI __MINGW_NAME_AW(StrChrI)
  LWSTDAPI_(int)    StrCmpNA(PCSTR psz1, PCSTR psz2, int nChar);
  LWSTDAPI_(int)    StrCmpNW(PCWSTR psz1, PCWSTR psz2, int nChar);
#define StrCmpN __MINGW_NAME_AW(StrCmpN)
#define StrNCmp   StrCmpN
  LWSTDAPI_(int)    StrCmpNIA(PCSTR psz1, PCSTR psz2, int nChar);
  LWSTDAPI_(int)    StrCmpNIW(PCWSTR psz1, PCWSTR psz2, int nChar);
#define StrCmpNI __MINGW_NAME_AW(StrCmpNI)
#define StrNCmpI   StrCmpNI
  LWSTDAPI_(int)    StrCSpnA(PCSTR pszStr, PCSTR pszSet);
  LWSTDAPI_(int)    StrCSpnW(PCWSTR pszStr, PCWSTR pszSet);
#define StrCSpn __MINGW_NAME_AW(StrCSpn)
  LWSTDAPI_(int)    StrCSpnIA(PCSTR pszStr, PCSTR pszSet);
  LWSTDAPI_(int)    StrCSpnIW(PCWSTR pszStr, PCWSTR pszSet);
#define StrCSpnI __MINGW_NAME_AW(StrCSpnI)
  LWSTDAPI_(PSTR)   StrDupA(PCSTR pszSrch);
  LWSTDAPI_(PWSTR)  StrDupW(PCWSTR pszSrch);
#define StrDup __MINGW_NAME_AW(StrDup)

  enum tagSFBS_FLAGS
  {
    SFBS_FLAGS_ROUND_TO_NEAREST_DISPLAYED_DIGIT    = 0x0001,
    SFBS_FLAGS_TRUNCATE_UNDISPLAYED_DECIMAL_DIGITS = 0x0002
  };
  typedef int SFBS_FLAGS;

  LWSTDAPI           StrFormatByteSizeEx(ULONGLONG ull, SFBS_FLAGS flags, PWSTR pszBuf, UINT cchBuf);
  LWSTDAPI_(PSTR)    StrFormatByteSizeA(DWORD dw, PSTR pszBuf, UINT cchBuf);
  LWSTDAPI_(PWSTR)   StrFormatByteSizeW(LONGLONG qdw, PWSTR pszBuf, UINT cchBuf);
#define StrFormatByteSize __MINGW_NAME_AW(StrFormatByteSize)
  LWSTDAPI_(PSTR)    StrFormatByteSize64A(LONGLONG qdw, PSTR pszBuf, UINT cchBuf);
#ifdef UNICODE
# define StrFormatByteSize64 StrFormatByteSizeW
#else
# define StrFormatByteSize64 StrFormatByteSize64A
#endif
  LWSTDAPI_(PSTR)    StrFormatKBSizeA(LONGLONG qdw, PSTR pszBuf, UINT cchBuf);
  LWSTDAPI_(PWSTR)   StrFormatKBSizeW(LONGLONG qdw, PWSTR pszBuf, UINT cchBuf);
#define StrFormatKBSize __MINGW_NAME_AW(StrFormatKBSize)
  LWSTDAPI_(int)     StrFromTimeIntervalA(PSTR pszOut, UINT cchMax, DWORD dwTimeMS, int digits);
  LWSTDAPI_(int)     StrFromTimeIntervalW(PWSTR pszOut, UINT cchMax, DWORD dwTimeMS, int digits);
#define StrFromTimeInterval __MINGW_NAME_AW(StrFromTimeInterval)
  LWSTDAPI_(WINBOOL) StrIsIntlEqualA(WINBOOL fCaseSens, PCSTR pszString1, PCSTR pszString2, int nChar);
  LWSTDAPI_(WINBOOL) StrIsIntlEqualW(WINBOOL fCaseSens, PCWSTR pszString1, PCWSTR pszString2, int nChar);
#define StrIsIntlEqual __MINGW_NAME_AW(StrIsIntlEqual)
  LWSTDAPI_(PSTR)    StrNCatA(PSTR psz1, PCSTR psz2, int cchMax);
  LWSTDAPI_(PWSTR)   StrNCatW(PWSTR psz1, PCWSTR psz2, int cchMax);
#define StrNCat __MINGW_NAME_AW(StrNCat)
#define StrCatN   StrNCat
#ifdef USE_STRICT_CONST
  LWSTDAPI_(PCSTR)   StrPBrkA(PCSTR psz, PCSTR pszSet);
  LWSTDAPI_(PCWSTR)  StrPBrkW(PCWSTR psz, PCWSTR pszSet);
  LWSTDAPI_(PCSTR)   StrRChrA(PCSTR pszStart, PCSTR pszEnd, WORD wMatch);
  LWSTDAPI_(PCWSTR)  StrRChrW(PCWSTR pszStart, PCWSTR pszEnd, WCHAR wMatch);
  LWSTDAPI_(PCSTR)   StrRChrIA(PCSTR pszStart, PCSTR pszEnd, WORD wMatch);
  LWSTDAPI_(PCWSTR)  StrRChrIW(PCWSTR pszStart, PCWSTR pszEnd, WCHAR wMatch);
  LWSTDAPI_(PCSTR)   StrRStrIA(PCSTR pszSource, PCSTR pszLast, PCSTR pszSrch);
  LWSTDAPI_(PCWSTR)  StrRStrIW(PCWSTR pszSource, PCWSTR pszLast, PCWSTR pszSrch);
#else
  LWSTDAPI_(PSTR)    StrPBrkA(PCSTR psz, PCSTR pszSet);
  LWSTDAPI_(PWSTR)   StrPBrkW(PCWSTR psz, PCWSTR pszSet);
  LWSTDAPI_(PSTR)    StrRChrA(PCSTR pszStart, PCSTR pszEnd, WORD wMatch);
  LWSTDAPI_(PWSTR)   StrRChrW(PCWSTR pszStart, PCWSTR pszEnd, WCHAR wMatch);
  LWSTDAPI_(PSTR)    StrRChrIA(PCSTR pszStart, PCSTR pszEnd, WORD wMatch);
  LWSTDAPI_(PWSTR)   StrRChrIW(PCWSTR pszStart, PCWSTR pszEnd, WCHAR wMatch);
  LWSTDAPI_(PSTR)    StrRStrIA(PCSTR pszSource, PCSTR pszLast, PCSTR pszSrch);
  LWSTDAPI_(PWSTR)   StrRStrIW(PCWSTR pszSource, PCWSTR pszLast, PCWSTR pszSrch);
#endif
#define StrPBrk  __MINGW_NAME_AW(StrPBrk)
#define StrRChr  __MINGW_NAME_AW(StrRChr)
#define StrRChrI __MINGW_NAME_AW(StrRChrI)
#define StrRStrI __MINGW_NAME_AW(StrRStrI)
  LWSTDAPI_(int)     StrSpnA(PCSTR psz, PCSTR pszSet);
  LWSTDAPI_(int)     StrSpnW(PCWSTR psz, PCWSTR pszSet);
#define StrSpn __MINGW_NAME_AW(StrSpn)
#ifdef USE_STRICT_CONST
  LWSTDAPI_(PCSTR)   StrStrA(PCSTR pszFirst, PCSTR pszSrch);
  LWSTDAPI_(PCWSTR)  StrStrW(PCWSTR pszFirst, PCWSTR pszSrch);
  LWSTDAPI_(PCSTR)   StrStrIA(PCSTR pszFirst, PCSTR pszSrch);
  LWSTDAPI_(PCWSTR)  StrStrIW(PCWSTR pszFirst, PCWSTR pszSrch);
  LWSTDAPI_(PCWSTR)  StrStrNW(PCWSTR pszFirst, PCWSTR pszSrch, UINT cchMax);
  LWSTDAPI_(PCWSTR)  StrStrNIW(PCWSTR pszFirst, PCWSTR pszSrch, UINT cchMax);
#else
  LWSTDAPI_(PSTR)    StrStrA(PCSTR pszFirst, PCSTR pszSrch);
  LWSTDAPI_(PWSTR)   StrStrW(PCWSTR pszFirst, PCWSTR pszSrch);
  LWSTDAPI_(PSTR)    StrStrIA(PCSTR pszFirst, PCSTR pszSrch);
  LWSTDAPI_(PWSTR)   StrStrIW(PCWSTR pszFirst, PCWSTR pszSrch);
  LWSTDAPI_(PWSTR)   StrStrNW(PCWSTR pszFirst, PCWSTR pszSrch, UINT cchMax);
  LWSTDAPI_(PWSTR)   StrStrNIW(PCWSTR pszFirst, PCWSTR pszSrch, UINT cchMax);
#endif
#define StrStr  __MINGW_NAME_AW(StrStr)
#define StrStrI __MINGW_NAME_AW(StrStrI)

#define STIF_DEFAULT     0x00000000L
#define STIF_SUPPORT_HEX 0x00000001L

  typedef int STIF_FLAGS;

  LWSTDAPI_(int)     StrToIntA(PCSTR pszSrc);
  LWSTDAPI_(int)     StrToIntW(PCWSTR pszSrc);
#define StrToInt  __MINGW_NAME_AW(StrToInt)
#define StrToLong   StrToInt
  LWSTDAPI_(WINBOOL) StrToIntExA(PCSTR pszString, STIF_FLAGS dwFlags, int *piRet);
  LWSTDAPI_(WINBOOL) StrToIntExW(PCWSTR pszString, STIF_FLAGS dwFlags, int *piRet);
#define StrToIntEx __MINGW_NAME_AW(StrToIntEx)
  LWSTDAPI_(WINBOOL) StrToInt64ExA(PCSTR pszString, STIF_FLAGS dwFlags, LONGLONG *pllRet);
  LWSTDAPI_(WINBOOL) StrToInt64ExW(PCWSTR pszString, STIF_FLAGS dwFlags, LONGLONG *pllRet);
#define StrToInt64Ex __MINGW_NAME_AW(StrToInt64Ex)
  LWSTDAPI_(WINBOOL) StrTrimA(PSTR psz, PCSTR pszTrimChars);
  LWSTDAPI_(WINBOOL) StrTrimW(PWSTR psz, PCWSTR pszTrimChars);
#define StrTrim __MINGW_NAME_AW(StrTrim)
#define StrCatA lstrcatA
  LWSTDAPI_(PWSTR)   StrCatW(PWSTR psz1, PCWSTR psz2);
#define StrCat __MINGW_NAME_AW(StrCat)
#define StrCmpA lstrcmpA
  LWSTDAPI_(int)     StrCmpW(PCWSTR psz1, PCWSTR psz2);
#define StrCmp __MINGW_NAME_AW(StrCmp)
#define StrCmpIA lstrcmpiA
  LWSTDAPI_(int)     StrCmpIW(PCWSTR psz1, PCWSTR psz2);
#define StrCmpI __MINGW_NAME_AW(StrCmpI)
#define StrCpyA lstrcpyA
  LWSTDAPI_(PWSTR)   StrCpyW(PWSTR psz1, PCWSTR psz2);
#define StrCpy __MINGW_NAME_AW(StrCpy)
#define StrCpyNA lstrcpynA
  LWSTDAPI_(PWSTR)   StrCpyNW(PWSTR pszDst, PCWSTR pszSrc, int cchMax);
#define StrCpyN __MINGW_NAME_AW(StrCpyN)
#define StrNCpy   StrCpyN
  LWSTDAPI_(PSTR)    StrCatBuffA(PSTR pszDest, PCSTR pszSrc, int cchDestBuffSize);
  LWSTDAPI_(PWSTR)   StrCatBuffW(PWSTR pszDest, PCWSTR pszSrc, int cchDestBuffSize);
#define StrCatBuff __MINGW_NAME_AW(StrCatBuff)
  LWSTDAPI_(WINBOOL) ChrCmpIA(WORD w1, WORD w2);
  LWSTDAPI_(WINBOOL) ChrCmpIW(WCHAR w1, WCHAR w2);
#define ChrCmpI __MINGW_NAME_AW(ChrCmpI)
  LWSTDAPI_(int)     wvnsprintfA(PSTR pszDest, int cchDest, PCSTR pszFmt, va_list arglist);
  LWSTDAPI_(int)     wvnsprintfW(PWSTR pszDest, int cchDest, PCWSTR pszFmt, va_list arglist);
#define wvnsprintf __MINGW_NAME_AW(wvnsprintf)
  LWSTDAPIV_(int)    wnsprintfA(PSTR pszDest, int cchDest, PCSTR pszFmt, ...);
  LWSTDAPIV_(int)    wnsprintfW(PWSTR pszDest, int cchDest, PCWSTR pszFmt, ...);
#define wnsprintf __MINGW_NAME_AW(wnsprintf)

#define StrIntlEqNA( s1, s2, nChar)   StrIsIntlEqualA( TRUE, s1, s2, nChar)
#define StrIntlEqNW( s1, s2, nChar)   StrIsIntlEqualW( TRUE, s1, s2, nChar)
#define StrIntlEqN                  __MINGW_NAME_AW(StrIntlEqN)
#define StrIntlEqNIA(s1, s2, nChar)   StrIsIntlEqualA(FALSE, s1, s2, nChar)
#define StrIntlEqNIW(s1, s2, nChar)   StrIsIntlEqualW(FALSE, s1, s2, nChar)
#define StrIntlEqNI                 __MINGW_NAME_AW(StrIntlEqNI)

  LWSTDAPI StrRetToStrA(STRRET *pstr, PCUITEMID_CHILD pidl, LPSTR *ppsz);
  LWSTDAPI StrRetToStrW(STRRET *pstr, PCUITEMID_CHILD pidl, LPWSTR *ppsz);
#define StrRetToStr __MINGW_NAME_AW(StrRetToStr)
  LWSTDAPI StrRetToBufA(STRRET *pstr, PCUITEMID_CHILD pidl, LPSTR pszBuf, UINT cchBuf);
  LWSTDAPI StrRetToBufW(STRRET *pstr, PCUITEMID_CHILD pidl, LPWSTR pszBuf, UINT cchBuf);
#define StrRetToBuf __MINGW_NAME_AW(StrRetToBuf)
  LWSTDAPI SHStrDupA(LPCSTR psz, LPWSTR *ppwsz);
  LWSTDAPI SHStrDupW(LPCWSTR psz, LPWSTR *ppwsz);
#define SHStrDup __MINGW_NAME_AW(SHStrDup)

#ifdef __cplusplus
  inline HRESULT SHLocalStrDupA(PCSTR psz, PSTR *ppsz)
  {
    *ppsz = StrDupA(psz);
    return *ppsz ? S_OK : E_OUTOFMEMORY;
  }

  inline HRESULT SHLocalStrDupW(PCWSTR psz, PWSTR *ppsz)
  {
    *ppsz = StrDupW(psz);
    return *ppsz ? S_OK : E_OUTOFMEMORY;
  }

#define SHLocalStrDup __MINGW_NAME_AW(SHLocalStrDup)
#endif

  LWSTDAPI_(int)     StrCmpLogicalW(PCWSTR psz1, PCWSTR psz2);
  LWSTDAPI_(DWORD)   StrCatChainW(PWSTR pszDst, DWORD cchDst, DWORD ichAt, PCWSTR pszSrc);
  LWSTDAPI           StrRetToBSTR(STRRET *pstr, PCUITEMID_CHILD pidl, BSTR *pbstr);
  LWSTDAPI_(WINBOOL) IsCharSpaceA(CHAR wch);
  LWSTDAPI_(WINBOOL) IsCharSpaceW(WCHAR wch);
#define IsCharSpace __MINGW_NAME_AW(IsCharSpace)
  LWSTDAPI_(int)     StrCmpCA(LPCSTR pszStr1, LPCSTR pszStr2);
  LWSTDAPI_(int)     StrCmpCW(LPCWSTR pszStr1, LPCWSTR pszStr2);
#define StrCmpC __MINGW_NAME_AW(StrCmpC)
  LWSTDAPI_(int)     StrCmpICA(LPCSTR pszStr1, LPCSTR pszStr2);
  LWSTDAPI_(int)     StrCmpICW(LPCWSTR pszStr1, LPCWSTR pszStr2);
#define StrCmpIC __MINGW_NAME_AW(StrCmpIC)
  LWSTDAPI_(int)     StrCmpNCA(LPCSTR pszStr1, LPCSTR pszStr2, int nChar);
  LWSTDAPI_(int)     StrCmpNCW(LPCWSTR pszStr1, LPCWSTR pszStr2, int nChar);
#define StrCmpNC __MINGW_NAME_AW(StrCmpNC)
  LWSTDAPI_(int)     StrCmpNICA(LPCSTR pszStr1, LPCSTR pszStr2, int nChar);
  LWSTDAPI_(int)     StrCmpNICW(LPCWSTR pszStr1, LPCWSTR pszStr2, int nChar);
#define StrCmpNIC __MINGW_NAME_AW(StrCmpNIC)
  LWSTDAPI_(WINBOOL) IntlStrEqWorkerA(WINBOOL fCaseSens, LPCSTR lpString1, LPCSTR lpString2, int nChar);
  LWSTDAPI_(WINBOOL) IntlStrEqWorkerW(WINBOOL fCaseSens, LPCWSTR lpString1, LPCWSTR lpString2, int nChar);

#define IntlStrEqNA( s1, s2, nChar)   IntlStrEqWorkerA( TRUE, s1, s2, nChar)
#define IntlStrEqNW( s1, s2, nChar)   IntlStrEqWorkerW( TRUE, s1, s2, nChar)
#define IntlStrEqN                  __MINGW_NAME_AW(IntlStrEqN)
#define IntlStrEqNIA(s1, s2, nChar)   IntlStrEqWorkerA(FALSE, s1, s2, nChar)
#define IntlStrEqNIW(s1, s2, nChar)   IntlStrEqWorkerW(FALSE, s1, s2, nChar)
#define IntlStrEqNI                 __MINGW_NAME_AW(IntlStrEqNI)

#define SZ_CONTENTTYPE_HTMLA  "text/html"
#define SZ_CONTENTTYPE_HTMLW L"text/html"
#define SZ_CONTENTTYPE_HTML  __MINGW_NAME_AW(SZ_CONTENTTYPE_HTML)
#define SZ_CONTENTTYPE_CDFA   "application/x-cdf"
#define SZ_CONTENTTYPE_CDFW  L"application/x-cdf"
#define SZ_CONTENTTYPE_CDF   __MINGW_NAME_AW(SZ_CONTENTTYPE_CDF)

#define PathIsHTMLFileA(pszPath) PathIsContentTypeA(pszPath, SZ_CONTENTTYPE_HTMLA)
#define PathIsHTMLFileW(pszPath) PathIsContentTypeW(pszPath, SZ_CONTENTTYPE_HTMLW)
#define PathIsHTMLFile         __MINGW_NAME_AW(PathIsHTMLFile)

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  LWSTDAPI SHLoadIndirectString(PCWSTR pszSource, PWSTR pszOutBuf, UINT cchOutBuf, void **ppvReserved);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#endif  /* NO_SHLWAPI_STRFCNS */

#ifndef NO_SHLWAPI_PATH

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

  LWSTDAPI_(LPSTR)   PathAddBackslashA(LPSTR pszPath);
  LWSTDAPI_(LPWSTR)  PathAddBackslashW(LPWSTR pszPath);
#define PathAddBackslash __MINGW_NAME_AW(PathAddBackslash)
  LWSTDAPI_(WINBOOL) PathAddExtensionA(LPSTR pszPath, LPCSTR pszExt);
  LWSTDAPI_(WINBOOL) PathAddExtensionW(LPWSTR pszPath, LPCWSTR pszExt);
#define PathAddExtension __MINGW_NAME_AW(PathAddExtension)
  LWSTDAPI_(WINBOOL) PathAppendA(LPSTR pszPath, LPCSTR pMore);
  LWSTDAPI_(WINBOOL) PathAppendW(LPWSTR pszPath, LPCWSTR pMore);
#define PathAppend __MINGW_NAME_AW(PathAppend)
  LWSTDAPI_(LPSTR)   PathBuildRootA(LPSTR pszRoot, int iDrive);
  LWSTDAPI_(LPWSTR)  PathBuildRootW(LPWSTR pszRoot, int iDrive);
#define PathBuildRoot __MINGW_NAME_AW(PathBuildRoot)
  LWSTDAPI_(WINBOOL) PathCanonicalizeA(LPSTR pszBuf, LPCSTR pszPath);
  LWSTDAPI_(WINBOOL) PathCanonicalizeW(LPWSTR pszBuf, LPCWSTR pszPath);
#define PathCanonicalize __MINGW_NAME_AW(PathCanonicalize)
  LWSTDAPI_(LPSTR)   PathCombineA(LPSTR pszDest, LPCSTR pszDir, LPCSTR pszFile);
  LWSTDAPI_(LPWSTR)  PathCombineW(LPWSTR pszDest, LPCWSTR pszDir, LPCWSTR pszFile);
#define PathCombine __MINGW_NAME_AW(PathCombine)
  LWSTDAPI_(WINBOOL) PathCompactPathA(HDC hDC, LPSTR pszPath, UINT dx);
  LWSTDAPI_(WINBOOL) PathCompactPathW(HDC hDC, LPWSTR pszPath, UINT dx);
#define PathCompactPath __MINGW_NAME_AW(PathCompactPath)
  LWSTDAPI_(WINBOOL) PathCompactPathExA(LPSTR pszOut, LPCSTR pszSrc, UINT cchMax, DWORD dwFlags);
  LWSTDAPI_(WINBOOL) PathCompactPathExW(LPWSTR pszOut, LPCWSTR pszSrc, UINT cchMax, DWORD dwFlags);
#define PathCompactPathEx __MINGW_NAME_AW(PathCompactPathEx)
  LWSTDAPI_(int)     PathCommonPrefixA(LPCSTR pszFile1, LPCSTR pszFile2, LPSTR achPath);
  LWSTDAPI_(int)     PathCommonPrefixW(LPCWSTR pszFile1, LPCWSTR pszFile2, LPWSTR achPath);
#define PathCommonPrefix __MINGW_NAME_AW(PathCommonPrefix)
  LWSTDAPI_(WINBOOL) PathFileExistsA(LPCSTR pszPath);
  LWSTDAPI_(WINBOOL) PathFileExistsW(LPCWSTR pszPath);
#define PathFileExists __MINGW_NAME_AW(PathFileExists)

#ifdef USE_STRICT_CONST
  LWSTDAPI_(LPCSTR)  PathFindExtensionA(LPCSTR pszPath);
  LWSTDAPI_(LPCWSTR) PathFindExtensionW(LPCWSTR pszPath);
  LWSTDAPI_(LPCSTR)  PathFindFileNameA(LPCSTR pszPath);
  LWSTDAPI_(LPCWSTR) PathFindFileNameW(LPCWSTR pszPath);
  LWSTDAPI_(LPCSTR)  PathFindNextComponentA(LPCSTR pszPath);
  LWSTDAPI_(LPCWSTR) PathFindNextComponentW(LPCWSTR pszPath);
  LWSTDAPI_(LPCSTR)  PathGetArgsA(LPCSTR pszPath);
  LWSTDAPI_(LPCWSTR) PathGetArgsW(LPCWSTR pszPath);
#else
  LWSTDAPI_(LPSTR)   PathFindExtensionA(LPCSTR pszPath);
  LWSTDAPI_(LPWSTR)  PathFindExtensionW(LPCWSTR pszPath);
  LWSTDAPI_(LPSTR)   PathFindFileNameA(LPCSTR pszPath);
  LWSTDAPI_(LPWSTR)  PathFindFileNameW(LPCWSTR pszPath);
  LWSTDAPI_(LPSTR)   PathFindNextComponentA(LPCSTR pszPath);
  LWSTDAPI_(LPWSTR)  PathFindNextComponentW(LPCWSTR pszPath);
  LWSTDAPI_(LPSTR)   PathGetArgsA(LPCSTR pszPath);
  LWSTDAPI_(LPWSTR)  PathGetArgsW(LPCWSTR pszPath);
#endif
#define PathFindExtension     __MINGW_NAME_AW(PathFindExtension)
#define PathFindFileName      __MINGW_NAME_AW(PathFindFileName)
#define PathFindNextComponent __MINGW_NAME_AW(PathFindNextComponent)
#define PathGetArgs           __MINGW_NAME_AW(PathGetArgs)
  LWSTDAPI_(WINBOOL) PathFindOnPathA(LPSTR pszPath, LPCSTR *ppszOtherDirs);
  LWSTDAPI_(WINBOOL) PathFindOnPathW(LPWSTR pszPath, LPCWSTR *ppszOtherDirs);
#define PathFindOnPath __MINGW_NAME_AW(PathFindOnPath)
  LWSTDAPI_(LPCSTR)  PathFindSuffixArrayA(LPCSTR pszPath, const LPCSTR *apszSuffix, int iArraySize);
  LWSTDAPI_(LPCWSTR) PathFindSuffixArrayW(LPCWSTR pszPath, const LPCWSTR *apszSuffix, int iArraySize);
#define PathFindSuffixArray __MINGW_NAME_AW(PathFindSuffixArray)
  LWSTDAPI_(WINBOOL) PathIsLFNFileSpecA(LPCSTR lpName);
  LWSTDAPI_(WINBOOL) PathIsLFNFileSpecW(LPCWSTR lpName);
#define PathIsLFNFileSpec __MINGW_NAME_AW(PathIsLFNFileSpec)
  LWSTDAPI_(UINT)    PathGetCharTypeA(UCHAR ch);
  LWSTDAPI_(UINT)    PathGetCharTypeW(WCHAR ch);
#define PathGetCharType __MINGW_NAME_AW(PathGetCharType)

#define GCT_INVALID   0x0000
#define GCT_LFNCHAR   0x0001
#define GCT_SHORTCHAR 0x0002
#define GCT_WILD      0x0004
#define GCT_SEPARATOR 0x0008

  LWSTDAPI_(int)     PathGetDriveNumberA(LPCSTR pszPath);
  LWSTDAPI_(int)     PathGetDriveNumberW(LPCWSTR pszPath);
#define PathGetDriveNumber __MINGW_NAME_AW(PathGetDriveNumber)
  LWSTDAPI_(WINBOOL) PathIsDirectoryA(LPCSTR pszPath);
  LWSTDAPI_(WINBOOL) PathIsDirectoryW(LPCWSTR pszPath);
#define PathIsDirectory __MINGW_NAME_AW(PathIsDirectory)
  LWSTDAPI_(WINBOOL) PathIsDirectoryEmptyA(LPCSTR pszPath);
  LWSTDAPI_(WINBOOL) PathIsDirectoryEmptyW(LPCWSTR pszPath);
#define PathIsDirectoryEmpty __MINGW_NAME_AW(PathIsDirectoryEmpty)
  LWSTDAPI_(WINBOOL) PathIsFileSpecA(LPCSTR pszPath);
  LWSTDAPI_(WINBOOL) PathIsFileSpecW(LPCWSTR pszPath);
#define PathIsFileSpec __MINGW_NAME_AW(PathIsFileSpec)
  LWSTDAPI_(WINBOOL) PathIsPrefixA(LPCSTR pszPrefix, LPCSTR pszPath);
  LWSTDAPI_(WINBOOL) PathIsPrefixW(LPCWSTR pszPrefix, LPCWSTR pszPath);
#define PathIsPrefix __MINGW_NAME_AW(PathIsPrefix)
  LWSTDAPI_(WINBOOL) PathIsRelativeA(LPCSTR pszPath);
  LWSTDAPI_(WINBOOL) PathIsRelativeW(LPCWSTR pszPath);
#define PathIsRelative __MINGW_NAME_AW(PathIsRelative)
  LWSTDAPI_(WINBOOL) PathIsRootA(LPCSTR pszPath);
  LWSTDAPI_(WINBOOL) PathIsRootW(LPCWSTR pszPath);
#define PathIsRoot __MINGW_NAME_AW(PathIsRoot)
  LWSTDAPI_(WINBOOL) PathIsSameRootA(LPCSTR pszPath1, LPCSTR pszPath2);
  LWSTDAPI_(WINBOOL) PathIsSameRootW(LPCWSTR pszPath1, LPCWSTR pszPath2);
#define PathIsSameRoot __MINGW_NAME_AW(PathIsSameRoot)
  LWSTDAPI_(WINBOOL) PathIsUNCA(LPCSTR pszPath);
  LWSTDAPI_(WINBOOL) PathIsUNCW(LPCWSTR pszPath);
#define PathIsUNC __MINGW_NAME_AW(PathIsUNC)
  LWSTDAPI_(WINBOOL) PathIsNetworkPathA(LPCSTR pszPath);
  LWSTDAPI_(WINBOOL) PathIsNetworkPathW(LPCWSTR pszPath);
#define PathIsNetworkPath __MINGW_NAME_AW(PathIsNetworkPath)
  LWSTDAPI_(WINBOOL) PathIsUNCServerA(LPCSTR pszPath);
  LWSTDAPI_(WINBOOL) PathIsUNCServerW(LPCWSTR pszPath);
#define PathIsUNCServer __MINGW_NAME_AW(PathIsUNCServer)
  LWSTDAPI_(WINBOOL) PathIsUNCServerShareA(LPCSTR pszPath);
  LWSTDAPI_(WINBOOL) PathIsUNCServerShareW(LPCWSTR pszPath);
#define PathIsUNCServerShare __MINGW_NAME_AW(PathIsUNCServerShare)
  LWSTDAPI_(WINBOOL) PathIsContentTypeA(LPCSTR pszPath, LPCSTR pszContentType);
  LWSTDAPI_(WINBOOL) PathIsContentTypeW(LPCWSTR pszPath, LPCWSTR pszContentType);
#define PathIsContentType __MINGW_NAME_AW(PathIsContentType)
  LWSTDAPI_(WINBOOL) PathIsURLA(LPCSTR pszPath);
  LWSTDAPI_(WINBOOL) PathIsURLW(LPCWSTR pszPath);
#define PathIsURL __MINGW_NAME_AW(PathIsURL)
  LWSTDAPI_(WINBOOL) PathMakePrettyA(LPSTR pszPath);
  LWSTDAPI_(WINBOOL) PathMakePrettyW(LPWSTR pszPath);
#define PathMakePretty __MINGW_NAME_AW(PathMakePretty)
  LWSTDAPI_(WINBOOL) PathMatchSpecA(LPCSTR pszFile, LPCSTR pszSpec);
  LWSTDAPI_(WINBOOL) PathMatchSpecW(LPCWSTR pszFile, LPCWSTR pszSpec);
#define PathMatchSpec __MINGW_NAME_AW(PathMatchSpec)

#define PMSF_NORMAL            0x00000000
#define PMSF_MULTIPLE          0x00000001
#define PMSF_DONT_STRIP_SPACES 0x00010000
  LWSTDAPI           PathMatchSpecExA(LPCSTR pszFile, LPCSTR pszSpec, DWORD dwFlags);
  LWSTDAPI           PathMatchSpecExW(LPCWSTR pszFile, LPCWSTR pszSpec, DWORD dwFlags);
#define PathMatchSpecEx __MINGW_NAME_AW(PathMatchSpecEx)
  LWSTDAPI_(int)     PathParseIconLocationA(LPSTR pszIconFile);
  LWSTDAPI_(int)     PathParseIconLocationW(LPWSTR pszIconFile);
#define PathParseIconLocation __MINGW_NAME_AW(PathParseIconLocation)
  LWSTDAPI_(WINBOOL) PathQuoteSpacesA(LPSTR lpsz);
  LWSTDAPI_(WINBOOL) PathQuoteSpacesW(LPWSTR lpsz);
#define PathQuoteSpaces __MINGW_NAME_AW(PathQuoteSpaces)
  LWSTDAPI_(WINBOOL) PathRelativePathToA(LPSTR pszPath, LPCSTR pszFrom, DWORD dwAttrFrom, LPCSTR pszTo, DWORD dwAttrTo);
  LWSTDAPI_(WINBOOL) PathRelativePathToW(LPWSTR pszPath, LPCWSTR pszFrom, DWORD dwAttrFrom, LPCWSTR pszTo, DWORD dwAttrTo);
#define PathRelativePathTo __MINGW_NAME_AW(PathRelativePathTo)
  LWSTDAPI_(void)    PathRemoveArgsA(LPSTR pszPath);
  LWSTDAPI_(void)    PathRemoveArgsW(LPWSTR pszPath);
#define PathRemoveArgs __MINGW_NAME_AW(PathRemoveArgs)
  LWSTDAPI_(LPSTR)   PathRemoveBackslashA(LPSTR pszPath);
  LWSTDAPI_(LPWSTR)  PathRemoveBackslashW(LPWSTR pszPath);
#define PathRemoveBackslash __MINGW_NAME_AW(PathRemoveBackslash)
  LWSTDAPI_(void)    PathRemoveBlanksA(LPSTR pszPath);
  LWSTDAPI_(void)    PathRemoveBlanksW(LPWSTR pszPath);
#define PathRemoveBlanks __MINGW_NAME_AW(PathRemoveBlanks)
  LWSTDAPI_(void)    PathRemoveExtensionA(LPSTR pszPath);
  LWSTDAPI_(void)    PathRemoveExtensionW(LPWSTR pszPath);
#define PathRemoveExtension __MINGW_NAME_AW(PathRemoveExtension)
  LWSTDAPI_(WINBOOL) PathRemoveFileSpecA(LPSTR pszPath);
  LWSTDAPI_(WINBOOL) PathRemoveFileSpecW(LPWSTR pszPath);
#define PathRemoveFileSpec __MINGW_NAME_AW(PathRemoveFileSpec)
  LWSTDAPI_(WINBOOL) PathRenameExtensionA(LPSTR pszPath, LPCSTR pszExt);
  LWSTDAPI_(WINBOOL) PathRenameExtensionW(LPWSTR pszPath, LPCWSTR pszExt);
#define PathRenameExtension __MINGW_NAME_AW(PathRenameExtension)
  LWSTDAPI_(WINBOOL) PathSearchAndQualifyA(LPCSTR pszPath, LPSTR pszBuf, UINT cchBuf);
  LWSTDAPI_(WINBOOL) PathSearchAndQualifyW(LPCWSTR pszPath, LPWSTR pszBuf, UINT cchBuf);
#define PathSearchAndQualify __MINGW_NAME_AW(PathSearchAndQualify)
  LWSTDAPI_(void)    PathSetDlgItemPathA(HWND hDlg, int id, LPCSTR pszPath);
  LWSTDAPI_(void)    PathSetDlgItemPathW(HWND hDlg, int id, LPCWSTR pszPath);
#define PathSetDlgItemPath __MINGW_NAME_AW(PathSetDlgItemPath)

#ifdef USE_STRICT_CONST
  LWSTDAPI_(LPCSTR)  PathSkipRootA(LPCSTR pszPath);
  LWSTDAPI_(LPCWSTR) PathSkipRootW(LPCWSTR pszPath);
#else
  LWSTDAPI_(LPSTR)   PathSkipRootA(LPCSTR pszPath);
  LWSTDAPI_(LPWSTR)  PathSkipRootW(LPCWSTR pszPath);
#endif
#define PathSkipRoot __MINGW_NAME_AW(PathSkipRoot)
  LWSTDAPI_(void)    PathStripPathA(LPSTR pszPath);
  LWSTDAPI_(void)    PathStripPathW(LPWSTR pszPath);
#define PathStripPath __MINGW_NAME_AW(PathStripPath)
  LWSTDAPI_(WINBOOL) PathStripToRootA(LPSTR pszPath);
  LWSTDAPI_(WINBOOL) PathStripToRootW(LPWSTR pszPath);
#define PathStripToRoot __MINGW_NAME_AW(PathStripToRoot)
  LWSTDAPI_(WINBOOL) PathUnquoteSpacesA(LPSTR lpsz);
  LWSTDAPI_(WINBOOL) PathUnquoteSpacesW(LPWSTR lpsz);
#define PathUnquoteSpaces __MINGW_NAME_AW(PathUnquoteSpaces)
  LWSTDAPI_(WINBOOL) PathMakeSystemFolderA(LPCSTR pszPath);
  LWSTDAPI_(WINBOOL) PathMakeSystemFolderW(LPCWSTR pszPath);
#define PathMakeSystemFolder __MINGW_NAME_AW(PathMakeSystemFolder)
  LWSTDAPI_(WINBOOL) PathUnmakeSystemFolderA(LPCSTR pszPath);
  LWSTDAPI_(WINBOOL) PathUnmakeSystemFolderW(LPCWSTR pszPath);
#define PathUnmakeSystemFolder __MINGW_NAME_AW(PathUnmakeSystemFolder)
  LWSTDAPI_(WINBOOL) PathIsSystemFolderA(LPCSTR pszPath, DWORD dwAttrb);
  LWSTDAPI_(WINBOOL) PathIsSystemFolderW(LPCWSTR pszPath, DWORD dwAttrb);
#define PathIsSystemFolder __MINGW_NAME_AW(PathIsSystemFolder)
  LWSTDAPI_(void)    PathUndecorateA(LPSTR pszPath);
  LWSTDAPI_(void)    PathUndecorateW(LPWSTR pszPath);
#define PathUndecorate __MINGW_NAME_AW(PathUndecorate)
  LWSTDAPI_(WINBOOL) PathUnExpandEnvStringsA(LPCSTR pszPath, LPSTR pszBuf, UINT cchBuf);
  LWSTDAPI_(WINBOOL) PathUnExpandEnvStringsW(LPCWSTR pszPath, LPWSTR pszBuf, UINT cchBuf);
#define PathUnExpandEnvStrings __MINGW_NAME_AW(PathUnExpandEnvStrings)

  typedef enum
  {
    URL_SCHEME_INVALID = -1,
    URL_SCHEME_UNKNOWN = 0,
    URL_SCHEME_FTP,
    URL_SCHEME_HTTP,
    URL_SCHEME_GOPHER,
    URL_SCHEME_MAILTO,
    URL_SCHEME_NEWS,
    URL_SCHEME_NNTP,
    URL_SCHEME_TELNET,
    URL_SCHEME_WAIS,
    URL_SCHEME_FILE,
    URL_SCHEME_MK,
    URL_SCHEME_HTTPS,
    URL_SCHEME_SHELL,
    URL_SCHEME_SNEWS,
    URL_SCHEME_LOCAL,
    URL_SCHEME_JAVASCRIPT,
    URL_SCHEME_VBSCRIPT,
    URL_SCHEME_ABOUT,
    URL_SCHEME_RES,
    URL_SCHEME_MSSHELLROOTED,
    URL_SCHEME_MSSHELLIDLIST,
    URL_SCHEME_MSHELP,
    URL_SCHEME_MSSHELLDEVICE,
    URL_SCHEME_WILDCARD,
    URL_SCHEME_SEARCH_MS,
    URL_SCHEME_SEARCH,
    URL_SCHEME_KNOWNFOLDER,
    URL_SCHEME_MAXVALUE
  } URL_SCHEME;

  typedef enum
  {
    URL_PART_NONE   = 0,
    URL_PART_SCHEME = 1,
    URL_PART_HOSTNAME,
    URL_PART_USERNAME,
    URL_PART_PASSWORD,
    URL_PART_PORT,
    URL_PART_QUERY,
  } URL_PART;

  typedef enum
  {
    URLIS_URL,
    URLIS_OPAQUE,
    URLIS_NOHISTORY,
    URLIS_FILEURL,
    URLIS_APPLIABLE,
    URLIS_DIRECTORY,
    URLIS_HASQUERY,
  } URLIS;

#define URL_UNESCAPE                   0x10000000
#define URL_ESCAPE_UNSAFE              0x20000000
#define URL_PLUGGABLE_PROTOCOL         0x40000000
#define URL_WININET_COMPATIBILITY      0x80000000
#define URL_DONT_ESCAPE_EXTRA_INFO     0x02000000
#define URL_DONT_UNESCAPE_EXTRA_INFO   URL_DONT_ESCAPE_EXTRA_INFO
#define URL_BROWSER_MODE               URL_DONT_ESCAPE_EXTRA_INFO
#define URL_ESCAPE_SPACES_ONLY         0x04000000
#define URL_DONT_SIMPLIFY              0x08000000
#define URL_NO_META                    URL_DONT_SIMPLIFY
#define URL_UNESCAPE_INPLACE           0x00100000
#define URL_CONVERT_IF_DOSPATH         0x00200000
#define URL_UNESCAPE_HIGH_ANSI_ONLY    0x00400000
#define URL_INTERNAL_PATH              0x00800000
#define URL_FILE_USE_PATHURL           0x00010000
#define URL_DONT_UNESCAPE              0x00020000
#define URL_ESCAPE_AS_UTF8             0x00040000
#define URL_UNESCAPE_AS_UTF8           URL_ESCAPE_AS_UTF8
#define URL_ESCAPE_ASCII_URI_COMPONENT 0x00080000
#define URL_ESCAPE_URI_COMPONENT       (URL_ESCAPE_ASCII_URI_COMPONENT | URL_ESCAPE_AS_UTF8)
#define URL_UNESCAPE_URI_COMPONENT     URL_UNESCAPE_AS_UTF8
#define URL_ESCAPE_PERCENT             0x00001000
#define URL_ESCAPE_SEGMENT_ONLY        0x00002000
#define URL_PARTFLAG_KEEPSCHEME        0x00000001
#define URL_APPLY_DEFAULT              0x00000001
#define URL_APPLY_GUESSSCHEME          0x00000002
#define URL_APPLY_GUESSFILE            0x00000004
#define URL_APPLY_FORCEAPPLY           0x00000008

  LWSTDAPI_(int)     UrlCompareA(PCSTR psz1, PCSTR psz2, WINBOOL fIgnoreSlash);
  LWSTDAPI_(int)     UrlCompareW(PCWSTR psz1, PCWSTR psz2, WINBOOL fIgnoreSlash);
#define UrlCompare __MINGW_NAME_AW(UrlCompare)
  LWSTDAPI           UrlCombineA(PCSTR pszBase, PCSTR pszRelative, PSTR pszCombined, DWORD *pcchCombined, DWORD dwFlags);
  LWSTDAPI           UrlCombineW(PCWSTR pszBase, PCWSTR pszRelative, PWSTR pszCombined, DWORD *pcchCombined, DWORD dwFlags);
#define UrlCombine __MINGW_NAME_AW(UrlCombine)
  LWSTDAPI           UrlCanonicalizeA(PCSTR pszUrl, PSTR pszCanonicalized, DWORD *pcchCanonicalized, DWORD dwFlags);
  LWSTDAPI           UrlCanonicalizeW(PCWSTR pszUrl, PWSTR pszCanonicalized, DWORD *pcchCanonicalized, DWORD dwFlags);
#define UrlCanonicalize __MINGW_NAME_AW(UrlCanonicalize)
  LWSTDAPI_(WINBOOL) UrlIsOpaqueA(PCSTR pszURL);
  LWSTDAPI_(WINBOOL) UrlIsOpaqueW(PCWSTR pszURL);
#define UrlIsOpaque __MINGW_NAME_AW(UrlIsOpaque)
  LWSTDAPI_(WINBOOL) UrlIsNoHistoryA(PCSTR pszURL);
  LWSTDAPI_(WINBOOL) UrlIsNoHistoryW(PCWSTR pszURL);
#define UrlIsFileUrlA(pszURL) UrlIsA(pszURL, URLIS_FILEURL)
#define UrlIsFileUrlW(pszURL) UrlIsW(pszURL, URLIS_FILEURL)
#define UrlIsFileUrl        __MINGW_NAME_AW(UrlIsFileUrl)
  LWSTDAPI_(WINBOOL) UrlIsA(PCSTR pszUrl, URLIS UrlIs);
  LWSTDAPI_(WINBOOL) UrlIsW(PCWSTR pszUrl, URLIS UrlIs);
#define UrlIs __MINGW_NAME_AW(UrlIs)
  LWSTDAPI_(LPCSTR)  UrlGetLocationA(PCSTR pszURL);
  LWSTDAPI_(LPCWSTR) UrlGetLocationW(PCWSTR pszURL);
#define UrlGetLocation __MINGW_NAME_AW(UrlGetLocation)
  LWSTDAPI           UrlUnescapeA(PSTR pszUrl, PSTR pszUnescaped, DWORD *pcchUnescaped, DWORD dwFlags);
  LWSTDAPI           UrlUnescapeW(PWSTR pszUrl, PWSTR pszUnescaped, DWORD *pcchUnescaped, DWORD dwFlags);
#define UrlUnescape __MINGW_NAME_AW(UrlUnescape)
  LWSTDAPI           UrlEscapeA(PCSTR pszUrl, PSTR pszEscaped, DWORD *pcchEscaped, DWORD dwFlags);
  LWSTDAPI           UrlEscapeW(PCWSTR pszUrl, PWSTR pszEscaped, DWORD *pcchEscaped, DWORD dwFlags);
#define UrlEscape __MINGW_NAME_AW(UrlEscape)
  LWSTDAPI           UrlCreateFromPathA(PCSTR pszPath, PSTR pszUrl, DWORD *pcchUrl, DWORD dwFlags);
  LWSTDAPI           UrlCreateFromPathW(PCWSTR pszPath, PWSTR pszUrl, DWORD *pcchUrl, DWORD dwFlags);
#define UrlCreateFromPath __MINGW_NAME_AW(UrlCreateFromPath)
  LWSTDAPI           PathCreateFromUrlA(PCSTR pszUrl, PSTR pszPath, DWORD *pcchPath, DWORD dwFlags);
  LWSTDAPI           PathCreateFromUrlW(PCWSTR pszUrl, PWSTR pszPath, DWORD *pcchPath, DWORD dwFlags);
#define PathCreateFromUrl __MINGW_NAME_AW(PathCreateFromUrl)
  LWSTDAPI           PathCreateFromUrlAlloc(PCWSTR pszIn, PWSTR *ppszOut, DWORD dwFlags);
  LWSTDAPI           UrlHashA(PCSTR pszUrl, BYTE *pbHash, DWORD cbHash);
  LWSTDAPI           UrlHashW(PCWSTR pszUrl, BYTE *pbHash, DWORD cbHash);
#define UrlHash __MINGW_NAME_AW(UrlHash)
  LWSTDAPI           UrlGetPartA(PCSTR pszIn, PSTR pszOut, DWORD *pcchOut, DWORD dwPart, DWORD dwFlags);
  LWSTDAPI           UrlGetPartW(PCWSTR pszIn, PWSTR pszOut, DWORD *pcchOut, DWORD dwPart, DWORD dwFlags);
#define UrlGetPart __MINGW_NAME_AW(UrlGetPart)
  LWSTDAPI           UrlApplySchemeA(PCSTR pszIn, PSTR pszOut, DWORD *pcchOut, DWORD dwFlags);
  LWSTDAPI           UrlApplySchemeW(PCWSTR pszIn, PWSTR pszOut, DWORD *pcchOut, DWORD dwFlags);
#define UrlApplyScheme __MINGW_NAME_AW(UrlApplyScheme)
  LWSTDAPI           HashData(BYTE *pbData, DWORD cbData, BYTE *pbHash, DWORD cbHash);
  LWSTDAPI           UrlFixupW(PCWSTR pcszUrl, PWSTR pszTranslatedUrl, DWORD cchMax);
#ifdef UNICODE
# define UrlFixup UrlFixupW
#endif

#define UrlEscapeSpaces(pszUrl, pszEscaped, pcchEscaped) UrlCanonicalize(pszUrl, pszEscaped, pcchEscaped, URL_ESCAPE_SPACES_ONLY | URL_DONT_ESCAPE_EXTRA_INFO)
#define UrlUnescapeInPlace(pszUrl, dwFlags)              UrlUnescape(pszUrl, NULL, NULL, dwFlags | URL_UNESCAPE_INPLACE)

  typedef struct tagPARSEDURLA
  {
    DWORD  cbSize;
    LPCSTR pszProtocol;
    UINT   cchProtocol;
    LPCSTR pszSuffix;
    UINT   cchSuffix;
    UINT   nScheme;
  } PARSEDURLA, *PPARSEDURLA;

  typedef struct tagPARSEDURLW
  {
    DWORD   cbSize;
    LPCWSTR pszProtocol;
    UINT    cchProtocol;
    LPCWSTR pszSuffix;
    UINT    cchSuffix;
    UINT    nScheme;
   } PARSEDURLW, *PPARSEDURLW;

  __MINGW_TYPEDEF_AW(PARSEDURL)
  __MINGW_TYPEDEF_AW(PPARSEDURL)

  LWSTDAPI ParseURLA(LPCSTR pcszURL, PARSEDURLA *ppu);
  LWSTDAPI ParseURLW(LPCWSTR pcszURL, PARSEDURLW *ppu);
#define ParseURL __MINGW_NAME_AW(ParseURL)

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */

#endif  /* NO_SHLWAPI_PATH */

#ifndef NO_SHLWAPI_REG

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

  LWSTDAPI_(LSTATUS) SHDeleteEmptyKeyA(HKEY hkey, LPCSTR pszSubKey);
  LWSTDAPI_(LSTATUS) SHDeleteEmptyKeyW(HKEY hkey, LPCWSTR pszSubKey);
#define SHDeleteEmptyKey __MINGW_NAME_AW(SHDeleteEmptyKey)
  LWSTDAPI_(LSTATUS) SHDeleteKeyA(HKEY hkey, LPCSTR pszSubKey);
  LWSTDAPI_(LSTATUS) SHDeleteKeyW(HKEY hkey, LPCWSTR pszSubKey);
#define SHDeleteKey __MINGW_NAME_AW(SHDeleteKey)
  LWSTDAPI_(HKEY)    SHRegDuplicateHKey(HKEY hkey);
  LWSTDAPI_(LSTATUS) SHDeleteValueA(HKEY hkey, LPCSTR pszSubKey, LPCSTR pszValue);
  LWSTDAPI_(LSTATUS) SHDeleteValueW(HKEY hkey, LPCWSTR pszSubKey, LPCWSTR pszValue);
#define SHDeleteValue __MINGW_NAME_AW(SHDeleteValue)
  LWSTDAPI_(LSTATUS) SHGetValueA(HKEY hkey, LPCSTR pszSubKey, LPCSTR pszValue, DWORD *pdwType, void *pvData, DWORD *pcbData);
  LWSTDAPI_(LSTATUS) SHGetValueW(HKEY hkey, LPCWSTR pszSubKey, LPCWSTR pszValue, DWORD *pdwType, void *pvData, DWORD *pcbData);
#define SHGetValue __MINGW_NAME_AW(SHGetValue)
  LWSTDAPI_(LSTATUS) SHSetValueA(HKEY hkey, LPCSTR pszSubKey, LPCSTR pszValue, DWORD dwType, LPCVOID pvData, DWORD cbData);
  LWSTDAPI_(LSTATUS) SHSetValueW(HKEY hkey, LPCWSTR pszSubKey, LPCWSTR pszValue, DWORD dwType, LPCVOID pvData, DWORD cbData);
#define SHSetValue __MINGW_NAME_AW(SHSetValue)

  typedef int SRRF;

#define SRRF_RT_REG_NONE      0x00000001
#define SRRF_RT_REG_SZ        0x00000002
#define SRRF_RT_REG_EXPAND_SZ 0x00000004
#define SRRF_RT_REG_BINARY    0x00000008
#define SRRF_RT_REG_DWORD     0x00000010
#define SRRF_RT_REG_MULTI_SZ  0x00000020
#define SRRF_RT_REG_QWORD     0x00000040
#define SRRF_RT_DWORD         (SRRF_RT_REG_BINARY | SRRF_RT_REG_DWORD)
#define SRRF_RT_QWORD         (SRRF_RT_REG_BINARY | SRRF_RT_REG_QWORD)
#define SRRF_RT_ANY           0x0000ffff
#define SRRF_RM_ANY           0x00000000
#define SRRF_RM_NORMAL        0x00010000
#define SRRF_RM_SAFE          0x00020000
#define SRRF_RM_SAFENETWORK   0x00040000
#define SRRF_NOEXPAND         0x10000000
#define SRRF_ZEROONFAILURE    0x20000000
#define SRRF_NOVIRT           0x40000000

  LWSTDAPI_(LSTATUS) SHRegGetValueA(HKEY hkey, LPCSTR pszSubKey, LPCSTR pszValue, SRRF dwFlags, DWORD *pdwType, void *pvData, DWORD *pcbData);
  LWSTDAPI_(LSTATUS) SHRegGetValueW(HKEY hkey, LPCWSTR pszSubKey, LPCWSTR pszValue, SRRF dwFlags, DWORD *pdwType, void *pvData, DWORD *pcbData);
#define SHRegGetValue __MINGW_NAME_AW(SHRegGetValue)
  LWSTDAPI_(LSTATUS) SHRegSetValue(HKEY hkey, LPCWSTR pszSubKey, LPCWSTR pszValue, SRRF srrfFlags, DWORD dwType, LPCVOID pvData, DWORD cbData);
  LWSTDAPI_(LSTATUS) SHRegGetValueFromHKCUHKLM(PCWSTR pwszKey, PCWSTR pwszValue, SRRF srrfFlags, DWORD *pdwType, void *pvData, DWORD *pcbData);
  STDAPI_(WINBOOL)   SHRegGetBoolValueFromHKCUHKLM(PCWSTR pszKey, PCWSTR pszValue, WINBOOL fDefault);
  LWSTDAPI_(LSTATUS) SHQueryValueExA(HKEY hkey, LPCSTR pszValue, DWORD *pdwReserved, DWORD *pdwType, void *pvData, DWORD *pcbData);
  LWSTDAPI_(LSTATUS) SHQueryValueExW(HKEY hkey, LPCWSTR pszValue, DWORD *pdwReserved, DWORD *pdwType, void *pvData, DWORD *pcbData);
#define SHQueryValueEx __MINGW_NAME_AW(SHQueryValueEx)
  LWSTDAPI_(LSTATUS) SHEnumKeyExA(HKEY hkey, DWORD dwIndex, LPSTR pszName, LPDWORD pcchName);
  LWSTDAPI_(LSTATUS) SHEnumKeyExW(HKEY hkey, DWORD dwIndex, LPWSTR pszName, LPDWORD pcchName);
#define SHEnumKeyEx __MINGW_NAME_AW(SHEnumKeyEx)
  LWSTDAPI_(LSTATUS) SHEnumValueA(HKEY hkey, DWORD dwIndex, PSTR pszValueName, LPDWORD pcchValueName, LPDWORD pdwType, void *pvData, LPDWORD pcbData);
  LWSTDAPI_(LSTATUS) SHEnumValueW(HKEY hkey, DWORD dwIndex, PWSTR pszValueName, LPDWORD pcchValueName, LPDWORD pdwType, void *pvData, LPDWORD pcbData);
#define SHEnumValue __MINGW_NAME_AW(SHEnumValue)
  LWSTDAPI_(LSTATUS) SHQueryInfoKeyA(HKEY hkey, LPDWORD pcSubKeys, LPDWORD pcchMaxSubKeyLen, LPDWORD pcValues, LPDWORD pcchMaxValueNameLen);
  LWSTDAPI_(LSTATUS) SHQueryInfoKeyW(HKEY hkey, LPDWORD pcSubKeys, LPDWORD pcchMaxSubKeyLen, LPDWORD pcValues, LPDWORD pcchMaxValueNameLen);
#define SHQueryInfoKey __MINGW_NAME_AW(SHQueryInfoKey)
  LWSTDAPI_(LSTATUS) SHCopyKeyA(HKEY hkeySrc, LPCSTR szSrcSubKey, HKEY hkeyDest, DWORD fReserved);
  LWSTDAPI_(LSTATUS) SHCopyKeyW(HKEY hkeySrc, LPCWSTR wszSrcSubKey, HKEY hkeyDest, DWORD fReserved);
#define SHCopyKey __MINGW_NAME_AW(SHCopyKey)
  LWSTDAPI_(LSTATUS) SHRegGetPathA(HKEY hKey, LPCSTR pcszSubKey, LPCSTR pcszValue, LPSTR pszPath, DWORD dwFlags);
  LWSTDAPI_(LSTATUS) SHRegGetPathW(HKEY hKey, LPCWSTR pcszSubKey, LPCWSTR pcszValue, LPWSTR pszPath, DWORD dwFlags);
#define SHRegGetPath __MINGW_NAME_AW(SHRegGetPath)
  LWSTDAPI_(LSTATUS) SHRegSetPathA(HKEY hKey, LPCSTR pcszSubKey, LPCSTR pcszValue, LPCSTR pcszPath, DWORD dwFlags);
  LWSTDAPI_(LSTATUS) SHRegSetPathW(HKEY hKey, LPCWSTR pcszSubKey, LPCWSTR pcszValue, LPCWSTR pcszPath, DWORD dwFlags);
#define SHRegSetPath __MINGW_NAME_AW(SHRegSetPath)

  typedef enum
  {
    SHREGDEL_DEFAULT = 0x00000000,
    SHREGDEL_HKCU    = 0x00000001,
    SHREGDEL_HKLM    = 0x00000010,
    SHREGDEL_BOTH    = 0x00000011,
  } SHREGDEL_FLAGS;

  typedef enum
  {
    SHREGENUM_DEFAULT = 0x00000000,
    SHREGENUM_HKCU    = 0x00000001,
    SHREGENUM_HKLM    = 0x00000010,
    SHREGENUM_BOTH    = 0x00000011,
  } SHREGENUM_FLAGS;

#define SHREGSET_HKCU       0x00000001
#define SHREGSET_FORCE_HKCU 0x00000002
#define SHREGSET_HKLM       0x00000004
#define SHREGSET_FORCE_HKLM 0x00000008
#define SHREGSET_DEFAULT    (SHREGSET_FORCE_HKCU | SHREGSET_HKLM)

  typedef HANDLE  HUSKEY;
  typedef HUSKEY *PHUSKEY;

  LWSTDAPI_(LSTATUS) SHRegCreateUSKeyA(LPCSTR pszPath, REGSAM samDesired, HUSKEY hRelativeUSKey, PHUSKEY phNewUSKey, DWORD dwFlags);
  LWSTDAPI_(LSTATUS) SHRegCreateUSKeyW(LPCWSTR pwzPath, REGSAM samDesired, HUSKEY hRelativeUSKey, PHUSKEY phNewUSKey, DWORD dwFlags);
#define SHRegCreateUSKey __MINGW_NAME_AW(SHRegCreateUSKey)
  LWSTDAPI_(LSTATUS) SHRegOpenUSKeyA(LPCSTR pszPath, REGSAM samDesired, HUSKEY hRelativeUSKey, PHUSKEY phNewUSKey, WINBOOL fIgnoreHKCU);
  LWSTDAPI_(LSTATUS) SHRegOpenUSKeyW(LPCWSTR pwzPath, REGSAM samDesired, HUSKEY hRelativeUSKey, PHUSKEY phNewUSKey, WINBOOL fIgnoreHKCU);
#define SHRegOpenUSKey __MINGW_NAME_AW(SHRegOpenUSKey)
  LWSTDAPI_(LSTATUS) SHRegQueryUSValueA(HUSKEY hUSKey, LPCSTR pszValue, LPDWORD pdwType, void *pvData, LPDWORD pcbData, WINBOOL fIgnoreHKCU, void *pvDefaultData, DWORD dwDefaultDataSize);
  LWSTDAPI_(LSTATUS) SHRegQueryUSValueW(HUSKEY hUSKey, LPCWSTR pwzValue, LPDWORD pdwType, void *pvData, LPDWORD pcbData, WINBOOL fIgnoreHKCU, void *pvDefaultData, DWORD dwDefaultDataSize);
#define SHRegQueryUSValue __MINGW_NAME_AW(SHRegQueryUSValue)
  LWSTDAPI_(LSTATUS) SHRegWriteUSValueA(HUSKEY hUSKey, LPCSTR pszValue, DWORD dwType, const void *pvData, DWORD cbData, DWORD dwFlags);
  LWSTDAPI_(LSTATUS) SHRegWriteUSValueW(HUSKEY hUSKey, LPCWSTR pwzValue, DWORD dwType, const void *pvData, DWORD cbData, DWORD dwFlags);
#define SHRegWriteUSValue __MINGW_NAME_AW(SHRegWriteUSValue)
  LWSTDAPI_(LSTATUS) SHRegDeleteUSValueA(HUSKEY hUSKey, LPCSTR pszValue, SHREGDEL_FLAGS delRegFlags);
  LWSTDAPI_(LSTATUS) SHRegDeleteUSValueW(HUSKEY hUSKey, LPCWSTR pwzValue, SHREGDEL_FLAGS delRegFlags);
#define SHRegDeleteUSValue __MINGW_NAME_AW(SHRegDeleteUSValue)
  LWSTDAPI_(LSTATUS) SHRegDeleteEmptyUSKeyA(HUSKEY hUSKey, LPCSTR pszSubKey, SHREGDEL_FLAGS delRegFlags);
  LWSTDAPI_(LSTATUS) SHRegDeleteEmptyUSKeyW(HUSKEY hUSKey, LPCWSTR pwzSubKey, SHREGDEL_FLAGS delRegFlags);
#define SHRegDeleteEmptyUSKey __MINGW_NAME_AW(SHRegDeleteEmptyUSKey)
  LWSTDAPI_(LSTATUS) SHRegEnumUSKeyA(HUSKEY hUSKey, DWORD dwIndex, LPSTR pszName, LPDWORD pcchName, SHREGENUM_FLAGS enumRegFlags);
  LWSTDAPI_(LSTATUS) SHRegEnumUSKeyW(HUSKEY hUSKey, DWORD dwIndex, LPWSTR pwzName, LPDWORD pcchName, SHREGENUM_FLAGS enumRegFlags);
#define SHRegEnumUSKey __MINGW_NAME_AW(SHRegEnumUSKey)
  LWSTDAPI_(LSTATUS) SHRegEnumUSValueA(HUSKEY hUSkey, DWORD dwIndex, LPSTR pszValueName, LPDWORD pcchValueName, LPDWORD pdwType, void *pvData, LPDWORD pcbData, SHREGENUM_FLAGS enumRegFlags);
  LWSTDAPI_(LSTATUS) SHRegEnumUSValueW(HUSKEY hUSkey, DWORD dwIndex, LPWSTR pszValueName, LPDWORD pcchValueName, LPDWORD pdwType, void *pvData, LPDWORD pcbData, SHREGENUM_FLAGS enumRegFlags);
#define SHRegEnumUSValue __MINGW_NAME_AW(SHRegEnumUSValue)
  LWSTDAPI_(LSTATUS) SHRegQueryInfoUSKeyA(HUSKEY hUSKey, LPDWORD pcSubKeys, LPDWORD pcchMaxSubKeyLen, LPDWORD pcValues, LPDWORD pcchMaxValueNameLen, SHREGENUM_FLAGS enumRegFlags);
  LWSTDAPI_(LSTATUS) SHRegQueryInfoUSKeyW(HUSKEY hUSKey, LPDWORD pcSubKeys, LPDWORD pcchMaxSubKeyLen, LPDWORD pcValues, LPDWORD pcchMaxValueNameLen, SHREGENUM_FLAGS enumRegFlags);
#define SHRegQueryInfoUSKey __MINGW_NAME_AW(SHRegQueryInfoUSKey)
  LWSTDAPI_(LSTATUS) SHRegCloseUSKey(HUSKEY hUSKey);
  STDAPI_(LSTATUS)   SHRegGetUSValueA(LPCSTR pszSubKey, LPCSTR pszValue, DWORD *pdwType, void *pvData, DWORD *pcbData, WINBOOL fIgnoreHKCU, void *pvDefaultData, DWORD dwDefaultDataSize);
  STDAPI_(LSTATUS)   SHRegGetUSValueW(LPCWSTR pwzSubKey, LPCWSTR pwzValue, DWORD *pdwType, void *pvData, DWORD *pcbData, WINBOOL fIgnoreHKCU, void *pvDefaultData, DWORD dwDefaultDataSize);
#define SHRegGetUSValue __MINGW_NAME_AW(SHRegGetUSValue)
  LWSTDAPI_(LSTATUS) SHRegSetUSValueA(LPCSTR pszSubKey, LPCSTR pszValue, DWORD dwType, const void *pvData, DWORD cbData, DWORD dwFlags);
  LWSTDAPI_(LSTATUS) SHRegSetUSValueW(LPCWSTR pwzSubKey, LPCWSTR pwzValue, DWORD dwType, const void *pvData, DWORD cbData, DWORD dwFlags);
#define SHRegSetUSValue __MINGW_NAME_AW(SHRegSetUSValue)
  LWSTDAPI_(int)     SHRegGetIntW(HKEY hk, PCWSTR pwzKey, int iDefault);
#ifdef UNICODE
# define SHRegGetInt SHRegGetIntW
#endif
  LWSTDAPI_(WINBOOL) SHRegGetBoolUSValueA(LPCSTR pszSubKey, LPCSTR pszValue, WINBOOL fIgnoreHKCU, WINBOOL fDefault);
  LWSTDAPI_(WINBOOL) SHRegGetBoolUSValueW(LPCWSTR pszSubKey, LPCWSTR pszValue, WINBOOL fIgnoreHKCU, WINBOOL fDefault);
#define SHRegGetBoolUSValue __MINGW_NAME_AW(SHRegGetBoolUSValue)

  enum
  {
    ASSOCF_NONE                 = 0x00000000,
    ASSOCF_INIT_NOREMAPCLSID    = 0x00000001,
    ASSOCF_INIT_BYEXENAME       = 0x00000002,
    ASSOCF_OPEN_BYEXENAME       = 0x00000002,
    ASSOCF_INIT_DEFAULTTOSTAR   = 0x00000004,
    ASSOCF_INIT_DEFAULTTOFOLDER = 0x00000008,
    ASSOCF_NOUSERSETTINGS       = 0x00000010,
    ASSOCF_NOTRUNCATE           = 0x00000020,
    ASSOCF_VERIFY               = 0x00000040,
    ASSOCF_REMAPRUNDLL          = 0x00000080,
    ASSOCF_NOFIXUPS             = 0x00000100,
    ASSOCF_IGNOREBASECLASS      = 0x00000200,
    ASSOCF_INIT_IGNOREUNKNOWN   = 0x00000400,
    ASSOCF_INIT_FIXED_PROGID    = 0x00000800,
    ASSOCF_IS_PROTOCOL          = 0x00001000,
    ASSOCF_INIT_FOR_FILE        = 0x00002000,
    ASSOCF_IS_FULL_URI          = 0x00004000,
    ASSOCF_PER_MACHINE_ONLY     = 0x00008000,
    ASSOCF_APP_TO_APP           = 0x00010000,
  };
  typedef DWORD ASSOCF;

  typedef enum
  {
    ASSOCSTR_COMMAND = 1,
    ASSOCSTR_EXECUTABLE,
    ASSOCSTR_FRIENDLYDOCNAME,
    ASSOCSTR_FRIENDLYAPPNAME,
    ASSOCSTR_NOOPEN,
    ASSOCSTR_SHELLNEWVALUE,
    ASSOCSTR_DDECOMMAND,
    ASSOCSTR_DDEIFEXEC,
    ASSOCSTR_DDEAPPLICATION,
    ASSOCSTR_DDETOPIC,
    ASSOCSTR_INFOTIP,
    ASSOCSTR_QUICKTIP,
    ASSOCSTR_TILEINFO,
    ASSOCSTR_CONTENTTYPE,
    ASSOCSTR_DEFAULTICON,
    ASSOCSTR_SHELLEXTENSION,
    ASSOCSTR_DROPTARGET,
    ASSOCSTR_DELEGATEEXECUTE,
    ASSOCSTR_SUPPORTED_URI_PROTOCOLS,
    ASSOCSTR_PROGID,
    ASSOCSTR_APPID,
    ASSOCSTR_APPPUBLISHER,
    ASSOCSTR_APPICONREFERENCE,
    ASSOCSTR_MAX
  } ASSOCSTR;

  typedef enum
  {
    ASSOCKEY_SHELLEXECCLASS = 1,
    ASSOCKEY_APP,
    ASSOCKEY_CLASS,
    ASSOCKEY_BASECLASS,
    ASSOCKEY_MAX
  } ASSOCKEY;

  typedef enum
  {
    ASSOCDATA_MSIDESCRIPTOR = 1,
    ASSOCDATA_NOACTIVATEHANDLER,
    ASSOCDATA_UNUSED1,
    ASSOCDATA_HASPERUSERASSOC,
    ASSOCDATA_EDITFLAGS,
    ASSOCDATA_VALUE,
    ASSOCDATA_MAX
  } ASSOCDATA;

  typedef enum
  {
    ASSOCENUM_NONE
  } ASSOCENUM;

  typedef enum
  {
    FTA_None                  = 0x00000000,
    FTA_Exclude               = 0x00000001,
    FTA_Show                  = 0x00000002,
    FTA_HasExtension          = 0x00000004,
    FTA_NoEdit                = 0x00000008,
    FTA_NoRemove              = 0x00000010,
    FTA_NoNewVerb             = 0x00000020,
    FTA_NoEditVerb            = 0x00000040,
    FTA_NoRemoveVerb          = 0x00000080,
    FTA_NoEditDesc            = 0x00000100,
    FTA_NoEditIcon            = 0x00000200,
    FTA_NoEditDflt            = 0x00000400,
    FTA_NoEditVerbCmd         = 0x00000800,
    FTA_NoEditVerbExe         = 0x00001000,
    FTA_NoDDE                 = 0x00002000,
    FTA_NoEditMIME            = 0x00008000,
    FTA_OpenIsSafe            = 0x00010000,
    FTA_AlwaysUnsafe          = 0x00020000,
    FTA_NoRecentDocs          = 0x00100000,
    FTA_SafeForElevation      = 0x00200000,
    FTA_AlwaysUseDirectInvoke = 0x00400000,
  } FILETYPEATTRIBUTEFLAGS;
  DEFINE_ENUM_FLAG_OPERATORS(FILETYPEATTRIBUTEFLAGS)

#undef  INTERFACE
#define INTERFACE IQueryAssociations

  DECLARE_INTERFACE_IID_(IQueryAssociations, IUnknown, "c46ca590-3c3f-11d2-bee6-0000f805ca57")
  {
    STDMETHOD(Init)(THIS_ ASSOCF flags, LPCWSTR pszAssoc, HKEY hkProgid, HWND hwnd) PURE;
    STDMETHOD(GetString)(THIS_ ASSOCF flags, ASSOCSTR str, LPCWSTR pszExtra, LPWSTR pszOut, DWORD *pcchOut) PURE;
    STDMETHOD(GetKey)(THIS_ ASSOCF flags, ASSOCKEY key, LPCWSTR pszExtra, HKEY *phkeyOut) PURE;
    STDMETHOD(GetData)(THIS_ ASSOCF flags, ASSOCDATA data, LPCWSTR pszExtra, void * pvOut, DWORD *pcbOut) PURE;
    STDMETHOD(GetEnum)(THIS_ ASSOCF flags, ASSOCENUM assocenum, LPCWSTR pszExtra, REFIID riid, void **ppvOut) PURE;
  };

  LWSTDAPI           AssocCreate(CLSID clsid, REFIID riid, void **ppv);
  STDAPI_(DWORD)     SHGetAssocKeys(IQueryAssociations *pqa, HKEY *rgKeys, DWORD cKeys);
  LWSTDAPI           AssocQueryStringA(ASSOCF flags, ASSOCSTR str, LPCSTR pszAssoc, LPCSTR pszExtra, LPSTR pszOut, DWORD *pcchOut);
  LWSTDAPI           AssocQueryStringW(ASSOCF flags, ASSOCSTR str, LPCWSTR pszAssoc, LPCWSTR pszExtra, LPWSTR pszOut, DWORD *pcchOut);
#define AssocQueryString __MINGW_NAME_AW(AssocQueryString)
  LWSTDAPI           AssocQueryStringByKeyA(ASSOCF flags, ASSOCSTR str, HKEY hkAssoc, LPCSTR pszExtra, LPSTR pszOut, DWORD *pcchOut);
  LWSTDAPI           AssocQueryStringByKeyW(ASSOCF flags, ASSOCSTR str, HKEY hkAssoc, LPCWSTR pszExtra, LPWSTR pszOut, DWORD *pcchOut);
#define AssocQueryStringByKey __MINGW_NAME_AW(AssocQueryStringByKey)
  LWSTDAPI           AssocQueryKeyA(ASSOCF flags, ASSOCKEY key, LPCSTR pszAssoc, LPCSTR pszExtra, HKEY *phkeyOut);
  LWSTDAPI           AssocQueryKeyW(ASSOCF flags, ASSOCKEY key, LPCWSTR pszAssoc, LPCWSTR pszExtra, HKEY *phkeyOut);
#define AssocQueryKey __MINGW_NAME_AW(AssocQueryKey)
  LWSTDAPI_(WINBOOL) AssocIsDangerous(PCWSTR pszAssoc);
  LWSTDAPI           AssocGetPerceivedType(PCWSTR pszExt, PERCEIVED *ptype, PERCEIVEDFLAG *pflag, PWSTR *ppszType);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */

#endif  /* NO_SHLWAPI_REG */

#ifndef NO_SHLWAPI_STREAM

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#ifndef __IStream_FWD_DEFINED__
# define __IStream_FWD_DEFINED__
  typedef interface IStream IStream;
#endif

  LWSTDAPI_(IStream *) SHOpenRegStreamA(HKEY hkey, LPCSTR pszSubkey, LPCSTR pszValue, DWORD grfMode);
  LWSTDAPI_(IStream *) SHOpenRegStreamW(HKEY hkey, LPCWSTR pszSubkey, LPCWSTR pszValue, DWORD grfMode);
#define SHOpenRegStream __MINGW_NAME_AW(SHOpenRegStream)
  LWSTDAPI_(IStream *) SHOpenRegStream2A(HKEY hkey, LPCSTR pszSubkey, LPCSTR pszValue, DWORD grfMode);
  LWSTDAPI_(IStream *) SHOpenRegStream2W(HKEY hkey, LPCWSTR pszSubkey, LPCWSTR pszValue, DWORD grfMode);
#define SHOpenRegStream2 __MINGW_NAME_AW(SHOpenRegStream2)
#undef  SHOpenRegStream
#define SHOpenRegStream SHOpenRegStream2
  LWSTDAPI             SHCreateStreamOnFileA(LPCSTR pszFile, DWORD grfMode, IStream **ppstm);
  LWSTDAPI             SHCreateStreamOnFileW(LPCWSTR pszFile, DWORD grfMode, IStream **ppstm);
#define SHCreateStreamOnFile __MINGW_NAME_AW(SHCreateStreamOnFile)
  LWSTDAPI             SHCreateStreamOnFileEx(LPCWSTR pszFile, DWORD grfMode, DWORD dwAttributes, WINBOOL fCreate, IStream *pstmTemplate, IStream **ppstm);
  LWSTDAPI_(IStream *) SHCreateMemStream(const BYTE *pInit, UINT cbInit);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */

#endif  /* NO_SHLWAPI_STREAM */

#ifndef NO_SHLWAPI_HTTP

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

  LWSTDAPI GetAcceptLanguagesA(LPSTR pszLanguages, DWORD *pcchLanguages);
  LWSTDAPI GetAcceptLanguagesW(LPWSTR pszLanguages, DWORD *pcchLanguages);
#define GetAcceptLanguages __MINGW_NAME_AW(GetAcceptLanguages)

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */

#endif  /* NO_SHLWAPI_HTTP */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

  LWSTDAPI_(void) IUnknown_Set(IUnknown **ppunk, IUnknown *punk);
  LWSTDAPI_(void) IUnknown_AtomicRelease(void **ppunk);
  LWSTDAPI        IUnknown_GetWindow(IUnknown *punk, HWND *phwnd);
  LWSTDAPI        IUnknown_SetSite(IUnknown *punk, IUnknown *punkSite);
  LWSTDAPI        IUnknown_GetSite(IUnknown *punk, REFIID riid, void **ppv);
  LWSTDAPI        IUnknown_QueryService(IUnknown *punk, REFGUID guidService, REFIID riid, void **ppvOut);

#if !defined(__cplusplus) && defined(COBJMACROS)
# undef IStream_Read
# undef IStream_Write
#endif
  LWSTDAPI IStream_Read(IStream *pstm, void *pv, ULONG cb);
  LWSTDAPI IStream_Write(IStream *pstm, const void *pv, ULONG cb);
  LWSTDAPI IStream_Reset(IStream *pstm);
  LWSTDAPI IStream_Size(IStream *pstm, ULARGE_INTEGER *pui);

#ifndef __IConnectionPoint_FWD_DEFINED__
# define __IConnectionPoint_FWD_DEFINED__
  typedef interface IConnectionPoint IConnectionPoint;
#endif

  LWSTDAPI ConnectToConnectionPoint(IUnknown *punk, REFIID riidEvent, WINBOOL fConnect, IUnknown *punkTarget, DWORD *pdwCookie, IConnectionPoint **ppcpOut);
  LWSTDAPI IStream_ReadPidl(IStream *pstm, PIDLIST_RELATIVE *ppidlOut);
  LWSTDAPI IStream_WritePidl(IStream *pstm, PCUIDLIST_RELATIVE pidlWrite);
  LWSTDAPI IStream_ReadStr(IStream *pstm, PWSTR *ppsz);
  LWSTDAPI IStream_WriteStr(IStream *pstm, PCWSTR psz);
  LWSTDAPI IStream_Copy(IStream *pstmFrom, IStream *pstmTo, DWORD cb);

#define SHGVSPB_PERUSER          0x00000001
#define SHGVSPB_ALLUSERS         0x00000002
#define SHGVSPB_PERFOLDER        0x00000004
#define SHGVSPB_ALLFOLDERS       0x00000008
#define SHGVSPB_INHERIT          0x00000010
#define SHGVSPB_ROAM             0x00000020
#define SHGVSPB_NOAUTODEFAULTS   0x80000000
#define SHGVSPB_FOLDER           (SHGVSPB_PERUSER | SHGVSPB_PERFOLDER)
#define SHGVSPB_FOLDERNODEFAULTS (SHGVSPB_PERUSER | SHGVSPB_PERFOLDER | SHGVSPB_NOAUTODEFAULTS)
#define SHGVSPB_USERDEFAULTS     (SHGVSPB_PERUSER | SHGVSPB_ALLFOLDERS)
#define SHGVSPB_GLOBALDEFAULTS   (SHGVSPB_ALLUSERS | SHGVSPB_ALLFOLDERS)

  LWSTDAPI SHGetViewStatePropertyBag(PCIDLIST_ABSOLUTE pidl, PCWSTR pszBagName, DWORD dwFlags, REFIID riid, void **ppv);

#define FDTF_SHORTTIME          0x00000001
#define FDTF_SHORTDATE          0x00000002
#define FDTF_DEFAULT            (FDTF_SHORTDATE | FDTF_SHORTTIME)
#define FDTF_LONGDATE           0x00000004
#define FDTF_LONGTIME           0x00000008
#define FDTF_RELATIVE           0x00000010
#define FDTF_LTRDATE            0x00000100
#define FDTF_RTLDATE            0x00000200
#define FDTF_NOAUTOREADINGORDER 0x00000400

  LWSTDAPI_(int) SHFormatDateTimeA(const FILETIME UNALIGNED *pft, DWORD *pdwFlags, LPSTR pszBuf, UINT cchBuf);
  LWSTDAPI_(int) SHFormatDateTimeW(const FILETIME UNALIGNED *pft, DWORD *pdwFlags, LPWSTR pszBuf, UINT cchBuf);
#define SHFormatDateTime __MINGW_NAME_AW(SHFormatDateTime)

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

  LWSTDAPI_(int) SHAnsiToUnicode(PCSTR pszSrc, PWSTR pwszDst, int cwchBuf);
  LWSTDAPI_(int) SHAnsiToAnsi(PCSTR pszSrc, PSTR pszDst, int cchBuf);
  LWSTDAPI_(int) SHUnicodeToAnsi(PCWSTR pwszSrc, PSTR pszDst, int cchBuf);
  LWSTDAPI_(int) SHUnicodeToUnicode(PCWSTR pwzSrc, PWSTR pwzDst, int cwchBuf);

#ifdef UNICODE
# define SHTCharToUnicode(wzSrc, wzDest, cchSize) SHUnicodeToUnicode(wzSrc, wzDest, cchSize)
# define SHTCharToAnsi(wzSrc, szDest, cchSize)    SHUnicodeToAnsi(wzSrc, szDest, cchSize)
# define SHUnicodeToTChar(wzSrc, wzDest, cchSize) SHUnicodeToUnicode(wzSrc, wzDest, cchSize)
# define SHAnsiToTChar(szSrc, wzDest, cchSize)    SHAnsiToUnicode(szSrc, wzDest, cchSize)
#else
# define SHTCharToUnicode(szSrc, wzDest, cchSize) SHAnsiToUnicode(szSrc, wzDest, cchSize)
# define SHTCharToAnsi(szSrc, szDest, cchSize)    SHAnsiToAnsi(szSrc, szDest, cchSize)
# define SHUnicodeToTChar(wzSrc, szDest, cchSize) SHUnicodeToAnsi(wzSrc, szDest, cchSize)
# define SHAnsiToTChar(szSrc, szDest, cchSize)    SHAnsiToAnsi(szSrc, szDest, cchSize)
#endif

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

  LWSTDAPI_(int)     SHMessageBoxCheckA(HWND hwnd, LPCSTR pszText, LPCSTR pszCaption, UINT uType, int iDefault, LPCSTR pszRegVal);
  LWSTDAPI_(int)     SHMessageBoxCheckW(HWND hwnd, LPCWSTR pszText, LPCWSTR pszCaption, UINT uType, int iDefault, LPCWSTR pszRegVal);
#define SHMessageBoxCheck __MINGW_NAME_AW(SHMessageBoxCheck)
  LWSTDAPI_(LRESULT) SHSendMessageBroadcastA(UINT uMsg, WPARAM wParam, LPARAM lParam);
  LWSTDAPI_(LRESULT) SHSendMessageBroadcastW(UINT uMsg, WPARAM wParam, LPARAM lParam);
#define SHSendMessageBroadcast __MINGW_NAME_AW(SHSendMessageBroadcast)
  LWSTDAPI_(CHAR)    SHStripMneumonicA(LPSTR pszMenu);
  LWSTDAPI_(WCHAR)   SHStripMneumonicW(LPWSTR pszMenu);
#define SHStripMneumonic __MINGW_NAME_AW(SHStripMneumonic)

#ifndef NO_SHLWAPI_ISOS
# define OS_WINDOWS                0
# define OS_NT                     1
# define OS_WIN95ORGREATER         2
# define OS_NT4ORGREATER           3
# define OS_WIN98ORGREATER         5
# define OS_WIN98_GOLD             6
# define OS_WIN2000ORGREATER       7
# define OS_WIN2000PRO             8
# define OS_WIN2000SERVER          9
# define OS_WIN2000ADVSERVER       10
# define OS_WIN2000DATACENTER      11
# define OS_WIN2000TERMINAL        12
# define OS_EMBEDDED               13
# define OS_TERMINALCLIENT         14
# define OS_TERMINALREMOTEADMIN    15
# define OS_WIN95_GOLD             16
# define OS_MEORGREATER            17
# define OS_XPORGREATER            18
# define OS_HOME                   19
# define OS_PROFESSIONAL           20
# define OS_DATACENTER             21
# define OS_ADVSERVER              22
# define OS_SERVER                 23
# define OS_TERMINALSERVER         24
# define OS_PERSONALTERMINALSERVER 25
# define OS_FASTUSERSWITCHING      26
# define OS_WELCOMELOGONUI         27
# define OS_DOMAINMEMBER           28
# define OS_ANYSERVER              29
# define OS_WOW6432                30
# define OS_WEBSERVER              31
# define OS_SMALLBUSINESSSERVER    32
# define OS_TABLETPC               33
# define OS_SERVERADMINUI          34
# define OS_MEDIACENTER            35
# define OS_APPLIANCE              36

  LWSTDAPI_(WINBOOL) IsOS(DWORD dwOS);
#endif  /* NO_SHLWAPI_ISOS */

  typedef enum
  {
    GLOBALCOUNTER_SEARCHMANAGER,
    GLOBALCOUNTER_SEARCHOPTIONS,
    GLOBALCOUNTER_FOLDERSETTINGSCHANGE,
    GLOBALCOUNTER_RATINGS,
    GLOBALCOUNTER_APPROVEDSITES,
    GLOBALCOUNTER_RESTRICTIONS,
    GLOBALCOUNTER_SHELLSETTINGSCHANGED,
    GLOBALCOUNTER_SYSTEMPIDLCHANGE,
    GLOBALCOUNTER_OVERLAYMANAGER,
    GLOBALCOUNTER_QUERYASSOCIATIONS,
    GLOBALCOUNTER_IESESSIONS,
    GLOBALCOUNTER_IEONLY_SESSIONS,
    GLOBALCOUNTER_APPLICATION_DESTINATIONS,
    __UNUSED_RECYCLE_WAS_GLOBALCOUNTER_CSCSYNCINPROGRESS,
    GLOBALCOUNTER_BITBUCKETNUMDELETERS,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_SHARES,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_A,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_B,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_C,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_D,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_E,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_F,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_G,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_H,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_I,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_J,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_K,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_L,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_M,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_N,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_O,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_P,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Q,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_R,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_S,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_T,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_U,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_V,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_W,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_X,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Y,
    GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Z,
    __UNUSED_RECYCLE_WAS_GLOBALCOUNTER_RECYCLEDIRTYCOUNT_SERVERDRIVE,
    __UNUSED_RECYCLE_WAS_GLOBALCOUNTER_RECYCLEGLOBALDIRTYCOUNT,
    GLOBALCOUNTER_RECYCLEBINENUM,
    GLOBALCOUNTER_RECYCLEBINCORRUPTED,
    GLOBALCOUNTER_RATINGS_STATECOUNTER,
    GLOBALCOUNTER_PRIVATE_PROFILE_CACHE,
    GLOBALCOUNTER_INTERNETTOOLBAR_LAYOUT,
    GLOBALCOUNTER_FOLDERDEFINITION_CACHE,
    GLOBALCOUNTER_COMMONPLACES_LIST_CACHE,
    GLOBALCOUNTER_PRIVATE_PROFILE_CACHE_MACHINEWIDE,
    GLOBALCOUNTER_ASSOCCHANGED,
    GLOBALCOUNTER_APP_ITEMS_STATE_STORE_CACHE,
    GLOBALCOUNTER_SETTINGSYNC_ENABLED,
    GLOBALCOUNTER_APPSFOLDER_FILETYPEASSOCIATION_COUNTER,
    GLOBALCOUNTER_USERINFOCHANGED,
    GLOBALCOUNTER_SYNC_ENGINE_INFORMATION_CACHE_MACHINEWIDE,
    GLOBALCOUNTER_BANNERS_DATAMODEL_CACHE_MACHINEWIDE,
    GLOBALCOUNTER_MAXIMUMVALUE
  } SHGLOBALCOUNTER;

  LWSTDAPI_(long)    SHGlobalCounterGetValue(const SHGLOBALCOUNTER id);
  LWSTDAPI_(long)    SHGlobalCounterIncrement(const SHGLOBALCOUNTER id);
  LWSTDAPI_(long)    SHGlobalCounterDecrement(const SHGLOBALCOUNTER id);
  LWSTDAPI_(HANDLE)  SHAllocShared(const void *pvData, DWORD dwSize, DWORD dwProcessId);
  LWSTDAPI_(WINBOOL) SHFreeShared(HANDLE hData, DWORD dwProcessId);
  LWSTDAPI_(void *)  SHLockShared(HANDLE hData, DWORD dwProcessId);
  LWSTDAPI_(WINBOOL) SHUnlockShared(void *pvData);
  LWSTDAPI           WhichPlatform(void);

#define PLATFORM_UNKNOWN     0
#define PLATFORM_IE3         1
#define PLATFORM_BROWSERONLY 1
#define PLATFORM_INTEGRATED  2

  typedef struct
  {
    const IID *piid;
    DWORD      dwOffset;
  } QITAB, *LPQITAB;
  typedef const QITAB *LPCQITAB;

#ifdef __cplusplus
# define QITABENTMULTI(Cthis, Ifoo, Iimpl) { &__uuidof(Ifoo), OFFSETOFCLASS(Iimpl, Cthis) }
#else
# define QITABENTMULTI(Cthis, Ifoo, Iimpl) { (IID*) &IID_##Ifoo, OFFSETOFCLASS(Iimpl, Cthis) }
#endif
#define QITABENTMULTI2(Cthis, Ifoo, Iimpl) { (IID*) &Ifoo, OFFSETOFCLASS(Iimpl, Cthis) }
#define QITABENT(Cthis, Ifoo)              QITABENTMULTI(Cthis, Ifoo, Ifoo)

  STDAPI QISearch(void *that, LPCQITAB pqit, REFIID riid, void **ppv);

#ifndef STATIC_CAST
# define STATIC_CAST(typ) (typ)
#endif

#ifndef OFFSETOFCLASS
# define OFFSETOFCLASS(base, derived) ((DWORD)(DWORD_PTR)(STATIC_CAST(base*)((derived*)8))-8)
#endif

#define ILMM_IE4 0
  LWSTDAPI_(WINBOOL) SHIsLowMemoryMachine(DWORD dwType);
  LWSTDAPI_(int)     GetMenuPosFromID(HMENU hMenu, UINT id);
  LWSTDAPI           SHGetInverseCMAP(BYTE *pbMap, ULONG cbMap);

#define SHACF_DEFAULT               0x00000000
#define SHACF_FILESYSTEM            0x00000001
#define SHACF_URLALL                (SHACF_URLHISTORY | SHACF_URLMRU)
#define SHACF_URLHISTORY            0x00000002
#define SHACF_URLMRU                0x00000004
#define SHACF_USETAB                0x00000008
#define SHACF_FILESYS_ONLY          0x00000010
#define SHACF_FILESYS_DIRS          0x00000020
#define SHACF_VIRTUAL_NAMESPACE     0x00000040
#define SHACF_AUTOSUGGEST_FORCE_ON  0x10000000
#define SHACF_AUTOSUGGEST_FORCE_OFF 0x20000000
#define SHACF_AUTOAPPEND_FORCE_ON   0x40000000
#define SHACF_AUTOAPPEND_FORCE_OFF  0x80000000

  LWSTDAPI           SHAutoComplete(HWND hwndEdit, DWORD dwFlags);
  LWSTDAPI           SHCreateThreadRef(LONG *pcRef, IUnknown **ppunk);
  LWSTDAPI           SHSetThreadRef(IUnknown *punk);
  LWSTDAPI           SHGetThreadRef(IUnknown **ppunk);
  LWSTDAPI_(WINBOOL) SHSkipJunction(IBindCtx *pbc, const CLSID *pclsid);

  enum
  {
    CTF_INSIST             = 0x00000001,
    CTF_THREAD_REF         = 0x00000002,
    CTF_PROCESS_REF        = 0x00000004,
    CTF_COINIT_STA         = 0x00000008,
    CTF_COINIT             = 0x00000008,
    CTF_FREELIBANDEXIT     = 0x00000010,
    CTF_REF_COUNTED        = 0x00000020,
    CTF_WAIT_ALLOWCOM      = 0x00000040,
    CTF_UNUSED             = 0x00000080,
    CTF_INHERITWOW64       = 0x00000100,
    CTF_WAIT_NO_REENTRANCY = 0x00000200,
    CTF_KEYBOARD_LOCALE    = 0x00000400,
    CTF_OLEINITIALIZE      = 0x00000800,
    CTF_COINIT_MTA         = 0x00001000,
    CTF_NOADDREFLIB        = 0x00002000,
  };

  typedef DWORD SHCT_FLAGS;

  LWSTDAPI_(WINBOOL) SHCreateThread(LPTHREAD_START_ROUTINE pfnThreadProc, void *pData, SHCT_FLAGS dwFlags, LPTHREAD_START_ROUTINE pfnCallback);
  LWSTDAPI_(WINBOOL) SHCreateThreadWithHandle(LPTHREAD_START_ROUTINE pfnThreadProc, void *pData, SHCT_FLAGS dwflags, LPTHREAD_START_ROUTINE pfnCallback, HANDLE *pHandle);
  LWSTDAPI_(void)    SetProcessReference(IUnknown *punk);
  LWSTDAPI           GetProcessReference(IUnknown **punk);
  LWSTDAPI           SHReleaseThreadRef(void);

#ifndef NO_SHLWAPI_GDI
  LWSTDAPI_(HPALETTE) SHCreateShellPalette(HDC hdc);
  LWSTDAPI_(void)     ColorRGBToHLS(COLORREF clrRGB, WORD *pwHue, WORD *pwLuminance, WORD *pwSaturation);
  LWSTDAPI_(COLORREF) ColorHLSToRGB(WORD wHue, WORD wLuminance, WORD wSaturation);
  LWSTDAPI_(COLORREF) ColorAdjustLuma(COLORREF clrRGB, int n, WINBOOL fScale);
#endif

  typedef struct _DLLVERSIONINFO
  {
    DWORD cbSize;
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    DWORD dwBuildNumber;
    DWORD dwPlatformID;
  } DLLVERSIONINFO;

#define DLLVER_PLATFORM_WINDOWS 0x00000001
#define DLLVER_PLATFORM_NT      0x00000002

  typedef struct _DLLVERSIONINFO2
  {
    DLLVERSIONINFO info1;
    DWORD          dwFlags;
    ULONGLONG      ullVersion;
  } DLLVERSIONINFO2;

#define DLLVER_MAJOR_MASK 0xFFFF000000000000
#define DLLVER_MINOR_MASK 0x0000FFFF00000000
#define DLLVER_BUILD_MASK 0x00000000FFFF0000
#define DLLVER_QFE_MASK   0x000000000000FFFF

#define MAKEDLLVERULL(major, minor, build, qfe) (((ULONGLONG)(major) << 48) | ((ULONGLONG)(minor) << 32) | ((ULONGLONG)(build) << 16) | ((ULONGLONG)(qfe) << 0))

  typedef HRESULT (CALLBACK *DLLGETVERSIONPROC)(DLLVERSIONINFO *);

  STDAPI             DllInstall(WINBOOL bInstall, PCWSTR pszCmdLine);
  LWSTDAPI_(WINBOOL) IsInternetESCEnabled(void);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

#ifdef __cplusplus
}
#endif

#include <poppack.h>

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */

#endif  /* NOSHLWAPI */

#endif  /* _INC_SHLWAPI */
