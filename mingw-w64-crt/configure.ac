#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
# Use AM_MAINTANER_MODE somewhere in this file once reconfigurations settle down.

AC_PREREQ([2.71])
AC_INIT([mingw-w64-runtime],[4.0b],[mingw-w64-public@lists.sourceforge.net])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_SRCDIR([ChangeLog])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([1.14 foreign subdir-objects])
AM_MAINTAINER_MODE

AC_CANONICAL_HOST

AC_MSG_CHECKING([for sysroot])
AC_ARG_WITH([sysroot],
  [AS_HELP_STRING([--with-sysroot=DIR],
    [Search for headers within DIR/include (default: prefix)])],
  [],
  [AS_VAR_SET([with_sysroot],[yes])])
AS_CASE([$with_sysroot],
  [no],[],
  [yes],[AS_VAR_SET([with_sysroot],[$prefix])],
  [])
AC_MSG_RESULT([$with_sysroot])
AS_VAR_IF([with_sysroot],[no],[],[AS_VAR_SET([TARGET_SYSTEM_ROOT],[$with_sysroot])])
AC_SUBST([TARGET_SYSTEM_ROOT])
AM_CONDITIONAL([WITHSYSROOT],[AS_VAR_TEST_SET([TARGET_SYSTEM_ROOT])])


# Checks for programs.
# Checks for headers, libs, etc need to utilize the sysroot... no idea how
AC_NO_EXECUTABLES
AC_PROG_SED
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CXX
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_RANLIB
AC_CHECK_TOOL([DLLTOOL], [dlltool], [:])
AM_PROG_AR
AM_PROG_AS
dnl Remove this once automake fixes the bug where AS is not defined according to $host
AC_CHECK_TOOL([AS], [as], [:])
dnl ---
AM_PROG_CC_C_O

AC_MSG_CHECKING([whether dlltool supports --temp-prefix])
cat > test.def <<EOF
LIBRARY test.dll
EXPORTS
myfunc
EOF

AS_VAR_SET([test_dlltool_flags],[])
AC_DEFUN([TEST_DLLTOOL], [
  test_dlltool_flags_save="$test_dlltool_flags"
  test_dlltool_flags="$test_dlltool_flags $1"
  AS_ECHO([["$DLLTOOL $test_dlltool_flags -d test.def -l libtest.a"]]) >&AS_MESSAGE_LOG_FD
  AS_IF($DLLTOOL $test_dlltool_flags -d test.def -l libtest.a >&AS_MESSAGE_LOG_FD 2>&AS_MESSAGE_LOG_FD, [
    $2
  ], [
    test_dlltool_flags="$test_dlltool_flags_save"
  ])
])

# First check if $DLLTOOL supports the -m option. LLVM dlltool might not
# have a default arch (in older versions), so make sure we specify one.
TEST_DLLTOOL([--as-flags=--64 -m i386:x86-64])
# Now check if --temp-prefix is supported. GNU dlltool supports it,
# LLVM dlltool doesn't, yet at least (but doesn't need it either).
AS_VAR_SET([dlltool_has_temp_prefix],[no])
TEST_DLLTOOL([--temp-prefix myprefix], [dlltool_has_temp_prefix=yes])

rm -f test.def libtest.a
AC_MSG_RESULT([$dlltool_has_temp_prefix])
AM_CONDITIONAL([DLLTOOL_HAS_TEMP_PREFIX],[test $dlltool_has_temp_prefix = yes])

AC_MSG_CHECKING([whether to build the Win64 libraries])
AC_ARG_ENABLE([lib64],
  [AS_HELP_STRING([--enable-lib64],
    [Build the Win64 libraries])],
  [],
  [
    _save_CFLAGS="$CFLAGS"
    CFLAGS="$CFLAGS -m64"
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[const char test[(sizeof(void*)==8)?0:-1];]],[])],
      [enable_lib64=yes],
      [enable_lib64=no])
    CFLAGS="$_save_CFLAGS"])
