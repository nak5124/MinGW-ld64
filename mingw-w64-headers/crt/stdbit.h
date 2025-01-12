/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _STDBIT_H
#define _STDBIT_H

#include <corecrt.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

__MINGW_BEGIN_C_DECLS

#define __MINGW_STDBIT_INLINE static __inline__ __attribute__((__always_inline__))

/* 7.18.1 General */
#define __STDC_VERSION_STDBIT_H__ 202311L

/* 7.18.2 Endian */
#define __STDC_ENDIAN_LITTLE__ __ORDER_LITTLE_ENDIAN__
#define __STDC_ENDIAN_BIG__    __ORDER_BIG_ENDIAN__
#define __STDC_ENDIAN_NATIVE__ __BYTE_ORDER__

/* 7.18.3 Count Leading Zeros */
  extern unsigned int stdc_leading_zeros_uc(unsigned char value)           __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_leading_zeros_us(unsigned short value)          __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_leading_zeros_ui(unsigned int value)            __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_leading_zeros_ul(unsigned long int value)       __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_leading_zeros_ull(unsigned long long int value) __MINGW_NOTHROW __MINGW_CONST;

#define stdc_leading_zeros(value) (__builtin_stdc_leading_zeros(value))

  __MINGW_STDBIT_INLINE
  unsigned int __leading_zeros_64(uint64_t _X)
  {
    return _X ? (unsigned int)__builtin_clzll(_X) : 64U;
  }

  __MINGW_STDBIT_INLINE
  unsigned int __leading_zeros_32(uint32_t _X)
  {
    return _X ? (unsigned int)__builtin_clz(_X) : 32U;
  }

  __MINGW_STDBIT_INLINE
  unsigned int __leading_zeros_16(uint16_t _X)
  {
    return __leading_zeros_32(_X) - 16U;
  }

  __MINGW_STDBIT_INLINE
  unsigned int __leading_zeros_8(uint8_t _X)
  {
    return __leading_zeros_32(_X) - 24U;
  }

#define stdc_leading_zeros_uc(value)  (__leading_zeros_8(value))
#define stdc_leading_zeros_us(value)  (__leading_zeros_16(value))
#define stdc_leading_zeros_ui(value)  (__leading_zeros_32(value))
#define stdc_leading_zeros_ul(value)  (__leading_zeros_32(value))
#define stdc_leading_zeros_ull(value) (__leading_zeros_64(value))

/* 7.18.4 Count Leading Ones */
  extern unsigned int stdc_leading_ones_uc(unsigned char value)           __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_leading_ones_us(unsigned short value)          __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_leading_ones_ui(unsigned int value)            __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_leading_ones_ul(unsigned long int value)       __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_leading_ones_ull(unsigned long long int value) __MINGW_NOTHROW __MINGW_CONST;

#define stdc_leading_ones(value) (__builtin_stdc_leading_ones(value))

  __MINGW_STDBIT_INLINE
  unsigned int __leading_ones_64(uint64_t _X)
  {
    return __leading_zeros_64(~_X);
  }

  __MINGW_STDBIT_INLINE
  unsigned int __leading_ones_32(uint32_t _X)
  {
    return __leading_zeros_32(~_X);
  }

  __MINGW_STDBIT_INLINE
  unsigned int __leading_ones_16(uint16_t _X)
  {
    return __leading_zeros_16(~_X);
  }

  __MINGW_STDBIT_INLINE
  unsigned int __leading_ones_8(uint8_t _X)
  {
    return __leading_zeros_8(~_X);
  }

#define stdc_leading_ones_uc(value)  (__leading_ones_8(value))
#define stdc_leading_ones_us(value)  (__leading_ones_16(value))
#define stdc_leading_ones_ui(value)  (__leading_ones_32(value))
#define stdc_leading_ones_ul(value)  (__leading_ones_32(value))
#define stdc_leading_ones_ull(value) (__leading_ones_64(value))

/* 7.18.5 Count Trailing Zeros */
  extern unsigned int stdc_trailing_zeros_uc(unsigned char value)           __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_trailing_zeros_us(unsigned short value)          __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_trailing_zeros_ui(unsigned int value)            __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_trailing_zeros_ul(unsigned long int value)       __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_trailing_zeros_ull(unsigned long long int value) __MINGW_NOTHROW __MINGW_CONST;

