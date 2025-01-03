#include <winapifamily.h>
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_DDEMLH
#define _INC_DDEMLH

#include <_mingw_unicode.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

  DECLARE_HANDLE(HCONVLIST);
  DECLARE_HANDLE(HCONV);
  DECLARE_HANDLE(HSZ);
  DECLARE_HANDLE(HDDEDATA);
#define EXPENTRY CALLBACK

  typedef struct tagHSZPAIR
  {
    HSZ hszSvc;
    HSZ hszTopic;
  } HSZPAIR, *PHSZPAIR;

  typedef struct tagCONVCONTEXT
  {
    UINT                        cb;
    UINT                        wFlags;
    UINT                        wCountryID;
    int                         iCodePage;
    DWORD                       dwLangID;
    DWORD                       dwSecurity;
    SECURITY_QUALITY_OF_SERVICE qos;
  } CONVCONTEXT, *PCONVCONTEXT;

  typedef struct tagCONVINFO
  {
    DWORD       cb;
    DWORD_PTR   hUser;
    HCONV       hConvPartner;
    HSZ         hszSvcPartner;
    HSZ         hszServiceReq;
    HSZ         hszTopic;
    HSZ         hszItem;
    UINT        wFmt;
    UINT        wType;
    UINT        wStatus;
    UINT        wConvst;
    UINT        wLastError;
    HCONVLIST   hConvList;
    CONVCONTEXT ConvCtxt;
    HWND        hwnd;
    HWND        hwndPartner;
  } CONVINFO, *PCONVINFO;

#define XST_NULL           0
#define XST_INCOMPLETE     1
#define XST_CONNECTED      2
#define XST_INIT1          3
#define XST_INIT2          4
#define XST_REQSENT        5
#define XST_DATARCVD       6
#define XST_POKESENT       7
#define XST_POKEACKRCVD    8
#define XST_EXECSENT       9
#define XST_EXECACKRCVD    10
#define XST_ADVSENT        11
#define XST_UNADVSENT      12
#define XST_ADVACKRCVD     13
#define XST_UNADVACKRCVD   14
#define XST_ADVDATASENT    15
#define XST_ADVDATAACKRCVD 16

#define CADV_LATEACK 0xFFFF

#define ST_CONNECTED  0x0001
#define ST_ADVISE     0x0002
#define ST_ISLOCAL    0x0004
#define ST_BLOCKED    0x0008
#define ST_CLIENT     0x0010
#define ST_TERMINATED 0x0020
#define ST_INLIST     0x0040
#define ST_BLOCKNEXT  0x0080
#define ST_ISSELF     0x0100

#define DDE_FACK          0x8000
#define DDE_FBUSY         0x4000
#define DDE_FDEFERUPD     0x4000
#define DDE_FACKREQ       0x8000
#define DDE_FRELEASE      0x2000
#define DDE_FREQUESTED    0x1000
#define DDE_FAPPSTATUS    0x00ff
#define DDE_FNOTPROCESSED 0x0000
#define DDE_FACKRESERVED  (~(DDE_FACK | DDE_FBUSY | DDE_FAPPSTATUS))
#define DDE_FADVRESERVED  (~(DDE_FACKREQ | DDE_FDEFERUPD))
#define DDE_FDATRESERVED  (~(DDE_FACKREQ | DDE_FRELEASE | DDE_FREQUESTED))
#define DDE_FPOKRESERVED  (~(DDE_FRELEASE))

#define MSGF_DDEMGR 0x8001

#define CP_WINANSI    1004
#define CP_WINUNICODE 1200
#ifdef UNICODE
# define CP_WINNEUTRAL CP_WINUNICODE
#else
# define CP_WINNEUTRAL CP_WINANSI
#endif

#define XTYPF_NOBLOCK 0x0002
#define XTYPF_NODATA  0x0004
#define XTYPF_ACKREQ  0x0008

#define XCLASS_MASK         0xFC00
#define XCLASS_BOOL         0x1000
#define XCLASS_DATA         0x2000
#define XCLASS_FLAGS        0x4000
#define XCLASS_NOTIFICATION 0x8000