AC_MSG_RESULT([$enable_lib64])
AS_CASE([$enable_lib64],
  [no],[],
  [yes],[AS_VAR_SET([LIB64])],
  [AC_MSG_ERROR([invalid argument.  Must be either yes or no.])])
AM_CONDITIONAL([LIB64], [AS_VAR_TEST_SET([LIB64])])

AS_VAR_IF([enable_lib64],[yes],[
  AS_IF([AS_VAR_TEST_SET([LIBARM64])],
    [AC_MSG_WARN([Building the runtime to use lib64 with libarm64 is unsupported.])])])

AC_MSG_CHECKING([whether to build the WinARM64 libraries])
AC_ARG_ENABLE([libarm64],
  [AS_HELP_STRING([--enable-libarm64],
    [Build the WinARM64 libraries])],
  [],
  [AS_CASE([$host_cpu],
    [aarch64*],[enable_libarm64=yes],
    [*],[enable_libarm64=no])
  ])
AC_MSG_RESULT([$enable_libarm64])
AS_CASE([$enable_libarm64],
  [no],[],
  [yes],[AS_VAR_SET([LIBARM64])],
  [AC_MSG_ERROR([invalid argument.  Must be either yes or no.])])
AM_CONDITIONAL([LIBARM64], [AS_VAR_TEST_SET([LIBARM64])])

AS_VAR_IF([enable_libarm64],[yes],[
  AS_IF([AS_VAR_TEST_SET([LIB64])],
    [AC_MSG_WARN([Building the runtime to use libarm64 with lib64 is unsupported.])])])

AS_CASE([$host_cpu],
  [x86_64],[
    libx8664suffx=lib
    libarm64suffx=libarm64],
  [aarch64*],[
    libx8664suffx=libx8664
    libarm64suffx=lib],
  [
    libx8664suffx=libx8664
    libarm64suffx=libarm64]
)

AC_SUBST([LIBX8664SUFFIXDIR],[$libx8664suffx])
AC_SUBST([LIBARM64SUFFIXDIR],[$libarm64suffx])

# Checks for features.

AC_MSG_CHECKING([whether to enable globbing])
AC_ARG_ENABLE([wildcard],
  [AS_HELP_STRING([--enable-wildcard],
    [Enable command line globbing])],
  [],
  [enable_wildcard=no])
AS_CASE([$enable_wildcard],
  [yes],[enable_wildcard_value=-1],
  [no],[enable_wildcard_value=0],
  [AC_MSG_ERROR([Please only use --enable-wildcard or --disable-wildcard, without any additional arguments.])])
AC_DEFINE_UNQUOTED([__ENABLE_GLOBBING],[$enable_wildcard_value],[Define as -1 to enable command line globbing or 0 to disable it.])
AC_MSG_RESULT([$enable_wildcard])

AC_MSG_CHECKING([whether to enable delay import libs])
AC_ARG_ENABLE([delay-import-libs],
  [AS_HELP_STRING([--enable-delay-import-libs],
    [Enable creation of delay-import libraries])],
  [],
  [enable_delay_import_libs=no])
AS_CASE([$enable_delay_import_libs],
  [yes],[],
  [no],[],
  [AC_MSG_ERROR([Please only use --enable-delay-import-libs  or --disable-delay-import-libs, without any additional arguments.])])
AM_CONDITIONAL([DELAY_IMPORT_LIBS],[test $enable_delay_import_libs = yes])
AC_MSG_RESULT([$enable_delay_import_libs])

AC_MSG_CHECKING([whether to include support for Control Flow Guard])
AC_ARG_ENABLE([cfguard],
  [AS_HELP_STRING([--enable-cfguard],
    [Enable building with Control Flow Guard support (Clang)])],
  [],
  [AS_VAR_SET([enable_cfguard],[no])])
