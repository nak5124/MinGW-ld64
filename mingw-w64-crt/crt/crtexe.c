/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#undef CRTDLL
#ifndef _DLL
#define _DLL
#endif

#define SPECIAL_CRTEXE

#include <oscalls.h>
#include <internal.h>
#include <process.h>
#include <signal.h>
#include <math.h>
#include <stdlib.h>
#include <tchar.h>
#include <sect_attribs.h>
#include <locale.h>
#include <corecrt_startup.h>
#include <stdio.h>
#ifdef __USING_MCFGTHREAD__
#include <mcfgthread/cxa.h>
#endif

#if defined(__SEH__) && (!defined(__clang__) || __clang_major__ >= 7)
#define SEH_INLINE_ASM
#endif

extern IMAGE_DOS_HEADER __ImageBase;

extern void _fpreset (void);

int *__cdecl __p__commode(void);

#undef _fmode
extern int _fmode;
#undef _commode
extern int _commode;
extern int _dowildcard;
extern HANDLE __dso_handle;

extern _CRTIMP void __cdecl _initterm(_PVFV *, _PVFV *);

static int __cdecl check_managed_app (void);

extern _PIFV __xi_a[];
extern _PIFV __xi_z[];
extern _PVFV __xc_a[];
extern _PVFV __xc_z[];


/* TLS initialization hook.  */
extern const PIMAGE_TLS_CALLBACK __dyn_tls_init_callback;

extern int __mingw_app_type;

static int argc;
extern void __main(void);
static _TCHAR **argv;
static _TCHAR **envp;

static int argret;
static int mainret=0;
static int managedapp;
static int has_cctor = 0;
static _startupinfo startinfo;
extern LPTOP_LEVEL_EXCEPTION_FILTER __mingw_oldexcpt_handler;

extern void _pei386_runtime_relocator (void);
long CALLBACK _gnu_exception_handler (EXCEPTION_POINTERS * exception_data);

#ifdef _UNICODE
static void duplicate_ppstrings (int ac, _TCHAR ***av);
#endif

static int __cdecl pre_c_init (void);
static void __cdecl pre_cpp_init (void);
_CRTALLOC(".CRT$XIAA") _PIFV __mingw_pcinit = pre_c_init;
_CRTALLOC(".CRT$XCAA") _PVFV __mingw_pcppinit = pre_cpp_init;

extern int _MINGW_INSTALL_DEBUG_MATHERR;

#ifdef __MINGW_SHOW_INVALID_PARAMETER_EXCEPTION
#define __UNUSED_PARAM_1(x) x
#else
#define __UNUSED_PARAM_1	__UNUSED_PARAM
#endif
static void
__mingw_invalidParameterHandler (const wchar_t * __UNUSED_PARAM_1(expression),
				 const wchar_t * __UNUSED_PARAM_1(function),
				 const wchar_t * __UNUSED_PARAM_1(file),
				 unsigned int    __UNUSED_PARAM_1(line),
				 uintptr_t __UNUSED_PARAM(pReserved))
{
#ifdef __MINGW_SHOW_INVALID_PARAMETER_EXCEPTION
  wprintf(L"Invalid parameter detected in function %s. File: %s Line: %d\n", function, file, line);
  wprintf(L"Expression: %s\n", expression);
#endif
}

static int __cdecl
pre_c_init (void)
{
  managedapp = check_managed_app ();
  if (__mingw_app_type)
    __set_app_type(_GUI_APP);
  else
    __set_app_type (_CONSOLE_APP);

  * __p__fmode() = _fmode;
  * __p__commode() = _commode;

#ifdef _UNICODE
  _wsetargv();
#else
  _setargv();
#endif
  if (_MINGW_INSTALL_DEBUG_MATHERR == 1)
    {
      __setusermatherr (_matherr);
    }

  if (__globallocalestatus == -1)
    {
    }
  return 0;
}

