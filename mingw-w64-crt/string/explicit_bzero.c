/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _DEFAULT_SOURCE
#define __CRT__NO_INLINE
#include <string.h>
#define WIN32_LEAN_AND_MEAN
#define NOSERVICE
#define NOMCX
#define NOIME
#include <windows.h>

void __cdecl explicit_bzero(void *_Ptr, size_t _N)
{
    SecureZeroMemory(_Ptr, _N);
}