#define XTYP_ERROR           (0x0000 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#define XTYP_ADVDATA         (0x0010 | XCLASS_FLAGS)
#define XTYP_ADVREQ          (0x0020 | XCLASS_DATA | XTYPF_NOBLOCK)
#define XTYP_ADVSTART        (0x0030 | XCLASS_BOOL)
#define XTYP_ADVSTOP         (0x0040 | XCLASS_NOTIFICATION)
#define XTYP_EXECUTE         (0x0050 | XCLASS_FLAGS)
#define XTYP_CONNECT         (0x0060 | XCLASS_BOOL | XTYPF_NOBLOCK)
#define XTYP_CONNECT_CONFIRM (0x0070 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#define XTYP_XACT_COMPLETE   (0x0080 | XCLASS_NOTIFICATION)
#define XTYP_POKE            (0x0090 | XCLASS_FLAGS)
#define XTYP_REGISTER        (0x00A0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#define XTYP_REQUEST         (0x00B0 | XCLASS_DATA)
#define XTYP_DISCONNECT      (0x00C0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#define XTYP_UNREGISTER      (0x00D0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#define XTYP_WILDCONNECT     (0x00E0 | XCLASS_DATA | XTYPF_NOBLOCK)
#define XTYP_MASK            0x00F0
#define XTYP_SHIFT           4

#define TIMEOUT_ASYNC 0xFFFFFFFF

#define QID_SYNC 0xFFFFFFFF

#define SZDDESYS_TOPIC         __MINGW_STRING_AW("System")
#define SZDDESYS_ITEM_TOPICS   __MINGW_STRING_AW("Topics")
#define SZDDESYS_ITEM_SYSITEMS __MINGW_STRING_AW("SysItems")
#define SZDDESYS_ITEM_RTNMSG   __MINGW_STRING_AW("ReturnMessage")
#define SZDDESYS_ITEM_STATUS   __MINGW_STRING_AW("Status")
#define SZDDESYS_ITEM_FORMATS  __MINGW_STRING_AW("Formats")
#define SZDDESYS_ITEM_HELP     __MINGW_STRING_AW("Help")
#define SZDDE_ITEM_ITEMLIST    __MINGW_STRING_AW("TopicItemList")

  typedef HDDEDATA (CALLBACK FNCALLBACK)(UINT wType, UINT wFmt, HCONV hConv, HSZ hsz1, HSZ hsz2, HDDEDATA hData, ULONG_PTR dwData1, ULONG_PTR dwData2);
  typedef HDDEDATA (CALLBACK *PFNCALLBACK)(UINT wType, UINT wFmt, HCONV hConv, HSZ hsz1, HSZ hsz2, HDDEDATA hData, ULONG_PTR dwData1, ULONG_PTR dwData2);

#define CBR_BLOCK ((HDDEDATA)-1)

  UINT WINAPI DdeInitializeA(LPDWORD pidInst, PFNCALLBACK pfnCallback, DWORD afCmd, DWORD ulRes);
  UINT WINAPI DdeInitializeW(LPDWORD pidInst, PFNCALLBACK pfnCallback, DWORD afCmd, DWORD ulRes);
#define DdeInitialize __MINGW_NAME_AW(DdeInitialize)

#define CBF_FAIL_SELFCONNECTIONS 0x00001000
#define CBF_FAIL_CONNECTIONS     0x00002000
#define CBF_FAIL_ADVISES         0x00004000
#define CBF_FAIL_EXECUTES        0x00008000
#define CBF_FAIL_POKES           0x00010000
#define CBF_FAIL_REQUESTS        0x00020000
#define CBF_FAIL_ALLSVRXACTIONS  0x0003f000

#define CBF_SKIP_CONNECT_CONFIRMS 0x00040000
#define CBF_SKIP_REGISTRATIONS    0x00080000
#define CBF_SKIP_UNREGISTRATIONS  0x00100000
#define CBF_SKIP_DISCONNECTS      0x00200000
#define CBF_SKIP_ALLNOTIFICATIONS 0x003c0000

#define APPCMD_CLIENTONLY  0x00000010L
#define APPCMD_FILTERINITS 0x00000020L
#define APPCMD_MASK        0x00000FF0L

