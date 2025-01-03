/*

	directx/dinput_private.h - DirectInput DATAFORMATs Definitions

	Written by Filip Navara <xnavara@volny.cz>

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

*/

#ifndef _DINPUT_PRIVATE_H
#define _DINPUT_PRIVATE_H

#include <windows.h>

#define DIDOI_FFACTUATOR	0x00000001
#define DIDOI_FFEFFECTTRIGGER	0x00000002
#define DIDOI_POLLED	0x00008000
#define DIDOI_ASPECTPOSITION	0x00000100
#define DIDOI_ASPECTVELOCITY	0x00000200
#define DIDOI_ASPECTACCEL	0x00000300
#define DIDOI_ASPECTFORCE	0x00000400
#define DIDOI_ASPECTMASK	0x00000F00
#define DIDOI_GUIDISUSAGE	0x00010000
#define DIDF_ABSAXIS	0x00000001
#define DIDF_RELAXIS	0x00000002
#define DIDFT_RELAXIS	0x00000001
#define DIDFT_ABSAXIS	0x00000002
#define DIDFT_AXIS	0x00000003
#define DIDFT_PSHBUTTON	0x00000004
#define DIDFT_TGLBUTTON	0x00000008
#define DIDFT_BUTTON	0x0000000C
#define DIDFT_POV	0x00000010
#define DIDFT_COLLECTION	0x00000040
#define DIDFT_NODATA	0x00000080
#define DIDFT_ANYINSTANCE	0x00FFFF00
#define DIDFT_FFACTUATOR	0x01000000
#define DIDFT_FFEFFECTTRIGGER	0x02000000
#define DIDFT_OUTPUT	0x10000000
#define DIDFT_VENDORDEFINED	0x04000000
#define DIDFT_ALIAS	0x08000000
#define DIDFT_OPTIONAL	0x80000000
#define DIDFT_MAKEINSTANCE(n)	((WORD)(n) << 8)

typedef struct _DIOBJECTDATAFORMAT {
	const GUID *pguid;
	DWORD dwOfs;
	DWORD dwType;
	DWORD dwFlags;
} DIOBJECTDATAFORMAT, *LPDIOBJECTDATAFORMAT;

typedef struct _DIDATAFORMAT {
	DWORD dwSize;
	DWORD dwObjSize;
	DWORD dwFlags;
	DWORD dwDataSize;
	DWORD dwNumObjs;
	LPDIOBJECTDATAFORMAT rgodf;
} DIDATAFORMAT, *LPDIDATAFORMAT;

extern GUID GUID_XAxis;
extern GUID GUID_YAxis;
extern GUID GUID_ZAxis;
extern GUID GUID_RxAxis;
extern GUID GUID_RyAxis;
extern GUID GUID_RzAxis;
extern GUID GUID_Slider;
extern GUID GUID_Key;
extern GUID GUID_POV;

#define ATTRIBUTE_TEXT_SECTION  __attribute__ ((section(".text")))

#endif
