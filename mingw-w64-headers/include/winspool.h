/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _WINSPOOL_
#define _WINSPOOL_

#include <_mingw_unicode.h>
#include <winapifamily.h>

#ifdef _WINUSER_
# include <prsht.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

  typedef struct _PRINTER_INFO_1A
  {
    DWORD Flags;
    LPSTR pDescription;
    LPSTR pName;
    LPSTR pComment;
  } PRINTER_INFO_1A, *PPRINTER_INFO_1A, *LPPRINTER_INFO_1A;

  typedef struct _PRINTER_INFO_1W
  {
    DWORD  Flags;
    LPWSTR pDescription;
    LPWSTR pName;
    LPWSTR pComment;
  } PRINTER_INFO_1W, *PPRINTER_INFO_1W, *LPPRINTER_INFO_1W;

  __MINGW_TYPEDEF_AW(PRINTER_INFO_1)
  __MINGW_TYPEDEF_AW(PPRINTER_INFO_1)
  __MINGW_TYPEDEF_AW(LPPRINTER_INFO_1)

  typedef struct _PRINTER_INFO_2A
  {
    LPSTR                pServerName;
    LPSTR                pPrinterName;
    LPSTR                pShareName;
    LPSTR                pPortName;
    LPSTR                pDriverName;
    LPSTR                pComment;
    LPSTR                pLocation;
    LPDEVMODEA           pDevMode;
    LPSTR                pSepFile;
    LPSTR                pPrintProcessor;
    LPSTR                pDatatype;
    LPSTR                pParameters;
    PSECURITY_DESCRIPTOR pSecurityDescriptor;
    DWORD                Attributes;
    DWORD                Priority;
    DWORD                DefaultPriority;
    DWORD                StartTime;
    DWORD                UntilTime;
    DWORD                Status;
    DWORD                cJobs;
    DWORD                AveragePPM;
  } PRINTER_INFO_2A, *PPRINTER_INFO_2A, *LPPRINTER_INFO_2A;

  typedef struct _PRINTER_INFO_2W
  {
    LPWSTR               pServerName;
    LPWSTR               pPrinterName;
    LPWSTR               pShareName;
    LPWSTR               pPortName;
    LPWSTR               pDriverName;
    LPWSTR               pComment;
    LPWSTR               pLocation;
    LPDEVMODEW           pDevMode;
    LPWSTR               pSepFile;
    LPWSTR               pPrintProcessor;
    LPWSTR               pDatatype;
    LPWSTR               pParameters;
    PSECURITY_DESCRIPTOR pSecurityDescriptor;
    DWORD                Attributes;
    DWORD                Priority;
    DWORD                DefaultPriority;
    DWORD                StartTime;
    DWORD                UntilTime;
    DWORD                Status;
    DWORD                cJobs;
    DWORD                AveragePPM;
  } PRINTER_INFO_2W, *PPRINTER_INFO_2W, *LPPRINTER_INFO_2W;

  __MINGW_TYPEDEF_AW(PRINTER_INFO_2)
  __MINGW_TYPEDEF_AW(PPRINTER_INFO_2)
  __MINGW_TYPEDEF_AW(LPPRINTER_INFO_2)

  typedef struct _PRINTER_INFO_3
  {
    PSECURITY_DESCRIPTOR pSecurityDescriptor;
  } PRINTER_INFO_3, *PPRINTER_INFO_3, *LPPRINTER_INFO_3;

  typedef struct _PRINTER_INFO_4A
  {
    LPSTR pPrinterName;
    LPSTR pServerName;
    DWORD Attributes;
  } PRINTER_INFO_4A, *PPRINTER_INFO_4A, *LPPRINTER_INFO_4A;

  typedef struct _PRINTER_INFO_4W
  {
    LPWSTR pPrinterName;
    LPWSTR pServerName;
    DWORD  Attributes;
  } PRINTER_INFO_4W, *PPRINTER_INFO_4W, *LPPRINTER_INFO_4W;

  __MINGW_TYPEDEF_AW(PRINTER_INFO_4)
  __MINGW_TYPEDEF_AW(PPRINTER_INFO_4)
  __MINGW_TYPEDEF_AW(LPPRINTER_INFO_4)

  typedef struct _PRINTER_INFO_5A
  {
    LPSTR pPrinterName;
    LPSTR pPortName;
    DWORD Attributes;
    DWORD DeviceNotSelectedTimeout;
    DWORD TransmissionRetryTimeout;
  } PRINTER_INFO_5A, *PPRINTER_INFO_5A, *LPPRINTER_INFO_5A;

  typedef struct _PRINTER_INFO_5W
  {
    LPWSTR pPrinterName;
    LPWSTR pPortName;
    DWORD  Attributes;
    DWORD  DeviceNotSelectedTimeout;
    DWORD  TransmissionRetryTimeout;
  } PRINTER_INFO_5W, *PPRINTER_INFO_5W, *LPPRINTER_INFO_5W;

  __MINGW_TYPEDEF_AW(PRINTER_INFO_5)
  __MINGW_TYPEDEF_AW(PPRINTER_INFO_5)
  __MINGW_TYPEDEF_AW(LPPRINTER_INFO_5)

  typedef struct _PRINTER_INFO_6
  {
    DWORD dwStatus;
  } PRINTER_INFO_6, *PPRINTER_INFO_6, *LPPRINTER_INFO_6;

  typedef struct _PRINTER_INFO_7A
  {
    LPSTR pszObjectGUID;
    DWORD dwAction;
  } PRINTER_INFO_7A, *PPRINTER_INFO_7A, *LPPRINTER_INFO_7A;

  typedef struct _PRINTER_INFO_7W
  {
    LPWSTR pszObjectGUID;
    DWORD  dwAction;
  } PRINTER_INFO_7W, *PPRINTER_INFO_7W, *LPPRINTER_INFO_7W;

  __MINGW_TYPEDEF_AW(PRINTER_INFO_7)
  __MINGW_TYPEDEF_AW(PPRINTER_INFO_7)
  __MINGW_TYPEDEF_AW(LPPRINTER_INFO_7)

#define DSPRINT_PUBLISH   0x00000001
#define DSPRINT_UPDATE    0x00000002
#define DSPRINT_UNPUBLISH 0x00000004
#define DSPRINT_REPUBLISH 0x00000008
#define DSPRINT_PENDING   0x80000000

  typedef struct _PRINTER_INFO_8A
  {
    LPDEVMODEA pDevMode;
  } PRINTER_INFO_8A, *PPRINTER_INFO_8A, *LPPRINTER_INFO_8A;

  typedef struct _PRINTER_INFO_8W
  {
    LPDEVMODEW pDevMode;
  } PRINTER_INFO_8W, *PPRINTER_INFO_8W, *LPPRINTER_INFO_8W;

  __MINGW_TYPEDEF_AW(PRINTER_INFO_8)
  __MINGW_TYPEDEF_AW(PPRINTER_INFO_8)
  __MINGW_TYPEDEF_AW(LPPRINTER_INFO_8)

  typedef struct _PRINTER_INFO_9A
  {
    LPDEVMODEA pDevMode;
  } PRINTER_INFO_9A, *PPRINTER_INFO_9A, *LPPRINTER_INFO_9A;

  typedef struct _PRINTER_INFO_9W
  {
    LPDEVMODEW pDevMode;
  } PRINTER_INFO_9W, *PPRINTER_INFO_9W, *LPPRINTER_INFO_9W;

  __MINGW_TYPEDEF_AW(PRINTER_INFO_9)
  __MINGW_TYPEDEF_AW(PPRINTER_INFO_9)
  __MINGW_TYPEDEF_AW(LPPRINTER_INFO_9)

#define PRINTER_CONTROL_PAUSE      1
#define PRINTER_CONTROL_RESUME     2
#define PRINTER_CONTROL_PURGE      3
#define PRINTER_CONTROL_SET_STATUS 4

#define PRINTER_STATUS_PAUSED               0x00000001
#define PRINTER_STATUS_ERROR                0x00000002
#define PRINTER_STATUS_PENDING_DELETION     0x00000004
#define PRINTER_STATUS_PAPER_JAM            0x00000008
#define PRINTER_STATUS_PAPER_OUT            0x00000010
#define PRINTER_STATUS_MANUAL_FEED          0x00000020
#define PRINTER_STATUS_PAPER_PROBLEM        0x00000040
#define PRINTER_STATUS_OFFLINE              0x00000080
#define PRINTER_STATUS_IO_ACTIVE            0x00000100
#define PRINTER_STATUS_BUSY                 0x00000200
#define PRINTER_STATUS_PRINTING             0x00000400
#define PRINTER_STATUS_OUTPUT_BIN_FULL      0x00000800
#define PRINTER_STATUS_NOT_AVAILABLE        0x00001000
#define PRINTER_STATUS_WAITING              0x00002000
#define PRINTER_STATUS_PROCESSING           0x00004000
#define PRINTER_STATUS_INITIALIZING         0x00008000
#define PRINTER_STATUS_WARMING_UP           0x00010000
#define PRINTER_STATUS_TONER_LOW            0x00020000
#define PRINTER_STATUS_NO_TONER             0x00040000
#define PRINTER_STATUS_PAGE_PUNT            0x00080000
#define PRINTER_STATUS_USER_INTERVENTION    0x00100000
#define PRINTER_STATUS_OUT_OF_MEMORY        0x00200000
#define PRINTER_STATUS_DOOR_OPEN            0x00400000
#define PRINTER_STATUS_SERVER_UNKNOWN       0x00800000
#define PRINTER_STATUS_POWER_SAVE           0x01000000
#define PRINTER_STATUS_SERVER_OFFLINE       0x02000000
#define PRINTER_STATUS_DRIVER_UPDATE_NEEDED 0x04000000

#define PRINTER_ATTRIBUTE_QUEUED            0x00000001
#define PRINTER_ATTRIBUTE_DIRECT            0x00000002
#define PRINTER_ATTRIBUTE_DEFAULT           0x00000004
#define PRINTER_ATTRIBUTE_SHARED            0x00000008
#define PRINTER_ATTRIBUTE_NETWORK           0x00000010
#define PRINTER_ATTRIBUTE_HIDDEN            0x00000020
#define PRINTER_ATTRIBUTE_LOCAL             0x00000040
#define PRINTER_ATTRIBUTE_ENABLE_DEVQ       0x00000080
#define PRINTER_ATTRIBUTE_KEEPPRINTEDJOBS   0x00000100
#define PRINTER_ATTRIBUTE_DO_COMPLETE_FIRST 0x00000200
#define PRINTER_ATTRIBUTE_WORK_OFFLINE      0x00000400
#define PRINTER_ATTRIBUTE_ENABLE_BIDI       0x00000800
#define PRINTER_ATTRIBUTE_RAW_ONLY          0x00001000
#define PRINTER_ATTRIBUTE_PUBLISHED         0x00002000
#define PRINTER_ATTRIBUTE_FAX               0x00004000
#define PRINTER_ATTRIBUTE_TS                0x00008000
#define PRINTER_ATTRIBUTE_PUSHED_USER       0x00020000
#define PRINTER_ATTRIBUTE_PUSHED_MACHINE    0x00040000
#define PRINTER_ATTRIBUTE_MACHINE           0x00080000
#define PRINTER_ATTRIBUTE_FRIENDLY_NAME     0x00100000
#define PRINTER_ATTRIBUTE_TS_GENERIC_DRIVER 0x00200000
#define PRINTER_ATTRIBUTE_PER_USER          0x00400000
#define PRINTER_ATTRIBUTE_ENTERPRISE_CLOUD  0x00800000