#define APPCLASS_STANDARD 0x00000000L
#define APPCLASS_MASK     0x0000000FL

  WINBOOL   WINAPI DdeUninitialize(DWORD idInst);
  HCONVLIST WINAPI DdeConnectList(DWORD idInst, HSZ hszService, HSZ hszTopic, HCONVLIST hConvList, PCONVCONTEXT pCC);
  HCONV     WINAPI DdeQueryNextServer(HCONVLIST hConvList, HCONV hConvPrev);
  WINBOOL   WINAPI DdeDisconnectList(HCONVLIST hConvList);
  HCONV     WINAPI DdeConnect(DWORD idInst, HSZ hszService, HSZ hszTopic, PCONVCONTEXT pCC);
  WINBOOL   WINAPI DdeDisconnect(HCONV hConv);
  HCONV     WINAPI DdeReconnect(HCONV hConv);
  UINT      WINAPI DdeQueryConvInfo(HCONV hConv, DWORD idTransaction, PCONVINFO pConvInfo);
  WINBOOL   WINAPI DdeSetUserHandle(HCONV hConv, DWORD id, DWORD_PTR hUser);
  WINBOOL   WINAPI DdeAbandonTransaction(DWORD idInst, HCONV hConv, DWORD idTransaction);
  WINBOOL   WINAPI DdePostAdvise(DWORD idInst, HSZ hszTopic, HSZ hszItem);
  WINBOOL   WINAPI DdeEnableCallback(DWORD idInst, HCONV hConv, UINT wCmd);
  WINBOOL   WINAPI DdeImpersonateClient(HCONV hConv);

#define EC_ENABLEALL    0
#define EC_ENABLEONE    ST_BLOCKNEXT
#define EC_DISABLE      ST_BLOCKED
#define EC_QUERYWAITING 2

  HDDEDATA WINAPI DdeNameService(DWORD idInst, HSZ hsz1, HSZ hsz2, UINT afCmd);

#define DNS_REGISTER   0x0001
#define DNS_UNREGISTER 0x0002
#define DNS_FILTERON   0x0004
#define DNS_FILTEROFF  0x0008

  HDDEDATA WINAPI DdeClientTransaction(LPBYTE pData, DWORD cbData, HCONV hConv, HSZ hszItem, UINT wFmt, UINT wType, DWORD dwTimeout, LPDWORD pdwResult);
  HDDEDATA WINAPI DdeCreateDataHandle(DWORD idInst, LPBYTE pSrc, DWORD cb, DWORD cbOff, HSZ hszItem, UINT wFmt, UINT afCmd);
  HDDEDATA WINAPI DdeAddData(HDDEDATA hData, LPBYTE pSrc, DWORD cb, DWORD cbOff);
  DWORD    WINAPI DdeGetData(HDDEDATA hData, LPBYTE pDst, DWORD cbMax, DWORD cbOff);
  LPBYTE   WINAPI DdeAccessData(HDDEDATA hData, LPDWORD pcbDataSize);
  WINBOOL  WINAPI DdeUnaccessData(HDDEDATA hData);
  WINBOOL  WINAPI DdeFreeDataHandle(HDDEDATA hData);

#define HDATA_APPOWNED 0x0001

  UINT WINAPI DdeGetLastError(DWORD idInst);

#define DMLERR_NO_ERROR            0
#define DMLERR_FIRST               0x4000
#define DMLERR_ADVACKTIMEOUT       0x4000
#define DMLERR_BUSY                0x4001
#define DMLERR_DATAACKTIMEOUT      0x4002
#define DMLERR_DLL_NOT_INITIALIZED 0x4003
#define DMLERR_DLL_USAGE           0x4004
#define DMLERR_EXECACKTIMEOUT      0x4005
#define DMLERR_INVALIDPARAMETER    0x4006
#define DMLERR_LOW_MEMORY          0x4007
#define DMLERR_MEMORY_ERROR        0x4008
#define DMLERR_NOTPROCESSED        0x4009
#define DMLERR_NO_CONV_ESTABLISHED 0x400a
#define DMLERR_POKEACKTIMEOUT      0x400b
#define DMLERR_POSTMSG_FAILED      0x400c
#define DMLERR_REENTRANCY          0x400d
#define DMLERR_SERVER_DIED         0x400e
#define DMLERR_SYS_ERROR           0x400f
#define DMLERR_UNADVACKTIMEOUT     0x4010
#define DMLERR_UNFOUND_QUEUE_ID    0x4011
#define DMLERR_LAST                0x4011

  HSZ     WINAPI DdeCreateStringHandleA(DWORD idInst, LPCSTR psz, int iCodePage);
  HSZ     WINAPI DdeCreateStringHandleW(DWORD idInst, LPCWSTR psz, int iCodePage);
#define DdeCreateStringHandle __MINGW_NAME_AW(DdeCreateStringHandle)
  DWORD   WINAPI DdeQueryStringA(DWORD idInst, HSZ hsz, LPSTR psz, DWORD cchMax, int iCodePage);
  DWORD   WINAPI DdeQueryStringW(DWORD idInst, HSZ hsz, LPWSTR psz, DWORD cchMax, int iCodePage);
