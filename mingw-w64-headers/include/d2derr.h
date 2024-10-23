/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.

 * d2derr.h - Header file for the Direct2D API
 * No original Microsoft headers were used in the creation of this
 * file.
 *API docs available at: http://msdn.microsoft.com/en-us/library/dd372349%28v=VS.85%29.aspx
 */
#ifndef _D2DERR_H
#define _D2DERR_H

#include <winapifamily.h>

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#define FACILITY_D2D 0x899

#define MAKE_D2DHR(sev, code) MAKE_HRESULT(sev, FACILITY_D2D, (code))
#define MAKE_D2DHR_ERR(code)  MAKE_D2DHR(1, code)

#define D2DERR_UNSUPPORTED_PIXEL_FORMAT WINCODEC_ERR_UNSUPPORTEDPIXELFORMAT
#define D2DERR_INSUFFICIENT_BUFFER      HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)
#define D2DERR_FILE_NOT_FOUND           HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */

#endif  /* _D2DERR_H */
