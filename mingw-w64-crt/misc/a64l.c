/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _DEFAULT_SOURCE
#include <stdlib.h>

long __cdecl a64l(const char *_Str64)
{
    long result = 0;
    int  shift  = 0;
    while(*_Str64 && shift < 32)
    {
        char c = *_Str64++;
        int value;

        if(c >= '.' && c <= '/')
        {
            value = c - '.';
        }
        else if(c >= '0' && c <= '9')
        {
            value = c - '0' + 2;
        }
        else if(c >= 'A' && c <= 'Z')
        {
            value = c - 'A' + 12;
        }
        else if(c >= 'a' && c <= 'z')
        {
            value = c - 'a' + 38;
        }
        else
        {
            break;
        }

        result |= (value << shift);
        shift  += 6;
    }
    return result;
}
