/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _ISOC23_SOURCE
#include <math.h>

int __cdecl canonicalize(double *_CX, const double *_X)
{
  double x = *_X;

  if(!iscanonical(x))
  {
    return 1;
  }
  if(issignaling(x))
  {
    *_CX = x + x;
  }
  else
  {
    *_CX = x;
  }

  return 0;
}

int __cdecl canonicalizel(long double *_CX, const long double *_X)
{
  long double x = *_X;

  if(!iscanonical(x))
  {
    return 1;
  }
  if(issignaling(x))
  {
    *_CX = x + x;
  }
  else
  {
    *_CX = x;
  }

  return 0;
}