#define stdc_trailing_zeros(value) (__builtin_stdc_trailing_zeros(value))

  __MINGW_STDBIT_INLINE
  unsigned int __trailing_zeros_64(uint64_t _X)
  {
    return _X ? (unsigned int)__builtin_ctzll(_X) : 64U;
  }

  __MINGW_STDBIT_INLINE
  unsigned int __trailing_zeros_32(uint32_t _X)
  {
    return _X ? (unsigned int)__builtin_ctz(_X) : 32U;
  }

  __MINGW_STDBIT_INLINE
  unsigned int __trailing_zeros_16(uint16_t _X)
  {
    return _X ? (unsigned int)__builtin_ctz(_X) : 16U;
  }

  __MINGW_STDBIT_INLINE
  unsigned int __trailing_zeros_8(uint8_t _X)
  {
    return _X ? (unsigned int)__builtin_ctz(_X) : 8U;
  }

#define stdc_trailing_zeros_uc(value)  (__trailing_zeros_8(value))
#define stdc_trailing_zeros_us(value)  (__trailing_zeros_16(value))
#define stdc_trailing_zeros_ui(value)  (__trailing_zeros_32(value))
#define stdc_trailing_zeros_ul(value)  (__trailing_zeros_32(value))
#define stdc_trailing_zeros_ull(value) (__trailing_zeros_64(value))

/* 7.18.6 Count Trailing Ones */
  extern unsigned int stdc_trailing_ones_uc(unsigned char value)           __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_trailing_ones_us(unsigned short value)          __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_trailing_ones_ui(unsigned int value)            __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_trailing_ones_ul(unsigned long int value)       __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_trailing_ones_ull(unsigned long long int value) __MINGW_NOTHROW __MINGW_CONST;

#define stdc_trailing_ones(value) (__builtin_stdc_trailing_ones(value))

  __MINGW_STDBIT_INLINE
  unsigned int __trailing_ones_64(uint64_t _X)
  {
    return __trailing_zeros_64(~_X);
  }

  __MINGW_STDBIT_INLINE
  unsigned int __trailing_ones_32(uint32_t _X)
  {
    return __trailing_zeros_32(~_X);
  }

  __MINGW_STDBIT_INLINE
  unsigned int __trailing_ones_16(uint16_t _X)
  {
    return __trailing_zeros_16(~_X);
  }

  __MINGW_STDBIT_INLINE
  unsigned int __trailing_ones_8(uint8_t _X)
  {
    return __trailing_zeros_8(~_X);
  }

#define stdc_trailing_ones_uc(value)  (__trailing_ones_8(value))
#define stdc_trailing_ones_us(value)  (__trailing_ones_16(value))
#define stdc_trailing_ones_ui(value)  (__trailing_ones_32(value))
#define stdc_trailing_ones_ul(value)  (__trailing_ones_32(value))
#define stdc_trailing_ones_ull(value) (__trailing_ones_64(value))

/* 7.18.7 First Leading Zero */
  extern unsigned int stdc_first_leading_zero_uc(unsigned char value)           __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_first_leading_zero_us(unsigned short value)          __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_first_leading_zero_ui(unsigned int value)            __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_first_leading_zero_ul(unsigned long int value)       __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_first_leading_zero_ull(unsigned long long int value) __MINGW_NOTHROW __MINGW_CONST;

#define stdc_first_leading_zero(value) (__builtin_stdc_first_leading_zero(value))

  __MINGW_STDBIT_INLINE
  unsigned int
  __first_leading_zero_64(uint64_t _X)
  {
    return _X == _UI64_MAX ? 0 : 1 + __leading_ones_64(_X);
  }

  __MINGW_STDBIT_INLINE
  unsigned int
  __first_leading_zero_32(uint32_t _X)
  {
    return _X == _UI32_MAX ? 0 : 1 + __leading_ones_32(_X);
  }

  __MINGW_STDBIT_INLINE
  unsigned int
  __first_leading_zero_16(uint16_t _X)
  {
    return _X == _UI16_MAX ? 0 : 1 + __leading_ones_16(_X);
  }

  __MINGW_STDBIT_INLINE
  unsigned int
  __first_leading_zero_8(uint8_t _X)
  {
    return _X == _UI8_MAX ? 0 : 1 + __leading_ones_8(_X);
  }

