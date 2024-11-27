/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define _GNU_SOURCE
#define _MS_SOURCE
#include <stdlib.h>

struct qsortr_ctx
{
    _Compare_fn_t  compare;
    void          *context;
};

static int compare_fnc(void *context, const void *a, const void *b)
{
    struct qsortr_ctx *ctx = (struct qsortr_ctx *)context;
    return ctx->compare(a, b, ctx->context);
}

void __cdecl qsort_r(void *_Base, size_t _Nmemb, size_t _Size, _Compare_fn_t _Compar, void *_Arg)
{
    if(_Nmemb <= 1)
    {
        return;
    }
    struct qsortr_ctx ctx = { _Compar, _Arg };
    qsort_s(_Base, _Nmemb, _Size, compare_fnc, &ctx);
}
