/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _DEFAULT_SOURCE
#include <unistd.h>
#define WIN32_LEAN_AND_MEAN
#define NOSERVICE
#define NOMCX
#define NOIME
#include <windows.h>
#include <bcrypt.h>
#include <errno.h>

int __cdecl getentropy(void *_Buffer, size_t _Length)
{
    if(_Buffer == NULL || _Length > 256)
    {
        errno = EIO;
        return -1;
    }

    NTSTATUS status = BCryptGenRandom(NULL, (PUCHAR)_Buffer, (ULONG)_Length, BCRYPT_USE_SYSTEM_PREFERRED_RNG);
    if(!BCRYPT_SUCCESS(status))
    {
        errno = EIO;
        return -1;
    }

    return 0;
}