#define stdc_first_leading_zero_uc(value)  (__first_leading_zero_8(value))
#define stdc_first_leading_zero_us(value)  (__first_leading_zero_16(value))
#define stdc_first_leading_zero_ui(value)  (__first_leading_zero_32(value))
#define stdc_first_leading_zero_ul(value)  (__first_leading_zero_32(value))
#define stdc_first_leading_zero_ull(value) (__first_leading_zero_64(value))

/* 7.18.8 First Leading One */
  extern unsigned int stdc_first_leading_one_uc(unsigned char value)           __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_first_leading_one_us(unsigned short value)          __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_first_leading_one_ui(unsigned int value)            __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_first_leading_one_ul(unsigned long int value)       __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_first_leading_one_ull(unsigned long long int value) __MINGW_NOTHROW __MINGW_CONST;

#define stdc_first_leading_one(value) (__builtin_stdc_first_leading_one(value))

  __MINGW_STDBIT_INLINE
  unsigned int __first_leading_one_64(uint64_t _X)
  {
    return _X ? 1 + __leading_zeros_64(_X) : 0;
  }

  __MINGW_STDBIT_INLINE
  unsigned int __first_leading_one_32(uint32_t _X)
  {
    return _X ? 1 + __leading_zeros_32(_X) : 0;
  }

  __MINGW_STDBIT_INLINE
  unsigned int __first_leading_one_16(uint16_t _X)
  {
    return _X ? 1 + __leading_zeros_16(_X) : 0;
  }

  __MINGW_STDBIT_INLINE
  unsigned int __first_leading_one_8(uint8_t _X)
  {
    return _X ? 1 + __leading_zeros_8(_X) : 0;
  }

#define stdc_first_leading_one_uc(value)  (__first_leading_one_8(value))
#define stdc_first_leading_one_us(value)  (__first_leading_one_16(value))
#define stdc_first_leading_one_ui(value)  (__first_leading_one_32(value))
#define stdc_first_leading_one_ul(value)  (__first_leading_one_32(value))
#define stdc_first_leading_one_ull(value) (__first_leading_one_64(value))

/* 7.18.9 First Trailing Zero */
  extern unsigned int stdc_first_trailing_zero_uc(unsigned char value)           __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_first_trailing_zero_us(unsigned short value)          __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_first_trailing_zero_ui(unsigned int value)            __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_first_trailing_zero_ul(unsigned long int value)       __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_first_trailing_zero_ull(unsigned long long int value) __MINGW_NOTHROW __MINGW_CONST;

#define stdc_first_trailing_zero(value) (__builtin_stdc_first_trailing_zero(value))

  __MINGW_STDBIT_INLINE
  unsigned int __first_trailing_zero_64(uint64_t _X)
  {
    return _X == _UI64_MAX ? 0 : 1 + __trailing_ones_64(_X);
  }

  __MINGW_STDBIT_INLINE
  unsigned int __first_trailing_zero_32(uint32_t _X)
  {
    return _X == _UI32_MAX ? 0 : 1 + __trailing_ones_32(_X);
  }

  __MINGW_STDBIT_INLINE
  unsigned int __first_trailing_zero_16(uint16_t _X)
  {
    return _X == _UI16_MAX ? 0 : 1 + __trailing_ones_16(_X);
  }

  __MINGW_STDBIT_INLINE
  unsigned int __first_trailing_zero_8(uint8_t _X)
  {
    return _X == _UI8_MAX ? 0 : 1 + __trailing_ones_8(_X);
  }

#define stdc_first_trailing_zero_uc(value)  (__first_trailing_zero_8(value))
#define stdc_first_trailing_zero_us(value)  (__first_trailing_zero_16(value))
#define stdc_first_trailing_zero_ui(value)  (__first_trailing_zero_32(value))
#define stdc_first_trailing_zero_ul(value)  (__first_trailing_zero_32(value))
#define stdc_first_trailing_zero_ull(value) (__first_trailing_zero_64(value))

