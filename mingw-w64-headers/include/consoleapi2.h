/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _APISETCONSOLEL2_
#define _APISETCONSOLEL2_

#include <_mingw_unicode.h>
#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>
#include <minwinbase.h>

#include <wincontypes.h>
#include <windef.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

#define FOREGROUND_BLUE            0x0001
#define FOREGROUND_GREEN           0x0002
#define FOREGROUND_RED             0x0004
#define FOREGROUND_INTENSITY       0x0008
#define BACKGROUND_BLUE            0x0010
#define BACKGROUND_GREEN           0x0020
#define BACKGROUND_RED             0x0040
#define BACKGROUND_INTENSITY       0x0080
#define COMMON_LVB_LEADING_BYTE    0x0100
#define COMMON_LVB_TRAILING_BYTE   0x0200
#define COMMON_LVB_GRID_HORIZONTAL 0x0400
#define COMMON_LVB_GRID_LVERTICAL  0x0800
#define COMMON_LVB_GRID_RVERTICAL  0x1000
#define COMMON_LVB_REVERSE_VIDEO   0x4000
#define COMMON_LVB_UNDERSCORE      0x8000
#define COMMON_LVB_SBCSDBCS        0x0300

  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterA(HANDLE hConsoleOutput, CHAR cCharacter, DWORD nLength, COORD dwWriteCoord, LPDWORD lpNumberOfCharsWritten);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterW(HANDLE hConsoleOutput, WCHAR cCharacter, DWORD nLength, COORD dwWriteCoord, LPDWORD lpNumberOfCharsWritten);
