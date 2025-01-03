#include <winapifamily.h>
/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ifndef _INC_OLE
#define _INC_OLE

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WINAPI
# define WINAPI   PASCAL
# define CALLBACK PASCAL
# define LPCSTR   LPSTR
# define LRESULT  LONG_PTR
# define HGLOBAL  HANDLE
#endif

#ifdef STRICT
# define OLE_LPCSTR LPCSTR
# define OLE_CONST  const
#else
# define OLE_LPCSTR LPSTR
# define OLE_CONST
#endif

#define LRESULT LONG_PTR
#define HGLOBAL HANDLE

#define OT_LINK     1L
#define OT_EMBEDDED 2L
#define OT_STATIC   3L

#define OLEVERB_PRIMARY 0

  typedef struct _OLETARGETDEVICE
  {
    USHORT otdDeviceNameOffset;
    USHORT otdDriverNameOffset;
    USHORT otdPortNameOffset;
    USHORT otdExtDevmodeOffset;
    USHORT otdExtDevmodeSize;
    USHORT otdEnvironmentOffset;
    USHORT otdEnvironmentSize;
    BYTE   otdData[1];
  } OLETARGETDEVICE;
  typedef OLETARGETDEVICE *LPOLETARGETDEVICE;

#define OF_SET     0x0001
#define OF_GET     0x0002
#define OF_HANDLER 0x0004

  typedef enum
  {
    OLE_OK,
    OLE_WAIT_FOR_RELEASE,
    OLE_BUSY,
    OLE_ERROR_PROTECT_ONLY,
    OLE_ERROR_MEMORY,
    OLE_ERROR_STREAM,
    OLE_ERROR_STATIC,
    OLE_ERROR_BLANK,
    OLE_ERROR_DRAW,
    OLE_ERROR_METAFILE,
    OLE_ERROR_ABORT,
    OLE_ERROR_CLIPBOARD,
    OLE_ERROR_FORMAT,
    OLE_ERROR_OBJECT,
    OLE_ERROR_OPTION,
    OLE_ERROR_PROTOCOL,
    OLE_ERROR_ADDRESS,
    OLE_ERROR_NOT_EQUAL,
    OLE_ERROR_HANDLE,
    OLE_ERROR_GENERIC,
    OLE_ERROR_CLASS,
    OLE_ERROR_SYNTAX,
    OLE_ERROR_DATATYPE,
    OLE_ERROR_PALETTE,
    OLE_ERROR_NOT_LINK,
    OLE_ERROR_NOT_EMPTY,
    OLE_ERROR_SIZE,
    OLE_ERROR_DRIVE,
    OLE_ERROR_NETWORK,
    OLE_ERROR_NAME,
    OLE_ERROR_TEMPLATE,
    OLE_ERROR_NEW,
    OLE_ERROR_EDIT,
    OLE_ERROR_OPEN,
    OLE_ERROR_NOT_OPEN,
    OLE_ERROR_LAUNCH,
    OLE_ERROR_COMM,
    OLE_ERROR_TERMINATE,
    OLE_ERROR_COMMAND,
    OLE_ERROR_SHOW,
    OLE_ERROR_DOVERB,
    OLE_ERROR_ADVISE_NATIVE,
    OLE_ERROR_ADVISE_PICT,
    OLE_ERROR_ADVISE_RENAME,
    OLE_ERROR_POKE_NATIVE,
    OLE_ERROR_REQUEST_NATIVE,
    OLE_ERROR_REQUEST_PICT,
    OLE_ERROR_SERVER_BLOCKED,
    OLE_ERROR_REGISTRATION,
    OLE_ERROR_ALREADY_REGISTERED,
    OLE_ERROR_TASK,
    OLE_ERROR_OUTOFDATE,
    OLE_ERROR_CANT_UPDATE_CLIENT,
    OLE_ERROR_UPDATE,
    OLE_ERROR_SETDATA_FORMAT,
    OLE_ERROR_STATIC_FROM_OTHER_OS,
    OLE_ERROR_FILE_VER,
    OLE_WARN_DELETE_DATA = 1000
  } OLESTATUS;

  typedef enum
  {
    OLE_CHANGED,
    OLE_SAVED,
    OLE_CLOSED,
    OLE_RENAMED,
    OLE_QUERY_PAINT,
    OLE_RELEASE,
    OLE_QUERY_RETRY
  } OLE_NOTIFICATION;

  typedef enum
  {
    OLE_NONE,
    OLE_DELETE,
    OLE_LNKPASTE,
    OLE_EMBPASTE,
    OLE_SHOW,
    OLE_RUN,
    OLE_ACTIVATE,
    OLE_UPDATE,
    OLE_CLOSE,
    OLE_RECONNECT,
    OLE_SETUPDATEOPTIONS,
    OLE_SERVERUNLAUNCH,
    OLE_LOADFROMSTREAM,
    OLE_SETDATA,
    OLE_REQUESTDATA,
    OLE_OTHER,
    OLE_CREATE,
    OLE_CREATEFROMTEMPLATE,
    OLE_CREATELINKFROMFILE,
    OLE_COPYFROMLNK,
    OLE_CREATEFROMFILE,
    OLE_CREATEINVISIBLE
  } OLE_RELEASE_METHOD;

  typedef enum
  {
    olerender_none,
    olerender_draw,
    olerender_format
  } OLEOPT_RENDER;

  typedef WORD OLECLIPFORMAT;

  typedef enum
  {
    oleupdate_always,
    oleupdate_onsave,
#ifdef OLE_INTERNAL
    oleupdate_oncall,
    oleupdate_onclose
#else
    oleupdate_oncall
#endif
  } OLEOPT_UPDATE;

  typedef HANDLE   HOBJECT;
  typedef LONG_PTR LHSERVER;
  typedef LONG_PTR LHCLIENTDOC;
  typedef LONG_PTR LHSERVERDOC;

  typedef struct _OLEOBJECT *LPOLEOBJECT;
  typedef struct _OLESTREAM *LPOLESTREAM;
  typedef struct _OLECLIENT *LPOLECLIENT;

  typedef struct _OLEOBJECTVTBL
  {
    void         *(CALLBACK *QueryProtocol)(LPOLEOBJECT, OLE_LPCSTR);
    OLESTATUS     (CALLBACK *Release)(LPOLEOBJECT);
    OLESTATUS     (CALLBACK *Show)(LPOLEOBJECT, WINBOOL);
    OLESTATUS     (CALLBACK *DoVerb)(LPOLEOBJECT, UINT, WINBOOL, WINBOOL);
    OLESTATUS     (CALLBACK *GetData)(LPOLEOBJECT, OLECLIPFORMAT, HANDLE *);
    OLESTATUS     (CALLBACK *SetData)(LPOLEOBJECT, OLECLIPFORMAT, HANDLE);
    OLESTATUS     (CALLBACK *SetTargetDevice)(LPOLEOBJECT, HGLOBAL);
    OLESTATUS     (CALLBACK *SetBounds)(LPOLEOBJECT, OLE_CONST RECT *);
    OLECLIPFORMAT (CALLBACK *EnumFormats)(LPOLEOBJECT, OLECLIPFORMAT);
    OLESTATUS     (CALLBACK *SetColorScheme)(LPOLEOBJECT, OLE_CONST LOGPALETTE *);
#ifndef SERVERONLY
    OLESTATUS          (CALLBACK *Delete)(LPOLEOBJECT);
    OLESTATUS          (CALLBACK *SetHostNames)(LPOLEOBJECT, OLE_LPCSTR, OLE_LPCSTR);
    OLESTATUS          (CALLBACK *SaveToStream)(LPOLEOBJECT, LPOLESTREAM);
    OLESTATUS          (CALLBACK *Clone)(LPOLEOBJECT, LPOLECLIENT, LHCLIENTDOC, OLE_LPCSTR, LPOLEOBJECT *);
    OLESTATUS          (CALLBACK *CopyFromLink)(LPOLEOBJECT, LPOLECLIENT, LHCLIENTDOC, OLE_LPCSTR, LPOLEOBJECT *);
    OLESTATUS          (CALLBACK *Equal)(LPOLEOBJECT, LPOLEOBJECT);
    OLESTATUS          (CALLBACK *CopyToClipboard)(LPOLEOBJECT);
    OLESTATUS          (CALLBACK *Draw)(LPOLEOBJECT, HDC, OLE_CONST RECT *, OLE_CONST RECT *, HDC);
    OLESTATUS          (CALLBACK *Activate)(LPOLEOBJECT, UINT, WINBOOL, WINBOOL, HWND, OLE_CONST RECT *);
    OLESTATUS          (CALLBACK *Execute)(LPOLEOBJECT, HGLOBAL, UINT);
    OLESTATUS          (CALLBACK *Close)(LPOLEOBJECT);
    OLESTATUS          (CALLBACK *Update)(LPOLEOBJECT);
    OLESTATUS          (CALLBACK *Reconnect)(LPOLEOBJECT);
    OLESTATUS          (CALLBACK *ObjectConvert)(LPOLEOBJECT, OLE_LPCSTR, LPOLECLIENT, LHCLIENTDOC, OLE_LPCSTR, LPOLEOBJECT *);
    OLESTATUS          (CALLBACK *GetLinkUpdateOptions)(LPOLEOBJECT, OLEOPT_UPDATE *);
    OLESTATUS          (CALLBACK *SetLinkUpdateOptions)(LPOLEOBJECT, OLEOPT_UPDATE);
    OLESTATUS          (CALLBACK *Rename)(LPOLEOBJECT, OLE_LPCSTR);
    OLESTATUS          (CALLBACK *QueryName)(LPOLEOBJECT, LPSTR, UINT *);
    OLESTATUS          (CALLBACK *QueryType)(LPOLEOBJECT, LONG *);
    OLESTATUS          (CALLBACK *QueryBounds)(LPOLEOBJECT, RECT *);
    OLESTATUS          (CALLBACK *QuerySize)(LPOLEOBJECT, DWORD *);
    OLESTATUS          (CALLBACK *QueryOpen)(LPOLEOBJECT);
    OLESTATUS          (CALLBACK *QueryOutOfDate)(LPOLEOBJECT);
    OLESTATUS          (CALLBACK *QueryReleaseStatus)(LPOLEOBJECT);
    OLESTATUS          (CALLBACK *QueryReleaseError)(LPOLEOBJECT);
    OLE_RELEASE_METHOD (CALLBACK *QueryReleaseMethod)(LPOLEOBJECT);
    OLESTATUS          (CALLBACK *RequestData)(LPOLEOBJECT, OLECLIPFORMAT);
    OLESTATUS          (CALLBACK *ObjectLong)(LPOLEOBJECT, UINT, LONG *);
    OLESTATUS          (CALLBACK *ChangeData)(LPOLEOBJECT, HANDLE, LPOLECLIENT, WINBOOL);
#endif
  } OLEOBJECTVTBL;
  typedef OLEOBJECTVTBL *LPOLEOBJECTVTBL;

