/* Copyright (C) 1989, 1997, 1998, 1999, 2000 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to
the Free Software Foundation, 51 Franklin Street, Fifth Floor,
Boston, MA 02110-1301, USA.  */

/* As a special exception, if you include this header file into source
 * files compiled by GCC, this header file does not by itself cause
 * the resulting executable to be covered by the GNU General Public
 * License.  This exception does not however invalidate any other
 * reasons why the executable file might be covered by the GNU General
 * Public License.  */

/*
 * ISO C Standard:  7.15  Variable arguments  <stdarg.h>
 */
#ifndef _STDARG_H
#define _STDARG_H
#define _ANSI_STDARG_H_
#undef __need___va_list

#include <corecrt.h>

#ifndef __GNUC_VA_LIST
# define __GNUC_VA_LIST
  typedef __builtin_va_list __gnuc_va_list;
#endif

#if defined(__STDC_VERSION__) && __STDC_VERSION__ > 201710L
# define va_start(v, ...) __builtin_va_start(v, 0)
#else
# define va_start(v, l)   __builtin_va_start(v, l)
#endif
#define va_end(v)   __builtin_va_end(v)
#define va_arg(v,l) __builtin_va_arg(v, l)
#if defined(__MINGW_USE_ISOC99) || defined(__MINGW_USE_MS) || defined(__MINGW_USE_ISOCXX11)
# define va_copy(d, s) __builtin_va_copy(d, s)
#endif
#define __va_copy(d,s) __builtin_va_copy(d, s)

#ifndef _VA_LIST_DEFINED  /* Also in vadefs.h */
# define _VA_LIST_DEFINED
  typedef __gnuc_va_list va_list;
#endif  /* _VA_LIST_DEFINED */

#if defined(__STDC_VERSION__) && __STDC_VERSION__ > 201710L
# define __STDC_VERSION_STDARG_H__ 202311L
#endif

#endif  /* _STDARG_H */