#define NO_PRIORITY  0
#define MAX_PRIORITY 99
#define MIN_PRIORITY 1
#define DEF_PRIORITY 1

  typedef struct _JOB_INFO_1A
  {
    DWORD      JobId;
    LPSTR      pPrinterName;
    LPSTR      pMachineName;
    LPSTR      pUserName;
    LPSTR      pDocument;
    LPSTR      pDatatype;
    LPSTR      pStatus;
    DWORD      Status;
    DWORD      Priority;
    DWORD      Position;
    DWORD      TotalPages;
    DWORD      PagesPrinted;
    SYSTEMTIME Submitted;
  } JOB_INFO_1A, *PJOB_INFO_1A, *LPJOB_INFO_1A;

  typedef struct _JOB_INFO_1W
  {
    DWORD      JobId;
    LPWSTR     pPrinterName;
    LPWSTR     pMachineName;
    LPWSTR     pUserName;
    LPWSTR     pDocument;
    LPWSTR     pDatatype;
    LPWSTR     pStatus;
    DWORD      Status;
    DWORD      Priority;
    DWORD      Position;
    DWORD      TotalPages;
    DWORD      PagesPrinted;
    SYSTEMTIME Submitted;
  } JOB_INFO_1W, *PJOB_INFO_1W, *LPJOB_INFO_1W;

  __MINGW_TYPEDEF_AW(JOB_INFO_1)
  __MINGW_TYPEDEF_AW(PJOB_INFO_1)
  __MINGW_TYPEDEF_AW(LPJOB_INFO_1)

  typedef struct _JOB_INFO_2A
  {
    DWORD                JobId;
    LPSTR                pPrinterName;
    LPSTR                pMachineName;
    LPSTR                pUserName;
    LPSTR                pDocument;
    LPSTR                pNotifyName;
    LPSTR                pDatatype;
    LPSTR                pPrintProcessor;
    LPSTR                pParameters;
    LPSTR                pDriverName;
    LPDEVMODEA           pDevMode;
    LPSTR                pStatus;
    PSECURITY_DESCRIPTOR pSecurityDescriptor;
    DWORD                Status;
    DWORD                Priority;
    DWORD                Position;
    DWORD                StartTime;
    DWORD                UntilTime;
    DWORD                TotalPages;
    DWORD                Size;
    SYSTEMTIME           Submitted;
    DWORD                Time;
    DWORD                PagesPrinted;
  } JOB_INFO_2A, *PJOB_INFO_2A, *LPJOB_INFO_2A;

  typedef struct _JOB_INFO_2W
  {
    DWORD                JobId;
    LPWSTR               pPrinterName;
    LPWSTR               pMachineName;
    LPWSTR               pUserName;
    LPWSTR               pDocument;
    LPWSTR               pNotifyName;
    LPWSTR               pDatatype;
    LPWSTR               pPrintProcessor;
    LPWSTR               pParameters;
    LPWSTR               pDriverName;
    LPDEVMODEW           pDevMode;
    LPWSTR               pStatus;
    PSECURITY_DESCRIPTOR pSecurityDescriptor;
    DWORD                Status;
    DWORD                Priority;
    DWORD                Position;
    DWORD                StartTime;
    DWORD                UntilTime;
    DWORD                TotalPages;
    DWORD                Size;
    SYSTEMTIME           Submitted;
    DWORD                Time;
    DWORD                PagesPrinted;
  } JOB_INFO_2W, *PJOB_INFO_2W, *LPJOB_INFO_2W;

  __MINGW_TYPEDEF_AW(JOB_INFO_2)
  __MINGW_TYPEDEF_AW(PJOB_INFO_2)
  __MINGW_TYPEDEF_AW(LPJOB_INFO_2)

  typedef struct _JOB_INFO_3
  {
    DWORD JobId;
    DWORD NextJobId;
    DWORD Reserved;
  } JOB_INFO_3, *PJOB_INFO_3, *LPJOB_INFO_3;

  typedef struct _JOB_INFO_4A
  {
    DWORD                JobId;
    LPSTR                pPrinterName;
    LPSTR                pMachineName;
    LPSTR                pUserName;
    LPSTR                pDocument;
    LPSTR                pNotifyName;
    LPSTR                pDatatype;
    LPSTR                pPrintProcessor;
    LPSTR                pParameters;
    LPSTR                pDriverName;
    LPDEVMODEA           pDevMode;
    LPSTR                pStatus;
    PSECURITY_DESCRIPTOR pSecurityDescriptor;
    DWORD                Status;
    DWORD                Priority;
    DWORD                Position;
    DWORD                StartTime;
    DWORD                UntilTime;
    DWORD                TotalPages;
    DWORD                Size;
    SYSTEMTIME           Submitted;
    DWORD                Time;
    DWORD                PagesPrinted;
    LONG                 SizeHigh;
  } JOB_INFO_4A, *PJOB_INFO_4A, *LPJOB_INFO_4A;

  typedef struct _JOB_INFO_4W
  {
    DWORD                JobId;
    LPWSTR               pPrinterName;
    LPWSTR               pMachineName;
    LPWSTR               pUserName;
    LPWSTR               pDocument;
    LPWSTR               pNotifyName;
    LPWSTR               pDatatype;
    LPWSTR               pPrintProcessor;
    LPWSTR               pParameters;
    LPWSTR               pDriverName;
    LPDEVMODEW           pDevMode;
    LPWSTR               pStatus;
    PSECURITY_DESCRIPTOR pSecurityDescriptor;
    DWORD                Status;
    DWORD                Priority;
    DWORD                Position;
    DWORD                StartTime;
    DWORD                UntilTime;
    DWORD                TotalPages;
    DWORD                Size;
    SYSTEMTIME           Submitted;
    DWORD                Time;
    DWORD                PagesPrinted;
    LONG                 SizeHigh;
  } JOB_INFO_4W, *PJOB_INFO_4W, *LPJOB_INFO_4W;

  __MINGW_TYPEDEF_AW(JOB_INFO_4)
  __MINGW_TYPEDEF_AW(PJOB_INFO_4)
  __MINGW_TYPEDEF_AW(LPJOB_INFO_4)

#define JOB_CONTROL_PAUSE             1
#define JOB_CONTROL_RESUME            2
#define JOB_CONTROL_CANCEL            3
#define JOB_CONTROL_RESTART           4
#define JOB_CONTROL_DELETE            5
#define JOB_CONTROL_SENT_TO_PRINTER   6
#define JOB_CONTROL_LAST_PAGE_EJECTED 7
#define JOB_CONTROL_RETAIN            8
#define JOB_CONTROL_RELEASE           9
#define JOB_CONTROL_SEND_TOAST        10
#define JOB_CONTROL_PENDING_ON_DEVICE 11

#define JOB_STATUS_PAUSED            0x00000001
#define JOB_STATUS_ERROR             0x00000002
#define JOB_STATUS_DELETING          0x00000004
#define JOB_STATUS_SPOOLING          0x00000008
#define JOB_STATUS_PRINTING          0x00000010
#define JOB_STATUS_OFFLINE           0x00000020
#define JOB_STATUS_PAPEROUT          0x00000040
#define JOB_STATUS_PRINTED           0x00000080
#define JOB_STATUS_DELETED           0x00000100
#define JOB_STATUS_BLOCKED_DEVQ      0x00000200
#define JOB_STATUS_USER_INTERVENTION 0x00000400
#define JOB_STATUS_RESTART           0x00000800
#define JOB_STATUS_COMPLETE          0x00001000
#define JOB_STATUS_RETAINED          0x00002000
#define JOB_STATUS_RENDERING_LOCALLY 0x00004000
#define JOB_POSITION_UNSPECIFIED     0

  typedef struct _ADDJOB_INFO_1A
  {
    LPSTR Path;
    DWORD JobId;
  } ADDJOB_INFO_1A, *PADDJOB_INFO_1A, *LPADDJOB_INFO_1A;

  typedef struct _ADDJOB_INFO_1W
  {
    LPWSTR Path;
    DWORD JobId;
  } ADDJOB_INFO_1W, *PADDJOB_INFO_1W, *LPADDJOB_INFO_1W;

  __MINGW_TYPEDEF_AW(ADDJOB_INFO_1)
  __MINGW_TYPEDEF_AW(PADDJOB_INFO_1)
  __MINGW_TYPEDEF_AW(LPADDJOB_INFO_1)

  typedef struct _DRIVER_INFO_1A
  {
    LPSTR pName;
  } DRIVER_INFO_1A, *PDRIVER_INFO_1A, *LPDRIVER_INFO_1A;

  typedef struct _DRIVER_INFO_1W
  {
    LPWSTR pName;
  } DRIVER_INFO_1W, *PDRIVER_INFO_1W, *LPDRIVER_INFO_1W;

  __MINGW_TYPEDEF_AW(DRIVER_INFO_1)
  __MINGW_TYPEDEF_AW(PDRIVER_INFO_1)
  __MINGW_TYPEDEF_AW(LPDRIVER_INFO_1)

  typedef struct _DRIVER_INFO_2A
  {
    DWORD cVersion;
    LPSTR pName;
    LPSTR pEnvironment;
    LPSTR pDriverPath;
    LPSTR pDataFile;
    LPSTR pConfigFile;
  } DRIVER_INFO_2A, *PDRIVER_INFO_2A, *LPDRIVER_INFO_2A;

  typedef struct _DRIVER_INFO_2W
  {
    DWORD  cVersion;
    LPWSTR pName;
    LPWSTR pEnvironment;
    LPWSTR pDriverPath;
    LPWSTR pDataFile;
    LPWSTR pConfigFile;
  } DRIVER_INFO_2W, *PDRIVER_INFO_2W, *LPDRIVER_INFO_2W;

  __MINGW_TYPEDEF_AW(DRIVER_INFO_2)
  __MINGW_TYPEDEF_AW(PDRIVER_INFO_2)
  __MINGW_TYPEDEF_AW(LPDRIVER_INFO_2)

  typedef struct _DRIVER_INFO_3A
  {
    DWORD cVersion;
    LPSTR pName;
    LPSTR pEnvironment;
    LPSTR pDriverPath;
    LPSTR pDataFile;
    LPSTR pConfigFile;
    LPSTR pHelpFile;
    LPSTR pDependentFiles;
    LPSTR pMonitorName;
    LPSTR pDefaultDataType;
  } DRIVER_INFO_3A, *PDRIVER_INFO_3A, *LPDRIVER_INFO_3A;

  typedef struct _DRIVER_INFO_3W
  {
    DWORD  cVersion;
    LPWSTR pName;
    LPWSTR pEnvironment;
    LPWSTR pDriverPath;
    LPWSTR pDataFile;
    LPWSTR pConfigFile;
    LPWSTR pHelpFile;
    LPWSTR pDependentFiles;
    LPWSTR pMonitorName;
    LPWSTR pDefaultDataType;
  } DRIVER_INFO_3W, *PDRIVER_INFO_3W, *LPDRIVER_INFO_3W;

  __MINGW_TYPEDEF_AW(DRIVER_INFO_3)
  __MINGW_TYPEDEF_AW(PDRIVER_INFO_3)
  __MINGW_TYPEDEF_AW(LPDRIVER_INFO_3)

  typedef struct _DRIVER_INFO_4A
  {
    DWORD cVersion;
    LPSTR pName;
    LPSTR pEnvironment;
    LPSTR pDriverPath;
    LPSTR pDataFile;
    LPSTR pConfigFile;
    LPSTR pHelpFile;
    LPSTR pDependentFiles;
    LPSTR pMonitorName;
    LPSTR pDefaultDataType;
    LPSTR pszzPreviousNames;
  } DRIVER_INFO_4A, *PDRIVER_INFO_4A, *LPDRIVER_INFO_4A;

  typedef struct _DRIVER_INFO_4W
  {
    DWORD  cVersion;
    LPWSTR pName;
    LPWSTR pEnvironment;
    LPWSTR pDriverPath;
    LPWSTR pDataFile;
    LPWSTR pConfigFile;
    LPWSTR pHelpFile;
    LPWSTR pDependentFiles;
    LPWSTR pMonitorName;
    LPWSTR pDefaultDataType;
    LPWSTR pszzPreviousNames;
  } DRIVER_INFO_4W, *PDRIVER_INFO_4W, *LPDRIVER_INFO_4W;

  __MINGW_TYPEDEF_AW(DRIVER_INFO_4)
  __MINGW_TYPEDEF_AW(PDRIVER_INFO_4)
  __MINGW_TYPEDEF_AW(LPDRIVER_INFO_4)

  typedef struct _DRIVER_INFO_5A
  {
    DWORD cVersion;
    LPSTR pName;
    LPSTR pEnvironment;
    LPSTR pDriverPath;
    LPSTR pDataFile;
    LPSTR pConfigFile;
    DWORD dwDriverAttributes;
    DWORD dwConfigVersion;
    DWORD dwDriverVersion;
  } DRIVER_INFO_5A, *PDRIVER_INFO_5A, *LPDRIVER_INFO_5A;

  typedef struct _DRIVER_INFO_5W
  {
    DWORD  cVersion;
    LPWSTR pName;
    LPWSTR pEnvironment;
    LPWSTR pDriverPath;
    LPWSTR pDataFile;
    LPWSTR pConfigFile;
    DWORD  dwDriverAttributes;
    DWORD  dwConfigVersion;
    DWORD  dwDriverVersion;
  } DRIVER_INFO_5W, *PDRIVER_INFO_5W, *LPDRIVER_INFO_5W;

  __MINGW_TYPEDEF_AW(DRIVER_INFO_5)
  __MINGW_TYPEDEF_AW(PDRIVER_INFO_5)
  __MINGW_TYPEDEF_AW(LPDRIVER_INFO_5)

  typedef struct _DRIVER_INFO_6A
  {
    DWORD     cVersion;
    LPSTR     pName;
    LPSTR     pEnvironment;
    LPSTR     pDriverPath;
    LPSTR     pDataFile;
    LPSTR     pConfigFile;
    LPSTR     pHelpFile;
    LPSTR     pDependentFiles;
    LPSTR     pMonitorName;
    LPSTR     pDefaultDataType;
    LPSTR     pszzPreviousNames;
    FILETIME  ftDriverDate;
    DWORDLONG dwlDriverVersion;
    LPSTR     pszMfgName;
    LPSTR     pszOEMUrl;
    LPSTR     pszHardwareID;
    LPSTR     pszProvider;
  } DRIVER_INFO_6A, *PDRIVER_INFO_6A, *LPDRIVER_INFO_6A;

  typedef struct _DRIVER_INFO_6W
  {
    DWORD     cVersion;
    LPWSTR    pName;
    LPWSTR    pEnvironment;
    LPWSTR    pDriverPath;
    LPWSTR    pDataFile;
    LPWSTR    pConfigFile;
    LPWSTR    pHelpFile;
    LPWSTR    pDependentFiles;
    LPWSTR    pMonitorName;
    LPWSTR    pDefaultDataType;
    LPWSTR    pszzPreviousNames;
    FILETIME  ftDriverDate;
    DWORDLONG dwlDriverVersion;
    LPWSTR    pszMfgName;
    LPWSTR    pszOEMUrl;
    LPWSTR    pszHardwareID;
    LPWSTR    pszProvider;
  } DRIVER_INFO_6W, *PDRIVER_INFO_6W, *LPDRIVER_INFO_6W;

  __MINGW_TYPEDEF_AW(DRIVER_INFO_6)
  __MINGW_TYPEDEF_AW(PDRIVER_INFO_6)
  __MINGW_TYPEDEF_AW(LPDRIVER_INFO_6)

