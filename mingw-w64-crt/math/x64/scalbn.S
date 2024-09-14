/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <_mingw_mac.h>

  .file "scalbn.S"
  .text
  .align 8
  .globl __MINGW_USYMBOL(scalbn)
  .globl __MINGW_USYMBOL(scalbnl)
  .def   __MINGW_USYMBOL(scalbn); .scl 2; .type 32; .endef
  .def   __MINGW_USYMBOL(scalbnl); .scl 2; .type 32; .endef
__MINGW_USYMBOL(scalbn):
__MINGW_USYMBOL(scalbnl):
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
  .globl __MINGW_IMP_LSYMBOL(scalbn)
__MINGW_IMP_LSYMBOL(scalbn):
  .quad  __MINGW_USYMBOL(scalbn)

  .globl __MINGW_USYMBOL(scalbln)
  .set __MINGW_USYMBOL(scalbln), __MINGW_USYMBOL(scalbn)

  .data
  .align 8
  .globl __MINGW_IMP_LSYMBOL(scalbln)
__MINGW_IMP_LSYMBOL(scalbln):
  .quad  __MINGW_USYMBOL(scalbln)

  .data
  .align 8
  .globl __MINGW_IMP_LSYMBOL(scalbnl)
__MINGW_IMP_LSYMBOL(scalbnl):
  .quad  __MINGW_USYMBOL(scalbnl)

  .globl __MINGW_USYMBOL(scalblnl)
  .set  __MINGW_USYMBOL(scalblnl), __MINGW_USYMBOL(scalbnl)

  .data
  .align 8
  .globl __MINGW_IMP_LSYMBOL(scalblnl)
__MINGW_IMP_LSYMBOL(scalblnl):
  .quad  __MINGW_USYMBOL(scalblnl)
