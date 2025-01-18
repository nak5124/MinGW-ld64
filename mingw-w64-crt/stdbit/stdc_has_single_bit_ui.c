/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <stdbit.h>

bool (stdc_has_single_bit_ui)(unsigned int value)
{
  return stdc_has_single_bit_ui(value);
}

bool (stdc_has_single_bit_ul)(unsigned long int value) __ALIAS(stdc_has_single_bit_ui);