#ifndef OLE_INTERNAL
  typedef struct _OLEOBJECT
  {
    LPOLEOBJECTVTBL lpvtbl;
  } OLEOBJECT;
#endif

  typedef struct _OLECLIENTVTBL
  {
    int (CALLBACK *CallBack)(LPOLECLIENT, OLE_NOTIFICATION, LPOLEOBJECT);
  } OLECLIENTVTBL;
  typedef OLECLIENTVTBL *LPOLECLIENTVTBL;

  typedef struct _OLECLIENT
  {
    LPOLECLIENTVTBL lpvtbl;
  } OLECLIENT;

  typedef struct _OLESTREAMVTBL
  {
    DWORD (CALLBACK *Get)(LPOLESTREAM, void *, DWORD);
    DWORD (CALLBACK *Put)(LPOLESTREAM, OLE_CONST void *, DWORD);
  } OLESTREAMVTBL;
  typedef OLESTREAMVTBL *LPOLESTREAMVTBL;

  typedef struct _OLESTREAM
  {
    LPOLESTREAMVTBL lpstbl;
  } OLESTREAM;

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

  OLESTATUS          WINAPI OleDelete(LPOLEOBJECT);
  OLESTATUS          WINAPI OleRelease(LPOLEOBJECT);
  OLESTATUS          WINAPI OleSaveToStream(LPOLEOBJECT, LPOLESTREAM);
  OLESTATUS          WINAPI OleEqual(LPOLEOBJECT, LPOLEOBJECT);
  OLESTATUS          WINAPI OleCopyToClipboard(LPOLEOBJECT);
  OLESTATUS          WINAPI OleSetHostNames(LPOLEOBJECT, LPCSTR, LPCSTR);
  OLESTATUS          WINAPI OleSetTargetDevice(LPOLEOBJECT, HGLOBAL);
  OLESTATUS          WINAPI OleSetBounds(LPOLEOBJECT, const RECT *);
  OLESTATUS          WINAPI OleSetColorScheme(LPOLEOBJECT, const LOGPALETTE *);
  OLESTATUS          WINAPI OleQueryBounds(LPOLEOBJECT, RECT *);
  OLESTATUS          WINAPI OleQuerySize(LPOLEOBJECT, DWORD *);
  OLESTATUS          WINAPI OleDraw(LPOLEOBJECT, HDC, const RECT *, const RECT *, HDC);
  OLESTATUS          WINAPI OleQueryOpen(LPOLEOBJECT);
  OLESTATUS          WINAPI OleActivate(LPOLEOBJECT, UINT, WINBOOL, WINBOOL, HWND, const RECT *);
  OLESTATUS          WINAPI OleExecute(LPOLEOBJECT, HGLOBAL, UINT);
  OLESTATUS          WINAPI OleClose(LPOLEOBJECT);
  OLESTATUS          WINAPI OleUpdate(LPOLEOBJECT);
  OLESTATUS          WINAPI OleReconnect(LPOLEOBJECT);
  OLESTATUS          WINAPI OleGetLinkUpdateOptions(LPOLEOBJECT, OLEOPT_UPDATE *);
  OLESTATUS          WINAPI OleSetLinkUpdateOptions(LPOLEOBJECT, OLEOPT_UPDATE);
  void              *WINAPI OleQueryProtocol(LPOLEOBJECT, LPCSTR);
  OLESTATUS          WINAPI OleQueryReleaseStatus(LPOLEOBJECT);
  OLESTATUS          WINAPI OleQueryReleaseError(LPOLEOBJECT);
  OLE_RELEASE_METHOD WINAPI OleQueryReleaseMethod(LPOLEOBJECT);
  OLESTATUS          WINAPI OleQueryType(LPOLEOBJECT, LONG *);
  DWORD              WINAPI OleQueryClientVersion(void);
  DWORD              WINAPI OleQueryServerVersion(void);
  OLECLIPFORMAT      WINAPI OleEnumFormats(LPOLEOBJECT, OLECLIPFORMAT);
  OLESTATUS          WINAPI OleGetData(LPOLEOBJECT, OLECLIPFORMAT, HANDLE *);
  OLESTATUS          WINAPI OleSetData(LPOLEOBJECT, OLECLIPFORMAT, HANDLE);
  OLESTATUS          WINAPI OleQueryOutOfDate(LPOLEOBJECT);
  OLESTATUS          WINAPI OleRequestData(LPOLEOBJECT, OLECLIPFORMAT);
  OLESTATUS          WINAPI OleQueryLinkFromClip(LPCSTR, OLEOPT_RENDER, OLECLIPFORMAT);
  OLESTATUS          WINAPI OleQueryCreateFromClip(LPCSTR, OLEOPT_RENDER, OLECLIPFORMAT);
  OLESTATUS          WINAPI OleCreateFromClip(LPCSTR, LPOLECLIENT, LHCLIENTDOC, LPCSTR, LPOLEOBJECT *, OLEOPT_RENDER, OLECLIPFORMAT);
  OLESTATUS          WINAPI OleCreateLinkFromClip(LPCSTR, LPOLECLIENT, LHCLIENTDOC, LPCSTR, LPOLEOBJECT *, OLEOPT_RENDER, OLECLIPFORMAT);
  OLESTATUS          WINAPI OleCreateFromFile(LPCSTR, LPOLECLIENT, LPCSTR, LPCSTR, LHCLIENTDOC, LPCSTR, LPOLEOBJECT *, OLEOPT_RENDER, OLECLIPFORMAT);
  OLESTATUS          WINAPI OleCreateLinkFromFile(LPCSTR, LPOLECLIENT, LPCSTR, LPCSTR, LPCSTR, LHCLIENTDOC, LPCSTR, LPOLEOBJECT *, OLEOPT_RENDER, OLECLIPFORMAT);
  OLESTATUS          WINAPI OleLoadFromStream(LPOLESTREAM, LPCSTR, LPOLECLIENT, LHCLIENTDOC, LPCSTR, LPOLEOBJECT *);
  OLESTATUS          WINAPI OleCreate(LPCSTR, LPOLECLIENT, LPCSTR, LHCLIENTDOC, LPCSTR, LPOLEOBJECT *, OLEOPT_RENDER, OLECLIPFORMAT);
  OLESTATUS          WINAPI OleCreateInvisible(LPCSTR, LPOLECLIENT, LPCSTR, LHCLIENTDOC, LPCSTR, LPOLEOBJECT *, OLEOPT_RENDER, OLECLIPFORMAT, WINBOOL);
  OLESTATUS          WINAPI OleCreateFromTemplate(LPCSTR, LPOLECLIENT, LPCSTR, LHCLIENTDOC, LPCSTR, LPOLEOBJECT *, OLEOPT_RENDER, OLECLIPFORMAT);
  OLESTATUS          WINAPI OleClone(LPOLEOBJECT, LPOLECLIENT, LHCLIENTDOC, LPCSTR, LPOLEOBJECT *);
  OLESTATUS          WINAPI OleCopyFromLink(LPOLEOBJECT, LPCSTR, LPOLECLIENT, LHCLIENTDOC, LPCSTR, LPOLEOBJECT *);
  OLESTATUS          WINAPI OleObjectConvert(LPOLEOBJECT, LPCSTR, LPOLECLIENT, LHCLIENTDOC, LPCSTR, LPOLEOBJECT *);
  OLESTATUS          WINAPI OleRename(LPOLEOBJECT, LPCSTR);
  OLESTATUS          WINAPI OleQueryName(LPOLEOBJECT lpobj, LPSTR lpBuf, UINT *lpcbBuf);
  OLESTATUS          WINAPI OleRevokeObject(LPOLECLIENT);
  WINBOOL            WINAPI OleIsDcMeta(HDC);
  OLESTATUS          WINAPI OleRegisterClientDoc(LPCSTR, LPCSTR, LONG, LHCLIENTDOC *);
  OLESTATUS          WINAPI OleRevokeClientDoc(LHCLIENTDOC);
  OLESTATUS          WINAPI OleRenameClientDoc(LHCLIENTDOC, LPCSTR);
  OLESTATUS          WINAPI OleRevertClientDoc(LHCLIENTDOC);
  OLESTATUS          WINAPI OleSavedClientDoc(LHCLIENTDOC);
  OLESTATUS          WINAPI OleEnumObjects(LHCLIENTDOC, LPOLEOBJECT *);

  typedef enum
  {
    OLE_SERVER_MULTI,
    OLE_SERVER_SINGLE
  } OLE_SERVER_USE;
  typedef struct _OLESERVER *LPOLESERVER;

  OLESTATUS WINAPI OleRegisterServer(LPCSTR, LPOLESERVER, LHSERVER *, HINSTANCE, OLE_SERVER_USE);
  OLESTATUS WINAPI OleRevokeServer(LHSERVER);
  OLESTATUS WINAPI OleBlockServer(LHSERVER);
  OLESTATUS WINAPI OleUnblockServer(LHSERVER, WINBOOL *);
  OLESTATUS WINAPI OleLockServer(LPOLEOBJECT, LHSERVER *);
  OLESTATUS WINAPI OleUnlockServer(LHSERVER);

  typedef struct _OLESERVERDOC *LPOLESERVERDOC;

  OLESTATUS WINAPI OleRegisterServerDoc(LHSERVER, LPCSTR, LPOLESERVERDOC, LHSERVERDOC *);
  OLESTATUS WINAPI OleRevokeServerDoc(LHSERVERDOC);
  OLESTATUS WINAPI OleRenameServerDoc(LHSERVERDOC, LPCSTR);
  OLESTATUS WINAPI OleRevertServerDoc(LHSERVERDOC);
  OLESTATUS WINAPI OleSavedServerDoc(LHSERVERDOC);

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */

  typedef struct _OLESERVERVTBL
  {
    OLESTATUS (CALLBACK *Open)(LPOLESERVER, LHSERVERDOC, OLE_LPCSTR, LPOLESERVERDOC *);
    OLESTATUS (CALLBACK *Create)(LPOLESERVER, LHSERVERDOC, OLE_LPCSTR, OLE_LPCSTR, LPOLESERVERDOC *);
    OLESTATUS (CALLBACK *CreateFromTemplate)(LPOLESERVER, LHSERVERDOC, OLE_LPCSTR, OLE_LPCSTR, OLE_LPCSTR, LPOLESERVERDOC *);
    OLESTATUS (CALLBACK *Edit)(LPOLESERVER, LHSERVERDOC, OLE_LPCSTR, OLE_LPCSTR, LPOLESERVERDOC *);
    OLESTATUS (CALLBACK *Exit)(LPOLESERVER);
    OLESTATUS (CALLBACK *Release)(LPOLESERVER);
    OLESTATUS (CALLBACK *Execute)(LPOLESERVER, HGLOBAL);
  } OLESERVERVTBL;
  typedef OLESERVERVTBL *LPOLESERVERVTBL;

  typedef struct _OLESERVER
  {
    LPOLESERVERVTBL lpvtbl;
  } OLESERVER;

  typedef struct _OLESERVERDOCVTBL
  {
    OLESTATUS (CALLBACK *Save)(LPOLESERVERDOC);
    OLESTATUS (CALLBACK *Close)(LPOLESERVERDOC);
    OLESTATUS (CALLBACK *SetHostNames)(LPOLESERVERDOC, OLE_LPCSTR, OLE_LPCSTR);
    OLESTATUS (CALLBACK *SetDocDimensions)(LPOLESERVERDOC, OLE_CONST RECT *);
    OLESTATUS (CALLBACK *GetObject)(LPOLESERVERDOC, OLE_LPCSTR, LPOLEOBJECT *, LPOLECLIENT);
    OLESTATUS (CALLBACK *Release)(LPOLESERVERDOC);
    OLESTATUS (CALLBACK *SetColorScheme)(LPOLESERVERDOC, OLE_CONST LOGPALETTE *);
    OLESTATUS (CALLBACK *Execute)(LPOLESERVERDOC, HGLOBAL);
  } OLESERVERDOCVTBL;
  typedef OLESERVERDOCVTBL *LPOLESERVERDOCVTBL;

  typedef struct _OLESERVERDOC
  {
    LPOLESERVERDOCVTBL lpvtbl;
  } OLESERVERDOC;

#ifdef __cplusplus
}
#endif

#endif  /* _INC_OLE */