AC_MSG_RESULT([$enable_cfguard])
AS_CASE([$enable_cfguard],
  [no],[],
  [yes],[AS_VAR_SET([CFGUARD])
   AS_VAR_SET([CFGUARD_CFLAGS],[-mguard=cf])],
  [AC_MSG_ERROR([invalid argument.  Must be either yes or no.])])
AM_CONDITIONAL([CFGUARD], [AS_VAR_TEST_SET([CFGUARD])])
AC_SUBST([CFGUARD_CFLAGS])

AC_MSG_CHECKING([whether the compiler supports -municode])
AC_ARG_ENABLE([tests-unicode],
  [AS_HELP_STRING([--enable-tests-unicode],
    [Enable the unicode testsuite without testing the compiler for support.])],
  [],[
    saved_CFLAGS="$CFLAGS"
    CFLAGS="$CFLAGS -municode"
    AC_COMPILE_IFELSE([AC_LANG_SOURCE([[
#ifndef UNICODE
# error UNICODE not defined with -municode
#endif
    ]])],
    [enable_tests_unicode=yes],
    [enable_tests_unicode=no])
    CFLAGS="$saved_CFLAGS"])
AM_CONDITIONAL([ENABLE_TESTS_UNICODE],[test x$enable_tests_unicode = xyes])
AC_MSG_RESULT([$enable_tests_unicode])

# Check for __ImageBase linker symbol.
AC_MSG_CHECKING([whether the linker provides __ImageBase symbol])
# Run this test manually instead of wrapping it in AC_LINK_IFELSE; when
# bootstrapping an environment, an earlier linking test will have failed,
# which both causes autoconf to refuse to run any linker test at all,
# and even if $ac_no_link is overridden, the linker test iteslf will explicitly
# check that the linker actually produced output in the given output file.
# If $ac_exeext is empty, as it is when the earlier linker test failed, gcc
# will behave differently depending on version. If run with "gcc conftest.c
# -o conftest", old versions will produce explicitly a file named "conftest",
# while modern GCC versions will produce "conftest.exe". AC_LINK_IFELSE will
# explicitly look for the output file named "conftest$ac_exeext", which isn't
# found, and the test fails even though linking succeeded.
#
# Therefore, just do a manual test; run the linking command and check the return
# code whether it was successful or not.
#
# This test uses both mainCRTStartup and main functions, to let lld deduce
# entry point and subsystem automatically without having to manually specify,
# anything. And as long as main() is provided, we need to implicitly provide
# __main as well, since the compiler injects a call to it.

cat <<_ACEOF >conftest.$ac_ext
extern unsigned char __ImageBase[[]];
void __main(void) {
}
int main(void) {
  return __ImageBase[[0]];
}
int mainCRTStartup(void) {
  return main();
}
_ACEOF

echo "$as_me:$LINENO: $CC conftest.$ac_ext $LDFLAGS -nostdlib -o conftest$ac_exeext" >&AS_MESSAGE_LOG_FD
# Doing the link test with -nosdlib, to avoid trying to link in any libraries
# which might not exist yet at this point.
if $CC conftest.$ac_ext $LDFLAGS -nostdlib -o conftest$ac_exeext >&AS_MESSAGE_LOG_FD 2>&1; then
  ld_provides_imagebase=yes
else
  ld_provides_imagebase=no
fi
rm -f conftest$ac_exeext conftest.$ac_ext
AC_MSG_RESULT([$ld_provides_imagebase])
AS_CASE([$ld_provides_imagebase],
  [no],[AS_VAR_SET([IMAGEBASE_CFLAGS],["-D__ImageBase=__MINGW_LSYMBOL\(_image_base__\)"])],
  [AS_VAR_SET([IMAGEBASE_CFLAGS])])
AC_SUBST([IMAGEBASE_CFLAGS])

AC_CHECK_HEADER([_mingw_mac.h], [], [AC_MSG_ERROR([Please check if the mingw-w64 header set and the build/host option are set properly.])])

