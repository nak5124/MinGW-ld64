/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CORECRT_SEARCH
#define _INC_CORECRT_SEARCH

#include <corecrt.h>
#include <stddef.h>

__MINGW_BEGIN_C_DECLS

  typedef int (__cdecl* _CoreCrtSecureSearchSortCompareFunction)(void *, const void *, const void *);
  typedef int (__cdecl* _CoreCrtNonSecureSearchSortCompareFunction)(const void *, const void *);

  _CRTIMP void *__cdecl bsearch(const void *_Key, const void *_Base, size_t _NumOfElements, size_t _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction) __MINGW_NONNULL((1, 2, 5));
#ifdef __MINGW_USE_SECAPI
  _CRTIMP void *__cdecl bsearch_s(const void *_Key, const void *_Base, rsize_t _NumOfElements, rsize_t _SizeOfElements, _CoreCrtSecureSearchSortCompareFunction _CompareFunction, void *_Context);
#endif
  _CRTIMP void  __cdecl qsort(void *_Base, size_t _NumOfElements, size_t _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction) __MINGW_NONNULL((1, 4));
#ifdef __MINGW_USE_SECAPI
  _CRTIMP void  __cdecl qsort_s(void *_Base, rsize_t _NumOfElements, rsize_t _SizeOfElements, _CoreCrtSecureSearchSortCompareFunction _CompareFunction, void *_Context);
#endif
  _CRTIMP void *__cdecl _lfind(const void *_Key, const void *_Base, unsigned int *_NumOfElements, unsigned int _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction);
  _CRTIMP void *__cdecl _lfind_s(const void *_Key, const void *_Base, unsigned int *_NumOfElements, size_t _SizeOfElements, _CoreCrtSecureSearchSortCompareFunction _CompareFunction, void *_Context);
  _CRTIMP void *__cdecl _lsearch(const void *_Key, void *_Base, unsigned int *_NumOfElements, unsigned int _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction);
  _CRTIMP void *__cdecl _lsearch_s(const void *_Key, void *_Base, unsigned int *_NumOfElements, size_t _SizeOfElements, _CoreCrtSecureSearchSortCompareFunction _CompareFunction, void *_Context);

  _CRTIMP void *__cdecl lfind(const void *_Key, const void *_Base, unsigned int *_NumOfElements, unsigned int _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction) __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP void *__cdecl lsearch(const void *_Key, void *_Base, unsigned int *_NumOfElements, unsigned int _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction)     __MINGW_DEPRECATED_MSVC2005;

__MINGW_END_C_DECLS

#endif  /* _INC_CORECRT_SEARCH */
