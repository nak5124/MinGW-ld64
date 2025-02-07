/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <internal.h>
#include <stdlib.h>
#include <windows.h>
#define _DECL_DLLMAIN
#include <process.h>
#include <crtdbg.h>
#include <locale.h>
#include <stdio.h>
#ifdef __USING_MCFGTHREAD__
#include <mcfgthread/cxa.h>
#endif

extern HANDLE __dso_handle;

extern void __cdecl _initterm(_PVFV *,_PVFV *);
extern void __main ();
extern void _pei386_runtime_relocator (void);
extern _PIFV __xi_a[];
extern _PIFV __xi_z[];
extern _PVFV __xc_a[];
extern _PVFV __xc_z[];


/* TLS initialization hook.  */
extern const PIMAGE_TLS_CALLBACK __dyn_tls_init_callback;

static int __proc_attached = 0;

static _onexit_table_t atexit_table;

extern int __mingw_app_type;

extern WINBOOL WINAPI DllMain (HANDLE hDllHandle, DWORD dwReason, LPVOID lpreserved);

extern WINBOOL WINAPI DllEntryPoint (HANDLE, DWORD, LPVOID);

static int pre_c_init (void);

_CRTALLOC(".CRT$XIAA") _PIFV pcinit = pre_c_init;

static int
pre_c_init (void)
{
  return _initialize_onexit_table(&atexit_table);
}

WINBOOL WINAPI _CRT_INIT (HANDLE hDllHandle, DWORD dwReason, LPVOID lpreserved)
{
  if (dwReason == DLL_PROCESS_DETACH)
    {
      if (__proc_attached > 0)
	__proc_attached--;
      else
	return FALSE;
    }
  if (dwReason == DLL_PROCESS_ATTACH)
    {
      void *lock_free = NULL;
      void *fiberid = ((PNT_TIB)NtCurrentTeb ())->StackBase;
      BOOL nested = FALSE;
      int ret = 0;
      
      while ((lock_free = InterlockedCompareExchangePointer (&__native_startup_lock,
							     fiberid, NULL)) != 0)
	{
	  if (lock_free == fiberid)
	    {
	      nested = TRUE;
	      break;
	    }
	  Sleep(1000);
	}
      if (__native_startup_state != __uninitialized)
	{
	  _amsg_exit (31);
	}
      else
	{
	  __native_startup_state = __initializing;
	  
	  _pei386_runtime_relocator ();
	  ret = _initterm_e (__xi_a, __xi_z);
	  if (ret != 0)
	    goto i__leave;
	  _initterm (__xc_a, __xc_z);
	  __main ();

	  __native_startup_state = __initialized;
	}
i__leave:
      if (! nested)
	{
	  (void) InterlockedExchangePointer (&__native_startup_lock, NULL);
	}
      if (ret != 0)
	{
	  return FALSE;
	}
      if (__dyn_tls_init_callback != NULL)
	{
	  __dyn_tls_init_callback (hDllHandle, DLL_THREAD_ATTACH, lpreserved);
	}
      __proc_attached++;
    }
  else if (dwReason == DLL_PROCESS_DETACH)
    {
      void *lock_free = NULL;
      void *fiberid = ((PNT_TIB)NtCurrentTeb ())->StackBase;
      BOOL nested = FALSE;

      while ((lock_free = InterlockedCompareExchangePointer (&__native_startup_lock, fiberid, NULL)) != 0)
	{
	  if (lock_free == fiberid)
	    {
	      nested = TRUE;
	      break;
	    }
	  Sleep(1000);
	}
      if (__native_startup_state != __initialized)
	{
	  _amsg_exit (31);
	}
      else
	{
          _execute_onexit_table(&atexit_table);
	  __native_startup_state = __uninitialized;
	}
      if (! nested)
	{
	  (void) InterlockedExchangePointer (&__native_startup_lock, NULL);
	}
    }
  return TRUE;
}

