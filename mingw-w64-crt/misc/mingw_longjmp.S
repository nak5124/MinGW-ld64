/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <_mingw_mac.h>

#if defined(__aarch64__) || defined(_ARM64_)
	.globl __MINGW_USYMBOL(__mingw_setjmp)
	.def	__MINGW_USYMBOL(__mingw_setjmp);	.scl	2;	.type	32;	.endef
__MINGW_USYMBOL(__mingw_setjmp):
	str     xzr, [x0]             /* jmp_buf->Frame */
	stp     x19, x20, [x0, #0x10] /* jmp_buf->X19, X20 */
	stp     x21, x22, [x0, #0x20] /* jmp_buf->X21, X22 */
	stp     x23, x24, [x0, #0x30] /* jmp_buf->X23, X24 */
	stp     x25, x26, [x0, #0x40] /* jmp_buf->X25, X26 */
	stp     x27, x28, [x0, #0x50] /* jmp_buf->X27, X28 */
	stp     x29, x30, [x0, #0x60] /* jmp_buf->Fp,  Lr  */
	mov     x2,  sp
	str     x2,       [x0, #0x70] /* jmp_buf->Sp */
	mrs     x2,  fpcr
	str     w2,       [x0, #0x78] /* jmp_buf->Fpcr */
	mrs     x2,  fpsr
	str     w2,       [x0, #0x7c] /* jmp_buf->Fpsr */
	stp     d8,  d9,  [x0, #0x80] /* jmp_buf->D[0-1] */
	stp     d10, d11, [x0, #0x90] /* jmp_buf->D[2-3] */
	stp     d12, d13, [x0, #0xa0] /* jmp_buf->D[4-5] */
	stp     d14, d15, [x0, #0xb0] /* jmp_buf->D[6-7] */
	mov     x0,  #0
	ret

	.globl __MINGW_USYMBOL(__mingw_longjmp)
	.def	__MINGW_USYMBOL(__mingw_longjmp);	.scl	2;	.type	32;	.endef
__MINGW_USYMBOL(__mingw_longjmp):
	ldp     x19, x20, [x0, #0x10] /* jmp_buf->X19, X20 */
	ldp     x21, x22, [x0, #0x20] /* jmp_buf->X21, X22 */
	ldp     x23, x24, [x0, #0x30] /* jmp_buf->X23, X24 */
	ldp     x25, x26, [x0, #0x40] /* jmp_buf->X25, X26 */
	ldp     x27, x28, [x0, #0x50] /* jmp_buf->X27, X28 */
	ldp     x29, x30, [x0, #0x60] /* jmp_buf->Fp,  Lr  */
	ldr     x2,       [x0, #0x70] /* jmp_buf->Sp */
	mov     sp,  x2
	ldr     w2,       [x0, #0x78] /* jmp_buf->Fpcr */
	msr     fpcr, x2
	ldr     w2,       [x0, #0x7c] /* jmp_buf->Fpsr */
	msr     fpsr, x2
	ldp     d8,  d9,  [x0, #0x80] /* jmp_buf->D[0-1] */
	ldp     d10, d11, [x0, #0x90] /* jmp_buf->D[2-3] */
	ldp     d12, d13, [x0, #0xa0] /* jmp_buf->D[4-5] */
	ldp     d14, d15, [x0, #0xb0] /* jmp_buf->D[6-7] */
	mov     x0,  x1               /* retval */
	ret
#endif
