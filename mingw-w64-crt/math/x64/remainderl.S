/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <_mingw_mac.h>

  .file "remainderl.S"
  .text
  .align 8
  .globl __MINGW_USYMBOL(remainderl)
  .def   __MINGW_USYMBOL(remainderl); .scl 2; .type 32; .endef
__MINGW_USYMBOL(remainderl):
  fldt (%r8)
  fldt (%rdx)

1: fprem1
  fstsw %ax
  sahf
  jp    1b
  fstp  %st(1)
  movq  %rcx, %rax
  movq  $0,   8(%rcx)
  fstpt (%rcx)
  ret

  .data
  .align 8
  .globl __MINGW_IMP_LSYMBOL(remainderl)
__MINGW_IMP_LSYMBOL(remainderl):
  .quad  __MINGW_USYMBOL(remainderl)
