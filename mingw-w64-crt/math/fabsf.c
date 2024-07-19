/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
float fabsf (float x);

float
fabsf (float x)
{
  return __builtin_fabsf (x);
}