/* 7.18.10 First Trailing One */
  extern unsigned int stdc_first_trailing_one_uc(unsigned char value)           __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_first_trailing_one_us(unsigned short value)          __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_first_trailing_one_ui(unsigned int value)            __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_first_trailing_one_ul(unsigned long int value)       __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_first_trailing_one_ull(unsigned long long int value) __MINGW_NOTHROW __MINGW_CONST;

#define stdc_first_trailing_one(value) (__builtin_stdc_first_trailing_one(value))

  __MINGW_STDBIT_INLINE
  unsigned int __first_trailing_one_64(uint64_t _X)
  {
    return _X ? 1 + __trailing_zeros_64(_X) : 0;
  }

  __MINGW_STDBIT_INLINE
  unsigned int __first_trailing_one_32(uint32_t _X)
  {
    return _X ? 1 + __trailing_zeros_32(_X) : 0;
  }

  __MINGW_STDBIT_INLINE
  unsigned int __first_trailing_one_16(uint16_t _X)
  {
    return _X ? 1 + __trailing_zeros_16(_X) : 0;
  }

  __MINGW_STDBIT_INLINE
  unsigned int __first_trailing_one_8(uint8_t _X)
  {
    return _X ? 1 + __trailing_zeros_8(_X) : 0;
  }

#define stdc_first_trailing_one_uc(value)  (__first_trailing_one_8(value))
#define stdc_first_trailing_one_us(value)  (__first_trailing_one_16(value))
#define stdc_first_trailing_one_ui(value)  (__first_trailing_one_32(value))
#define stdc_first_trailing_one_ul(value)  (__first_trailing_one_32(value))
#define stdc_first_trailing_one_ull(value) (__first_trailing_one_64(value))

/* 7.18.11 Count Zeros */
  extern unsigned int stdc_count_zeros_uc(unsigned char value)           __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_count_zeros_us(unsigned short value)          __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_count_zeros_ui(unsigned int value)            __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_count_zeros_ul(unsigned long int value)       __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_count_zeros_ull(unsigned long long int value) __MINGW_NOTHROW __MINGW_CONST;

#define stdc_count_zeros(value) (__builtin_stdc_count_zeros(value))

  __MINGW_STDBIT_INLINE
  unsigned int __count_zeros_64(uint64_t _X)
  {
    return 64U - (unsigned int)__builtin_popcountll(_X);
  }

  __MINGW_STDBIT_INLINE
  unsigned int __count_zeros_32(uint32_t _X)
  {
    return 32U - (unsigned int)__builtin_popcount(_X);
  }

  __MINGW_STDBIT_INLINE
  unsigned int __count_zeros_16(uint16_t _X)
  {
    return 16U - (unsigned int)__builtin_popcount(_X);
  }

  __MINGW_STDBIT_INLINE
  unsigned int __count_zeros_8(uint8_t _X)
  {
    return 8U - (unsigned int)__builtin_popcount(_X);
  }

#define stdc_count_zeros_uc(value)  (__count_zeros_8(value))
#define stdc_count_zeros_us(value)  (__count_zeros_16(value))
#define stdc_count_zeros_ui(value)  (__count_zeros_32(value))
#define stdc_count_zeros_ul(value)  (__count_zeros_32(value))
#define stdc_count_zeros_ull(value) (__count_zeros_64(value))

/* 7.18.12 Count Ones */
  extern unsigned int stdc_count_ones_uc(unsigned char value)           __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_count_ones_us(unsigned short value)          __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_count_ones_ui(unsigned int value)            __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_count_ones_ul(unsigned long int value)       __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_count_ones_ull(unsigned long long int value) __MINGW_NOTHROW __MINGW_CONST;

