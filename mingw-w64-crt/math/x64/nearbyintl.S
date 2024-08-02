/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <_mingw_mac.h>

  .file "nearbyintl.S"
  .text
  .align 8
  .globl __MINGW_USYMBOL(nearbyintl)
  .def   __MINGW_USYMBOL(nearbyintl); .scl 2; .type 32; .endef
__MINGW_USYMBOL(nearbyintl):
  fldt   (%rdx)
  movq   %rcx,   %r8
  pushq  %rax
  pushq  %rcx
  fnstcw (%rsp)
  movl   (%rsp), %eax
  orl    $0x20,  %eax
  movl   %eax,   8(%rsp)
  fldcw  8(%rsp)
  frndint
  fclex
  fldcw (%rsp)
  popq  %rcx
  popq  %rax
  movq  %r8, %rax
  movq  $0,  8(%r8)
  fstpt (%r8)
  ret

  .data
  .align 8
  .globl __MINGW_IMP_LSYMBOL(nearbyintl)
__MINGW_IMP_LSYMBOL(nearbyintl):
  .quad  __MINGW_USYMBOL(nearbyintl)
