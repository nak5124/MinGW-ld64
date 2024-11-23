/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_SEARCH
#define _INC_SEARCH

#include <corecrt.h>
#include <corecrt_search.h>

__MINGW_BEGIN_C_DECLS

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
    char        *key;
    struct node *llink, *rlink;
  } node_t;
#endif

  typedef int (*__compar_fn_t)(const void *, const void *);
  extern void *__cdecl tdelete(const void *__restrict __key, void **__restrict __rootp, __compar_fn_t __compar) __MINGW_NONNULL((2, 3));
  extern void *__cdecl tfind(const void *__key, void * const *__rootp, __compar_fn_t __compar) __MINGW_NONNULL((2, 3));
  extern void *__cdecl tsearch(const void *__key, void **__rootp, __compar_fn_t __compar) __MINGW_NONNULL((2, 3));
  typedef void (*__action_fn_t)(const void *__nodep, VISIT __value, int __level);
  extern void  __cdecl twalk(const void *__root, __action_fn_t __action);

#ifdef __MINGW_USE_GNU
  typedef void (*__free_fn_t)(void *__nodep);
  extern void __cdecl tdestroy(void *__root, __free_fn_t __freenode) __MINGW_NONNULL((2));
#endif

#if defined(__MINGW_USE_MISC) || defined(__MINGW_USE_XOPEN_EXT)
# ifdef __MINGW_USE_GNU
  struct qelem
  {
    struct qelem *q_forw;
    struct qelem *q_back;
    char          q_data[1];
  };
# endif

  extern void __cdecl insque(void *_Elem, void *_Prev);
  extern void __cdecl remque(void *_Elem);
#endif

__MINGW_END_C_DECLS

#endif  /* _INC_SEARCH */
