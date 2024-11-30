if WITHSYSROOT
  sysincludes="-I@TARGET_SYSTEM_ROOT@/include"
  withsys="--with-sysroot=@TARGET_SYSTEM_ROOT@"
else
  sysincludes=
  withsys=
endif

AM_CPPFLAGS=$(sysincludes)
AM_CFLAGS=-pipe -std=gnu17 -D_CRTBLD -D_WIN32_WINNT=0x0A00 @IMAGEBASE_CFLAGS@ @CFGUARD_CFLAGS@ @ADD_C_CXX_WARNING_FLAGS@ @ADD_C_ONLY_WARNING_FLAGS@
AM_CXXFLAGS=@ADD_C_CXX_WARNING_FLAGS@ @ADD_CXX_ONLY_WARNING_FLAGS@
CPPFLAGSARM64=
CPPFLAGS64=-m64 -masm=att
AM_DLLTOOLFLAGS=-k --as=$(AS) --output-lib $@
DLLTOOLFLAGSARM64=-m arm64
DLLTOOLFLAGS64=--as-flags=--64 -m i386:x86-64
DTDEFARM64=$(DLLTOOL) $(DLLTOOLFLAGSARM64) $(AM_DLLTOOLFLAGS) --input-def
DTDEF64=$(DLLTOOL) $(DLLTOOLFLAGS64) $(AM_DLLTOOLFLAGS) --input-def
if DLLTOOL_HAS_TEMP_PREFIX
  AM_DLLTOOLFLAGS += --temp-prefix $(basename $@)
endif
if DELAY_IMPORT_LIBS
  AM_DLLTOOLFLAGS += --output-delaylib $@.delayimp.a
endif
DTLIBARM64=$(DTDEFARM64) $(top_srcdir)/`echo $@ | $(SED) 's|/lib|/|;s|\.a|.def|'`
DTLIB64=$(DTDEF64) $(top_srcdir)/`echo $@ | $(SED) 's|/lib|/|;s|\.a|.def|'`
LDFLAGSARM64= -L$(top_builddir)/libarm64
LDFLAGS64=-m64 -L$(top_builddir)/lib64
extra_include=-I$(top_srcdir)/include
processed_defs=

noinst_LIBRARIES =

# default directx import library names
xinput=xinput1_4
xapofx=xapofx1_5
x3daudio=x3daudio1_7
d3dx9=d3dx9_43
d3dx10=d3dx10_43
d3dx11=d3dx11_43
d3dcompiler=d3dcompiler_47

# can move this into libsrc/dummy_libm.c or similar
BUILT_SOURCES = _libm_dummy.c
_libm_dummy.c:
	echo "static int __attribute__((unused)) __mingw_libm_dummy;" > _libm_dummy.c

src_libm=_libm_dummy.c

src_libbits=libsrc/bits.c
src_libshell32=libsrc/shell32.c
src_libdinput=libsrc/dinput_joy.c libsrc/dinput_joy2.c libsrc/dinput_kbd.c libsrc/dinput_mouse.c libsrc/dinput_mouse2.c
src_libdinput8=$(src_libdinput)
src_libdmoguids=libsrc/dmoguids.c
src_libdxerr8=libsrc/dxerr8.c libsrc/dxerr8w.c
src_libdxerr9=libsrc/dxerr9.c libsrc/dxerr9w.c
src_libmfuuid=libsrc/mfuuid.c
src_libmsxml2=libsrc/msxml2.c
src_libmsxml6=libsrc/msxml6.c
src_libamstrmid=libsrc/amstrmid.c
src_libwbemuuid=libsrc/wbemuuid.c
src_libwmcodecdspuuid=libsrc/wmcodecdspuuid.c
src_libwindowscodecs=libsrc/windowscodecs.c
src_libdxguid=libsrc/dxguid.c
src_libksuser=libsrc/ksuser.c
src_libksguid=$(src_libksuser)
src_liblargeint=libsrc/largeint.c
src_liblocationapi=libsrc/locationapi.c
src_libsapi=libsrc/sapi.c
src_libsensorsapi=libsrc/sensorsapi.c
src_libportabledeviceguids=libsrc/portabledeviceguids.c
src_libtaskschd=libsrc/taskschd.c
src_libntoskrnl=libsrc/memcmp.c
src_libdloadhelper=libsrc/dloadhelper.c misc/delay-f.c

src_libmingw32=\
  crt/_newmode.c       crt/charmax.c     crt/cinitexe.c           crt/CRT_fp8.c       crt/crt_handler.c        \
  crt/crtexewin.c      crt/cxa_atexit.c  crt/cxa_thread_atexit.c  crt/dll_argv.c      crt/dllargv.c            \
  crt/exit_wrappers.c  crt/gccmain.c     crt/merr.c               crt/mingw_custom.c  crt/mingw_helpers.c      \
  crt/natstart.c       crt/pesect.c      crt/pseudo-reloc-list.c  crt/pseudo-reloc.c  crt/tls_atexit.c         \
  crt/tlsmcrt.c        crt/tlsmthread.c  crt/tlssup.c             crt/tlsthrd.c       crt/ucrt_exit_wrappers.c \
  crt/ucrtexewin.c     crt/udll_argv.c   crt/udllargc.c           crt/usermatherr.c   crt/wildcard.c           \
  crt/xncommod.c       crt/xthdloc.c     crt/xtxtmode.c

src_libscrnsave=libsrc/scrnsave.c
src_libscrnsavw=$(src_libscrnsave)
src_libstrmiids=libsrc/strmiids.c
src_libmingwthrd=libsrc/mingwthrd_mt.c

src_libgdiplus=libsrc/gdiplus.c

src_adsiid=libsrc/activeds-uuid.c

src_libuuid=\
  libsrc/ativscp-uuid.c   libsrc/atsmedia-uuid.c  libsrc/bth-uuid.c       libsrc/cguid-uuid.c        libsrc/comcat-uuid.c   \
  libsrc/ctxtcall-uuid.c  libsrc/devguid.c        libsrc/docobj-uuid.c    libsrc/dxva-uuid.c         libsrc/exdisp-uuid.c   \
  libsrc/extras-uuid.c    libsrc/fwp-uuid.c       libsrc/guid_nul.c       libsrc/hlguids-uuid.c      libsrc/hlink-uuid.c    \
  libsrc/mlang-uuid.c     libsrc/msctf-uuid.c     libsrc/mshtmhst-uuid.c  libsrc/mshtml-uuid.c       libsrc/msxml-uuid.c    \
  libsrc/netcfg-uuid.c    libsrc/netcon-uuid.c    libsrc/ntddkbd-uuid.c   libsrc/ntddmou-uuid.c      libsrc/ntddpar-uuid.c  \
  libsrc/ntddscsi-uuid.c  libsrc/ntddser-uuid.c   libsrc/ntddstor-uuid.c  libsrc/ntddvdeo-uuid.c     libsrc/oaidl-uuid.c    \
  libsrc/objidl-uuid.c    libsrc/objsafe-uuid.c   libsrc/ocidl-uuid.c     libsrc/oleacc-uuid.c       libsrc/olectlid-uuid.c \
  libsrc/oleidl-uuid.c    libsrc/power-uuid.c     libsrc/powrprof-uuid.c  libsrc/uianimation-uuid.c  libsrc/usbcamdi-uuid.c \
  libsrc/usbiodef-uuid.c  libsrc/uuid.c           libsrc/vds-uuid.c       libsrc/virtdisk-uuid.c     libsrc/vss-uuid.c      \
  libsrc/wia-uuid.c       libsrc/windowscodecs.c

src_libws2_32=\
  libsrc/ws2_32.c                                        \
  \
  libsrc/ws2tcpip/gai_strerrorA.c                        libsrc/ws2tcpip/gai_strerrorW.c                      libsrc/ws2tcpip/in6_addr_equal.c           \
  libsrc/ws2tcpip/in6_is_addr_anycast.c                  libsrc/ws2tcpip/in6_is_addr_eui64.c                  libsrc/ws2tcpip/in6_is_addr_global.c       \
  libsrc/ws2tcpip/in6_is_addr_linklocal.c                libsrc/ws2tcpip/in6_is_addr_loopback.c               libsrc/ws2tcpip/in6_is_addr_mc_global.c    \
  libsrc/ws2tcpip/in6_is_addr_mc_linklocal.c             libsrc/ws2tcpip/in6_is_addr_mc_nodelocal.c           libsrc/ws2tcpip/in6_is_addr_mc_orglocal.c  \
  libsrc/ws2tcpip/in6_is_addr_mc_sitelocal.c             libsrc/ws2tcpip/in6_is_addr_multicast.c              libsrc/ws2tcpip/in6_is_addr_sitelocal.c    \
  libsrc/ws2tcpip/in6_is_addr_subnet_reserved_anycast.c  libsrc/ws2tcpip/in6_is_addr_subnet_router_anycast.c  libsrc/ws2tcpip/in6_is_addr_unspecified.c  \
  libsrc/ws2tcpip/in6_is_addr_v4compat.c                 libsrc/ws2tcpip/in6_is_addr_v4mapped.c               libsrc/ws2tcpip/in6_is_addr_v4translated.c \
  libsrc/ws2tcpip/in6_set_addr_loopback.c                libsrc/ws2tcpip/in6_set_addr_unspecified.c           libsrc/ws2tcpip/in6addr_isany.c            \
  libsrc/ws2tcpip/in6addr_isequal.c                      libsrc/ws2tcpip/in6addr_isloopback.c                 libsrc/ws2tcpip/in6addr_isunspecified.c    \
  libsrc/ws2tcpip/in6addr_setany.c                       libsrc/ws2tcpip/in6addr_setloopback.c                \
  \
  libsrc/wspiapi/WspiapiClone.c                          libsrc/wspiapi/WspiapiFreeAddrInfo.c                 libsrc/wspiapi/WspiapiGetAddrInfo.c        \
  libsrc/wspiapi/WspiapiGetNameInfo.c                    libsrc/wspiapi/WspiapiLegacyFreeAddrInfo.c           libsrc/wspiapi/WspiapiLegacyGetAddrInfo.c  \
  libsrc/wspiapi/WspiapiLegacyGetNameInfo.c              libsrc/wspiapi/WspiapiLoad.c                         libsrc/wspiapi/WspiapiLookupNode.c         \
  libsrc/wspiapi/WspiapiNewAddrInfo.c                    libsrc/wspiapi/WspiapiParseV4Address.c               libsrc/wspiapi/WspiapiQueryDNS.c           \
  libsrc/wspiapi/WspiapiStrdup.c

# Files included in libucrt*.a
src_ucrtbase=\
  math/_huge.c               math/frexpf.c             math/ldexpf.c              math/lgamma.c            math/lgammaf.c              \
  math/modfl.c               math/signgam.c            \
  \
  misc/__badioinfo.c         misc/__initenv.c          misc/__p___initenv.c       misc/__p___winitenv.c    misc/__p__osplatform_emul.c \
  misc/__p__osver_emul.c     misc/__winitenv.c         misc/_onexit.c             misc/output_format.c     misc/ucrt__getmainargs.c    \
  misc/ucrt__wgetmainargs.c  misc/ucrt_amsg_exit.c     misc/ucrt_at_quick_exit.c  misc/ucrt_tzset.c        misc/ucrt-access.c          \
  \
  stdio/ucrt__scprintf.c     stdio/ucrt__snprintf.c    stdio/ucrt__snscanf.c      stdio/ucrt__snwprintf.c  stdio/ucrt__vscprintf.c     \
  stdio/ucrt__vsnprintf.c    stdio/ucrt__vsnwprintf.c  string/ucrt__wcstok.c      stdio/ucrt_fprintf.c     stdio/ucrt_fscanf.c         \
  stdio/ucrt_fwprintf.c      stdio/ucrt_printf.c       stdio/ucrt_scanf.c         stdio/ucrt_snprintf.c    stdio/ucrt_sprintf.c        \
  stdio/ucrt_sscanf.c        stdio/ucrt_vfprintf.c     stdio/ucrt_vfscanf.c       stdio/ucrt_vprintf.c     stdio/ucrt_vscanf.c         \
  stdio/ucrt_vsnprintf.c     stdio/ucrt_vsprintf.c     stdio/ucrt_vsscanf.c

# Files included in libucrtapp.a
src_ucrtapp=\
  misc/__C_specific_handler.c  misc/longjmp.S   misc/setjmp.S    \
  \
  string/memchr.c              string/memcmp.c  string/memcpy.c  string/memmove.c  string/strchr.c \
  string/strrchr.c             string/strstr.c  string/wcschr.c  string/wcsrchr.c  string/wcsstr.c

# Files included in libucrt*.a on x86_64
src_ucrtbase64=\
  $(src_ucrtbase)  math/x64/fabsf.c  math/x64/ldexp.c  math/x64/scalbn.S  math/x64/scalbnf.S


# Files included in libucrt*.a on ARM64
src_ucrtbasearm64=$(src_ucrtbase) math/arm64/scalbn.c

# These mingwex sources are target independent:
src_libmingwex=\
  cfguard/mingw_cfguard_support.c  \
  \
  complex/cabs.c                   complex/cabsf.c       complex/cabsl.c           complex/cacos.c        complex/cacosf.c          \
  complex/cacosl.c                 complex/carg.c        complex/cargf.c           complex/cargl.c        complex/casin.c           \
  complex/casinf.c                 complex/casinl.c      complex/catan.c           complex/catanf.c       complex/catanl.c          \
  complex/ccos.c                   complex/ccosf.c       complex/ccosl.c           complex/cexp.c         complex/cexpf.c           \
  complex/cexpl.c                  complex/cimag.c       complex/cimagf.c          complex/cimagl.c       complex/clog.c            \
  complex/clog10.c                 complex/clog10f.c     complex/clog10l.c         complex/clogf.c        complex/clogl.c           \
  complex/conj.c                   complex/conjf.c       complex/conjl.c           complex/cpow.c         complex/cpowf.c           \
  complex/cpowl.c                  complex/cproj.c       complex/cprojf.c          complex/cprojl.c       complex/creal.c           \
  complex/crealf.c                 complex/creall.c      complex/csin.c            complex/csinf.c        complex/csinl.c           \
  complex/csqrt.c                  complex/csqrtf.c      complex/csqrtl.c          complex/ctan.c         complex/ctanf.c           \
  complex/ctanl.c                  complex/norm.c        complex/normf.c           complex/norml.c        \
  \
  math/fpclassify.c                math/fpclassifyf.c    math/isnan.c              math/isnanf.c          math/signbit.c            \
  math/signbitf.c                  \
  \
  misc/a64l.c                      misc/alarm.c          misc/arc4random.c         misc/arc4random_buf.c  misc/arc4random_uniform.c \
  misc/clearenv.c                  misc/delay-f.c        misc/delay-n.c            misc/delayimp.c        misc/dirent.c             \
  misc/dirname.c                   misc/dllentrypoint.c  misc/dllmain.c            misc/ftruncate.c       misc/ftruncate64.c        \
  misc/ftw.c                       misc/ftw64.c          misc/fwide.c              misc/getentropy.c      misc/getlogin.c           \
  misc/getopt.c                    misc/gettimeofday.c   misc/insque.c             misc/l64a.c            misc/mempcpy.c            \
  misc/mingw_getsp.S               misc/mingw_longjmp.S  misc/mingw_matherr.c      misc/mingw_usleep.c    misc/mkdtemp.c            \
  misc/mkstemp.c                   misc/mkstemps.c       misc/qsort_r.c            misc/realpath.c        misc/setenv.c             \
  misc/sleep.c                     misc/strsafe.c        misc/tdelete.c            misc/tdestroy.c        misc/tfind.c              \
  misc/tsearch.c                   misc/twalk.c          misc/unsetenv.c           misc/wdirent.c         misc/wmemchr.c            \
  misc/wmemcmp.c                   misc/wmemcpy.c        misc/wmemmove.c           misc/wmempcpy.c        misc/wmemset.c            \
  \
  ssp/chk_fail.c                   ssp/gets_chk.c        ssp/memcpy_chk.c          ssp/memmove_chk.c      ssp/mempcpy_chk.c         \
  ssp/memset_chk.c                 ssp/stack_chk_fail.c  ssp/stack_chk_guard.c     ssp/stpcpy_chk.c       ssp/strcat_chk.c          \
  ssp/strcpy_chk.c                 ssp/strncat_chk.c     ssp/strncpy_chk.c         \
  \
  stdio/asprintf.c                 stdio/truncate.c      stdio/vasprintf.c         \
  \
  string/bcopy.c                   string/bzero.c        string/explicit_bzero.c   string/ffs.c           string/ffsll.c            \
  string/memmem.c                  string/memrchr.c      string/memset_explicit.c  string/memset_s.c      string/stpcpy.c           \
  string/stpncpy.c                 string/strcasestr.c   string/strchrnul.c        string/strerror_r.c    string/strlcat.c          \
  string/strlcpy.c                 string/strndup.c      string/strsep.c           string/strverscmp.c    string/xsi_strerror_r.c   \
  \
  time/asctime_r.c                 time/clock.c          time/ctime_r.c            time/gmtime_r.c        time/localtime_r.c        \
  time/nanosleep.c

# Include the default load config struct only for Control Flow Guard support.
if CFGUARD
src_libmingwex+=\
  cfguard/mingw_cfguard_loadcfg.S
endif

# these only go into the x86_64 version:
src_libmingwex64=math/x64/sincos.c

# these only go into the ARM64 version:
src_libmingwexarm64=math/arm64/sincos.S  math/arm64/sincosf.S

# These intrinsics are target independent:
src_intrincs= \
  intrincs/__int2c.c         intrincs/__movsb.c       intrincs/__movsd.c         intrincs/__movsw.c              intrincs/__stosb.c       \
  intrincs/__stosd.c         intrincs/__stosw.c       intrincs/_rotl64.c         intrincs/_rotr64.c              intrincs/bitscanfwd.c    \
  intrincs/bitscanrev.c      intrincs/bittest.c       intrincs/bittestc.c        intrincs/bittestci.c            intrincs/bittestr.c      \
  intrincs/bittestri.c       intrincs/bittests.c      intrincs/bittestsi.c       intrincs/cpuid.c                intrincs/ilockadd.c      \
  intrincs/ilockand.c        intrincs/ilockand64.c    intrincs/ilockcxch.c       intrincs/ilockcxch16.c          intrincs/ilockcxch64.c   \
  intrincs/ilockcxchptr.c    intrincs/ilockdec.c      intrincs/ilockdec16.c      intrincs/ilockdec64.c           intrincs/ilockexch.c     \
  intrincs/ilockexch64.c     intrincs/ilockexchadd.c  intrincs/ilockexchadd64.c  intrincs/ilockexchptr.c         intrincs/ilockinc.c      \
  intrincs/ilockinc16.c      intrincs/ilockinc64.c    intrincs/ilockor.c         intrincs/ilockor64.c            intrincs/ilockxor.c      \
  intrincs/ilockxor64.c      intrincs/inbyte.c        intrincs/inbytestring.c    intrincs/indword.c              intrincs/indwordstring.c \
  intrincs/inword.c          intrincs/inwordstring.c  intrincs/outbyte.c         intrincs/outbytestring.c        intrincs/outdword.c      \
  intrincs/outdwordstring.c  intrincs/outword.c       intrincs/outwordstring.c   intrincs/readcr0.c              intrincs/readcr2.c       \
  intrincs/readcr3.c         intrincs/readcr4.c       intrincs/readmsr.c         intrincs/RtlSecureZeroMemory.c  intrincs/writecr0.c      \
  intrincs/writecr2.c        intrincs/writecr3.c      intrincs/writecr4.c        intrincs/writemsr.c

