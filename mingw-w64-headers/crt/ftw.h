/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ifndef _FTW_HXX
#define _FTW_HXX

#include <corecrt.h>
#include <sys/types.h>
#include <sys/stat.h>

__MINGW_BEGIN_C_DECLS

  struct FTW
  {
    int base;
    int level;
  };


#define FTW_F   0  /* A regular file. */
#define FTW_D   1  /* A directory. */
#define FTW_DNR 2  /* An unreadable directory. */
#define FTW_NS  3  /* An unstatable file. */
#define FTW_SL  4  /* A symbolic link (not supported). */
#define FTW_DP  5  /* A directory (all subdirs are visited). */
#define FTW_SLN 6  /* A symbolic link naming non-existing file (not supported). */

#define FTW_PHYS         1   /* Do a physical walk (ignore symlinks). */
#define FTW_MOUNT        2   /* Do report only files on same device as the argument (partial supported). */
#define FTW_CHDIR        4   /* Change to current directory while processing (unsupported). */
#define FTW_DEPTH        8   /* Do report files in directory before the directory itself. */
#define FTW_ACTIONRETVAL 16  /* Tell callback to return FTW_* values instead of zero to continue and non-zero to terminate. */

#define FTW_CONTINUE      0  /* Continue with next sibling or with the first child-directory. */
#define FTW_STOP          1  /* Return from ftw or nftw with FTW_STOP as return value. */
#define FTW_SKIP_SUBTREE  2  /* Valid only for FTW_D: Don't walk through the subtree. */
#define FTW_SKIP_SIBLINGS 3  /* Continue with FTW_DP callback for current directory (if FTW_DEPTH) and then its siblings. */


  typedef int (*__ftw_func_t)(const char *__filename, const struct stat *__status, int __flag);
#if !defined(__MINGW_USE_FOB64) || defined(_CRTBLD)
  extern int ftw(const char *__dir, __ftw_func_t __func, int __descriptors) __MINGW_NONNULL((1, 2));
#else
  extern int ftw(const char *__dir, __ftw_func_t __func, int __descriptors) __MINGW_ASM_CALL(ftw64) __MINGW_NONNULL((1, 2));
#endif
#ifdef __MINGW_USE_LFS64
  typedef int (*__ftw64_func_t)(const char *__filename, const struct stat64 *__status, int __flag);
  extern int ftw64(const char *__dir, __ftw64_func_t __func, int __descriptors) __MINGW_NONNULL((1, 2));
#endif

#ifdef __MINGW_USE_XOPEN_EXT
  typedef int (*__nftw_func_t)(const char *__filename, const struct stat *__status, int __flag, struct FTW *__info);
# if !defined(__MINGW_USE_FOB64) || defined(_CRTBLD)
  extern int nftw(const char *__dir, __nftw_func_t __func, int __descriptors, int __flag) __MINGW_NONNULL((1, 2));
# else
  extern int nftw(const char *__dir, __nftw_func_t __func, int __descriptors, int __flag) __MINGW_ASM_CALL(nftw64) __MINGW_NONNULL((1, 2));
# endif
# ifdef __MINGW_USE_LFS64
  typedef int (*__nftw64_func_t)(const char *__filename, const struct stat64 *__status, int __flag, struct FTW *__info);
  extern int nftw64(const char *__dir, __nftw64_func_t __func, int __descriptors, int __flag) __MINGW_NONNULL((1, 2));
# endif
#endif

__MINGW_END_C_DECLS

#endif  /* _FTW_HXX */
