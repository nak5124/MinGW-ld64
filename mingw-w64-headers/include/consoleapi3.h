/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _APISETCONSOLEL3_
#define _APISETCONSOLEL3_

#include <_mingw_unicode.h>
#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>
#include <minwinbase.h>

#include <wincontypes.h>
#include <windef.h>

#ifndef NOGDI
#include <wingdi.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

  WINBASEAPI WINBOOL WINAPI GetNumberOfConsoleMouseButtons(LPDWORD lpNumberOfMouseButtons);
  WINBASEAPI COORD   WINAPI GetConsoleFontSize(HANDLE hConsoleOutput, DWORD nFont);
  WINBASEAPI WINBOOL WINAPI GetCurrentConsoleFont(HANDLE hConsoleOutput, WINBOOL bMaximumWindow, PCONSOLE_FONT_INFO lpConsoleCurrentFont);

#ifndef NOGDI

  typedef struct _CONSOLE_FONT_INFOEX
  {
    ULONG cbSize;
    DWORD nFont;
    COORD dwFontSize;
    UINT  FontFamily;
    UINT  FontWeight;
    WCHAR FaceName[LF_FACESIZE];
  } CONSOLE_FONT_INFOEX, *PCONSOLE_FONT_INFOEX;

  WINBASEAPI WINBOOL WINAPI GetCurrentConsoleFontEx(HANDLE hConsoleOutput, WINBOOL bMaximumWindow, PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx);
  WINBASEAPI WINBOOL WINAPI SetCurrentConsoleFontEx(HANDLE hConsoleOutput, WINBOOL bMaximumWindow, PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx);

#endif  /* NOGDI */

#define CONSOLE_NO_SELECTION          0x0000
#define CONSOLE_SELECTION_IN_PROGRESS 0x0001
#define CONSOLE_SELECTION_NOT_EMPTY   0x0002
#define CONSOLE_MOUSE_SELECTION       0x0004
#define CONSOLE_MOUSE_DOWN            0x0008

  typedef struct _CONSOLE_SELECTION_INFO
  {
    DWORD      dwFlags;
    COORD      dwSelectionAnchor;
    SMALL_RECT srSelection;
  } CONSOLE_SELECTION_INFO, *PCONSOLE_SELECTION_INFO;

  WINBASEAPI WINBOOL WINAPI GetConsoleSelectionInfo(PCONSOLE_SELECTION_INFO lpConsoleSelectionInfo);

#define HISTORY_NO_DUP_FLAG 0x1

  typedef struct _CONSOLE_HISTORY_INFO
  {
    UINT  cbSize;
    UINT  HistoryBufferSize;
    UINT  NumberOfHistoryBuffers;
    DWORD dwFlags;
  } CONSOLE_HISTORY_INFO, *PCONSOLE_HISTORY_INFO;

  WINBASEAPI WINBOOL WINAPI GetConsoleHistoryInfo(PCONSOLE_HISTORY_INFO lpConsoleHistoryInfo);
  WINBASEAPI WINBOOL WINAPI SetConsoleHistoryInfo(PCONSOLE_HISTORY_INFO lpConsoleHistoryInfo);

#define CONSOLE_FULLSCREEN          1
#define CONSOLE_FULLSCREEN_HARDWARE 2

  WINBASEAPI WINBOOL APIENTRY GetConsoleDisplayMode(LPDWORD lpModeFlags);

#define CONSOLE_FULLSCREEN_MODE 1
#define CONSOLE_WINDOWED_MODE   2

  WINBASEAPI WINBOOL APIENTRY SetConsoleDisplayMode(HANDLE hConsoleOutput, DWORD dwFlags, PCOORD lpNewScreenBufferDimensions);
  WINBASEAPI HWND    APIENTRY GetConsoleWindow(VOID);
  WINBASEAPI WINBOOL APIENTRY AddConsoleAliasA(LPSTR Source, LPSTR Target, LPSTR ExeName);
  WINBASEAPI WINBOOL APIENTRY AddConsoleAliasW(LPWSTR Source, LPWSTR Target, LPWSTR ExeName);