#define stdc_count_ones(value) (__builtin_stdc_count_ones(value))

  __MINGW_STDBIT_INLINE
  unsigned int __count_ones_64(uint64_t _X)
  {
    return (unsigned int)__builtin_popcountll(_X);
  }

  __MINGW_STDBIT_INLINE
  unsigned int __count_ones_32(uint32_t _X)
  {
    return (unsigned int)__builtin_popcount(_X);
  }

  __MINGW_STDBIT_INLINE
  unsigned int __count_ones_16(uint16_t _X)
  {
    return (unsigned int)__builtin_popcount(_X);
  }

  __MINGW_STDBIT_INLINE
  unsigned int __count_ones_8(uint8_t _X)
  {
    return (unsigned int)__builtin_popcount(_X);
  }

#define stdc_count_ones_uc(value)  (__count_ones_8(value))
#define stdc_count_ones_us(value)  (__count_ones_16(value))
#define stdc_count_ones_ui(value)  (__count_ones_32(value))
#define stdc_count_ones_ul(value)  (__count_ones_32(value))
#define stdc_count_ones_ull(value) (__count_ones_64(value))

/* 7.18.13 Single-bit Check */
  extern bool stdc_has_single_bit_uc(unsigned char value)           __MINGW_NOTHROW __MINGW_CONST;
  extern bool stdc_has_single_bit_us(unsigned short value)          __MINGW_NOTHROW __MINGW_CONST;
  extern bool stdc_has_single_bit_ui(unsigned int value)            __MINGW_NOTHROW __MINGW_CONST;
  extern bool stdc_has_single_bit_ul(unsigned long int value)       __MINGW_NOTHROW __MINGW_CONST;
  extern bool stdc_has_single_bit_ull(unsigned long long int value) __MINGW_NOTHROW __MINGW_CONST;

#define stdc_has_single_bit(value) (__builtin_stdc_has_single_bit(value))

  __MINGW_STDBIT_INLINE
  bool __has_single_bit_64(uint64_t _X)
  {
    return (_X != 0) && ((_X & (_X - 1)) == 0);
  }

  __MINGW_STDBIT_INLINE
  bool __has_single_bit_32(uint32_t _X)
  {
    return (_X != 0) && ((_X & (_X - 1)) == 0);
  }

  __MINGW_STDBIT_INLINE
  bool __has_single_bit_16(uint16_t _X)
  {
    return (_X != 0) && ((_X & (_X - 1)) == 0);
  }

  __MINGW_STDBIT_INLINE
  bool __has_single_bit_8(uint8_t _X)
  {
    return (_X != 0) && ((_X & (_X - 1)) == 0);
  }

#define stdc_has_single_bit_uc(value)  (__has_single_bit_8(value))
#define stdc_has_single_bit_us(value)  (__has_single_bit_16(value))
#define stdc_has_single_bit_ui(value)  (__has_single_bit_32(value))
#define stdc_has_single_bit_ul(value)  (__has_single_bit_32(value))
#define stdc_has_single_bit_ull(value) (__has_single_bit_64(value))

/* 7.18.14 Bit Width */
  extern unsigned int stdc_bit_width_uc(unsigned char value)           __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_bit_width_us(unsigned short value)          __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_bit_width_ui(unsigned int value)            __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_bit_width_ul(unsigned long int value)       __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int stdc_bit_width_ull(unsigned long long int value) __MINGW_NOTHROW __MINGW_CONST;

#define stdc_bit_width(value) (__builtin_stdc_bit_width(value))

  __MINGW_STDBIT_INLINE
  unsigned int __bit_width_64(uint64_t _X)
  {
    return 64U - __leading_zeros_64(_X);
  }

  __MINGW_STDBIT_INLINE
  unsigned int __bit_width_32(uint32_t _X)
  {
    return 32U - __leading_zeros_32(_X);
  }

  __MINGW_STDBIT_INLINE
  unsigned int __bit_width_16(uint16_t _X)
  {
    return 16U - __leading_zeros_16(_X);
  }

  __MINGW_STDBIT_INLINE
  unsigned int __bit_width_8(uint8_t _X)
  {
    return 8U - __leading_zeros_8(_X);
  }

#define stdc_bit_width_uc(value)  (__bit_width_8(value))
#define stdc_bit_width_us(value)  (__bit_width_16(value))
#define stdc_bit_width_ui(value)  (__bit_width_32(value))
#define stdc_bit_width_ul(value)  (__bit_width_32(value))
#define stdc_bit_width_ull(value) (__bit_width_64(value))

