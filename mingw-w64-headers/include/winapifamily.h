/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_WINAPIFAMILY
#define _INC_WINAPIFAMILY

#include <winpackagefamily.h>

#define WINAPI_FAMILY_PC_APP      2    /* Windows Store Applications */
#define WINAPI_FAMILY_PHONE_APP   3    /* Windows Phone Applications */
#define WINAPI_FAMILY_SYSTEM      4    /* Windows Drivers and Tools */
#define WINAPI_FAMILY_SERVER      5    /* Windows Server Applications */
#define WINAPI_FAMILY_GAMES       6    /* Windows Games and Applications */
#define WINAPI_FAMILY_DESKTOP_APP 100  /* Windows Desktop Applications */

#define WINAPI_FAMILY_APP WINAPI_FAMILY_PC_APP

/* WINAPI_FAMILY can be either desktop + App, or App.  */
#ifndef WINAPI_FAMILY
# define WINAPI_FAMILY WINAPI_FAMILY_DESKTOP_APP
#endif

#if WINAPI_FAMILY != WINAPI_FAMILY_DESKTOP_APP && \
    WINAPI_FAMILY != WINAPI_FAMILY_PC_APP &&      \
    WINAPI_FAMILY != WINAPI_FAMILY_PHONE_APP &&   \
    WINAPI_FAMILY != WINAPI_FAMILY_SYSTEM &&      \
    WINAPI_FAMILY != WINAPI_FAMILY_GAMES &&       \
    WINAPI_FAMILY != WINAPI_FAMILY_SERVER
# error Unknown WINAPI_FAMILY value. Was it defined in terms of a WINAPI_PARTITION_* value?
#endif

/* Desktop Win32 apps (but not store apps) */
#ifndef WINAPI_PARTITION_DESKTOP
# define WINAPI_PARTITION_DESKTOP (WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP)
#endif

/* Windows Universal store apps */
#ifndef WINAPI_PARTITION_APP
# define WINAPI_PARTITION_APP (WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP || \
    WINAPI_FAMILY == WINAPI_FAMILY_PC_APP                                 || \
    WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP)
#endif

/* Desktop-only store apps */
#ifndef WINAPI_PARTITION_PC_APP
# define WINAPI_PARTITION_PC_APP (WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP || WINAPI_FAMILY == WINAPI_FAMILY_PC_APP)
#endif

/* Phone-only store apps */
#ifndef WINAPI_PARTITION_PHONE_APP
# define WINAPI_PARTITION_PHONE_APP (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP)
#endif

/* Games and apps */
#ifndef WINAPI_PARTITION_GAMES
# define WINAPI_PARTITION_GAMES (WINAPI_FAMILY == WINAPI_FAMILY_GAMES || WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP)
#endif

/* System applications */
#ifndef WINAPI_PARTITION_SYSTEM
# define WINAPI_PARTITION_SYSTEM (WINAPI_FAMILY == WINAPI_FAMILY_SYSTEM || WINAPI_FAMILY == WINAPI_FAMILY_SERVER)
#endif

/* Windows Phone 8 */
#define WINAPI_PARTITION_PHONE WINAPI_PARTITION_PHONE_APP

#define WINAPI_FAMILY_PARTITION(v) (v)

#endif  /* _INC_WINAPIFAMILY */
