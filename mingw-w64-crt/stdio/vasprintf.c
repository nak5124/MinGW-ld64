#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int __cdecl vasprintf(char **__restrict _Strp, const char *__restrict _Format, va_list _ArgList)
{
    __builtin_va_list ap;
    __builtin_va_copy(ap, _ArgList);
    int len = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, _Format, NULL, ap);
    __builtin_va_end(ap);

    if(len < 0)
    {
        return -1;
    }

    *_Strp = (char *)malloc(len + 1U);
    if(*_Strp == NULL)
    {
        return -1;
    }

    int ret = __stdio_common_vsprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, *_Strp, len + 1U, _Format, NULL, _ArgList);
    if(ret < 0)
    {
        free(*_Strp);
        return -1;
    }

    return ret;
}

