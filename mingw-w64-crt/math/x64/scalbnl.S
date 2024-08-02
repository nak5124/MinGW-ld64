/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <_mingw_mac.h>

  .file "scalbnl.S"
  .text
  .align 8
  .globl __MINGW_USYMBOL(scalbnl)
  .def   __MINGW_USYMBOL(scalbnl); .scl 2; .type 32; .endef
__MINGW_USYMBOL(scalbnl):
  subq  $24,  %rsp
  andl  $-1,  %r8d
  movq  %r8,  (%rsp)
  fildl (%rsp)
  fldt  (%rdx)
  fscale
  fstp  %st(1)
  movq  %rcx, %rax
  movq  $0,   8(%rcx)
  fstpt (%rcx)
  addq  $24,  %rsp
  ret

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
