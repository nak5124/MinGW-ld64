/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef	_ENDIAN_H
#define _ENDIAN_H

#include <corecrt.h>
#include <stdint.h>

__MINGW_BEGIN_C_DECLS

#ifdef __MINGW_USE_MISC
# define __LITTLE_ENDIAN    __ORDER_LITTLE_ENDIAN__
# define __BIG_ENDIAN       __ORDER_BIG_ENDIAN__
# define __PDP_ENDIAN       __ORDER_PDP_ENDIAN__
# define __BYTE_ORDER       __BYTE_ORDER__
# define __FLOAT_WORD_ORDER __BYTE_ORDER__
# define  _LITTLE_ENDIAN    __ORDER_LITTLE_ENDIAN__
# define  _BIG_ENDIAN       __ORDER_BIG_ENDIAN__
# define  _PDP_ENDIAN       __ORDER_PDP_ENDIAN__
# define  _BYTE_ORDER       __BYTE_ORDER__
# define  _FLOAT_WORD_ORDER __BYTE_ORDER__
#endif

#if defined(__MINGW_USE_MISC) || defined(__MINGW_USE_XOPEN2K24)
# define LITTLE_ENDIAN __ORDER_LITTLE_ENDIAN__
# define BIG_ENDIAN    __ORDER_BIG_ENDIAN__
# define PDP_ENDIAN    __ORDER_PDP_ENDIAN__
# define BYTE_ORDER    __BYTE_ORDER__

# define be16toh(_X) __builtin_bswap16(_X)
# define be32toh(_X) __builtin_bswap32(_X)
# define be64toh(_X) __builtin_bswap64(_X)
# define htobe16(_X) __builtin_bswap16(_X)
# define htobe32(_X) __builtin_bswap32(_X)
# define htobe64(_X) __builtin_bswap64(_X)
# define htole16(_X) ((uint16_t)(_X))
# define htole32(_X) ((uint32_t)(_X))
# define htole64(_X) ((uint64_t)(_X))
# define le16toh(_X) ((uint16_t)(_X))
# define le32toh(_X) ((uint32_t)(_X))
# define le64toh(_X) ((uint64_t)(_X))
#endif

__MINGW_END_C_DECLS

#endif  /* _ENDIAN_H */