#define PRINTER_DRIVER_PACKAGE_AWARE       0x00000001
#define PRINTER_DRIVER_XPS                 0x00000002
#define PRINTER_DRIVER_SANDBOX_ENABLED     0x00000004
#define PRINTER_DRIVER_CLASS               0x00000008
#define PRINTER_DRIVER_DERIVED             0x00000010
#define PRINTER_DRIVER_NOT_SHAREABLE       0x00000020
#define PRINTER_DRIVER_CATEGORY_FAX        0x00000040
#define PRINTER_DRIVER_CATEGORY_FILE       0x00000080
#define PRINTER_DRIVER_CATEGORY_VIRTUAL    0x00000100
#define PRINTER_DRIVER_CATEGORY_SERVICE    0x00000200
#define PRINTER_DRIVER_SOFT_RESET_REQUIRED 0x00000400
#define PRINTER_DRIVER_SANDBOX_DISABLED    0x00000800
#define PRINTER_DRIVER_CATEGORY_3D         0x00001000
#define PRINTER_DRIVER_CATEGORY_CLOUD      0x00002000

  typedef struct _DRIVER_INFO_8A
  {
    DWORD     cVersion;
    LPSTR     pName;
    LPSTR     pEnvironment;
    LPSTR     pDriverPath;
    LPSTR     pDataFile;
    LPSTR     pConfigFile;
    LPSTR     pHelpFile;
    LPSTR     pDependentFiles;
    LPSTR     pMonitorName;
    LPSTR     pDefaultDataType;
    LPSTR     pszzPreviousNames;
    FILETIME  ftDriverDate;
    DWORDLONG dwlDriverVersion;
    LPSTR     pszMfgName;
    LPSTR     pszOEMUrl;
    LPSTR     pszHardwareID;
    LPSTR     pszProvider;
    LPSTR     pszPrintProcessor;
    LPSTR     pszVendorSetup;
    LPSTR     pszzColorProfiles;
    LPSTR     pszInfPath;
    DWORD     dwPrinterDriverAttributes;
    LPSTR     pszzCoreDriverDependencies;
    FILETIME  ftMinInboxDriverVerDate;
    DWORDLONG dwlMinInboxDriverVerVersion;
  } DRIVER_INFO_8A, *PDRIVER_INFO_8A, *LPDRIVER_INFO_8A;

  typedef struct _DRIVER_INFO_8W
  {
    DWORD     cVersion;
    LPWSTR    pName;
    LPWSTR    pEnvironment;
    LPWSTR    pDriverPath;
    LPWSTR    pDataFile;
    LPWSTR    pConfigFile;
    LPWSTR    pHelpFile;
    LPWSTR    pDependentFiles;
    LPWSTR    pMonitorName;
    LPWSTR    pDefaultDataType;
    LPWSTR    pszzPreviousNames;
    FILETIME  ftDriverDate;
    DWORDLONG dwlDriverVersion;
    LPWSTR    pszMfgName;
    LPWSTR    pszOEMUrl;
    LPWSTR    pszHardwareID;
    LPWSTR    pszProvider;
    LPWSTR    pszPrintProcessor;
    LPWSTR    pszVendorSetup;
    LPWSTR    pszzColorProfiles;
    LPWSTR    pszInfPath;
    DWORD     dwPrinterDriverAttributes;
    LPWSTR    pszzCoreDriverDependencies;
    FILETIME  ftMinInboxDriverVerDate;
    DWORDLONG dwlMinInboxDriverVerVersion;
  } DRIVER_INFO_8W, *PDRIVER_INFO_8W, *LPDRIVER_INFO_8W;

  __MINGW_TYPEDEF_AW(DRIVER_INFO_8)
  __MINGW_TYPEDEF_AW(PDRIVER_INFO_8)
  __MINGW_TYPEDEF_AW(LPDRIVER_INFO_8)

#define DRIVER_KERNELMODE           0x00000001
#define DRIVER_USERMODE             0x00000002
#define DPD_DELETE_UNUSED_FILES     0x00000001
#define DPD_DELETE_SPECIFIC_VERSION 0x00000002
#define DPD_DELETE_ALL_FILES        0x00000004
#define APD_STRICT_UPGRADE          0x00000001
#define APD_STRICT_DOWNGRADE        0x00000002
#define APD_COPY_ALL_FILES          0x00000004
#define APD_COPY_NEW_FILES          0x00000008
#define APD_COPY_FROM_DIRECTORY     0x00000010

  typedef struct _DOC_INFO_1A
  {
    LPSTR pDocName;
    LPSTR pOutputFile;
    LPSTR pDatatype;
  } DOC_INFO_1A, *PDOC_INFO_1A, *LPDOC_INFO_1A;

  typedef struct _DOC_INFO_1W
  {
    LPWSTR pDocName;
    LPWSTR pOutputFile;
    LPWSTR pDatatype;
  } DOC_INFO_1W, *PDOC_INFO_1W, *LPDOC_INFO_1W;

  __MINGW_TYPEDEF_AW(DOC_INFO_1)
  __MINGW_TYPEDEF_AW(PDOC_INFO_1)
  __MINGW_TYPEDEF_AW(LPDOC_INFO_1)

  typedef struct _FORM_INFO_1A
  {
    DWORD Flags;
    LPSTR pName;
    SIZEL Size;
    RECTL ImageableArea;
  } FORM_INFO_1A, *PFORM_INFO_1A, *LPFORM_INFO_1A;

  typedef struct _FORM_INFO_1W
  {
    DWORD  Flags;
    LPWSTR pName;
    SIZEL  Size;
    RECTL  ImageableArea;
  } FORM_INFO_1W, *PFORM_INFO_1W, *LPFORM_INFO_1W;

  __MINGW_TYPEDEF_AW(FORM_INFO_1)
  __MINGW_TYPEDEF_AW(PFORM_INFO_1)
  __MINGW_TYPEDEF_AW(LPFORM_INFO_1)

#define STRING_NONE     0x00000001
#define STRING_MUIDLL   0x00000002
#define STRING_LANGPAIR 0x00000004

#define MAX_FORM_KEYWORD_LENGTH 63 + 1

  typedef struct _FORM_INFO_2A
  {
    DWORD  Flags;
    LPSTR  pName;
    SIZEL  Size;
    RECTL  ImageableArea;
    LPCSTR pKeyword;
    DWORD  StringType;
    LPCSTR pMuiDll;
    DWORD  dwResourceId;
    LPCSTR pDisplayName;
    LANGID wLangId;
  } FORM_INFO_2A, *PFORM_INFO_2A, *LPFORM_INFO_2A;

  typedef struct _FORM_INFO_2W
  {
    DWORD   Flags;
    LPWSTR  pName;
    SIZEL   Size;
    RECTL   ImageableArea;
    LPCSTR  pKeyword;
    DWORD   StringType;
    LPCWSTR pMuiDll;
    DWORD   dwResourceId;
    LPCWSTR pDisplayName;
    LANGID  wLangId;
  } FORM_INFO_2W, *PFORM_INFO_2W, *LPFORM_INFO_2W;

  __MINGW_TYPEDEF_AW(FORM_INFO_2)
  __MINGW_TYPEDEF_AW(PFORM_INFO_2)
  __MINGW_TYPEDEF_AW(LPFORM_INFO_2)

  typedef struct _DOC_INFO_2A
  {
    LPSTR pDocName;
    LPSTR pOutputFile;
    LPSTR pDatatype;
    DWORD dwMode;
    DWORD JobId;
  } DOC_INFO_2A, *PDOC_INFO_2A, *LPDOC_INFO_2A;

  typedef struct _DOC_INFO_2W
  {
    LPWSTR pDocName;
    LPWSTR pOutputFile;
    LPWSTR pDatatype;
    DWORD  dwMode;
    DWORD  JobId;
  } DOC_INFO_2W, *PDOC_INFO_2W, *LPDOC_INFO_2W;

  __MINGW_TYPEDEF_AW(DOC_INFO_2)
  __MINGW_TYPEDEF_AW(PDOC_INFO_2)
  __MINGW_TYPEDEF_AW(LPDOC_INFO_2)

#define DI_CHANNEL        1
#define DI_READ_SPOOL_JOB 3

  typedef struct _DOC_INFO_3A
  {
    LPSTR pDocName;
    LPSTR pOutputFile;
    LPSTR pDatatype;
    DWORD dwFlags;
  } DOC_INFO_3A, *PDOC_INFO_3A, *LPDOC_INFO_3A;

  typedef struct _DOC_INFO_3W
  {
    LPWSTR pDocName;
    LPWSTR pOutputFile;
    LPWSTR pDatatype;
    DWORD  dwFlags;
  } DOC_INFO_3W, *PDOC_INFO_3W, *LPDOC_INFO_3W;

  __MINGW_TYPEDEF_AW(DOC_INFO_3)
  __MINGW_TYPEDEF_AW(PDOC_INFO_3)
  __MINGW_TYPEDEF_AW(LPDOC_INFO_3)

#define DI_MEMORYMAP_WRITE 0x00000001

#define FORM_USER    0x00000000
#define FORM_BUILTIN 0x00000001
#define FORM_PRINTER 0x00000002

  typedef struct _PRINTPROCESSOR_INFO_1A
  {
    LPSTR pName;
  } PRINTPROCESSOR_INFO_1A, *PPRINTPROCESSOR_INFO_1A, *LPPRINTPROCESSOR_INFO_1A;

  typedef struct _PRINTPROCESSOR_INFO_1W
  {
    LPWSTR pName;
  } PRINTPROCESSOR_INFO_1W, *PPRINTPROCESSOR_INFO_1W, *LPPRINTPROCESSOR_INFO_1W;

  __MINGW_TYPEDEF_AW(PRINTPROCESSOR_INFO_1)
  __MINGW_TYPEDEF_AW(PPRINTPROCESSOR_INFO_1)
  __MINGW_TYPEDEF_AW(LPPRINTPROCESSOR_INFO_1)

  typedef struct _PRINTPROCESSOR_CAPS_1
  {
    DWORD dwLevel;
    DWORD dwNupOptions;
    DWORD dwPageOrderFlags;
    DWORD dwNumberOfCopies;
  } PRINTPROCESSOR_CAPS_1, *PPRINTPROCESSOR_CAPS_1;

#define NORMAL_PRINT  (0x00000000)
#define REVERSE_PRINT (0x00000001)

  typedef struct _PRINTPROCESSOR_CAPS_2
  {
    DWORD dwLevel;
    DWORD dwNupOptions;
    DWORD dwPageOrderFlags;
    DWORD dwNumberOfCopies;
    DWORD dwNupDirectionCaps;
    DWORD dwNupBorderCaps;
    DWORD dwBookletHandlingCaps;
    DWORD dwDuplexHandlingCaps;
    DWORD dwScalingCaps;
  } PRINTPROCESSOR_CAPS_2, *PPRINTPROCESSOR_CAPS_2;

#define PPCAPS_RIGHT_THEN_DOWN                  (0x00000001     )
#define PPCAPS_DOWN_THEN_RIGHT                  (0x00000001 << 1)
#define PPCAPS_LEFT_THEN_DOWN                   (0x00000001 << 2)
#define PPCAPS_DOWN_THEN_LEFT                   (0x00000001 << 3)
#define PPCAPS_BORDER_PRINT                     (0x00000001     )
#define PPCAPS_BOOKLET_EDGE                     (0x00000001     )
#define PPCAPS_REVERSE_PAGES_FOR_REVERSE_DUPLEX (0x00000001     )
#define PPCAPS_DONT_SEND_EXTRA_PAGES_FOR_DUPLEX (0x00000001 << 1)
#define PPCAPS_SQUARE_SCALING                   (0x00000001     )

  typedef struct _PORT_INFO_1A
  {
    LPSTR pName;
  } PORT_INFO_1A, *PPORT_INFO_1A, *LPPORT_INFO_1A;
  typedef struct _PORT_INFO_1W
  {
    LPWSTR pName;
  } PORT_INFO_1W, *PPORT_INFO_1W, *LPPORT_INFO_1W;

  __MINGW_TYPEDEF_AW(PORT_INFO_1)
  __MINGW_TYPEDEF_AW(PPORT_INFO_1)
  __MINGW_TYPEDEF_AW(LPPORT_INFO_1)

  typedef struct _PORT_INFO_2A
  {
    LPSTR pPortName;
    LPSTR pMonitorName;
    LPSTR pDescription;
    DWORD fPortType;
    DWORD Reserved;
  } PORT_INFO_2A, *PPORT_INFO_2A, *LPPORT_INFO_2A;

  typedef struct _PORT_INFO_2W
  {
    LPWSTR pPortName;
    LPWSTR pMonitorName;
    LPWSTR pDescription;
    DWORD  fPortType;
    DWORD  Reserved;
  } PORT_INFO_2W, *PPORT_INFO_2W, *LPPORT_INFO_2W;

  __MINGW_TYPEDEF_AW(PORT_INFO_2)
  __MINGW_TYPEDEF_AW(PPORT_INFO_2)
  __MINGW_TYPEDEF_AW(LPPORT_INFO_2)

#define PORT_TYPE_WRITE        0x0001
#define PORT_TYPE_READ         0x0002
#define PORT_TYPE_REDIRECTED   0x0004
#define PORT_TYPE_NET_ATTACHED 0x0008

  typedef struct _PORT_INFO_3A
  {
    DWORD dwStatus;
    LPSTR pszStatus;
    DWORD dwSeverity;
  } PORT_INFO_3A, *PPORT_INFO_3A, *LPPORT_INFO_3A;

  typedef struct _PORT_INFO_3W
  {
    DWORD  dwStatus;
    LPWSTR pszStatus;
    DWORD  dwSeverity;
  } PORT_INFO_3W, *PPORT_INFO_3W, *LPPORT_INFO_3W;

  __MINGW_TYPEDEF_AW(PORT_INFO_3)
  __MINGW_TYPEDEF_AW(PPORT_INFO_3)
  __MINGW_TYPEDEF_AW(LPPORT_INFO_3)

#define PORT_STATUS_TYPE_ERROR   1
#define PORT_STATUS_TYPE_WARNING 2
#define PORT_STATUS_TYPE_INFO    3

