/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <_mingw_mac.h>

	.file "mcountFunc.S"
	.text
	.align 8

/* gcc always assumes the mcount public symbol has a single leading underscore
   for our target.  See gcc/config/i386.h; it isn't overridden in
   config/i386/cygming.h or any other places for mingw */
.globl _mcount
        .def    _mcount;  .scl    2;      .type   32;     .endef
_mcount:
	push %rbp
	mov %rsp, %rbp
	push %rax
	push %rcx
	push %rdx
	push %r8
	push %r9
	push %r10
	push %r11
	movq 8(%rbp),%rdx
	movq (%rbp),%rax
	movq 8(%rax),%rcx
	sub $40, %rsp
	call __MINGW_USYMBOL(_mcount_private)
	add $40, %rsp
	pop %r11
	pop %r10
	pop %r9
	pop %r8
	pop %rdx
	pop %rcx
	pop %rax
	leave
	ret

/* gcc always assumes the mcount public symbol has a single leading underscore
   for our target.  See gcc/config/i386.h; it isn't overridden in
   config/i386/cygming.h or any other places for mingw.  This is the entry
   for new prologue mechanism required for x64 seh calling convention.  */
.globl __fentry__
        .def    _mcount_top;  .scl    2;      .type   32;     .endef
__fentry__:
	push %rbp
	mov %rsp, %rbp
	push %rax
	push %rcx
	push %rdx
	push %r8
	push %r9
	push %r10
	push %r11
	movq 8(%rbp),%rdx
	movq 16(%rbp),%rcx
	sub $40, %rsp
	call __MINGW_USYMBOL(_mcount_private)
	add $40, %rsp
	pop %r11
	pop %r10
	pop %r9
	pop %r8
	pop %rdx
	pop %rcx
	pop %rax
	leave
	ret