static WINBOOL __DllMainCRTStartup (HANDLE, DWORD, LPVOID);

WINBOOL WINAPI DllMainCRTStartup (HANDLE, DWORD, LPVOID);

__ATTR_USED /* required due to GNU LD bug: https://sourceware.org/bugzilla/show_bug.cgi?id=30300 */
WINBOOL WINAPI
DllMainCRTStartup (HANDLE hDllHandle, DWORD dwReason, LPVOID lpreserved)
{
  __mingw_app_type = 0;
  return __DllMainCRTStartup (hDllHandle, dwReason, lpreserved);
}

static
__NOINLINE WINBOOL
__DllMainCRTStartup (HANDLE hDllHandle, DWORD dwReason, LPVOID lpreserved)
{
  WINBOOL retcode = TRUE;

  __native_dllmain_reason = dwReason;
  if (dwReason == DLL_PROCESS_DETACH && __proc_attached <= 0)
    {
	retcode = FALSE;
	goto i__leave;
    }

  if (dwReason == DLL_PROCESS_ATTACH || dwReason == DLL_THREAD_ATTACH)
    {
        retcode = _CRT_INIT (hDllHandle, dwReason, lpreserved);
        if (!retcode)
          goto i__leave;
        retcode = DllEntryPoint (hDllHandle, dwReason, lpreserved);
	if (! retcode)
	  {
	    if (dwReason == DLL_PROCESS_ATTACH)
	      _CRT_INIT (hDllHandle, DLL_PROCESS_DETACH, lpreserved);
	    goto i__leave;
	  }
    }
#ifdef __USING_MCFGTHREAD__
  if (dwReason == DLL_PROCESS_ATTACH)
    {
      /* Register `fflush(NULL)` before user-defined constructors, so
       * it will be executed after all user-defined destructors.  */
      __MCF_cxa_atexit ((__MCF_cxa_dtor_cdecl*)(intptr_t) fflush, NULL, &__dso_handle);
    }
#endif
  retcode = DllMain(hDllHandle,dwReason,lpreserved);
  if (dwReason == DLL_PROCESS_ATTACH && ! retcode)
    {
	DllMain (hDllHandle, DLL_PROCESS_DETACH, lpreserved);
	DllEntryPoint (hDllHandle, DLL_PROCESS_DETACH, lpreserved);
	_CRT_INIT (hDllHandle, DLL_PROCESS_DETACH, lpreserved);
    }
  if (dwReason == DLL_PROCESS_DETACH || dwReason == DLL_THREAD_DETACH)
    {
        retcode = DllEntryPoint (hDllHandle, dwReason, lpreserved);
	if (_CRT_INIT (hDllHandle, dwReason, lpreserved) == FALSE)
	  retcode = FALSE;
    }
#ifdef __USING_MCFGTHREAD__
  if (dwReason == DLL_PROCESS_DETACH && lpreserved == NULL)
    {
      /* Call `__cxa_finalize(dso_handle)` if the library is unloaded
       * dynamically. This conforms to the Itanium C++ ABI. Note it is
       * not called in case of process termination, where a call to
       * `__cxa_finalize(NULL)` shall have been made instead.  */
      __MCF_cxa_finalize (&__dso_handle);
    }
#endif
i__leave:
  __native_dllmain_reason = UINT_MAX;
  return retcode ;
}

int __cdecl atexit (_PVFV func)
{
#ifdef __USING_MCFGTHREAD__
    return __MCF_cxa_atexit ((__MCF_cxa_dtor_cdecl*)(intptr_t) func, NULL, &__dso_handle);
#else
    /* Do not use msvcrt's atexit() or UCRT's _crt_atexit() function as it
     * cannot be called from DLL library which may be unloaded at runtime. */
    return _register_onexit_function(&atexit_table, (_onexit_t)func);
#endif
}

char __mingw_module_is_dll = 1;