#define PORT_STATUS_OFFLINE           1
#define PORT_STATUS_PAPER_JAM         2
#define PORT_STATUS_PAPER_OUT         3
#define PORT_STATUS_OUTPUT_BIN_FULL   4
#define PORT_STATUS_PAPER_PROBLEM     5
#define PORT_STATUS_NO_TONER          6
#define PORT_STATUS_DOOR_OPEN         7
#define PORT_STATUS_USER_INTERVENTION 8
#define PORT_STATUS_OUT_OF_MEMORY     9
#define PORT_STATUS_TONER_LOW         10
#define PORT_STATUS_WARMING_UP        11
#define PORT_STATUS_POWER_SAVE        12

  typedef struct _MONITOR_INFO_1A
  {
    LPSTR pName;
  } MONITOR_INFO_1A, *PMONITOR_INFO_1A, *LPMONITOR_INFO_1A;

  typedef struct _MONITOR_INFO_1W
  {
    LPWSTR pName;
  } MONITOR_INFO_1W, *PMONITOR_INFO_1W, *LPMONITOR_INFO_1W;

  __MINGW_TYPEDEF_AW(MONITOR_INFO_1)
  __MINGW_TYPEDEF_AW(PMONITOR_INFO_1)
  __MINGW_TYPEDEF_AW(LPMONITOR_INFO_1)

  typedef struct _MONITOR_INFO_2A
  {
    LPSTR pName;
    LPSTR pEnvironment;
    LPSTR pDLLName;
  } MONITOR_INFO_2A, *PMONITOR_INFO_2A, *LPMONITOR_INFO_2A;

  typedef struct _MONITOR_INFO_2W
  {
    LPWSTR pName;
    LPWSTR pEnvironment;
    LPWSTR pDLLName;
  } MONITOR_INFO_2W, *PMONITOR_INFO_2W, *LPMONITOR_INFO_2W;

  __MINGW_TYPEDEF_AW(MONITOR_INFO_2)
  __MINGW_TYPEDEF_AW(PMONITOR_INFO_2)
  __MINGW_TYPEDEF_AW(LPMONITOR_INFO_2)

  typedef struct _DATATYPES_INFO_1A
  {
    LPSTR pName;
  } DATATYPES_INFO_1A, *PDATATYPES_INFO_1A, *LPDATATYPES_INFO_1A;

  typedef struct _DATATYPES_INFO_1W
  {
    LPWSTR pName;
  } DATATYPES_INFO_1W, *PDATATYPES_INFO_1W, *LPDATATYPES_INFO_1W;

  __MINGW_TYPEDEF_AW(DATATYPES_INFO_1)
  __MINGW_TYPEDEF_AW(PDATATYPES_INFO_1)
  __MINGW_TYPEDEF_AW(LPDATATYPES_INFO_1)

  typedef struct _PRINTER_DEFAULTSA
  {
    LPSTR       pDatatype;
    LPDEVMODEA  pDevMode;
    ACCESS_MASK DesiredAccess;
  } PRINTER_DEFAULTSA, *PPRINTER_DEFAULTSA, *LPPRINTER_DEFAULTSA;

  typedef struct _PRINTER_DEFAULTSW
  {
    LPWSTR      pDatatype;
    LPDEVMODEW  pDevMode;
    ACCESS_MASK DesiredAccess;
  } PRINTER_DEFAULTSW, *PPRINTER_DEFAULTSW, *LPPRINTER_DEFAULTSW;

  __MINGW_TYPEDEF_AW(PRINTER_DEFAULTS)
  __MINGW_TYPEDEF_AW(PPRINTER_DEFAULTS)
  __MINGW_TYPEDEF_AW(LPPRINTER_DEFAULTS)

  typedef struct _PRINTER_ENUM_VALUESA
  {
    LPSTR  pValueName;
    DWORD  cbValueName;
    DWORD  dwType;
    LPBYTE pData;
    DWORD  cbData;
  } PRINTER_ENUM_VALUESA, *PPRINTER_ENUM_VALUESA, *LPPRINTER_ENUM_VALUESA;

  typedef struct _PRINTER_ENUM_VALUESW
  {
    LPWSTR pValueName;
    DWORD  cbValueName;
    DWORD  dwType;
    LPBYTE pData;
    DWORD  cbData;
  } PRINTER_ENUM_VALUESW, *PPRINTER_ENUM_VALUESW, *LPPRINTER_ENUM_VALUESW;

  __MINGW_TYPEDEF_AW(PRINTER_ENUM_VALUES)
  __MINGW_TYPEDEF_AW(PPRINTER_ENUM_VALUES)
  __MINGW_TYPEDEF_AW(LPPRINTER_ENUM_VALUES)

  WINBOOL WINAPI EnumPrintersA(DWORD Flags, LPSTR Name, DWORD Level, LPBYTE pPrinterEnum, DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned);
  WINBOOL WINAPI EnumPrintersW(DWORD Flags, LPWSTR Name, DWORD Level, LPBYTE pPrinterEnum, DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned);
#define EnumPrinters __MINGW_NAME_AW(EnumPrinters)

#define PRINTER_ENUM_DEFAULT      0x00000001
#define PRINTER_ENUM_LOCAL        0x00000002
#define PRINTER_ENUM_CONNECTIONS  0x00000004
#define PRINTER_ENUM_FAVORITE     0x00000004
#define PRINTER_ENUM_NAME         0x00000008
#define PRINTER_ENUM_REMOTE       0x00000010
#define PRINTER_ENUM_SHARED       0x00000020
#define PRINTER_ENUM_NETWORK      0x00000040
#define PRINTER_ENUM_EXPAND       0x00004000
#define PRINTER_ENUM_CONTAINER    0x00008000
#define PRINTER_ENUM_ICONMASK     0x00ff0000
#define PRINTER_ENUM_ICON1        0x00010000
#define PRINTER_ENUM_ICON2        0x00020000
#define PRINTER_ENUM_ICON3        0x00040000
#define PRINTER_ENUM_ICON4        0x00080000
#define PRINTER_ENUM_ICON5        0x00100000
#define PRINTER_ENUM_ICON6        0x00200000
#define PRINTER_ENUM_ICON7        0x00400000
#define PRINTER_ENUM_ICON8        0x00800000
#define PRINTER_ENUM_HIDE         0x01000000
#define PRINTER_ENUM_CATEGORY_ALL 0x02000000
#define PRINTER_ENUM_CATEGORY_3D  0x04000000

#define SPOOL_FILE_PERSISTENT 0x00000001
#define SPOOL_FILE_TEMPORARY  0x00000002

  HANDLE  WINAPI GetSpoolFileHandle(HANDLE hPrinter);
  HANDLE  WINAPI CommitSpoolData(HANDLE hPrinter, HANDLE hSpoolFile, DWORD cbCommit);
  WINBOOL WINAPI CloseSpoolFileHandle(HANDLE hPrinter, HANDLE hSpoolFile);
  WINBOOL WINAPI OpenPrinterA(LPSTR pPrinterName, LPHANDLE phPrinter, LPPRINTER_DEFAULTSA pDefault);
  WINBOOL WINAPI OpenPrinterW(LPWSTR pPrinterName, LPHANDLE phPrinter, LPPRINTER_DEFAULTSW pDefault);
#define OpenPrinter __MINGW_NAME_AW(OpenPrinter)
  WINBOOL WINAPI ResetPrinterA(HANDLE hPrinter, LPPRINTER_DEFAULTSA pDefault);
  WINBOOL WINAPI ResetPrinterW(HANDLE hPrinter, LPPRINTER_DEFAULTSW pDefault);
#define ResetPrinter __MINGW_NAME_AW(ResetPrinter)
  WINBOOL WINAPI SetJobA(HANDLE hPrinter, DWORD JobId, DWORD Level, LPBYTE pJob, DWORD Command);
  WINBOOL WINAPI SetJobW(HANDLE hPrinter, DWORD JobId, DWORD Level, LPBYTE pJob, DWORD Command);
#define SetJob __MINGW_NAME_AW(SetJob)
  WINBOOL WINAPI GetJobA(HANDLE hPrinter, DWORD JobId, DWORD Level, LPBYTE pJob, DWORD cbBuf, LPDWORD pcbNeeded);
  WINBOOL WINAPI GetJobW(HANDLE hPrinter, DWORD JobId, DWORD Level, LPBYTE pJob, DWORD cbBuf, LPDWORD pcbNeeded);
#define GetJob __MINGW_NAME_AW(GetJob)
  WINBOOL WINAPI EnumJobsA(HANDLE hPrinter, DWORD FirstJob, DWORD NoJobs, DWORD Level, LPBYTE pJob, DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned);
  WINBOOL WINAPI EnumJobsW(HANDLE hPrinter, DWORD FirstJob, DWORD NoJobs, DWORD Level, LPBYTE pJob, DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned);
#define EnumJobs __MINGW_NAME_AW(EnumJobs)
  HANDLE  WINAPI AddPrinterA(LPSTR pName, DWORD Level, LPBYTE pPrinter);
  HANDLE  WINAPI AddPrinterW(LPWSTR pName, DWORD Level, LPBYTE pPrinter);
#define AddPrinter __MINGW_NAME_AW(AddPrinter)
  WINBOOL WINAPI DeletePrinter(HANDLE hPrinter);
  WINBOOL WINAPI SetPrinterA(HANDLE hPrinter, DWORD Level, LPBYTE pPrinter, DWORD Command);
  WINBOOL WINAPI SetPrinterW(HANDLE hPrinter, DWORD Level, LPBYTE pPrinter, DWORD Command);
#define SetPrinter __MINGW_NAME_AW(SetPrinter)
  WINBOOL WINAPI GetPrinterA(HANDLE hPrinter, DWORD Level, LPBYTE pPrinter, DWORD cbBuf, LPDWORD pcbNeeded);
  WINBOOL WINAPI GetPrinterW(HANDLE hPrinter, DWORD Level, LPBYTE pPrinter, DWORD cbBuf, LPDWORD pcbNeeded);
#define GetPrinter __MINGW_NAME_AW(GetPrinter)
  WINBOOL WINAPI AddPrinterDriverA(LPSTR pName, DWORD Level, LPBYTE pDriverInfo);
  WINBOOL WINAPI AddPrinterDriverW(LPWSTR pName, DWORD Level, LPBYTE pDriverInfo);
#define AddPrinterDriver __MINGW_NAME_AW(AddPrinterDriver)
  WINBOOL WINAPI AddPrinterDriverExA(LPSTR pName, DWORD Level, LPBYTE pDriverInfo, DWORD dwFileCopyFlags);
  WINBOOL WINAPI AddPrinterDriverExW(LPWSTR pName, DWORD Level, LPBYTE pDriverInfo, DWORD dwFileCopyFlags);
#define AddPrinterDriverEx __MINGW_NAME_AW(AddPrinterDriverEx)
  WINBOOL WINAPI EnumPrinterDriversA(LPSTR pName, LPSTR pEnvironment, DWORD Level, LPBYTE pDriverInfo, DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned);
  WINBOOL WINAPI EnumPrinterDriversW(LPWSTR pName, LPWSTR pEnvironment, DWORD Level, LPBYTE pDriverInfo, DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned);
#define EnumPrinterDrivers __MINGW_NAME_AW(EnumPrinterDrivers)
  WINBOOL WINAPI GetPrinterDriverA(HANDLE hPrinter, LPSTR pEnvironment, DWORD Level, LPBYTE pDriverInfo, DWORD cbBuf, LPDWORD pcbNeeded);
  WINBOOL WINAPI GetPrinterDriverW(HANDLE hPrinter, LPWSTR pEnvironment, DWORD Level, LPBYTE pDriverInfo, DWORD cbBuf, LPDWORD pcbNeeded);
#define GetPrinterDriver __MINGW_NAME_AW(GetPrinterDriver)
  WINBOOL WINAPI GetPrinterDriverDirectoryA(LPSTR pName, LPSTR pEnvironment, DWORD Level, LPBYTE pDriverDirectory, DWORD cbBuf, LPDWORD pcbNeeded);
  WINBOOL WINAPI GetPrinterDriverDirectoryW(LPWSTR pName, LPWSTR pEnvironment, DWORD Level, LPBYTE pDriverDirectory, DWORD cbBuf, LPDWORD pcbNeeded);
#define GetPrinterDriverDirectory __MINGW_NAME_AW(GetPrinterDriverDirectory)
  WINBOOL WINAPI DeletePrinterDriverA(LPSTR pName, LPSTR pEnvironment, LPSTR pDriverName);
  WINBOOL WINAPI DeletePrinterDriverW(LPWSTR pName, LPWSTR pEnvironment, LPWSTR pDriverName);
#define DeletePrinterDriver __MINGW_NAME_AW(DeletePrinterDriver)
  WINBOOL WINAPI DeletePrinterDriverExA(LPSTR pName, LPSTR pEnvironment, LPSTR pDriverName, DWORD dwDeleteFlag, DWORD dwVersionFlag);
  WINBOOL WINAPI DeletePrinterDriverExW(LPWSTR pName, LPWSTR pEnvironment, LPWSTR pDriverName, DWORD dwDeleteFlag, DWORD dwVersionFlag);
#define DeletePrinterDriverEx __MINGW_NAME_AW(DeletePrinterDriverEx)
  WINBOOL WINAPI AddPrintProcessorA(LPSTR pName, LPSTR pEnvironment, LPSTR pPathName, LPSTR pPrintProcessorName);
  WINBOOL WINAPI AddPrintProcessorW(LPWSTR pName, LPWSTR pEnvironment, LPWSTR pPathName, LPWSTR pPrintProcessorName);
#define AddPrintProcessor __MINGW_NAME_AW(AddPrintProcessor)
  WINBOOL WINAPI EnumPrintProcessorsA(LPSTR pName, LPSTR pEnvironment, DWORD Level, LPBYTE pPrintProcessorInfo, DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned);
  WINBOOL WINAPI EnumPrintProcessorsW(LPWSTR pName, LPWSTR pEnvironment, DWORD Level, LPBYTE pPrintProcessorInfo, DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned);
