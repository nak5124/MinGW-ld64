/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <windows.h>

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

unsigned int _set_output_format(unsigned int) __ALIAS(fake_set_output_format);
f_set_output_format __IMP_SYMBOL(_set_output_format) = _set_output_format;


unsigned int _get_output_format(void) __ALIAS(fake_get_output_format);
f_get_output_format __IMP_SYMBOL(_get_output_format) = _get_output_format;
