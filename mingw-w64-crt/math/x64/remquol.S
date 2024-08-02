/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <_mingw_mac.h>

  .file "remquol.S"
  .text
  .align 8
  .globl __MINGW_USYMBOL(remquol)
__MINGW_USYMBOL(remquol):
  pushq %rcx
  fldt  (%r8)
  fldt  (%rdx)

1: fprem1
  fstsw %ax
  sahf
  jp    1b
  fstp  %st(1)
  movl  %eax,            %ecx
  shrl  $8,              %eax
  shrl  $12,             %ecx
  andl  $4,              %ecx
  andl  $3,              %eax
  orl   %eax,            %ecx
  movl  $0xef2a60,       %eax
  leal  (%ecx, %ecx, 2), %ecx
  shrl  %cl,             %eax
  andl  $7,              %eax
  movl  8(%rdx),         %edx
  xorl  8(%r8),          %edx
  testl $0x8000,         %edx
  jz    1f
  negl  %eax

1: movl %eax, (%r9)
  popq  %rcx
  movq  %rcx, %rax
  movq  $0,   8(%rcx)
  fstpt (%rcx)
  ret

  .data
  .align 8
  .globl __MINGW_IMP_LSYMBOL(remquol)
__MINGW_IMP_LSYMBOL(remquol):
  .quad  __MINGW_USYMBOL(remquol)