/* 7.18.15 Bit Floor */
  extern unsigned char          stdc_bit_floor_uc(unsigned char value)           __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned short         stdc_bit_floor_us(unsigned short value)          __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int           stdc_bit_floor_ui(unsigned int value)            __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned long int      stdc_bit_floor_ul(unsigned long int value)       __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned long long int stdc_bit_floor_ull(unsigned long long int value) __MINGW_NOTHROW __MINGW_CONST;

#define stdc_bit_floor(value) (__builtin_stdc_bit_floor(value))

  __MINGW_STDBIT_INLINE
  uint64_t __bit_floor_64(uint64_t _X)
  {
    return _X ? ((uint64_t)1) << (__bit_width_64(_X) - 1) : 0;
  }

  __MINGW_STDBIT_INLINE
  uint32_t __bit_floor_32(uint32_t _X)
  {
    return _X ? ((uint32_t)1) << (__bit_width_32(_X) - 1) : 0;
  }

  __MINGW_STDBIT_INLINE
  uint16_t __bit_floor_16(uint16_t _X)
  {
    return _X ? ((uint16_t)1) << (__bit_width_16(_X) - 1) : 0;
  }

  __MINGW_STDBIT_INLINE
  uint8_t __bit_floor_8(uint8_t _X)
  {
    return _X ? ((uint8_t)1) << (__bit_width_8(_X) - 1) : 0;
  }

#define stdc_bit_floor_uc(value)  ((unsigned char)__bit_floor_8(value))
#define stdc_bit_floor_us(value)  ((unsigned short)__bit_floor_16(value))
#define stdc_bit_floor_ui(value)  ((unsigned int)__bit_floor_32(value))
#define stdc_bit_floor_ul(value)  ((unsigned long int)__bit_floor_32(value))
#define stdc_bit_floor_ull(value) ((unsigned long long int)__bit_floor_64(value))

/* 7.18.16 Bit Ceiling */
  extern unsigned char          stdc_bit_ceil_uc(unsigned char value)           __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned short         stdc_bit_ceil_us(unsigned short value)          __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned int           stdc_bit_ceil_ui(unsigned int value)            __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned long int      stdc_bit_ceil_ul(unsigned long int value)       __MINGW_NOTHROW __MINGW_CONST;
  extern unsigned long long int stdc_bit_ceil_ull(unsigned long long int value) __MINGW_NOTHROW __MINGW_CONST;

#define stdc_bit_ceil(value) (__builtin_stdc_bit_ceil(value))

  __MINGW_STDBIT_INLINE
  uint64_t __bit_ceil_64(uint64_t _X)
  {
    return _X < 2 ? 1 : ((uint64_t)2) << (__bit_width_64(_X - 1) - 1);
  }

  __MINGW_STDBIT_INLINE
  uint32_t __bit_ceil_32(uint32_t _X)
  {
    return _X < 2 ? 1 : ((uint32_t)2) << (__bit_width_32(_X - 1) - 1);
  }

  __MINGW_STDBIT_INLINE
  uint16_t __bit_ceil_16(uint16_t _X)
  {
    return _X < 2 ? 1 : ((uint16_t)2) << (__bit_width_16(_X - 1) - 1);
  }

  __MINGW_STDBIT_INLINE
  uint8_t __bit_ceil_8(uint8_t _X)
  {
    return _X < 2 ? 1 : ((uint8_t)2) << (__bit_width_8(_X - 1) - 1);
  }

#define stdc_bit_ceil_uc(value)  ((unsigned char)__bit_ceil_8(value))
#define stdc_bit_ceil_us(value)  ((unsigned short)__bit_ceil_16(value))
#define stdc_bit_ceil_ui(value)  ((unsigned int)__bit_ceil_32(value))
#define stdc_bit_ceil_ul(value)  ((unsigned long int)__bit_ceil_32(value))
#define stdc_bit_ceil_ull(value) ((unsigned long long int)__bit_ceil_64(value))

__MINGW_END_C_DECLS

#endif  /* _STDBIT_H */
