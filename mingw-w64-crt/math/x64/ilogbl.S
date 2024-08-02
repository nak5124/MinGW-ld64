/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <_mingw_mac.h>

  .file "ilogbl.S"
  .text
  .align 8
  .globl __MINGW_USYMBOL(ilogbl)
  .def   __MINGW_USYMBOL(ilogbl); .scl 2; .type 32; .endef
__MINGW_USYMBOL(ilogbl):
  fldt  (%rcx)
  fxam  /* Is NaN or +-Inf?  */
  fstsw %ax
  movb  $0x45, %dh
  andb  %ah,   %dh
  cmpb  $0x05, %dh
  je    1f  /* Is +-Inf, jump.  */
  cmpb  $0x01, %dh
  je    1f  /* Is NaN, jump.  */

  fxtract
  pushq %rax
  fstp  %st

  fistpl (%rsp)
  fwait
  popq   %rax

  ret

1: fstp %st
  movl $0x7fffffff, %eax
  ret

  .data
  .align 8
  .globl __MINGW_IMP_LSYMBOL(ilogbl)
__MINGW_IMP_LSYMBOL(ilogbl):
  .quad  __MINGW_USYMBOL(ilogbl)
