/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _IME_CMODES_
#define _IME_CMODES_

#define IME_CMODE_ALPHANUMERIC 0x0000
#define IME_CMODE_NATIVE       0x0001
#define IME_CMODE_CHINESE      IME_CMODE_NATIVE
#define IME_CMODE_HANGUL       IME_CMODE_NATIVE
#define IME_CMODE_JAPANESE     IME_CMODE_NATIVE
#define IME_CMODE_KATAKANA     0x0002
#define IME_CMODE_LANGUAGE     0x0003
#define IME_CMODE_FULLSHAPE    0x0008
#define IME_CMODE_ROMAN        0x0010
#define IME_CMODE_CHARCODE     0x0020
#define IME_CMODE_HANJACONVERT 0x0040
#define IME_CMODE_NATIVESYMBOL 0x0080

#endif  /* _IME_CMODES_*/
