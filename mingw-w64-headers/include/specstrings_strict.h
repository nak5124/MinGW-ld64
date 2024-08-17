/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef SPECSTRINGS_STRICT_H
#define SPECSTRINGS_STRICT_H

#define __SPECSTRINGS_STRICT_LEVEL 1

#ifndef __WIDL__
# include <specstrings_undef.h>
# define __ecount(size)
# define __bcount(size)
# define __xcount(size)
# define __in
# define __in_ecount(size)
# define __in_bcount(size)
# define __in_xcount(size)
# define __in_z
# define __in_ecount_z(size)
# define __in_bcount_z(size)
# define __out
# define __out_ecount(size)
# define __out_bcount(size)
# define __out_xcount(size)
# define __out_ecount_part(size,len)
# define __out_bcount_part(size,len)
# define __out_xcount_part(size,len)
# define __out_ecount_full(size)
# define __out_bcount_full(size)
# define __out_xcount_full(size)
# define __out_z
# define __out_ecount_z(size)
# define __out_bcount_z(size)
# define __inout
# define __inout_ecount(size)
# define __inout_bcount(size)
# define __inout_xcount(size)
# define __inout_ecount_part(size,len)
# define __inout_bcount_part(size,len)
# define __inout_xcount_part(size,len)
# define __inout_ecount_full(size)
# define __inout_bcount_full(size)
# define __inout_xcount_full(size)
# define __inout_z
# define __inout_ecount_z(size)
# define __inout_bcount_z(size)
# define __ecount_opt(size)
# define __bcount_opt(size)
# define __xcount_opt(size)
# define __in_opt
# define __in_ecount_opt(size)
# define __in_bcount_opt(size)
# define __in_z_opt
# define __in_ecount_z_opt(size)
# define __in_bcount_z_opt(size)
# define __in_xcount_opt(size)
# define __out_opt
# define __out_ecount_opt(size)
# define __out_bcount_opt(size)
# define __out_xcount_opt(size)
# define __out_ecount_part_opt(size, len)
# define __out_bcount_part_opt(size, len)
# define __out_xcount_part_opt(size, len)
# define __out_ecount_full_opt(size)
# define __out_bcount_full_opt(size)
# define __out_xcount_full_opt(size)
# define __out_ecount_z_opt(size)
# define __out_bcount_z_opt(size)
# define __inout_opt
# define __inout_ecount_opt(size)
# define __inout_bcount_opt(size)
# define __inout_xcount_opt(size)
# define __inout_ecount_part_opt(size, len)
# define __inout_bcount_part_opt(size, len)
# define __inout_xcount_part_opt(size, len)
# define __inout_ecount_full_opt(size)
# define __inout_bcount_full_opt(size)
# define __inout_xcount_full_opt(size)
# define __inout_z_opt
# define __inout_ecount_z_opt(size)
# define __inout_ecount_z_opt(size)
# define __inout_bcount_z_opt(size)
# define __deref_ecount(size)
# define __deref_bcount(size)
# define __deref_xcount(size)
# define __deref_in
# define __deref_in_ecount(size)
# define __deref_in_bcount(size)
# define __deref_in_xcount(size)
# define __deref_out
# define __deref_out_ecount(size)
# define __deref_out_bcount(size)
# define __deref_out_xcount(size)
# define __deref_out_ecount_part(size, len)
# define __deref_out_bcount_part(size, len)
# define __deref_out_xcount_part(size, len)
# define __deref_out_ecount_full(size)
# define __deref_out_bcount_full(size)
# define __deref_out_xcount_full(size)
# define __deref_out_z
# define __deref_out_ecount_z(size)
# define __deref_out_bcount_z(size)
# define __deref_inout
# define __deref_inout_ecount(size)
# define __deref_inout_bcount(size)
# define __deref_inout_xcount(size)
# define __deref_inout_ecount_part(size, len)
# define __deref_inout_bcount_part(size, len)
# define __deref_inout_xcount_part(size, len)
# define __deref_inout_ecount_full(size)
# define __deref_inout_bcount_full(size)
# define __deref_inout_xcount_full(size)
# define __deref_inout_z
# define __deref_inout_ecount_z(size)
# define __deref_inout_bcount_z(size)
# define __deref_ecount_opt(size)
# define __deref_bcount_opt(size)
# define __deref_xcount_opt(size)
# define __deref_in_opt
# define __deref_in_opt_out
# define __deref_in_ecount_opt(size)
# define __deref_in_bcount_opt(size)
# define __deref_in_xcount_opt(size)
# define __deref_out_opt
# define __deref_out_ecount_opt(size)
# define __deref_out_bcount_opt(size)
# define __deref_out_xcount_opt(size)
# define __deref_out_ecount_part_opt(size, len)
# define __deref_out_bcount_part_opt(size, len)
# define __deref_out_xcount_part_opt(size, len)
# define __deref_out_ecount_full_opt(size)
# define __deref_out_bcount_full_opt(size)
# define __deref_out_xcount_full_opt(size)
# define __deref_out_z_opt
# define __deref_out_ecount_z_opt(size)
# define __deref_out_bcount_z_opt(size)
# define __deref_inout_opt
# define __deref_inout_ecount_opt(size)
# define __deref_inout_bcount_opt(size)
# define __deref_inout_xcount_opt(size)
# define __deref_inout_ecount_part_opt(size, len)
# define __deref_inout_bcount_part_opt(size, len)
# define __deref_inout_xcount_part_opt(size, len)
# define __deref_inout_ecount_full_opt(size)
# define __deref_inout_bcount_full_opt(size)
# define __deref_inout_xcount_full_opt(size)
# define __deref_inout_z_opt
# define __deref_inout_ecount_z_opt(size)
# define __deref_inout_bcount_z_opt(size)
# define __deref_opt_ecount(size)
# define __deref_opt_bcount(size)
# define __deref_opt_xcount(size)
# define __deref_opt_in
# define __deref_opt_in_ecount(size)
# define __deref_opt_in_bcount(size)
# define __deref_opt_in_xcount(size)
# define __deref_opt_out
# define __deref_opt_out_ecount(size)
# define __deref_opt_out_bcount(size)
# define __deref_opt_out_xcount(size)
# define __deref_opt_out_ecount_part(size, len)
# define __deref_opt_out_bcount_part(size, len)
# define __deref_opt_out_xcount_part(size, len)
# define __deref_opt_out_ecount_full(size)
# define __deref_opt_out_bcount_full(size)
# define __deref_opt_out_xcount_full(size)
# define __deref_opt_inout
# define __deref_opt_inout_ecount(size)
# define __deref_opt_inout_bcount(size)
# define __deref_opt_inout_xcount(size)
# define __deref_opt_inout_ecount_part(size, len)
# define __deref_opt_inout_bcount_part(size, len)
# define __deref_opt_inout_xcount_part(size, len)
# define __deref_opt_inout_ecount_full(size)
# define __deref_opt_inout_bcount_full(size)
# define __deref_opt_inout_xcount_full(size)
# define __deref_opt_inout_z
# define __deref_opt_inout_ecount_z(size)
# define __deref_opt_inout_bcount_z(size)
# define __deref_opt_ecount_opt(size)
# define __deref_opt_bcount_opt(size)
# define __deref_opt_xcount_opt(size)
# define __deref_opt_in_opt
# define __deref_opt_in_ecount_opt(size)
# define __deref_opt_in_bcount_opt(size)
# define __deref_opt_in_xcount_opt(size)
# define __deref_opt_out_opt
# define __deref_opt_out_ecount_opt(size)
# define __deref_opt_out_bcount_opt(size)
# define __deref_opt_out_xcount_opt(size)
# define __deref_opt_out_ecount_part_opt(size, len)
# define __deref_opt_out_bcount_part_opt(size, len)
# define __deref_opt_out_xcount_part_opt(size, len)
# define __deref_opt_out_ecount_full_opt(size)
# define __deref_opt_out_bcount_full_opt(size)
# define __deref_opt_out_xcount_full_opt(size)
# define __deref_opt_out_z_opt
# define __deref_opt_out_ecount_z_opt(size)
# define __deref_opt_out_bcount_z_opt(size)
# define __deref_opt_inout_opt
# define __deref_opt_inout_ecount_opt(size)
# define __deref_opt_inout_bcount_opt(size)
# define __deref_opt_inout_xcount_opt(size)
# define __deref_opt_inout_ecount_part_opt(size, len)
# define __deref_opt_inout_bcount_part_opt(size, len)
# define __deref_opt_inout_xcount_part_opt(size, len)
# define __deref_opt_inout_ecount_full_opt(size)
# define __deref_opt_inout_bcount_full_opt(size)
# define __deref_opt_inout_xcount_full_opt(size)
# define __deref_opt_inout_z_opt
# define __deref_opt_inout_ecount_z_opt(size)
# define __deref_opt_inout_bcount_z_opt(size)
# define __deref_in_ecount_iterator(size, incr)
# define __deref_out_ecount_iterator(size, incr)
# define __deref_inout_ecount_iterator(size, incr)
# define __deref_realloc_bcount(insize, outsize)
# define _Outptr_
# define _Outptr_result_maybenull_
# define _Outptr_opt_
# define _Outptr_opt_result_maybenull_
# define _Outptr_result_z_
# define _Outptr_opt_result_z_
# define _Outptr_result_maybenull_z_
# define _Outptr_opt_result_maybenull_z_
# define _Outptr_result_nullonfailure_
# define _Outptr_opt_result_nullonfailure_
# define _COM_Outptr_
# define _COM_Outptr_result_maybenull_
# define _COM_Outptr_opt_
# define _COM_Outptr_opt_result_maybenull_
# define _Outptr_result_buffer_(size)
# define _Outptr_opt_result_buffer_(size)
# define _Outptr_result_buffer_to_(size, count)
# define _Outptr_opt_result_buffer_to_(size, count)
# define _Outptr_result_buffer_all_(size)
# define _Outptr_opt_result_buffer_all_(size)
# define _Outptr_result_buffer_maybenull_(size)
# define _Outptr_opt_result_buffer_maybenull_(size)
# define _Outptr_result_buffer_to_maybenull_(size, count)
# define _Outptr_opt_result_buffer_to_maybenull_(size, count)
# define _Outptr_result_buffer_all_maybenull_(size)
# define _Outptr_opt_result_buffer_all_maybenull_(size)
# define _Outptr_result_bytebuffer_(size)
# define _Outptr_opt_result_bytebuffer_(size)
# define _Outptr_result_bytebuffer_to_(size, count)
# define _Outptr_opt_result_bytebuffer_to_(size, count)
# define _Outptr_result_bytebuffer_all_(size)
# define _Outptr_opt_result_bytebuffer_all_(size)
# define _Outptr_result_bytebuffer_maybenull_(size)
# define _Outptr_opt_result_bytebuffer_maybenull_(size)
# define _Outptr_result_bytebuffer_to_maybenull_(size, count)
# define _Outptr_opt_result_bytebuffer_to_maybenull_(size, count)
# define _Outptr_result_bytebuffer_all_maybenull_(size)
# define _Outptr_opt_result_bytebuffer_all_maybenull_(size)
# define _Deref_out_
# define _Deref_out_opt_
# define _Deref_opt_out_
# define _Deref_opt_out_opt_
# define _In_count_(size)
# define _In_opt_count_(size)
# define _In_bytecount_(size)
# define _In_opt_bytecount_(size)
# define _Out_cap_(size)
# define _Out_opt_cap_(size)
# define _Out_bytecap_(size)
# define _Out_opt_bytecap_(size)
# define _Deref_post_count_(size)
# define _Deref_post_opt_count_(size)
# define _Deref_post_bytecount_(size)
# define _Deref_post_opt_bytecount_(size)
# define _Deref_post_cap_(size)
# define _Deref_post_opt_cap_(size)
# define _Deref_post_bytecap_(size)
# define _Deref_post_opt_bytecap_(size)
# define _At_(expr, annotes)
# define _When_(expr, annotes)
# define __success(expr)
# define __out_awcount(expr, size)
# define __in_awcount(expr, size)
# define __nullterminated
# define __nullnullterminated
# define __reserved
# define __checkReturn
# define __typefix(ctype)
# define __override
# define __callback
# define __format_string
# define __blocksOn(resource)
# define __fallthrough
# define __range(lb, ub)
# define __in_range(lb, ub)
# define __out_range(lb, ub)
# define __deref_in_range(lb, ub)
# define __deref_out_range(lb, ub)
# define __deref_inout_range(lb, ub)
# define __field_range(lb, ub)
# define __range_max(a, b)
# define __range_min(a, b)
# define __bound
# define __in_bound
# define __out_bound
# define __deref_out_bound
# define __assume_bound(i)
# define __analysis_assume_nullterminated(x)
# define __allocator
# define __deallocate(kind)
# define __deallocate_opt(kind)
# define __post_invalid
# define __post_nullnullterminated
# define __null
# define __notnull
# define __maybenull
# define __exceptthat
# define __field_ecount(size)
# define __field_bcount(size)
# define __field_xcount(size)
# define __field_ecount_opt(size)
# define __field_bcount_opt(size)
# define __field_xcount_opt(size)
# define __field_ecount_part(size,init)
# define __field_bcount_part(size,init)
# define __field_xcount_part(size,init)
# define __field_ecount_part_opt(size,init)
# define __field_bcount_part_opt(size,init)
# define __field_xcount_part_opt(size,init)
# define __field_ecount_full(size)
# define __field_bcount_full(size)
# define __field_xcount_full(size)
# define __field_ecount_full_opt(size)
# define __field_bcount_full_opt(size)
# define __field_xcount_full_opt(size)
# define __field_nullterminated
# define __struct_bcount(size)
# define __struct_xcount(size)
# define __control_entrypoint(category)
# define __rpc_entry
# define __kernel_entry
# define __gdi_entry
# define __in_data_source(src_sym)
# define __out_data_source(src_sym)
# define __field_data_source(src_sym)
# define __this_out_data_source(src_syn)
# define __out_validated(filetype_sym)
# define __this_out_validated(filetype_sym)
# define __file_parser(filetype_sym)
# define __file_parser_class(filetype_sym)
# define __file_parser_library(filetype_sym)
# define __source_code_content(codetype_sym)
# define __class_code_content(codetype_sym)
# define __encoded_pointer
# define __encoded_array
# define __field_encoded_pointer
# define __field_encoded_array
# define __transfer(formal)
# define __assume_validated(exp)
# define __analysis_assume(expr)
# define __analysis_assert(expr)
# define __analysis_hint(hint)
# define __type_has_adt_prop(adt,prop)
# define __out_has_adt_prop(adt,prop)
# define __out_not_has_adt_prop(adt,prop)
# define __out_transfer_adt_prop(arg)
# define __out_has_type_adt_props(typ)
# define __possibly_notnullterminated
# define __volatile
# define __deref_volatile
# define __nonvolatile
# define __deref_nonvolatile
# define __in_nz
# define __in_ecount_nz(size)
# define __in_bcount_nz(size)
# define __out_nz
# define __out_nz_opt
# define __out_ecount_nz(size)
# define __out_bcount_nz(size)
# define __inout_nz
# define __inout_ecount_nz(size)
# define __inout_bcount_nz(size)
# define __in_nz_opt
# define __in_ecount_nz_opt(size)
# define __in_bcount_nz_opt(size)
# define __out_ecount_nz_opt(size)
# define __out_bcount_nz_opt(size)
# define __inout_nz_opt
# define __inout_ecount_nz_opt(size)
# define __inout_bcount_nz_opt(size)
# define __deref_out_nz
# define __deref_out_ecount_nz(size)
# define __deref_out_bcount_nz(size)
# define __deref_inout_nz
# define __deref_inout_ecount_nz(size)
# define __deref_inout_bcount_nz(size)
# define __deref_out_nz_opt
# define __deref_out_ecount_nz_opt(size)
# define __deref_out_bcount_nz_opt(size)
# define __deref_inout_nz_opt
# define __deref_inout_ecount_nz_opt(size)
# define __deref_inout_bcount_nz_opt(size)
# define __deref_opt_inout_nz
# define __deref_opt_inout_ecount_nz(size)
# define __deref_opt_inout_bcount_nz(size)
# define __deref_opt_out_nz_opt
# define __deref_opt_out_ecount_nz_opt(size)
# define __deref_opt_out_bcount_nz_opt(size)
# define __deref_opt_inout_nz_opt
# define __deref_opt_inout_ecount_nz_opt(size)
# define __deref_opt_inout_bcount_nz_opt(size)
# define __deref
# define __pre
# define __post
# define __readableTo(count)
# define __writableTo(count)
# define __maybevalid
# define __inexpressible_readableTo(string)
# define __data_entrypoint(category)
# define __readonly
# define __byte_writableTo(count)
# define __byte_readableTo(count)
# define __elem_readableTo(count)
# define __elem_writableTo(count)
# define __valid
# define __notvalid
# define __refparam
# define __precond(condition)
# define __allowed(p)
#endif  /* __WIDL__ */

#endif  /* SPECSTRINGS_STRICT_H */