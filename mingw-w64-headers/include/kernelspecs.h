/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef KERNELSPECS_H
#define KERNELSPECS_H

#include <driverspecs.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DISPATCH_LEVEL 2
#define APC_LEVEL      1
#define PASSIVE_LEVEL  0

#ifdef _AMD64_
# define HIGH_LEVEL 15
#endif
#ifdef _ARM64_
# define HIGH_LEVEL 15
#endif

#undef  __drv_setsIRQL
#define __drv_setsIRQL(irql)
#undef  _IRQL_raises_
#define _IRQL_raises_(irql)
#undef  __drv_raisesIRQL
#define __drv_raisesIRQL(irql)
#undef  _IRQL_requires_
#define _IRQL_requires_(irql)
#undef  __drv_requiresIRQL
#define __drv_requiresIRQL(irql)
#undef  _IRQL_requires_max_
#define _IRQL_requires_max_(irql)
#undef  __drv_maxIRQL
#define __drv_maxIRQL(irql)
#undef  _IRQL_requires_min_
#define _IRQL_requires_min_(irql)
#undef  __drv_minIRQL
#define __drv_minIRQL(irql)
#undef  _IRQL_saves_
#define _IRQL_saves_
#undef  __drv_savesIRQL
#define __drv_savesIRQL
#undef  _IRQL_saves_global_
#define _IRQL_saves_global_(kind, param)
#undef  __drv_savesIRQLGlobal
#define __drv_savesIRQLGlobal(kind, param)
#undef  _IRQL_restores_
#define _IRQL_restores_
#undef  __drv_restoresIRQL
#define __drv_restoresIRQL
#undef  _IRQL_restores_global_
#define _IRQL_restores_global_(kind, param)
#undef  __drv_restoresIRQLGlobal
#define __drv_restoresIRQLGlobal(kind, param)
#undef  _IRQL_always_function_min_
#define _IRQL_always_function_min_(irql)
#undef  __drv_minFunctionIRQL
#define __drv_minFunctionIRQL(irql)
#undef  _IRQL_always_function_max_
#define _IRQL_always_function_max_(irql)
#undef  __drv_maxFunctionIRQL
#define __drv_maxFunctionIRQL(irql)
#undef  _IRQL_requires_same_
#define _IRQL_requires_same_
#undef  __drv_sameIRQL
#define __drv_sameIRQL
#undef  _IRQL_uses_cancel_
#define _IRQL_uses_cancel_
#undef  __drv_useCancelIRQL
#define __drv_useCancelIRQL
#undef  _IRQL_inout_
#define _IRQL_inout_

#ifdef __cplusplus
}
#endif

#endif  /* KERNELSPECS_H */
