/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _SYS_CDEFS_H
#define _SYS_CDEFS_H

#include <corecrt.h>

#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS   }
#else
# define __BEGIN_DECLS
# define __END_DECLS
#endif

#define __P(protos) protos  /* full-blown ANSI C */

#endif  /* _SYS_CDEFS_H */