#define EnumPrintProcessors __MINGW_NAME_AW(EnumPrintProcessors)
  WINBOOL WINAPI GetPrintProcessorDirectoryA(LPSTR pName, LPSTR pEnvironment, DWORD Level, LPBYTE pPrintProcessorInfo, DWORD cbBuf, LPDWORD pcbNeeded);
  WINBOOL WINAPI GetPrintProcessorDirectoryW(LPWSTR pName, LPWSTR pEnvironment, DWORD Level, LPBYTE pPrintProcessorInfo, DWORD cbBuf, LPDWORD pcbNeeded);
#define GetPrintProcessorDirectory __MINGW_NAME_AW(GetPrintProcessorDirectory)
  WINBOOL WINAPI EnumPrintProcessorDatatypesA(LPSTR pName, LPSTR pPrintProcessorName, DWORD Level, LPBYTE pDatatypes, DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned);
  WINBOOL WINAPI EnumPrintProcessorDatatypesW(LPWSTR pName, LPWSTR pPrintProcessorName, DWORD Level, LPBYTE pDatatypes, DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned);
#define EnumPrintProcessorDatatypes __MINGW_NAME_AW(EnumPrintProcessorDatatypes)
  WINBOOL WINAPI DeletePrintProcessorA(LPSTR pName, LPSTR pEnvironment, LPSTR pPrintProcessorName);
  WINBOOL WINAPI DeletePrintProcessorW(LPWSTR pName, LPWSTR pEnvironment, LPWSTR pPrintProcessorName);
#define DeletePrintProcessor __MINGW_NAME_AW(DeletePrintProcessor)
  DWORD   WINAPI StartDocPrinterA(HANDLE hPrinter, DWORD Level, LPBYTE pDocInfo);
  DWORD   WINAPI StartDocPrinterW(HANDLE hPrinter, DWORD Level, LPBYTE pDocInfo);
#define StartDocPrinter __MINGW_NAME_AW(StartDocPrinter)
  WINBOOL WINAPI StartPagePrinter(HANDLE hPrinter);
  WINBOOL WINAPI WritePrinter(HANDLE hPrinter, LPVOID pBuf, DWORD cbBuf, LPDWORD pcWritten);
  WINBOOL WINAPI FlushPrinter(HANDLE hPrinter, LPVOID pBuf, DWORD cbBuf, LPDWORD pcWritten, DWORD cSleep);
  WINBOOL WINAPI EndPagePrinter(HANDLE hPrinter);
  WINBOOL WINAPI AbortPrinter(HANDLE hPrinter);
  WINBOOL WINAPI ReadPrinter(HANDLE hPrinter, LPVOID pBuf, DWORD cbBuf, LPDWORD pNoBytesRead);
  WINBOOL WINAPI EndDocPrinter(HANDLE hPrinter);
  WINBOOL WINAPI AddJobA(HANDLE hPrinter, DWORD Level, LPBYTE pData, DWORD cbBuf, LPDWORD pcbNeeded);
  WINBOOL WINAPI AddJobW(HANDLE hPrinter, DWORD Level, LPBYTE pData, DWORD cbBuf, LPDWORD pcbNeeded);
#define AddJob __MINGW_NAME_AW(AddJob)
  WINBOOL WINAPI ScheduleJob(HANDLE hPrinter, DWORD JobId);
  WINBOOL WINAPI PrinterProperties(HWND hWnd, HANDLE hPrinter);
  LONG    WINAPI DocumentPropertiesA(HWND hWnd, HANDLE hPrinter, LPSTR pDeviceName, PDEVMODEA pDevModeOutput, PDEVMODEA pDevModeInput, DWORD fMode);
  LONG    WINAPI DocumentPropertiesW(HWND hWnd, HANDLE hPrinter, LPWSTR pDeviceName, PDEVMODEW pDevModeOutput, PDEVMODEW pDevModeInput, DWORD fMode);
#define DocumentProperties __MINGW_NAME_AW(DocumentProperties)
  LONG    WINAPI AdvancedDocumentPropertiesA(HWND hWnd, HANDLE hPrinter, LPSTR pDeviceName, PDEVMODEA pDevModeOutput, PDEVMODEA pDevModeInput);
  LONG    WINAPI AdvancedDocumentPropertiesW(HWND hWnd, HANDLE hPrinter, LPWSTR pDeviceName, PDEVMODEW pDevModeOutput, PDEVMODEW pDevModeInput);
#define AdvancedDocumentProperties __MINGW_NAME_AW(AdvancedDocumentProperties)
  LONG           ExtDeviceMode(HWND hWnd, HANDLE hInst, LPDEVMODEA pDevModeOutput, LPSTR pDeviceName, LPSTR pPort, LPDEVMODEA pDevModeInput, LPSTR pProfile, DWORD fMode);
  DWORD   WINAPI GetPrinterDataA(HANDLE hPrinter, LPSTR pValueName, LPDWORD pType, LPBYTE pData, DWORD nSize, LPDWORD pcbNeeded);
  DWORD   WINAPI GetPrinterDataW(HANDLE hPrinter, LPWSTR pValueName, LPDWORD pType, LPBYTE pData, DWORD nSize, LPDWORD pcbNeeded);
#define GetPrinterData __MINGW_NAME_AW(GetPrinterData)
  DWORD   WINAPI GetPrinterDataExA(HANDLE hPrinter, LPCSTR pKeyName, LPCSTR pValueName, LPDWORD pType, LPBYTE pData, DWORD nSize, LPDWORD pcbNeeded);
  DWORD   WINAPI GetPrinterDataExW(HANDLE hPrinter, LPCWSTR pKeyName, LPCWSTR pValueName, LPDWORD pType, LPBYTE pData, DWORD nSize, LPDWORD pcbNeeded);
#define GetPrinterDataEx __MINGW_NAME_AW(GetPrinterDataEx)
  DWORD   WINAPI EnumPrinterDataA(HANDLE hPrinter, DWORD dwIndex, LPSTR pValueName, DWORD cbValueName, LPDWORD pcbValueName, LPDWORD pType, LPBYTE pData, DWORD cbData, LPDWORD pcbData);
  DWORD   WINAPI EnumPrinterDataW(HANDLE hPrinter, DWORD dwIndex, LPWSTR pValueName, DWORD cbValueName, LPDWORD pcbValueName, LPDWORD pType, LPBYTE pData, DWORD cbData, LPDWORD pcbData);
#define EnumPrinterData __MINGW_NAME_AW(EnumPrinterData)
  DWORD   WINAPI EnumPrinterDataExA(HANDLE hPrinter, LPCSTR pKeyName, LPBYTE pEnumValues, DWORD cbEnumValues, LPDWORD pcbEnumValues, LPDWORD pnEnumValues);
  DWORD   WINAPI EnumPrinterDataExW(HANDLE hPrinter, LPCWSTR pKeyName, LPBYTE pEnumValues, DWORD cbEnumValues, LPDWORD pcbEnumValues, LPDWORD pnEnumValues);
#define EnumPrinterDataEx __MINGW_NAME_AW(EnumPrinterDataEx)
  DWORD   WINAPI EnumPrinterKeyA(HANDLE hPrinter, LPCSTR pKeyName, LPSTR pSubkey, DWORD cbSubkey, LPDWORD pcbSubkey);
  DWORD   WINAPI EnumPrinterKeyW(HANDLE hPrinter, LPCWSTR pKeyName, LPWSTR pSubkey, DWORD cbSubkey, LPDWORD pcbSubkey);
#define EnumPrinterKey __MINGW_NAME_AW(EnumPrinterKey)
  DWORD   WINAPI SetPrinterDataA(HANDLE hPrinter, LPSTR pValueName, DWORD Type, LPBYTE pData, DWORD cbData);
  DWORD   WINAPI SetPrinterDataW(HANDLE hPrinter, LPWSTR pValueName, DWORD Type, LPBYTE pData, DWORD cbData);
#define SetPrinterData __MINGW_NAME_AW(SetPrinterData)
  DWORD   WINAPI SetPrinterDataExA(HANDLE hPrinter, LPCSTR pKeyName, LPCSTR pValueName, DWORD Type, LPBYTE pData, DWORD cbData);
  DWORD   WINAPI SetPrinterDataExW(HANDLE hPrinter, LPCWSTR pKeyName, LPCWSTR pValueName, DWORD Type, LPBYTE pData, DWORD cbData);
#define SetPrinterDataEx __MINGW_NAME_AW(SetPrinterDataEx)
  DWORD   WINAPI DeletePrinterDataA(HANDLE hPrinter, LPSTR pValueName);
  DWORD   WINAPI DeletePrinterDataW(HANDLE hPrinter, LPWSTR pValueName);
#define DeletePrinterData __MINGW_NAME_AW(DeletePrinterData)
  DWORD   WINAPI DeletePrinterDataExA(HANDLE hPrinter, LPCSTR pKeyName, LPCSTR pValueName);
  DWORD   WINAPI DeletePrinterDataExW(HANDLE hPrinter, LPCWSTR pKeyName, LPCWSTR pValueName);
#define DeletePrinterDataEx __MINGW_NAME_AW(DeletePrinterDataEx)
  DWORD   WINAPI DeletePrinterKeyA(HANDLE hPrinter, LPCSTR pKeyName);
  DWORD   WINAPI DeletePrinterKeyW(HANDLE hPrinter, LPCWSTR pKeyName);
#define DeletePrinterKey __MINGW_NAME_AW(DeletePrinterKey)

#define PRINTER_NOTIFY_TYPE 0x00
#define JOB_NOTIFY_TYPE     0x01
#define SERVER_NOTIFY_TYPE  0x02

#define PRINTER_NOTIFY_FIELD_SERVER_NAME            0x00
#define PRINTER_NOTIFY_FIELD_PRINTER_NAME           0x01
#define PRINTER_NOTIFY_FIELD_SHARE_NAME             0x02
#define PRINTER_NOTIFY_FIELD_PORT_NAME              0x03
#define PRINTER_NOTIFY_FIELD_DRIVER_NAME            0x04
#define PRINTER_NOTIFY_FIELD_COMMENT                0x05
#define PRINTER_NOTIFY_FIELD_LOCATION               0x06
#define PRINTER_NOTIFY_FIELD_DEVMODE                0x07
#define PRINTER_NOTIFY_FIELD_SEPFILE                0x08
#define PRINTER_NOTIFY_FIELD_PRINT_PROCESSOR        0x09
#define PRINTER_NOTIFY_FIELD_PARAMETERS             0x0A
#define PRINTER_NOTIFY_FIELD_DATATYPE               0x0B
#define PRINTER_NOTIFY_FIELD_SECURITY_DESCRIPTOR    0x0C
#define PRINTER_NOTIFY_FIELD_ATTRIBUTES             0x0D
#define PRINTER_NOTIFY_FIELD_PRIORITY               0x0E
#define PRINTER_NOTIFY_FIELD_DEFAULT_PRIORITY       0x0F
#define PRINTER_NOTIFY_FIELD_START_TIME             0x10
#define PRINTER_NOTIFY_FIELD_UNTIL_TIME             0x11
#define PRINTER_NOTIFY_FIELD_STATUS                 0x12
#define PRINTER_NOTIFY_FIELD_STATUS_STRING          0x13
#define PRINTER_NOTIFY_FIELD_CJOBS                  0x14
#define PRINTER_NOTIFY_FIELD_AVERAGE_PPM            0x15
#define PRINTER_NOTIFY_FIELD_TOTAL_PAGES            0x16
#define PRINTER_NOTIFY_FIELD_PAGES_PRINTED          0x17
#define PRINTER_NOTIFY_FIELD_TOTAL_BYTES            0x18
#define PRINTER_NOTIFY_FIELD_BYTES_PRINTED          0x19
#define PRINTER_NOTIFY_FIELD_OBJECT_GUID            0x1A
#define PRINTER_NOTIFY_FIELD_FRIENDLY_NAME          0x1B
#define PRINTER_NOTIFY_FIELD_BRANCH_OFFICE_PRINTING 0x1C

#define JOB_NOTIFY_FIELD_PRINTER_NAME        0x00
#define JOB_NOTIFY_FIELD_MACHINE_NAME        0x01
#define JOB_NOTIFY_FIELD_PORT_NAME           0x02
#define JOB_NOTIFY_FIELD_USER_NAME           0x03
#define JOB_NOTIFY_FIELD_NOTIFY_NAME         0x04
#define JOB_NOTIFY_FIELD_DATATYPE            0x05
#define JOB_NOTIFY_FIELD_PRINT_PROCESSOR     0x06
#define JOB_NOTIFY_FIELD_PARAMETERS          0x07
#define JOB_NOTIFY_FIELD_DRIVER_NAME         0x08
#define JOB_NOTIFY_FIELD_DEVMODE             0x09
#define JOB_NOTIFY_FIELD_STATUS              0x0A
#define JOB_NOTIFY_FIELD_STATUS_STRING       0x0B
#define JOB_NOTIFY_FIELD_SECURITY_DESCRIPTOR 0x0C
#define JOB_NOTIFY_FIELD_DOCUMENT            0x0D
#define JOB_NOTIFY_FIELD_PRIORITY            0x0E
#define JOB_NOTIFY_FIELD_POSITION            0x0F
#define JOB_NOTIFY_FIELD_SUBMITTED           0x10
#define JOB_NOTIFY_FIELD_START_TIME          0x11
#define JOB_NOTIFY_FIELD_UNTIL_TIME          0x12
#define JOB_NOTIFY_FIELD_TIME                0x13
#define JOB_NOTIFY_FIELD_TOTAL_PAGES         0x14
#define JOB_NOTIFY_FIELD_PAGES_PRINTED       0x15
#define JOB_NOTIFY_FIELD_TOTAL_BYTES         0x16
#define JOB_NOTIFY_FIELD_BYTES_PRINTED       0x17
#define JOB_NOTIFY_FIELD_REMOTE_JOB_ID       0x18

#define SERVER_NOTIFY_FIELD_PRINT_DRIVER_ISOLATION_GROUP 0x00

