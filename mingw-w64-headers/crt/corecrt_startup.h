/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CORECRT_STARTUP
#define _INC_CORECRT_STARTUP

#include <corecrt.h>
#include <math.h>

#pragma pack(push, _CRT_PACKING)

__MINGW_BEGIN_C_DECLS

  struct _EXCEPTION_POINTERS;

  _CRTIMP int __cdecl _seh_filter_dll(unsigned long _ExceptionNum, struct _EXCEPTION_POINTERS *_ExceptionPtr);
  _CRTIMP int __cdecl _seh_filter_exe(unsigned long _ExceptionNum, struct _EXCEPTION_POINTERS *_ExceptionPtr);

  typedef enum _crt_app_type
  {
    _crt_unknown_app,
    _crt_console_app,
    _crt_gui_app
  } _crt_app_type;

  _CRTIMP _crt_app_type __cdecl _query_app_type(void);
  _CRTIMP void __cdecl _set_app_type(_crt_app_type _Type);

#ifndef _EXCEPTION_DEFINED  /* Also in math.h */
# define _EXCEPTION_DEFINED
  struct _exception
  {
    int type;
    const char *name;
    double arg1;
    double arg2;
    double retval;
  };

  void __mingw_raise_matherr(int typ, const char *name, double a1, double a2, double rslt);
  void __mingw_setusermatherr(int (__cdecl *)(struct _exception *));
  _CRTIMP void __setusermatherr(int (__cdecl *)(struct _exception *));
  #define __setusermatherr __mingw_setusermatherr
#endif  /* _EXCEPTION_DEFINED */

  typedef enum _crt_argv_mode
  {
    _crt_argv_no_arguments,
    _crt_argv_unexpanded_arguments,
    _crt_argv_expanded_arguments,
  } _crt_argv_mode;

  _CRTIMP errno_t __cdecl _configure_narrow_argv(_crt_argv_mode mode);
  _CRTIMP errno_t __cdecl _configure_wide_argv(_crt_argv_mode mode);

  _CRTIMP int __cdecl _initialize_narrow_environment(void);
  _CRTIMP int __cdecl _initialize_wide_environment(void);

  _CRTIMP char *__cdecl _get_narrow_winmain_command_line(void);
  _CRTIMP wchar_t *__cdecl _get_wide_winmain_command_line(void);

  _CRTIMP char **__cdecl __p__acmdln(void);
  _CRTIMP wchar_t **__cdecl __p__wcmdln(void);

#define _acmdln (*__p__acmdln())
#define _wcmdln (*__p__wcmdln())

  typedef void (__cdecl *_PVFV)(void);
  typedef int  (__cdecl *_PIFV)(void);
  typedef void (__cdecl *_PVFI)(int);

  _CRTIMP void __cdecl _initterm(_PVFV *_First, _PVFV *_Last);
  _CRTIMP int  __cdecl _initterm_e(_PIFV *_First, _PIFV *_Last);

#ifndef _CRT_ONEXIT_T_DEFINED
# define _CRT_ONEXIT_T_DEFINED
# ifndef _ONEXIT_T_DEFINED
#   define _ONEXIT_T_DEFINED
    typedef int (__cdecl *_onexit_t)(void);
#   define onexit_t _onexit_t
# endif
  typedef struct _onexit_table_t
  {
      _PVFV* _first;
      _PVFV* _last;
      _PVFV* _end;
  } _onexit_table_t;
#endif

  _CRTIMP int __cdecl _initialize_onexit_table(_onexit_table_t *_Table);
  _CRTIMP int __cdecl _register_onexit_function(_onexit_table_t *_Table, _onexit_t _Function);
  _CRTIMP int __cdecl _execute_onexit_table(_onexit_table_t *_Table);
  _CRTIMP int __cdecl _crt_atexit(_PVFV func);
  _CRTIMP int __cdecl _crt_at_quick_exit(_PVFV func);

__MINGW_END_C_DECLS

#pragma pack(pop)

#endif  /* _INC_CORECRT_STARTUP */
