/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _DEFAULT_SOURCE
#include <stdlib.h>

int clearenv(void)
{
    char **env = environ;
    while(*env)
    {
        *env = NULL;
        env++;
    }

    return 0;
}