static void __cdecl
pre_cpp_init (void)
{
  startinfo.newmode = _newmode;

#ifdef _UNICODE
  argret = __wgetmainargs(&argc,&argv,&envp,_dowildcard,&startinfo);
#else
  // Get argv as wide chars and convert it to active code page
  // without best-fit mapping to avoid security issues.
  // Environment will be taken directly as narrow chars later.
  wchar_t **wargv;
  wchar_t **wenvp_dummy;
  argret = __wgetmainargs(&argc,&wargv,&wenvp_dummy,_dowildcard,&startinfo);

  size_t buf_size = 0;

  for (int i = 0; i < argc; ++i) {
    BOOL conv_was_lossy = TRUE;
    int size = WideCharToMultiByte(CP_ACP, WC_NO_BEST_FIT_CHARS,
        wargv[i], -1,
        NULL, 0,
        NULL, &conv_was_lossy);

    if (size <= 0 || conv_was_lossy) {
      fprintf(stderr,
          "Error: Command line contains characters that are not supported\n"
          "in the active code page (%u).\n", GetACP());
      _exit(255);
    }

    buf_size += size;
  }

  argv = malloc((argc + 1) * sizeof(char *));
  char *buf = malloc(buf_size);
  if (argv == NULL || buf == NULL)
    _amsg_exit(8); // R6008 "not enough space for arguments" with MSVCRT

  for (int i = 0; i < argc; ++i) {
    int size = WideCharToMultiByte(CP_ACP, WC_NO_BEST_FIT_CHARS,
        wargv[i], -1,
        buf, buf_size,
        NULL, NULL);
    argv[i] = buf;
    buf += size;
    buf_size -= size;
  }

  argv[argc] = NULL;

  // Initialize narrow environment.
  //
  // IMPORANT: Don't expand wildcards as that alone can be a security issue
  // with __getmainargs! Best-fit mapping can result in arguments that point
  // to network shares and wildcard expansion of such arguments could then
  // result in unexpected network access.
  int argc_dummy;
  char **argv_dummy;
  (void)__getmainargs(&argc_dummy,&argv_dummy,&envp,0,&startinfo);
#endif
}

static int __tmainCRTStartup (void);

int WinMainCRTStartup (void);

__attribute__((used)) /* required due to GNU LD bug: https://sourceware.org/bugzilla/show_bug.cgi?id=30300 */
int WinMainCRTStartup (void)
{
  int ret = 255;
#ifdef SEH_INLINE_ASM
  asm ("\t.l_startw:\n");
#endif
  __mingw_app_type = 1;
  ret = __tmainCRTStartup ();
#ifdef SEH_INLINE_ASM
  asm ("\tnop\n"
    "\t.l_endw: nop\n"
    "\t.seh_handler __C_specific_handler, @except\n"
    "\t.seh_handlerdata\n"
    "\t.long 1\n"
    "\t.rva .l_startw, .l_endw, _gnu_exception_handler ,.l_endw\n"
    "\t.text");
#endif
  return ret;
}

int mainCRTStartup (void);

#if defined(__x86_64__) && !defined(__SEH__)
int __mingw_init_ehandler (void);
#endif

__attribute__((used)) /* required due to GNU LD bug: https://sourceware.org/bugzilla/show_bug.cgi?id=30300 */
int mainCRTStartup (void)
{
  int ret = 255;
#ifdef SEH_INLINE_ASM
  asm ("\t.l_start:\n");
#endif
  __mingw_app_type = 0;
  ret = __tmainCRTStartup ();
#ifdef SEH_INLINE_ASM
  asm ("\tnop\n"
    "\t.l_end: nop\n"
    "\t.seh_handler __C_specific_handler, @except\n"
    "\t.seh_handlerdata\n"
    "\t.long 1\n"
    "\t.rva .l_start, .l_end, _gnu_exception_handler ,.l_end\n"
    "\t.text");
#endif
  return ret;
}

