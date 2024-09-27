#define _get_output_format __dummy__get_output_format
#define _set_output_format __dummy__set_output_format
#include <windows.h>

#undef _get_output_format
#undef _set_output_format

static unsigned int last_value = 0;
typedef unsigned int (*f_get_output_format)(void);
typedef unsigned int (*f_set_output_format)(unsigned int);

static unsigned int fake_get_output_format(void)
{
    return last_value;
}

static unsigned int fake_set_output_format(unsigned int value)
{
    return InterlockedExchange((LONG*)&last_value, value);
}

unsigned int __attribute__ ((alias ("fake_set_output_format"))) _set_output_format(unsigned int);
f_set_output_format __MINGW_IMP_SYMBOL(_set_output_format) = _set_output_format;


unsigned int __attribute__ ((alias ("fake_get_output_format"))) _get_output_format(void);
f_get_output_format __MINGW_IMP_SYMBOL(_get_output_format) = _get_output_format;
