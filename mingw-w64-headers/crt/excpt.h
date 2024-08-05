/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_EXCPT
#define _INC_EXCPT

#include <corecrt.h>

__MINGW_BEGIN_C_DECLS

  struct _EXCEPTION_POINTERS;

#ifndef EXCEPTION_DISPOSITION
# define EXCEPTION_DISPOSITION int
#endif
#define ExceptionContinueExecution 0
#define ExceptionContinueSearch    1
#define ExceptionNestedException   2
#define ExceptionCollidedUnwind    3
#define ExceptionExecuteHandler    4

  struct _EXCEPTION_RECORD;
  struct _CONTEXT;
  struct _DISPATCHER_CONTEXT;

  __MINGW_EXTENSION _CRTIMP EXCEPTION_DISPOSITION __cdecl __C_specific_handler(struct _EXCEPTION_RECORD *_ExceptionRecord, void *_EstablisherFrame, struct _CONTEXT *_ContextRecord, struct _DISPATCHER_CONTEXT *_DispatcherContext);

#define GetExceptionCode          _exception_code
#define exception_code            _exception_code
#define GetExceptionInformation() ((struct _EXCEPTION_POINTERS *)_exception_info())
#define exception_info()          ((struct _EXCEPTION_POINTERS *)_exception_info())
#define AbnormalTermination       _abnormal_termination
#define abnormal_termination      _abnormal_termination

  unsigned long __cdecl _exception_code(void);
  void *__cdecl _exception_info(void);
  int __cdecl _abnormal_termination(void);

#define EXCEPTION_EXECUTE_HANDLER     1
#define EXCEPTION_CONTINUE_SEARCH     0
#define EXCEPTION_CONTINUE_EXECUTION -1

  /*
  * The type of function that is expected as an exception handler to be
  * installed with __try1.
  */
  typedef EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(struct _EXCEPTION_RECORD *, void *, struct _CONTEXT *, void *);

#ifdef __x86_64__
#define __try1(pHandler) \
  __asm__ __volatile__ ("\t.l_startw:\n" \
  "\t.seh_handler __C_specific_handler, @except\n" \
  "\t.seh_handlerdata\n" \
  "\t.long 1\n" \
  "\t.rva .l_startw, .l_endw, " __MINGW64_STRINGIFY(__MINGW_USYMBOL(pHandler)) " ,.l_endw\n" \
  "\t.text" \
  );
#define __except1 \
  asm ("\tnop\n" \
  "\t.l_endw: nop\n");
#else
#define __try1(pHandler)
#define __except1
#endif

__MINGW_END_C_DECLS

#endif  /* _INC_EXCPT */
