/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _MDBROLE_HXX_
#define _MDBROLE_HXX_

#ifndef WINAPI
#define WINAPI __stdcall
#endif

#ifdef FASTCALL_IN_STORE
#define __FORCENONFASTCALL WINAPI
#else
#define __FORCENONFASTCALL
#endif

#define ROLDLLEXP __declspec(dllimport)

#define ROLEAPI

WINBOOL ROLDLLEXP ROLEAPI FRoleSid(PSID psid);
HRESULT ROLDLLEXP ROLEAPI HrParseRoleSid(PSID psid,long cbNameBuffer,char rgchName[],ULONG *pptagrole,BYTE *prolescope);
HRESULT ROLDLLEXP ROLEAPI HrConstructRoleSid(char *szRoleName,BYTE rolescope,ULONG ptagrole,PSID *ppsid);
void ROLDLLEXP ROLEAPI FreeRoleSid(PSID psid);
WINBOOL ROLDLLEXP ROLEAPI FCanonicalAcl(PACL pacl);
WINBOOL ROLDLLEXP ROLEAPI FCanonicalAcl(PSECURITY_DESCRIPTOR pntsd);

#endif
