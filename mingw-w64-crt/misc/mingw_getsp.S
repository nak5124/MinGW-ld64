/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <_mingw_mac.h>

	.file	"mingw_getsp.S"
	.text
	.align 8
	.globl __MINGW_USYMBOL(mingw_getsp)
	.def	__MINGW_USYMBOL(mingw_getsp);	.scl	2;	.type	32;	.endef
__MINGW_USYMBOL(mingw_getsp):
#if defined(__x86_64__) || defined(_AMD64_)
	leaq  8(%rsp),%rax
	ret
#elif defined(__aarch64__) || defined(_ARM64_)
	mov	x0, sp
	ret
#endif