# these only go into the x86_64 version:
src_intrincs64=\
  intrincs/__faststorefence.c  intrincs/__movsq.c      intrincs/__shiftleft128.c  intrincs/__shiftright128.c  intrincs/__stosq.c     \
  intrincs/_mul128.c           intrincs/_umul128.c     intrincs/bitscanfwd64.c    intrincs/bitscanrev64.c     intrincs/bittest64.c   \
  intrincs/bittestc64.c        intrincs/bittestci64.c  intrincs/bittestr64.c      intrincs/bittestri64.c      intrincs/bittests64.c  \
  intrincs/bittestsi64.c       intrincs/ilockadd64.c   intrincs/mul128ex.c        intrincs/rdtsc.c            intrincs/readcr8.c     \
  intrincs/readgsbyte.c        intrincs/readgsdword.c  intrincs/readgsqword.c     intrincs/readgsword.c       intrincs/umul128ex.c   \
  intrincs/writecr8.c          intrincs/writegsbyte.c  intrincs/writegsdword.c    intrincs/writegsqword.c     intrincs/writegsword.c

# these only go into the ARM64 version:
src_intrincsarm64=

if LIB64
#########################################################################
# Compiling 64-bit runtime
# #######################################################################

lib64dir=$(prefix)/@LIBX8664SUFFIXDIR@
crt64dir=$(lib64dir)
winrt64dir=$(lib64dir)
dx64dir=$(lib64dir)

crt64_DATA = \
  lib64/binmode.o  lib64/CRT_fp10.o  lib64/CRT_fp8.o   lib64/CRT_glob.o  lib64/CRT_noglob.o \
  lib64/crt2.o     lib64/crt2u.o     lib64/crtbegin.o  lib64/crtend.o    lib64/dllcrt2.o    \
  lib64/gcrt2.o    lib64/txtmode.o

COMPILE64=$(COMPILE) $(CPPFLAGS64) $(extra_include) -D_SYSCRT=1 -DCRTDLL=1
lib64/crt2.o: crt/crtexe.c
	$(COMPILE64) -c $< -o $@
lib64/crt2u.o: crt/ucrtexe.c
	$(COMPILE64) -c $< -o $@
lib64/dllcrt2.o: crt/crtdll.c
	$(COMPILE64) -c $< -o $@

lib64/gcrt2.o: profile/gcrt0.c
	$(COMPILE) $(CPPFLAGS64) -c $< -o $@

lib64/%.o: crt/%.c
	$(COMPILE) $(CPPFLAGS64) -c $< -o $@

lib64_LIBRARIES = lib64/libkernel32.a
lib64_libkernel32_a_SOURCES = $(src_intrincs) $(src_intrincs64) lib-common/kernel32.def.in
lib64_libkernel32_a_CPPFLAGS=$(CPPFLAGS64) $(extra_include) $(AM_CPPFLAGS)
lib64_libkernel32_a_AR = $(DTDEF64) lib64/kernel32.def && $(AR) $(ARFLAGS)
EXTRA_lib64_libkernel32_a_DEPENDENCIES=lib64/kernel32.def

lib64_DATA =
lib64_DATA += lib64/libmsvcrt.a
lib64/libmsvcrt.a: lib64/libucrt.a
	cp $< $@

lib64_LIBRARIES += lib64/libbits.a
lib64_libbits_a_SOURCES = $(src_libbits)
lib64_libbits_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libshell32.a
lib64_libshell32_a_SOURCES = $(src_libshell32)
lib64_libshell32_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)
lib64_libshell32_a_AR = $(DTDEF64) $(top_srcdir)/lib-common/shell32.def && $(AR) $(ARFLAGS)

lib64_LIBRARIES += lib64/libdinput.a
lib64_libdinput_a_SOURCES = $(src_libdinput)
lib64_libdinput_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)
lib64_libdinput_a_AR = $(DTDEF64) $(top_srcdir)/lib-common/dinput.def && $(AR) $(ARFLAGS)

lib64_LIBRARIES += lib64/libdinput8.a
lib64_libdinput8_a_SOURCES = $(src_libdinput8)
lib64_libdinput8_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)
lib64_libdinput8_a_AR = $(DTDEF64) $(top_srcdir)/lib-common/dinput8.def && $(AR) $(ARFLAGS)

lib64_LIBRARIES += lib64/libdmoguids.a
lib64_libdmoguids_a_SOURCES = $(src_libdmoguids)
lib64_libdmoguids_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libdxerr8.a
lib64_libdxerr8_a_SOURCES = $(src_libdxerr8)
lib64_libdxerr8_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libdxerr9.a
lib64_libdxerr9_a_SOURCES = $(src_libdxerr9)
lib64_libdxerr9_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libmsxml2.a
lib64_libmsxml2_a_SOURCES = $(src_libmsxml2)
lib64_libmsxml2_a_CPPFLAGS = $(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libmsxml6.a
lib64_libmsxml6_a_SOURCES = $(src_libmsxml6)
lib64_libmsxml6_a_CPPFLAGS = $(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libmfuuid.a
lib64_libmfuuid_a_SOURCES = $(src_libmfuuid)
lib64_libmfuuid_a_CPPFLAGS = $(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libamstrmid.a
lib64_libamstrmid_a_SOURCES = $(src_libamstrmid)
lib64_libamstrmid_a_CPPFLAGS = $(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libwmcodecdspuuid.a
lib64_libwmcodecdspuuid_a_SOURCES = $(src_libwmcodecdspuuid)
lib64_libwmcodecdspuuid_a_CPPFLAGS = $(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libwindowscodecs.a
lib64_libwindowscodecs_a_SOURCES = $(src_libwindowscodecs)
lib64_libwindowscodecs_a_CPPFLAGS = $(CPPFLAGS64) $(sysincludes)
lib64_libwindowscodecs_a_AR = $(DTDEF64) $(top_srcdir)/lib-common/windowscodecs.def && $(AR) $(ARFLAGS)

lib64_LIBRARIES += lib64/libwbemuuid.a
lib64_libwbemuuid_a_SOURCES = $(src_libwbemuuid)
lib64_libwbemuuid_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libdxguid.a
lib64_libdxguid_a_SOURCES = $(src_libdxguid)
lib64_libdxguid_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/liblocationapi.a
lib64_liblocationapi_a_SOURCES = $(src_liblocationapi)
lib64_liblocationapi_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libsapi.a
lib64_libsapi_a_SOURCES = $(src_libsapi)
lib64_libsapi_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libsensorsapi.a
lib64_libsensorsapi_a_SOURCES = $(src_libsensorsapi)
lib64_libsensorsapi_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libportabledeviceguids.a
lib64_libportabledeviceguids_a_SOURCES = $(src_libportabledeviceguids)
lib64_libportabledeviceguids_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libksuser.a
lib64_libksuser_a_SOURCES = $(src_libksuser)
lib64_libksuser_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)
lib64_libksuser_a_AR = $(DTDEF64) $(top_srcdir)/lib-common/ksuser.def && $(AR) $(ARFLAGS)

lib64_LIBRARIES += lib64/libksguid.a
lib64_libksguid_a_SOURCES = $(src_libksguid)
lib64_libksguid_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libscrnsave.a
lib64_libscrnsave_a_SOURCES = $(src_libscrnsave)
lib64_libscrnsave_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libscrnsavw.a
lib64_libscrnsavw_a_SOURCES = libsrc/scrnsave.c
lib64_libscrnsavw_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)
lib64_libscrnsavw_a_CFLAGS = -DUNICODE

lib64_LIBRARIES += lib64/libstrmiids.a
lib64_libstrmiids_a_SOURCES = $(src_libstrmiids)
lib64_libstrmiids_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libuuid.a
lib64_libuuid_a_SOURCES = $(src_libuuid)
lib64_libuuid_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libgdiplus.a
lib64_libgdiplus_a_SOURCES = $(src_libgdiplus)
lib64_libgdiplus_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)
lib64_libgdiplus_a_AR = $(DTDEF64) $(top_srcdir)/lib-common/gdiplus.def && $(AR) $(ARFLAGS)

lib64_LIBRARIES += lib64/libws2_32.a
lib64_libws2_32_a_SOURCES = $(src_libws2_32) lib-common/ws2_32.def.in
lib64_libws2_32_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)
lib64_libws2_32_a_AR = $(DTDEF64) lib64/ws2_32.def && $(AR) $(ARFLAGS)
EXTRA_lib64_libws2_32_a_DEPENDENCIES=lib64/ws2_32.def

lib64_LIBRARIES += lib64/libtaskschd.a
lib64_libtaskschd_a_SOURCES = $(src_libtaskschd)
lib64_libtaskschd_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libadsiid.a
lib64_libadsiid_a_SOURCES = $(src_adsiid)
lib64_libadsiid_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libdloadhelper.a
lib64_libdloadhelper_a_SOURCES = $(src_libdloadhelper)
lib64_libdloadhelper_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libdelayimp.a
lib64_libdelayimp_a_SOURCES =

lib64_LIBRARIES += lib64/libm.a
nodist_lib64_libm_a_SOURCES = $(src_libm)
lib64_libm_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libgmon.a
lib64_libgmon_a_SOURCES = profile/mcount.c \
  profile/profil.h profile/profil.c        \
  profile/gmon.h   profile/gmon.c \
  profile/mcountFunc.S
lib64_libgmon_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/liblargeint.a
lib64_liblargeint_a_SOURCES = $(src_liblargeint)
lib64_liblargeint_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

lib64_LIBRARIES += lib64/libmingw32.a
lib64_libmingw32_a_CPPFLAGS=$(CPPFLAGS64) -D_SYSCRT=1 -DCRTDLL=1 $(extra_include) $(AM_CPPFLAGS)
lib64_libmingw32_a_SOURCES = $(src_libmingw32)

lib64_LIBRARIES += lib64/libmingwex.a
lib64_libmingwex_a_CPPFLAGS=$(CPPFLAGS64) $(extra_include) $(AM_CPPFLAGS)
lib64_libmingwex_a_SOURCES = $(src_libmingwex) $(src_libmingwex64)

lib64_LIBRARIES += lib64/libmoldname.a
lib64_libmoldname_a_CPPFLAGS=$(CPPFLAGS64) $(extra_include) $(AM_CPPFLAGS)
lib64_libmoldname_a_SOURCES = $(src_libm)

lib64_LIBRARIES += lib64/libmingwthrd.a
lib64_libmingwthrd_a_SOURCES = $(src_libmingwthrd)
lib64_libmingwthrd_a_CPPFLAGS=$(CPPFLAGS64) $(sysincludes)

processed_defs += lib64/ucrtbase.def \
				  lib64/advapi32.def lib64/clbcatq.def lib64/kernel32.def lib64/ole32.def \
				  lib64/oleaut32.def lib64/user32.def lib64/winhvplatform.def lib64/ws2_32.def \
				  lib64/api-ms-win-crt-math-l1-1-0.def lib64/api-ms-win-crt-private-l1-1-0.def lib64/api-ms-win-crt-runtime-l1-1-0.def \
				  lib64/api-ms-win-crt-filesystem-l1-1-0.def lib64/api-ms-win-crt-time-l1-1-0.def

include lib64/Makefile.am

lib64_DATA += lib64/libucrtbase.a
lib64/libucrtbase.a: lib-common/ucrtbase.mri lib64/libucrtbase_def.a lib64/libucrt_extra.a lib64/libvcruntime140_threads.a
	cd $(dir $@) && $(AR) -M < $(abspath $<)

lib64_DATA += lib64/libucrt.a lib64/libucrtapp.a
noinst_LIBRARIES += lib64/libucrt_extra.a lib64/libucrtapp_extra.a
lib64_libucrt_extra_a_SOURCES = $(src_ucrtbase64)
lib64_libucrt_extra_a_CPPFLAGS=$(CPPFLAGS64) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
lib64_libucrtapp_extra_a_SOURCES = $(src_ucrtapp)
lib64_libucrtapp_extra_a_CPPFLAGS=$(CPPFLAGS64) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)

lib64/lib%.a: lib64/%.def
	$(DTDEF64) $<

lib64/lib%.a: lib-common/%.def
	$(DTDEF64) $<

lib64/lib%_def.a: lib64/%.def
	$(DTDEF64) $<

lib64/lib%_def.a: lib-common/%.def
	$(DTDEF64) $<

dx64_DATA =
dx64_DATA += lib64/libxinput.a
dx64_DATA += lib64/libxapofx.a
dx64_DATA += lib64/libx3daudio.a
dx64_DATA += lib64/libd3dx9.a
dx64_DATA += lib64/libd3dx10.a
dx64_DATA += lib64/libd3dx11.a
dx64_DATA += lib64/libd3dcompiler.a

lib64/libxinput.a: lib-common/$(xinput).def
	$(DTDEF64) $<
lib64/libxapofx.a: lib64/$(xapofx).def
	$(DTDEF64) $<
lib64/libx3daudio.a: lib64/$(x3daudio).def
	$(DTDEF64) $<
lib64/libd3dx9.a: lib64/$(d3dx9).def
	$(DTDEF64) $<
lib64/libd3dx10.a: lib64/$(d3dx10).def
	$(DTDEF64) $<
lib64/libd3dx11.a: lib64/$(d3dx11).def
	$(DTDEF64) $<
lib64/libd3dcompiler.a: lib-common/$(d3dcompiler).def
	$(DTDEF64) $<

endif
# End 64-bit runtime
##########


if LIBARM64
#########
# Compiling ARM 64-bit runtime
#

libarm64dir=$(prefix)/@LIBARM64SUFFIXDIR@
crt64dir=$(libarm64dir)
winrt64dir=$(libarm64dir)
dx64dir=$(libarm64dir)

crt64_DATA = \
  libarm64/binmode.o  libarm64/CRT_fp10.o  libarm64/CRT_fp8.o   libarm64/CRT_glob.o  libarm64/CRT_noglob.o \
  libarm64/crt2.o     libarm64/crt2u.o     libarm64/crtbegin.o  libarm64/crtend.o    libarm64/dllcrt2.o    \
  libarm64/gcrt2.o    libarm64/txtmode.o

COMPILE64=$(COMPILE) $(CPPFLAGSARM64) $(extra_include) -D_SYSCRT=1 -DCRTDLL=1
libarm64/crt2.o: crt/crtexe.c
	$(COMPILE64) -c $< -o $@
libarm64/crt2u.o: crt/ucrtexe.c
	$(COMPILE64) -c $< -o $@
libarm64/dllcrt2.o: crt/crtdll.c
	$(COMPILE64) -c $< -o $@

libarm64/gcrt2.o: profile/gcrt0.c
	$(COMPILE) $(CPPFLAGSARM64) -c $< -o $@

libarm64/%.o: crt/%.c
	$(COMPILE) $(CPPFLAGSARM64) -c $< -o $@

# These source files aren't compiled in to any library yet.  I'm not sure how / where to do so.
# The source files that I did compile somewhere I just guessed at anyway.
#

temp= \
dxerr.c \
test.c

libarm64_LIBRARIES = libarm64/libkernel32.a
libarm64_libkernel32_a_SOURCES = $(src_intrincs) $(src_intrincsarm64) lib-common/kernel32.def.in
libarm64_libkernel32_a_AR = $(DTDEFARM64) libarm64/kernel32.def && $(AR) $(ARFLAGS)
libarm64_libkernel32_a_CPPFLAGS=$(CPPFLAGSARM64) $(extra_include) $(AM_CPPFLAGS)
EXTRA_libarm64_libkernel32_a_DEPENDENCIES=libarm64/kernel32.def

libarm64_DATA =
libarm64_DATA += libarm64/libmsvcrt.a
libarm64/libmsvcrt.a: libarm64/libucrt.a
	cp $< $@

libarm64_LIBRARIES += libarm64/libbits.a
libarm64_libbits_a_SOURCES = $(src_libbits)
libarm64_libbits_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libshell32.a
libarm64_libshell32_a_SOURCES = $(src_libshell32)
libarm64_libshell32_a_AR = $(DTDEFARM64) $(top_srcdir)/lib-common/shell32.def && $(AR) $(ARFLAGS)
libarm64_libshell32_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libdinput.a
libarm64_libdinput_a_SOURCES = $(src_libdinput)
libarm64_libdinput_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)
libarm64_libdinput_a_AR = $(DTDEFARM64) $(top_srcdir)/lib-common/dinput.def && $(AR) $(ARFLAGS)

libarm64_LIBRARIES += libarm64/libdinput8.a
libarm64_libdinput8_a_SOURCES = $(src_libdinput8)
libarm64_libdinput8_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)
libarm64_libdinput8_a_AR = $(DTDEFARM64) $(top_srcdir)/lib-common/dinput8.def && $(AR) $(ARFLAGS)

