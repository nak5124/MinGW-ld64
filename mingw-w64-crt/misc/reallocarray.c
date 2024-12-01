/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _DEFAULT_SOURCE
#include <stdlib.h>
#include <errno.h>

void *__cdecl reallocarray(void *_Ptr, size_t _Nmemb, size_t _Size)
{
    size_t newsize;
    if(__builtin_mul_overflow(_Nmemb, _Size, &newsize))
    {
        errno = ENOMEM;
        return NULL;
    }
    return realloc(_Ptr, newsize);
}
