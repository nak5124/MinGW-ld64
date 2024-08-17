/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef SPECSTRINGS_H
#define SPECSTRINGS_H

#define _SAL_VERSION_SAL2(_A)
#define _SAL_VERSION_CHECK(_A)
#define SAL_VERSION_SAL2(_A)
#define _SAL_L_Source_(Name, args, annotes)

#include <sal.h>

#define __SAL_H_FULL_VER 140050727

#ifdef __cplusplus
extern "C" {
#endif

#define __inner_bound
#define __inner_range(lb, ub)
#define __inner_assume_bound_dec
#define __inner_assume_bound(i)
#define __inner_allocator
#define __static_context(ctx, annotes)
#define __failure(x)
#define __valueUndefined
#define __failureDefault(x)
#define __xcount(size)
#define __in_xcount(size)
#define __out_xcount(size)
#define __out_xcount_part(size, length)
#define __out_xcount_full(size)
#define __inout_xcount(size)
#define __inout_xcount_part(size, length)
#define __inout_xcount_full(size)
#define __xcount_opt(size)
#define __in_xcount_opt(size)
#define __out_xcount_opt(size)
#define __out_xcount_part_opt(size, length)
#define __out_xcount_full_opt(size)
#define __inout_xcount_opt(size)
#define __inout_xcount_part_opt(size, length)
#define __inout_xcount_full_opt(size)
#define __deref_xcount(size)
#define __deref_in
#define __deref_in_ecount(size)
#define __deref_in_bcount(size)
#define __deref_in_xcount(size)
#define __deref_out_xcount(size)
#define __deref_out_xcount_part(size, length)
#define __deref_out_xcount_full(size)
#define __deref_out_xcount(size)
#define __inout_xcount_opt(size)
#define __deref_xcount(size)
#define __deref_in
#define __deref_in_ecount(size)
#define __deref_in_bcount(size)
#define __deref_in_xcount(size)
#define __deref_out_xcount(size)
#define __deref_out_xcount_part(size, length)
#define __deref_out_xcount_full(size)
#define __deref_out_xcount(size)
#define __deref_inout_xcount(size)
#define __deref_inout_xcount_part(size, length)
#define __deref_inout_xcount_full(size)
#define __deref_xcount_opt(size)
#define __deref_in_opt
#define __deref_in_opt_out
#define __deref_in_ecount_opt(size)
#define __deref_in_bcount_opt(size)
#define __deref_in_xcount_opt(size)
#define __deref_out_xcount_opt(size)
#define __deref_out_xcount_part_opt(size, length)
#define __deref_out_xcount_full_opt(size)
#define __deref_inout_xcount_opt(size)
#define __deref_inout_xcount_part_opt(size, length)
#define __deref_inout_xcount_full_opt(size)
#define __deref_opt_xcount(size)
#define __deref_opt_in
#define __deref_opt_in_ecount(size)
#define __deref_opt_in_bcount(size)
#define __deref_opt_in_xcount(size)
#define __deref_opt_out_xcount(size)
#define __deref_opt_out_xcount_part(size, length)
#define __deref_opt_out_xcount_full(size)
#define __deref_opt_inout_xcount(size)
#define __deref_opt_inout_xcount_part(size, length)
#define __deref_opt_inout_xcount_full(size)
#define __deref_opt_xcount_opt(size)
#define __deref_opt_in_opt
#define __deref_opt_in_ecount_opt(size)
#define __deref_opt_in_bcount_opt(size)
#define __deref_opt_in_xcount_opt(size)
#define __deref_opt_out_xcount_opt(size)
#define __deref_opt_out_xcount_part_opt(size, length)
#define __deref_opt_out_xcount_full_opt(size)
#define __deref_opt_inout_xcount_opt(size)
#define __deref_opt_inout_xcount_part_opt(size, length)
#define __deref_opt_inout_xcount_full_opt(size)
#define __deref_in_ecount_iterator(size, incr)
#define __deref_out_ecount_iterator(size, incr)
#define __deref_inout_ecount_iterator(size, incr)
#define __post_bcount(size)
#define __post_ecount(size)
#define __deref_realloc_bcount(insize, outsize)
#define __in_ecount_or_z(c)
#define __post_nullnullterminated

#ifndef RC_INVOKED
# undef  __nullnullterminated
# define __nullnullterminated
# undef  __post_nullnullterminated
# define __post_nullnullterminated
#endif  /* RC_INVOKED */

#define __file_parser(typ)
#define __file_parser_class(typ)
#define __file_parser_library(typ)
#define __source_code_content(typ)
#define __class_code_content(typ)
#define __analysis_assert(e)
#define __analysis_hint(hint)
#define __analysis_noreturn
#define __inner_data_source(src_raw)
#define __inner_this_data_source(src_raw)
#define __inner_out_validated(typ_raw)
#define __inner_this_out_validated(typ_raw)
#define __inner_assume_validated_dec
#define __inner_assume_validated(p)
#define __inner_transfer(formal)
#define __inner_encoded
#define __inner_adt_prop(adt, prop)
#define __inner_adt_add_prop(adt, prop)
#define __inner_adt_remove_prop(adt, prop)
#define __inner_adt_transfer_prop(arg)
#define __inner_adt_type_props(typ)
#define __inner_volatile
#define __inner_nonvolatile
#define __inner_possibly_notnullterminated
#define _Memory_origin_(context)
#define _Memory_origin_when_(previousContext, context)
#define _Accessible_bytes_(context, expr)
#define _Accessible_bytes_when_(previousContext, context, expr)
#define _Pre_accessible_bytes_(context, expr)
#define _Pre_accessible_bytes_when_(context, previousContext, expr)
#define _User_
#define _User_on_(expr)
#define _User_always_
#define _User_always_and_needs_probe_on_(mode)
#define _Kernel_entry_
#define _Kernel_entry_always_
#define __field_ecount(size)
#define __field_bcount(size)
#define __field_xcount(size)
#define __field_ecount_opt(size)
#define __field_bcount_opt(size)
#define __field_xcount_opt(size)
#define __field_ecount_part(size, init)
#define __field_bcount_part(size, init)
#define __field_xcount_part(size, init)
#define __field_ecount_part_opt(size, init)
#define __field_bcount_part_opt(size, init)
#define __field_xcount_part_opt(size, init)
#define __field_ecount_full(size)
#define __field_bcount_full(size)
#define __field_xcount_full(size)
#define __field_ecount_full_opt(size)
#define __field_bcount_full_opt(size)
#define __field_xcount_full_opt(size)
#define __field_nullterminated
#define __struct_bcount(size)
#define __struct_xcount(size)
#define __out_awcount(expr, size)
#define __in_awcount(expr, size)
#define __post_invalid
#define __allocator
#define __deallocate(kind)
#define __deallocate_opt(kind)
#define __bound
#define __range(lb, ub)
#define __in_bound
#define __out_bound
#define __deref_out_bound
#define __in_range(lb, ub)
#define __out_range(lb, ub)
#define __deref_in_range(lb, ub)
#define __deref_out_range(lb, ub)
#define __deref_inout_range(lb, ub)
#define __field_range(lb, ub)
#define __field_data_source(src_sym)
#define __range_max(a, b)
#define __range_min(a, b)
#define __in_data_source(src_sym)
#define __out_data_source(src_sym)
#define __out_validated(typ_sym)
#define __this_out_data_source(src_sym)
#define __this_out_validated(typ_sym)
#define __transfer(formal)
#define __rpc_entry
#define __kernel_entry
#define __gdi_entry
#define __encoded_pointer
#define __encoded_array
#define __field_encoded_pointer
#define __field_encoded_array
#define __type_has_adt_prop(adt, prop)
#define __out_has_adt_prop(adt, prop)
#define __out_not_has_adt_prop(adt, prop)
#define __out_transfer_adt_prop(arg)
#define __out_has_type_adt_props(typ)
#define __possibly_notnullterminated
#define __volatile
#define __nonvolatile
#define __deref_volatile
#define __deref_nonvolatile
#define __analysis_assume_nullterminated(x)
#define __assume_validated(p)
#define __assume_bound(i)
#define _Unreferenced_parameter_
#define _Frees_ptr_
#define _Frees_ptr_opt_
#define _Reallocation_function_(after, before, size)
#define _Ret_reallocated_bytes_(before, size)
#define _In_NLS_string_(size)
#define _Flt_ConnectionCookie_Outptr_
#define _Writes_and_advances_ptr_(size)
#define _Writes_bytes_and_advances_ptr_(size)
#define _Post_equals_last_error_
#define _Translates_Win32_to_HRESULT_(errorCode)
#define _Translates_NTSTATUS_to_HRESULT_(status)
#define _Translates_last_error_to_HRESULT_

#ifdef __cplusplus
}
#endif

#ifndef RC_INVOKED
# include <specstrings_strict.h>
#endif

#include <driverspecs.h>

#endif  /* SPECSTRINGS_H */
