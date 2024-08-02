/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
/*
 * Written by J.T. Conklin <jtc@netbsd.org>.
 * Changes for long double by Ulrich Drepper <drepper@cygnus.com>
 * Public domain.
 */
#include <_mingw_mac.h>

  .file "copysignl.S"
  .text
  .align 8

  .globl __MINGW_USYMBOL(copysignl)
  .def   __MINGW_USYMBOL(copysignl); .scl 2; .type 32; .endef
__MINGW_USYMBOL(copysignl):
  movq (%rdx),  %rax
  movq %rax,    (%rcx)
  movq 8(%rdx), %rax
  movq 8(%r8),  %rdx
  andq $0x7fff, %rax
  andq $0x8000, %rdx
  orq  %rdx,    %rax
  movq %rax,    8(%rcx)
  movq %rcx,    %rax
  ret

  .data
  .align 8
  .globl __MINGW_IMP_LSYMBOL(copysignl)
__MINGW_IMP_LSYMBOL(copysignl):
  .quad  __MINGW_USYMBOL(copysignl)

  .globl __MINGW_USYMBOL(_copysignl)
  .set __MINGW_USYMBOL(_copysignl), __MINGW_USYMBOL(copysignl)

  .data
  .align 8
  .globl __MINGW_IMP_LSYMBOL(_copysignl)
__MINGW_IMP_LSYMBOL(_copysignl):
  .quad  __MINGW_USYMBOL(_copysignl)
