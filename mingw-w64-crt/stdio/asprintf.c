#define _GNU_SOURCE
#include <stdio.h>

int __cdecl asprintf(char **__restrict _Strp, const char *__restrict _Format, ...)
{
    __builtin_va_list ap;
    int ret;
    __builtin_va_start(ap, _Format);
    ret = vasprintf(_Strp, _Format, ap);
    __builtin_va_end(ap);
    return ret;
}