#define AddConsoleAlias __MINGW_NAME_AW(AddConsoleAlias)
  WINBASEAPI DWORD   APIENTRY GetConsoleAliasA(LPSTR Source, LPSTR TargetBuffer, DWORD TargetBufferLength, LPSTR ExeName);
  WINBASEAPI DWORD   APIENTRY GetConsoleAliasW(LPWSTR Source, LPWSTR TargetBuffer, DWORD TargetBufferLength, LPWSTR ExeName);
#define GetConsoleAlias __MINGW_NAME_AW(GetConsoleAlias)
  WINBASEAPI DWORD   APIENTRY GetConsoleAliasesLengthA(LPSTR ExeName);
  WINBASEAPI DWORD   APIENTRY GetConsoleAliasesLengthW(LPWSTR ExeName);
#define GetConsoleAliasesLength __MINGW_NAME_AW(GetConsoleAliasesLength)
  WINBASEAPI DWORD   APIENTRY GetConsoleAliasExesLengthA(VOID);
  WINBASEAPI DWORD   APIENTRY GetConsoleAliasExesLengthW(VOID);
#define GetConsoleAliasExesLength __MINGW_NAME_AW(GetConsoleAliasExesLength)
  WINBASEAPI DWORD   APIENTRY GetConsoleAliasesA(LPSTR AliasBuffer, DWORD AliasBufferLength, LPSTR ExeName);
  WINBASEAPI DWORD   APIENTRY GetConsoleAliasesW(LPWSTR AliasBuffer, DWORD AliasBufferLength, LPWSTR ExeName);
#define GetConsoleAliases __MINGW_NAME_AW(GetConsoleAliases)
  WINBASEAPI DWORD   APIENTRY GetConsoleAliasExesA(LPSTR ExeNameBuffer, DWORD ExeNameBufferLength);
  WINBASEAPI DWORD   APIENTRY GetConsoleAliasExesW(LPWSTR ExeNameBuffer, DWORD ExeNameBufferLength);
#define GetConsoleAliasExes __MINGW_NAME_AW(GetConsoleAliasExes)
  WINBASEAPI VOID    APIENTRY ExpungeConsoleCommandHistoryA(LPSTR ExeName);
  WINBASEAPI VOID    APIENTRY ExpungeConsoleCommandHistoryW(LPWSTR ExeName);
#define ExpungeConsoleCommandHistory __MINGW_NAME_AW(ExpungeConsoleCommandHistory)
  WINBASEAPI WINBOOL APIENTRY SetConsoleNumberOfCommandsA(DWORD Number, LPSTR ExeName);
  WINBASEAPI WINBOOL APIENTRY SetConsoleNumberOfCommandsW(DWORD Number, LPWSTR ExeName);
#define SetConsoleNumberOfCommands __MINGW_NAME_AW(SetConsoleNumberOfCommands)
  WINBASEAPI DWORD   APIENTRY GetConsoleCommandHistoryLengthA(LPSTR ExeName);
  WINBASEAPI DWORD   APIENTRY GetConsoleCommandHistoryLengthW(LPWSTR ExeName);
#define GetConsoleCommandHistoryLength __MINGW_NAME_AW(GetConsoleCommandHistoryLength)
  WINBASEAPI DWORD   APIENTRY GetConsoleCommandHistoryA(LPSTR Commands, DWORD CommandBufferLength, LPSTR ExeName);
  WINBASEAPI DWORD   APIENTRY GetConsoleCommandHistoryW(LPWSTR Commands, DWORD CommandBufferLength, LPWSTR ExeName);
#define GetConsoleCommandHistory __MINGW_NAME_AW(GetConsoleCommandHistory)
  WINBASEAPI DWORD   APIENTRY GetConsoleProcessList(LPDWORD lpdwProcessList, DWORD dwProcessCount);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */

#ifdef __cplusplus
}
#endif

#endif  /* _APISETCONSOLEL3_ */
