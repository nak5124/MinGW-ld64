/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <_mingw_mac.h>

  .file "scalbnf.S"
  .text
  .align 8
  .globl __MINGW_USYMBOL(scalbnf)
  .def   __MINGW_USYMBOL(scalbnf); .scl 2; .type 32; .endef
__MINGW_USYMBOL(scalbnf):
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
  .globl __MINGW_IMP_LSYMBOL(scalbnf)
__MINGW_IMP_LSYMBOL(scalbnf):
  .quad  __MINGW_USYMBOL(scalbnf)

  .globl __MINGW_USYMBOL(scalblnf)
  .set  __MINGW_USYMBOL(scalblnf), __MINGW_USYMBOL(scalbnf)

  .data
  .align 8
  .globl __MINGW_IMP_LSYMBOL(scalblnf)
__MINGW_IMP_LSYMBOL(scalblnf):
  .quad  __MINGW_USYMBOL(scalblnf)