#define PRINTER_NOTIFY_CATEGORY_ALL 0x001000
#define PRINTER_NOTIFY_CATEGORY_3D  0x002000

  typedef struct _PRINTER_NOTIFY_OPTIONS_TYPE
  {
    WORD  Type;
    WORD  Reserved0;
    DWORD Reserved1;
    DWORD Reserved2;
    DWORD Count;
    PWORD pFields;
  } PRINTER_NOTIFY_OPTIONS_TYPE, *PPRINTER_NOTIFY_OPTIONS_TYPE, *LPPRINTER_NOTIFY_OPTIONS_TYPE;

#define PRINTER_NOTIFY_OPTIONS_REFRESH 0x01

  typedef struct _PRINTER_NOTIFY_OPTIONS
  {
    DWORD                        Version;
    DWORD                        Flags;
    DWORD                        Count;
    PPRINTER_NOTIFY_OPTIONS_TYPE pTypes;
  } PRINTER_NOTIFY_OPTIONS, *PPRINTER_NOTIFY_OPTIONS, *LPPRINTER_NOTIFY_OPTIONS;

#define PRINTER_NOTIFY_INFO_DISCARDED 0x01

  typedef struct _PRINTER_NOTIFY_INFO_DATA
  {
    WORD  Type;
    WORD  Field;
    DWORD Reserved;
    DWORD Id;
    union
    {
      DWORD adwData[2];
      struct
      {
        DWORD cbBuf;
        LPVOID pBuf;
      } Data;
    } NotifyData;
  } PRINTER_NOTIFY_INFO_DATA, *PPRINTER_NOTIFY_INFO_DATA, *LPPRINTER_NOTIFY_INFO_DATA;

  typedef struct _PRINTER_NOTIFY_INFO
  {
    DWORD                    Version;
    DWORD                    Flags;
    DWORD                    Count;
    PRINTER_NOTIFY_INFO_DATA aData[1];
  } PRINTER_NOTIFY_INFO, *PPRINTER_NOTIFY_INFO, *LPPRINTER_NOTIFY_INFO;

  typedef struct _BINARY_CONTAINER
  {
    DWORD  cbBuf;
    LPBYTE pData;
  } BINARY_CONTAINER, *PBINARY_CONTAINER;

  typedef struct _BIDI_DATA
  {
    DWORD dwBidiType;
    union
    {
      WINBOOL          bData;
      LONG             iData;
      LPWSTR           sData;
      FLOAT            fData;
      BINARY_CONTAINER biData;
    } u;
  } BIDI_DATA, *PBIDI_DATA, *LPBIDI_DATA;

  typedef struct _BIDI_REQUEST_DATA
  {
    DWORD     dwReqNumber;
    LPWSTR    pSchema;
    BIDI_DATA data;
  } BIDI_REQUEST_DATA, *PBIDI_REQUEST_DATA, *LPBIDI_REQUEST_DATA;

  typedef struct _BIDI_REQUEST_CONTAINER
  {
    DWORD             Version;
    DWORD             Flags;
    DWORD             Count;
    BIDI_REQUEST_DATA aData[1];
  }BIDI_REQUEST_CONTAINER, *PBIDI_REQUEST_CONTAINER, *LPBIDI_REQUEST_CONTAINER;

  typedef struct _BIDI_RESPONSE_DATA
  {
    DWORD     dwResult;
    DWORD     dwReqNumber;
    LPWSTR    pSchema;
    BIDI_DATA data;
  } BIDI_RESPONSE_DATA, *PBIDI_RESPONSE_DATA, *LPBIDI_RESPONSE_DATA;

  typedef struct _BIDI_RESPONSE_CONTAINER
  {
    DWORD              Version;
    DWORD              Flags;
    DWORD              Count;
    BIDI_RESPONSE_DATA aData[1];
  } BIDI_RESPONSE_CONTAINER, *PBIDI_RESPONSE_CONTAINER, *LPBIDI_RESPONSE_CONTAINER;

#define BIDI_ACTION_ENUM_SCHEMA       L"EnumSchema"
#define BIDI_ACTION_GET               L"Get"
#define BIDI_ACTION_SET               L"Set"
#define BIDI_ACTION_GET_ALL           L"GetAll"
#define BIDI_ACTION_GET_WITH_ARGUMENT L"GetWithArgument"

  typedef enum
  {
    BIDI_NULL   = 0,
    BIDI_INT    = 1,
    BIDI_FLOAT  = 2,
    BIDI_BOOL   = 3,
    BIDI_STRING = 4,
    BIDI_TEXT   = 5,
    BIDI_ENUM   = 6,
    BIDI_BLOB   = 7
  } BIDI_TYPE;

#define BIDI_ACCESS_ADMINISTRATOR 0x1
#define BIDI_ACCESS_USER          0x2

#define ERROR_BIDI_STATUS_OK                   0
#define ERROR_BIDI_NOT_SUPPORTED               ERROR_NOT_SUPPORTED
#define ERROR_BIDI_ERROR_BASE                  13000
#define ERROR_BIDI_STATUS_WARNING              (ERROR_BIDI_ERROR_BASE +  1)
#define ERROR_BIDI_SCHEMA_READ_ONLY            (ERROR_BIDI_ERROR_BASE +  2)
#define ERROR_BIDI_SERVER_OFFLINE              (ERROR_BIDI_ERROR_BASE +  3)
#define ERROR_BIDI_DEVICE_OFFLINE              (ERROR_BIDI_ERROR_BASE +  4)
#define ERROR_BIDI_SCHEMA_NOT_SUPPORTED        (ERROR_BIDI_ERROR_BASE +  5)
#define ERROR_BIDI_SET_DIFFERENT_TYPE          (ERROR_BIDI_ERROR_BASE +  6)
#define ERROR_BIDI_SET_MULTIPLE_SCHEMAPATH     (ERROR_BIDI_ERROR_BASE +  7)
#define ERROR_BIDI_SET_INVALID_SCHEMAPATH      (ERROR_BIDI_ERROR_BASE +  8)
#define ERROR_BIDI_SET_UNKNOWN_FAILURE         (ERROR_BIDI_ERROR_BASE +  9)
#define ERROR_BIDI_SCHEMA_WRITE_ONLY           (ERROR_BIDI_ERROR_BASE + 10)
#define ERROR_BIDI_GET_REQUIRES_ARGUMENT       (ERROR_BIDI_ERROR_BASE + 11)
#define ERROR_BIDI_GET_ARGUMENT_NOT_SUPPORTED  (ERROR_BIDI_ERROR_BASE + 12)
#define ERROR_BIDI_GET_MISSING_ARGUMENT        (ERROR_BIDI_ERROR_BASE + 13)
#define ERROR_BIDI_DEVICE_CONFIG_UNCHANGED     (ERROR_BIDI_ERROR_BASE + 14)
#define ERROR_BIDI_NO_LOCALIZED_RESOURCES      (ERROR_BIDI_ERROR_BASE + 15)
#define ERROR_BIDI_NO_BIDI_SCHEMA_EXTENSIONS   (ERROR_BIDI_ERROR_BASE + 16)
#define ERROR_BIDI_UNSUPPORTED_CLIENT_LANGUAGE (ERROR_BIDI_ERROR_BASE + 17)
#define ERROR_BIDI_UNSUPPORTED_RESOURCE_FORMAT (ERROR_BIDI_ERROR_BASE + 18)

  DWORD   WINAPI WaitForPrinterChange(HANDLE hPrinter, DWORD Flags);
  HANDLE  WINAPI FindFirstPrinterChangeNotification(HANDLE hPrinter, DWORD fdwFlags, DWORD fdwOptions, LPVOID pPrinterNotifyOptions);
  WINBOOL WINAPI FindNextPrinterChangeNotification(HANDLE hChange, PDWORD pdwChange, LPVOID pPrinterNotifyOptions, LPVOID *ppPrinterNotifyInfo);
  WINBOOL WINAPI FreePrinterNotifyInfo(PPRINTER_NOTIFY_INFO pPrinterNotifyInfo);
  WINBOOL WINAPI FindClosePrinterChangeNotification(HANDLE hChange);

#define PRINTER_CHANGE_ADD_PRINTER               0x00000001
#define PRINTER_CHANGE_SET_PRINTER               0x00000002
#define PRINTER_CHANGE_DELETE_PRINTER            0x00000004
#define PRINTER_CHANGE_FAILED_CONNECTION_PRINTER 0x00000008
#define PRINTER_CHANGE_PRINTER                   0x000000FF
#define PRINTER_CHANGE_ADD_JOB                   0x00000100
#define PRINTER_CHANGE_SET_JOB                   0x00000200
#define PRINTER_CHANGE_DELETE_JOB                0x00000400
#define PRINTER_CHANGE_WRITE_JOB                 0x00000800
#define PRINTER_CHANGE_JOB                       0x0000FF00
#define PRINTER_CHANGE_ADD_FORM                  0x00010000
#define PRINTER_CHANGE_SET_FORM                  0x00020000
#define PRINTER_CHANGE_DELETE_FORM               0x00040000
#define PRINTER_CHANGE_FORM                      0x00070000
#define PRINTER_CHANGE_ADD_PORT                  0x00100000
#define PRINTER_CHANGE_CONFIGURE_PORT            0x00200000
#define PRINTER_CHANGE_DELETE_PORT               0x00400000
#define PRINTER_CHANGE_PORT                      0x00700000
#define PRINTER_CHANGE_ADD_PRINT_PROCESSOR       0x01000000
#define PRINTER_CHANGE_DELETE_PRINT_PROCESSOR    0x04000000
#define PRINTER_CHANGE_PRINT_PROCESSOR           0x07000000
#define PRINTER_CHANGE_SERVER                    0x08000000
#define PRINTER_CHANGE_ADD_PRINTER_DRIVER        0x10000000
#define PRINTER_CHANGE_SET_PRINTER_DRIVER        0x20000000
#define PRINTER_CHANGE_DELETE_PRINTER_DRIVER     0x40000000
#define PRINTER_CHANGE_PRINTER_DRIVER            0x70000000
#define PRINTER_CHANGE_TIMEOUT                   0x80000000
#define PRINTER_CHANGE_ALL                       0x7F77FFFF

  DWORD WINAPI PrinterMessageBoxA(HANDLE hPrinter, DWORD Error, HWND hWnd, LPSTR pText, LPSTR pCaption, DWORD dwType);
  DWORD WINAPI PrinterMessageBoxW(HANDLE hPrinter, DWORD Error, HWND hWnd, LPWSTR pText, LPWSTR pCaption, DWORD dwType);
#define PrinterMessageBox __MINGW_NAME_AW(PrinterMessageBox)

#define PRINTER_ERROR_INFORMATION 0x80000000
#define PRINTER_ERROR_WARNING     0x40000000
#define PRINTER_ERROR_SEVERE      0x20000000
#define PRINTER_ERROR_OUTOFPAPER  0x00000001
#define PRINTER_ERROR_JAM         0x00000002
#define PRINTER_ERROR_OUTOFTONER  0x00000004

  WINBOOL WINAPI ClosePrinter(HANDLE hPrinter);
  WINBOOL WINAPI AddFormA(HANDLE hPrinter, DWORD Level, LPBYTE pForm);
  WINBOOL WINAPI AddFormW(HANDLE hPrinter, DWORD Level, LPBYTE pForm);
#define AddForm __MINGW_NAME_AW(AddForm)
  WINBOOL WINAPI DeleteFormA(HANDLE hPrinter, LPSTR pFormName);
  WINBOOL WINAPI DeleteFormW(HANDLE hPrinter, LPWSTR pFormName);
#define DeleteForm __MINGW_NAME_AW(DeleteForm)
  WINBOOL WINAPI GetFormA(HANDLE hPrinter, LPSTR pFormName, DWORD Level, LPBYTE pForm, DWORD cbBuf, LPDWORD pcbNeeded);
  WINBOOL WINAPI GetFormW(HANDLE hPrinter, LPWSTR pFormName, DWORD Level, LPBYTE pForm, DWORD cbBuf, LPDWORD pcbNeeded);
#define GetForm __MINGW_NAME_AW(GetForm)
  WINBOOL WINAPI SetFormA(HANDLE hPrinter, LPSTR pFormName, DWORD Level, LPBYTE pForm);
  WINBOOL WINAPI SetFormW(HANDLE hPrinter, LPWSTR pFormName, DWORD Level, LPBYTE pForm);
#define SetForm __MINGW_NAME_AW(SetForm)
  WINBOOL WINAPI EnumFormsA(HANDLE hPrinter, DWORD Level, LPBYTE pForm, DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned);
  WINBOOL WINAPI EnumFormsW(HANDLE hPrinter, DWORD Level, LPBYTE pForm, DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned);
#define EnumForms __MINGW_NAME_AW(EnumForms)
  WINBOOL WINAPI EnumMonitorsA(LPSTR pName, DWORD Level, LPBYTE pMonitor, DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned);
  WINBOOL WINAPI EnumMonitorsW(LPWSTR pName, DWORD Level, LPBYTE pMonitor, DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned);
#define EnumMonitors __MINGW_NAME_AW(EnumMonitors)
  WINBOOL WINAPI AddMonitorA(LPSTR pName, DWORD Level, LPBYTE pMonitorInfo);
  WINBOOL WINAPI AddMonitorW(LPWSTR pName, DWORD Level, LPBYTE pMonitorInfo);
#define AddMonitor __MINGW_NAME_AW(AddMonitor)
  WINBOOL WINAPI DeleteMonitorA(LPSTR pName, LPSTR pEnvironment, LPSTR pMonitorName);
  WINBOOL WINAPI DeleteMonitorW(LPWSTR pName, LPWSTR pEnvironment, LPWSTR pMonitorName);
#define DeleteMonitor __MINGW_NAME_AW(DeleteMonitor)
  WINBOOL WINAPI EnumPortsA(LPSTR pName, DWORD Level, LPBYTE pPorts, DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned);
  WINBOOL WINAPI EnumPortsW(LPWSTR pName, DWORD Level, LPBYTE pPorts, DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned);
