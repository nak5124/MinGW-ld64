/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <malloc.h>

size_t __cdecl malloc_usable_size(void *_Ptr)
{
    if(!_Ptr)
    {
        return 0;
    }

    return _msize(_Ptr);
}
