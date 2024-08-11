/*
 * DIRENT.H (formerly DIRLIB.H)
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within the package.
 *
 */
#ifndef _DIRENT_H_
#define _DIRENT_H_

#include <corecrt.h>
#include <io.h>

__MINGW_BEGIN_C_DECLS

  struct dirent
  {
    long           d_ino;        /* Always zero. */
    unsigned short d_reclen;     /* Always zero. */
    unsigned short d_namlen;     /* Length of name in d_name. */
    char           d_name[260];  /* [FILENAME_MAX] */ /* File name. */
  };

  /*
   * This is an internal data structure. Good programmers will not use it
   * except as an argument to one of the functions below.
   * dd_stat field is now int (was short in older versions).
   */
  typedef struct
  {
    /* disk transfer area for this dir */
    struct _finddata_t dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
     * safe as long as only one thread uses a particular DIR struct at
     * a time) */
    struct dirent dd_dir;

    /* _findnext handle */
    intptr_t dd_handle;

    /*
     * Status of search:
     *   0 = not started yet (next entry to read is first entry)
     *  -1 = off the end
     *   positive = 0 based index of next entry
     */
    int dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    char dd_name[1];
  } DIR;

  extern int            __cdecl closedir(DIR *__dirp)       __MINGW_NONNULL((1)) __MINGW_NOTHROW;
  extern DIR           *__cdecl opendir(const char *__name) __MINGW_NONNULL((1)) __MINGW_MALLOC __MINGW_DEALLOC(closedir, 1) __MINGW_NOTHROW;
  extern struct dirent *__cdecl readdir(DIR *__dirp)        __MINGW_NONNULL((1)) __MINGW_NOTHROW;
  extern void           __cdecl rewinddir(DIR *__dirp)      __MINGW_NONNULL((1)) __MINGW_NOTHROW;
#if defined(__MINGW_USE_XOPEN) || defined(__MINGW_USE_MISC)
  extern long           __cdecl telldir(DIR *__dirp)             __MINGW_NONNULL((1)) __MINGW_NOTHROW;
  extern void           __cdecl seekdir(DIR *__dirp, long __pos) __MINGW_NONNULL((1)) __MINGW_NOTHROW;
#endif

  /* wide char versions */
  struct _wdirent
  {
    long           d_ino;        /* Always zero. */
    unsigned short d_reclen;     /* Always zero. */
    unsigned short d_namlen;     /* Length of name in d_name. */
    wchar_t        d_name[260];  /* [FILENAME_MAX] */ /* File name. */
  };

  /*
   * This is an internal data structure. Good programmers will not use it
   * except as an argument to one of the functions below.
   */
  typedef struct
  {
    /* disk transfer area for this dir */
    struct _wfinddata_t dd_dta;

    /* dirent struct to return from dir (NOTE: this makes this thread
     * safe as long as only one thread uses a particular DIR struct at
     * a time) */
    struct _wdirent dd_dir;

    /* _findnext handle */
    intptr_t dd_handle;

    /*
     * Status of search:
     *   0 = not started yet (next entry to read is first entry)
     *  -1 = off the end
     *   positive = 0 based index of next entry
     */
    int dd_stat;

    /* given path for dir with search pattern (struct is extended) */
    wchar_t dd_name[1];
  } _WDIR;

  extern int              __cdecl _wclosedir(_WDIR *__dirp)            __MINGW_NONNULL((1)) __MINGW_NOTHROW;
  extern _WDIR           *__cdecl _wopendir(const wchar_t *__name)     __MINGW_NONNULL((1)) __MINGW_MALLOC __MINGW_DEALLOC(_wclosedir, 1) __MINGW_NOTHROW;
  extern struct _wdirent *__cdecl _wreaddir(_WDIR *__dirp)             __MINGW_NONNULL((1)) __MINGW_NOTHROW;
  extern void             __cdecl _wrewinddir(_WDIR *__dirp)           __MINGW_NONNULL((1)) __MINGW_NOTHROW;
  extern long             __cdecl _wtelldir(_WDIR *__dirp)             __MINGW_NONNULL((1)) __MINGW_NOTHROW;
  extern void             __cdecl _wseekdir(_WDIR *__dirp, long __pos) __MINGW_NONNULL((1)) __MINGW_NOTHROW;

__MINGW_END_C_DECLS

#endif  /* _DIRENT_H_ */