#Warnings and errors, default level is 3
AC_MSG_CHECKING([for warning levels])
AC_ARG_ENABLE([warnings],
  [AS_HELP_STRING([[--enable-warnings[=0-5]]],
    [Enable compile time warnings @<:@default=3@:>@])],
  [AS_CASE([$enableval],
    [yes], [warning_level=3],
    [no],  [warning_level=0],
    [[[0-5]]], [warning_level="$enableval"],
    [warning_level=3])],
  [warning_level=3])
AC_MSG_RESULT([Level $warning_level])

#Add warning flags as appropriate. Level 4 and above are only for testing purpose.
AS_CASE([$warning_level],
  [0],[ADD_C_CXX_WARNING_FLAGS="-Wall"],
  [1],[
    ADD_C_CXX_WARNING_FLAGS="-Wall -Wextra"
    ADD_C_ONLY_WARNING_FLAGS="-Wimplicit-function-declaration"],
  [2],[
    ADD_C_CXX_WARNING_FLAGS="-Wall -Wextra -Wformat -Wstrict-aliasing -Wshadow -Wpacked -Winline"
    ADD_C_ONLY_WARNING_FLAGS="-Wimplicit-function-declaration"],
  [3],[
    ADD_C_CXX_WARNING_FLAGS="-Wall -Wextra -Wformat -Wstrict-aliasing -Wshadow -Wpacked -Winline"
    ADD_C_ONLY_WARNING_FLAGS="-Wimplicit-function-declaration -Wmissing-noreturn -Wmissing-prototypes"],
  [4],[
    ADD_C_CXX_WARNING_FLAGS="-Wall -Wextra -Wformat -Wstrict-aliasing=2 -Wsystem-headers -Wshadow -Wmissing-declarations -Wpacked -Winline -Werror -pedantic"
    ADD_C_ONLY_WARNING_FLAGS="-Wimplicit-function-declaration -Wmissing-noreturn -Wmissing-prototypes"],
  [5],[
    ADD_C_CXX_WARNING_FLAGS="-Wall -Wextra -Wformat -Wstrict-aliasing=2 -Wsystem-headers -Wshadow -Wmissing-declarations -Wpacked -Wredundant-decls -Winline -Werror -Wfatal-errors -pedantic -pedantic-errors"
    ADD_C_ONLY_WARNING_FLAGS="-Wimplicit-function-declaration -Wmissing-noreturn -Wmissing-prototypes"]
   )

AC_SUBST(ADD_C_ONLY_WARNING_FLAGS)
AC_SUBST(ADD_C_CXX_WARNING_FLAGS)
AC_SUBST(ADD_CXX_ONLY_WARNING_FLAGS)

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

AC_MSG_NOTICE([])
AC_MSG_NOTICE([])
AC_MSG_NOTICE([])
AC_MSG_NOTICE([------------------------------------------------------------------------])
AC_MSG_NOTICE([$PACKAGE $VERSION])
AC_MSG_NOTICE([------------------------------------------------------------------------])
AC_MSG_NOTICE([])
AC_MSG_NOTICE([])
AC_MSG_NOTICE([Configuration Options Summary:])
AC_MSG_NOTICE([])
AC_MSG_NOTICE([  WinARM64 runtime.....: $enable_libarm64])
AC_MSG_NOTICE([  Win64 runtime........: $enable_lib64])
AC_MSG_NOTICE([  C Warning Flags......: $ADD_C_ONLY_WARNING_FLAGS])
AC_MSG_NOTICE([  C++ Warning Flags....: $ADD_CXX_ONLY_WARNING_FLAGS])
AC_MSG_NOTICE([  Common Warning Flags.: $ADD_C_CXX_WARNING_FLAGS])
AC_MSG_NOTICE([  Control Flow Guard...: $enable_cfguard])
AC_MSG_NOTICE([])