libarm64_LIBRARIES += libarm64/libdmoguids.a
libarm64_libdmoguids_a_SOURCES = $(src_libdmoguids)
libarm64_libdmoguids_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libdxerr8.a
libarm64_libdxerr8_a_SOURCES = $(src_libdxerr8)
libarm64_libdxerr8_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libdxerr9.a
libarm64_libdxerr9_a_SOURCES = $(src_libdxerr9)
libarm64_libdxerr9_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libmsxml2.a
libarm64_libmsxml2_a_SOURCES = $(src_libmsxml2)
libarm64_libmsxml2_a_CPPFLAGS = $(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libmsxml6.a
libarm64_libmsxml6_a_SOURCES = $(src_libmsxml6)
libarm64_libmsxml6_a_CPPFLAGS = $(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libmfuuid.a
libarm64_libmfuuid_a_SOURCES = $(src_libmfuuid)
libarm64_libmfuuid_a_CPPFLAGS = $(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libamstrmid.a
libarm64_libamstrmid_a_SOURCES = $(src_libamstrmid)
libarm64_libamstrmid_a_CPPFLAGS = $(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libwmcodecdspuuid.a
libarm64_libwmcodecdspuuid_a_SOURCES = $(src_libwmcodecdspuuid)
libarm64_libwmcodecdspuuid_a_CPPFLAGS = $(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libwindowscodecs.a
libarm64_libwindowscodecs_a_SOURCES = $(src_libwindowscodecs)
libarm64_libwindowscodecs_a_CPPFLAGS = $(CPPFLAGSARM64) $(sysincludes)
libarm64_libwindowscodecs_a_AR = $(DTDEFARM64) $(top_srcdir)/lib-common/windowscodecs.def && $(AR) $(ARFLAGS)

libarm64_LIBRARIES += libarm64/libwbemuuid.a
libarm64_libwbemuuid_a_SOURCES = $(src_libwbemuuid)
libarm64_libwbemuuid_a_CPPFLAGS = $(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libdxguid.a
libarm64_libdxguid_a_SOURCES = $(src_libdxguid)
libarm64_libdxguid_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libksuser.a
libarm64_libksuser_a_SOURCES = $(src_libksuser)
libarm64_libksuser_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)
libarm64_libksuser_a_AR = $(DTDEFARM64) $(top_srcdir)/lib-common/ksuser.def && $(AR) $(ARFLAGS)

libarm64_LIBRARIES += libarm64/libksguid.a
libarm64_libksguid_a_SOURCES = $(src_libksguid)
libarm64_libksguid_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/liblocationapi.a
libarm64_liblocationapi_a_SOURCES = $(src_liblocationapi)
libarm64_liblocationapi_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libsensorsapi.a
libarm64_libsensorsapi_a_SOURCES = $(src_libsensorsapi)
libarm64_libsensorsapi_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libsapi.a
libarm64_libsapi_a_SOURCES = $(src_libsapi)
libarm64_libsapi_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libportabledeviceguids.a
libarm64_libportabledeviceguids_a_SOURCES = $(src_libportabledeviceguids)
libarm64_libportabledeviceguids_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libscrnsave.a
libarm64_libscrnsave_a_SOURCES = $(src_libscrnsave)
libarm64_libscrnsave_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libscrnsavw.a
libarm64_libscrnsavw_a_SOURCES = $(src_libscrnsavw)
libarm64_libscrnsavw_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)
libarm64_libscrnsavw_a_CFLAGS = -DUNICODE

libarm64_LIBRARIES += libarm64/libstrmiids.a
libarm64_libstrmiids_a_SOURCES = $(src_libstrmiids)
libarm64_libstrmiids_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libuuid.a
libarm64_libuuid_a_SOURCES = $(src_libuuid)
libarm64_libuuid_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libgdiplus.a
libarm64_libgdiplus_a_SOURCES = $(src_libgdiplus)
libarm64_libgdiplus_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)
libarm64_libgdiplus_a_AR = $(DTDEFARM64) $(top_srcdir)/lib-common/gdiplus.def && $(AR) $(ARFLAGS)

libarm64_LIBRARIES += libarm64/libws2_32.a
libarm64_libws2_32_a_SOURCES = $(src_libws2_32) lib-common/libws2_32.def.in
libarm64_libws2_32_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)
libarm64_libws2_32_a_AR = $(DTDEFARM64) libarm64/ws2_32.def && $(AR) $(ARFLAGS)
EXTRA_libarm64_libws2_32_a_DEPENDENCIES=libarm64/ws2_32.def

libarm64_LIBRARIES += libarm64/libadsiid.a
libarm64_libadsiid_a_SOURCES = $(src_adsiid)
libarm64_libadsiid_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libdloadhelper.a
libarm64_libdloadhelper_a_SOURCES = $(src_libdloadhelper)
libarm64_libdloadhelper_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libdelayimp.a
libarm64_libdelayimp_a_SOURCES =

libarm64_LIBRARIES += libarm64/libm.a
nodist_libarm64_libm_a_SOURCES = $(src_libm)
libarm64_libm_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

#libarm64_LIBRARIES += libarm64/libgmon.a
#libarm64_libgmon_a_SOURCES = profile/mcount.c \
#  profile/profil.h profile/profil.c        \
#  profile/gmon.h   profile/gmon.c \
#  profile/mcountFunc.S
#libarm64_libgmon_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/liblargeint.a
libarm64_liblargeint_a_SOURCES = $(src_liblargeint)
libarm64_liblargeint_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

libarm64_LIBRARIES += libarm64/libmingw32.a
libarm64_libmingw32_a_CPPFLAGS=$(CPPFLAGSARM64) -D_SYSCRT=1 -DCRTDLL=1 $(extra_include) $(AM_CPPFLAGS)
libarm64_libmingw32_a_SOURCES = $(src_libmingw32)

libarm64_LIBRARIES += libarm64/libmingwex.a
libarm64_libmingwex_a_CPPFLAGS=$(CPPFLAGSARM64) $(extra_include) $(AM_CPPFLAGS)
libarm64_libmingwex_a_SOURCES = $(src_libmingwex) $(src_libmingwexarm64)

libarm64_LIBRARIES += libarm64/libmoldname.a
libarm64_libmoldname_a_CPPFLAGS=$(CPPFLAGSARM64) $(extra_include) $(AM_CPPFLAGS)
libarm64_libmoldname_a_SOURCES = $(src_libm)

libarm64_LIBRARIES += libarm64/libmingwthrd.a
libarm64_libmingwthrd_a_SOURCES = $(src_libmingwthrd)
libarm64_libmingwthrd_a_CPPFLAGS=$(CPPFLAGSARM64) $(sysincludes)

processed_defs += libarm64/ucrtbase.def \
				  libarm64/advapi32.def libarm64/clbcatq.def libarm64/kernel32.def libarm64/ole32.def libarm64/oleaut32.def \
				  libarm64/user32.def libarm64/winhvplatform.def libarm64/ws2_32.def \
				  libarm64/api-ms-win-crt-math-l1-1-0.def libarm64/api-ms-win-crt-private-l1-1-0.def libarm64/api-ms-win-crt-runtime-l1-1-0.def \
				  libarm64/api-ms-win-crt-filesystem-l1-1-0.def libarm64/api-ms-win-crt-time-l1-1-0.def

include libarm64/Makefile.am

libarm64_DATA += libarm64/libucrtbase.a
libarm64/libucrtbase.a: lib-common/ucrtbase.mri libarm64/libucrtbase_def.a libarm64/libucrt_extra.a libarm64/libvcruntime140_threads.a
	cd $(dir $@) && $(AR) -M < $(abspath $<)

libarm64_DATA += libarm64/libucrt.a libarm64/libucrtapp.a
noinst_LIBRARIES += libarm64/libucrt_extra.a libarm64/libucrtapp_extra.a
libarm64_libucrt_extra_a_SOURCES = $(src_ucrtbasearm64)
libarm64_libucrt_extra_a_CPPFLAGS=$(CPPFLAGSARM64) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)
libarm64_libucrtapp_extra_a_SOURCES = $(src_ucrtapp)
libarm64_libucrtapp_extra_a_CPPFLAGS=$(CPPFLAGSARM64) -D__LIBMSVCRT__ $(extra_include) $(sysincludes)

libarm64/lib%.a: libarm64/%.def
	$(DTDEFARM64) $<

libarm64/lib%.a: lib-common/%.def
	$(DTDEFARM64) $<

libarm64/lib%_def.a: libarm64/%.def
	$(DTDEFARM64) $<

libarm64/lib%_def.a: lib-common/%.def
	$(DTDEFARM64) $<

dx64_DATA =
dx64_DATA += libarm64/libxinput.a
dx64_DATA += libarm64/libd3dcompiler.a

libarm64/libxinput.a: lib-common/xinput1_4.def
	$(DTDEFARM64) $<
libarm64/libd3dcompiler.a: lib-common/d3dcompiler_47.def
	$(DTDEFARM64) $<

endif
# End ARM 64-bit runtime
# ##########

%/libmincore.a: lib-common/mincore.mri \
		%/libapi-ms-win-core-com-l1-1-0.a \
		%/libapi-ms-win-core-com-l1-1-1.a \
		%/libapi-ms-win-core-com-l1-1-2.a \
		%/libapi-ms-win-core-com-l1-1-3.a \
		%/libapi-ms-win-core-com-midlproxystub-l1-1-0.a \
		%/libapi-ms-win-core-comm-l1-1-0.a \
		%/libapi-ms-win-core-comm-l1-1-1.a \
		%/libapi-ms-win-core-comm-l1-1-2.a \
		%/libapi-ms-win-core-console-l1-1-0.a \
		%/libapi-ms-win-core-console-l1-2-0.a \
		%/libapi-ms-win-core-console-l1-2-1.a \
		%/libapi-ms-win-core-console-l2-1-0.a \
		%/libapi-ms-win-core-console-l2-2-0.a \
		%/libapi-ms-win-core-console-l3-2-0.a \
		%/libapi-ms-win-core-datetime-l1-1-0.a \
		%/libapi-ms-win-core-datetime-l1-1-1.a \
		%/libapi-ms-win-core-datetime-l1-1-2.a \
		%/libapi-ms-win-core-debug-l1-1-0.a \
		%/libapi-ms-win-core-debug-l1-1-1.a \
		%/libapi-ms-win-core-debug-l1-1-2.a \
		%/libapi-ms-win-core-delayload-l1-1-0.a \
		%/libapi-ms-win-core-delayload-l1-1-1.a \
		%/libapi-ms-win-core-errorhandling-l1-1-0.a \
		%/libapi-ms-win-core-errorhandling-l1-1-1.a \
		%/libapi-ms-win-core-errorhandling-l1-1-2.a \
		%/libapi-ms-win-core-errorhandling-l1-1-3.a \
		%/libapi-ms-win-core-fibers-l1-1-0.a \
		%/libapi-ms-win-core-fibers-l1-1-1.a \
		%/libapi-ms-win-core-file-l1-1-0.a \
		%/libapi-ms-win-core-file-l1-2-0.a \
		%/libapi-ms-win-core-file-l1-2-1.a \
		%/libapi-ms-win-core-file-l1-2-2.a \
		%/libapi-ms-win-core-file-l1-2-3.a \
		%/libapi-ms-win-core-file-l2-1-0.a \
		%/libapi-ms-win-core-file-l2-1-1.a \
		%/libapi-ms-win-core-file-l2-1-2.a \
		%/libapi-ms-win-core-file-l2-1-3.a \
		%/libapi-ms-win-core-firmware-l1-1-0.a \
		%/libapi-ms-win-core-handle-l1-1-0.a \
		%/libapi-ms-win-core-heap-l1-1-0.a \
		%/libapi-ms-win-core-heap-l2-1-0.a \
		%/libapi-ms-win-core-interlocked-l1-1-0.a \
		%/libapi-ms-win-core-interlocked-l1-2-0.a \
		%/libapi-ms-win-core-io-l1-1-0.a \
		%/libapi-ms-win-core-io-l1-1-1.a \
		%/libapi-ms-win-core-job-l1-1-0.a \
		%/libapi-ms-win-core-libraryloader-l1-2-0.a \
		%/libapi-ms-win-core-libraryloader-l1-2-1.a \
		%/libapi-ms-win-core-libraryloader-l1-2-2.a \
		%/libapi-ms-win-core-libraryloader-l2-1-0.a \
		%/libapi-ms-win-core-localization-l1-2-1.a \
		%/libapi-ms-win-core-localization-l1-2-0.a \
		%/libapi-ms-win-core-localization-l1-2-2.a \
		%/libapi-ms-win-core-localization-l1-2-3.a \
		%/libapi-ms-win-core-localization-l1-2-4.a \
		%/libapi-ms-win-core-localization-l2-1-0.a \
		%/libapi-ms-win-core-memory-l1-1-0.a \
		%/libapi-ms-win-core-memory-l1-1-1.a \
		%/libapi-ms-win-core-memory-l1-1-2.a \
		%/libapi-ms-win-core-memory-l1-1-3.a \
		%/libapi-ms-win-core-memory-l1-1-4.a \
		%/libapi-ms-win-core-memory-l1-1-5.a \
		%/libapi-ms-win-core-memory-l1-1-6.a \
		%/libapi-ms-win-core-memory-l1-1-7.a \
		%/libapi-ms-win-core-namedpipe-l1-1-0.a \
		%/libapi-ms-win-core-namedpipe-l1-2-1.a \
		%/libapi-ms-win-core-namedpipe-l1-2-2.a \
		%/libapi-ms-win-core-namespace-l1-1-0.a \
		%/libapi-ms-win-core-path-l1-1-0.a \
		%/libapi-ms-win-core-processenvironment-l1-1-0.a \
		%/libapi-ms-win-core-processenvironment-l1-2-0.a \
		%/libapi-ms-win-core-processsnapshot-l1-1-0.a \
		%/libapi-ms-win-core-processthreads-l1-1-0.a \
		%/libapi-ms-win-core-processthreads-l1-1-1.a \
		%/libapi-ms-win-core-processthreads-l1-1-2.a \
		%/libapi-ms-win-core-processthreads-l1-1-3.a \
		%/libapi-ms-win-core-processthreads-l1-1-4.a \
		%/libapi-ms-win-core-processtopology-l1-1-0.a \
		%/libapi-ms-win-core-profile-l1-1-0.a \
		%/libapi-ms-win-core-psapi-l1-1-0.a \
		%/libapi-ms-win-core-quirks-l1-1-0.a \
		%/libapi-ms-win-core-quirks-l1-1-1.a \
		%/libapi-ms-win-core-realtime-l1-1-0.a \
		%/libapi-ms-win-core-realtime-l1-1-1.a \
		%/libapi-ms-win-core-realtime-l1-1-2.a \
		%/libapi-ms-win-core-registry-l1-1-0.a \
		%/libapi-ms-win-core-registry-l1-1-1.a \
		%/libapi-ms-win-core-registry-l1-1-2.a \
		%/libapi-ms-win-core-rtlsupport-l1-1-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-2-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-2-1.a \
		%/libapi-ms-win-core-shutdown-l1-1-0.a \
		%/libapi-ms-win-core-shutdown-l1-1-1.a \
		%/libapi-ms-win-core-sidebyside-ansi-l1-1-0.a \
		%/libapi-ms-win-core-sidebyside-l1-1-0.a \
		%/libapi-ms-win-core-state-helpers-l1-1-0.a \
		%/libapi-ms-win-core-string-l1-1-0.a \
		%/libapi-ms-win-core-string-l2-1-0.a \
		%/libapi-ms-win-core-string-l2-1-1.a \
		%/libapi-ms-win-core-synch-l1-1-0.a \
		%/libapi-ms-win-core-synch-l1-2-0.a \
		%/libapi-ms-win-core-synch-l1-2-1.a \
		%/libapi-ms-win-core-sysinfo-l1-1-0.a \
		%/libapi-ms-win-core-sysinfo-l1-2-0.a \
		%/libapi-ms-win-core-sysinfo-l1-2-1.a \
		%/libapi-ms-win-core-sysinfo-l1-2-2.a \
		%/libapi-ms-win-core-sysinfo-l1-2-3.a \
		%/libapi-ms-win-core-sysinfo-l1-2-4.a \
		%/libapi-ms-win-core-sysinfo-l1-2-5.a \
		%/libapi-ms-win-core-sysinfo-l1-2-6.a \
		%/libapi-ms-win-core-systemtopology-l1-1-0.a \
		%/libapi-ms-win-core-systemtopology-l1-1-1.a \
		%/libapi-ms-win-core-threadpool-l1-2-0.a \
		%/libapi-ms-win-core-timezone-l1-1-0.a \
		%/libapi-ms-win-core-timezone-l1-1-1.a \
		%/libapi-ms-win-core-util-l1-1-0.a \
		%/libapi-ms-win-core-util-l1-1-1.a \
		%/libapi-ms-win-core-version-l1-1-0.a \
		%/libapi-ms-win-core-version-l1-1-1.a \
		%/libapi-ms-win-core-winrt-error-l1-1-0.a \
		%/libapi-ms-win-core-winrt-error-l1-1-1.a \
		%/libapi-ms-win-core-winrt-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-1.a \
		%/libapi-ms-win-core-wow64-l1-1-0.a \
		%/libapi-ms-win-core-wow64-l1-1-1.a \
		%/libapi-ms-win-core-wow64-l1-1-2.a \
		%/libapi-ms-win-core-wow64-l1-1-3.a \
		%/libapi-ms-win-core-xstate-l1-1-0.a \
		%/libapi-ms-win-core-xstate-l1-1-1.a \
		%/libapi-ms-win-core-xstate-l1-1-2.a \
		%/libapi-ms-win-core-xstate-l1-1-3.a \
		%/libapi-ms-win-core-xstate-l2-1-0.a \
		%/libapi-ms-win-core-xstate-l2-1-1.a \
		%/libapi-ms-win-devices-config-l1-1-1.a \
		%/libapi-ms-win-devices-config-l1-1-2.a \
		%/libapi-ms-win-devices-swdevice-l1-1-0.a \
		%/libapi-ms-win-devices-swdevice-l1-1-1.a \
		%/libapi-ms-win-eventing-classicprovider-l1-1-0.a \
		%/libapi-ms-win-eventing-consumer-l1-1-0.a \
		%/libapi-ms-win-eventing-consumer-l1-1-1.a \
		%/libapi-ms-win-eventing-controller-l1-1-0.a \
		%/libapi-ms-win-eventing-provider-l1-1-0.a \
		%/libapi-ms-win-power-base-l1-1-0.a \
		%/libapi-ms-win-power-setting-l1-1-0.a \
		%/libapi-ms-win-power-setting-l1-1-1.a \
		%/libapi-ms-win-security-appcontainer-l1-1-0.a \
		%/libapi-ms-win-security-base-l1-1-0.a \
		%/libapi-ms-win-security-base-l1-2-0.a \
		%/libapi-ms-win-security-base-l1-2-1.a \
		%/libapi-ms-win-security-base-l1-2-2.a \
		%/libapi-ms-win-security-credentials-l1-1-0.a \
		%/libapi-ms-win-security-lsalookup-l2-1-0.a \
		%/libapi-ms-win-security-lsalookup-l2-1-1.a \
		%/libapi-ms-win-security-sddl-l1-1-0.a \
		%/libapi-ms-win-service-core-l1-1-0.a \
		%/libapi-ms-win-service-core-l1-1-1.a \
		%/libapi-ms-win-service-core-l1-1-2.a \
		%/libapi-ms-win-service-core-l1-1-3.a \
		%/libapi-ms-win-service-core-l1-1-4.a \
		%/libapi-ms-win-service-management-l1-1-0.a \
		%/libapi-ms-win-service-management-l2-1-0.a \
		%/libapi-ms-win-service-winsvc-l1-1-0.a \
		%/libauthz.a \
		%/libbcrypt.a \
		%/libcabinet.a \
		%/libcrypt32.a \
		%/libcryptbase.a \
		%/libcryptnet.a \
		%/libdnsapi.a \
		%/libdfscli.a \
		%/libdsparse.a \
		%/libdsrole.a \
		%/libiphlpapi.a \
		%/liblogoncli.a \
		%/libmpr.a \
		%/libmswsock.a \
		%/libncrypt.a \
		%/libnetutils.a \
		%/liboleaut32.a \
		%/librpcrt4.a \
		%/libsamcli.a \
		%/libschedcli.a \
		%/libsrvcli.a \
		%/libsspicli.a \
		%/libuserenv.a \
		%/libwinhttp.a \
		%/libwkscli.a \
		%/libwldap32.a \
		%/libwebsocket.a \
		%/libws2_32.a
	rm -f $@
	cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(RANLIB) $@

%/libmincore_downlevel.a: lib-common/mincore_downlevel.mri \
		%/libapi-ms-win-downlevel-advapi32-l1-1-0.a \
		%/libapi-ms-win-downlevel-advapi32-l2-1-0.a \
		%/libapi-ms-win-downlevel-normaliz-l1-1-0.a \
		%/libapi-ms-win-downlevel-ole32-l1-1-0.a \
		%/libapi-ms-win-downlevel-shell32-l1-1-0.a \
		%/libapi-ms-win-downlevel-shlwapi-l1-1-0.a \
		%/libapi-ms-win-downlevel-shlwapi-l2-1-0.a \
		%/libapi-ms-win-downlevel-user32-l1-1-0.a \
		%/libapi-ms-win-downlevel-version-l1-1-0.a
	rm -f $@
	cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(RANLIB) $@

%/libnanosrv.a: lib-common/nanosrv.mri \
		%/libapi-ms-win-net-isolation-l1-1-0.a \
		%/libapi-ms-win-net-isolation-l1-1-1.a \
		%/libclfsw32.a \
		%/libclusapi.a \
		%/libcryptxml.a \
		%/libdbgeng.a \
		%/libdbghelp.a \
		%/libdnsperf.a \
		%/libesent.a \
		%/libfaultrep.a \
		%/libfwpuclnt.a \
		%/libhbaapi.a \
		%/libhttpapi.a \
		%/libiscsidsc.a \
		%/libktmw32.a \
		%/libmprapi.a \
		%/libntdsapi.a \
		%/libpdh.a \
		%/libsnmpapi.a \
		%/libtbs.a \
		%/libvirtdisk.a \
		%/libvssapi.a \
		%/libwebservices.a \
		%/libwer.a \
		%/libwevtapi.a \
		%/libwintrust.a \
		%/libwsmsvc.a
	rm -f $@
	cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(RANLIB) $@

%/libonecore.a: lib-common/onecore.mri \
		%/libadvapi32_onecore.a \
		%/libapi-ms-win-core-backgroundtask-l1-1-0.a \
		%/libapi-ms-win-core-calendar-l1-1-0.a \
		%/libapi-ms-win-core-comm-l1-1-1.a \
		%/libapi-ms-win-core-comm-l1-1-2.a \
		%/libapi-ms-win-core-debug-minidump-l1-1-0.a \
		%/libapi-ms-win-core-enclave-l1-1-1.a \
		%/libapi-ms-win-core-errorhandling-l1-1-3.a \
		%/libapi-ms-win-core-featurestaging-l1-1-0.a \
		%/libapi-ms-win-core-featurestaging-l1-1-1.a \
		%/libapi-ms-win-core-handle-l1-1-0.a \
		%/libapi-ms-win-core-libraryloader-l2-1-0.a \
		%/libapi-ms-win-core-memory-l1-1-3.a \
		%/libapi-ms-win-core-memory-l1-1-4.a \
		%/libapi-ms-win-core-memory-l1-1-5.a \
		%/libapi-ms-win-core-memory-l1-1-6.a \
		%/libapi-ms-win-core-memory-l1-1-7.a \
		%/libapi-ms-win-core-path-l1-1-0.a \
		%/libapi-ms-win-core-quirks-l1-1-0.a \
		%/libapi-ms-win-core-quirks-l1-1-1.a \
		%/libapi-ms-win-core-realtime-l1-1-1.a \
		%/libapi-ms-win-core-realtime-l1-1-2.a \
		%/libapi-ms-win-core-rtlsupport-l1-1-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-2-0.a \
		%/libapi-ms-win-core-state-helpers-l1-1-0.a \
		%/libapi-ms-win-core-synch-l1-2-0.a \
		%/libapi-ms-win-core-sysinfo-l1-2-0.a \
		%/libapi-ms-win-core-sysinfo-l1-2-3.a \
		%/libapi-ms-win-core-sysinfo-l1-2-4.a \
		%/libapi-ms-win-core-util-l1-1-1.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-0.a \
		%/libapi-ms-win-core-winrt-error-l1-1-0.a \
		%/libapi-ms-win-core-winrt-error-l1-1-1.a \
		%/libapi-ms-win-core-winrt-l1-1-0.a \
		%/libapi-ms-win-core-winrt-registration-l1-1-0.a \
		%/libapi-ms-win-core-winrt-robuffer-l1-1-0.a \
		%/libapi-ms-win-core-winrt-roparameterizediid-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-1.a \
		%/libapi-ms-win-core-wow64-l1-1-1.a \
		%/libapi-ms-win-devices-config-l1-1-1.a \
		%/libapi-ms-win-devices-query-l1-1-0.a \
		%/libapi-ms-win-devices-query-l1-1-1.a \
		%/libapi-ms-win-devices-swdevice-l1-1-0.a \
		%/libapi-ms-win-devices-swdevice-l1-1-1.a \
		%/libapi-ms-win-gaming-deviceinformation-l1-1-0.a \
		%/libapi-ms-win-power-base-l1-1-0.a \
		%/libapi-ms-win-power-limitsmanagement-l1-1-0.a \
		%/libapi-ms-win-power-setting-l1-1-0.a \
		%/libapi-ms-win-power-setting-l1-1-1.a \
		%/libapi-ms-win-ro-typeresolution-l1-1-0.a \
		%/libapi-ms-win-ro-typeresolution-l1-1-1.a \
		%/libapi-ms-win-security-base-l1-2-2.a \
		%/libapi-ms-win-security-isolatedcontainer-l1-1-0.a \
		%/libapi-ms-win-security-isolatedcontainer-l1-1-1.a \
		%/libapi-ms-win-service-core-l1-1-3.a \
		%/libapi-ms-win-service-core-l1-1-4.a \
		%/libapi-ms-win-shcore-scaling-l1-1-0.a \
		%/libapi-ms-win-shcore-scaling-l1-1-1.a \
		%/libapi-ms-win-shcore-scaling-l1-1-2.a \
		%/libapi-ms-win-shcore-stream-winrt-l1-1-0.a \
		%/libauthz.a \
		%/libbcrypt.a \
		%/libcabinet.a \
		%/libcomctl32_onecore.a \
		%/libcomdlg32.a \
		%/libcrypt32.a \
		%/libcryptnet.a \
		%/libdfscli.a \
		%/libdhcpcsvc.a \
		%/libdhcpcsvc6.a \
		%/libdiagnosticdataquery.a \
		%/libdnsapi.a \
		%/libdsrole.a \
		%/libfltlib.a \
		%/libfontsub.a \
		%/libgdi32_onecore.a \
		%/libiphlpapi.a \
		%/libkernel32_onecore.a \
		%/liblogoncli.a \
		%/libmpr.a \
		%/libmswsock.a \
		%/libncrypt_onecore.a \
		%/libnetutils.a \
		%/libnormaliz_onecore.a \
		%/libntdll_onecore.a \
		%/libole32_onecore.a \
		%/liboleaut32.a \
		%/libpowrprof_onecore.a \
		%/libprofapi.a \
		%/libpsapi.a \
		%/librpcrt4.a \
		%/libsamcli.a \
		%/libschedcli.a \
		%/libsecur32_onecore.a \
		%/libsetupapi_onecore.a \
		%/libshell32_onecore.a \
		%/libshlwapi.a \
		%/libsrvcli.a \
		%/libsspicli.a \
		%/libtdh_onecore.a \
		%/libuser32_onecore.a \
		%/libuserenv.a \
		%/libversion.a \
		%/libwebsocket.a \
		%/libwinhttp_onecore.a \
		%/libwinmm_onecore.a \
		%/libwkscli.a \
		%/libwldap32.a \
		%/libwpprecorderum.a \
		%/libws2_32.a \
		%/libwtsapi32_onecore.a \
		%/libxmllite.a
	rm -f $@
	cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(RANLIB) $@

%/libonecore_apiset.a: lib-common/onecore_apiset.mri \
		%/libapi-ms-win-base-bootconfig-l1-1-0.a \
		%/libapi-ms-win-base-util-l1-1-0.a \
		%/libapi-ms-win-core-apiquery-l2-1-0.a \
		%/libapi-ms-win-core-atoms-l1-1-0.a \
		%/libapi-ms-win-core-backgroundtask-l1-1-0.a \
		%/libapi-ms-win-core-calendar-l1-1-0.a \
		%/libapi-ms-win-core-com-l1-1-0.a \
		%/libapi-ms-win-core-com-l1-1-1.a \
		%/libapi-ms-win-core-com-l1-1-2.a \
		%/libapi-ms-win-core-com-l1-1-3.a \
		%/libapi-ms-win-core-com-midlproxystub-l1-1-0.a \
		%/libapi-ms-win-core-com-private-l1-1-0.a \
		%/libapi-ms-win-core-comm-l1-1-0.a \
		%/libapi-ms-win-core-comm-l1-1-1.a \
		%/libapi-ms-win-core-comm-l1-1-2.a \
		%/libapi-ms-win-core-console-l1-1-0.a \
		%/libapi-ms-win-core-console-l1-2-0.a \
		%/libapi-ms-win-core-console-l1-2-1.a \
		%/libapi-ms-win-core-console-l1-2-2.a \
		%/libapi-ms-win-core-console-l2-1-0.a \
		%/libapi-ms-win-core-console-l2-2-0.a \
		%/libapi-ms-win-core-console-l3-2-0.a \
		%/libapi-ms-win-core-datetime-l1-1-0.a \
		%/libapi-ms-win-core-datetime-l1-1-1.a \
		%/libapi-ms-win-core-datetime-l1-1-2.a \
		%/libapi-ms-win-core-debug-l1-1-0.a \
		%/libapi-ms-win-core-debug-l1-1-1.a \
		%/libapi-ms-win-core-debug-l1-1-2.a \
		%/libapi-ms-win-core-debug-minidump-l1-1-0.a \
		%/libapi-ms-win-core-delayload-l1-1-0.a \
		%/libapi-ms-win-core-delayload-l1-1-1.a \
		%/libapi-ms-win-core-enclave-l1-1-0.a \
		%/libapi-ms-win-core-enclave-l1-1-1.a \
		%/libapi-ms-win-core-errorhandling-l1-1-0.a \
		%/libapi-ms-win-core-errorhandling-l1-1-1.a \
		%/libapi-ms-win-core-errorhandling-l1-1-2.a \
		%/libapi-ms-win-core-errorhandling-l1-1-3.a \
		%/libapi-ms-win-core-featurestaging-l1-1-0.a \
		%/libapi-ms-win-core-featurestaging-l1-1-1.a \
		%/libapi-ms-win-core-featuretoggles-l1-1-0.a \
		%/libapi-ms-win-core-fibers-l1-1-0.a \
		%/libapi-ms-win-core-fibers-l1-1-1.a \
		%/libapi-ms-win-core-fibers-l1-1-2.a \
		%/libapi-ms-win-core-fibers-l2-1-0.a \
		%/libapi-ms-win-core-fibers-l2-1-1.a \
		%/libapi-ms-win-core-file-ansi-l1-1-0.a \
		%/libapi-ms-win-core-file-ansi-l2-1-0.a \
		%/libapi-ms-win-core-file-fromapp-l1-1-0.a \
		%/libapi-ms-win-core-file-l1-1-0.a \
		%/libapi-ms-win-core-file-l1-2-0.a \
		%/libapi-ms-win-core-file-l1-2-1.a \
		%/libapi-ms-win-core-file-l1-2-2.a \
		%/libapi-ms-win-core-file-l1-2-3.a \
		%/libapi-ms-win-core-file-l1-2-4.a \
		%/libapi-ms-win-core-file-l2-1-0.a \
		%/libapi-ms-win-core-file-l2-1-1.a \
		%/libapi-ms-win-core-file-l2-1-2.a \
		%/libapi-ms-win-core-file-l2-1-3.a \
		%/libapi-ms-win-core-file-l2-1-4.a \
		%/libapi-ms-win-core-firmware-l1-1-0.a \
		%/libapi-ms-win-core-handle-l1-1-0.a \
		%/libapi-ms-win-core-heap-l1-1-0.a \
		%/libapi-ms-win-core-heap-l2-1-0.a \
		%/libapi-ms-win-core-heap-obsolete-l1-1-0.a \
		%/libapi-ms-win-core-interlocked-l1-1-0.a \
		%/libapi-ms-win-core-interlocked-l1-2-0.a \
		%/libapi-ms-win-core-io-l1-1-0.a \
		%/libapi-ms-win-core-io-l1-1-1.a \
		%/libapi-ms-win-core-ioring-l1-1-0.a \
		%/libapi-ms-win-core-ioring-l1-1-1.a \
		%/libapi-ms-win-core-ioring-l1-1-2.a \
		%/libapi-ms-win-core-job-l1-1-0.a \
		%/libapi-ms-win-core-job-l2-1-0.a \
		%/libapi-ms-win-core-job-l2-1-1.a \
		%/libapi-ms-win-core-kernel32-legacy-ansi-l1-1-0.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-0.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-1.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-2.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-3.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-4.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-5.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-6.a \
		%/libapi-ms-win-core-largeinteger-l1-1-0.a \
		%/libapi-ms-win-core-libraryloader-l1-2-0.a \
		%/libapi-ms-win-core-libraryloader-l1-2-1.a \
		%/libapi-ms-win-core-libraryloader-l1-2-2.a \
		%/libapi-ms-win-core-libraryloader-l1-2-3.a \
		%/libapi-ms-win-core-libraryloader-l2-1-0.a \
		%/libapi-ms-win-core-localization-ansi-l1-1-0.a \
		%/libapi-ms-win-core-localization-l1-2-0.a \
		%/libapi-ms-win-core-localization-l1-2-1.a \
		%/libapi-ms-win-core-localization-l1-2-2.a \
		%/libapi-ms-win-core-localization-l1-2-3.a \
		%/libapi-ms-win-core-localization-l1-2-4.a \
		%/libapi-ms-win-core-localization-l2-1-0.a \
		%/libapi-ms-win-core-localization-obsolete-l1-2-0.a \
		%/libapi-ms-win-core-marshal-l1-1-0.a \
		%/libapi-ms-win-core-memory-l1-1-0.a \
		%/libapi-ms-win-core-memory-l1-1-1.a \
		%/libapi-ms-win-core-memory-l1-1-2.a \
		%/libapi-ms-win-core-memory-l1-1-3.a \
		%/libapi-ms-win-core-memory-l1-1-4.a \
		%/libapi-ms-win-core-memory-l1-1-5.a \
		%/libapi-ms-win-core-memory-l1-1-6.a \
		%/libapi-ms-win-core-memory-l1-1-7.a \
		%/libapi-ms-win-core-memory-l1-1-8.a \
		%/libapi-ms-win-core-memory-l1-1-9.a \
		%/libapi-ms-win-core-namedpipe-ansi-l1-1-0.a \
		%/libapi-ms-win-core-namedpipe-ansi-l1-1-1.a \
		%/libapi-ms-win-core-namedpipe-l1-1-0.a \
		%/libapi-ms-win-core-namedpipe-l1-2-1.a \
		%/libapi-ms-win-core-namedpipe-l1-2-2.a \
		%/libapi-ms-win-core-namespace-ansi-l1-1-0.a \
		%/libapi-ms-win-core-namespace-l1-1-0.a \
		%/libapi-ms-win-core-normalization-l1-1-0.a \
		%/libapi-ms-win-core-path-l1-1-0.a \
		%/libapi-ms-win-core-perfcounters-l1-1-0.a \
		%/libapi-ms-win-core-privateprofile-l1-1-0.a \
		%/libapi-ms-win-core-privateprofile-l1-1-1.a \
		%/libapi-ms-win-core-processenvironment-ansi-l1-1-0.a \
		%/libapi-ms-win-core-processenvironment-l1-1-0.a \
		%/libapi-ms-win-core-processenvironment-l1-2-0.a \
		%/libapi-ms-win-core-processsnapshot-l1-1-0.a \
		%/libapi-ms-win-core-processthreads-l1-1-0.a \
		%/libapi-ms-win-core-processthreads-l1-1-1.a \
		%/libapi-ms-win-core-processthreads-l1-1-2.a \
		%/libapi-ms-win-core-processthreads-l1-1-3.a \
		%/libapi-ms-win-core-processthreads-l1-1-4.a \
		%/libapi-ms-win-core-processthreads-l1-1-5.a \
		%/libapi-ms-win-core-processthreads-l1-1-6.a \
		%/libapi-ms-win-core-processthreads-l1-1-7.a \
		%/libapi-ms-win-core-processthreads-l1-1-8.a \
		%/libapi-ms-win-core-processtopology-l1-1-0.a \
		%/libapi-ms-win-core-processtopology-obsolete-l1-1-0.a \
		%/libapi-ms-win-core-processtopology-obsolete-l1-1-1.a \
		%/libapi-ms-win-core-profile-l1-1-0.a \
		%/libapi-ms-win-core-psapi-ansi-l1-1-0.a \
		%/libapi-ms-win-core-psapi-l1-1-0.a \
		%/libapi-ms-win-core-quirks-l1-1-0.a \
		%/libapi-ms-win-core-quirks-l1-1-1.a \
		%/libapi-ms-win-core-realtime-l1-1-0.a \
		%/libapi-ms-win-core-realtime-l1-1-1.a \
		%/libapi-ms-win-core-realtime-l1-1-2.a \
		%/libapi-ms-win-core-registry-l1-1-0.a \
		%/libapi-ms-win-core-registry-l1-1-1.a \
		%/libapi-ms-win-core-registry-l1-1-2.a \
		%/libapi-ms-win-core-registry-l2-1-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-1-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-2-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-2-1.a \
		%/libapi-ms-win-core-rtlsupport-l1-2-2.a \
		%/libapi-ms-win-core-shlwapi-legacy-l1-1-0.a \
		%/libapi-ms-win-core-shutdown-ansi-l1-1-0.a \
		%/libapi-ms-win-core-shutdown-l1-1-0.a \
		%/libapi-ms-win-core-shutdown-l1-1-1.a \
		%/libapi-ms-win-core-sidebyside-ansi-l1-1-0.a \
		%/libapi-ms-win-core-sidebyside-l1-1-0.a \
		%/libapi-ms-win-core-state-helpers-l1-1-0.a \
		%/libapi-ms-win-core-string-l1-1-0.a \
		%/libapi-ms-win-core-string-l2-1-0.a \
		%/libapi-ms-win-core-string-l2-1-1.a \
		%/libapi-ms-win-core-string-obsolete-l1-1-0.a \
		%/libapi-ms-win-core-string-obsolete-l1-1-1.a \
		%/libapi-ms-win-core-stringansi-l1-1-0.a \
		%/libapi-ms-win-core-synch-ansi-l1-1-0.a \
		%/libapi-ms-win-core-synch-l1-1-0.a \
		%/libapi-ms-win-core-synch-l1-2-0.a \
		%/libapi-ms-win-core-synch-l1-2-1.a \
		%/libapi-ms-win-core-sysinfo-l1-1-0.a \
		%/libapi-ms-win-core-sysinfo-l1-2-0.a \
		%/libapi-ms-win-core-sysinfo-l1-2-1.a \
		%/libapi-ms-win-core-sysinfo-l1-2-2.a \
		%/libapi-ms-win-core-sysinfo-l1-2-3.a \
		%/libapi-ms-win-core-sysinfo-l1-2-4.a \
		%/libapi-ms-win-core-sysinfo-l1-2-5.a \
		%/libapi-ms-win-core-sysinfo-l1-2-6.a \
		%/libapi-ms-win-core-sysinfo-l1-2-7.a \
		%/libapi-ms-win-core-sysinfo-l2-1-0.a \
		%/libapi-ms-win-core-systemtopology-l1-1-0.a \
		%/libapi-ms-win-core-systemtopology-l1-1-1.a \
		%/libapi-ms-win-core-systemtopology-l1-1-2.a \
		%/libapi-ms-win-core-threadpool-l1-2-0.a \
		%/libapi-ms-win-core-threadpool-legacy-l1-1-0.a \
		%/libapi-ms-win-core-timezone-l1-1-0.a \
		%/libapi-ms-win-core-timezone-l1-1-1.a \
		%/libapi-ms-win-core-toolhelp-l1-1-0.a \
		%/libapi-ms-win-core-toolhelp-l1-1-1.a \
		%/libapi-ms-win-core-url-l1-1-0.a \
		%/libapi-ms-win-core-util-l1-1-0.a \
		%/libapi-ms-win-core-util-l1-1-1.a \
		%/libapi-ms-win-core-version-l1-1-0.a \
		%/libapi-ms-win-core-version-l1-1-1.a \
		%/libapi-ms-win-core-versionansi-l1-1-0.a \
		%/libapi-ms-win-core-versionansi-l1-1-1.a \
		%/libapi-ms-win-core-windowsceip-l1-1-0.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-0.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-1.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-2.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-3.a \
		%/libapi-ms-win-core-winrt-error-l1-1-0.a \
		%/libapi-ms-win-core-winrt-error-l1-1-1.a \
		%/libapi-ms-win-core-winrt-l1-1-0.a \
		%/libapi-ms-win-core-winrt-registration-l1-1-0.a \
		%/libapi-ms-win-core-winrt-robuffer-l1-1-0.a \
		%/libapi-ms-win-core-winrt-roparameterizediid-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-1.a \
		%/libapi-ms-win-core-wow64-l1-1-0.a \
		%/libapi-ms-win-core-wow64-l1-1-1.a \
		%/libapi-ms-win-core-wow64-l1-1-2.a \
		%/libapi-ms-win-core-wow64-l1-1-3.a \
		%/libapi-ms-win-core-xstate-l2-1-0.a \
		%/libapi-ms-win-core-xstate-l2-1-1.a \
		%/libapi-ms-win-core-xstate-l2-1-2.a \
		%/libapi-ms-win-devices-config-l1-1-1.a \
		%/libapi-ms-win-devices-config-l1-1-2.a \
		%/libapi-ms-win-devices-query-l1-1-0.a \
		%/libapi-ms-win-devices-query-l1-1-1.a \
		%/libapi-ms-win-devices-swdevice-l1-1-0.a \
		%/libapi-ms-win-devices-swdevice-l1-1-1.a \
		%/libapi-ms-win-eventing-classicprovider-l1-1-0.a \
		%/libapi-ms-win-eventing-consumer-l1-1-0.a \
		%/libapi-ms-win-eventing-consumer-l1-1-1.a \
		%/libapi-ms-win-eventing-consumer-l1-1-2.a \
		%/libapi-ms-win-eventing-controller-l1-1-0.a \
		%/libapi-ms-win-eventing-controller-l1-1-1.a \
		%/libapi-ms-win-eventing-legacy-l1-1-0.a \
		%/libapi-ms-win-eventing-obsolete-l1-1-0.a \
		%/libapi-ms-win-eventing-provider-l1-1-0.a \
		%/libapi-ms-win-eventing-tdh-l1-1-0.a \
		%/libapi-ms-win-eventing-tdh-l1-1-1.a \
		%/libapi-ms-win-eventing-tdh-l1-1-2.a \
		%/libapi-ms-win-eventlog-legacy-l1-1-0.a \
		%/libapi-ms-win-gaming-deviceinformation-l1-1-0.a \
		%/libapi-ms-win-mm-time-l1-1-0.a \
		%/libapi-ms-win-oobe-notification-l1-1-0.a \
		%/libapi-ms-win-perf-legacy-l1-1-0.a \
		%/libapi-ms-win-power-base-l1-1-0.a \
		%/libapi-ms-win-power-limitsmanagement-l1-1-0.a \
		%/libapi-ms-win-power-setting-l1-1-0.a \
		%/libapi-ms-win-power-setting-l1-1-1.a \
		%/libapi-ms-win-ro-typeresolution-l1-1-0.a \
		%/libapi-ms-win-ro-typeresolution-l1-1-1.a \
		%/libapi-ms-win-security-appcontainer-l1-1-0.a \
		%/libapi-ms-win-security-audit-l1-1-0.a \
		%/libapi-ms-win-security-audit-l1-1-1.a \
		%/libapi-ms-win-security-base-ansi-l1-1-0.a \
		%/libapi-ms-win-security-base-l1-1-0.a \
		%/libapi-ms-win-security-base-l1-2-0.a \
		%/libapi-ms-win-security-base-l1-2-1.a \
		%/libapi-ms-win-security-base-l1-2-2.a \
		%/libapi-ms-win-security-cpwl-l1-1-0.a \
		%/libapi-ms-win-security-credentials-l1-1-0.a \
		%/libapi-ms-win-security-cryptoapi-l1-1-0.a \
		%/libapi-ms-win-security-isolatedcontainer-l1-1-0.a \
		%/libapi-ms-win-security-isolatedcontainer-l1-1-1.a \
		%/libapi-ms-win-security-logon-l1-1-0.a \
		%/libapi-ms-win-security-logon-l1-1-1.a \
		%/libapi-ms-win-security-lsalookup-ansi-l2-1-0.a \
		%/libapi-ms-win-security-lsalookup-l2-1-0.a \
		%/libapi-ms-win-security-lsalookup-l2-1-1.a \
		%/libapi-ms-win-security-lsapolicy-l1-1-0.a \
		%/libapi-ms-win-security-provider-ansi-l1-1-0.a \
		%/libapi-ms-win-security-provider-l1-1-0.a \
		%/libapi-ms-win-security-sddl-ansi-l1-1-0.a \
		%/libapi-ms-win-security-sddl-l1-1-0.a \
		%/libapi-ms-win-security-systemfunctions-l1-1-0.a \
		%/libapi-ms-win-security-trustee-l1-1-0.a \
		%/libapi-ms-win-security-trustee-l1-1-1.a \
		%/libapi-ms-win-security-trustee-l1-1-2.a \
		%/libapi-ms-win-service-core-ansi-l1-1-0.a \
		%/libapi-ms-win-service-core-ansi-l1-1-1.a \
		%/libapi-ms-win-service-core-l1-1-0.a \
		%/libapi-ms-win-service-core-l1-1-1.a \
		%/libapi-ms-win-service-core-l1-1-2.a \
		%/libapi-ms-win-service-core-l1-1-3.a \
		%/libapi-ms-win-service-core-l1-1-4.a \
		%/libapi-ms-win-service-core-l1-1-5.a \
		%/libapi-ms-win-service-legacy-l1-1-0.a \
		%/libapi-ms-win-service-management-l1-1-0.a \
		%/libapi-ms-win-service-management-l2-1-0.a \
		%/libapi-ms-win-service-winsvc-l1-1-0.a \
		%/libapi-ms-win-shcore-obsolete-l1-1-0.a \
		%/libapi-ms-win-shcore-path-l1-1-0.a \
		%/libapi-ms-win-shcore-registry-l1-1-0.a \
		%/libapi-ms-win-shcore-registry-l1-1-1.a \
		%/libapi-ms-win-shcore-scaling-l1-1-0.a \
		%/libapi-ms-win-shcore-scaling-l1-1-1.a \
		%/libapi-ms-win-shcore-scaling-l1-1-2.a \
		%/libapi-ms-win-shcore-stream-l1-1-0.a \
		%/libapi-ms-win-shcore-stream-winrt-l1-1-0.a \
		%/libapi-ms-win-shcore-sysinfo-l1-1-0.a \
		%/libapi-ms-win-shcore-unicodeansi-l1-1-0.a \
		%/libapi-ms-win-shell-shdirectory-l1-1-0.a \
		%/libext-ms-win-advapi32-lsa-l1-1-1.a \
		%/libext-ms-win-wer-wct-l1-1-0.a \
		%/libauthz_onecore.a \
		%/libbcrypt_onecore.a \
		%/libcabinet.a \
		%/libcrypt32_onecore.a \
		%/libcryptbase_onecore.a \
		%/libcryptnet_onecore.a \
		%/libdfscli_onecore.a \
		%/libdhcpcsvc.a \
		%/libdhcpcsvc6.a \
		%/libdiagnosticdataquery.a \
		%/libdnsapi_onecore.a \
		%/libdsparse.a \
		%/libdsrole.a \
		%/libfltlib.a \
		%/libicu.a \
		%/libiphlpapi_onecore.a \
		%/liblogoncli_onecore.a \
		%/libmpr_onecore.a \
		%/libmswsock_onecore.a \
		%/libncrypt_onecore.a \
		%/libnetutils_onecore.a \
		%/libntdll_onecore.a \
		%/liboleaut32_onecore.a \
		%/libpowrprof_onecore.a \
		%/libprofapi.a \
		%/librpcrt4_onecore.a \
		%/libsamcli.a \
		%/libschedcli.a \
		%/libsrvcli_onecore.a \
		%/libsspicli_onecore.a \
		%/libuserenv_onecore.a \
		%/libwebsocket.a \
		%/libwinhttp_onecore.a \
		%/libwkscli.a \
		%/libwldap32.a \
		%/libwpprecorderum.a \
		%/libws2_32.a \
		%/libxmllite.a
	rm -f $@
	cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(RANLIB) $@

%/libonecoreuap_apiset.a: lib-common/onecoreuap_apiset.mri \
		%/libapi-ms-win-appmodel-runtime-l1-1-0.a \
		%/libapi-ms-win-appmodel-runtime-l1-1-1.a \
		%/libapi-ms-win-appmodel-runtime-l1-1-2.a \
		%/libapi-ms-win-appmodel-runtime-l1-1-3.a \
		%/libapi-ms-win-core-apiquery-l2-1-0.a \
		%/libapi-ms-win-core-atoms-l1-1-0.a \
		%/libapi-ms-win-core-backgroundtask-l1-1-0.a \
		%/libapi-ms-win-core-calendar-l1-1-0.a \
		%/libapi-ms-win-core-com-l1-1-0.a \
		%/libapi-ms-win-core-com-l1-1-1.a \
		%/libapi-ms-win-core-com-l1-1-2.a \
		%/libapi-ms-win-core-com-l1-1-3.a \
		%/libapi-ms-win-core-com-l2-1-1.a \
		%/libapi-ms-win-core-com-midlproxystub-l1-1-0.a \
		%/libapi-ms-win-core-comm-l1-1-0.a \
		%/libapi-ms-win-core-comm-l1-1-1.a \
		%/libapi-ms-win-core-comm-l1-1-2.a \
		%/libapi-ms-win-core-console-l1-1-0.a \
		%/libapi-ms-win-core-console-l1-2-0.a \
		%/libapi-ms-win-core-console-l1-2-1.a \
		%/libapi-ms-win-core-console-l2-1-0.a \
		%/libapi-ms-win-core-console-l2-2-0.a \
		%/libapi-ms-win-core-console-l3-2-0.a \
		%/libapi-ms-win-core-datetime-l1-1-0.a \
		%/libapi-ms-win-core-datetime-l1-1-1.a \
		%/libapi-ms-win-core-datetime-l1-1-2.a \
		%/libapi-ms-win-core-debug-l1-1-0.a \
		%/libapi-ms-win-core-debug-l1-1-1.a \
		%/libapi-ms-win-core-debug-l1-1-2.a \
		%/libapi-ms-win-core-debug-minidump-l1-1-0.a \
		%/libapi-ms-win-core-delayload-l1-1-0.a \
		%/libapi-ms-win-core-delayload-l1-1-1.a \
		%/libapi-ms-win-core-enclave-l1-1-0.a \
		%/libapi-ms-win-core-enclave-l1-1-1.a \
		%/libapi-ms-win-core-errorhandling-l1-1-0.a \
		%/libapi-ms-win-core-errorhandling-l1-1-1.a \
		%/libapi-ms-win-core-errorhandling-l1-1-2.a \
		%/libapi-ms-win-core-errorhandling-l1-1-3.a \
		%/libapi-ms-win-core-featurestaging-l1-1-0.a \
		%/libapi-ms-win-core-featurestaging-l1-1-1.a \
		%/libapi-ms-win-core-fibers-l1-1-0.a \
		%/libapi-ms-win-core-fibers-l1-1-1.a \
		%/libapi-ms-win-core-fibers-l2-1-0.a \
		%/libapi-ms-win-core-fibers-l2-1-1.a \
		%/libapi-ms-win-core-file-ansi-l1-1-0.a \
		%/libapi-ms-win-core-file-ansi-l2-1-0.a \
		%/libapi-ms-win-core-file-fromapp-l1-1-0.a \
		%/libapi-ms-win-core-file-l1-1-0.a \
		%/libapi-ms-win-core-file-l1-2-0.a \
		%/libapi-ms-win-core-file-l1-2-1.a \
		%/libapi-ms-win-core-file-l1-2-2.a \
		%/libapi-ms-win-core-file-l1-2-3.a \
		%/libapi-ms-win-core-file-l2-1-0.a \
		%/libapi-ms-win-core-file-l2-1-1.a \
		%/libapi-ms-win-core-file-l2-1-2.a \
		%/libapi-ms-win-core-file-l2-1-3.a \
		%/libapi-ms-win-core-firmware-l1-1-0.a \
		%/libapi-ms-win-core-handle-l1-1-0.a \
		%/libapi-ms-win-core-heap-l1-1-0.a \
		%/libapi-ms-win-core-heap-l2-1-0.a \
		%/libapi-ms-win-core-heap-obsolete-l1-1-0.a \
		%/libapi-ms-win-core-interlocked-l1-1-0.a \
		%/libapi-ms-win-core-interlocked-l1-2-0.a \
		%/libapi-ms-win-core-io-l1-1-0.a \
		%/libapi-ms-win-core-io-l1-1-1.a \
		%/libapi-ms-win-core-job-l1-1-0.a \
		%/libapi-ms-win-core-job-l2-1-0.a \
		%/libapi-ms-win-core-job-l2-1-1.a \
		%/libapi-ms-win-core-kernel32-legacy-ansi-l1-1-0.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-0.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-1.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-2.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-3.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-4.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-5.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-6.a \
		%/libapi-ms-win-core-largeinteger-l1-1-0.a \
		%/libapi-ms-win-core-libraryloader-l1-2-0.a \
		%/libapi-ms-win-core-libraryloader-l1-2-1.a \
		%/libapi-ms-win-core-libraryloader-l1-2-2.a \
		%/libapi-ms-win-core-libraryloader-l2-1-0.a \
		%/libapi-ms-win-core-localization-ansi-l1-1-0.a \
		%/libapi-ms-win-core-localization-l1-2-0.a \
		%/libapi-ms-win-core-localization-l1-2-1.a \
		%/libapi-ms-win-core-localization-l1-2-2.a \
		%/libapi-ms-win-core-localization-l1-2-3.a \
		%/libapi-ms-win-core-localization-l1-2-4.a \
		%/libapi-ms-win-core-localization-l2-1-0.a \
		%/libapi-ms-win-core-localization-obsolete-l1-2-0.a \
		%/libapi-ms-win-core-memory-l1-1-0.a \
		%/libapi-ms-win-core-memory-l1-1-1.a \
		%/libapi-ms-win-core-memory-l1-1-2.a \
		%/libapi-ms-win-core-memory-l1-1-3.a \
		%/libapi-ms-win-core-memory-l1-1-4.a \
		%/libapi-ms-win-core-memory-l1-1-5.a \
		%/libapi-ms-win-core-memory-l1-1-6.a \
		%/libapi-ms-win-core-memory-l1-1-7.a \
		%/libapi-ms-win-core-namedpipe-ansi-l1-1-0.a \
		%/libapi-ms-win-core-namedpipe-ansi-l1-1-1.a \
		%/libapi-ms-win-core-namedpipe-l1-1-0.a \
		%/libapi-ms-win-core-namedpipe-l1-2-1.a \
		%/libapi-ms-win-core-namedpipe-l1-2-2.a \
		%/libapi-ms-win-core-namespace-ansi-l1-1-0.a \
		%/libapi-ms-win-core-namespace-l1-1-0.a \
		%/libapi-ms-win-core-normalization-l1-1-0.a \
		%/libapi-ms-win-core-path-l1-1-0.a \
		%/libapi-ms-win-core-perfcounters-l1-1-0.a \
		%/libapi-ms-win-core-privateprofile-l1-1-0.a \
		%/libapi-ms-win-core-privateprofile-l1-1-1.a \
		%/libapi-ms-win-core-processenvironment-ansi-l1-1-0.a \
		%/libapi-ms-win-core-processenvironment-l1-1-0.a \
		%/libapi-ms-win-core-processenvironment-l1-2-0.a \
		%/libapi-ms-win-core-processsnapshot-l1-1-0.a \
		%/libapi-ms-win-core-processthreads-l1-1-0.a \
		%/libapi-ms-win-core-processthreads-l1-1-1.a \
		%/libapi-ms-win-core-processthreads-l1-1-2.a \
		%/libapi-ms-win-core-processthreads-l1-1-3.a \
		%/libapi-ms-win-core-processthreads-l1-1-4.a \
		%/libapi-ms-win-core-processtopology-l1-1-0.a \
		%/libapi-ms-win-core-processtopology-obsolete-l1-1-0.a \
		%/libapi-ms-win-core-processtopology-obsolete-l1-1-1.a \
		%/libapi-ms-win-core-profile-l1-1-0.a \
		%/libapi-ms-win-core-psapi-ansi-l1-1-0.a \
		%/libapi-ms-win-core-psapi-l1-1-0.a \
		%/libapi-ms-win-core-psm-appnotify-l1-1-0.a \
		%/libapi-ms-win-core-quirks-l1-1-0.a \
		%/libapi-ms-win-core-quirks-l1-1-1.a \
		%/libapi-ms-win-core-realtime-l1-1-0.a \
		%/libapi-ms-win-core-realtime-l1-1-1.a \
		%/libapi-ms-win-core-realtime-l1-1-2.a \
		%/libapi-ms-win-core-registry-l1-1-0.a \
		%/libapi-ms-win-core-registry-l1-1-1.a \
		%/libapi-ms-win-core-registry-l1-1-2.a \
		%/libapi-ms-win-core-registry-l2-1-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-1-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-2-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-2-1.a \
		%/libapi-ms-win-core-shutdown-ansi-l1-1-0.a \
		%/libapi-ms-win-core-shutdown-l1-1-0.a \
		%/libapi-ms-win-core-shutdown-l1-1-1.a \
		%/libapi-ms-win-core-slapi-l1-1-0.a \
		%/libapi-ms-win-core-string-l1-1-0.a \
		%/libapi-ms-win-core-string-l2-1-0.a \
		%/libapi-ms-win-core-string-l2-1-1.a \
		%/libapi-ms-win-core-string-obsolete-l1-1-0.a \
		%/libapi-ms-win-core-string-obsolete-l1-1-1.a \
		%/libapi-ms-win-core-stringansi-l1-1-0.a \
		%/libapi-ms-win-core-synch-ansi-l1-1-0.a \
		%/libapi-ms-win-core-synch-l1-1-0.a \
		%/libapi-ms-win-core-synch-l1-2-0.a \
		%/libapi-ms-win-core-synch-l1-2-1.a \
		%/libapi-ms-win-core-sysinfo-l1-1-0.a \
		%/libapi-ms-win-core-sysinfo-l1-2-0.a \
		%/libapi-ms-win-core-sysinfo-l1-2-1.a \
		%/libapi-ms-win-core-sysinfo-l1-2-2.a \
		%/libapi-ms-win-core-sysinfo-l1-2-3.a \
		%/libapi-ms-win-core-sysinfo-l1-2-4.a \
		%/libapi-ms-win-core-sysinfo-l1-2-5.a \
		%/libapi-ms-win-core-sysinfo-l1-2-6.a \
		%/libapi-ms-win-core-systemtopology-l1-1-0.a \
		%/libapi-ms-win-core-systemtopology-l1-1-1.a \
		%/libapi-ms-win-core-threadpool-l1-2-0.a \
		%/libapi-ms-win-core-threadpool-legacy-l1-1-0.a \
		%/libapi-ms-win-core-timezone-l1-1-0.a \
		%/libapi-ms-win-core-timezone-l1-1-1.a \
		%/libapi-ms-win-core-toolhelp-l1-1-0.a \
		%/libapi-ms-win-core-toolhelp-l1-1-1.a \
		%/libapi-ms-win-core-url-l1-1-0.a \
		%/libapi-ms-win-core-util-l1-1-0.a \
		%/libapi-ms-win-core-util-l1-1-1.a \
		%/libapi-ms-win-core-version-l1-1-0.a \
		%/libapi-ms-win-core-version-l1-1-1.a \
		%/libapi-ms-win-core-versionansi-l1-1-0.a \
		%/libapi-ms-win-core-versionansi-l1-1-1.a \
		%/libapi-ms-win-core-windowsceip-l1-1-0.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-0.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-1.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-2.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-3.a \
		%/libapi-ms-win-core-winrt-error-l1-1-0.a \
		%/libapi-ms-win-core-winrt-error-l1-1-1.a \
		%/libapi-ms-win-core-winrt-l1-1-0.a \
		%/libapi-ms-win-core-winrt-registration-l1-1-0.a \
		%/libapi-ms-win-core-winrt-robuffer-l1-1-0.a \
		%/libapi-ms-win-core-winrt-roparameterizediid-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-1.a \
		%/libapi-ms-win-core-wow64-l1-1-0.a \
		%/libapi-ms-win-core-wow64-l1-1-1.a \
		%/libapi-ms-win-core-wow64-l1-1-2.a \
		%/libapi-ms-win-core-wow64-l1-1-3.a \
		%/libapi-ms-win-core-xstate-l2-1-0.a \
		%/libapi-ms-win-core-xstate-l2-1-1.a \
		%/libapi-ms-win-devices-config-l1-1-1.a \
		%/libapi-ms-win-devices-config-l1-1-2.a \
		%/libapi-ms-win-devices-query-l1-1-0.a \
		%/libapi-ms-win-devices-query-l1-1-1.a \
		%/libapi-ms-win-devices-swdevice-l1-1-0.a \
		%/libapi-ms-win-devices-swdevice-l1-1-1.a \
		%/libapi-ms-win-eventing-classicprovider-l1-1-0.a \
		%/libapi-ms-win-eventing-consumer-l1-1-0.a \
		%/libapi-ms-win-eventing-consumer-l1-1-1.a \
		%/libapi-ms-win-eventing-controller-l1-1-0.a \
		%/libapi-ms-win-eventing-legacy-l1-1-0.a \
		%/libapi-ms-win-eventing-obsolete-l1-1-0.a \
		%/libapi-ms-win-eventing-provider-l1-1-0.a \
		%/libapi-ms-win-eventing-tdh-l1-1-0.a \
		%/libapi-ms-win-eventing-tdh-l1-1-1.a \
		%/libapi-ms-win-gaming-deviceinformation-l1-1-0.a \
		%/libapi-ms-win-gaming-expandedresources-l1-1-0.a \
		%/libapi-ms-win-gaming-tcui-l1-1-0.a \
		%/libapi-ms-win-gaming-tcui-l1-1-1.a \
		%/libapi-ms-win-gaming-tcui-l1-1-2.a \
		%/libapi-ms-win-gaming-tcui-l1-1-3.a \
		%/libapi-ms-win-gaming-tcui-l1-1-4.a \
		%/libapi-ms-win-mm-time-l1-1-0.a \
		%/libapi-ms-win-net-isolation-l1-1-0.a \
		%/libapi-ms-win-net-isolation-l1-1-1.a \
		%/libapi-ms-win-ntuser-sysparams-l1-1-0.a \
		%/libapi-ms-win-oobe-notification-l1-1-0.a \
		%/libapi-ms-win-perf-legacy-l1-1-0.a \
		%/libapi-ms-win-power-base-l1-1-0.a \
		%/libapi-ms-win-power-limitsmanagement-l1-1-0.a \
		%/libapi-ms-win-power-setting-l1-1-0.a \
		%/libapi-ms-win-power-setting-l1-1-1.a \
		%/libapi-ms-win-ro-typeresolution-l1-1-0.a \
		%/libapi-ms-win-ro-typeresolution-l1-1-1.a \
		%/libapi-ms-win-security-appcontainer-l1-1-0.a \
		%/libapi-ms-win-security-base-ansi-l1-1-0.a \
		%/libapi-ms-win-security-base-l1-1-0.a \
		%/libapi-ms-win-security-base-l1-2-0.a \
		%/libapi-ms-win-security-base-l1-2-1.a \
		%/libapi-ms-win-security-base-l1-2-2.a \
		%/libapi-ms-win-security-cpwl-l1-1-0.a \
		%/libapi-ms-win-security-credentials-l1-1-0.a \
		%/libapi-ms-win-security-cryptoapi-l1-1-0.a \
		%/libapi-ms-win-security-isolatedcontainer-l1-1-0.a \
		%/libapi-ms-win-security-isolatedcontainer-l1-1-1.a \
		%/libapi-ms-win-security-lsalookup-ansi-l2-1-0.a \
		%/libapi-ms-win-security-lsalookup-l2-1-0.a \
		%/libapi-ms-win-security-lsalookup-l2-1-1.a \
		%/libapi-ms-win-security-lsapolicy-l1-1-0.a \
		%/libapi-ms-win-security-provider-ansi-l1-1-0.a \
		%/libapi-ms-win-security-provider-l1-1-0.a \
		%/libapi-ms-win-security-sddl-ansi-l1-1-0.a \
		%/libapi-ms-win-security-sddl-l1-1-0.a \
		%/libapi-ms-win-security-systemfunctions-l1-1-0.a \
		%/libapi-ms-win-service-core-ansi-l1-1-0.a \
		%/libapi-ms-win-service-core-ansi-l1-1-1.a \
		%/libapi-ms-win-service-core-l1-1-0.a \
		%/libapi-ms-win-service-core-l1-1-1.a \
		%/libapi-ms-win-service-core-l1-1-2.a \
		%/libapi-ms-win-service-core-l1-1-3.a \
		%/libapi-ms-win-service-core-l1-1-4.a \
		%/libapi-ms-win-service-management-l1-1-0.a \
		%/libapi-ms-win-service-management-l2-1-0.a \
		%/libapi-ms-win-service-winsvc-l1-1-0.a \
		%/libapi-ms-win-shcore-obsolete-l1-1-0.a \
		%/libapi-ms-win-shcore-path-l1-1-0.a \
		%/libapi-ms-win-shcore-registry-l1-1-0.a \
		%/libapi-ms-win-shcore-registry-l1-1-1.a \
		%/libapi-ms-win-shcore-scaling-l1-1-0.a \
		%/libapi-ms-win-shcore-scaling-l1-1-1.a \
		%/libapi-ms-win-shcore-scaling-l1-1-2.a \
		%/libapi-ms-win-shcore-stream-l1-1-0.a \
		%/libapi-ms-win-shcore-stream-winrt-l1-1-0.a \
		%/libapi-ms-win-shcore-sysinfo-l1-1-0.a \
		%/libapi-ms-win-shcore-unicodeansi-l1-1-0.a \
		%/libapi-ms-win-shell-shdirectory-l1-1-0.a \
		%/libauthz.a \
		%/libbcrypt.a \
		%/libcabinet.a \
		%/libchakrart.a \
		%/libcrypt32.a \
		%/libcryptbase.a \
		%/libcryptnet.a \
		%/libd2d1.a \
		%/libd3d11.a \
		%/libd3d12.a \
		%/libd3dcompiler_47.a \
		%/libdfscli.a \
		%/libdhcpcsvc.a \
		%/libdhcpcsvc6.a \
		%/libdirectml.a \
		%/libdnsapi.a \
		%/libdsrole.a \
		%/libdwrite.a \
		%/libdxgi.a \
		%/libesent.a \
		%/libfltlib.a \
		%/libhid.a \
		%/libhrtfapo.a \
		%/libicu.a \
		%/libinkobjcore.a \
		%/libiphlpapi.a \
		%/liblogoncli.a \
		%/libmf.a \
		%/libmfplat.a \
		%/libmfreadwrite.a \
		%/libmfsensorgroup.a \
		%/libmmdevapi.a \
		%/libmpr.a \
		%/libmsajapi.a \
		%/libmscms.a \
		%/libmswsock.a \
		%/libncrypt.a \
		%/libnetutils.a \
		%/liboleaut32.a \
		%/libpowrprof.a \
		%/libprofapi.a \
		%/libpropsys.a \
		%/librometadata.a \
		%/librpcrt4.a \
		%/libsamcli.a \
		%/libschedcli.a \
		%/libsrvcli.a \
		%/libsspicli.a \
		%/libuiautomationcore.a \
		%/libuserenv.a \
		%/libwebauthn.a \
		%/libwebservices.a \
		%/libwebsocket.a \
		%/libwindows.ai.machinelearning.a \
		%/libwindows.data.pdf.a \
		%/libwindows.networking.a \
		%/libwindowscodecs.a \
		%/libwinhttp.a \
		%/libwkscli.a \
		%/libwldap32.a \
		%/libwpprecorderum.a \
		%/libws2_32.a \
		%/libxaudio2_9.a \
		%/libxmllite.a
	rm -f $@
	cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(RANLIB) $@

%/libpathcch.a: lib-common/pathcch.mri \
		%/libapi-ms-win-core-path-l1-1-0.a
	rm -f $@
	cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(RANLIB) $@

%/libruntimeobject.a: lib-common/runtimeobject.mri \
		%/libapi-ms-win-core-winrt-l1-1-0.a \
		%/libapi-ms-win-core-winrt-error-l1-1-0.a \
		%/libapi-ms-win-core-winrt-error-l1-1-1.a \
		%/libapi-ms-win-core-winrt-registration-l1-1-0.a \
		%/libapi-ms-win-core-winrt-robuffer-l1-1-0.a \
		%/libapi-ms-win-core-winrt-roparameterizediid-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-0.a \
		%/libapi-ms-win-ro-typeresolution-l1-1-0.a
	rm -f $@
	cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(RANLIB) $@

%/libsynchronization.a: lib-common/synchronization.mri \
		%/libapi-ms-win-core-synch-l1-2-0.a
	rm -f $@
	cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(RANLIB) $@

%/libwindowsapp.a: lib-common/windowsapp.mri \
		%/libapi-ms-win-appmodel-runtime-l1-1-0_windowsapp.a \
		%/libapi-ms-win-appmodel-runtime-l1-1-1_windowsapp.a \
		%/libapi-ms-win-appmodel-runtime-l1-1-2.a \
		%/libapi-ms-win-appmodel-runtime-l1-1-3.a \
		%/libapi-ms-win-core-atoms-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-com-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-com-l1-1-1_windowsapp.a \
		%/libapi-ms-win-core-com-l2-1-1.a \
		%/libapi-ms-win-core-com-midlproxystub-l1-1-0.a \
		%/libapi-ms-win-core-comm-l1-1-0.a \
		%/libapi-ms-win-core-comm-l1-1-1.a \
		%/libapi-ms-win-core-comm-l1-1-2.a \
		%/libapi-ms-win-core-console-l1-1-0.a \
		%/libapi-ms-win-core-console-l1-2-0.a \
		%/libapi-ms-win-core-console-l2-1-0.a \
		%/libapi-ms-win-core-console-l2-2-0.a \
		%/libapi-ms-win-core-console-l3-2-0.a \
		%/libapi-ms-win-core-datetime-l1-1-0.a \
		%/libapi-ms-win-core-datetime-l1-1-1.a \
		%/libapi-ms-win-core-datetime-l1-1-2.a \
		%/libapi-ms-win-core-debug-l1-1-0.a \
		%/libapi-ms-win-core-debug-l1-1-1.a \
		%/libapi-ms-win-core-delayload-l1-1-0.a \
		%/libapi-ms-win-core-delayload-l1-1-1.a \
		%/libapi-ms-win-core-enclave-l1-1-0.a \
		%/libapi-ms-win-core-errorhandling-l1-1-0.a \
		%/libapi-ms-win-core-errorhandling-l1-1-1_windowsapp.a \
		%/libapi-ms-win-core-errorhandling-l1-1-2.a \
		%/libapi-ms-win-core-errorhandling-l1-1-3_windowsapp.a \
		%/libapi-ms-win-core-featurestaging-l1-1-0.a \
		%/libapi-ms-win-core-featurestaging-l1-1-1.a \
		%/libapi-ms-win-core-fibers-l1-1-0.a \
		%/libapi-ms-win-core-fibers-l1-1-1.a \
		%/libapi-ms-win-core-fibers-l2-1-0_windowsapp.a \
		%/libapi-ms-win-core-fibers-l2-1-1.a \
		%/libapi-ms-win-core-file-ansi-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-file-ansi-l2-1-0_windowsapp.a \
		%/libapi-ms-win-core-file-fromapp-l1-1-0.a \
		%/libapi-ms-win-core-file-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-file-l1-2-0.a \
		%/libapi-ms-win-core-file-l1-2-2_windowsapp.a \
		%/libapi-ms-win-core-file-l2-1-0.a \
		%/libapi-ms-win-core-file-l2-1-2_windowsapp.a \
		%/libapi-ms-win-core-firmware-l1-1-0.a \
		%/libapi-ms-win-core-handle-l1-1-0.a \
		%/libapi-ms-win-core-heap-l1-1-0.a \
		%/libapi-ms-win-core-heap-l2-1-0_windowsapp.a \
		%/libapi-ms-win-core-heap-obsolete-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-interlocked-l1-1-0.a \
		%/libapi-ms-win-core-interlocked-l1-2-0.a \
		%/libapi-ms-win-core-io-l1-1-0.a \
		%/libapi-ms-win-core-io-l1-1-1_windowsapp.a \
		%/libapi-ms-win-core-job-l2-1-0_windowsapp.a \
		%/libapi-ms-win-core-kernel32-legacy-ansi-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-1_windowsapp.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-2_windowsapp.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-5_windowsapp.a \
		%/libapi-ms-win-core-largeinteger-l1-1-0.a \
		%/libapi-ms-win-core-libraryloader-l1-2-0_windowsapp.a \
		%/libapi-ms-win-core-libraryloader-l1-2-1.a \
		%/libapi-ms-win-core-libraryloader-l1-2-2.a \
		%/libapi-ms-win-core-libraryloader-l2-1-0.a \
		%/libapi-ms-win-core-localization-ansi-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-localization-l1-2-0_windowsapp.a \
		%/libapi-ms-win-core-localization-l1-2-1.a \
		%/libapi-ms-win-core-localization-l1-2-2.a \
		%/libapi-ms-win-core-localization-l2-1-0_windowsapp.a \
		%/libapi-ms-win-core-localization-obsolete-l1-2-0_windowsapp.a \
		%/libapi-ms-win-core-memory-l1-1-0.a \
		%/libapi-ms-win-core-memory-l1-1-1_windowsapp.a \
		%/libapi-ms-win-core-memory-l1-1-2_windowsapp.a \
		%/libapi-ms-win-core-memory-l1-1-3.a \
		%/libapi-ms-win-core-memory-l1-1-5_windowsapp.a \
		%/libapi-ms-win-core-memory-l1-1-6_windowsapp.a \
		%/libapi-ms-win-core-memory-l1-1-7_windowsapp.a \
		%/libapi-ms-win-core-namedpipe-ansi-l1-1-0.a \
		%/libapi-ms-win-core-namedpipe-ansi-l1-1-1.a \
		%/libapi-ms-win-core-namedpipe-l1-1-0.a \
		%/libapi-ms-win-core-namedpipe-l1-2-1.a \
		%/libapi-ms-win-core-namedpipe-l1-2-2.a \
		%/libapi-ms-win-core-namespace-ansi-l1-1-0.a \
		%/libapi-ms-win-core-namespace-l1-1-0.a \
		%/libapi-ms-win-core-normalization-l1-1-0.a \
		%/libapi-ms-win-core-path-l1-1-0.a \
		%/libapi-ms-win-core-privateprofile-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-privateprofile-l1-1-1_windowsapp.a \
		%/libapi-ms-win-core-processenvironment-ansi-l1-1-0.a \
		%/libapi-ms-win-core-processenvironment-l1-1-0.a \
		%/libapi-ms-win-core-processenvironment-l1-2-0_windowsapp.a \
		%/libapi-ms-win-core-processsnapshot-l1-1-0.a \
		%/libapi-ms-win-core-processthreads-l1-1-0.a \
		%/libapi-ms-win-core-processthreads-l1-1-1.a \
		%/libapi-ms-win-core-processthreads-l1-1-2_windowsapp.a \
		%/libapi-ms-win-core-processthreads-l1-1-3_windowsapp.a \
		%/libapi-ms-win-core-processtopology-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-processtopology-obsolete-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-profile-l1-1-0.a \
		%/libapi-ms-win-core-psapi-ansi-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-psapi-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-psm-appnotify-l1-1-0.a \
		%/libapi-ms-win-core-realtime-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-realtime-l1-1-1.a \
		%/libapi-ms-win-core-realtime-l1-1-2.a \
		%/libapi-ms-win-core-registry-l1-1-0.a \
		%/libapi-ms-win-core-registry-l1-1-1.a \
		%/libapi-ms-win-core-registry-l1-1-2.a \
		%/libapi-ms-win-core-registry-l2-1-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-1-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-2-0_windowsapp.a \
		%/libapi-ms-win-core-shutdown-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-slapi-l1-1-0.a \
		%/libapi-ms-win-core-string-l1-1-0.a \
		%/libapi-ms-win-core-string-l2-1-0_windowsapp.a \
		%/libapi-ms-win-core-string-obsolete-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-string-obsolete-l1-1-1.a \
		%/libapi-ms-win-core-stringansi-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-synch-ansi-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-synch-l1-1-0.a \
		%/libapi-ms-win-core-synch-l1-2-0.a \
		%/libapi-ms-win-core-synch-l1-2-1.a \
		%/libapi-ms-win-core-sysinfo-l1-1-0.a \
		%/libapi-ms-win-core-sysinfo-l1-2-0_windowsapp.a \
		%/libapi-ms-win-core-sysinfo-l1-2-1_windowsapp.a \
		%/libapi-ms-win-core-sysinfo-l1-2-3_windowsapp.a \
		%/libapi-ms-win-core-sysinfo-l1-2-5.a \
		%/libapi-ms-win-core-sysinfo-l1-2-6.a \
		%/libapi-ms-win-core-systemtopology-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-threadpool-l1-2-0.a \
		%/libapi-ms-win-core-threadpool-legacy-l1-1-0.a \
		%/libapi-ms-win-core-timezone-l1-1-0.a \
		%/libapi-ms-win-core-timezone-l1-1-1.a \
		%/libapi-ms-win-core-toolhelp-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-url-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-util-l1-1-0.a \
		%/libapi-ms-win-core-versionansi-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-versionansi-l1-1-1_windowsapp.a \
		%/libapi-ms-win-core-version-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-version-l1-1-1_windowsapp.a \
		%/libapi-ms-win-core-windowsceip-l1-1-0.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-1.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-2.a \
		%/libapi-ms-win-core-winrt-error-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-winrt-error-l1-1-1_windowsapp.a \
		%/libapi-ms-win-core-winrt-l1-1-0.a \
		%/libapi-ms-win-core-winrt-registration-l1-1-0.a \
		%/libapi-ms-win-core-winrt-robuffer-l1-1-0.a \
		%/libapi-ms-win-core-winrt-roparameterizediid-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-wow64-l1-1-0_windowsapp.a \
		%/libapi-ms-win-core-wow64-l1-1-1_windowsapp.a \
		%/libapi-ms-win-core-xstate-l2-1-0_windowsapp.a \
		%/libapi-ms-win-devices-config-l1-1-1_windowsapp.a \
		%/libapi-ms-win-devices-config-l1-1-2_windowsapp.a \
		%/libapi-ms-win-devices-query-l1-1-0_windowsapp.a \
		%/libapi-ms-win-eventing-classicprovider-l1-1-0_windowsapp.a \
		%/libapi-ms-win-eventing-consumer-l1-1-0.a \
		%/libapi-ms-win-eventing-controller-l1-1-0_windowsapp.a \
		%/libapi-ms-win-eventing-legacy-l1-1-0_windowsapp.a \
		%/libapi-ms-win-eventing-obsolete-l1-1-0_windowsapp.a \
		%/libapi-ms-win-eventing-provider-l1-1-0.a \
		%/libapi-ms-win-eventlog-legacy-l1-1-0.a \
		%/libapi-ms-win-gaming-deviceinformation-l1-1-0.a \
		%/libapi-ms-win-gaming-expandedresources-l1-1-0.a \
		%/libapi-ms-win-gaming-tcui-l1-1-0.a \
		%/libapi-ms-win-gaming-tcui-l1-1-1.a \
		%/libapi-ms-win-gaming-tcui-l1-1-2.a \
		%/libapi-ms-win-gaming-tcui-l1-1-3.a \
		%/libapi-ms-win-gaming-tcui-l1-1-4.a \
		%/libapi-ms-win-mm-time-l1-1-0_windowsapp.a \
		%/libapi-ms-win-ntuser-sysparams-l1-1-0_windowsapp.a \
		%/libapi-ms-win-power-base-l1-1-0_windowsapp.a \
		%/libapi-ms-win-power-setting-l1-1-0_windowsapp.a \
		%/libapi-ms-win-ro-typeresolution-l1-1-0.a \
		%/libapi-ms-win-ro-typeresolution-l1-1-1.a \
		%/libapi-ms-win-security-appcontainer-l1-1-0.a \
		%/libapi-ms-win-security-base-ansi-l1-1-0_windowsapp.a \
		%/libapi-ms-win-security-base-l1-1-0_windowsapp.a \
		%/libapi-ms-win-security-base-l1-2-0_windowsapp.a \
		%/libapi-ms-win-security-base-l1-2-1.a \
		%/libapi-ms-win-security-base-l1-2-2.a \
		%/libapi-ms-win-security-cpwl-l1-1-0_windowsapp.a \
		%/libapi-ms-win-security-cryptoapi-l1-1-0_windowsapp.a \
		%/libapi-ms-win-security-isolatedcontainer-l1-1-0.a \
		%/libapi-ms-win-security-lsalookup-ansi-l2-1-0.a \
		%/libapi-ms-win-security-lsalookup-l2-1-0_windowsapp.a \
		%/libapi-ms-win-security-lsapolicy-l1-1-0_windowsapp.a \
		%/libapi-ms-win-security-provider-ansi-l1-1-0.a \
		%/libapi-ms-win-security-provider-l1-1-0.a \
		%/libapi-ms-win-security-sddl-ansi-l1-1-0.a \
		%/libapi-ms-win-security-sddl-l1-1-0.a \
		%/libapi-ms-win-security-systemfunctions-l1-1-0_windowsapp.a \
		%/libapi-ms-win-service-core-l1-1-0_windowsapp.a \
		%/libapi-ms-win-service-management-l1-1-0_windowsapp.a \
		%/libapi-ms-win-service-winsvc-l1-1-0_windowsapp.a \
		%/libapi-ms-win-shcore-obsolete-l1-1-0_windowsapp.a \
		%/libapi-ms-win-shcore-stream-winrt-l1-1-0.a \
		%/libbcrypt_windowsapp.a \
		%/libcabinet_windowsapp.a \
		%/libchakrart_windowsapp.a \
		%/libcoremessaging_windowsapp.a \
		%/libcrypt32_windowsapp.a \
		%/libd3d11_windowsapp.a \
		%/libd3d12_windowsapp.a \
		%/libd3dcompiler_47_windowsapp.a \
		%/libdhcpcsvc6_windowsapp.a \
		%/libdhcpcsvc_windowsapp.a \
		%/libdiagnosticdataquery_windowsapp.a \
		%/libdirectml_windowsapp.a \
		%/libdnsapi_windowsapp.a \
		%/libdxgi_windowsapp.a \
		%/libesent_windowsapp.a \
		%/libhid_windowsapp.a \
		%/libhrtfapo_windowsapp.a \
		%/libicu.a \
		%/libinkobjcore_windowsapp.a \
		%/libiphlpapi_windowsapp.a \
		%/libmfplat_windowsapp.a \
		%/libmfsensorgroup_windowsapp.a \
		%/libmf_windowsapp.a \
		%/libmmdevapi_windowsapp.a \
		%/libmpr_windowsapp.a \
		%/libmsajapi_windowsapp.a \
		%/libmscms_windowsapp.a \
		%/libmswsock_windowsapp.a \
		%/libncrypt_windowsapp.a \
		%/libnetutils_windowsapp.a \
		%/libntdll_windowsapp.a \
		%/liboleaut32_windowsapp.a \
		%/libpowrprof_windowsapp.a \
		%/libpropsys_windowsapp.a \
		%/libpsapi_windowsapp.a \
		%/librometadata.a \
		%/librpcrt4_windowsapp.a \
		%/libsrvcli_windowsapp.a \
		%/libsspicli_windowsapp.a \
		%/libuiautomationcore_windowsapp.a \
		%/liburlmon_windowsapp.a \
		%/libwebauthn_windowsapp.a \
		%/libwebservices_windowsapp.a \
		%/libwindows.ai.machinelearning.a \
		%/libwindows.data.pdf.a \
		%/libwindows.networking.a \
		%/libwindowscodecs_windowsapp.a \
		%/libwinhttp_windowsapp.a \
		%/libwintrust_windowsapp.a \
		%/libwkscli_windowsapp.a \
		%/libwlanapi_windowsapp.a \
		%/libws2_32_windowsapp.a \
		%/libxaudio2_9_windowsapp.a
	rm -f $@
	cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(RANLIB) $@

%/libwindowscoreheadless_apiset.a: lib-common/windowscoreheadless_apiset.mri \
		%/libapi-ms-win-appmodel-runtime-l1-1-0.a \
		%/libapi-ms-win-appmodel-runtime-l1-1-1.a \
		%/libapi-ms-win-appmodel-runtime-l1-1-2.a \
		%/libapi-ms-win-appmodel-runtime-l1-1-3.a \
		%/libapi-ms-win-core-apiquery-l2-1-0.a \
		%/libapi-ms-win-core-atoms-l1-1-0.a \
		%/libapi-ms-win-core-backgroundtask-l1-1-0.a \
		%/libapi-ms-win-core-calendar-l1-1-0.a \
		%/libapi-ms-win-core-com-l1-1-0.a \
		%/libapi-ms-win-core-com-l1-1-1.a \
		%/libapi-ms-win-core-com-l1-1-2.a \
		%/libapi-ms-win-core-com-l1-1-3.a \
		%/libapi-ms-win-core-com-midlproxystub-l1-1-0.a \
		%/libapi-ms-win-core-comm-l1-1-0.a \
		%/libapi-ms-win-core-comm-l1-1-1.a \
		%/libapi-ms-win-core-comm-l1-1-2.a \
		%/libapi-ms-win-core-console-l1-1-0.a \
		%/libapi-ms-win-core-console-l1-2-0.a \
		%/libapi-ms-win-core-console-l1-2-1.a \
		%/libapi-ms-win-core-console-l2-1-0.a \
		%/libapi-ms-win-core-console-l2-2-0.a \
		%/libapi-ms-win-core-console-l3-2-0.a \
		%/libapi-ms-win-core-datetime-l1-1-0.a \
		%/libapi-ms-win-core-datetime-l1-1-1.a \
		%/libapi-ms-win-core-datetime-l1-1-2.a \
		%/libapi-ms-win-core-debug-l1-1-0.a \
		%/libapi-ms-win-core-debug-l1-1-1.a \
		%/libapi-ms-win-core-debug-l1-1-2.a \
		%/libapi-ms-win-core-debug-minidump-l1-1-0.a \
		%/libapi-ms-win-core-delayload-l1-1-0.a \
		%/libapi-ms-win-core-delayload-l1-1-1.a \
		%/libapi-ms-win-core-enclave-l1-1-0.a \
		%/libapi-ms-win-core-enclave-l1-1-1.a \
		%/libapi-ms-win-core-errorhandling-l1-1-0.a \
		%/libapi-ms-win-core-errorhandling-l1-1-1.a \
		%/libapi-ms-win-core-errorhandling-l1-1-2.a \
		%/libapi-ms-win-core-errorhandling-l1-1-3.a \
		%/libapi-ms-win-core-featurestaging-l1-1-0.a \
		%/libapi-ms-win-core-featurestaging-l1-1-1.a \
		%/libapi-ms-win-core-fibers-l1-1-0.a \
		%/libapi-ms-win-core-fibers-l1-1-1.a \
		%/libapi-ms-win-core-fibers-l2-1-0.a \
		%/libapi-ms-win-core-fibers-l2-1-1.a \
		%/libapi-ms-win-core-file-ansi-l1-1-0.a \
		%/libapi-ms-win-core-file-ansi-l2-1-0.a \
		%/libapi-ms-win-core-file-fromapp-l1-1-0.a \
		%/libapi-ms-win-core-file-l1-1-0.a \
		%/libapi-ms-win-core-file-l1-2-0.a \
		%/libapi-ms-win-core-file-l1-2-1.a \
		%/libapi-ms-win-core-file-l1-2-2.a \
		%/libapi-ms-win-core-file-l1-2-3.a \
		%/libapi-ms-win-core-file-l2-1-0.a \
		%/libapi-ms-win-core-file-l2-1-1.a \
		%/libapi-ms-win-core-file-l2-1-2.a \
		%/libapi-ms-win-core-file-l2-1-3.a \
		%/libapi-ms-win-core-firmware-l1-1-0.a \
		%/libapi-ms-win-core-handle-l1-1-0.a \
		%/libapi-ms-win-core-heap-l1-1-0.a \
		%/libapi-ms-win-core-heap-l2-1-0.a \
		%/libapi-ms-win-core-heap-obsolete-l1-1-0.a \
		%/libapi-ms-win-core-interlocked-l1-1-0.a \
		%/libapi-ms-win-core-interlocked-l1-2-0.a \
		%/libapi-ms-win-core-io-l1-1-0.a \
		%/libapi-ms-win-core-io-l1-1-1.a \
		%/libapi-ms-win-core-job-l1-1-0.a \
		%/libapi-ms-win-core-job-l2-1-0.a \
		%/libapi-ms-win-core-job-l2-1-1.a \
		%/libapi-ms-win-core-kernel32-legacy-ansi-l1-1-0.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-0.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-1.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-2.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-3.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-4.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-5.a \
		%/libapi-ms-win-core-kernel32-legacy-l1-1-6.a \
		%/libapi-ms-win-core-largeinteger-l1-1-0.a \
		%/libapi-ms-win-core-libraryloader-l1-2-0.a \
		%/libapi-ms-win-core-libraryloader-l1-2-1.a \
		%/libapi-ms-win-core-libraryloader-l1-2-2.a \
		%/libapi-ms-win-core-libraryloader-l2-1-0.a \
		%/libapi-ms-win-core-localization-ansi-l1-1-0.a \
		%/libapi-ms-win-core-localization-l1-2-0.a \
		%/libapi-ms-win-core-localization-l1-2-1.a \
		%/libapi-ms-win-core-localization-l1-2-2.a \
		%/libapi-ms-win-core-localization-l1-2-3.a \
		%/libapi-ms-win-core-localization-l1-2-4.a \
		%/libapi-ms-win-core-localization-l2-1-0.a \
		%/libapi-ms-win-core-localization-obsolete-l1-2-0.a \
		%/libapi-ms-win-core-memory-l1-1-0.a \
		%/libapi-ms-win-core-memory-l1-1-1.a \
		%/libapi-ms-win-core-memory-l1-1-2.a \
		%/libapi-ms-win-core-memory-l1-1-3.a \
		%/libapi-ms-win-core-memory-l1-1-4.a \
		%/libapi-ms-win-core-memory-l1-1-5.a \
		%/libapi-ms-win-core-memory-l1-1-6.a \
		%/libapi-ms-win-core-memory-l1-1-7.a \
		%/libapi-ms-win-core-namedpipe-ansi-l1-1-0.a \
		%/libapi-ms-win-core-namedpipe-ansi-l1-1-1.a \
		%/libapi-ms-win-core-namedpipe-l1-1-0.a \
		%/libapi-ms-win-core-namedpipe-l1-2-1.a \
		%/libapi-ms-win-core-namedpipe-l1-2-2.a \
		%/libapi-ms-win-core-namespace-ansi-l1-1-0.a \
		%/libapi-ms-win-core-namespace-l1-1-0.a \
		%/libapi-ms-win-core-normalization-l1-1-0.a \
		%/libapi-ms-win-core-path-l1-1-0.a \
		%/libapi-ms-win-core-perfcounters-l1-1-0.a \
		%/libapi-ms-win-core-privateprofile-l1-1-0.a \
		%/libapi-ms-win-core-privateprofile-l1-1-1.a \
		%/libapi-ms-win-core-processenvironment-ansi-l1-1-0.a \
		%/libapi-ms-win-core-processenvironment-l1-1-0.a \
		%/libapi-ms-win-core-processenvironment-l1-2-0.a \
		%/libapi-ms-win-core-processsnapshot-l1-1-0.a \
		%/libapi-ms-win-core-processthreads-l1-1-0.a \
		%/libapi-ms-win-core-processthreads-l1-1-1.a \
		%/libapi-ms-win-core-processthreads-l1-1-2.a \
		%/libapi-ms-win-core-processthreads-l1-1-3.a \
		%/libapi-ms-win-core-processthreads-l1-1-4.a \
		%/libapi-ms-win-core-processtopology-l1-1-0.a \
		%/libapi-ms-win-core-processtopology-obsolete-l1-1-0.a \
		%/libapi-ms-win-core-processtopology-obsolete-l1-1-1.a \
		%/libapi-ms-win-core-profile-l1-1-0.a \
		%/libapi-ms-win-core-psapi-ansi-l1-1-0.a \
		%/libapi-ms-win-core-psapi-l1-1-0.a \
		%/libapi-ms-win-core-psm-appnotify-l1-1-0.a \
		%/libapi-ms-win-core-quirks-l1-1-0.a \
		%/libapi-ms-win-core-quirks-l1-1-1.a \
		%/libapi-ms-win-core-realtime-l1-1-0.a \
		%/libapi-ms-win-core-realtime-l1-1-1.a \
		%/libapi-ms-win-core-realtime-l1-1-2.a \
		%/libapi-ms-win-core-registry-l1-1-0.a \
		%/libapi-ms-win-core-registry-l1-1-1.a \
		%/libapi-ms-win-core-registry-l1-1-2.a \
		%/libapi-ms-win-core-registry-l2-1-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-1-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-2-0.a \
		%/libapi-ms-win-core-rtlsupport-l1-2-1.a \
		%/libapi-ms-win-core-shutdown-ansi-l1-1-0.a \
		%/libapi-ms-win-core-shutdown-l1-1-0.a \
		%/libapi-ms-win-core-shutdown-l1-1-1.a \
		%/libapi-ms-win-core-sidebyside-ansi-l1-1-0.a \
		%/libapi-ms-win-core-sidebyside-l1-1-0.a \
		%/libapi-ms-win-core-slapi-l1-1-0.a \
		%/libapi-ms-win-core-state-helpers-l1-1-0.a \
		%/libapi-ms-win-core-string-l1-1-0.a \
		%/libapi-ms-win-core-string-l2-1-0.a \
		%/libapi-ms-win-core-string-l2-1-1.a \
		%/libapi-ms-win-core-string-obsolete-l1-1-0.a \
		%/libapi-ms-win-core-string-obsolete-l1-1-1.a \
		%/libapi-ms-win-core-stringansi-l1-1-0.a \
		%/libapi-ms-win-core-synch-ansi-l1-1-0.a \
		%/libapi-ms-win-core-synch-l1-1-0.a \
		%/libapi-ms-win-core-synch-l1-2-0.a \
		%/libapi-ms-win-core-synch-l1-2-1.a \
		%/libapi-ms-win-core-sysinfo-l1-1-0.a \
		%/libapi-ms-win-core-sysinfo-l1-2-0.a \
		%/libapi-ms-win-core-sysinfo-l1-2-1.a \
		%/libapi-ms-win-core-sysinfo-l1-2-2.a \
		%/libapi-ms-win-core-sysinfo-l1-2-3.a \
		%/libapi-ms-win-core-sysinfo-l1-2-4.a \
		%/libapi-ms-win-core-sysinfo-l1-2-5.a \
		%/libapi-ms-win-core-sysinfo-l1-2-6.a \
		%/libapi-ms-win-core-systemtopology-l1-1-0.a \
		%/libapi-ms-win-core-systemtopology-l1-1-1.a \
		%/libapi-ms-win-core-threadpool-l1-2-0.a \
		%/libapi-ms-win-core-threadpool-legacy-l1-1-0.a \
		%/libapi-ms-win-core-timezone-l1-1-0.a \
		%/libapi-ms-win-core-timezone-l1-1-1.a \
		%/libapi-ms-win-core-toolhelp-l1-1-0.a \
		%/libapi-ms-win-core-toolhelp-l1-1-1.a \
		%/libapi-ms-win-core-url-l1-1-0.a \
		%/libapi-ms-win-core-util-l1-1-0.a \
		%/libapi-ms-win-core-util-l1-1-1.a \
		%/libapi-ms-win-core-version-l1-1-0.a \
		%/libapi-ms-win-core-version-l1-1-1.a \
		%/libapi-ms-win-core-versionansi-l1-1-0.a \
		%/libapi-ms-win-core-versionansi-l1-1-1.a \
		%/libapi-ms-win-core-windowsceip-l1-1-0.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-0.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-1.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-2.a \
		%/libapi-ms-win-core-windowserrorreporting-l1-1-3.a \
		%/libapi-ms-win-core-winrt-error-l1-1-0.a \
		%/libapi-ms-win-core-winrt-error-l1-1-1.a \
		%/libapi-ms-win-core-winrt-l1-1-0.a \
		%/libapi-ms-win-core-winrt-registration-l1-1-0.a \
		%/libapi-ms-win-core-winrt-robuffer-l1-1-0.a \
		%/libapi-ms-win-core-winrt-roparameterizediid-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-0.a \
		%/libapi-ms-win-core-winrt-string-l1-1-1.a \
		%/libapi-ms-win-core-wow64-l1-1-0.a \
		%/libapi-ms-win-core-wow64-l1-1-1.a \
		%/libapi-ms-win-core-wow64-l1-1-2.a \
		%/libapi-ms-win-core-wow64-l1-1-3.a \
		%/libapi-ms-win-core-xstate-l2-1-0.a \
		%/libapi-ms-win-core-xstate-l2-1-1.a \
		%/libapi-ms-win-devices-config-l1-1-1.a \
		%/libapi-ms-win-devices-config-l1-1-2.a \
		%/libapi-ms-win-devices-query-l1-1-0.a \
		%/libapi-ms-win-devices-query-l1-1-1.a \
		%/libapi-ms-win-devices-swdevice-l1-1-0.a \
		%/libapi-ms-win-devices-swdevice-l1-1-1.a \
		%/libapi-ms-win-eventing-classicprovider-l1-1-0.a \
		%/libapi-ms-win-eventing-consumer-l1-1-0.a \
		%/libapi-ms-win-eventing-consumer-l1-1-1.a \
		%/libapi-ms-win-eventing-controller-l1-1-0.a \
		%/libapi-ms-win-eventing-legacy-l1-1-0.a \
		%/libapi-ms-win-eventing-obsolete-l1-1-0.a \
		%/libapi-ms-win-eventing-provider-l1-1-0.a \
		%/libapi-ms-win-eventing-tdh-l1-1-0.a \
		%/libapi-ms-win-eventing-tdh-l1-1-1.a \
		%/libapi-ms-win-gaming-deviceinformation-l1-1-0.a \
		%/libapi-ms-win-mm-time-l1-1-0.a \
		%/libapi-ms-win-ntuser-sysparams-l1-1-0.a \
		%/libapi-ms-win-oobe-notification-l1-1-0.a \
		%/libapi-ms-win-perf-legacy-l1-1-0.a \
		%/libapi-ms-win-power-base-l1-1-0.a \
		%/libapi-ms-win-power-limitsmanagement-l1-1-0.a \
		%/libapi-ms-win-power-setting-l1-1-0.a \
		%/libapi-ms-win-power-setting-l1-1-1.a \
		%/libapi-ms-win-ro-typeresolution-l1-1-0.a \
		%/libapi-ms-win-ro-typeresolution-l1-1-1.a \
		%/libapi-ms-win-security-appcontainer-l1-1-0.a \
		%/libapi-ms-win-security-base-ansi-l1-1-0.a \
		%/libapi-ms-win-security-base-l1-1-0.a \
		%/libapi-ms-win-security-base-l1-2-0.a \
		%/libapi-ms-win-security-base-l1-2-1.a \
		%/libapi-ms-win-security-base-l1-2-2.a \
		%/libapi-ms-win-security-cpwl-l1-1-0.a \
		%/libapi-ms-win-security-credentials-l1-1-0.a \
		%/libapi-ms-win-security-cryptoapi-l1-1-0.a \
		%/libapi-ms-win-security-isolatedcontainer-l1-1-0.a \
		%/libapi-ms-win-security-isolatedcontainer-l1-1-1.a \
		%/libapi-ms-win-security-lsalookup-ansi-l2-1-0.a \
		%/libapi-ms-win-security-lsalookup-l2-1-0.a \
		%/libapi-ms-win-security-lsalookup-l2-1-1.a \
		%/libapi-ms-win-security-lsapolicy-l1-1-0.a \
		%/libapi-ms-win-security-provider-ansi-l1-1-0.a \
		%/libapi-ms-win-security-provider-l1-1-0.a \
		%/libapi-ms-win-security-sddl-ansi-l1-1-0.a \
		%/libapi-ms-win-security-sddl-l1-1-0.a \
		%/libapi-ms-win-security-systemfunctions-l1-1-0.a \
		%/libapi-ms-win-service-core-ansi-l1-1-0.a \
		%/libapi-ms-win-service-core-ansi-l1-1-1.a \
		%/libapi-ms-win-service-core-l1-1-0.a \
		%/libapi-ms-win-service-core-l1-1-1.a \
		%/libapi-ms-win-service-core-l1-1-2.a \
		%/libapi-ms-win-service-core-l1-1-3.a \
		%/libapi-ms-win-service-core-l1-1-4.a \
		%/libapi-ms-win-service-management-l1-1-0.a \
		%/libapi-ms-win-service-management-l2-1-0.a \
		%/libapi-ms-win-service-winsvc-l1-1-0.a \
		%/libapi-ms-win-shcore-obsolete-l1-1-0.a \
		%/libapi-ms-win-shcore-path-l1-1-0.a \
		%/libapi-ms-win-shcore-registry-l1-1-0.a \
		%/libapi-ms-win-shcore-registry-l1-1-1.a \
		%/libapi-ms-win-shcore-scaling-l1-1-0.a \
		%/libapi-ms-win-shcore-scaling-l1-1-1.a \
		%/libapi-ms-win-shcore-scaling-l1-1-2.a \
		%/libapi-ms-win-shcore-stream-l1-1-0.a \
		%/libapi-ms-win-shcore-stream-winrt-l1-1-0.a \
		%/libapi-ms-win-shcore-sysinfo-l1-1-0.a \
		%/libapi-ms-win-shcore-unicodeansi-l1-1-0.a \
		%/libapi-ms-win-shell-shdirectory-l1-1-0.a \
		%/libauthz.a \
		%/libbcrypt.a \
		%/libcabinet.a \
		%/libchakrart.a \
		%/libcrypt32.a \
		%/libcryptbase.a \
		%/libcryptnet.a \
		%/libdfscli.a \
		%/libdhcpcsvc.a \
		%/libdnsapi.a \
		%/libdsrole.a \
		%/libdwrite.a \
		%/libfltlib.a \
		%/libhid.a \
		%/libhrtfapo.a \
		%/libiphlpapi.a \
		%/liblogoncli.a \
		%/libmmdevapi.a \
		%/libmpr.a \
		%/libmsajapi.a \
		%/libmscms.a \
		%/libmswsock.a \
		%/libncrypt.a \
		%/libnetutils.a \
		%/libpowrprof.a \
		%/libprofapi.a \
		%/libpropsys.a \
		%/librometadata.a \
		%/librpcrt4.a \
		%/libsamcli.a \
		%/libschedcli.a \
		%/libsrvcli.a \
		%/libsspicli.a \
		%/libuserenv.a \
		%/libwebauthn.a \
		%/libwebservices.a \
		%/libwebsocket.a \
		%/libwindows.ai.machinelearning.a \
		%/libwindows.data.pdf.a \
		%/libwindows.networking.a \
		%/libwindowscodecs.a \
		%/libwinhttp.a \
		%/libwkscli.a \
		%/libwlanapi.a \
		%/libwldap32.a \
		%/libwpprecorderum.a \
		%/libxaudio2_9.a \
		%/libxmllite.a
	rm -f $@
	cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(RANLIB) $@

%/libvfw32.a: lib-common/vfw32.mri \
		%/libmsvfw32.a \
		%/libavifil32.a \
		%/libavicap32.a
	rm -f $@
	cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(RANLIB) $@

%/libucrt.a: lib-common/ucrt.mri %/libucrt_extra.a \
		%/libapi-ms-win-crt-conio-l1-1-0.a %/libapi-ms-win-crt-convert-l1-1-0.a %/libapi-ms-win-crt-environment-l1-1-0.a \
		%/libapi-ms-win-crt-filesystem-l1-1-0.a %/libapi-ms-win-crt-heap-l1-1-0.a %/libapi-ms-win-crt-locale-l1-1-0.a \
		%/libapi-ms-win-crt-math-l1-1-0.a %/libapi-ms-win-crt-multibyte-l1-1-0.a %/libapi-ms-win-crt-private-l1-1-0.a \
		%/libapi-ms-win-crt-process-l1-1-0.a %/libapi-ms-win-crt-runtime-l1-1-0.a %/libapi-ms-win-crt-stdio-l1-1-0.a \
		%/libapi-ms-win-crt-string-l1-1-0.a %/libapi-ms-win-crt-time-l1-1-0.a %/libapi-ms-win-crt-utility-l1-1-0.a \
		%/libvcruntime140_threads.a
	rm -f $@
	cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(RANLIB) $@

# The same as libucrt.a above, but without the -private lib and with some more
# statically linked functions.
%/libucrtapp.a: lib-common/ucrtapp.mri %/libucrt_extra.a %/libucrtapp_extra.a \
		%/libapi-ms-win-crt-conio-l1-1-0.a %/libapi-ms-win-crt-convert-l1-1-0.a %/libapi-ms-win-crt-environment-l1-1-0.a \
		%/libapi-ms-win-crt-filesystem-l1-1-0.a %/libapi-ms-win-crt-heap-l1-1-0.a %/libapi-ms-win-crt-locale-l1-1-0.a \
		%/libapi-ms-win-crt-math-l1-1-0.a %/libapi-ms-win-crt-multibyte-l1-1-0.a \
		%/libapi-ms-win-crt-process-l1-1-0.a %/libapi-ms-win-crt-runtime-l1-1-0.a %/libapi-ms-win-crt-stdio-l1-1-0.a \
		%/libapi-ms-win-crt-string-l1-1-0.a %/libapi-ms-win-crt-time-l1-1-0.a %/libapi-ms-win-crt-utility-l1-1-0.a \
		%/libvcruntime140_threads.a
	rm -f $@
	cd $(dir $@) && $(AR) -M < $(abspath $<)
	$(RANLIB) $@

lib64/%.def: lib64/%.def.in
	$(MKDIR_P) $(@D) && $(CPP) -x c $< -Wp,-w -undef -P -I$(top_srcdir)/def-include -DDEF_X64 > $@

libarm64/%.def: libarm64/%.def.in
	$(MKDIR_P) $(@D) && $(CPP) -x c $< -Wp,-w -undef -P -I$(top_srcdir)/def-include -DDEF_ARM64 > $@

lib64/%.def: lib-common/%.def.in
	$(MKDIR_P) $(@D) && $(CPP) -x c $< -Wp,-w -undef -P -I$(top_srcdir)/def-include -DDEF_X64 > $@

libarm64/%.def: lib-common/%.def.in
	$(MKDIR_P) $(@D) && $(CPP) -x c $< -Wp,-w -undef -P -I$(top_srcdir)/def-include -DDEF_ARM64 > $@

# Don't compile these, but install as is:
#
libsrcdir=$(includedir)
dist_libsrc_DATA = \
  libsrc/agtctl_i.c   libsrc/agtsvr_i.c     libsrc/cdoex_i.c    libsrc/cdoexm_i.c     \
  libsrc/cdosys_i.c   libsrc/emostore_i.c   libsrc/iisext_i.c   libsrc/mtsadmin_i.c   \
  libsrc/mtxadmin_i.c libsrc/scardssp_i.c   libsrc/scardssp_p.c libsrc/tsuserex_i.c


# Installation options
#

noinst_HEADERS = libsrc/dxerr.c \
 include/internal.h


# Cleaning options
#

CLEANFILES = $(BUILT_SOURCES) $(crt64_DATA) $(lib64_DATA) $(processed_defs)

# Distribution options
#

EXTRA_DIST = $(srcdir)/ChangeLog.*
EXTRA_DIST += revstamp.h \
  $(top_srcdir)/lib-common/*.def \
  $(top_srcdir)/lib64/*.def \
  $(top_srcdir)/lib64/*.mri \
  $(top_srcdir)/lib-common/*.def.in \
  $(top_srcdir)/lib64/*.def.in \
  $(top_srcdir)/def-include/*.def.in \
  crt/binmode.c \
  crt/crtbegin.c \
  crt/crtdll.c \
  crt/crtend.c \
  crt/crtexe.c \
  crt/CRT_fp8.c \
  crt/CRT_fp10.c \
  crt/CRT_glob.c \
  crt/CRT_noglob.c \
  crt/txtmode.c \
  crt/ucrtexe.c \
  profile/gcrt0.c \
  profile/COPYING \
  profile/CYGWIN_LICENSE

DISTCHECK_CONFIGURE_FLAGS = --host=$(host_triplet) $(withsys)

dist-hook:
	find $(top_distdir) -name ".svn" -delete

# Testsuite options
#

testcase_progs = \
  testcases/tstmainc \
  testcases/tstmaincpp \
  testcases/tstmain_sys_xxx \
  testcases/t_ansi_io \
  testcases/t_findfirst \
  testcases/t_float  \
  testcases/t_fstat \
  testcases/t_intrinc \
  testcases/t_imagebase \
  testcases/t_matherr \
  testcases/t_nullptrexception \
  testcases/t_readdir \
  testcases/t_snprintf \
  testcases/t_swprintf \
  testcases/t_snwprintf \
  testcases/t_stprintf_a \
  testcases/t_stprintf_u \
  testcases/t_setjmp \
  testcases/t_sigv \
  testcases/t_speed_powl \
  testcases/t_stat \
  testcases/t_stdint \
  testcases/t_time \
  testcases/t_tls1 \
  testcases/t_trycatch \
  testcases/t_stat_slash \
  testcases/t_wreaddir \
  testcases/t_fseeko64

testcases_tstmaincpp_SOURCES = testcases/tstmaincpp.cpp
testcases_t_trycatch_SOURCES = testcases/t_trycatch.cpp
testcases_t_intrinc_CFLAGS = -std=c17

if ENABLE_TESTS_UNICODE
  testcase_progs += testcases/t_municode testcases/t_tmain
  testcases_t_municode_CFLAGS = -municode
  testcases_t_tmain_CFLAGS = -municode -D_UNICODE
endif

# Do not specify TESTS = check_PROGRAMS, because some TESTS
# may not be check_PROGRAMS.
check_LIBRARIES =
check_PROGRAMS = $(testcase_progs)
TESTS = $(testcase_progs)
XFAIL_TESTS = \
  testcases/t_nullptrexception

# Include the complex math testcase fragment.
include testcases/complex/Makefile.am