static
__declspec(noinline) int
__tmainCRTStartup (void)
{
    void *lock_free = NULL;
    void *fiberid = ((PNT_TIB)NtCurrentTeb())->StackBase;
    int nested = FALSE;
    while((lock_free = InterlockedCompareExchangePointer ((volatile PVOID *) &__native_startup_lock,
							  fiberid, 0)) != 0)
      {
	if (lock_free == fiberid)
	  {
	    nested = TRUE;
	    break;
	  }
	Sleep(1000);
      }
    if (__native_startup_state == __initializing)
      {
	_amsg_exit (31);
      }
    else if (__native_startup_state == __uninitialized)
      {
	__native_startup_state = __initializing;
	_initterm ((_PVFV *)(void *)__xi_a, (_PVFV *)(void *) __xi_z);
      }
    else
      has_cctor = 1;

    if (__native_startup_state == __initializing)
      {
	_initterm (__xc_a, __xc_z);
	__native_startup_state = __initialized;
      }
    _ASSERTE(__native_startup_state == __initialized);
    if (! nested)
      (VOID)InterlockedExchangePointer ((volatile PVOID *) &__native_startup_lock, 0);
    
    if (__dyn_tls_init_callback != NULL)
      __dyn_tls_init_callback (NULL, DLL_THREAD_ATTACH, NULL);
    
    _pei386_runtime_relocator ();
    __mingw_oldexcpt_handler = SetUnhandledExceptionFilter (_gnu_exception_handler);
#if defined(__x86_64__) && !defined(__SEH__)
    __mingw_init_ehandler ();
#endif
    _set_invalid_parameter_handler (__mingw_invalidParameterHandler);
    
    _fpreset ();

#ifdef _UNICODE
    // Narrow argv is already a local copy so only duplicate the wide version.
    duplicate_ppstrings (argc, &argv);
#endif
#ifdef __USING_MCFGTHREAD__
    /* Register `fflush(NULL)` before user-defined constructors, so
     * it will be executed after all user-defined destructors.  */
    __MCF_cxa_atexit ((__MCF_cxa_dtor_cdecl*)(intptr_t) fflush, NULL, &__dso_handle);
#endif
    __main (); /* C++ initialization. */
#ifdef _UNICODE
    __winitenv = envp;
#else
    __initenv = envp;
#endif
    mainret = _tmain (argc, argv, envp);
    if (!managedapp)
      exit (mainret);

    if (has_cctor == 0)
      _cexit ();

  return mainret;
}

extern int __mingw_initltsdrot_force;
extern int __mingw_initltsdyn_force;
extern int __mingw_initltssuo_force;

static int __cdecl
check_managed_app (void)
{
  PIMAGE_DOS_HEADER pDOSHeader;
  PIMAGE_NT_HEADERS pPEHeader;
  PIMAGE_OPTIONAL_HEADER32 pNTHeader32;
  PIMAGE_OPTIONAL_HEADER64 pNTHeader64;

  /* Force to be linked.  */
  __mingw_initltsdrot_force=1;
  __mingw_initltsdyn_force=1;
  __mingw_initltssuo_force=1;

  pDOSHeader = (PIMAGE_DOS_HEADER) &__ImageBase;
  if (pDOSHeader->e_magic != IMAGE_DOS_SIGNATURE)
    return 0;

  pPEHeader = (PIMAGE_NT_HEADERS)((char *)pDOSHeader + pDOSHeader->e_lfanew);
  if (pPEHeader->Signature != IMAGE_NT_SIGNATURE)
    return 0;

  pNTHeader32 = (PIMAGE_OPTIONAL_HEADER32) &pPEHeader->OptionalHeader;
  switch (pNTHeader32->Magic)
    {
    case IMAGE_NT_OPTIONAL_HDR32_MAGIC:
      if (pNTHeader32->NumberOfRvaAndSizes <= IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR)
	return 0;
      return !! pNTHeader32->DataDirectory[IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR].VirtualAddress;
    case IMAGE_NT_OPTIONAL_HDR64_MAGIC:
      pNTHeader64 = (PIMAGE_OPTIONAL_HEADER64)pNTHeader32;
      if (pNTHeader64->NumberOfRvaAndSizes <= IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR)
	return 0;
      return !! pNTHeader64->DataDirectory[IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR].VirtualAddress;
    }
  return 0;
}

#ifdef _UNICODE
static void duplicate_ppstrings (int ac, _TCHAR ***av)
{
	_TCHAR **avl;
	int i;
	_TCHAR **n = (_TCHAR **) malloc (sizeof (_TCHAR *) * (ac + 1));
	
	avl=*av;
	for (i=0; i < ac; i++)
	  {
		size_t l = sizeof (_TCHAR) * (_tcslen (avl[i]) + 1);
		n[i] = (_TCHAR *) malloc (l);
		memcpy (n[i], avl[i], l);
	  }
	n[i] = NULL;
	*av = n;
}
#endif

int __cdecl atexit (_PVFV func)
{
#ifdef __USING_MCFGTHREAD__
    return __MCF_cxa_atexit ((__MCF_cxa_dtor_cdecl*)(intptr_t) func, NULL, &__dso_handle);
#else
    /*
     * msvcrt def file renames the real atexit() function to _crt_atexit().
     * UCRT provides atexit() function only under name _crt_atexit().
     * So redirect call to _crt_atexit() function.
     */
    return _crt_atexit(func);
#endif
}

char __mingw_module_is_dll = 0;