#define EnumPorts __MINGW_NAME_AW(EnumPorts)
  WINBOOL WINAPI AddPortA(LPSTR pName, HWND hWnd, LPSTR pMonitorName);
  WINBOOL WINAPI AddPortW(LPWSTR pName, HWND hWnd, LPWSTR pMonitorName);
#define AddPort __MINGW_NAME_AW(AddPort)
  WINBOOL WINAPI ConfigurePortA(LPSTR pName, HWND hWnd, LPSTR pPortName);
  WINBOOL WINAPI ConfigurePortW(LPWSTR pName, HWND hWnd, LPWSTR pPortName);
#define ConfigurePort __MINGW_NAME_AW(ConfigurePort)
  WINBOOL WINAPI DeletePortA(LPSTR pName, HWND hWnd, LPSTR pPortName);
  WINBOOL WINAPI DeletePortW(LPWSTR pName, HWND hWnd, LPWSTR pPortName);
#define DeletePort __MINGW_NAME_AW(DeletePort)
  WINBOOL WINAPI XcvDataW(HANDLE hXcv, PCWSTR pszDataName, PBYTE pInputData, DWORD cbInputData, PBYTE pOutputData, DWORD cbOutputData, PDWORD pcbOutputNeeded, PDWORD pdwStatus);
#define XcvData XcvDataW
  WINBOOL WINAPI GetDefaultPrinterA(LPSTR pszBuffer, LPDWORD pcchBuffer);
  WINBOOL WINAPI GetDefaultPrinterW(LPWSTR pszBuffer, LPDWORD pcchBuffer);
#define GetDefaultPrinter __MINGW_NAME_AW(GetDefaultPrinter)
  WINBOOL WINAPI SetDefaultPrinterA(LPCSTR pszPrinter);
  WINBOOL WINAPI SetDefaultPrinterW(LPCWSTR pszPrinter);
#define SetDefaultPrinter __MINGW_NAME_AW(SetDefaultPrinter)
  WINBOOL WINAPI SetPortA(LPSTR pName, LPSTR pPortName, DWORD dwLevel, LPBYTE pPortInfo);
  WINBOOL WINAPI SetPortW(LPWSTR pName, LPWSTR pPortName, DWORD dwLevel, LPBYTE pPortInfo);
#define SetPort __MINGW_NAME_AW(SetPort)
  WINBOOL WINAPI AddPrinterConnectionA(LPSTR pName);
  WINBOOL WINAPI AddPrinterConnectionW(LPWSTR pName);
#define AddPrinterConnection __MINGW_NAME_AW(AddPrinterConnection)
  WINBOOL WINAPI DeletePrinterConnectionA(LPSTR pName);
  WINBOOL WINAPI DeletePrinterConnectionW(LPWSTR pName);
#define DeletePrinterConnection __MINGW_NAME_AW(DeletePrinterConnection)
  HANDLE  WINAPI ConnectToPrinterDlg(HWND hwnd, DWORD Flags);

  typedef struct _PROVIDOR_INFO_1A
  {
    LPSTR pName;
    LPSTR pEnvironment;
    LPSTR pDLLName;
  } PROVIDOR_INFO_1A, *PPROVIDOR_INFO_1A, *LPPROVIDOR_INFO_1A;

  typedef struct _PROVIDOR_INFO_1W
  {
    LPWSTR pName;
    LPWSTR pEnvironment;
    LPWSTR pDLLName;
  } PROVIDOR_INFO_1W, *PPROVIDOR_INFO_1W, *LPPROVIDOR_INFO_1W;

  __MINGW_TYPEDEF_AW(PROVIDOR_INFO_1)
  __MINGW_TYPEDEF_AW(PPROVIDOR_INFO_1)
  __MINGW_TYPEDEF_AW(LPPROVIDOR_INFO_1)

  typedef struct _PROVIDOR_INFO_2A
  {
    LPSTR pOrder;
  } PROVIDOR_INFO_2A, *PPROVIDOR_INFO_2A, *LPPROVIDOR_INFO_2A;

  typedef struct _PROVIDOR_INFO_2W
  {
    LPWSTR pOrder;
  } PROVIDOR_INFO_2W, *PPROVIDOR_INFO_2W, *LPPROVIDOR_INFO_2W;

  __MINGW_TYPEDEF_AW(PROVIDOR_INFO_2)
  __MINGW_TYPEDEF_AW(PPROVIDOR_INFO_2)
  __MINGW_TYPEDEF_AW(LPPROVIDOR_INFO_2)

  WINBOOL WINAPI AddPrintProvidorA(LPSTR pName, DWORD level, LPBYTE pProvidorInfo);
  WINBOOL WINAPI AddPrintProvidorW(LPWSTR pName, DWORD level, LPBYTE pProvidorInfo);
#define AddPrintProvidor __MINGW_NAME_AW(AddPrintProvidor)
  WINBOOL WINAPI DeletePrintProvidorA(LPSTR pName, LPSTR pEnvironment, LPSTR pPrintProvidorName);
  WINBOOL WINAPI DeletePrintProvidorW(LPWSTR pName, LPWSTR pEnvironment, LPWSTR pPrintProvidorName);
#define DeletePrintProvidor __MINGW_NAME_AW(DeletePrintProvidor)
  WINBOOL WINAPI IsValidDevmodeA (PDEVMODEA pDevmode, size_t DevmodeSize);
  WINBOOL WINAPI IsValidDevmodeW (PDEVMODEW pDevmode, size_t DevmodeSize);
#define IsValidDevmode __MINGW_NAME_AW(IsValidDevmode)

#define SPLREG_DEFAULT_SPOOL_DIRECTORY                           TEXT("DefaultSpoolDirectory")
#define SPLREG_PORT_THREAD_PRIORITY_DEFAULT                      TEXT("PortThreadPriorityDefault")
#define SPLREG_PORT_THREAD_PRIORITY                              TEXT("PortThreadPriority")
#define SPLREG_SCHEDULER_THREAD_PRIORITY_DEFAULT                 TEXT("SchedulerThreadPriorityDefault")
#define SPLREG_SCHEDULER_THREAD_PRIORITY                         TEXT("SchedulerThreadPriority")
#define SPLREG_BEEP_ENABLED                                      TEXT("BeepEnabled")
#define SPLREG_NET_POPUP                                         TEXT("NetPopup")
#define SPLREG_RETRY_POPUP                                       TEXT("RetryPopup")
#define SPLREG_NET_POPUP_TO_COMPUTER                             TEXT("NetPopupToComputer")
#define SPLREG_EVENT_LOG                                         TEXT("EventLog")
#define SPLREG_MAJOR_VERSION                                     TEXT("MajorVersion")
#define SPLREG_MINOR_VERSION                                     TEXT("MinorVersion")
#define SPLREG_ARCHITECTURE                                      TEXT("Architecture")
#define SPLREG_OS_VERSION                                        TEXT("OSVersion")
#define SPLREG_OS_VERSIONEX                                      TEXT("OSVersionEx")
#define SPLREG_DS_PRESENT                                        TEXT("DsPresent")
#define SPLREG_DS_PRESENT_FOR_USER                               TEXT("DsPresentForUser")
#define SPLREG_REMOTE_FAX                                        TEXT("RemoteFax")
#define SPLREG_RESTART_JOB_ON_POOL_ERROR                         TEXT("RestartJobOnPoolError")
#define SPLREG_RESTART_JOB_ON_POOL_ENABLED                       TEXT("RestartJobOnPoolEnabled")
#define SPLREG_DNS_MACHINE_NAME                                  TEXT("DNSMachineName")
#define SPLREG_ALLOW_USER_MANAGEFORMS                            TEXT("AllowUserManageForms")
#define SPLREG_WEBSHAREMGMT                                      TEXT("WebShareMgmt")
#define SPLREG_PRINT_DRIVER_ISOLATION_GROUPS_SEPARATOR           L'\\'
#define SPLREG_PRINT_DRIVER_ISOLATION_GROUPS                     TEXT("PrintDriverIsolationGroups")
#define SPLREG_PRINT_DRIVER_ISOLATION_TIME_BEFORE_RECYCLE        TEXT("PrintDriverIsolationTimeBeforeRecycle")
#define SPLREG_PRINT_DRIVER_ISOLATION_MAX_OBJECTS_BEFORE_RECYCLE TEXT("PrintDriverIsolationMaxobjsBeforeRecycle")
#define SPLREG_PRINT_DRIVER_ISOLATION_IDLE_TIMEOUT               TEXT("PrintDriverIsolationIdleTimeout")
#define SPLREG_PRINT_DRIVER_ISOLATION_EXECUTION_POLICY           TEXT("PrintDriverIsolationExecutionPolicy")
#define SPLREG_PRINT_DRIVER_ISOLATION_OVERRIDE_POLICY            TEXT("PrintDriverIsolationOverrideCompat")
#define SPLREG_PRINT_QUEUE_V4_DRIVER_DIRECTORY                   TEXT("PrintQueueV4DriverDirectory")

#define SERVER_ACCESS_ADMINISTER      0x00000001
#define SERVER_ACCESS_ENUMERATE       0x00000002
#define PRINTER_ACCESS_ADMINISTER     0x00000004
#define PRINTER_ACCESS_USE            0x00000008
#define JOB_ACCESS_ADMINISTER         0x00000010
#define JOB_ACCESS_READ               0x00000020
#define PRINTER_ACCESS_MANAGE_LIMITED 0x00000040

#define SERVER_ALL_ACCESS  (STANDARD_RIGHTS_REQUIRED | SERVER_ACCESS_ADMINISTER  | SERVER_ACCESS_ENUMERATE)
#define SERVER_READ        (STANDARD_RIGHTS_READ     | SERVER_ACCESS_ENUMERATE                            )
#define SERVER_WRITE       (STANDARD_RIGHTS_WRITE    | SERVER_ACCESS_ADMINISTER  | SERVER_ACCESS_ENUMERATE)
#define SERVER_EXECUTE     (STANDARD_RIGHTS_EXECUTE  | SERVER_ACCESS_ENUMERATE                            )
#define PRINTER_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | PRINTER_ACCESS_ADMINISTER | PRINTER_ACCESS_USE     )
#define PRINTER_READ       (STANDARD_RIGHTS_READ     | PRINTER_ACCESS_USE                                 )
#define PRINTER_WRITE      (STANDARD_RIGHTS_WRITE    | PRINTER_ACCESS_USE                                 )
#define PRINTER_EXECUTE    (STANDARD_RIGHTS_EXECUTE  | PRINTER_ACCESS_USE                                 )
#define JOB_ALL_ACCESS     (STANDARD_RIGHTS_REQUIRED | JOB_ACCESS_ADMINISTER     | JOB_ACCESS_READ        )
#define JOB_READ           (STANDARD_RIGHTS_READ     | JOB_ACCESS_READ                                    )
#define JOB_WRITE          (STANDARD_RIGHTS_WRITE    | JOB_ACCESS_ADMINISTER                              )
#define JOB_EXECUTE        (STANDARD_RIGHTS_EXECUTE  | JOB_ACCESS_ADMINISTER                              )

