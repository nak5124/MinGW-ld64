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

uint32_t __cdecl arc4random(void)
{
    uint32_t random_value;
    NTSTATUS status = BCryptGenRandom(NULL, (PUCHAR)&random_value, (ULONG)sizeof(random_value), BCRYPT_USE_SYSTEM_PREFERRED_RNG);
    if(!BCRYPT_SUCCESS(status))
    {
        fprintf(stderr, "Fatal error: cannot get entropy for arc4random\n");
    }
    return random_value;
}
