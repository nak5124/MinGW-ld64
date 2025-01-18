/* For UCRT, positive infinity */
#include <_mingw.h>
#undef _HUGE
static double _HUGE = __builtin_huge_val();
double * __IMP_SYMBOL(_HUGE) = &_HUGE;
#undef HUGE
extern double * __IMP_SYMBOL(HUGE) __ALIAS_IMP_SYM(_HUGE);