#define DdeQueryString __MINGW_NAME_AW(DdeQueryString)
  WINBOOL WINAPI DdeFreeStringHandle(DWORD idInst, HSZ hsz);
  WINBOOL WINAPI DdeKeepStringHandle(DWORD idInst, HSZ hsz);
  int     WINAPI DdeCmpStringHandles(HSZ hsz1, HSZ hsz2);

#ifndef NODDEMLSPY

  typedef struct tagDDEML_MSG_HOOK_DATA
  {
    UINT_PTR uiLo;
    UINT_PTR uiHi;
    DWORD    cbData;
    DWORD    Data[8];
  } DDEML_MSG_HOOK_DATA, *PDDEML_MSG_HOOK_DATA;

  typedef struct tagMONMSGSTRUCT
  {
    UINT                cb;
    HWND                hwndTo;
    DWORD               dwTime;
    HANDLE              hTask;
    UINT                wMsg;
    WPARAM              wParam;
    LPARAM              lParam;
    DDEML_MSG_HOOK_DATA dmhd;
  } MONMSGSTRUCT, *PMONMSGSTRUCT;

  typedef struct tagMONCBSTRUCT
  {
    UINT        cb;
    DWORD       dwTime;
    HANDLE      hTask;
    DWORD       dwRet;
    UINT        wType;
    UINT        wFmt;
    HCONV       hConv;
    HSZ         hsz1;
    HSZ         hsz2;
    HDDEDATA    hData;
    ULONG_PTR   dwData1;
    ULONG_PTR   dwData2;
    CONVCONTEXT cc;
    DWORD       cbData;
    DWORD       Data[8];
  } MONCBSTRUCT, *PMONCBSTRUCT;

  typedef struct tagMONHSZSTRUCTA
  {
    UINT    cb;
    WINBOOL fsAction;
    DWORD   dwTime;
    HSZ     hsz;
    HANDLE  hTask;
    CHAR    str[1];
  } MONHSZSTRUCTA, *PMONHSZSTRUCTA;

  typedef struct tagMONHSZSTRUCTW
  {
    UINT    cb;
    WINBOOL fsAction;
    DWORD   dwTime;
    HSZ     hsz;
    HANDLE  hTask;
    WCHAR   str[1];
  } MONHSZSTRUCTW, *PMONHSZSTRUCTW;

  __MINGW_TYPEDEF_AW(MONHSZSTRUCT)
  __MINGW_TYPEDEF_AW(PMONHSZSTRUCT)

#define MH_CREATE  1
#define MH_KEEP    2
#define MH_DELETE  3
#define MH_CLEANUP 4

  typedef struct tagMONERRSTRUCT
  {
    UINT   cb;
    UINT   wLastError;
    DWORD  dwTime;
    HANDLE hTask;
  } MONERRSTRUCT, *PMONERRSTRUCT;

  typedef struct tagMONLINKSTRUCT
  {
    UINT    cb;
    DWORD   dwTime;
    HANDLE  hTask;
    WINBOOL fEstablished;
    WINBOOL fNoData;
    HSZ     hszSvc;
    HSZ     hszTopic;
    HSZ     hszItem;
    UINT    wFmt;
    WINBOOL fServer;
    HCONV   hConvServer;
    HCONV   hConvClient;
  } MONLINKSTRUCT, *PMONLINKSTRUCT;

  typedef struct tagMONCONVSTRUCT
  {
    UINT    cb;
    WINBOOL fConnect;
    DWORD   dwTime;
    HANDLE  hTask;
    HSZ     hszSvc;
    HSZ     hszTopic;
    HCONV   hConvClient;
    HCONV   hConvServer;
  } MONCONVSTRUCT, *PMONCONVSTRUCT;

#define MAX_MONITORS     4
#define APPCLASS_MONITOR 0x00000001L
#define XTYP_MONITOR     (0x00F0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)

#define MF_HSZ_INFO  0x01000000
#define MF_SENDMSGS  0x02000000
#define MF_POSTMSGS  0x04000000
#define MF_CALLBACKS 0x08000000
#define MF_ERRORS    0x10000000
#define MF_LINKS     0x20000000
#define MF_CONV      0x40000000
#define MF_MASK      0xFF000000

#endif  /* NODDEMLSPY */

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */

#ifdef __cplusplus
}
#endif

#endif  /* _INC_DDEMLH */
