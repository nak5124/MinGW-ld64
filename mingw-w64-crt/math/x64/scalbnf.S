/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define __NO_INTRIN_DECL
#include <_mingw.h>

  .file "scalbnf.S"
  .text
  .align 8
  .globl __USYMBOL(scalbnf)
  .def   __USYMBOL(scalbnf); .scl 2; .type 32; .endef
__USYMBOL(scalbnf):
  subq  $24,    %rsp
  movq  %rdx,   (%rsp)
  fildl (%rsp)
  movss %xmm0,  (%rsp)
  flds  (%rsp)
  fscale
  fstp  %st(1)
  fstps (%rsp)
  movss (%rsp), %xmm0
  addq  $24,    %rsp
  ret

  .data
  .align 8
  .globl __IMP_LSYMBOL(scalbnf)
__IMP_LSYMBOL(scalbnf):
  .quad  __USYMBOL(scalbnf)

  .globl __USYMBOL(scalblnf)
  .set  __USYMBOL(scalblnf), __USYMBOL(scalbnf)

  .data
  .align 8
  .globl __IMP_LSYMBOL(scalblnf)
__IMP_LSYMBOL(scalblnf):
  .quad  __USYMBOL(scalblnf)