#define FillConsoleOutputCharacter __MINGW_NAME_AW(FillConsoleOutputCharacter)
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputAttribute(HANDLE hConsoleOutput, WORD wAttribute, DWORD nLength, COORD dwWriteCoord, LPDWORD lpNumberOfAttrsWritten);
  WINBASEAPI WINBOOL WINAPI GenerateConsoleCtrlEvent(DWORD dwCtrlEvent, DWORD dwProcessGroupId);
  WINBASEAPI HANDLE  WINAPI CreateConsoleScreenBuffer(DWORD dwDesiredAccess, DWORD dwShareMode, CONST SECURITY_ATTRIBUTES *lpSecurityAttributes, DWORD dwFlags, LPVOID lpScreenBufferData);
  WINBASEAPI WINBOOL WINAPI SetConsoleActiveScreenBuffer(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI FlushConsoleInputBuffer(HANDLE hConsoleInput);
  WINBASEAPI WINBOOL WINAPI SetConsoleCP(UINT wCodePageID);
  WINBASEAPI WINBOOL WINAPI SetConsoleOutputCP(UINT wCodePageID);

  typedef struct _CONSOLE_CURSOR_INFO
  {
    DWORD   dwSize;
    WINBOOL bVisible;
  } CONSOLE_CURSOR_INFO, *PCONSOLE_CURSOR_INFO;

  WINBASEAPI WINBOOL WINAPI GetConsoleCursorInfo(HANDLE hConsoleOutput, PCONSOLE_CURSOR_INFO lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI SetConsoleCursorInfo(HANDLE hConsoleOutput, CONST CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);

  typedef struct _CONSOLE_SCREEN_BUFFER_INFO
  {
    COORD      dwSize;
    COORD      dwCursorPosition;
    WORD       wAttributes;
    SMALL_RECT srWindow;
    COORD      dwMaximumWindowSize;
  } CONSOLE_SCREEN_BUFFER_INFO, *PCONSOLE_SCREEN_BUFFER_INFO;

  WINBASEAPI WINBOOL WINAPI GetConsoleScreenBufferInfo(HANDLE hConsoleOutput, PCONSOLE_SCREEN_BUFFER_INFO lpConsoleScreenBufferInfo);

  typedef struct _CONSOLE_SCREEN_BUFFER_INFOEX
  {
    ULONG      cbSize;
    COORD      dwSize;
    COORD      dwCursorPosition;
    WORD       wAttributes;
    SMALL_RECT srWindow;
    COORD      dwMaximumWindowSize;
    WORD       wPopupAttributes;
    WINBOOL    bFullscreenSupported;
    COLORREF   ColorTable[16];
  } CONSOLE_SCREEN_BUFFER_INFOEX, *PCONSOLE_SCREEN_BUFFER_INFOEX;

  WINBASEAPI WINBOOL WINAPI GetConsoleScreenBufferInfoEx(HANDLE hConsoleOutput, PCONSOLE_SCREEN_BUFFER_INFOEX lpConsoleScreenBufferInfoEx);
  WINBASEAPI WINBOOL WINAPI SetConsoleScreenBufferInfoEx(HANDLE hConsoleOutput, PCONSOLE_SCREEN_BUFFER_INFOEX lpConsoleScreenBufferInfoEx);
  WINBASEAPI WINBOOL WINAPI SetConsoleScreenBufferSize(HANDLE hConsoleOutput, COORD dwSize);
  WINBASEAPI WINBOOL WINAPI SetConsoleCursorPosition(HANDLE hConsoleOutput, COORD dwCursorPosition);
  WINBASEAPI COORD   WINAPI GetLargestConsoleWindowSize(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI SetConsoleTextAttribute(HANDLE hConsoleOutput, WORD wAttributes);
  WINBASEAPI WINBOOL WINAPI SetConsoleWindowInfo(HANDLE hConsoleOutput, WINBOOL bAbsolute, CONST SMALL_RECT *lpConsoleWindow);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterA(HANDLE hConsoleOutput, LPCSTR lpCharacter, DWORD nLength, COORD dwWriteCoord, LPDWORD lpNumberOfCharsWritten);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterW(HANDLE hConsoleOutput, LPCWSTR lpCharacter, DWORD nLength, COORD dwWriteCoord, LPDWORD lpNumberOfCharsWritten);
#define WriteConsoleOutputCharacter __MINGW_NAME_AW(WriteConsoleOutputCharacter)
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputAttribute(HANDLE hConsoleOutput, CONST WORD *lpAttribute, DWORD nLength, COORD dwWriteCoord, LPDWORD lpNumberOfAttrsWritten);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterA(HANDLE hConsoleOutput, LPSTR lpCharacter, DWORD nLength, COORD dwReadCoord, LPDWORD lpNumberOfCharsRead);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterW(HANDLE hConsoleOutput, LPWSTR lpCharacter, DWORD nLength, COORD dwReadCoord, LPDWORD lpNumberOfCharsRead);
#define ReadConsoleOutputCharacter __MINGW_NAME_AW(ReadConsoleOutputCharacter)
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputAttribute(HANDLE hConsoleOutput, LPWORD lpAttribute, DWORD nLength, COORD dwReadCoord, LPDWORD lpNumberOfAttrsRead);
  WINBASEAPI WINBOOL WINAPI WriteConsoleInputA(HANDLE hConsoleInput, CONST INPUT_RECORD *lpBuffer, DWORD nLength, LPDWORD lpNumberOfEventsWritten);
  WINBASEAPI WINBOOL WINAPI WriteConsoleInputW(HANDLE hConsoleInput, CONST INPUT_RECORD *lpBuffer, DWORD nLength, LPDWORD lpNumberOfEventsWritten);
#define WriteConsoleInput __MINGW_NAME_AW(WriteConsoleInput)
  WINBASEAPI WINBOOL WINAPI ScrollConsoleScreenBufferA(HANDLE hConsoleOutput, CONST SMALL_RECT *lpScrollRectangle, CONST SMALL_RECT *lpClipRectangle, COORD dwDestinationOrigin, CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI ScrollConsoleScreenBufferW(HANDLE hConsoleOutput, CONST SMALL_RECT *lpScrollRectangle, CONST SMALL_RECT *lpClipRectangle, COORD dwDestinationOrigin, CONST CHAR_INFO *lpFill);
#define ScrollConsoleScreenBuffer __MINGW_NAME_AW(ScrollConsoleScreenBuffer)
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputA(HANDLE hConsoleOutput, CONST CHAR_INFO *lpBuffer, COORD dwBufferSize, COORD dwBufferCoord, PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputW(HANDLE hConsoleOutput, CONST CHAR_INFO *lpBuffer, COORD dwBufferSize, COORD dwBufferCoord, PSMALL_RECT lpWriteRegion);
#define WriteConsoleOutput __MINGW_NAME_AW(WriteConsoleOutput)
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputA(HANDLE hConsoleOutput, PCHAR_INFO lpBuffer, COORD dwBufferSize, COORD dwBufferCoord, PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputW(HANDLE hConsoleOutput, PCHAR_INFO lpBuffer, COORD dwBufferSize, COORD dwBufferCoord, PSMALL_RECT lpReadRegion);
#define ReadConsoleOutput __MINGW_NAME_AW(ReadConsoleOutput)
  WINBASEAPI DWORD   WINAPI GetConsoleTitleA(LPSTR lpConsoleTitle, DWORD nSize);
  WINBASEAPI DWORD   WINAPI GetConsoleTitleW(LPWSTR lpConsoleTitle, DWORD nSize);
#define GetConsoleTitle __MINGW_NAME_AW(GetConsoleTitle)
  WINBASEAPI DWORD   WINAPI GetConsoleOriginalTitleA(LPSTR lpConsoleTitle, DWORD nSize);
  WINBASEAPI DWORD   WINAPI GetConsoleOriginalTitleW(LPWSTR lpConsoleTitle, DWORD nSize);
#define GetConsoleOriginalTitle __MINGW_NAME_AW(GetConsoleOriginalTitle)
  WINBASEAPI WINBOOL WINAPI SetConsoleTitleA(LPCSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI SetConsoleTitleW(LPCWSTR lpConsoleTitle);
#define SetConsoleTitle __MINGW_NAME_AW(SetConsoleTitle)

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */

#ifdef __cplusplus
}
#endif

#endif  /* _APISETCONSOLEL2_ */