#define SPLDS_SPOOLER_KEY                     TEXT("DsSpooler")
#define SPLDS_DRIVER_KEY                      TEXT("DsDriver")
#define SPLDS_USER_KEY                        TEXT("DsUser")
#define SPLDS_ASSET_NUMBER                    TEXT("assetNumber")
#define SPLDS_BYTES_PER_MINUTE                TEXT("bytesPerMinute")
#define SPLDS_DESCRIPTION                     TEXT("description")
#define SPLDS_DRIVER_NAME                     TEXT("driverName")
#define SPLDS_DRIVER_VERSION                  TEXT("driverVersion")
#define SPLDS_LOCATION                        TEXT("location")
#define SPLDS_PORT_NAME                       TEXT("portName")
#define SPLDS_PRINT_ATTRIBUTES                TEXT("printAttributes")
#define SPLDS_PRINT_BIN_NAMES                 TEXT("printBinNames")
#define SPLDS_PRINT_COLLATE                   TEXT("printCollate")
#define SPLDS_PRINT_COLOR                     TEXT("printColor")
#define SPLDS_PRINT_DUPLEX_SUPPORTED          TEXT("printDuplexSupported")
#define SPLDS_PRINT_END_TIME                  TEXT("printEndTime")
#define SPLDS_PRINTER_CLASS                   TEXT("printQueue")
#define SPLDS_PRINTER_NAME                    TEXT("printerName")
#define SPLDS_PRINT_KEEP_PRINTED_JOBS         TEXT("printKeepPrintedJobs")
#define SPLDS_PRINT_LANGUAGE                  TEXT("printLanguage")
#define SPLDS_PRINT_MAC_ADDRESS               TEXT("printMACAddress")
#define SPLDS_PRINT_MAX_X_EXTENT              TEXT("printMaxXExtent")
#define SPLDS_PRINT_MAX_Y_EXTENT              TEXT("printMaxYExtent")
#define SPLDS_PRINT_MAX_RESOLUTION_SUPPORTED  TEXT("printMaxResolutionSupported")
#define SPLDS_PRINT_MEDIA_READY               TEXT("printMediaReady")
#define SPLDS_PRINT_MEDIA_SUPPORTED           TEXT("printMediaSupported")
#define SPLDS_PRINT_MEMORY                    TEXT("printMemory")
#define SPLDS_PRINT_MIN_X_EXTENT              TEXT("printMinXExtent")
#define SPLDS_PRINT_MIN_Y_EXTENT              TEXT("printMinYExtent")
#define SPLDS_PRINT_NETWORK_ADDRESS           TEXT("printNetworkAddress")
#define SPLDS_PRINT_NOTIFY                    TEXT("printNotify")
#define SPLDS_PRINT_NUMBER_UP                 TEXT("printNumberUp")
#define SPLDS_PRINT_ORIENTATIONS_SUPPORTED    TEXT("printOrientationsSupported")
#define SPLDS_PRINT_OWNER                     TEXT("printOwner")
#define SPLDS_PRINT_PAGES_PER_MINUTE          TEXT("printPagesPerMinute")
#define SPLDS_PRINT_RATE                      TEXT("printRate")
#define SPLDS_PRINT_RATE_UNIT                 TEXT("printRateUnit")
#define SPLDS_PRINT_SEPARATOR_FILE            TEXT("printSeparatorFile")
#define SPLDS_PRINT_SHARE_NAME                TEXT("printShareName")
#define SPLDS_PRINT_SPOOLING                  TEXT("printSpooling")
#define SPLDS_PRINT_STAPLING_SUPPORTED        TEXT("printStaplingSupported")
#define SPLDS_PRINT_START_TIME                TEXT("printStartTime")
#define SPLDS_PRINT_STATUS                    TEXT("printStatus")
#define SPLDS_PRIORITY                        TEXT("priority")
#define SPLDS_SERVER_NAME                     TEXT("serverName")
#define SPLDS_SHORT_SERVER_NAME               TEXT("shortServerName")
#define SPLDS_UNC_NAME                        TEXT("uNCName")
#define SPLDS_URL                             TEXT("url")
#define SPLDS_FLAGS                           TEXT("flags")
#define SPLDS_VERSION_NUMBER                  TEXT("versionNumber")
#define SPLDS_PRINT_IPP_COMPRESSION_SUPPORTED TEXT("ippCompressionSupported")
#define SPLDS_PRINTER_NAME_ALIASES            TEXT("printerNameAliases")
#define SPLDS_PRINTER_LOCATIONS               TEXT("printerLocations")
#define SPLDS_PRINTER_MODEL                   TEXT("printerModel")

  typedef enum _PRINTER_OPTION_FLAGS
  {
    PRINTER_OPTION_NO_CACHE       = 1 << 0,
    PRINTER_OPTION_CACHE          = 1 << 1,
    PRINTER_OPTION_CLIENT_CHANGE  = 1 << 2,
    PRINTER_OPTION_NO_CLIENT_DATA = 1 << 3,
  } PRINTER_OPTION_FLAGS;

  typedef struct _PRINTER_OPTIONSA
  {
    UINT  cbSize;
    DWORD dwFlags;
  } PRINTER_OPTIONSA, *PPRINTER_OPTIONSA, *LPPRINTER_OPTIONSA;

  typedef struct _PRINTER_OPTIONSW
  {
    UINT  cbSize;
    DWORD dwFlags;
  } PRINTER_OPTIONSW, *PPRINTER_OPTIONSW, *LPPRINTER_OPTIONSW;

  __MINGW_TYPEDEF_AW(PRINTER_OPTIONS)
  __MINGW_TYPEDEF_AW(PPRINTER_OPTIONS)
  __MINGW_TYPEDEF_AW(LPPRINTER_OPTIONS)

  WINBOOL WINAPI OpenPrinter2A(LPCSTR pPrinterName, LPHANDLE phPrinter, LPPRINTER_DEFAULTS pDefault, PPRINTER_OPTIONS pOptions);
  WINBOOL WINAPI OpenPrinter2W(LPCWSTR pPrinterName, LPHANDLE phPrinter, LPPRINTER_DEFAULTS pDefault, PPRINTER_OPTIONS pOptions);
#define OpenPrinter2 __MINGW_NAME_AW(OpenPrinter2)

#define PRINTER_CONNECTION_MISMATCH 0x00000020
#define PRINTER_CONNECTION_NO_UI    0x00000040

  typedef struct _PRINTER_CONNECTION_INFO_1A
  {
    DWORD dwFlags;
    LPSTR pszDriverName;
  } PRINTER_CONNECTION_INFO_1A, *PPRINTER_CONNECTION_INFO_1A;

  typedef struct _PRINTER_CONNECTION_INFO_1W
  {
    DWORD  dwFlags;
    LPWSTR pszDriverName;
  } PRINTER_CONNECTION_INFO_1W, *PPRINTER_CONNECTION_INFO_1W;

  __MINGW_TYPEDEF_AW(PRINTER_CONNECTION_INFO_1)
  __MINGW_TYPEDEF_AW(PPRINTER_CONNECTION_INFO_1)

  WINBOOL WINAPI AddPrinterConnection2A(HWND hWnd, LPCSTR pszName, DWORD dwLevel, PVOID pConnectionInfo);
  WINBOOL WINAPI AddPrinterConnection2W(HWND hWnd, LPCWSTR pszName, DWORD dwLevel, PVOID pConnectionInfo);
#define AddPrinterConnection2 __MINGW_NAME_AW(AddPrinterConnection2)

#define IPDFP_COPY_ALL_FILES 0x00000001

  HRESULT WINAPI InstallPrinterDriverFromPackageA(LPCSTR pszServer, LPCSTR pszInfPath, LPCSTR pszDriverName, LPCSTR pszEnvironment, DWORD dwFlags);
  HRESULT WINAPI InstallPrinterDriverFromPackageW(LPCWSTR pszServer, LPCWSTR pszInfPath, LPCWSTR pszDriverName, LPCWSTR pszEnvironment, DWORD dwFlags);
#define InstallPrinterDriverFromPackage __MINGW_NAME_AW(InstallPrinterDriverFromPackage)

#define UPDP_SILENT_UPLOAD     0x00000001
#define UPDP_UPLOAD_ALWAYS     0x00000002
#define UPDP_CHECK_DRIVERSTORE 0x00000004

  HRESULT WINAPI UploadPrinterDriverPackageA(LPCSTR pszServer, LPCSTR pszInfPath, LPCSTR pszEnvironment, DWORD dwFlags, HWND hwnd, LPSTR pszDestInfPath, PULONG pcchDestInfPath);
  HRESULT WINAPI UploadPrinterDriverPackageW(LPCWSTR pszServer, LPCWSTR pszInfPath, LPCWSTR pszEnvironment, DWORD dwFlags, HWND hwnd, LPWSTR pszDestInfPath, PULONG pcchDestInfPath);
#define UploadPrinterDriverPackage __MINGW_NAME_AW(UploadPrinterDriverPackage)

  typedef struct _CORE_PRINTER_DRIVERA
  {
    GUID      CoreDriverGUID;
    FILETIME  ftDriverDate;
    DWORDLONG dwlDriverVersion;
    CHAR      szPackageID[MAX_PATH];
  } CORE_PRINTER_DRIVERA, *PCORE_PRINTER_DRIVERA;

  typedef struct _CORE_PRINTER_DRIVERW
  {
    GUID      CoreDriverGUID;
    FILETIME  ftDriverDate;
    DWORDLONG dwlDriverVersion;
    WCHAR     szPackageID[MAX_PATH];
  } CORE_PRINTER_DRIVERW, *PCORE_PRINTER_DRIVERW;

  __MINGW_TYPEDEF_AW(CORE_PRINTER_DRIVER)
  __MINGW_TYPEDEF_AW(PCORE_PRINTER_DRIVER)

  HRESULT WINAPI GetCorePrinterDriversA(LPCSTR pszServer, LPCSTR pszEnvironment, LPCSTR pszzCoreDriverDependencies, DWORD cCorePrinterDrivers, PCORE_PRINTER_DRIVERA pCorePrinterDrivers);
  HRESULT WINAPI GetCorePrinterDriversW(LPCWSTR pszServer, LPCWSTR pszEnvironment, LPCWSTR pszzCoreDriverDependencies, DWORD cCorePrinterDrivers, PCORE_PRINTER_DRIVERW pCorePrinterDrivers);
#define GetCorePrinterDrivers __MINGW_NAME_AW(GetCorePrinterDrivers)
  HRESULT WINAPI CorePrinterDriverInstalledA(LPCSTR pszServer, LPCSTR pszEnvironment, GUID CoreDriverGUID, FILETIME ftDriverDate, DWORDLONG dwlDriverVersion, WINBOOL *pbDriverInstalled);
  HRESULT WINAPI CorePrinterDriverInstalledW(LPCWSTR pszServer, LPCWSTR pszEnvironment, GUID CoreDriverGUID, FILETIME ftDriverDate, DWORDLONG dwlDriverVersion, WINBOOL *pbDriverInstalled);
#define CorePrinterDriverInstalled __MINGW_NAME_AW(CorePrinterDriverInstalled)
  HRESULT WINAPI GetPrinterDriverPackagePathA(LPCSTR pszServer, LPCSTR pszEnvironment, LPCSTR pszLanguage, LPCSTR pszPackageID, LPSTR pszDriverPackageCab, DWORD cchDriverPackageCab, LPDWORD pcchRequiredSize);
  HRESULT WINAPI GetPrinterDriverPackagePathW(LPCWSTR pszServer, LPCWSTR pszEnvironment, LPCWSTR pszLanguage, LPCWSTR pszPackageID, LPWSTR pszDriverPackageCab, DWORD cchDriverPackageCab, LPDWORD pcchRequiredSize);
#define GetPrinterDriverPackagePath __MINGW_NAME_AW(GetPrinterDriverPackagePath)
  HRESULT WINAPI DeletePrinterDriverPackageA(LPCSTR pszServer, LPCSTR pszInfPath, LPCSTR pszEnvironment);
  HRESULT WINAPI DeletePrinterDriverPackageW(LPCWSTR pszServer, LPCWSTR pszInfPath, LPCWSTR pszEnvironment);
#define DeletePrinterDriverPackage __MINGW_NAME_AW(DeletePrinterDriverPackage)

  typedef enum
  {
    kPropertyTypeString = 1,
    kPropertyTypeInt32,
    kPropertyTypeInt64,
    kPropertyTypeByte,
    kPropertyTypeTime,
    kPropertyTypeDevMode,
    kPropertyTypeSD,
    kPropertyTypeNotificationReply,
    kPropertyTypeNotificationOptions,
    kPropertyTypeBuffer
  } EPrintPropertyType;

  typedef enum
  {
    kAddingDocumentSequence = 0,
    kDocumentSequenceAdded  = 1,
    kAddingFixedDocument    = 2,
    kFixedDocumentAdded     = 3,
    kAddingFixedPage        = 4,
    kFixedPageAdded         = 5,
    kResourceAdded          = 6,
    kFontAdded              = 7,
    kImageAdded             = 8,
    kXpsDocumentCommitted   = 9
  } EPrintXPSJobProgress;

  typedef enum
  {
    kJobProduction = 1,
    kJobConsumption
  } EPrintXPSJobOperation;

  typedef struct
  {
    EPrintPropertyType ePropertyType;
    union
    {
      BYTE     propertyByte;
      PWSTR    propertyString;
      LONG     propertyInt32;
      LONGLONG propertyInt64;
      struct
      {
        DWORD  cbBuf;
        LPVOID pBuf;
      } propertyBlob;
    } value;
  } PrintPropertyValue;

  typedef struct
  {
    WCHAR              *propertyName;
    PrintPropertyValue  propertyValue;
  } PrintNamedProperty;

  typedef struct
  {
    ULONG               numberOfProperties;
    PrintNamedProperty *propertiesCollection;
  } PrintPropertiesCollection;

  HRESULT WINAPI ReportJobProcessingProgress(HANDLE printerHandle, ULONG jobId, EPrintXPSJobOperation jobOperation, EPrintXPSJobProgress jobProgress);
  WINBOOL WINAPI GetPrinterDriver2A(HWND hWnd, HANDLE hPrinter, LPSTR pEnvironment, DWORD Level, LPBYTE pDriverInfo, DWORD cbBuf, LPDWORD pcbNeeded);
  WINBOOL WINAPI GetPrinterDriver2W(HWND hWnd, HANDLE hPrinter, LPWSTR pEnvironment, DWORD Level, LPBYTE pDriverInfo, DWORD cbBuf, LPDWORD pcbNeeded);
#define GetPrinterDriver2 __MINGW_NAME_AW(GetPrinterDriver2)

  typedef enum
  {
    PRINT_EXECUTION_CONTEXT_APPLICATION            = 0,
    PRINT_EXECUTION_CONTEXT_SPOOLER_SERVICE        = 1,
    PRINT_EXECUTION_CONTEXT_SPOOLER_ISOLATION_HOST = 2,
    PRINT_EXECUTION_CONTEXT_FILTER_PIPELINE        = 3,
    PRINT_EXECUTION_CONTEXT_WOW64                  = 4
  } PRINT_EXECUTION_CONTEXT;

  typedef struct
  {
    PRINT_EXECUTION_CONTEXT context;
    DWORD                   clientAppPID;
  } PRINT_EXECUTION_DATA;

  WINBOOL WINAPI GetPrintExecutionData(PRINT_EXECUTION_DATA *pData);
  DWORD   WINAPI GetJobNamedPropertyValue(HANDLE hPrinter, DWORD JobId, PCWSTR pszName, PrintPropertyValue *pValue);
  void    WINAPI FreePrintPropertyValue(PrintPropertyValue *pValue);
  void    WINAPI FreePrintNamedPropertyArray(DWORD cProperties, PrintNamedProperty **ppProperties);
  DWORD   WINAPI SetJobNamedProperty(HANDLE hPrinter, DWORD JobId, const PrintNamedProperty *pProperty);
  DWORD   WINAPI DeleteJobNamedProperty(HANDLE hPrinter, DWORD JobId, PCWSTR pszName);
  DWORD   WINAPI EnumJobNamedProperties(HANDLE hPrinter, DWORD JobId, DWORD *pcProperties, PrintNamedProperty **ppProperties);
  HRESULT WINAPI GetPrintOutputInfo(HWND hWnd, PCWSTR pszPrinter, HANDLE *phFile, PWSTR *ppszOutputFile);

#define MS_PRINT_JOB_OUTPUT_FILE L"MsPrintJobOutputFile"

#endif  /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */

#ifdef __cplusplus
}
#endif

#endif  /* _WINSPOOL_ */
