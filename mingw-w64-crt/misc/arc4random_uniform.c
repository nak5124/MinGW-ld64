/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _DEFAULT_SOURCE
#include <stdlib.h>
#include <stdio.h>
#define WIN32_LEAN_AND_MEAN
#define NOSERVICE
#define NOMCX
#define NOIME
#include <windows.h>
#include <bcrypt.h>

uint32_t __cdecl arc4random_uniform(uint32_t _Upper_bound)
{
    if(_Upper_bound <= 1)
    {
        return 0;
    }
    if(((_Upper_bound - 1) & _Upper_bound) == 0)
    {
        return arc4random() & (_Upper_bound - 1);
    }

    uint32_t min = (uint32_t)(-_Upper_bound % _Upper_bound);
    uint32_t r;

    do
    {
        r = arc4random();
    } while(r < min);

    return r % _Upper_bound;
}
