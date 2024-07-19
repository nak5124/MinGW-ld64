#define __INTRINSIC_ONLYSPECIAL
#define __INTRINSIC_SPECIAL__InterlockedXor64 /* Causes code generation in intrin-impl.h */

#include <intrin.h>

__int64 InterlockedXor64(__int64 volatile *, __int64) __attribute__((alias("_InterlockedXor64")));
