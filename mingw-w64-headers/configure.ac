#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([mingw-w64-headers],[4.0b],[mingw-w64-public@lists.sourceforge.net])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([foreign])
AM_MAINTAINER_MODE

AC_CANONICAL_HOST

# Checks for programs.
AC_PROG_SED

# Search for a usable widl.  If PATH is given, search there.  Otherwise, search
# in $PATH.  In all cases, search for a canonicalized name first ($host-widl),
# followed by a non-canonicalized name (widl).  If these fail, error out.
# NB: $host from this perspective is the same as $target while building widl.
AC_MSG_CHECKING([whether to rebuild headers with widl])
AC_ARG_WITH([widl],
  AS_HELP_STRING([--with-widl=PATH],
    [use widl to update idl-based headers.  Optionally search for a compatible widl in PATH]),
  [AS_VAR_IF([with_widl],[yes],[AS_VAR_SET([with_widl],["$PATH"])])],
  [AS_VAR_SET([with_widl],[no])])
AC_MSG_RESULT([$with_widl])

AS_VAR_IF([with_widl],[no],[],[
  AS_VAR_IF([srcdir],[.],[],
    [AC_MSG_WARN([--with-widl used in out of the tree compilation.  Existing generated files will not be modified.])])
  AC_PATH_PROGS([WIDL], [$host-widl widl], [], [$with_widl])
  AS_VAR_IF([WIDL],[],[AC_MSG_ERROR([--with-widl is specified, but widl installation could not be found.])])])

AM_CONDITIONAL([HAVE_WIDL],[AS_VAR_TEST_SET([WIDL])])

# Checks for header files.

BASEHEAD_LIST="crt/_bsd_types.h crt/_mingw.h crt/_mingw_mac.h crt/_mingw_unicode.h crt/_timeval.h crt/crtdefs.h crt/corecrt.h crt/excpt.h crt/intrin.h crt/vadefs.h crt/tchar.h "$srcdir/include/*.h
for i in c inl dlg h16 hxx rh ver; do
  BASEHEAD_LIST="$BASEHEAD_LIST "$srcdir/include/*.$i
done

BASEHEAD_LIST="$BASEHEAD_LIST "$srcdir/crt/*.h
SYSHEAD_LIST=$srcdir/crt/sys/*.h
GDIPLUSHEAD_LIST=$srcdir/include/gdiplus/*.h
WRLHEAD_LIST=$srcdir/include/wrl/*.h
WRLWRAPPERSHEAD_LIST=$srcdir/include/wrl/wrappers/*.h
GLHEAD_LIST=$srcdir/include/GL/*.h
KHRHEAD_LIST=$srcdir/include/KHR/*.h
MINGWHELPERHEAD_LIST=$srcdir/include/psdk_inc/*.h
AC_SUBST([BASEHEAD_LIST])
AC_SUBST([GDIPLUSHEAD_LIST])
AC_SUBST([WRLHEAD_LIST])
AC_SUBST([WRLWRAPPERSHEAD_LIST])
AC_SUBST([GLHEAD_LIST])
AC_SUBST([KHRHEAD_LIST])
AC_SUBST([MINGWHELPERHEAD_LIST])
AC_SUBST([SYSHEAD_LIST])

AC_MSG_CHECKING([for optional sdk headers])
AC_ARG_ENABLE([sdk],
  [AS_HELP_STRING([--enable-sdk=ARG],
    [Add the desired SDK, where ARG can be one of ddk, no or all.  Default is all.])],
  [],
  [AS_VAR_SET([enable_sdk],[all])])

AS_CASE([$enable_sdk],
  [all|yes],[
    AS_VAR_SET([enable_sdk],[ddk])
    AS_VAR_SET([enable_ddk],[yes])],
  [ddk],[
    AS_VAR_SET([enable_ddk],[yes])],
  [directx],[
    AC_MSG_WARN([Deprecated option: directx.  directx headers are always enabled.])],
  [no],[],
  [AC_MSG_ERROR([Invalid option: $enable_sdk.  Please choose one of ddk, no or all.])])
AC_MSG_RESULT([$enable_sdk])

AS_VAR_IF([enable_ddk],[yes],[
    DDKHEAD_LIST=$srcdir/ddk/include/ddk/*.h
    MINGW_HAS_DDK=1
  ],[
    MINGW_HAS_DDK=0
  ])
AC_SUBST([DDKHEAD_LIST])
AC_SUBST([MINGW_HAS_DDK])

AC_MSG_CHECKING([if installing idl files is enabled])
AC_ARG_ENABLE([idl],
    [AS_HELP_STRING([--enable-idl],
        [Enable installing idl files])],
    [],
    [enable_idl=no])
AC_MSG_RESULT([$enable_idl])
AS_VAR_IF([enable_idl],[yes],
    [IDLHEAD_LIST=$srcdir/include/*.idl" "$srcdir/tlb/*.tlb],
    [IDLHEAD_LIST=""])
AC_SUBST([IDLHEAD_LIST])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([
  Makefile
])
AC_OUTPUT

