/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define __NO_INTRIN_DECL
#include <_mingw.h>

  .file "scalbn.S"
  .text
  .align 8
  .globl __USYMBOL(scalbn)
  .globl __USYMBOL(scalbnl)
  .def   __USYMBOL(scalbn); .scl 2; .type 32; .endef
  .def   __USYMBOL(scalbnl); .scl 2; .type 32; .endef
__USYMBOL(scalbn):
__USYMBOL(scalbnl):
  subq  $24,    %rsp
  movq  %rdx,   (%rsp)
  fildl (%rsp)
  movsd %xmm0,  (%rsp)
  fldl  (%rsp)
  fscale
  fstp  %st(1)
  fstpl (%rsp)
  movsd (%rsp), %xmm0
  addq  $24,    %rsp
  ret

  .data
  .align 8
  .globl __IMP_LSYMBOL(scalbn)
__IMP_LSYMBOL(scalbn):
  .quad  __USYMBOL(scalbn)

  .globl __USYMBOL(scalbln)
  .set __USYMBOL(scalbln), __USYMBOL(scalbn)

  .data
  .align 8
  .globl __IMP_LSYMBOL(scalbln)
__IMP_LSYMBOL(scalbln):
  .quad  __USYMBOL(scalbln)

  .data
  .align 8
  .globl __IMP_LSYMBOL(scalbnl)
__IMP_LSYMBOL(scalbnl):
  .quad  __USYMBOL(scalbnl)

  .globl __USYMBOL(scalblnl)
  .set  __USYMBOL(scalblnl), __USYMBOL(scalbnl)

  .data
  .align 8
  .globl __IMP_LSYMBOL(scalblnl)
__IMP_LSYMBOL(scalblnl):
  .quad  __USYMBOL(scalblnl)
