/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_SEARCH
#define _INC_SEARCH

#include <corecrt.h>
#include <stddef.h>

__MINGW_BEGIN_C_DECLS

  typedef int (__cdecl* _CoreCrtSecureSearchSortCompareFunction)(void *, const void *, const void *);
  typedef int (__cdecl* _CoreCrtNonSecureSearchSortCompareFunction)(const void *, const void *);

  _CRTIMP void *__cdecl bsearch(const void *_Key, const void *_Base, size_t _NumOfElements, size_t _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction) __MINGW_NONNULL((1, 2, 5));
#ifdef __MINGW_USE_SECAPI
  _CRTIMP void *__cdecl bsearch_s(const void *_Key, const void *_Base, rsize_t _NumOfElements, rsize_t _SizeOfElements, _CoreCrtSecureSearchSortCompareFunction _CompareFunction, void *_Context);
#endif
  _CRTIMP void __cdecl qsort(void *_Base, size_t _NumOfElements, size_t _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction) __MINGW_NONNULL((1, 4));
#ifdef __MINGW_USE_SECAPI
  _CRTIMP void __cdecl qsort_s(void *_Base, rsize_t _NumOfElements, rsize_t _SizeOfElements, _CoreCrtSecureSearchSortCompareFunction _CompareFunction, void *_Context);
#endif
  _CRTIMP void *__cdecl _lfind(const void *_Key, const void *_Base, unsigned int *_NumOfElements, unsigned int _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction);
  _CRTIMP void *__cdecl _lfind_s(const void *_Key, const void *_Base, unsigned int *_NumOfElements, size_t _SizeOfElements, _CoreCrtSecureSearchSortCompareFunction _CompareFunction, void *_Context);
  _CRTIMP void *__cdecl _lsearch(const void *_Key, void *_Base, unsigned int *_NumOfElements, unsigned int _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction);
  _CRTIMP void *__cdecl _lsearch_s(const void *_Key, void *_Base, unsigned int *_NumOfElements, size_t _SizeOfElements, _CoreCrtSecureSearchSortCompareFunction _CompareFunction, void *_Context);

  _CRTIMP void *__cdecl lfind(const void *_Key, const void *_Base, unsigned int *_NumOfElements, unsigned int _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction) __MINGW_DEPRECATED_MSVC2005;
  _CRTIMP void *__cdecl lsearch(const void *_Key, void *_Base, unsigned int *_NumOfElements, unsigned int _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction) __MINGW_DEPRECATED_MSVC2005;

/*
Documentation for these POSIX definitions and prototypes can be found in
The Open Group Base Specifications Issue 6
IEEE Std 1003.1, 2004 Edition.
eg:  http://www.opengroup.org/onlinepubs/009695399/functions/twalk.html
*/

  typedef struct entry
  {
    char *key;
    void *data;
  } ENTRY;

  typedef enum
  {
    FIND,
    ENTER
  } ACTION;

  typedef enum
  {
    preorder,
    postorder,
    endorder,
    leaf
  } VISIT;

#ifdef _SEARCH_PRIVATE
  typedef struct node
  {
    char         *key;
    struct node  *llink, *rlink;
  } node_t;
#endif

  typedef int (*__compar_fn_t) (const void *, const void *);
  extern void *__cdecl tdelete(const void * __restrict__ _key, void ** __restrict__ _rootp, __compar_fn_t _compar) __MINGW_NONNULL((2, 3));
  extern void *__cdecl tfind(const void *_key, void * const *_rootp, __compar_fn_t _compar) __MINGW_NONNULL((2, 3));
  extern void *__cdecl tsearch(const void *_key, void **_rootp, __compar_fn_t _compar) __MINGW_NONNULL((2, 3));
  typedef void (*__action_fn_t) (const void *_nodep, VISIT _value, int _level);
  extern void __cdecl twalk(const void *_root, __action_fn_t _action);

#ifdef __MINGW_USE_GNU
  typedef void (*__free_fn_t) (void *_nodep);
  extern void __cdecl tdestroy(void *_root, __free_fn_t _freenode) __MINGW_NONNULL((2));
#endif

__MINGW_END_C_DECLS

#endif  /* _INC_SEARCH */
