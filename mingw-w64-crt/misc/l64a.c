/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _DEFAULT_SOURCE
#include <stdlib.h>
#include <stdint.h>

char *__cdecl l64a(long _Value)
{
    static char       buf[7];
    static const char b64c[] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    uint32_t          v      = (uint32_t)_Value;
    size_t            blen   = sizeof(buf);

    char *p = buf;
    while(blen-- > 0)
    {
        if(v == 0)
        {
            *p = '\0';
            break;
        }
        *p++ = b64c[v & 0x3f];
        v >>= 6;
    }
    return buf;
}
