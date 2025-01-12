/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <stdbit.h>

unsigned int (stdc_trailing_zeros_ui)(unsigned int value)
{
  return stdc_trailing_zeros_ui(value);
}

unsigned int (stdc_trailing_zeros_ul)(unsigned long int value) __attribute__((alias("stdc_trailing_zeros_ui")));
